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
 * src/stt/stt_operations_simple_list_tests.c: Test the Amara syntax
 * tree application function operations simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_operation * stt_operation_example_print_foo()`. */
#include "stt_operation_tests.h"

/*   For `typedef struct stt_operations_simple_list { ... }
 * stt_operations_simple_list`. */
#include "stt_operations_simple_list.h"

stt_operations_simple_list *
stt_operations_simple_list_example_print_foo(void)
{
	stt_operations_simple_list * operations_;
	stt_operation * operation_;

	operations_ = stt_operations_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(operations_ != NULL);
	assertion(operations_->first == NULL);
	assertion(operations_->next == NULL);
#endif

	operation_ = stt_operation_example_print_string_literal_foo();
#ifndef NDEBUG
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operation_);
#endif

	stt_operations_simple_list_push_back(operations_, operation_);
#ifndef NDEBUG
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operation_);
	assertion(operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operations_->first);
	assertion(operations_->next == NULL);
#endif

	stt_operation_destructor(operation_);

	return operations_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operations_simple_list_example_print_foo(
		const stt_operations_simple_list * operations)
{
	assertion(operations != NULL);
	assertion(operations->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operations->first);
	assertion(operations->next == NULL);
}

#endif

/*

stt_operations_simple_list *
stt_operations_simple_list_example_print_string_literal_foo(void)
{
	return stt_operations_simple_list_example_print_foo();
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operations_simple_list_example_print_string_literal_foo(
		const stt_operations_simple_list * operations)
{
	forced_assertion(operations != NULL);
	assert_expectations_on_stt_operations_simple_list_example_print_foo(
			operations);
}

#endif

*/

stt_operations_simple_list *
stt_operations_simple_list_example_print_identifier_foo(void)
{
	stt_operation * operation_;
	stt_operations_simple_list * ret_;

	operation_ = stt_operation_example_print_identifier_foo();
	forced_assertion(operation_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			operation_);
#endif

	ret_ = stt_operations_simple_list_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first == NULL);
	assertion(ret_->next == NULL);
#endif

	stt_operations_simple_list_push_back(ret_, operation_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			operation_);
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			ret_->first);
	assertion(ret_->next == NULL);
#endif

	stt_operation_destructor(operation_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operations_simple_list_example_print_identifier_foo(
		const stt_operations_simple_list * operations)
{
	assertion(operations != NULL);
	assertion(operations->first != NULL);
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			operations->first);
	assertion(operations->next == NULL);
}

#endif

void
stt_operations_simple_list_construct_and_destruct_test_0()
{
	stt_operations_simple_list * list_;
	list_ = stt_operations_simple_list_default_constructor();
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
	stt_operations_simple_list_destructor(list_);
}

void
stt_operations_simple_list_construct_and_destruct_tests()
{
	stt_operations_simple_list_construct_and_destruct_test_0();
}

void
stt_operations_simple_list_tests()
{
	stt_operations_simple_list_construct_and_destruct_tests();
}
