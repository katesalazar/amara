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
 * src/stt/stt_expression_sub_dice.h: Amara syntax tree dice type of
 * expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `natural * natural_copy_constructor(const natural * natural)`. */
#include "../brt/natural.h"

/*   For `typedef struct stt_expression_sub_dice { ... }
 * stt_expression_sub_dice;`. */
#include "stt_expression_sub_dice.h"

stt_expression_sub_dice *
stt_expression_sub_dice_copy_constructor(
		const stt_expression_sub_dice * stt_expression_sub_dice_)
{
	stt_expression_sub_dice * returning_;

	assertion(stt_expression_sub_dice_ != NULL);
	assertion(stt_expression_sub_dice_->left_hand_side_natural_ != NULL);
	assertion(stt_expression_sub_dice_->left_hand_side_natural_->raw_ !=
			NULL);
	assertion(stt_expression_sub_dice_->left_hand_side_natural_->raw_->value_ !=
			NULL);
	assertion(stt_expression_sub_dice_->right_hand_side_natural_ != NULL);
	assertion(stt_expression_sub_dice_->right_hand_side_natural_->raw_ !=
			NULL);
	assertion(stt_expression_sub_dice_->right_hand_side_natural_->raw_->value_ !=
			NULL);

	returning_ = malloc(sizeof(stt_expression_sub_dice));

	returning_->left_hand_side_natural_ = natural_copy_constructor(
			stt_expression_sub_dice_->left_hand_side_natural_);

	returning_->right_hand_side_natural_ = natural_copy_constructor(
			stt_expression_sub_dice_->right_hand_side_natural_);

	return returning_;
}

stt_expression_sub_dice *
stt_expression_sub_dice_exhaustive_constructor(
		const natural * left_hand_side,
		const natural * right_hand_side)
{
	stt_expression_sub_dice * returning_;

	assertion(left_hand_side != NULL);
	assertion(left_hand_side->raw_ != NULL);
	assertion(left_hand_side->raw_->value_ != NULL);
	assertion(right_hand_side != NULL);
	assertion(right_hand_side->raw_ != NULL);
	assertion(right_hand_side->raw_->value_ != NULL);

	returning_ = malloc(sizeof(stt_expression_sub_dice));

	returning_->left_hand_side_natural_ =
			natural_copy_constructor(left_hand_side);

	returning_->right_hand_side_natural_ =
			natural_copy_constructor(right_hand_side);

	return returning_;
}

void
stt_expression_sub_dice_destructor(
		stt_expression_sub_dice * stt_expression_sub_dice_)
{
	assertion(stt_expression_sub_dice_ != NULL);
	assertion(stt_expression_sub_dice_->left_hand_side_natural_ != NULL);
	assertion(stt_expression_sub_dice_->right_hand_side_natural_ != NULL);
	natural_destructor(stt_expression_sub_dice_->left_hand_side_natural_);
	natural_destructor(stt_expression_sub_dice_->right_hand_side_natural_);
	free(stt_expression_sub_dice_);
}
