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
 * src/arn/arn_values_fixed_list.c: Amara application run time values
 * fixed list. A fixed list is like a simple list, but the pointer to it
 * stays constant over time from construction until destruction.
 */

#include "arn_values_fixed_list.h"

arn_values_fixed_list *
arn_values_fixed_list_default_constructor(void)
{
	arn_values_fixed_list * values;
	values = malloc(sizeof(arn_values_fixed_list));
	values->first = NULL;
	values->next = NULL;
	return values;
}

void
arn_values_fixed_list_destructor(arn_values_fixed_list * values)
{
	arn_values_fixed_list * ptr_;
	arn_values_fixed_list * ptr_delete_;

	assertion(values != NULL);
	if (values->first == NULL) {
		assertion(values->next == NULL);
		free(values);
	} else {
		ptr_ = values;
		while (ptr_ != NULL) {
			assertion(ptr_->first != NULL);
			arn_value_destructor(ptr_->first);
			ptr_delete_ = ptr_;
			ptr_ = ptr_->next;
			free(ptr_delete_);
		}
	}
}

void
arn_values_fixed_list_push_front(
		arn_values_fixed_list * values, const arn_value * value)
{
	arn_values_fixed_list * new_list_node_;
	assertion(values != NULL);
	assertion(value != NULL);
	if (values->first == NULL) {
		assertion(values->next == NULL);
		values->first = arn_value_copy_constructor(value);
		return;
	}
	new_list_node_ = malloc(sizeof(arn_values_fixed_list));
	new_list_node_->first = values->first;
	new_list_node_->next = values->next;
	values->first = arn_value_copy_constructor(value);
	values->next = new_list_node_;
}

arn_value *
arn_values_fixed_list_find_value_by_name_inner(
		const arn_values_fixed_list * values,
		const amara_string * value_name)
__attribute__((warn_unused_result))
;

arn_value *
arn_values_fixed_list_find_value_by_name_inner(
		const arn_values_fixed_list * values,
		const amara_string * value_name)
{
	assertion(value_name != NULL);
	if (values == NULL) {
		return NULL;
	}
	assertion(values->first != NULL);
	if (amara_string_equality(values->first->name_, value_name) ==
			AMARA_BOOLEAN_TRUE) {
		return values->first;
	}
	return arn_values_fixed_list_find_value_by_name_inner(
			values->next, value_name);
}

arn_value *
arn_values_fixed_list_find_value_by_name(
		const arn_values_fixed_list * values,
		const amara_string * value_name)
{
	assertion(values != NULL);
	assertion(value_name != NULL);
	assertion(value_name->value_ != NULL);
	if (values->first == NULL) {
		assertion(values->next == NULL);
		return NULL;
	}
	return arn_values_fixed_list_find_value_by_name_inner(
			values, value_name);
}

void
arn_values_fixed_list_assign_natural_out_of_unsigned_int(
		arn_values_fixed_list * values,
		const amara_string * value_name,
		const unsigned int unsigned_int)
{
	arn_value * value_;
	natural * natural_;
	assertion(values != NULL);
	assertion(value_name != NULL);
	/*
	assert_value_is_known(values, value_name); *//* XXX maybe double checking... *//*
	*/
	value_ = arn_values_fixed_list_find_value_by_name(
			values, value_name);
	natural_ = natural_default_constructor();
	natural_copy_from_unsigned_int(natural_, unsigned_int);
	if (value_ == NULL) {
		value_ = arn_value_default_constructor();
		assertion(value_ != NULL);
		assertion(value_->type_ == ARN_VALUE_TYPE_INVALID);
		arn_value_set_name(value_, value_name);
		arn_value_set_natural(value_, natural_);
		arn_values_fixed_list_push_front(values, value_);
		/*
		value_ = arn_values_fixed_list_find_value_by_name(
				returning_, value_name);
		assertion(value_ != NULL);
		*/
		return;
	}
	/*
	arn_value
	else {
	arn_value_assign_natural_out_of_unsigned_int(
			value_, unsigned_int_natural);
	}
	return la nueva si ha cambiado, o la vieja si no ha cambiado? push frontal?
	*/
	assertion(0 /* XXX ??? Take care, maybe the value exists as declared (typed or not) but the value is yet to be assigned? */);
	return;
}
