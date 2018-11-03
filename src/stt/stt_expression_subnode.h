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
 * src/stt/stt_expression_subnode.h: Amara syntax tree expression
 * subnode.
 */

#ifndef __AMARA__SYNTAX_TREE__EXPRESSION_SUBNODE__H__
#define __AMARA__SYNTAX_TREE__EXPRESSION_SUBNODE__H__

#include "../asr/assertion.h"

/*   For `stt_expression` AKA `struct stt_expression`. */
#include "stt_expression.h"

typedef struct stt_expression_subnode {
	stt_expression * expression_;
} stt_expression_subnode
;

stt_expression_subnode *
stt_expression_subnode_exhaustive_constructor(
		const stt_expression * expression)
__attribute__((warn_unused_result))
;

stt_expression_subnode *
stt_expression_subnode_copy_constructor(
		const stt_expression_subnode * expression_subnode)
__attribute__((warn_unused_result))
;

void
stt_expression_subnode_destructor(stt_expression_subnode * subnode)
;

#endif
