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
 * src/stt/stt_expression.c: Amara syntax tree expression.
 */

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `NULL`. */
/* #include <stdlib.h> */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

/*   For `void assert_valid_raw_natural(const amara_string *
 * raw_natural)`. */
#include "../brt/natural.h"

/*   For `stt_expression_sub_natural_literal_exhaustive_constructor`. */
#include "stt_expression_sub_natural_literal.h"

/*   For own definitions. */
#include "stt_expression.h"

stt_expression *
stt_expression_default_constructor(void)
{
	stt_expression * returning_;

	returning_ = malloc(sizeof(stt_expression));

	returning_->sub_string_literal_ = NULL;
	returning_->sub_natural_literal_ = NULL;
	returning_->sub_identifier_ = NULL;
	returning_->sub_conditional_ = NULL;
	returning_->sub_function_call_ = NULL;
	returning_->sub_dice_ = NULL;
	returning_->type_ = STT_EXPRESSION_TYPE_INVALID;

	return returning_;
}

stt_expression *
stt_expression_copy_constructor(const stt_expression * expression)
{
	stt_expression * returning_;

#ifndef NDEBUG
	assertion(expression != NULL);
	assertion(expression->type_ != STT_EXPRESSION_TYPE_INVALID);
#endif

	returning_ = stt_expression_default_constructor();
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	if (expression->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL) {
#ifndef NDEBUG
		assertion(expression->sub_string_literal_ != NULL);
#endif

		returning_->sub_string_literal_ =
				stt_expression_sub_string_literal_copy_constructor(
						expression->sub_string_literal_);
#ifndef NDEBUG
		assertion(returning_->sub_string_literal_ != NULL);
#endif

#ifndef NDEBUG
		assertion(expression->sub_natural_literal_ == NULL);
		/* XXX missing assertions? */
		assertion(expression->sub_conditional_ == NULL);
		assertion(expression->sub_dice_ == NULL);
#endif
	} else if (expression->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL) {

#ifndef NDEBUG
		assertion(expression->sub_string_literal_ == NULL);
		assertion(expression->sub_natural_literal_ != NULL);
		assertion(expression->sub_conditional_ == NULL);
#endif

		returning_->sub_natural_literal_ =
				stt_expression_sub_natural_literal_copy_constructor(
						expression->sub_natural_literal_);
#ifndef NDEBUG
		assertion(returning_->sub_natural_literal_ != NULL);
#endif

#ifndef NDEBUG
		/* XXX missing assertions? */
		assertion(expression->sub_conditional_ == NULL);
		assertion(expression->sub_dice_ == NULL);
#endif
	} else if (expression->type_ == STT_EXPRESSION_TYPE_IDENTIFIER) {

#ifndef NDEBUG
		assertion(expression->sub_string_literal_ == NULL);
		assertion(expression->sub_natural_literal_ == NULL);
		assertion(expression->sub_identifier_ != NULL);
		assertion(expression->sub_conditional_ == NULL);
		assertion(expression->sub_dice_ == NULL);
#endif

		returning_->sub_identifier_ =
				stt_expression_sub_identifier_copy_constructor(
						expression->sub_identifier_);
#ifndef NDEBUG
		assertion(returning_->sub_identifier_ != NULL);
#endif
	} else if (expression->type_ == STT_EXPRESSION_TYPE_CONDITIONAL) {

#ifndef NDEBUG
		assertion(expression->sub_string_literal_ == NULL);
		assertion(expression->sub_natural_literal_ == NULL);
		assertion(expression->sub_conditional_ != NULL);
#endif

		returning_->sub_conditional_ =
				stt_expression_sub_conditional_copy_constructor(
						expression->sub_conditional_);
#ifndef NDEBUG
		assertion(returning_->sub_conditional_ != NULL);
#endif

#ifndef NDEBUG
		/* XXX missing assertions? */
		assertion(expression->sub_dice_ == NULL);
#endif
	} else if (expression->type_ == STT_EXPRESSION_TYPE_FUNCTION_CALL) {

#ifndef NDEBUG
		assertion(expression->sub_string_literal_ == NULL);
		assertion(expression->sub_natural_literal_ == NULL);
		assertion(expression->sub_conditional_ == NULL);
		assertion(expression->sub_function_call_ != NULL);
#endif

		returning_->sub_function_call_ =
				stt_expression_sub_function_call_copy_constructor(
						expression->sub_function_call_);
#ifndef NDEBUG
		assertion(returning_->sub_function_call_ != NULL);
#endif
	} else {
#ifndef NDEBUG
		fprintf(stderr, "%u\n", expression->type_);
		assertion(expression->type_ == STT_EXPRESSION_TYPE_DICE);
#endif

#ifndef NDEBUG
		assertion(expression->sub_string_literal_ == NULL);
		assertion(expression->sub_natural_literal_ == NULL);
		assertion(expression->sub_conditional_ == NULL);
		assertion(expression->sub_dice_ != NULL);
#endif

		returning_->sub_dice_ =
				stt_expression_sub_dice_copy_constructor(
						expression->sub_dice_);
#ifndef NDEBUG
		assertion(returning_->sub_dice_ != NULL);
#endif

		/* XXX missing assertions? */
	}

	returning_->type_ = expression->type_;

	return returning_;
}

