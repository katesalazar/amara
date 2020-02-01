/*
 * Copyright 2018-2020 Mercedes Catherine Salazar
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
 * src/arn/arn_value_tests.c: Test the Amara application run time value.
 * A value is basically a constant.
 */

#include "../rtg/rtg_expression_sub_dice_tests.h"

#include "arn_value_tests.h"

arn_value *
arn_value_example_named_natural_zero()
{
	arn_value * value_;

	value_ = arn_value_default_constructor();
	assertion(value_ != NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_INVALID);
	assertion(value_->name_ == NULL);
	assertion(value_->natural_ == NULL);

	value_->natural_ = natural_default_constructor();
	assertion(value_->natural_ != NULL);
	assertion(value_->natural_->raw_ == NULL);

	value_->natural_->raw_ = amara_string_exhaustive_constructor("0");

	value_->name_ = amara_string_exhaustive_constructor("zero");

	value_->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL;

	return value_;
}

void
assert_expectations_on_arn_value_example_named_natural_zero(
		const arn_value * value)
{
	amara_string * expected_named_natural_name_;
	amara_string * expected_named_natural_raw_value_;
	amara_boolean equality_;

	expected_named_natural_name_ =
			amara_string_exhaustive_constructor("zero");
	assertion(expected_named_natural_name_ != NULL);
	assertion(expected_named_natural_name_->value_ != NULL);

	expected_named_natural_raw_value_ =
			amara_string_exhaustive_constructor("0");
	assertion(expected_named_natural_raw_value_ != NULL);
	assertion(expected_named_natural_raw_value_->value_ != NULL);

	assertion(value != NULL);
	assertion(value->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(value->name_ != NULL);
	assertion(value->name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_named_natural_name_, value->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(value->natural_ != NULL);
	assertion(value->natural_->raw_ != NULL);
	equality_ = amara_string_equality(
			expected_named_natural_raw_value_,
			value->natural_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(expected_named_natural_raw_value_);
	amara_string_destructor(expected_named_natural_name_);
}

arn_value *
arn_value_example_named_natural_one()
{
	arn_value * value_;

	value_ = arn_value_default_constructor();
	assertion(value_ != NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_INVALID);
	assertion(value_->name_ == NULL);
	assertion(value_->natural_ == NULL);

	value_->natural_ = natural_default_constructor();
	assertion(value_->natural_ != NULL);
	assertion(value_->natural_->raw_ == NULL);

	value_->natural_->raw_ = amara_string_exhaustive_constructor("1");

	value_->name_ = amara_string_exhaustive_constructor("one");

	value_->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL;

	return value_;
}

void
assert_expectations_on_arn_value_example_named_natural_one(
		const arn_value * value)
{
	amara_string * expected_named_natural_name_;
	amara_string * expected_named_natural_raw_value_;
	amara_boolean equality_;

	expected_named_natural_name_ =
			amara_string_exhaustive_constructor("one");
	assertion(expected_named_natural_name_ != NULL);
	assertion(expected_named_natural_name_->value_ != NULL);

	expected_named_natural_raw_value_ =
			amara_string_exhaustive_constructor("1");
	assertion(expected_named_natural_raw_value_ != NULL);
	assertion(expected_named_natural_raw_value_->value_ != NULL);

	assertion(value != NULL);
	assertion(value->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(value->name_ != NULL);
	assertion(value->name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_named_natural_name_, value->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(value->natural_ != NULL);
	assertion(value->natural_->raw_ != NULL);
	equality_ = amara_string_equality(
			expected_named_natural_raw_value_,
			value->natural_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(expected_named_natural_raw_value_);
	amara_string_destructor(expected_named_natural_name_);
}

/**  Create an empty value and destroy it. */
void
arn_value_construct_and_destruct_test_0()
{
	arn_value * value_;

	value_ = arn_value_default_constructor();
	assertion(value_ != NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_INVALID);
	assertion(value_->name_ == NULL);
	assertion(value_->string_ == NULL);
	assertion(value_->string_was_moved == AMARA_BOOLEAN_FALSE);
	assertion(value_->natural_ == NULL);
	assertion(value_->natural_was_moved == AMARA_BOOLEAN_FALSE);

	arn_value_destructor(value_);
}

/**  Create an empty value, set it a name, create a copy of it, and
 * destroy it and the copy. */
void
arn_value_construct_and_destruct_test_1()
{
	arn_value * value_;
	amara_string * value_name_;
	arn_value * value_copy_;
	amara_boolean equality_;

	value_ = arn_value_default_constructor();
	assertion(value_ != NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_INVALID);
	assertion(value_->name_ == NULL);
	assertion(value_->string_ == NULL);
	assertion(value_->string_was_moved == AMARA_BOOLEAN_FALSE);
	assertion(value_->natural_ == NULL);
	assertion(value_->natural_was_moved == AMARA_BOOLEAN_FALSE);
	/*
	assertion(value_->integer_ == NULL);
	assertion(value_->rational_ == NULL);
	*/

	value_name_ = amara_string_exhaustive_constructor("foo");
	assertion(value_name_ != NULL);
	assertion(value_name_->value_ != NULL);

	arn_value_set_name(value_, value_name_);
	assertion(value_->type_ ==
			ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);
	assertion(value_->name_ != NULL);
	assertion(value_->string_ == NULL);
	assertion(value_->string_was_moved == AMARA_BOOLEAN_FALSE);
	assertion(value_->natural_ == NULL);
	assertion(value_->natural_was_moved == AMARA_BOOLEAN_FALSE);
	/*
	assertion(value_->integer_ == NULL);
	assertion(value_->rational_ == NULL);
	*/
	assertion(value_name_->value_ != NULL);
	equality_ = amara_string_equality(value_->name_, value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	value_copy_ = arn_value_copy_constructor(value_);
	assertion(value_->type_ ==
			ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);
	assertion(value_->name_ != NULL);
	equality_ = amara_string_equality(value_->name_, value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(value_->string_ == NULL);
	assertion(value_->string_was_moved == AMARA_BOOLEAN_FALSE);
	assertion(value_->natural_ == NULL);
	assertion(value_->natural_was_moved == AMARA_BOOLEAN_FALSE);
	/*
	assertion(value_->integer_ == NULL);
	assertion(value_->rational_ == NULL);
	*/
	assertion(value_copy_ != NULL);
	assertion(value_copy_->type_ ==
			ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);
	assertion(value_copy_->name_ != NULL);
	equality_ = amara_string_equality(value_copy_->name_, value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(value_copy_->string_ == NULL);
	assertion(value_copy_->string_was_moved == AMARA_BOOLEAN_FALSE);
	assertion(value_copy_->natural_ == NULL);
	assertion(value_copy_->natural_was_moved == AMARA_BOOLEAN_FALSE);
	/*
	assertion(value_copy_->integer_ == NULL);
	assertion(value_copy_->rational_ == NULL);
	*/

	arn_value_destructor(value_copy_);
	amara_string_destructor(value_name_);
	arn_value_destructor(value_);
}

/**  Create an empty value, set it a name, characterize it as a natural
 * typed value, create a copy of it, and destroy it and the copy. */
void
arn_value_construct_and_destruct_test_2()
{
	arn_value * value_;
	amara_string * value_name_;
	arn_value * value_copy_;
	amara_boolean equality_;

	value_ = arn_value_default_constructor();
	assertion(value_ != NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_INVALID);
	assertion(value_->name_ == NULL);
	assertion(value_->string_ == NULL);
	assertion(value_->string_was_moved == AMARA_BOOLEAN_FALSE);
	assertion(value_->natural_ == NULL);
	assertion(value_->natural_was_moved == AMARA_BOOLEAN_FALSE);
	/*
	assertion(value_->integer_ == NULL);
	assertion(value_->rational_ == NULL);
	*/

	value_name_ = amara_string_exhaustive_constructor("foo");
	assertion(value_name_ != NULL);
	assertion(value_name_->value_ != NULL);

	arn_value_set_name(value_, value_name_);
	assertion(value_->type_ ==
			ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);
	assertion(value_->name_ != NULL);
	assertion(value_->string_ == NULL);
	assertion(value_->string_was_moved == AMARA_BOOLEAN_FALSE);
	assertion(value_->natural_ == NULL);
	assertion(value_->natural_was_moved == AMARA_BOOLEAN_FALSE);
	/*
	assertion(value_->integer_ == NULL);
	assertion(value_->rational_ == NULL);
	*/
	assertion(value_name_->value_ != NULL);
	equality_ = amara_string_equality(value_->name_, value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	arn_value_characterize_as_natural(value_);
	assertion(value_->type_ ==
			ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL);

	value_copy_ = arn_value_copy_constructor(value_);
	assertion(value_->type_ ==
			ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL);
	assertion(value_->name_ != NULL);
	equality_ = amara_string_equality(value_->name_, value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(value_->string_ == NULL);
	assertion(value_->string_was_moved == AMARA_BOOLEAN_FALSE);
	assertion(value_->natural_ == NULL);
	assertion(value_->natural_was_moved == AMARA_BOOLEAN_FALSE);
	/*
	assertion(value_->integer_ == NULL);
	assertion(value_->rational_ == NULL);
	*/
	assertion(value_copy_ != NULL);
	assertion(value_copy_->type_ ==
			ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL);
	assertion(value_copy_->name_ != NULL);
	equality_ = amara_string_equality(value_copy_->name_, value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(value_copy_->string_ == NULL);
	assertion(value_copy_->string_was_moved == AMARA_BOOLEAN_FALSE);
	assertion(value_copy_->natural_ == NULL);
	assertion(value_copy_->natural_was_moved == AMARA_BOOLEAN_FALSE);
	/*
	assertion(value_copy_->integer_ == NULL);
	assertion(value_copy_->rational_ == NULL);
	*/

	arn_value_destructor(value_copy_);
	amara_string_destructor(value_name_);
	arn_value_destructor(value_);
}

/**  Create an empty value, characterize it as natural, set its actual
 * value, create a copy of it, and destroy it and the copy. */
void
arn_value_construct_and_destruct_test_3()
{
	arn_value * value_;
	amara_string * raw_natural_;
	natural * natural_;
	arn_value * value_copy_;
	amara_boolean equality_;

	value_ = arn_value_default_constructor();
	assertion(value_ != NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_INVALID);
	assertion(value_->name_ == NULL);
	assertion(value_->string_ == NULL);
	assertion(value_->string_was_moved == AMARA_BOOLEAN_FALSE);
	assertion(value_->natural_ == NULL);
	assertion(value_->natural_was_moved == AMARA_BOOLEAN_FALSE);
	/*
	assertion(value_->integer_ == NULL);
	assertion(value_->rational_ == NULL);
	*/

	arn_value_characterize_as_natural(value_);
	assertion(value_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_NATURAL);

	raw_natural_ = amara_string_exhaustive_constructor("0");
	assertion(raw_natural_ != NULL);
	assertion(raw_natural_->value_ != NULL);

	natural_ = natural_exhaustive_constructor(raw_natural_);
	assertion(natural_ != NULL);
	assertion(natural_->raw_ != NULL);
	assertion(natural_->raw_->value_ != NULL);

	arn_value_set_natural(value_, natural_);
	assertion(value_->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);

	value_copy_ = arn_value_copy_constructor(value_);
	assertion(value_->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);
	assertion(value_->natural_ != NULL);
	assertion(value_->natural_->raw_ != NULL);
	assertion(value_->natural_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			value_->natural_->raw_, natural_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(value_copy_ != NULL);
	assertion(value_copy_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);
	assertion(value_copy_->natural_ != NULL);
	assertion(value_copy_->natural_->raw_ != NULL);
	assertion(value_copy_->natural_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			value_copy_->natural_->raw_, natural_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	arn_value_destructor(value_copy_);
	natural_destructor(natural_);
	amara_string_destructor(raw_natural_);
	arn_value_destructor(value_);
}

/**  Create an empty value, characterize it as string, set its actual
 * value, create a copy of it, and destroy it and the copy. */
void
arn_value_construct_and_destruct_test_4()
{
	arn_value * value_;
	amara_string * string_;
	arn_value * value_copy_;
	amara_boolean equality_;

	value_ = arn_value_default_constructor();
	assertion(value_ != NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_INVALID);
	assertion(value_->name_ == NULL);
	assertion(value_->string_ == NULL);
	assertion(value_->string_was_moved == AMARA_BOOLEAN_FALSE);
	assertion(value_->natural_ == NULL);
	assertion(value_->natural_was_moved == AMARA_BOOLEAN_FALSE);
	/*
	assertion(value_->integer_ == NULL);
	assertion(value_->rational_ == NULL);
	*/

	arn_value_characterize_as_string(value_);
	assertion(value_->type_ == ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_STRING);

	string_ = amara_string_exhaustive_constructor("");
	assertion(string_ != NULL);
	assertion(string_->value_ != NULL);

	arn_value_set_string(value_, string_);
	assertion(value_->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING);

	value_copy_ = arn_value_copy_constructor(value_);
	assertion(value_->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING);
	assertion(value_->string_ != NULL);
	assertion(value_->string_->value_ != NULL);
	equality_ = amara_string_equality(value_->string_, string_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(value_copy_ != NULL);
	assertion(value_copy_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING);
	assertion(value_copy_->string_ != NULL);
	assertion(value_copy_->string_->value_ != NULL);
	equality_ = amara_string_equality(value_copy_->string_, string_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	arn_value_destructor(value_copy_);
	amara_string_destructor(string_);
	arn_value_destructor(value_);
}

void
arn_value_construct_and_destruct_tests()
{
	arn_value_construct_and_destruct_test_0();
	arn_value_construct_and_destruct_test_1();
	arn_value_construct_and_destruct_test_2();
	arn_value_construct_and_destruct_test_3();
	arn_value_construct_and_destruct_test_4();
}

tests_simple_list *
register_arn_value_construct_and_destruct_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_arn_value_construct_and_destruct_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(tests,
	                            & arn_value_construct_and_destruct_test_0);
	tests_simple_list_push_back(tests,
	                            & arn_value_construct_and_destruct_test_1);
	tests_simple_list_push_back(tests,
	                            & arn_value_construct_and_destruct_test_2);
	tests_simple_list_push_back(tests,
	                            & arn_value_construct_and_destruct_test_3);
	tests_simple_list_push_back(tests,
	                            & arn_value_construct_and_destruct_test_4);
	return tests;
}

void
arn_value_assign_natural_out_of_unsigned_short_test_0()
{
	arn_value * value_;
	unsigned short unsigned_short_;
	amara_string * expected_value_raw_natural_;
	arn_value_assign_natural_out_of_unsigned_short_ret * ret_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	value_ = arn_value_default_constructor();
	forced_assertion(value_ != NULL);
#ifndef NDEBUG
	assertion(value_->type_ == ARN_VALUE_TYPE_INVALID);
#endif

	unsigned_short_ = 0;

	expected_value_raw_natural_ = amara_string_exhaustive_constructor("0");
	forced_assertion(expected_value_raw_natural_ != NULL);
	forced_assertion(expected_value_raw_natural_->value_ != NULL);

	value_->type_ = ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_NATURAL; /* XXX */

	ret_ = arn_value_assign_natural_out_of_unsigned_short(
			value_, unsigned_short_);
#ifndef NDEBUG
	assertion(value_->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);
#endif
	forced_assertion(value_->natural_ != NULL);
	forced_assertion(value_->natural_->raw_ != NULL);
	forced_assertion(value_->natural_->raw_->value_ != NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(
			value_->natural_->raw_, expected_value_raw_natural_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->status ==
			ARN_VALUE_ASSIGN_NATURAL_OUT_OF_UNSIGNED_INT_RET_STATUS_SUCCESS);
#endif

	/*
	arn_value_assign_natural_out_of_unsigned_short_ret_destructor(ret_);
	*/
	free(ret_);
	amara_string_destructor(expected_value_raw_natural_);
	arn_value_destructor(value_);
}

void
arn_value_assign_natural_out_of_unsigned_short_tests()
{
	arn_value_assign_natural_out_of_unsigned_short_test_0();
}

tests_simple_list *
register_arn_value_assign_natural_out_of_unsigned_short_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_arn_value_assign_natural_out_of_unsigned_short_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& arn_value_assign_natural_out_of_unsigned_short_test_0);
	return tests;
}

void
arn_value_out_of_amara_boolean_test_0()
{
	amara_boolean bool_;
	arn_value * arn_value_;

	bool_ = AMARA_BOOLEAN_FALSE;

	arn_value_ = arn_value_out_of_amara_boolean(bool_);
	forced_assertion(arn_value_ != NULL);
	forced_assertion(arn_value_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_BOOLEAN);
	forced_assertion(* arn_value_->boolean_ == AMARA_BOOLEAN_FALSE);

	arn_value_destructor(arn_value_);
}

void
arn_value_out_of_amara_boolean_tests()
{
	arn_value_out_of_amara_boolean_test_0();
}

tests_simple_list *
register_arn_value_out_of_amara_boolean_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_arn_value_out_of_amara_boolean_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(tests,
	                            & arn_value_out_of_amara_boolean_test_0);
	return tests;
}

/**  Friend declaration of otherwise private function. */
arn_value *
run_dice(const rtg_expression_sub_dice * expression_sub_dice)
__amara__warn_unused_result__
;

void
run_dice_test_0()
{
	rtg_expression_sub_dice * dice_;
	arn_value * dice_rolls_results_;

	dice_ = rtg_expression_sub_dice_example_single_vanilla_dice();
	forced_assertion(dice_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_sub_dice_example_single_vanilla_dice(
			dice_);
#endif

	dice_rolls_results_ = run_dice(dice_);
	forced_assertion(dice_rolls_results_ != NULL);
	forced_assertion(dice_rolls_results_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);
	forced_assertion(48 < * dice_rolls_results_->natural_->raw_->value_);  /* XXX */
	forced_assertion(56 > * dice_rolls_results_->natural_->raw_->value_);  /* XXX */

	rtg_expression_sub_dice_destructor(dice_);
	arn_value_destructor(dice_rolls_results_);
}

void
run_dice_tests()
{
	run_dice_test_0();
}

tests_simple_list *
register_run_dice_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_run_dice_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(tests, & run_dice_test_0);
	return tests;
}

/**  Friendly declaration of an otherwise private function. */
arn_value *
arn_value_out_of_rtg_expression(const rtg_expression * expression)
__amara__warn_unused_result__
;

/*

void
arn_value_out_of_rtg_expression_test_0()
{
	rtg_expression_sub_dice * dice_;
	arn_value * dice_rolls_results_;

	dice_ = rtg_expression_sub_dice_example_single_vanilla_dice();
	forced_assertion(dice_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_sub_dice_example_single_vanilla_dice(
			dice_);
#endif

	dice_rolls_results_ = arn_value_out_of_rtg_expression(dice_);
	forced_assertion(dice_rolls_results_ != NULL);
	forced_assertion(dice_rolls_results_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_BOOLEAN);
	forced_assertion(48 < * dice_rolls_results_->natural_->raw_->value_);*/  /* XXX */
	/*forced_assertion(56 > * dice_rolls_results_->natural_->raw_->value_);*/  /* XXX */

	/*rtg_expression_sub_dice_destructor(dice_);
	arn_value_destructor(dice_rolls_results_);
}

*/

void
arn_value_out_of_rtg_expression_tests()
{
	/*
	arn_value_out_of_rtg_expression_test_0();
	*/
}

tests_simple_list *
register_arn_value_out_of_rtg_expression_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_arn_value_out_of_rtg_expression_tests(tests_simple_list * tests)
{
	return tests;
}

void
arn_value_characterize_as_boolean_test_0()
{
	arn_value * arn_value_;

	arn_value_ = arn_value_default_constructor();
	forced_assertion(arn_value_ != NULL);
#ifndef NDEBUG
	assertion(arn_value_->type_ == ARN_VALUE_TYPE_INVALID);
#endif

	arn_value_characterize_as_boolean(arn_value_);
	forced_assertion(arn_value_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_BOOLEAN);

	arn_value_destructor(arn_value_);
}

void
arn_value_characterize_as_boolean_tests()
{
	arn_value_characterize_as_boolean_test_0();
}

tests_simple_list *
register_arn_value_characterize_as_boolean_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_arn_value_characterize_as_boolean_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests, & arn_value_characterize_as_boolean_test_0);
	return tests;
}

void
arn_value_tests()
{
	arn_value_construct_and_destruct_tests();
	arn_value_assign_natural_out_of_unsigned_short_tests();
	arn_value_out_of_amara_boolean_tests();
	run_dice_tests();
	arn_value_out_of_rtg_expression_tests();
	arn_value_characterize_as_boolean_tests();
}

tests_simple_list *
register_arn_value_tests(tests_simple_list * tests)
{
	return register_arn_value_characterize_as_boolean_tests(
	       register_arn_value_out_of_rtg_expression_tests(
	       register_run_dice_tests(
	       register_arn_value_out_of_amara_boolean_tests(
	       register_arn_value_assign_natural_out_of_unsigned_short_tests(
	       register_arn_value_construct_and_destruct_tests(tests))))));
}
