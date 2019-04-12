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
 * src/rtg/rtg_where_value_binding_tests.c: Test the Amara run time
 * graph _where_ value binding.
 */

/*   For `stt_where_value_binding *
 * stt_where_value_binding_example_bind_value_foo_to_expression_natural_zero()`. */
#include "../stt/stt_where_value_binding_tests.h"

#include "rtg_expression_tests.h"

/*   For own function prototypes. */
#include "rtg_where_value_binding_tests.h"

rtg_where_value_binding *
rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(void)
{
	stt_where_value_binding * stt_where_value_binding_;
	rtg_where_value_binding * returning_;

	stt_where_value_binding_ =
			stt_where_value_binding_example_simple_value_bind_foo_to_zero();
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			stt_where_value_binding_);
#endif

	returning_ = rtg_where_value_binding_out_of_stt_where_value_binding(
			stt_where_value_binding_);
#ifndef NDEBUG
	assert_expectations_on_rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(
			returning_);
#endif

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(
		const rtg_where_value_binding * where_value_binding)
{
	assertion(where_value_binding != NULL);
	assertion(where_value_binding->value_name_ != NULL);
	assertion(where_value_binding->value_name_->value_ != NULL);
	assertion(where_value_binding->value_name_->value_[0] == 'f');
	assertion(where_value_binding->value_name_->value_[1] == 'o');
	assertion(where_value_binding->value_name_->value_[2] == 'o');
	assertion(where_value_binding->value_name_->value_[3] == '\0');
	assertion(where_value_binding->value_expression_ != NULL);
	assertion(where_value_binding->value_expression_->type_ ==
			RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(where_value_binding->value_expression_->sub_natural_literal_ !=
			NULL);
	assertion(where_value_binding->value_expression_->sub_natural_literal_->natural_literal_ !=
			NULL);
	assertion(where_value_binding->value_expression_->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(where_value_binding->value_expression_->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(where_value_binding->value_expression_->sub_natural_literal_->natural_literal_->raw_->value_[0] ==
			'0');
	assertion(where_value_binding->value_expression_->sub_natural_literal_->natural_literal_->raw_->value_[1] ==
			'\0');
}

#endif

rtg_where_value_binding *
rtg_where_value_binding_example_bind_value_bar_to_expression_natural_one(void)
{
	stt_where_value_binding * stt_where_value_binding_;
	rtg_where_value_binding * returning_;

	stt_where_value_binding_ =
			stt_where_value_binding_example_simple_value_bind_bar_to_one();
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_bar_to_one(
			stt_where_value_binding_);
#endif

	returning_ = rtg_where_value_binding_out_of_stt_where_value_binding(
			stt_where_value_binding_);
#ifndef NDEBUG
	assert_expectations_on_rtg_where_value_binding_example_bind_value_bar_to_expression_natural_one(
			returning_);
#endif

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_where_value_binding_example_bind_value_bar_to_expression_natural_one(
		const rtg_where_value_binding * where_value_binding)
{
	assertion(where_value_binding != NULL);
	assertion(where_value_binding->value_name_ != NULL);
	assertion(where_value_binding->value_name_->value_ != NULL);
	assertion(where_value_binding->value_name_->value_[0] == 'b');
	assertion(where_value_binding->value_name_->value_[1] == 'a');
	assertion(where_value_binding->value_name_->value_[2] == 'r');
	assertion(where_value_binding->value_name_->value_[3] == '\0');
	assertion(where_value_binding->value_expression_ != NULL);
	assertion(where_value_binding->value_expression_->type_ ==
			RTG_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(where_value_binding->value_expression_->sub_natural_literal_ !=
			NULL);
	assertion(where_value_binding->value_expression_->sub_natural_literal_->natural_literal_ !=
			NULL);
	assertion(where_value_binding->value_expression_->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(where_value_binding->value_expression_->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(where_value_binding->value_expression_->sub_natural_literal_->natural_literal_->raw_->value_[0] ==
			'1');
	assertion(where_value_binding->value_expression_->sub_natural_literal_->natural_literal_->raw_->value_[1] ==
			'\0');
}

#endif

#ifndef NDEBUG

void
assert_expectations_on_rtg_where_value_binding_example_identifier_foo_is_bound_to_string_literal_foo(
		const rtg_where_value_binding * where_value_binding)
{
	assertion(where_value_binding != NULL);
	assertion(where_value_binding->value_name_ != NULL);
	assertion(where_value_binding->value_name_->value_ != NULL);
	assertion(where_value_binding->value_name_->value_[0] == 'f');
	assertion(where_value_binding->value_name_->value_[1] == 'o');
	assertion(where_value_binding->value_name_->value_[2] == 'o');
	assertion(where_value_binding->value_name_->value_[3] == '\0');
	assertion(where_value_binding->value_expression_ != NULL);
	assert_expectations_on_rtg_expression_example_string_literal_foo(
			where_value_binding->value_expression_);
}

#endif