void
stt_expression_destructor(stt_expression * expression)
{
#ifndef NDEBUG
	assertion(expression != NULL);
	assertion(expression->type_ != STT_EXPRESSION_TYPE_INVALID);
#endif

	if (expression->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL) {

#ifndef NDEBUG
		assertion(expression->sub_string_literal_ != NULL);
#endif
		stt_expression_sub_string_literal_destructor(
				expression->sub_string_literal_);
	} else if (expression->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL) {

#ifndef NDEBUG
		assertion(expression->sub_natural_literal_ != NULL);
#endif
		stt_expression_sub_natural_literal_destructor(
				expression->sub_natural_literal_);
	} else if (expression->type_ == STT_EXPRESSION_TYPE_IDENTIFIER) {

#ifndef NDEBUG
		assertion(expression->sub_identifier_ != NULL);
#endif
		stt_expression_sub_identifier_destructor(
				expression->sub_identifier_);
	} else if (expression->type_ == STT_EXPRESSION_TYPE_CONDITIONAL) {

#ifndef NDEBUG
		assertion(expression->sub_conditional_ != NULL);
#endif
		stt_expression_sub_conditional_destructor(
				expression->sub_conditional_);
	} else if (expression->type_ == STT_EXPRESSION_TYPE_FUNCTION_CALL) {

#ifndef NDEBUG
		assertion(expression->sub_function_call_ != NULL);
#endif
		stt_expression_sub_function_call_destructor(
				expression->sub_function_call_);
	} else {
#ifndef NDEBUG
		assertion(expression->type_ == STT_EXPRESSION_TYPE_DICE);
#endif

#ifndef NDEBUG
		assertion(expression->sub_dice_ != NULL);
#endif
		stt_expression_sub_dice_destructor(expression->sub_dice_);
	}
	free(expression);
}

void
stt_expression_set_string_literal(
		stt_expression * expression,
		const amara_string * string_literal)
{
#ifndef NDEBUG
	assertion(expression != NULL);
	assertion(expression->type_ == STT_EXPRESSION_TYPE_INVALID);
	assertion(expression->sub_string_literal_ == NULL);
	assertion(expression->sub_natural_literal_ == NULL);
	assertion(expression->sub_conditional_ == NULL);
	assertion(expression->sub_dice_ == NULL);
#endif

#ifndef NDEBUG
	assertion(string_literal != NULL);
	assertion(string_literal->value_ != NULL);
#endif

	expression->sub_string_literal_ =
			stt_expression_sub_string_literal_exhaustive_constructor(
					string_literal);

	expression->type_ = STT_EXPRESSION_TYPE_STRING_LITERAL;
}

void
stt_expression_set_natural_literal(
		stt_expression * expression, const natural * natural_literal)
{
#ifndef NDEBUG
	assertion(expression != NULL);
	assertion(expression->type_ == STT_EXPRESSION_TYPE_INVALID);
	assertion(expression->sub_string_literal_ == NULL);
	assertion(expression->sub_natural_literal_ == NULL);
	assertion(expression->sub_conditional_ == NULL);
	assertion(expression->sub_dice_ == NULL);
#endif

#ifndef NDEBUG
	assertion(natural_literal != NULL);
	assertion(natural_literal->raw_ != NULL);
	assertion(natural_literal->raw_->value_ != NULL);
	natural_assert_validity(natural_literal);
#endif

	expression->sub_natural_literal_ =
			stt_expression_sub_natural_literal_exhaustive_constructor(
					natural_literal);

	expression->type_ = STT_EXPRESSION_TYPE_NATURAL_LITERAL;
}

