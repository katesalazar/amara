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

/*   For `int snprintf(char * str, size_t size, const char * format,
 * ...)`. */
#include "../ftr/stdio_ninety_nine_modernizer.h"

/*   For own public definitions. */
#include "natural.h"

natural *
natural_default_constructor(void)
{
	natural * returning_;

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(natural *)
#endif
			malloc(sizeof(natural));
	forced_assertion_two(returning_ != NULL, "natural.c: 49\n");
	returning_->raw_ = NULL;
	return returning_;
}

natural *
natural_exhaustive_constructor(const amara_string * raw)
{
	natural * returning_;

#ifndef NDEBUG
	assertion(raw != NULL);
	assert_valid_raw_natural(raw);
#endif
	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(natural *)
#endif
			malloc(sizeof(natural));
	forced_assertion_two(returning_ != NULL, "natural.c: 69\n");
	returning_->raw_ = amara_string_copy_constructor(raw);
	return returning_;
}

natural *
natural_copy_constructor(const natural * input)
{
	natural * returning_;

	assertion(input != NULL);
	assertion(input->raw_ != NULL);
	natural_assert_validity(input);
	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(natural *)
#endif
			malloc(sizeof(input));
	forced_assertion_two(returning_ != NULL, "natural.c: 86\n");
	returning_->raw_ = amara_string_copy_constructor(input->raw_);
	return returning_;
}

void
natural_destructor(natural * natural)
{
#ifndef NDEBUG
	assertion(natural != NULL);
	assertion(natural->raw_ != NULL);
#endif
	amara_string_destructor(natural->raw_);
	free(natural);
}

#ifndef NDEBUG

void
natural_assert_healthy(const natural * natural)
{
	natural_assert_validity(natural);
}

#endif

void
natural_copy_unsigned_short_into_natural(
		natural * destination,
		const unsigned short source_unsigned_short)
{
	amara_string * raw_natural;
	if (destination->raw_ != NULL) {
		amara_string_destructor(destination->raw_);
	}
	raw_natural = natural_copy_unsigned_short_into_raw_natural(
			source_unsigned_short);
	destination->raw_ = raw_natural;
}

void
natural_copy_from_unsigned_short(
		natural * destination,
		const unsigned short source_unsigned_short)
{
	natural_copy_unsigned_short_into_natural(
			destination, source_unsigned_short);
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
	free((char *) raw_natural_char_array_);
}

amara_boolean
well_formed_raw_natural(const amara_string * raw_natural)
{
	/* XXX never returning false? */

	assert_valid_raw_natural(raw_natural);
	return AMARA_BOOLEAN_TRUE;
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
	free((char *) raw_natural_zero_chars_array_);
	free((char *) raw_natural_one_chars_array_);
			return ~0x7F;
		} else if (raw_natural_zero_chars_array_[indexer_] >
				raw_natural_one_chars_array_[indexer_]) {
	free((char *) raw_natural_zero_chars_array_);
	free((char *) raw_natural_one_chars_array_);
			return 0x7F;
		}
	}
	free((char *) raw_natural_zero_chars_array_);
	free((char *) raw_natural_one_chars_array_);
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
	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(fit_raw_natural_in_unsigned_char_ret *)
#endif
			malloc(sizeof(fit_raw_natural_in_unsigned_char_ret));
	forced_assertion(ret_ != NULL);
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
	free((char *) valid_raw_natural_chars_array_);
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
	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(fit_raw_natural_in_unsigned_short_ret *)
#endif
			malloc(sizeof(fit_raw_natural_in_unsigned_short_ret));
	forced_assertion_two(ret_ != NULL, "natural.c: 339\n");
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
	free((char *) valid_raw_natural_chars_array_);
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

			ret_ =
#ifdef AMARA_USE_STD_CXX98
					(fit_raw_natural_in_unsigned_short_ret *)
#endif
					malloc(sizeof(fit_raw_natural_in_unsigned_short_ret));
			forced_assertion_two(ret_ != NULL, "natural.c: 497\n");
			ret_->status = FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_ERR_NOT_FITTING; /* even if it did */
			free((char *) valid_raw_natural_chars_array_);
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
		ret_ =
#ifdef AMARA_USE_STD_CXX98
				(fit_raw_natural_in_unsigned_short_ret *)
#endif
				malloc(sizeof(fit_raw_natural_in_unsigned_short_ret));
		forced_assertion_two(ret_ != NULL, "natural.c: 527\n");
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
		ret_ =
				(fit_raw_natural_in_unsigned_char_ret *)
				malloc(sizeof(fit_raw_natural_in_unsigned_char_ret));
		forced_assertion(ret_ != NULL);
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
natural_copy_unsigned_char_into_raw_natural(const unsigned char input)
{
	char * buffer_;
	amara_string * returning_;
	int snprintf_ret_;
	buffer_ = (char *) malloc(3 + 1);
	snprintf_ret_ = snprintf(
			buffer_, (size_t) (/* 3 + 1 */ 4), "%u", input);
	assertion(snprintf_ret_ >= 0);
	returning_ = amara_string_exhaustive_constructor(buffer_);
	forced_assertion(returning_ != NULL);
	free(buffer_);
	return returning_;
}

