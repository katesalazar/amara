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
 * src/stt/stt_condition_subnode.h: Amara syntax tree condition subnode.
 */

#ifndef __AMARA__SYNTAX_TREE__CONDITION_SUBNODE__H__
#define __AMARA__SYNTAX_TREE__CONDITION_SUBNODE__H__

#include "stt_condition.h"

typedef struct stt_condition_subnode {
	stt_condition * condition_;
} stt_condition_subnode
;

stt_condition_subnode *
stt_condition_subnode_exhaustive_constructor(const stt_condition * condition)
__attribute__((warn_unused_result))
;

stt_condition_subnode *
stt_condition_subnode_copy_constructor(const stt_condition_subnode * subnode)
__attribute__((warn_unused_result))
;

void
stt_condition_subnode_destructor(stt_condition_subnode * subnode)
;

#endif
