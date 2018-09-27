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
 * src/stt/stt_execution_request_subnode.h: Amara syntax tree
 * application execution request subnode.
 */

#ifndef __AMARA__SYNTAX_TREE__EXECUTION_REQUEST_SUBNODE__H__
#define __AMARA__SYNTAX_TREE__EXECUTION_REQUEST_SUBNODE__H__

/*   For `uint_fast8_t`. */
#include <stdint.h>

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

#define STT_EXECUTION_REQUEST_SUBNODE_TYPE_INVALID             0x00
#define STT_EXECUTION_REQUEST_SUBNODE_TYPE_RUN_CLI_APPLICATION 0xFF

typedef struct stt_execution_request_subnode {
	uint_fast8_t type_;
	amara_string * application_name_;
} stt_execution_request_subnode;

stt_execution_request_subnode *
stt_execution_request_subnode_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_execution_request_subnode *
stt_execution_request_subnode_copy_constructor(
		const stt_execution_request_subnode * subnode)
__attribute__((warn_unused_result))
;

void
stt_execution_request_subnode_destructor(
		stt_execution_request_subnode * subnode)
;

#endif
