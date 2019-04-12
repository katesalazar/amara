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
 * src/stt/stt_named_functions_simple_list.h: Amara syntax tree
 * application named functions simple list.
 */

#ifndef __AMARA__SYNTAX_TREE__NAMED_FUNCTIONS_SIMPLE_LIST__H__
#define __AMARA__SYNTAX_TREE__NAMED_FUNCTIONS_SIMPLE_LIST__H__

/*   For `stt_named_function`. */
#include "stt_named_function.h"

typedef struct stt_named_functions_simple_list {
	stt_named_function * first;
	struct stt_named_functions_simple_list * next;
} stt_named_functions_simple_list;

stt_named_functions_simple_list *
stt_named_functions_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_named_functions_simple_list *
stt_named_functions_simple_list_copy_constructor(
		const stt_named_functions_simple_list * named_functions)
__attribute__((warn_unused_result))
;

void
stt_named_functions_simple_list_destructor(
		stt_named_functions_simple_list * list)
;

unsigned char
stt_named_functions_simple_list_length(stt_named_functions_simple_list * list)
__attribute__((warn_unused_result))
;

stt_named_functions_simple_list *
stt_named_functions_simple_list_push_front(
		stt_named_functions_simple_list * named_functions,
		const stt_named_function * named_function)
__attribute__((warn_unused_result))
;

#endif
