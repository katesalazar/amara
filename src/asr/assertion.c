/*
 * Copyright 2018-2019 Mercedes Catherine Salazar
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * src/asr/assertion.c: Assertions utility.
 */

/*   For `void assert(scalar expression)`. */
#include <assert.h>

/*   XXX won't be available in every system. */
#include <execinfo.h>

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `int strcmp(const char * s1, const char * s2)`, and
 * `size_t strlen(const char * s)`. */
#include <string.h>

/*   For `AMARA_BOOLEAN_TRUE` and `AMARA_BOOLEAN_FALSE`. */
#include "../cmn/amara_boolean.h"

/*   For own definitions. */
#include "assertion.h"

const char *
strip_from_full_path(const char * potentially_full_path_name_to_a_doc)
__attribute__((warn_unused_result))
;

#ifndef SHORT_MIN
#define SHORT_MIN (short) 0x8000 /* XXX */
#endif

const char *
strip_from_full_path(const char * potentially_full_path_name_to_a_doc)
{
	short last_slash_found_index_;
	signed short i_;
	char * returning_;

	const signed short potentially_full_path_name_to_a_doc_len_ =
			strlen(potentially_full_path_name_to_a_doc);

	last_slash_found_index_ = SHORT_MIN;

	for (i_ = 0; i_ < potentially_full_path_name_to_a_doc_len_; i_++) {
		if (i_ < 0) {
			forced_assertion(0);
		}
		if (potentially_full_path_name_to_a_doc[i_] == '/') {  /* FIXME WONT WORK ON MICROSOFT */
			last_slash_found_index_ = i_;
		}
	}

	returning_ = malloc(
			potentially_full_path_name_to_a_doc_len_
			- last_slash_found_index_
			+ 1);
	for (
			i_ = 0;
			i_ < potentially_full_path_name_to_a_doc_len_
					- last_slash_found_index_;
			i_++) {
		returning_[i_] = potentially_full_path_name_to_a_doc[
				last_slash_found_index_
				+ 1 /* for the slash itself */
				+ i_];
	}
	returning_[i_] = '\0';

	return returning_;
}

void
assertion(int expression)
{
	assertion_two(expression, "WARNING Assertion failed\n");
}

void
assertion_two(int expression, const char * message)
{
	/**  FIXME This repeated allocation MUST be removed. */
	void * call_stack[128];
	char * * call_stack_strings;
	short i, frames;

	if (!expression) {
		fprintf(stderr, "%s\n", message);

	/* WARNING THIS IS ONLY VALID IN LINUX AND MACO (http://stackoverflow.com/questions/3899870/) */
	frames = backtrace(call_stack, 128);
	call_stack_strings = backtrace_symbols(call_stack, frames);
	for (i = 0; i < frames; i++) {
		printf("%s\n", call_stack_strings[i]);
	}
	free(call_stack_strings);

	}

	assert(expression);

	/* TODO    Convert to macro so this can be removed without
	 * TODO  triggering `-Werror,-Wunused-parameter`. */
	expression--;
}

