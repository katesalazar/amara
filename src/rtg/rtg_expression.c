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
 * src/rtg/rtg_expression.c: Amara run time graph expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

/*   For `stt_expression`. */
#include "../stt/stt_expression.h"

/*   For `rtg_expression`. */
#include "rtg_expression.h"

#ifndef NDEBUG

void
rtg_expression_assert_cleanly_string_literal(const rtg_expression * expression)
;

void
rtg_expression_assert_cleanly_string_literal(const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_STRING_LITERAL);
	assertion(expression->sub_string_literal_ != NULL);
	assertion(expression->sub_string_literal_->string_literal_ != NULL);
	assertion(expression->sub_string_literal_->string_literal_->value_ !=
			NULL);
	assertion(expression->sub_natural_literal_ == NULL);
	assertion(expression->sub_identifier_ == NULL);
	assertion(expression->sub_conditional_ == NULL);
	assertion(expression->sub_dice_ == NULL);
}

void
rtg_expression_assert_cleanly_natural_literal(
		const rtg_expression * expression)
;


void
rtg_expression_assert_cleanly_natural_literal(
		const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(expression->sub_string_literal_ == NULL);
	assertion(expression->sub_natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(expression->sub_identifier_ == NULL);
	assertion(expression->sub_conditional_ == NULL);
	assertion(expression->sub_dice_ == NULL);
}

void
rtg_expression_assert_cleanly_identifier(const rtg_expression * expression)
;

void
rtg_expression_assert_cleanly_identifier(const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_IDENTIFIER);
	assertion(expression->sub_string_literal_ == NULL);
	assertion(expression->sub_natural_literal_ == NULL);
	assertion(expression->sub_identifier_ != NULL);
	assertion(expression->sub_identifier_->identifier_ != NULL);
	assertion(expression->sub_identifier_->identifier_->value_ != NULL);
	assertion(expression->sub_conditional_ == NULL);
	assertion(expression->sub_dice_ == NULL);
}

void
rtg_expression_assert_cleanly_conditional(const rtg_expression * expression)
;

void
rtg_expression_assert_cleanly_conditional(const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_CONDITIONAL);
	assertion(expression->sub_string_literal_ == NULL);
	assertion(expression->sub_natural_literal_ == NULL);
	/*
	assertion(expression->sub_integer_literal_ == NULL);
	assertion(expression->sub_rational_literal_ == NULL);
	assertion(expression->sub_identifier_literal_ == NULL);
	*/
	assertion(expression->sub_conditional_ != NULL);
	rtg_expression_sub_conditional_assert_validity(
			expression->sub_conditional_);
	assertion(expression->sub_dice_ == NULL);
}

void
rtg_expression_assert_cleanly_dice(const rtg_expression * expression)
;

void
rtg_expression_assert_cleanly_dice(const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_DICE);
	assertion(expression->sub_string_literal_ == NULL);
	assertion(expression->sub_natural_literal_ == NULL);
	/*
	assertion(expression->sub_integer_literal_ == NULL);
	assertion(expression->sub_rational_literal_ == NULL);
	assertion(expression->sub_identifier_literal_ == NULL);
	*/
	assertion(expression->sub_conditional_ == NULL);
	assertion(expression->sub_dice_ != NULL);
	rtg_expression_sub_dice_assert_validity(
			expression->sub_dice_);
}

#endif

rtg_expression *
rtg_expression_default_constructor()
{
	rtg_expression * returning_;

	returning_ = malloc(sizeof(rtg_expression));
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	returning_->type_ = RTG_EXPRESSION_TYPE_INVALID;
	returning_->sub_string_literal_ = NULL;
	returning_->sub_natural_literal_ = NULL;
	returning_->sub_identifier_ = NULL;
	returning_->sub_conditional_ = NULL;
	returning_->sub_function_call_ = NULL;
	returning_->sub_dice_ = NULL;

	return returning_;
}

