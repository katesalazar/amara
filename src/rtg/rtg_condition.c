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
 * src/rtg/rtg_condition.h: Amara run time graph condition.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

/*   For `rtg_condition`. */
#include "rtg_condition.h"

/*
rtg_condition_type
rtg_condition_type_ill()
{
	rtg_condition_type returning_;

	returning_ = 0xFF;

#ifndef NDEBUG
	assertion(returning_ != RTG_CONDITION_TYPE_INVALID);
	assertion(returning_ != RTG_CONDITION_TYPE_LESS_THAN);
	assertion(rtg_condition_type_is_ill(returning_) == AMARA_BOOLEAN_TRUE);
#endif

	return returning_;
}
*/

amara_boolean
rtg_condition_type_is_valid(rtg_condition_type condition_type)
{
	if (condition_type == RTG_CONDITION_TYPE_LESS_THAN) {

		return AMARA_BOOLEAN_TRUE;
	}

	forced_assertion(condition_type == RTG_CONDITION_TYPE_GREATER_THAN);  /* XXX */

	return AMARA_BOOLEAN_TRUE;
}

/*
amara_boolean
rtg_condition_type_is_known(rtg_condition_type condition_type)
{
	if (rtg_condition_type_is_valid(condition_type) ==
			AMARA_BOOLEAN_TRUE) {

		return AMARA_BOOLEAN_TRUE;
	}

	if (condition_type == RTG_CONDITION_TYPE_INVALID) {

		return AMARA_BOOLEAN_TRUE;
	}

	return AMARA_BOOLEAN_FALSE;
}

amara_boolean
rtg_condition_type_is_ill(rtg_condition_type condition_type)
{
	amara_boolean known_;

	known_ = rtg_condition_type_is_known(condition_type);

	if (known_ == AMARA_BOOLEAN_FALSE) {

		return AMARA_BOOLEAN_TRUE;
	} else {
#ifndef NDEBUG
		assertion(known_ == AMARA_BOOLEAN_TRUE);
#endif

		return AMARA_BOOLEAN_FALSE;
	}
}
*/

rtg_condition *
rtg_condition_default_constructor()
{
	rtg_condition * returning_;

	returning_ = malloc(sizeof(rtg_condition));
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	returning_->type_ = RTG_CONDITION_TYPE_INVALID;
	returning_->left_hand_side_expression_ = NULL;
	returning_->right_hand_side_expression_ = NULL;

	return returning_;
}

rtg_condition *
rtg_condition_copy_constructor(const rtg_condition * condition)
{
	rtg_condition * returning_;

#ifndef NDEBUG
	assertion(condition != NULL);
	assertion(condition->type_ != RTG_CONDITION_TYPE_INVALID);
#endif

	if (condition->type_ != RTG_CONDITION_TYPE_LESS_THAN) {
		assertion(condition->type_ == RTG_CONDITION_TYPE_GREATER_THAN);
	}

#ifndef NDEBUG
	assertion(condition->left_hand_side_expression_ != NULL);
#endif

	returning_ = malloc(sizeof(rtg_condition));
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	returning_->left_hand_side_expression_ =
			rtg_expression_copy_constructor(
					condition->left_hand_side_expression_);
#ifndef NDEBUG
	assertion(returning_->left_hand_side_expression_ != NULL);
#endif

#ifndef NDEBUG
	assertion(condition->right_hand_side_expression_ != NULL);
#endif

	returning_->right_hand_side_expression_ =
			rtg_expression_copy_constructor(
					condition->right_hand_side_expression_);
#ifndef NDEBUG
	assertion(returning_->right_hand_side_expression_ != NULL);
#endif

	returning_->type_ = condition->type_;

	return returning_;
}

void
rtg_condition_destructor(rtg_condition * condition)
{
#ifndef NDEBUG
	assertion(condition != NULL);
	assertion(condition->type_ != RTG_CONDITION_TYPE_INVALID);
#endif
	/*
	forced_assertion(rtg_condition_type_is_known(condition->type_));
	*/

	/*
	if (rtg_condition_type_is_known(condition->type_)) {
	*/

	if (condition->type_ == RTG_CONDITION_TYPE_LESS_THAN) {

#ifndef NDEBUG
		assertion(condition->type_ == RTG_CONDITION_TYPE_LESS_THAN);
#endif
	} else {
		forced_assertion(condition->type_ ==
				RTG_CONDITION_TYPE_GREATER_THAN);
	}

#ifndef NDEBUG
		assertion(condition->left_hand_side_expression_ != NULL);
#endif

		rtg_expression_destructor(
				condition->left_hand_side_expression_);

#ifndef NDEBUG
		assertion(condition->right_hand_side_expression_ != NULL);
#endif

		rtg_expression_destructor(
				condition->right_hand_side_expression_);
	/*
	} else {
#ifndef NDEBUG
		assertion(rtg_condition_type_is_ill(condition->type_) ==
				AMARA_BOOLEAN_TRUE);
#endif

		if (condition->left_hand_side_expression_ != NULL) {

			rtg_expression_destructor(
					condition->left_hand_side_expression_);
		}

		if (condition->right_hand_side_expression_ != NULL) {

			rtg_expression_destructor(
					condition->right_hand_side_expression_);
		}
	}
	*/

	free(condition);
}

