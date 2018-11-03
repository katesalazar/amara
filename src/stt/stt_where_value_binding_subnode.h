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
 * src/stt/stt_where_binding_subnode.h: Amara syntax tree where value
 * binding sub node.
 */

#ifndef __AMARA__SYNTAX_TREE__WHERE_VALUE_BINDING_SUBNODE__H__
#define __AMARA__SYNTAX_TREE__WHERE_VALUE_BINDING_SUBNODE__H__

#include "stt_where_value_binding.h"

typedef struct stt_where_value_binding_subnode {
	stt_where_value_binding * where_value_binding_;
} stt_where_value_binding_subnode
;

stt_where_value_binding_subnode *
stt_where_value_binding_subnode_exhaustive_constructor(
		const stt_where_value_binding * where_value_binding)
__attribute__((warn_unused_result))
;

stt_where_value_binding_subnode *
stt_where_value_binding_subnode_copy_constructor(
		const stt_where_value_binding_subnode * where_value_binding_subnode_)
__attribute__((warn_unused_result))
;

void
stt_where_value_binding_subnode_destructor(
		stt_where_value_binding_subnode * stt_where_value_binding_subnode_)
;

#endif
