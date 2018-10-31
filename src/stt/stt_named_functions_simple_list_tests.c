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
 * src/stt/stt_named_functions_simple_list_tests.c: Test the Amara
 * syntax tree application named functions simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "stt_named_function_tests.h"

/*   For `stt_named_functions_simple_list`. */
/* #include "stt_named_functions_simple_list.h" */

#include "stt_node.h"

void
stt_named_functions_simple_list_construct_and_destruct_test_0()
{
	stt_named_functions_simple_list * list_;

	list_ = stt_named_functions_simple_list_default_constructor();
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);

	stt_named_functions_simple_list_destructor(list_);
}

void
stt_named_functions_simple_list_construct_and_destruct_test_1()
{
	stt_named_functions_simple_list * list_zero_;
	stt_named_functions_simple_list * list_one_;

	list_zero_ = stt_named_functions_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	list_one_ = stt_named_functions_simple_list_copy_constructor(
			list_zero_);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	stt_named_functions_simple_list_destructor(list_zero_);
	stt_named_functions_simple_list_destructor(list_one_);
}

void
stt_named_functions_simple_list_construct_and_destruct_test_2()
{
	stt_named_functions_simple_list * list_zero_;
	stt_named_functions_simple_list * list_one_;
	stt_named_function * named_function_;

	list_zero_ = stt_named_functions_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	named_function_ = stt_named_function_example_print_foo();
	assertion(named_function_ != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_);

	list_zero_ = stt_named_functions_simple_list_push_front(
			list_zero_, named_function_);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_);
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			list_zero_->first);
	assertion(list_zero_->next == NULL);

	list_one_ = stt_named_functions_simple_list_copy_constructor(
			list_zero_);
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			list_zero_->first);
	assertion(list_zero_->next == NULL);
	assertion(list_one_ != NULL);
	assertion(list_one_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			list_one_->first);
	assertion(list_one_->next == NULL);

	stt_named_functions_simple_list_destructor(list_one_);
	stt_named_function_destructor(named_function_);
	stt_named_functions_simple_list_destructor(list_zero_);
}

void
stt_named_functions_simple_list_construct_and_destruct_test_3()
{
	stt_named_functions_simple_list * list_zero_;
	stt_named_functions_simple_list * list_one_;
	stt_named_function * named_function_zero_;
	stt_named_function * named_function_one_;

	list_zero_ = stt_named_functions_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	named_function_zero_ = stt_named_function_example_print_bar();
	assertion(named_function_zero_ != NULL);
	assert_expectations_on_stt_named_function_example_print_bar(
			named_function_zero_);

	named_function_one_ = stt_named_function_example_print_foo();
	assertion(named_function_one_ != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_one_);

	list_zero_ = stt_named_functions_simple_list_push_front(
			list_zero_, named_function_zero_);
	assert_expectations_on_stt_named_function_example_print_bar(
			named_function_zero_);
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_bar(
			list_zero_->first);
	assertion(list_zero_->next == NULL);

	list_zero_ = stt_named_functions_simple_list_push_front(
			list_zero_, named_function_one_);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_one_);
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			list_zero_->first);
	assertion(list_zero_->next != NULL);
	assertion(list_zero_->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_bar(
			list_zero_->next->first);
	assertion(list_zero_->next->next == NULL);

	list_one_ = stt_named_functions_simple_list_copy_constructor(
			list_zero_);
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			list_zero_->first);
	assertion(list_zero_->next != NULL);
	assertion(list_zero_->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_bar(
			list_zero_->next->first);
	assertion(list_zero_->next->next == NULL);
	assertion(list_one_ != NULL);
	assertion(list_one_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			list_one_->first);
	assertion(list_one_->next != NULL);
	assertion(list_one_->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_bar(
			list_one_->next->first);
	assertion(list_one_->next->next == NULL);

	stt_named_functions_simple_list_destructor(list_one_);
	stt_named_function_destructor(named_function_one_);
	stt_named_function_destructor(named_function_zero_);
	stt_named_functions_simple_list_destructor(list_zero_);
}

void
stt_named_functions_simple_list_construct_and_destruct_tests()
{
	stt_named_functions_simple_list_construct_and_destruct_test_0();
	stt_named_functions_simple_list_construct_and_destruct_test_1();
	stt_named_functions_simple_list_construct_and_destruct_test_2();
	stt_named_functions_simple_list_construct_and_destruct_test_3();
}

void
stt_named_functions_simple_list_tests()
{
	stt_named_functions_simple_list_construct_and_destruct_tests();
}
