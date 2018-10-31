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
 * src/arn/arn_values_simple_list.h: Amara application run time values
 * simple list.
 */

#ifndef __AMARA__APPLICATIONS_RUNNER__VALUES_SIMPLE_LIST__H__
#define __AMARA__APPLICATIONS_RUNNER__VALUES_SIMPLE_LIST__H__

#include "arn_value.h"

typedef struct arn_values_simple_list {
	arn_value * first;
	struct arn_values_simple_list * next;
} arn_values_simple_list
;

arn_values_simple_list *
arn_values_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

void
arn_values_simple_list_destructor(arn_values_simple_list * values)
;

arn_values_simple_list *
arn_values_simple_list_push_front(
		arn_values_simple_list * values, const arn_value * value)
__attribute__((warn_unused_result))
;

arn_value *
arn_values_simple_list_find_value_by_name_return_reference(
		const arn_values_simple_list * values,
		const amara_string * value_name)
__attribute__((warn_unused_result))
;

void
assert_value_is_known(
		const arn_values_simple_list * values,
		const amara_string * value_name)
;

/**  Pre: the value is not assigned (type not
 * `ARN_VALUE_TYPE_ASSIGNED_NATURAL`).
 *   Pre: TODO Is the value known to be added to the list, or not? */
arn_values_simple_list *
arn_values_simple_list_assign_natural_out_of_unsigned_int(
		arn_values_simple_list * values,
		const amara_string * value_name,
		const unsigned int unsigned_int)
__attribute__((warn_unused_result))
;

#endif
