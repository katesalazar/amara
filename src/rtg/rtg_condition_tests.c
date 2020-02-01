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
 * src/rtg/rtg_condition_tests.c: Test the Amara run time graph
 * condition.
 */

/*   For `stt_condition * stt_condition_example_simple_condition()`. */
#include "../stt/stt_condition_tests.h"

/*   For `assert_expectations_on_rtg_expression_example_natural_zero`. */
#include "rtg_expression_tests.h"

/*   For own functions prototypes. */
#include "rtg_condition_tests.h"

rtg_condition *
rtg_condition_example_simple_less_than_condition()
{
	stt_condition * stt_condition_;
	rtg_condition * ret_;

	stt_condition_ = stt_condition_example_simple_condition();
	forced_assertion(stt_condition_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_condition_example_simple_condition(
			stt_condition_);
#endif

	ret_ = rtg_condition_out_of_stt_condition(stt_condition_);
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_condition_example_simple_condition(
			ret_);
#endif

	stt_condition_destructor(stt_condition_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_condition_example_simple_less_than_condition(
		const rtg_condition * condition)
{
	assertion(condition != NULL);
	assertion(condition->type_ == RTG_CONDITION_TYPE_LESS_THAN);
	assertion(condition->left_hand_side_expression_ != NULL);
	assertion(condition->left_hand_side_expression_->type_ ==
			RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(condition->left_hand_side_expression_->sub_natural_literal_ !=
			NULL);
	assertion(condition->left_hand_side_expression_->sub_natural_literal_->natural_literal_ !=
			NULL);
	assert_expectations_on_rtg_expression_example_natural_literal_zero(
			condition->left_hand_side_expression_);
	assertion(condition->right_hand_side_expression_ != NULL);
	assertion(condition->right_hand_side_expression_->type_ ==
			RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(condition->right_hand_side_expression_->sub_natural_literal_ !=
			NULL);
	assertion(condition->right_hand_side_expression_->sub_natural_literal_->natural_literal_ !=
			NULL);
	assert_expectations_on_rtg_expression_example_natural_literal_one(
			condition->right_hand_side_expression_);
}

#endif

rtg_condition *
rtg_condition_example_simple_greater_than_condition(void)
{
	rtg_condition * less_than_condition_;
	rtg_condition * ret_;

	less_than_condition_ =
			rtg_condition_example_simple_less_than_condition();
	forced_assertion(less_than_condition_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_condition_example_simple_less_than_condition(
			less_than_condition_);
#endif

	ret_ = rtg_condition_flip(less_than_condition_);
#ifndef NDEBUG
	assert_expectations_on_rtg_condition_example_simple_less_than_condition(
			less_than_condition_);
#endif
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_condition_example_simple_greater_than_condition(
			ret_);
#endif

	rtg_condition_destructor(less_than_condition_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_condition_example_simple_greater_than_condition(
		const rtg_condition * condition)
{
	assertion(condition != NULL);
	assertion(condition->type_ == RTG_CONDITION_TYPE_GREATER_THAN);
	assertion(condition->left_hand_side_expression_ != NULL);
	assert_expectations_on_rtg_expression_example_natural_literal_one(
			condition->left_hand_side_expression_);
	assertion(condition->right_hand_side_expression_ != NULL);
	assert_expectations_on_rtg_expression_example_natural_literal_zero(
			condition->right_hand_side_expression_);
}

#endif

rtg_condition *
rtg_condition_example_simple_condition(void)
{
	return rtg_condition_example_simple_less_than_condition();
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_condition_example_simple_condition(
		const rtg_condition * condition)
{
	assertion(condition != NULL);
	assert_expectations_on_rtg_condition_example_simple_less_than_condition(
			condition);
}

#endif

void
rtg_condition_copy_constructors_test_0()
{
	rtg_condition * condition_0_;
	rtg_condition * condition_1_;

	condition_0_ = rtg_condition_example_simple_greater_than_condition();
	forced_assertion(condition_0_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_condition_example_simple_greater_than_condition(
			condition_0_);
#endif

	condition_1_ = rtg_condition_copy_constructor(condition_0_);
#ifndef NDEBUG
	assert_expectations_on_rtg_condition_example_simple_greater_than_condition(
			condition_0_);
#endif
	forced_assertion(condition_1_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_condition_example_simple_greater_than_condition(
			condition_1_);
#endif

	rtg_condition_destructor(condition_1_);
	rtg_condition_destructor(condition_0_);
}

void
rtg_condition_copy_constructors_tests()
{
	rtg_condition_copy_constructors_test_0();
}

tests_simple_list *
register_rtg_condition_copy_constructors_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_condition_copy_constructors_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(tests,
	                            & rtg_condition_copy_constructors_test_0);
	return tests;
}

void
rtg_condition_transformation_constructor_test_0()
{
	stt_condition * stt_condition_;
	rtg_condition * rtg_condition_;

	stt_condition_ = stt_condition_example_simple_greater_than_condition();
	forced_assertion(stt_condition_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_condition_example_simple_greater_than_condition(
			stt_condition_);
#endif

	rtg_condition_ = rtg_condition_out_of_stt_condition(stt_condition_);
#ifndef NDEBUG
	assert_expectations_on_stt_condition_example_simple_greater_than_condition(
			stt_condition_);
#endif
	forced_assertion(rtg_condition_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_condition_example_simple_greater_than_condition(
			rtg_condition_);
#endif

	stt_condition_destructor(stt_condition_);
	rtg_condition_destructor(rtg_condition_);
}

void
rtg_condition_transformation_constructors_tests()
{
	rtg_condition_transformation_constructor_test_0();
}

tests_simple_list *
register_rtg_condition_transformation_constructors_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_condition_transformation_constructors_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& rtg_condition_transformation_constructor_test_0);
	return tests;
}

void
rtg_condition_constructors_tests()
{
	rtg_condition_copy_constructors_tests();
	rtg_condition_transformation_constructors_tests();
}

tests_simple_list *
register_rtg_condition_constructors_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_condition_constructors_tests(tests_simple_list * tests)
{
	return
			register_rtg_condition_transformation_constructors_tests(
					register_rtg_condition_copy_constructors_tests(
							tests
					)
			)
			;
}

void
rtg_condition_type_is_valid_test_10_less_than()
{
	rtg_condition * condition_;
	amara_boolean valid_;

	condition_ = rtg_condition_example_simple_less_than_condition();
	forced_assertion(condition_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_condition_example_simple_less_than_condition(
			condition_);
#endif

	valid_ = rtg_condition_type_is_valid(condition_->type_);
	forced_assertion(valid_ == AMARA_BOOLEAN_TRUE);

	rtg_condition_destructor(condition_);
}

void
rtg_condition_type_is_valid_test_20_greater_than()
{
	rtg_condition * condition_;
	amara_boolean valid_;

	condition_ = rtg_condition_example_simple_greater_than_condition();
	forced_assertion(condition_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_condition_example_simple_greater_than_condition(
			condition_);
#endif

	valid_ = rtg_condition_type_is_valid(condition_->type_);
	forced_assertion(valid_ == AMARA_BOOLEAN_TRUE);

	rtg_condition_destructor(condition_);
}

void
rtg_condition_type_is_valid_tests()
{
	rtg_condition_type_is_valid_test_10_less_than();
	rtg_condition_type_is_valid_test_20_greater_than();
}

tests_simple_list *
register_rtg_condition_type_is_valid_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_condition_type_is_valid_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& rtg_condition_type_is_valid_test_10_less_than);
	tests_simple_list_push_back(
			tests,
			& rtg_condition_type_is_valid_test_20_greater_than);
	return tests;
}

void
rtg_condition_flip_test_0()
{
	rtg_condition * condition_;
	rtg_condition * flipped_condition_;

	condition_ = rtg_condition_example_simple_condition();
	forced_assertion(condition_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_condition_example_simple_condition(
			condition_);
#endif

	flipped_condition_ = rtg_condition_flip(condition_);
#ifndef NDEBUG
	assert_expectations_on_rtg_condition_example_simple_condition(
			condition_);
#endif
	forced_assertion(flipped_condition_ != NULL);
#ifndef NDEBUG
	assertion(flipped_condition_->type_ == RTG_CONDITION_TYPE_GREATER_THAN);
	assertion(flipped_condition_->left_hand_side_expression_ != NULL);
	assertion(flipped_condition_->left_hand_side_expression_->type_ ==
			RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(flipped_condition_->left_hand_side_expression_->sub_natural_literal_ !=
			NULL);
	assertion(flipped_condition_->left_hand_side_expression_->sub_natural_literal_->natural_literal_ !=
			NULL);
	assert_expectations_on_rtg_expression_example_natural_literal_one(
			flipped_condition_->left_hand_side_expression_);
	assertion(flipped_condition_->right_hand_side_expression_ != NULL);
	assertion(flipped_condition_->right_hand_side_expression_->type_ ==
			RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(flipped_condition_->right_hand_side_expression_->sub_natural_literal_ !=
			NULL);
	assertion(flipped_condition_->right_hand_side_expression_->sub_natural_literal_->natural_literal_ !=
			NULL);
	assert_expectations_on_rtg_expression_example_natural_literal_zero(
			flipped_condition_->right_hand_side_expression_);
#endif

	rtg_condition_destructor(condition_);
	rtg_condition_destructor(flipped_condition_);
}

void
rtg_condition_flip_tests()
{
	rtg_condition_flip_test_0();
}

tests_simple_list *
register_rtg_condition_flip_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_condition_flip_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(tests, & rtg_condition_flip_test_0);
	return tests;
}

#ifndef NDEBUG

void
rtg_condition_assert_validity_tests()
{
	rtg_condition * condition_;

	condition_ = rtg_condition_example_simple_greater_than_condition();
	forced_assertion(condition_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_condition_example_simple_greater_than_condition(
			condition_);
#endif

	rtg_condition_assert_validity(condition_);

	rtg_condition_destructor(condition_);
}

#endif

void
rtg_condition_tests()
{
	rtg_condition_constructors_tests();

	rtg_condition_type_is_valid_tests();

	rtg_condition_flip_tests();

#ifndef NDEBUG
	rtg_condition_assert_validity_tests();
#endif
}

tests_simple_list *
register_rtg_condition_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_rtg_condition_constructors_tests(tests);

	returning_ = register_rtg_condition_type_is_valid_tests(returning_);

	returning_ = register_rtg_condition_flip_tests(returning_);

#ifndef NDEBUG
	tests_simple_list_push_back(returning_,
	                            & rtg_condition_assert_validity_tests);
#endif

	return returning_;
}
