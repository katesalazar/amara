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
 * src/rtg/rtg_operation_tests.c: Test the Amara runtime graph
 * application function operation.
 */

#include "../asr/assertion.h"

#include "../cmn/amara_string_tests.h"

#include "../stt/stt_operation_tests.h"

#include "rtg_operation_arg.h"

#include "rtg_operation_arg_tests.h"

#include "rtg_operation_tests.h"

rtg_operation *
rtg_operation_example_print_string_literal_foo()
{
	rtg_operation * operation_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	amara_string * string_literal_;

	operation_arg_ = rtg_operation_arg_default_constructor();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(operation_arg_->string_literal_ == NULL);
#endif

	string_literal_ = amara_string_example_foo();
	forced_assertion(string_literal_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_foo(string_literal_);
#endif

	rtg_operation_arg_set_string_literal(operation_arg_, string_literal_);
	rtg_operation_arg_set_type(
			operation_arg_, RTG_OPERATION_ARG_TYPE_STRING_LITERAL);

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);
#ifndef NDEBUG
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 0);
#endif

	amara_string_destructor(string_literal_);

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
#ifndef NDEBUG
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 1);
#endif

	rtg_operation_arg_destructor(operation_arg_);

	operation_ = rtg_operation_exhaustive_constructor(
			RTG_OPERATION_TYPE_PRINT,
			operation_args_);
	forced_assertion(operation_ != NULL);

	rtg_operation_args_simple_list_destructor(operation_args_);

	return operation_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_example_print_string_literal_foo(
		const rtg_operation * operation)
{
	rtg_operation_args_simple_list * args_;
	rtg_operation_arg * arg_;
	amara_string * expected_operation_arg_string_literal_;
	amara_boolean equality_;

	expected_operation_arg_string_literal_ = amara_string_example_foo();
	forced_assertion(expected_operation_arg_string_literal_ != NULL);
	assert_expectations_on_amara_string_example_foo(
			expected_operation_arg_string_literal_);

	forced_assertion(operation != NULL);
	assertion(operation->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operation->args_ != NULL);
	args_ = operation->args_;
	assertion(args_->first != NULL);
	arg_ = args_->first;
	assertion(arg_->type_ == RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(arg_->string_literal_ != NULL);
	assertion(arg_->string_literal_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_operation_arg_string_literal_,
			arg_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(args_->next == NULL);

	amara_string_destructor(expected_operation_arg_string_literal_);
}

#endif

rtg_operation *
rtg_operation_example_print_string_literal_bar()
{
	rtg_operation * operation_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	amara_string * string_literal_;

	operation_arg_ = rtg_operation_arg_default_constructor();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(operation_arg_->string_literal_ == NULL);
#endif

	string_literal_ = amara_string_exhaustive_constructor("bar");
	forced_assertion(string_literal_ != NULL);

	rtg_operation_arg_set_string_literal(operation_arg_, string_literal_);
	rtg_operation_arg_set_type(
			operation_arg_, RTG_OPERATION_ARG_TYPE_STRING_LITERAL);

	amara_string_destructor(string_literal_);

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);
#ifndef NDEBUG
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 0);
#endif

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
#ifndef NDEBUG
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 1);
#endif

	rtg_operation_arg_destructor(operation_arg_);

	operation_ = rtg_operation_exhaustive_constructor(
			RTG_OPERATION_TYPE_PRINT,
			operation_args_);
	forced_assertion(operation_ != NULL);

	rtg_operation_args_simple_list_destructor(operation_args_);

	return operation_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_example_print_string_literal_bar(
		const rtg_operation * operation)
{
	rtg_operation_args_simple_list * args_;
	rtg_operation_arg * arg_;
	amara_string * expected_operation_arg_string_literal_;
	amara_boolean equality_;

	expected_operation_arg_string_literal_ =
			amara_string_exhaustive_constructor("bar");
	forced_assertion(expected_operation_arg_string_literal_ != NULL);
	forced_assertion(expected_operation_arg_string_literal_->value_ !=
			NULL);

	forced_assertion(operation != NULL);
	assertion(operation->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operation->args_ != NULL);
	args_ = operation->args_;
	assertion(args_->first != NULL);
	arg_ = args_->first;
	assertion(arg_->type_ == RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(arg_->string_literal_ != NULL);
	assertion(arg_->string_literal_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_operation_arg_string_literal_,
			arg_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(args_->next == NULL);

	amara_string_destructor(expected_operation_arg_string_literal_);
}

#endif

rtg_operation *
rtg_operation_example_read_natural_into_foo()
{
	rtg_operation * operation_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	amara_string * identifier_;

	operation_arg_ = rtg_operation_arg_default_constructor();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(operation_arg_->string_literal_ == NULL);
#endif

	identifier_ = amara_string_exhaustive_constructor("i_foo");
	forced_assertion(identifier_ != NULL);

	rtg_operation_arg_set_identifier(operation_arg_, identifier_);
	rtg_operation_arg_set_type(
			operation_arg_,
			/*   This might be a bit counter intuitive, but it is
			 * like this... I think (but am not sure!). */
			RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED);

	amara_string_destructor(identifier_);

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);
#ifndef NDEBUG
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 0);
#endif

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
#ifndef NDEBUG
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 1);
#endif

	rtg_operation_arg_destructor(operation_arg_);

	operation_ = rtg_operation_exhaustive_constructor(
			RTG_OPERATION_TYPE_READ_NATURAL_INTO_VALUE,
			operation_args_);
	forced_assertion(operation_ != NULL);

	rtg_operation_args_simple_list_destructor(operation_args_);

	return operation_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_example_read_natural_into_foo(
		const rtg_operation * operation)
{
	assertion(operation != NULL);
	assertion(operation->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_INTO_VALUE);
	assertion(operation->args_ != NULL);
	assertion(operation->args_->first != NULL);
	assertion(operation->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED);
	assertion(operation->args_->first->type_ != 0);
	assertion(operation->args_->next == NULL);
}

