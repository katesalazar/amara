/*
 * Copyright 2018-2019 Mercedes Catherine Salazar
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

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_operation_arg *
 * stt_operation_arg_example_natural_literal_zero()`. */
#include "../stt/stt_operation_arg_tests.h"

/*   For own prototypes. */
#include "rtg_operation_arg_tests.h"

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

#ifndef NDEBUG

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

#endif

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_arg_example_natural_literal_zero(
		const rtg_operation_arg * operation_arg)
{
	assertion(operation_arg != NULL);
	assertion(operation_arg->type_ ==
			RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL);
	assertion(operation_arg->natural_literal_ != NULL);
	assertion(operation_arg->natural_literal_->value_ != NULL);
	assertion(operation_arg->natural_literal_->value_[0] == '0');
	assertion(operation_arg->natural_literal_->value_[1] == '\0');
}

#endif

rtg_operation_arg *
rtg_operation_arg_example_identifier_foo()
{
	rtg_operation_arg * operation_arg_;
	amara_string * string_for_operation_arg_;
	amara_boolean equality_;

	string_for_operation_arg_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(string_for_operation_arg_ != NULL);
	forced_assertion(string_for_operation_arg_->value_ != NULL);

	operation_arg_ = rtg_operation_arg_default_constructor();
	forced_assertion(operation_arg_ != NULL);
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

#ifndef NDEBUG

void
assert_expectations_on_rtg_operation_arg_example_identifier_foo(
		const rtg_operation_arg * operation_arg)
{
	amara_string * expected_identifier_;
	amara_boolean equality_;

	expected_identifier_ = amara_string_exhaustive_constructor("foo");
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

#endif

rtg_operation_arg *
rtg_operation_arg_example_identifier_bar()
{
	rtg_operation_arg * operation_arg_;
	amara_string * string_for_operation_arg_;
	amara_boolean equality_;

	string_for_operation_arg_ = amara_string_exhaustive_constructor("bar");
	forced_assertion(string_for_operation_arg_ != NULL);
	forced_assertion(string_for_operation_arg_->value_ != NULL);

	operation_arg_ = rtg_operation_arg_default_constructor();
	forced_assertion(operation_arg_ != NULL);
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

#ifndef NDEBUG

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

#endif

void
rtg_operation_arg_default_constructor_test()
{
	rtg_operation_arg * operation_arg_;

	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);

	rtg_operation_arg_destructor(operation_arg_);
}

void
rtg_operation_arg_copy_constructor_test_0()
{
	stt_operation_arg * stt_operation_arg_;
	rtg_operation_arg_out_of_stt_operation_arg_ret * rtg_operation_arg_out_of_stt_operation_arg_ret_;
	rtg_operation_arg * rtg_operation_arg_zero_;
	rtg_operation_arg * rtg_operation_arg_one_;

	stt_operation_arg_ = stt_operation_arg_example_natural_literal_zero();
	forced_assertion(stt_operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_natural_literal_zero(
			stt_operation_arg_);
#endif

	rtg_operation_arg_out_of_stt_operation_arg_ret_ =
			rtg_operation_arg_out_of_stt_operation_arg(
					stt_operation_arg_,
					STT_OPERATION_TYPE_PRINT,
					NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_natural_literal_zero(
			stt_operation_arg_);
#endif
	forced_assertion(rtg_operation_arg_out_of_stt_operation_arg_ret_ !=
			NULL);
	forced_assertion(rtg_operation_arg_out_of_stt_operation_arg_ret_->status ==
			RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_SUCCESS);
	forced_assertion(rtg_operation_arg_out_of_stt_operation_arg_ret_->operation_arg !=
			NULL);
	rtg_operation_arg_zero_ =
			rtg_operation_arg_out_of_stt_operation_arg_ret_->operation_arg;
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_natural_literal_zero(
			rtg_operation_arg_zero_);
#endif

	rtg_operation_arg_one_ = rtg_operation_arg_copy_constructor(
			rtg_operation_arg_zero_);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_natural_literal_zero(
			rtg_operation_arg_zero_);
#endif
	forced_assertion(rtg_operation_arg_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_arg_example_natural_literal_zero(
			rtg_operation_arg_one_);
#endif

	rtg_operation_arg_destructor(rtg_operation_arg_one_);
	rtg_operation_arg_destructor(rtg_operation_arg_zero_);
	stt_operation_arg_destructor(stt_operation_arg_);
}

void
rtg_operation_arg_copy_constructor_tests()
{
	rtg_operation_arg_copy_constructor_test_0();
}

void
rtg_operation_arg_construct_and_destruct_tests()
{
	rtg_operation_arg_default_constructor_test();
	rtg_operation_arg_copy_constructor_tests();
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
rtg_operation_arg_type_setter_test_4_set_invalid_when_being_string_literal()
{
	rtg_operation_arg * operation_arg_;

	operation_arg_ = rtg_operation_arg_default_constructor();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
#endif

	rtg_operation_arg_set_string_literal(operation_arg_, amara_string_exhaustive_constructor("foo"));
	/* TODO missing assertions */
	/* FIXME memory gets leaked */

	rtg_operation_arg_set_type(
			operation_arg_, RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	/* TODO missing assertions */

	rtg_operation_arg_set_type(
			operation_arg_, RTG_OPERATION_ARG_TYPE_INVALID);
#ifndef NDEBUG
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(operation_arg_->string_literal_ == NULL);
	assertion(operation_arg_->natural_literal_ == NULL);
	assertion(operation_arg_->identifier_ == NULL);
	assertion(operation_arg_->operation_ == NULL);
#endif

	rtg_operation_arg_destructor(operation_arg_);
}

void
rtg_operation_arg_type_setter_tests()
{
	rtg_operation_arg_type_setter_test_0_string_literal();
	rtg_operation_arg_type_setter_test_1_natural_literal();
	rtg_operation_arg_type_setter_test_2_identifier();
	rtg_operation_arg_type_setter_test_3_set_invalid_when_being_invalid();
	rtg_operation_arg_type_setter_test_4_set_invalid_when_being_string_literal();
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
