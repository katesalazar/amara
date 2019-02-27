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
 * src/stt/stt_expression_sub_conditional.c: Amara syntax tree
 * conditional type of expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

/*   For `stt_expression_sub_conditional`. */
#include "stt_expression_sub_conditional.h"

stt_expression_sub_conditional_if *
stt_expression_sub_conditional_if_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_expression_sub_conditional_if *
stt_expression_sub_conditional_if_default_constructor()
{
	stt_expression_sub_conditional_if * returning_;

	returning_ = malloc(sizeof(stt_expression_sub_conditional_if));
	assertion(returning_ != NULL);

	returning_->type_ = STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID;
	returning_->condition_ = NULL;
	returning_->expression_then_ = NULL;
	returning_->next_if_ = NULL;
	returning_->expression_else_ = NULL;

	return returning_;
}

stt_expression_sub_conditional *
stt_expression_sub_conditional_default_constructor()
{
	stt_expression_sub_conditional * returning_;

	returning_ = malloc(sizeof(stt_expression_sub_conditional));
	assertion(returning_ != NULL);

	returning_->if_ = NULL;

	return returning_;
}


stt_expression_sub_conditional_if *
stt_expression_sub_conditional_if_copy_constructor(
		const stt_expression_sub_conditional_if * expression_sub_conditional_if)
__attribute__((warn_unused_result))
;

