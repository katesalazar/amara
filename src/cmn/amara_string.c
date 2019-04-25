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
 * src/cmn/amara_string.c: Self explanatory...
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `size_t strlen(const char * s)` and `char * strcpy(char * dest,
 * const char * src)`. */
#include <string.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "amara_string.h"

amara_string *
amara_string_default_constructor()
{
	amara_string * ret_;

	ret_ = malloc(sizeof(amara_string));
	forced_assertion(ret_ != NULL);
	ret_->value_ = NULL;

	return ret_;
}

#ifndef MAX_STRING_LEN
#define MAX_STRING_LEN 4096
#endif

amara_string *
amara_string_exhaustive_constructor(const char * value)
{
	amara_string * ret_;
	size_t value_len_;
	const size_t new_string_max_len_ = MAX_STRING_LEN;
	size_t new_string_len_;

	value_len_ = strlen(value);
	new_string_len_ = value_len_;
	forced_assertion(new_string_len_ <= new_string_max_len_);

	ret_ = malloc(sizeof(amara_string));
	forced_assertion(ret_ != NULL);
	ret_->value_ = malloc(new_string_len_ + 1);
	forced_assertion(ret_->value_ != NULL);
	strcpy(ret_->value_, value);

	return ret_;
}

amara_string *
amara_string_exhaustive_constructor_three(
		const char * ca0, const char * ca1, const char * ca2)
{
	amara_string * ret_;
	size_t ca0_len_;
	size_t ca1_len_;
	size_t ca2_len_;
	const size_t new_string_max_len_ = MAX_STRING_LEN;
	size_t new_string_len_;

	ca0_len_ = strlen(ca0);
	ca1_len_ = strlen(ca1);
	ca2_len_ = strlen(ca2);
	new_string_len_ = ca0_len_;
	forced_assertion(new_string_len_ <= new_string_max_len_);
	new_string_len_ += ca1_len_;
	forced_assertion(new_string_len_ <= new_string_max_len_);
	new_string_len_ += ca2_len_;
	forced_assertion(new_string_len_ <= new_string_max_len_);

	ret_ = malloc(sizeof(amara_string));
	forced_assertion(ret_ != NULL);
	ret_->value_ = malloc(new_string_len_ + 1);
	forced_assertion(ret_->value_ != NULL);
	strcpy(ret_->value_, ca0);
	strcat(ret_->value_, ca1);
	strcat(ret_->value_, ca2);

	return ret_;
}

amara_string *
amara_string_copy_constructor(const amara_string * as)
{
	amara_string * ret_;
	char * as_value_;

	ret_ = malloc(sizeof(amara_string));
	forced_assertion(ret_ != NULL);
	as_value_ = amara_string_get_value(as);
	forced_assertion(as_value_ != NULL);
	ret_->value_ = malloc(strlen(as_value_) + 1);
	forced_assertion(ret_->value_ != NULL);
	strcpy(ret_->value_, as_value_);
	free(as_value_);

	return ret_;
}

void
amara_string_destructor(amara_string * string)
{
	assertion(string != NULL);
	if (string->value_ != NULL) {
		free(string->value_);
	}
	free(string);
}

#ifndef NDEBUG

void
amara_string_assert_healthy(const amara_string * string)
{
	assertion(string != NULL);
	assertion(string->value_ != NULL);
}

#endif

char *
amara_string_get_value(const amara_string * string)
{
	char * value_copy_;

	if (string == NULL) {

		value_copy_ = malloc(1);
		value_copy_[0] = 0x00;  /* '\0'. */
	} else {

		value_copy_ = malloc(strlen(string->value_) + 1);
		strcpy(value_copy_, string->value_);
	}

	return value_copy_;
}

void
amara_string_set_value(amara_string * string, const char * value)
{
	string->value_ = malloc(strlen(value) + 1);
	strcpy(string->value_, value);
}

size_t
amara_string_length(const amara_string * string)
{
	assertion(string != NULL);
	assertion(string->value_ != NULL);
	return strlen(string->value_);
}

int
amara_string_strcmp(const amara_string * s1, const amara_string * s2)
{
	assertion(s1 != NULL);
	assertion(s1->value_ != NULL);
	assertion(s2 != NULL);
	assertion(s2->value_ != NULL);

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "%s:%u:s1->value_: %s\n", __FILE__, __LINE__, s1->value_);
	fprintf(stderr, "%s:%u:s2->value_: %s\n", __FILE__, __LINE__, s2->value_);
#endif

	return strcmp(s1->value_, s2->value_);
}

amara_boolean
amara_string_equality(const amara_string * a1, const amara_string * a2)
{
	int amara_string_strcmp_ret_;

	if (a1 == NULL && a2 == NULL) { /* XXX */
		return AMARA_BOOLEAN_TRUE; /* XXX */
	} /* XXX */

	if (a1 == NULL) {

		if (a2->value_[0] == 0x00) {  /* '\0'. */  /* XXX */

			return AMARA_BOOLEAN_TRUE;  /* XXX */
		} else {  /* XXX */

			return AMARA_BOOLEAN_FALSE;
		}  /* XXX */
	}

	if (a2 == NULL) {

		if (a1->value_[0] == 0x00) {  /* '\0'. */  /* XXX */

			return AMARA_BOOLEAN_TRUE;  /* XXX */
		} else {  /* XXX */

			return AMARA_BOOLEAN_FALSE;
		}  /* XXX */
	}

	amara_string_strcmp_ret_ = amara_string_strcmp(a1, a2);

	if (amara_string_strcmp_ret_) {

		return AMARA_BOOLEAN_FALSE;
	} else {

		return AMARA_BOOLEAN_TRUE;
	}
}

amara_boolean
amara_strings_equality(const amara_string * a1, const amara_string * a2)
{
	return amara_string_equality(a1, a2);
}
