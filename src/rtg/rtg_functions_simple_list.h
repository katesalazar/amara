/*
 * Copyright 2018 Mercedes Catherine Salazar
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
 * src/rtg/rtg_functions_simple_list.h: Amara run time graph application
 * functions simple list.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__FUNCTIONS_SIMPLE_LIST__H__
#define __AMARA__RUN_TIME_GRAPH__FUNCTIONS_SIMPLE_LIST__H__

/*   For `stt_functions_simple_list`. */
#include "../stt/stt_functions_simple_list.h"

/*   For `rtg_function`. */
#include "rtg_function.h"

typedef struct rtg_functions_simple_list {
	rtg_function * first;
	struct rtg_functions_simple_list * next;
} rtg_functions_simple_list;

rtg_functions_simple_list *
rtg_functions_simple_list_copy_constructor(rtg_functions_simple_list * list)
__attribute__((warn_unused_result))
;

#define FIND_RTG_FUNCTION_BY_NAME_RET_STATUS_INVALID   0x00
#define FIND_RTG_FUNCTION_BY_NAME_RET_STATUS_SUCCESS   0x0F
#define FIND_RTG_FUNCTION_BY_NAME_RET_STATUS_NOT_FOUND 0xF0

typedef struct find_rtg_function_by_name_ret {
	uint_fast8_t status;
	rtg_function * function;
} find_rtg_function_by_name_ret;

find_rtg_function_by_name_ret *
find_rtg_function_by_name(
		const amara_string * needle,
		const rtg_functions_simple_list * haystack)
__attribute__((warn_unused_result))
;

#define RTG_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID 0x00
#define RTG_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_functions_simple_list_out_of_stt_functions_simpe_list_ret {
	uint_fast8_t status;
	rtg_functions_simple_list * functions;
} rtg_functions_simple_list_out_of_stt_functions_simple_list_ret;

rtg_functions_simple_list_out_of_stt_functions_simple_list_ret *
rtg_functions_simple_list_out_of_stt_functions_simple_list(
		const stt_functions_simple_list * list)
__attribute__((warn_unused_result))
;

#endif
