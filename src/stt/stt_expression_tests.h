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
 * src/stt/stt_expression_tests.h: Test the Amara syntax tree expression.
 */

#ifndef __AMARA__SYNTAX_TREE__EXPRESSION_TESTS__H__
#define __AMARA__SYNTAX_TREE__EXPRESSION_TESTS__H__

#include "../tst/tests_simple_list.h"

/*   For `stt_expression`. */
#include "stt_expression.h"

/**  `0`. */
stt_expression *
stt_expression_example_natural_zero(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_example_natural_zero(
		const stt_expression * expression)
;

#endif

/**  `1`. */
stt_expression *
stt_expression_example_natural_one(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_example_natural_one(
		const stt_expression * expression)
;

#endif

/**  `'foo'`. */
stt_expression *
stt_expression_example_string_literal_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_example_string_literal_foo(
		const stt_expression * expression)
;

#endif

/**  `'bar'`. */
stt_expression *
stt_expression_example_string_literal_bar(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_example_string_literal_bar(
		const stt_expression * expression)
;

#endif

/**  `foo`. */
stt_expression *
stt_expression_example_identifier_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_example_identifier_foo(
		const stt_expression * expression)
;

#endif

/**  `1d6`. */
stt_expression *
stt_expression_example_single_vanilla_dice(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_example_single_vanilla_dice(
		const stt_expression * expression)
;

#endif

/**  `if 0 less than 1 then 'foo' else 'bar' end if`. */
stt_expression *
stt_expression_example_simple_conditional(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_example_simple_conditional(
		const stt_expression * expression)
;

#endif

void
stt_expression_tests(void)
;

tests_simple_list *
register_stt_expression_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

#endif
