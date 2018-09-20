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
 * src/stt/stt_function.h: Amara syntax tree application function.
 */

#ifndef __AMARA__SYNTAX_TREE__FUNCTION__H__
#define __AMARA__SYNTAX_TREE__FUNCTION__H__

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   For `stt_operations_simple_list`. */
#include "stt_operations_simple_list.h"

/*   This is an enumeration, but it should probably become a mask. */

#define STT_FUNCTION_TYPE_INVALID      0x00
#define STT_FUNCTION_TYPE_CLI_FUNCTION 0xFF

typedef struct stt_function {
	uint_fast8_t type_;
	amara_string * name_;
	stt_operations_simple_list * operations_;
} stt_function;

stt_function *
stt_function_copy_constructor(const stt_function * function)
__attribute__((warn_unused_result))
;

void
stt_function_destructor(stt_function * function)
;

#endif
