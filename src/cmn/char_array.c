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
 * src/cmn/char_array.c: Utilities for character arrays.
 */

/*   For `uint_fast8_t`. */
#include <stdint.h>

/*   For `int snprintf(char * str, size_t size,
 * const char * format, ...)`, and for `int fprintf(FILE * stream,
 * const char * format, ...)`. */
#include <stdio.h>

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `size_t strlen(const char * s)`. */
#include <string.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For C99 `int snprintf(char * str, size_t size,
 * const char * format, ...)` in case building with C89. */
#include "../ftr/stdio_ninety_nine_modernizer.h"

const uint_fast8_t max_concatenation_length_in_bytes = UINT8_MAX;
const uint_fast8_t max_concatenation_length_in_chars = UINT8_MAX - 1;

char *
concatenate_two_char_arrays(const char * zero, const char * one)
{
	/* uint_fast8_t length_; */
	uint_fast8_t zero_length_;
	char * ret_;
	uint_fast8_t one_length_;
	uint_fast8_t combined_length_;
	int snprintf_ret_;
	zero_length_ = strlen(zero);
	if (zero_length_ >= max_concatenation_length_in_chars) {
		ret_ = (char *) malloc(max_concatenation_length_in_bytes);
		snprintf_ret_ = snprintf(
				ret_, max_concatenation_length_in_chars + 1,
				"%s", zero);
		if (snprintf_ret_ >= max_concatenation_length_in_bytes) {
			fprintf(stderr, "%s:%u - aborting operation", __FILE__,
					__LINE__);
			exit(EXIT_FAILURE);
		}
		return ret_;
	}
	assertion(zero_length_ < max_concatenation_length_in_chars);
	one_length_ = strlen(one);
	if (zero_length_ + one_length_ >= max_concatenation_length_in_chars) {
		ret_ = (char *) malloc(max_concatenation_length_in_bytes);
		snprintf_ret_ = snprintf(
				ret_, max_concatenation_length_in_chars + 1,
				"%s%s", zero, one);
		if (snprintf_ret_ >= max_concatenation_length_in_bytes) {
			fprintf(stderr, "%s:%u - aborting operation", __FILE__,
					__LINE__);
			exit(EXIT_FAILURE);
		}
		return ret_;
	}
	combined_length_ = zero_length_ + one_length_;
	assertion(combined_length_ < max_concatenation_length_in_chars);
	ret_ = (char *) malloc(combined_length_ + 1);
	snprintf_ret_ = snprintf(
			ret_, combined_length_ + 1, "%s%s", zero, one);
	if (snprintf_ret_ >= max_concatenation_length_in_bytes) {
		fprintf(stderr, "%s:%u - aborting operation", __FILE__,
				__LINE__);
		exit(EXIT_FAILURE);
	}
	return ret_;
}

char *
concatenate_three_char_arrays(
		const char * zero, const char * one, const char * two)
{
	char * ret_;
	const char * inner_ret_;
	inner_ret_ = concatenate_two_char_arrays(zero, one);
	ret_ = concatenate_two_char_arrays(inner_ret_, two);
	return ret_;
}

char *
concatenate_four_char_arrays(
		const char * zero, const char * one, const char * two,
		const char * three)
{
	char * ret_;
	const char * inner_ret_;
	inner_ret_ = concatenate_three_char_arrays(zero, one, two);
	ret_ = concatenate_two_char_arrays(inner_ret_, three);
	return ret_;
}
