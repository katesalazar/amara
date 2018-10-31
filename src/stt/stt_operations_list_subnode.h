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
 * src/stt/stt_operations_list_subnode.h: Amara syntax tree application
 * function operations list subnode.
 */

#ifndef __AMARA__SYNTAX_TREE__OPERATIONS_LIST_SUBNODE__H__
#define __AMARA__SYNTAX_TREE__OPERATIONS_LIST_SUBNODE__H__

/*   For `stt_operations_simple_list`. */
#include "stt_operations_simple_list.h"

typedef struct stt_operations_list_subnode {
	stt_operations_simple_list * operations_;
} stt_operations_list_subnode;

stt_operations_list_subnode *
stt_operations_list_subnode_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_operations_list_subnode *
stt_operations_list_subnode_copy_constructor(
		const stt_operations_list_subnode * subnode)
__attribute__((warn_unused_result))
;

stt_operations_list_subnode *
stt_operations_list_subnode_exhaustive_constructor(
		const stt_operations_simple_list * operations)
__attribute__((warn_unused_result))
;

void
stt_operations_list_subnode_destructor(stt_operations_list_subnode * subnode)
;

#endif
