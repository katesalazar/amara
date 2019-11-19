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
 * src/stt/stt_dice_expression_tests.c: Test the Amara syntax tree dice
 * expression.
 */

/*   For `void forced_assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `natural * natural_example_zero()`. */
#include "../brt/natural_tests.h"

/*   For `typedef stt_dice_expression { ... } stt_dice_expression`. */
#include "stt_dice_expression.h"

#ifndef NDEBUG

void
assert_expectations_on_stt_dice_expression_example_single_vanilla_dice(
		const stt_dice_expression * dice_expression)
{
	assertion(dice_expression != NULL);
	assertion(dice_expression->left_hand_side_natural_ != NULL);
	assertion(dice_expression->left_hand_side_natural_->raw_ != NULL);
	assertion(dice_expression->left_hand_side_natural_->raw_->value_ !=
			NULL);
	assertion(dice_expression->left_hand_side_natural_->raw_->value_[0] ==
			'1');
	assertion(dice_expression->left_hand_side_natural_->raw_->value_[1] ==
			'\0');
	assertion(dice_expression->right_hand_side_natural_ != NULL);
	assertion(dice_expression->right_hand_side_natural_->raw_ != NULL);
	assertion(dice_expression->right_hand_side_natural_->raw_->value_ !=
			NULL);
	assertion(dice_expression->right_hand_side_natural_->raw_->value_[0] ==
			'6');
	assertion(dice_expression->right_hand_side_natural_->raw_->value_[1] ==
			'\0');
}

#endif

stt_dice_expression *
stt_dice_expression_example_single_vanilla_dice()
{
	stt_dice_expression * ret_;
	natural * left_hand_side_natural_;
	natural * right_hand_side_natural_;

	left_hand_side_natural_ = natural_example_one();
	forced_assertion(left_hand_side_natural_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_natural_example_one(left_hand_side_natural_);
#endif

	right_hand_side_natural_ = natural_example_six();
	forced_assertion(right_hand_side_natural_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_natural_example_six(right_hand_side_natural_);
#endif

	ret_ = stt_dice_expression_exhaustive_constructor(
			left_hand_side_natural_, right_hand_side_natural_);

	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_dice_expression_example_single_vanilla_dice(
			ret_);
#endif

	natural_destructor(left_hand_side_natural_);
	natural_destructor(right_hand_side_natural_);

	return ret_;
}

void
stt_dice_expression_constructors_test_0()
{
	natural * natural_zero_;
	natural * left_hand_side_natural_;
	natural * natural_one_;
	natural * right_hand_side_natural_;
	stt_dice_expression * dice_expression_;

	natural_zero_ = natural_example_zero();
#ifndef NDEBUG
	assertion(natural_zero_ != NULL);
	assert_expectations_on_natural_example_zero(natural_zero_);
#endif

	natural_one_ = natural_example_one();
#ifndef NDEBUG
	assertion(natural_one_ != NULL);
	assert_expectations_on_natural_example_one(natural_one_);
#endif

	left_hand_side_natural_ = natural_zero_;
	right_hand_side_natural_ = natural_one_;

	dice_expression_ = stt_dice_expression_exhaustive_constructor(
			left_hand_side_natural_, right_hand_side_natural_);
#ifndef NDEBUG
	assertion(dice_expression_ != NULL);
#endif

	stt_dice_expression_destructor(dice_expression_);
	natural_destructor(natural_one_);
	natural_destructor(natural_zero_);
}

void
stt_dice_expression_constructors_tests()
{
	stt_dice_expression_constructors_test_0();
}

void
stt_dice_expression_tests()
{
	stt_dice_expression_constructors_tests();
}
