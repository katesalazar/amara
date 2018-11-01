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
 * src/stt/stt_named_function.h: Amara syntax tree application named
 * function.
 */

#ifndef __AMARA__SYNTAX_TREE__NAMED_FUNCTION__H__
#define __AMARA__SYNTAX_TREE__NAMED_FUNCTION__H__

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   For `stt_operations_simple_list`. */
#include "stt_operations_simple_list.h"

/*   This is an enumeration, but it should probably become a mask. */

#define STT_NAMED_FUNCTION_TYPE_INVALID      0x00
#define STT_NAMED_FUNCTION_TYPE_PURE_FUNCTION 0x0F
#define STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION 0xF0
#define STT_NAMED_FUNCTION_TYPE_CLI_APP_NAMED_FUNCTION \
		STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION

typedef struct stt_named_function {
	unsigned char type_;
	amara_string * name_;
	stt_operations_simple_list * operations_;
} stt_named_function;

stt_named_function *
stt_named_function_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_named_function *
stt_named_function_exhaustive_constructor(
		unsigned char type, const amara_string * name,
		const stt_operations_simple_list * operations)
__attribute__((warn_unused_result))
;

stt_named_function *
stt_named_function_copy_constructor(const stt_named_function * named_function)
__attribute__((warn_unused_result))
;

void
stt_named_function_destructor(stt_named_function * named_function)
;

void
stt_named_function_set_type(
		stt_named_function * named_function, unsigned char type)
;

void
stt_named_function_set_name(
		stt_named_function * named_function, const amara_string * name)
;

void
stt_named_function_set_operations(
		stt_named_function * named_function,
		const stt_operations_simple_list * operations)
;

#endif
