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
 * src/rtg/rtg_operation_arg_tests.c: Test the Amara run time graph
 * application function operation argument class.
 */

#include "../asr/assertion.h"
#include "rtg_operation_arg.h"

rtg_operation_arg *
rtg_operation_arg_example_string_literal_foo()
{
	rtg_operation_arg * operation_arg_;
	amara_string * string_for_operation_arg_;

	string_for_operation_arg_ = amara_string_exhaustive_constructor("foo");
	assertion(string_for_operation_arg_ != NULL);
	assertion(string_for_operation_arg_->value_ != NULL);

	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	rtg_operation_arg_set_string_literal(
			operation_arg_, string_for_operation_arg_);
	assertion(operation_arg_->type_ ==
			RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(operation_arg_->string_literal_ != NULL);
	assertion(operation_arg_->string_literal_->value_ != NULL);
	assertion(string_for_operation_arg_->value_ != NULL);

	rtg_operation_arg_set_type(
			operation_arg_, RTG_OPERATION_ARG_TYPE_STRING_LITERAL);

	amara_string_destructor(string_for_operation_arg_);

	return operation_arg_;
}

void
assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
		const rtg_operation_arg * operation_arg)
{
	amara_string * expected_string_literal_;
	amara_boolean equality_;

	expected_string_literal_ = amara_string_exhaustive_constructor("foo");
	assertion(expected_string_literal_ != NULL);
	assertion(expected_string_literal_->value_ != NULL);

	assertion(operation_arg->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operation_arg->string_literal_ != NULL);
	assertion(operation_arg->string_literal_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_string_literal_,
			operation_arg->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(expected_string_literal_);
}

rtg_operation_arg *
rtg_operation_arg_example_identifier_foo()
{
	return rtg_operation_arg_example_string_literal_foo(); /* XXX */
}

void
assert_expectations_on_rtg_operation_arg_example_identifier_foo(
		const rtg_operation_arg * operation_arg)
{
	assert_expectations_on_rtg_operation_arg_example_string_literal_foo( /* XXX */
			operation_arg); /* XXX */
}

rtg_operation_arg *
rtg_operation_arg_example_identifier_bar()
{
	rtg_operation_arg * operation_arg_;
	amara_string * string_for_operation_arg_;
	amara_boolean equality_;

	string_for_operation_arg_ = amara_string_exhaustive_constructor("bar");
	assertion(string_for_operation_arg_ != NULL);
	assertion(string_for_operation_arg_->value_ != NULL);

	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	rtg_operation_arg_set_identifier(
			operation_arg_, string_for_operation_arg_);
	assertion(operation_arg_->type_ ==
			RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(operation_arg_->identifier_ != NULL);
	assertion(operation_arg_->identifier_->value_ != NULL);
	equality_ = amara_string_equality(
			operation_arg_->identifier_,
			string_for_operation_arg_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(string_for_operation_arg_->value_ != NULL);

	rtg_operation_arg_set_type(
			operation_arg_,
			RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED);

	amara_string_destructor(string_for_operation_arg_);

	return operation_arg_;
}

void
assert_expectations_on_rtg_operation_arg_example_identifier_bar(
		const rtg_operation_arg * operation_arg)
{
	amara_string * expected_identifier_;
	amara_boolean equality_;

	expected_identifier_ = amara_string_exhaustive_constructor("bar");
	assertion(expected_identifier_ != NULL);
	assertion(expected_identifier_->value_ != NULL);

	assertion(operation_arg->type_ ==
			RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED);
	assertion(operation_arg->identifier_ != NULL);
	assertion(operation_arg->identifier_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_identifier_, operation_arg->identifier_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(expected_identifier_);
}

void
rtg_operation_arg_construct_and_destruct_test_0()
{
	rtg_operation_arg * operation_arg_;

	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);

	rtg_operation_arg_destructor(operation_arg_);
}

void
rtg_operation_arg_construct_and_destruct_tests()
{
	rtg_operation_arg_construct_and_destruct_test_0();
}

/* FIXME Remove leaks in this test. */
void
rtg_operation_arg_type_setter_test_0_string_literal()
{
	rtg_operation_arg * operation_arg_;

	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);

	rtg_operation_arg_set_string_literal(
			operation_arg_,
			amara_string_exhaustive_constructor("foo"));
	assertion(amara_string_equality(
			operation_arg_->string_literal_,
			amara_string_exhaustive_constructor("foo")));
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);

	rtg_operation_arg_set_string_literal(
			operation_arg_,
			amara_string_exhaustive_constructor("bar"));
	assertion(amara_string_equality(
			operation_arg_->string_literal_,
			amara_string_exhaustive_constructor("bar")));
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);

	rtg_operation_arg_set_type(
			operation_arg_, RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operation_arg_->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(amara_string_equality(
			operation_arg_->string_literal_,
			amara_string_exhaustive_constructor("bar")));

	rtg_operation_arg_destructor(operation_arg_);
}

void
rtg_operation_arg_type_setter_test_1_natural_literal()
{
	amara_string * natural_literal_zero_;
	amara_string * natural_literal_one_;
	rtg_operation_arg * operation_arg_;
	amara_boolean equality_;

	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);

	natural_literal_zero_ = amara_string_exhaustive_constructor("0");
	assertion(natural_literal_zero_ != NULL);
	assertion(natural_literal_zero_->value_ != NULL);

	rtg_operation_arg_set_natural_literal(
			operation_arg_, natural_literal_zero_);
	assertion(operation_arg_->natural_literal_ != NULL);
	assertion(operation_arg_->natural_literal_->value_ != NULL);
	equality_ = amara_string_equality(
			operation_arg_->natural_literal_,
			natural_literal_zero_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(natural_literal_zero_->value_ != NULL);

	rtg_operation_arg_set_type(
			operation_arg_,
			RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL);
	assertion(operation_arg_->type_ ==
			RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL);
	assertion(amara_string_equality(
			operation_arg_->natural_literal_,
			natural_literal_zero_));

	natural_literal_one_ = amara_string_exhaustive_constructor("1");
	assertion(natural_literal_one_ != NULL);
	assertion(natural_literal_one_->value_ != NULL);

	rtg_operation_arg_set_natural_literal(
			operation_arg_, natural_literal_one_);
	assertion(operation_arg_->natural_literal_ != NULL);
	assertion(operation_arg_->natural_literal_->value_ != NULL);
	equality_ = amara_string_equality(
			operation_arg_->natural_literal_,
			natural_literal_one_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(operation_arg_->type_ ==
			RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL);
	assertion(natural_literal_one_->value_ != NULL);

	amara_string_destructor(natural_literal_one_);
	rtg_operation_arg_destructor(operation_arg_);
	amara_string_destructor(natural_literal_zero_);
}

/* FIXME Remove leaks in this test. */
void
rtg_operation_arg_type_setter_test_2_identifier()
{
	rtg_operation_arg * operation_arg_;

	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);

	rtg_operation_arg_set_identifier(
			operation_arg_,
			amara_string_exhaustive_constructor("foo"));
	assertion(amara_string_equality(
			operation_arg_->identifier_,
			amara_string_exhaustive_constructor("foo")));
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);

	rtg_operation_arg_set_identifier(
			operation_arg_,
			amara_string_exhaustive_constructor("bar"));
	assertion(amara_string_equality(
			operation_arg_->identifier_,
			amara_string_exhaustive_constructor("bar")));
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);

	rtg_operation_arg_set_type(
			operation_arg_,
			RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED);
	assertion(operation_arg_->type_ ==
			RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED);
	assertion(amara_string_equality(
			operation_arg_->identifier_,
			amara_string_exhaustive_constructor("bar")));

	rtg_operation_arg_destructor(operation_arg_);
}

void
rtg_operation_arg_type_setter_test_3_set_invalid_when_being_invalid()
{
	rtg_operation_arg * operation_arg_;

	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);

	rtg_operation_arg_set_type(
			operation_arg_, RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(operation_arg_->string_literal_ == NULL);
	assertion(operation_arg_->natural_literal_ == NULL);
	assertion(operation_arg_->identifier_ == NULL);
	assertion(operation_arg_->operation_ == NULL);

	rtg_operation_arg_destructor(operation_arg_);
}

void
rtg_operation_arg_type_setter_tests()
{
	rtg_operation_arg_type_setter_test_0_string_literal();
	rtg_operation_arg_type_setter_test_1_natural_literal();
	rtg_operation_arg_type_setter_test_2_identifier();
	rtg_operation_arg_type_setter_test_3_set_invalid_when_being_invalid();
}

void
rtg_operation_arg_setters_tests()
{
	rtg_operation_arg_type_setter_tests();
}

void
rtg_operation_arg_tests()
{
	rtg_operation_arg_construct_and_destruct_tests();
	rtg_operation_arg_setters_tests();
}
