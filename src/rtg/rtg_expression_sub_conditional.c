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
 * src/rtg/rtg_expression_sub_conditional.c: Amara run time graph
 * conditional type of expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `rtg_expression_sub_conditional`. */
#include "rtg_expression_sub_conditional.h"

rtg_expression_sub_conditional_if *
rtg_expression_sub_conditional_if_copy_constructor(
		const rtg_expression_sub_conditional_if * expression_sub_conditional_if)
__attribute__((warn_unused_result))
;

rtg_expression_sub_conditional_if *
rtg_expression_sub_conditional_if_copy_constructor(
		const rtg_expression_sub_conditional_if * expression_sub_conditional_if)
{
	rtg_expression_sub_conditional_if * returning_;

#ifndef NDEBUG
	assertion(expression_sub_conditional_if != NULL);
	assertion(expression_sub_conditional_if->type_ !=
			RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
#endif

	returning_ = malloc(sizeof(rtg_expression_sub_conditional_if));
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

#ifndef NDEBUG
	assertion(expression_sub_conditional_if->condition_ != NULL);
#endif

	returning_->condition_ = rtg_condition_copy_constructor(
			expression_sub_conditional_if->condition_);
#ifndef NDEBUG
	assertion(returning_->condition_ != NULL);
#endif

#ifndef NDEBUG
	assertion(expression_sub_conditional_if->expression_then_ != NULL);
#endif

	returning_->expression_then_ = rtg_expression_copy_constructor(
			expression_sub_conditional_if->expression_then_);
#ifndef NDEBUG
	assertion(returning_->expression_then_ != NULL);
#endif

	forced_assertion(expression_sub_conditional_if->type_ ==
			RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);

	/*

	if (expression_sub_conditional_if->type_ ==
			RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE) {

	*/

#ifndef NDEBUG
		assertion(expression_sub_conditional_if->expression_else_ !=
				NULL);
#endif

		returning_->expression_else_ = rtg_expression_copy_constructor(
				expression_sub_conditional_if->expression_else_);
#ifndef NDEBUG
		assertion(returning_->expression_else_ != NULL);
#endif

#ifndef NDEBUG
		assertion(expression_sub_conditional_if->next_if_ == NULL);
#endif

		returning_->next_if_ = NULL;

		returning_->type_ =
				RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE;
	/*
	} else {
#ifndef NDEBUG
		assertion(expression_sub_conditional_if->type_ ==
				RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF);
#endif

#ifndef NDEBUG
		assertion(expression_sub_conditional_if->expression_else_ ==
				NULL);
#endif

		returning_->expression_else_ = NULL;

#ifndef NDEBUG
		assertion(expression_sub_conditional_if->next_if_ != NULL);
#endif

		returning_->next_if_ =
				rtg_expression_sub_conditional_if_copy_constructor(
						expression_sub_conditional_if->next_if_);
#ifndef NDEBUG
		assertion(returning_->next_if_ != NULL);
#endif

		returning_->type_ =
				RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF;
	}
	*/

	return returning_;
}

rtg_expression_sub_conditional *
rtg_expression_sub_conditional_copy_constructor(
		const rtg_expression_sub_conditional * expression_sub_conditional)
{
	rtg_expression_sub_conditional * returning_;

#ifndef NDEBUG
	assertion(expression_sub_conditional != NULL);
	assertion(expression_sub_conditional->if_ != NULL);
#endif

	returning_ = malloc(sizeof(rtg_expression_sub_conditional));
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	returning_->if_ = rtg_expression_sub_conditional_if_copy_constructor(
			expression_sub_conditional->if_);
#ifndef NDEBUG
	assertion(returning_->if_ != NULL);
#endif

	return returning_;
}

void
rtg_expression_sub_conditional_if_destructor(
		rtg_expression_sub_conditional_if * expression_sub_conditional_if)
;

void
rtg_expression_sub_conditional_if_destructor(
		rtg_expression_sub_conditional_if * expression_sub_conditional_if)
{
	assertion(expression_sub_conditional_if != NULL);
	assertion(expression_sub_conditional_if->condition_ != NULL);
	rtg_condition_destructor(expression_sub_conditional_if->condition_);
	assertion(expression_sub_conditional_if->expression_then_ != NULL);
	rtg_expression_destructor(
			expression_sub_conditional_if->expression_then_);

	forced_assertion(expression_sub_conditional_if->type_ ==
			RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);

	/*
	if (expression_sub_conditional_if->type_ ==
			RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE) {
	*/

		assertion(expression_sub_conditional_if->expression_else_ !=
				NULL);
		rtg_expression_destructor(
				expression_sub_conditional_if->expression_else_);
		assertion(expression_sub_conditional_if->next_if_ == NULL);
	/*
	} else {
		assertion(expression_sub_conditional_if->type_ ==
				RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF);

		assertion(expression_sub_conditional_if->expression_else_ ==
				NULL);
		assertion(expression_sub_conditional_if->next_if_ != NULL);
		rtg_expression_sub_conditional_if_destructor(
				expression_sub_conditional_if->next_if_);
	}
	*/

	free(expression_sub_conditional_if);
}

void
rtg_expression_sub_conditional_destructor(
		rtg_expression_sub_conditional * expression_sub_conditional)
{
	assertion(expression_sub_conditional != NULL);
	assertion(expression_sub_conditional->if_ != NULL);
	rtg_expression_sub_conditional_if_destructor(
			expression_sub_conditional->if_);
	free(expression_sub_conditional);
}

rtg_expression_sub_conditional_if *
rtg_expression_sub_conditional_if_out_of_stt_expression_sub_conditional_if(
		const stt_expression_sub_conditional_if * expression_sub_conditional_if)
__attribute__((warn_unused_result))
;

rtg_expression_sub_conditional_if *
rtg_expression_sub_conditional_if_out_of_stt_expression_sub_conditional_if(
		const stt_expression_sub_conditional_if * expression_sub_conditional_if)
{
	rtg_expression_out_of_stt_expression_ret * rtg_exp_ret_then_;
	rtg_expression_out_of_stt_expression_ret * rtg_exp_ret_else_;
	rtg_expression_sub_conditional_if * returning_;

#ifndef NDEBUG
	assertion(expression_sub_conditional_if != NULL);
	assertion(expression_sub_conditional_if->condition_ != NULL);
	assertion(expression_sub_conditional_if->expression_then_ != NULL);

	assertion(expression_sub_conditional_if->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);

	/*
	if (expression_sub_conditional_if->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE) {
	*/

		assertion(expression_sub_conditional_if->expression_else_ !=
				NULL);
		assertion(expression_sub_conditional_if->next_if_ == NULL);
	/*
	} else{
		assertion(expression_sub_conditional_if->type_ ==
				STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF);

		assertion(expression_sub_conditional_if->expression_else_ ==
				NULL);
		assertion(expression_sub_conditional_if->next_if_ != NULL);
	}
	*/
#endif

	returning_ = malloc(sizeof(rtg_expression_sub_conditional_if));

	returning_->condition_ = rtg_condition_out_of_stt_condition(
			expression_sub_conditional_if->condition_);


	rtg_exp_ret_then_ = rtg_expression_out_of_stt_expression(
			expression_sub_conditional_if->expression_then_);
#ifndef NDEBUG
	assertion(rtg_exp_ret_then_->status ==
			RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS);
	assertion(rtg_exp_ret_then_->expression != NULL);
#endif

	returning_->expression_then_ = rtg_exp_ret_then_->expression;
	rtg_exp_ret_then_->expression = NULL;
	rtg_expression_out_of_stt_expression_ret_destructor(rtg_exp_ret_then_);

	assertion(expression_sub_conditional_if->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);

	/*
	if (expression_sub_conditional_if->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE) {
	*/

		rtg_exp_ret_else_ = rtg_expression_out_of_stt_expression(
				expression_sub_conditional_if->expression_else_);
#ifndef NDEBUG
		assertion(rtg_exp_ret_else_->status ==
				RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS);
		assertion(rtg_exp_ret_else_->expression != NULL);
#endif

		returning_->expression_else_ = rtg_exp_ret_else_->expression;
		rtg_exp_ret_else_->expression = NULL;
		rtg_expression_out_of_stt_expression_ret_destructor(
				rtg_exp_ret_else_);

		returning_->next_if_ = NULL;

		returning_->type_ =
				RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE;
	/*
	} else {
#ifndef NDEBUG
		assertion(expression_sub_conditional_if->type_ ==
				STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF);
#endif

		returning_->expression_else_ = NULL;

		returning_->next_if_ =
				rtg_expression_sub_conditional_if_out_of_stt_expression_sub_conditional_if(
						expression_sub_conditional_if->next_if_);

		returning_->type_ =
				RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF;
	}
	*/

	return returning_;
}

rtg_expression_sub_conditional *
rtg_expression_sub_conditional_out_of_stt_expression_sub_conditional(
		const stt_expression_sub_conditional * expression_sub_conditional)
{
	rtg_expression_sub_conditional * returning_;

#ifndef NDEBUG
	assertion(expression_sub_conditional != NULL);
	assertion(expression_sub_conditional->if_ != NULL);
	assertion(expression_sub_conditional->if_->type_ !=
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
	assertion(expression_sub_conditional->if_->condition_ != NULL);
	assertion(expression_sub_conditional->if_->expression_then_ != NULL);

	assertion(expression_sub_conditional->if_->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);

	/*
	if (expression_sub_conditional->if_->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE) {
	*/

		assertion(expression_sub_conditional->if_->expression_else_ !=
				NULL);
		assertion(expression_sub_conditional->if_->next_if_ == NULL);
	/*
	} else {
		assertion(expression_sub_conditional->if_->type_ ==
				STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF);

		assertion(expression_sub_conditional->if_->expression_else_ ==
				NULL);
		assertion(expression_sub_conditional->if_->next_if_ != NULL);
	}
	*/
#endif

	returning_ = malloc(sizeof(rtg_expression_sub_conditional));
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	returning_->if_ =
			rtg_expression_sub_conditional_if_out_of_stt_expression_sub_conditional_if(
					expression_sub_conditional->if_);
#ifndef NDEBUG
	assertion(returning_->if_ != NULL);
#endif

	return returning_;
}

#ifndef NDEBUG

void
rtg_expression_sub_conditional_if_assert_validity(
		const rtg_expression_sub_conditional_if * expression_sub_conditional_if)
{
	assertion(expression_sub_conditional_if != NULL);
	assertion(expression_sub_conditional_if->type_ !=
			RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);

	assertion(expression_sub_conditional_if->condition_ != NULL);
	rtg_condition_assert_validity(
			expression_sub_conditional_if->condition_);

	assertion(expression_sub_conditional_if->expression_then_ != NULL);
	rtg_expression_assert_validity(
			expression_sub_conditional_if->expression_then_);

	assertion(expression_sub_conditional_if->type_ ==
			RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);

	/*
	if (expression_sub_conditional_if->type_ ==
			RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE) {
	*/

		assertion(expression_sub_conditional_if->expression_else_ !=
				NULL);
		rtg_expression_assert_validity(
				expression_sub_conditional_if->expression_else_);

		assertion(expression_sub_conditional_if->next_if_ == NULL);
	/*
	} else {
		assertion(expression_sub_conditional_if->type_ ==
				RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF);

		assertion(expression_sub_conditional_if->expression_else_ ==
				NULL);

		assertion(expression_sub_conditional_if->next_if_ != NULL);

		rtg_expression_sub_conditional_if_assert_validity(
				expression_sub_conditional_if->next_if_);
	}
	*/
}

void
rtg_expression_sub_conditional_assert_validity(
		const rtg_expression_sub_conditional * expression_sub_conditional)
{
	assertion(expression_sub_conditional != NULL);
	assertion(expression_sub_conditional->if_ != NULL);
	rtg_expression_sub_conditional_if_assert_validity(
			expression_sub_conditional->if_);
}

#endif
