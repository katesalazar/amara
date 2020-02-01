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
 * src/stt/stt_named_functions_simple_list_tests.c: Test the Amara
 * syntax tree application named functions simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "stt_named_function_tests.h"

#include "stt_node.h"

stt_named_functions_simple_list *
stt_named_functions_simple_list_example_two_named_functions()
{
	stt_named_function * function_;
	stt_named_functions_simple_list * ret_;

	function_ = stt_named_function_example_print_string_literal_bar();
	forced_assertion(function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			function_);
#endif

	ret_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first == NULL);
	assertion(ret_->next == NULL);
#endif

	ret_ = stt_named_functions_simple_list_push_front(ret_, function_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			function_);
#endif
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			ret_->first);
	assertion(ret_->next == NULL);
#endif

	stt_named_function_destructor(function_);

	function_ = stt_named_function_example_print_string_literal_foo();
	forced_assertion(function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			function_);
#endif

	ret_ = stt_named_functions_simple_list_push_front(ret_, function_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			function_);
#endif
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			ret_->first);
#endif
	forced_assertion(ret_->next != NULL);
	forced_assertion(ret_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			ret_->next->first);
	assertion(ret_->next->next == NULL);
#endif

	stt_named_function_destructor(function_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_named_functions_simple_list_example_two_named_functions(
		const stt_named_functions_simple_list * list)
{
	assertion(list != NULL);
	assertion(list->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			list->first);
	assertion(list->next != NULL);
	assertion(list->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			list->next->first);
	assertion(list->next->next == NULL);
}

#endif

stt_named_functions_simple_list *
stt_named_functions_simple_list_example_one_invalid_named_function(void)
{
	stt_named_function * invalid_named_function_;
	stt_named_functions_simple_list * ret_;

	ret_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first == NULL);
	assertion(ret_->next == NULL);
#endif

	invalid_named_function_ = stt_named_function_ill_formed_example_print_identifier_foo();
	forced_assertion(invalid_named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_ill_formed_example_print_identifier_foo(
			invalid_named_function_);
#endif

	ret_ = stt_named_functions_simple_list_push_front(
			ret_, invalid_named_function_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_ill_formed_example_print_identifier_foo(
			invalid_named_function_);
#endif
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_ill_formed_example_print_identifier_foo(
			ret_->first);
	assertion(ret_->next == NULL);
#endif

	stt_named_function_destructor(invalid_named_function_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_named_functions_simple_list_example_one_invalid_named_function(
		const stt_named_functions_simple_list * list)
{
	assertion(list != NULL);
	assertion(list->first != NULL);
	assert_expectations_on_stt_named_function_ill_formed_example_print_identifier_foo(
			list->first);
	assertion(list->next == NULL);
}

#endif

stt_named_functions_simple_list *
stt_named_functions_simple_list_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(void)
{
	stt_named_function * named_function_;
	stt_named_functions_simple_list * ret_;

	ret_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first == NULL);
	assertion(ret_->next == NULL);
#endif

	named_function_ = stt_named_function_example_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo();
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
			named_function_);
#endif

	ret_ = stt_named_functions_simple_list_push_front(
			ret_, named_function_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
			named_function_);
#endif
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
			ret_->first);
	assertion(ret_->next == NULL);
#endif

	stt_named_function_destructor(named_function_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_named_functions_simple_list_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
		const stt_named_functions_simple_list * list)
{
	assertion(list != NULL);
	assertion(list->first != NULL);
	assert_expectations_on_stt_named_function_example_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
			list->first);
	assertion(list->next == NULL);
}

#endif

void
stt_named_functions_simple_list_default_constructor_test()
{
	stt_named_functions_simple_list * list_;

	list_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(list_ != NULL);
	forced_assertion(list_->first == NULL);
	forced_assertion(list_->next == NULL);

	stt_named_functions_simple_list_destructor(list_);
}

void
stt_named_functions_simple_list_default_constructor_tests()
{
	stt_named_functions_simple_list_default_constructor_test();
}

tests_simple_list *
register_stt_named_functions_simple_list_default_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_named_functions_simple_list_default_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_named_functions_simple_list_default_constructor_test);
	return returning_;
}

void
stt_named_functions_simple_list_copy_constructor_test_0()
{
	stt_named_functions_simple_list * list_zero_;
	stt_named_functions_simple_list * list_one_;

	list_zero_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	list_one_ = stt_named_functions_simple_list_copy_constructor(
			list_zero_);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);
	forced_assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	stt_named_functions_simple_list_destructor(list_zero_);
	stt_named_functions_simple_list_destructor(list_one_);
}

