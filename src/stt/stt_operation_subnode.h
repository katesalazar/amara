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
 * src/stt/stt_operation_subnode.h: Amara syntax tree application
 * function operation subnode.
 */

#ifndef __AMARA__SYNTAX_TREE__OPERATION_SUBNODE__H__
#define __AMARA__SYNTAX_TREE__OPERATION_SUBNODE__H__

/*   For `stt_operation`. */
#include "stt_operation.h"

typedef struct stt_operation_subnode {
	stt_operation * operation_;
} stt_operation_subnode;

stt_operation_subnode *
stt_operation_subnode_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_operation_subnode *
stt_operation_subnode_copy_constructor(const stt_operation_subnode * subnode)
__attribute__((warn_unused_result))
;

stt_operation_subnode *
stt_operation_subnode_exhaustive_constructor(
		const stt_operation * operation)
__attribute__((warn_unused_result))
;

void
stt_operation_subnode_destructor(stt_operation_subnode * subnode)
;

#endif
