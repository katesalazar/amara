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
 * src/stt/stt_operation_args_simple_list.h: Amara syntax tree
 * application function operation arguments simple list.
 */

#ifndef __AMARA__SYNTAX_TREE__OPERATION_ARGS_SIMPLE_LIST__H__
#define __AMARA__SYNTAX_TREE__OPERATION_ARGS_SIMPLE_LIST__H__

/*   For `stt_operation_arg`. */
#include "stt_operation_arg.h"

typedef struct stt_operation_args_simple_list {

	stt_operation_arg * first;

	struct stt_operation_args_simple_list * next;
} stt_operation_args_simple_list
;

stt_operation_args_simple_list *
stt_operation_args_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_operation_args_simple_list *
stt_operation_args_simple_list_copy_constructor(
		const stt_operation_args_simple_list * operation_args)
__attribute__((warn_unused_result))
;

void
stt_operation_args_simple_list_destructor(
		stt_operation_args_simple_list * list)
;

stt_operation_args_simple_list *
stt_operation_args_simple_list_push_front(
		stt_operation_args_simple_list * operation_args,
		const stt_operation_arg * operation_arg)
__attribute__((warn_unused_result))
;

unsigned char
stt_operation_args_simple_list_length(
		const stt_operation_args_simple_list * operation_args)
__attribute__((warn_unused_result))
;

amara_boolean
stt_operation_args_simple_list_equality(
		const stt_operation_args_simple_list * l0,
		const stt_operation_args_simple_list * l1)
;

#endif
