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
 * src/arn/arn_values_simple_list.c: Amara application run time values
 * simple list.
 */

#include "arn_values_simple_list.h"

arn_values_simple_list *
arn_values_simple_list_default_constructor(void)
{
	arn_values_simple_list * values;
	values = malloc(sizeof(arn_values_simple_list));
	values->first = NULL;
	values->next = NULL;
	return values;
}

arn_values_simple_list *
arn_values_simple_list_push_front(
		arn_values_simple_list * values, const arn_value * value)
{
	arn_values_simple_list * new_list_node_;
	assertion(values != NULL);
	assertion(value != NULL);
	if (values->first == NULL) {
		assertion(values->next == NULL);
		values->first = arn_value_copy_constructor(value);
		return values;
	}
	new_list_node_ = malloc(sizeof(arn_values_simple_list));
	new_list_node_->first = arn_value_copy_constructor(value);
	new_list_node_->next = values;
	return new_list_node_;
}

arn_value *
arn_values_simple_list_find_value_by_name_inner(
		const arn_values_simple_list * values,
		const amara_string * value_name)
__attribute__((warn_unused_result))
;

arn_value *
arn_values_simple_list_find_value_by_name_inner(
		const arn_values_simple_list * values,
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
	return arn_values_simple_list_find_value_by_name_inner(
			values->next, value_name);
}

arn_value *
arn_values_simple_list_find_value_by_name(
		const arn_values_simple_list * values,
		const amara_string * value_name)
{
	assertion(values != NULL);
	assertion(value_name != NULL);
	assertion(value_name->value_ != NULL);
	if (values->first == NULL) {
		assertion(values->next == NULL);
		return NULL;
	}
	return arn_values_simple_list_find_value_by_name_inner(
			values, value_name);
}

arn_values_simple_list *
arn_values_simple_list_assign_natural_out_of_unsigned_int(
		arn_values_simple_list * values,
		const amara_string * value_name,
		const unsigned int unsigned_int)
{
	arn_values_simple_list * returning_;
	arn_value * value_;
	natural * natural_;
	/*
	assert_value_is_known(values, value_name); *//* XXX maybe double checking... *//*
	*/
	value_ = arn_values_simple_list_find_value_by_name(
			values, value_name);
	natural_ = natural_default_constructor();
	natural_copy_from_unsigned_int(natural_, unsigned_int);
	if (value_ == NULL) {
		value_ = arn_value_default_constructor();
		assertion(value_ != NULL);
		assertion(value_->type_ == ARN_VALUE_TYPE_INVALID);
		arn_value_set_name(value_, value_name);
		arn_value_set_natural(value_, natural_);
		returning_ = arn_values_simple_list_push_front(
				values, value_);
		/*
		value_ = arn_values_simple_list_find_value_by_name(
				returning_, value_name);
		assertion(value_ != NULL);
		*/
		return returning_;
	}
	/*
	arn_value
	else {
	arn_value_assign_natural_out_of_unsigned_int(
			value_, unsigned_int_natural);
	}
	return la nueva si ha cambiado, o la vieja si no ha cambiado? push frontal?
	*/
	return NULL;
}
