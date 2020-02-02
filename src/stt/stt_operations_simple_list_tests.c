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
 * src/stt/stt_operations_simple_list_tests.c: Test the Amara syntax
 * tree application function operations simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `typedef struct stt_node { ... } stt_node`. */
#include "stt_forward_declarations.h"

/*   For `stt_operation * stt_operation_example_print_foo()`. */
#include "stt_operation_tests.h"

/*   For own definitions. */
#include "stt_operations_simple_list_tests.h"

#include "stt_operations_simple_list_tests.h"

stt_operations_simple_list *
stt_operations_simple_list_example_print_foo(void)
{
	stt_operations_simple_list * operations_;
	stt_operation * operation_;

	operations_ = stt_operations_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(operations_ != NULL);
	assertion(operations_->first == NULL);
	assertion(operations_->next == NULL);
#endif

	operation_ = stt_operation_example_print_string_literal_foo();
#ifndef NDEBUG
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operation_);
#endif

	stt_operations_simple_list_push_back(operations_, operation_);
#ifndef NDEBUG
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operation_);
	assertion(operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operations_->first);
	assertion(operations_->next == NULL);
#endif

	stt_operation_destructor(operation_);

	return operations_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operations_simple_list_example_print_foo(
		const stt_operations_simple_list * operations)
{
	assertion(operations != NULL);
	assertion(operations->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operations->first);
	assertion(operations->next == NULL);
}

#endif

/*

stt_operations_simple_list *
stt_operations_simple_list_example_print_string_literal_foo(void)
{
	return stt_operations_simple_list_example_print_foo();
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operations_simple_list_example_print_string_literal_foo(
		const stt_operations_simple_list * operations)
{
	forced_assertion(operations != NULL);
	assert_expectations_on_stt_operations_simple_list_example_print_foo(
			operations);
}

#endif

*/

stt_operations_simple_list *
stt_operations_simple_list_example_print_identifier_foo(void)
{
	stt_operation * operation_;
	stt_operations_simple_list * ret_;

	operation_ = stt_operation_example_print_identifier_foo();
	forced_assertion(operation_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			operation_);
#endif

	ret_ = stt_operations_simple_list_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first == NULL);
	assertion(ret_->next == NULL);
#endif

	stt_operations_simple_list_push_back(ret_, operation_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			operation_);
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			ret_->first);
	assertion(ret_->next == NULL);
#endif

	stt_operation_destructor(operation_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operations_simple_list_example_print_identifier_foo(
		const stt_operations_simple_list * operations)
{
	assertion(operations != NULL);
	assertion(operations->first != NULL);
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			operations->first);
	assertion(operations->next == NULL);
}

#endif

stt_operations_simple_list *
stt_operations_simple_list_example_one_operation_list(void)
{
	return stt_operations_simple_list_example_print_identifier_foo();
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operations_simple_list_example_one_operation_list(
		const stt_operations_simple_list * operations)
{
	assert_expectations_on_stt_operations_simple_list_example_print_identifier_foo(
			operations);
}

#endif

stt_operations_simple_list *
stt_operations_simple_list_example_two_operations_list(void)
{
	stt_operations_simple_list * returning_;
	stt_operation * operation_;

	returning_ = stt_operations_simple_list_example_print_identifier_foo();
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_print_identifier_foo(
			returning_);
#endif

	operation_ = returning_->first;
	/* XXX missing assertions? */

	stt_operations_simple_list_push_back(returning_, operation_);
	/* XXX missing assertions? */

#ifndef NDEBUG
	assertion(returning_->next != NULL);
	assertion(returning_->next->next == NULL);
#endif

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operations_simple_list_example_two_operations_list(
		const stt_operations_simple_list * operations)
{
	assertion(operations != NULL);
	assertion(operations->first != NULL);
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			operations->first);
	assertion(operations->next != NULL);
	assertion(operations->next->first != NULL);
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			operations->next->first);
	assertion(operations->next->next == NULL);
}

