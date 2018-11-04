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
 * src/stt/stt_expression_subnode_tests.c: Test the Amara syntax tree
 * expression subnode.
 */

/*   For `typedef struct stt_expression_subnode { ... }
 * stt_expression_subnode`. */
#include "stt_expression_subnode.h"

/*   For `stt_expression * stt_expression_example_natural_zero()`. */
#include "stt_expression_tests.h"

void
stt_expression_subnode_constructors_test_0()
{
	stt_expression * expression_;
	stt_expression_subnode * subnode_;

	expression_ = stt_expression_example_natural_zero();
#ifndef NDEBUG
	assertion(expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_);
#endif

	subnode_ = stt_expression_subnode_exhaustive_constructor(
			expression_);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_);
	assertion(subnode_ != NULL);
	assertion(subnode_->expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			subnode_->expression_);
#endif

	stt_expression_subnode_destructor(subnode_);
	stt_expression_destructor(expression_);
}

void
stt_expression_subnode_constructors_test_1()
{
	stt_expression * expression_;
	stt_expression_subnode * subnode_zero_;
	stt_expression_subnode * subnode_one_;

	expression_ = stt_expression_example_natural_zero();
#ifndef NDEBUG
	assertion(expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_);
#endif

	subnode_zero_ = stt_expression_subnode_exhaustive_constructor(
			expression_);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_);
	assertion(subnode_zero_ != NULL);
	assertion(subnode_zero_->expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			subnode_zero_->expression_);
#endif

	subnode_one_ = stt_expression_subnode_copy_constructor(
			subnode_zero_);
#ifndef NDEBUG
	assertion(subnode_zero_->expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			subnode_zero_->expression_);
	assertion(subnode_one_ != NULL);
	assertion(subnode_one_->expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			subnode_one_->expression_);
#endif

	stt_expression_subnode_destructor(subnode_one_);
	stt_expression_subnode_destructor(subnode_zero_);
	stt_expression_destructor(expression_);
}

void
stt_expression_subnode_constructors_tests()
{
	stt_expression_subnode_constructors_test_0();
	stt_expression_subnode_constructors_test_1();
}

void
stt_expression_subnode_tests()
{
	stt_expression_subnode_constructors_tests();
}
