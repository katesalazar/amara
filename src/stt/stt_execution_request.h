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
 * src/stt/stt_execution_request.h: Amara syntax tree application
 * execution request.
 */

#ifndef __AMARA__SYNTAX_TREE__EXECUTION_REQUEST__H__
#define __AMARA__SYNTAX_TREE__EXECUTION_REQUEST__H__

/*   For `uint_fast8_t`. */
#include <stdint.h>

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

#define STT_EXECUTION_REQUEST_TYPE_INVALID         0x00
#define STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION 0xFF

typedef struct stt_execution_request {
	uint_fast8_t type_;
	amara_string * application_name_;
} stt_execution_request;

stt_execution_request *
stt_execution_request_default_constructor()
__attribute__((warn_unused_result))
;

stt_execution_request *
stt_execution_request_copy_constructor(
		const stt_execution_request * execution_request)
__attribute__((warn_unused_result))
;

void
stt_execution_request_destructor(stt_execution_request * execution_request_)
;

void
stt_execution_request_set_type(
		stt_execution_request * execution_request,
		uint_fast8_t type)
;

void
stt_execution_request_set_application_name(
		stt_execution_request * execution_request,
		const amara_string * application_name)
;

#endif
