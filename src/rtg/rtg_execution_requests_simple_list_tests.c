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
 * src/rtg/rtg_execution_requests_simple_list_tests.c: Test the Amara
 * run time graph application execution requests simple list.
 */

#include "../asr/assertion.h"
#include "../stt/stt_execution_request_tests.h"

#include "rtg_application_tests.h"
#include "rtg_execution_request_tests.h"
#include "rtg_execution_requests_simple_list.h"

#include "rtg_execution_requests_simple_list_tests.h"

void
rtg_execution_requests_simple_list_construct_and_destruct_test_0()
{
	rtg_execution_requests_simple_list * list_zero_;
	rtg_execution_requests_simple_list * list_one_;

	list_zero_ = rtg_execution_requests_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	list_one_ = rtg_execution_requests_simple_list_copy_constructor(
			list_zero_);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	rtg_execution_requests_simple_list_destructor(list_one_);
	rtg_execution_requests_simple_list_destructor(list_zero_);
}

void
rtg_execution_requests_simple_list_construct_and_destruct_test_1()
{
	rtg_execution_requests_simple_list * list_zero_;
	rtg_execution_requests_simple_list * list_one_;
	rtg_execution_request * execution_request_zero_;
	rtg_execution_request * execution_request_one_;

	list_zero_ = rtg_execution_requests_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	execution_request_zero_ = rtg_execution_request_example_execute_foo();
	assertion(execution_request_zero_ != NULL);
	assertion(execution_request_zero_->application_ != NULL);

	execution_request_one_ = rtg_execution_request_example_execute_bar();
	assertion(execution_request_one_ != NULL);
	assertion(execution_request_one_->application_ != NULL);

	list_zero_ = rtg_execution_requests_simple_list_push_front(
			list_zero_, execution_request_zero_);
	assertion(list_zero_->first != NULL);
	assertion(list_zero_->next == NULL);

	list_zero_ = rtg_execution_requests_simple_list_push_front(
			list_zero_, execution_request_one_);
	assertion(list_zero_->first != NULL);
	assertion(list_zero_->next != NULL);
	assertion(list_zero_->next->first != NULL);
	assertion(list_zero_->next->next == NULL);

	list_one_ = rtg_execution_requests_simple_list_copy_constructor(
			list_zero_);
	assertion(list_zero_->first != NULL);
	assertion(list_zero_->next != NULL);
	assertion(list_zero_->next->first != NULL);
	assertion(list_zero_->next->next == NULL);
	assertion(list_one_ != NULL);
	assertion(list_one_->first != NULL);
	assertion(list_one_->next != NULL);
	assertion(list_one_->next->first != NULL);
	assertion(list_one_->next->next == NULL);

	rtg_execution_requests_simple_list_destructor(list_one_);
	rtg_execution_requests_simple_list_destructor(list_zero_);
}

void
rtg_execution_requests_simple_list_construct_and_destruct_tests()
{
	rtg_execution_requests_simple_list_construct_and_destruct_test_0();
	rtg_execution_requests_simple_list_construct_and_destruct_test_1();
}

/**  Try to create run time graph execution requests out of a NULL
 * syntax tree execution requests list. */
void
rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_test_0()
{
	rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret * target_ret_;
	stt_execution_requests_simple_list * stt_execution_requests_;
	rtg_applications_simple_list * rtg_applications_;

	stt_execution_requests_ = NULL;
	rtg_applications_ = NULL;

	target_ret_ = rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list(
			stt_execution_requests_, rtg_applications_);
	assertion(target_ret_ != NULL);
	assertion(target_ret_->status ==
			RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC);
	assertion(target_ret_->execution_requests == NULL);
}

/**  Try to create run time graph execution requests out of a syntax
 * execution requests list with more than one element. */
