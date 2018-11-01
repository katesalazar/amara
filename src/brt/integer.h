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
 * src/brt/integer.h: Algebraic integer number class.
 */

#ifndef __AMARA__BASIC_ARITHMETIC__INTEGER__H__
#define __AMARA__BASIC_ARITHMETIC__INTEGER__H__

/* For `typedef struct stt_node { ... } stt_node`. */
#include "../stt/stt_node.h"

/*   Asserts that the string represents a valid and canonical raw
 * integer.
 *   Valid: only digits.
 *   Canonical: not left padded by zeros. */
void
assert_valid_raw_integer(const amara_string * raw_integer)
;

#define FIT_RAW_INTEGER_IN_SIGNED_CHAR_RET_STATUS_INVALID          0x00
#define FIT_RAW_INTEGER_IN_SIGNED_CHAR_RET_STATUS_ERR_DOES_NOT_FIT 0x01
#define FIT_RAW_INTEGER_IN_SIGNED_CHAR_RET_STATUS_OK               0xFF

typedef struct fit_raw_integer_in_signed_char_ret {
	unsigned char status;
	signed char value;
} fit_raw_integer_in_signed_char_ret;

/*   Input `valid_raw_integer` is expected to be valid and canonical,
 * i.e. a `-` character, and then only digits and no unnecessary
 * _leading_ zeroes after the `-` character. */
fit_raw_integer_in_signed_char_ret *
fit_raw_integer_in_signed_char(const amara_string * valid_raw_integer)
__attribute__((warn_unused_result))
;

void
fit_raw_integer_in_signed_char_ret_destructor(
		fit_raw_integer_in_signed_char_ret * ret)
;

amara_string *
signed_char_to_raw_integer(signed char input)
__attribute__((warn_unused_result))
;

/*   Shoud return negative integer, zero, or positive integer, as the
 * first argument is less than, equal, or greater than the second. Both
 * arguments are valid canonical raw integer numbers. */
signed char
safe_arguments_integer_raw_comparison(
		const amara_string * raw_integer_zero,
		const amara_string * raw_integer_one)
__attribute__((warn_unused_result))
;

/*   Non destructive in its arguments.
 *   `node_zero` minus `node_one`. */
stt_node *
numeric_integer_nodes_substraction(
		const stt_node * node_zero, const stt_node * node_one)
__attribute__((warn_unused_result));

/*   Non destructive in its arguments.
 *   `raw_integer_zero` divided by `raw_integer_one`. */
amara_string *
raw_integers_division_as_raw_integer(
		const amara_string * raw_integer_zero,
		const amara_string * raw_integer_one)
__attribute__((warn_unused_result));

/*   Non destructive in its arguments.
 *   `node_zero` divided by `node_one`. */
stt_node *
numeric_integer_nodes_division(
		const stt_node * node_zero, const stt_node * node_one)
__attribute__((warn_unused_result));

/*   `raw_integer` must be a valid raw integer: only digits and no
 * unnecessary left padding zeroes. */
stt_node *
stt_node_from_raw_integer(const amara_string * raw_integer)
__attribute__((warn_unused_result));

#endif
