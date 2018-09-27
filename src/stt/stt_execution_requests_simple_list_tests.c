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
 * src/stt/stt_execution_requests_simple_list_tests.c: Test the Amara
 * syntax tree application execution requests simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_execution_requests_simple_list`. */
#include "stt_execution_requests_simple_list.h"

void
stt_execution_requests_simple_list_construct_and_destruct_test_0()
{
	stt_execution_requests_simple_list * list_;
	list_ = stt_execution_requests_simple_list_default_constructor();
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
	stt_execution_requests_simple_list_destructor(list_);
}

void
stt_execution_requests_simple_list_construct_and_destruct_test_1()
{
	stt_execution_requests_simple_list * list_zero_;
	stt_execution_requests_simple_list * list_one_;
	list_zero_ = stt_execution_requests_simple_list_default_constructor();
	list_one_ = stt_execution_requests_simple_list_copy_constructor(
			list_zero_);
	stt_execution_requests_simple_list_destructor(list_one_);
	stt_execution_requests_simple_list_destructor(list_zero_);
}

void
stt_execution_requests_simple_list_construct_and_destruct_test_2()
{
	stt_execution_requests_simple_list * list_zero_;
	stt_execution_requests_simple_list * list_one_;
	stt_execution_request * execution_request_;
	amara_string * execution_request_name_;
	list_zero_ = stt_execution_requests_simple_list_default_constructor();
	execution_request_ = stt_execution_request_default_constructor();
	assertion(execution_request_ != NULL);
	assertion(execution_request_->type_ ==
			STT_EXECUTION_REQUEST_TYPE_INVALID);
	execution_request_name_ = amara_string_exhaustive_constructor("foo");
	stt_execution_request_set_application_name(
			execution_request_, execution_request_name_);
	stt_execution_request_set_type(
			execution_request_,
			STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);
	list_zero_ = stt_execution_requests_simple_list_push_front(
			list_zero_, execution_request_);
	list_one_ = stt_execution_requests_simple_list_copy_constructor(
			list_zero_);
	stt_execution_requests_simple_list_destructor(list_one_);
	stt_execution_requests_simple_list_destructor(list_zero_);
}

void
stt_execution_requests_simple_list_construct_and_destruct_tests()
{
	stt_execution_requests_simple_list_construct_and_destruct_test_0();
	stt_execution_requests_simple_list_construct_and_destruct_test_1();
	stt_execution_requests_simple_list_construct_and_destruct_test_2();
}

void
stt_execution_requests_simple_list_tests()
{
	stt_execution_requests_simple_list_construct_and_destruct_tests();
}
