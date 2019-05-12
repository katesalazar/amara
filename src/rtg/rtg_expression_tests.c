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
 * src/rtg/rtg_expression_tests.c: Test the Amara run time graph
 * expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_expression_example_simple_conditional`. */
#include "../stt/stt_expression_tests.h"

/*   For
 * `assert_expectations_on_rtg_condition_example_simple_conditional`. */
#include "rtg_condition_tests.h"

#include "rtg_named_functions_simple_list.h"

/*   For owned function prototypes. */
#include "rtg_expression_tests.h"

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_string_literal_foo(
		const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_STRING_LITERAL);
	assertion(expression->sub_string_literal_ != NULL);
	assertion(expression->sub_string_literal_->string_literal_ != NULL);
	assertion(expression->sub_string_literal_->string_literal_->value_ !=
			NULL);
	assertion(expression->sub_string_literal_->string_literal_->value_[0] ==
			'f');
	assertion(expression->sub_string_literal_->string_literal_->value_[1] ==
			'o');
	assertion(expression->sub_string_literal_->string_literal_->value_[2] ==
			'o');
	assertion(expression->sub_string_literal_->string_literal_->value_[3] ==
			'\0');
}

#endif

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_string_literal_bar(
		const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_STRING_LITERAL);
	assertion(expression->sub_string_literal_ != NULL);
	assertion(expression->sub_string_literal_->string_literal_ != NULL);
	assertion(expression->sub_string_literal_->string_literal_->value_ !=
			NULL);
	assertion(expression->sub_string_literal_->string_literal_->value_[0] ==
			'b');
	assertion(expression->sub_string_literal_->string_literal_->value_[1] ==
			'a');
	assertion(expression->sub_string_literal_->string_literal_->value_[2] ==
			'r');
	assertion(expression->sub_string_literal_->string_literal_->value_[3] ==
			'\0');
}

#endif

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_natural_literal_zero(
		const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(expression->sub_natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_[0] ==
			0x30);  /* 48: '0'. */
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_[1] ==
			0x00);  /* 0: '\0'. */
}

#endif

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_natural_literal_one(
		const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(expression->sub_natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_[0] ==
			0x31);  /* 49: '1'. */
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_[1] ==
			0x00);  /* 0: '\0'. */
}

#endif

rtg_expression *
rtg_expression_example_identifier_foo()
{
	stt_expression * stt_expression_;
	rtg_named_functions_simple_list * rtg_named_functions_;
	rtg_expression_out_of_stt_expression_ret * transformation_ret_;
	rtg_expression * ret_;

	stt_expression_ = stt_expression_example_identifier_foo();
	forced_assertion(stt_expression_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_identifier_foo(
			stt_expression_);
#endif

	rtg_named_functions_ =
			rtg_named_functions_simple_list_default_constructor();
	forced_assertion(rtg_named_functions_ != NULL);

	transformation_ret_ = rtg_expression_out_of_stt_expression(
			stt_expression_, rtg_named_functions_);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_identifier_foo(
			stt_expression_);
#endif
	forced_assertion(transformation_ret_ != NULL);
	forced_assertion(transformation_ret_->status ==
			RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS);
	forced_assertion(transformation_ret_->expression != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_example_identifier_foo(
			transformation_ret_->expression);
#endif

	stt_expression_destructor(stt_expression_);

	ret_ = transformation_ret_->expression;

	free(transformation_ret_);

	rtg_named_functions_simple_list_deep_destructor(rtg_named_functions_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_identifier_foo(
		const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_IDENTIFIER);
	assertion(expression->sub_identifier_ != NULL);
	assertion(expression->sub_identifier_->identifier_ != NULL);
	assertion(expression->sub_identifier_->identifier_->value_ != NULL);
	assertion(expression->sub_identifier_->identifier_->value_[0] == 'f');
	assertion(expression->sub_identifier_->identifier_->value_[1] == 'o');
	assertion(expression->sub_identifier_->identifier_->value_[2] == 'o');
	assertion(expression->sub_identifier_->identifier_->value_[3] == '\0');
}

#endif

rtg_expression *
rtg_expression_example_single_vanilla_dice(void)
{
	stt_expression * stt_expression_;
	rtg_named_functions_simple_list * rtg_named_functions_;
	rtg_expression_out_of_stt_expression_ret * transformation_ret_;
	rtg_expression * ret_;

	stt_expression_ = stt_expression_example_single_vanilla_dice();
	forced_assertion(stt_expression_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_single_vanilla_dice(
			stt_expression_);
#endif

	rtg_named_functions_ =
			rtg_named_functions_simple_list_default_constructor();
	forced_assertion(rtg_named_functions_ != NULL);

	transformation_ret_ = rtg_expression_out_of_stt_expression(
			stt_expression_, rtg_named_functions_);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_single_vanilla_dice(
			stt_expression_);
#endif
	forced_assertion(transformation_ret_ != NULL);
#ifndef NDEBUG
	assertion(transformation_ret_->status ==
			RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS);
#endif
	forced_assertion(transformation_ret_->expression != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_example_single_vanilla_dice(
			transformation_ret_->expression);
#endif

	ret_ = transformation_ret_->expression;

	free(transformation_ret_);

	rtg_named_functions_simple_list_deep_destructor(rtg_named_functions_);

	stt_expression_destructor(stt_expression_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_single_vanilla_dice(
		const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_DICE);
	assertion(expression->sub_dice_ != NULL);
	assertion(expression->sub_dice_->left_hand_side_natural_ != NULL);
	assertion(expression->sub_dice_->left_hand_side_natural_->raw_ !=
			NULL);
	assertion(expression->sub_dice_->left_hand_side_natural_->raw_->value_ !=
			NULL);
	assertion(expression->sub_dice_->left_hand_side_natural_->raw_->value_[0] ==
			'1');
	assertion(expression->sub_dice_->left_hand_side_natural_->raw_->value_[1] ==
			'\0');
	assertion(expression->sub_dice_->right_hand_side_natural_ != NULL);
	assertion(expression->sub_dice_->right_hand_side_natural_->raw_ !=
			NULL);
	assertion(expression->sub_dice_->right_hand_side_natural_->raw_->value_ !=
			NULL);
	assertion(expression->sub_dice_->right_hand_side_natural_->raw_->value_[0] ==
			'6');
	assertion(expression->sub_dice_->right_hand_side_natural_->raw_->value_[1] ==
			'\0');
}

#endif

rtg_expression *
rtg_expression_example_simple_conditional()
{
	stt_expression * expression_;
	rtg_expression_out_of_stt_expression_ret * mid_ret_;
	rtg_expression * returning_;

	expression_ = stt_expression_example_simple_conditional();
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_simple_conditional(
			expression_);
#endif

	mid_ret_ = rtg_expression_out_of_stt_expression(expression_, NULL);
#ifndef NDEBUG
	assertion(mid_ret_ != NULL);
	assertion(mid_ret_->status ==
			RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS);
	assert_expectations_on_rtg_expression_example_simple_conditional(
			mid_ret_->expression);
#endif

	returning_ = mid_ret_->expression;

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_simple_conditional(
		const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_CONDITIONAL);
	assertion(expression->sub_conditional_ != NULL);
	assertion(expression->sub_conditional_->if_ != NULL);
	assertion(expression->sub_conditional_->if_->type_ ==
			RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);
	assertion(expression->sub_conditional_->if_->condition_ != NULL);
	assert_expectations_on_rtg_condition_example_simple_condition(
			expression->sub_conditional_->if_->condition_);
}

#endif

void
rtg_expression_copy_constructor_test_10_identifier()
{
	rtg_expression * rtg_expression_zero_;
	rtg_expression * rtg_expression_one_;

	rtg_expression_zero_ = rtg_expression_example_identifier_foo();
	forced_assertion(rtg_expression_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_example_identifier_foo(
			rtg_expression_zero_);
#endif

	rtg_expression_one_ = rtg_expression_copy_constructor(
			rtg_expression_zero_);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_example_identifier_foo(
			rtg_expression_zero_);
#endif
	forced_assertion(rtg_expression_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_example_identifier_foo(
			rtg_expression_one_);
#endif

	rtg_expression_destructor(rtg_expression_one_);
	rtg_expression_destructor(rtg_expression_zero_);
}

void
rtg_expression_copy_constructor_test_20_conditional()
{
	rtg_expression * rtg_expression_zero_;
	rtg_expression * rtg_expression_one_;

	rtg_expression_zero_ = rtg_expression_example_simple_conditional();
	forced_assertion(rtg_expression_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_example_simple_conditional(
			rtg_expression_zero_);
#endif

	rtg_expression_one_ = rtg_expression_copy_constructor(
			rtg_expression_zero_);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_example_simple_conditional(
			rtg_expression_zero_);
#endif
	forced_assertion(rtg_expression_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_example_simple_conditional(
			rtg_expression_one_);
#endif

	rtg_expression_destructor(rtg_expression_one_);
	rtg_expression_destructor(rtg_expression_zero_);
}

void
rtg_expression_copy_constructor_tests()
{
	rtg_expression_copy_constructor_test_10_identifier();
	rtg_expression_copy_constructor_test_20_conditional();
}

void
rtg_expression_constructors_tests()
{
	rtg_expression_copy_constructor_tests();
}

#ifndef NDEBUG

void
rtg_expression_assert_validity_test_10_dice()
{
	rtg_expression * expression_;

	expression_ = rtg_expression_example_single_vanilla_dice();
	forced_assertion(expression_ != NULL);
	assert_expectations_on_rtg_expression_example_single_vanilla_dice(
			expression_);

	rtg_expression_assert_validity(expression_);
	assert_expectations_on_rtg_expression_example_single_vanilla_dice(
			expression_);

	rtg_expression_destructor(expression_);
}

#endif

#ifndef NDEBUG

void
rtg_expression_assert_validity_test_20_conditional()
{
	rtg_expression * expression_;

	expression_ = rtg_expression_example_simple_conditional();
	forced_assertion(expression_ != NULL);
	assert_expectations_on_rtg_expression_example_simple_conditional(
			expression_);

	rtg_expression_assert_validity(expression_);
	assert_expectations_on_rtg_expression_example_simple_conditional(
			expression_);

	rtg_expression_destructor(expression_);
}

#endif

#ifndef NDEBUG

void
rtg_expression_assert_validity_tests()
{
	rtg_expression_assert_validity_test_10_dice();
	rtg_expression_assert_validity_test_20_conditional();
}

#endif

void
rtg_expression_tests()
{
	rtg_expression_constructors_tests();
#ifndef NDEBUG
	rtg_expression_assert_validity_tests();
#endif
}
