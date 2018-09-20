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
 * src/brt/rational.c: Algebraic rational number class.
 */

/*   For `size_t strlen(const char * s)` and `char * strcpy(char * dest,
 * const char * stc)`. */
#include <string.h>

/*   For `void assertion(int expression)` and for `void assertion_two(
 * int expression, const char * message)`. */
#include "../asr/assertion.h"

/*   For own public definitions. */
#include "rational.h"

void
assert_valid_raw_rational(const amara_string * raw_rational)
{
	const char * raw_rational_chars_array_;
	size_t raw_rational_chars_array_len_;
	uint_fast8_t indexer_;
	/* amara_boolean negative_; */
	raw_rational_chars_array_ = amara_string_get_value(raw_rational);
	raw_rational_chars_array_len_ = strlen(raw_rational_chars_array_);
	assertion_two(raw_rational_chars_array_len_ > 0,
			"found an illegal rational number length (number of digits), rational numbers can not have no digits at all, at least one digit is necessary");
	assertion_two(raw_rational_chars_array_len_ > 1,
			"found an unimplemented rational number length (number of digits)");
	assertion_two(raw_rational_chars_array_len_ < 4,
			"found an unimplemented rational number length (number of digits)");
	indexer_ = 0;
	/* negative_ = AMARA_BOOLEAN_FALSE; */
	if (raw_rational_chars_array_[indexer_] == '-') {
		/* negative_ = AMARA_BOOLEAN_TRUE; */
		indexer_ += 1;
	}
	if (raw_rational_chars_array_len_ == 2) {
		/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
		 * is `2`, `57` is `9`, `58` is `:`. */
		assertion(raw_rational_chars_array_[1] > 47);
		assertion(raw_rational_chars_array_[1] < 58);
	} else {
		/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
		 * is `2`, `57` is `9`, `58` is `:`. */
		assertion(raw_rational_chars_array_[1] > 48);
		assertion(raw_rational_chars_array_[1] < 58);
		for (
				indexer_ = 2;
				indexer_ < raw_rational_chars_array_len_;
				indexer_++) {
			/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
			 * is `2`, `57` is `9`, `58` is `:`. */
			assertion(raw_rational_chars_array_[indexer_] > 47);
			assertion(raw_rational_chars_array_[indexer_] < 58);
		}
	}
}