amara_string *
natural_copy_unsigned_short_into_raw_natural(const unsigned short input)
{
	char * buffer_;
	amara_string * returning_;
	int snprintf_ret_;

	buffer_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(5 + 1);
	forced_assertion_two(buffer_ != NULL, "natural.c: 612\n");
	snprintf_ret_ = snprintf(
			buffer_, (size_t) (/* 5 + 1 */ 6), "%hu", input);
	assertion(snprintf_ret_ >= 0);
	returning_ = amara_string_exhaustive_constructor(buffer_);
	free(buffer_);
	return returning_;
}

amara_string *
natural_copy_unsigned_long_into_raw_natural(const unsigned long input)
{
	char * buffer_;
	amara_string * returning_;
	int snprintf_ret_;
	assertion(input <= 0xFF);
	buffer_ = (char *) malloc(3 + 1);
	snprintf_ret_ = snprintf(
			buffer_, (size_t) (/* 3 + 1 */ 4), "%lu", input);
	assertion(snprintf_ret_ >= 0);
	returning_ = amara_string_exhaustive_constructor(buffer_);
	free(buffer_);
	return returning_;
}

amara_string *
natural_copy_pointer_to_unsigned_short_into_raw_natural(
		const unsigned short * input)
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
natural_copy_pointer_to_unsigned_long_into_raw_natural(
		const unsigned long * input)
{
	char * buffer_;
	amara_string * returning_;
	int snprintf_ret_;
	assertion(* input <= 0xFF);
	buffer_ = (char *) malloc(3 + 1);
	snprintf_ret_ = snprintf(
			buffer_, (size_t) (/* 3 + 1 */ 4), "%lu", * input);
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
#ifdef AMARA_USE_STD_CXX98
				(char *)
#endif
				malloc(strlen(machine_numeric_overflow) + 1);
		forced_assertion_two(returning_chars_array_ != NULL,
				"natural.c: 711\n");
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
#ifdef AMARA_USE_STD_CXX98
				(char *)
#endif
				malloc(strlen(machine_numeric_overflow) + 1);
		forced_assertion_two(returning_chars_array_ != NULL,
				"natural.c: 730\n");
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
	return natural_copy_unsigned_char_into_raw_natural(
			substraction_result_);
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
#ifdef AMARA_USE_STD_CXX98
				(char *)
#endif
				malloc(strlen(machine_numeric_overflow) + 1);
		forced_assertion_two(returning_chars_array_ != NULL,
				"natural.c: 775\n");
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
#ifdef AMARA_USE_STD_CXX98
				(char *)
#endif
				malloc(strlen(machine_numeric_overflow) + 1);
		forced_assertion_two(returning_chars_array_ != NULL,
				"natural.c: 793\n");
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
		return natural_copy_unsigned_short_into_raw_natural(
				multiplication_result_16_);
	}
	/* printf("multiplication_result_: %u\n", multiplication_result_); */ /* FIXME */
	/*
	fit_raw_natural_in_unsigned_char_ret_destructor(zero_fit_ret_);
	fit_raw_natural_in_unsigned_char_ret_destructor(one_fit_ret_);
	return NULL;
	*/
	/* return unsigned_char_to_raw_natural(multiplication_result_8_) */;
}

