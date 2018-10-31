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
 * src/stt/stt_named_function_subnode_tests.c: Test the Amara syntax
 * tree application named function subnode.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_named_function_subnode`. */
#include "stt_named_function_subnode.h"

#include "stt_operation_tests.h"

#include "stt_named_function_subnode_tests.h"

void
assert_expectations_on_stt_named_function_subnode_example_print_foo(
		const stt_named_function_subnode * subnode)
{
	amara_string * expected_named_function_name_;
	amara_boolean equality_;

	expected_named_function_name_ =
			amara_string_exhaustive_constructor("print_foo");
	assertion(expected_named_function_name_ != NULL);
	assertion(expected_named_function_name_->value_ != NULL);

	assertion(subnode != NULL);
	assertion(subnode->type_ ==
			STT_NAMED_FUNCTION_SUBNODE_TYPE_CLI_APP_NAMED_FUNCTION);
	assertion(subnode->name_ != NULL);
	assertion(subnode->name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_named_function_name_, subnode->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(subnode->operations_ != NULL);
	assertion(subnode->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			subnode->operations_->first);
	assertion(subnode->operations_->next == NULL);

	amara_string_destructor(expected_named_function_name_);
}

void
stt_named_function_subnode_construct_and_destruct_test_0()
{
	stt_named_function_subnode * stt_named_function_subnode_;
	stt_named_function_subnode_ =
			stt_named_function_subnode_default_constructor();
	assertion(stt_named_function_subnode_ != NULL);
	assertion(stt_named_function_subnode_->type_ ==
			STT_NAMED_FUNCTION_SUBNODE_TYPE_INVALID);
	assertion(stt_named_function_subnode_->name_ == NULL);
	assertion(stt_named_function_subnode_->operations_ == NULL);
	stt_named_function_subnode_destructor(stt_named_function_subnode_);
}

void
stt_named_function_subnode_construct_and_destruct_test_1()
{
	stt_named_function_subnode * named_function_subnode_zero_;
	stt_named_function_subnode * named_function_subnode_one_;
	named_function_subnode_zero_ =
			stt_named_function_subnode_default_constructor();
	assertion(named_function_subnode_zero_ != NULL);
	assertion(named_function_subnode_zero_->type_ ==
			STT_NAMED_FUNCTION_SUBNODE_TYPE_INVALID);
	assertion(named_function_subnode_zero_->name_ == NULL);
	assertion(named_function_subnode_zero_->operations_ == NULL);
	named_function_subnode_zero_->name_ =
			amara_string_exhaustive_constructor("foo");
	named_function_subnode_zero_->operations_ =
			stt_operations_simple_list_default_constructor();
	named_function_subnode_zero_->type_ =
			STT_NAMED_FUNCTION_SUBNODE_TYPE_CLI_APP_NAMED_FUNCTION;
	named_function_subnode_one_ = stt_named_function_subnode_copy_constructor(
			named_function_subnode_zero_);
	assertion(named_function_subnode_one_ != NULL);
	assertion(named_function_subnode_one_->type_ !=
			STT_NAMED_FUNCTION_SUBNODE_TYPE_INVALID);
	assertion(named_function_subnode_one_->name_ != NULL);
	assertion(named_function_subnode_one_->name_->value_ != NULL);
	assertion(amara_string_equality(
			named_function_subnode_one_->name_,
			amara_string_exhaustive_constructor("foo")));
	assertion(named_function_subnode_one_->operations_ != NULL);
	stt_named_function_subnode_destructor(named_function_subnode_one_);
	stt_named_function_subnode_destructor(named_function_subnode_zero_);
}

void
stt_named_function_subnode_construct_and_destruct_tests()
{
	stt_named_function_subnode_construct_and_destruct_test_0();
	stt_named_function_subnode_construct_and_destruct_test_1();
}

void
stt_named_function_subnode_tests()
{
	stt_named_function_subnode_construct_and_destruct_tests();
}
