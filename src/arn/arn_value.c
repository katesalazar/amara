/*
 * Copyright 2018-2020 Mercedes Catherine Salazar
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
 * src/arn/arn_value.c: Amara application run time value. A value is
 * basically a constant.
 */

/*   For `void * malloc(size_t size)`. */
#include <stdio.h>

/*   For `rand`, `srand`, and `time`. */
#include <time.h>

/*   For `natural`. */
#include "../brt/natural.h"

/*   For `rtg_expression`. */
#include "../rtg/rtg_expression.h"

/*   For `arn_type`. */
#include "arn_type.h"

/*   For `arn_value`. */
#include "arn_value.h"

arn_value *
arn_value_default_constructor(void)
{
	arn_value * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(arn_value *)
#endif
			malloc(sizeof(arn_value));

	ret_->type_ = ARN_VALUE_TYPE_INVALID;
	ret_->name_ = NULL;
	ret_->string_ = NULL;
	ret_->string_was_moved = AMARA_BOOLEAN_FALSE;
	ret_->boolean_ = NULL;
	ret_->boolean_was_moved = AMARA_BOOLEAN_FALSE;
	ret_->natural_ = NULL;
	ret_->natural_was_moved = AMARA_BOOLEAN_FALSE;

	return ret_;
}

arn_value *
arn_value_copy_constructor(const arn_value * value)
{
	arn_value * ret_;

	assertion(value->type_ != ARN_VALUE_TYPE_INVALID);

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(arn_value *)
#endif
			malloc(sizeof(arn_value));

	ret_->type_ = ARN_VALUE_TYPE_INVALID;

	if (value->name_ != NULL) {
		ret_->name_ = amara_string_copy_constructor(value->name_);
	} else {
		ret_->name_ = NULL;
	}

	/* XXX obvious one */
	/* XXX */
	if (value->type_ != ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL) {
		/* XXX */
		if (value->type_ !=
				ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL) {
		if (value->type_ !=
				ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL) {
			/* XXX */
			if (value->type_ !=
					ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING) {
			if (value->type_ !=
					ARN_VALUE_TYPE_NAMED_ASSIGNED_STRING) {

				/* XXX */
#ifdef DUMP_FLOW_TO_STDERR
				/*
				fprintf(stderr, "%u\n", value->type_);
				*/
#endif
				assertion(value->type_ == ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);
			}
			}
		}
		}
	}

	assertion(value->type_ != ARN_VALUE_TYPE_INVALID);
	if (value->type_ != ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_STRING &&
			value->type_ != ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE &&
			value->type_ != ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL &&
			value->type_ != ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_NATURAL) {
		if (value->type_ != ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL) {
			if (value->type_ !=
					ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL) {
			if (value->type_ !=
					ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING) {

#ifdef DUMP_FLOW_TO_STDERR
				/*
				fprintf(stderr, "%u\n", value->type_);
				*/
#endif
				assertion(value->type_ ==
						ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_STRING);
			}
			}
		}
		if (value->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL ||
				value->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL) {
			ret_->string_ = NULL;
			ret_->string_was_moved = AMARA_BOOLEAN_FALSE;
			/* XXX */
			ret_->natural_ = natural_copy_constructor(
					value->natural_);
			/* XXX */
			ret_->natural_was_moved = AMARA_BOOLEAN_FALSE;
		} else {

#ifdef DUMP_FLOW_TO_STDERR
			/*
			fprintf(stderr, "%u\n", value->type_);
			*/
#endif
			assertion(value->type_ ==
					ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING);
			ret_->string_ = amara_string_copy_constructor(
					value->string_);
			ret_->string_was_moved = AMARA_BOOLEAN_FALSE;
			ret_->natural_ = NULL;
			ret_->natural_was_moved = AMARA_BOOLEAN_FALSE;
		}
	/* } else if (value->type_ == ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_STRING) { */
	} else {
		ret_->string_ = NULL; /* XXX will obviously change in the future. */
		ret_->string_was_moved = AMARA_BOOLEAN_FALSE; /* XXX will obviously change in the future. */
		ret_->natural_ = NULL;
		ret_->natural_was_moved = AMARA_BOOLEAN_FALSE;
	}

	/* XXX */
	if (value->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING) {
		ret_->type_ = ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING;
	} else if (value->type_ == ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL) {
		ret_->type_ = ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL;
	} else if (value->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL) {
		ret_->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL;
	} else if (value->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL) {
		ret_->type_ = ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL;
	} else {

#ifdef DUMP_FLOW_TO_STDERR
		/*
		fprintf(stderr, "%u\n", value->type_);
		*/
#endif

		assertion(value->type_ ==
				ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);
		assertion(value->name_ != NULL);
		assertion(value->name_->value_ != NULL);
		assertion(ret_->name_ != NULL);
		assertion(ret_->name_->value_ != NULL);
		ret_->type_ = ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE;
	}

	return ret_;
}

