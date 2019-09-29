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
 * src/stt/stt_where_value_binding.h: Amara syntax tree _where_ value
 * binding.
 */

#ifndef __AMARA__SYNTAX_TREE__WHERE_VALUE_BINDING__H__
#define __AMARA__SYNTAX_TREE__WHERE_VALUE_BINDING__H__

#include "../cmn/amara_string.h"

#include "stt_expression.h"

typedef struct stt_where_value_binding {

	amara_string * value_name_;

	stt_expression * value_expression_;
} stt_where_value_binding
;

/**  Temporary. XXX Must remove once the class hits 100% coverage. */
stt_where_value_binding *
stt_where_value_binding_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_where_value_binding *
stt_where_value_binding_copy_constructor(
		const stt_where_value_binding * where_value_binding_)
__attribute__((warn_unused_result))
;

stt_where_value_binding *
stt_where_value_binding_exhaustive_constructor(
		const amara_string * value_name_,
		const stt_expression * value_expression_)
__attribute__((warn_unused_result))
;

void
stt_where_value_binding_destructor(
		stt_where_value_binding * stt_where_value_binding_)
;

amara_boolean
stt_where_value_binding_equality(
		const stt_where_value_binding * wvb0,
		const stt_where_value_binding * wvb1)
;

amara_boolean
stt_where_value_bindings_equality(
		const stt_where_value_binding * wvb0,
		const stt_where_value_binding * wvb1)
;

#endif
