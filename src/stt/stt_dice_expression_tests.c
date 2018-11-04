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
 * src/stt/stt_dice_expression_tests.c: Test the Amara syntax tree dice
 * expression.
 */

/*   For `natural * natural_example_zero()`. */
#include "../brt/natural_tests.h"

/*   For `typedef stt_dice_expression { ... } stt_dice_expression`. */
#include "stt_dice_expression.h"

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
