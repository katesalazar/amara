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
 * src/stt/stt_expression_tests.c: Test the Amara syntax tree expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `natural * natural_example_zero()`. */
#include "../brt/natural_tests.h"

/*   For `stt_dice_expression *
 * stt_dice_expression_example_single_vanilla_dice()`. */
#include "stt_dice_expression_tests.h"

/*   For `stt_expression_sub_conditional_example_simple_conditional`. */
#include "stt_expression_sub_conditional_tests.h"

/*   For `stt_expression_sub_dice *
 * stt_expression_sub_dice_example_single_vanilla_dice()`. */
#include "stt_expression_sub_dice_tests.h"

/*   For own prototypes definitions. */
#include "stt_expression_tests.h"

stt_expression *
stt_expression_example_natural_zero()
{
	natural * natural_;
	stt_expression * returning_;

	natural_ = natural_example_zero();
	forced_assertion(natural_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_natural_example_zero(natural_);
#endif

	returning_ = stt_expression_default_constructor();
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_natural_literal(returning_, natural_);
#ifndef NDEBUG
	assert_expectations_on_natural_example_zero(natural_);
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL);
#endif
	forced_assertion(returning_->sub_natural_literal_ != NULL);
	forced_assertion(returning_->sub_natural_literal_->natural_literal_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_natural_example_zero(
			returning_->sub_natural_literal_->natural_literal_);
	assert_expectations_on_stt_expression_example_natural_zero(returning_);
#endif

	natural_destructor(natural_);

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
	forced_assertion(natural_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_natural_example_one(natural_);
#endif

	returning_ = stt_expression_default_constructor();
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_natural_literal(returning_, natural_);
#ifndef NDEBUG
	assert_expectations_on_natural_example_one(natural_);
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL);
#endif
	forced_assertion(returning_->sub_natural_literal_ != NULL);
	forced_assertion(returning_->sub_natural_literal_->natural_literal_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_natural_example_one(
			returning_->sub_natural_literal_->natural_literal_);
	assert_expectations_on_stt_expression_example_natural_one(returning_);
#endif

	natural_destructor(natural_);

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

	amara_string_destructor(string_literal_);

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

	amara_string_destructor(string_literal_);

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
stt_expression_example_identifier_foo()
{
	amara_string * identifier_;
	stt_expression * returning_;

	identifier_ = amara_string_exhaustive_constructor("foo");
#ifndef NDEBUG
	assertion(identifier_ != NULL);
	assertion(identifier_->value_ != NULL);
#endif

	returning_ = stt_expression_default_constructor();
#ifndef NDEBUG
	assertion(returning_ != NULL);
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_identifier(returning_, identifier_);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_IDENTIFIER);
	assertion(returning_->sub_identifier_ != NULL);
	assertion(returning_->sub_identifier_->identifier_ != NULL);
	assertion(returning_->sub_identifier_->identifier_->value_ != NULL);
	assertion(identifier_->value_ != NULL);
#endif

	amara_string_destructor(identifier_);

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_example_identifier_foo(
		const stt_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == STT_EXPRESSION_TYPE_IDENTIFIER);
	assertion(expression->sub_identifier_ != NULL);
	assertion(expression->sub_identifier_->identifier_ != NULL);
	assertion(expression->sub_identifier_->identifier_->value_ != NULL);
	/* 100: 'f'. */
	assertion(expression->sub_identifier_->identifier_->value_[0] == 0x66);
	/* 111: 'o'. */
	assertion(expression->sub_identifier_->identifier_->value_[1] == 0x6F);
	/* 111: 'o'. */
	assertion(expression->sub_identifier_->identifier_->value_[2] == 0x6F);
	/* '\0'. */
	assertion(expression->sub_identifier_->identifier_->value_[3] == 0);
}

#endif

stt_expression *
stt_expression_example_single_vanilla_dice()
{
	stt_dice_expression * dice_expression_;
	stt_expression * returning_;

	dice_expression_ = stt_dice_expression_example_single_vanilla_dice();
	forced_assertion(dice_expression_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_dice_expression_example_single_vanilla_dice(
			dice_expression_);
#endif

	returning_ = stt_expression_default_constructor();
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_dice(returning_, dice_expression_);
#ifndef NDEBUG
	assert_expectations_on_stt_dice_expression_example_single_vanilla_dice(
			dice_expression_);
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_DICE);
#endif
	forced_assertion(returning_->sub_dice_ != NULL);
	forced_assertion(returning_->sub_dice_->left_hand_side_natural_ !=
			NULL);
	forced_assertion(returning_->sub_dice_->left_hand_side_natural_->raw_ !=
			NULL);
	forced_assertion(returning_->sub_dice_->right_hand_side_natural_ !=
			NULL);
	forced_assertion(returning_->sub_dice_->right_hand_side_natural_->raw_ !=
			NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
			returning_->sub_dice_);
#endif

	stt_dice_expression_destructor(dice_expression_);

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_example_single_vanilla_dice(
		const stt_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == STT_EXPRESSION_TYPE_DICE);
	assertion(expression->sub_dice_ != NULL);
	assertion(expression->sub_dice_->left_hand_side_natural_ != NULL);
	assertion(expression->sub_dice_->left_hand_side_natural_->raw_ !=
			NULL);
	assertion(expression->sub_dice_->left_hand_side_natural_->raw_->value_ !=
			NULL);
	assertion(expression->sub_dice_->left_hand_side_natural_->raw_->value_[0] ==
			'1');
	assertion(expression->sub_dice_->left_hand_side_natural_->raw_->value_[1] ==
			'\0');
	assertion(expression->sub_dice_->right_hand_side_natural_ != NULL);
	assertion(expression->sub_dice_->right_hand_side_natural_->raw_->value_ !=
			NULL);
	assertion(expression->sub_dice_->right_hand_side_natural_->raw_ !=
			NULL);
	assertion(expression->sub_dice_->right_hand_side_natural_->raw_->value_[0] ==
			'6');
	assertion(expression->sub_dice_->right_hand_side_natural_->raw_->value_[1] ==
			'\0');
	assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
			expression->sub_dice_);
}

#endif

stt_expression *
stt_expression_example_simple_conditional()
{
	stt_expression_sub_conditional * expression_sub_conditional_;
	stt_expression * returning_;

	expression_sub_conditional_ =
			stt_expression_sub_conditional_example_simple_conditional();
	forced_assertion(expression_sub_conditional_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			expression_sub_conditional_);
#endif

	returning_ = stt_expression_default_constructor();
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_conditional(
			returning_, expression_sub_conditional_);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			expression_sub_conditional_);
	assertion(returning_->type_ == STT_EXPRESSION_TYPE_CONDITIONAL);
#endif
	forced_assertion(returning_->sub_conditional_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			returning_->sub_conditional_);
#endif

	stt_expression_sub_conditional_destructor(expression_sub_conditional_);

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
stt_expression_default_constructor_test()
{
	stt_expression * expression_;

	expression_ = stt_expression_default_constructor();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
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
stt_expression_default_constructor_tests()
{
	stt_expression_default_constructor_test();
}

tests_simple_list *
register_stt_expression_default_constructor_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_expression_default_constructor_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(returning_,
	                            & stt_expression_default_constructor_test);
	return returning_;
}

void
stt_expression_copy_constructor_test_20_identifier()
{
	amara_string * identifier_;
	stt_expression * original_expression_;
	stt_expression * expression_copy_;

	identifier_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(identifier_ != NULL);
	forced_assertion(identifier_->value_ != NULL);
#ifndef NDEBUG
	assertion(identifier_->value_[0] == 0x66);  /* 102: 'f'. */
	assertion(identifier_->value_[1] == 0x6F);  /* 111: 'o'. */
	assertion(identifier_->value_[2] == 0x6F);  /* 111: 'o'. */
	assertion(identifier_->value_[3] == 0x00);  /* 0: '\0'. */
#endif

	original_expression_ = stt_expression_default_constructor();
	forced_assertion(original_expression_ != NULL);
#ifndef NDEBUG
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
#endif
	forced_assertion(expression_copy_ != NULL);
#ifndef NDEBUG
	assertion(expression_copy_->type_ == STT_EXPRESSION_TYPE_IDENTIFIER);
#endif
	forced_assertion(expression_copy_->sub_identifier_ != NULL);
	forced_assertion(expression_copy_->sub_identifier_->identifier_ !=
			NULL);
	forced_assertion(expression_copy_->sub_identifier_->identifier_->value_ !=
			NULL);
#ifndef NDEBUG
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
stt_expression_copy_constructor_test_30_conditional()
{
	stt_expression_sub_conditional * sub_conditional_;
	stt_expression * original_expression_;
	stt_expression * expression_copy_;

	sub_conditional_ = stt_expression_sub_conditional_example_simple_conditional();
	forced_assertion(sub_conditional_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			sub_conditional_);
#endif

	original_expression_ = stt_expression_default_constructor();
	forced_assertion(original_expression_ != NULL);
#ifndef NDEBUG
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
#endif
	forced_assertion(expression_copy_ != NULL);
	forced_assertion(expression_copy_->sub_conditional_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			expression_copy_->sub_conditional_);
#endif

	stt_expression_destructor(expression_copy_);
	stt_expression_destructor(original_expression_);
	stt_expression_sub_conditional_destructor(sub_conditional_);
}

void
stt_expression_copy_constructor_test_40_dice()
{
	/*
	stt_expression_sub_dice * sub_dice_;
	*/
	stt_dice_expression * dice_expression_;
	stt_expression * original_expression_;
	stt_expression * expression_copy_;

	/*
	sub_dice_ = stt_expression_sub_dice_example_single_vanilla_dice();
	forced_assertion(sub_dice_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
			sub_dice_);
#endif
	*/

	dice_expression_ = stt_dice_expression_example_single_vanilla_dice();
	forced_assertion(dice_expression_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_dice_expression_example_single_vanilla_dice(
			dice_expression_);
#endif

	original_expression_ = stt_expression_default_constructor();
	forced_assertion(original_expression_ != NULL);
#ifndef NDEBUG
	assertion(original_expression_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_dice(original_expression_, dice_expression_);
#ifndef NDEBUG
	assert_expectations_on_stt_dice_expression_example_single_vanilla_dice(
			dice_expression_);
#endif
	forced_assertion(original_expression_->sub_dice_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
			original_expression_->sub_dice_);
#endif

	expression_copy_ =
			stt_expression_copy_constructor(original_expression_);
#ifndef NDEBUG
	assertion(original_expression_->sub_dice_ != NULL);
	assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
			original_expression_->sub_dice_);
#endif
	forced_assertion(expression_copy_ != NULL);
	forced_assertion(expression_copy_->sub_dice_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
			expression_copy_->sub_dice_);
#endif

	stt_expression_destructor(expression_copy_);
	stt_expression_destructor(original_expression_);
	/*
	stt_expression_sub_dice_destructor(sub_dice_);
	*/
	stt_dice_expression_destructor(dice_expression_);
}

void
stt_expression_copy_constructor_tests()
{
	stt_expression_copy_constructor_test_20_identifier();
	stt_expression_copy_constructor_test_30_conditional();
	stt_expression_copy_constructor_test_40_dice();
}

tests_simple_list *
register_stt_expression_copy_constructor_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_expression_copy_constructor_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_expression_copy_constructor_test_20_identifier);
	tests_simple_list_push_back(
			returning_,
			& stt_expression_copy_constructor_test_30_conditional);
	tests_simple_list_push_back(
			returning_,
			& stt_expression_copy_constructor_test_40_dice);
	return returning_;
}

void
stt_expression_constructors_and_destructors_tests()
{
	stt_expression_default_constructor_tests();
	stt_expression_copy_constructor_tests();
}

tests_simple_list *
register_stt_expression_constructors_and_destructors_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_expression_constructors_and_destructors_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_expression_default_constructor_tests(tests);
	returning_ = register_stt_expression_copy_constructor_tests(
			returning_);
	return returning_;
}

