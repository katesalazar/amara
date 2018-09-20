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
 * src/brt/natural.h: Algebraic natural number class.
 */

#ifndef __AMARA__BASIC_ARITHMETIC__NATURAL__H__
#define __AMARA__BASIC_ARITHMETIC__NATURAL__H__

/* For `typedef struct stt_node { ... } stt_node`. */
#include "../stt/stt_node.h"

/*   Asserts that the string represents a valid and canonical raw
 * natural.
 *   Valid: only digits.
 *   Canonical: not left padded by zeros. */
void
assert_valid_raw_natural(const amara_string * raw_natural)
;

#define FIT_RAW_NATURAL_IN_UINT_FAST8_T_RET_STATUS_INVALID          0x00
#define FIT_RAW_NATURAL_IN_UINT_FAST8_T_RET_STATUS_ERR_NOT_FITTING  0x01
#define FIT_RAW_NATURAL_IN_UINT_FAST8_T_RET_STATUS_OK               0xFF
#define FIT_RAW_NATURAL_IN_UINT_FAST8_T_RET_STATUS_ERR_DOES_NOT_FIT \
		FIT_RAW_NATURAL_IN_UINT_FAST8_T_RET_STATUS_ERR_NOT_FITTING

typedef struct fit_raw_natural_in_uint_fast8_t_ret {
	uint_fast8_t status;
	uint_fast8_t value;
} fit_raw_natural_in_uint_fast8_t_ret;

/*   Input `valid_raw_natural` is expected to be valid and canonical,
 * i.e. only digits and no unnecessary leading zeroes. */
fit_raw_natural_in_uint_fast8_t_ret *
fit_raw_natural_in_uint_fast8_t(const amara_string * valid_raw_natural)
__attribute__((warn_unused_result));

void
fit_raw_natural_in_uint_fast8_t_ret_destructor(
		fit_raw_natural_in_uint_fast8_t_ret * ret)
;

amara_string *
uint_fast8_t_to_raw_natural(uint_fast8_t input)
__attribute__((warn_unused_result));

/*   Shoud return negative integer, zero, or positive integer, as the
 * first argument is less than, equal, or greater than the second. Both
 * arguments are valid canonical raw natural numbers. */
int_fast8_t
safe_arguments_natural_raw_comparison(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
__attribute__((warn_unused_result));

/*   Non destructive in its arguments.
 *   `node_zero` minus `node_one`. */
stt_node *
numeric_natural_nodes_substraction(
		const stt_node * node_zero, const stt_node * node_one)
__attribute__((warn_unused_result));

/*   Non destructive in its arguments.
 *   `raw_natural_zero` divided by `raw_natural_one`. */
amara_string *
raw_naturals_division_as_raw_natural(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
__attribute__((warn_unused_result));

/*   Non destructive in its arguments.
 *   `node_zero` divided by `node_one`. */
stt_node *
numeric_natural_nodes_division(
		const stt_node * node_zero, const stt_node * node_one)
__attribute__((warn_unused_result));

#endif
