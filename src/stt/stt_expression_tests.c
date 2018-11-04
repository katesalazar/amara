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
 * src/stt/stt_expression_tests.c: Test the Amara syntax tree expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `natural * natural_example_zero()`. */
#include "../brt/natural_tests.h"

/*   For `stt_expression_sub_conditional_example_simple_conditional`. */
#include "stt_expression_sub_conditional_tests.h"

/*   For own prototypes definitions. */
#include "stt_expression_tests.h"

stt_expression *
stt_expression_example_natural_zero()
{
	natural * natural_;
	stt_expression * returning_;

	natural_ = natural_example_zero();
#ifndef NDEBUG
	assert_expectations_on_natural_example_zero(natural_);
#endif

	returning_ = stt_expression_default_constructor();
	assertion(returning_ != NULL);
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_INVALID);

	stt_expression_set_natural_literal(returning_, natural_);
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_natural_zero(returning_);
	assert_expectations_on_natural_example_zero(
			returning_->sub_natural_literal_->natural_literal_);
#endif

	return returning_;
}

#ifndef NDEBUG
void
assert_expectations_on_stt_expression_example_natural_zero(
		const stt_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(expression->sub_natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_[0] ==
			0x30);  /* 48: '0'. */
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_[1] ==
			0);  /* '\0'. */
}
#endif

stt_expression *
stt_expression_example_natural_one()
{
	natural * natural_;
	stt_expression * returning_;

	natural_ = natural_example_one();
#ifndef NDEBUG
	assert_expectations_on_natural_example_one(natural_);
#endif

	returning_ = stt_expression_default_constructor();
#ifndef NDEBUG
	assertion(returning_ != NULL);
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_natural_literal(returning_, natural_);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assert_expectations_on_stt_expression_example_natural_one(returning_);
	assert_expectations_on_natural_example_one(
			returning_->sub_natural_literal_->natural_literal_);
#endif

	return returning_;
}

#ifndef NDEBUG
void
assert_expectations_on_stt_expression_example_natural_one(
		const stt_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(expression->sub_natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_[0] ==
			0x31);  /* 49: '1'. */
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_[1] ==
			0);  /* '\0'. */
}
#endif

stt_expression *
stt_expression_example_string_literal_foo()
{
	amara_string * string_literal_;
	stt_expression * returning_;

	string_literal_ = amara_string_exhaustive_constructor("foo");
#ifndef NDEBUG
	assertion(string_literal_ != NULL);
	assertion(string_literal_->value_ != NULL);
#endif

	returning_ = stt_expression_default_constructor();
#ifndef NDEBUG
	assertion(returning_ != NULL);
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_string_literal(returning_, string_literal_);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL);
	assertion(returning_->sub_string_literal_ != NULL);
	assertion(returning_->sub_string_literal_->string_literal_ != NULL);
	assertion(returning_->sub_string_literal_->string_literal_->value_ !=
			NULL);
	assertion(string_literal_->value_ != NULL);
#endif

	return returning_;
}

#ifndef NDEBUG
void
assert_expectations_on_stt_expression_example_string_literal_foo(
		const stt_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL);
	assertion(expression->sub_string_literal_ != NULL);
	assertion(expression->sub_string_literal_->string_literal_ != NULL);
	assertion(expression->sub_string_literal_->string_literal_->value_ !=
			NULL);
	assertion(expression->sub_string_literal_->string_literal_->value_[0] ==
			0x66);  /* 100: 'f'. */
	assertion(expression->sub_string_literal_->string_literal_->value_[1] ==
			0x6F);  /* 111: 'o'. */
	assertion(expression->sub_string_literal_->string_literal_->value_[2] ==
			0x6F);  /* 111: 'o'. */
	assertion(expression->sub_string_literal_->string_literal_->value_[3] ==
			0);  /* '\0'. */
}
#endif

/**  `'bar'`. */
stt_expression *
stt_expression_example_string_literal_bar()
{
	amara_string * string_literal_;
	stt_expression * returning_;

	string_literal_ = amara_string_exhaustive_constructor("bar");
#ifndef NDEBUG
	assertion(string_literal_ != NULL);
	assertion(string_literal_->value_ != NULL);
#endif

	returning_ = stt_expression_default_constructor();
#ifndef NDEBUG
	assertion(returning_ != NULL);
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_string_literal(returning_, string_literal_);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL);
	assertion(returning_->sub_string_literal_ != NULL);
	assertion(returning_->sub_string_literal_->string_literal_ != NULL);
	assertion(returning_->sub_string_literal_->string_literal_->value_ !=
			NULL);
	assertion(string_literal_->value_ != NULL);
