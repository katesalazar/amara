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
 * src/rtg/rtg_expression_sub_dice_test_tests.c: Amara run time graph
 * dice type of expression tests.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_expression_sub_dice *
 * stt_expression_sub_dice_example_single_vanilla_dice()`. */
#include "../stt/stt_expression_sub_dice_tests.h"

/*   For own prototypes. */
#include "rtg_expression_sub_dice_tests.h"

rtg_expression_sub_dice *
rtg_expression_sub_dice_example_single_vanilla_dice(void)
{
	stt_expression_sub_dice * stt_expression_sub_dice_;
	rtg_expression_sub_dice * rtg_expression_sub_dice_;

	stt_expression_sub_dice_ =
			stt_expression_sub_dice_example_single_vanilla_dice();
	forced_assertion(stt_expression_sub_dice_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
			stt_expression_sub_dice_);
#endif

	rtg_expression_sub_dice_ =
			rtg_expression_sub_dice_out_of_stt_expression_sub_dice(
					stt_expression_sub_dice_);
	forced_assertion(rtg_expression_sub_dice_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_sub_dice_example_single_vanilla_dice(
			rtg_expression_sub_dice_);
#endif

	stt_expression_sub_dice_destructor(stt_expression_sub_dice_);

	return rtg_expression_sub_dice_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_sub_dice_example_single_vanilla_dice(
		const rtg_expression_sub_dice * expression_sub_dice)
{
	assertion(expression_sub_dice != NULL);
	assertion(expression_sub_dice->left_hand_side_natural_ != NULL);
	assertion(expression_sub_dice->left_hand_side_natural_->raw_ != NULL);
	assertion(expression_sub_dice->left_hand_side_natural_->raw_->value_ !=
			NULL);
	assertion(expression_sub_dice->left_hand_side_natural_->raw_->value_[0] ==
			'1');
	assertion(expression_sub_dice->left_hand_side_natural_->raw_->value_[1] ==
			'\0');
	assertion(expression_sub_dice->right_hand_side_natural_ != NULL);
	assertion(expression_sub_dice->right_hand_side_natural_->raw_ != NULL);
	assertion(expression_sub_dice->right_hand_side_natural_->raw_->value_ !=
			NULL);
	assertion(expression_sub_dice->right_hand_side_natural_->raw_->value_[0] ==
			'6');
	assertion(expression_sub_dice->right_hand_side_natural_->raw_->value_[1] ==
			'\0');
}

#endif

void
rtg_expression_sub_dice_transformation_constructor_test_0()
{
	stt_expression_sub_dice * stt_expression_sub_dice_;
	rtg_expression_sub_dice * rtg_expression_sub_dice_;

	stt_expression_sub_dice_ =
			stt_expression_sub_dice_example_single_vanilla_dice();
	forced_assertion(stt_expression_sub_dice_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
			stt_expression_sub_dice_);
#endif

	rtg_expression_sub_dice_ =
			rtg_expression_sub_dice_out_of_stt_expression_sub_dice(
					stt_expression_sub_dice_);
	forced_assertion(rtg_expression_sub_dice_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_sub_dice_example_single_vanilla_dice(
			rtg_expression_sub_dice_);
#endif

	rtg_expression_sub_dice_destructor(rtg_expression_sub_dice_);
	stt_expression_sub_dice_destructor(stt_expression_sub_dice_);
}

void
rtg_expression_sub_dice_transformation_constructor_tests()
{
	rtg_expression_sub_dice_transformation_constructor_test_0();
}

void
rtg_expression_sub_dice_constructors_tests()
{
	rtg_expression_sub_dice_transformation_constructor_tests();
}

#ifndef NDEBUG

void
rtg_expression_sub_dice_validity_test_0()
{
	stt_expression_sub_dice * stt_expression_sub_dice_;
	rtg_expression_sub_dice * rtg_expression_sub_dice_;

	stt_expression_sub_dice_ =
			stt_expression_sub_dice_example_single_vanilla_dice();
	forced_assertion(stt_expression_sub_dice_ != NULL);
	assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
			stt_expression_sub_dice_);

	rtg_expression_sub_dice_ =
			rtg_expression_sub_dice_out_of_stt_expression_sub_dice(
					stt_expression_sub_dice_);
	forced_assertion(rtg_expression_sub_dice_ != NULL);
	assert_expectations_on_rtg_expression_sub_dice_example_single_vanilla_dice(
			rtg_expression_sub_dice_);

	rtg_expression_sub_dice_assert_validity(rtg_expression_sub_dice_);

	rtg_expression_sub_dice_destructor(rtg_expression_sub_dice_);
	stt_expression_sub_dice_destructor(stt_expression_sub_dice_);
}

#endif

#ifndef NDEBUG

void
rtg_expression_sub_dice_validity_tests()
{
	rtg_expression_sub_dice_validity_test_0();
}

#endif

void
rtg_expression_sub_dice_tests()
{
	rtg_expression_sub_dice_constructors_tests();
#ifndef NDEBUG
	rtg_expression_sub_dice_validity_tests();
#endif
}