#endif

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_example_read_integer_into_foo(
		const rtg_operation * operation)
{
	assertion(operation != NULL);
	assertion(operation->type_ ==
			RTG_OPERATION_TYPE_READ_INTEGER_INTO_VALUE);
	assertion(operation->args_ != NULL);
	assertion(operation->args_->first != NULL);
	assertion(operation->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED);
	assertion(operation->args_->first->identifier_ != NULL);
	assertion(operation->args_->first->identifier_->value_ != NULL);
	assertion(operation->args_->first->identifier_->value_[0] == 'f');
	assertion(operation->args_->first->identifier_->value_[1] == 'o');
	assertion(operation->args_->first->identifier_->value_[2] == 'o');
	assertion(operation->args_->first->identifier_->value_[3] == '\0');
	assertion(operation->args_->next == NULL);
}

#endif

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_example_print_identifier_foo(
		const rtg_operation * operation)
{
	assertion(operation != NULL);
	assertion(operation->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operation->args_ != NULL);
	assertion(operation->args_->first != NULL);
	assertion(operation->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_IDENTIFIER);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation->args_->first);
	assertion(operation->args_->next == NULL);
}

#endif

/*

rtg_operation *
rtg_operation_example_print_integer_literal(void)
{
	;
}

*/

/*

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_example_print_integer_literal(
		const rtg_operation * operation)
{
	assertion(operation != NULL);
	assertion(operation->type_ ==
			RTG_OPERATION_TYPE_PRINT_INTEGER_LITERAL);
	assertion(operation->args_ != NULL);
	assertion(operation->args_->first != NULL);
	assertion(operation->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_INTEGER_LITERAL);
	assertion(operation->args_->first->integer_literal_ != NULL);
	assertion(operation->args_->first->integer_literal_->value_ != NULL);
	assertion(operation->args_->first->integer_literal_->value_[0] == '-');
	assertion(operation->args_->first->integer_literal_->value_[1] == '1');
	assertion(operation->args_->first->integer_literal_->value_[2] ==
			'\0');
}

#endif

*/

/**  Construct an invalid operation using the exhaustive constructor
 * and then destroy it. */
