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
 * src/stt/stt_natural_subnode.h: Amara syntax tree natural literal
 * subnode.
 */

#ifndef __AMARA__SYNTAX_TREE__NATURAL_SUBNODE__H__
#define __AMARA__SYNTAX_TREE__NATURAL_SUBNODE__H__

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

typedef struct stt_natural_subnode {
	amara_string * raw_;
} stt_natural_subnode;

stt_natural_subnode *
stt_natural_subnode_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_natural_subnode *
stt_natural_subnode_copy_constructor(const stt_natural_subnode * subnode)
__attribute__((warn_unused_result))
;

stt_natural_subnode *
stt_natural_subnode_exhaustive_constructor(const amara_string * raw)
__attribute__((warn_unused_result))
;

void
stt_natural_subnode_destructor(stt_natural_subnode * subnode)
;

amara_string *
stt_natural_subnode_get_raw(const stt_natural_subnode * subnode)
__attribute__((warn_unused_result))
;

void
stt_natural_subnode_set_raw(
		stt_natural_subnode * subnode, const amara_string * raw)
;

amara_boolean
stt_natural_subnode_equality(
		stt_natural_subnode * subnode0,
		stt_natural_subnode * subnode1)
__attribute__((warn_unused_result))
;

#endif
