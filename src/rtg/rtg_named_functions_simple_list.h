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
 * src/rtg/rtg_named_functions_simple_list.h: Amara run time graph
 * application named functions simple list.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTIONS_SIMPLE_LIST__H__
#define __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTIONS_SIMPLE_LIST__H__

/*   For `stt_named_functions_simple_list`. */
#include "../stt/stt_named_functions_simple_list.h"

/*   For `rtg_named_function`. */
#include "rtg_named_function.h"

typedef struct rtg_named_functions_simple_list {
	rtg_named_function * first;
	struct rtg_named_functions_simple_list * next;
} rtg_named_functions_simple_list;

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_copy_constructor(
		const rtg_named_functions_simple_list * list)
__attribute__((warn_unused_result))
;

void
rtg_named_functions_simple_list_destructor(
		rtg_named_functions_simple_list * list)
;

#define FIND_RTG_NAMED_FUNCTION_BY_NAME_RET_STATUS_INVALID   0x00
#define FIND_RTG_NAMED_FUNCTION_BY_NAME_RET_STATUS_SUCCESS   0x0F
#define FIND_RTG_NAMED_FUNCTION_BY_NAME_RET_STATUS_NOT_FOUND 0xF0

typedef struct find_rtg_named_function_by_name_ret {
	uint_fast8_t status;
	rtg_named_function * named_function;
	amara_boolean named_function_was_moved;
} find_rtg_named_function_by_name_ret;

void
find_rtg_named_function_by_name_ret_destructor(
		find_rtg_named_function_by_name_ret * find_rtg_named_function_by_name_ret_)
;

find_rtg_named_function_by_name_ret *
find_rtg_named_function_by_name(
		const amara_string * needle,
		const rtg_named_functions_simple_list * haystack)
__attribute__((warn_unused_result))
;

#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID 0x00
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_named_functions_simple_list_out_of_stt_named_functions_simpe_list_ret {
	uint_fast8_t status;
	rtg_named_functions_simple_list * named_functions;
	amara_boolean named_functions_were_moved;
} rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret;

rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(
		const stt_named_functions_simple_list * list)
__attribute__((warn_unused_result))
;

#endif
