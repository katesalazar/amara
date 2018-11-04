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
 * src/rtg/rtg_condition_tests.c: Test the Amara run time graph
 * condition.
 */

/*   For `assert_expectations_on_rtg_expression_example_natural_zero`. */
#include "rtg_expression_tests.h"

/*   For own functions prototypes. */
#include "rtg_condition_tests.h"

#ifndef NDEBUG

void
assert_expectations_on_rtg_condition_example_simple_conditional(
		const rtg_condition * condition)
{
	assertion(condition != NULL);
	assertion(condition->type_ == RTG_CONDITION_TYPE_LESS_THAN);
	assertion(condition->left_hand_side_expression_ != NULL);
	assertion(condition->left_hand_side_expression_->type_ ==
			RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(condition->left_hand_side_expression_->sub_natural_literal_ !=
			NULL);
	assertion(condition->left_hand_side_expression_->sub_natural_literal_->natural_literal_ !=
			NULL);
	assert_expectations_on_rtg_expression_example_natural_literal_zero(
			condition->left_hand_side_expression_);
	assertion(condition->right_hand_side_expression_ != NULL);
	assertion(condition->right_hand_side_expression_->type_ ==
			RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(condition->right_hand_side_expression_->sub_natural_literal_ !=
			NULL);
	assertion(condition->right_hand_side_expression_->sub_natural_literal_->natural_literal_ !=
			NULL);
	assert_expectations_on_rtg_expression_example_natural_literal_one(
			condition->right_hand_side_expression_);
}

#endif
