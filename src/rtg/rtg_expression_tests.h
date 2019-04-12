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
 * src/rtg/rtg_expression_tests.h: Test the Amara run time graph
 * expression.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__EXPRESSION_TESTS__H__
#define __AMARA__RUN_TIME_GRAPH__EXPRESSION_TESTS__H__

/*   For `rtg_expression`. */
#include "rtg_expression.h"

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_string_literal_foo(
		const rtg_expression * expression)
;

#endif

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_string_literal_bar(
		const rtg_expression * expression)
;

#endif

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_natural_literal_zero(
		const rtg_expression * expression)
;

#endif

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_natural_literal_one(
		const rtg_expression * expression)
;

#endif

rtg_expression *
rtg_expression_example_identifier_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_identifier_foo(
		const rtg_expression * expression)
;

#endif

/**  `1d6`. */
rtg_expression *
rtg_expression_example_single_vanilla_dice(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_single_vanilla_dice(
		const rtg_expression * expression)
;

#endif

/**  `if 0 less than 1 then 'true' else 'false' end if`. */
rtg_expression *
rtg_expression_example_simple_conditional(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_simple_conditional(
		const rtg_expression * expression)
;

#endif

void
rtg_expression_tests(void)
;

#endif