rtg_expression *
rtg_expression_copy_constructor(const rtg_expression * expression)
{
	rtg_expression * returning_;

#ifndef NDEBUG
	assertion(expression != NULL);
	assertion(expression->type_ != RTG_EXPRESSION_TYPE_INVALID);
	rtg_expression_assert_validity(expression);
#endif

	returning_ = rtg_expression_default_constructor();
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	if (expression->type_ == RTG_EXPRESSION_TYPE_STRING_LITERAL) {

#ifndef NDEBUG
		assertion(expression->sub_string_literal_ != NULL);
		assertion(expression->sub_string_literal_->string_literal_ !=
				NULL);
		assertion(expression->sub_string_literal_->string_literal_->value_ !=
				NULL);
		rtg_expression_assert_cleanly_string_literal(expression);
#endif

		returning_->sub_string_literal_ =
				rtg_expression_sub_string_literal_copy_constructor(
						expression->sub_string_literal_);
#ifndef NDEBUG
		assertion(returning_->sub_string_literal_ != NULL);
#endif
	} else if (expression->type_ == RTG_EXPRESSION_TYPE_NATURAL_LITERAL) {

#ifndef NDEBUG
		assertion(expression->sub_natural_literal_ != NULL);
		assertion(expression->sub_natural_literal_->natural_literal_ !=
				NULL);
		assertion(expression->sub_natural_literal_->natural_literal_->raw_ !=
				NULL);
		assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_ !=
				NULL);
		rtg_expression_assert_cleanly_natural_literal(expression);
#endif

		returning_->sub_natural_literal_ =
				rtg_expression_sub_natural_literal_copy_constructor(
						expression->sub_natural_literal_);
#ifndef NDEBUG
		assertion(returning_->sub_natural_literal_ != NULL);
#endif
	} else if (expression->type_ == RTG_EXPRESSION_TYPE_IDENTIFIER) {

#ifndef NDEBUG
		assertion(expression->sub_identifier_ != NULL);
		assertion(expression->sub_identifier_->identifier_ != NULL);
		assertion(expression->sub_identifier_->identifier_->value_ !=
				NULL);
		rtg_expression_assert_cleanly_identifier(expression);
#endif

		returning_->sub_identifier_ =
				rtg_expression_sub_identifier_copy_constructor(
						expression->sub_identifier_);
		forced_assertion(returning_->sub_identifier_ != NULL);

	} else if (expression->type_ == RTG_EXPRESSION_TYPE_DICE) {

#ifndef NDEBUG
		assertion(expression->sub_dice_ != NULL);
		assertion(expression->sub_dice_->left_hand_side_natural_ !=
				NULL);
		assertion(expression->sub_dice_->left_hand_side_natural_->raw_ !=
				NULL);
		assertion(expression->sub_dice_->left_hand_side_natural_->raw_->value_ !=
				NULL);
		assertion(expression->sub_dice_->right_hand_side_natural_ !=
				NULL);
		assertion(expression->sub_dice_->right_hand_side_natural_->raw_ !=
				NULL);
		assertion(expression->sub_dice_->right_hand_side_natural_->raw_->value_ !=
				NULL);
		rtg_expression_assert_cleanly_dice(expression);
#endif

		returning_->sub_dice_ =
				rtg_expression_sub_dice_copy_constructor(
						expression->sub_dice_);
		forced_assertion(returning_->sub_dice_ != NULL);

	} else {
		forced_assertion(expression->type_ ==
				RTG_EXPRESSION_TYPE_CONDITIONAL);

#ifndef NDEBUG
		assertion(expression->sub_conditional_ != NULL);
		rtg_expression_assert_cleanly_conditional(expression);
		rtg_expression_sub_conditional_assert_validity(
				expression->sub_conditional_);
#endif

		returning_->sub_conditional_ =
				rtg_expression_sub_conditional_copy_constructor(
						expression->sub_conditional_);
	}

	returning_->type_ = expression->type_;

	return returning_;
}

