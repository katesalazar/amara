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
 * src/stt/stt_where_binding_subnode_tests.c: Test the Amara syntax tree
 * _where_ value binding sub node.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_where_value_binding_subnode`. */
#include "stt_where_value_binding_subnode.h"

/*   For `stt_where_value_binding *
 * stt_where_value_binding_example_simple_value_bind()`. */
#include "stt_where_value_binding_tests.h"

void
stt_where_value_binding_subnode_default_constructor_test()
{
	stt_where_value_binding_subnode * subnode_;

	subnode_ = stt_where_value_binding_subnode_default_constructor();
#ifndef NDEBUG
	assertion(subnode_ != NULL);
	assertion(subnode_->where_value_binding_ == NULL);
#endif

	stt_where_value_binding_subnode_destructor(subnode_);
}

void
stt_where_value_binding_subnode_exhaustive_constructor_test_0()
{
	stt_where_value_binding * where_value_binding_;
	stt_where_value_binding_subnode * subnode_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	where_value_binding_ =
			stt_where_value_binding_example_simple_value_bind();
#ifndef NDEBUG
	assertion(where_value_binding_ != NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
			where_value_binding_);
#endif

	subnode_ = stt_where_value_binding_subnode_exhaustive_constructor(
			where_value_binding_);
#ifndef NDEBUG
	assertion(subnode_ != NULL);
	assertion(subnode_->where_value_binding_ != NULL);
	assertion(subnode_->where_value_binding_->value_name_ != NULL);
	assertion(subnode_->where_value_binding_->value_name_->value_ != NULL);
	assertion(subnode_->where_value_binding_->value_expression_ != NULL);
	assertion(where_value_binding_->value_name_ != NULL);
	assertion(where_value_binding_->value_name_->value_ != NULL);
	assertion(where_value_binding_->value_expression_ != NULL);
	equality_ = amara_string_equality(
			subnode_->where_value_binding_->value_name_,
			where_value_binding_->value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	equality_ = stt_expression_equality(
			subnode_->where_value_binding_->value_expression_,
			where_value_binding_->value_expression_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_where_value_binding_subnode_destructor(subnode_);
	stt_where_value_binding_destructor(where_value_binding_);
}

void
stt_where_value_binding_subnode_copy_constructor_test_0()
{
	stt_where_value_binding * where_value_binding_;
	stt_where_value_binding_subnode * original_subnode_;
	stt_where_value_binding_subnode * subnode_copy_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	where_value_binding_ =
			stt_where_value_binding_example_simple_value_bind();
#ifndef NDEBUG
	assertion(where_value_binding_ != NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
			where_value_binding_);
#endif

	original_subnode_ = stt_where_value_binding_subnode_exhaustive_constructor(
			where_value_binding_);
#ifndef NDEBUG
	assertion(original_subnode_ != NULL);
	assertion(original_subnode_->where_value_binding_ != NULL);
	assertion(original_subnode_->where_value_binding_->value_name_ != NULL);
	assertion(original_subnode_->where_value_binding_->value_name_->value_ !=
			NULL);
	assertion(original_subnode_->where_value_binding_->value_expression_ !=
			NULL);
	assertion(where_value_binding_->value_name_ != NULL);
	assertion(where_value_binding_->value_name_->value_ != NULL);
	assertion(where_value_binding_->value_expression_ != NULL);
	equality_ = amara_string_equality(
			original_subnode_->where_value_binding_->value_name_,
			where_value_binding_->value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	equality_ = stt_expression_equality(
			original_subnode_->where_value_binding_->value_expression_,
			where_value_binding_->value_expression_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	subnode_copy_ = stt_where_value_binding_subnode_copy_constructor(
			original_subnode_);
#ifndef NDEBUG
	assertion(original_subnode_->where_value_binding_ != NULL);
	assertion(original_subnode_->where_value_binding_->value_name_ != NULL);
	assertion(original_subnode_->where_value_binding_->value_name_->value_ !=
			NULL);
	assertion(original_subnode_->where_value_binding_->value_expression_ !=
			NULL);
	assertion(where_value_binding_->value_name_ != NULL);
	assertion(where_value_binding_->value_name_->value_ != NULL);
	assertion(where_value_binding_->value_expression_ != NULL);
	equality_ = amara_string_equality(
			original_subnode_->where_value_binding_->value_name_,
			where_value_binding_->value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	equality_ = stt_expression_equality(
			original_subnode_->where_value_binding_->value_expression_,
			where_value_binding_->value_expression_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(subnode_copy_ != NULL);
	assertion(subnode_copy_->where_value_binding_ != NULL);
	assertion(subnode_copy_->where_value_binding_->value_name_ != NULL);
	assertion(subnode_copy_->where_value_binding_->value_name_->value_ !=
			NULL);
	assertion(subnode_copy_->where_value_binding_->value_expression_ !=
			NULL);
	assertion(where_value_binding_->value_name_ != NULL);
	assertion(where_value_binding_->value_name_->value_ != NULL);
	assertion(where_value_binding_->value_expression_ != NULL);
	equality_ = amara_string_equality(
			subnode_copy_->where_value_binding_->value_name_,
			where_value_binding_->value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	equality_ = stt_expression_equality(
			subnode_copy_->where_value_binding_->value_expression_,
			where_value_binding_->value_expression_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_where_value_binding_subnode_destructor(subnode_copy_);
	stt_where_value_binding_subnode_destructor(original_subnode_);
	stt_where_value_binding_destructor(where_value_binding_);
}

void
stt_where_value_binding_subnode_constructors_tests()
{
	stt_where_value_binding_subnode_default_constructor_test();
	stt_where_value_binding_subnode_exhaustive_constructor_test_0();
	stt_where_value_binding_subnode_copy_constructor_test_0();
}

void
stt_where_value_binding_subnode_tests()
{
	stt_where_value_binding_subnode_constructors_tests();
}
