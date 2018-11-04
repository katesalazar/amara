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
 * src/stt/stt_expression_sub_conditional_tests.c: Test the Amara syntax
 * tree conditional type of expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_condition_example_simple_condition`. */
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

	condition_ = stt_condition_example_simple_condition();
#ifndef NDEBUG
	assertion(condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_condition(
			condition_);
#endif

	stt_expression_sub_conditional_if_set_condition(
			returning_, condition_);
#ifndef NDEBUG
	assertion(returning_->type_ ==
			STT_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_INVALID);
	assertion(returning_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_condition(
			returning_->condition_);
	assertion(returning_->expression_then_ == NULL);
	assertion(returning_->expression_else_ == NULL);
	assertion(returning_->next_if_ == NULL);
	assert_expectations_on_stt_condition_example_simple_condition(
			condition_);
#endif

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
	assert_expectations_on_stt_condition_example_simple_condition(
			returning_->condition_);
	assertion(returning_->expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			returning_->expression_then_);
	assertion(returning_->expression_else_ == NULL);
	assertion(returning_->next_if_ == NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			expression_then_);
#endif

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
	assert_expectations_on_stt_condition_example_simple_condition(
			returning_->condition_);
	assertion(returning_->expression_then_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			returning_->expression_then_);
	assertion(returning_->expression_else_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_bar(
			returning_->expression_else_);
	assertion(returning_->next_if_ == NULL);
	assert_expectations_on_stt_expression_example_string_literal_bar(
			expression_else_);
#endif

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

stt_expression_sub_conditional *
stt_expression_sub_conditional_example_simple_conditional()
{
	stt_expression_sub_conditional_if * inner_;
	stt_expression_sub_conditional * returning_;

	inner_ = stt_expression_sub_conditional_if_example_simple_conditional();
#ifndef NDEBUG
	assertion(inner_ != NULL);
	assert_expectations_on_stt_expression_sub_conditional_if_example_simple_conditional(
			inner_);
#endif

	returning_ = stt_expression_sub_conditional_default_constructor();
	assertion(returning_ != NULL);
	assertion(returning_->if_ == NULL);

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

void
stt_expression_sub_conditional_default_constructor_test()
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

void
stt_expression_sub_conditional_test_0()
{
	stt_expression_sub_conditional_default_constructor_test();
	stt_expression_sub_conditional_setters_tests();
}

void
stt_expression_sub_conditional_tests()
{
	stt_expression_sub_conditional_test_0();
}
