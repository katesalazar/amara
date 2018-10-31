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
 * src/stt/stt_string_literal_subnode.h: Amara syntax tree string
 * literal subnode.
 */

#ifndef __AMARA__SYNTAX_TREE__STRING_LITERAL_SUBNODE__H__
#define __AMARA__SYNTAX_TREE__STRING_LITERAL_SUBNODE__H__

/*   For `amara_boolean` and its values. */
#include "../cmn/amara_boolean.h"

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

typedef struct stt_string_literal_subnode {
	amara_string * string_literal_;
} stt_string_literal_subnode;

stt_string_literal_subnode *
stt_string_literal_subnode_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_string_literal_subnode *
stt_string_literal_subnode_copy_constructor(
		const stt_string_literal_subnode * subnode)
__attribute__((warn_unused_result))
;

stt_string_literal_subnode *
stt_string_literal_subnode_exhaustive_constructor(
		const amara_string * string_literal)
__attribute__((warn_unused_result))
;

void
stt_string_literal_subnode_destructor(
		stt_string_literal_subnode * subnode)
;

amara_string *
stt_string_literal_subnode_get_string_literal(
		const stt_string_literal_subnode * subnode)
__attribute__((warn_unused_result))
;

void
stt_string_literal_subnode_set_string_literal(
		stt_string_literal_subnode * subnode,
		amara_string * string_literal)
;

amara_boolean
stt_string_literal_subnode_equality(
		stt_string_literal_subnode * subnode0,
		stt_string_literal_subnode * subnode1)
__attribute__((warn_unused_result))
;

#endif
