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
 * src/brt/basic_arithmetic_tests.c: Self explanatory...
 */

/*   For `int_fast8_t`. */
#include <stdint.h>

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `NULL`. */
#include <stdlib.h>

/*   For `int strcmp(const char * s1, const char * s2)`. */
#include <string.h>

/*   For `void assertion_two(int expression, const char * message)`. */
#include "../asr/assertion.h"

/*   For `int_fast8_t safe_arguments_natural_raw_comparison(
 * const char * raw_natural_zero, const char * raw_natural_one)`, and
 * for `typedef struct fit_raw_natural_in_uint_fast8_t_ret { ... }
 * fit_raw_natural_in_uint_fast8_t_ret`, and for several others. */
#include "natural.h"

void
safe_arguments_natural_raw_comparison_test_0(void)
;

void
safe_arguments_natural_raw_comparison_test_1(void)
;

void
safe_arguments_natural_raw_comparison_test_2(void)
;

void
safe_arguments_natural_raw_comparison_test_3(void)
;

void
safe_arguments_natural_raw_comparison_test_4(void)
;

void
safe_arguments_natural_raw_comparison_tests(void)
;

void
fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_0(void)
;

void
fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_1(void)
;

void
fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_2(void)
;

void
fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_3(void)
;

void
fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_4(void)
;

void
fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_tests(void)
;

void
fit_raw_natural_in_uint_fast8_t_test_0(void)
;

void
fit_raw_natural_in_uint_fast8_t_tests(void)
;

void
raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one_test_0(void)
;

void
raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one_test_1(void)
;

void
raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one_tests(void)
;

void
raw_naturals_division_as_raw_natural_test_0(void)
;

void
raw_naturals_division_as_raw_natural_test_1(void)
;

void
raw_naturals_division_as_raw_natural_tests(void)
;

void
numeric_natural_nodes_substraction_test_0(void)
;

void
numeric_natural_nodes_substraction_tests(void)
;

void
natural_tests(void)
;

void
safe_arguments_natural_raw_comparison_test_0()
{
	const char * raw_natural_zero_chars_array_ = "0";
	const char * raw_natural_one_chars_array_ = "0";
	const amara_string * raw_natural_zero_ =
			amara_string_exhaustive_constructor(
					raw_natural_zero_chars_array_);
	const amara_string * raw_natural_one_ =
			amara_string_exhaustive_constructor(
					raw_natural_one_chars_array_);
	const int_fast8_t result_ = safe_arguments_natural_raw_comparison(
			raw_natural_zero_, raw_natural_one_);
	assertion_two(result_ == 0, "unexpected result");
	amara_string_destructor((amara_string *) raw_natural_zero_);
	amara_string_destructor((amara_string *) raw_natural_one_);
	/* FIXME attempt to free a non heap object */
	/*
	free((char *) raw_natural_zero_chars_array_);
	free((char *) raw_natural_one_chars_array_);
	*/
}

void
safe_arguments_natural_raw_comparison_test_1()
{
	const char * raw_natural_zero_chars_array_ = "0";
	const char * raw_natural_one_chars_array_ = "1";
	const amara_string * raw_natural_zero_ =
			amara_string_exhaustive_constructor(
					raw_natural_zero_chars_array_);
	const amara_string * raw_natural_one_ =
			amara_string_exhaustive_constructor(
					raw_natural_one_chars_array_);
	const int_fast8_t result_ = safe_arguments_natural_raw_comparison(
			raw_natural_zero_, raw_natural_one_);
	assertion_two(result_ < 0, "unexpected result");
	amara_string_destructor((amara_string *) raw_natural_zero_);
	amara_string_destructor((amara_string *) raw_natural_one_);
	/* FIXME attempt to free a non heap object */
	/*
	free((char *) raw_natural_zero_chars_array_);
	free((char *) raw_natural_one_chars_array_);
	*/
}

