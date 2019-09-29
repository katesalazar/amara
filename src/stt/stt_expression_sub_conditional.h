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
 * src/stt/stt_expression_sub_conditional.h: Amara syntax tree
 * conditional type of expression.
 */

#ifndef __AMARA__SYNTAX_TREE__EXPRESSION_SUB_CONDITIONAL__H__
#define __AMARA__SYNTAX_TREE__EXPRESSION_SUB_CONDITIONAL__H__

/*   For `stt_condition`. */
#include "stt_condition.h"

/*   For `stt_expression`. */
/* #include "stt_expression.h" */

#define STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID         0x21  /* 33: '!'. */
#define STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE    0x22  /* 34: '"'. */
#define STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE_IF 0x23  /* 35: '#'. */

/**  This `struct` is the soul of the conditional expression. It is a
 * linked list of _if_ type of conditions, and _then_ expressions,
 * terminated by a (required) _else_ expression. */
typedef struct stt_expression_sub_conditional_if {

	unsigned char type_;

	struct stt_condition * condition_;

	struct stt_expression * expression_then_;

	/**  Either this or `expression_else_` must be filled and set to
	 * non NULL. The other must be set NULL. */
	struct stt_expression_sub_conditional_if * next_if_;

	/**  Either this or `next_if_` must be filled and set to non
	 * NULL. The other must be set NULL. */
	struct stt_expression * expression_else_;
} stt_expression_sub_conditional_if
;

/**  This `struct` is the body of the conditional expression. It simply
 * stores a pointer to a linked list representing the different
 * conditions and corresponding expressions for the conditional cases. */
typedef struct stt_expression_sub_conditional {

	stt_expression_sub_conditional_if * if_;
} stt_expression_sub_conditional
;

stt_expression_sub_conditional *
stt_expression_sub_conditional_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_expression_sub_conditional *
stt_expression_sub_conditional_copy_constructor(
		const stt_expression_sub_conditional * expression_sub_conditional)
__attribute__((warn_unused_result))
;

void
stt_expression_sub_conditional_destructor(
		stt_expression_sub_conditional * expression_sub_conditional)
;

void
stt_expression_sub_conditional_set_condition(
		stt_expression_sub_conditional * sub_conditional,
		const struct stt_condition * condition)
;

void
stt_expression_sub_conditional_set_expression_then(
		stt_expression_sub_conditional * sub_conditional,
		const struct stt_expression * expression_then)
;

void
stt_expression_sub_conditional_set_expression_else(
		stt_expression_sub_conditional * sub_conditional,
		const struct stt_expression * expression_else)
;

amara_boolean
stt_expression_sub_conditional_equality(
		const stt_expression_sub_conditional * esc0,
		const stt_expression_sub_conditional * esc1)
__attribute__((warn_unused_result))
;

amara_boolean
stt_expression_sub_conditionals_equality(
		const stt_expression_sub_conditional * esc0,
		const stt_expression_sub_conditional * esc1)
__attribute__((warn_unused_result))
;

#endif
