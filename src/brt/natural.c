/*
 * Copyright 2018 Mercedes Catherine Salazar
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
 * src/brt/natural.c: Algebraic natural number class.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `size_t strlen(const char * s)` and `char * strcpy(char * dest,
 * const char * stc)`. */
#include <string.h>

/*   For `void assertion(int expression)` and for `void assertion_two(
 * int expression, const char * message)`. */
#include "../asr/assertion.h"

/* For `typedef struct stt_node { ... } stt_node`. */
#include "../stt/stt_node.h"

/*   For `int snprintf(char * str, size_t size, const char * format,
 * ...)`. */
#include "../ftr/stdio_ninety_nine_modernizer.h"

/*   For own public definitions. */
#include "natural.h"

natural *
natural_default_constructor(void)
{
	natural * returning_;
	returning_ = malloc(sizeof(natural));
	returning_->raw_ = NULL;
	return returning_;
}

natural *
natural_exhaustive_constructor(const amara_string * raw)
{
	natural * returning_;
	assertion(raw != NULL);
	assert_valid_raw_natural(raw);
	returning_ = malloc(sizeof(natural));
	returning_->raw_ = amara_string_copy_constructor(raw);
	return returning_;
}

natural *
natural_copy_constructor(const natural * natural)
{
	struct natural * returning_;
	assertion(natural != NULL);
	assertion(natural->raw_ != NULL);
	natural_assert_validity(natural);
	returning_ = malloc(sizeof(natural));
	returning_->raw_ = amara_string_copy_constructor(natural->raw_);
	return returning_;
}

void
natural_destructor(natural * natural)
{
	assertion(natural != NULL);
	assertion(natural->raw_ != NULL);
	amara_string_destructor(natural->raw_);
	free(natural);
}

void
natural_copy_unsigned_int_into_natural(
		natural * destination,
		const unsigned int source_unsigned_int)
{
	amara_string * raw_natural;
	if (destination->raw_ != NULL) {
		amara_string_destructor(destination->raw_);
	}
	raw_natural = copy_unsigned_int_into_raw_natural(source_unsigned_int);
	destination->raw_ = raw_natural;
}

void
natural_copy_from_unsigned_int(
		natural * destination,
		const unsigned int source_unsigned_int)
{
	natural_copy_unsigned_int_into_natural(
			destination, source_unsigned_int);
}

void
natural_assert_validity(const natural * natural)
{
	assertion(natural != NULL);
	assertion(natural->raw_ != NULL);
	assert_valid_raw_natural(natural->raw_);
}

void
assert_valid_raw_natural(const amara_string * raw_natural)
{
	const char * raw_natural_char_array_;
	size_t raw_natural_char_array_len_;
	unsigned char indexer_;
	raw_natural_char_array_ = amara_string_get_value(raw_natural);
	raw_natural_char_array_len_ = strlen(raw_natural_char_array_);
	assertion_two(raw_natural_char_array_len_ > 0,
			"found an illegal natural number length (number of digits), natural numbers can not have no digits at all, at least one is necessary");
	assertion_two(raw_natural_char_array_len_ < 4,
			"found an unimplemented natural number length (number of digits)");
	if (raw_natural_char_array_len_ == 1) {
		/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
		 * is `2`, `57` is `9`, `58` is `:`. */
		assertion(raw_natural_char_array_[0] > 47);
		assertion(raw_natural_char_array_[0] < 58);
	} else {
		/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
		 * is `2`, `57` is `9`, `58` is `:`. */
		assertion(raw_natural_char_array_[0] > 48);
		assertion(raw_natural_char_array_[0] < 58);
		for (
				indexer_ = 1;
				indexer_ < raw_natural_char_array_len_;
				indexer_++) {
			/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
			 * is `2`, `57` is `9`, `58` is `:`. */
			assertion(raw_natural_char_array_[indexer_] > 47);
			assertion(raw_natural_char_array_[indexer_] < 58);
		}
	}
}

/*   Both `raw_natural_zero` and `raw_natural_one` are raw natural
 * numbers with exactly the same length (in digits). See `signed char
 * safe_arguments_natural_raw_comparison(
 * const amara_string * raw_natural_zero,
 * const amara_string * raw_natural_one)`. */
signed char
safe_arguments_natural_raw_comparison_inner(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one,
		const size_t raw_naturals_len)
__attribute__((warn_unused_result));

signed char
safe_arguments_natural_raw_comparison_inner(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one,
		const size_t raw_naturals_len)
{
	unsigned char indexer_;
	const char * raw_natural_zero_chars_array_;
	const char * raw_natural_one_chars_array_;
	raw_natural_zero_chars_array_ =
			amara_string_get_value(raw_natural_zero);
	raw_natural_one_chars_array_ =
			amara_string_get_value(raw_natural_one);
	assertion_two(raw_naturals_len > 0,
			"found an illegal natural number length (number of digits), natural numbers can not have no digits at all, at least one is necessary");
	assertion_two(raw_naturals_len < 3,
			"found an unimplemented natural number length (number of digits)");
	for (indexer_ = 0; indexer_ < raw_naturals_len; indexer_++) {
		if (raw_natural_zero_chars_array_[indexer_] <
				raw_natural_one_chars_array_[indexer_]) {
			return ~0x7F;
		} else if (raw_natural_zero_chars_array_[indexer_] >
				raw_natural_one_chars_array_[indexer_]) {
			return 0x7F;
		}
	}
	return 0;
}

