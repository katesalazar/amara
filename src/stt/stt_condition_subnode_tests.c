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
 * src/stt/stt_condition_subnode_tests.c: Test the Amara syntax tree
 * condition subnode.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_condition_tests`. */
#include "stt_condition_tests.h"

/*   For `void
 * assert_expectations_on_stt_condition_subnode_example_simple_condition(
 * const stt_condition_subnode * condition_subnode)`. */
#include "stt_condition_subnode_tests.h"

#ifndef NDEBUG

void
assert_expectations_on_stt_condition_subnode_example_simple_condition(
		const stt_condition_subnode * condition_subnode)
{
	const stt_condition * condition_;

	assertion(condition_subnode != NULL);
	assertion(condition_subnode->condition_ != NULL);

	condition_ = condition_subnode->condition_;
	assert_expectations_on_stt_condition_example_simple_condition(
			condition_);
}

#endif

void
stt_condition_subnode_exhaustive_constructor_test_0()
{
	stt_condition * condition_;
	stt_condition_subnode * condition_subnode_;

	condition_ = stt_condition_example_simple_condition();
#ifndef NDEBUG
	assertion(condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_condition(
			condition_);
#endif

	condition_subnode_ = stt_condition_subnode_exhaustive_constructor(
			condition_);
#ifndef NDEBUG
	assert_expectations_on_stt_condition_example_simple_condition(
			condition_);
	assertion(condition_subnode_ != NULL);
	assert_expectations_on_stt_condition_subnode_example_simple_condition(
			condition_subnode_);
#endif

	stt_condition_destructor(condition_);
	stt_condition_subnode_destructor(condition_subnode_);
}

void
stt_condition_subnode_copy_constructor_test_0()
{
	stt_condition * condition_;
	stt_condition_subnode * condition_subnode_zero_;
	stt_condition_subnode * condition_subnode_one_;

	condition_ = stt_condition_example_simple_condition();
#ifndef NDEBUG
	assertion(condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_condition(
			condition_);
#endif

	condition_subnode_zero_ = stt_condition_subnode_exhaustive_constructor(
			condition_);
#ifndef NDEBUG
	assert_expectations_on_stt_condition_example_simple_condition(
			condition_);
	assertion(condition_subnode_zero_ != NULL);
	assert_expectations_on_stt_condition_subnode_example_simple_condition(
			condition_subnode_zero_);
#endif

	condition_subnode_one_ = stt_condition_subnode_copy_constructor(
			condition_subnode_zero_);
#ifndef NDEBUG
	assert_expectations_on_stt_condition_subnode_example_simple_condition(
			condition_subnode_zero_);
	assertion(condition_subnode_one_ != NULL);
	assert_expectations_on_stt_condition_subnode_example_simple_condition(
			condition_subnode_one_);
#endif

	stt_condition_destructor(condition_);
	stt_condition_subnode_destructor(condition_subnode_one_);
	stt_condition_subnode_destructor(condition_subnode_zero_);
}

void
stt_condition_subnode_exhaustive_constructor_tests()
{
	stt_condition_subnode_exhaustive_constructor_test_0();
}

void
stt_condition_subnode_copy_constructor_tests()
{
	stt_condition_subnode_copy_constructor_test_0();
}

void
stt_condition_subnode_constructors_tests()
{
	stt_condition_subnode_exhaustive_constructor_tests();
	stt_condition_subnode_copy_constructor_tests();
}

void
stt_condition_subnode_tests()
{
	stt_condition_subnode_constructors_tests();
}
