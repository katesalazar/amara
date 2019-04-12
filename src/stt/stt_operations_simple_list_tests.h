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
 * src/stt/stt_operations_simple_list_tests.h: Test the Amara syntax
 * tree application function operations simple list.
 */

#ifndef __AMARA__SYNTAX_TREE__OPERATIONS_SIMPLE_LIST_TESTS__H__
#define __AMARA__SYNTAX_TREE__OPERATIONS_SIMPLE_LIST_TESTS__H__

stt_operations_simple_list *
stt_operations_simple_list_example_print_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operations_simple_list_example_print_foo(
		const stt_operations_simple_list * operations)
;

#endif

stt_operations_simple_list *
stt_operations_simple_list_example_print_string_literal_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operations_simple_list_example_print_string_literal_foo(
		const stt_operations_simple_list * operations)
;

#endif

stt_operations_simple_list *
stt_operations_simple_list_example_print_identifier_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operations_simple_list_example_print_identifier_foo(
		const stt_operations_simple_list * operations)
;

#endif

void
stt_operations_simple_list_tests(void)
;

#endif
