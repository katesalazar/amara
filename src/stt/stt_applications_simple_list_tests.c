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
 * src/stt/stt_applications_simple_list_tests.c: Test the Amara syntax
 * tree applications simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "stt_application_tests.h"

/*   For `stt_applications_simple_list`. */
#include "stt_applications_simple_list.h"

#include "stt_applications_simple_list_tests.h"

stt_applications_simple_list *
stt_applications_simple_list_example_two_applications()
{
	stt_application * application_;
	stt_applications_simple_list * ret_;

	ret_ = stt_applications_simple_list_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first == NULL);
	assertion(ret_->next == NULL);
#endif

	application_ = stt_application_example_print_bar();
	forced_assertion(application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_bar(application_);
#endif

	ret_ = stt_applications_simple_list_push_front(ret_, application_);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_bar(application_);
#endif
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_bar(ret_->first);
	assertion(ret_->next == NULL);
#endif

	stt_application_destructor(application_);

	application_ = stt_application_example_print_foo();
	forced_assertion(application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(application_);
#endif

	ret_ = stt_applications_simple_list_push_front(ret_, application_);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(application_);
#endif
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(ret_->first);
#endif
	forced_assertion(ret_->next != NULL);
	forced_assertion(ret_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_bar(
			ret_->next->first);
	assertion(ret_->next->next == NULL);
#endif

	stt_application_destructor(application_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_applications_simple_list_example_two_applications(
		const stt_applications_simple_list * list)
{
	assertion(list != NULL);
	assertion(list->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			list->first);
	assertion(list->next != NULL);
	assertion(list->next->first != NULL);
	assert_expectations_on_stt_application_example_print_bar(
			list->next->first);
	assertion(list->next->next == NULL);
}

#endif

void
stt_applications_simple_list_default_constructor_test()
{
	stt_applications_simple_list * list_;

	list_ = stt_applications_simple_list_default_constructor();
	forced_assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);

	stt_applications_simple_list_destructor(list_);
}

void
stt_applications_simple_list_copy_constructor_test_0()
{
	stt_applications_simple_list * list_zero_;
	stt_applications_simple_list * list_one_;

	list_zero_ = stt_applications_simple_list_default_constructor();
	forced_assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	list_one_ = stt_applications_simple_list_copy_constructor(list_zero_);
	forced_assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	stt_applications_simple_list_destructor(list_zero_);
	stt_applications_simple_list_destructor(list_one_);
}

void
stt_applications_simple_list_copy_constructor_test_1()
{
	stt_applications_simple_list * list_zero_;
	stt_application * application_;
	stt_applications_simple_list * list_one_;

	list_zero_ = stt_applications_simple_list_default_constructor();
	forced_assertion(list_zero_ != NULL);
#ifndef NDEBUG
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);
#endif

	application_ = stt_application_example_print_foo();
	forced_assertion(application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(application_);
#endif

	list_zero_ = stt_applications_simple_list_push_front(
			list_zero_, application_);
	forced_assertion(list_zero_ != NULL);
	forced_assertion(list_zero_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			list_zero_->first);
	assertion(list_zero_->next == NULL);
#endif

	list_one_ = stt_applications_simple_list_copy_constructor(list_zero_);
#ifndef NDEBUG
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			list_zero_->first);
	assertion(list_zero_->next == NULL);
#endif
	forced_assertion(list_one_ != NULL);
	forced_assertion(list_one_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			list_one_->first);
	assertion(list_one_->next == NULL);
#endif

	stt_applications_simple_list_destructor(list_one_);
	stt_application_destructor(application_);
	stt_applications_simple_list_destructor(list_zero_);
}

void
stt_applications_simple_list_copy_constructor_test_2()
{
	stt_applications_simple_list * list_zero_;
	stt_application * application_zero_;
	stt_application * application_one_;
	stt_applications_simple_list * list_one_;

	list_zero_ = stt_applications_simple_list_default_constructor();
	forced_assertion(list_zero_ != NULL);
#ifndef NDEBUG
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);
#endif

	application_zero_ = stt_application_example_print_foo();
	forced_assertion(application_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_zero_);
#endif

	application_one_ = stt_application_example_print_bar();
	forced_assertion(application_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_bar(
			application_one_);
#endif

	list_zero_ = stt_applications_simple_list_push_front(
			list_zero_, application_zero_);
#ifndef NDEBUG
	assertion(list_zero_ != NULL);
#endif
	forced_assertion(list_zero_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			list_zero_->first);
	assertion(list_zero_->next == NULL);
#endif

	list_zero_ = stt_applications_simple_list_push_front(
			list_zero_, application_one_);
#ifndef NDEBUG
	assertion(list_zero_ != NULL);
#endif
	forced_assertion(list_zero_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_bar(
			list_zero_->first);
	assertion(list_zero_->next != NULL);
	assertion(list_zero_->next->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			list_zero_->next->first);
	assertion(list_zero_->next->next == NULL);
#endif

	list_one_ = stt_applications_simple_list_copy_constructor(list_zero_);
#ifndef NDEBUG
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_application_example_print_bar(
			list_zero_->first);
	assertion(list_zero_->next != NULL);
	assertion(list_zero_->next->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			list_zero_->next->first);
	assertion(list_zero_->next->next == NULL);
#endif
	forced_assertion(list_one_ != NULL);
	forced_assertion(list_one_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_bar(
			list_one_->first);
#endif
	forced_assertion(list_one_->next != NULL);
	forced_assertion(list_one_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			list_one_->next->first);
	assertion(list_one_->next->next == NULL);
#endif

	stt_applications_simple_list_destructor(list_one_);
	stt_application_destructor(application_one_);
	stt_application_destructor(application_zero_);
	stt_applications_simple_list_destructor(list_zero_);
}

void
stt_applications_simple_list_constructors_tests()
{
	stt_applications_simple_list_default_constructor_test();
	stt_applications_simple_list_copy_constructor_test_0();
	stt_applications_simple_list_copy_constructor_test_1();
	stt_applications_simple_list_copy_constructor_test_2();
}

tests_simple_list *
register_stt_applications_simple_list_constructors_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_applications_simple_list_constructors_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_applications_simple_list_default_constructor_test);
	tests_simple_list_push_back(
			returning_,
			& stt_applications_simple_list_copy_constructor_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_applications_simple_list_copy_constructor_test_1);
	tests_simple_list_push_back(
			returning_,
			& stt_applications_simple_list_copy_constructor_test_2);
	return returning_;
}

void
stt_applications_simple_list_length_test_0()
{
	stt_applications_simple_list * list_;
	stt_applications_simple_list_length_ret * len_ret_ptr_;

	list_ = stt_applications_simple_list_default_constructor();
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
#endif

	len_ret_ptr_ = stt_applications_simple_list_length(list_);
	forced_assertion(len_ret_ptr_ != NULL);
	forced_assertion(len_ret_ptr_->status ==
			STT_APPLICATIONS_SIMPLE_LIST_LENGTH_RET_STATUS_SUCCESS);
	forced_assertion(len_ret_ptr_->length == 0);

	free(len_ret_ptr_);
	stt_applications_simple_list_destructor(list_);
}

void
stt_applications_simple_list_length_test_1()
{
	stt_applications_simple_list * list_;
	stt_application * application_;
	stt_applications_simple_list_length_ret * len_ret_ptr_;

	list_ = stt_applications_simple_list_default_constructor();
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
#endif

	application_ = stt_application_example_print_foo();
	forced_assertion(application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(application_);
#endif

	list_ = stt_applications_simple_list_push_front(list_, application_);
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(application_);
	assertion(list_->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(list_->first);
	assertion(list_->next == NULL);
#endif

	len_ret_ptr_ = stt_applications_simple_list_length(list_);
	forced_assertion(len_ret_ptr_ != NULL);
	forced_assertion(len_ret_ptr_->status ==
			STT_APPLICATIONS_SIMPLE_LIST_LENGTH_RET_STATUS_SUCCESS);
	forced_assertion(len_ret_ptr_->length == 1);

	free(len_ret_ptr_);
	stt_application_destructor(application_);
	stt_applications_simple_list_destructor(list_);
}

void
stt_applications_simple_list_length_test_2()
{
	stt_applications_simple_list * list_;
	stt_application * application_;
	stt_applications_simple_list_length_ret * len_ret_ptr_;
	unsigned short i_;

	list_ = stt_applications_simple_list_default_constructor();
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
#endif

	application_ = stt_application_example_print_foo();
	forced_assertion(application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(application_);
#endif

	i_ = 0;

	do {

	list_ = stt_applications_simple_list_push_front(list_, application_);
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(application_);
	assertion(list_->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(list_->first);
	if (i_ == 0) {
		assertion(list_->next == NULL);
	} else {
		assertion(list_->next != NULL);
	}
#endif

	len_ret_ptr_ = stt_applications_simple_list_length(list_);
	forced_assertion(len_ret_ptr_ != NULL);
	if (i_ < 0xFF) {  /* 255. */
		forced_assertion(len_ret_ptr_->status ==
				STT_APPLICATIONS_SIMPLE_LIST_LENGTH_RET_STATUS_SUCCESS);
		forced_assertion(len_ret_ptr_->length == i_ + 1);
	} else {
		forced_assertion(len_ret_ptr_->status ==
				STT_APPLICATIONS_SIMPLE_LIST_LENGTH_RET_STATUS_ERROR_OVERFLOW);
	}

	i_++;

	free(len_ret_ptr_);

	} while (i_ < 0x0100);  /* 256. */

	stt_application_destructor(application_);
	stt_applications_simple_list_destructor(list_);
}

void
stt_applications_simple_list_length_tests()
{
	stt_applications_simple_list_length_test_0();
	stt_applications_simple_list_length_test_1();
	stt_applications_simple_list_length_test_2();
}

tests_simple_list *
register_stt_applications_simple_list_length_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_applications_simple_list_length_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_applications_simple_list_length_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_applications_simple_list_length_test_1);
	tests_simple_list_push_back(
			returning_,
			& stt_applications_simple_list_length_test_2);
	return returning_;
}

void
stt_applications_simple_list_push_front_test_0()
{
	stt_applications_simple_list * list_;

	list_ = stt_applications_simple_list_example_two_applications();
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_applications_simple_list_example_two_applications(
			list_);
#endif

	stt_applications_simple_list_destructor(list_);
}

void
stt_applications_simple_list_push_front_tests()
{
	stt_applications_simple_list_push_front_test_0();
}

tests_simple_list *
register_stt_applications_simple_list_push_front_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_applications_simple_list_push_front_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_applications_simple_list_push_front_test_0);
	return returning_;
}

void
stt_applications_simple_list_tests()
{
	stt_applications_simple_list_constructors_tests();
	stt_applications_simple_list_length_tests();
	stt_applications_simple_list_push_front_tests();
}

tests_simple_list *
register_stt_applications_simple_list_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;
	returning_ = register_stt_applications_simple_list_constructors_tests(
			tests);
	returning_ = register_stt_applications_simple_list_length_tests(
			returning_);
	returning_ = register_stt_applications_simple_list_push_front_tests(
			returning_);
	return returning_;
}