rtg_condition *
rtg_condition_flip(const rtg_condition * condition)
{
	rtg_condition * returning_;

#ifndef NDEBUG
	assertion(condition != NULL);
	assertion(condition->type_ != RTG_CONDITION_TYPE_INVALID);
	assertion(condition->left_hand_side_expression_ != NULL);
	assertion(condition->left_hand_side_expression_->type_ !=
			RTG_EXPRESSION_TYPE_INVALID);
	assertion(condition->right_hand_side_expression_ != NULL);
	assertion(condition->right_hand_side_expression_->type_ !=
			RTG_EXPRESSION_TYPE_INVALID);
#endif

	/*
	if (condition->type_ == RTG_CONDITION_TYPE_GREATER_THAN_OR_EQUAL_TO) {

		;
	} else {
#ifndef NDEBUG
		assertion(condition->type_ ==
				RTG_CONDITION_TYPE_LESS_THAN_OR_EQUAL_TO);
#endif

		;
	}
	*/

	returning_ = rtg_condition_default_constructor();

	returning_->left_hand_side_expression_ =
			rtg_expression_copy_constructor(
					condition->right_hand_side_expression_);
#ifndef NDEBUG
	assertion(returning_->left_hand_side_expression_ != NULL);
#endif

	returning_->right_hand_side_expression_ =
			rtg_expression_copy_constructor(
					condition->left_hand_side_expression_);
#ifndef NDEBUG
	assertion(returning_->right_hand_side_expression_ != NULL);
#endif

	assertion(condition->type_ == RTG_CONDITION_TYPE_LESS_THAN);

	returning_->type_ = RTG_CONDITION_TYPE_GREATER_THAN;

	/*
	if (condition->type_ == RTG_CONDITION_TYPE_LESS_THAN) {

		returning_->type_ = RTG_CONDITION_TYPE_GREATER_THAN;
	} else {
#ifndef NDEBUG
		assertion(condition->type_ ==
				RTG_CONDITION_TYPE_GREATER_THAN);
#endif

		returning_->type_ = RTG_CONDITION_TYPE_LESS_THAN;
	}
	*/

	return returning_;
}

rtg_condition *
rtg_condition_out_of_stt_condition(const stt_condition * condition)
{
	rtg_expression_out_of_stt_expression_ret * left_hand_side_exp_ret_;
	rtg_expression_out_of_stt_expression_ret * right_hand_side_exp_ret_;
	rtg_condition * returning_;

#ifndef NDEBUG
	assertion(condition != NULL);
	assertion(condition->type_ != STT_CONDITION_TYPE_INVALID);
#endif

	returning_ = rtg_condition_default_constructor();
#ifndef NDEBUG
	assertion(returning_ != NULL);
	assertion(returning_->type_ == RTG_CONDITION_TYPE_INVALID);
#endif

#ifndef NDEBUG
	if (condition->type_ != STT_CONDITION_TYPE_LESS_THAN) {
		assertion(condition->type_ == STT_CONDITION_TYPE_GREATER_THAN);
	}
#endif

	left_hand_side_exp_ret_ =
			rtg_expression_out_of_stt_expression(
					condition->left_hand_side_expression_);
#ifndef NDEBUG
	assertion(left_hand_side_exp_ret_->status ==
			RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS);
	assertion(left_hand_side_exp_ret_->expression != NULL);
#endif

	returning_->left_hand_side_expression_ =
			left_hand_side_exp_ret_->expression;
	left_hand_side_exp_ret_->expression = NULL;
	rtg_expression_out_of_stt_expression_ret_destructor(
			left_hand_side_exp_ret_);

	right_hand_side_exp_ret_ =
			rtg_expression_out_of_stt_expression(
					condition->right_hand_side_expression_);
#ifndef NDEBUG
	assertion(right_hand_side_exp_ret_->status ==
			RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS);
	assertion(right_hand_side_exp_ret_->expression != NULL);
#endif

	returning_->right_hand_side_expression_ =
			right_hand_side_exp_ret_->expression;
	right_hand_side_exp_ret_->expression = NULL;
	rtg_expression_out_of_stt_expression_ret_destructor(
			right_hand_side_exp_ret_);

	if (condition->type_ == STT_CONDITION_TYPE_LESS_THAN) {

		returning_->type_ = RTG_CONDITION_TYPE_LESS_THAN;
	} else {
#ifndef NDEBUG
		assertion(condition->type_ == STT_CONDITION_TYPE_GREATER_THAN);
#endif

		returning_->type_ = RTG_CONDITION_TYPE_GREATER_THAN;
	}

	return returning_;
}

#ifndef NDEBUG

void
rtg_condition_assert_validity(const rtg_condition * condition)
{
	assertion(condition != NULL);
	assertion(condition->type_ != RTG_CONDITION_TYPE_INVALID);

	if (condition->type_ != RTG_CONDITION_TYPE_LESS_THAN) {
		assertion(condition->type_ == RTG_CONDITION_TYPE_GREATER_THAN);
	}

	assertion(condition->left_hand_side_expression_ != NULL);
	rtg_expression_assert_validity(condition->left_hand_side_expression_);

	assertion(condition->right_hand_side_expression_ != NULL);
	rtg_expression_assert_validity(condition->right_hand_side_expression_);
}

#endif