void
stt_expression_equality_test_0()
{
	stt_expression * e0_;
	stt_expression * e1_;
	amara_boolean equality_;

	e0_ = stt_expression_example_string_literal_foo();
	forced_assertion(e0_ != NULL);

	e1_ = stt_expression_example_natural_zero();
	forced_assertion(e1_ != NULL);

	equality_ = stt_expression_equality(e0_, e1_);
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);

	stt_expression_destructor(e0_);
	stt_expression_destructor(e1_);
}

void
stt_expression_equality_test_1()
{
	stt_expression * e0_;
	stt_expression * e1_;
	amara_boolean equality_;

	e0_ = stt_expression_example_string_literal_foo();
	forced_assertion(e0_ != NULL);

	e1_ = stt_expression_example_string_literal_bar();
	forced_assertion(e1_ != NULL);

	equality_ = stt_expression_equality(e0_, e1_);
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);

	stt_expression_destructor(e0_);
	stt_expression_destructor(e1_);
}

void
stt_expression_equality_tests()
{
	stt_expression_equality_test_0();
	stt_expression_equality_test_1();
}

tests_simple_list *
register_stt_expression_equality_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_expression_equality_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_expression_equality_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_expression_equality_test_1);
	return returning_;
}

#ifndef NDEBUG

void
stt_expression_cleanliness_test_10_string_literal()
{
	stt_expression * expression_;

	expression_ = stt_expression_example_string_literal_foo();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_string_literal_foo(
			expression_);
#endif

	stt_expression_assert_cleanliness(expression_);

	stt_expression_destructor(expression_);
}

