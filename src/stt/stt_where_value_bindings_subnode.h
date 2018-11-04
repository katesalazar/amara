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
 * src/stt/stt_where_value_bindings_subnode.h: Amara syntax tree _where_
 * value bindings subnode.
 */

#ifndef __AMARA__SYNTAX_TREE__WHERE_VALUE_BINDINGS_SUBNODE__H__
#define __AMARA__SYNTAX_TREE__WHERE_VALUE_BINDINGS_SUBNODE__H__

#include "stt_where_value_bindings_simple_list.h"

typedef struct stt_where_value_bindings_subnode {

	stt_where_value_bindings_simple_list * where_value_bindings_;
} stt_where_value_bindings_subnode
;

/**  Temporary. XXX Must remove once the class hits 100% coverage. */
stt_where_value_bindings_subnode *
stt_where_value_bindings_subnode_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_where_value_bindings_subnode *
stt_where_value_bindings_subnode_exhaustive_constructor(
		const stt_where_value_bindings_simple_list * list)
__attribute__((warn_unused_result))
;

stt_where_value_bindings_subnode *
stt_where_value_bindings_subnode_copy_constructor(
		const stt_where_value_bindings_subnode * stt_where_value_bindings_subnode_)
__attribute__((warn_unused_result))
;

void
stt_where_value_bindings_subnode_destructor(
		stt_where_value_bindings_subnode * stt_where_value_bindings_subnode_)
;

#endif
