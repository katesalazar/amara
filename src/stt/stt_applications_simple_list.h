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
stt_applications_simple_list_copy_constructor(
		stt_applications_simple_list * applications)
__attribute__((warn_unused_result))
;

void
stt_applications_simple_list_destructor(
		stt_applications_simple_list * list)
;

uint_fast8_t
stt_applications_simple_list_length(stt_applications_simple_list * list)
__attribute__((warn_unused_result))
;

#endif
