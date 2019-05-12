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
 * src/rtg/rtg_expression_sub_function_call.h: Amara run time graph
 * function call type of expression.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__EXPRESSION_SUB_FUNCTION_CALL__H__
#define __AMARA__RUN_TIME_GRAPH__EXPRESSION_SUB_FUNCTION_CALL__H__

#include "../cmn/amara_strings_simple_list.h"

#include "../stt/stt_expression_sub_function_call.h"

#include "rtg_forward_declarations.h"

#include "rtg_expressions_simple_list.h"

typedef struct rtg_expression_sub_function_call {

	struct rtg_named_function * function_;

	rtg_expressions_simple_list * arguments_;
} rtg_expression_sub_function_call
;

rtg_expression_sub_function_call *
rtg_expression_sub_function_call_exhaustive_constructor(
		const rtg_named_function * function,
		const rtg_expressions_simple_list * arguments)
__attribute__((warn_unused_result))
;

typedef unsigned char rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret_status
;

#define RTG_EXPRESSION_SUB_FUNCTION_CALL_OUT_OF_STT_EXPRESSION_SUB_FUNCTION_CALL_RET_STATUS_INVALID 0x00

/*   RTG function not found. */
#define RTG_EXPRESSION_SUB_FUNCTION_CALL_OUT_OF_STT_EXPRESSION_SUB_FUNCTION_CALL_RET_STATUS_ERROR_FUNCTION_NOT_FOUND 0x3F  /* 63: '?'. */

#define RTG_EXPRESSION_SUB_FUNCTION_CALL_OUT_OF_STT_EXPRESSION_SUB_FUNCTION_CALL_RET_STATUS_ERROR_UNSPECIFIC 0x7F

#define RTG_EXPRESSION_SUB_FUNCTION_CALL_OUT_OF_STT_EXPRESSION_SUB_FUNCTION_CALL_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret {

	rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret_status status;

	rtg_expression_sub_function_call * ret;

	amara_strings_simple_list * error_messages;
} rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret
;

rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret *
rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call(
		const stt_expression_sub_function_call * stt_expression_sub_function_call,
		const rtg_named_functions_simple_list * named_functions)
__attribute__((warn_unused_result))
;

#endif