void
assertion_four(
		int expression, const char * location_message,
		const char * source_doc_name, const short source_doc_line)
{
	size_t source_doc_name_len_;
	char * source_doc_line_as_string_;
	size_t source_doc_line_as_string_len_;
	size_t constructed_location_message_len_;
	char * constructed_location_message_;
	int sprintf_result_;
	size_t sprintf_result_as_size_t_;
	const char * source_doc_name_stripped_from_full_path_;
	int bison_table_name_strcmp_;
	amara_boolean source_doc_is_the_bison_table_;
	unsigned short line_upper_bound_;
	static unsigned char line_upper_bound_logten_ceil_;
	static amara_boolean line_upper_bound_is_power_of_ten_unknown_;
	static amara_boolean line_upper_bound_is_power_of_ten_;

	/*   Will not be able to handle line numbers this large or
	 * higher. E.g. for a value of `1000`, lines allowed are from
	 * line `1` to line `999`.
	 * 1000 lines is a reasonable number for the source docs of
	 * Amara. However, a Bison symbol table might get larger than
	 * that, so 10000 lines are allowed as an exception. */
	const char * bison_table_name_ = malloc(strlen("minia.tab.c") + 1);
	assertion(bison_table_name_ != NULL);
	strcpy((char *) bison_table_name_, "minia.tab.c");
	source_doc_name_stripped_from_full_path_ =
			strip_from_full_path(source_doc_name);
	bison_table_name_strcmp_ = strcmp(
			source_doc_name_stripped_from_full_path_,
			bison_table_name_);
	source_doc_is_the_bison_table_ = bison_table_name_strcmp_ == 0 ?
			AMARA_BOOLEAN_TRUE : AMARA_BOOLEAN_FALSE;
	line_upper_bound_ =
			source_doc_is_the_bison_table_ == AMARA_BOOLEAN_TRUE ?
					10000 : 1000;
	/*   This is going to hold the _logarithm in base ten_ of
	 * `line_upper_bound_`. In case of powers of ten, the `ceil`ing
	 * of the logarithm in base ten is exactly the logarithm in base
	 * ten. */
	line_upper_bound_is_power_of_ten_unknown_ =
			/*   Initially, `AMARA_BOOLEAN_TRUE`. After
			 * first execution of this function, always
			 * `AMARA_BOOLEAN_FALSE`. */
			AMARA_BOOLEAN_TRUE;

	assertion_two(location_message[0] == '%', "assertion.c: 117\n");
	assertion_two(location_message[1] == 's', "assertion.c: 118\n");
	assertion_two(location_message[2] == ':', "assertion.c: 105\n");
	assertion_two(location_message[3] == ' ', "assertion.c: 120\n");
	assertion_two(location_message[4] == '%', "assertion.c: 121\n");
	assertion_two(location_message[5] == 'd', "assertion.c: 108\n");
	assertion_two(location_message[6] == '\n', "assertion.c: 125\n");

	source_doc_name_len_ = strlen(source_doc_name);

	assertion_two(source_doc_line > -1, "assertion.c: 113\n");
	assertion_two(source_doc_line < line_upper_bound_,
			"assertion.c: 114\n");

	if (line_upper_bound_is_power_of_ten_unknown_ == AMARA_BOOLEAN_TRUE) {
		assertion_two(
				(line_upper_bound_ == 1000 && source_doc_is_the_bison_table_ == AMARA_BOOLEAN_FALSE)
						|| (line_upper_bound_ == 10000 && source_doc_is_the_bison_table_ == AMARA_BOOLEAN_TRUE),
				"assertion.c: 182\n");
		line_upper_bound_is_power_of_ten_unknown_ =
				AMARA_BOOLEAN_FALSE;
        line_upper_bound_is_power_of_ten_unknown_ = /* XXX */
        AMARA_BOOLEAN_TRUE; /* XXX */
		line_upper_bound_is_power_of_ten_ = AMARA_BOOLEAN_TRUE;
		line_upper_bound_logten_ceil_ =
				source_doc_is_the_bison_table_ == AMARA_BOOLEAN_TRUE ?
						5 : 4;
	}
#ifdef NDEBUG
	if (line_upper_bound_is_power_of_ten_ != AMARA_BOOLEAN_TRUE) {
		exit(1);
	}
#else
	assert(line_upper_bound_is_power_of_ten_ == AMARA_BOOLEAN_TRUE);
#endif

	source_doc_line_as_string_ = malloc(
			/*   Logarithm in base ten of the lines upper
			 * bound constant. This is relevant in the way
			 * e.g., for a lines upper bound of `1000`,
			 * three digits are enough for all included
			 * numbers. The logarithm in base ten of `1000`
			 * is precisely `4`. */
			line_upper_bound_logten_ceil_ - 1
			/*   A reserve provision for a potential `-`
			 * glyph, in case of numeric domain overflow. */
			+ 1
			/*   A reserved space for the chars array
			 * terminator (`\0`). */
			+ 1);
	assertion_two(source_doc_line_as_string_ != NULL,
			"assertion.c: 135\n");

	sprintf_result_ = sprintf(
			source_doc_line_as_string_, "%d", source_doc_line);
	assertion_two(sprintf_result_ > -1, "assertion.c: 141\n");
	sprintf_result_as_size_t_ = sprintf_result_;

	assertion_two(
			sprintf_result_as_size_t_ <
					line_upper_bound_logten_ceil_,
			"assertion.c: 139\n");

	source_doc_line_as_string_len_ = strlen(source_doc_line_as_string_);

	constructed_location_message_len_ =
			source_doc_name_len_
			+ 2 /* ": " */
			+ source_doc_line_as_string_len_
			+ 1 /* '\n' */
			;

	constructed_location_message_ = malloc(
			constructed_location_message_len_
			+ 1 /* '\0' */
	);
	assertion_two(
			constructed_location_message_ != NULL,
			"assertion.c: 137\n");
	sprintf_result_ = sprintf(
			constructed_location_message_, location_message,
			source_doc_name, source_doc_line);
	assertion_two(sprintf_result_ > -1, "assertion.c: 162\n");
	sprintf_result_as_size_t_ = sprintf_result_;
	if (sprintf_result_as_size_t_ != constructed_location_message_len_) {
		fprintf(stderr, "assertion.c: 181: %lu %lu %lu %lu %s %s\n", sprintf_result_as_size_t_, constructed_location_message_len_, source_doc_name_len_, source_doc_line_as_string_len_, source_doc_name, constructed_location_message_);
	}
	assertion_two(
			sprintf_result_as_size_t_ == constructed_location_message_len_,
			"assertion.c: 176\n");
	assertion_two(expression, constructed_location_message_);
	free(constructed_location_message_);
	free(source_doc_line_as_string_);
}