void
safe_arguments_natural_raw_comparison_test_2()
{
	const char * raw_natural_zero_chars_array_ = "0";
	const char * raw_natural_one_chars_array_ = "10";
	const amara_string * raw_natural_zero_ =
			amara_string_exhaustive_constructor(
					raw_natural_zero_chars_array_);
	const amara_string * raw_natural_one_ =
			amara_string_exhaustive_constructor(
					raw_natural_one_chars_array_);
	const int_fast8_t result_ = safe_arguments_natural_raw_comparison(
			raw_natural_zero_, raw_natural_one_);
	assertion_two(result_ < 0, "unexpected result");
	amara_string_destructor((amara_string *) raw_natural_zero_);
	amara_string_destructor((amara_string *) raw_natural_one_);
	/* FIXME attempt to free a non heap object */
	/*
	free((char *) raw_natural_zero_chars_array_);
	free((char *) raw_natural_one_chars_array_);
	*/
}

void
safe_arguments_natural_raw_comparison_test_3()
{
	const char * raw_natural_zero_chars_array_ = "1";
	const char * raw_natural_one_chars_array_ = "0";
	const amara_string * raw_natural_zero_ =
			amara_string_exhaustive_constructor(
					raw_natural_zero_chars_array_);
	const amara_string * raw_natural_one_ =
			amara_string_exhaustive_constructor(
					raw_natural_one_chars_array_);
	const int_fast8_t result_ = safe_arguments_natural_raw_comparison(
			raw_natural_zero_, raw_natural_one_);
	assertion_two(result_ > 0, "unexpected result");
	amara_string_destructor((amara_string *) raw_natural_zero_);
	amara_string_destructor((amara_string *) raw_natural_one_);
	/* FIXME attempt to free a non heap object */
	/*
	free((char *) raw_natural_zero_chars_array_);
	free((char *) raw_natural_one_chars_array_);
	*/
}

void
safe_arguments_natural_raw_comparison_test_4()
{
	const char * raw_natural_zero_chars_array_ = "10";
	const char * raw_natural_one_chars_array_ = "0";
	const amara_string * raw_natural_zero_ =
			amara_string_exhaustive_constructor(
					raw_natural_zero_chars_array_);
	const amara_string * raw_natural_one_ =
			amara_string_exhaustive_constructor(
					raw_natural_one_chars_array_);
	const int_fast8_t result_ = safe_arguments_natural_raw_comparison(
			raw_natural_zero_, raw_natural_one_);
	assertion_two(result_ > 0, "unexpected result");
	amara_string_destructor((amara_string *) raw_natural_zero_);
	amara_string_destructor((amara_string *) raw_natural_one_);
	/* FIXME attempt to free a non heap object */
	/*
	free((char *) raw_natural_zero_chars_array_);
	free((char *) raw_natural_one_chars_array_);
	*/
}

void
safe_arguments_natural_raw_comparison_tests()
{
	safe_arguments_natural_raw_comparison_test_0();
	safe_arguments_natural_raw_comparison_test_1();
	safe_arguments_natural_raw_comparison_test_2();
	safe_arguments_natural_raw_comparison_test_3();
	safe_arguments_natural_raw_comparison_test_4();
}

fit_raw_natural_in_uint_fast8_t_ret *
fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not(
		const amara_string * valid_raw_natural)
__attribute__((warn_unused_result));

void
fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_0()
{
	const char * raw_natural_chars_array_ = "123";
	const amara_string * raw_natural_ =
			amara_string_exhaustive_constructor(
					raw_natural_chars_array_);
	const fit_raw_natural_in_uint_fast8_t_ret * ret_ =
			fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not(
					raw_natural_);
	assertion(ret_->status ==
			FIT_RAW_NATURAL_IN_UINT_FAST8_T_RET_STATUS_OK);
}

void
fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_1()
{
	const char * raw_natural_chars_array_ = "234";
	const amara_string * raw_natural_ =
			amara_string_exhaustive_constructor(
					raw_natural_chars_array_);
	const fit_raw_natural_in_uint_fast8_t_ret * ret_ =
			fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not(
					raw_natural_);
	assertion(ret_->status ==
			FIT_RAW_NATURAL_IN_UINT_FAST8_T_RET_STATUS_OK);
}