void
rtg_operation_exhaustive_constructor_test_0()
{
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation * operation_;

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);

	operation_ = rtg_operation_exhaustive_constructor(
			RTG_OPERATION_TYPE_INVALID, operation_args_);
	forced_assertion(operation_ != NULL);
	assertion(operation_->type_ == RTG_OPERATION_TYPE_INVALID);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first == NULL);
	assertion(operation_->args_->next == NULL);

	rtg_operation_destructor(operation_);
	rtg_operation_args_simple_list_destructor(operation_args_);
}

/**  Construct an invalid operation using the exhaustive constructor
 * and then destroy it. */
void
rtg_operation_exhaustive_constructor_test_1()
{
	unsigned char requested_type_;
	rtg_operation_args_simple_list * operation_args_;
	/*
	rtg_operation_arg * operation_arg_;
	*/
	rtg_operation * operation_;

	requested_type_ = RTG_OPERATION_TYPE_INVALID;

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);

	/*
	operation_arg_ = rtg_operation_arg_example_identifier_foo();
	forced_assertion(operation_arg_ != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);
	*/

	operation_ = rtg_operation_exhaustive_constructor(
			requested_type_, operation_args_);
	forced_assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);
	assertion(operation_ != NULL);
	assertion(operation_->type_ == RTG_OPERATION_TYPE_INVALID);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first == NULL);
	assertion(operation_->args_->next == NULL);

	rtg_operation_destructor(operation_);
	/*
	rtg_operation_arg_destructor(operation_arg_);
	*/
	rtg_operation_args_simple_list_destructor(operation_args_);
}

/**  Construct an invalid operation using the exhaustive constructor
 * and then destroy it. */
void
rtg_operation_exhaustive_constructor_test_2()
{
	unsigned char requested_type_;
	rtg_operation_args_simple_list * operation_args_;
	/*
	rtg_operation_arg * operation_arg_;
	*/
	rtg_operation * operation_;

	requested_type_ = RTG_OPERATION_TYPE_INVALID;

	operation_args_ = NULL;

	/*
	operation_arg_ = rtg_operation_arg_example_identifier_foo();
	assertion(operation_arg_ != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);
	*/

	operation_ = rtg_operation_exhaustive_constructor(
			requested_type_, operation_args_);
	forced_assertion(operation_ != NULL);
	assertion(operation_->type_ == RTG_OPERATION_TYPE_INVALID);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first == NULL);
	assertion(operation_->args_->next == NULL);

	rtg_operation_destructor(operation_);
	/*
	rtg_operation_arg_destructor(operation_arg_);
	*/
}

/**  Construct a _read into value_ valid operation using the exhaustive
 * constructor and then destroy it. */
void
rtg_operation_exhaustive_constructor_test_3()
{
	unsigned char requested_type_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	rtg_operation * operation_;

	requested_type_ = RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE;

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);

	operation_arg_ = rtg_operation_arg_example_identifier_foo();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);
#endif

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);
#endif
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
#endif
	assertion(operation_args_->next == NULL);

	operation_ = rtg_operation_exhaustive_constructor(
			requested_type_, operation_args_);
	forced_assertion(operation_args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
#endif
	assertion(operation_args_->next == NULL);
	assertion(operation_ != NULL);
	assertion(operation_->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_INTO_VALUE);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_->args_->first);
#endif
	assertion(operation_->args_->next == NULL);

	rtg_operation_destructor(operation_);
	rtg_operation_arg_destructor(operation_arg_);
	rtg_operation_args_simple_list_destructor(operation_args_);
}

/**  Construct a _read into value_ valid operation using the exhaustive
 * constructor and then copy it and then destroy it and destroy the copy
 * too. */
