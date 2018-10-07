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
 * src/rtg/rtg_operation_arg.h: Amara run time graph application
 * function operation argument.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__OPERATION_ARG__H__
#define __AMARA__RUN_TIME_GRAPH__OPERATION_ARG__H__

/*   For `uint_fast8_t`. */
#include <stdint.h>

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   For `stt_operation_arg`. */
#include "../stt/stt_operation_arg.h"

/*   This is an enumeration. */

#define RTG_OPERATION_ARG_TYPE_INVALID        0x00
#define RTG_OPERATION_ARG_TYPE_STRING_LITERAL            0x01
#define RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL           0x02
#define RTG_OPERATION_ARG_TYPE_INTEGER_LITERAL           0x04
#define RTG_OPERATION_ARG_TYPE_RATIONAL_LITERAL          0x08
#define RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED 0x10
#define RTG_OPERATION_ARG_TYPE_UNKNOWN_TYPE_VARIABLE     0x20
#define RTG_OPERATION_ARG_TYPE_STRING_VARIABLE           RTG_OPERATION_ARG_TYPE_UNKNOWN_TYPE_VARIABLE
#define RTG_OPERATION_ARG_TYPE_NATURAL_VARIABLE          RTG_OPERATION_ARG_TYPE_UNKNOWN_TYPE_VARIABLE
#define RTG_OPERATION_ARG_TYPE_INTEGER_VARIABLE          RTG_OPERATION_ARG_TYPE_UNKNOWN_TYPE_VARIABLE
#define RTG_OPERATION_ARG_TYPE_RATIONAL_VARIABLE         RTG_OPERATION_ARG_TYPE_UNKNOWN_TYPE_VARIABLE
#define RTG_OPERATION_ARG_TYPE_OPERATION                 0x40

typedef struct rtg_operation_arg {
	uint_fast8_t type_;

	amara_string * string_literal_;

	amara_string * natural_literal_;

	amara_string * integer_literal_;

	amara_string * rational_literal_;

	/**  Later must be resolved as variable name (or any other type
	 * of identifier appliable at the whatever scope), if so, later
	 * as a reference to the actual variable storing its actual
	 * current value. */
	amara_string * identifier_;

	/**  Later would have to be resolved as a reference to the
	 * actual variable storing its actual current value. */
	amara_string * variable_name_;

	/* rtg_variable * variable_; */

	struct rtg_operation * operation_;
} rtg_operation_arg;

rtg_operation_arg *
rtg_operation_arg_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_operation_arg *
rtg_operation_arg_copy_constructor(const rtg_operation_arg * operation_arg)
__attribute__((warn_unused_result))
;

void
rtg_operation_arg_destructor(rtg_operation_arg * operation_arg)
;

void
rtg_operation_arg_set_type(
		rtg_operation_arg * operation_arg, uint_fast8_t type)
;

void
rtg_operation_arg_set_string_literal(
		rtg_operation_arg * operation_arg,
		const amara_string * string_literal)
;

#define RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_INVALID 0x00
#define RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_operation_arg_out_of_stt_operation_arg_ret {
	uint_fast8_t status;
	rtg_operation_arg * operation_arg;
	amara_boolean operation_arg_was_moved;
} rtg_operation_arg_out_of_stt_operation_arg_ret;

void
rtg_operation_arg_out_of_stt_operation_arg_ret_destructor(
		rtg_operation_arg_out_of_stt_operation_arg_ret * rtg_operation_arg_out_of_stt_operation_arg_ret_)
;

rtg_operation_arg_out_of_stt_operation_arg_ret *
rtg_operation_arg_out_of_stt_operation_arg(
		const stt_operation_arg * operation_arg)
__attribute__((warn_unused_result))
;

#endif
