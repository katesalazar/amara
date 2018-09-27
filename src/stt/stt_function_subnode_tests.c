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
 * src/stt/stt_function_subnode_tests.c: Test the Amara syntax tree
 * application function subnode.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_function_subnode`. */
#include "stt_function_subnode.h"

void
stt_function_subnode_construct_and_destruct_test_0()
{
	stt_function_subnode * stt_function_subnode_;
	stt_function_subnode_ = stt_function_subnode_default_constructor();
	assertion(stt_function_subnode_ != NULL);
	assertion(stt_function_subnode_->type_ ==
			STT_FUNCTION_SUBNODE_TYPE_INVALID);
	assertion(stt_function_subnode_->name_ == NULL);
	assertion(stt_function_subnode_->operations_ == NULL);
	stt_function_subnode_destructor(stt_function_subnode_);
}

void
stt_function_subnode_construct_and_destruct_test_1()
{
	stt_function_subnode * function_subnode_zero_;
	stt_function_subnode * function_subnode_one_;
	function_subnode_zero_ = stt_function_subnode_default_constructor();
	assertion(function_subnode_zero_ != NULL);
	assertion(function_subnode_zero_->type_ ==
			STT_FUNCTION_SUBNODE_TYPE_INVALID);
	assertion(function_subnode_zero_->name_ == NULL);
	assertion(function_subnode_zero_->operations_ == NULL);
	function_subnode_zero_->name_ =
			amara_string_exhaustive_constructor("foo");
	function_subnode_zero_->operations_ =
			stt_operations_simple_list_default_constructor();
	function_subnode_zero_->type_ = STT_FUNCTION_SUBNODE_TYPE_CLI_FUNCTION;
	function_subnode_one_ = stt_function_subnode_copy_constructor(
			function_subnode_zero_);
	assertion(function_subnode_one_ != NULL);
	assertion(function_subnode_one_->type_ !=
			STT_FUNCTION_SUBNODE_TYPE_INVALID);
	assertion(function_subnode_one_->name_ != NULL);
	assertion(function_subnode_one_->name_->value_ != NULL);
	assertion(amara_string_equality(
			function_subnode_one_->name_,
			amara_string_exhaustive_constructor("foo")));
	assertion(function_subnode_one_->operations_ != NULL);
	stt_function_subnode_destructor(function_subnode_one_);
	stt_function_subnode_destructor(function_subnode_zero_);
}

void
stt_function_subnode_construct_and_destruct_tests()
{
	stt_function_subnode_construct_and_destruct_test_0();
	stt_function_subnode_construct_and_destruct_test_1();
}

void
stt_function_subnode_tests()
{
	stt_function_subnode_construct_and_destruct_tests();
}
