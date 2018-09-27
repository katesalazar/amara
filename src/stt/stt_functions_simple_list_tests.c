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
 * src/stt/stt_functions_simple_list_tests.c: Test the Amara syntax tree
 * application functions simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_functions_simple_list`. */
/* #include "stt_functions_simple_list.h" */

#include "stt_node.h"

void
stt_functions_simple_list_construct_and_destruct_test_0()
{
	stt_functions_simple_list * list_;
	list_ = stt_functions_simple_list_default_constructor();
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
	stt_functions_simple_list_destructor(list_);
}

void
stt_functions_simple_list_construct_and_destruct_test_1()
{
	stt_functions_simple_list * list_zero_;
	stt_functions_simple_list * list_one_;
	list_zero_ = stt_functions_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);
	list_one_ = stt_functions_simple_list_copy_constructor(list_zero_);
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);
	stt_functions_simple_list_destructor(list_zero_);
	stt_functions_simple_list_destructor(list_one_);
}

void
stt_functions_simple_list_construct_and_destruct_test_2()
{
	stt_functions_simple_list * list_zero_;
	stt_functions_simple_list * list_one_;
	stt_function * function_;
	amara_string * function_name_;
	stt_operations_simple_list * operations_;
	stt_operation * operation_;
	stt_operation_args_simple_list * operation_args_;
	stt_operation_arg * operation_arg_;
	/* stt_node * operation_arg_node_; */
	list_zero_ = stt_functions_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);
	function_ = stt_function_default_constructor();
	assertion(function_ != NULL);
	assertion(function_->type_ == STT_FUNCTION_TYPE_INVALID);
	assertion(function_->name_ == NULL);
	assertion(function_->operations_ == NULL);
	function_name_ = amara_string_exhaustive_constructor("foo");
	stt_function_set_name(function_, function_name_);
	operation_arg_ = stt_operation_arg_default_constructor();
	operation_arg_->node_ = stt_node_default_constructor();
	operation_arg_->node_->natural_subnode_ =
			stt_natural_subnode_default_constructor();
	operation_arg_->node_->natural_subnode_->raw_ =
			amara_string_exhaustive_constructor("0");
	operation_arg_->node_->type_ = STT_NODE_TYPE_NATURAL_LITERAL;
	operation_arg_->type_ = STT_OPERATION_ARG_TYPE_VALID;
	operation_args_ = stt_operation_args_simple_list_default_constructor();
	operation_args_->first = operation_arg_;
	operation_ = stt_operation_default_constructor();
	operation_->type_ = STT_OPERATION_TYPE_PRINT;
	operation_->args_ = operation_args_;
	operations_ = stt_operations_simple_list_default_constructor();
	stt_operations_simple_list_push_front(operations_, operation_);
	stt_function_set_operations(function_, operations_);
	stt_function_set_type(function_, STT_FUNCTION_TYPE_CLI_FUNCTION);
	list_zero_ = stt_functions_simple_list_push_front(
			list_zero_, function_);
	assertion(list_zero_ != NULL);
	list_one_ = stt_functions_simple_list_copy_constructor(list_zero_);
	assertion(list_one_ != NULL);
	assertion(list_one_->first != NULL);
	assertion(
			amara_string_equality(
					list_one_->first->name_,
					list_zero_->first->name_) ==
							AMARA_BOOLEAN_TRUE);
	assertion(list_one_->next == NULL);
	stt_functions_simple_list_destructor(list_one_);
	stt_operations_simple_list_destructor(operations_);
	stt_operation_destructor(operation_);
	amara_string_destructor(function_name_);
	stt_function_destructor(function_);
	stt_functions_simple_list_destructor(list_zero_);
}

void
stt_functions_simple_list_construct_and_destruct_tests()
{
	stt_functions_simple_list_construct_and_destruct_test_0();
	stt_functions_simple_list_construct_and_destruct_test_1();
	stt_functions_simple_list_construct_and_destruct_test_2();
}

void
stt_functions_simple_list_tests()
{
	stt_functions_simple_list_construct_and_destruct_tests();
}
