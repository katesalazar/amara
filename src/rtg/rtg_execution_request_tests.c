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
 * src/rtg/rtg_execution_request_tests.c: Test the Amara run time graph
 * application execution request.
 */

#include "../asr/assertion.h"

#include "rtg_application_tests.h"

#include "rtg_execution_request.h"

#include "rtg_named_function_tests.h"

#include "rtg_execution_request_tests.h"

rtg_execution_request *
rtg_execution_request_example_execute_foo()
{
	rtg_execution_request * returning_;
	rtg_application * application_;
	unsigned char requested_type_;

	requested_type_ = RTG_EXECUTION_REQUEST_TYPE_CLI_APPLICATION;

	application_ = rtg_application_example_cli_app_print_foo();
	forced_assertion(application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);
#endif

	returning_ = rtg_execution_request_exhaustive_constructor(
			requested_type_, application_);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);
#endif
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assertion(returning_->type_ ==
			RTG_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			returning_->application_);
#endif

	rtg_application_destructor(application_);

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_execution_request_example_execute_foo(
		const rtg_execution_request * execution_request)
{
	assertion(execution_request->type_ ==
			RTG_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);
	assertion(execution_request->application_ != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			execution_request->application_);
}

#endif

rtg_execution_request *
rtg_execution_request_example_execute_bar()
{
	rtg_execution_request * returning_;
	rtg_application * application_;
	unsigned char requested_type_;

	requested_type_ = RTG_EXECUTION_REQUEST_TYPE_CLI_APPLICATION;

	application_ = rtg_application_example_cli_app_print_bar();
	forced_assertion(application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			application_);
#endif

	returning_ = rtg_execution_request_exhaustive_constructor(
			requested_type_, application_);
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			application_);
#endif
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assertion(returning_->type_ ==
			RTG_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			returning_->application_);
#endif

	rtg_application_destructor(application_);

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_execution_request_example_execute_bar(
		const rtg_execution_request * execution_request)
{
	assertion(execution_request->type_ ==
			RTG_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);
	assertion(execution_request->application_ != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			execution_request->application_);
}

#endif

void
rtg_execution_request_default_constructor_test()
{
	rtg_execution_request * rtg_execution_request_;

	rtg_execution_request_ = rtg_execution_request_default_constructor();
	forced_assertion(rtg_execution_request_ != NULL);
#ifndef NDEBUG
	assertion(rtg_execution_request_->type_ ==
			RTG_EXECUTION_REQUEST_TYPE_INVALID);
	assertion(rtg_execution_request_->application_ == NULL);
#endif

	rtg_execution_request_destructor(rtg_execution_request_);
}

void
rtg_execution_request_default_constructor_tests(void)
;

void
rtg_execution_request_default_constructor_tests(void)
{
	rtg_execution_request_default_constructor_test();
}

tests_simple_list *
register_rtg_execution_request_default_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_execution_request_default_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& rtg_execution_request_default_constructor_test);
	return tests;
}

void
rtg_execution_request_transformation_constructor_test_0()
{
	rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret * rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_;
	stt_execution_request * stt_execution_request_;
	rtg_applications_simple_list * rtg_applications_;
	rtg_application * rtg_application_;

	stt_execution_request_ = stt_execution_request_default_constructor();
	forced_assertion(stt_execution_request_ != NULL);
#ifndef NDEBUG
	assertion(stt_execution_request_->type_ ==
			STT_EXECUTION_REQUEST_TYPE_INVALID);
	assertion(stt_execution_request_->application_name_ == NULL);
#endif

	/* XXX scope transgression */
	stt_execution_request_->application_name_ =
			amara_string_exhaustive_constructor("foo");
	forced_assertion(stt_execution_request_->application_name_ != NULL);

	/* XXX scope transgression */
	stt_execution_request_->type_ =
			STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION;

	rtg_applications_ = rtg_applications_simple_list_default_constructor();
	forced_assertion(rtg_applications_ != NULL);
#ifndef NDEBUG
	assertion(rtg_applications_->first == NULL);
	assertion(rtg_applications_->next == NULL);
#endif

	rtg_application_ = rtg_application_default_constructor();
	forced_assertion(rtg_application_ != NULL);
#ifndef NDEBUG
	assertion(rtg_application_->type_ == RTG_APPLICATION_TYPE_INVALID);
	assertion(rtg_application_->name_ == NULL);
	assertion(rtg_application_->entry_point_function_ == NULL);
#endif

	/* XXX scope transgression */
	rtg_application_->name_ = amara_string_exhaustive_constructor("foo"); /* XXX */
	forced_assertion(rtg_application_->name_ != NULL);

	/* XXX scope transgression */
	rtg_application_->entry_point_function_ = /* XXX */
			rtg_named_function_example_print_string_literal_foo(); /* XXX */
	forced_assertion(rtg_application_->entry_point_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			rtg_application_->entry_point_function_);
#endif

	/* XXX scope transgression */
	rtg_application_->type_ = RTG_APPLICATION_TYPE_CLI_APPLICATION; /* XXX */

	rtg_applications_ = rtg_applications_simple_list_push_front(
			rtg_applications_, rtg_application_);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			rtg_application_->entry_point_function_);
