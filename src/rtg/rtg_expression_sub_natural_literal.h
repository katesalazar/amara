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
 * src/rtg/rtg_expression_sub_natural_literal.h: Amara run time graph
 * natural literal type of expression.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__EXPRESSION_SUB_NATURAL_LITERAL__H__
#define __AMARA__RUN_TIME_GRAPH__EXPRESSION_SUB_NATURAL_LITERAL__H__

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `natural`. */
#include "../brt/natural.h"

/*   For `stt_expression_sub_natural_literal`. */
#include "../stt/stt_expression_sub_natural_literal.h"

typedef struct rtg_expression_sub_natural_literal {

	natural * natural_literal_;
} rtg_expression_sub_natural_literal
;

/**  Copy constructor. */
rtg_expression_sub_natural_literal *
rtg_expression_sub_natural_literal_copy_constructor(
		const rtg_expression_sub_natural_literal * expression_sub_natural_literal)
__attribute__((warn_unused_result))
;

/**  Destructor. */
void
rtg_expression_sub_natural_literal_destructor(
		rtg_expression_sub_natural_literal * expression_sub_natural_literal)
;

#ifndef NDEBUG

/**  Health check. */
void
rtg_expression_sub_natural_literal_assert_healthy(
		const rtg_expression_sub_natural_literal * expression_sub_natural_literal)
;

#endif

/**  Transformation constructor. */
rtg_expression_sub_natural_literal *
rtg_expression_sub_natural_literal_out_of_stt_expression_sub_natural_literal(
		const stt_expression_sub_natural_literal * expression_sub_natural_literal)
__attribute__((warn_unused_result))
;

#endif
