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
 * src/rtg/rtg_operation_args_simple_list_tests.c: Test the Amara run
 * time graph operation args simple list.
 */

#include "../asr/assertion.h"

#include "../stt/stt_operation_args_simple_list_tests.h"

#include "rtg_named_functions_simple_list.h"

#include "rtg_operation_arg_tests.h"

#include "rtg_operation_args_simple_list.h"

#include "rtg_operation_args_simple_list_tests.h"

rtg_operation_args_simple_list *
rtg_operation_args_simple_list_example_two_args_list()
{
	rtg_operation_args_simple_list * ret_;
	rtg_operation_arg * arg_zero_;
	rtg_operation_arg * arg_one_;


	ret_ = rtg_operation_args_simple_list_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first == NULL);
	assertion(ret_->next == NULL);
#endif

	arg_zero_ = rtg_operation_arg_example_string_literal_foo();
	forced_assertion(arg_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			arg_zero_);
#endif

	arg_one_ = rtg_operation_arg_example_string_literal_foo();
	forced_assertion(arg_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			arg_one_);
#endif

	ret_ = rtg_operation_args_simple_list_push_front(
			ret_, arg_zero_);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			arg_zero_);
#endif
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			ret_->first);
	assertion(ret_->next == NULL);
#endif

	ret_ = rtg_operation_args_simple_list_push_front(
			ret_, arg_one_);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			arg_one_);
#endif
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			ret_->first);
	assertion(ret_->next != NULL);
	assertion(ret_->next->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			ret_->next->first);
	assertion(ret_->next->next == NULL);
#endif

	rtg_operation_arg_destructor(arg_zero_);
	rtg_operation_arg_destructor(arg_one_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_args_simple_list_example_two_args_list(
		const rtg_operation_args_simple_list * list)
{
	assertion(list != NULL);
	assertion(list->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			list->first);
	assertion(list->next != NULL);
	assertion(list->next->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			list->next->first);
	assertion(list->next->next == NULL);
}

#endif

void
rtg_operation_args_simple_list_default_constructor_test()
{
	rtg_operation_args_simple_list * operation_args_list_;

	operation_args_list_ =
			rtg_operation_args_simple_list_default_constructor();
	assertion(operation_args_list_ != NULL);
	assertion(operation_args_list_->first == NULL);
	assertion(operation_args_list_->next == NULL);

	rtg_operation_args_simple_list_destructor(operation_args_list_);
}

void
rtg_operation_args_simple_list_copy_constructor_test_0()
{
	rtg_operation_args_simple_list * operation_args_list_zero_;
	rtg_operation_args_simple_list * operation_args_list_one_;

	operation_args_list_zero_ =
			rtg_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_list_zero_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_list_zero_->first == NULL);
	assertion(operation_args_list_zero_->next == NULL);
#endif

	operation_args_list_one_ =
			rtg_operation_args_simple_list_copy_constructor(
					operation_args_list_zero_);
#ifndef NDEBUG
	assertion(operation_args_list_zero_->first == NULL);
	assertion(operation_args_list_zero_->next == NULL);
#endif
	forced_assertion(operation_args_list_one_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_list_one_->first == NULL);
	assertion(operation_args_list_one_->next == NULL);
#endif

	rtg_operation_args_simple_list_destructor(operation_args_list_one_);
	rtg_operation_args_simple_list_destructor(operation_args_list_zero_);
}

void
rtg_operation_args_simple_list_copy_constructor_test_1()
{
	rtg_operation_args_simple_list * operation_args_list_zero_;
	rtg_operation_arg * operation_arg_;
	rtg_operation_args_simple_list * operation_args_list_one_;

	operation_args_list_zero_ =
			rtg_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_list_zero_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_list_zero_->first == NULL);
	assertion(operation_args_list_zero_->next == NULL);
#endif

	operation_arg_ = rtg_operation_arg_example_string_literal_foo();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			operation_arg_);
#endif

	operation_args_list_zero_ = rtg_operation_args_simple_list_push_front(
			operation_args_list_zero_, operation_arg_);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			operation_arg_);
#endif
	forced_assertion(operation_args_list_zero_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_list_zero_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			operation_args_list_zero_->first);
	assertion(operation_args_list_zero_->next == NULL);
#endif

	rtg_operation_arg_destructor(operation_arg_);

	operation_args_list_one_ =
			rtg_operation_args_simple_list_copy_constructor(
					operation_args_list_zero_);
#ifndef NDEBUG
	assertion(operation_args_list_zero_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			operation_args_list_zero_->first);
	assertion(operation_args_list_zero_->next == NULL);
#endif
	forced_assertion(operation_args_list_one_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_list_one_->first !=  NULL);
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			operation_args_list_one_->first);
	assertion(operation_args_list_one_->next == NULL);
#endif

	rtg_operation_args_simple_list_destructor(operation_args_list_one_);
	rtg_operation_args_simple_list_destructor(operation_args_list_zero_);
}

void
rtg_operation_args_simple_list_copy_constructor_test_2()
{
	rtg_operation_args_simple_list * operation_args_list_zero_;
	rtg_operation_arg * operation_arg_zero_;
	rtg_operation_arg * operation_arg_one_;
	rtg_operation_args_simple_list * operation_args_list_one_;

	operation_args_list_zero_ =
			rtg_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_list_zero_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_list_zero_->first == NULL);
	assertion(operation_args_list_zero_->next == NULL);
