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
 * src/rtg/rtg_condition.h: Amara run time graph condition.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__CONDITION__H__
#define __AMARA__RUN_TIME_GRAPH__CONDITION__H__

/*   For `rtg_expression`. */
#include "rtg_expression.h"

#include "rtg_forward_declarations.h"

typedef unsigned char rtg_condition_type;

#define RTG_CONDITION_TYPE_INVALID                     0x00
#define RTG_CONDITION_TYPE_LESS_THAN                   0x01
/* #define RTG_CONDITION_TYPE_EQUAL_TO                 0x02 */
#define RTG_CONDITION_TYPE_GREATER_THAN                0x03
/* #define RTG_CONDITION_TYPE_GREATER_THAN_OR_EQUAL_TO 0x04 */
/* #define RTG_CONDITION_TYPE_NOT_EQUAL_TO             0x05 */
/* #define RTG_CONDITION_TYPE_LESS_THAN_OR_EQUAL_TO    0x06 */

/*
rtg_condition_type
rtg_condition_type_ill(void)
__attribute__((warn_unused_result))
;
*/

amara_boolean
rtg_condition_type_is_valid(rtg_condition_type condition_type)
__attribute__((warn_unused_result))
;

/*
amara_boolean
rtg_condition_type_is_known(rtg_condition_type condition_type)
__attribute__((warn_unused_result))
;

amara_boolean
rtg_condition_type_is_ill(rtg_condition_type condition_type)
__attribute__((warn_unused_result))
;
*/

typedef struct rtg_condition {

	rtg_condition_type type_;

	struct rtg_expression * left_hand_side_expression_;

	struct rtg_expression * right_hand_side_expression_;
} rtg_condition
;

rtg_condition *
rtg_condition_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_condition *
rtg_condition_copy_constructor(const rtg_condition * condition)
__attribute__((warn_unused_result))
;

void
rtg_condition_destructor(rtg_condition * condition)
;

/**  Transformation constructor. Will flip `less than` type of
 * conditions into `greater than` type of conditions, and vice versa. */
rtg_condition *
rtg_condition_flip(const rtg_condition * condition)
__attribute__((warn_unused_result))
;

/**  Transformation constructor. */
rtg_condition *
rtg_condition_out_of_stt_condition(
		const stt_condition * condition,
		const rtg_named_functions_simple_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
rtg_condition_assert_validity(const rtg_condition * condition)
;

#endif

#endif