arn_value *
arn_value_out_of_amara_boolean(const amara_boolean boolean)
{
	arn_value * returning_;

	returning_ = arn_value_default_constructor();
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assertion(returning_->type_ == ARN_VALUE_TYPE_INVALID);
#endif

	arn_value_characterize_as_boolean(returning_);
#ifndef NDEBUG
	assertion(returning_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_BOOLEAN);
#endif

	arn_value_set_boolean(returning_, boolean);
#ifndef NDEBUG
	assertion(returning_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_BOOLEAN);
#endif

	return returning_;
}

void
arn_value_destructor(arn_value * value)
{
	forced_assertion(value != NULL);
	if (value->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING) {
#ifndef NDEBUG
		assertion(value->name_ == NULL);
		assertion(value->string_ != NULL);
		assertion(value->string_->value_ != NULL);
#endif
		amara_string_destructor(value->string_);
#ifndef NDEBUG
		assertion(value->natural_ == NULL);
#endif
	} else if (value->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_BOOLEAN) {
#ifndef NDEBUG
		assertion(value->name_ == NULL);
		assertion(value->boolean_ == NULL);
#endif
	} else if (value->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_BOOLEAN) {
#ifndef NDEBUG
		assertion(value->name_ == NULL);
		assertion(value->boolean_ != NULL);
		assertion(* value->boolean_ == AMARA_BOOLEAN_FALSE ||
				* value->boolean_ == AMARA_BOOLEAN_TRUE);
#endif
		free(value->boolean_);
	} else if (value->type_ == ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL) {
#ifndef NDEBUG
		assertion(value->name_ != NULL);
		assertion(value->name_->value_ != NULL);
#endif
		amara_string_destructor(value->name_);
#ifndef NDEBUG
		assertion(value->string_ == NULL);
		assertion(value->natural_ == NULL);
#endif
	} else if (value->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL) {
#ifndef NDEBUG
		assertion(value->name_ != NULL);
		assertion(value->name_->value_ != NULL);
#endif
		amara_string_destructor(value->name_);
#ifndef NDEBUG
		assertion(value->string_ == NULL);
		assertion(value->natural_ != NULL);
		assertion(value->natural_->raw_ != NULL);
		assertion(value->natural_->raw_->value_ != NULL);
		assertion(value->natural_was_moved == AMARA_BOOLEAN_FALSE);
#endif
		natural_destructor(value->natural_);
	} else if (value->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL) {
#ifndef NDEBUG
		assertion(value->name_ == NULL);
		assertion(value->string_ == NULL);
		assertion(value->natural_ != NULL);
		assertion(value->natural_->raw_ != NULL);
		assertion(value->natural_->raw_->value_ != NULL);
		assertion(value->natural_was_moved == AMARA_BOOLEAN_FALSE);
#endif
		natural_destructor(value->natural_);
	} else if (value->type_ ==
			ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE) {
#ifndef NDEBUG
		assertion(value->name_ != NULL);
		assertion(value->name_->value_ != NULL);
#endif
		amara_string_destructor(value->name_);
#ifndef NDEBUG
		assertion(value->string_ == NULL);
		assertion(value->natural_ == NULL);
#endif
	} else {

#ifdef DUMP_FLOW_TO_STDERR
		/*
		fprintf(stderr, "%u\n", value->type_);
		*/
#endif

		forced_assertion(value->type_ == ARN_VALUE_TYPE_INVALID);
#ifndef NDEBUG
		assertion(value->name_ == NULL);
		assertion(value->string_ == NULL);
		assertion(value->natural_ == NULL);
#endif
	}
	free(value);
}

/**  Helper. */
arn_value *
run_dice(const rtg_expression_sub_dice * expression_sub_dice)
__attribute__((warn_unused_result))
;