#endif

	operation_arg_zero_ = rtg_operation_arg_example_string_literal_foo();
	forced_assertion(operation_arg_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			operation_arg_zero_);
#endif

	operation_args_list_zero_ = rtg_operation_args_simple_list_push_front(
			operation_args_list_zero_, operation_arg_zero_);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			operation_arg_zero_);
#endif
	forced_assertion(operation_args_list_zero_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_list_zero_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			operation_args_list_zero_->first);
	assertion(operation_args_list_zero_->next == NULL);
#endif

	rtg_operation_arg_destructor(operation_arg_zero_);

	operation_arg_one_ = rtg_operation_arg_example_identifier_bar();
	forced_assertion(operation_arg_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_arg_one_);
#endif

	operation_args_list_zero_ = rtg_operation_args_simple_list_push_front(
			operation_args_list_zero_, operation_arg_one_);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_arg_one_);
#endif
	forced_assertion(operation_args_list_zero_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_list_zero_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_args_list_zero_->first);
	assertion(operation_args_list_zero_->next != NULL);
	assertion(operation_args_list_zero_->next->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			operation_args_list_zero_->next->first);
	assertion(operation_args_list_zero_->next->next == NULL);
#endif

	rtg_operation_arg_destructor(operation_arg_one_);

	operation_args_list_one_ =
			rtg_operation_args_simple_list_copy_constructor(
					operation_args_list_zero_);
#ifndef NDEBUG
	assertion(operation_args_list_zero_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_args_list_zero_->first);
	assertion(operation_args_list_zero_->next != NULL);
	assertion(operation_args_list_zero_->next->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			operation_args_list_zero_->next->first);
	assertion(operation_args_list_zero_->next->next == NULL);
#endif
	forced_assertion(operation_args_list_one_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_list_one_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_args_list_one_->first);
	assertion(operation_args_list_one_->next != NULL);
	assertion(operation_args_list_one_->next->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
			operation_args_list_one_->next->first);
	assertion(operation_args_list_one_->next->next == NULL);
#endif

	rtg_operation_args_simple_list_destructor(operation_args_list_one_);
	rtg_operation_args_simple_list_destructor(operation_args_list_zero_);
}

void
rtg_operation_args_simple_list_copy_constructor_tests()
{
	rtg_operation_args_simple_list_copy_constructor_test_0();
	rtg_operation_args_simple_list_copy_constructor_test_1();
	rtg_operation_args_simple_list_copy_constructor_test_2();
}

void
rtg_operation_args_simple_list_transformation_constructor_test_0()
{
	stt_operation_args_simple_list * stt_operation_args_;
	rtg_named_functions_simple_list * rtg_named_functions_;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret * transformation_ret_;
	rtg_operation_args_simple_list * rtg_operation_args_;

	stt_operation_args_ =
			stt_operation_args_simple_list_example_two_args_list();
	forced_assertion(stt_operation_args_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_args_simple_list_example_two_args_list(
			stt_operation_args_);
#endif

	rtg_named_functions_ =
			rtg_named_functions_simple_list_default_constructor();
	forced_assertion(rtg_named_functions_ != NULL);

	transformation_ret_ =
			rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list(
					stt_operation_args_,
					STT_OPERATION_TYPE_PRINT,
					NULL,
					rtg_named_functions_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_args_simple_list_example_two_args_list(
			stt_operation_args_);
#endif
	forced_assertion(transformation_ret_ != NULL);
	forced_assertion(transformation_ret_->status ==
			RTG_OPERATION_ARGS_SIMPLE_LIST_OUT_OF_STT_OPERATION_ARGS_SIMPLE_LIST_RET_STATUS_SUCCESS);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_args_simple_list_example_two_args_list(
			transformation_ret_->operation_args);
#endif

	stt_operation_args_simple_list_destructor(stt_operation_args_);

	rtg_operation_args_ = transformation_ret_->operation_args;

	free(transformation_ret_);

	rtg_named_functions_simple_list_deep_destructor(rtg_named_functions_);

	rtg_operation_args_simple_list_destructor(rtg_operation_args_);
}

void
rtg_operation_args_simple_list_transformation_constructor_tests()
{
	rtg_operation_args_simple_list_transformation_constructor_test_0();
}

void
rtg_operation_args_simple_list_constructors_tests()
{
	rtg_operation_args_simple_list_default_constructor_test();
	rtg_operation_args_simple_list_copy_constructor_tests();
	rtg_operation_args_simple_list_transformation_constructor_tests();
}

void
rtg_operation_args_simple_list_length_test_0()
{
	rtg_operation_args_simple_list * list_;
	unsigned char length_;

	list_ = rtg_operation_args_simple_list_example_two_args_list();
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_args_simple_list_example_two_args_list(
			list_);
#endif

	length_ = rtg_operation_args_simple_list_length(list_);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_args_simple_list_example_two_args_list(
			list_);
#endif
	forced_assertion(length_ == 2);

	rtg_operation_args_simple_list_destructor(list_);
}

void
rtg_operation_args_simple_list_length_tests()
{
	rtg_operation_args_simple_list_length_test_0();
}

void
rtg_operation_args_simple_list_tests()
{
	rtg_operation_args_simple_list_constructors_tests();
	rtg_operation_args_simple_list_length_tests();
}
