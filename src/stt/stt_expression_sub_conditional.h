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
 * src/stt/stt_expression_sub_conditional.h: Amara syntax tree
 * conditional type of expression.
 */

#ifndef __AMARA__SYNTAX_TREE__EXPRESSION_SUB_CONDITIONAL__H__
#define __AMARA__SYNTAX_TREE__EXPRESSION_SUB_CONDITIONAL__H__

typedef struct stt_expression_sub_conditional_if {

	stt_condition * condition_;

	stt_expression * expression_then_;

	/**  Either this or `expression_else_` must be filled and set to
	 * non NULL. The other must be set NULL. */
	stt_expression_sub_conditional_if * expression_next_if_;

	/**  Either this or `expression_next_if_` must be filled and set
	 * to non NULL. The other must be set NULL. */
	stt_expression * expression_else_;
} stt_expression_sub_conditional_if
;

typedef struct stt_expression_sub_conditional {

	stt_expression_sub_conditional_if * if_;
} stt_expression_sub_conditional
;

/*
stt_expression_sub_conditional *
stt_expression_sub_conditional_copy_constructor(const stt_expression * expression)
__attribute__((warn_unused_result))
;
*/

#endif
