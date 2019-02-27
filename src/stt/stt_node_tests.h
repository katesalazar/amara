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
 * src/stt/stt_node_tests.h: Test the Amara syntax tree node.
 */

#ifndef __AMARA__SYNTAX_TREE__NODE_TESTS__H__
#define __AMARA__SYNTAX_TREE__NODE_TESTS__H__

#include "stt_node.h"

stt_node *
stt_node_example_natural_literal_zero(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_natural_literal_zero(
		const stt_node * node)
;

#endif

stt_node *
stt_node_example_natural_literal_one(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_natural_literal_one(
		const stt_node * node)
;

#endif

stt_node *
stt_node_example_expression_natural_literal_zero(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_expression_natural_literal_zero(
		const stt_node * node)
;

#endif

stt_node *
stt_node_example_expression_natural_literal_one(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_expression_natural_literal_one(
		const stt_node * node)
;

#endif

stt_node *
stt_node_example_operation_print_string_literal_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_operation_print_string_literal_foo(
		const stt_node * node)
;

#endif

stt_node *
stt_node_example_operation_print_bar(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_operation_print_bar(
		const stt_node * node)
;

#endif

stt_node *
stt_node_example_operations_list_print_string_literal_foo_and_then_print_string_literal_bar(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_operations_list_print_string_literal_foo_and_then_print_string_literal_bar(
		const stt_node * node)
;

#endif

stt_node *
stt_node_example_named_function_print_string_literal_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_named_function_print_string_literal_foo(
		const stt_node * node)
;

#endif

stt_node *
stt_node_example_application_print_string_literal_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_application_print_string_literal_foo(
		const stt_node * node)
;

#endif

stt_node *
stt_node_example_execution_request(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_execution_request(
		const stt_node * node)
;

#endif

/**  A syntax tree node holding a document holding a named function.
 * There are no references to other functions. */
stt_node *
stt_node_example_doc_zero(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_zero(
		const stt_node * node)
;

#endif

/**  A syntax tree node holding a document holding a named function and
 * an application which uses it. There are no missing references. */
stt_node *
stt_node_example_doc_one(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_one(
		const stt_node * node)
;

#endif

/**  A syntax tree node holding a document holding an application which
 * uses a named function that is not defined. */
stt_node *
stt_node_example_doc_two(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_two(
		const stt_node * node)
;

#endif

/**  A syntax tree node holding a document holding two named functions
 * and an application, but none of the functions is the requested entry
 * point named function for the application. */
stt_node *
stt_node_example_doc_three(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_three(
		const stt_node * node)
;

#endif

/**  A syntax tree node holding a document holding one execution request
 * but no named functions or application requests. */
stt_node *
stt_node_example_doc_four(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_four(
		const stt_node * node)
;

#endif

/**   A syntax tree node holding a document holding two applications and
 * one execution request, but none of the applications is that what the
 * execution requests wants. */
stt_node *
stt_node_example_doc_five(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_five(
		const stt_node * node)
;

#endif

/**   A syntax tree node holding a document holding one application
 * execution request, the requested application, and the entry point
 * function for that application. */
stt_node *
stt_node_example_doc_six(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_six(
		const stt_node * node)
;

#endif

void
stt_node_tests(void)
;

#endif