#endif
	forced_assertion(rtg_applications_ != NULL);
#ifndef NDEBUG
	assertion(rtg_applications_->first != NULL);
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			rtg_applications_->first->entry_point_function_);
	assertion(rtg_applications_->next == NULL);
#endif

	rtg_application_destructor(rtg_application_);

	rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_ =
			rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list(
					stt_execution_request_,
					rtg_applications_);
	forced_assertion(rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_ !=
			NULL);
#ifndef NDEBUG
	assertion(rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_->status ==
			RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
#endif

	stt_execution_request_destructor(stt_execution_request_);
	rtg_applications_simple_list_destructor(rtg_applications_);
	rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_destructor(
			rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_);
}

void
rtg_execution_request_transformation_constructor_test_1()
{
	rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret * rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_;
	stt_execution_request * stt_execution_request_;
	rtg_applications_simple_list * rtg_applications_;

	stt_execution_request_ = stt_execution_request_default_constructor();
	forced_assertion(stt_execution_request_ != NULL);
#ifndef NDEBUG
	assertion(stt_execution_request_->type_ ==
			STT_EXECUTION_REQUEST_TYPE_INVALID);
	assertion(stt_execution_request_->application_name_ == NULL);
#endif

	/* XXX scope transgression */
	stt_execution_request_->application_name_ =
			amara_string_exhaustive_constructor("foo");
	forced_assertion(stt_execution_request_->application_name_ != NULL);

	/* XXX scope transgression */
	stt_execution_request_->type_ =
			STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION;

	rtg_applications_ = rtg_applications_simple_list_default_constructor();
	forced_assertion(rtg_applications_ != NULL);
#ifndef NDEBUG
	assertion(rtg_applications_->first == NULL);
	assertion(rtg_applications_->next == NULL);
#endif

	rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_ =
			rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list(
					stt_execution_request_,
					rtg_applications_);
	forced_assertion(rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_ !=
			NULL);
#ifndef NDEBUG
	assertion(rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_->status ==
			RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_APPLICATION_NOT_FOUND);
#endif

	rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_destructor(
			rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_);
	stt_execution_request_destructor(stt_execution_request_);
}

void
rtg_execution_request_transformation_constructor_tests()
{
	rtg_execution_request_transformation_constructor_test_0();
	rtg_execution_request_transformation_constructor_test_1();
}

tests_simple_list *
register_rtg_execution_request_transformation_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_execution_request_transformation_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& rtg_execution_request_transformation_constructor_test_0);
	tests_simple_list_push_back(
			tests,
			& rtg_execution_request_transformation_constructor_test_1);
	return tests;
}

void
rtg_execution_request_constructors_tests()
{
	rtg_execution_request_default_constructor_tests();
	rtg_execution_request_transformation_constructor_tests();
}

tests_simple_list *
register_rtg_execution_request_constructors_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_execution_request_constructors_tests(tests_simple_list * tests)
{
	return register_rtg_execution_request_transformation_constructor_tests(
	       register_rtg_execution_request_default_constructor_tests(
	           tests));
}

void
rtg_execution_request_tests()
{
	rtg_execution_request_constructors_tests();
}

tests_simple_list *
register_rtg_execution_request_tests(tests_simple_list * tests)
{
	return register_rtg_execution_request_constructors_tests(tests);
}
