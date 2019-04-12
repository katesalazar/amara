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
 * src/stt/stt_expression_sub_natural_literal.h: Amara syntax tree
 * natural literal type of expression.
 */

#ifndef __AMARA__SYNTAX_TREE__EXPRESSION_SUB_NATURAL_LITERAL__H__
#define __AMARA__SYNTAX_TREE__EXPRESSION_SUB_NATURAL_LITERAL__H__

/*   For `typedef struct natural { ... } natural;`. */
#include "../brt/brt_forward_declarations.h"

typedef struct stt_expression_sub_natural_literal {

	natural * natural_literal_;
} stt_expression_sub_natural_literal
;

stt_expression_sub_natural_literal *
stt_expression_sub_natural_literal_copy_constructor(
		const stt_expression_sub_natural_literal * expression_sub_natural_literal)
__attribute__((warn_unused_result))
;

stt_expression_sub_natural_literal *
stt_expression_sub_natural_literal_exhaustive_constructor(
		const natural * natural_literal)
__attribute__((warn_unused_result))
;

void
stt_expression_sub_natural_literal_destructor(
		stt_expression_sub_natural_literal * expression_sub_natural_literal)
;

#endif