void
assertion_five(
		int expression, const char * message,
		const char * location_message,
		const char * source_doc_name, const short source_doc_line)
{
	size_t source_doc_name_len_;
	char * source_doc_line_as_string_;
	size_t source_doc_line_as_string_len_;
	size_t constructed_location_message_len_;
	char * constructed_location_message_;
	int sprintf_result_;
	size_t sprintf_result_as_size_t_;
	/*   Will not be able to handle line numbers this large or
	 * higher. E.g. for a value of `1000`, lines allowed are from
	 * line `1` to line `999`. */
	const unsigned short line_upper_bound_ = 1000;
	/*   This is going to hold the _logarithm in base ten_ of
	 * `line_upper_bound_`. In case of powers of ten, the `ceil`ing
	 * of the logarithm in base ten is exactly the logarithm in base
	 * ten. */
	static unsigned char line_upper_bound_logten_ceil_;
	static amara_boolean line_upper_bound_is_power_of_ten_unknown_ =
			/*   Initially, `AMARA_BOOLEAN_TRUE`. After
			 * first execution of this function, always
			 * `AMARA_BOOLEAN_FALSE`. */
			AMARA_BOOLEAN_TRUE;
	static amara_boolean line_upper_bound_is_power_of_ten_;

	assertion_two(location_message[0] == '%', "assertion.c: 220\n");
	assertion_two(location_message[1] == 's', "assertion.c: 118\n");
	assertion_two(location_message[2] == ':', "assertion.c: 215\n");
	assertion_two(location_message[3] == ' ', "assertion.c: 120\n");
	assertion_two(location_message[4] == '%', "assertion.c: 121\n");
	assertion_two(location_message[5] == 'd', "assertion.c: 108\n");
	assertion_two(location_message[6] == '\n', "assertion.c: 125\n");

	source_doc_name_len_ = strlen(source_doc_name);

	assertion_two(source_doc_line > -1, "assertion.c: 131\n");
	assertion_two(source_doc_line < line_upper_bound_,
			"assertion.c: 232\n");

	if (line_upper_bound_is_power_of_ten_unknown_ == AMARA_BOOLEAN_TRUE) {
		assertion_two(line_upper_bound_ == 1000, "assertion.c: 147\n");
		line_upper_bound_is_power_of_ten_unknown_ =
				AMARA_BOOLEAN_FALSE;
		line_upper_bound_is_power_of_ten_ = AMARA_BOOLEAN_TRUE;
		line_upper_bound_logten_ceil_ = 4;
	}
	located_assertion(line_upper_bound_is_power_of_ten_ ==
			AMARA_BOOLEAN_TRUE);

	source_doc_line_as_string_ = malloc(
			/*   Logarithm in base ten of the lines upper
			 * bound constant. This is relevant in the way
			 * e.g., for a lines upper bound of `1000`,
			 * three digits are enough for all included
			 * numbers. The logarithm in base ten of `1000`
			 * is precisely `4`. */
			line_upper_bound_logten_ceil_ - 1
			/*   A reserve provision for a potential `-`
			 * glyph, in case of numeric domain overflow. */
			+ 1
			/*   A reserved space for the chars array
			 * terminator (`\0`). */
			+ 1);
	assertion_two(source_doc_line_as_string_ != NULL,
			"assertion.c: 135\n");

	sprintf_result_ = sprintf(
			source_doc_line_as_string_, "%d", source_doc_line);
	assertion_two(sprintf_result_ > -1, "assertion.c: 141\n");
	sprintf_result_as_size_t_ = sprintf_result_;

	assertion_two(
			sprintf_result_as_size_t_ <
					line_upper_bound_logten_ceil_,
			"assertion.c: 139\n");

	source_doc_line_as_string_len_ = strlen(source_doc_line_as_string_);

	constructed_location_message_len_ =
			source_doc_name_len_
			+ 2 /* ": " */
			+ source_doc_line_as_string_len_
			+ 1 /* '\n' */
			;

	constructed_location_message_ = malloc(
			constructed_location_message_len_
			+ 1 /* '\0' */
	);
	assertion_two(
			constructed_location_message_ != NULL,
			"assertion.c: 137\n");
	sprintf_result_ = sprintf(
			constructed_location_message_, message,
			location_message, source_doc_name, source_doc_line);
	assertion_two(sprintf_result_ > -1, "assertion.c: 162\n");
	sprintf_result_as_size_t_ = sprintf_result_;
	if (sprintf_result_as_size_t_ != constructed_location_message_len_) {
		fprintf(stderr, "assertion.c: 181: %lu %lu %lu %lu %s %s\n", sprintf_result_as_size_t_, constructed_location_message_len_, source_doc_name_len_, source_doc_line_as_string_len_, source_doc_name, constructed_location_message_);
	}
	assertion_two(
			sprintf_result_as_size_t_ == constructed_location_message_len_,
			"assertion.c: 176\n");
	assertion_two(expression, constructed_location_message_);
	free(constructed_location_message_);
	free(source_doc_line_as_string_);
}

