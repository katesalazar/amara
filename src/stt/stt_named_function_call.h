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
 * src/stt/stt_named_function_call.h: TODO
 */

#ifndef __AMARA__SYNTAX_TREE__NAMED_FUNCTION_CALL__H__
#define __AMARA__SYNTAX_TREE__NAMED_FUNCTION_CALL__H__

#include "../definitions.h"

#include "../cmn/amara_boolean.h"

/*
#include "stt_node.h"
*/

/**  Helper struct for flags. */
typedef struct stt_named_function_call_pending_semantic_checks {

	/**  A function call might need to be checked that has no return
	 * value, for that hints a function which causes side effects. */
	amara_boolean called_function_has_no_return_value_;

	/**  XXX Remove this later. */
	/*
	int placeholder_for_avoiding_an_empty_struct;
	*/
} stt_named_function_call_pending_semantic_checks
;

typedef struct stt_named_function_call {

	/**  A node, of type identifier (STT_NODE_TYPE_IDENTIFIER),
	 * holds the name of the function to be called. */
	struct stt_node * function_name_identifier_;

	/**  A node, of type "function call arguments"
	 * (STT_NODE_TYPE_FUNCTION_CALL_ARGUMENTS_LIST), holds the list
	 * of arguments to the function call. */
	struct stt_node * call_arguments_;

	stt_named_function_call_pending_semantic_checks * pending_semantic_checks_;
} stt_named_function_call
;

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

void
stt_named_function_call_destructor(stt_named_function_call * nfc)
;

amara_boolean
stt_named_function_call_equality(
		const stt_named_function_call * nfc0,
		const stt_named_function_call * nfc1)
__amara__warn_unused_result__
;

/**  Synctactic sugar for `amara_boolean
 * stt_named_function_call_equality(const stt_named_function_call *,
 * const stt_named_function_call)`. */
amara_boolean
stt_named_function_calls_equality(
		const stt_named_function_call * nfc0,
		const stt_named_function_call * nfc1)
__amara__warn_unused_result__
;

#endif
