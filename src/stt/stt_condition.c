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
 * src/stt/stt_condition.c: Amara syntax tree condition.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

/*   For own definitions. */
#include "stt_condition.h"

stt_condition *
stt_condition_default_constructor()
{
	stt_condition * returning_;

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_condition *)
#endif
			malloc(sizeof(stt_condition));
	forced_assertion_two(returning_ != NULL, "stt_condition.c: 39\n");

	returning_->left_hand_side_expression_ = NULL;

	returning_->right_hand_side_expression_ = NULL;

	returning_->type_ = STT_CONDITION_TYPE_INVALID;

	return returning_;
}

stt_condition *
stt_condition_copy_constructor(const stt_condition * condition)
{
	stt_condition * returning_;

#ifndef NDEBUG
	assertion(condition != NULL);
	assertion(condition->type_ != STT_CONDITION_TYPE_INVALID);
	assertion(condition->left_hand_side_expression_ != NULL);
	assertion(condition->left_hand_side_expression_->type_ !=
			STT_EXPRESSION_TYPE_INVALID);
	stt_expression_assert_cleanliness(
			condition->left_hand_side_expression_);
	assertion(condition->right_hand_side_expression_ != NULL);
	assertion(condition->right_hand_side_expression_->type_ !=
			STT_EXPRESSION_TYPE_INVALID);
	stt_expression_assert_cleanliness(
			condition->right_hand_side_expression_);
#endif

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_condition *)
#endif
			malloc(sizeof(stt_condition));
	forced_assertion_two(returning_ != NULL,
			"malloc failed, stt_condition.c: 75\n");

	returning_->left_hand_side_expression_ =
			stt_expression_copy_constructor(
					condition->left_hand_side_expression_);
#ifndef NDEBUG
	assertion(returning_->left_hand_side_expression_ != NULL);
	stt_expression_assert_cleanliness(
			returning_->left_hand_side_expression_);
#endif

	returning_->right_hand_side_expression_ =
			stt_expression_copy_constructor(
					condition->right_hand_side_expression_);
#ifndef NDEBUG
	assertion(returning_->right_hand_side_expression_ != NULL);
	stt_expression_assert_cleanliness(
			returning_->right_hand_side_expression_);
#endif

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

void
stt_condition_initialize_less_than(
		stt_condition * condition,
		const struct stt_expression * left_hand_side_expression,
		const struct stt_expression * right_hand_side_expression)
{
	assertion(condition != NULL);
	assertion(condition->type_ == STT_CONDITION_TYPE_INVALID);
	assertion(condition->left_hand_side_expression_ == NULL);
	assertion(condition->right_hand_side_expression_ == NULL);

	condition->left_hand_side_expression_ =
			stt_expression_copy_constructor(
					left_hand_side_expression);

	condition->right_hand_side_expression_ =
			stt_expression_copy_constructor(
					right_hand_side_expression);

	condition->type_ = STT_CONDITION_TYPE_LESS_THAN;
}

void
stt_condition_initialize_greater_than(
		stt_condition * condition,
		const struct stt_expression * left_hand_side_expression,
		const struct stt_expression * right_hand_side_expression)
{
	assertion(condition != NULL);
	assertion(condition->type_ == STT_CONDITION_TYPE_INVALID);
	assertion(condition->left_hand_side_expression_ == NULL);
	assertion(condition->right_hand_side_expression_ == NULL);

	condition->left_hand_side_expression_ =
			stt_expression_copy_constructor(
					left_hand_side_expression);

	condition->right_hand_side_expression_ =
			stt_expression_copy_constructor(
					right_hand_side_expression);

	condition->type_ = STT_CONDITION_TYPE_GREATER_THAN;
}

amara_boolean
stt_condition_equality(const stt_condition * c0, const stt_condition * c1)
{
	amara_boolean equality_;
	amara_boolean returning_;

#ifndef NDEBUG
	assertion(c0 != NULL);
	assertion(c0->type_ != STT_CONDITION_TYPE_INVALID);
	assertion(c0->left_hand_side_expression_ != NULL);
	assertion(c0->right_hand_side_expression_ != NULL);
	assertion(c1 != NULL);
	assertion(c1->type_ != STT_CONDITION_TYPE_INVALID);
	assertion(c1->left_hand_side_expression_ != NULL);
	assertion(c1->right_hand_side_expression_ != NULL);
#endif

	assertion(c0->type_ == c1->type_);  /* XXX */

	if (c0->type_ == STT_CONDITION_TYPE_LESS_THAN) {

		assertion(c0->type_ == STT_CONDITION_TYPE_LESS_THAN);
		assertion(c1->type_ == STT_CONDITION_TYPE_LESS_THAN);
	} else {
		forced_assertion(c0->type_ == STT_CONDITION_TYPE_GREATER_THAN);  /* XXX */

		assertion(c0->type_ == STT_CONDITION_TYPE_GREATER_THAN);
		assertion(c1->type_ == STT_CONDITION_TYPE_GREATER_THAN);
	}

	equality_ = stt_expression_equality(
			c0->left_hand_side_expression_,
			c1->left_hand_side_expression_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	equality_ = stt_expression_equality(
			c0->right_hand_side_expression_,
			c1->right_hand_side_expression_);
	if (equality_ == AMARA_BOOLEAN_FALSE) {
		returning_ = AMARA_BOOLEAN_FALSE;
	} else {
		assertion(equality_ == AMARA_BOOLEAN_TRUE);

		returning_ = AMARA_BOOLEAN_TRUE;
	}

	/*

	assertion(c0->left_hand_side_expression_->type_ ==
			STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(c1->left_hand_side_expression_->type_ ==
			STT_EXPRESSION_TYPE_NATURAL_LITERAL);

	assertion(c0->left_hand_side_expression_->sub_natural_literal_ !=
			NULL);
	assertion(c1->left_hand_side_expression_->sub_natural_literal_ !=
			NULL);

	assertion(c0->left_hand_side_expression_->sub_natural_literal_->raw_ !=
			NULL);
	assertion(c1->left_hand_side_expression_->sub_natural_literal_->raw_ !=
			NULL);

	assertion(c0->left_hand_side_expression_->sub_natural_literal_->raw_->value_ !=
			NULL);
	assertion(c1->left_hand_side_expression_->sub_natural_literal_->raw_->value_ !=
			NULL);

	equality_

	assertion(c0->right_hand_side_expression_->type_ ==
			STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(c1->right_hand_side_expression_->type_ ==
			STT_EXPRESSION_TYPE_NATURAL_LITERAL);

	*/

	return returning_;
}

amara_boolean
stt_conditions_equality(const stt_condition * c0, const stt_condition * c1)
{
	return stt_condition_equality(c0, c1);
}
