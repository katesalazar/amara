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
 * src/rtg/rtg_operations_simple_list.h: Amara runtime graph application
 * function operations simple list.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__OPERATIONS_SIMPLE_LIST__H__
#define __AMARA__RUN_TIME_GRAPH__OPERATIONS_SIMPLE_LIST__H__

/*   For `stt_operations_simple_list`. */
#include "../stt/stt_operations_simple_list.h"

/*   For `rtg_operation`. */
#include "rtg_operation.h"

rtg_operations_simple_list *
rtg_operations_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_operations_simple_list *
rtg_operations_simple_list_copy_constructor(
		const rtg_operations_simple_list * list)
__attribute__((warn_unused_result))
;

void
rtg_operations_simple_list_destructor(rtg_operations_simple_list * list)
;

rtg_operations_simple_list *
rtg_operations_simple_list_push_front(
		rtg_operations_simple_list * operations,
		rtg_operation * operation)
__amara__warn_unused_result__
;

typedef unsigned char rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_status;

#define RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_INVALID 0x00
#define RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION 0x0E
#define RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_operations_simple_list_out_of_stt_operations_simple_list_ret {

	rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_status status;

	amara_strings_simple_list * error_messages;

	rtg_operations_simple_list * operations;
} rtg_operations_simple_list_out_of_stt_operations_simple_list_ret
;

void
rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_destructor(
		rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_)
;

/*   @param operations - A function's operations.
 *   @param where_bindings - A function's where value bindings.
 *   @param rtg_named_functions - Other functions that `operations` or
 * `where_bindings` might be relying on. */
rtg_operations_simple_list_out_of_stt_operations_simple_list_ret *
rtg_operations_simple_list_out_of_stt_operations_simple_list(
		const stt_operations_simple_list * operations,
		const struct stt_where_value_bindings_simple_list * function_where_bindings,
		const rtg_named_functions_simple_list * rtg_named_functions)
__amara__warn_unused_result__
;

#endif
