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
 * src/stt/stt_operation_args_simple_list_tests.c: Test the Amara syntax
 * tree application function operation arguments simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "stt_operation_arg_tests.h"

/*   For owned prototypes. */
#include "stt_operation_args_simple_list_tests.h"

stt_operation_args_simple_list *
stt_operation_args_simple_list_example_one_arg_list()
{
	stt_operation_arg * operation_arg_;
	stt_operation_args_simple_list * ret_;

	operation_arg_ = stt_operation_arg_example_string_literal_foo();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			operation_arg_);
#endif

	ret_ = stt_operation_args_simple_list_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first == NULL);
	assertion(ret_->next == NULL);
#endif

	ret_ = stt_operation_args_simple_list_push_front(ret_, operation_arg_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			operation_arg_);
#endif
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			ret_->first);
	assertion(ret_->next == NULL);
#endif

	stt_operation_arg_destructor(operation_arg_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_args_simple_list_example_one_arg_list(
		const stt_operation_args_simple_list * list)
{
	assertion(list != NULL);
	assertion(list->first != NULL);
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			list->first);
	assertion(list->next == NULL);
}

#endif

#include "stt_operation_args_simple_list_tests.h"

stt_operation_args_simple_list *
stt_operation_args_simple_list_example_two_args_list()
{
	stt_operation_arg * operation_arg_;
	stt_operation_args_simple_list * ret_;

	operation_arg_ = stt_operation_arg_example_string_literal_foo();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			operation_arg_);
#endif

	ret_ = stt_operation_args_simple_list_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first == NULL);
	assertion(ret_->next == NULL);
#endif

	ret_ = stt_operation_args_simple_list_push_front(ret_, operation_arg_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			operation_arg_);
#endif
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			ret_->first);
	assertion(ret_->next == NULL);
#endif

	ret_ = stt_operation_args_simple_list_push_front(ret_, operation_arg_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			operation_arg_);
#endif
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			ret_->first);
#endif
	forced_assertion(ret_->next != NULL);
	forced_assertion(ret_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			ret_->next->first);
	assertion(ret_->next->next == NULL);
#endif

	stt_operation_arg_destructor(operation_arg_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_args_simple_list_example_two_args_list(
		const stt_operation_args_simple_list * list)
{
	assertion(list != NULL);
	assertion(list->first != NULL);
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			list->first);
	assertion(list->next != NULL);
	assertion(list->next->first != NULL);
	assert_expectations_on_stt_operation_arg_example_string_literal_foo(
			list->next->first);
	assertion(list->next->next == NULL);
}

#endif

void
stt_operation_args_simple_list_copy_constructor_test_0()
{
	stt_operation_args_simple_list * stt_operation_args_simple_list_original;
	stt_operation_args_simple_list * stt_operation_args_simple_list_clone;

	stt_operation_args_simple_list_original =
			stt_operation_args_simple_list_default_constructor();
	forced_assertion(stt_operation_args_simple_list_original != NULL);
#ifndef NDEBUG
	assertion(stt_operation_args_simple_list_original->first == NULL);
	assertion(stt_operation_args_simple_list_original->next == NULL);
#endif

	stt_operation_args_simple_list_clone =
			stt_operation_args_simple_list_copy_constructor(
					stt_operation_args_simple_list_original);
	forced_assertion(stt_operation_args_simple_list_clone != NULL);
#ifndef NDEBUG
	assertion(stt_operation_args_simple_list_clone->first == NULL);
	assertion(stt_operation_args_simple_list_clone->next == NULL);
#endif

	stt_operation_args_simple_list_destructor(
			stt_operation_args_simple_list_original);
	stt_operation_args_simple_list_destructor(
			stt_operation_args_simple_list_clone);
}

void
stt_operation_args_simple_list_copy_constructor_test_1()
{
	stt_operation_args_simple_list * stt_operation_args_simple_list_original;
	stt_operation_args_simple_list * stt_operation_args_simple_list_clone;

	stt_operation_args_simple_list_original =
			stt_operation_args_simple_list_example_two_args_list();
	forced_assertion(stt_operation_args_simple_list_original != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_args_simple_list_example_two_args_list(
			stt_operation_args_simple_list_original);
#endif

	stt_operation_args_simple_list_clone =
			stt_operation_args_simple_list_copy_constructor(
					stt_operation_args_simple_list_original);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_args_simple_list_example_two_args_list(
			stt_operation_args_simple_list_original);
#endif
	forced_assertion(stt_operation_args_simple_list_clone != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_args_simple_list_example_two_args_list(
			stt_operation_args_simple_list_clone);
#endif

	stt_operation_args_simple_list_destructor(
			stt_operation_args_simple_list_original);
	stt_operation_args_simple_list_destructor(
			stt_operation_args_simple_list_clone);
}

void
stt_operation_args_simple_list_copy_constructor_tests()
{
	stt_operation_args_simple_list_copy_constructor_test_0();
	stt_operation_args_simple_list_copy_constructor_test_1();
}

tests_simple_list *
register_stt_operation_args_simple_list_copy_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_operation_args_simple_list_copy_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_operation_args_simple_list_copy_constructor_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_operation_args_simple_list_copy_constructor_test_1);
	return returning_;
}