/*
void
rtg_operation_exhaustive_constructor_test_4()
{
	unsigned char requested_type_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_zero_;
	rtg_operation_arg * operation_arg_one_;
	rtg_operation * operation_zero_;
	rtg_operation * operation_one_;

	requested_type_ = RTG_OPERATION_TYPE_ADDITION;

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);

	operation_arg_zero_ = rtg_operation_arg_example_identifier_foo();
	forced_assertion(operation_arg_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_zero_);
#endif

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_zero_);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_zero_);
#endif
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
#endif
	assertion(operation_args_->next == NULL);

	operation_arg_one_ = rtg_operation_arg_example_identifier_bar();
	forced_assertion(operation_arg_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_arg_one_);
#endif

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_one_);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_arg_one_);
#endif
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_args_->first);
#endif
	assertion(operation_args_->next != NULL);
	assertion(operation_args_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->next->first);
#endif
	assertion(operation_args_->next->next == NULL);

	operation_zero_ = rtg_operation_exhaustive_constructor(
			requested_type_, operation_args_);
	forced_assertion(operation_args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_args_->first);
#endif
	assertion(operation_args_->next != NULL);
	assertion(operation_args_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->next->first);
#endif
	assertion(operation_args_->next->next == NULL);
	assertion(operation_zero_ != NULL);
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_ADDITION);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_zero_->args_->first);
#endif
	assertion(operation_zero_->args_->next != NULL);
	assertion(operation_zero_->args_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_zero_->args_->next->first);
#endif
	assertion(operation_zero_->args_->next->next == NULL);

	operation_one_ = rtg_operation_copy_constructor(operation_zero_);
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_ADDITION);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_zero_->args_->first);
#endif
	assertion(operation_zero_->args_->next != NULL);
	assertion(operation_zero_->args_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_zero_->args_->next->first);
#endif
	assertion(operation_zero_->args_->next->next == NULL);
	forced_assertion(operation_one_ != NULL);
	assertion(operation_one_->type_ == RTG_OPERATION_TYPE_ADDITION);
	assertion(operation_one_->args_ != NULL);
	assertion(operation_one_->args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_one_->args_->first);
#endif
	assertion(operation_one_->args_->next != NULL);
	assertion(operation_one_->args_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_one_->args_->next->first);
#endif
	assertion(operation_one_->args_->next->next == NULL);

	rtg_operation_destructor(operation_one_);
	rtg_operation_destructor(operation_zero_);
	rtg_operation_arg_destructor(operation_arg_one_);
	rtg_operation_arg_destructor(operation_arg_zero_);
	rtg_operation_args_simple_list_destructor(operation_args_);
}
*/

void
rtg_operation_exhaustive_constructor_tests()
{
	rtg_operation_exhaustive_constructor_test_0();
	rtg_operation_exhaustive_constructor_test_1();
	rtg_operation_exhaustive_constructor_test_2();
	rtg_operation_exhaustive_constructor_test_3();
	/*
	rtg_operation_exhaustive_constructor_test_4();
	*/
}

tests_simple_list *
register_rtg_operation_exhaustive_constructor_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_operation_exhaustive_constructor_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests, & rtg_operation_exhaustive_constructor_test_0);
	tests_simple_list_push_back(
			tests, & rtg_operation_exhaustive_constructor_test_1);
	tests_simple_list_push_back(
			tests, & rtg_operation_exhaustive_constructor_test_2);
	tests_simple_list_push_back(
			tests, & rtg_operation_exhaustive_constructor_test_3);
	/*
	tests_simple_list_push_back(
			tests, & rtg_operation_exhaustive_constructor_test_4);
	*/
	return tests;
}

/**  Create a sum operation, copy it, and destroy it and the copy. */
void
rtg_operation_copy_constructor_test_0()
{
	unsigned char requested_type_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	rtg_operation * operation_zero_;
	rtg_operation * operation_one_;

	requested_type_ = RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE;

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);

	operation_arg_ = rtg_operation_arg_example_identifier_foo();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);
#endif

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);
#endif
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
#endif
	assertion(operation_args_->next == NULL);

	operation_zero_ = rtg_operation_exhaustive_constructor(
			requested_type_, operation_args_);
	forced_assertion(operation_args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
#endif
	assertion(operation_args_->next == NULL);
	assertion(operation_zero_ != NULL);
	assertion(operation_zero_->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_INTO_VALUE);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_zero_->args_->first);
