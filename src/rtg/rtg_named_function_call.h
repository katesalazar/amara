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
 * src/rtg/rtg_named_function_call.h: Amara runtime graph named function
 * call.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTION_CALL__H__
#define __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTION_CALL__H__

#include "../definitions.h"

#include "../cmn/amara_strings_simple_list.h"

#include "../stt/stt_named_function_call.h"

#include "rtg_forward_declarations.h"

#include "rtg_named_function_call_arguments_simple_list.h"

typedef struct rtg_named_function_call {

	rtg_named_function * named_function_;

	rtg_named_function_call_arguments_simple_list * call_arguments_;
} rtg_named_function_call
;

typedef unsigned char rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function_ret_status
;

#define RTG_NAMED_FUNCTION_CALL_OUT_OF_STT_NAMED_FUNCTION_CALL_AND_RTG_NAMED_FUNCTION_RET_STATUS_INVALID 0x00
#define RTG_NAMED_FUNCTION_CALL_OUT_OF_STT_NAMED_FUNCTION_CALL_AND_RTG_NAMED_FUNCTION_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function_ret {

	rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function_ret_status status;

	amara_strings_simple_list * error_messages;

	rtg_named_function_call * named_function_call;
} rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function_ret
;

void
rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function_ret_destructor(
		rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function_ret * input_ret)
;

rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function_ret *
rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function(
		const stt_named_function_call * named_function_call,
		const rtg_named_function * named_function)
__amara__warn_unused_result__
;

amara_boolean
rtg_named_function_call_compatible_with_rtg_named_function(
		const rtg_named_function_call * rtg_named_function_call,
		const rtg_named_function * rtg_named_function)
__amara__warn_unused_result__
;

#endif
