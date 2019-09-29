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
 * src/arn/arn_type_tests.c: Test the Amara application run time value
 * type. A value is basically a constant.
 */

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `rtg_expression_example_simple_conditional`. */
#include "../rtg/rtg_expression_tests.h"

/*   For `arn_type`. */
#include "arn_type.h"

void
arn_type_type_is_valid_test_0()
{
	arn_type_type arn_type_type_;
	amara_boolean is_valid_;

	arn_type_type_ = ARN_TYPE_TYPE_STRING;

	is_valid_ = arn_type_type_is_valid(arn_type_type_);
	assertion(is_valid_ == AMARA_BOOLEAN_TRUE);
}

void
arn_type_type_is_valid_test_1()
{
	arn_type_type arn_type_type_;
	amara_boolean is_valid_;

	arn_type_type_ = ARN_TYPE_TYPE_INVALID;

	is_valid_ = arn_type_type_is_valid(arn_type_type_);
	assertion(is_valid_ == AMARA_BOOLEAN_FALSE);
}

void
arn_type_type_is_valid_test_2()
{
	arn_type_type arn_type_type_;
	amara_boolean is_valid_;

	arn_type_type_ = ARN_TYPE_TYPE_BOOLEAN;

	is_valid_ = arn_type_type_is_valid(arn_type_type_);
	assertion(is_valid_ == AMARA_BOOLEAN_TRUE);
}

void
arn_type_type_is_valid_test_3()
{
	arn_type_type arn_type_type_;
	amara_boolean is_valid_;

	arn_type_type_ = ARN_TYPE_TYPE_NATURAL;

	is_valid_ = arn_type_type_is_valid(arn_type_type_);
	assertion(is_valid_ == AMARA_BOOLEAN_TRUE);
}

void
arn_type_type_is_valid_test_4()
{
	arn_type_type arn_type_type_;
	amara_boolean is_valid_;

	arn_type_type_ = ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED;

	is_valid_ = arn_type_type_is_valid(arn_type_type_);
	assertion(is_valid_ == AMARA_BOOLEAN_TRUE);
}

void
arn_type_type_is_valid_tests()
{
	arn_type_type_is_valid_test_0();
	arn_type_type_is_valid_test_1();
	arn_type_type_is_valid_test_2();
	arn_type_type_is_valid_test_3();
	arn_type_type_is_valid_test_4();
}

/*
void
arn_type_type_is_known_test_0()
{
	arn_type_type arn_type_type_;
	amara_boolean is_known_;

	arn_type_type_ = ARN_TYPE_TYPE_INVALID;

	is_known_ = arn_type_type_is_known(arn_type_type_);
	assertion(is_known_ == AMARA_BOOLEAN_TRUE);
}

void
arn_type_type_is_known_tests()
{
	arn_type_type_is_known_test_0();
}
*/

/*
void
arn_type_type_is_ill_test_0()
{
	arn_type_type arn_type_type_;
	amara_boolean is_ill_;

	arn_type_type_ = arn_type_type_ill();

	is_ill_ = arn_type_type_is_ill(arn_type_type_);
	assertion(is_ill_ == AMARA_BOOLEAN_TRUE);
}

void
arn_type_type_is_ill_tests()
{
	arn_type_type_is_ill_test_0();
}
*/

void
arn_type_default_constructor_test_0()
{
	arn_type * type_;

	type_ = arn_type_default_constructor();
	assertion(type_ != NULL);
	assertion(type_->type_ == ARN_TYPE_TYPE_INVALID);
	assertion(type_->name_ == NULL);

	free(type_);
	/*
	arn_type_destructor(type_);
	*/
}

void
arn_type_default_constructor_tests()
{
	arn_type_default_constructor_test_0();
}

void
arn_type_constructors_and_destructors_tests()
{
	arn_type_default_constructor_tests();
}

/**  Friend declaration of private function. */
arn_type *
arn_type_out_of_rtg_condition(const rtg_condition * condition)
__attribute__((warn_unused_result))
;

/*
void
arn_type_out_of_rtg_condition_test_0()
{
*/
	/**  ARN type out of an ill formed RTG condition. */
/*
	rtg_condition * condition_;
	rtg_condition_type condition_requested_type_;
	rtg_condition * ill_condition_;
	arn_type * ill_condition_arn_type_;

	condition_ = rtg_condition_default_constructor();
#ifndef NDEBUG
	assertion(condition_ != NULL);
#endif

	condition_requested_type_ = rtg_condition_type_ill();
	condition_->type_ = condition_requested_type_;
	ill_condition_ = condition_;

	ill_condition_arn_type_ =
			arn_type_out_of_rtg_condition(ill_condition_);
#ifndef NDEBUG
	assertion(ill_condition_arn_type_ != NULL);
	assertion(ill_condition_arn_type_->type_ ==
			ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED);
#endif

	arn_type_destructor(ill_condition_arn_type_);
	rtg_condition_destructor(ill_condition_);
}
*/

void
arn_type_out_of_rtg_condition_tests()
{
	/*
	arn_type_out_of_rtg_condition_test_0();
	*/
}

void
arn_type_out_of_rtg_expression_test_0()
{
	rtg_expression * expression_;
	arn_type * type_;

	expression_ = rtg_expression_example_simple_conditional();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_example_simple_conditional(
			expression_);
#endif

	type_ = arn_type_out_of_rtg_expression(expression_);
	forced_assertion(type_ != NULL);
	fprintf(stderr, "%u\n", type_->type_);
#ifndef NDEBUG
	assertion(type_->type_ != ARN_TYPE_TYPE_INVALID);
	assertion(type_->type_ != ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED);
	assertion(type_->type_ == ARN_TYPE_TYPE_STRING);
#endif

	arn_type_destructor(type_);
	rtg_expression_destructor(expression_);
}

void
arn_type_out_of_rtg_expression_tests()
{
	arn_type_out_of_rtg_expression_test_0();
}

void
arn_type_tests()
{
	arn_type_type_is_valid_tests();
	/*
	arn_type_type_is_known_tests();
	*/
	/*
	arn_type_type_is_ill_tests();
	*/
	arn_type_constructors_and_destructors_tests();
	arn_type_out_of_rtg_condition_tests();
	arn_type_out_of_rtg_expression_tests();
}
