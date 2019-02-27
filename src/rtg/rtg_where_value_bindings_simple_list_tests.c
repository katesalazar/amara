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
 * src/rtg/rtg_where_value_bindings_simple_list_tests.c: Test the Amara
 * run time graph _where_ value bindings simple list.
 */

/*   For `stt_where_value_bindings_simple_list *
 * stt_where_value_bindings_simple_list_example_simple_value_bind()`. */
#include "../stt/stt_where_value_bindings_simple_list_tests.h"

/*   For `rtg_where_value_binding *
 * rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero()`. */
#include "rtg_where_value_binding_tests.h"

/*   For `typedef struct rtg_where_value_bindings_simple_list { ... }
 * rtg_where_value_bindings_simple_list`. */
#include "rtg_where_value_bindings_simple_list.h"

#ifndef NDEBUG

void
assert_expectations_on_rtg_where_value_bindings_simple_list_example_simple_value_bind(
		const rtg_where_value_bindings_simple_list * list)
{
	assertion(list != NULL);
	assertion(list->first != NULL);
	assertion(list->first->value_name_ != NULL);
	assertion(list->first->value_name_->value_ != NULL);
	assertion(list->first->value_name_->value_[0] == 'f');
	assertion(list->first->value_name_->value_[1] == 'o');
	assertion(list->first->value_name_->value_[2] == 'o');
	assertion(list->first->value_name_->value_[3] == '\0');
	assertion(list->first->value_expression_ != NULL);
	/* XXX delegate these checks below. */
	assertion(list->first->value_expression_->type_ ==
			RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(list->first->value_expression_->sub_natural_literal_ !=
			NULL);
	assertion(list->first->value_expression_->sub_natural_literal_->natural_literal_ !=
			NULL);
	assertion(list->first->value_expression_->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(list->first->value_expression_->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(list->first->value_expression_->sub_natural_literal_->natural_literal_->raw_->value_[0] ==
			'0');
	assertion(list->first->value_expression_->sub_natural_literal_->natural_literal_->raw_->value_[1] ==
			'\0');
	assertion(list->next == NULL);
}

#endif

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
rtg_where_value_bindings_simple_list_transformation_constructors_test_0()
{
	stt_where_value_bindings_simple_list * stt_where_bindings_list_;
	/*
	rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_ret * transformation_ret_;
	*/
	rtg_where_value_bindings_simple_list * rtg_where_bindings_list_;

	stt_where_bindings_list_ =
			stt_where_value_bindings_simple_list_example_simple_value_bind();
	forced_assertion(stt_where_bindings_list_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind(
			stt_where_bindings_list_);
#endif

	rtg_where_bindings_list_ =
			rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list(
					stt_where_bindings_list_);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind(
			stt_where_bindings_list_);
#endif
	forced_assertion(rtg_where_bindings_list_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_where_value_bindings_simple_list_example_simple_value_bind(
			rtg_where_bindings_list_);
#endif

	rtg_where_value_bindings_simple_list_destructor(
			rtg_where_bindings_list_);
	/*
	free(transformation_ret_);
	*/
	stt_where_value_bindings_simple_list_destructor(
			stt_where_bindings_list_);
}

void
rtg_where_value_bindings_simple_list_transformation_constructors_tests()
{
	rtg_where_value_bindings_simple_list_transformation_constructors_test_0();
}

void
rtg_where_value_bindings_simple_list_constructors_tests()
{
	rtg_where_value_bindings_simple_list_copy_constructors_tests();
	rtg_where_value_bindings_simple_list_transformation_constructors_tests();
}

void
rtg_where_value_bindings_simple_list_tests()
{
	rtg_where_value_bindings_simple_list_constructors_tests();
}
