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
 * src/rtg/rtg_operation_arg.h: Amara run time graph application
 * function operation argument.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__OPERATION_ARG__H__
#define __AMARA__RUN_TIME_GRAPH__OPERATION_ARG__H__

/*   For `amara_string`. */
/*
#include "../cmn/amara_string.h"
*/

#include "../cmn/amara_strings_simple_list.h"

/*   For `stt_operation_arg`. */
#include "../stt/stt_operation_arg.h"

#include "rtg_forward_declarations.h"

/*   For `rtg_expression`. */
#include "rtg_expression.h"

/*   For `rtg_operation`. */
#include "rtg_operation.h"

#include "rtg_named_function_call.h"

/*   This is an enumeration. */

#define RTG_OPERATION_ARG_TYPE_INVALID                   0x20
#define RTG_OPERATION_ARG_TYPE_STRING_LITERAL            0x21
#define RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL           0x22
#define RTG_OPERATION_ARG_TYPE_INTEGER_LITERAL           0x23
/* #define RTG_OPERATION_ARG_TYPE_RATIONAL_LITERAL       0x24 */
#define RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED 0x25  /* 37: '%'. */
#define RTG_OPERATION_ARG_TYPE_IDENTIFIER RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED
#define RTG_OPERATION_ARG_TYPE_UNKNOWN_TYPE_VARIABLE     0x26
#define RTG_OPERATION_ARG_TYPE_STRING_VARIABLE           RTG_OPERATION_ARG_TYPE_UNKNOWN_TYPE_VARIABLE
#define RTG_OPERATION_ARG_TYPE_NATURAL_VARIABLE          RTG_OPERATION_ARG_TYPE_UNKNOWN_TYPE_VARIABLE
/* #define RTG_OPERATION_ARG_TYPE_INTEGER_VARIABLE       RTG_OPERATION_ARG_TYPE_UNKNOWN_TYPE_VARIABLE */
/* #define RTG_OPERATION_ARG_TYPE_RATIONAL_VARIABLE      RTG_OPERATION_ARG_TYPE_UNKNOWN_TYPE_VARIABLE */
#define RTG_OPERATION_ARG_TYPE_EXPRESSION                0x27  /* 39: "'". */
/*   This might come back in the future, but at the time of writing
 * makes no sense as is becoming void of meaning with the conversion of
 * most arithmetics into expressions from being operations.
#define RTG_OPERATION_ARG_TYPE_OPERATION                 0x28
*/

typedef struct rtg_operation_arg {

	unsigned char type_;

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
	/* amara_string * variable_name_; */

	/* rtg_variable * variable_; */

	rtg_expression * expression_;

	/**  In case the operation is a function call, pointer to the
	 * function call, which should include a pointer to the called
	 * function itself. */
	rtg_named_function_call * named_function_call_;

	/**  TODO Why was this added? */
	struct rtg_operation * operation_;
} rtg_operation_arg
;

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
		rtg_operation_arg * operation_arg, unsigned char type)
;

void
rtg_operation_arg_set_string_literal(
		rtg_operation_arg * operation_arg,
		const amara_string * string_literal)
;

void
rtg_operation_arg_set_natural_literal(
		rtg_operation_arg * operation_arg,
		const amara_string * natural_literal)
;

void
rtg_operation_arg_set_identifier(
		rtg_operation_arg * operation_arg,
		const amara_string * identifier)
;

void
rtg_operation_arg_set_named_function_call(
		rtg_operation_arg * operation_arg,
		const rtg_named_function_call * named_function_call)
;

#define RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_INVALID 0x00
#define RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_IDENTIFIER 0x0E
#define RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_operation_arg_out_of_stt_operation_arg_ret {

	unsigned char status;

	amara_strings_simple_list * error_messages;

	rtg_operation_arg * operation_arg;
} rtg_operation_arg_out_of_stt_operation_arg_ret
;

void
rtg_operation_arg_out_of_stt_operation_arg_ret_destructor(
		rtg_operation_arg_out_of_stt_operation_arg_ret * rtg_operation_arg_out_of_stt_operation_arg_ret_)
;

rtg_operation_arg_out_of_stt_operation_arg_ret *
rtg_operation_arg_out_of_stt_operation_arg(
		const stt_operation_arg * operation_arg,
		const stt_operation_type operation_type,
		const struct stt_where_value_bindings_simple_list * function_where_bindings,
		const rtg_named_functions_simple_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

#endif
