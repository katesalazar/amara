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
 * src/arn/app_runner_tests.c: Amara applications runtime applications
 * runner tests.
 */

#include "arn_value_tests.h"

#include "app_runner_tests.h"

#ifndef NDEBUG

/**  Friend declaration. */
amara_boolean
assert_types_compatible_for_condition_type_less_than(
		arn_value * left_hand_side_value_,
		arn_value * right_hand_side_value_)
;

#endif

#ifndef NDEBUG

void
assert_types_compatible_for_condition_type_less_than_test_0()
{
	arn_value * left_hand_side_value_;
	arn_value * right_hand_side_value_;
	amara_boolean result_;

	left_hand_side_value_ = arn_value_example_named_natural_zero();
	forced_assertion(left_hand_side_value_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_arn_value_example_named_natural_zero(
			left_hand_side_value_);
#endif

	right_hand_side_value_ = arn_value_example_named_natural_one();
	forced_assertion(right_hand_side_value_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_arn_value_example_named_natural_one(
			right_hand_side_value_);
#endif

	result_ = assert_types_compatible_for_condition_type_less_than(
			left_hand_side_value_, right_hand_side_value_);
	forced_assertion(result_ == AMARA_BOOLEAN_TRUE);
}

#endif

void
assert_types_compatible_for_condition_type_less_than_tests()
{
#ifndef NDEBUG
	assert_types_compatible_for_condition_type_less_than_test_0();
#endif
}

void
app_runner_tests()
{
	assert_types_compatible_for_condition_type_less_than_tests();
	/*
	assert_types_compatible_for_condition_type_greater_than_tests();
	*/
}
