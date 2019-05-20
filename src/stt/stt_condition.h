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
 * src/stt/stt_condition.h: Amara syntax tree condition.
 */

#ifndef __AMARA__SYNTAX_TREE__CONDITION__H__
#define __AMARA__SYNTAX_TREE__CONDITION__H__

#include <stdlib.h>

/*   For `typedef unsigned char amara_boolean`. */
#include "../cmn/amara_boolean.h"

/*   For `typedef struct stt_expression { ... } stt_expression`. */
#include "stt_expression.h"

#define STT_CONDITION_TYPE_INVALID                     0x00
#define STT_CONDITION_TYPE_LESS_THAN                   0x01
/* #define STT_CONDITION_TYPE_EQUAL_TO                 0x02 */
#define STT_CONDITION_TYPE_GREATER_THAN                0x03
/* #define STT_CONDITION_TYPE_GREATER_THAN_OR_EQUAL_TO 0x04 */
/* #define STT_CONDITION_TYPE_NOT_EQUAL_TO             0x05 */
/* #define STT_CONDITION_TYPE_LESS_THAN_OR_EQUAL_TO    0x06 */

/**  Condition elements. */
typedef struct stt_condition {

	/**  The type of condition, e.g. an equality condition (if so,
	 * of type `STT_CONDITION_TYPE_EQUAL_TO`. */
	unsigned char type_;

	/**  If the condition is an expressions equality, or an
	 * expressions inequality, or a mixture, then condition operator
	 * is a _binary_ conditional operator, so this is the first
	 * element of the equation or inequation. */
	struct stt_expression * left_hand_side_expression_;


	/**  If the condition is an expressions equality, or an
	 * expressions inequality, or a mixture, then condition operator
	 * is a _binary_ conditional operator, so this is the second
	 * element of the equation or inequation. */
	struct stt_expression * right_hand_side_expression_;
} stt_condition
;

stt_condition *
stt_condition_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_condition *
stt_condition_copy_constructor(const stt_condition * condition)
__attribute__((warn_unused_result))
;

void
stt_condition_destructor(stt_condition * condition)
;

void
stt_condition_initialize_less_than(
		stt_condition * condition,
		const struct stt_expression * left_hand_side_expression,
		const struct stt_expression * right_hand_side_expression)
;

void
stt_condition_initialize_greater_than(
		stt_condition * condition,
		const struct stt_expression * left_hand_side_expression,
		const struct stt_expression * right_hand_side_expression)
;

amara_boolean
stt_condition_equality(const stt_condition * c0, const stt_condition * c1)
__attribute__((warn_unused_result))
;

#endif