#endif
	assertion(operation_zero_->args_->next == NULL);

	operation_one_ = rtg_operation_copy_constructor(operation_zero_);
	forced_assertion(operation_zero_->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_INTO_VALUE);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_zero_->args_->first);
#endif
	assertion(operation_zero_->args_->next == NULL);
	assertion(operation_one_ != NULL);
	assertion(operation_one_->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_INTO_VALUE);
	assertion(operation_one_->args_ != NULL);
	assertion(operation_one_->args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_one_->args_->first);
#endif
	assertion(operation_one_->args_->next == NULL);

	rtg_operation_destructor(operation_one_);
	rtg_operation_destructor(operation_zero_);
	rtg_operation_arg_destructor(operation_arg_);
	rtg_operation_args_simple_list_destructor(operation_args_);
}

/**  Create a _print without line feed and carriage return_ operation,
 * copy it, and destroy it and the copy. */
void
rtg_operation_copy_constructor_test_1()
{
	unsigned char requested_type_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	rtg_operation * operation_zero_;
	rtg_operation * operation_one_;

	requested_type_ = RTG_OPERATION_TYPE_PRINT;

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);

	operation_arg_ = rtg_operation_arg_example_identifier_foo();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);
#endif

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);
#endif
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
#endif
	assertion(operation_args_->next == NULL);

	operation_zero_ = rtg_operation_exhaustive_constructor(
			requested_type_, operation_args_);
	forced_assertion(operation_args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
#endif
	assertion(operation_args_->next == NULL);
	forced_assertion(operation_zero_ != NULL);
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_zero_->args_->first);
#endif
	assertion(operation_zero_->args_->next == NULL);

	operation_one_ = rtg_operation_copy_constructor(operation_zero_);
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_zero_->args_->first);
#endif
	assertion(operation_zero_->args_->next == NULL);
	forced_assertion(operation_one_ != NULL);
	assertion(operation_one_->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operation_one_->args_ != NULL);
	assertion(operation_one_->args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_one_->args_->first);
#endif
	assertion(operation_one_->args_->next == NULL);

	rtg_operation_destructor(operation_one_);
	rtg_operation_destructor(operation_zero_);
	rtg_operation_arg_destructor(operation_arg_);
	rtg_operation_args_simple_list_destructor(operation_args_);
}

