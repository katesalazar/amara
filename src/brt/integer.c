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
 * src/brt/integer.c: Algebraic integer number class.
 */

/*   For `size_t strlen(const char * s)` and `char * strcpy(char * dest,
 * const char * stc)`. */
#include <string.h>

/*   For `void assertion(int expression)` and for `void assertion_two(
 * int expression, const char * message)`. */
#include "../asr/assertion.h"

/*   For own public definitions. */
#include "integer.h"

void
assert_valid_raw_integer(const amara_string * raw_integer)
{
	const char * raw_integer_chars_array_;
	size_t raw_integer_chars_array_len_;
	uint_fast8_t indexer_;
	raw_integer_chars_array_ = amara_string_get_value(raw_integer);
	raw_integer_chars_array_len_ = strlen(raw_integer_chars_array_);
	assertion_two(raw_integer_chars_array_len_ > 0,
			"found an illegal integer number length (number of digits), integer numbers can not have no digits at all, at least one digit is necessary, and the `-` character is required");
	assertion_two(raw_integer_chars_array_len_ > 1,
			"found an unimplemented integer number length (number of digits)");
	assertion_two(raw_integer_chars_array_len_ < 4,
			"found an unimplemented integer number length (number of digits)");
	assertion_two(raw_integer_chars_array_[0] == '-',
			"an integer number must begin with a `-` character");
	if (raw_integer_chars_array_len_ == 2) {
		/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
		 * is `2`, `57` is `9`, `58` is `:`. */
		assertion(raw_integer_chars_array_[1] > 47);
		assertion(raw_integer_chars_array_[1] < 58);
	} else {
		/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
		 * is `2`, `57` is `9`, `58` is `:`. */
		assertion(raw_integer_chars_array_[1] > 48);
		assertion(raw_integer_chars_array_[1] < 58);
		for (
				indexer_ = 2;
				indexer_ < raw_integer_chars_array_len_;
				indexer_++) {
			/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
			 * is `2`, `57` is `9`, `58` is `:`. */
			assertion(raw_integer_chars_array_[indexer_] > 47);
			assertion(raw_integer_chars_array_[indexer_] < 58);
		}
	}
}
