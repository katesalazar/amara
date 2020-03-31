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
 * src/arn/arn_values_simple_list.c: Amara application run time values
 * simple list.
 */

#include "arn_values_simple_list.h"

arn_values_simple_list *
arn_values_simple_list_default_constructor(void)
{
	arn_values_simple_list * values_;

	values_ =
#ifdef AMARA_USE_STD_CXX98
			(arn_values_simple_list *)
#endif
			malloc(sizeof(arn_values_simple_list));
	forced_assertion(values_ != NULL);
	values_->first = NULL;
	values_->next = NULL;

	return values_;
}

arn_values_simple_list *
arn_values_simple_list_copy_constructor(
		const arn_values_simple_list * list)
{
	arn_values_simple_list * returning_;

	forced_assertion(list != NULL);

	forced_assertion(list->first == NULL);  /* XXX */

	forced_assertion(list->next == NULL);

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(arn_values_simple_list *)
#endif
			malloc(sizeof(arn_values_simple_list));
	forced_assertion(returning_ != NULL);

	returning_->first = NULL;

	returning_->next = NULL;

	return returning_;
}

arn_values_simple_list *
arn_values_simple_list_out_of_arn_values_fixed_list_inner(
		const arn_values_fixed_list * list)
__attribute__((warn_unused_result))
;

arn_values_simple_list *
arn_values_simple_list_out_of_arn_values_fixed_list_inner(
		const arn_values_fixed_list * list)
{
	arn_values_simple_list * returning_;

	if (list == NULL) {

		return NULL;
	}

#ifndef NDEBUG
	assertion(list->first != NULL);
#endif

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(arn_values_simple_list *)
#endif
			malloc(sizeof(arn_values_simple_list));
	forced_assertion(returning_ != NULL);

	returning_->first = arn_value_copy_constructor(list->first);
	forced_assertion(returning_->first != NULL);

	returning_->next =
			arn_values_simple_list_out_of_arn_values_fixed_list_inner(
					list->next);

#ifndef NDEBUG
	if (list->next != NULL) {

		assertion(returning_->next != NULL);
	}
#endif

	return returning_;
}

arn_values_simple_list *
arn_values_simple_list_out_of_arn_values_fixed_list(
		const arn_values_fixed_list * list)
{
	arn_values_simple_list * returning_;

	forced_assertion(list != NULL);

	if (list->first == NULL) {

#ifndef NDEBUG
		assertion(list->next == NULL);
#endif
		returning_ =
#ifdef AMARA_USE_STD_CXX98
				(arn_values_simple_list *)
#endif
				malloc(sizeof(arn_values_simple_list));
		forced_assertion(returning_ != NULL);
		returning_->first = NULL;
		returning_->next = NULL;
		return returning_;
	}

	return arn_values_simple_list_out_of_arn_values_fixed_list_inner(list);
}

void
arn_values_simple_list_destructor_inner(arn_values_simple_list * values)
;

void
arn_values_simple_list_destructor_inner(arn_values_simple_list * values)
{
	forced_assertion(values != NULL);
#ifndef NDEBUG
	assertion(values->first != NULL);
#endif
	arn_value_destructor(values->first);
	if (values->next != NULL) {
		arn_values_simple_list_destructor_inner(values->next);
	}
	free(values);
}

void
arn_values_simple_list_destructor(arn_values_simple_list * values)
{
	forced_assertion(values != NULL);
	if (values->first == NULL) {
#ifndef NDEBUG
		forced_assertion(values->next == NULL);
#endif
		free(values);
	} else {
		arn_values_simple_list_destructor_inner(values);
	}
}

void
arn_values_simple_list_shallow_destructor_inner(
		arn_values_simple_list * values)
;

void
arn_values_simple_list_shallow_destructor_inner(
		arn_values_simple_list * values)
{
	if (values != NULL) {
#ifndef NDEBUG
		assertion(values->first != NULL);
#endif
		arn_values_simple_list_shallow_destructor_inner(values->next);
		free(values);
	}
}

void
arn_values_simple_list_shallow_destructor(arn_values_simple_list * values)
{
	forced_assertion(values != NULL);
	if (values->first == NULL) {
#ifndef NDEBUG
		forced_assertion(values->next == NULL);
#endif
		free(values);
	} else {
		arn_values_simple_list_shallow_destructor_inner(values);
	}
}

void
arn_values_simple_list_deep_destructor(arn_values_simple_list * values)
{
	arn_values_simple_list_destructor(values);
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
	new_list_node_ =
#ifdef AMARA_USE_STD_CXX98
			(arn_values_simple_list *)
#endif
			malloc(sizeof(arn_values_simple_list));
	forced_assertion_two(new_list_node_ != NULL,
			"arn_values_simple_list.c: 180\n");
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
	arn_values_simple_list * nested_call_returned_;

	assertion(destination != NULL);

	if (source == NULL) {

		return destination;
	}

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(arn_values_simple_list *)
#endif
			malloc(sizeof(arn_values_simple_list));
	forced_assertion_two(returning_ != NULL,
			"arn_values_simple_list.c: 217\n");

	returning_->first = source->first;

	nested_call_returned_ =
			arn_values_simple_list_push_front_as_references_all_elements_of_arn_values_fixed_list_inner(
					destination, source->next);
	forced_assertion(nested_call_returned_ != NULL);

	if (nested_call_returned_->first == NULL) {

#ifndef NDEBUG
		assertion(nested_call_returned_->next == NULL);
#endif
		returning_->next = NULL;
	} else {

		returning_->next = nested_call_returned_;
	}

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

	if (source->first == NULL) {

		assertion(source->next == NULL);

		return destination;
		/*
		return arn_values_simple_list_copy_constructor(destination);
		*/
	}

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