void
stt_named_functions_simple_list_copy_constructor_test_1()
{
	stt_named_functions_simple_list * list_zero_;
	stt_named_functions_simple_list * list_one_;
	stt_named_function * named_function_;

	list_zero_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	named_function_ = stt_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	list_zero_ = stt_named_functions_simple_list_push_front(
			list_zero_, named_function_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif
	forced_assertion(list_zero_ != NULL);
	forced_assertion(list_zero_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			list_zero_->first);
	assertion(list_zero_->next == NULL);
#endif

	list_one_ = stt_named_functions_simple_list_copy_constructor(
			list_zero_);
#ifndef NDEBUG
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			list_zero_->first);
	assertion(list_zero_->next == NULL);
#endif
	forced_assertion(list_one_ != NULL);
	forced_assertion(list_one_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			list_one_->first);
	assertion(list_one_->next == NULL);
#endif

	stt_named_functions_simple_list_destructor(list_one_);
	stt_named_function_destructor(named_function_);
	stt_named_functions_simple_list_destructor(list_zero_);
}

void
stt_named_functions_simple_list_copy_constructor_test_2()
{
	stt_named_functions_simple_list * list_zero_;
	stt_named_functions_simple_list * list_one_;
	stt_named_function * named_function_zero_;
	stt_named_function * named_function_one_;

	list_zero_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	named_function_zero_ = stt_named_function_example_print_string_literal_bar();
	forced_assertion(named_function_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			named_function_zero_);
#endif

	named_function_one_ = stt_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_one_);
#endif

	list_zero_ = stt_named_functions_simple_list_push_front(
			list_zero_, named_function_zero_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			named_function_zero_);
#endif
	forced_assertion(list_zero_ != NULL);
	forced_assertion(list_zero_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			list_zero_->first);
	assertion(list_zero_->next == NULL);
#endif

	list_zero_ = stt_named_functions_simple_list_push_front(
			list_zero_, named_function_one_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_one_);
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			list_zero_->first);
	assertion(list_zero_->next != NULL);
	assertion(list_zero_->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			list_zero_->next->first);
	assertion(list_zero_->next->next == NULL);
#endif

	list_one_ = stt_named_functions_simple_list_copy_constructor(
			list_zero_);
#ifndef NDEBUG
	assertion(list_zero_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			list_zero_->first);
	assertion(list_zero_->next != NULL);
	assertion(list_zero_->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			list_zero_->next->first);
	assertion(list_zero_->next->next == NULL);
#endif
	forced_assertion(list_one_ != NULL);
#ifndef NDEBUG
	assertion(list_one_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			list_one_->first);
	assertion(list_one_->next != NULL);
	assertion(list_one_->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			list_one_->next->first);
	assertion(list_one_->next->next == NULL);
#endif

	stt_named_functions_simple_list_destructor(list_one_);
	stt_named_function_destructor(named_function_one_);
	stt_named_function_destructor(named_function_zero_);
	stt_named_functions_simple_list_destructor(list_zero_);
}

void
stt_named_functions_simple_list_copy_constructor_tests()
{
	stt_named_functions_simple_list_copy_constructor_test_0();
	stt_named_functions_simple_list_copy_constructor_test_1();
	stt_named_functions_simple_list_copy_constructor_test_2();
}

tests_simple_list *
register_stt_named_functions_simple_list_copy_constructors_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_named_functions_simple_list_copy_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_named_functions_simple_list_copy_constructor_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_named_functions_simple_list_copy_constructor_test_1);
	tests_simple_list_push_back(
			returning_,
			& stt_named_functions_simple_list_copy_constructor_test_2);
	return returning_;
}

void
stt_named_functions_simple_list_constructors_tests()
{
	stt_named_functions_simple_list_default_constructor_tests();
	stt_named_functions_simple_list_copy_constructor_tests();
}

tests_simple_list *
register_stt_named_functions_simple_list_constructors_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_named_functions_simple_list_constructors_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_named_functions_simple_list_default_constructor_tests(
			tests);
	returning_ = register_stt_named_functions_simple_list_copy_constructor_tests(
			returning_);
	return returning_;
}

void
stt_named_functions_simple_list_length_test_0()
{
	stt_named_functions_simple_list * list_;
	unsigned char length_;

	list_ = NULL;

	length_ = stt_named_functions_simple_list_length(list_);
	forced_assertion(length_ == 0);
}