void
rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_test_1()
{
	amara_string * expected_execution_request_application_name_;
	stt_execution_request * stt_execution_request_zero_;
	stt_execution_request * stt_execution_request_one_;
	stt_execution_requests_simple_list * stt_execution_requests_;
	/*
	amara_boolean * equality_;
	*/
	rtg_application * rtg_application_;
	rtg_applications_simple_list * rtg_applications_;
	rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret * target_ret_;

	expected_execution_request_application_name_ =
			amara_string_exhaustive_constructor(
					"cli_app_print_foo");
	assertion(expected_execution_request_application_name_ != NULL);
	assertion(expected_execution_request_application_name_->value_ !=
			NULL);

	stt_execution_request_zero_ =
			stt_execution_request_example_print_foo();
	assertion(stt_execution_request_zero_ != NULL);
	/*
	assertion(stt_execution_request_zero_->application_name_ != NULL);
	assertion(stt_execution_request_zero_->application_name_->value_ !=
			NULL);
	equality_ = amara_string_equality(
			expected_execution_request_application_name_,
			stt_execution_request_zero_->application_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	*/
	assert_expectations_on_stt_execution_request_example_print_foo(
			stt_execution_request_zero_); /* TODO and remove the prior checks. */

	stt_execution_request_one_ =
			stt_execution_request_example_print_foo();
	assertion(stt_execution_request_one_ != NULL);
	/*
	assertion(stt_execution_request_one_->application_name_ != NULL);
	assertion(stt_execution_request_one_->application_name_->value_ !=
			NULL);
	equality_ = amara_string_equality(
			expected_execution_request_application_name_,
			stt_execution_request_one_->application_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	*/
	assert_expectations_on_stt_execution_request_example_print_foo(
			stt_execution_request_one_); /* TODO and remove the prior checks. */

	stt_execution_requests_ =
			stt_execution_requests_simple_list_default_constructor();
	assertion(stt_execution_requests_ != NULL);
	assertion(stt_execution_requests_->first == NULL);
	assertion(stt_execution_requests_->next == NULL);

	stt_execution_requests_ =
			stt_execution_requests_simple_list_push_front(
					stt_execution_requests_,
					stt_execution_request_one_);
	assertion(stt_execution_requests_ != NULL);
	assertion(stt_execution_requests_->first != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			stt_execution_requests_->first);
	assertion(stt_execution_requests_->next == NULL);

	stt_execution_requests_ =
			stt_execution_requests_simple_list_push_front(
					stt_execution_requests_,
					stt_execution_request_zero_);
	assertion(stt_execution_requests_ != NULL);
	assertion(stt_execution_requests_->first != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			stt_execution_requests_->first);
	assertion(stt_execution_requests_->next != NULL);
	assertion(stt_execution_requests_->next->first != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			stt_execution_requests_->next->first);
	assertion(stt_execution_requests_->next->next == NULL);

	rtg_application_ = rtg_application_example_cli_app_print_foo();
	assertion(rtg_application_ != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			rtg_application_);

	rtg_applications_ = rtg_applications_simple_list_default_constructor();
	assertion(rtg_applications_ != NULL);
	assertion(rtg_applications_->first == NULL);
	assertion(rtg_applications_->next == NULL);

	rtg_applications_ = rtg_applications_simple_list_push_front(
			rtg_applications_, rtg_application_);
	assertion(rtg_applications_ != NULL);
	assertion(rtg_applications_->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			rtg_applications_->first);
	assertion(rtg_applications_->next == NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			rtg_application_);

	target_ret_ = rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list(
			stt_execution_requests_, rtg_applications_);
	assertion(target_ret_ != NULL);
	assertion(target_ret_->status ==
			RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	assertion(target_ret_->execution_requests != NULL);

	rtg_applications_simple_list_destructor(rtg_applications_);
	rtg_application_destructor(rtg_application_);
	stt_execution_requests_simple_list_destructor(stt_execution_requests_);
	stt_execution_request_destructor(stt_execution_request_one_);
	stt_execution_request_destructor(stt_execution_request_zero_);
	amara_string_destructor(expected_execution_request_application_name_);
}

void
rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_tests()
{
	rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_test_0();
	rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_test_1();
}

void
rtg_execution_requests_simple_list_tests()
{
	rtg_execution_requests_simple_list_construct_and_destruct_tests();
	rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_tests();
}
