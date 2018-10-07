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
 * src/stt/stt_operation.h: Amara syntax tree application function
 * operation.
 */

#ifndef __AMARA__SYNTAX_TREE__OPERATION__H__
#define __AMARA__SYNTAX_TREE__OPERATION__H__

/*   For `stt_operation_args_simple_list`. */
#include "stt_operation_args_simple_list.h"

/*   This is an enumeration. */

#define STT_OPERATION_TYPE_INVALID       0x00
#define STT_OPERATION_TYPE_PRINT      0x03
#define STT_OPERATION_TYPE_PRINT_CRLF 0x0C
#define STT_OPERATION_TYPE_READ_NATURAL_TO_VALUE 0x2F
#define STT_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE 0x30
#define STT_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION 0x31
#define STT_OPERATION_TYPE_MULTIPLICATION           0x32
#define STT_OPERATION_TYPE_DIVISION                 0x33
#define STT_OPERATION_TYPE_ADDITION                 0x34
#define STT_OPERATION_TYPE_SUBSTRACTION             0x35
#define STT_OPERATION_TYPE_PRINT_NO_CRLF            0xFF /* TODO obsolete, must remove */

typedef struct stt_operation {
	uint_fast8_t type_;
	stt_operation_args_simple_list * args_;
} stt_operation;

stt_operation *
stt_operation_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_operation *
stt_operation_copy_constructor(const stt_operation * operation)
__attribute__((warn_unused_result))
;

void
stt_operation_destructor(stt_operation * operation)
;

#endif