void
stt_expression_cleanliness_test_20_identifier()
{
	stt_expression * expression_;

	expression_ = stt_expression_example_identifier_foo();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_identifier_foo(
			expression_);
#endif

	stt_expression_assert_cleanliness(expression_);

	stt_expression_destructor(expression_);
}

void
stt_expression_cleanliness_test_25_conditional()
{
	stt_expression * expression_;

	expression_ = stt_expression_example_simple_conditional();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_simple_conditional(
			expression_);
#endif

	stt_expression_assert_cleanliness(expression_);

	stt_expression_destructor(expression_);
}

void
stt_expression_cleanliness_test_30_dice()
{
	stt_expression * expression_;

	expression_ = stt_expression_example_single_vanilla_dice();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_single_vanilla_dice(
			expression_);
#endif

	stt_expression_assert_cleanliness(expression_);

	stt_expression_destructor(expression_);
}

void
stt_expression_cleanliness_tests()
{
	stt_expression_cleanliness_test_10_string_literal();
	stt_expression_cleanliness_test_20_identifier();
	stt_expression_cleanliness_test_25_conditional();
	stt_expression_cleanliness_test_30_dice();
}

tests_simple_list *
register_stt_expression_cleanliness_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_expression_cleanliness_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_expression_cleanliness_test_10_string_literal);
	tests_simple_list_push_back(
			returning_,
			& stt_expression_cleanliness_test_20_identifier);
	tests_simple_list_push_back(
			returning_,
			& stt_expression_cleanliness_test_25_conditional);
	tests_simple_list_push_back(returning_,
	                            & stt_expression_cleanliness_test_30_dice);
	return returning_;
}

#endif

void
stt_expression_tests()
{
	stt_expression_constructors_and_destructors_tests();
	stt_expression_equality_tests();
#ifndef NDEBUG
	stt_expression_cleanliness_tests();
#endif
}

tests_simple_list *
register_stt_expression_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_expression_constructors_and_destructors_tests(
			tests);
	returning_ = register_stt_expression_equality_tests(returning_);
#ifndef NDEBUG
	returning_ = register_stt_expression_cleanliness_tests(returning_);
#endif
	return returning_;
}
