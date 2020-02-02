/*
 * Copyright 2018-2020 Mercedes Catherine Salazar
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
 * src/stt/stt_execution_request_tests.c: Test the Amara syntax tree
 * application execution request.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_execution_request`. */
#include "stt_execution_request.h"

#include "stt_execution_request_tests.h"

stt_execution_request *
stt_execution_request_example_print_foo()
{
	stt_execution_request * ret_;

	ret_ = stt_execution_request_default_constructor();
	forced_assertion(ret_ != NULL);

	ret_->application_name_ = amara_string_exhaustive_constructor(
			"cli_app_print_foo");
	forced_assertion(ret_->application_name_ != NULL);
#ifndef NDEBUG
	assertion(ret_->application_name_->value_ != NULL);
#endif

	ret_->type_ = STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION;

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_execution_request_example_print_foo(
		const stt_execution_request * execution_request)
{
	assertion(execution_request != NULL);
	assertion(execution_request->application_name_ != NULL);
	assertion(execution_request->application_name_->value_ != NULL);
	assertion(execution_request->type_ ==
			STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);
}

#endif

stt_execution_request *
stt_execution_request_example_print_baz()
{
	stt_execution_request * ret_;

	ret_ = stt_execution_request_default_constructor();
	assertion(ret_ != NULL);

	ret_->application_name_ = amara_string_exhaustive_constructor(
			"cli_app_print_baz");
	assertion(ret_->application_name_ != NULL);
	assertion(ret_->application_name_->value_ != NULL);
	ret_->type_ = STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION;

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_execution_request_example_print_baz(
		const stt_execution_request * execution_request)
{
	assertion(execution_request != NULL);
	assertion(execution_request->application_name_ != NULL);
	assertion(execution_request->application_name_->value_ != NULL);
	assertion(execution_request->type_ ==
			STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);
}

#endif

void
stt_execution_request_construct_and_destruct_test_0()
{
	stt_execution_request * execution_request_;
	execution_request_ = stt_execution_request_default_constructor();
	assertion(execution_request_ != NULL);
	assertion(execution_request_->type_ ==
			STT_EXECUTION_REQUEST_TYPE_INVALID);
	assertion(execution_request_->application_name_ == NULL);
	stt_execution_request_destructor(execution_request_);
}

void
stt_execution_request_construct_and_destruct_tests()
{
	stt_execution_request_construct_and_destruct_test_0();
}

tests_simple_list *
register_stt_execution_request_construct_and_destruct_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_execution_request_construct_and_destruct_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& stt_execution_request_construct_and_destruct_test_0);
	return tests;
}

void
stt_execution_request_tests()
{
	stt_execution_request_construct_and_destruct_tests();
}

tests_simple_list *
register_stt_execution_request_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_execution_request_construct_and_destruct_tests(
			tests);
	return returning_;
}
