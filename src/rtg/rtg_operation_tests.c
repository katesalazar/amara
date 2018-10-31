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
 * src/rtg/rtg_operation_tests.c: Test the Amara runtime graph
 * application function operation.
 */

#include "../asr/assertion.h"
#include "rtg_operation_arg.h"
#include "rtg_operation_arg_tests.h"
#include "rtg_operation_tests.h"

rtg_operation *
rtg_operation_example_print_foo()
{
	rtg_operation * operation_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	amara_string * string_literal_;

	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(operation_arg_->string_literal_ == NULL);

	string_literal_ = amara_string_exhaustive_constructor("foo");

	rtg_operation_arg_set_string_literal(operation_arg_, string_literal_);
	rtg_operation_arg_set_type(
			operation_arg_, RTG_OPERATION_ARG_TYPE_STRING_LITERAL);

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	assertion(operation_args_ != NULL);
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 0);

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 1);

	operation_ = rtg_operation_exhaustive_constructor(
			RTG_OPERATION_TYPE_PRINT,
			operation_args_);

	return operation_;
}

void
assert_expectations_on_rtg_operation_example_print_foo(
		const rtg_operation * operation)
{
	rtg_operation_args_simple_list * args_;
	rtg_operation_arg * arg_;
	amara_string * expected_operation_arg_string_literal_;
	amara_boolean equality_;

	expected_operation_arg_string_literal_ =
			amara_string_exhaustive_constructor("foo");
	assertion(expected_operation_arg_string_literal_ != NULL);
	assertion(expected_operation_arg_string_literal_->value_ != NULL);

	assertion(operation != NULL);
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

rtg_operation *
rtg_operation_example_print_bar()
{
	rtg_operation * operation_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	amara_string * string_literal_;

	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(operation_arg_->string_literal_ == NULL);

	string_literal_ = amara_string_exhaustive_constructor("bar");

	rtg_operation_arg_set_string_literal(operation_arg_, string_literal_);
	rtg_operation_arg_set_type(
			operation_arg_, RTG_OPERATION_ARG_TYPE_STRING_LITERAL);

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	assertion(operation_args_ != NULL);
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 0);

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 1);

	operation_ = rtg_operation_exhaustive_constructor(
			RTG_OPERATION_TYPE_PRINT,
			operation_args_);

	return operation_;
}

void
assert_expectations_on_rtg_operation_example_print_bar(
		const rtg_operation * operation)
{
	rtg_operation_args_simple_list * args_;
	rtg_operation_arg * arg_;
	amara_string * expected_operation_arg_string_literal_;
	amara_boolean equality_;

	expected_operation_arg_string_literal_ =
			amara_string_exhaustive_constructor("bar");
	assertion(expected_operation_arg_string_literal_ != NULL);
	assertion(expected_operation_arg_string_literal_->value_ != NULL);

	assertion(operation != NULL);
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

rtg_operation *
rtg_operation_example_read_natural_into_i_foo()
{
	rtg_operation * operation_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	amara_string * identifier_;

	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(operation_arg_->string_literal_ == NULL);

	identifier_ = amara_string_exhaustive_constructor("i_foo");

	rtg_operation_arg_set_identifier(operation_arg_, identifier_);
	rtg_operation_arg_set_type(
			operation_arg_,
			/*   This might be a bit counter intuitive, but it is
			 * like this... I think (but am not sure!). */
			RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED);

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	assertion(operation_args_ != NULL);
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 0);

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 1);

	operation_ = rtg_operation_exhaustive_constructor(
			RTG_OPERATION_TYPE_READ_NATURAL_INTO_VALUE,
			operation_args_);

	return operation_;
}

/**  Construct an invalid operation using the exhaustive constructor
 * and then destroy it. */
