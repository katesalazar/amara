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
 * src/stt/stt_condition.c: Amara syntax tree condition.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_condition.h"

stt_condition *
stt_condition_copy_constructor(const stt_condition * condition)
{
	stt_condition * returning_;

	assertion(condition != NULL);
	assertion(condition->type_ != STT_CONDITION_TYPE_INVALID);
	assertion(condition->left_hand_side_expression_ != NULL);
	assertion(condition->left_hand_side_expression_->type_ !=
			STT_EXPRESSION_TYPE_INVALID);
	assertion(condition->right_hand_side_expression_ != NULL);
	assertion(condition->right_hand_side_expression_->type_ !=
			STT_EXPRESSION_TYPE_INVALID);

	returning_ = malloc(sizeof(stt_condition));

	returning_->left_hand_side_expression_ =
			stt_expression_copy_constructor(
					condition->left_hand_side_expression_);

	returning_->right_hand_side_expression_ =
			stt_expression_copy_constructor(
					condition->right_hand_side_expression_);

	returning_->type_ = condition->type_;

	return returning_;
}

void
stt_condition_destructor(stt_condition * condition)
{
	assertion(condition != NULL);
	assertion(condition->type_ != STT_CONDITION_TYPE_INVALID);
	assertion(condition->left_hand_side_expression_ != NULL);
	assertion(condition->left_hand_side_expression_->type_ !=
			STT_EXPRESSION_TYPE_INVALID);
	assertion(condition->right_hand_side_expression_ != NULL);
	assertion(condition->right_hand_side_expression_->type_ !=
			STT_EXPRESSION_TYPE_INVALID);

	stt_expression_destructor(condition->left_hand_side_expression_);
	stt_expression_destructor(condition->right_hand_side_expression_);
	free(condition);
}