void
rtg_expression_destructor(rtg_expression * expression)
{
#ifndef NDEBUG
	assertion(expression != NULL);
	assertion(expression->type_ != RTG_EXPRESSION_TYPE_INVALID);
#endif

	if (expression->type_ == RTG_EXPRESSION_TYPE_STRING_LITERAL) {

#ifndef NDEBUG
		assertion(expression->sub_string_literal_ != NULL);
		assertion(expression->sub_string_literal_->string_literal_ !=
				NULL);
		assertion(expression->sub_string_literal_->string_literal_->value_ !=
				NULL);
#endif

		rtg_expression_sub_string_literal_destructor(
				expression->sub_string_literal_);
	} else if (expression->type_ == RTG_EXPRESSION_TYPE_NATURAL_LITERAL) {

#ifndef NDEBUG
		assertion(expression->sub_natural_literal_ != NULL);
		assertion(expression->sub_natural_literal_->natural_literal_ !=
				NULL);
		assertion(expression->sub_natural_literal_->natural_literal_->raw_ !=
				NULL);
		assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_ !=
				NULL);
#endif

		rtg_expression_sub_natural_literal_destructor(
				expression->sub_natural_literal_);
	} else if (expression->type_ == RTG_EXPRESSION_TYPE_IDENTIFIER) {

#ifndef NDEBUG
		assertion(expression->sub_identifier_ != NULL);
		assertion(expression->sub_identifier_->identifier_ != NULL);
		assertion(expression->sub_identifier_->identifier_->value_ !=
				NULL);
#endif

		rtg_expression_sub_identifier_destructor(
				expression->sub_identifier_);
	} else if (expression->type_ == RTG_EXPRESSION_TYPE_CONDITIONAL) {

#ifndef NDEBUG
		assertion(expression->sub_conditional_ != NULL);
		assertion(expression->sub_conditional_->if_ != NULL);
#endif

		rtg_expression_sub_conditional_destructor(
				expression->sub_conditional_);
	} else {
		forced_assertion(expression->type_ ==
				RTG_EXPRESSION_TYPE_DICE);

#ifndef NDEBUG
		assertion(expression->sub_dice_ != NULL);
		assertion(expression->sub_dice_->left_hand_side_natural_ !=
				NULL);
		natural_assert_validity(
				expression->sub_dice_->left_hand_side_natural_);
		assertion(expression->sub_dice_->right_hand_side_natural_ !=
				NULL);
		natural_assert_validity(
				expression->sub_dice_->right_hand_side_natural_);
#endif

		rtg_expression_sub_dice_destructor(expression->sub_dice_);
	}

	free(expression);
}

void
rtg_expression_set_identifier(
		rtg_expression * expression, const amara_string * identifier)
{
#ifndef NDEBUG
	located_assertion(expression != NULL);
	located_assertion(expression->type_ == RTG_EXPRESSION_TYPE_INVALID);
	located_assertion(expression->sub_identifier_ == NULL);
	located_assertion(identifier != NULL);
	located_assertion(identifier->value_ != NULL);
#endif

	expression->sub_identifier_ =
			rtg_expression_sub_identifier_exhaustive_constructor(
					identifier);
	forced_assertion(expression->sub_identifier_ != NULL);

	expression->type_ = RTG_EXPRESSION_TYPE_IDENTIFIER;
}

#ifndef NDEBUG

void
rtg_expression_assert_healthy(const rtg_expression * expression)
{
	forced_assertion(expression != NULL);

	forced_assertion(expression->type_ != RTG_EXPRESSION_TYPE_INVALID);

	/*
	if (expression->type_ == RTG_EXPRESSION_TYPE_INVALID) {

		assertion(expression->sub_natural_literal_ == NULL);
	*/
		/* FIXME */
	/*
	} else {
	*/
		assertion(expression->type_ == /* XXX */
				RTG_EXPRESSION_TYPE_NATURAL_LITERAL); /* XXX */

		rtg_expression_sub_natural_literal_assert_healthy(
				expression->sub_natural_literal_);
	/*
	}
	*/
}

#endif

amara_boolean
rtg_expression_equality(const rtg_expression * e0, const rtg_expression * e1)
{
#ifndef NDEBUG
	assertion(e0 != NULL);
	assertion(e0->type_ != RTG_EXPRESSION_TYPE_INVALID);
	assertion(e1 != NULL);
	assertion(e1->type_ != RTG_EXPRESSION_TYPE_INVALID);
#endif

	assertion(e0->type_ == e1->type_); /* FIXME */
	return AMARA_BOOLEAN_TRUE; /* FIXME */
}

