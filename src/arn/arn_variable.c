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
 * src/arn/arn_variable.c: Amara application run time variable.
 */

#include "../brt/natural.h"

#include "arn_variable.h"

arn_variable *
arn_variable_default_constructor(void)
{
	arn_variable * variable_;
	variable_ =
#ifdef AMARA_USE_STD_CXX98
			(arn_variable *)
#endif
			malloc(sizeof(arn_variable));
	forced_assertion_two(variable_ != NULL, "arn_variable.c: 28\n");
	variable_->type_ = ARN_VARIABLE_TYPE_INVALID;
	variable_->name_ = NULL;
	variable_->natural_ = NULL;
	variable_->natural_was_moved_ = AMARA_BOOLEAN_FALSE;
	return variable_;
}

void
arn_variable_destructor(arn_variable * variable)
{
	assertion(variable != NULL);
	assertion(variable->type_ == ARN_VARIABLE_TYPE_INVALID); /* XXX */
	assertion(variable->name_ == NULL);
	assertion(variable->natural_ == NULL);
	free(variable);
}

/*

void
arn_variable_set_name(arn_variable * variable, const amara_string * name)
{
	assertion(variable == NULL); *//* FIXME */
/*	assertion(name == NULL); *//* FIXME */
/*}

void
arn_variable_set_natural(arn_variable * variable, const natural * natural)
{
	assertion(variable == NULL); *//* FIXME */
/*	assertion(natural == NULL); *//* FIXME */
/*}

void
arn_variable_assign_natural_out_of_unsigned_int(
		arn_variable * variable,
		const unsigned int unsigned_int)
{
	assertion(variable->type_ != ARN_VARIABLE_TYPE_ASSIGNED_NATURAL);
	assertion(variable->type_ != ARN_VARIABLE_TYPE_UNDEFINED);
	assertion(variable->type_ == ARN_VARIABLE_TYPE_UNASSIGNED_NATURAL);
	assertion(variable->name_ != NULL);
*/
	/*
	assertion(variable->raw_natural_ == NULL);
	*/
/*
	assertion(variable->natural_ == NULL);
*/
	/*
	variable->raw_natural_ =
			copy_unsigned_int_into_raw_natural(unsigned_int);
	*/
/*
	variable->natural_ = natural_default_constructor();
	natural_copy_unsigned_int_into_natural(
			variable->natural_, unsigned_int);
}
*/
