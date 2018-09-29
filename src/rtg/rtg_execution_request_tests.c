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
 * src/rtg/rtg_execution_request_tests.c: Test the Amara run time graph
 * application execution request.
 */

#include "../asr/assertion.h"
#include "rtg_execution_request.h"
#include "rtg_function_tests.h"

void
rtg_execution_request_construct_and_destruct_test_0()
{
	rtg_execution_request * rtg_execution_request_;
	rtg_execution_request_ = rtg_execution_request_default_constructor();
	assertion(rtg_execution_request_ != NULL);
	assertion(rtg_execution_request_->type_ ==
			RTG_EXECUTION_REQUEST_TYPE_INVALID);
	assertion(rtg_execution_request_->application_ == NULL);
	rtg_execution_request_destructor(rtg_execution_request_);
}

void
rtg_execution_request_construct_and_destruct_test_1()
{
	rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret * rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_;
	stt_execution_request * stt_execution_request_;
	rtg_applications_simple_list * rtg_applications_;
	rtg_application * rtg_application_;
	stt_execution_request_ = stt_execution_request_default_constructor();
	assertion(stt_execution_request_ != NULL);
	stt_execution_request_->application_name_ =
			amara_string_exhaustive_constructor("foo");
	stt_execution_request_->type_ =
			STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION;
	rtg_applications_ = rtg_applications_simple_list_default_constructor();
	assertion(rtg_applications_ != NULL);
	assertion(rtg_applications_->first == NULL);
	assertion(rtg_applications_->next == NULL);
	rtg_application_ = rtg_application_default_constructor();
	assertion(rtg_application_ != NULL);
	assertion(rtg_application_->type_ == RTG_APPLICATION_TYPE_INVALID);
	assertion(rtg_application_->name_ == NULL);
	assertion(rtg_application_->entry_point_function_ == NULL);
	rtg_application_->name_ = amara_string_exhaustive_constructor("foo"); /* XXX */
	rtg_application_->entry_point_function_ = /* XXX */
			rtg_function_example_print_foo(); /* XXX */
	rtg_application_->type_ = RTG_APPLICATION_TYPE_CLI_APPLICATION; /* XXX */
	rtg_applications_ = rtg_applications_simple_list_push_front(
			rtg_applications_, rtg_application_);
	rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_ =
			rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list(
					stt_execution_request_,
					rtg_applications_);
	assertion(rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_ !=
			NULL);
	assertion(rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_->status ==
			RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_destructor(
			rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_);
	rtg_application_destructor(rtg_application_);
	stt_execution_request_destructor(stt_execution_request_);
}

void
rtg_execution_request_construct_and_destruct_tests()
{
	rtg_execution_request_construct_and_destruct_test_0();
	rtg_execution_request_construct_and_destruct_test_1();
}

void
rtg_execution_request_tests()
{
	rtg_execution_request_construct_and_destruct_tests();
}
