/*
 * Copyright 2019 Mercedes Catherine Salazar
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
 * src/cmn/amara_strings_simple_list.h: Simple list of strings.
 */

#ifndef __AMARA__COMMON__AMARA_STRINGS_SIMPLE_LIST__H__
#define __AMARA__COMMON__AMARA_STRINGS_SIMPLE_LIST__H__

/*
#include "amara_boolean.h"
*/

#include "amara_string.h"

typedef struct amara_strings_simple_list {

	amara_string * first;

	struct amara_strings_simple_list * next;
} amara_strings_simple_list
;

amara_strings_simple_list *
amara_strings_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

/**  Three char arrays result in one string element in a list of strings
 * (three to one: three char arrays, list with one single element. */
amara_strings_simple_list *
amara_strings_simple_list_exhaustive_constructor_three_to_one(
		const char * ca0, const char * ca1, const char * ca2)
__attribute__((warn_unused_result))
;

/*

amara_strings_simple_list *
amara_strings_simple_list_copy_constructor(
		const amara_stringss_simple_list * list)
__attribute__((warn_unused_result))
;

*/

void
amara_strings_simple_list_destructor(amara_strings_simple_list * list)
;

amara_strings_simple_list *
amara_strings_simple_list_push_front(
		amara_strings_simple_list * list, const amara_string * string)
__attribute__((warn_unused_result))
;

#endif