arn_value *
run_dice(const rtg_expression_sub_dice * expression_sub_dice)
{
	time_t r_seed_;  /* XXX ??? */
	arn_value * returning_;
	unsigned char random_;
	unsigned char uc_;
	unsigned char rolls_;
	arn_value_assign_natural_out_of_unsigned_short_ret * arn_value_assign_natural_out_of_unsigned_short_ret_;

	/*   `expression_sub_dice` already checked not `NULL`. */
#ifndef NDEBUG
	assertion(expression_sub_dice != NULL);
#endif

	forced_assertion(expression_sub_dice->left_hand_side_natural_ != NULL);
	forced_assertion(expression_sub_dice->right_hand_side_natural_ !=
			NULL);

	r_seed_ = time(0L);  /* XXX ??? */
	srand((unsigned int) r_seed_);  /* XXX ??? */

	forced_assertion(expression_sub_dice->left_hand_side_natural_->raw_ != NULL);
	forced_assertion(expression_sub_dice->left_hand_side_natural_->raw_->value_ != NULL);
	if (expression_sub_dice->left_hand_side_natural_->raw_->value_[0] == '1') {

		rolls_ = 1;
	} else {
		forced_assertion(expression_sub_dice->left_hand_side_natural_->raw_->value_[0] ==
				'3');

		rolls_ = 3;
	}
	forced_assertion(expression_sub_dice->left_hand_side_natural_->raw_->value_[1] == '\0');
	forced_assertion(expression_sub_dice->right_hand_side_natural_->raw_ != NULL);
	forced_assertion(expression_sub_dice->right_hand_side_natural_->raw_->value_ != NULL);
	forced_assertion(expression_sub_dice->right_hand_side_natural_->raw_->value_[0] == '6');
	forced_assertion(expression_sub_dice->right_hand_side_natural_->raw_->value_[1] == '\0');

	random_ = 0;
	for (uc_ = 0; uc_ < rolls_; uc_++) {
		random_ +=
				rand()  /* XXX ??? */
				% 6
				+ 1;
	}

	returning_ = arn_value_default_constructor();
	forced_assertion(returning_ != NULL);
	/* XXX missing assertions */

	arn_value_characterize_as_natural(returning_);
	/* XXX missing assertions */

	arn_value_assign_natural_out_of_unsigned_short_ret_ =
			arn_value_assign_natural_out_of_unsigned_short(
					returning_, random_);
	forced_assertion(arn_value_assign_natural_out_of_unsigned_short_ret_ !=
			NULL);
	forced_assertion(arn_value_assign_natural_out_of_unsigned_short_ret_->status ==
		ARN_VALUE_ASSIGN_NATURAL_OUT_OF_UNSIGNED_INT_RET_STATUS_SUCCESS);

	free(arn_value_assign_natural_out_of_unsigned_short_ret_);

	return returning_;
}

/**  Transformation constructor. */
arn_value *
arn_value_out_of_rtg_expression(const rtg_expression * expression)
__attribute__((warn_unused_result))
;

arn_value *
arn_value_out_of_rtg_expression(const rtg_expression * expression)
{
	arn_value * returning_;

	forced_assertion(expression != NULL);

	if (expression->type_ == RTG_EXPRESSION_TYPE_DICE) {

		forced_assertion(expression->sub_dice_ != NULL);
		returning_ = run_dice(expression->sub_dice_);
		forced_assertion(returning_ != NULL);
		forced_assertion(returning_->name_ == NULL);

		return returning_;
	}

	forced_assertion(expression->type_ == RTG_EXPRESSION_TYPE_INVALID);

	returning_ = NULL; /* XXX */
	return returning_;
}

