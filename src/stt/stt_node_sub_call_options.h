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
 * src/stt/stt_node_sub_call_options.h: Amara syntax tree node sub part.
 */

#ifndef __AMARA__SYNTAX_TREE__NODE_SUB_CALL_OPTIONS__H__
#define __AMARA__SYNTAX_TREE__NODE_SUB_CALL_OPTIONS__H__

#include "../cmn/amara_boolean.h"

typedef struct stt_node_sub_call_options {

	/**  Called function is a builtin function. */
	amara_boolean * builtin_function_;
} stt_node_sub_call_options
;

stt_node_sub_call_options *
stt_node_sub_call_options_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_node_sub_call_options *
stt_node_sub_call_options_copy_constructor(
		const stt_node_sub_call_options * sub_call_options)
__attribute__((warn_unused_result))
;

void
stt_node_sub_call_options_destructor(stt_node_sub_call_options * sub)
;

void
stt_node_sub_call_options_set_builtin_function_true(
		stt_node_sub_call_options * sub)
;

#endif
