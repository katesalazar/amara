/*
 * Copyright 2019, 2020 Mercedes Catherine Salazar
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
 * src/cmn/amara_strings_simple_list_tests.c: Simple list of strings
 * test.
 */

#include "../asr/assertion.h"

#include "amara_string_tests.h"

#include "amara_strings_simple_list.h"

#include "amara_strings_simple_list_tests.h"

void
amara_strings_simple_list_default_constructor_test()
{
	amara_strings_simple_list * list_;

	list_ = amara_strings_simple_list_default_constructor();
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
#endif

	amara_strings_simple_list_destructor(list_);
}

void
amara_strings_simple_list_constructors_tests()
{
	amara_strings_simple_list_default_constructor_test();
}

tests_simple_list *
register_amara_strings_simple_list_constructors_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_amara_strings_simple_list_constructors_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& amara_strings_simple_list_default_constructor_test);
	return returning_;
}

void
amara_strings_simple_list_push_front_test_0()
{
	amara_strings_simple_list * strings_;
	amara_string * string_;

	strings_ = amara_strings_simple_list_default_constructor();
	forced_assertion(strings_ != NULL);
#ifndef NDEBUG
	assertion(strings_->first == NULL);
	assertion(strings_->next == NULL);
#endif

	string_ = amara_string_example_foo();
	forced_assertion(string_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_foo(string_);
#endif

	strings_ = amara_strings_simple_list_push_front(strings_, string_);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_foo(string_);
#endif
	forced_assertion(strings_ != NULL);
	forced_assertion(strings_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_foo(strings_->first);
	assertion(strings_->next == NULL);
#endif

	amara_string_destructor(string_);
	amara_strings_simple_list_destructor(strings_);
}

void
amara_strings_simple_list_push_front_test_1()
{
	amara_strings_simple_list * strings_;
	amara_string * string_;

	strings_ = amara_strings_simple_list_default_constructor();
	forced_assertion(strings_ != NULL);
#ifndef NDEBUG
	assertion(strings_->first == NULL);
	assertion(strings_->next == NULL);
#endif

	string_ = amara_string_example_bar();
	forced_assertion(string_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_bar(string_);
#endif

	strings_ = amara_strings_simple_list_push_front(strings_, string_);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_bar(string_);
#endif
	forced_assertion(strings_ != NULL);
	forced_assertion(strings_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_bar(strings_->first);
	assertion(strings_->next == NULL);
#endif

	amara_string_destructor(string_);

	string_ = amara_string_example_foo();
	forced_assertion(string_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_foo(string_);
#endif

	strings_ = amara_strings_simple_list_push_front(strings_, string_);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_foo(string_);
#endif
	forced_assertion(strings_ != NULL);
	forced_assertion(strings_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_foo(strings_->first);
#endif
	forced_assertion(strings_->next != NULL);
	forced_assertion(strings_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_bar(strings_->next->first);
	assertion(strings_->next->next == NULL);
#endif

	amara_string_destructor(string_);
	amara_strings_simple_list_destructor(strings_);
}

void
amara_strings_simple_list_push_front_tests()
{
	amara_strings_simple_list_push_front_test_0();
	amara_strings_simple_list_push_front_test_1();
}

tests_simple_list *
register_amara_strings_simple_list_push_front_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_amara_strings_simple_list_push_front_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& amara_strings_simple_list_push_front_test_0);
	tests_simple_list_push_back(
			returning_,
			& amara_strings_simple_list_push_front_test_1);
	return returning_;
}

void
amara_strings_simple_list_tests()
{
	amara_strings_simple_list_constructors_tests();
	amara_strings_simple_list_push_front_tests();
}

tests_simple_list *
register_amara_strings_simple_list_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_amara_strings_simple_list_constructors_tests(
			tests);
	returning_ = register_amara_strings_simple_list_push_front_tests(
			returning_);
	return returning_;
}
