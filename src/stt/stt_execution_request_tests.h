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
 * src/stt/stt_execution_request_tests.h: Test the Amara syntax tree
 * application execution request.
 */

#ifndef __AMARA__SYNTAX_TREE__EXECUTION_REQUEST_TESTS__H__
#define __AMARA__SYNTAX_TREE__EXECUTION_REQUEST_TESTS__H__

#include "../tst/tests_simple_list.h"

#include "stt_execution_request.h"

stt_execution_request *
stt_execution_request_example_print_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_execution_request_example_print_foo(
		const stt_execution_request * execution_request)
;

#endif

stt_execution_request *
stt_execution_request_example_print_baz(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_execution_request_example_print_baz(
		const stt_execution_request * execution_request)
;

#endif

void
stt_execution_request_tests(void)
;

tests_simple_list *
register_stt_execution_request_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

#endif