void
fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_2()
{
	const char * raw_natural_chars_array_ = "255";
	const amara_string * raw_natural_ =
			amara_string_exhaustive_constructor(
					raw_natural_chars_array_);
	const fit_raw_natural_in_uint_fast8_t_ret * ret_ =
			fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not(
					raw_natural_);
	assertion(ret_->status ==
			FIT_RAW_NATURAL_IN_UINT_FAST8_T_RET_STATUS_OK);
}

void
fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_3()
{
	const char * raw_natural_chars_array_ = "260";
	const amara_string * raw_natural_ =
			amara_string_exhaustive_constructor(
					raw_natural_chars_array_);
	const fit_raw_natural_in_uint_fast8_t_ret * ret_ =
			fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not(
					raw_natural_);
	assertion(ret_->status ==
			FIT_RAW_NATURAL_IN_UINT_FAST8_T_RET_STATUS_ERR_DOES_NOT_FIT);
}

void
fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_4()
{
	const char * raw_natural_chars_array_ = "300";
	const amara_string * raw_natural_ =
			amara_string_exhaustive_constructor(
					raw_natural_chars_array_);
	const fit_raw_natural_in_uint_fast8_t_ret * ret_ =
			fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not(
					raw_natural_);
	assertion(ret_->status ==
			FIT_RAW_NATURAL_IN_UINT_FAST8_T_RET_STATUS_ERR_DOES_NOT_FIT);
}

void
fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_tests()
{
	fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_0();
	fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_1();
	fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_2();
	fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_3();
	fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_test_4();
}

void
fit_raw_natural_in_uint_fast8_t_test_0()
{
	const char * raw_natural_chars_array_ = "32993";
	const amara_string * raw_natural_ =
			amara_string_exhaustive_constructor(
					raw_natural_chars_array_);
	const fit_raw_natural_in_uint_fast8_t_ret * ret_ =
			fit_raw_natural_in_uint_fast8_t(raw_natural_);
	assertion(ret_->status ==
			FIT_RAW_NATURAL_IN_UINT_FAST8_T_RET_STATUS_ERR_NOT_FITTING);
	fit_raw_natural_in_uint_fast8_t_ret_destructor(
			(fit_raw_natural_in_uint_fast8_t_ret *) ret_);
	amara_string_destructor((amara_string *) raw_natural_);
	/* FIXME attempt to free a non heap object */
	/*
	free((char *) raw_natural_chars_array_);
	*/
}

void
fit_raw_natural_in_uint_fast8_t_tests()
{
	fit_raw_natural_in_uint_fast8_t_test_0();
}

/*   This is a _friend_ declaration of a function otherwise private to
 * `natural.c`. */
amara_string *
raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one(
		const amara_string * raw_natural_zero,
		const amara_string * raw_natural_one)
__attribute__((warn_unused_result));

const char * MACHINE_NUMERIC_OVERFLOW = "MACHINE_NUMERIC_OVERFLOW";