void
forced_assertion(int expression)
{
	forced_assertion_two(expression, "WARNING Assertion failed\n");
}

void
forced_assertion_two(int expression, const char * message)
{
	/**  FIXME This repeated allocation MUST be removed. */
	void * call_stack[128];
	char * * call_stack_strings;
	short i, frames;

	if (!expression) {
		fprintf(stderr, "%s\n", message);

	/* WARNING THIS IS ONLY VALID IN LINUX AND MACO (http://stackoverflow.com/questions/3899870/) */
	frames = backtrace(call_stack, 128);
	call_stack_strings = backtrace_symbols(call_stack, frames);
	for (i = 0; i < frames; i++) {
		printf("%s\n", call_stack_strings[i]);
	}
	free(call_stack_strings);

	}

	assert(expression);

	if (!expression) {
		exit(1); /* FIXME 1..? */
	}
}

void
forced_assertion_four(
		int expression, const char * message,
		const char * source_doc_name, const short source_doc_line)
{
	size_t source_doc_name_len_;
	char * source_doc_line_as_string_;
	size_t source_doc_line_as_string_len_;
	size_t constructed_message_len_;
	char * constructed_message_;
	int sprintf_result_;
	size_t sprintf_result_as_size_t_;
	/*   Will not be able to handle line numbers this large or
	 * higher. E.g. for a value of `1000`, lines allowed are from
	 * line `1` to line `999`. */
	const unsigned short line_upper_bound_ = 1000;
	/*   This is going to hold the _logarithm in base ten_ of
	 * `line_upper_bound_`. In case of powers of ten, the `ceil`ing
	 * of the logarithm in base ten is exactly the logarithm in base
	 * ten. */
	static unsigned char line_upper_bound_logten_ceil_;
	static amara_boolean line_upper_bound_is_power_of_ten_unknown_ =
			/*   Initially, `AMARA_BOOLEAN_TRUE`. After
			 * first execution of this function, always
			 * `AMARA_BOOLEAN_FALSE`. */
			AMARA_BOOLEAN_TRUE;
	static amara_boolean line_upper_bound_is_power_of_ten_;

	forced_assertion_two(message[0] == '%', "assertion.c: 117\n");
	forced_assertion_two(message[1] == 's', "assertion.c: 118\n");
	forced_assertion_two(message[2] == ':', "assertion.c: 358\n");
	forced_assertion_two(message[3] == ' ', "assertion.c: 120\n");
	forced_assertion_two(message[4] == '%', "assertion.c: 121\n");
	forced_assertion_two(message[5] == 'd', "assertion.c: 370\n");
	forced_assertion_two(message[6] == '\n', "assertion.c: 125\n");

	source_doc_name_len_ = strlen(source_doc_name);

	forced_assertion_two(source_doc_line > -1, "assertion.c: 131\n");
	forced_assertion_two(source_doc_line < line_upper_bound_,
			"assertion.c: 377\n");

	if (line_upper_bound_is_power_of_ten_unknown_ == AMARA_BOOLEAN_TRUE) {
		forced_assertion_two(line_upper_bound_ == 1000, "assertion.c: 147\n");
		line_upper_bound_is_power_of_ten_unknown_ =
				AMARA_BOOLEAN_FALSE;
		line_upper_bound_is_power_of_ten_ = AMARA_BOOLEAN_TRUE;
		line_upper_bound_logten_ceil_ = 4;
	}
	located_assertion(line_upper_bound_is_power_of_ten_ ==
			AMARA_BOOLEAN_TRUE);

	source_doc_line_as_string_ = malloc(
			/*   Logarithm in base ten of the lines upper
			 * bound constant. This is relevant in the way
			 * e.g., for a lines upper bound of `1000`,
			 * three digits are enough for all included
			 * numbers. The logarithm in base ten of `1000`
			 * is precisely `4`. */
			line_upper_bound_logten_ceil_ - 1
			/*   A reserve provision for a potential `-`
			 * glyph, in case of numeric domain overflow. */
			+ 1
			/*   A reserved space for the chars array
			 * terminator (`\0`). */
			+ 1);
	forced_assertion_two(source_doc_line_as_string_ != NULL,
			"assertion.c: 135\n");

	sprintf_result_ = sprintf(
			source_doc_line_as_string_, "%d", source_doc_line);
	forced_assertion_two(sprintf_result_ > -1, "assertion.c: 141\n");
	sprintf_result_as_size_t_ = sprintf_result_;

	forced_assertion_two(
			sprintf_result_as_size_t_ <
					line_upper_bound_logten_ceil_,
			"assertion.c: 139\n");

	source_doc_line_as_string_len_ = strlen(source_doc_line_as_string_);

	constructed_message_len_ =
			source_doc_name_len_
			+ 2 /* ": " */
			+ source_doc_line_as_string_len_
			+ 1 /* '\n' */
			;

	constructed_message_ = malloc(
			constructed_message_len_
			+ 1 /* '\0' */
	);
	forced_assertion_two(
			constructed_message_ != NULL, "assertion.c: 137\n");
	sprintf_result_ = sprintf(
			constructed_message_, message, source_doc_name,
			source_doc_line);
	forced_assertion_two(sprintf_result_ > -1, "assertion.c: 162\n");
	sprintf_result_as_size_t_ = sprintf_result_;
	if (sprintf_result_as_size_t_ != constructed_message_len_) {
		fprintf(stderr, "assertion.c: 181: %lu %lu %lu %lu %s %s\n", sprintf_result_as_size_t_, constructed_message_len_, source_doc_name_len_, source_doc_line_as_string_len_, source_doc_name, constructed_message_);
	}
	forced_assertion_two(
			sprintf_result_as_size_t_ == constructed_message_len_,
			"assertion.c: 294\n");
	forced_assertion_two(expression, constructed_message_);
	free(constructed_message_);
	free(source_doc_line_as_string_);
}

