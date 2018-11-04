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
 * src/stt/stt_operation_tests.h: Test the Amara syntax tree application
 * function operation.
 */

#ifndef __AMARA__SYNTAX_TREE__OPERATION_TESTS__H__
#define __AMARA__SYNTAX_TREE__OPERATION_TESTS__H__

#include "stt_operation.h"

stt_operation *
stt_operation_example_print_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_example_print_foo(
		const stt_operation * operation)
;

#endif

stt_operation *
stt_operation_example_print_bar(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_example_print_bar(
		const stt_operation * operation)
;

#endif

stt_operation *
stt_operation_example_print_foo_no_crlf(void)
__attribute__((warn_unused_result))
;

void
stt_operation_tests(void)
;

#endif
