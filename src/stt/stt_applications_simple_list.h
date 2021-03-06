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
 * src/stt/stt_applications_simple_list.h: Amara syntax tree
 * applications simple list.
 */

#ifndef __AMARA__SYNTAX_TREE__APPLICATIONS_SIMPLE_LIST__H__
#define __AMARA__SYNTAX_TREE__APPLICATIONS_SIMPLE_LIST__H__

/*   For `stt_application`. */
#include "stt_application.h"

typedef struct stt_applications_simple_list {

	stt_application * first;

	struct stt_applications_simple_list * next;
} stt_applications_simple_list;

stt_applications_simple_list *
stt_applications_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_applications_simple_list *
stt_applications_simple_list_copy_constructor(
		const stt_applications_simple_list * applications)
__attribute__((warn_unused_result))
;

void
stt_applications_simple_list_destructor(
		stt_applications_simple_list * list)
;

stt_applications_simple_list *
stt_applications_simple_list_push_front(
		stt_applications_simple_list * applications,
		const stt_application * application)
__attribute__((warn_unused_result))
;

#define STT_APPLICATIONS_SIMPLE_LIST_LENGTH_RET_STATUS_INVALID 0x00
#define STT_APPLICATIONS_SIMPLE_LIST_LENGTH_RET_STATUS_ERROR_OVERFLOW 0x0F
#define STT_APPLICATIONS_SIMPLE_LIST_LENGTH_RET_STATUS_SUCCESS 0xF0

typedef struct stt_applications_simple_list_length_ret {

	unsigned char status;

	unsigned char length;
} stt_applications_simple_list_length_ret
;

stt_applications_simple_list_length_ret *
stt_applications_simple_list_length(const stt_applications_simple_list * list)
__attribute__((warn_unused_result))
;

#endif