arn_value *
arn_value_bind_where_value(const rtg_where_value_binding * where_value_binding)
{
	arn_value * returning_;
	arn_type * expression_type_;
	arn_value * boolean_value_;
	amara_boolean * boolean_;
	arn_value * string_value_;
	amara_string * string_;
	arn_value * natural_value_;
	natural * natural_;

#ifndef NDEBUG
	assertion(where_value_binding != NULL);
	assertion(where_value_binding->value_name_ != NULL);
	assertion(where_value_binding->value_name_->value_ != NULL);
	assertion(where_value_binding->value_expression_ != NULL);
	assertion(where_value_binding->value_expression_->type_ !=
			RTG_EXPRESSION_TYPE_INVALID);
	rtg_expression_assert_validity(where_value_binding->value_expression_);
#endif

	returning_ = arn_value_default_constructor();
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	returning_->name_ = amara_string_copy_constructor(
			where_value_binding->value_name_);
#ifndef NDEBUG
	assertion(returning_->name_ != NULL);
	assertion(returning_->name_->value_ != NULL);
#endif

	expression_type_ = arn_type_out_of_rtg_expression(
			where_value_binding->value_expression_);
#ifndef NDEBUG
	assertion(expression_type_ != NULL);
	assertion(expression_type_->type_ != ARN_TYPE_TYPE_INVALID);
#endif

	if (expression_type_->type_ == ARN_TYPE_TYPE_BOOLEAN) {
		boolean_value_ = arn_value_out_of_rtg_expression(
				where_value_binding->value_expression_);
#ifndef NDEBUG
		assertion(boolean_value_->type_ = ARN_TYPE_TYPE_BOOLEAN);
#endif
		boolean_ = boolean_value_->boolean_;
		returning_->boolean_ = boolean_;
		returning_->string_ = NULL;
		returning_->natural_ = NULL;
		returning_->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_BOOLEAN;
	} else if (expression_type_->type_ == ARN_TYPE_TYPE_STRING) {
		string_value_ = arn_value_out_of_rtg_expression(
				where_value_binding->value_expression_);
#ifndef NDEBUG
		assertion(string_value_->type_ == ARN_TYPE_TYPE_STRING);
#endif
		string_ = string_value_->string_;
		returning_->boolean_ = NULL;
		returning_->string_ = string_;
		returning_->natural_ = NULL;
		returning_->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_STRING;
	} else {
		assertion(expression_type_->type_ == ARN_TYPE_TYPE_NATURAL);
		natural_value_ = arn_value_out_of_rtg_expression(
				where_value_binding->value_expression_);
#ifndef NDEBUG
		assertion(natural_value_->type_ ==
				ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);
#endif
		natural_ = natural_value_->natural_;
		returning_->boolean_ = NULL;
		returning_->string_ = NULL;
		returning_->natural_ = natural_;
		returning_->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL;
	}

	return returning_;
}

void
arn_value_characterize_as_string(arn_value * value)
{
	assertion(value != NULL);
	if (value->type_ == ARN_VALUE_TYPE_INVALID) {
		value->type_ = ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_STRING;
	} else {
		assertion(value->type_ ==
				ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);
		value->type_ = ARN_VALUE_TYPE_NAMED_UNASSIGNED_STRING;
	}
}

void
arn_value_characterize_as_boolean(arn_value * value)
{
	assertion(value != NULL);

	if (value->type_ == ARN_VALUE_TYPE_INVALID) {

		value->type_ = ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_BOOLEAN;
	} else {
		forced_assertion(value->type_ ==
				ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);

		value->type_ = ARN_VALUE_TYPE_NAMED_UNASSIGNED_BOOLEAN;
	}
}

void
arn_value_characterize_as_natural(arn_value * value)
{
	assertion(value != NULL);

	if (value->type_ == ARN_VALUE_TYPE_INVALID) {

		value->type_ = ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_NATURAL;
	} else {
		forced_assertion(value->type_ ==
				ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);

		value->type_ = ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL;
	}
}

void
arn_value_set_name(arn_value * value, const amara_string * name)
{
	assertion(value != NULL);
	assertion(value->type_ == ARN_VALUE_TYPE_INVALID); /* XXX is there a case to name an undefined value? */
	value->name_ = amara_string_copy_constructor(name);
	value->type_ = ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE;
}

