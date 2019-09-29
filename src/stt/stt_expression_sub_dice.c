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
 * src/stt/stt_expression_sub_dice.h: Amara syntax tree dice type of
 * expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

/*   For `natural * natural_copy_constructor(const natural * natural)`. */
#include "../brt/natural.h"

/*   For `typedef struct stt_expression_sub_dice { ... }
 * stt_expression_sub_dice;`. */
#include "stt_expression_sub_dice.h"

stt_expression_sub_dice *
stt_expression_sub_dice_exhaustive_constructor(
		const natural * left_hand_side,
		const natural * right_hand_side)
{
	stt_expression_sub_dice * returning_;

#ifndef NDEBUG
	assertion(left_hand_side != NULL);
	assertion(left_hand_side->raw_ != NULL);
	assertion(left_hand_side->raw_->value_ != NULL);
	assertion(right_hand_side != NULL);
	assertion(right_hand_side->raw_ != NULL);
	assertion(right_hand_side->raw_->value_ != NULL);
#endif

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_expression_sub_dice *)
#endif
			malloc(sizeof(stt_expression_sub_dice));
	forced_assertion(returning_ != NULL);

	returning_->left_hand_side_natural_ =
			natural_copy_constructor(left_hand_side);

	returning_->right_hand_side_natural_ =
			natural_copy_constructor(right_hand_side);

	return returning_;
}

stt_expression_sub_dice *
stt_expression_sub_dice_copy_constructor(
		const stt_expression_sub_dice * expression_sub_dice)
{
	stt_expression_sub_dice * returning_;

#ifndef NDEBUG
	assertion(expression_sub_dice != NULL);
	assertion(expression_sub_dice->left_hand_side_natural_ != NULL);
	assertion(expression_sub_dice->left_hand_side_natural_->raw_ !=
			NULL);
	assertion(expression_sub_dice->left_hand_side_natural_->raw_->value_ !=
			NULL);
	assertion(expression_sub_dice->right_hand_side_natural_ != NULL);
	assertion(expression_sub_dice->right_hand_side_natural_->raw_ !=
			NULL);
	assertion(expression_sub_dice->right_hand_side_natural_->raw_->value_ !=
			NULL);
#endif

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_expression_sub_dice *)
#endif
			malloc(sizeof(stt_expression_sub_dice));
	forced_assertion(returning_ != NULL);

	returning_->left_hand_side_natural_ = natural_copy_constructor(
			expression_sub_dice->left_hand_side_natural_);

	returning_->right_hand_side_natural_ = natural_copy_constructor(
			expression_sub_dice->right_hand_side_natural_);

	return returning_;
}

void
stt_expression_sub_dice_destructor(
		stt_expression_sub_dice * stt_expression_sub_dice_)
{
#ifndef NDEBUG
	assertion(stt_expression_sub_dice_ != NULL);
	assertion(stt_expression_sub_dice_->left_hand_side_natural_ != NULL);
	assertion(stt_expression_sub_dice_->right_hand_side_natural_ != NULL);
#endif
	natural_destructor(stt_expression_sub_dice_->left_hand_side_natural_);
	natural_destructor(stt_expression_sub_dice_->right_hand_side_natural_);
	free(stt_expression_sub_dice_);
}

amara_boolean
stt_expression_sub_dice_equality(
		const stt_expression_sub_dice * esd0,
		const stt_expression_sub_dice * esd1)
{
	amara_boolean returning_;

#ifndef NDEBUG
	assertion(esd0 != NULL);
	assertion(esd1 != NULL);
#endif

#ifndef NDEBUG
	assertion(esd0->left_hand_side_natural_ != NULL);
	assertion(esd1->left_hand_side_natural_ != NULL);
#endif

	returning_ = naturals_equality(
			esd0->left_hand_side_natural_,
			esd1->left_hand_side_natural_);

	if (returning_ == AMARA_BOOLEAN_FALSE) {
		return AMARA_BOOLEAN_FALSE;
	}

#ifndef NDEBUG
	assertion(esd0->right_hand_side_natural_ != NULL);
	assertion(esd1->right_hand_side_natural_ != NULL);
#endif

	returning_ = naturals_equality(
			esd0->right_hand_side_natural_,
			esd1->right_hand_side_natural_);

	return returning_;
}

amara_boolean
stt_expression_sub_dices_equality(
		const stt_expression_sub_dice * esd0,
		const stt_expression_sub_dice * esd1)
{
	return stt_expression_sub_dice_equality(esd0, esd1);
}
