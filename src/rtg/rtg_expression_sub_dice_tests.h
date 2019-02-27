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
 * src/rtg/rtg_expression_sub_dice_test_tests.h: Amara run time graph
 * dice type of expression tests.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__EXPRESSION_SUB_DICE_TESTS__H__
#define __AMARA__RUN_TIME_GRAPH__EXPRESSION_SUB_DICE_TESTS__H__

/*   For `typedef struct rtg_expression_sub_dice { ... }
 * rtg_expression_sub_dice;`. */
#include "rtg_expression_sub_dice.h"

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_sub_dice_example_single_vanilla_dice(
		const rtg_expression_sub_dice * expression_sub_dice)
;

#endif

void
rtg_expression_sub_dice_tests(void)
;

#endif