void
stt_named_functions_simple_list_length_test_1()
{
	stt_named_functions_simple_list * list_;
	unsigned char length_;

	list_ = stt_named_functions_simple_list_default_constructor();
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);

	length_ = stt_named_functions_simple_list_length(list_);
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
	forced_assertion(length_ == 0);

	stt_named_functions_simple_list_destructor(list_);
}

void
stt_named_functions_simple_list_length_test_2()
{
	stt_named_functions_simple_list * list_;
	stt_named_function * named_function_zero_;
	unsigned char length_;

	list_ = stt_named_functions_simple_list_default_constructor();
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);

	named_function_zero_ = stt_named_function_example_print_string_literal_bar();
#ifndef NDEBUG
	assertion(named_function_zero_ != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			named_function_zero_);
#endif

	list_ = stt_named_functions_simple_list_push_front(
			list_, named_function_zero_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			named_function_zero_);
	assertion(list_ != NULL);
	assertion(list_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			list_->first);
	assertion(list_->next == NULL);
#endif

	length_ = stt_named_functions_simple_list_length(list_);
#ifndef NDEBUG
	assertion(list_ != NULL);
	assertion(list_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			list_->first);
	assertion(list_->next == NULL);
#endif
	forced_assertion(length_ == 1);

	stt_named_function_destructor(named_function_zero_);
	stt_named_functions_simple_list_destructor(list_);
}

void
stt_named_functions_simple_list_length_test_3()
{
	stt_named_functions_simple_list * list_;
	stt_named_function * named_function_zero_;
	stt_named_function * named_function_one_;
	unsigned char length_;

	list_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
#endif

	named_function_zero_ = stt_named_function_example_print_string_literal_bar();
	forced_assertion(named_function_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			named_function_zero_);
#endif

	named_function_one_ = stt_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_one_);
#endif

	list_ = stt_named_functions_simple_list_push_front(
			list_, named_function_zero_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			named_function_zero_);
#endif
	forced_assertion(list_ != NULL);
	forced_assertion(list_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			list_->first);
	assertion(list_->next == NULL);
#endif

	stt_named_function_destructor(named_function_zero_);

	list_ = stt_named_functions_simple_list_push_front(
			list_, named_function_one_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_one_);
#endif
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assertion(list_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			list_->first);
	assertion(list_->next != NULL);
	assertion(list_->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			list_->next->first);
	assertion(list_->next->next == NULL);
#endif

	stt_named_function_destructor(named_function_one_);

	length_ = stt_named_functions_simple_list_length(list_);
#ifndef NDEBUG
	assertion(list_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			list_->first);
	assertion(list_->next != NULL);
	assertion(list_->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			list_->next->first);
	assertion(list_->next->next == NULL);
#endif
	forced_assertion(length_ == 2);

	stt_named_functions_simple_list_destructor(list_);
}

void
stt_named_functions_simple_list_length_tests()
{
	stt_named_functions_simple_list_length_test_0();
	stt_named_functions_simple_list_length_test_1();
	stt_named_functions_simple_list_length_test_2();
	stt_named_functions_simple_list_length_test_3();
}

tests_simple_list *
register_stt_named_functions_simple_list_length_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_named_functions_simple_list_length_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_named_functions_simple_list_length_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_named_functions_simple_list_length_test_1);
	tests_simple_list_push_back(
			returning_,
			& stt_named_functions_simple_list_length_test_2);
	tests_simple_list_push_back(
			returning_,
			& stt_named_functions_simple_list_length_test_3);
	return returning_;
}

void
stt_named_functions_simple_list_push_front_test_0()
{
	stt_named_functions_simple_list * list_;

	list_ = stt_named_functions_simple_list_example_two_named_functions();
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_functions_simple_list_example_two_named_functions(
			list_);
#endif

	stt_named_functions_simple_list_destructor(list_);
}

void
stt_named_functions_simple_list_push_front_tests()
{
	stt_named_functions_simple_list_push_front_test_0();
}

tests_simple_list *
register_stt_named_functions_simple_list_push_front_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_named_functions_simple_list_push_front_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_named_functions_simple_list_push_front_test_0);
	return returning_;
}

void
stt_named_functions_simple_list_tests()
{
	stt_named_functions_simple_list_constructors_tests();
	stt_named_functions_simple_list_length_tests();
	stt_named_functions_simple_list_push_front_tests();
}

tests_simple_list *
register_stt_named_functions_simple_list_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_named_functions_simple_list_constructors_tests(
			tests);
	returning_ = register_stt_named_functions_simple_list_length_tests(
			returning_);
	returning_ = register_stt_named_functions_simple_list_push_front_tests(
			returning_);
	return returning_;
}
