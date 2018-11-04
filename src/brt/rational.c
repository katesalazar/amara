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

/*   FIXME This is missing correct validation for strings in the form of
 * `0.0+[1-9]`, among other missing cases (see `rational_tests.c`). This
 * might probably be better if converted to a boolean function, but that
 * is not completely clear. I mean, the lexer is supposedly already
 * filtering strings which are not valid rational numbers. */
void
assert_valid_raw_rational(const amara_string * raw_rational)
{
	const char * raw_rational_chars_array_;
	size_t raw_rational_chars_array_len_;
	unsigned char indexer_;
	signed char dot_index_;

	raw_rational_chars_array_ = amara_string_get_value(raw_rational);
	raw_rational_chars_array_len_ = strlen(raw_rational_chars_array_);
	assertion_two(raw_rational_chars_array_len_ > 0, "found an illegal rational number length (number of digits), rational numbers can not have no digits at all, at least one digit is necessary");
	assertion_two(raw_rational_chars_array_len_ > 1, "found an unimplemented rational number length (number of digits)");
	/*
	assertion_two(raw_rational_chars_array_len_ < 4, "found an unimplemented rational number length (number of digits)");
	*/
	dot_index_ = -1;
	if (raw_rational_chars_array_[0] == '-') {

		assertion_two(raw_rational_chars_array_len_ > 2, "found an unimplemented rational number length (number of digits)");
		if (raw_rational_chars_array_[1] == '.') {

			indexer_ = 2;
			dot_index_ = 1;
		} else {

			indexer_ = 1;
		}
	} else if (raw_rational_chars_array_[0] == '.') {

		indexer_ = 1;
		dot_index_ = 0;
	} else {

		indexer_ = 0;
	}
	if (dot_index_ == -1) {

		if (raw_rational_chars_array_[indexer_ + 1] == '.') {

			/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
			 * is `2`, `57` is `9`, `58` is `:`. */
			assertion(raw_rational_chars_array_[indexer_] > 47);
			assertion(raw_rational_chars_array_[indexer_] < 58);
		} else {

			/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
			 * is `2`, `57` is `9`, `58` is `:`. */
			assertion(raw_rational_chars_array_[indexer_] > 48);
			assertion(raw_rational_chars_array_[indexer_] < 58);
		}
	} else {

		if (dot_index_ != 0) {

			assertion(dot_index_ == 1);
		}
		/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
		 * is `2`, `57` is `9`, `58` is `:`. */
		assertion(raw_rational_chars_array_[indexer_] > 47);
		assertion(raw_rational_chars_array_[indexer_] < 58);
	}
	while (indexer_ < raw_rational_chars_array_len_) {

		if (dot_index_ == -1) {

			if (raw_rational_chars_array_[indexer_] == '.') {

				dot_index_ = indexer_;
			} else {

				/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
				 * is `2`, `57` is `9`, `58` is `:`. */
				assertion(raw_rational_chars_array_[indexer_] > 47);
				assertion(raw_rational_chars_array_[indexer_] < 58);
			}
		} else {

			/*   ASCII `47` is `/`, `48` is `0`, `49` is `1`, `50`
			 * is `2`, `57` is `9`, `58` is `:`. */
			assertion(raw_rational_chars_array_[indexer_] > 47);
			assertion(raw_rational_chars_array_[indexer_] < 58);
		}
		indexer_ += 1;
	}
}
