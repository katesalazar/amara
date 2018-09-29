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
 * src/stt/stt_identifier_subnode.h: Amara syntax tree identifier
 * subnode. An identifier does not have any atomic sense, so do not look
 * for the run time graph counter part of this class.
 */

#ifndef __AMARA__SYNTAX_TREE__IDENTIFIER_SUBNODE__H__
#define __AMARA__SYNTAX_TREE__IDENTIFIER_SUBNODE__H__

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

typedef struct stt_identifier_subnode {
	amara_string * value_;
} stt_identifier_subnode;

stt_identifier_subnode *
stt_identifier_subnode_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_identifier_subnode *
stt_identifier_subnode_copy_constructor(const stt_identifier_subnode * subnode)
__attribute__((warn_unused_result))
;

stt_identifier_subnode *
stt_identifier_subnode_exhaustive_constructor(
		const amara_string * identifier)
__attribute__((warn_unused_result))
;

void
stt_identifier_subnode_destructor(stt_identifier_subnode * subnode)
;

amara_string *
stt_identifier_subnode_get_value(void)
__attribute__((warn_unused_result))
;

void
stt_identifier_subnode_set_value(
		stt_identifier_subnode * subnode, amara_string * value)
;

#endif
