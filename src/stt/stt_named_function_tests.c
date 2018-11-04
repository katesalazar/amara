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
 * src/stt/stt_named_function_tests.c: Test the Amara syntax tree
 * application named function.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

#include "stt_named_function_tests.h"
#include "stt_operation_tests.h"

stt_named_function *
stt_named_function_example_print_foo()
{
	stt_named_function * ret_;
	stt_operations_simple_list * operations_;
	stt_operation * operation_;
	stt_where_value_bindings_simple_list * where_value_bindings_;

	operation_ = stt_operation_example_print_foo();
#ifndef NDEBUG
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
#endif

	operations_ = stt_operations_simple_list_default_constructor();
#ifndef NDEBUG
	/* TODO missing assertions here. */
#endif

	operations_ = stt_operations_simple_list_push_front(
			operations_, operation_);
#ifndef NDEBUG
	/* TODO missing assertions here. */
#endif

	where_value_bindings_ =
			stt_where_value_bindings_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(where_value_bindings_ != NULL);
	assertion(where_value_bindings_->first == NULL);
	assertion(where_value_bindings_->next == NULL);
#endif

	ret_ = stt_named_function_exhaustive_constructor(
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION,
			amara_string_exhaustive_constructor("print_foo"),
			operations_, where_value_bindings_);
#ifndef NDEBUG
	assertion(ret_ != NULL);
	assertion(ret_->type_ == STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
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
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_named_function_example_print_foo(
		const stt_named_function * named_function)
{
	amara_string * expected_named_function_name_;
	amara_boolean equality_;

	expected_named_function_name_ =
			amara_string_exhaustive_constructor("print_foo");
	assertion(expected_named_function_name_ != NULL);
	assertion(expected_named_function_name_->value_ != NULL);

	assertion(named_function != NULL);
	assertion(named_function->type_ ==
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(named_function->name_ != NULL);
	assertion(named_function->name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_named_function_name_, named_function->name_);
	assertion(equality_ = AMARA_BOOLEAN_TRUE);
	assertion(named_function->operations_ != NULL);
	assertion(named_function->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			named_function->operations_->first);
	assertion(named_function->operations_->next == NULL);

	amara_string_destructor(expected_named_function_name_);
}

#endif

stt_named_function *
stt_named_function_example_print_bar()
{
	stt_named_function * ret_;
	stt_operations_simple_list * operations_;
	stt_operation * operation_;
	stt_where_value_bindings_simple_list * where_value_bindings_;

	operation_ = stt_operation_example_print_bar();
#ifndef NDEBUG
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
			amara_string_exhaustive_constructor("bar"));
	*/
	assertion(operation_->args_->next == NULL);
#endif

	operations_ = stt_operations_simple_list_default_constructor();
#ifndef NDEBUG
	/* TODO missing assertions here. */
#endif

	operations_ = stt_operations_simple_list_push_front(
			operations_, operation_);
#ifndef NDEBUG
	/* TODO missing assertions here. */
#endif

	where_value_bindings_ =
			stt_where_value_bindings_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(where_value_bindings_ != NULL);
	assertion(where_value_bindings_->first == NULL);
	assertion(where_value_bindings_->next == NULL);
#endif

	ret_ = stt_named_function_exhaustive_constructor(
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION,
			amara_string_exhaustive_constructor("print_bar"),
			operations_, where_value_bindings_);
#ifndef NDEBUG
	assertion(ret_ != NULL);
	assertion(ret_->type_ == STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(ret_->name_ != NULL);
	assertion(ret_->name_->value_ != NULL);
	assertion(
			amara_string_equality(
					ret_->name_,
					amara_string_exhaustive_constructor(
							"print_bar")
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
							"bar")
			) == AMARA_BOOLEAN_TRUE);
	*/
	assertion(ret_->operations_->first->args_->next == NULL);
	assertion(ret_->operations_->next == NULL);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_named_function_example_print_bar(
		const stt_named_function * named_function)
{
	amara_string * expected_named_function_name_;
	amara_boolean equality_;

	expected_named_function_name_ =
			amara_string_exhaustive_constructor("print_bar");
	assertion(expected_named_function_name_ != NULL);
	assertion(expected_named_function_name_->value_ != NULL);

	assertion(named_function != NULL);
	assertion(named_function->type_ ==
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(named_function->name_ != NULL);
	assertion(named_function->name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_named_function_name_, named_function->name_);
	assertion(equality_ = AMARA_BOOLEAN_TRUE);
	assertion(named_function->operations_ != NULL);
	assertion(named_function->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_bar(
			named_function->operations_->first);
	assertion(named_function->operations_->next == NULL);

	amara_string_destructor(expected_named_function_name_);
}

#endif

void
stt_named_function_construct_and_destruct_test_0()
{
	stt_named_function * named_function_;
	named_function_ = stt_named_function_default_constructor();
	assertion(named_function_ != NULL);
	assertion(named_function_->type_ == STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ == NULL);
	assertion(named_function_->operations_ == NULL);
	stt_named_function_destructor(named_function_);
}

void
stt_named_function_construct_and_destruct_tests()
{
	stt_named_function_construct_and_destruct_test_0();
}

void
stt_named_function_setters_test_0()
{
	stt_named_function * named_function_;
	amara_string * name_;
	amara_boolean equality_;
	stt_operations_simple_list * operations_;
	stt_operation * operation_;

	named_function_ = stt_named_function_default_constructor();
	assertion(named_function_ != NULL);
	assertion(named_function_->type_ == STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ == NULL);
	assertion(named_function_->operations_ == NULL);

	name_ = amara_string_exhaustive_constructor("print_foo");
	assertion(name_ != NULL);
	assertion(name_->value_ != NULL);

	stt_named_function_set_name(named_function_, name_);
	assertion(named_function_->type_ == STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ != NULL);
	assertion(named_function_->name_->value_ != NULL);
	assertion(named_function_->operations_ == NULL);
	assertion(name_->value_ != NULL);
	equality_ = amara_string_equality(named_function_->name_, name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	operations_ = stt_operations_simple_list_default_constructor();
	assertion(operations_ != NULL);
	assertion(operations_->first == NULL);
	assertion(operations_->next == NULL);

	operation_ = stt_operation_example_print_foo();
#ifndef NDEBUG
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(operation_);
#endif

	operations_ = stt_operations_simple_list_push_front(
			operations_, operation_);
#ifndef NDEBUG
	assertion(operations_ != NULL);
	assertion(operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			operations_->first);
	assertion(operations_->next == NULL);
	assert_expectations_on_stt_operation_example_print_foo(operation_);
#endif

	stt_named_function_set_operations(named_function_, operations_);
#ifndef NDEBUG
	assertion(named_function_->type_ == STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ != NULL);
	assertion(named_function_->name_->value_ != NULL);
	assertion(name_->value_ != NULL);
	equality_ = amara_string_equality(named_function_->name_, name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(named_function_->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			named_function_->operations_->first);
	assertion(named_function_->operations_->next == NULL);
	assertion(operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			operations_->first);
	assertion(operations_->next == NULL);
#endif

	stt_named_function_set_type(named_function_,
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
#ifndef NDEBUG
	assertion(named_function_->type_ ==
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(named_function_->name_ != NULL);
	assertion(named_function_->name_->value_ != NULL);
	assertion(name_->value_ != NULL);
	equality_ = amara_string_equality(named_function_->name_, name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(named_function_->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			named_function_->operations_->first);
	assertion(named_function_->operations_->next == NULL);
#endif

	stt_operation_destructor(operation_);
	stt_operations_simple_list_destructor(operations_);
	amara_string_destructor(name_);
	stt_named_function_destructor(named_function_);
}

void
stt_named_function_setters_tests()
{
	stt_named_function_setters_test_0();
}

void
stt_named_function_tests()
{
	stt_named_function_construct_and_destruct_tests();
	stt_named_function_setters_tests();
}
