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
 * src/stt/stt_operation_args_simple_list_tests.c: Test the Amara syntax
 * tree application function operation arguments simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "../stt/stt_operation_arg_tests.h"

/*   For `stt_operation_args_simple_list`. */
#include "stt_operation_args_simple_list.h"

stt_operation_args_simple_list *
stt_operation_args_simple_list_example_two_args_list()
{
	stt_operation_arg * operation_arg_;
	stt_operation_args_simple_list * ret_;

	operation_arg_ = stt_operation_arg_example_string_literal_foo();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			operation_arg_);
#endif

	ret_ = stt_operation_args_simple_list_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first == NULL);
	assertion(ret_->next == NULL);
#endif

	ret_ = stt_operation_args_simple_list_push_front(ret_, operation_arg_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			operation_arg_);
#endif
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			ret_->first);
	assertion(ret_->next == NULL);
#endif

	ret_ = stt_operation_args_simple_list_push_front(ret_, operation_arg_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			operation_arg_);
#endif
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			ret_->first);
#endif
	forced_assertion(ret_->next != NULL);
	forced_assertion(ret_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			ret_->next->first);
	assertion(ret_->next->next == NULL);
#endif

	stt_operation_arg_destructor(operation_arg_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_args_simple_list_example_two_args_list(
		const stt_operation_args_simple_list * list)
{
	assertion(list != NULL);
	assertion(list->first != NULL);
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			list->first);
	assertion(list->next != NULL);
	assertion(list->next->first != NULL);
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			list->next->first);
	assertion(list->next->next == NULL);
}

#endif

void
stt_operation_args_simple_list_copy_constructor_test_0()
{
	stt_operation_args_simple_list * stt_operation_args_simple_list_original;
	stt_operation_args_simple_list * stt_operation_args_simple_list_clone;

	stt_operation_args_simple_list_original =
			stt_operation_args_simple_list_default_constructor();
	forced_assertion(stt_operation_args_simple_list_original != NULL);
#ifndef NDEBUG
	assertion(stt_operation_args_simple_list_original->first == NULL);
	assertion(stt_operation_args_simple_list_original->next == NULL);
#endif

	stt_operation_args_simple_list_clone =
			stt_operation_args_simple_list_copy_constructor(
					stt_operation_args_simple_list_original);
	forced_assertion(stt_operation_args_simple_list_clone != NULL);
#ifndef NDEBUG
	assertion(stt_operation_args_simple_list_clone->first == NULL);
	assertion(stt_operation_args_simple_list_clone->next == NULL);
#endif

	stt_operation_args_simple_list_destructor(
			stt_operation_args_simple_list_original);
	stt_operation_args_simple_list_destructor(
			stt_operation_args_simple_list_clone);
}

void
stt_operation_args_simple_list_copy_constructor_tests()
{
	stt_operation_args_simple_list_copy_constructor_test_0();
}

void
stt_operation_args_simple_list_tests()
{
	stt_operation_args_simple_list_copy_constructor_tests();
}
