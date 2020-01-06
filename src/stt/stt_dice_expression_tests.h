/*
 * Copyright 2018-2020 Mercedes Catherine Salazar
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
 * src/stt/stt_dice_expression_tests.h: Test the Amara syntax tree dice
 * expression.
 */

#ifndef __AMARA__SYNTAX_TREE__DICE_EXPRESSION_TESTS__H__
#define __AMARA__SYNTAX_TREE__DICE_EXPRESSION_TESTS__H__

#include "../tst/tests_simple_list.h"

/*   For `typedef struct stt_dice_expression { ... }
 * stt_dice_expression;` eventually in `stt_forward_declarations.h`
 * actually. */
#include "stt_dice_expression.h"

#ifndef NDEBUG

void
assert_expectations_on_stt_dice_expression_example_single_vanilla_dice(
		const stt_dice_expression * dice_expression)
;

#endif

stt_dice_expression *
stt_dice_expression_example_single_vanilla_dice(void)
__attribute__((warn_unused_result))
;

void
stt_dice_expression_tests(void)
;

tests_simple_list *
register_stt_dice_expression_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

#endif