void
rtg_expression_out_of_stt_expression_ret_destructor(
		rtg_expression_out_of_stt_expression_ret * input_ret_)
{
	forced_assertion(input_ret_ != NULL);

	forced_assertion(input_ret_->status ==
			RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS);

	forced_assertion(input_ret_->expression == NULL);

	/*
	if (input_ret_->expression != NULL) {

		rtg_expression_destructor(input_ret_->expression);
	}
	*/

	free(input_ret_);
}

rtg_expression_out_of_stt_expression_ret *
rtg_expression_out_of_stt_expression(
		const stt_expression * expression,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
	rtg_expression_out_of_stt_expression_ret * returning_;
	rtg_expression * returning_sub_;
	rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret * function_call_ret_;

#ifndef NDEBUG
	located_assertion_one(expression != NULL);
	located_assertion_one(
			expression->type_ != STT_EXPRESSION_TYPE_INVALID);
#endif

	if (expression->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL) {

		assertion(expression->sub_string_literal_ != NULL);
	} else if (expression->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL) {

		assertion(expression->sub_natural_literal_ != NULL);
	} else if (expression->type_ == STT_EXPRESSION_TYPE_IDENTIFIER) {

		assertion(expression->sub_identifier_ != NULL);
	} else if (expression->type_ == STT_EXPRESSION_TYPE_CONDITIONAL) {

#ifndef NDEBUG
		stt_expression_assert_clean_conditional(expression);
#endif

		assertion(expression->sub_conditional_ != NULL);
		assertion(expression->sub_conditional_->if_->condition_ !=
				NULL);
		assertion(expression->sub_conditional_->if_->expression_then_ !=
				NULL);

		assertion(expression->sub_conditional_->if_->type_ ==  /* XXX */
				STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);  /* XXX */

		/*
		if (expression->sub_conditional_->if_->type_ ==
				STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE) {
		*/

			assertion(expression->sub_conditional_->if_->expression_else_ !=
					NULL);
			assertion(expression->sub_conditional_->if_->next_if_ ==
					NULL);
		/*
		} else {
			assertion(expression->sub_conditional_->if_->type_ ==
					STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF);

			assertion(expression->sub_conditional_->if_->expression_else_ ==
					NULL);
			assertion(expression->sub_conditional_->if_->next_if_ !=
					NULL);
		}
		*/
	} else if (expression->type_ == STT_EXPRESSION_TYPE_FUNCTION_CALL) {

#ifndef NDEBUG
		stt_expression_assert_clean_function_call(expression);
#endif

		assertion(expression->sub_function_call_ != NULL);
		assertion(expression->sub_function_call_->builtin_function_ !=
				NULL);
		assertion(expression->sub_function_call_->function_name_ !=
				NULL);
		assertion(expression->sub_function_call_->call_arguments_ !=
				NULL);
	} else {
		located_forced_unsigned_char_equality_assertion_two(
				expression->type_, STT_EXPRESSION_TYPE_DICE);

#ifndef NDEBUG
		stt_expression_assert_clean_dice(expression);
#endif

		assertion(expression->sub_dice_ != NULL);
		assertion(expression->sub_dice_->left_hand_side_natural_ !=
				NULL);
		assertion(expression->sub_dice_->right_hand_side_natural_ !=
				NULL);
	}

	returning_sub_ = rtg_expression_default_constructor();
#ifndef NDEBUG
	assertion(returning_sub_ != NULL);
	assertion(returning_sub_->type_ == RTG_EXPRESSION_TYPE_INVALID);
#endif

	if (expression->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL) {

		returning_sub_->sub_string_literal_ =
				rtg_expression_sub_string_literal_out_of_stt_expression_sub_string_literal(
						expression->sub_string_literal_);
#ifndef NDEBUG
		assertion(returning_sub_->sub_string_literal_ != NULL);
#endif

		returning_sub_->type_ = RTG_EXPRESSION_TYPE_STRING_LITERAL;
	} else if (expression->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL) {

		returning_sub_->sub_natural_literal_ =
				rtg_expression_sub_natural_literal_out_of_stt_expression_sub_natural_literal(
						expression->sub_natural_literal_);
#ifndef NDEBUG
		assertion(returning_sub_->sub_natural_literal_ != NULL);
#endif

		returning_sub_->type_ = RTG_EXPRESSION_TYPE_NATURAL_LITERAL;
	} else if (expression->type_ == STT_EXPRESSION_TYPE_IDENTIFIER) {

		returning_sub_->sub_identifier_ =
				rtg_expression_sub_identifier_out_of_stt_expression_sub_identifier(
						expression->sub_identifier_);
#ifndef NDEBUG
		assertion(returning_sub_->sub_identifier_ != NULL);
#endif

		returning_sub_->type_ = RTG_EXPRESSION_TYPE_IDENTIFIER;
	} else if (expression->type_ ==
				STT_EXPRESSION_TYPE_CONDITIONAL) {

		returning_sub_->sub_conditional_ =
				rtg_expression_sub_conditional_out_of_stt_expression_sub_conditional(
						expression->sub_conditional_,
						NULL);
#ifndef NDEBUG
		assertion(returning_sub_->sub_conditional_ != NULL);
#endif

		returning_sub_->type_ = RTG_EXPRESSION_TYPE_CONDITIONAL;
	} else if (expression->type_ == STT_EXPRESSION_TYPE_FUNCTION_CALL) {

		function_call_ret_ =
				rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call(
						expression->sub_function_call_,
						rtg_named_functions);
		located_forced_assertion(function_call_ret_ != NULL);
		located_forced_assertion(function_call_ret_->status ==
				RTG_EXPRESSION_SUB_FUNCTION_CALL_OUT_OF_STT_EXPRESSION_SUB_FUNCTION_CALL_RET_STATUS_SUCCESS);
		located_forced_assertion(function_call_ret_->ret != NULL);
		returning_sub_->sub_function_call_ = function_call_ret_->ret;

		returning_sub_->type_ = RTG_EXPRESSION_TYPE_FUNCTION_CALL;
	} else {
		located_assertion(
				expression->type_ == STT_EXPRESSION_TYPE_DICE);

		returning_sub_->sub_dice_ =
				rtg_expression_sub_dice_out_of_stt_expression_sub_dice(
						expression->sub_dice_);
#ifndef NDEBUG
		assertion(returning_sub_->sub_dice_ != NULL);
#endif

		returning_sub_->type_ = RTG_EXPRESSION_TYPE_DICE;
	}

	returning_ = malloc(sizeof(rtg_expression_out_of_stt_expression_ret));
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	returning_->expression = returning_sub_;
	returning_->status =
			RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS;

	return returning_;
}

