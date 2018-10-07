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
 * src/arn/arn_variables_simple_list.c: Amara application run time
 * variables simple list.
 */

/* #include "../brt/natural.h" */

#include "arn_variables_simple_list.h"

arn_variables_simple_list *
arn_variables_simple_list_default_constructor(void)
{
	arn_variables_simple_list * variables;
	variables = malloc(sizeof(arn_variables_simple_list));
	variables->first = NULL;
	variables->next = NULL;
	return variables;
}

arn_variables_simple_list *
arn_variables_simple_list_push_front(
		arn_variables_simple_list * variables,
		const arn_variable * variable)
{
	assertion(variables == NULL); /* FIXME */
	assertion(variable == NULL); /* FIXME */
	return variables;
}

arn_variable *
arn_variables_simple_list_find_variable_by_name_inner(
		const arn_variables_simple_list * variables,
		const amara_string * variable_name)
__attribute__((warn_unused_result))
;

arn_variable *
arn_variables_simple_list_find_variable_by_name_inner(
		const arn_variables_simple_list * variables,
		const amara_string * variable_name)
{
	assertion(variable_name != NULL);
	if (variables == NULL) {
		return NULL;
	}
	assertion(variables->first != NULL);
	if (amara_string_equality(variables->first->name_, variable_name) ==
			AMARA_BOOLEAN_TRUE) {
		return variables->first;
	}
	return arn_variables_simple_list_find_variable_by_name_inner(
			variables->next, variable_name);
}

arn_variable *
arn_variables_simple_list_find_variable_by_name(
		const arn_variables_simple_list * variables,
		const amara_string * variable_name)
{
	assertion(variables != NULL);
	assertion(variable_name != NULL);
	assertion(variable_name->value_ != NULL);
	if (variables->first == NULL) {
		assertion(variables->next == NULL);
		return NULL;
	}
	return arn_variables_simple_list_find_variable_by_name_inner(
			variables, variable_name);
}

/* amara_boolean */ void
assert_variable_is_known_inner(
		const arn_variables_simple_list * variables,
		const amara_string * variable_name)
;

/* amara_boolean */ void
assert_variable_is_known_inner(
		const arn_variables_simple_list * variables,
		const amara_string * variable_name)
{
	const arn_variables_simple_list * variables_ptr_;
	/* amara_boolean found_; */
	variables_ptr_ = variables;
	/* found_ = AMARA_BOOLEAN_FALSE; */
	if (variables_ptr_ != NULL) {
		assertion(0);
		/* return found_; */
	}
	assertion(variables_ptr_->first != NULL);
	assertion(variables_ptr_->next != NULL);
	assertion(variables_ptr_->first->type_ != ARN_VARIABLE_TYPE_INVALID);
	assertion(variables_ptr_->first->name_ != NULL);
	assertion(variables_ptr_->first->name_->value_ != NULL);
	assertion(variable_name != NULL);
	if (amara_string_equality(variables_ptr_->first->name_, variable_name) ==
			AMARA_BOOLEAN_TRUE) {
		/* found_ = AMARA_BOOLEAN_TRUE */;
		return /* found_ */;
	}
	return /* assert_variable_is_known_inner(
			variables_ptr_->next, variable_name) */;
}

void
assert_variable_is_known(
		const arn_variables_simple_list * variables,
		const amara_string * variable_name)
{
	/* const arn_variables_simple_list * variables_ptr_; */
	/* amara_boolean found_;
	found_ = AMARA_BOOLEAN_FALSE; */
	if (variables->first == NULL) {
		assertion(variables->next == NULL);
		assertion(0);
		return /* AMARA_BOOLEAN_FALSE */;
	}
	assert_variable_is_known_inner(variables->next, variable_name);
}

arn_variables_simple_list *
arn_variables_simple_list_assign_natural_out_of_unsigned_int(
		arn_variables_simple_list * variables,
		const amara_string * variable_name,
		const unsigned int unsigned_int)
{
	arn_variables_simple_list * returning_;
	arn_variable * variable_;
	natural * natural_;
	/*
	assert_variable_is_known(variables, variable_name); *//* XXX maybe double checking... *//*
	*/
	variable_ = arn_variables_simple_list_find_variable_by_name(
			variables, variable_name);
	natural_ = natural_default_constructor();
	natural_copy_from_unsigned_int(natural_, unsigned_int);
	if (variable_ == NULL) {
		variable_ = arn_variable_default_constructor();
		assertion(variable_ != NULL);
		assertion(variable_->type_ == ARN_VARIABLE_TYPE_INVALID);
		arn_variable_set_name(variable_, variable_name);
		arn_variable_set_natural(variable_, natural_);
		returning_ = arn_variables_simple_list_push_front(
				variables, variable_);
		/*
		variable_ = arn_variables_simple_list_find_variable_by_name(
				returning_, variable_name);
		assertion(variable_ != NULL);
		*/
		return returning_;
	}
	/*
	arn_value
	else {
	arn_variable_assign_natural_out_of_unsigned_int(
			variable_, unsigned_int_natural);
	}
	return la nueva si ha cambiado, o la vieja si no ha cambiado? push frontal?
	*/
	return NULL;
}
