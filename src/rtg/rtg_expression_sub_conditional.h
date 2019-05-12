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
 * src/rtg/rtg_expression_sub_conditional.h: Amara run time graph
 * conditional type of expression.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__EXPRESSION_SUB_CONDITIONAL__H__
#define __AMARA__RUN_TIME_GRAPH__EXPRESSION_SUB_CONDITIONAL__H__

#include "rtg_forward_declarations.h"

/*   For `rtg_condition`. */
#include "rtg_condition.h"

#define RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID         0x00
#define RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE    0x0F
#define RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF 0xF0

typedef struct rtg_expression_sub_conditional_if {

	unsigned char type_;

	struct rtg_condition * condition_;

	struct rtg_expression * expression_then_;

	/**  Either this or `expression_else_` must be filled and set to
	 * non NULL. The other must be set NULL. */
	struct rtg_expression_sub_conditional_if * next_if_;

	/**  Either this or `next_if_` must be filled and set to non
	 * NULL. The other must be set NULL. */
	struct rtg_expression * expression_else_;
} rtg_expression_sub_conditional_if
;

typedef struct rtg_expression_sub_conditional {

	rtg_expression_sub_conditional_if * if_;
} rtg_expression_sub_conditional
;

rtg_expression_sub_conditional *
rtg_expression_sub_conditional_copy_constructor(
		const rtg_expression_sub_conditional * expression_sub_conditional)
__attribute__((warn_unused_result))
;

void
rtg_expression_sub_conditional_destructor(
		rtg_expression_sub_conditional * expression_sub_conditional)
;

rtg_expression_sub_conditional *
rtg_expression_sub_conditional_out_of_stt_expression_sub_conditional(
		const stt_expression_sub_conditional * expression_sub_conditional,
		const rtg_named_functions_simple_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
rtg_expression_sub_conditional_assert_validity(
		const rtg_expression_sub_conditional * expression_sub_conditional)
;

#endif

#endif
