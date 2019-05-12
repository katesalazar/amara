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
 * src/stt/stt_expression_sub_function_call.h: Amara syntax tree
 * function call type of expression sub node.
 */

#ifndef __AMARA__SYNTAX_TREE__EXPRESSION_SUB_FUNCTION_CALL__H__
#define __AMARA__SYNTAX_TREE__EXPRESSION_SUB_FUNCTION_CALL__H__

#include "stt_expressions_simple_list.h"

typedef struct stt_expression_sub_function_call {

	/**  Options: the function is a builtin function. */
	amara_boolean * builtin_function_;

	amara_string * function_name_;

	struct stt_expressions_simple_list * call_arguments_;
} stt_expression_sub_function_call
;

stt_expression_sub_function_call *
stt_expression_sub_function_call_copy_constructor(
		const stt_expression_sub_function_call * expression_sub_function_call)
__attribute__((warn_unused_result))
;

stt_expression_sub_function_call *
stt_expression_sub_function_call_exhaustive_constructor(
		const amara_string * function_name,
		const struct stt_expressions_simple_list * call_arguments,
		const amara_boolean * builtin_function)
__attribute__((warn_unused_result))
;

void
stt_expression_sub_function_call_destructor(
		stt_expression_sub_function_call * expression_sub_function_call)
;

amara_boolean
stt_expression_sub_function_call_equality(
		const stt_expression_sub_function_call * o0,
		const stt_expression_sub_function_call * o1)
__attribute__((warn_unused_result))
;

#endif
