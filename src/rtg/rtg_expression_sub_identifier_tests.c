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
 * src/rtg/rtg_expression_sub_identifier_tests.c: Amara run time graph
 * identifier type of expression tests.
 */

/*   For `void forced_assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_expression_sub_identifier *
 * stt_expression_sub_identifier_example_foo()`. */
#include "../stt/stt_expression_sub_identifier_tests.h"

/*   For `typedef struct rtg_expression_sub_identifier { ... }
 * rtg_expression_sub_identifier;`. */
#include "rtg_expression_sub_identifier.h"

#ifndef NDEBUG

void
assert_expectations_on_rtg_expression_sub_identifier_example_foo(
		const rtg_expression_sub_identifier * expression_sub)
{
	assertion(expression_sub != NULL);
	assertion(expression_sub->identifier_ != NULL);
	assertion(expression_sub->identifier_->value_ != NULL);
	assertion(expression_sub->identifier_->value_[0] == 0x66);  /* 102: 'f'. */
	assertion(expression_sub->identifier_->value_[1] == 0x6F);  /* 111: 'o'. */
	assertion(expression_sub->identifier_->value_[2] == 0x6F);  /* 111: 'o'. */
	assertion(expression_sub->identifier_->value_[3] == 0x00);  /* 0: '\0'. */
}

#endif

void
rtg_expression_sub_identifier_copy_constructor_test_0()
{
	stt_expression_sub_identifier * stt_expression_sub_identifier_;
	rtg_expression_sub_identifier * rtg_expression_sub_identifier_zero_;
	rtg_expression_sub_identifier * rtg_expression_sub_identifier_one_;

	stt_expression_sub_identifier_ =
			stt_expression_sub_identifier_example_foo();
	forced_assertion(stt_expression_sub_identifier_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_identifier_example_foo(
			stt_expression_sub_identifier_);
#endif

	rtg_expression_sub_identifier_zero_ =
			rtg_expression_sub_identifier_out_of_stt_expression_sub_identifier(
					stt_expression_sub_identifier_);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_identifier_example_foo(
			stt_expression_sub_identifier_);
#endif
	forced_assertion(rtg_expression_sub_identifier_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_sub_identifier_example_foo(
			rtg_expression_sub_identifier_zero_);
#endif

	rtg_expression_sub_identifier_one_ =
			rtg_expression_sub_identifier_copy_constructor(
					rtg_expression_sub_identifier_zero_);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_sub_identifier_example_foo(
			rtg_expression_sub_identifier_zero_);
#endif
	forced_assertion(rtg_expression_sub_identifier_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_sub_identifier_example_foo(
			rtg_expression_sub_identifier_one_);
#endif

	rtg_expression_sub_identifier_destructor(
			rtg_expression_sub_identifier_one_);
	rtg_expression_sub_identifier_destructor(
			rtg_expression_sub_identifier_zero_);
	stt_expression_sub_identifier_destructor(
			stt_expression_sub_identifier_);
}

void
rtg_expression_sub_identifier_copy_constructor_tests()
{
	rtg_expression_sub_identifier_copy_constructor_test_0();
}

void
rtg_expression_sub_identifier_transformation_constructor_test_0()
{
	stt_expression_sub_identifier * stt_expression_sub_identifier_;
	rtg_expression_sub_identifier * rtg_expression_sub_identifier_;

	stt_expression_sub_identifier_ =
			stt_expression_sub_identifier_example_foo();
	forced_assertion(stt_expression_sub_identifier_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_identifier_example_foo(
			stt_expression_sub_identifier_);
#endif

	rtg_expression_sub_identifier_ =
			rtg_expression_sub_identifier_out_of_stt_expression_sub_identifier(
					stt_expression_sub_identifier_);
	forced_assertion(rtg_expression_sub_identifier_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_expression_sub_identifier_example_foo(
			rtg_expression_sub_identifier_);
#endif

	rtg_expression_sub_identifier_destructor(
			rtg_expression_sub_identifier_);
	stt_expression_sub_identifier_destructor(
			stt_expression_sub_identifier_);
}

void
rtg_expression_sub_identifier_transformation_constructor_tests()
{
	rtg_expression_sub_identifier_transformation_constructor_test_0();
}

void
rtg_expression_sub_identifier_constructors_tests()
{
	rtg_expression_sub_identifier_copy_constructor_tests();
	rtg_expression_sub_identifier_transformation_constructor_tests();
}

void
rtg_expression_sub_identifier_tests()
{
	rtg_expression_sub_identifier_constructors_tests();
}
