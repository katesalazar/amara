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
 * src/arn/arn_type.c: Amara application run time value type. A value is
 * basically a constant.
 */

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

/*   For `arn_type`. */
#include "arn_type.h"

/*
arn_type_type
arn_type_type_ill()
{
	arn_type_type returning_;

	returning_ = 0xFE;

#ifndef NDEBUG
	assertion(returning_ != ARN_TYPE_TYPE_INVALID);
	assertion(returning_ != ARN_TYPE_TYPE_STRING);
	assertion(returning_ != ARN_TYPE_TYPE_BOOLEAN);
	assertion(returning_ != ARN_TYPE_TYPE_NATURAL);
	assertion(returning_ != ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED);
	assertion(rtg_condition_type_is_ill(returning_) == AMARA_BOOLEAN_TRUE);
#endif

	return returning_;
}
*/

amara_boolean
arn_type_type_is_valid(arn_type_type type_type)
{
	if (type_type == ARN_TYPE_TYPE_STRING) {

		return AMARA_BOOLEAN_TRUE;
	}
	if (type_type == ARN_TYPE_TYPE_BOOLEAN) {

		return AMARA_BOOLEAN_TRUE;
	}
	if (type_type == ARN_TYPE_TYPE_NATURAL) {

		return AMARA_BOOLEAN_TRUE;
	}
	if (type_type == ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED) {

		return AMARA_BOOLEAN_TRUE;
	}
	return AMARA_BOOLEAN_FALSE;
}
/*
amara_boolean
arn_type_type_is_known(arn_type_type type_type)
{
	if (arn_type_type_is_valid(type_type) == AMARA_BOOLEAN_TRUE) {

		return AMARA_BOOLEAN_TRUE;
	}

	if (type_type == ARN_TYPE_TYPE_INVALID) {

		return AMARA_BOOLEAN_TRUE;
	}

	return AMARA_BOOLEAN_FALSE;
}

amara_boolean
arn_type_type_is_ill(arn_type_type type_type)
{
	amara_boolean known_;

	known_ = arn_type_type_is_known(type_type);

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

arn_type *
arn_type_default_constructor()
{
	arn_type * returning_;

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(arn_type *)
#endif
			malloc(sizeof(arn_type));
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	returning_->type_ = ARN_TYPE_TYPE_INVALID;

	returning_->name_ = NULL;

	return returning_;
}

void
arn_type_destructor(arn_type * type)
{
#ifndef NDEBUG
	assertion(type != NULL);
	assertion(type->type_ != ARN_TYPE_TYPE_INVALID);
#endif

	/*
	if (arn_type_type_is_known(type->type_) == AMARA_BOOLEAN_TRUE) {
	*/

#ifndef NDEBUG
		assertion(type->name_ != NULL);
		assertion(type->name_->value_ != NULL);
#endif

		amara_string_destructor(type->name_);
	/*
	} else {
#ifndef NDEBUG
		assertion(arn_type_type_is_ill(type->type_) ==
				AMARA_BOOLEAN_TRUE);
#endif

		if (type->name_ != NULL) {
#ifndef NDEBUG
			assertion(type->name_->value_ != NULL);
#endif

			amara_string_destructor(type->name_);
		}
	}
	*/

	free(type);
}

arn_type *
arn_type_out_of_rtg_condition_of_type_less_than(
		const rtg_condition * condition)
__attribute__((warn_unused_result))
;

arn_type *
arn_type_out_of_rtg_condition_of_type_less_than(
		const rtg_condition * condition)
{
	arn_type * left_hand_side_type_;
	arn_type * right_hand_side_type_;
	arn_type * returning_;

#ifndef NDEBUG
	assertion(condition != NULL);
	assertion(condition->type_ == RTG_CONDITION_TYPE_LESS_THAN);
	assertion(condition->left_hand_side_expression_ != NULL);
	assertion(condition->right_hand_side_expression_ != NULL);
#endif

	left_hand_side_type_ = arn_type_out_of_rtg_expression(
			condition->left_hand_side_expression_);
#ifndef NDEBUG
	/*
	if (left_hand_side_type_ == NULL) {
		fprintf(stderr, "debugger break\n");
	}
	*/
	assertion(left_hand_side_type_ != NULL);
#endif

	right_hand_side_type_ = arn_type_out_of_rtg_expression(
			condition->right_hand_side_expression_);
#ifndef NDEBUG
	assertion(right_hand_side_type_ != NULL);
#endif

	assertion(left_hand_side_type_->type_ == ARN_TYPE_TYPE_NATURAL);  /* XXX */
	assertion(right_hand_side_type_->type_ == ARN_TYPE_TYPE_NATURAL);  /* XXX */

	returning_ = arn_type_default_constructor();

	returning_->type_ = ARN_TYPE_TYPE_BOOLEAN;  /* XXX */
	returning_->name_ = arn_type_type_name_out_of_type_type(  /* XXX */
			ARN_TYPE_TYPE_BOOLEAN);  /* XXX */

	return returning_;
}

