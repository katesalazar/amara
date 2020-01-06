/*
 * Copyright 2019 Mercedes Catherine Salazar
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
amara_strings_simple_list_exhaustive_constructor_three_to_one_test_0()
{
	char * ca0_;
	char * ca1_;
	char * ca2_;
	amara_strings_simple_list * returned_;

	ca0_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion(ca0_ != NULL);
	ca0_[0] = '0';
	ca0_[1] = '\0';

	ca1_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(3);
	forced_assertion(ca1_ != NULL);
	ca1_[0] = '1';
	ca1_[1] = '2';
	ca1_[2] = '\0';

	ca2_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(4);
	forced_assertion(ca2_ != NULL);
	ca2_[0] = '3';
	ca2_[1] = '4';
	ca2_[2] = '5';
	ca2_[3] = '\0';

	returned_ = amara_strings_simple_list_exhaustive_constructor_three_to_one(
			ca0_, ca1_, ca2_);
	forced_assertion(returned_ != NULL);
#ifndef NDEBUG
	assertion(ca0_[0] == '0');
	assertion(ca0_[1] == '\0');
	assertion(ca1_[0] == '1');
	assertion(ca1_[1] == '2');
	assertion(ca1_[2] == '\0');
	assertion(ca2_[0] == '3');
	assertion(ca2_[1] == '4');
	assertion(ca2_[2] == '5');
	assertion(ca2_[3] == '\0');
#endif
	forced_assertion(returned_->first != NULL);
	forced_assertion(returned_->first->value_ != NULL);
#ifndef NDEBUG
	assertion(returned_->first->value_[0] == '0');
	assertion(returned_->first->value_[1] == '1');
	assertion(returned_->first->value_[2] == '2');
	assertion(returned_->first->value_[3] == '3');
	assertion(returned_->first->value_[4] == '4');
	assertion(returned_->first->value_[5] == '5');
	assertion(returned_->first->value_[6] == '\0');
	assertion(returned_->next == NULL);
#endif

	free(ca0_);
	free(ca1_);
	free(ca2_);
	amara_strings_simple_list_destructor(returned_);
}

void
amara_strings_simple_list_exhaustive_constructor_three_to_one_tests()
{
	amara_strings_simple_list_exhaustive_constructor_three_to_one_test_0();
}

void
amara_strings_simple_list_exhaustive_constructors_tests()
{
	amara_strings_simple_list_exhaustive_constructor_three_to_one_tests();
}

void
amara_strings_simple_list_constructors_tests()
{
	amara_strings_simple_list_default_constructor_test();
	amara_strings_simple_list_exhaustive_constructors_tests();
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

void
amara_strings_simple_list_tests()
{
	amara_strings_simple_list_constructors_tests();
	amara_strings_simple_list_push_front_tests();
}
