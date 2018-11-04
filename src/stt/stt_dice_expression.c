
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
 * src/stt/stt_dice_expression.c: Amara syntax tree dice expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

/*   For own prototypes dependencies. */
#include "stt_dice_expression.h"

/**  FIXME REMOVE THIS */
stt_dice_expression *
stt_dice_expression_exhaustive_constructor(
		const struct natural * left_hand_side,
		const struct natural * right_hand_side)
{
	stt_dice_expression * returning_;

	returning_ = malloc(sizeof(stt_dice_expression));

	returning_->left_hand_side_natural_ =
			natural_copy_constructor(left_hand_side);
	returning_->right_hand_side_natural_ =
			natural_copy_constructor(right_hand_side);
	return returning_;
}

/**  FIXME REMOVE THIS */
void
stt_dice_expression_destructor(stt_dice_expression * dice_expression)
{
	assertion(dice_expression != NULL);
	assertion(dice_expression->left_hand_side_natural_ != NULL);
	assertion(dice_expression->right_hand_side_natural_ != NULL);

	natural_destructor(dice_expression->left_hand_side_natural_);
	natural_destructor(dice_expression->right_hand_side_natural_);
	free(dice_expression);
}
