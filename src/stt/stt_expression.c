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
 * src/stt/stt_expression.c: Amara syntax tree expression.
 */

/*   For `NULL`. */
#include <stdlib.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_expression.h"

stt_expression *
stt_expression_default_constructor(void)
{
	stt_expression * returning_;

	returning_ = malloc(sizeof(stt_expression));

	returning_->sub_dice_ = NULL;
	returning_->type_ = STT_EXPRESSION_TYPE_INVALID;

	return returning_;
}

stt_expression *
stt_expression_copy_constructor(const stt_expression * expression)
{
	stt_expression * returning_;

	assertion(expression != NULL);
	assertion(expression->type_ != STT_EXPRESSION_TYPE_INVALID);

	returning_ = malloc(sizeof(stt_expression));

	if (expression->type_ == STT_EXPRESSION_TYPE_DICE) {
		assertion(expression->sub_dice_ != NULL);
		returning_->sub_dice_ =
				stt_expression_sub_dice_copy_constructor(
						expression->sub_dice_);
	}

	returning_->type_ = expression->type_;

	return returning_;
}

void
stt_expression_set_dice(stt_expression * expression,
                        const stt_dice_expression * dice_expression)
{
	stt_expression_sub_dice * expression_sub_dice_;

	assertion(expression != NULL);
	assertion(expression->type_ == STT_EXPRESSION_TYPE_INVALID);
	assertion(expression->sub_dice_ == NULL);

	assertion(dice_expression != NULL);
	assertion(dice_expression->left_hand_side_natural_ != NULL);
	assertion(dice_expression->right_hand_side_natural_ != NULL);

	expression_sub_dice_ = stt_expression_sub_dice_exhaustive_constructor(
			dice_expression->left_hand_side_natural_,
			dice_expression->right_hand_side_natural_);

	expression->sub_dice_ = expression_sub_dice_;
	expression->type_ = STT_EXPRESSION_TYPE_DICE;
}

void
stt_expression_destructor(stt_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ != STT_EXPRESSION_TYPE_INVALID);
	if (expression->type_ == STT_EXPRESSION_TYPE_DICE) {
		assertion(expression->sub_dice_ != NULL);
		stt_expression_sub_dice_destructor(expression->sub_dice_);
	}
	free(expression);
}
