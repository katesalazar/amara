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
 * src/stt/stt_expression_sub_dice_tests.h: Test the Amara syntax tree
 * dice type of expression.
 */

#ifndef __AMARA__SYNTAX_TREE__EXPRESSION_SUB_DICE_TESTS__H__
#define __AMARA__SYNTAX_TREE__EXPRESSION_SUB_DICE_TESTS__H__

/*   For `stt_expression_sub_dice`. */
#include "stt_expression_sub_dice.h"

stt_expression_sub_dice *
stt_expression_sub_dice_example_single_vanilla_dice(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
		const stt_expression_sub_dice * sub_dice)
;

#endif

void
stt_expression_sub_dice_tests(void)
;

#endif
