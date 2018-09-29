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
 * src/stt/stt_operation_tests.c: Test the Amara syntax tree application
 * function operation.
 */

#include "../asr/assertion.h"
#include "stt_node.h"
#include "stt_operation_tests.h"

stt_operation *
stt_operation_example_print_foo()
{
	stt_operation * operation_;
	stt_operation_args_simple_list * operation_args_;
	stt_operation_arg * operation_arg_;
	stt_node * operation_arg_node_;
	stt_string_literal_subnode * operation_arg_node_string_literal_subnode_;
	amara_string * string_literal_;
	string_literal_ = amara_string_exhaustive_constructor("foo");
	operation_arg_node_string_literal_subnode_ =
			stt_string_literal_subnode_exhaustive_constructor(
					string_literal_);
	assertion(operation_arg_node_string_literal_subnode_ != NULL);
	operation_arg_node_ = stt_node_default_constructor();
	assertion(operation_arg_node_ != NULL);
	operation_arg_node_->string_literal_subnode_ =
			operation_arg_node_string_literal_subnode_;
	operation_arg_node_->type_ = STT_NODE_TYPE_STRING_LITERAL;
	operation_arg_ = stt_operation_arg_default_constructor();
	operation_arg_->node_ = operation_arg_node_;
	operation_arg_->type_ = STT_OPERATION_ARG_TYPE_VALID;
	operation_args_ = stt_operation_args_simple_list_default_constructor();
	operation_args_ = stt_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	operation_ = stt_operation_default_constructor();
	operation_->args_ = operation_args_;
	operation_->type_ = STT_OPERATION_TYPE_PRINT;
	return operation_;
}
