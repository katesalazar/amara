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
 * src/stt/stt_applications_simple_list_tests.c: Test the Amara syntax
 * tree applications simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "stt_application_tests.h"

/*   For `stt_applications_simple_list`. */
#include "stt_applications_simple_list.h"

void
stt_applications_simple_list_construct_and_destruct_test_0()
{
	stt_applications_simple_list * list_;

	list_ = stt_applications_simple_list_default_constructor();
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);

	stt_applications_simple_list_destructor(list_);
}

void
stt_applications_simple_list_construct_and_destruct_test_1()
{
	stt_applications_simple_list * list_zero_;
	stt_applications_simple_list * list_one_;

	list_zero_ = stt_applications_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	list_one_ = stt_applications_simple_list_copy_constructor(list_zero_);
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	stt_applications_simple_list_destructor(list_zero_);
	stt_applications_simple_list_destructor(list_one_);
}

void
stt_applications_simple_list_construct_and_destruct_test_2()
{
	stt_applications_simple_list * list_zero_;
	stt_application * application_;
	stt_applications_simple_list * list_one_;

	list_zero_ = stt_applications_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	application_ = stt_application_example_print_foo();
	assertion(application_ != NULL);
	assert_expectations_on_stt_application_example_print_foo(application_);

	list_zero_ = stt_applications_simple_list_push_front(
			list_zero_, application_);
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			list_zero_->first);
	assertion(list_zero_->next == NULL);

	list_one_ = stt_applications_simple_list_copy_constructor(list_zero_);
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			list_zero_->first);
	assertion(list_zero_->next == NULL);
	assertion(list_one_ != NULL);
	assertion(list_one_->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			list_one_->first);
	assertion(list_one_->next == NULL);

	stt_applications_simple_list_destructor(list_one_);
	stt_application_destructor(application_);
	stt_applications_simple_list_destructor(list_zero_);
}

void
stt_applications_simple_list_construct_and_destruct_test_3()
{
	stt_applications_simple_list * list_zero_;
	stt_application * application_zero_;
	stt_application * application_one_;
	stt_applications_simple_list * list_one_;

	list_zero_ = stt_applications_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	application_zero_ = stt_application_example_print_foo();
	assertion(application_zero_ != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			application_zero_);

	application_one_ = stt_application_example_print_bar();
	assertion(application_one_ != NULL);
	assert_expectations_on_stt_application_example_print_bar(
			application_one_);

	list_zero_ = stt_applications_simple_list_push_front(
			list_zero_, application_zero_);
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			list_zero_->first);
	assertion(list_zero_->next == NULL);

	list_zero_ = stt_applications_simple_list_push_front(
			list_zero_, application_one_);
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_application_example_print_bar(
			list_zero_->first);
	assertion(list_zero_->next != NULL);
	assertion(list_zero_->next->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			list_zero_->next->first);
	assertion(list_zero_->next->next == NULL);

	list_one_ = stt_applications_simple_list_copy_constructor(list_zero_);
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_application_example_print_bar(
			list_zero_->first);
	assertion(list_zero_->next != NULL);
	assertion(list_zero_->next->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			list_zero_->next->first);
	assertion(list_zero_->next->next == NULL);
	assertion(list_one_ != NULL);
	assertion(list_one_->first != NULL);
	assert_expectations_on_stt_application_example_print_bar(
			list_one_->first);
	assertion(list_one_->next != NULL);
	assertion(list_one_->next->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			list_one_->next->first);
	assertion(list_one_->next->next == NULL);

	stt_applications_simple_list_destructor(list_one_);
	stt_application_destructor(application_one_);
	stt_application_destructor(application_zero_);
	stt_applications_simple_list_destructor(list_zero_);
}

void
stt_applications_simple_list_construct_and_destruct_tests()
{
	stt_applications_simple_list_construct_and_destruct_test_0();
	stt_applications_simple_list_construct_and_destruct_test_1();
	stt_applications_simple_list_construct_and_destruct_test_2();
	stt_applications_simple_list_construct_and_destruct_test_3();
}

void
stt_applications_simple_list_tests()
{
	stt_applications_simple_list_construct_and_destruct_tests();
}
