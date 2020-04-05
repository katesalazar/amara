/*
 * Copyright 2018, 2020 Mercedes Catherine Salazar
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
 * src/rtg/rtg_expression_sub_string_literal.h: Amara run time graph
 * string literal type of expression.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__EXPRESSION_SUB_STRING_LITERAL__H__
#define __AMARA__RUN_TIME_GRAPH__EXPRESSION_SUB_STRING_LITERAL__H__

#include "rtg_forward_declarations.h"

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   For `stt_expression_sub_string_literal`. */
#include "../stt/stt_expression_sub_string_literal.h"

rtg_expression_sub_string_literal *
rtg_expression_sub_string_literal_copy_constructor(
		const rtg_expression_sub_string_literal * expression_sub_string_literal)
__attribute__((warn_unused_result))
;

void
rtg_expression_sub_string_literal_destructor(
		rtg_expression_sub_string_literal * expression_sub_string_literal)
;

rtg_expression_sub_string_literal *
rtg_expression_sub_string_literal_out_of_stt_expression_sub_string_literal(
		const stt_expression_sub_string_literal * expression_sub_string_literal)
__attribute__((warn_unused_result))
;

#endif