void
arn_value_set_string(arn_value * value, const amara_string * string)
{
#ifndef NDEBUG
    amara_boolean equality_;
#endif

#ifndef NDEBUG
	assertion(value != NULL);
	assertion(value->type_ != ARN_VALUE_TYPE_INVALID);
	assertion(value->type_ != ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING);
	assertion(value->type_ != ARN_VALUE_TYPE_NAMED_ASSIGNED_STRING);
	assertion(value->type_ != ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);
	assertion(value->type_ != ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	if (value->type_ == ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE) {
		assertion(value->string_ == NULL);
	} else {
		if (value->type_ !=
				ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_STRING) {
			assertion(value->type_ ==
					ARN_VALUE_TYPE_NAMED_UNASSIGNED_STRING);
		}
		assertion(value->string_ == NULL);
	}
	assertion(string != NULL);
	assertion(string->value_ != NULL);
#endif
	value->string_ = amara_string_copy_constructor(string);
	forced_assertion(value->string_ != NULL);
	forced_assertion(value->string_->value_ != NULL);
#ifndef NDEBUG
    equality_ = amara_string_equality(value->string_, string);
    assertion(equality_ == AMARA_BOOLEAN_TRUE);
    equality_ = amara_string_equality(value->string_, string);
    assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif
	value->string_was_moved = AMARA_BOOLEAN_FALSE;

#ifdef DUMP_FLOW_TO_STDERR
	/*
	fprintf(stderr, "%u\n", value->type_);
	*/
#endif

	if (value->type_ == ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL) {
		forced_assertion_two(0, "TYPE ERROR????????");
		value->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_STRING;  /* XXX ??? */
	} else if (value->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_STRING) {
		value->type_ = ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING;
	} else {

#ifdef DUMP_FLOW_TO_STDERR
		/*
		fprintf(stderr, "%u\n", value->type_);
		*/
#endif

		forced_assertion(value->type_ ==
				ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);
		value->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_STRING;
	}
}

void
arn_value_set_boolean(arn_value * value, const amara_boolean boolean)
{
	forced_assertion(value != NULL);
	forced_assertion(value->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_BOOLEAN);
	forced_assertion(value->boolean_ == NULL);
	value->boolean_ =
#ifdef AMARA_USE_STD_CXX98
			(amara_boolean *)
#endif
			malloc(sizeof(amara_boolean));
	forced_assertion_two(value->boolean_ != NULL, "arn_value.c: 547\n");
	(* value->boolean_) = boolean;
	value->type_ = ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_BOOLEAN;
}

void
arn_value_set_natural(arn_value * value, const natural * natural)
{
	assertion(value != NULL);
	assertion(value->type_ != ARN_VALUE_TYPE_INVALID);
	assertion(value->type_ != ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING);
	assertion(value->type_ != ARN_VALUE_TYPE_NAMED_ASSIGNED_STRING);
	assertion(value->type_ != ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);
	assertion(value->type_ != ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	if (value->type_ == ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE) {

		forced_assertion(value->natural_ == NULL);
	} else {
		if (value->type_ !=
				ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_NATURAL) {

			forced_assertion(value->type_ ==
					ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL);
		}
		forced_assertion(value->natural_ == NULL);
	}
	assertion(natural != NULL);
	assertion(natural->raw_ != NULL);
	assertion(natural->raw_->value_ != NULL);
	value->natural_ = natural_copy_constructor(natural);
	value->natural_was_moved = AMARA_BOOLEAN_FALSE;

#ifdef DUMP_FLOW_TO_STDERR
	/*
	fprintf(stderr, "%u\n", value->type_);
	*/
#endif

	if (value->type_ == ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL) {

		value->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL;
	} else if (value->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_NATURAL) {

		value->type_ = ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL;
	} else {
		forced_assertion(value->type_ ==
				ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);

#ifdef DUMP_FLOW_TO_STDERR
		/*
		fprintf(stderr, "%u\n", value->type_);
		*/
#endif

		value->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL;
	}
}

arn_value_assign_natural_out_of_unsigned_short_ret *
arn_value_assign_natural_out_of_unsigned_short(
		arn_value * value,
		const unsigned short unsigned_short)
{
	arn_value_assign_natural_out_of_unsigned_short_ret * ret_;
	natural * natural_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(arn_value_assign_natural_out_of_unsigned_short_ret *)
#endif
			malloc(sizeof(arn_value_assign_natural_out_of_unsigned_short_ret));
	forced_assertion(ret_ != NULL);

	ret_->status = ARN_VALUE_ASSIGN_NATURAL_OUT_OF_UNSIGNED_INT_RET_STATUS_INVALID;
	assertion(value->type_ != ARN_VALUE_TYPE_INVALID);
	assertion(value->type_ != ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(value->type_ !=
			ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);
	assertion(value->type_ != ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	if (value->type_ != ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL) {
		assertion(value->type_ ==
				ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_NATURAL);
	}
	if (value->type_ == ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL) {
		assertion(value->name_ != NULL);
	}
	assertion(value->natural_ == NULL);

	natural_ = natural_default_constructor();
	forced_assertion(natural_ != NULL);

	natural_copy_from_unsigned_short(natural_, unsigned_short);

	arn_value_set_natural(value, natural_);
	forced_assertion(value->natural_ != NULL);

	natural_destructor(natural_);

	ret_->status = ARN_VALUE_ASSIGN_NATURAL_OUT_OF_UNSIGNED_INT_RET_STATUS_SUCCESS;

	return ret_;
}
