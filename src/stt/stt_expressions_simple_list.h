/*
 * Copyright 2019 Mercedes Catherine Salazar
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
 * src/stt/stt_expressions_simple_list.h: Amara syntax tree expressions
 * simple listt.
 */

#ifndef __AMARA__SYNTAX_TREE__EXPRESSIONS_SIMPLE_LIST__H__
#define __AMARA__SYNTAX_TREE__EXPRESSIONS_SIMPLE_LIST__H__

#include "stt_expression.h"

typedef struct stt_expressions_simple_list {

	struct stt_expression * first;

	struct stt_expressions_simple_list * next;
} stt_expressions_simple_list
;

stt_expressions_simple_list *
stt_expressions_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_expressions_simple_list *
stt_expressions_simple_list_copy_constructor(
		const stt_expressions_simple_list * expressions_list)
__attribute__((warn_unused_result))
;

void
stt_expressions_simple_list_destructor(stt_expressions_simple_list * list)
;

stt_expressions_simple_list *
stt_expressions_simple_list_push_front(
		const stt_expressions_simple_list * expressions_list,
		const struct stt_expression * expression)
__attribute__((warn_unused_result))
;

signed short
stt_expressions_simple_list_length(
		const stt_expressions_simple_list * expressions_list)
__attribute__((warn_unused_result))
;

amara_boolean
stt_expressions_simple_list_equality(
		const stt_expressions_simple_list * l0,
		const stt_expressions_simple_list * l1)
__attribute__((warn_unused_result))
;

#endif
