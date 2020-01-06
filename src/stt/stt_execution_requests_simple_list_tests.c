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
 * src/stt/stt_execution_requests_simple_list_tests.c: Test the Amara
 * syntax tree application execution requests simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_execution_request *
 * stt_execution_request_example_print_foo()`. */
#include "stt_execution_request_tests.h"

/*   For `stt_execution_requests_simple_list`. */
#include "stt_execution_requests_simple_list.h"

#include "stt_execution_requests_simple_list_tests.h"

void
stt_execution_requests_simple_list_default_constructor_test()
{
	stt_execution_requests_simple_list * list_;

	list_ = stt_execution_requests_simple_list_default_constructor();
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
#endif

	stt_execution_requests_simple_list_destructor(list_);
}

void
stt_execution_requests_simple_list_construct_and_destruct_test_0()
{
	stt_execution_requests_simple_list * list_zero_;
	stt_execution_requests_simple_list * list_one_;

	list_zero_ = stt_execution_requests_simple_list_default_constructor();
	forced_assertion(list_zero_ != NULL);

	list_one_ = stt_execution_requests_simple_list_copy_constructor(
			list_zero_);
	forced_assertion(list_one_ != NULL);

	stt_execution_requests_simple_list_destructor(list_one_);
	stt_execution_requests_simple_list_destructor(list_zero_);
}

void
stt_execution_requests_simple_list_construct_and_destruct_test_1()
{
	stt_execution_requests_simple_list * list_zero_;
	stt_execution_requests_simple_list * list_one_;
	stt_execution_request * execution_request_;
	amara_string * execution_request_name_;

	list_zero_ = stt_execution_requests_simple_list_default_constructor();
	forced_assertion(list_zero_ != NULL);
#ifndef NDEBUG
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);
#endif

	execution_request_ = stt_execution_request_default_constructor();
	forced_assertion(execution_request_ != NULL);
#ifndef NDEBUG
	assertion(execution_request_->type_ ==
			STT_EXECUTION_REQUEST_TYPE_INVALID);
#endif

	execution_request_name_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(execution_request_name_ != NULL);
#ifndef NDEBUG
	assertion(execution_request_name_->value_ != NULL);
#endif

	stt_execution_request_set_application_name(
			execution_request_, execution_request_name_);
	/* XXX missing assertions here. */

	amara_string_destructor(execution_request_name_);

	stt_execution_request_set_type(
			execution_request_,
			STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);
	/* XXX missing assertions here? */

	list_zero_ = stt_execution_requests_simple_list_push_front(
			list_zero_, execution_request_);
	/* XXX missing assertions here. */

	stt_execution_request_destructor(execution_request_);

	list_one_ = stt_execution_requests_simple_list_copy_constructor(
			list_zero_);
	/* XXX missing assertions here. */

	stt_execution_requests_simple_list_destructor(list_one_);
	stt_execution_requests_simple_list_destructor(list_zero_);
}

void
stt_execution_requests_simple_list_construct_and_destruct_test_2()
{
	stt_execution_requests_simple_list * list_zero_;
	stt_execution_requests_simple_list * list_one_;
	stt_execution_request * execution_request_zero_;
	stt_execution_request * execution_request_one_;
	amara_string * execution_request_zero_application_name_;
	amara_string * execution_request_one_application_name_;

	list_zero_ = stt_execution_requests_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first ==  NULL);
	assertion(list_zero_->next ==  NULL);

	execution_request_zero_ =
			stt_execution_request_default_constructor();
	assertion(execution_request_zero_ != NULL);
	assertion(execution_request_zero_->type_ ==
			STT_EXECUTION_REQUEST_TYPE_INVALID);
	assertion(execution_request_zero_->application_name_ == NULL);

	execution_request_zero_application_name_ =
			amara_string_exhaustive_constructor("foo");
	assertion(execution_request_zero_application_name_ != NULL);
	assertion(execution_request_zero_application_name_->value_ != NULL);

	stt_execution_request_set_application_name(
			execution_request_zero_,
			execution_request_zero_application_name_);
	assertion(execution_request_zero_->application_name_ != NULL);
	assertion(execution_request_zero_->application_name_->value_ != NULL);

	amara_string_destructor(execution_request_zero_application_name_);

	stt_execution_request_set_type(
			execution_request_zero_,
			STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);
	assertion(execution_request_zero_->type_ ==
			STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);

	execution_request_one_ =
			stt_execution_request_default_constructor();
	assertion(execution_request_one_ != NULL);
	assertion(execution_request_one_->type_ ==
			STT_EXECUTION_REQUEST_TYPE_INVALID);
	assertion(execution_request_one_->application_name_ == NULL);

	execution_request_one_application_name_ =
			amara_string_exhaustive_constructor("bar");
	assertion(execution_request_one_application_name_ != NULL);
	assertion(execution_request_one_application_name_->value_ != NULL);

	stt_execution_request_set_application_name(
			execution_request_one_,
			execution_request_one_application_name_);
	assertion(execution_request_one_->application_name_ != NULL);
	assertion(execution_request_one_->application_name_->value_ != NULL);

	amara_string_destructor(execution_request_one_application_name_);

	stt_execution_request_set_type(
			execution_request_one_,
			STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);
	assertion(execution_request_one_->type_ ==
			STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);

	list_zero_ = stt_execution_requests_simple_list_push_front(
			list_zero_, execution_request_zero_);
#ifndef NDEBUG
	assertion(list_zero_ != NULL);
#endif
	/* XXX add missing assertions. */

	list_zero_ = stt_execution_requests_simple_list_push_front(
			list_zero_, execution_request_one_);
#ifndef NDEBUG
	assertion(list_zero_ != NULL);
#endif
	/* XXX add missing assertions. */

	list_one_ = stt_execution_requests_simple_list_copy_constructor(
			list_zero_);
	forced_assertion(list_one_ != NULL);
	/* XXX add missing assertions. */

	stt_execution_requests_simple_list_destructor(list_one_);
	stt_execution_request_destructor(execution_request_one_);
	stt_execution_request_destructor(execution_request_zero_);
	stt_execution_requests_simple_list_destructor(list_zero_);
}

void
stt_execution_requests_simple_list_constructors_tests()
{
	stt_execution_requests_simple_list_default_constructor_test();
	stt_execution_requests_simple_list_construct_and_destruct_test_0();
	stt_execution_requests_simple_list_construct_and_destruct_test_1();
	stt_execution_requests_simple_list_construct_and_destruct_test_2();
}

tests_simple_list *
register_stt_execution_requests_simple_list_constructors_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_execution_requests_simple_list_constructors_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_execution_requests_simple_list_default_constructor_test);
	tests_simple_list_push_back(
			returning_,
			& stt_execution_requests_simple_list_construct_and_destruct_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_execution_requests_simple_list_construct_and_destruct_test_1);
	tests_simple_list_push_back(
			returning_,
			& stt_execution_requests_simple_list_construct_and_destruct_test_2);
	return returning_;
}

void
stt_execution_requests_simple_list_length_test_0()
{
	stt_execution_requests_simple_list * execution_requests_;
	unsigned char execution_requests_len_;

	execution_requests_ = NULL;

	execution_requests_len_ = stt_execution_requests_simple_list_length(
			execution_requests_);

	forced_assertion(execution_requests_len_ == 0);
}

void
stt_execution_requests_simple_list_length_test_1()
{
	stt_execution_requests_simple_list * execution_requests_;
	unsigned char execution_requests_len_;

	execution_requests_ = stt_execution_requests_simple_list_default_constructor();
	forced_assertion(execution_requests_ != NULL);
#ifndef NDEBUG
	forced_assertion(execution_requests_->first == NULL);
	forced_assertion(execution_requests_->next == NULL);
#endif

	execution_requests_len_ = stt_execution_requests_simple_list_length(
			execution_requests_);

	forced_assertion(execution_requests_len_ == 0);

	stt_execution_requests_simple_list_destructor(execution_requests_);
}

void
stt_execution_requests_simple_list_length_test_2()
{
	stt_execution_requests_simple_list * execution_requests_;
	stt_execution_request * execution_request_;
	unsigned char execution_requests_len_;

	execution_requests_ = stt_execution_requests_simple_list_default_constructor();
	forced_assertion(execution_requests_ != NULL);
#ifndef NDEBUG
	forced_assertion(execution_requests_->first == NULL);
	forced_assertion(execution_requests_->next == NULL);
#endif

	execution_request_ = stt_execution_request_example_print_foo();
	forced_assertion(execution_request_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_);
#endif

	execution_requests_ = stt_execution_requests_simple_list_push_front(
			execution_requests_, execution_request_);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_);
#endif
	forced_assertion(execution_requests_ != NULL);
#ifndef NDEBUG
	forced_assertion(execution_requests_->first != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_requests_->first);
	forced_assertion(execution_requests_->next == NULL);
#endif

	stt_execution_request_destructor(execution_request_);

	execution_requests_len_ = stt_execution_requests_simple_list_length(
			execution_requests_);

	forced_assertion(execution_requests_len_ == 1);

	stt_execution_requests_simple_list_destructor(execution_requests_);
}

void
stt_execution_requests_simple_list_length_tests()
{
	stt_execution_requests_simple_list_length_test_0();
	stt_execution_requests_simple_list_length_test_1();
	stt_execution_requests_simple_list_length_test_2();
}

tests_simple_list *
register_stt_execution_requests_simple_list_length_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_execution_requests_simple_list_length_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_execution_requests_simple_list_length_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_execution_requests_simple_list_length_test_1);
	tests_simple_list_push_back(
			returning_,
			& stt_execution_requests_simple_list_length_test_2);
	return returning_;
}

void
stt_execution_requests_simple_list_tests()
{
	stt_execution_requests_simple_list_constructors_tests();
	stt_execution_requests_simple_list_length_tests();
}

tests_simple_list *
register_stt_execution_requests_simple_list_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_execution_requests_simple_list_constructors_tests(
			tests);
	returning_ = register_stt_execution_requests_simple_list_length_tests(
			returning_);
	return returning_;
}
