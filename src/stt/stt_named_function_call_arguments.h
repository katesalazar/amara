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
 * src/stt/stt_named_function_call_arguments.h: TODO
 */

#ifndef __AMARA__SYNTAX_TREE__NAMED_FUNCTION_CALL_ARGUMENTS__H__
#define __AMARA__SYNTAX_TREE__NAMED_FUNCTION_CALL_ARGUMENTS__H__

/*
#include "../definitions.h"

#include "../cmn/amara_boolean.h"
*/

/*
#include "stt_node.h"
*/

typedef struct stt_named_function_call_arguments {

	/**  A node, of type identifier (STT_NODE_TYPE_IDENTIFIER),
	 * holds the name of the function to be called. */
/*
	struct stt_node * function_name_identifier_;
*/
	/**  A node, of type "function call arguments"
	 * (STT_NODE_TYPE_FUNCTION_CALL_ARGUMENTS_LIST), holds the list
	 * of arguments to the function call. */
/*
	struct stt_node * call_arguments_;

	stt_named_function_call_pending_semantic_checks * pending_semantic_checks_;
*/
	void *
			unused_;  /* XXX */
} stt_named_function_call
;

/*
stt_named_function_call *
stt_named_function_call_copy_constructor(
		const stt_named_function_call * named_function_call)
__amara__warn_unused_result__
;

stt_named_function_call *
stt_named_function_call_exhaustive_constructor(
		const struct stt_node * function_name_identifier,
		const struct stt_node * call_arguments)
__amara__warn_unused_result__
;
*/

#endif
