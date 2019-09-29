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
 * src/stt/stt_operation_arg.h: Amara syntax tree application function
 * operation argument.
 */

#ifndef __AMARA__SYNTAX_TREE__OPERATION_ARG__H__
#define __AMARA__SYNTAX_TREE__OPERATION_ARG__H__

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

typedef unsigned char stt_operation_arg_type;

#define STT_OPERATION_ARG_TYPE_INVALID 0x21  /* 33: '!'. */
#define STT_OPERATION_ARG_TYPE_VALID   0x3F  /* 63: '?'. */

typedef struct stt_operation_arg {

	stt_operation_arg_type type_;

	/*
	amara_string * raw_;
	*/

	struct stt_node * node_;
} stt_operation_arg
;

stt_operation_arg *
stt_operation_arg_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_operation_arg *
stt_operation_arg_copy_constructor(const stt_operation_arg * operation_arg)
__attribute__((warn_unused_result))
;

void
stt_operation_arg_destructor(const stt_operation_arg * operation_arg)
;

void
stt_operation_arg_set_type(
		stt_operation_arg * operation_arg,
		const stt_operation_arg_type type)
;

void
stt_operation_arg_set_node(
		stt_operation_arg * operation_arg,
		const struct stt_node * node)
;

void
stt_operation_arg_set_string_literal(
		stt_operation_arg * operation_arg,
		const amara_string * string_literal)
;

void
stt_operation_arg_set_identifier(
		stt_operation_arg * operation_arg,
		const amara_string * identifier)
;

amara_boolean
stt_operation_arg_equality(
		const stt_operation_arg * oa0, const stt_operation_arg * oa1)
__attribute__((warn_unused_result))
;

amara_boolean
stt_operation_args_equality(
		const stt_operation_arg * oa0, const stt_operation_arg * oa1)
__attribute__((warn_unused_result))
;

#endif
