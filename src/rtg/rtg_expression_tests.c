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
 * src/rtg/rtg_expression_tests.c: Test the Amara run time graph
 * expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_expression_example_simple_conditional`. */
#include "../stt/stt_expression_tests.h"

/*   For
 * `assert_expectations_on_rtg_condition_example_simple_conditional`. */
#include "rtg_condition_tests.h"

/*   For owned function prototypes. */
#include "rtg_expression_tests.h"

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_natural_literal_zero(
		const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(expression->sub_natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_[0] ==
			0x30);  /* 48: '0'. */
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_[1] ==
			0x00);  /* 0: '\0'. */
}

void
assert_expectations_on_rtg_expression_example_natural_literal_one(
		const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(expression->sub_natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_ != NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_[0] ==
			0x31);  /* 49: '1'. */
	assertion(expression->sub_natural_literal_->natural_literal_->raw_->value_[1] ==
			0x00);  /* 0: '\0'. */
}

#endif

rtg_expression *
rtg_expression_example_simple_conditional()
{
	stt_expression * expression_;
	rtg_expression_out_of_stt_expression_ret * mid_ret_;
	rtg_expression * returning_;

	expression_ = stt_expression_example_simple_conditional();
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_simple_conditional(
			expression_);
#endif

	mid_ret_ = rtg_expression_out_of_stt_expression(expression_);
#ifndef NDEBUG
	assertion(mid_ret_ != NULL);
	assertion(mid_ret_->status ==
			RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS);
	assert_expectations_on_rtg_expression_example_simple_conditional(
			mid_ret_->expression);
#endif

	returning_ = mid_ret_->expression;

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_example_simple_conditional(
		const rtg_expression * expression)
{
	assertion(expression != NULL);
	assertion(expression->type_ == RTG_EXPRESSION_TYPE_CONDITIONAL);
	assertion(expression->sub_conditional_ != NULL);
	assertion(expression->sub_conditional_->if_ != NULL);
	assertion(expression->sub_conditional_->if_->type_ ==
			RTG_EXPRESSION_SUB_CONDITIONAL_IF_TYPE_IF_THEN_ELSE);
	assertion(expression->sub_conditional_->if_->condition_ != NULL);
	assert_expectations_on_rtg_condition_example_simple_conditional(
			expression->sub_conditional_->if_->condition_);
}

#endif
