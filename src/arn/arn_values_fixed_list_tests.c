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
 * src/arn/arn_values_fixed_list_tests.c: Test the Amara application run
 * time values fixed list. A fixed list is like a simple list, but the
 * pointer to it stays constant over time from construction until
 * destruction.
 */

#include "arn_values_fixed_list.h"
#include "arn_value_tests.h"

void
arn_values_fixed_list_construct_and_destruct_test_0()
{
	arn_values_fixed_list * list_;

	list_ = arn_values_fixed_list_default_constructor();
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);

	arn_values_fixed_list_destructor(list_);
}

void
arn_values_fixed_list_construct_and_destruct_test_1()
{
	arn_values_fixed_list * list_;
	arn_value * value_;

	list_ = arn_values_fixed_list_default_constructor();
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);

	value_ = arn_value_example_named_natural_zero();
	assertion(value_ != NULL);
	assert_expectations_on_arn_value_example_named_natural_zero(value_);

	arn_values_fixed_list_push_front(list_, value_);
	assert_expectations_on_arn_value_example_named_natural_zero(value_);
	assertion(list_->first != NULL);
	assert_expectations_on_arn_value_example_named_natural_zero(
			list_->first);
	assertion(list_->next == NULL);

	arn_value_destructor(value_);
	arn_values_fixed_list_destructor(list_);
}

void
arn_values_fixed_list_construct_and_destruct_test_2()
{
	arn_values_fixed_list * list_;
	arn_value * value_zero_;
	arn_value * value_one_;

	list_ = arn_values_fixed_list_default_constructor();
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);

	value_zero_ = arn_value_example_named_natural_zero();
	assertion(value_zero_ != NULL);
	assert_expectations_on_arn_value_example_named_natural_zero(
			value_zero_);

	value_one_ = arn_value_example_named_natural_one();
	assertion(value_one_ != NULL);
	assert_expectations_on_arn_value_example_named_natural_one(
			value_one_);

	arn_values_fixed_list_push_front(list_, value_zero_);
	assert_expectations_on_arn_value_example_named_natural_zero(
			value_zero_);
	assertion(list_->first != NULL);
	assert_expectations_on_arn_value_example_named_natural_zero(
			list_->first);
	assertion(list_->next == NULL);

	arn_values_fixed_list_push_front(list_, value_one_);
	assert_expectations_on_arn_value_example_named_natural_one(
			value_one_);
	assertion(list_->first != NULL);
	assert_expectations_on_arn_value_example_named_natural_one(
			list_->first);
	assertion(list_->next != NULL);
	assertion(list_->next->first != NULL);
	assert_expectations_on_arn_value_example_named_natural_zero(
			list_->next->first);
	assertion(list_->next->next == NULL);

	arn_value_destructor(value_one_);
	arn_value_destructor(value_zero_);
	arn_values_fixed_list_destructor(list_);
}

void
arn_values_fixed_list_construct_and_destruct_tests()
{
	arn_values_fixed_list_construct_and_destruct_test_0();
	arn_values_fixed_list_construct_and_destruct_test_1();
	arn_values_fixed_list_construct_and_destruct_test_2();
}

void
arn_values_fixed_list_find_value_by_name_test_0()
{
	amara_string * value_name_expectation_;
	amara_string * value_raw_natural_expectation_;
	arn_value * value_;
	amara_boolean equality_;
	arn_values_fixed_list * haystack_;
	amara_string * needle_;
	arn_value * search_results_;

	value_name_expectation_ =
			amara_string_exhaustive_constructor("zero");
	assertion(value_name_expectation_ != NULL);
	assertion(value_name_expectation_->value_ != NULL);

	value_raw_natural_expectation_ =
			amara_string_exhaustive_constructor("0");
	assertion(value_raw_natural_expectation_ != NULL);
	assertion(value_raw_natural_expectation_->value_ != NULL);

	value_ = arn_value_example_named_natural_zero();
	assertion(value_ != NULL);
	assertion(value_->name_ != NULL);
	assertion(value_->name_->value_ != NULL);
	equality_ = amara_string_equality(
			value_->name_, value_name_expectation_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(value_->natural_ != NULL);
	assertion(value_->natural_->raw_ != NULL);
	assertion(value_->natural_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			value_->natural_->raw_,
			value_raw_natural_expectation_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	haystack_ = arn_values_fixed_list_default_constructor();
	assertion(haystack_ != NULL);
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);

	arn_values_fixed_list_push_front(haystack_, value_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
	assertion(haystack_->first->name_ != NULL);
	assertion(haystack_->first->name_->value_ != NULL);
	equality_ = amara_string_equality(
			haystack_->first->name_, value_name_expectation_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(haystack_->first->natural_ != NULL);
	assertion(haystack_->first->natural_->raw_ != NULL);
	assertion(haystack_->first->natural_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			haystack_->first->natural_->raw_,
			value_raw_natural_expectation_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(haystack_->next == NULL);
	assertion(value_->name_ != NULL);
	assertion(value_->name_->value_ != NULL);
	equality_ = amara_string_equality(
			value_->name_, value_name_expectation_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(value_->natural_ != NULL);
	assertion(value_->natural_->raw_ != NULL);
	assertion(value_->natural_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			value_->natural_->raw_,
			value_raw_natural_expectation_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	needle_ = amara_string_exhaustive_constructor("one");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_results_ = arn_values_fixed_list_find_value_by_name(
			haystack_, needle_);
	assertion(haystack_->first != NULL);
	assertion(haystack_->first->name_ != NULL);
	assertion(haystack_->first->name_->value_ != NULL);
	equality_ = amara_string_equality(
			haystack_->first->name_, value_name_expectation_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(haystack_->first->natural_ != NULL);
	assertion(haystack_->first->natural_->raw_ != NULL);
	assertion(haystack_->first->natural_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			haystack_->first->natural_->raw_,
			value_raw_natural_expectation_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(haystack_->next == NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_results_ == NULL);

	amara_string_destructor(needle_);
	arn_values_fixed_list_destructor(haystack_);
	arn_value_destructor(value_);
	amara_string_destructor(value_raw_natural_expectation_);
	amara_string_destructor(value_name_expectation_);
}

void
arn_values_fixed_list_find_value_by_name_tests()
{
	arn_values_fixed_list_find_value_by_name_test_0();
}

void
arn_values_fixed_list_tests()
{
	arn_values_fixed_list_construct_and_destruct_tests();
	arn_values_fixed_list_find_value_by_name_tests();
}
