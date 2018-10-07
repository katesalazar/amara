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
 * src/arn/arn_value.c: Amara application run time value. A value is
 * basically a constant.
 */

#include "../brt/natural.h"

#include "arn_value.h"

arn_value *
arn_value_default_constructor(void)
{
	arn_value * ret_;
	ret_ = malloc(sizeof(arn_value));
	ret_->type_ = ARN_VALUE_TYPE_INVALID;
	ret_->name_ = NULL;
	ret_->natural_ = NULL;
	ret_->natural_was_moved_ = AMARA_BOOLEAN_FALSE;
	return ret_;
}

arn_value *
arn_value_copy_constructor(const arn_value * value)
{
	arn_value * ret_;
	assertion(value->type_ != ARN_VALUE_TYPE_INVALID);
	ret_ = malloc(sizeof(arn_value));
	ret_->type_ = ARN_VALUE_TYPE_INVALID;
	assertion(value->name_ != NULL); /* XXX consider that a variable without name is subject to be copied? */
	ret_->name_ = amara_string_copy_constructor(value->name_);
	assertion(value->type_ == ARN_VALUE_TYPE_ASSIGNED_NATURAL); /* XXX obvious one */
	ret_->natural_ = natural_copy_constructor(value->natural_);
	ret_->natural_was_moved_ = AMARA_BOOLEAN_FALSE;
	ret_->type_ = ARN_VALUE_TYPE_ASSIGNED_NATURAL;
	return ret_;
}

void
arn_value_set_name(arn_value * value, const amara_string * name)
{
	assertion(value != NULL);
	assertion(value->type_ == ARN_VALUE_TYPE_INVALID); /* XXX is there a case to name an undefined value? */
	value->name_ = amara_string_copy_constructor(name);
	value->type_ = ARN_VALUE_TYPE_UNDEFINED;
}

void
arn_value_set_natural(arn_value * value, const natural * natural)
{
	assertion(value != NULL);
	assertion(value->type_ != ARN_VALUE_TYPE_INVALID);
	assertion(value->type_ != ARN_VALUE_TYPE_ASSIGNED_NATURAL);
	if (value->type_ == ARN_VALUE_TYPE_UNDEFINED) {
		assertion(value->natural_ == NULL);
	} else {
		assertion(value->type_ == ARN_VALUE_TYPE_UNASSIGNED_NATURAL);
		assertion(value->natural_ == NULL);
	}
	value->natural_ = natural_copy_constructor(natural);
	value->natural_was_moved_ = AMARA_BOOLEAN_FALSE;
	value->type_ = ARN_VALUE_TYPE_ASSIGNED_NATURAL;
}

arn_value_assign_natural_out_of_unsigned_int_ret *
arn_value_assign_natural_out_of_unsigned_int(
		arn_value * value,
		const unsigned int unsigned_int)
{
	arn_value_assign_natural_out_of_unsigned_int_ret * ret_;
	natural * natural_;
	ret_ = malloc(sizeof(
			arn_value_assign_natural_out_of_unsigned_int_ret));
	ret_->status = ARN_VALUE_ASSIGN_NATURAL_OUT_OF_UNSIGNED_INT_RET_STATUS_INVALID;
	assertion(value->type_ != ARN_VALUE_TYPE_INVALID);
	assertion(value->type_ != ARN_VALUE_TYPE_ASSIGNED_NATURAL);
	assertion(value->type_ != ARN_VALUE_TYPE_UNDEFINED);
	assertion(value->type_ != ARN_VALUE_TYPE_ASSIGNED_NATURAL);
	assertion(value->type_ == ARN_VALUE_TYPE_UNASSIGNED_NATURAL);
	assertion(value->name_ != NULL);
	assertion(value->natural_ == NULL);
	natural_ = malloc(sizeof(natural));
	natural_copy_from_unsigned_int(natural_, unsigned_int);
	arn_value_set_natural(value, natural_);
	ret_->status = ARN_VALUE_ASSIGN_NATURAL_OUT_OF_UNSIGNED_INT_RET_STATUS_SUCCESS;
	return ret_;
}