void
forced_assertion_five(
		int expression, const char * message,
		const char * location_message,
		const char * source_doc_name, const short source_doc_line)
{
	size_t message_len_;
	size_t source_doc_name_len_;
	char * source_doc_line_as_string_;
	size_t source_doc_line_as_string_len_;
	size_t constructed_message_len_;
	char * constructed_message_;
	int sprintf_result_;
	size_t sprintf_result_as_size_t_;
	const char * source_doc_name_stripped_from_full_path_;
	int bison_table_name_strcmp_;
	amara_boolean source_doc_is_the_bison_table_;
	unsigned short line_upper_bound_;
	static unsigned char line_upper_bound_logten_ceil_;
	static amara_boolean line_upper_bound_is_power_of_ten_unknown_;
	static amara_boolean line_upper_bound_is_power_of_ten_;

	/*   Will not be able to handle line numbers this large or
	 * higher. E.g. for a value of `1000`, lines allowed are from
	 * line `1` to line `999`.
	 *   1000 lines is a reasonable number for the source docs of
	 * Amara. However, a Bison symbol table might get larger than
	 * that, so 10000 lines are allowed as an exception. */
	const char * bison_table_name_ = malloc(strlen("minia.tab.c") + 1);
	assertion(bison_table_name_ != NULL);
	strcpy((char *) bison_table_name_, "minia.tab.c");
	source_doc_name_stripped_from_full_path_ =
			strip_from_full_path(source_doc_name);
	bison_table_name_strcmp_ = strcmp(
			source_doc_name_stripped_from_full_path_,
			bison_table_name_);
	source_doc_is_the_bison_table_ = bison_table_name_strcmp_ == 0 ?
			AMARA_BOOLEAN_TRUE : AMARA_BOOLEAN_FALSE;
	line_upper_bound_ =
			source_doc_is_the_bison_table_ == AMARA_BOOLEAN_TRUE ?
					10000 : 1000;
	/*   This is going to hold the _logarithm in base ten_ of
	 * `line_upper_bound_`. In case of powers of ten, the `ceil`ing
	 * of the logarithm in base ten is exactly the logarithm in base
	 * ten. */
	line_upper_bound_is_power_of_ten_unknown_ =
			/*   Initially, `AMARA_BOOLEAN_TRUE`. After
			 * first execution of this function, always
			 * `AMARA_BOOLEAN_FALSE`. */
			AMARA_BOOLEAN_TRUE;

	message_len_ = strlen(message);

	forced_assertion_two(location_message[0] == '%', "assertion.c: 479\n");
	forced_assertion_two(location_message[1] == 's', "assertion.c: 118\n");
	forced_assertion_two(location_message[2] == ' ', "assertion.c: 467\n");
	forced_assertion_two(location_message[3] == '(', "assertion.c: 120\n");
	forced_assertion_two(location_message[4] == '%', "assertion.c: 121\n");
	forced_assertion_two(location_message[5] == 's', "assertion.c: 250\n");
	forced_assertion_two(location_message[6] == ':', "assertion.c: 250\n");
	forced_assertion_two(location_message[7] == '%', "assertion.c: 250\n");
	forced_assertion_two(location_message[8] == 'd', "assertion.c: 250\n");
	forced_assertion_two(location_message[9] == ')', "assertion.c: 250\n");
	forced_assertion_two(location_message[10] == '\n',
			"assertion.c: 125\n");

	source_doc_name_len_ = strlen(source_doc_name);

	forced_assertion_two(source_doc_line > -1, "assertion.c: 131\n");
	forced_assertion_two(source_doc_line < line_upper_bound_,
			"assertion.c: 495\n");

	if (line_upper_bound_is_power_of_ten_unknown_ == AMARA_BOOLEAN_TRUE) {
		forced_assertion_two((line_upper_bound_ == 1000 && source_doc_is_the_bison_table_ == AMARA_BOOLEAN_FALSE) || (line_upper_bound_ == 10000 && source_doc_is_the_bison_table_ == AMARA_BOOLEAN_TRUE), "assertion.c: 543\n");
		line_upper_bound_is_power_of_ten_unknown_ =
				AMARA_BOOLEAN_FALSE;
		line_upper_bound_is_power_of_ten_ = AMARA_BOOLEAN_TRUE;
        line_upper_bound_logten_ceil_ = source_doc_is_the_bison_table_ ==AMARA_BOOLEAN_FALSE?  4:5;
	}
	located_assertion(line_upper_bound_is_power_of_ten_ ==
			AMARA_BOOLEAN_TRUE);

	source_doc_line_as_string_ = malloc(
			/*   Logarithm in base ten of the lines upper
			 * bound constant. This is relevant in the way
			 * e.g., for a lines upper bound of `1000`,
			 * three digits are enough for all included
			 * numbers. The logarithm in base ten of `1000`
			 * is precisely `4`. */
			line_upper_bound_logten_ceil_ - 1
			/*   A reserve provision for a potential `-`
			 * glyph, in case of numeric domain overflow. */
			+ 1
			/*   A reserved space for the chars array
			 * terminator (`\0`). */
			+ 1);
	forced_assertion_two(source_doc_line_as_string_ != NULL,
			"assertion.c: 135\n");

	sprintf_result_ = sprintf(
			source_doc_line_as_string_, "%d", source_doc_line);
	forced_assertion_two(sprintf_result_ > -1, "assertion.c: 141\n");
	sprintf_result_as_size_t_ = sprintf_result_;

	forced_assertion_two(
			sprintf_result_as_size_t_ <
					line_upper_bound_logten_ceil_,
			"assertion.c: 574\n");

	source_doc_line_as_string_len_ = strlen(source_doc_line_as_string_);

	constructed_message_len_ =
			message_len_
			+ 2 /*   " (" */
			+ source_doc_name_len_
			+ 1 /*   ':' */
			+ source_doc_line_as_string_len_
			+ 2 /*   ")\n" */
			;

	constructed_message_ = malloc(
			constructed_message_len_
			+ 1 /* '\0' */
	);
	forced_assertion_two(
			constructed_message_ != NULL, "assertion.c: 137\n");
	sprintf_result_ = sprintf(
			constructed_message_, location_message, message,
			source_doc_name, source_doc_line);
	forced_assertion_two(sprintf_result_ > -1, "assertion.c: 162\n");
	sprintf_result_as_size_t_ = sprintf_result_;
	if (sprintf_result_as_size_t_ != constructed_message_len_) {
		fprintf(stderr, "assertion.c: 181: %lu\n", sprintf_result_as_size_t_);
		fprintf(stderr, "assertion.c: 181: %lu\n", constructed_message_len_);
		fprintf(stderr, "assertion.c: 181: %lu\n", source_doc_name_len_);
		fprintf(stderr, "assertion.c: 181: %lu\n", source_doc_line_as_string_len_);
		fprintf(stderr, "assertion.c: 181: %s\n", source_doc_name);
		fprintf(stderr, "assertion.c: 181: %s\n", constructed_message_);
		fprintf(stderr, "assertion.c: 181: %s\n", message);
	}
	forced_assertion_two(
			sprintf_result_as_size_t_ == constructed_message_len_,
			"assertion.c: 542\n");
	forced_assertion_two(expression, constructed_message_);
	free(constructed_message_);
	free(source_doc_line_as_string_);
}