/*
arn_type *
arn_type_out_of_rtg_condition_of_type_equal_to(const rtg_condition * condition)
__attribute__((warn_unused_result))
;

arn_type *
arn_type_out_of_rtg_condition_of_type_equal_to(const rtg_condition * condition)
{
	arn_type * returning_;

	condition = NULL;  *//* FIXME *//*
	if (condition) condition = NULL;  *//* FIXME *//*

	returning_ = NULL;  *//* FIXME *//*

	return returning_;  *//* FIXME *//*
}
*/

/*
arn_type *
arn_type_out_of_rtg_condition_of_type_greater_than(
		const rtg_condition * condition)
__attribute__((warn_unused_result))
;

arn_type *
arn_type_out_of_rtg_condition_of_type_greater_than(
		const rtg_condition * condition)
{
	arn_type * returning_;

	condition = NULL;  *//* FIXME *//*
	if (condition) condition = NULL;  *//* FIXME *//*

	returning_ = NULL;  *//* FIXME *//*

	return returning_;  *//* FIXME *//*
}
*/

/*
arn_type *
arn_type_out_of_rtg_condition_of_type_greater_than_or_equal_to(
		const rtg_condition * condition)
__attribute__((warn_unused_result))
;

arn_type *
arn_type_out_of_rtg_condition_of_type_greater_than_or_equal_to(
		const rtg_condition * condition)
{
	rtg_condition * flipped_;
	arn_type * returning_;

#ifndef NDEBUG
	assertion(condition != NULL);
#endif

	flipped_ = rtg_condition_flip(condition);
#ifndef NDEBUG
	assertion(flipped_ != NULL);
#endif

	returning_ = arn_type_out_of_rtg_condition_of_type_less_than(flipped_);
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	return returning_;
}
*/

/*
arn_type *
arn_type_out_of_rtg_condition_of_type_not_equal_to(
		const rtg_condition * condition)
__attribute__((warn_unused_result))
;

arn_type *
arn_type_out_of_rtg_condition_of_type_not_equal_to(
		const rtg_condition * condition)
{
	arn_type * returning_;

	condition = NULL;  *//* FIXME *//*
	if (condition) condition = NULL;  *//* FIXME *//*

	returning_ = NULL;  *//* FIXME *//*

	return returning_;  *//* FIXME *//*
}
*/

/*
arn_type *
arn_type_out_of_rtg_condition_of_type_less_than_or_equal_to(
		const rtg_condition * condition)
__attribute__((warn_unused_result))
;

arn_type *
arn_type_out_of_rtg_condition_of_type_less_than_or_equal_to(
		const rtg_condition * condition)
{
	rtg_condition * flipped_;
	arn_type * returning_;

#ifndef NDEBUG
	assertion(condition != NULL);
#endif

	flipped_ = rtg_condition_flip(condition);
#ifndef NDEBUG
	assertion(flipped_ != NULL);
#endif

	returning_ = arn_type_out_of_rtg_condition_of_type_greater_than(
			flipped_);
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	return returning_;
}
*/

arn_type *
arn_type_out_of_rtg_condition(const rtg_condition * condition)
__attribute__((warn_unused_result))
;

