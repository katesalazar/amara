/*
 * Copyright 2018-2020 Mercedes Catherine Salazar
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
 * src/rtg/rtg_named_function.h: Amara run time graph application named
 * function.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTION__H__
#define __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTION__H__

#include "rtg_forward_declarations.h"

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   For `stt_named_function`. */
#include "../stt/stt_named_function.h"

#include "../stt/stt_named_function_call.h"

/*   For `rtg_operations_simple_list`. */
#include "rtg_operations_simple_list.h"

/*   For `rtg_where_value_bindings_simple_list`. */
#include "rtg_where_value_bindings_simple_list.h"

/*   This is an enumeration, however it should probably become a mask
 * somewhat soon. */

#define RTG_NAMED_FUNCTION_TYPE_INVALID      0x00
#define RTG_NAMED_FUNCTION_TYPE_PURE_FUNCTION 0x0F
#define RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION 0xF0

rtg_named_function *
rtg_named_function_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_named_function *
rtg_named_function_exhaustive_constructor(
		unsigned char type, const amara_string * name,
		const rtg_operations_simple_list * operations,
		const rtg_where_value_bindings_simple_list * where_value_bindings)
__attribute__((warn_unused_result))
;

rtg_named_function *
rtg_named_function_copy_constructor(const rtg_named_function * original)
__attribute__((warn_unused_result))
;

void
rtg_named_function_destructor(rtg_named_function * named_function)
;

#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_INVALID          0x00
#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION 0x0E  /* 15. */
#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_SUCCESS          0xFF

typedef struct rtg_named_function_out_of_stt_named_function_ret {

	unsigned char status;

	amara_strings_simple_list * error_messages;

	rtg_named_function * named_function;
} rtg_named_function_out_of_stt_named_function_ret
;

void
rtg_named_function_out_of_stt_named_function_ret_destructor(
	rtg_named_function_out_of_stt_named_function_ret * input_ret)
;

rtg_named_function_out_of_stt_named_function_ret *
rtg_named_function_out_of_stt_named_function(
		const stt_named_function * named_function)
__attribute__((warn_unused_result))
;

#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID          0x00
#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION 0x0E
#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS          0xFF

typedef struct rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret {

	unsigned char status;

	amara_strings_simple_list * error_messages;

	rtg_named_function * named_function;
} rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret
;

void
rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret_destructor(
		rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret * input_ret)
;

rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret *
rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list(
		const stt_named_function * stt_named_function,
		const rtg_named_functions_simple_list * rtg_named_functions)
__amara__warn_unused_result__
;

amara_boolean
rtg_named_function_callable_from_stt_named_function_call(
		const rtg_named_function * named_function,
		const stt_named_function_call * named_function_call)
__amara__warn_unused_result__
;

#endif