void
stt_operation_args_simple_list_equality_test_0()
{
	stt_operation_args_simple_list * l0_;
	stt_operation_args_simple_list * l1_;
	amara_boolean equality_;

	l0_ = stt_operation_args_simple_list_default_constructor();
	forced_assertion(l0_ != NULL);
#ifndef NDEBUG
	assertion(l0_->first == NULL);
	assertion(l0_->next == NULL);
#endif

	l1_ = stt_operation_args_simple_list_example_two_args_list();
	forced_assertion(l1_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_args_simple_list_example_two_args_list(
			l1_);
#endif

	equality_ = stt_operation_args_simple_lists_equality(l0_, l1_);
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);

	stt_operation_args_simple_list_destructor(l0_);
	stt_operation_args_simple_list_destructor(l1_);
}

void
stt_operation_args_simple_list_equality_test_1()
{
	stt_operation_args_simple_list * l0_;
	stt_operation_args_simple_list * l1_;
	amara_boolean equality_;

	l0_ = stt_operation_args_simple_list_example_two_args_list();
	forced_assertion(l0_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_args_simple_list_example_two_args_list(
			l0_);
#endif

	l1_ = stt_operation_args_simple_list_default_constructor();
	forced_assertion(l1_ != NULL);
#ifndef NDEBUG
	assertion(l1_->first == NULL);
	assertion(l1_->next == NULL);
#endif

	equality_ = stt_operation_args_simple_lists_equality(l0_, l1_);
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);

	stt_operation_args_simple_list_destructor(l0_);
	stt_operation_args_simple_list_destructor(l1_);
}

/**  List with `n` elements not equal to list with `n + 1` elements. */
void
stt_operation_args_simple_list_equality_test_2()
{
	stt_operation_args_simple_list * l0_;
	stt_operation_args_simple_list * l1_;
	amara_boolean equality_;

	l0_ = stt_operation_args_simple_list_example_one_arg_list();
	forced_assertion(l0_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_args_simple_list_example_one_arg_list(
			l0_);
#endif

	l1_ = stt_operation_args_simple_list_example_two_args_list();
	forced_assertion(l1_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_args_simple_list_example_two_args_list(
			l1_);
#endif

	equality_ = stt_operation_args_simple_lists_equality(l0_, l1_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_args_simple_list_example_one_arg_list(
			l0_);
	assert_expectations_on_stt_operation_args_simple_list_example_two_args_list(
			l1_);
#endif
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);

	stt_operation_args_simple_list_destructor(l0_);
	stt_operation_args_simple_list_destructor(l1_);
}

/**  List with `n + 1` elements not equal to list with `n` elements. */
void
stt_operation_args_simple_list_equality_test_3()
{
	stt_operation_args_simple_list * l0_;
	stt_operation_args_simple_list * l1_;
	amara_boolean equality_;

	l0_ = stt_operation_args_simple_list_example_two_args_list();
	forced_assertion(l0_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_args_simple_list_example_two_args_list(
			l0_);
#endif

	l1_ = stt_operation_args_simple_list_example_one_arg_list();
	forced_assertion(l1_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_args_simple_list_example_one_arg_list(
			l1_);
#endif

	equality_ = stt_operation_args_simple_lists_equality(l0_, l1_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_args_simple_list_example_two_args_list(
			l0_);
	assert_expectations_on_stt_operation_args_simple_list_example_one_arg_list(
			l1_);
#endif
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);

	stt_operation_args_simple_list_destructor(l0_);
	stt_operation_args_simple_list_destructor(l1_);
}

void
stt_operation_args_simple_list_equality_tests()
{
	stt_operation_args_simple_list_equality_test_0();
	stt_operation_args_simple_list_equality_test_1();
	stt_operation_args_simple_list_equality_test_2();
	stt_operation_args_simple_list_equality_test_3();
}

void
stt_operation_args_simple_list_tests()
{
	stt_operation_args_simple_list_copy_constructor_tests();
	stt_operation_args_simple_list_equality_tests();
}

tests_simple_list *
register_stt_operation_args_simple_list_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_operation_args_simple_list_copy_constructor_tests(
			tests);
	return returning_;
}
