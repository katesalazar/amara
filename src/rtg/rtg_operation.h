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
#define RTG_OPERATION_TYPE_PRINT      0x03
#define RTG_OPERATION_TYPE_PRINT_CRLF 0x0C
/*
#define RTG_OPERATION_TYPE_MULTIPLICATION           0x30
#define RTG_OPERATION_TYPE_DIVISION                 0x31
#define RTG_OPERATION_TYPE_ADDITION                 0x32
#define RTG_OPERATION_TYPE_SUBSTRACTION             0x33
*/
#define RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE    0xBF
#define RTG_OPERATION_TYPE_READ_NATURAL_INTO_VALUE \
		RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE
#define RTG_OPERATION_TYPE_READ_INTEGER_INTO_VALUE  0xC0
/*
#define RTG_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE 0xC0
#define RTG_OPERATION_TYPE_READ_NATURAL_INTO_VARIABLE \
		RTG_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE
*/
/*
#define RTG_FAKE_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION 0xC1 *//*   Must remain resolved by semantic analysis by the time run time comes. */
/*
#define RTG_OPERATION_TYPE_PRINT_NO_CRLF            0xFF
*/

typedef unsigned char rtg_operation_type;

typedef struct rtg_operation {

	rtg_operation_type type_;

	struct rtg_operation_args_simple_list * args_;
} rtg_operation
;

rtg_operation *
rtg_operation_exhaustive_constructor(
		const rtg_operation_type type,
		const struct rtg_operation_args_simple_list * args)
__attribute__((warn_unused_result))
;

rtg_operation *
rtg_operation_copy_constructor(const rtg_operation * operation)
__attribute__((warn_unused_result))
;

void
rtg_operation_destructor(rtg_operation * operation)
;

amara_string *
rtg_operation_type_as_string(unsigned char operation_type)
__attribute__((warn_unused_result))
;

/*   This is an enumeration. */

#define RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_INVALID 0x00
#define RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER 0x0E
#define RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_operation_out_of_stt_operation_ret {

	unsigned char status;

	amara_strings_simple_list * error_messages;

	rtg_operation * operation;
} rtg_operation_out_of_stt_operation_ret
;

void
rtg_operation_out_of_stt_operation_ret_destructor(
		rtg_operation_out_of_stt_operation_ret * input_ret_)
;

rtg_operation_out_of_stt_operation_ret *
rtg_operation_out_of_stt_operation(
		const stt_operation * operation,
		const struct stt_where_value_bindings_simple_list * function_where_bindings)
__attribute__((warn_unused_result))
;

#endif