#ifndef NDEBUG

void
rtg_expression_assert_validity(const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ != RTG_EXPRESSION_TYPE_INVALID);

	if (expression->type_ == RTG_EXPRESSION_TYPE_STRING_LITERAL) {

		assertion(expression->sub_string_literal_ != NULL);
		rtg_expression_assert_cleanly_string_literal(expression);
	} else if (expression->type_ == RTG_EXPRESSION_TYPE_NATURAL_LITERAL) {

		assertion(expression->sub_natural_literal_ != NULL);
		rtg_expression_assert_cleanly_natural_literal(expression);
	} else if (expression->type_ == RTG_EXPRESSION_TYPE_IDENTIFIER) {

		assertion(expression->sub_identifier_ != NULL);
		rtg_expression_sub_identifier_assert_validity(
				expression->sub_identifier_);
	} else if (expression->type_ == RTG_EXPRESSION_TYPE_CONDITIONAL) {

		assertion(expression->sub_conditional_ != NULL);
		rtg_expression_sub_conditional_assert_validity(
				expression->sub_conditional_);
	} else {
		assertion(expression->type_ == RTG_EXPRESSION_TYPE_DICE);

		assertion(expression->sub_dice_ != NULL);
		rtg_expression_sub_dice_assert_validity(
				expression->sub_dice_);
	}
}

#endif