unsigned char
ends_with_eol(const char * chars_array)
{
	size_t chars_array_len_;

	chars_array_len_ = strlen(chars_array);
	located_assertion(chars_array[chars_array_len_] == '\0');
	if (chars_array[chars_array_len_ - 1] == '\n') {
		return 1;
	}
	return 0;
}

void
forced_unsigned_char_equality_assertion_three(
		unsigned char actual, unsigned char expected,
		const char * message)
{
	/**  FIXME This repeated allocation MUST be removed. */
	void * call_stack[128];
	char * * call_stack_strings;
	short i, frames;

	if (actual != expected) {
		if (ends_with_eol(message)) {
			fprintf(stderr, "%s", message);
		} else {
			fprintf(stderr, "%s\n", message);
		}
		fprintf(stderr, "actual: dec %03u hex 0x%02X\n", actual,
		        actual);
		fprintf(stderr, "expected: dec %03u hex 0x%02X\n", expected,
		        expected);

	/* WARNING THIS IS ONLY VALID IN LINUX AND MACO (http://stackoverflow.com/questions/3899870/) */
	frames = backtrace(call_stack, 128);
	call_stack_strings = backtrace_symbols(call_stack, frames);
	for (i = 0; i < frames; i++) {
		printf("%s\n", call_stack_strings[i]);
	}
	free(call_stack_strings);

	}

	assert(actual == expected);

	if (actual != expected) {
		exit(1); /* FIXME 1..? */
	}
}

