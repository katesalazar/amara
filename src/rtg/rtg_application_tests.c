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
 * src/rtg/rtg_application_tests.c: Test the Amara run time graph
 * application.
 */

#include "../asr/assertion.h"

#include "../stt/stt_application_tests.h"

#include "rtg_named_function_tests.h"

#include "rtg_application_tests.h"

rtg_application *
rtg_application_example_cli_app_print_foo()
{
	rtg_application * application_;
	amara_string * application_name_;
	rtg_named_function * entry_point_function_;
	application_ = rtg_application_default_constructor();
	assertion(application_ != NULL);
	assertion(application_->type_ == RTG_APPLICATION_TYPE_INVALID);
	assertion(application_->name_ == NULL);
	assertion(application_->entry_point_function_ == NULL);
	application_name_ = amara_string_exhaustive_constructor(
			"cli_app_print_foo");
	application_->name_ = application_name_; /* XXX */
	entry_point_function_ =
			rtg_named_function_example_print_string_literal_foo();
	application_->entry_point_function_ = entry_point_function_; /* XXX */
	application_->type_ = RTG_APPLICATION_TYPE_CLI_APPLICATION;
	return application_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_application_example_cli_app_print_foo(
		const rtg_application * application)
{
	amara_string * expected_application_name_;
	rtg_named_function * function_;
	amara_string * expected_function_name_;
	rtg_operation * operation_;
	rtg_operation_arg * operation_arg_;
	amara_string * expected_string_literal_;
	amara_boolean equality_;

	expected_application_name_ = amara_string_exhaustive_constructor(
			"cli_app_print_foo");
	assertion(expected_application_name_ != NULL);
	assertion(expected_application_name_->value_ != NULL);

	expected_function_name_ = amara_string_exhaustive_constructor(
			"print_foo");
	assertion(expected_function_name_ != NULL);
	assertion(expected_function_name_->value_ != NULL);

	expected_string_literal_ = amara_string_exhaustive_constructor("foo");
	assertion(expected_string_literal_ != NULL);
	assertion(expected_string_literal_->value_ != NULL);

	assertion(application != NULL);
	assertion(application->type_ == RTG_APPLICATION_TYPE_CLI_APPLICATION);
	assertion(application->name_ != NULL);
	assertion(application->name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_application_name_, application->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(application->entry_point_function_ != NULL);
	function_ = application->entry_point_function_;
	assertion(function_->type_ ==
			RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(function_->name_ != NULL);
	assertion(function_->name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_function_name_, function_->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(function_->operations_ != NULL);
	assertion(function_->operations_->first != NULL);
	operation_ = function_->operations_->first;
	assertion(operation_->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first != NULL);
	operation_arg_ = operation_->args_->first;
	assertion(operation_arg_->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operation_arg_->string_literal_ != NULL);
	assertion(operation_arg_->string_literal_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_string_literal_,
			operation_arg_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(operation_->args_->next == NULL);
	assertion(function_->operations_->next == NULL);

	amara_string_destructor(expected_string_literal_);
	amara_string_destructor(expected_function_name_);
	amara_string_destructor(expected_application_name_);
}

#endif

rtg_application *
rtg_application_example_cli_app_print_bar()
{
	rtg_application * application_;
	amara_string * application_name_;
	rtg_named_function * entry_point_function_;
	application_ = rtg_application_default_constructor();
	assertion(application_ != NULL);
	assertion(application_->type_ == RTG_APPLICATION_TYPE_INVALID);
	assertion(application_->name_ == NULL);
	assertion(application_->entry_point_function_ == NULL);
	application_name_ = amara_string_exhaustive_constructor(
			"cli_app_print_bar");
	application_->name_ = application_name_; /* XXX */
	entry_point_function_ =
			rtg_named_function_example_print_string_literal_bar();
	application_->entry_point_function_ = entry_point_function_; /* XXX */
	application_->type_ = RTG_APPLICATION_TYPE_CLI_APPLICATION;
	return application_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_application_example_cli_app_print_bar(
		const rtg_application * application)
{
	amara_string * expected_application_name_;
	rtg_named_function * function_;
	amara_string * expected_function_name_;
	rtg_operation * operation_;
	rtg_operation_arg * operation_arg_;
	amara_string * expected_string_literal_;
	amara_boolean equality_;

	expected_application_name_ = amara_string_exhaustive_constructor(
			"cli_app_print_bar");
	assertion(expected_application_name_ != NULL);
	assertion(expected_application_name_->value_ != NULL);

	expected_function_name_ = amara_string_exhaustive_constructor(
			"print_bar");
	assertion(expected_function_name_ != NULL);
	assertion(expected_function_name_->value_ != NULL);

	expected_string_literal_ = amara_string_exhaustive_constructor("bar");
	assertion(expected_string_literal_ != NULL);
	assertion(expected_string_literal_->value_ != NULL);

	assertion(application != NULL);
	assertion(application->type_ == RTG_APPLICATION_TYPE_CLI_APPLICATION);
	assertion(application->name_ != NULL);
	assertion(application->name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_application_name_, application->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(application->entry_point_function_ != NULL);
	function_ = application->entry_point_function_;
	assertion(function_->type_ ==
			RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(function_->name_ != NULL);
	assertion(function_->name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_function_name_, function_->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(function_->operations_ != NULL);
	assertion(function_->operations_->first != NULL);
	operation_ = function_->operations_->first;
	assertion(operation_->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first != NULL);
	operation_arg_ = operation_->args_->first;
	assertion(operation_arg_->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operation_arg_->string_literal_ != NULL);
	assertion(operation_arg_->string_literal_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_string_literal_,
			operation_arg_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(operation_->args_->next == NULL);
	assertion(function_->operations_->next == NULL);

	amara_string_destructor(expected_string_literal_);
	amara_string_destructor(expected_function_name_);
	amara_string_destructor(expected_application_name_);
}

#endif

void
rtg_application_construct_and_destruct_test_0()
{
	rtg_application * application_;

	application_ = rtg_application_default_constructor();
	assertion(application_ != NULL);
	assertion(application_->type_ == RTG_APPLICATION_TYPE_INVALID);
	assertion(application_->name_ == NULL);
	assertion(application_->entry_point_function_ == NULL);

	rtg_application_destructor(application_);
}

void
rtg_application_construct_and_destruct_tests()
{
	rtg_application_construct_and_destruct_test_0();
}

void
rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_test_0()
{
	stt_application * stt_application_;
	rtg_named_functions_simple_list * rtg_named_functions_;
	rtg_named_function * rtg_named_function_;
	rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret * target_;

	stt_application_ = stt_application_example_print_foo();
	forced_assertion(stt_application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			stt_application_);
#endif

	rtg_named_functions_ =
			rtg_named_functions_simple_list_default_constructor();
	assertion(rtg_named_functions_ != NULL);
	assertion(rtg_named_functions_->first == NULL);
	assertion(rtg_named_functions_->next == NULL);

	rtg_named_function_ =
			rtg_named_function_example_print_string_literal_foo();
	assertion(rtg_named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			rtg_named_function_);
#endif

	rtg_named_functions_ = rtg_named_functions_simple_list_push_front(
			rtg_named_functions_, rtg_named_function_);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			rtg_named_function_);
#endif
	assertion(rtg_named_functions_ != NULL);
	assertion(rtg_named_functions_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			rtg_named_functions_->first);
#endif
	assertion(rtg_named_functions_->next == NULL);

	target_ = rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list(
			stt_application_, rtg_named_functions_);
	assertion(target_ != NULL);
	assertion(target_->status ==
			RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	assertion(target_->application != NULL);

	rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret_destructor(
			target_);
	rtg_named_function_destructor(rtg_named_function_);
	rtg_named_functions_simple_list_deep_destructor(rtg_named_functions_);
	stt_application_destructor(stt_application_);
}

/**  This is like `void
 * rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_test_0()`,
 * just moving the result before destruction. */
/*
void
rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_test_1()
{
	stt_application * stt_application_;
	rtg_named_functions_simple_list * rtg_named_functions_;
	rtg_named_function * rtg_named_function_;
	rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret * target_;
	rtg_application * rtg_application_;

	stt_application_ = stt_application_example_print_foo();
	forced_assertion(stt_application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			stt_application_);
#endif

	rtg_named_functions_ =
			rtg_named_functions_simple_list_default_constructor();
	assertion(rtg_named_functions_ != NULL);
	assertion(rtg_named_functions_->first == NULL);
	assertion(rtg_named_functions_->next == NULL);

	rtg_named_function_ = rtg_named_function_example_print_foo();
	assertion(rtg_named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_foo(
			rtg_named_function_);
#endif

	rtg_named_functions_ = rtg_named_functions_simple_list_push_front(
			rtg_named_functions_, rtg_named_function_);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_foo(
			rtg_named_function_);
#endif
	assertion(rtg_named_functions_ != NULL);
	assertion(rtg_named_functions_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_foo(
			rtg_named_functions_->first);
#endif
	assertion(rtg_named_functions_->next == NULL);

	target_ = rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list(
			stt_application_, rtg_named_functions_);
	assertion(target_ != NULL);
	assertion(target_->status ==
			RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	assertion(target_->application != NULL);
	assertion(target_->application_was_moved == AMARA_BOOLEAN_FALSE);

	target_->application_was_moved = AMARA_BOOLEAN_TRUE;
	rtg_application_ = target_->application;

	rtg_application_destructor(rtg_application_);
	rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret_destructor(
			target_);
	rtg_named_function_destructor(rtg_named_function_);
	rtg_named_functions_simple_list_destructor(rtg_named_functions_);
	stt_application_destructor(stt_application_);
}
*/

void
rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_tests()
{
	rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_test_0();
	/*
	rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_test_1();
	*/
}

void
rtg_application_tests()
{
	rtg_application_construct_and_destruct_tests();
	rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_tests();
}