#endif

void
stt_operations_simple_list_default_constructor_test_0()
{
	stt_operations_simple_list * list_;

	list_ = stt_operations_simple_list_default_constructor();
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
#endif

	stt_operations_simple_list_destructor(list_);
}

void
stt_operations_simple_list_default_constructor_test_1()
{
	stt_operations_simple_list * list_;

	list_ = stt_operations_simple_list_example_print_identifier_foo();
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_print_identifier_foo(
			list_);
#endif

	stt_operations_simple_list_destructor(list_);
}

void
stt_operations_simple_list_default_constructor_tests()
{
	stt_operations_simple_list_default_constructor_test_0();
	stt_operations_simple_list_default_constructor_test_1();
}


tests_simple_list *
register_stt_operations_simple_list_default_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_operations_simple_list_default_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& stt_operations_simple_list_default_constructor_test_0);
	tests_simple_list_push_back(
			tests,
			& stt_operations_simple_list_default_constructor_test_1);
	return tests;
}

void
stt_operations_simple_list_constructors_tests()
{
	stt_operations_simple_list_default_constructor_tests();
}

tests_simple_list *
register_stt_operations_simple_list_constructors_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_operations_simple_list_constructors_tests(
		tests_simple_list * tests)
{
	tests = register_stt_operations_simple_list_default_constructor_tests(
			tests);
	return tests;
}

/**  An empty list can not be equal to a non empty list. */
void
stt_operations_simple_list_equality_test_0()
{
	stt_operations_simple_list * l0_;
	stt_operations_simple_list * l1_;
	amara_boolean equality_;

	l0_ = stt_operations_simple_list_default_constructor();
	forced_assertion(l0_ != NULL);

	l1_ = stt_operations_simple_list_example_one_operation_list();
	forced_assertion(l1_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_one_operation_list(
			l1_);
#endif

	equality_ = stt_operations_simple_lists_equality(l0_, l1_);
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);

	stt_operations_simple_list_destructor(l0_);
	stt_operations_simple_list_destructor(l1_);
}

/**  A non empty list can not be equal to an empty list. */
void
stt_operations_simple_list_equality_test_1()
{
	stt_operations_simple_list * l0_;
	stt_operations_simple_list * l1_;
	amara_boolean equality_;

	l0_ = stt_operations_simple_list_example_one_operation_list();
	forced_assertion(l0_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_one_operation_list(
			l0_);
#endif

	l1_ = stt_operations_simple_list_default_constructor();
	forced_assertion(l1_ != NULL);

	equality_ = stt_operations_simple_lists_equality(l0_, l1_);
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);

	stt_operations_simple_list_destructor(l0_);
	stt_operations_simple_list_destructor(l1_);
}

/**  An empty list is equal to another empty list. */
void
stt_operations_simple_list_equality_test_2()
{
	stt_operations_simple_list * l0_;
	stt_operations_simple_list * l1_;
	amara_boolean equality_;

	l0_ = stt_operations_simple_list_default_constructor();
	forced_assertion(l0_ != NULL);

	l1_ = stt_operations_simple_list_default_constructor();
	forced_assertion(l1_ != NULL);

	equality_ = stt_operations_simple_lists_equality(l0_, l1_);
	forced_assertion(equality_ == AMARA_BOOLEAN_TRUE);

	stt_operations_simple_list_destructor(l0_);
	stt_operations_simple_list_destructor(l1_);
}

/**  A list with `n` elements is not equal to a list with `n + 1`
 * elements. */