void
forced_unsigned_char_equality_assertion_five(
		unsigned char actual, unsigned char expected,
		const char * location_message, const char * source_doc_name,
		const short source_doc_line)
{
	size_t source_doc_name_len_;
	char * source_doc_line_as_string_;
	size_t source_doc_line_as_string_len_;
	size_t constructed_message_len_;
	char * constructed_message_;
	int sprintf_result_;
	size_t sprintf_result_as_size_t_;
	/*   Will not be able to handle line numbers this large or
	 * higher. E.g. for a value of `1000`, lines allowed are from
	 * line `1` to line `999`. */
	const unsigned short line_upper_bound_ = 1000;
	/*   This is going to hold the _logarithm in base ten_ of
	 * `line_upper_bound_`. In case of powers of ten, the `ceil`ing
	 * of the logarithm in base ten is exactly the logarithm in base
	 * ten. */
	static unsigned char line_upper_bound_logten_ceil_;
	static amara_boolean line_upper_bound_is_power_of_ten_unknown_ =
			/*   Initially, `AMARA_BOOLEAN_TRUE`. After
			 * first execution of this function, always
			 * `AMARA_BOOLEAN_FALSE`. */
			AMARA_BOOLEAN_TRUE;
	static amara_boolean line_upper_bound_is_power_of_ten_;

	forced_assertion_two(location_message[0] == '%', "assertion.c: 117\n");
	forced_assertion_two(location_message[1] == 's', "assertion.c: 118\n");
	forced_assertion_two(location_message[2] == ':', "assertion.c: 619\n");
	forced_assertion_two(location_message[3] == ' ', "assertion.c: 120\n");
	forced_assertion_two(location_message[4] == '%', "assertion.c: 121\n");
	forced_assertion_two(location_message[5] == 'd', "assertion.c: 250\n");
	forced_assertion_two(location_message[6] == '\n',
			"assertion.c: 125\n");

	source_doc_name_len_ = strlen(source_doc_name);

	forced_assertion_two(source_doc_line > -1, "assertion.c: 131\n");
	forced_assertion_two(source_doc_line < line_upper_bound_,
			"assertion.c: 667\n");

	if (line_upper_bound_is_power_of_ten_unknown_ == AMARA_BOOLEAN_TRUE) {
		forced_assertion_two(line_upper_bound_ == 1000, "assertion.c: 147\n");
		line_upper_bound_is_power_of_ten_unknown_ =
				AMARA_BOOLEAN_FALSE;
		line_upper_bound_is_power_of_ten_ = AMARA_BOOLEAN_TRUE;
		line_upper_bound_logten_ceil_ = 4;
	}
	located_assertion(line_upper_bound_is_power_of_ten_ ==
			AMARA_BOOLEAN_TRUE);

	source_doc_line_as_string_ = malloc(
			/*   Logarithm in base ten of the lines upper
			 * bound constant. This is relevant in the way
			 * e.g., for a lines upper bound of `1000`,
			 * three digits are enough for all included
			 * numbers. The logarithm in base ten of `1000`
			 * is precisely `4`. */
			line_upper_bound_logten_ceil_ - 1
			/*   A reserve provision for a potential `-`
			 * glyph, in case of numeric domain overflow. */
			+ 1
			/*   A reserved space for the chars array
			 * terminator (`\0`). */
			+ 1);
	forced_assertion_two(source_doc_line_as_string_ != NULL,
			"assertion.c: 135\n");

	sprintf_result_ = sprintf(
			source_doc_line_as_string_, "%d", source_doc_line);
	forced_assertion_two(sprintf_result_ > -1, "assertion.c: 141\n");
	sprintf_result_as_size_t_ = sprintf_result_;

	forced_assertion_two(
			sprintf_result_as_size_t_ <
					line_upper_bound_logten_ceil_,
			"assertion.c: 139\n");

	source_doc_line_as_string_len_ = strlen(source_doc_line_as_string_);

	constructed_message_len_ =
			source_doc_name_len_
			+ 2 /* ": " */
			+ source_doc_line_as_string_len_
			+ 1 /* '\n' */
			;

	constructed_message_ = malloc(
			constructed_message_len_
			+ 1 /* '\0' */
	);
	forced_assertion_two(
			constructed_message_ != NULL, "assertion.c: 137\n");
	sprintf_result_ = sprintf(
			constructed_message_, location_message,
			source_doc_name, source_doc_line);
	forced_assertion_two(sprintf_result_ > -1, "assertion.c: 162\n");
	sprintf_result_as_size_t_ = sprintf_result_;
	if (sprintf_result_as_size_t_ != constructed_message_len_) {
		fprintf(stderr, "assertion.c: 181: %lu %lu %lu %lu %s %s\n", sprintf_result_as_size_t_, constructed_message_len_, source_doc_name_len_, source_doc_line_as_string_len_, source_doc_name, constructed_message_);
	}
	forced_assertion_two(
			sprintf_result_as_size_t_ == constructed_message_len_,
			"assertion.c: 294\n");
	forced_unsigned_char_equality_assertion_three(
			actual, expected, constructed_message_);
	free(constructed_message_);
	free(source_doc_line_as_string_);
}