stt_expression_sub_conditional_if *
stt_expression_sub_conditional_if_copy_constructor(
		const stt_expression_sub_conditional_if * expression_sub_conditional_if)
{
	stt_expression_sub_conditional_if * returning_;

	assertion(expression_sub_conditional_if != NULL);
	assertion(expression_sub_conditional_if->type_ !=
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
	assertion(expression_sub_conditional_if->condition_ != NULL);
	assertion(expression_sub_conditional_if->expression_then_ != NULL);

	forced_assertion(expression_sub_conditional_if->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);

	/*
	if (expression_sub_conditional_if->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE) {
	*/

		assertion(expression_sub_conditional_if->expression_else_ !=
				NULL);
		assertion(expression_sub_conditional_if->next_if_ == NULL);
	/*
	} else {
		forced_assertion(expression_sub_conditional_if->type_ ==
				STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF);

		assertion(expression_sub_conditional_if->expression_else_ ==
				NULL);
		assertion(expression_sub_conditional_if->next_if_ != NULL);
	}
	*/

	returning_ = malloc(sizeof(stt_expression_sub_conditional_if));

	returning_->condition_ = stt_condition_copy_constructor(
			expression_sub_conditional_if->condition_);

	returning_->expression_then_ = stt_expression_copy_constructor(
			expression_sub_conditional_if->expression_then_);

	forced_assertion(expression_sub_conditional_if->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);

	/*
	if (expression_sub_conditional_if->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE) {
	*/

		returning_->expression_else_ = stt_expression_copy_constructor(
				expression_sub_conditional_if->expression_else_);
		returning_->next_if_ = NULL;
		returning_->type_ =
				STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE;
	/*
	} else {
		assertion(expression_sub_conditional_if->type_ ==
				STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF);

		returning_->expression_else_ = NULL;
		returning_->next_if_ =
				stt_expression_sub_conditional_if_copy_constructor(
						expression_sub_conditional_if
								->next_if_);
		returning_->type_ =
				STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF;
	}
	*/

	return returning_;
}

stt_expression_sub_conditional *
stt_expression_sub_conditional_copy_constructor(
		const stt_expression_sub_conditional * expression_sub_conditional)
{
	stt_expression_sub_conditional * returning_;

	assertion(expression_sub_conditional != NULL);
	assertion(expression_sub_conditional->if_ != NULL);

	returning_ = malloc(sizeof(stt_expression_sub_conditional));
	assertion(returning_ != NULL);

	returning_->if_ = stt_expression_sub_conditional_if_copy_constructor(
			expression_sub_conditional->if_);
#ifndef NDEBUG
	assertion(returning_->if_ != NULL);
	assertion(returning_->if_->type_ !=
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
#endif

	return returning_;
}

void
stt_expression_sub_conditional_if_destructor(
		stt_expression_sub_conditional_if * expression_sub_conditional_if)
;

void
stt_expression_sub_conditional_if_destructor(
		stt_expression_sub_conditional_if * expression_sub_conditional_if)
{
#ifndef NDEBUG
	assertion(expression_sub_conditional_if != NULL);
	assertion(expression_sub_conditional_if->type_ !=
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
	assertion(expression_sub_conditional_if->condition_ != NULL);
	assertion(expression_sub_conditional_if->expression_then_ != NULL);
	assertion(expression_sub_conditional_if->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);
	assertion(expression_sub_conditional_if->expression_else_ != NULL);
	assertion(expression_sub_conditional_if->next_if_ == NULL);
#endif

	stt_condition_destructor(expression_sub_conditional_if->condition_);

	stt_expression_destructor(
			expression_sub_conditional_if->expression_then_);

#ifndef NDEBUG
	assertion(expression_sub_conditional_if->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);
#endif

	stt_expression_destructor(
			expression_sub_conditional_if->expression_else_);

	free(expression_sub_conditional_if);
}

void
stt_expression_sub_conditional_destructor(
		stt_expression_sub_conditional * expression_sub_conditional)
{
#ifndef NDEBUG
	assertion(expression_sub_conditional != NULL);
	assertion(expression_sub_conditional->if_ != NULL);
#endif

	stt_expression_sub_conditional_if_destructor(
			expression_sub_conditional->if_);
	free(expression_sub_conditional);
}

void
stt_expression_sub_conditional_if_set_condition(
		stt_expression_sub_conditional_if * sub_conditional_if,
		const struct stt_condition * condition)
;

void
stt_expression_sub_conditional_if_set_condition(
		stt_expression_sub_conditional_if * sub_conditional_if,
		const struct stt_condition * condition)
{
	assertion(sub_conditional_if != NULL);
	assertion(sub_conditional_if->condition_ == NULL);

	sub_conditional_if->condition_ =
			stt_condition_copy_constructor(condition);
}

void
stt_expression_sub_conditional_set_condition(
		stt_expression_sub_conditional * sub_conditional,
		const struct stt_condition * condition)
{
#ifndef NDEBUG
	assertion(sub_conditional != NULL);
#endif

#ifndef NDEBUG
	assertion(condition != NULL);
	assertion(condition->type_ != STT_CONDITION_TYPE_INVALID);
#endif

	if (sub_conditional->if_ == NULL) {

		sub_conditional->if_ =
				stt_expression_sub_conditional_if_default_constructor();
#ifndef NDEBUG
		assertion(sub_conditional->if_ != NULL);
		assertion(sub_conditional->if_->type_ ==
				STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
		assertion(sub_conditional->if_->condition_ == NULL);
		assertion(sub_conditional->if_->expression_then_ == NULL);
		assertion(sub_conditional->if_->expression_else_ == NULL);
		assertion(sub_conditional->if_->next_if_ == NULL);
#endif
	} else {

#ifndef NDEBUG
		assertion(sub_conditional->if_->type_ ==
				STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
		assertion(sub_conditional->if_->condition_ == NULL);
#endif
	}

	stt_expression_sub_conditional_if_set_condition(
			sub_conditional->if_, condition);
}

void
stt_expression_sub_conditional_if_set_expression_then(
		stt_expression_sub_conditional_if * sub_conditional_if,
		const struct stt_expression * expression_then)
;

void
stt_expression_sub_conditional_if_set_expression_then(
		stt_expression_sub_conditional_if * sub_conditional_if,
		const struct stt_expression * expression_then)
{
#ifndef NDEBUG
	assertion(sub_conditional_if != NULL);
	assertion(sub_conditional_if->expression_then_ == NULL);
#endif

	sub_conditional_if->expression_then_ =
			stt_expression_copy_constructor(expression_then);
}

void
stt_expression_sub_conditional_set_expression_then(
		stt_expression_sub_conditional * sub_conditional,
		const struct stt_expression * expression_then)
{
#ifndef NDEBUG
	assertion(sub_conditional != NULL);
#endif

#ifndef NDEBUG
	assertion(expression_then != NULL);
	assertion(expression_then->type_ != STT_EXPRESSION_TYPE_INVALID);
#endif

	if (sub_conditional->if_ == NULL) {

		sub_conditional->if_ =
				stt_expression_sub_conditional_if_default_constructor();
#ifndef NDEBUG
		assertion(sub_conditional->if_ != NULL);
		assertion(sub_conditional->if_->type_ ==
				STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
		assertion(sub_conditional->if_->condition_ == NULL);
		assertion(sub_conditional->if_->expression_then_ == NULL);
		assertion(sub_conditional->if_->expression_else_ == NULL);
		assertion(sub_conditional->if_->next_if_ == NULL);
#endif
	} else {

#ifndef NDEBUG
		assertion(sub_conditional->if_->type_ ==
				STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
		assertion(sub_conditional->if_->expression_then_ == NULL);
#endif
	}

	stt_expression_sub_conditional_if_set_expression_then(
			sub_conditional->if_, expression_then);
}

void
stt_expression_sub_conditional_if_set_expression_else(
		stt_expression_sub_conditional_if * sub_conditional_if,
		const struct stt_expression * expression_else)
;

void
stt_expression_sub_conditional_if_set_expression_else(
		stt_expression_sub_conditional_if * sub_conditional_if,
		const struct stt_expression * expression_else)
{
#ifndef NDEBUG
	assertion(sub_conditional_if != NULL);
	assertion(sub_conditional_if->expression_else_ == NULL);
	assertion(sub_conditional_if->next_if_ == NULL);
#endif

	sub_conditional_if->expression_else_ =
			stt_expression_copy_constructor(expression_else);
	sub_conditional_if->type_ =
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE;
}

void
stt_expression_sub_conditional_set_expression_else(
		stt_expression_sub_conditional * sub_conditional,
		const struct stt_expression * expression_else)
{
#ifndef NDEBUG
	assertion(sub_conditional != NULL);
	assertion(sub_conditional->if_ != NULL);
#endif

	stt_expression_sub_conditional_if_set_expression_else(
			sub_conditional->if_, expression_else);
}
