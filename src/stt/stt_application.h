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
 * src/stt/stt_application.h: Amara syntax tree application.
 */

#ifndef __AMARA__SYNTAX_TREE__APPLICATION__H__
#define __AMARA__SYNTAX_TREE__APPLICATION__H__

/*   For `uint_fast8_t`. */
#include <stdint.h>

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

#define STT_APPLICATION_TYPE_INVALID         0x00
#define STT_APPLICATION_TYPE_CLI_APPLICATION 0xFF

typedef struct stt_application {
	uint_fast8_t type_;
	amara_string * name_;
	amara_string * entry_point_function_name_;
} stt_application;

stt_application *
stt_application_copy_constructor(const stt_application * application)
__attribute__((warn_unused_result))
;

void
stt_application_destructor(stt_application * application)
;

#endif
