/*
 * Copyright 2018 Mercedes Catherine Salazar
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
 * src/stt/stt_node_tests.h: Test the Amara syntax tree node.
 */

#ifndef __AMARA__SYNTAX_TREE__NODE_TESTS__H__
#define __AMARA__SYNTAX_TREE__NODE_TESTS__H__

stt_node *
stt_node_example_operation_print_foo(void)
__attribute__((warn_unused_result))
;

void
assert_expectations_on_stt_node_example_operation_print_foo(
		const stt_node * node)
;

stt_node *
stt_node_example_operation_print_bar(void)
__attribute__((warn_unused_result))
;

void
assert_expectations_on_stt_node_example_operation_print_bar(
		const stt_node * node)
;

stt_node *
stt_node_example_operations_list_print_foo_and_then_print_bar(void)
__attribute__((warn_unused_result))
;

void
assert_expectations_on_stt_node_example_operations_list_print_foo_and_then_print_bar(
		const stt_node * node)
;

stt_node *
stt_node_example_named_function_print_foo(void)
__attribute__((warn_unused_result))
;

void
assert_expectations_on_stt_node_example_named_function_print_foo(
		const stt_node * node)
;

stt_node *
stt_node_example_application_print_foo(void)
__attribute__((warn_unused_result))
;

void
assert_expectations_on_stt_node_example_application_print_foo(
		const stt_node * node)
;

void
stt_node_tests(void)
;

#endif
