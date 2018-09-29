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
 * src/rtg/rtg_operation.h: Amara runtime graph application function
 * operation.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__OPERATION__H__
#define __AMARA__RUN_TIME_GRAPH__OPERATION__H__

/*   For `stt_operation`. */
#include "../stt/stt_operation.h"

/*   For `rtg_operation_args_simple_list`. */
#include "rtg_operation_args_simple_list.h"

#define RTG_OPERATION_TYPE_INVALID       0x00
#define RTG_OPERATION_TYPE_PRINT         0x0F
#define RTG_OPERATION_TYPE_PRINT_NO_CRLF 0xF0

typedef struct rtg_operation {
	uint_fast8_t type_;
	rtg_operation_args_simple_list * args_;
} rtg_operation;

rtg_operation *
rtg_operation_exhaustive_constructor(
		uint_fast8_t type, const rtg_operation_args_simple_list * args)
__attribute__((warn_unused_result))
;

rtg_operation *
rtg_operation_copy_constructor(const rtg_operation * operation)
__attribute__((warn_unused_result))
;

void
rtg_operation_destructor(rtg_operation * operation)
;

/*   This is an enumeration. */

#define RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_INVALID 0x00
#define RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_operation_out_of_stt_operation_ret {
	uint_fast8_t status;
	rtg_operation * operation;
	amara_boolean operation_was_moved;
} rtg_operation_out_of_stt_operation_ret;

void
rtg_operation_out_of_stt_operation_ret_destructor(
		rtg_operation_out_of_stt_operation_ret * rtg_operation_out_of_stt_operation_ret_)
;

rtg_operation_out_of_stt_operation_ret *
rtg_operation_out_of_stt_operation(const stt_operation * operation)
__attribute__((warn_unused_result))
;

#endif