signed char
safe_arguments_natural_raw_comparison(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
{
	/*
	const char * raw_natural_zero_chars_array_;
	const char * raw_natural_one_chars_array_;
	*/
	size_t raw_natural_zero_chars_array_len_;
	size_t raw_natural_one_chars_array_len_;
	raw_natural_zero_chars_array_len_ =
			/*
			strlen(raw_natural_zero_chars_array_);
			*/
			amara_string_length(raw_natural_zero);
	raw_natural_one_chars_array_len_ =
			/*
			strlen(raw_natural_one_chars_array_);
			*/
			amara_string_length(raw_natural_one);
	if (raw_natural_zero_chars_array_len_ <
			raw_natural_one_chars_array_len_) {
		return ~0x7F;
	} else if (raw_natural_zero_chars_array_len_ ==
			raw_natural_one_chars_array_len_) {
		return safe_arguments_natural_raw_comparison_inner(
				raw_natural_zero, raw_natural_one,
				raw_natural_zero_chars_array_len_);
	} else {
		assertion(raw_natural_zero_chars_array_len_ >
				raw_natural_one_chars_array_len_);
		return 0x7F;
	}
}

/*   Input `valid_raw_natural` is expected to be valid and canonical,
 * i.e. only digits and no unnecessary leading zeroes. Also it is known
 * that it trivially fits, because its length is less than three. */
fit_raw_natural_in_unsigned_char_ret *
fit_raw_natural_in_unsigned_char_inner_trivially_fits(
		const amara_string * valid_raw_natural)
__attribute__((warn_unused_result));

fit_raw_natural_in_unsigned_char_ret *
fit_raw_natural_in_unsigned_char_inner_trivially_fits(
		const amara_string * valid_raw_natural)
{
	fit_raw_natural_in_unsigned_char_ret * ret_;
	/* unsigned char min_digits_ct_; */
	unsigned char max_digits_ct_;
	size_t valid_raw_natural_len_;
	const char * valid_raw_natural_chars_array_;
	unsigned char current_digit_index_;
	unsigned char current_digit_;
	/* min_digits_ct_ = 1; */
	max_digits_ct_ = 3;
	ret_ = (fit_raw_natural_in_unsigned_char_ret *) malloc(
			sizeof(fit_raw_natural_in_unsigned_char_ret));
	ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_INVALID;
	valid_raw_natural_len_ = amara_string_length(valid_raw_natural);
	valid_raw_natural_chars_array_ =
			amara_string_get_value(valid_raw_natural);
	ret_->value = 0;
	current_digit_index_ = 0;
	/* printf("valid_raw_natural_len_: %lu\n", valid_raw_natural_len_); */
	while (current_digit_index_ < valid_raw_natural_len_) {
		/* printf("current_digit_index_: %u\n", current_digit_index_); */
		/*   `48` is the index of the `0` character. */
		current_digit_ = valid_raw_natural_chars_array_[
				current_digit_index_] - 48;
		/* printf("current_digit_: %u\n", current_digit_); */
		ret_->value += current_digit_;
		/* printf("ret_->value: %u\n", ret_->value); */
		current_digit_index_++;
		if (current_digit_index_ < valid_raw_natural_len_) {
			ret_->value *= 10;
			/* printf("ret_->value: %u\n", ret_->value); */
		}
		assertion_two(current_digit_index_ <= max_digits_ct_, "unexpected raw natural width (in digits)\n");
		/*
		if (current_digit_index_ > max_digits_ct_) {
			fprintf(stderr, "unimplemented condition at %s:%u\n", __FILE__, __LINE__);
		}
		*/
	}
	ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_OK;
	return ret_;
}

/*   Input `valid_raw_natural` is expected to be valid and canonical,
 * i.e. only digits and no unnecessary leading zeroes. Also it is known
 * that it trivially fits, because its length is less than three. */
fit_raw_natural_in_unsigned_short_ret *
fit_raw_natural_in_unsigned_short_inner_trivially_fits(
		const amara_string * valid_raw_natural)
__attribute__((warn_unused_result));

fit_raw_natural_in_unsigned_short_ret *
fit_raw_natural_in_unsigned_short_inner_trivially_fits(
		const amara_string * valid_raw_natural)
{
	fit_raw_natural_in_unsigned_short_ret * ret_;
	/* unsigned char min_digits_ct_; */
	unsigned char max_digits_ct_;
	size_t valid_raw_natural_len_;
	const char * valid_raw_natural_chars_array_;
	unsigned char current_digit_index_;
	unsigned char current_digit_;
	/* min_digits_ct_ = 1; */
	max_digits_ct_ = 5;
	ret_ = malloc(sizeof(fit_raw_natural_in_unsigned_short_ret));
	ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_INVALID;
	valid_raw_natural_len_ = amara_string_length(valid_raw_natural);
	valid_raw_natural_chars_array_ =
			amara_string_get_value(valid_raw_natural);
	ret_->value = 0;
	current_digit_index_ = 0;
	/* printf("valid_raw_natural_len_: %lu\n", valid_raw_natural_len_); */
	while (current_digit_index_ < valid_raw_natural_len_) {
		/* printf("current_digit_index_: %u\n", current_digit_index_); */
		/*   `48` is the index of the `0` character. */
		current_digit_ = valid_raw_natural_chars_array_[
				current_digit_index_] - 48;
		/* printf("current_digit_: %u\n", current_digit_); */
		ret_->value += current_digit_;
		/* printf("ret_->value: %u\n", ret_->value); */
		current_digit_index_++;
		if (current_digit_index_ < valid_raw_natural_len_) {
			ret_->value *= 10;
			/* printf("ret_->value: %u\n", ret_->value); */
		}
		assertion_two(current_digit_index_ <= max_digits_ct_, "unexpected raw natural width (in digits)\n");
		/*
		if (current_digit_index_ > max_digits_ct_) {
			fprintf(stderr, "unimplemented condition at %s:%u\n", __FILE__, __LINE__);
		}
		*/
	}
	ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_OK;
	return ret_;
}

fit_raw_natural_in_unsigned_char_ret *
fit_raw_natural_in_unsigned_char_inner_should_fit(
		const amara_string * valid_raw_natural)
__attribute__((warn_unused_result));

fit_raw_natural_in_unsigned_char_ret *
fit_raw_natural_in_unsigned_char_inner_should_fit(
		const amara_string * valid_raw_natural)
{
	return fit_raw_natural_in_unsigned_char_inner_trivially_fits(
			valid_raw_natural);
}

fit_raw_natural_in_unsigned_short_ret *
fit_raw_natural_in_unsigned_short_inner_should_fit(
		const amara_string * valid_raw_natural)
__attribute__((warn_unused_result))
;

fit_raw_natural_in_unsigned_short_ret *
fit_raw_natural_in_unsigned_short_inner_should_fit(
		const amara_string * valid_raw_natural)
{
	return fit_raw_natural_in_unsigned_short_inner_trivially_fits(
			valid_raw_natural);
}

/*   Input `valid_raw_natural` is expected to be valid and canonical,
 * i.e. only digits and no unnecessary leading zeroes. Also it is known
 * that it might fit or not, because its length is exactly of three and
 * the safe limit is set at `255`. */
fit_raw_natural_in_unsigned_char_ret *
fit_raw_natural_in_unsigned_char_inner_might_fit_or_not(
		const amara_string * valid_raw_natural)
__attribute__((warn_unused_result));

/* XXX    Should rework this, and then reuse the code for the subsequent
 * XXX  widths. */
fit_raw_natural_in_unsigned_char_ret *
fit_raw_natural_in_unsigned_char_inner_might_fit_or_not(
		const amara_string * valid_raw_natural)
{
	fit_raw_natural_in_unsigned_char_ret * ret_;
	const char * valid_raw_natural_chars_array_;
	valid_raw_natural_chars_array_ =
			amara_string_get_value(valid_raw_natural);
	if (valid_raw_natural_chars_array_[0] < '2') {
		free((char *) valid_raw_natural_chars_array_);
		return fit_raw_natural_in_unsigned_char_inner_should_fit(
				valid_raw_natural);
	} else if (valid_raw_natural_chars_array_[0] == '2') {
		if (valid_raw_natural_chars_array_[1] < '5') {
			free((char *) valid_raw_natural_chars_array_);
			return fit_raw_natural_in_unsigned_char_inner_should_fit(
					valid_raw_natural);
		} else if (valid_raw_natural_chars_array_[1] == '5') {
			if (valid_raw_natural_chars_array_[2] < '6') {
				free((char *) valid_raw_natural_chars_array_);
				return fit_raw_natural_in_unsigned_char_inner_should_fit(
						valid_raw_natural);
			} else {
				free((char *) valid_raw_natural_chars_array_);
				ret_ = (fit_raw_natural_in_unsigned_char_ret *)
						malloc(sizeof(fit_raw_natural_in_unsigned_char_ret));
				ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_ERR_DOES_NOT_FIT;
				return ret_;
			}
		} else {
			assertion(valid_raw_natural_chars_array_[1] > '5');
			free((char *) valid_raw_natural_chars_array_);
			ret_ = (fit_raw_natural_in_unsigned_char_ret *)
					malloc(sizeof(fit_raw_natural_in_unsigned_char_ret));
			ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_ERR_DOES_NOT_FIT;
			return ret_;
		}
	} else {
		assertion_two(valid_raw_natural_chars_array_[0] > '2',
				"programming error");
		free((char *) valid_raw_natural_chars_array_);
		ret_ = (fit_raw_natural_in_unsigned_char_ret *)
				malloc(sizeof(fit_raw_natural_in_unsigned_char_ret));
		ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_ERR_DOES_NOT_FIT;
		return ret_;
	}
	/*   This should be unreachable code. */
	/* fprintf(stderr, "reached unreachable code\n");
	exit(EXIT_FAILURE); */
}

/*   Input `valid_raw_natural` is expected to be valid and canonical,
 * i.e. only digits and no unnecessary leading zeroes. Also it is known
 * that it might fit or not, because its length is exactly of five and
 * the safe limit is set at `65535`. */
fit_raw_natural_in_unsigned_short_ret *
fit_raw_natural_in_unsigned_short_inner_might_fit_or_not(
		const amara_string * valid_raw_natural)
__attribute__((warn_unused_result))
;

/* XXX    Should rework this, and then reuse the code for the subsequent
 * XXX  widths. */
fit_raw_natural_in_unsigned_short_ret *
fit_raw_natural_in_unsigned_short_inner_might_fit_or_not(
		const amara_string * valid_raw_natural)
{
	fit_raw_natural_in_unsigned_short_ret * ret_;
	const char * valid_raw_natural_chars_array_;
	valid_raw_natural_chars_array_ =
			amara_string_get_value(valid_raw_natural);
	if (valid_raw_natural_chars_array_[0] < '6') {
		free((char *) valid_raw_natural_chars_array_);
		return fit_raw_natural_in_unsigned_short_inner_should_fit(
				valid_raw_natural);
	} else if (valid_raw_natural_chars_array_[0] == '6') {
		if (valid_raw_natural_chars_array_[1] < '5') {
			free((char *) valid_raw_natural_chars_array_);
			return fit_raw_natural_in_unsigned_short_inner_should_fit(
					valid_raw_natural);
		} else if (valid_raw_natural_chars_array_[1] == '5') {
			/* FIXME!!!!!!!!!! */

			ret_ = malloc(sizeof(
					fit_raw_natural_in_unsigned_short_ret));
			ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_ERR_NOT_FITTING; /* even if it did */
			return ret_;

			/*
			if (valid_raw_natural_chars_array_[2] < '6') {
				free((char *) valid_raw_natural_chars_array_);
				return fit_raw_natural_in_unsigned_short_inner_should_fit(
						valid_raw_natural);
			} else {
				free((char *) valid_raw_natural_chars_array_);
				ret_ = (fit_raw_natural_in_unsigned_short_ret *)
						malloc(sizeof(fit_raw_natural_in_unsigned_char_ret));
				ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_ERR_DOES_NOT_FIT;
				return ret_;
			}
			*/
		} else {
			assertion(valid_raw_natural_chars_array_[1] > '5');
			free((char *) valid_raw_natural_chars_array_);
			ret_ = (fit_raw_natural_in_unsigned_short_ret *)
					malloc(sizeof(fit_raw_natural_in_unsigned_char_ret));
			ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_ERR_NOT_FITTING;
			return ret_;
		}
	} else {
		assertion_two(valid_raw_natural_chars_array_[0] > '6',
				"programming error");
		free((char *) valid_raw_natural_chars_array_);
		ret_ = malloc(sizeof(fit_raw_natural_in_unsigned_short_ret));
		ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_ERR_NOT_FITTING;
		return ret_;
	}
	/*   This should be unreachable code. */
	/* fprintf(stderr, "reached unreachable code\n");
	exit(EXIT_FAILURE); */
}

fit_raw_natural_in_unsigned_char_ret *
fit_raw_natural_in_unsigned_char(const amara_string * valid_raw_natural)
{
	fit_raw_natural_in_unsigned_char_ret * ret_;
	size_t valid_raw_natural_len_;
	valid_raw_natural_len_ = amara_string_length(valid_raw_natural);
	if (valid_raw_natural_len_ < 3) {
		ret_ = fit_raw_natural_in_unsigned_char_inner_trivially_fits(
				valid_raw_natural);
	} else if (valid_raw_natural_len_ == 3) {
		ret_ = fit_raw_natural_in_unsigned_char_inner_might_fit_or_not(
				valid_raw_natural);
	} else {
		assertion(valid_raw_natural_len_ > 3);
		ret_ = (fit_raw_natural_in_unsigned_char_ret *) malloc(
				sizeof(fit_raw_natural_in_unsigned_char_ret));
		ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_ERR_NOT_FITTING;
	}
	return ret_;
}

fit_raw_natural_in_unsigned_short_ret *
fit_raw_natural_in_unsigned_short(const amara_string * valid_raw_natural)
{
	fit_raw_natural_in_unsigned_short_ret * ret_;
	size_t valid_raw_natural_len_;
	valid_raw_natural_len_ = amara_string_length(valid_raw_natural);
	if (valid_raw_natural_len_ < 5) {
		ret_ = fit_raw_natural_in_unsigned_short_inner_trivially_fits(
				valid_raw_natural);
	} else if (valid_raw_natural_len_ == 5) {
		ret_ = fit_raw_natural_in_unsigned_short_inner_might_fit_or_not(
				valid_raw_natural);
	} else {
		assertion(valid_raw_natural_len_ > 5);
		ret_ = (fit_raw_natural_in_unsigned_short_ret *) malloc(
				sizeof(fit_raw_natural_in_unsigned_short_ret));
		ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_ERR_NOT_FITTING;
	}
	return ret_;
}

void
fit_raw_natural_in_unsigned_char_ret_destructor(
		fit_raw_natural_in_unsigned_char_ret * ret)
{
	free(ret);
}

void
fit_raw_natural_in_unsigned_short_ret_destructor(
		fit_raw_natural_in_unsigned_short_ret * ret)
{
	free(ret);
}

amara_string *
copy_unsigned_int_into_raw_natural(const unsigned int input)
{
	char * buffer_;
	amara_string * returning_;
	int snprintf_ret_;
	assertion(input <= 0xFF);
	buffer_ = (char *) malloc(3 + 1);
	snprintf_ret_ = snprintf(
			buffer_, (size_t) (/* 3 + 1 */ 4), "%u", input);
	assertion(snprintf_ret_ >= 0);
	returning_ = amara_string_exhaustive_constructor(buffer_);
	free(buffer_);
	return returning_;
}

amara_string *
copy_pointer_to_unsigned_int_into_raw_natural(const unsigned int * input)
{
	char * buffer_;
	amara_string * returning_;
	int snprintf_ret_;
	assertion(* input <= 0xFF);
	buffer_ = (char *) malloc(3 + 1);
	snprintf_ret_ = snprintf(
			buffer_, (size_t) (/* 3 + 1 */ 4), "%u", * input);
	assertion(snprintf_ret_ >= 0);
	returning_ = amara_string_exhaustive_constructor(buffer_);
	free(buffer_);
	return returning_;
}

amara_string *
copy_unsigned_char_into_raw_natural(unsigned char input)
{
	char * buffer_;
	amara_string * returning_;
	int snprintf_ret_;
	buffer_ = (char *) malloc(3 + 1);
	snprintf_ret_ = snprintf(
			buffer_, (size_t) (/* 3 + 1 */ 4), "%u", input);
	assertion(snprintf_ret_ >= 0);
	returning_ = amara_string_exhaustive_constructor(buffer_);
	free(buffer_);
	return returning_;
}

amara_string *
copy_unsigned_short_into_raw_natural(unsigned short input)
{
	char * buffer_;
	amara_string * returning_;
	int snprintf_ret_;
	buffer_ = malloc(5 + 1);
	snprintf_ret_ = snprintf(
			buffer_, (size_t) (/* 5 + 1 */ 6), "%u", input);
	assertion(snprintf_ret_ >= 0);
	returning_ = amara_string_exhaustive_constructor(buffer_);
	free(buffer_);
	return returning_;
}

const char * machine_numeric_overflow = "MACHINE_NUMERIC_OVERFLOW";

/*   Must return the result of substracting `raw_natural_one` from
 * `raw_natural_zero`. Without being destructive on its input. */
amara_string *
raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
__attribute__((warn_unused_result));

amara_string *
raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
{
	fit_raw_natural_in_unsigned_char_ret * zero_fit_ret_;
	fit_raw_natural_in_unsigned_char_ret * one_fit_ret_;
	unsigned char substraction_result_;
	char * returning_chars_array_;
	amara_string * returning_;
	zero_fit_ret_ = fit_raw_natural_in_unsigned_char(
			raw_natural_zero);
	if (zero_fit_ret_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_ERR_NOT_FITTING) {
		returning_chars_array_ =
				malloc(strlen(machine_numeric_overflow) + 1);
		strcpy(returning_chars_array_, machine_numeric_overflow);
		returning_ = amara_string_exhaustive_constructor(
				returning_chars_array_);
		free(zero_fit_ret_);
		free(returning_chars_array_);
		return returning_;
	}
	one_fit_ret_ = fit_raw_natural_in_unsigned_char(
			raw_natural_one);
	if (one_fit_ret_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_ERR_NOT_FITTING) {
		returning_chars_array_ =
				malloc(strlen(machine_numeric_overflow) + 1);
		strcpy(returning_chars_array_, machine_numeric_overflow);
		returning_ = amara_string_exhaustive_constructor(
				returning_chars_array_);
		free(zero_fit_ret_);
		free(one_fit_ret_);
		free(returning_chars_array_);
		return returning_;
	}
	assertion(zero_fit_ret_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_OK);
	assertion(one_fit_ret_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_OK);
	/* printf("zero_fit_ret_->value: %u\n", zero_fit_ret_->value); */ /* FIXME */
	/* printf("one_fit_ret_->value: %u\n", one_fit_ret_->value); */ /* FIXME */
	substraction_result_ = zero_fit_ret_->value - one_fit_ret_->value;
	/* printf("substraction_result_: %u\n", substraction_result_); */ /* FIXME */
	free(zero_fit_ret_);
	free(one_fit_ret_);
	return copy_unsigned_char_into_raw_natural(substraction_result_);
}

amara_string *
raw_naturals_multiplication_as_raw_natural(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
{
	fit_raw_natural_in_unsigned_char_ret * zero_fit_ret_;
	fit_raw_natural_in_unsigned_char_ret * one_fit_ret_;
	/* unsigned char multiplication_result_8_; */
	unsigned short multiplication_result_16_;
	char * returning_chars_array_;
	amara_string * returning_;
	zero_fit_ret_ = fit_raw_natural_in_unsigned_char(
			raw_natural_zero);
	if (zero_fit_ret_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_ERR_NOT_FITTING) {
		returning_chars_array_ =
				malloc(strlen(machine_numeric_overflow) + 1);
		strcpy(returning_chars_array_, machine_numeric_overflow);
		returning_ = amara_string_exhaustive_constructor(
				returning_chars_array_);
		fit_raw_natural_in_unsigned_char_ret_destructor(zero_fit_ret_);
		free(returning_chars_array_);
		return returning_;
	}
	one_fit_ret_ = fit_raw_natural_in_unsigned_char(
			raw_natural_one);
	if (one_fit_ret_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_ERR_NOT_FITTING) {
		returning_chars_array_ =
				malloc(strlen(machine_numeric_overflow) + 1);
		strcpy(returning_chars_array_, machine_numeric_overflow);
		returning_ = amara_string_exhaustive_constructor(
				returning_chars_array_);
		fit_raw_natural_in_unsigned_char_ret_destructor(zero_fit_ret_);
		fit_raw_natural_in_unsigned_char_ret_destructor(one_fit_ret_);
		free(returning_chars_array_);
		return returning_;
	}
	assertion(zero_fit_ret_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_OK);
	assertion(one_fit_ret_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_OK);
	/* printf("zero_fit_ret_->value: %u\n", zero_fit_ret_->value); */ /* FIXME */
	/* printf("one_fit_ret_->value: %u\n", one_fit_ret_->value); */ /* FIXME */
	/* multiplication_result_8_ = zero_fit_ret_->value * one_fit_ret_->value; */
	if (~0 /* multiplication_result_8_ < zero_fit_ret_->value ||
			multiplication_result_8_ < one_fit_ret_->value */) {
		multiplication_result_16_ = zero_fit_ret_->value *
				one_fit_ret_->value;
		if (multiplication_result_16_ == zero_fit_ret_->value) {
			assertion(multiplication_result_16_ >=
					one_fit_ret_->value);
		} else if (multiplication_result_16_ == one_fit_ret_->value) {
			assertion(multiplication_result_16_ >=
					zero_fit_ret_->value);
		} else {
			assertion(multiplication_result_16_ >
					zero_fit_ret_->value);
			assertion(multiplication_result_16_ >
					one_fit_ret_->value);
		}
		/* printf("multiplication_result_: %u\n", multiplication_result_); */ /* FIXME */
		fit_raw_natural_in_unsigned_char_ret_destructor(zero_fit_ret_);
		fit_raw_natural_in_unsigned_char_ret_destructor(one_fit_ret_);
		return copy_unsigned_short_into_raw_natural(
				multiplication_result_16_);
	}
	/* printf("multiplication_result_: %u\n", multiplication_result_); */ /* FIXME */
	fit_raw_natural_in_unsigned_char_ret_destructor(zero_fit_ret_);
	fit_raw_natural_in_unsigned_char_ret_destructor(one_fit_ret_);
	return NULL /* unsigned_char_to_raw_natural(multiplication_result_8_) */;
}

amara_string *
raw_naturals_division_as_raw_natural(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
{
	fit_raw_natural_in_unsigned_char_ret * r_n_zero_fits_8_bits_ret_;
	fit_raw_natural_in_unsigned_short_ret * r_n_zero_fits_16_bits_ret_;
	fit_raw_natural_in_unsigned_char_ret * r_n_one_fits_8_bits_ret_;
	amara_boolean use_8_bits_for_numerator_;
	amara_boolean use_16_bits_for_numerator_;
	amara_boolean use_8_bits_for_denominator_;
	unsigned char raw_natural_zero_as_unsigned_char_;
	unsigned short raw_natural_zero_as_unsigned_short_;
	unsigned char raw_natural_one_as_unsigned_char_;
	unsigned char eight_bits_division_result_;
	unsigned short sixteen_bits_division_result_;
	char * returning_chars_array_;
	amara_string * returning_;
	use_8_bits_for_numerator_ = AMARA_BOOLEAN_FALSE;
	use_16_bits_for_numerator_ = AMARA_BOOLEAN_FALSE;
	r_n_zero_fits_8_bits_ret_ = NULL;
	r_n_zero_fits_16_bits_ret_ = NULL;
	r_n_one_fits_8_bits_ret_ = NULL;
	r_n_zero_fits_8_bits_ret_ = fit_raw_natural_in_unsigned_char(
			raw_natural_zero);
	if (r_n_zero_fits_8_bits_ret_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_ERR_NOT_FITTING) {
		r_n_zero_fits_16_bits_ret_ = fit_raw_natural_in_unsigned_short(
				raw_natural_zero);
		if (r_n_zero_fits_16_bits_ret_->status ==
				FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_ERR_NOT_FITTING) {
			returning_chars_array_ = malloc(
					strlen(machine_numeric_overflow) + 1);
			strcpy(
					returning_chars_array_,
					machine_numeric_overflow);
			returning_ = amara_string_exhaustive_constructor(
					returning_chars_array_);
			fit_raw_natural_in_unsigned_char_ret_destructor(
					r_n_zero_fits_8_bits_ret_);
			fit_raw_natural_in_unsigned_short_ret_destructor(
					r_n_zero_fits_16_bits_ret_);
			free(returning_chars_array_);
			return returning_;
		} else {
			assertion(r_n_zero_fits_16_bits_ret_->status ==
					FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_OK);
			use_16_bits_for_numerator_ = AMARA_BOOLEAN_TRUE;
			raw_natural_zero_as_unsigned_short_ =
					r_n_zero_fits_16_bits_ret_->value;
		}
	} else {
		assertion(r_n_zero_fits_8_bits_ret_->status ==
				FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_OK);
		use_8_bits_for_numerator_ = AMARA_BOOLEAN_TRUE;
		raw_natural_zero_as_unsigned_char_ =
				r_n_zero_fits_8_bits_ret_->value;
	}
	r_n_one_fits_8_bits_ret_ = fit_raw_natural_in_unsigned_char(
			raw_natural_one);
	assertion(r_n_one_fits_8_bits_ret_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_OK);
	use_8_bits_for_denominator_ = AMARA_BOOLEAN_TRUE;
	raw_natural_one_as_unsigned_char_ = r_n_one_fits_8_bits_ret_->value;
	if (r_n_one_fits_8_bits_ret_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_ERR_NOT_FITTING) {
		returning_chars_array_ =
				malloc(strlen(machine_numeric_overflow) + 1);
		strcpy(returning_chars_array_, machine_numeric_overflow);
		returning_ = amara_string_exhaustive_constructor(
				returning_chars_array_);
		fit_raw_natural_in_unsigned_char_ret_destructor(
				r_n_zero_fits_8_bits_ret_);
		if (r_n_zero_fits_16_bits_ret_ != NULL) {
			fit_raw_natural_in_unsigned_short_ret_destructor(
					r_n_zero_fits_16_bits_ret_);
		}
		fit_raw_natural_in_unsigned_char_ret_destructor(
				r_n_one_fits_8_bits_ret_);
		free(returning_chars_array_);
		return returning_;
	} else {
		assertion(r_n_one_fits_8_bits_ret_->status ==
				FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_OK);
	}
	/* printf("zero_fit_ret_->value: %u\n", zero_fit_ret_->value); */ /* FIXME */
	/* printf("one_fit_ret_->value: %u\n", one_fit_ret_->value); */ /* FIXME */
	if (use_8_bits_for_numerator_ == AMARA_BOOLEAN_TRUE) {
		assertion(use_8_bits_for_denominator_ == AMARA_BOOLEAN_TRUE);
		eight_bits_division_result_ = raw_natural_zero_as_unsigned_char_ / /* XXX extract completely before using. */
				raw_natural_one_as_unsigned_char_; /* XXX extract completely before using. */
	} else {
		assertion(use_16_bits_for_numerator_ == AMARA_BOOLEAN_TRUE);
		assertion(use_8_bits_for_denominator_ == AMARA_BOOLEAN_TRUE);
		sixteen_bits_division_result_ = raw_natural_zero_as_unsigned_short_ / /* XXX extract completely before using. */
				raw_natural_one_as_unsigned_char_; /* XXX extract completely before using. */
	}
	/* printf("division_result_: %u\n", division_result_); */ /* FIXME */
	fit_raw_natural_in_unsigned_char_ret_destructor(
			r_n_zero_fits_8_bits_ret_);
	if (r_n_zero_fits_16_bits_ret_ != NULL) {
		fit_raw_natural_in_unsigned_short_ret_destructor(
				r_n_zero_fits_16_bits_ret_);
	}
	fit_raw_natural_in_unsigned_char_ret_destructor(
			r_n_one_fits_8_bits_ret_);
	if (use_8_bits_for_numerator_ == AMARA_BOOLEAN_TRUE) {
		assertion(use_8_bits_for_denominator_ == AMARA_BOOLEAN_TRUE);
		return copy_unsigned_char_into_raw_natural(
				eight_bits_division_result_);
	} else {
		assertion(use_16_bits_for_numerator_ == AMARA_BOOLEAN_TRUE);
		assertion(use_8_bits_for_denominator_ == AMARA_BOOLEAN_TRUE);
		return copy_unsigned_short_into_raw_natural(
				sixteen_bits_division_result_);
	}
}

/*   This is non destructive towards its arguments. */
stt_node *
numeric_natural_nodes_multiplication_types_checked_both_are_valid_raw_naturals(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
__attribute__((warn_unused_result))
;

stt_node *
numeric_natural_nodes_multiplication_types_checked_both_are_valid_raw_naturals(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
{
	amara_string * raw_natural_;
	stt_node * returning_;
	raw_natural_ = raw_naturals_multiplication_as_raw_natural(
			raw_natural_zero, raw_natural_one);
	returning_ = stt_node_wrapping_raw_natural(raw_natural_);
	return returning_;
}

/*   This is non destructive towards its arguments. */
stt_node *
numeric_natural_nodes_division_types_checked_both_are_valid_raw_naturals(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
__attribute__((warn_unused_result));

stt_node *
numeric_natural_nodes_division_types_checked_both_are_valid_raw_naturals(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
{
	amara_string * raw_natural_;
	stt_node * returning_;
	raw_natural_ = raw_naturals_division_as_raw_natural(
			raw_natural_zero, raw_natural_one);
	returning_ = stt_node_wrapping_raw_natural(raw_natural_);
	return returning_;
}

/*   This is non destructive towards its arguments. */
stt_node *
numeric_natural_nodes_substraction_types_checked_both_are_valid_raw_naturals(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
__attribute__((warn_unused_result));

stt_node *
numeric_natural_nodes_substraction_types_checked_both_are_valid_raw_naturals(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
{
	signed char comparison_result_;
	/*   Substraction results as a raw natural (characters array). */
	amara_string * raw_natural_;
	stt_node * returning_;
	/* printf("raw_natural_zero: %s\n", raw_natural_zero);
	fprintf(stderr, "raw_natural_one: %s\n", raw_natural_one); */
	comparison_result_ = safe_arguments_natural_raw_comparison(
			raw_natural_zero, raw_natural_one);
	/* printf("raw_natural_zero: %s\n", raw_natural_zero);
	fprintf(stderr, "raw_natural_one: %s\n", raw_natural_one); */
	if (comparison_result_ < 0) {
		assertion_two(0, "right now can not substract b from a if a is lesser than b");
		fprintf(stderr, "right now can not substract b from a if a is lesset than b\n");
		exit(EXIT_FAILURE);
	} else if (comparison_result_ == 0) {
		return stt_node_wrapping_raw_natural(
				amara_string_exhaustive_constructor("0"));
	} else {
		assertion(comparison_result_ > 0);
		raw_natural_ = raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one(
				raw_natural_zero, raw_natural_one);
		returning_ = stt_node_wrapping_raw_natural(raw_natural_);
		return returning_;
	}
}

/*   This is non destructive towards its arguments. */
stt_node *
simplify_natural_literal_nodes_multiplication(
		const stt_node * node_zero, const stt_node * node_one)
{
	stt_node * returning_;
	/* can include:
	 * - natural node (trivially multipliable)
	 * - identifier node (multipliable because the semantic analysis confirms)
	 * - operation node (multipliabe because the semantic analysis confirms)
	 */
	assertion(node_zero->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assert_pure_natural_literal_node(node_zero);
	assert_valid_raw_natural(node_zero->natural_literal_subnode_->raw_);
	assertion(node_one->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assert_pure_natural_literal_node(node_one);
	assert_valid_raw_natural(node_one->natural_literal_subnode_->raw_);
	returning_ = numeric_natural_nodes_multiplication_types_checked_both_are_valid_raw_naturals(
			node_zero->natural_literal_subnode_->raw_,
			node_one->natural_literal_subnode_->raw_);
	return returning_;
}

/*   This is non destructive towards its arguments. */
stt_node *
simplify_natural_literal_nodes_division(
		const stt_node * node_zero, const stt_node * node_one)
{
	stt_node * returning_;
	assertion(node_zero->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assert_pure_natural_literal_node(node_zero);
	assert_valid_raw_natural(node_zero->natural_literal_subnode_->raw_);
	assertion(node_one->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assert_pure_natural_literal_node(node_one);
	assert_valid_raw_natural(node_one->natural_literal_subnode_->raw_);
	returning_ = numeric_natural_nodes_division_types_checked_both_are_valid_raw_naturals(
			node_zero->natural_literal_subnode_->raw_,
			node_one->natural_literal_subnode_->raw_);
	return returning_;
}

/*   This is non destructive towards its arguments. */
stt_node *
simplify_natural_literal_nodes_substraction(
		const stt_node * node_zero, const stt_node * node_one)
{
	stt_node * returning_;
	assertion(node_zero->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(node_zero->natural_literal_subnode_ != NULL);
	assertion(node_zero->natural_literal_subnode_->raw_ != NULL);
	assert_valid_raw_natural(node_zero->natural_literal_subnode_->raw_);
	assertion(node_one->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(node_one->natural_literal_subnode_ != NULL);
	assertion(node_one->natural_literal_subnode_->raw_ != NULL);
	assert_valid_raw_natural(node_one->natural_literal_subnode_->raw_);
	returning_ = numeric_natural_nodes_substraction_types_checked_both_are_valid_raw_naturals(
			node_zero->natural_literal_subnode_->raw_,
			node_one->natural_literal_subnode_->raw_);
	return returning_;
}
