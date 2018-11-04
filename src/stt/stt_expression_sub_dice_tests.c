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
 * src/stt/stt_expression_sub_dice_tests.c: Test the Amara syntax tree
 * dice type of expression.
 */

/*   For `natural * natural_example_one()`. */
#include "../brt/natural_tests.h"

/*   For own functions prototypes. */
#include "stt_expression_sub_dice_tests.h"

stt_expression_sub_dice *
stt_expression_sub_dice_example_single_vanilla_dice()
{
	natural * number_of_dices_;
	natural * dice_sides_;
	stt_expression_sub_dice * returning_;

	number_of_dices_ = natural_example_one();
#ifndef NDEBUG
	assertion(number_of_dices_ != NULL);
	assert_expectations_on_natural_example_one(number_of_dices_);
#endif

	dice_sides_ = natural_example_six();
#ifndef NDEBUG
	assertion(dice_sides_ != NULL);
	assert_expectations_on_natural_example_six(dice_sides_);
#endif

	returning_ = stt_expression_sub_dice_exhaustive_constructor(
			number_of_dices_, dice_sides_);
#ifndef NDEBUG
	assertion(returning_ != NULL);
	assert_expectations_on_natural_example_one(
			returning_->left_hand_side_natural_);
	assert_expectations_on_natural_example_six(
			returning_->right_hand_side_natural_);
#endif

	natural_destructor(number_of_dices_);
	natural_destructor(dice_sides_);

	return returning_;
}

void
stt_expression_sub_dice_exhaustive_constructor_test_0()
{
	stt_expression_sub_dice * dice_;

	dice_ = stt_expression_sub_dice_example_single_vanilla_dice();
#ifndef NDEBUG
	assertion(dice_ != NULL);
	assert_expectations_on_natural_example_one(
			dice_->left_hand_side_natural_);
	assert_expectations_on_natural_example_six(
			dice_->right_hand_side_natural_);
#endif

	stt_expression_sub_dice_destructor(dice_);
}

void
stt_expression_sub_dice_copy_constructor_test_0()
{
	stt_expression_sub_dice * dice_zero_;
	stt_expression_sub_dice * dice_one_;

	dice_zero_ = stt_expression_sub_dice_example_single_vanilla_dice();
#ifndef NDEBUG
	assertion(dice_zero_ != NULL);
	assert_expectations_on_natural_example_one(
			dice_zero_->left_hand_side_natural_);
	assert_expectations_on_natural_example_six(
			dice_zero_->right_hand_side_natural_);
#endif

	dice_one_ = stt_expression_sub_dice_copy_constructor(dice_zero_);
#ifndef NDEBUG
	assert_expectations_on_natural_example_one(
			dice_zero_->left_hand_side_natural_);
	assert_expectations_on_natural_example_six(
			dice_zero_->right_hand_side_natural_);
	assertion(dice_one_ != NULL);
	assert_expectations_on_natural_example_one(
			dice_one_->left_hand_side_natural_);
	assert_expectations_on_natural_example_six(
			dice_one_->right_hand_side_natural_);
#endif

	stt_expression_sub_dice_destructor(dice_one_);
	stt_expression_sub_dice_destructor(dice_zero_);
}

void
stt_expression_sub_dice_exhaustive_constructor_tests()
{
	stt_expression_sub_dice_exhaustive_constructor_test_0();
}

void
stt_expression_sub_dice_copy_constructor_tests()
{
	stt_expression_sub_dice_copy_constructor_test_0();
}

void
stt_expression_sub_dice_constructors_tests()
{
	stt_expression_sub_dice_exhaustive_constructor_tests();
	stt_expression_sub_dice_copy_constructor_tests();
}

void
stt_expression_sub_dice_tests()
{
	stt_expression_sub_dice_constructors_tests();
}