void
raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one_test_0()
{
	const char * raw_natural_zero_chars_array_ = "256";
	const char * raw_natural_one_chars_array_ = "0";
	const amara_string * raw_natural_zero_ =
			amara_string_exhaustive_constructor(
					raw_natural_zero_chars_array_);
	const amara_string * raw_natural_one_ =
			amara_string_exhaustive_constructor(
					raw_natural_one_chars_array_);
	const amara_string * actual_ret_ =
			raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one(
					raw_natural_zero_, raw_natural_one_);
	const char * expected_ret_chars_array_ =
			malloc(strlen(MACHINE_NUMERIC_OVERFLOW) + 1);
	const amara_string * expected_ret_;
	amara_boolean expectation_matches_;
	strcpy((char *) expected_ret_chars_array_, MACHINE_NUMERIC_OVERFLOW);
	expected_ret_ = amara_string_exhaustive_constructor(
			expected_ret_chars_array_);
	expectation_matches_ =
			amara_string_equality(expected_ret_, actual_ret_);
	/* fprintf(stderr, "%s:%u - %d\n", __FILE__, __LINE__, strcmp_ret_); */
	assertion(expectation_matches_);
	amara_string_destructor((amara_string *) expected_ret_);
	free((char *) expected_ret_chars_array_);
	amara_string_destructor((amara_string *) actual_ret_);
	amara_string_destructor((amara_string *) raw_natural_one_);
	amara_string_destructor((amara_string *) raw_natural_zero_);
	/* FIXME attempt to free a non heap object */
	/*
	free((char *) raw_natural_one_chars_array_);
	free((char *) raw_natural_zero_chars_array_);
	*/
}

void
raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one_test_1()
{
	const char * raw_natural_zero_chars_array_ = "0";
	const char * raw_natural_one_chars_array_ = "256";
	const amara_string * raw_natural_zero_ =
			amara_string_exhaustive_constructor(
					raw_natural_zero_chars_array_);
	const amara_string * raw_natural_one_ =
			amara_string_exhaustive_constructor(
					raw_natural_one_chars_array_);
	const amara_string * actual_ret_ =
			raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one(
					raw_natural_zero_, raw_natural_one_);
	const char * expected_ret_chars_array_ =
			malloc(strlen(MACHINE_NUMERIC_OVERFLOW) + 1);
	const amara_string * expected_ret_;
	amara_boolean expectation_matches_;
	strcpy((char *) expected_ret_chars_array_, MACHINE_NUMERIC_OVERFLOW);
	expected_ret_ = amara_string_exhaustive_constructor(
			expected_ret_chars_array_);
	expectation_matches_ =
			amara_string_equality(expected_ret_, actual_ret_);
	assertion(expectation_matches_);
	amara_string_destructor((amara_string *) expected_ret_);
	free((char *) expected_ret_chars_array_);
	amara_string_destructor((amara_string *) actual_ret_);
	amara_string_destructor((amara_string *) raw_natural_one_);
	amara_string_destructor((amara_string *) raw_natural_zero_);
	/* FIXME attempt to free a non heap object */
	/*
	free((char *) raw_natural_one_chars_array_);
	free((char *) raw_natural_zero_chars_array_);
	*/
}

void
raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one_tests()
{
	raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one_test_0();
	raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one_test_1();
}

void
raw_naturals_division_as_raw_natural_test_0()
{
	const char * raw_natural_zero_chars_array_ = "256";
	const char * raw_natural_one_chars_array_ = "1";
	const amara_string * raw_natural_zero_ =
			amara_string_exhaustive_constructor(
					raw_natural_zero_chars_array_);
	const amara_string * raw_natural_one_ =
			amara_string_exhaustive_constructor(
					raw_natural_one_chars_array_);
	const amara_string * ret_ = raw_naturals_division_as_raw_natural(
			raw_natural_zero_, raw_natural_one_);
	const char * expected_raw_natural_chars_array_ =
			"MACHINE_NUMERIC_OVERFLOW";
	const amara_string * expected_raw_natural_ =
			amara_string_exhaustive_constructor(
					expected_raw_natural_chars_array_);
	assertion(amara_string_equality(ret_, expected_raw_natural_));
	amara_string_destructor((amara_string *) ret_);
	amara_string_destructor((amara_string *) raw_natural_one_);
	amara_string_destructor((amara_string *) raw_natural_zero_);
	/* FIXME attempt to free a non heap object */
	/*
	free((char *) raw_natural_one_chars_array_);
	free((char *) raw_natural_zero_chars_array_);
	*/
}