/*
void disarm_interim(char * message)
{
	const unsigned char traces_printing = 0x00;
	size_t i;
	assertion_two(message != NULL, "expectation was not met");
	if (traces_printing) {
		printf("%lu\n", strlen(message)); */ /* FIXME NOT PORTABLE!!! */ /*
	}
	if (strlen(message) == 0) {
		return;
	}
	for (i = 0; i < strlen(message) - 1; i++) {
		if (traces_printing) {
			printf("iterating... "); */ /* FIXME */ /*
			printf("%lu\n", i);
			printf("%d\n", message[i]);
			printf("%c\n", message[i]);
		}
		if (message[i] == '%' && (message[i + 1] == 's' || message[i + 1] == 'd' || message[i + 1] == 'n')) {
			if (traces_printing) {
				printf("%lu\n", i);
				printf("matches!\n"); */ /* FIXME */ /*
				printf("%lu\n", i);
				printf("%d\n", message[i]);
				printf("%c\n", message[i]);
				printf("%lu\n", i + 1);
				printf("%d\n", message[i + 1]);
				printf("%c\n", message[i + 1]);
			}
			message[i + 1] = '%';
			if (traces_printing) {
				printf("%lu\n", i);
			}
			i++;
			if (traces_printing) {
				printf("%lu\n", i);
			}
		}
	}
}
*/

/*
void
assertion_two_located_interim(
		int expression, const char * message, const char * source_doc,
		unsigned int source_line)
{
	char * message_copy;
	message_copy = NULL;
	if (!expression) {
*/
		/* TODO    Must change in order to use `int sprintf(char * str,
		 * TODO  const char * format, ...)` or one of its alternatives. */
/*
		message_copy = (char *) malloc(strlen(message) + 1);
		strcpy(message_copy, message);
		disarm_interim(message_copy);
		fprintf(stderr, "%s", message_copy);*/  /* XXX */
/*		fprintf(stderr, "%s:", source_doc); */ /* XXX */
/*		fprintf(stderr, "%d\n", source_line); */ /* XXX */
/*	}
	if (message_copy != NULL) {
		free(message_copy);
	}
	assertion(expression);
}
*/

void
interpret_and_assert(const char * expression)
{
	unsigned char expression_numeric_value_;

	assertion(strlen(expression) == 1);

	assertion(expression[0] != '\0');
	assertion(expression[0] >= '0');
	assertion(expression[0] <= '1');
	assertion(expression[1] == '\0');

	expression_numeric_value_ = expression[0] - 48;

	assertion(expression_numeric_value_);
}

void
interpret_and_assert_two(const char * expression, const char * message)
{
	unsigned char expression_numeric_value_;

	assertion_two(strlen(expression) == 1, "expression uses an unexpected length");

	assertion_two(expression[0] != '\0', "unexpected expression");
	assertion_two(expression[0] >= '0', "unexpected expression");
	assertion_two(expression[0] <= '1', "unexpected expression");
	assertion_two(expression[1] == '\0', "unexpected expression");

	expression_numeric_value_ = expression[0] - 48;

	assertion_two(expression_numeric_value_, message);
}
