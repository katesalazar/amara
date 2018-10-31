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
 * src/arn/arn_variables_simple_list.h: Amara application run time
 * variables simple list.
 */

#ifndef __AMARA__APPLICATIONS_RUNNER__VARIABLES_SIMPLE_LIST__H__
#define __AMARA__APPLICATIONS_RUNNER__VARIABLES_SIMPLE_LIST__H__

#include "arn_variable.h"

typedef struct arn_variables_simple_list {
	arn_variable * first;
	struct arn_variables_simple_list * next;
} arn_variables_simple_list
;

arn_variables_simple_list *
arn_variables_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

void
arn_variables_simple_list_destructor(arn_variables_simple_list * variables)
;

/*
arn_variables_simple_list *
arn_variables_simple_list_push_front(
		arn_variables_simple_list * variables,
		const arn_variable * variable)
__attribute__((warn_unused_result))
;

arn_variable *
arn_variables_simple_list_find_variable_by_name(
		const arn_variables_simple_list * variables,
		const amara_string * variable_name)
__attribute__((warn_unused_result))
;

void
assert_variable_is_known(
		const arn_variables_simple_list * variables,
		const amara_string * variable_name)
;
*/
/**  Pre: the variable is not assigned (type not
 * `ARN_VARIABLE_TYPE_ASSIGNED_NATURAL`).
 *   Pre: TODO Is the variable known to be added to the list, or not? */
/*arn_variables_simple_list *
arn_variables_simple_list_assign_natural_out_of_unsigned_int(
		arn_variables_simple_list * variables,
		const amara_string * variable_name,
		const unsigned int unsigned_int)
__attribute__((warn_unused_result))
;*/

#endif
