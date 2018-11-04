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
 * src/rtg/rtg_expression_sub_dice.c: Amara run time graph dice type of
 * expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `natural * natural_copy_constructor(const natural * natural)`. */
#include "../brt/natural.h"

/*   For `rtg_expression_sub_dice`. */
#include "rtg_expression_sub_dice.h"

rtg_expression_sub_dice *
rtg_expression_sub_dice_out_of_stt_expression_sub_dice(
		const stt_expression_sub_dice * expression_sub_dice)
{
	rtg_expression_sub_dice * returning_;

	assertion(expression_sub_dice != NULL);
	assertion(expression_sub_dice->left_hand_side_natural_ != NULL);
	assertion(expression_sub_dice->right_hand_side_natural_ != NULL);

	returning_ = malloc(sizeof(rtg_expression_sub_dice));

	returning_->left_hand_side_natural_ = natural_copy_constructor(
			expression_sub_dice->left_hand_side_natural_);

	returning_->right_hand_side_natural_ = natural_copy_constructor(
			expression_sub_dice->right_hand_side_natural_);

	return returning_;
}

#ifndef NDEBUG

void
rtg_expression_sub_dice_assert_validity(
		const rtg_expression_sub_dice * expression_sub_dice)
{
	assertion(expression_sub_dice != NULL);

	assertion(expression_sub_dice->left_hand_side_natural_ != NULL);
	natural_assert_validity(expression_sub_dice->left_hand_side_natural_);

	assertion(expression_sub_dice->right_hand_side_natural_ != NULL);
	natural_assert_validity(expression_sub_dice->right_hand_side_natural_);
}

#endif
