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
 * src/stt/stt_operation_tests.h: Test the Amara syntax tree application
 * function operation.
 */

#ifndef __AMARA__SYNTAX_TREE__OPERATION_TESTS__H__
#define __AMARA__SYNTAX_TREE__OPERATION_TESTS__H__

#include "../tst/tests_simple_list.h"

#include "stt_operation.h"

stt_operation *
stt_operation_example_print_string_literal_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_example_print_string_literal_foo(
		const stt_operation * operation)
;

#endif

stt_operation *
stt_operation_example_print_string_literal_bar(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_example_print_string_literal_bar(
		const stt_operation * operation)
;

#endif

stt_operation *
stt_operation_example_print_string_literal_foo_no_crlf(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_example_print_string_literal_foo_no_crlf(
		const stt_operation * operation)
;

#endif

stt_operation *
stt_operation_example_print_identifier_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_example_print_identifier_foo(
		const stt_operation * operation)
;

#endif

stt_operation *
stt_operation_example_read_natural_into_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_example_read_natural_into_foo(
		const stt_operation * operation)
;

#endif

stt_operation *
stt_operation_example_read_integer_into_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_example_read_integer_into_foo(
		const stt_operation * operation)
;

#endif

void
stt_operation_tests(void)
;

tests_simple_list *
register_stt_operation_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

#endif
