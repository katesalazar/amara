/*
 * Copyright 2018-2020 Mercedes Catherine Salazar
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
 * src/arn/arn_values_simple_list.c: Test the Amara application run time
 * values simple list.
 */

#include "arn_value_tests.h"
#include "arn_values_simple_list.h"

void
arn_values_simple_list_construct_and_destruct_test_0()
{
	arn_values_simple_list * values_;

	values_ = arn_values_simple_list_default_constructor();
	assertion(values_ != NULL);
	assertion(values_->first == NULL);
	assertion(values_->next == NULL);

	arn_values_simple_list_destructor(values_);
}

void
arn_values_simple_list_construct_and_destruct_test_1()
{
	arn_values_simple_list * values_;
	arn_value * value_;
	amara_boolean equality_;

	values_ = arn_values_simple_list_default_constructor();
	assertion(values_ != NULL);
	assertion(values_->first == NULL);
	assertion(values_->next == NULL);

	value_ = arn_value_example_named_natural_zero();
	assertion(value_ != NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(value_->name_ != NULL);
	assertion(value_->name_->value_ != NULL);
	assertion(value_->natural_ != NULL);

	values_ = arn_values_simple_list_push_front(values_, value_);
	assertion(values_ != NULL);
	assertion(values_->first != NULL);
	assertion(values_->first->type_ ==
			ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(values_->first->name_ != NULL);
	assertion(values_->first->name_->value_ != NULL);
	assertion(values_->next == NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(value_->name_ != NULL);
	assertion(value_->name_->value_ != NULL);
	assertion(value_->natural_ != NULL);
	equality_ = amara_string_equality(
			values_->first->name_, value_->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	arn_value_destructor(value_);
	arn_values_simple_list_destructor(values_);
}

void
arn_values_simple_list_construct_and_destruct_test_2()
{
	arn_values_simple_list * values_;
	arn_value * value_zero_;
	arn_value * value_one_;
	amara_boolean equality_;

	values_ = arn_values_simple_list_default_constructor();
	assertion(values_ != NULL);
	assertion(values_->first == NULL);
	assertion(values_->next == NULL);

	value_zero_ = arn_value_example_named_natural_zero();
	assertion(value_zero_ != NULL);
	assertion(value_zero_->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(value_zero_->name_ != NULL);
	assertion(value_zero_->name_->value_ != NULL);
	assertion(value_zero_->natural_ != NULL);

	value_one_ = arn_value_example_named_natural_one();
	assertion(value_one_ != NULL);
	assertion(value_one_->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(value_one_->name_ != NULL);
	assertion(value_one_->name_->value_ != NULL);
	assertion(value_one_->natural_ != NULL);

	values_ = arn_values_simple_list_push_front(values_, value_zero_);
	assertion(values_ != NULL);
	assertion(values_->first != NULL);
	assertion(values_->first->type_ ==
			ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(values_->first->name_ != NULL);
	assertion(values_->first->name_->value_ != NULL);
	assertion(values_->next == NULL);
	assertion(value_zero_ != NULL);
	assertion(value_zero_->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(value_zero_->name_ != NULL);
	assertion(value_zero_->name_->value_ != NULL);
	assertion(value_zero_->natural_ != NULL);
	equality_ = amara_string_equality(
			values_->first->name_, value_zero_->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	values_ = arn_values_simple_list_push_front(values_, value_one_);
	assertion(values_ != NULL);
	assertion(values_->first != NULL);
	assertion(values_->first->type_ ==
			ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(values_->first->name_ != NULL);
	assertion(values_->first->name_->value_ != NULL);
	assertion(values_->next != NULL);
	assertion(values_->next->first != NULL);
	assertion(values_->next->first->type_ ==
			ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(values_->next->first->name_ != NULL);
	assertion(values_->next->first->name_->value_ != NULL);
	assertion(values_->next->next == NULL);
	assertion(value_zero_ != NULL);
	assertion(value_zero_->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(value_zero_->name_ != NULL);
	assertion(value_zero_->name_->value_ != NULL);
	assertion(value_zero_->natural_ != NULL);
	equality_ = amara_string_equality(
			values_->next->first->name_, value_one_->name_);

	arn_value_destructor(value_one_);
	arn_value_destructor(value_zero_);
	arn_values_simple_list_destructor(values_);
}

void
arn_values_simple_list_construct_and_destruct_tests()
{
	arn_values_simple_list_construct_and_destruct_test_0();
	arn_values_simple_list_construct_and_destruct_test_1();
	arn_values_simple_list_construct_and_destruct_test_2();
}

tests_simple_list *
register_arn_values_simple_list_construct_and_destruct_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_arn_values_simple_list_construct_and_destruct_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& arn_values_simple_list_construct_and_destruct_test_0);
	tests_simple_list_push_back(
			tests,
			& arn_values_simple_list_construct_and_destruct_test_1);
	tests_simple_list_push_back(
			tests,
			& arn_values_simple_list_construct_and_destruct_test_2);
	return tests;
}

/*
void
arn_values_simple_list_find_test_0()
{
	arn_values_simple_list * values_;
	amara_string * name_to_search_;
	arn_value * search_result_;

	values_ = NULL;

	name_to_search_ = amara_string_exhaustive_constructor("zero");
	assertion(name_to_search_->value_ != NULL);

	search_result_ = arn_values_simple_list_find_value_by_name(
			values_, name_to_search_);
	assertion(values_->first == NULL);
	assertion(values_->next == NULL);
	assertion(name_to_search_->value_ != NULL);
	assertion(search_result_ == NULL);

	amara_string_destructor(name_to_search_);
*/
	/*
	arn_value_destructor(value_);
	*/
/*
}
*/

void
arn_values_simple_list_find_test_1()
{
	arn_values_simple_list * values_;
	amara_string * name_to_search_;
	arn_value * search_result_;

	values_ = arn_values_simple_list_default_constructor();
	assertion(values_ != NULL);
	assertion(values_->first == NULL);
	assertion(values_->next == NULL);

	name_to_search_ = amara_string_exhaustive_constructor("zero");
	assertion(name_to_search_->value_ != NULL);

	search_result_ =
			arn_values_simple_list_find_value_by_name_return_reference(
					values_, name_to_search_);
	assertion(values_->first == NULL);
	assertion(values_->next == NULL);
	assertion(name_to_search_->value_ != NULL);
	assertion(search_result_ == NULL);

	amara_string_destructor(name_to_search_);
	/*
	arn_value_destructor(value_);
	*/
	arn_values_simple_list_destructor(values_);
}

void
arn_values_simple_list_find_test_2()
{
	arn_values_simple_list * values_;
	arn_value * value_;
	amara_string * name_to_search_;
	arn_value * search_result_;
	amara_boolean equality_;

	values_ = arn_values_simple_list_default_constructor();
	assertion(values_ != NULL);
	assertion(values_->first == NULL);
	assertion(values_->next == NULL);

	value_ = arn_value_example_named_natural_zero();
	assertion(value_ != NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(value_->name_ != NULL);
	assertion(value_->name_->value_ != NULL);
	assertion(value_->natural_ != NULL);
	assertion(value_->natural_->raw_ != NULL);

	name_to_search_ = amara_string_exhaustive_constructor("zero");
	assertion(name_to_search_->value_ != NULL);

	values_ = arn_values_simple_list_push_front(values_, value_);
	assertion(values_ != NULL);
	assertion(values_->first != NULL);
	assertion(values_->first->type_ ==
			ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(values_->first->name_ != NULL);
	assertion(values_->first->name_->value_ != NULL);
	assertion(values_->first->natural_ != NULL);
	assertion(values_->first->natural_->raw_ != NULL);
	assertion(values_->next == NULL);
	assertion(value_ != NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(value_->name_ != NULL);
	assertion(value_->name_->value_ != NULL);
	assertion(value_->natural_ != NULL);
	assertion(value_->natural_->raw_ != NULL);
	equality_ = amara_string_equality(
			values_->first->name_, value_->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	equality_ = amara_string_equality(
			values_->first->natural_->raw_,
			value_->natural_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	search_result_ =
			arn_values_simple_list_find_value_by_name_return_reference(
					values_, name_to_search_);
	assertion(values_->first != NULL);
	assertion(values_->first->type_ ==
			ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(values_->first->name_ != NULL);
	assertion(values_->first->name_->value_ != NULL);
	assertion(values_->first->natural_ != NULL);
	assertion(values_->first->natural_->raw_ != NULL);
	assertion(values_->next == NULL);
	assertion(name_to_search_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->type_ ==
			ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(search_result_->name_ != NULL);
	assertion(search_result_->name_->value_ != NULL);
	assertion(search_result_->natural_ != NULL);
	assertion(search_result_->natural_->raw_ != NULL);
	equality_ = amara_string_equality(
			values_->first->natural_->raw_,
			value_->natural_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(name_to_search_);
	arn_value_destructor(value_);
	arn_values_simple_list_destructor(values_);
}

void
arn_values_simple_list_find_test_3()
{
	arn_values_simple_list * values_;
	arn_value * value_;
	amara_string * name_to_search_;
	arn_value * search_result_;
	amara_boolean equality_;

	values_ = arn_values_simple_list_default_constructor();
	assertion(values_ != NULL);
	assertion(values_->first == NULL);
	assertion(values_->next == NULL);

	value_ = arn_value_example_named_natural_zero();
	assertion(value_ != NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(value_->name_ != NULL);
	assertion(value_->name_->value_ != NULL);
	assertion(value_->natural_ != NULL);
	assertion(value_->natural_->raw_ != NULL);

	name_to_search_ = amara_string_exhaustive_constructor("one");
	assertion(name_to_search_->value_ != NULL);

	values_ = arn_values_simple_list_push_front(values_, value_);
	assertion(values_ != NULL);
	assertion(values_->first != NULL);
	assertion(values_->first->type_ ==
			ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(values_->first->name_ != NULL);
	assertion(values_->first->name_->value_ != NULL);
	assertion(values_->first->natural_ != NULL);
	assertion(values_->first->natural_->raw_ != NULL);
	assertion(values_->next == NULL);
	assertion(value_ != NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(value_->name_ != NULL);
	assertion(value_->name_->value_ != NULL);
	assertion(value_->natural_ != NULL);
	assertion(value_->natural_->raw_ != NULL);
	equality_ = amara_string_equality(
			values_->first->name_, value_->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	equality_ = amara_string_equality(
			values_->first->natural_->raw_,
			value_->natural_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	search_result_ =
			arn_values_simple_list_find_value_by_name_return_reference(
					values_, name_to_search_);
	assertion(values_->first != NULL);
	assertion(values_->first->type_ ==
			ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
	assertion(values_->first->name_ != NULL);
	assertion(values_->first->name_->value_ != NULL);
	assertion(values_->first->natural_ != NULL);
	assertion(values_->first->natural_->raw_ != NULL);
	assertion(values_->next == NULL);
	assertion(name_to_search_->value_ != NULL);
	assertion(search_result_ == NULL);

	amara_string_destructor(name_to_search_);
	arn_value_destructor(value_);
	arn_values_simple_list_destructor(values_);
}

void
arn_values_simple_list_find_tests()
{
	/*
	arn_values_simple_list_find_test_0();
	*/
	arn_values_simple_list_find_test_1();
	arn_values_simple_list_find_test_2();
	arn_values_simple_list_find_test_3();
}

tests_simple_list *
register_arn_values_simple_list_find_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_arn_values_simple_list_find_tests(tests_simple_list * tests)
{
	/*
	tests_simple_list_push_back(tests,
	                            & arn_values_simple_list_find_test_0);
	*/
	tests_simple_list_push_back(tests,
	                            & arn_values_simple_list_find_test_1);
	tests_simple_list_push_back(tests,
	                            & arn_values_simple_list_find_test_2);
	tests_simple_list_push_back(tests,
	                            & arn_values_simple_list_find_test_3);
	return tests;
}

void
arn_values_simple_list_assign_natural_out_of_unsigned_short_test_0()
{
	arn_value * value_;
	arn_values_simple_list * values_;
	amara_string * value_name_;
	unsigned short unsigned_short_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif
	amara_string * expected_value_raw_natural_;

	value_ = arn_value_default_constructor();
	forced_assertion(value_ != NULL);
#ifndef NDEBUG
	assertion(value_->type_ == ARN_VALUE_TYPE_INVALID);
	assertion(value_->name_ == NULL);
	assertion(value_->string_ == NULL);
	assertion(value_->natural_ == NULL);
#endif

	values_ = arn_values_simple_list_default_constructor();
	forced_assertion(values_ != NULL);
#ifndef NDEBUG
	assertion(values_->first == NULL);
	assertion(values_->next == NULL);
#endif

	value_name_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(value_name_ != NULL);
	forced_assertion(value_name_->value_ != NULL);

	arn_value_set_name(value_, value_name_);
#ifndef NDEBUG
	assertion(value_->type_ ==
			ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE);
#endif
	forced_assertion(value_->name_ != NULL);
	forced_assertion(value_->name_->value_ != NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(value_->name_, value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(value_->string_ == NULL);
	assertion(value_->natural_ == NULL);
	assertion(value_name_->value_ != NULL);
#endif

	arn_value_characterize_as_natural(value_);
#ifndef NDEBUG
	assertion(value_->type_ == ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL);
	assertion(value_->name_ != NULL);
	assertion(value_->name_->value_ != NULL);
	equality_ = amara_string_equality(value_->name_, value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(value_->string_ == NULL);
	assertion(value_->natural_ == NULL);
#endif

	values_ = arn_values_simple_list_push_front(values_, value_);
	forced_assertion(values_ != NULL);
	forced_assertion(values_->first != NULL);
#ifndef NDEBUG
	assertion(values_->first->type_ ==
			ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL);
#endif
	forced_assertion(values_->first->name_ != NULL);
	forced_assertion(values_->first->name_->value_ != NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(values_->first->name_, value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(values_->first->string_ == NULL);
	assertion(values_->first->natural_ == NULL);
	assertion(values_->next == NULL);
	assertion(value_->type_ == ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL);
	assertion(value_->name_ != NULL);
	assertion(value_->name_->value_ != NULL);
	equality_ = amara_string_equality(value_->name_, value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(value_->string_ == NULL);
	assertion(value_->natural_ == NULL);
#endif

	unsigned_short_ = 7;

	expected_value_raw_natural_ = amara_string_exhaustive_constructor("7");
	forced_assertion(expected_value_raw_natural_ != NULL);
	forced_assertion(expected_value_raw_natural_->value_ != NULL);

	values_ = arn_values_simple_list_assign_natural_out_of_unsigned_short(
			values_, value_name_, unsigned_short_);
	/* if (values_ == NULL) { */ /* XXX */
	/* } else { */ /* XXX*/
	forced_assertion(values_ != NULL);
#ifndef NDEBUG
	assertion(values_->first->type_ ==
			ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
#endif
	forced_assertion(values_->first != NULL);
	forced_assertion(values_->first->name_ != NULL);
	forced_assertion(values_->first->name_->value_ != NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(values_->first->name_, value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(values_->first->string_ == NULL);
#endif
	forced_assertion(values_->first->natural_ != NULL);
	forced_assertion(values_->first->natural_->raw_ != NULL);
	forced_assertion(values_->first->natural_->raw_->value_ != NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(
			expected_value_raw_natural_,
			values_->first->natural_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(values_->next == NULL);
	assertion(value_name_->value_ != NULL);
#endif
	/* } */ /* XXX */

	/* if (values_ == NULL) { */ /* XXX */
	/* } else { */ /* XXX */
	arn_values_simple_list_destructor(values_);
	/* } */ /* XXX */

	amara_string_destructor(expected_value_raw_natural_);
	arn_value_destructor(value_);
	amara_string_destructor(value_name_);
}

void
arn_values_simple_list_assign_natural_out_of_unsigned_short_tests()
{
	arn_values_simple_list_assign_natural_out_of_unsigned_short_test_0();
}

tests_simple_list *
register_arn_values_simple_list_assign_natural_out_of_unsigned_short_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_arn_values_simple_list_assign_natural_out_of_unsigned_short_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& arn_values_simple_list_assign_natural_out_of_unsigned_short_test_0);
	return tests;
}

void
arn_values_simple_list_tests()
{
	arn_values_simple_list_construct_and_destruct_tests();
	arn_values_simple_list_find_tests();
	arn_values_simple_list_assign_natural_out_of_unsigned_short_tests();
}

tests_simple_list *
register_arn_values_simple_list_tests(tests_simple_list * tests)
{
	return register_arn_values_simple_list_assign_natural_out_of_unsigned_short_tests(
	       register_arn_values_simple_list_find_tests(
	       register_arn_values_simple_list_construct_and_destruct_tests(
	               tests)));
}