arn_type *
arn_type_out_of_rtg_condition(const rtg_condition * condition)
{
	arn_type * returning_;

#ifndef NDEBUG
	assertion(condition != NULL);
	assertion(condition->type_ != RTG_CONDITION_TYPE_INVALID);
#endif

	returning_ = NULL;

	forced_assertion(condition->type_ == RTG_CONDITION_TYPE_LESS_THAN);  /* XXX temporary */

	/*
	if (condition->type_ == RTG_CONDITION_TYPE_LESS_THAN) {
	*/

		returning_ = arn_type_out_of_rtg_condition_of_type_less_than(
				condition);
#ifndef NDEBUG
		assertion(returning_ != NULL);
#endif
		return returning_;
	/*
	}
	*/
	/*
	if (condition->type_ == RTG_CONDITION_TYPE_EQUAL_TO) {
		returning_ = arn_type_out_of_rtg_condition_of_type_equal_to(
				condition);
#ifndef NDEBUG
		assertion(returning_ != NULL);
#endif
		return returning_;
	}
	if (condition->type_ == RTG_CONDITION_TYPE_GREATER_THAN) {
		returning_ = arn_type_out_of_rtg_condition_of_type_greater_than(
				condition);
#ifndef NDEBUG
		assertion(returning_ != NULL);
#endif
		return returning_;
	}
	if (condition->type_ == RTG_CONDITION_TYPE_GREATER_THAN_OR_EQUAL_TO) {
		returning_ = arn_type_out_of_rtg_condition_of_type_greater_than_or_equal_to(
				condition);
#ifndef NDEBUG
		assertion(returning_ != NULL);
#endif
		return returning_;
	}
	if (condition->type_ == RTG_CONDITION_TYPE_NOT_EQUAL_TO) {
		returning_ = arn_type_out_of_rtg_condition_of_type_not_equal_to(
				condition);
#ifndef NDEBUG
		assertion(returning_ != NULL);
#endif
		return returning_;
	}
	if (condition->type_ == RTG_CONDITION_TYPE_LESS_THAN_OR_EQUAL_TO) {
		returning_ = arn_type_out_of_rtg_condition_of_type_less_than_or_equal_to(
				condition);
#ifndef NDEBUG
		assertion(returning_ != NULL);
#endif
		return returning_;
	}
	*/

	/*
	if (returning_ == NULL) {
		returning_ = arn_type_default_constructor();
#ifndef NDEBUG
		assertion(returning_ != NULL);
		assertion(returning_->type_ == ARN_TYPE_TYPE_INVALID);
#endif

		returning_->type_ = ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
		returning_->name_ = arn_type_type_name_out_of_type_type(
				ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED);
	}
	*/

	return returning_;
}

arn_type *
arn_type_out_of_rtg_expression_sub_conditional_if(
		const rtg_expression_sub_conditional_if * expression_sub_conditional_if)
__attribute__((warn_unused_result))
;

