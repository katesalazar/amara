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
 * src/stt/stt_expression_sub_conditional_tests.c: Test the Amara syntax
 * tree conditional type of expression.
 */

/*   For `__amara__warn_unused_result__`. */
#include "../definitions.h"

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_condition_example_simple_condition`,
 * `stt_condition_example_simple_true_condition`,
 * `stt_condition_example_simple_false_condition`, etc. */
#include "stt_condition_tests.h"

/*   For `stt_expression_sub_conditional_if`. */
/* #include "stt_expression_sub_conditional.h" */

/*   For `stt_expression_example_string_literal_foo`. */
#include "stt_expression_tests.h"

/*   For owned functions prototypes. */
#include "stt_expression_sub_conditional_tests.h"

/*   Friend declaration of a private function. */
stt_expression_sub_conditional_if *
stt_expression_sub_conditional_if_default_constructor(void)
__attribute__((warn_unused_result))
;

/*   Friend declaration of a private function. */
void
stt_expression_sub_conditional_if_set_condition(
		stt_expression_sub_conditional_if * expression_sub_conditional_if,
		const stt_condition * condition)
;

/*   Friend declaration of a private function. */
void
stt_expression_sub_conditional_if_set_expression_then(
		stt_expression_sub_conditional_if * expression_sub_conditional_if,
		const stt_expression * expression_then)
;

/*   Friend declaration of a private function. */
void
stt_expression_sub_conditional_if_set_expression_else(
		stt_expression_sub_conditional_if * expression_sub_conditional_if,
		const stt_expression * expression_else)
;

stt_expression_sub_conditional_if *
stt_expression_sub_conditional_if_example_simple_conditional(void)
__attribute__((warn_unused_result))
;

stt_expression_sub_conditional_if *
stt_expression_sub_conditional_if_example_simple_conditional()
{
	stt_condition * condition_;
	stt_expression * expression_then_;
	stt_expression * expression_else_;
	stt_expression_sub_conditional_if * returning_;

	returning_ = stt_expression_sub_conditional_if_default_constructor();
#ifndef NDEBUG
	assertion(returning_ != NULL);
	assertion(returning_->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
	assertion(returning_->condition_ == NULL);
	assertion(returning_->expression_then_ == NULL);
	assertion(returning_->expression_else_ == NULL);
	assertion(returning_->next_if_ == NULL);
#endif

	condition_ = stt_condition_example_simple_true_condition();
#ifndef NDEBUG
	assertion(condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			condition_);
#endif

	stt_expression_sub_conditional_if_set_condition(
			returning_, condition_);
#ifndef NDEBUG
	assertion(returning_->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
	assertion(returning_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			returning_->condition_);
	assertion(returning_->expression_then_ == NULL);
	assertion(returning_->expression_else_ == NULL);
	assertion(returning_->next_if_ == NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			condition_);
#endif

	stt_condition_destructor(condition_);

	expression_then_ = stt_expression_example_string_literal_foo();
#ifndef NDEBUG
	assertion(expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			expression_then_);
#endif

	stt_expression_sub_conditional_if_set_expression_then(
			returning_, expression_then_);
#ifndef NDEBUG
	assertion(returning_->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
	assertion(returning_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			returning_->condition_);
	assertion(returning_->expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			returning_->expression_then_);
	assertion(returning_->expression_else_ == NULL);
	assertion(returning_->next_if_ == NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			expression_then_);
#endif

	stt_expression_destructor(expression_then_);

	expression_else_ = stt_expression_example_string_literal_bar();
#ifndef NDEBUG
	assertion(expression_else_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_bar(
			expression_else_);
#endif

	stt_expression_sub_conditional_if_set_expression_else(
			returning_, expression_else_);
#ifndef NDEBUG
	assertion(returning_->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);
	assertion(returning_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			returning_->condition_);
	assertion(returning_->expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			returning_->expression_then_);
#endif
	forced_assertion(returning_->expression_else_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_string_literal_bar(
			returning_->expression_else_);
	assertion(returning_->next_if_ == NULL);
	assert_expectations_on_stt_expression_example_string_literal_bar(
			expression_else_);
#endif

	stt_expression_destructor(expression_else_);

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_sub_conditional_if_example_simple_conditional(
		const stt_expression_sub_conditional_if * expression_sub_conditional_if)
;

void
assert_expectations_on_stt_expression_sub_conditional_if_example_simple_conditional(
		const stt_expression_sub_conditional_if * expression_sub_conditional_if)
{
	assertion(expression_sub_conditional_if != NULL);
	assertion(expression_sub_conditional_if->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);
	assertion(expression_sub_conditional_if->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_condition(
			expression_sub_conditional_if->condition_);
	assertion(expression_sub_conditional_if->expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			expression_sub_conditional_if->expression_then_);
	assertion(expression_sub_conditional_if->expression_else_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_bar(
			expression_sub_conditional_if->expression_else_);
	assertion(expression_sub_conditional_if->next_if_ == NULL);
}

#endif

/*

stt_expression_sub_conditional_if *
stt_expression_sub_conditional_if_example_simple_true_conditional(void)
__attribute__((warn_unused_result))
;

stt_expression_sub_conditional_if *
stt_expression_sub_conditional_if_example_simple_true_conditional()
{
	return stt_expression_sub_conditional_if_example_simple_conditional();
}

*/

stt_expression_sub_conditional_if *
stt_expression_sub_conditional_if_example_simple_false_conditional(void)
__amara__warn_unused_result__
;

stt_expression_sub_conditional_if *
stt_expression_sub_conditional_if_example_simple_false_conditional()
{
	stt_condition * condition_;
	stt_expression * expression_then_;
	stt_expression * expression_else_;
	stt_expression_sub_conditional_if * returning_;

	returning_ = stt_expression_sub_conditional_if_default_constructor();
#ifndef NDEBUG
	assertion(returning_ != NULL);
	assertion(returning_->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
	assertion(returning_->condition_ == NULL);
	assertion(returning_->expression_then_ == NULL);
	assertion(returning_->expression_else_ == NULL);
	assertion(returning_->next_if_ == NULL);
#endif

	condition_ = stt_condition_example_simple_false_condition();
#ifndef NDEBUG
	assertion(condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_false_condition(
			condition_);
#endif

	stt_expression_sub_conditional_if_set_condition(
			returning_, condition_);
#ifndef NDEBUG
	assertion(returning_->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
	assertion(returning_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_false_condition(
			returning_->condition_);
	assertion(returning_->expression_then_ == NULL);
	assertion(returning_->expression_else_ == NULL);
	assertion(returning_->next_if_ == NULL);
	assert_expectations_on_stt_condition_example_simple_false_condition(
			condition_);
#endif

	stt_condition_destructor(condition_);

	expression_then_ = stt_expression_example_string_literal_foo();
#ifndef NDEBUG
	assertion(expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			expression_then_);
#endif

	stt_expression_sub_conditional_if_set_expression_then(
			returning_, expression_then_);
#ifndef NDEBUG
	assertion(returning_->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
	assertion(returning_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_false_condition(
			returning_->condition_);
	assertion(returning_->expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			returning_->expression_then_);
	assertion(returning_->expression_else_ == NULL);
	assertion(returning_->next_if_ == NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			expression_then_);
#endif

	stt_expression_destructor(expression_then_);

	expression_else_ = stt_expression_example_string_literal_bar();
#ifndef NDEBUG
	assertion(expression_else_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_bar(
			expression_else_);
#endif

	stt_expression_sub_conditional_if_set_expression_else(
			returning_, expression_else_);
#ifndef NDEBUG
	assertion(returning_->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);
	assertion(returning_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_false_condition(
			returning_->condition_);
	assertion(returning_->expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			returning_->expression_then_);
#endif
	forced_assertion(returning_->expression_else_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_string_literal_bar(
			returning_->expression_else_);
	assertion(returning_->next_if_ == NULL);
	assert_expectations_on_stt_expression_example_string_literal_bar(
			expression_else_);
#endif

	stt_expression_destructor(expression_else_);

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_sub_conditional_if_example_simple_false_conditional(
		const stt_expression_sub_conditional_if * expression_sub_conditional_if)
;

void
assert_expectations_on_stt_expression_sub_conditional_if_example_simple_false_conditional(
		const stt_expression_sub_conditional_if * expression_sub_conditional_if)
{
	assertion(expression_sub_conditional_if != NULL);
	assertion(expression_sub_conditional_if->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);
	assertion(expression_sub_conditional_if->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_false_condition(
			expression_sub_conditional_if->condition_);
	assertion(expression_sub_conditional_if->expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			expression_sub_conditional_if->expression_then_);
	assertion(expression_sub_conditional_if->expression_else_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_bar(
			expression_sub_conditional_if->expression_else_);
	assertion(expression_sub_conditional_if->next_if_ == NULL);
}

#endif

stt_expression_sub_conditional *
stt_expression_sub_conditional_example_simple_conditional()
{
	stt_expression_sub_conditional_if * inner_;
	stt_expression_sub_conditional * returning_;

	inner_ = stt_expression_sub_conditional_if_example_simple_conditional();
	forced_assertion(inner_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_if_example_simple_conditional(
			inner_);
#endif

	returning_ = stt_expression_sub_conditional_default_constructor();
	forced_assertion(returning_ != NULL);
	forced_assertion(returning_->if_ == NULL);

	returning_->if_ = inner_;
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			returning_);
#endif

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
		const stt_expression_sub_conditional * expression_sub_conditional)
{
	assertion(expression_sub_conditional != NULL);
	assertion(expression_sub_conditional->if_ != NULL);
	assert_expectations_on_stt_expression_sub_conditional_if_example_simple_conditional(
			expression_sub_conditional->if_);
}

#endif

stt_expression_sub_conditional *
stt_expression_sub_conditional_example_simple_true_conditional()
{
	return stt_expression_sub_conditional_example_simple_conditional();
}

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_sub_conditional_example_simple_true_conditional(
		const stt_expression_sub_conditional * expression_sub_conditional)
{
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			expression_sub_conditional);
}

#endif

stt_expression_sub_conditional *
stt_expression_sub_conditional_example_simple_false_conditional()
{
	stt_expression_sub_conditional_if * inner_;
	stt_expression_sub_conditional * returning_;

	inner_ = stt_expression_sub_conditional_if_example_simple_false_conditional();
	forced_assertion(inner_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_if_example_simple_false_conditional(
			inner_);
#endif

	returning_ = stt_expression_sub_conditional_default_constructor();
	forced_assertion(returning_ != NULL);
	forced_assertion(returning_->if_ == NULL);

	returning_->if_ = inner_;
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_false_conditional(
			returning_);
#endif

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_expression_sub_conditional_example_simple_false_conditional(
		const stt_expression_sub_conditional * expression_sub_conditional)
{
	assertion(expression_sub_conditional != NULL);
	assertion(expression_sub_conditional->if_ != NULL);
	assert_expectations_on_stt_expression_sub_conditional_if_example_simple_false_conditional(
			expression_sub_conditional->if_);
}

#endif

void
stt_expression_sub_conditional_default_constructor_test_0()
{
	stt_condition * condition_;
	stt_expression * expression_then_;
	stt_expression * expression_else_;
	stt_expression_sub_conditional * expression_sub_conditional_;

	condition_ = stt_condition_example_simple_true_condition();
#ifndef NDEBUG
	assertion(condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			condition_);
#endif

	expression_then_ = stt_expression_example_natural_zero();
#ifndef NDEBUG
	assertion(expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_then_);
#endif

	expression_else_ = stt_expression_example_natural_one();
#ifndef NDEBUG
	assertion(expression_else_ != NULL);
	assert_expectations_on_stt_expression_example_natural_one(
			expression_else_);
#endif

	expression_sub_conditional_ =
			stt_expression_sub_conditional_default_constructor();
#ifndef NDEBUG
	assertion(expression_sub_conditional_ != NULL);
	assertion(expression_sub_conditional_->if_ == NULL);
#endif

	stt_expression_sub_conditional_set_condition(
			expression_sub_conditional_, condition_);
#ifndef NDEBUG
	assertion(expression_sub_conditional_->if_ != NULL);
	assertion(expression_sub_conditional_->if_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			expression_sub_conditional_->if_->condition_);
	assertion(expression_sub_conditional_->if_->expression_then_ == NULL);
	assertion(expression_sub_conditional_->if_->expression_else_ == NULL);
	assertion(expression_sub_conditional_->if_->next_if_ == NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			condition_);
#endif

	stt_expression_sub_conditional_set_expression_then(
			expression_sub_conditional_, expression_then_);
#ifndef NDEBUG
	assertion(expression_sub_conditional_->if_ != NULL);
	assertion(expression_sub_conditional_->if_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			expression_sub_conditional_->if_->condition_);
	assertion(expression_sub_conditional_->if_->expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_sub_conditional_->if_->expression_then_);
	assertion(expression_sub_conditional_->if_->expression_else_ == NULL);
	assertion(expression_sub_conditional_->if_->next_if_ == NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_then_);
#endif

	stt_expression_sub_conditional_set_expression_else(
			expression_sub_conditional_, expression_else_);
#ifndef NDEBUG
	assertion(expression_sub_conditional_->if_ != NULL);
	assertion(expression_sub_conditional_->if_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			expression_sub_conditional_->if_->condition_);
	assertion(expression_sub_conditional_->if_->expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_sub_conditional_->if_->expression_then_);
	assertion(expression_sub_conditional_->if_->expression_else_ != NULL);
	assert_expectations_on_stt_expression_example_natural_one(
			expression_sub_conditional_->if_->expression_else_);
	assertion(expression_sub_conditional_->if_->next_if_ == NULL);
	assert_expectations_on_stt_expression_example_natural_one(
			expression_else_);
#endif

	stt_expression_sub_conditional_destructor(expression_sub_conditional_);

	stt_expression_destructor(expression_else_);

	stt_expression_destructor(expression_then_);

	stt_condition_destructor(condition_);
}

void
stt_expression_sub_conditional_default_constructor_tests()
{
	stt_expression_sub_conditional_default_constructor_test_0();
}

tests_simple_list *
register_stt_expression_sub_conditional_default_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_expression_sub_conditional_default_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_expression_sub_conditional_default_constructor_test_0);
	return returning_;
}

/**  This is a reordering of `void
 * stt_expression_sub_conditional_default_constructor_test()`. */
void
stt_expression_sub_conditional_setters_test_0()
{
	stt_expression * expression_then_;
	stt_condition * condition_;
	stt_expression * expression_else_;
	stt_expression_sub_conditional * expression_sub_conditional_;

	expression_then_ = stt_expression_example_natural_zero();
#ifndef NDEBUG
	assertion(expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_then_);
#endif

	condition_ = stt_condition_example_simple_true_condition();
#ifndef NDEBUG
	assertion(condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			condition_);
#endif

	expression_else_ = stt_expression_example_natural_one();
#ifndef NDEBUG
	assertion(expression_else_ != NULL);
	assert_expectations_on_stt_expression_example_natural_one(
			expression_else_);
#endif

	expression_sub_conditional_ =
			stt_expression_sub_conditional_default_constructor();
#ifndef NDEBUG
	assertion(expression_sub_conditional_ != NULL);
	assertion(expression_sub_conditional_->if_ == NULL);
#endif

	stt_expression_sub_conditional_set_expression_then(
			expression_sub_conditional_, expression_then_);
#ifndef NDEBUG
	assertion(expression_sub_conditional_->if_ != NULL);
	assertion(expression_sub_conditional_->if_->condition_ == NULL);
	assertion(expression_sub_conditional_->if_->expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_sub_conditional_->if_->expression_then_);
	assertion(expression_sub_conditional_->if_->expression_else_ == NULL);
	assertion(expression_sub_conditional_->if_->next_if_ == NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_then_);
#endif

	stt_expression_sub_conditional_set_condition(
			expression_sub_conditional_, condition_);
#ifndef NDEBUG
	assertion(expression_sub_conditional_->if_ != NULL);
	assertion(expression_sub_conditional_->if_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			expression_sub_conditional_->if_->condition_);
	assertion(expression_sub_conditional_->if_->expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_sub_conditional_->if_->expression_then_);
	assertion(expression_sub_conditional_->if_->expression_else_ == NULL);
	assertion(expression_sub_conditional_->if_->next_if_ == NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			condition_);
#endif

	stt_expression_sub_conditional_set_expression_else(
			expression_sub_conditional_, expression_else_);
#ifndef NDEBUG
	assertion(expression_sub_conditional_->if_ != NULL);
	assertion(expression_sub_conditional_->if_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_true_condition(
			expression_sub_conditional_->if_->condition_);
	assertion(expression_sub_conditional_->if_->expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_sub_conditional_->if_->expression_then_);
	assertion(expression_sub_conditional_->if_->expression_else_ != NULL);
	assert_expectations_on_stt_expression_example_natural_one(
			expression_sub_conditional_->if_->expression_else_);
	assertion(expression_sub_conditional_->if_->next_if_ == NULL);
	assert_expectations_on_stt_expression_example_natural_one(
			expression_else_);
#endif

	stt_expression_sub_conditional_destructor(expression_sub_conditional_);

	stt_expression_destructor(expression_else_);

	stt_condition_destructor(condition_);

	stt_expression_destructor(expression_then_);
}

void
stt_expression_sub_conditional_setters_tests()
{
	stt_expression_sub_conditional_setters_test_0();
}

tests_simple_list *
register_stt_expression_sub_conditional_setters_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_expression_sub_conditional_setters_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_expression_sub_conditional_setters_test_0);
	return returning_;
}

/**  If the conditions are different, then the whole E.S.C. 's are
 * different. */
void
stt_expression_sub_conditional_equality_test_0()
{
	stt_expression_sub_conditional * simple_true_conditional_;
	stt_expression_sub_conditional * simple_false_conditional_;
	amara_boolean equality_;

	simple_true_conditional_ =
			stt_expression_sub_conditional_example_simple_true_conditional();
	forced_assertion(simple_true_conditional_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_true_conditional(
			simple_true_conditional_);
#endif

	simple_false_conditional_ =
			stt_expression_sub_conditional_example_simple_false_conditional();
	forced_assertion(simple_false_conditional_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_false_conditional(
			simple_false_conditional_);
#endif

	equality_ = stt_expression_sub_conditionals_equality(
			simple_true_conditional_, simple_false_conditional_);
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_true_conditional(
			simple_true_conditional_);
	assert_expectations_on_stt_expression_sub_conditional_example_simple_false_conditional(
			simple_false_conditional_);
#endif

	stt_expression_sub_conditional_destructor(simple_true_conditional_);
	stt_expression_sub_conditional_destructor(simple_false_conditional_);
}

/**  If the conditions are equal, but the expression then 's are
 * different, then the whole E.S.C. 's are different. */
void
stt_expression_sub_conditional_equality_test_1()
{
	stt_expression_sub_conditional * simple_true_conditional_;
	stt_expression_sub_conditional * different_simple_true_conditional_;
	amara_string * fooo_;
	stt_expression * different_expression_then_;
	amara_boolean equality_;

	simple_true_conditional_ =
			stt_expression_sub_conditional_example_simple_true_conditional();
	forced_assertion(simple_true_conditional_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_true_conditional(
			simple_true_conditional_);
#endif

	different_simple_true_conditional_ =
			stt_expression_sub_conditional_example_simple_true_conditional();
	forced_assertion(different_simple_true_conditional_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_true_conditional(
			different_simple_true_conditional_);
#endif

	fooo_ = amara_string_exhaustive_constructor("fooo");
	forced_assertion(fooo_ != NULL);

	different_expression_then_ = stt_expression_default_constructor();
	forced_assertion(different_expression_then_ != NULL);

	stt_expression_set_string_literal(different_expression_then_, fooo_);
	forced_assertion(different_expression_then_->sub_string_literal_ !=
			NULL);
#ifndef NDEBUG
	assertion(different_expression_then_->type_ ==
			STT_EXPRESSION_TYPE_STRING_LITERAL);
#endif

	amara_string_destructor(fooo_);

#ifndef NDEBUG
	assertion(different_simple_true_conditional_ != NULL);
	assertion(different_simple_true_conditional_->if_ != NULL);
	assertion(different_simple_true_conditional_->if_->expression_then_ !=
			NULL);
#endif
	stt_expression_destructor(
			different_simple_true_conditional_->if_->expression_then_);
	different_simple_true_conditional_->if_->expression_then_ =
			different_expression_then_;

	equality_ = stt_expression_sub_conditionals_equality(
			simple_true_conditional_,
			different_simple_true_conditional_);
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_true_conditional(
			simple_true_conditional_);
	/* XXX missing assertions here */
#endif

	stt_expression_sub_conditional_destructor(simple_true_conditional_);
	stt_expression_sub_conditional_destructor(different_simple_true_conditional_);
}

/**  If the conditions are equal, and the expression then 's are equal,
 * then the whole E.S.C. 's will be equal if the expression else 's are
 * equal (whenever the E.S.C. is not of type `if-[elseif]+-else`. */
void
stt_expression_sub_conditional_equality_test_2()
{
	stt_expression_sub_conditional * simple_true_conditional_;
	stt_expression_sub_conditional * another_simple_true_conditional_;
	amara_boolean equality_;

	simple_true_conditional_ =
			stt_expression_sub_conditional_example_simple_true_conditional();
	forced_assertion(simple_true_conditional_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_true_conditional(
			simple_true_conditional_);
#endif

	another_simple_true_conditional_ =
			stt_expression_sub_conditional_example_simple_true_conditional();
	forced_assertion(another_simple_true_conditional_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_true_conditional(
			another_simple_true_conditional_);
#endif

	equality_ = stt_expression_sub_conditionals_equality(
			simple_true_conditional_,
			another_simple_true_conditional_);
	forced_assertion(equality_ == AMARA_BOOLEAN_TRUE);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_true_conditional(
			simple_true_conditional_);
	assert_expectations_on_stt_expression_sub_conditional_example_simple_true_conditional(
			another_simple_true_conditional_);
	/* XXX missing assertions here? */
#endif

	stt_expression_sub_conditional_destructor(simple_true_conditional_);
	stt_expression_sub_conditional_destructor(
			another_simple_true_conditional_);
}

void
stt_expression_sub_conditional_equality_tests()
{
	stt_expression_sub_conditional_equality_test_0();
	stt_expression_sub_conditional_equality_test_1();
	stt_expression_sub_conditional_equality_test_2();
}

tests_simple_list *
register_stt_expression_sub_conditional_equality_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_expression_sub_conditional_equality_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_expression_sub_conditional_equality_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_expression_sub_conditional_equality_test_1);
	return returning_;
}

void
stt_expression_sub_conditional_tests()
{
	stt_expression_sub_conditional_default_constructor_tests();
	stt_expression_sub_conditional_setters_tests();
	stt_expression_sub_conditional_equality_tests();
}

tests_simple_list *
register_stt_expression_sub_conditional_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_expression_sub_conditional_default_constructor_tests(
			tests);
	returning_ = register_stt_expression_sub_conditional_setters_tests(
			returning_);
	returning_ = register_stt_expression_sub_conditional_equality_tests(
			returning_);
	return returning_;
}