void
rtg_operation_copy_constructor_test_10_read_natural_from_stdin()
{
	rtg_operation * operation_zero_;
	rtg_operation * operation_one_;

	operation_zero_ = rtg_operation_example_read_natural_into_foo();
	forced_assertion(operation_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_example_read_natural_into_foo(
			operation_zero_);
#endif

	operation_one_ = rtg_operation_copy_constructor(operation_zero_);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_example_read_natural_into_foo(
			operation_zero_);
#endif
	forced_assertion(operation_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_example_read_natural_into_foo(
			operation_one_);
#endif

	rtg_operation_destructor(operation_one_);
	rtg_operation_destructor(operation_zero_);
}

void
rtg_operation_copy_constructor_tests()
{
	rtg_operation_copy_constructor_test_0();
	rtg_operation_copy_constructor_test_1();
	rtg_operation_copy_constructor_test_10_read_natural_from_stdin();
}

tests_simple_list *
register_rtg_operation_copy_constructor_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_operation_copy_constructor_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(tests,
	                            & rtg_operation_copy_constructor_test_0);
	tests_simple_list_push_back(tests,
	                            & rtg_operation_copy_constructor_test_1);
	tests_simple_list_push_back(
			tests,
			& rtg_operation_copy_constructor_test_10_read_natural_from_stdin);
	return tests;
}

void
rtg_operation_transformation_constructor_test_10_read_natural_into_value()
{
	stt_operation * stt_operation_;
	rtg_operation_out_of_stt_operation_ret * transformation_ret_;
	rtg_operation * rtg_operation_;

	stt_operation_ = stt_operation_example_read_natural_into_foo();
	forced_assertion(stt_operation_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_read_natural_into_foo(
			stt_operation_);
#endif

	transformation_ret_ =
			rtg_operation_out_of_stt_operation(stt_operation_,
			                                   NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_read_natural_into_foo(
			stt_operation_);
#endif
	forced_assertion(transformation_ret_ != NULL);
#ifndef NDEBUG
	assertion(transformation_ret_->status ==
			RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS);
#endif
	forced_assertion(transformation_ret_->operation != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_example_read_natural_into_foo(
			transformation_ret_->operation);
#endif

	stt_operation_destructor(stt_operation_);

	rtg_operation_ = transformation_ret_->operation;

	free(transformation_ret_);
	rtg_operation_destructor(rtg_operation_);
}

void
rtg_operation_transformation_constructor_test_20_read_integer_into_value()
{
	stt_operation * stt_operation_;
	rtg_operation_out_of_stt_operation_ret * transformation_ret_;
	rtg_operation * rtg_operation_;

	stt_operation_ = stt_operation_example_read_integer_into_foo();
	forced_assertion(stt_operation_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_read_integer_into_foo(
			stt_operation_);
#endif

	transformation_ret_ =
			rtg_operation_out_of_stt_operation(stt_operation_,
			                                   NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_read_integer_into_foo(
			stt_operation_);
#endif
	forced_assertion(transformation_ret_ != NULL);
#ifndef NDEBUG
	assertion(transformation_ret_->status ==
			RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS);
#endif
	forced_assertion(transformation_ret_->operation != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_example_read_integer_into_foo(
			transformation_ret_->operation);
#endif

	stt_operation_destructor(stt_operation_);

	rtg_operation_ = transformation_ret_->operation;

	free(transformation_ret_);
	rtg_operation_destructor(rtg_operation_);
}

/*

void
rtg_operation_transformation_constructor_test_30_print_integer_literal()
{
	stt_operation * stt_operation_;
	rtg_operation_out_of_stt_operation_ret * transformation_ret_;
	rtg_operation * rtg_operation_;

	stt_operation_ = stt_operation_example_print_integer_literal();
	forced_assertion(stt_operation_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_print_integer_literal(
			stt_operation_);
#endif

	transformation_ret_ =
			rtg_operation_out_of_stt_operation(stt_operation_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_print_integer_literal(
			stt_operation_);
#endif
	forced_assertion(transformation_ret_ != NULL);
#ifndef NDEBUG
	assertion(transformation_ret_->status ==
			RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS);
#endif
	forced_assertion(transformation_ret_->operation != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_example_print_integer_literal(
			transformation_ret_->operation);
#endif

	stt_operation_destructor(stt_operation_);

	rtg_operation_ = transformation_ret_->operation;

	free(transformation_ret_);
	rtg_operation_destructor(rtg_operation_);
}

*/

void
rtg_operation_transformation_constructor_tests()
{
	rtg_operation_transformation_constructor_test_10_read_natural_into_value();
	rtg_operation_transformation_constructor_test_20_read_integer_into_value();
	/*
	rtg_operation_transformation_constructor_test_30_print_integer_literal();
	*/
}

tests_simple_list *
register_rtg_operation_transformation_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_operation_transformation_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& rtg_operation_transformation_constructor_test_10_read_natural_into_value);
	tests_simple_list_push_back(
			tests,
			& rtg_operation_transformation_constructor_test_20_read_integer_into_value);
	/*
	tests_simple_list_push_back(
			tests,
			& rtg_operation_transformation_constructor_test_30_print_integer_literal);
	*/
	return tests;
}

void
rtg_operation_constructors_tests()
{
	rtg_operation_exhaustive_constructor_tests();
	rtg_operation_copy_constructor_tests();
	rtg_operation_transformation_constructor_tests();
}

tests_simple_list *
register_rtg_operation_constructors_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_operation_constructors_tests(tests_simple_list * tests)
{
	return register_rtg_operation_transformation_constructor_tests(
	       register_rtg_operation_copy_constructor_tests(
	       register_rtg_operation_exhaustive_constructor_tests(tests)));
}

void
rtg_operation_tests()
{
	rtg_operation_constructors_tests();
}

tests_simple_list *
register_rtg_operation_tests(tests_simple_list * tests)
{
	return register_rtg_operation_constructors_tests(tests);
}