#endif

	return returning_;
}

#ifndef NDEBUG
void
assert_expectations_on_stt_expression_example_string_literal_bar(
		const stt_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL);
	assertion(expression->sub_string_literal_ != NULL);
	assertion(expression->sub_string_literal_->string_literal_ != NULL);
	assertion(expression->sub_string_literal_->string_literal_->value_ !=
			NULL);
	assertion(expression->sub_string_literal_->string_literal_->value_[0] ==
			0x62);  /* 98: 'b'. */
	assertion(expression->sub_string_literal_->string_literal_->value_[1] ==
			0x61);  /* 97: 'a'. */
	assertion(expression->sub_string_literal_->string_literal_->value_[2] ==
			0x72);  /* 114: 'r'. */
	assertion(expression->sub_string_literal_->string_literal_->value_[3] ==
			0);  /* '\0'. */
}
#endif

stt_expression *
stt_expression_example_simple_conditional()
{
	stt_expression_sub_conditional * expression_sub_conditional_;
	stt_expression * returning_;

	expression_sub_conditional_ =
			stt_expression_sub_conditional_example_simple_conditional();
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			expression_sub_conditional_);
#endif

	returning_ = stt_expression_default_constructor();
#ifndef NDEBUG
	assertion(returning_ != NULL);
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_conditional(
			returning_, expression_sub_conditional_);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_CONDITIONAL);
	assertion(returning_->sub_conditional_ != NULL);
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			returning_->sub_conditional_);
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			expression_sub_conditional_);
#endif

	return returning_;
}

#ifndef NDEBUG
void
assert_expectations_on_stt_expression_example_simple_conditional(
		const stt_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == STT_EXPRESSION_TYPE_CONDITIONAL);
	assertion(expression->sub_conditional_ != NULL);
	assertion(expression->sub_conditional_->if_ != NULL);
	assertion(expression->sub_conditional_->if_->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);
	assertion(expression->sub_conditional_->if_->condition_ != NULL);
	/*
	assert_expectations_on_stt_condition_example_less_than
	*/
	assertion(expression->sub_conditional_->if_->condition_->type_ ==
			STT_CONDITION_TYPE_LESS_THAN);
	assertion(expression->sub_conditional_->if_->expression_then_ != NULL);
}
#endif

void
stt_expression_default_constructor_test_10_default()
{
	stt_expression * expression_;

	expression_ = stt_expression_default_constructor();
#ifndef NDEBUG
	assertion(expression_ != NULL);
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_INVALID);
	assertion(expression_->sub_natural_literal_ == NULL);
	assertion(expression_->sub_conditional_ == NULL);
	assertion(expression_->sub_dice_ == NULL);
#endif

	free(expression_);
	/*
	stt_expression_destructor(expression_);
	*/
}

