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
 * src/rtg/rtg_operation_tests.h: Test the Amara runtime graph
 * application function operation.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__OPERATION_TESTS__H__
#define __AMARA__RUN_TIME_GRAPH__OPERATION_TESTS__H__

#include "rtg_operation.h"

rtg_operation *
rtg_operation_example_print_string_literal_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_example_print_string_literal_foo(
		const rtg_operation * operation)
;

#endif

rtg_operation *
rtg_operation_example_print_string_literal_bar(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_example_print_string_literal_bar(
		const rtg_operation * operation)
;

#endif

rtg_operation *
rtg_operation_example_read_natural_into_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_example_read_natural_into_foo(
		const rtg_operation * operation)
;

#endif

rtg_operation *
rtg_operation_example_read_integer_into_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_example_read_integer_into_foo(
		const rtg_operation * operation)
;

#endif

/*

rtg_operation *
rtg_operation_example_print_integer_literal(void)
__attribute__((warn_unused_result))
;

*/

/*

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_example_print_integer_literal(
		const rtg_operation * operation)
;

#endif

*/

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_example_print_identifier_foo(
		const rtg_operation * operation)
;

#endif

void
rtg_operation_tests(void)
;

#endif