void
rtg_operation_construct_and_destruct_test_0()
{
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation * operation_;

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);

	operation_ = rtg_operation_exhaustive_constructor(
			RTG_OPERATION_TYPE_INVALID, operation_args_);
	assertion(operation_ != NULL);
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
rtg_operation_construct_and_destruct_test_1()
{
	uint_fast8_t requested_type_;
	rtg_operation_args_simple_list * operation_args_;
	/*
	rtg_operation_arg * operation_arg_;
	*/
	rtg_operation * operation_;

	requested_type_ = RTG_OPERATION_TYPE_INVALID;

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);

	/*
	operation_arg_ = rtg_operation_arg_example_identifier_foo();
	assertion(operation_arg_ != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);
	*/

	operation_ = rtg_operation_exhaustive_constructor(
			requested_type_, operation_args_);
	assertion(operation_args_->first == NULL);
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
rtg_operation_construct_and_destruct_test_2()
{
	uint_fast8_t requested_type_;
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
	assertion(operation_ != NULL);
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
rtg_operation_construct_and_destruct_test_3()
{
	uint_fast8_t requested_type_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	rtg_operation * operation_;

	requested_type_ = RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE;

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);

	operation_arg_ = rtg_operation_arg_example_identifier_foo();
	assertion(operation_arg_ != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	assertion(operation_arg_ != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
	assertion(operation_args_->next == NULL);

	operation_ = rtg_operation_exhaustive_constructor(
			requested_type_, operation_args_);
	assertion(operation_args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
	assertion(operation_args_->next == NULL);
	assertion(operation_ != NULL);
	assertion(operation_->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_INTO_VALUE);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_->args_->first);
	assertion(operation_->args_->next == NULL);

	rtg_operation_destructor(operation_);
	rtg_operation_arg_destructor(operation_arg_);
	rtg_operation_args_simple_list_destructor(operation_args_);
}

/**  Construct a _read into value_ valid operation using the exhaustive
 * constructor and then copy it and then destroy it and destroy the copy
 * too. */
void
rtg_operation_construct_and_destruct_test_4()
{
	uint_fast8_t requested_type_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_zero_;
	rtg_operation_arg * operation_arg_one_;
	rtg_operation * operation_zero_;
	rtg_operation * operation_one_;

	requested_type_ = RTG_OPERATION_TYPE_ADDITION;

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);

	operation_arg_zero_ = rtg_operation_arg_example_identifier_foo();
	assertion(operation_arg_zero_ != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_zero_);

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_zero_);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_zero_);
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
	assertion(operation_args_->next == NULL);

	operation_arg_one_ = rtg_operation_arg_example_identifier_bar();
	assertion(operation_arg_one_ != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_arg_one_);

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_one_);
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_arg_one_);
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_args_->first);
	assertion(operation_args_->next != NULL);
	assertion(operation_args_->next->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->next->first);
	assertion(operation_args_->next->next == NULL);

	operation_zero_ = rtg_operation_exhaustive_constructor(
			requested_type_, operation_args_);
	assertion(operation_args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_args_->first);
	assertion(operation_args_->next != NULL);
	assertion(operation_args_->next->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->next->first);
	assertion(operation_args_->next->next == NULL);
	assertion(operation_zero_ != NULL);
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_ADDITION);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_zero_->args_->first);
	assertion(operation_zero_->args_->next != NULL);
	assertion(operation_zero_->args_->next->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_zero_->args_->next->first);
	assertion(operation_zero_->args_->next->next == NULL);

	operation_one_ = rtg_operation_copy_constructor(operation_zero_);
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_ADDITION);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_zero_->args_->first);
	assertion(operation_zero_->args_->next != NULL);
	assertion(operation_zero_->args_->next->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_zero_->args_->next->first);
	assertion(operation_zero_->args_->next->next == NULL);
	assertion(operation_one_ != NULL);
	assertion(operation_one_->type_ == RTG_OPERATION_TYPE_ADDITION);
	assertion(operation_one_->args_ != NULL);
	assertion(operation_one_->args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_bar(
			operation_one_->args_->first);
	assertion(operation_one_->args_->next != NULL);
	assertion(operation_one_->args_->next->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_one_->args_->next->first);
	assertion(operation_one_->args_->next->next == NULL);

	rtg_operation_destructor(operation_one_);
	rtg_operation_destructor(operation_zero_);
	rtg_operation_arg_destructor(operation_arg_one_);
	rtg_operation_arg_destructor(operation_arg_zero_);
	rtg_operation_args_simple_list_destructor(operation_args_);
}