arn_type *
arn_type_out_of_rtg_expression_sub_conditional_if(
		const rtg_expression_sub_conditional_if * expression_sub_conditional_if)
{
	arn_type * condition_type_;

	arn_type * expression_then_type_;

	/**  And so this is an `if [...] then [...] else [...]` type of
	 * expression. */
	amara_boolean next_if_is_null_;

	arn_type * next_if_type_;

	/**  And so this is an `if [...] then [...] else if [...] then
	 * [...] [...] else [...]` type of expression. */
	amara_boolean else_is_null_;

	arn_type * expression_else_type_;

	arn_type * returning_;

	assertion(expression_sub_conditional_if != NULL);

	assertion(expression_sub_conditional_if->condition_ != NULL);

	condition_type_ = arn_type_out_of_rtg_condition(
			expression_sub_conditional_if->condition_);

	assertion(expression_sub_conditional_if->expression_then_ != NULL);

	expression_then_type_ = arn_type_out_of_rtg_expression(
			expression_sub_conditional_if->expression_then_);

	forced_assertion(expression_sub_conditional_if->expression_else_ !=
			NULL);

	/*
	if (expression_sub_conditional_if->expression_else_ == NULL) {

		next_if_is_null_ = AMARA_BOOLEAN_FALSE;
		else_is_null_ = AMARA_BOOLEAN_TRUE;
		next_if_type_ = arn_type_out_of_rtg_expression_sub_conditional_if(
				expression_sub_conditional_if->next_if_);
		expression_else_type_ = NULL;
	} else {
	*/
		forced_assertion(expression_sub_conditional_if->next_if_ == NULL);

		next_if_is_null_ = AMARA_BOOLEAN_TRUE;
		else_is_null_ = AMARA_BOOLEAN_FALSE;
		next_if_type_ = NULL;
		expression_else_type_ = arn_type_out_of_rtg_expression(
				expression_sub_conditional_if->expression_else_);
	/*
	}
	*/

	returning_ = NULL;

	forced_assertion(condition_type_->type_ == ARN_TYPE_TYPE_BOOLEAN);

	/*
	if (condition_type_->type_ != ARN_TYPE_TYPE_BOOLEAN) {

		returning_ = arn_type_default_constructor();
		returning_->type_ = ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
		return returning_;
	}
	*/

	forced_assertion(expression_then_type_->type_ !=
			ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED);

	/*
	if (expression_then_type_->type_ ==
			ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED) {

		returning_ = arn_type_default_constructor();
		returning_->type_ = ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
		return returning_;
	}
	*/

	if (next_if_is_null_ == AMARA_BOOLEAN_TRUE) {

		assertion(else_is_null_ == AMARA_BOOLEAN_FALSE);

		forced_assertion(expression_else_type_->type_ !=
				ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED);

		/*
		if (expression_else_type_->type_ ==
				ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED) {

			returning_ = arn_type_default_constructor();
			returning_->type_ = ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
			return returning_;
		}
		*/
	}

	forced_assertion(else_is_null_ != AMARA_BOOLEAN_TRUE);

	/*
	if (else_is_null_ == AMARA_BOOLEAN_TRUE) {

		assertion(next_if_is_null_ == AMARA_BOOLEAN_FALSE);

		if (next_if_type_->type_ ==
				ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED) {

			returning_ = arn_type_default_constructor();
			returning_->type_ = ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
			return returning_;
		}
	}
	*/

	if (next_if_is_null_ == AMARA_BOOLEAN_TRUE) {
		assertion(else_is_null_ == AMARA_BOOLEAN_FALSE);
		if (expression_then_type_->type_ == ARN_TYPE_TYPE_BOOLEAN) {
			if (expression_else_type_->type_ ==
					ARN_TYPE_TYPE_BOOLEAN) {
				returning_ = arn_type_default_constructor();
				returning_->type_ = ARN_TYPE_TYPE_BOOLEAN;
				returning_->name_ = arn_type_type_name_out_of_type_type(ARN_TYPE_TYPE_BOOLEAN);
				return returning_;
			} else if (expression_else_type_->type_ ==
					ARN_TYPE_TYPE_STRING) {
				/* TODO Allow type erasure `string|natural`, `any`, etc., compound type erasures. */
				returning_ = arn_type_default_constructor();
				returning_->type_ =
						ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
				return returning_;
			} else {
				assertion(expression_else_type_->type_ ==
						ARN_TYPE_TYPE_NATURAL);
				/* TODO Allow type erasure `string|natural`, `any`, etc., compound type erasures. */
				returning_ = arn_type_default_constructor();
				returning_->type_ =
						ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
				return returning_;
			}
		} else if (expression_then_type_->type_ ==
				ARN_TYPE_TYPE_STRING) {
			if (expression_else_type_->type_ ==
					ARN_TYPE_TYPE_BOOLEAN) {
				/* TODO Allow type erasure `string|natural`, `any`, etc., compound type erasures. */
				returning_ = arn_type_default_constructor();
				returning_->type_ =
						ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
				return returning_;
			} else if (expression_else_type_->type_ ==
					ARN_TYPE_TYPE_STRING) {
				returning_ = arn_type_default_constructor();
				returning_->type_ = ARN_TYPE_TYPE_STRING;
				returning_->name_ = arn_type_type_name_out_of_type_type(ARN_TYPE_TYPE_STRING);
				return returning_;
			} else {
				assertion(expression_else_type_->type_ ==
						ARN_TYPE_TYPE_NATURAL);
				/* TODO Allow type erasure `string|natural`, `any`, etc., compound type erasures. */
				returning_ = arn_type_default_constructor();
				returning_->type_ =
						ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
				return returning_;
			}
		} else {
			assertion(expression_then_type_->type_ ==
					ARN_TYPE_TYPE_NATURAL);
			if (expression_else_type_->type_ == ARN_TYPE_TYPE_BOOLEAN) {
				/* TODO Allow type erasure `string|natural`, `any`, etc., compound type erasures. */
				returning_ = arn_type_default_constructor();
				returning_->type_ =
						ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
				return returning_;
			} else if (expression_else_type_->type_ ==
					ARN_TYPE_TYPE_STRING) {
				/* TODO Allow type erasure `string|natural`, `any`, etc., compound type erasures. */
				returning_ = arn_type_default_constructor();
				returning_->type_ =
						ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
				return returning_;
			} else {
				assertion(expression_else_type_->type_ ==
						ARN_TYPE_TYPE_NATURAL);
				returning_ = arn_type_default_constructor();
				returning_->type_ = ARN_TYPE_TYPE_NATURAL;
				returning_->name_ = arn_type_type_name_out_of_type_type(ARN_TYPE_TYPE_NATURAL);
				return returning_;
			}
		}
	} else {
		assertion(next_if_is_null_ == AMARA_BOOLEAN_FALSE);
		assertion(else_is_null_ == AMARA_BOOLEAN_TRUE);
		if (expression_then_type_->type_ == ARN_TYPE_TYPE_BOOLEAN) {
			if (next_if_type_->type_ == ARN_TYPE_TYPE_BOOLEAN) {
				returning_ = arn_type_default_constructor();
				returning_->type_ = ARN_TYPE_TYPE_BOOLEAN;
				returning_->name_ = arn_type_type_name_out_of_type_type(ARN_TYPE_TYPE_BOOLEAN);
				return returning_;
			} else if (next_if_type_->type_ ==
					ARN_TYPE_TYPE_STRING) {
				/* TODO Allow type erasure `string|natural`, `any`, etc., compound type erasures. */
				returning_ = arn_type_default_constructor();
				returning_->type_ =
						ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
				return returning_;
			} else {
				assertion(next_if_type_->type_ ==
						ARN_TYPE_TYPE_NATURAL);
				/* TODO Allow type erasure `string|natural`, `any`, etc., compound type erasures. */
				returning_ = arn_type_default_constructor();
				returning_->type_ =
						ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
				return returning_;
			}
		} else if (expression_then_type_->type_ ==
				ARN_TYPE_TYPE_STRING) {
			if (next_if_type_->type_ == ARN_TYPE_TYPE_BOOLEAN) {
				/* TODO Allow type erasure `string|natural`, `any`, etc., compound type erasures. */
				returning_ = arn_type_default_constructor();
				returning_->type_ =
						ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
				return returning_;
			} else if (next_if_type_->type_ ==
					ARN_TYPE_TYPE_STRING) {
				returning_ = arn_type_default_constructor();
				returning_->type_ = ARN_TYPE_TYPE_STRING;
				returning_->name_ = arn_type_type_name_out_of_type_type(ARN_TYPE_TYPE_STRING);
				return returning_;
			} else {
				assertion(next_if_type_->type_ ==
						ARN_TYPE_TYPE_NATURAL);
				/* TODO Allow type erasure `string|natural`, `any`, etc., compound type erasures. */
				returning_ = arn_type_default_constructor();
				returning_->type_ =
						ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
				return returning_;
			}
		} else {
			assertion(expression_then_type_->type_ ==
					ARN_TYPE_TYPE_NATURAL);
			if (next_if_type_->type_ == ARN_TYPE_TYPE_BOOLEAN) {
				/* TODO Allow type erasure `string|natural`, `any`, etc., compound type erasures. */
				returning_ = arn_type_default_constructor();
				returning_->type_ =
						ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
				return returning_;
			} else if (next_if_type_->type_ ==
					ARN_TYPE_TYPE_STRING) {
				/* TODO Allow type erasure `string|natural`, `any`, etc., compound type erasures. */
				returning_ = arn_type_default_constructor();
				returning_->type_ =
						ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;
				return returning_;
			} else {
				assertion(next_if_type_->type_ ==
						ARN_TYPE_TYPE_NATURAL);
				returning_ = arn_type_default_constructor();
				returning_->type_ = ARN_TYPE_TYPE_NATURAL;
				returning_->name_ = arn_type_type_name_out_of_type_type(ARN_TYPE_TYPE_NATURAL);
				return returning_;
			}
		}
	}

	/*

	arn_type_destructor(condition_type_);

	arn_type_destructor(expression_then_type_);

	if (else_is_null_ == AMARA_BOOLEAN_FALSE) {
		assertion(next_if_is_null_ == AMARA_BOOLEAN_TRUE);
		arn_type_destructor(expression_else_type_);
	}

	if (next_if_is_null_ == AMARA_BOOLEAN_FALSE) {
		assertion(else_is_null_ == AMARA_BOOLEAN_TRUE);
		arn_type_destructor(next_if_type_);
	}

	if (returning_ == NULL) {
		returning_ = arn_type_default_constructor();
	}
	return returning_;

	*/
}

