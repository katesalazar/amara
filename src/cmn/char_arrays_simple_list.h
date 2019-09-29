/*
 * Copyright 2018-2019 Mercedes Catherine Salazar
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
 * src/cmn/char_arrays_simple_list.h: Simple list of character arrays.
 */

#ifndef __AMARA__COMMON__CHAR_ARRAYS_SIMPLE_LIST__H__
#define __AMARA__COMMON__CHAR_ARRAYS_SIMPLE_LIST__H__

#include "amara_boolean.h"

typedef struct char_arrays_simple_list {
	char * first;
	struct char_arrays_simple_list * next;
} char_arrays_simple_list;

char_arrays_simple_list *
char_arrays_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

char_arrays_simple_list *
char_arrays_simple_list_copy_constructor(const char_arrays_simple_list * list)
__attribute__((warn_unused_result))
;

void
char_arrays_simple_list_destructor(char_arrays_simple_list * list)
;

char_arrays_simple_list *
char_arrays_simple_list_push_front(
		char_arrays_simple_list * list, char * char_array)
__attribute__((warn_unused_result))
;

/*   This operation is non destructive towards both `list_zero` and
 * `list_one`. */
char_arrays_simple_list *
char_arrays_simple_list_concat(
		const char_arrays_simple_list * list_zero,
		const char_arrays_simple_list * list_one)
__attribute__((warn_unused_result))
;

/*   This operation is **destructive** towards both `list_zero` and
 * `list_one`. Structures pointed to by `list_zero` and `list_one`, if
 * any (i.e. passing not NULL), get invalidated and must be set to NULL
 * by/in the calling scope. */
char_arrays_simple_list *
char_arrays_simple_list_concat_destructive(
		char_arrays_simple_list * list_zero,
		char_arrays_simple_list * list_one)
__attribute__((warn_unused_result))
;

amara_boolean
char_arrays_simple_list_equality(
		const char_arrays_simple_list * list_zero,
		const char_arrays_simple_list * list_one)
__attribute__((warn_unused_result))
;

#endif
