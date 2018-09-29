/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "stt_function_tests.h"
#include "stt_operation_tests.h"

stt_function *
stt_function_example_print_foo()
{
	stt_function * ret_;
	stt_operations_simple_list * operations_;
	stt_operation * operation_;
	operation_ = stt_operation_example_print_foo();
	assertion(operation_ != NULL);
	assertion(operation_->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first != NULL);
	assertion(operation_->args_->first->type_ ==
			STT_OPERATION_ARG_TYPE_VALID);
	assertion(operation_->args_->first->node_ != NULL);
	/*
	assertion(operation_->args_->first->node_->type_ ==
			STT_NODE_TYPE_STRING_LITERAL);
	assertion(operation_->args_->first->node_->string_literal_subnode_ !=
			NULL);
	assertion(operation_->args_->first->node_->string_literal_subnode_->value_ !=
			NULL);
	assertion(amara_string_equality(
			operation_->args_->first->node_->string_literal_subnode_->value_,
			amara_string_exhaustive_constructor("foo"));
	*/
	assertion(operation_->args_->next == NULL);
	operations_ = stt_operations_simple_list_default_constructor();
	operations_ = stt_operations_simple_list_push_front(
			operations_, operation_);
	ret_ = stt_function_exhaustive_constructor(
			STT_FUNCTION_TYPE_CLI_FUNCTION,
			amara_string_exhaustive_constructor("print_foo"),
			operations_);
	assertion(ret_ != NULL);
	assertion(ret_->type_ == STT_FUNCTION_TYPE_CLI_FUNCTION);
	assertion(ret_->name_ != NULL);
	assertion(ret_->name_->value_ != NULL);
	assertion(
			amara_string_equality(
					ret_->name_,
					amara_string_exhaustive_constructor(
							"print_foo")
			) == AMARA_BOOLEAN_TRUE);
	assertion(ret_->operations_ != NULL);
	assertion(ret_->operations_->first != NULL);
	assertion(ret_->operations_->first->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(ret_->operations_->first->args_ != NULL);
	assertion(ret_->operations_->first->args_->first != NULL);
	assertion(ret_->operations_->first->args_->first->type_ ==
			STT_OPERATION_ARG_TYPE_VALID);
	/*
	assertion(
			amara_string_equality(
					ret_->operations_->first->args_->first->string_literal_,
					amara_string_exhaustive_constructor(
							"foo")
			) == AMARA_BOOLEAN_TRUE);
	*/
	assertion(ret_->operations_->first->args_->next == NULL);
	assertion(ret_->operations_->next == NULL);
	return ret_;
}

void
stt_function_construct_and_destruct_test_0()
{
	stt_function * function_;
	function_ = stt_function_default_constructor();
	assertion(function_ != NULL);
	assertion(function_->type_ == STT_FUNCTION_TYPE_INVALID);
	assertion(function_->name_ == NULL);
	assertion(function_->operations_ == NULL);
	stt_function_destructor(function_);
}

void
stt_function_construct_and_destruct_tests()
{
	stt_function_construct_and_destruct_test_0();
}

void
stt_function_tests()
{
	stt_function_construct_and_destruct_tests();
}