arn_type *
arn_type_out_of_rtg_expression_sub_conditional(
		const rtg_expression_sub_conditional * expression_sub_conditional)
__attribute__((warn_unused_result))
;

arn_type *
arn_type_out_of_rtg_expression_sub_conditional(
		const rtg_expression_sub_conditional * expression_sub_conditional)
{
	arn_type * returning_;

#ifndef NDEBUG
	assertion(expression_sub_conditional != NULL);
	assertion(expression_sub_conditional->if_ != NULL);
#endif

	returning_ = arn_type_out_of_rtg_expression_sub_conditional_if(
			expression_sub_conditional->if_);

	return returning_;
}

arn_type *
arn_type_out_of_rtg_expression(const rtg_expression * expression)
{
	arn_type * returning_;

#ifndef NDEBUG
	assertion(expression != NULL);
	assertion(expression->type_ != RTG_EXPRESSION_TYPE_INVALID);
#endif

	if (expression->type_ == RTG_EXPRESSION_TYPE_STRING_LITERAL) {

#ifndef NDEBUG
		assertion(expression->sub_string_literal_ != NULL);
#endif

		returning_ = arn_type_default_constructor();
#ifndef NDEBUG
		assertion(returning_ != NULL);
#endif

		returning_->type_ = ARN_TYPE_TYPE_STRING;

		return returning_;
	} else if (expression->type_ == RTG_EXPRESSION_TYPE_NATURAL_LITERAL) {

#ifndef NDEBUG
		assertion(expression->sub_natural_literal_ != NULL);
#endif

		returning_ = arn_type_default_constructor();
#ifndef NDEBUG
		assertion(returning_ != NULL);
#endif

		returning_->type_ = ARN_TYPE_TYPE_NATURAL;

		return returning_;
	} else if (expression->type_ == RTG_EXPRESSION_TYPE_CONDITIONAL) {

#ifndef NDEBUG
		assertion(expression->sub_conditional_ != NULL);
#endif

		returning_ = arn_type_out_of_rtg_expression_sub_conditional(
				expression->sub_conditional_);
#ifndef NDEBUG
		assertion(returning_ != NULL);
#endif

		return returning_;
	} else {
#ifndef NDEBUG
		assertion(expression->type_ == RTG_EXPRESSION_TYPE_DICE);
#endif

#ifndef NDEBUG
		assertion(expression->sub_dice_ != NULL);
#endif

		returning_ = arn_type_default_constructor();
#ifndef NDEBUG
		assertion(returning_ != NULL);
#endif

		returning_->type_ = ARN_TYPE_TYPE_NATURAL;

		return returning_;
	}

	return NULL; /* TODO this should be unreachable... remove it. */
}

amara_string *
arn_type_type_name_out_of_type_type(arn_type_type type_type)
{
	amara_string * returning_;

	if (type_type == ARN_TYPE_TYPE_STRING) {

		returning_ = amara_string_exhaustive_constructor("string");
#ifndef NDEBUG
		assertion(returning_ != NULL);
		assertion(returning_->value_ != NULL);
#endif

		return returning_;
	}

	if (type_type == ARN_TYPE_TYPE_BOOLEAN) {

		returning_ = amara_string_exhaustive_constructor("boolean");
#ifndef NDEBUG
		assertion(returning_ != NULL);
		assertion(returning_->value_ != NULL);
#endif

		return returning_;
	}

#ifndef NDEBUG
	assertion(type_type == ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED);
#endif

	returning_ = amara_string_exhaustive_constructor("type_error");
#ifndef NDEBUG
	assertion(returning_ != NULL);
	assertion(returning_->value_ != NULL);
#endif

	return returning_;
}