void
stt_operations_simple_list_equality_test_3()
{
	stt_operations_simple_list * l0_;
	stt_operations_simple_list * l1_;
	amara_boolean equality_;

	l0_ = stt_operations_simple_list_example_one_operation_list();
	forced_assertion(l0_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_one_operation_list(
			l0_);
#endif

	l1_ = stt_operations_simple_list_example_two_operations_list();
	forced_assertion(l1_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_two_operations_list(
			l1_);
#endif

	equality_ = stt_operations_simple_lists_equality(l0_, l1_);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_one_operation_list(
			l0_);
	assert_expectations_on_stt_operations_simple_list_example_two_operations_list(
			l1_);
#endif
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);

	stt_operations_simple_list_destructor(l0_);
	stt_operations_simple_list_destructor(l1_);
}

/**  A list with `n + 1` elements is not equal to a list with `n`
 * elements. */
void
stt_operations_simple_list_equality_test_4()
{
	stt_operations_simple_list * l0_;
	stt_operations_simple_list * l1_;
	amara_boolean equality_;

	l0_ = stt_operations_simple_list_example_two_operations_list();
	forced_assertion(l0_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_two_operations_list(
			l0_);
#endif

	l1_ = stt_operations_simple_list_example_one_operation_list();
	forced_assertion(l1_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_one_operation_list(
			l1_);
#endif

	equality_ = stt_operations_simple_lists_equality(l0_, l1_);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_two_operations_list(
			l0_);
	assert_expectations_on_stt_operations_simple_list_example_one_operation_list(
			l1_);
#endif
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);

	stt_operations_simple_list_destructor(l0_);
	stt_operations_simple_list_destructor(l1_);
}

/**  If an element in a list is different from another element in the
 * same index in another list, then the whole two such lists are
 * different. */
void
stt_operations_simple_list_equality_test_5()
{
	stt_operations_simple_list * l0_;
	stt_operations_simple_list * l1_;
	amara_boolean equality_;

	l0_ = stt_operations_simple_list_example_one_operation_list();
	forced_assertion(l0_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_one_operation_list(
			l0_);
#endif

	l1_ = stt_operations_simple_list_example_one_operation_list();
	forced_assertion(l1_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_one_operation_list(
			l1_);
#endif

	/*   Perform a tainting manipulation. */
#ifndef NDEBUG
	assertion(l1_->first != NULL);
	assertion(l1_->first->type_ == STT_OPERATION_TYPE_PRINT);
#endif
	l1_->first->type_ = STT_OPERATION_TYPE_READ_NATURAL_INTO_VALUE;

	equality_ = stt_operations_simple_lists_equality(l0_, l1_);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_one_operation_list(
			l0_);
	/*
	assert_expectations_on_stt_operations_simple_list_example_one_operation_list(
			l1_);
	*/
	assertion(l1_->first != NULL);
	assertion(l1_->first->type_ ==
			STT_OPERATION_TYPE_READ_NATURAL_INTO_VALUE);
#endif
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);

	stt_operations_simple_list_destructor(l0_);
	stt_operations_simple_list_destructor(l1_);
}

void
stt_operations_simple_list_equality_tests()
{
	stt_operations_simple_list_equality_test_0();
	stt_operations_simple_list_equality_test_1();
	stt_operations_simple_list_equality_test_2();
	stt_operations_simple_list_equality_test_3();
	stt_operations_simple_list_equality_test_4();
	stt_operations_simple_list_equality_test_5();
}

tests_simple_list *
register_stt_operations_simple_list_equality_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_operations_simple_list_equality_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& stt_operations_simple_list_equality_test_0);
	tests_simple_list_push_back(
			tests,
			& stt_operations_simple_list_equality_test_1);
	tests_simple_list_push_back(
			tests,
			& stt_operations_simple_list_equality_test_2);
	return tests;
}

void
stt_operations_simple_list_tests()
{
	stt_operations_simple_list_constructors_tests();
	stt_operations_simple_list_equality_tests();
}

tests_simple_list *
register_stt_operations_simple_list_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_operations_simple_list_constructors_tests(
			tests);
	returning_ = register_stt_operations_simple_list_equality_tests(
			returning_);
	return returning_;
}
