/*
 * Copyright 2019 Mercedes Catherine Salazar
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
 * src/rtg/rtg_expression_sub_conditional_tests.c: Amara run time graph
 * conditional type of expression tests.
 */

/*   For `stt_expression_sub_conditional *
 * stt_expression_sub_conditional_example_simple_conditional()`. */
#include "../stt/stt_expression_sub_conditional_tests.h"

/*   For `void
 * assert_expectations_on_rtg_condition_example_simple_condition(
 * const rtg_condition * condition);`. */
#include "rtg_condition_tests.h"

/*   For `void
 * assert_expectations_on_rtg_expression_example_string_literal_foo(
 * const rtg_expression * expression);`. */
#include "rtg_expression_tests.h"

/*   For own prototypes. */
#include "rtg_expression_sub_conditional_tests.h"

rtg_expression_sub_conditional *
rtg_expression_sub_conditional_example_simple_conditional()
{
	stt_expression_sub_conditional * stt_expression_sub_conditional_;
	rtg_expression_sub_conditional * returning_;

	stt_expression_sub_conditional_ =
			stt_expression_sub_conditional_example_simple_conditional();
	forced_assertion(stt_expression_sub_conditional_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_conditional_example_simple_conditional(
			stt_expression_sub_conditional_);
#endif

	returning_ = rtg_expression_sub_conditional_out_of_stt_expression_sub_conditional(
			stt_expression_sub_conditional_);
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_sub_conditional_example_simple_conditional(
			returning_);
#endif

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_sub_conditional_example_simple_conditional(
		const rtg_expression_sub_conditional * sub)
{
	/*   `IF 0 LESS THAN 1 THEN FOO ELSE BAR`. */
	assertion(sub != NULL);
	assertion(sub->if_ != NULL);
	assertion(sub->if_->type_ ==
			RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);
	assertion(sub->if_->condition_ != NULL);
	assert_expectations_on_rtg_condition_example_simple_condition(
			sub->if_->condition_);
	assertion(sub->if_->expression_then_ != NULL);
	assert_expectations_on_rtg_expression_example_string_literal_foo(
			sub->if_->expression_then_);
	assertion(sub->if_->next_if_ == NULL);
	assertion(sub->if_->expression_else_ != NULL);
	assert_expectations_on_rtg_expression_example_string_literal_bar(
			sub->if_->expression_else_);
}

#endif

void
rtg_expression_sub_conditional_copy_constructor_test_0()
{
	rtg_expression_sub_conditional * sub_zero_;
	rtg_expression_sub_conditional * sub_one_;

	sub_zero_ = rtg_expression_sub_conditional_example_simple_conditional();
	forced_assertion(sub_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_sub_conditional_example_simple_conditional(
			sub_zero_);
#endif

	sub_one_ = rtg_expression_sub_conditional_copy_constructor(sub_zero_);
	forced_assertion(sub_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_sub_conditional_example_simple_conditional(
			sub_one_);
#endif

	rtg_expression_sub_conditional_destructor(sub_one_);
	rtg_expression_sub_conditional_destructor(sub_zero_);
}

void
rtg_expression_sub_conditional_copy_constructor_tests()
{
	rtg_expression_sub_conditional_copy_constructor_test_0();
}

void
rtg_expression_sub_conditional_constructors_tests()
{
	rtg_expression_sub_conditional_copy_constructor_tests();
}

#ifndef NDEBUG

void
rtg_expression_sub_conditional_validity_test_0()
{
	rtg_expression_sub_conditional * sub_zero_;

	sub_zero_ = rtg_expression_sub_conditional_example_simple_conditional();
	forced_assertion(sub_zero_ != NULL);
	assert_expectations_on_rtg_expression_sub_conditional_example_simple_conditional(
			sub_zero_);

	rtg_expression_sub_conditional_assert_validity(sub_zero_);

	rtg_expression_sub_conditional_destructor(sub_zero_);
}

void
rtg_expression_sub_conditional_validity_tests()
{
	rtg_expression_sub_conditional_validity_test_0();
}

#endif

void
rtg_expression_sub_conditional_tests()
{
	rtg_expression_sub_conditional_constructors_tests();
#ifndef NDEBUG
	rtg_expression_sub_conditional_validity_tests();
#endif
}
