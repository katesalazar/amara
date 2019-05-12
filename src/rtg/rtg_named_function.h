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
 * src/rtg/rtg_named_function.h: Amara run time graph application named
 * function.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTION__H__
#define __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTION__H__

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   For `stt_named_function`. */
#include "../stt/stt_named_function.h"

/*   For `rtg_operations_simple_list`. */
#include "rtg_operations_simple_list.h"

/*   For `rtg_where_value_bindings_simple_list`. */
#include "rtg_where_value_bindings_simple_list.h"

rtg_named_function *
rtg_named_function_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_named_function *
rtg_named_function_exhaustive_constructor(
		unsigned char type, const amara_string * name,
		const struct rtg_operations_simple_list * operations,
		const struct rtg_where_value_bindings_simple_list * where_value_bindings)
__attribute__((warn_unused_result))
;

rtg_named_function *
rtg_named_function_copy_constructor(const rtg_named_function * original)
__attribute__((warn_unused_result))
;

void
rtg_named_function_destructor(rtg_named_function * named_function)
;

#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID          0x00
#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION 0x0E
#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS          0xFF

typedef struct rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret {

	unsigned char status;

	amara_strings_simple_list * error_messages;

	rtg_named_function * new_named_function;

	rtg_named_functions_simple_list * new_named_functions_directory;
} rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret
;

void
rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret_destructor(
	rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret * input_ret)
;

rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret *
rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list(
		const stt_named_function * stt_named_function,
		const rtg_named_functions_simple_list * rtg_named_functions_directory)
__attribute__((warn_unused_result))
;

#endif
