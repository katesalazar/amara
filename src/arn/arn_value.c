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

#include <stdio.h>

#include "../brt/natural.h"

#include "arn_value.h"

arn_value *
arn_value_default_constructor(void)
{
	arn_value * ret_;

	ret_ = malloc(sizeof(arn_value));

	ret_->type_ = ARN_VALUE_TYPE_INVALID;
	ret_->name_ = NULL;
	ret_->string_ = NULL;
	ret_->string_was_moved_ = AMARA_BOOLEAN_FALSE;
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
				fprintf(stderr, "%u\n", value->type_);
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
				fprintf(stderr, "%u\n", value->type_);
				assertion(value->type_ ==
						ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_STRING);
			}
			}
		}
		if (value->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL ||
				value->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL) {
			ret_->string_ = NULL;
			ret_->string_was_moved_ = AMARA_BOOLEAN_FALSE;
			/* XXX */
			ret_->natural_ = natural_copy_constructor(
					value->natural_);
			/* XXX */
			ret_->natural_was_moved_ = AMARA_BOOLEAN_FALSE;
		} else {
			fprintf(stderr, "%u\n", value->type_);
			assertion(value->type_ ==
					ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING);
			ret_->string_ = amara_string_copy_constructor(
					value->string_);
			ret_->string_was_moved_ = AMARA_BOOLEAN_FALSE;
			ret_->natural_ = NULL;
			ret_->natural_was_moved_ = AMARA_BOOLEAN_FALSE;
		}
	/* } else if (value->type_ == ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_STRING) { */
	} else {
		ret_->string_ = NULL; /* XXX will obviously change in the future. */
		ret_->string_was_moved_ = AMARA_BOOLEAN_FALSE; /* XXX will obviously change in the future. */
		ret_->natural_ = NULL;
		ret_->natural_was_moved_ = AMARA_BOOLEAN_FALSE;
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
		fprintf(stderr, "%u\n", value->type_);
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

void
arn_value_destructor(arn_value * value)
{
	assertion(value != NULL);
	if (value->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING) {
		assertion(value->name_ == NULL);
		assertion(value->string_ != NULL);
		assertion(value->string_->value_ != NULL);
		amara_string_destructor(value->string_);
		assertion(value->natural_ == NULL);
	} else if (value->type_ == ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL) {
		assertion(value->name_ != NULL);
		assertion(value->name_->value_ != NULL);
		amara_string_destructor(value->name_);
		assertion(value->string_ == NULL);
		assertion(value->natural_ == NULL);
	} else if (value->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL) {
		assertion(value->name_ != NULL);
		assertion(value->name_->value_ != NULL);
		amara_string_destructor(value->name_);
		assertion(value->string_ == NULL);
		assertion(value->natural_ != NULL);
		assertion(value->natural_->raw_ != NULL);
		assertion(value->natural_->raw_->value_ != NULL);
		assertion(value->natural_was_moved_ == AMARA_BOOLEAN_FALSE);
		natural_destructor(value->natural_);
	} else if (value->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL) {
		assertion(value->name_ == NULL);
		assertion(value->string_ == NULL);
		assertion(value->natural_ != NULL);
		assertion(value->natural_->raw_ != NULL);
		assertion(value->natural_->raw_->value_ != NULL);
		assertion(value->natural_was_moved_ == AMARA_BOOLEAN_FALSE);
		natural_destructor(value->natural_);
	} else if (value->type_ ==
			ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE) {
		assertion(value->name_ != NULL);
		assertion(value->name_->value_ != NULL);
		amara_string_destructor(value->name_);
		assertion(value->string_ == NULL);
		assertion(value->natural_ == NULL);
	} else {
		fprintf(stderr, "%u\n", value->type_);
		assertion(value->type_ == ARN_VALUE_TYPE_INVALID);
		assertion(value->name_ == NULL);
		assertion(value->string_ == NULL);
		assertion(value->natural_ == NULL);
	}
	free(value);
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
arn_value_characterize_as_natural(arn_value * value)
{
	assertion(value != NULL);
	if (value->type_ == ARN_VALUE_TYPE_INVALID) {
		value->type_ = ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_NATURAL;
	} else {
		assertion(value->type_ ==
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
	value->string_ = amara_string_copy_constructor(string);
	value->string_was_moved_ = AMARA_BOOLEAN_FALSE;
	fprintf(stderr, "%u\n", value->type_);
	if (value->type_ == ARN_VALUE_TYPE_NAMED_UNASSIGNED_STRING) {
		value->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL;
	} else if (value->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_STRING) {
		value->type_ = ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING;
	} else {
		fprintf(stderr, "%u\n", value->type_);
		assertion(value->type_ ==
				ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);
		value->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_STRING;
	}
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
		assertion(value->natural_ == NULL);
	} else {
		if (value->type_ !=
				ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_NATURAL) {
			assertion(value->type_ ==
					ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL);
		}
		assertion(value->natural_ == NULL);
	}
	assertion(natural != NULL);
	assertion(natural->raw_ != NULL);
	assertion(natural->raw_->value_ != NULL);
	value->natural_ = natural_copy_constructor(natural);
	value->natural_was_moved_ = AMARA_BOOLEAN_FALSE;
	fprintf(stderr, "%u\n", value->type_);
	if (value->type_ == ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL) {
		value->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL;
	} else if (value->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_NATURAL) {
		value->type_ = ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL;
	} else {
		fprintf(stderr, "%u\n", value->type_);
		assertion(value->type_ ==
				ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);
		value->type_ = ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL;
	}
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

	natural_copy_from_unsigned_int(natural_, unsigned_int);

	arn_value_set_natural(value, natural_);

	ret_->status = ARN_VALUE_ASSIGN_NATURAL_OUT_OF_UNSIGNED_INT_RET_STATUS_SUCCESS;

	return ret_;
}
