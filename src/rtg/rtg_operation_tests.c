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
 * src/rtg/rtg_operation_tests.c: Test the Amara runtime graph
 * application function operation.
 */

#include "../asr/assertion.h"
#include "rtg_operation_arg.h"
#include "rtg_operation_tests.h"

rtg_operation *
rtg_operation_example_print_foo()
{
	rtg_operation * operation_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	amara_string * string_literal_;
	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(operation_arg_->string_literal_ == NULL);
	string_literal_ = amara_string_exhaustive_constructor("foo");
	rtg_operation_arg_set_string_literal(operation_arg_, string_literal_);
	rtg_operation_arg_set_type(
			operation_arg_, RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	assertion(operation_args_ != NULL);
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 0);
	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 1);
	operation_ = rtg_operation_exhaustive_constructor(
			RTG_OPERATION_TYPE_PRINT,
			operation_args_);
	return operation_;
}

rtg_operation *
rtg_operation_example_print_bar()
{
	rtg_operation * operation_;
	rtg_operation_args_simple_list * operation_args_;
	rtg_operation_arg * operation_arg_;
	amara_string * string_literal_;
	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	assertion(operation_arg_->string_literal_ == NULL);
	string_literal_ = amara_string_exhaustive_constructor("bar");
	rtg_operation_arg_set_string_literal(operation_arg_, string_literal_);
	rtg_operation_arg_set_type(
			operation_arg_, RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	assertion(operation_args_ != NULL);
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 0);
	operation_args_ = rtg_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	assertion(rtg_operation_args_simple_list_length(operation_args_) == 1);
	operation_ = rtg_operation_exhaustive_constructor(
			RTG_OPERATION_TYPE_PRINT,
			operation_args_);
	return operation_;
}

void
rtg_operation_construct_and_destruct_test_0()
{
	rtg_operation * operation_;
	rtg_operation_args_simple_list * operation_args_;
	operation_args_ = rtg_operation_args_simple_list_default_constructor();
	operation_ = rtg_operation_exhaustive_constructor(
			RTG_OPERATION_TYPE_INVALID, operation_args_);
	assertion(operation_ != NULL);
	assertion(operation_->type_ == RTG_OPERATION_TYPE_INVALID);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first == NULL);
	assertion(operation_->args_->next == NULL);
	rtg_operation_destructor(operation_);
}

void
rtg_operation_construct_and_destruct_tests()
{
	rtg_operation_construct_and_destruct_test_0();
}

void
rtg_operation_tests()
{
	rtg_operation_construct_and_destruct_tests();
}
