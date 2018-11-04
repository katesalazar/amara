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

void
arn_values_simple_list_destructor_inner(arn_values_simple_list * values)
;

void
arn_values_simple_list_destructor_inner(arn_values_simple_list * values)
{
	assertion(values != NULL);
	assertion(values->first != NULL);
	arn_value_destructor(values->first);
	if (values->next != NULL) {
		arn_values_simple_list_destructor_inner(values->next);
	}
	free(values);
}

void
arn_values_simple_list_destructor(arn_values_simple_list * values)
{
	assertion(values != NULL);
	if (values->first == NULL) {
		assertion(values->next == NULL);
		free(values);
	} else{
		arn_values_simple_list_destructor_inner(values);
	}
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

arn_values_simple_list *
arn_values_simple_list_push_front_as_references_all_elements_of_arn_values_fixed_list_inner(
		arn_values_simple_list * destination,
		const arn_values_fixed_list * source)
__attribute__((warn_unused_result))
;

arn_values_simple_list *
arn_values_simple_list_push_front_as_references_all_elements_of_arn_values_fixed_list_inner(
		arn_values_simple_list * destination,
		const arn_values_fixed_list * source)
{
	arn_values_simple_list * returning_;

	assertion(destination != NULL);

	if (source == NULL) {
		return destination;
	}

	returning_ = malloc(sizeof(arn_values_simple_list));

	returning_->first = source->first;
	returning_->next =
			arn_values_simple_list_push_front_as_references_all_elements_of_arn_values_fixed_list_inner(
					destination, source->next);

	return returning_;
}

arn_values_simple_list *
arn_values_simple_list_push_front_as_references_all_elements_of_arn_values_fixed_list(
		arn_values_simple_list * destination,
		const arn_values_fixed_list * source)
{
	/* arn_values_simple_list * returning_; */

	assertion(destination != NULL);
	assertion(source != NULL);

	return arn_values_simple_list_push_front_as_references_all_elements_of_arn_values_fixed_list_inner(
			destination, source);
}

arn_value *
arn_values_simple_list_find_value_by_name_return_reference_inner(
		const arn_values_simple_list * values,
		const amara_string * value_name)
__attribute__((warn_unused_result))
;

arn_value *
arn_values_simple_list_find_value_by_name_return_reference_inner(
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
	return arn_values_simple_list_find_value_by_name_return_reference_inner(
			values->next, value_name);
}

arn_value *
arn_values_simple_list_find_value_by_name_return_reference(
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
	return arn_values_simple_list_find_value_by_name_return_reference_inner(
			values, value_name);
}

arn_values_simple_list *
arn_values_simple_list_assign_natural_out_of_unsigned_short(
		arn_values_simple_list * values,
		const amara_string * value_name,
		const unsigned short unsigned_short)
{
	arn_values_simple_list * returning_;
	arn_value * value_reference_;
	natural * natural_;
	/*
	assert_value_is_known(values, value_name); *//* XXX maybe double checking... *//*
	*/
	value_reference_ =
			arn_values_simple_list_find_value_by_name_return_reference(
					values, value_name);
	natural_ = natural_default_constructor();
	natural_copy_from_unsigned_short(natural_, unsigned_short);
	if (value_reference_ == NULL) {
		value_reference_ = arn_value_default_constructor();
		assertion(value_reference_ != NULL);
		assertion(value_reference_->type_ == ARN_VALUE_TYPE_INVALID);
		arn_value_set_name(value_reference_, value_name);
		arn_value_set_natural(value_reference_, natural_);
		returning_ = arn_values_simple_list_push_front(
				values, value_reference_);
		/*
		value_ = arn_values_simple_list_find_value_by_name(
				returning_, value_name);
		assertion(value_ != NULL);
		*/
		natural_destructor(natural_);
		return returning_;
	}
	assertion(value_reference_->type_ ==
			ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL);
	arn_value_set_natural(value_reference_, natural_);
	returning_ = values;
	/*
	arn_value
	else {
	arn_value_assign_natural_out_of_unsigned_short(
			value_, unsigned_short_natural);
	}
	return la nueva si ha cambiado, o la vieja si no ha cambiado? push frontal?
	*/
	natural_destructor(natural_);
	return returning_;
}
