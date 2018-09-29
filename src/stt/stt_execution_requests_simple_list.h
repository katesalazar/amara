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
 * src/stt/stt_execution_requests_simple_list.h: Amara syntax tree
 * application execution requests simple list.
 */

#ifndef __AMARA__SYNTAX_TREE__EXECUTION_REQUESTS_SIMPLE_LIST__H__
#define __AMARA__SYNTAX_TREE__EXECUTION_REQUESTS_SIMPLE_LIST__H__

/*   For `stt_execution_request`. */
#include "stt_execution_request.h"

typedef struct stt_execution_requests_simple_list {
	stt_execution_request * first;
	struct stt_execution_requests_simple_list * next;
} stt_execution_requests_simple_list;

stt_execution_requests_simple_list *
stt_execution_requests_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_execution_requests_simple_list *
stt_execution_requests_simple_list_copy_constructor(
		const stt_execution_requests_simple_list * execution_requests)
__attribute__((warn_unused_result))
;

void
stt_execution_requests_simple_list_destructor(
		stt_execution_requests_simple_list * list)
;

uint_fast8_t
stt_execution_requests_simple_list_length(
		stt_execution_requests_simple_list * list)
__attribute__((warn_unused_result))
;

stt_execution_requests_simple_list *
stt_execution_requests_simple_list_push_front(
		stt_execution_requests_simple_list * execution_requests,
		const stt_execution_request * execution_request)
__attribute__((warn_unused_result))
;

#endif
