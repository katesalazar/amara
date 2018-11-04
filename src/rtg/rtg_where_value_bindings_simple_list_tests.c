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
 * src/rtg/rtg_where_value_bindings_simple_list_tests.c: Test the Amara
 * run time graph _where_ value bindings simple list.
 */

/*   For `rtg_where_value_binding *
 * rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero()`. */
#include "rtg_where_value_binding_tests.h"

/*   For `typedef struct rtg_where_value_bindings_simple_list { ... }
 * rtg_where_value_bindings_simple_list`. */
#include "rtg_where_value_bindings_simple_list.h"

void
rtg_where_value_bindings_simple_list_copy_constructors_test_0()
{
	rtg_where_value_binding * foo_value_binding_;
	rtg_where_value_bindings_simple_list * list_;
	rtg_where_value_bindings_simple_list * list_copy_;

	foo_value_binding_ =
			rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero();
#ifndef NDEBUG
	assert_expectations_on_rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(
			foo_value_binding_);
#endif

	list_ = rtg_where_value_bindings_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
#endif

	list_ = rtg_where_value_bindings_simple_list_push_front(
			list_, foo_value_binding_);
#ifndef NDEBUG
	assertion(list_ != NULL);
	assertion(list_->first != NULL);
	assert_expectations_on_rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(
			list_->first);
	assertion(list_->next == NULL);
	assert_expectations_on_rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(
			foo_value_binding_);
#endif

	list_copy_ = rtg_where_value_bindings_simple_list_copy_constructor(
			list_);
#ifndef NDEBUG
	rtg_where_value_bindings_simple_list_assert_healthy(list_);
	assert_expectations_on_rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(
			list_->first);
	assertion(list_->next == NULL);
	rtg_where_value_bindings_simple_list_assert_healthy(list_copy_);
	assert_expectations_on_rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(
			list_copy_->first);
	assertion(list_copy_->next == NULL);
#endif

	rtg_where_value_bindings_simple_list_destructor(list_copy_);
	rtg_where_value_bindings_simple_list_destructor(list_);
	rtg_where_value_binding_destructor(foo_value_binding_);
}

void
rtg_where_value_bindings_simple_list_copy_constructors_test_1()
{
	rtg_where_value_binding * foo_value_binding_;
	rtg_where_value_binding * bar_value_binding_;
	rtg_where_value_bindings_simple_list * list_;
	rtg_where_value_bindings_simple_list * list_copy_;

	foo_value_binding_ =
			rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero();
#ifndef NDEBUG
	assert_expectations_on_rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(
			foo_value_binding_);
#endif

	bar_value_binding_ =
			rtg_where_value_binding_example_bind_value_bar_to_expression_natural_one();
#ifndef NDEBUG
	assert_expectations_on_rtg_where_value_binding_example_bind_value_bar_to_expression_natural_one(
			bar_value_binding_);
#endif

	list_ = rtg_where_value_bindings_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
#endif

	list_ = rtg_where_value_bindings_simple_list_push_front(
			list_, bar_value_binding_);
#ifndef NDEBUG
	assertion(list_ != NULL);
	assertion(list_->first != NULL);
	assert_expectations_on_rtg_where_value_binding_example_bind_value_bar_to_expression_natural_one(
			list_->first);
	assertion(list_->next == NULL);
	assert_expectations_on_rtg_where_value_binding_example_bind_value_bar_to_expression_natural_one(
			bar_value_binding_);
#endif

	list_ = rtg_where_value_bindings_simple_list_push_front(
			list_, foo_value_binding_);
#ifndef NDEBUG
	assertion(list_ != NULL);
	assertion(list_->first != NULL);
	assert_expectations_on_rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(
			list_->first);
	assertion(list_->next != NULL);
	assert_expectations_on_rtg_where_value_binding_example_bind_value_bar_to_expression_natural_one(
			list_->next->first);
	assertion(list_->next->next == NULL);
	assert_expectations_on_rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(
			foo_value_binding_);
#endif

	list_copy_ = rtg_where_value_bindings_simple_list_copy_constructor(
			list_);
#ifndef NDEBUG
	rtg_where_value_bindings_simple_list_assert_healthy(list_);
	assert_expectations_on_rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(
			list_->first);
	assertion(list_->next != NULL);
	assert_expectations_on_rtg_where_value_binding_example_bind_value_bar_to_expression_natural_one(
			list_->next->first);
	assertion(list_->next->next == NULL);
	rtg_where_value_bindings_simple_list_assert_healthy(list_copy_);
	assert_expectations_on_rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(
			list_copy_->first);
	assertion(list_copy_->next != NULL);
	assert_expectations_on_rtg_where_value_binding_example_bind_value_bar_to_expression_natural_one(
			list_copy_->next->first);
	assertion(list_copy_->next->next == NULL);
#endif

	rtg_where_value_bindings_simple_list_destructor(list_copy_);
	rtg_where_value_bindings_simple_list_destructor(list_);
	rtg_where_value_binding_destructor(bar_value_binding_);
	rtg_where_value_binding_destructor(foo_value_binding_);
}

void
rtg_where_value_bindings_simple_list_copy_constructors_tests()
{
	rtg_where_value_bindings_simple_list_copy_constructors_test_0();
	rtg_where_value_bindings_simple_list_copy_constructors_test_1();
}

void
rtg_where_value_bindings_simple_list_constructors_tests()
{
	rtg_where_value_bindings_simple_list_copy_constructors_tests();
}

void
rtg_where_value_bindings_simple_list_tests()
{
	rtg_where_value_bindings_simple_list_constructors_tests();
}