void
raw_naturals_division_as_raw_natural_test_1()
{
	const char * raw_natural_zero_chars_array_ = "1";
	const char * raw_natural_one_chars_array_ = "256";
	const amara_string * raw_natural_zero_ =
			amara_string_exhaustive_constructor(
					raw_natural_zero_chars_array_);
	const amara_string * raw_natural_one_ =
			amara_string_exhaustive_constructor(
					raw_natural_one_chars_array_);
	const amara_string * ret_ = raw_naturals_division_as_raw_natural(
			raw_natural_zero_, raw_natural_one_);
	const char * expected_raw_natural_chars_array_ =
			"MACHINE_NUMERIC_OVERFLOW";
	const amara_string * expected_raw_natural_ =
			amara_string_exhaustive_constructor(
					expected_raw_natural_chars_array_);
	assertion(amara_string_equality(ret_, expected_raw_natural_));
	amara_string_destructor((amara_string *) ret_);
	amara_string_destructor((amara_string *) raw_natural_one_);
	amara_string_destructor((amara_string *) raw_natural_zero_);
	/* FIXME attempt to free a non heap object */
	/*
	free((char *) raw_natural_one_chars_array_);
	free((char *) raw_natural_zero_chars_array_);
	*/
}

void
raw_naturals_division_as_raw_natural_tests()
{
	raw_naturals_division_as_raw_natural_test_0();
	raw_naturals_division_as_raw_natural_test_1();
}

void
numeric_natural_nodes_substraction_test_0()
{
	const char * raw_natural_zero_chars_array_ = "23";
	const amara_string * raw_natural_zero_ =
			amara_string_exhaustive_constructor(
					raw_natural_zero_chars_array_);
	const stt_node * numeric_natural_stt_node_zero_ =
			stt_node_wrapping_raw_natural(raw_natural_zero_);
	const char * raw_natural_one_chars_array_ = "23";
	const amara_string * raw_natural_one_ =
			amara_string_exhaustive_constructor(
					raw_natural_one_chars_array_);
	const stt_node * numeric_natural_stt_node_one_ =
			stt_node_wrapping_raw_natural(raw_natural_one_);
	const stt_node * result_ = numeric_natural_nodes_substraction(
			numeric_natural_stt_node_zero_,
			numeric_natural_stt_node_one_);
	const char * expectation_raw_chars_array_ = "0";
	const amara_string * expectation_raw_ =
			amara_string_default_constructor();
	amara_string_set_value(
			(amara_string *) expectation_raw_,
			expectation_raw_chars_array_);
	assert_pure_natural_node(result_);
	assertion(
			amara_string_equality(
				result_->natural_subnode_->raw_,
				expectation_raw_) ==
			AMARA_BOOLEAN_TRUE);
	/* FIXME attempt to free a non heap object */
	/*
	free((char *) expectation_raw_chars_array_);
	*/
	stt_node_destructor((stt_node *) result_);
	stt_node_destructor((stt_node *) numeric_natural_stt_node_one_);
	amara_string_destructor((amara_string *) raw_natural_one_);
	/* FIXME attempt to free a non heap object */
	/*
	free((char *) raw_natural_one_chars_array_);
	*/
	stt_node_destructor((stt_node *) numeric_natural_stt_node_zero_);
	amara_string_destructor((amara_string *) raw_natural_zero_);
	/* FIXME attempt to free a non heap object */
	/*
	free((char *) raw_natural_zero_chars_array_);
	*/
}

void
numeric_natural_nodes_substraction_tests()
{
	numeric_natural_nodes_substraction_test_0();
}

void
natural_tests()
{
	safe_arguments_natural_raw_comparison_tests();
	fit_raw_natural_in_uint_fast8_t_inner_might_fit_or_not_tests();
	fit_raw_natural_in_uint_fast8_t_tests();
	raw_naturals_substraction_as_raw_natural_zero_is_larger_than_one_tests();
	raw_naturals_division_as_raw_natural_tests();
	numeric_natural_nodes_substraction_tests();
}

void
basic_arithmetic_tests()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void basic_arithmetic_tests()\n", __FILE__, __LINE__);
#endif
	natural_tests();
}