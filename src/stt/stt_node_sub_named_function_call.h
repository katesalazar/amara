/*
 * Copyright 2020 Mercedes Catherine Salazar
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
 * src/stt/stt_node_sub_named_function_call.h: A syntax tree node can
 * represent a function call. If so, it holds some information that is
 * stored in this "sub" entity.
 */

#ifndef __AMARA__SYNTAX_TREE__NODE_SUB_NAMED_FUNCTION_CALL__H__
#define __AMARA__SYNTAX_TREE__NODE_SUB_NAMED_FUNCTION_CALL__H__

#include "../definitions.h"

/*
#include "../cmn/amara_boolean.h"
*/

#include "stt_named_function_call.h"

typedef struct stt_node_sub_named_function_call {

	stt_named_function_call * named_function_call_;
} stt_node_sub_named_function_call
;

/*
stt_node_sub_named_function_call *
stt_node_sub_named_function_call_default_constructor(void)
__amara__warn_unused_result__
;
*/

/**  Copy constructor. */
stt_node_sub_named_function_call *
stt_node_sub_named_function_call_copy_constructor(
		const stt_node_sub_named_function_call * sub_named_function_call)
__amara__warn_unused_result__
;

/**  Exhaustive constructor. Warning: _steals_ both
 * `function_name_identifier` and `call_arguments`. */
stt_node_sub_named_function_call *
stt_node_sub_named_function_call_exhaustive_constructor(
		struct stt_named_function_call * named_function_call)
__amara__warn_unused_result__
;

void
stt_node_sub_named_function_call_destructor(
		stt_node_sub_named_function_call  * sfc)
;

/*
amara_string *
stt_identifier_subnode_get_value(void)
__attribute__((warn_unused_result))
;

void
stt_identifier_subnode_set_value(
		stt_identifier_subnode * subnode, amara_string * value)
;
*/

/**  Equality test. */
amara_boolean
stt_node_sub_named_function_call_equality(
		const stt_node_sub_named_function_call * s0,
		const stt_node_sub_named_function_call * s1)
__amara__warn_unused_result__
;

#endif