/**  Create a sum operation, copy it, and destroy it and the copy. */
void
rtg_operation_construct_and_destruct_test_5()
{
	uint_fast8_t requested_type_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	rtg_operation * operation_zero_;
	rtg_operation * operation_one_;

	requested_type_ = RTG_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE;

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);

	operation_arg_ = rtg_operation_arg_example_identifier_foo();
	assertion(operation_arg_ != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	assertion(operation_arg_ != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
	assertion(operation_args_->next == NULL);

	operation_zero_ = rtg_operation_exhaustive_constructor(
			requested_type_, operation_args_);
	assertion(operation_args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
	assertion(operation_args_->next == NULL);
	assertion(operation_zero_ != NULL);
	assertion(operation_zero_->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_INTO_VARIABLE);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_zero_->args_->first);
	assertion(operation_zero_->args_->next == NULL);

	operation_one_ = rtg_operation_copy_constructor(operation_zero_);
	assertion(operation_zero_->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_INTO_VARIABLE);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_zero_->args_->first);
	assertion(operation_zero_->args_->next == NULL);
	assertion(operation_one_ != NULL);
	assertion(operation_one_->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_INTO_VARIABLE);
	assertion(operation_one_->args_ != NULL);
	assertion(operation_one_->args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_one_->args_->first);
	assertion(operation_one_->args_->next == NULL);

	rtg_operation_destructor(operation_one_);
	rtg_operation_destructor(operation_zero_);
	rtg_operation_arg_destructor(operation_arg_);
	rtg_operation_args_simple_list_destructor(operation_args_);
}

/**  Create a _print without line feed and carriage return_ operation,
 * copy it, and destroy it and the copy. */
void
rtg_operation_construct_and_destruct_test_6()
{
	uint_fast8_t requested_type_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	rtg_operation * operation_zero_;
	rtg_operation * operation_one_;

	requested_type_ = RTG_OPERATION_TYPE_PRINT_NO_CRLF;

	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);

	operation_arg_ = rtg_operation_arg_example_identifier_foo();
	assertion(operation_arg_ != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);

	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	assertion(operation_arg_ != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_arg_);
	assertion(operation_args_ != NULL);
	assertion(operation_args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
	assertion(operation_args_->next == NULL);

	operation_zero_ = rtg_operation_exhaustive_constructor(
			requested_type_, operation_args_);
	assertion(operation_args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_args_->first);
	assertion(operation_args_->next == NULL);
	assertion(operation_zero_ != NULL);
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_PRINT_NO_CRLF);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_zero_->args_->first);
	assertion(operation_zero_->args_->next == NULL);

	operation_one_ = rtg_operation_copy_constructor(operation_zero_);
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_PRINT_NO_CRLF);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_zero_->args_->first);
	assertion(operation_zero_->args_->next == NULL);
	assertion(operation_one_ != NULL);
	assertion(operation_one_->type_ == RTG_OPERATION_TYPE_PRINT_NO_CRLF);
	assertion(operation_one_->args_ != NULL);
	assertion(operation_one_->args_->first != NULL);
	assert_expectations_on_rtg_operation_arg_example_identifier_foo(
			operation_one_->args_->first);
	assertion(operation_one_->args_->next == NULL);

	rtg_operation_destructor(operation_one_);
	rtg_operation_destructor(operation_zero_);
	rtg_operation_arg_destructor(operation_arg_);
	rtg_operation_args_simple_list_destructor(operation_args_);
}

void
rtg_operation_construct_and_destruct_tests()
{
	rtg_operation_construct_and_destruct_test_0();
	rtg_operation_construct_and_destruct_test_1();
	rtg_operation_construct_and_destruct_test_2();
	rtg_operation_construct_and_destruct_test_3();
	rtg_operation_construct_and_destruct_test_4();
	rtg_operation_construct_and_destruct_test_5();
	rtg_operation_construct_and_destruct_test_6();
}

void
rtg_operation_tests()
{
	rtg_operation_construct_and_destruct_tests();
}