void
stt_expression_set_identifier(
		stt_expression * expression, const amara_string * identifier)
{
#ifndef NDEBUG
	assertion(expression != NULL);
	assertion(expression->type_ == STT_EXPRESSION_TYPE_INVALID);
	assertion(expression->sub_string_literal_ == NULL);
	assertion(expression->sub_natural_literal_ == NULL);
	assertion(expression->sub_conditional_ == NULL);
	assertion(expression->sub_dice_ == NULL);
#endif

#ifndef NDEBUG
	assertion(identifier != NULL);
	assertion(identifier->value_ != NULL);
#endif

	expression->sub_identifier_ =
			stt_expression_sub_identifier_exhaustive_constructor(
					identifier);

	expression->type_ = STT_EXPRESSION_TYPE_IDENTIFIER;
}

void
stt_expression_set_conditional(
		stt_expression * expression,
		const stt_expression_sub_conditional * expression_sub_conditional)
{
	assertion(expression != NULL);
	assertion(expression->type_ == STT_EXPRESSION_TYPE_INVALID);
	assertion(expression->sub_string_literal_ == NULL);
	assertion(expression->sub_natural_literal_ == NULL);
	assertion(expression->sub_conditional_ == NULL);
	assertion(expression->sub_dice_ == NULL);

	assertion(expression_sub_conditional != NULL);
	assertion(expression_sub_conditional->if_ != NULL);
	assertion(expression_sub_conditional->if_->type_ !=
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
	assertion(expression_sub_conditional->if_->condition_ != NULL);
	assertion(expression_sub_conditional->if_->expression_then_ != NULL);
	forced_assertion(expression_sub_conditional->if_->type_ ==
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

	expression->sub_conditional_ =
			stt_expression_sub_conditional_copy_constructor(
					expression_sub_conditional);

	expression->type_ = STT_EXPRESSION_TYPE_CONDITIONAL;
}

void
stt_expression_set_function_call(
		stt_expression * expression,
		const struct stt_expression_sub_function_call * sub_function_call)
{
#ifndef NDEBUG
	assertion_two(expression != NULL, "stt_expression.c: 352\n");
	assertion_two(expression->type_ == STT_EXPRESSION_TYPE_INVALID,
			"stt_expression.c: 353\n");
	assertion_two(sub_function_call != NULL, "stt_expression.c: 355\n");
#endif

#ifndef NDEBUG
	assertion_two(expression->sub_function_call_ == NULL,
			"stt_expression.c: 359\n");
#endif

	expression->sub_function_call_ =
			stt_expression_sub_function_call_copy_constructor(
					sub_function_call);
	forced_assertion(expression->sub_function_call_ != NULL);

	expression->type_ = STT_EXPRESSION_TYPE_FUNCTION_CALL;
}

void
stt_expression_set_dice(stt_expression * expression,
                        const stt_dice_expression * dice_expression)
{
	stt_expression_sub_dice * expression_sub_dice_;

	assertion(expression != NULL);
	assertion(expression->type_ == STT_EXPRESSION_TYPE_INVALID);
	assertion(expression->sub_string_literal_ == NULL);
	assertion(expression->sub_natural_literal_ == NULL);
	assertion(expression->sub_conditional_ == NULL);
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

amara_boolean
stt_expression_equality(const stt_expression * e0, const stt_expression * e1)
{
	amara_boolean equality_;

#ifndef NDEBUG
	assertion(e0 != NULL);
	assertion(e0->type_ != STT_EXPRESSION_TYPE_INVALID);
	assertion(e1 != NULL);
	assertion(e1->type_ != STT_EXPRESSION_TYPE_INVALID);
#endif

	if (e0->type_ != e1->type_) {

		/*   XXX Potentially not? Revaluate identity, equality,
		 * and equivalence considerations..? */
		return AMARA_BOOLEAN_FALSE;
	}

	fprintf(stderr, "stt_expression.c: 437: %u\n", e0->type_);
	fprintf(stderr, "stt_expression.c: 438: %u\n", e1->type_);

	if (e0->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL) {

#ifndef NDEBUG
		assertion(e0->sub_string_literal_ != NULL);
		assertion(e0->sub_string_literal_->string_literal_ != NULL);
		assertion(e0->sub_string_literal_->string_literal_->value_ !=
				NULL);
		assertion(e1->sub_string_literal_ != NULL);
		assertion(e1->sub_string_literal_->string_literal_ != NULL);
		assertion(e1->sub_string_literal_->string_literal_->value_ !=
				NULL);
#endif

		equality_ = amara_string_equality(
				e0->sub_string_literal_->string_literal_,
				e1->sub_string_literal_->string_literal_);
	} else if (e0->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL) {

#ifndef NDEBUG
		assertion(e0->sub_natural_literal_ != NULL);
		assertion(e0->sub_natural_literal_->natural_literal_ != NULL);
		assertion(e0->sub_natural_literal_->natural_literal_->raw_ !=
				NULL);
		assertion(e0->sub_natural_literal_->natural_literal_->raw_->value_ !=
				NULL);
		assertion(e1->sub_natural_literal_ != NULL);
		assertion(e1->sub_natural_literal_->natural_literal_ != NULL);
		assertion(e1->sub_natural_literal_->natural_literal_->raw_ !=
				NULL);
		assertion(e1->sub_natural_literal_->natural_literal_->raw_->value_ !=
				NULL);
#endif

		/*

		equality_ = natural_equality(
				e0->sub_natural_literal_->natural_literal_,
				e1->sub_natural_literal_->natural_literal_);

		*/

		equality_ = amara_string_equality(
				e0->sub_natural_literal_->natural_literal_->raw_,
				e1->sub_natural_literal_->natural_literal_->raw_);
	} else if (e0->type_ == STT_EXPRESSION_TYPE_FUNCTION_CALL) {

#ifndef NDEBUG
		assertion(e0->sub_function_call_ != NULL);
		assertion(e0->sub_function_call_->function_name_ != NULL);
		assertion(e0->sub_function_call_->call_arguments_ != NULL);
		assertion(e0->sub_function_call_->builtin_function_ != NULL);
		assertion(e1->sub_function_call_ != NULL);
		assertion(e1->sub_function_call_->function_name_ != NULL);
		assertion(e1->sub_function_call_->call_arguments_ != NULL);
		assertion(e1->sub_function_call_->builtin_function_ != NULL);
#endif

		equality_ = stt_expression_sub_function_call_equality(
				e0->sub_function_call_,
				e1->sub_function_call_);
	} else {
		forced_assertion_two(
				e0->type_ == STT_EXPRESSION_TYPE_IDENTIFIER,
				"stt_expression.c: 438\n");

#ifndef NDEBUG
		assertion_two(e0->sub_identifier_ != NULL, "stt_expression.c: 443\n");
		assertion_two(e0->sub_identifier_->identifier_ != NULL, "stt_expression.c: 444\n");
		assertion_two(e0->sub_identifier_->identifier_->value_ != NULL, "stt_expression.c: 445\n");
		assertion_two(e1->sub_identifier_ != NULL, "stt_expression.c: 446\n");
		assertion_two(e1->sub_identifier_->identifier_ != NULL, "stt_expression.c: 447\n");
		assertion_two(e1->sub_identifier_->identifier_->value_ != NULL, "stt_expression.c: 448\n");
#endif

		equality_ = amara_strings_equality(
				e0->sub_identifier_->identifier_,
				e1->sub_identifier_->identifier_);
	}

	return equality_;
}

amara_boolean
stt_expressions_equality(const stt_expression * e0, const stt_expression * e1)
{
	return stt_expression_equality(e0, e1);
}

#ifndef NDEBUG

void
stt_expression_assert_clean_string_literal(const stt_expression * this)
{
	assertion(this != NULL);
	assertion(this->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL);
	assertion(this->sub_string_literal_ != NULL);
	assertion(this->sub_string_literal_->string_literal_ != NULL);
	assertion(this->sub_string_literal_->string_literal_->value_ != NULL);
	assertion(this->sub_natural_literal_ == NULL);
	assertion(this->sub_identifier_ == NULL);
	assertion(this->sub_conditional_ == NULL);
	assertion(this->sub_dice_ == NULL);
}

void
stt_expression_assert_clean_natural_literal(const stt_expression * this)
{
	assertion(this != NULL);
	assertion(this->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(this->sub_string_literal_ == NULL);
	assertion(this->sub_natural_literal_ != NULL);
	assertion(this->sub_natural_literal_->natural_literal_ != NULL);
	assertion(this->sub_natural_literal_->natural_literal_->raw_ != NULL);
	assertion(this->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(this->sub_identifier_ == NULL);
	assertion(this->sub_conditional_ == NULL);
	assertion(this->sub_dice_ == NULL);
}

void
stt_expression_assert_clean_identifier(const stt_expression * this)
{
	assertion(this != NULL);
	assertion(this->type_ == STT_EXPRESSION_TYPE_IDENTIFIER);
	assertion(this->sub_string_literal_ == NULL);
	assertion(this->sub_natural_literal_ == NULL);
	assertion(this->sub_identifier_ != NULL);
	assertion(this->sub_identifier_->identifier_ != NULL);
	assertion(this->sub_identifier_->identifier_->value_ != NULL);
	assertion(this->sub_conditional_ == NULL);
	assertion(this->sub_dice_ == NULL);
}

void
stt_expression_assert_clean_conditional(const stt_expression * this)
{
	assertion(this != NULL);
	assertion(this->type_ == STT_EXPRESSION_TYPE_CONDITIONAL);
	assertion(this->sub_string_literal_ == NULL);
	assertion(this->sub_natural_literal_ == NULL);
	assertion(this->sub_identifier_ == NULL);
	assertion(this->sub_conditional_ != NULL);
	assertion(this->sub_conditional_->if_ != NULL);
	assertion(this->sub_conditional_->if_->condition_ != NULL);
	assertion(this->sub_conditional_->if_->expression_then_ != NULL);
	forced_assertion(this->sub_conditional_->if_->next_if_ == NULL);
	/*
	if (this->sub_conditional_->if_->next_if_ == NULL) {
	*/
		assertion(this->sub_conditional_->if_->expression_else_ !=
				NULL);
	/*
	} else {
		assertion(this->sub_conditional_->if_->expression_else_ ==
				NULL);
	}
	*/
	assertion(this->sub_dice_ == NULL);
}

void
stt_expression_assert_clean_function_call(const stt_expression * this)
{
	located_assertion(this != NULL);
	located_assertion(this->type_ == STT_EXPRESSION_TYPE_FUNCTION_CALL);
	assertion(this->sub_string_literal_ == NULL);
	assertion(this->sub_natural_literal_ == NULL);
	assertion(this->sub_identifier_ == NULL);
	assertion(this->sub_conditional_ == NULL);
	located_assertion(this->sub_function_call_ != NULL);
	located_assertion(this->sub_function_call_->builtin_function_ != NULL);
	located_assertion(this->sub_function_call_->function_name_ != NULL);
	located_assertion(this->sub_function_call_->call_arguments_ != NULL);
	located_assertion(this->sub_dice_ == NULL);
}

void
stt_expression_assert_clean_dice(const stt_expression * this)
{
	assertion(this != NULL);
	assertion(this->type_ == STT_EXPRESSION_TYPE_DICE);
	assertion(this->sub_string_literal_ == NULL);
	assertion(this->sub_natural_literal_ == NULL);
	assertion(this->sub_identifier_ == NULL);
	assertion(this->sub_conditional_ == NULL);
	assertion(this->sub_dice_ != NULL);
	assertion(this->sub_dice_->left_hand_side_natural_ != NULL);
	assertion(this->sub_dice_->left_hand_side_natural_->raw_ != NULL);
	assertion(this->sub_dice_->left_hand_side_natural_->raw_->value_ !=
			NULL);
	assertion(this->sub_dice_->right_hand_side_natural_ != NULL);
	assertion(this->sub_dice_->right_hand_side_natural_->raw_ != NULL);
	assertion(this->sub_dice_->right_hand_side_natural_->raw_->value_ !=
			NULL);
}

void
stt_expression_assert_cleanliness(const stt_expression * this)
{
	assertion(this != NULL);
	if (this->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL) {

		stt_expression_assert_clean_string_literal(this);
	} else if (this->type_ == STT_EXPRESSION_TYPE_IDENTIFIER) {

		stt_expression_assert_clean_identifier(this);
	} else if (this->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL) {

		stt_expression_assert_clean_natural_literal(this);
	} else {
		forced_assertion(this->type_ == STT_EXPRESSION_TYPE_DICE);

		stt_expression_assert_clean_dice(this);
	}
}

#endif