void
stt_expression_copy_constructor_test_20_identifier()
{
	amara_string * identifier_;
	stt_expression * original_expression_;
	stt_expression * expression_copy_;

	identifier_ = amara_string_exhaustive_constructor("foo");
#ifndef NDEBUG
	assertion(identifier_ != NULL);
	assertion(identifier_->value_ != NULL);
	assertion(identifier_->value_[0] == 0x66);  /* 102: 'f'. */
	assertion(identifier_->value_[1] == 0x6F);  /* 111: 'o'. */
	assertion(identifier_->value_[2] == 0x6F);  /* 111: 'o'. */
	assertion(identifier_->value_[3] == 0x00);  /* 0: '\0'. */
#endif

	original_expression_ = stt_expression_default_constructor();
#ifndef NDEBUG
	assertion(original_expression_ != NULL);
	assertion(original_expression_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_identifier(original_expression_, identifier_);
#ifndef NDEBUG
	assertion(original_expression_ != NULL);
	assertion(original_expression_->type_ ==
			STT_EXPRESSION_TYPE_IDENTIFIER);
	assertion(original_expression_->sub_identifier_ != NULL);
	assertion(original_expression_->sub_identifier_->identifier_ != NULL);
	assertion(original_expression_->sub_identifier_->identifier_->value_ !=
			NULL);
	assertion(original_expression_->sub_identifier_->identifier_->value_[0] ==
			0x66);  /* 102: 'f'. */
	assertion(original_expression_->sub_identifier_->identifier_->value_[1] ==
			0x6F);  /* 111: 'o'. */
	assertion(original_expression_->sub_identifier_->identifier_->value_[2] ==
			0x6F);  /* 111: 'o'. */
	assertion(original_expression_->sub_identifier_->identifier_->value_[3] ==
			0x00);  /* 0: '\0'. */
	assertion(identifier_->value_ != NULL);
	assertion(identifier_->value_[0] == 0x66);  /* 102: 'f'. */
	assertion(identifier_->value_[1] == 0x6F);  /* 111: 'o'. */
	assertion(identifier_->value_[2] == 0x6F);  /* 111: 'o'. */
	assertion(identifier_->value_[3] == 0x00);  /* 0: '\0'. */
#endif

	expression_copy_ =
			stt_expression_copy_constructor(original_expression_);
#ifndef NDEBUG
	assertion(original_expression_->type_ == STT_EXPRESSION_TYPE_IDENTIFIER);
	assertion(original_expression_->sub_identifier_ != NULL);
	assertion(original_expression_->sub_identifier_->identifier_ != NULL);
	assertion(original_expression_->sub_identifier_->identifier_->value_ !=
			NULL);
	assertion(original_expression_->sub_identifier_->identifier_->value_[0] ==
			0x66);  /* 102: 'f'. */
	assertion(original_expression_->sub_identifier_->identifier_->value_[1] ==
			0x6F);  /* 111: 'o'. */
	assertion(original_expression_->sub_identifier_->identifier_->value_[2] ==
			0x6F);  /* 111: 'o'. */
	assertion(original_expression_->sub_identifier_->identifier_->value_[3] ==
			0x00);  /* 0: '\0'. */
	assertion(expression_copy_ != NULL);
	assertion(expression_copy_->type_ == STT_EXPRESSION_TYPE_IDENTIFIER);
	assertion(expression_copy_->sub_identifier_ != NULL);
	assertion(expression_copy_->sub_identifier_->identifier_ != NULL);
	assertion(expression_copy_->sub_identifier_->identifier_->value_ !=
			NULL);
	assertion(expression_copy_->sub_identifier_->identifier_->value_[0] ==
			0x66);  /* 102: 'f'. */
	assertion(expression_copy_->sub_identifier_->identifier_->value_[1] ==
			0x6F);  /* 111: 'o'. */
	assertion(expression_copy_->sub_identifier_->identifier_->value_[2] ==
			0x6F);  /* 111: 'o'. */
	assertion(expression_copy_->sub_identifier_->identifier_->value_[3] ==
			0x00);  /* 0: '\0'. */
#endif

	stt_expression_destructor(expression_copy_);
	stt_expression_destructor(original_expression_);
	amara_string_destructor(identifier_);
}

void
stt_expression_default_constructor_tests()
{
	stt_expression_default_constructor_test_10_default();
	stt_expression_copy_constructor_test_20_identifier();
}

void
stt_expression_copy_constructor_test_30_conditional()
{
	stt_expression_sub_conditional * sub_conditional_;
	stt_expression * original_expression_;
	stt_expression * expression_copy_;

	sub_conditional_ = stt_expression_sub_conditional_example_simple_conditional();
#ifndef NDEBUG
	assertion(sub_conditional_ != NULL);
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			sub_conditional_);
#endif

	original_expression_ = stt_expression_default_constructor();
#ifndef NDEBUG
	assertion(original_expression_ != NULL);
	assertion(original_expression_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_conditional(original_expression_, sub_conditional_);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			sub_conditional_);
	assertion(original_expression_->sub_conditional_ != NULL);
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			original_expression_->sub_conditional_);
#endif

	expression_copy_ =
			stt_expression_copy_constructor(original_expression_);
#ifndef NDEBUG
	assertion(original_expression_->sub_conditional_ != NULL);
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			original_expression_->sub_conditional_);
	assertion(expression_copy_ != NULL);
	assertion(expression_copy_->sub_conditional_ != NULL);
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			expression_copy_->sub_conditional_);
#endif

	stt_expression_destructor(expression_copy_);
	stt_expression_destructor(original_expression_);
	stt_expression_sub_conditional_destructor(sub_conditional_);
}

void
stt_expression_copy_constructor_tests()
{
	/*
	stt_expression_copy_constructor_test_0();
	*/
	stt_expression_copy_constructor_test_30_conditional();
}

void
stt_expression_constructors_and_destructors_tests()
{
	stt_expression_default_constructor_tests();
	stt_expression_copy_constructor_tests();
}

void
stt_expression_tests()
{
	stt_expression_constructors_and_destructors_tests();
}
