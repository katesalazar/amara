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
 * src/cmn/char_arrays_simple_list.h: Simple list of character arrays.
 */

#ifndef __AMARA__COMMON__CHAR_ARRAYS_SIMPLE_LIST__H__
#define __AMARA__COMMON__CHAR_ARRAYS_SIMPLE_LIST__H__

/*   For `uint_fast8_t`. */
#include <stdint.h>

typedef struct char_arrays_simple_list {
	char * first;
	struct char_arrays_simple_list * next;
} char_arrays_simple_list;

char_arrays_simple_list *
char_arrays_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

void
char_arrays_simple_list_destructor(char_arrays_simple_list * list)
;

/*   This operation is non destructive towards both `list_zero` and
 * `list_one`. */
char_arrays_simple_list *
char_arrays_simple_list_concat(
		const char_arrays_simple_list * list_zero,
		const char_arrays_simple_list * list_one)
__attribute__((warn_unused_result))
;

/*   This operations is **destructive** towards both `list_zero` and
 * `list_one`. */
char_arrays_simple_list *
char_arrays_simple_list_concat_destructive(
		char_arrays_simple_list * list_zero,
		char_arrays_simple_list * list_one)
__attribute__((warn_unused_result))
;

uint_fast8_t
char_arrays_simple_list_equality(
		const char_arrays_simple_list * list_zero,
		const char_arrays_simple_list * list_one)
__attribute__((warn_unused_result))
;

#endif