amara_string *
raw_naturals_euclidean_quotient_as_raw_natural(
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
			returning_chars_array_ =
#ifdef AMARA_USE_STD_CXX98
					(char *)
#endif
					malloc(strlen(machine_numeric_overflow) + 1);
			forced_assertion_two(returning_chars_array_ != NULL,
					"natural.c: 878\n");
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
			/*   In order to calm static analysis dissent. */
			raw_natural_zero_as_unsigned_char_ = ~0x00;
			/*   Actual code. */
			raw_natural_zero_as_unsigned_short_ =
					r_n_zero_fits_16_bits_ret_->value;
		}
	} else {
		assertion(r_n_zero_fits_8_bits_ret_->status ==
				FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_OK);
		use_8_bits_for_numerator_ = AMARA_BOOLEAN_TRUE;
		/*   Actual code. */
		raw_natural_zero_as_unsigned_char_ =
				r_n_zero_fits_8_bits_ret_->value;
		/*   In order to calm static analysis dissent. */
		raw_natural_zero_as_unsigned_short_ = ~0x0000;
	}
	r_n_one_fits_8_bits_ret_ = fit_raw_natural_in_unsigned_char(
			raw_natural_one);
	/*
	assertion(r_n_one_fits_8_bits_ret_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_OK);
	*/
	use_8_bits_for_denominator_ = AMARA_BOOLEAN_TRUE;
	raw_natural_one_as_unsigned_char_ = r_n_one_fits_8_bits_ret_->value;
	if (r_n_one_fits_8_bits_ret_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_CHAR_RET_STATUS_ERR_NOT_FITTING) {
		returning_chars_array_ =
#ifdef AMARA_USE_STD_CXX98
				(char *)
#endif
				malloc(strlen(machine_numeric_overflow) + 1);
		forced_assertion_two(returning_chars_array_ != NULL,
				"natural.c: 926\n");
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
		/*   Actual code. */
		eight_bits_division_result_ = raw_natural_zero_as_unsigned_char_ / /* XXX extract completely before using. */ /* FIXME this will fail badly if dividing 3 in 2 (returning 1 instead of 1.5 */
				raw_natural_one_as_unsigned_char_; /* XXX extract completely before using. */
		/*   In order to calm static analysis dissent. */
		sixteen_bits_division_result_ = ~0x0000;
	} else {
		assertion(use_16_bits_for_numerator_ == AMARA_BOOLEAN_TRUE);
		assertion(use_8_bits_for_denominator_ == AMARA_BOOLEAN_TRUE);
		/*   In order to calm static analysis dissent. */
		eight_bits_division_result_ = ~0x00;
		/*   Actual code. */
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
		return natural_copy_unsigned_char_into_raw_natural(
				eight_bits_division_result_);
	} else {
		assertion(use_16_bits_for_numerator_ == AMARA_BOOLEAN_TRUE);
		assertion(use_8_bits_for_denominator_ == AMARA_BOOLEAN_TRUE);
		return natural_copy_unsigned_short_into_raw_natural(
				sixteen_bits_division_result_);
	}
}

amara_boolean
naturals_less_than(const natural * n0, const natural * n1)
{
	unsigned char n0_as_unsigned_char_;
	unsigned char n1_as_unsigned_char_;

	forced_assertion(n0 != NULL);
	forced_assertion(n0->raw_ != NULL);
	forced_assertion(well_formed_raw_natural(n0->raw_));
	forced_assertion(n0->raw_->value_[0] != '\0');
	if (n0->raw_->value_[1] != '\0') {
		forced_assertion(n0->raw_->value_[2] == '\0');
	}
	forced_assertion(n1 != NULL);
	forced_assertion(n1->raw_ != NULL);
	forced_assertion(well_formed_raw_natural(n1->raw_));
	forced_assertion(n1->raw_->value_[0] != '\0');
	if (n1->raw_->value_[1] != '\0') {
		forced_assertion(n1->raw_->value_[2] == '\0');
	}

	n0_as_unsigned_char_ = atoi(n0->raw_->value_);
	n1_as_unsigned_char_ = atoi(n1->raw_->value_);

	if (n0_as_unsigned_char_ < n1_as_unsigned_char_) {

		return AMARA_BOOLEAN_TRUE;
	}

	return AMARA_BOOLEAN_FALSE;
}

amara_boolean
naturals_greater_than(const natural * n0, const natural * n1)
{
	unsigned char n0_as_unsigned_char_;
	unsigned char n1_as_unsigned_char_;

	forced_assertion(n0 != NULL);
	forced_assertion(n0->raw_ != NULL);
	forced_assertion(well_formed_raw_natural(n0->raw_));
	forced_assertion(n0->raw_->value_[0] != '\0');
	if (n0->raw_->value_[1] != '\0') {
		forced_assertion(n0->raw_->value_[2] == '\0');
	}
	forced_assertion(n1 != NULL);
	forced_assertion(n1->raw_ != NULL);
	forced_assertion(well_formed_raw_natural(n1->raw_));
	forced_assertion(n1->raw_->value_[0] != '\0');
	if (n1->raw_->value_[1] != '\0') {
		forced_assertion(n1->raw_->value_[2] == '\0');
	}

	n0_as_unsigned_char_ = atoi(n0->raw_->value_);
	n1_as_unsigned_char_ = atoi(n1->raw_->value_);

	if (n0_as_unsigned_char_ > n1_as_unsigned_char_) {

		return AMARA_BOOLEAN_TRUE;
	}

	return AMARA_BOOLEAN_FALSE;
}

amara_boolean
natural_equality(const natural * n0, const natural * n1)
{
#ifndef NDEBUG
	assertion(n0 != NULL);
	assertion(n1 != NULL);
#endif

#ifndef NDEBUG
	assertion(n0->raw_ != NULL);
	assertion(n1->raw_ != NULL);
#endif

	return amara_strings_equality(n0->raw_, n1->raw_);
}

amara_boolean
naturals_equality(const natural * n0, const natural * n1)
{
	return natural_equality(n0, n1);
}
