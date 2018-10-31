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

void
assert_expectations_on_stt_operation_example_print_foo(
		const stt_operation * operation)
{
	const stt_operation_arg * operation_arg_;
	const stt_node * operation_arg_node_;
	const stt_string_literal_subnode * operation_arg_string_literal_subnode_;
	amara_string * expected_string_literal_;
	amara_boolean equality_;

	expected_string_literal_ = amara_string_exhaustive_constructor("foo");
	assertion(expected_string_literal_ != NULL);
	assertion(expected_string_literal_->value_ != NULL);

	assertion(operation != NULL);
	assertion(operation->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(operation->args_ != NULL);
	assertion(operation->args_->first != NULL);
	operation_arg_ = operation->args_->first;
	assertion(operation_arg_->type_ == STT_OPERATION_ARG_TYPE_VALID);
	assertion(operation_arg_->node_ != NULL);
	operation_arg_node_ = operation_arg_->node_;
	assertion(operation_arg_node_->type_ == STT_NODE_TYPE_STRING_LITERAL);
	assertion(operation_arg_node_->string_literal_subnode_ != NULL);
	operation_arg_string_literal_subnode_ =
			operation_arg_node_->string_literal_subnode_;
	assertion(operation_arg_string_literal_subnode_->string_literal_ !=
			NULL);
	assertion(operation_arg_string_literal_subnode_->string_literal_->value_ !=
			NULL);
	equality_ = amara_string_equality(
			expected_string_literal_,
			operation_arg_string_literal_subnode_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(operation->args_->next == NULL);

	amara_string_destructor(expected_string_literal_);
}

stt_operation *
stt_operation_example_print_bar()
{
	stt_operation * operation_;
	stt_operation_args_simple_list * operation_args_;
	stt_operation_arg * operation_arg_;
	stt_node * operation_arg_node_;
	stt_string_literal_subnode * operation_arg_node_string_literal_subnode_;
	amara_string * string_literal_;
	string_literal_ = amara_string_exhaustive_constructor("bar");
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

void
assert_expectations_on_stt_operation_example_print_bar(
		const stt_operation * operation)
{
	const stt_operation_arg * operation_arg_;
	const stt_node * operation_arg_node_;
	const stt_string_literal_subnode * operation_arg_string_literal_subnode_;
	amara_string * expected_string_literal_;
	amara_boolean equality_;

	expected_string_literal_ = amara_string_exhaustive_constructor("bar");
	assertion(expected_string_literal_ != NULL);
	assertion(expected_string_literal_->value_ != NULL);

	assertion(operation != NULL);
	assertion(operation->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(operation->args_ != NULL);
	assertion(operation->args_->first != NULL);
	operation_arg_ = operation->args_->first;
	assertion(operation_arg_->type_ == STT_OPERATION_ARG_TYPE_VALID);
	assertion(operation_arg_->node_ != NULL);
	operation_arg_node_ = operation_arg_->node_;
	assertion(operation_arg_node_->type_ == STT_NODE_TYPE_STRING_LITERAL);
	assertion(operation_arg_node_->string_literal_subnode_ != NULL);
	operation_arg_string_literal_subnode_ =
			operation_arg_node_->string_literal_subnode_;
	assertion(operation_arg_string_literal_subnode_->string_literal_ !=
			NULL);
	assertion(operation_arg_string_literal_subnode_->string_literal_->value_ !=
			NULL);
	equality_ = amara_string_equality(
			expected_string_literal_,
			operation_arg_string_literal_subnode_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(operation->args_->next == NULL);

	amara_string_destructor(expected_string_literal_);
}

stt_operation *
stt_operation_example_print_foo_no_crlf()
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
	operation_->type_ = STT_OPERATION_TYPE_PRINT_NO_CRLF;
	return operation_;
}

void
stt_operation_construct_and_destruct_test_0()
{
	stt_operation * operation_;

	operation_ = stt_operation_default_constructor();
	assertion(operation_ != NULL);
	assertion(operation_->type_ == STT_OPERATION_TYPE_INVALID);
	assertion(operation_->args_ == NULL);

	stt_operation_destructor(operation_);
}

void
stt_operation_construct_and_destruct_test_1()
{
	stt_operation * operation_;
	amara_string * expected_string_;
	amara_boolean equality_;

	expected_string_ = amara_string_exhaustive_constructor("foo");
	assertion(expected_string_ != NULL);
	assertion(expected_string_->value_ != NULL);

	operation_ = stt_operation_example_print_foo_no_crlf();
	assertion(operation_ != NULL);
	assertion(operation_->type_ == STT_OPERATION_TYPE_PRINT_NO_CRLF);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first != NULL);
	assertion(operation_->args_->first->type_ ==
			STT_OPERATION_ARG_TYPE_VALID);
	assertion(operation_->args_->first->node_ != NULL);
	assertion(operation_->args_->first->node_->type_ ==
			STT_NODE_TYPE_STRING_LITERAL);
	assertion(operation_->args_->first->node_->string_literal_subnode_ !=
			NULL);
	assertion(operation_->args_->first->node_->string_literal_subnode_->string_literal_ !=
			NULL);
	assertion(operation_->args_->first->node_->string_literal_subnode_->string_literal_->value_ !=
			NULL);
	equality_ = amara_string_equality(
			expected_string_,
			operation_->args_->first->node_->string_literal_subnode_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(operation_->args_->next == NULL);

	stt_operation_destructor(operation_);
}

void
stt_operation_construct_and_destruct_tests()
{
	stt_operation_construct_and_destruct_test_0();
	stt_operation_construct_and_destruct_test_1();
}

void
stt_operation_tests()
{
	stt_operation_construct_and_destruct_tests();
}
