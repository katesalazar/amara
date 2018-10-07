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
 * src/rtg/rtg_named_function_tests.c: Test the Amara run time graph
 * application named function.
 */

#include "../asr/assertion.h"
#include "rtg_named_function_tests.h"
#include "rtg_operation_tests.h"
/* #include "rtg_operations_simple_list.h" */

rtg_named_function *
rtg_named_function_example_print_foo()
{
	rtg_named_function * named_function_;
	rtg_operation * operation_;
	rtg_operations_simple_list * operations_;
	operation_ = rtg_operation_example_print_foo();
	operations_ = rtg_operations_simple_list_default_constructor();
	operations_ = rtg_operations_simple_list_push_front(
			operations_, operation_);
	named_function_ = rtg_named_function_exhaustive_constructor(
			RTG_NAMED_FUNCTION_TYPE_CLI_FUNCTION,
			amara_string_exhaustive_constructor("print_foo"),
			operations_);
	assertion(named_function_ != NULL);
	assertion(named_function_->name_ != NULL);
	assertion(named_function_->name_->value_ != NULL);
	assertion(amara_string_equality(
			named_function_->name_,
			amara_string_exhaustive_constructor("print_foo")));
	assertion(named_function_->operations_ != NULL);
	assertion(named_function_->operations_->first != NULL);
	assertion(named_function_->operations_->first->type_ ==
			RTG_OPERATION_TYPE_PRINT);
	assertion(named_function_->operations_->first->args_ != NULL);
	assertion(named_function_->operations_->first->args_->first != NULL);
	assertion(named_function_->operations_->first->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(named_function_->operations_->first->args_->first->string_literal_ !=
			NULL);
	assertion(amara_string_equality(
			named_function_->operations_->first->args_->first->string_literal_,
			amara_string_exhaustive_constructor("foo")));
	assertion(named_function_->operations_->next == NULL);
	return named_function_;
}

void
rtg_named_function_construct_and_destruct_test_0()
{
	rtg_named_function * named_function_;
	named_function_ = rtg_named_function_exhaustive_constructor(
			RTG_NAMED_FUNCTION_TYPE_INVALID, NULL, NULL);
	assertion(named_function_->type_ == RTG_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ == NULL);
	assertion(named_function_->operations_ == NULL);
	rtg_named_function_destructor(named_function_);
}

void
rtg_named_function_construct_and_destruct_tests()
{
	rtg_named_function_construct_and_destruct_test_0();
}

void
rtg_named_function_tests()
{
	rtg_named_function_construct_and_destruct_tests();
}
