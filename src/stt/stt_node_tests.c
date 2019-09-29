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
 * src/stt/stt_node_tests.c: Test the Amara syntax tree node.
 */

#include "../asr/assertion.h"

#include "stt_application_subnode_tests.h"

#include "stt_application_tests.h"

/*   For `stt_condition * stt_condition_example_simple_condition()`. */
#include "stt_condition_tests.h"

/*   For `stt_dice_expression *
 * stt_dice_expression_example_single_vanilla_dice()`. */
#include "stt_dice_expression_tests.h"

#include "stt_doc_subnode_tests.h"

#include "stt_execution_request_tests.h"

#include "stt_execution_request_subnode_tests.h"

/*   For `void
 * assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice()`. */
#include "stt_expression_sub_dice_tests.h"

/*   For `stt_expression * stt_expression_example_natural_zero()`. */
#include "stt_expression_tests.h"

#include "stt_named_function_subnode_tests.h"

#include "stt_named_function_tests.h"

#include "stt_node.h"

/*   For `stt_operation * stt_operation_example_print_foo()`. */
#include "stt_operation_tests.h"

/*   For `stt_operations_simple_list *
 * stt_operations_simple_list_example_print_foo()`. */
#include "stt_operations_simple_list_tests.h"

#include "stt_node_tests.h"

/*   For `stt_where_value_binding *
 * stt_where_value_binding_example_simple_value_bind()`. */
#include "stt_where_value_binding_tests.h"

/*   For `stt_where_value_bindings_simple_list *
 * stt_where_value_bindings_simple_list_example_simple_value_bind()`. */
#include "stt_where_value_bindings_simple_list_tests.h"

stt_node *
stt_node_example_natural_literal_zero(void)
{
	stt_node * ret_;
	amara_string * raw_natural_literal_;

	ret_ = stt_node_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	raw_natural_literal_ = amara_string_exhaustive_constructor("0");
	forced_assertion(raw_natural_literal_ != NULL);
#ifndef NDEBUG
	assertion(raw_natural_literal_->value_ != NULL);
	assertion(raw_natural_literal_->value_[0] == '0');
	assertion(raw_natural_literal_->value_[1] == '\0');
#endif

	stt_node_set_natural_literal(ret_, raw_natural_literal_);
#ifndef NDEBUG
	assertion(raw_natural_literal_->value_ != NULL);
	assertion(raw_natural_literal_->value_[0] == '0');
	assertion(raw_natural_literal_->value_[1] == '\0');
	assertion(ret_->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
#endif
	forced_assertion(ret_->natural_literal_subnode_ != NULL);
	forced_assertion(ret_->natural_literal_subnode_->raw_ != NULL);
	forced_assertion(ret_->natural_literal_subnode_->raw_->value_ != NULL);
#ifndef NDEBUG
	assertion(ret_->natural_literal_subnode_->raw_->value_[0] == '0');
	assertion(ret_->natural_literal_subnode_->raw_->value_[1] == '\0');
#endif

	amara_string_destructor(raw_natural_literal_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_natural_literal_zero(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(node->natural_literal_subnode_ != NULL);
	assertion(node->natural_literal_subnode_->raw_ != NULL);
	assertion(node->natural_literal_subnode_->raw_->value_ != NULL);
	assertion(node->natural_literal_subnode_->raw_->value_[0] == '0');
	assertion(node->natural_literal_subnode_->raw_->value_[1] == '\0');
}

#endif

stt_node *
stt_node_example_natural_literal_one(void)
{
	stt_node * ret_;
	amara_string * raw_natural_literal_;

	ret_ = stt_node_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	raw_natural_literal_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_literal_ != NULL);
#ifndef NDEBUG
	assertion(raw_natural_literal_->value_ != NULL);
	assertion(raw_natural_literal_->value_[0] == '1');
	assertion(raw_natural_literal_->value_[1] == '\0');
#endif

	stt_node_set_natural_literal(ret_, raw_natural_literal_);
#ifndef NDEBUG
	assertion(raw_natural_literal_->value_ != NULL);
	assertion(raw_natural_literal_->value_[0] == '1');
	assertion(raw_natural_literal_->value_[1] == '\0');
	assertion(ret_->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
#endif
	forced_assertion(ret_->natural_literal_subnode_ != NULL);
	forced_assertion(ret_->natural_literal_subnode_->raw_ != NULL);
	forced_assertion(ret_->natural_literal_subnode_->raw_->value_ != NULL);
#ifndef NDEBUG
	assertion(ret_->natural_literal_subnode_->raw_->value_[0] == '1');
	assertion(ret_->natural_literal_subnode_->raw_->value_[1] == '\0');
#endif

	amara_string_destructor(raw_natural_literal_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_natural_literal_one(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(node->natural_literal_subnode_ != NULL);
	assertion(node->natural_literal_subnode_->raw_ != NULL);
	assertion(node->natural_literal_subnode_->raw_->value_ != NULL);
	assertion(node->natural_literal_subnode_->raw_->value_[0] == '1');
	assertion(node->natural_literal_subnode_->raw_->value_[1] == '\0');
}

#endif

stt_node *
stt_node_example_expression_natural_literal_zero()
{
	stt_node * natural_literal_node_;
	natural * natural_;
	stt_expression * expression_;
	stt_node * returning_;

	natural_literal_node_ = stt_node_example_natural_literal_zero();
	forced_assertion(natural_literal_node_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_natural_literal_zero(
			natural_literal_node_);
#endif

	natural_ = natural_exhaustive_constructor(
			natural_literal_node_->natural_literal_subnode_->raw_);
	forced_assertion(natural_ != NULL);
#ifndef NDEBUG
	assertion(natural_->raw_ != NULL);
	assertion(natural_->raw_->value_ != NULL);
	assertion(natural_->raw_->value_[0] == '0');
	assertion(natural_->raw_->value_[1] == '\0');
#endif

	stt_node_destructor(natural_literal_node_);

	expression_ = stt_expression_default_constructor();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_natural_literal(expression_, natural_);
#ifndef NDEBUG
	assertion(natural_->raw_ != NULL);
	assertion(natural_->raw_->value_ != NULL);
	assertion(natural_->raw_->value_[0] == '0');
	assertion(natural_->raw_->value_[1] == '\0');
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(expression_->sub_natural_literal_ != NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_ != NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_->value_[0] ==
			'0');
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_->value_[1] ==
			'\0');
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_);
#endif

	natural_destructor(natural_);

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_expression(returning_, expression_);
#ifndef NDEBUG
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(expression_->sub_natural_literal_ != NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_ != NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_->value_[0] ==
			'0');
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_->value_[1] ==
			'\0');
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_);
	assertion(returning_->type_ == STT_NODE_TYPE_EXPRESSION);
	assertion(returning_->expression_subnode_ != NULL);
	assertion(returning_->expression_subnode_->expression_ != NULL);
	assertion(returning_->expression_subnode_->expression_->type_ ==
			STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assert_expectations_on_stt_expression_example_natural_zero(
			returning_->expression_subnode_->expression_);
#endif

	stt_expression_destructor(expression_);

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_expression_natural_literal_zero(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_EXPRESSION);
	assertion(node->expression_subnode_ != NULL);
	assertion(node->expression_subnode_->expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			node->expression_subnode_->expression_);
}

#endif

stt_node *
stt_node_example_expression_natural_literal_one()
{
	stt_node * natural_literal_node_;
	natural * natural_;
	stt_expression * expression_;
	stt_node * returning_;

	natural_literal_node_ = stt_node_example_natural_literal_one();
	forced_assertion(natural_literal_node_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_natural_literal_one(
			natural_literal_node_);
#endif

	natural_ = natural_exhaustive_constructor(
			natural_literal_node_->natural_literal_subnode_->raw_);
	forced_assertion(natural_ != NULL);
#ifndef NDEBUG
	assertion(natural_->raw_ != NULL);
	assertion(natural_->raw_->value_ != NULL);
	assertion(natural_->raw_->value_[0] == '1');
	assertion(natural_->raw_->value_[1] == '\0');
#endif

	stt_node_destructor(natural_literal_node_);

	expression_ = stt_expression_default_constructor();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_natural_literal(expression_, natural_);
#ifndef NDEBUG
	assertion(natural_->raw_ != NULL);
	assertion(natural_->raw_->value_ != NULL);
	assertion(natural_->raw_->value_[0] == '1');
	assertion(natural_->raw_->value_[1] == '\0');
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(expression_->sub_natural_literal_ != NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_ != NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_->value_[0] ==
			'1');
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_->value_[1] ==
			'\0');
	assert_expectations_on_stt_expression_example_natural_one(
			expression_);
#endif

	natural_destructor(natural_);

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_expression(returning_, expression_);
#ifndef NDEBUG
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(expression_->sub_natural_literal_ != NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_ != NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_->value_[0] ==
			'1');
	assertion(expression_->sub_natural_literal_->natural_literal_->raw_->value_[1] ==
			'\0');
	assert_expectations_on_stt_expression_example_natural_one(
			expression_);
	assertion(returning_->type_ == STT_NODE_TYPE_EXPRESSION);
	assertion(returning_->expression_subnode_ != NULL);
	assertion(returning_->expression_subnode_->expression_ != NULL);
	assertion(returning_->expression_subnode_->expression_->type_ ==
			STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assert_expectations_on_stt_expression_example_natural_one(
			returning_->expression_subnode_->expression_);
#endif

	stt_expression_destructor(expression_);

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_expression_natural_literal_one(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_EXPRESSION);
	assertion(node->expression_subnode_ != NULL);
	assertion(node->expression_subnode_->expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_one(
			node->expression_subnode_->expression_);
}

#endif

stt_node *
stt_node_example_operation_print_string_literal_foo()
{
	stt_node * ret_;
	stt_operation * operation_;

	ret_ = stt_node_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	operation_ = stt_operation_example_print_string_literal_foo();
	forced_assertion(operation_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operation_);
#endif

	stt_node_set_operation(ret_, operation_);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(ret_->operation_subnode_ != NULL);
	assertion(ret_->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			ret_->operation_subnode_->operation_);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operation_);
#endif

	stt_operation_destructor(operation_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_operation_print_string_literal_foo(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node->operation_subnode_ != NULL);
	assertion(node->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			node->operation_subnode_->operation_);
}

#endif

/*

stt_node *
stt_node_example_operation_print_bar()
{
	stt_node * ret_;
	stt_operation * operation_;

	ret_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(ret_ != NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	operation_ = stt_operation_example_print_bar();
#ifndef NDEBUG
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_bar(operation_);
#endif

	stt_node_set_operation(ret_, operation_);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(ret_->operation_subnode_ != NULL);
	assertion(ret_->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_bar(
			ret_->operation_subnode_->operation_);
	assert_expectations_on_stt_operation_example_print_bar(operation_);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_operation_print_bar(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node->operation_subnode_ != NULL);
	assertion(node->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_bar(
			node->operation_subnode_->operation_);
}

#endif

*/

stt_node *
stt_node_example_operations_list_print_string_literal_foo_and_then_print_string_literal_bar()
{
	stt_node * ret_;
	stt_operation * operation_zero_;
	stt_operation * operation_one_;
	stt_operations_simple_list * operations_;

	ret_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(ret_ != NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	operation_zero_ = stt_operation_example_print_string_literal_bar();
#ifndef NDEBUG
	assertion(operation_zero_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_bar(
			operation_zero_);
#endif

	operation_one_ = stt_operation_example_print_string_literal_foo();
#ifndef NDEBUG
	assertion(operation_one_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operation_one_);
#endif

	operations_ = stt_operations_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(operations_ != NULL);
	assertion(operations_->first == NULL);
	assertion(operations_->next == NULL);
#endif

	operations_ = stt_operations_simple_list_push_front(
			operations_, operation_zero_);
#ifndef NDEBUG
	assertion(operations_ != NULL);
	assertion(operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_bar(
			operations_->first);
	assertion(operations_->next == NULL);
#endif

	stt_operation_destructor(operation_zero_);

	operations_ = stt_operations_simple_list_push_front(
			operations_, operation_one_);
#ifndef NDEBUG
	assertion(operations_ != NULL);
	assertion(operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operations_->first);
	assertion(operations_->next != NULL);
	assertion(operations_->next->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_bar(
			operations_->next->first);
	assertion(operations_->next->next == NULL);
#endif

	stt_operation_destructor(operation_one_);

	stt_node_set_operations_list(ret_, operations_);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(ret_->operations_list_subnode_ != NULL);
	assertion(ret_->operations_list_subnode_->operations_ != NULL);
	assertion(ret_->operations_list_subnode_->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			ret_->operations_list_subnode_->operations_->first);
	assertion(ret_->operations_list_subnode_->operations_->next != NULL);
	assertion(ret_->operations_list_subnode_->operations_->next->first !=
			NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_bar(
			ret_->operations_list_subnode_->operations_->next->first);
	assertion(ret_->operations_list_subnode_->operations_->next->next ==
			NULL);
#endif

	stt_operations_simple_list_destructor(operations_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_operations_list_print_string_literal_foo_and_then_print_string_literal_bar(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(node->operations_list_subnode_ != NULL);
	assertion(node->operations_list_subnode_->operations_ != NULL);
	assertion(node->operations_list_subnode_->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			node->operations_list_subnode_->operations_->first);
	assertion(node->operations_list_subnode_->operations_->next != NULL);
	assertion(node->operations_list_subnode_->operations_->next->first !=
			NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_bar(
			node->operations_list_subnode_->operations_->next->first);
	assertion(node->operations_list_subnode_->operations_->next->next ==
			NULL);
}

#endif

stt_node *
stt_node_example_named_function_print_string_literal_foo()
{
	stt_node * ret_;
	stt_named_function * named_function_;

	ret_ = stt_node_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	named_function_ = stt_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	stt_node_set_named_function(ret_, named_function_);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(ret_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
			ret_->named_function_subnode_);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	stt_named_function_destructor(named_function_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_named_function_print_string_literal_foo(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
			node->named_function_subnode_);
}

#endif

stt_node *
stt_node_example_application_print_string_literal_foo()
{
	stt_node * ret_;
	stt_application * application_;

	ret_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(ret_ != NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	application_ = stt_application_example_print_foo();
#ifndef NDEBUG
	assertion(application_ != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			application_);
#endif

	stt_node_set_application(ret_, application_);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(ret_->application_subnode_ != NULL);
	assert_expectations_on_stt_application_subnode_example_print_foo(
			ret_->application_subnode_);
	assert_expectations_on_stt_application_example_print_foo(
			application_);
#endif

	stt_application_destructor(application_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_application_print_string_literal_foo(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node->application_subnode_ != NULL);
	assert_expectations_on_stt_application_subnode_example_print_foo(
			node->application_subnode_);
}

#endif

stt_node *
stt_node_example_execution_request()
{
	stt_execution_request * execution_request_;
	stt_node * ret_;

	execution_request_ = stt_execution_request_example_print_foo();
	forced_assertion(execution_request_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_);
#endif

	ret_ = stt_node_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_execution_request(ret_, execution_request_);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_);
	assertion(ret_->type_ == STT_NODE_TYPE_EXECUTION_REQUEST);
	assert_expectations_on_stt_execution_request_subnode_example_print_foo(
			ret_->execution_request_subnode_);
#endif

	stt_execution_request_destructor(execution_request_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_execution_request(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_EXECUTION_REQUEST);
	assertion(node->execution_request_subnode_ != NULL);
	assert_expectations_on_stt_execution_request_subnode_example_print_foo(
			node->execution_request_subnode_);
}

#endif

stt_node *
stt_node_example_doc_zero()
{
	stt_named_function * named_function_;
	stt_named_functions_simple_list * named_functions_;
	stt_applications_simple_list * applications_;
	stt_execution_requests_simple_list * execution_requests_;
	stt_node * ret_;

	named_function_ = stt_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	named_functions_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(named_functions_ != NULL);
#ifndef NDEBUG
	assertion(named_functions_->first == NULL);
	assertion(named_functions_->next == NULL);
#endif

	named_functions_ = stt_named_functions_simple_list_push_front(
			named_functions_, named_function_);
#ifndef NDEBUG
	assertion(named_functions_ != NULL);
	assertion(named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_functions_->first);
	assertion(named_functions_->next == NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	stt_named_function_destructor(named_function_);

	applications_ = NULL;

	execution_requests_ = NULL;

	ret_ = stt_node_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_doc(ret_, named_functions_, applications_,
	                 execution_requests_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_functions_->first);
	assertion(named_functions_->next == NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_DOC);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			ret_->doc_subnode_->named_functions_->first);
	assertion(ret_->doc_subnode_->named_functions_->next == NULL);
#endif

	stt_named_functions_simple_list_destructor(named_functions_);

#ifndef NDEBUG
	assert_expectations_on_stt_node_example_doc_zero(ret_);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_zero(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_DOC);
	assertion(node->doc_subnode_ != NULL);
	assertion(node->doc_subnode_->named_functions_ != NULL);
	assertion(node->doc_subnode_->named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			node->doc_subnode_->named_functions_->first);
	assertion(node->doc_subnode_->named_functions_->next == NULL);
	assertion(node->doc_subnode_->applications_ != NULL);
	assertion(node->doc_subnode_->applications_->first == NULL);
	/*
	assert_expectations_on_stt_application_example_print_string_literal_foo(
			node->doc_subnode_->applications_->first);
	*/
	assertion(node->doc_subnode_->applications_->next == NULL);
	assertion(node->doc_subnode_->execution_requests_ != NULL);
	assertion(node->doc_subnode_->execution_requests_->first == NULL);
	/*
	assert_expectations_on_stt_execution_request_example_print_string_literal_foo(
			node->doc_subnode_->execution_requests_->first);
	*/
	assertion(node->doc_subnode_->execution_requests_->next == NULL);
}

#endif

stt_node *
stt_node_example_doc_one()
{
	stt_named_function * named_function_;
	stt_named_functions_simple_list * named_functions_;
	stt_application * application_;
	stt_applications_simple_list * applications_;
	stt_execution_requests_simple_list * execution_requests_;
	stt_node * ret_;

	named_function_ = stt_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	named_functions_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(named_functions_ != NULL);
#ifndef NDEBUG
	assertion(named_functions_->first == NULL);
	assertion(named_functions_->next == NULL);
#endif

	named_functions_ = stt_named_functions_simple_list_push_front(
			named_functions_, named_function_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif
	forced_assertion(named_functions_ != NULL);
#ifndef NDEBUG
	assertion(named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_functions_->first);
	assertion(named_functions_->next == NULL);
#endif

	stt_named_function_destructor(named_function_);

	application_ = stt_application_example_print_foo();
	forced_assertion(application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_);
#endif

	applications_ = stt_applications_simple_list_default_constructor();
	forced_assertion(applications_ != NULL);
#ifndef NDEBUG
	assertion(applications_->first == NULL);
	assertion(applications_->next == NULL);
#endif

	applications_ = stt_applications_simple_list_push_front(
			applications_, application_);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_);
#endif
	forced_assertion(applications_ != NULL);
#ifndef NDEBUG
	assertion(applications_->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			applications_->first);
	assertion(applications_->next == NULL);
#endif

	stt_application_destructor(application_);

	execution_requests_ = NULL;

	ret_ = stt_node_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_doc(ret_, named_functions_, applications_,
	                 execution_requests_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_functions_->first);
	assertion(named_functions_->next == NULL);
	assert_expectations_on_stt_application_example_print_foo(
			applications_->first);
	assertion(applications_->next == NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_DOC);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			ret_->doc_subnode_->named_functions_->first);
	assertion(ret_->doc_subnode_->named_functions_->next == NULL);
	assert_expectations_on_stt_application_example_print_foo(
			ret_->doc_subnode_->applications_->first);
	assertion(ret_->doc_subnode_->applications_->next == NULL);
#endif

	stt_named_functions_simple_list_destructor(named_functions_);
	stt_applications_simple_list_destructor(applications_);

#ifndef NDEBUG
	assert_expectations_on_stt_node_example_doc_one(ret_);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_one(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_DOC);
	assertion(node->doc_subnode_ != NULL);
	assertion(node->doc_subnode_->named_functions_ != NULL);
	assertion(node->doc_subnode_->named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			node->doc_subnode_->named_functions_->first);
	assertion(node->doc_subnode_->named_functions_->next == NULL);
	assertion(node->doc_subnode_->applications_ != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			node->doc_subnode_->applications_->first);
	assertion(node->doc_subnode_->applications_->next == NULL);
	assertion(node->doc_subnode_->execution_requests_ != NULL);
	assertion(node->doc_subnode_->execution_requests_->first == NULL);
	/*
	assert_expectations_on_stt_execution_request_example_print_foo(
			node->doc_subnode_->execution_requests_->first);
	*/
	assertion(node->doc_subnode_->execution_requests_->next == NULL);
}

#endif

stt_node *
stt_node_example_doc_two()
{
	stt_named_functions_simple_list * named_functions_;
	stt_application * application_;
	stt_applications_simple_list * applications_;
	stt_execution_requests_simple_list * execution_requests_;
	stt_node * ret_;

	named_functions_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(named_functions_ != NULL);
#ifndef NDEBUG
	assertion(named_functions_->first == NULL);
	assertion(named_functions_->next == NULL);
#endif

	application_ = stt_application_example_print_foo();
	forced_assertion(application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_);
#endif

	applications_ = stt_applications_simple_list_default_constructor();
	forced_assertion(applications_ != NULL);
#ifndef NDEBUG
	assertion(applications_->first == NULL);
	assertion(applications_->next == NULL);
#endif

	applications_ = stt_applications_simple_list_push_front(
			applications_, application_);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_);
#endif
	forced_assertion(applications_ != NULL);
#ifndef NDEBUG
	assertion(applications_->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			applications_->first);
	assertion(applications_->next == NULL);
#endif

	stt_application_destructor(application_);

	execution_requests_ = NULL;

	ret_ = stt_node_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_doc(ret_, named_functions_, applications_,
	                 execution_requests_);
#ifndef NDEBUG
	assertion(named_functions_->first == NULL);
	assertion(named_functions_->next == NULL);
	assert_expectations_on_stt_application_example_print_foo(
			applications_->first);
	assertion(applications_->next == NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_DOC);
	assertion(ret_->doc_subnode_->named_functions_->first == NULL);
	assertion(ret_->doc_subnode_->named_functions_->next == NULL);
	assert_expectations_on_stt_application_example_print_foo(
			ret_->doc_subnode_->applications_->first);
	assertion(ret_->doc_subnode_->applications_->next == NULL);
#endif

	stt_named_functions_simple_list_destructor(named_functions_);

	stt_applications_simple_list_destructor(applications_);

#ifndef NDEBUG
	assert_expectations_on_stt_node_example_doc_two(ret_);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_two(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_DOC);
	assertion(node->doc_subnode_ != NULL);
	assertion(node->doc_subnode_->named_functions_ != NULL);
	assertion(node->doc_subnode_->named_functions_->first == NULL);
	assertion(node->doc_subnode_->named_functions_->next == NULL);
	assertion(node->doc_subnode_->applications_ != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			node->doc_subnode_->applications_->first);
	assertion(node->doc_subnode_->applications_->next == NULL);
	assertion(node->doc_subnode_->execution_requests_ != NULL);
	assertion(node->doc_subnode_->execution_requests_->first == NULL);
	/*
	assert_expectations_on_stt_execution_request_example_print_foo(
			node->doc_subnode_->execution_requests_->first);
	*/
	assertion(node->doc_subnode_->execution_requests_->next == NULL);
}

#endif

stt_node *
stt_node_example_doc_three()
{
	stt_named_function * named_function_foo_;
	stt_named_function * named_function_bar_;
	stt_named_functions_simple_list * named_functions_;
	stt_application * application_baz_;
	stt_applications_simple_list * applications_;
	stt_execution_requests_simple_list * execution_requests_;
	stt_node * ret_;

	named_function_foo_ = stt_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_foo_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_foo_);
#endif

	named_function_bar_ = stt_named_function_example_print_string_literal_bar();
	forced_assertion(named_function_bar_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			named_function_bar_);
#endif

	named_functions_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(named_functions_ != NULL);
#ifndef NDEBUG
	assertion(named_functions_->first == NULL);
	assertion(named_functions_->next == NULL);
#endif

	named_functions_ = stt_named_functions_simple_list_push_front(
			named_functions_, named_function_foo_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_foo_);
	assertion(named_functions_ != NULL);
	assertion(named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_functions_->first);
	assertion(named_functions_->next == NULL);
#endif

	stt_named_function_destructor(named_function_foo_);

	named_functions_ = stt_named_functions_simple_list_push_front(
			named_functions_, named_function_bar_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			named_function_bar_);
	assertion(named_functions_ != NULL);
	assertion(named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			named_functions_->first);
	assertion(named_functions_->next != NULL);
	assertion(named_functions_->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_functions_->next->first);
	assertion(named_functions_->next->next == NULL);
#endif

	stt_named_function_destructor(named_function_bar_);

	application_baz_ = stt_application_example_print_baz();
	forced_assertion(application_baz_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_baz(
			application_baz_);
#endif

	applications_ = stt_applications_simple_list_default_constructor();
	forced_assertion(applications_ != NULL);
#ifndef NDEBUG
	assertion(applications_->first == NULL);
	assertion(applications_->next == NULL);
#endif

	applications_ = stt_applications_simple_list_push_front(
			applications_, application_baz_);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_baz(
			application_baz_);
	assertion(applications_ != NULL);
	assertion(applications_->first != NULL);
	assert_expectations_on_stt_application_example_print_baz(
			applications_->first);
	assertion(applications_->next == NULL);
#endif

	stt_application_destructor(application_baz_);

	execution_requests_ = NULL;

	ret_ = stt_node_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_doc(ret_, named_functions_, applications_,
	                 execution_requests_);
#ifndef NDEBUG
	assertion(named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			named_functions_->first);
	assertion(named_functions_->next != NULL);
	assertion(named_functions_->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_functions_->next->first);
	assertion(named_functions_->next->next == NULL);
	assert_expectations_on_stt_application_example_print_baz(
			applications_->first);
	assertion(applications_->next == NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_DOC);
#endif
	forced_assertion(ret_->doc_subnode_->named_functions_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			ret_->doc_subnode_->named_functions_->first);
#endif
	forced_assertion(ret_->doc_subnode_->named_functions_->next != NULL);
	forced_assertion(ret_->doc_subnode_->named_functions_->next->first !=
			NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			ret_->doc_subnode_->named_functions_->next->first);
	assertion(ret_->doc_subnode_->named_functions_->next->next == NULL);
	assert_expectations_on_stt_application_example_print_baz(
			ret_->doc_subnode_->applications_->first);
	assertion(ret_->doc_subnode_->applications_->next == NULL);
#endif

	stt_named_functions_simple_list_destructor(named_functions_);
	stt_applications_simple_list_destructor(applications_);

#ifndef NDEBUG
	assert_expectations_on_stt_node_example_doc_three(ret_);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_three(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_DOC);
	assertion(node->doc_subnode_ != NULL);
	assertion(node->doc_subnode_->named_functions_ != NULL);
	assertion(node->doc_subnode_->named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			node->doc_subnode_->named_functions_->first);
	assertion(node->doc_subnode_->named_functions_->next != NULL);
	assertion(node->doc_subnode_->named_functions_->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			node->doc_subnode_->named_functions_->next->first);
	assertion(node->doc_subnode_->named_functions_->next->next == NULL);
	assertion(node->doc_subnode_->applications_ != NULL);
	assert_expectations_on_stt_application_example_print_baz(
			node->doc_subnode_->applications_->first);
	assertion(node->doc_subnode_->applications_->next == NULL);
	assertion(node->doc_subnode_->execution_requests_ != NULL);
	assertion(node->doc_subnode_->execution_requests_->first == NULL);
	/*
	assert_expectations_on_stt_execution_request_example_print_foo(
			node->doc_subnode_->execution_requests_->first);
	*/
	assertion(node->doc_subnode_->execution_requests_->next == NULL);
}

#endif

stt_node *
stt_node_example_doc_four()
{
	stt_named_functions_simple_list * named_functions_;
	stt_applications_simple_list * applications_;
	stt_execution_request * execution_request_foo_;
	stt_execution_requests_simple_list * execution_requests_;
	stt_node * ret_;

	named_functions_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(named_functions_ != NULL);
#ifndef NDEBUG
	assertion(named_functions_->first == NULL);
	assertion(named_functions_->next == NULL);
#endif

	applications_ = stt_applications_simple_list_default_constructor();
	forced_assertion(applications_ != NULL);
#ifndef NDEBUG
	assertion(applications_->first == NULL);
	assertion(applications_->next == NULL);
#endif

	execution_request_foo_ = stt_execution_request_example_print_foo();
	forced_assertion(execution_request_foo_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_foo_);
#endif

	execution_requests_ =
			stt_execution_requests_simple_list_default_constructor();
	forced_assertion(execution_requests_ != NULL);
#ifndef NDEBUG
	assertion(execution_requests_->first == NULL);
	assertion(execution_requests_->next == NULL);
#endif

	execution_requests_ = stt_execution_requests_simple_list_push_front(
			execution_requests_, execution_request_foo_);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_foo_);
	assertion(execution_requests_ != NULL);
#endif
	forced_assertion(execution_requests_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_requests_->first);
	assertion(execution_requests_->next == NULL);
#endif

	stt_execution_request_destructor(execution_request_foo_);

	ret_ = stt_node_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_doc(ret_, named_functions_, applications_,
	                 execution_requests_);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_requests_->first);
	assertion(execution_requests_->next == NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_DOC);
#endif
	forced_assertion(ret_->doc_subnode_ != NULL);
	forced_assertion(ret_->doc_subnode_->execution_requests_ != NULL);
	forced_assertion(ret_->doc_subnode_->execution_requests_->first !=
			NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			ret_->doc_subnode_->execution_requests_->first);
	assertion(ret_->doc_subnode_->execution_requests_->next == NULL);
#endif

	stt_named_functions_simple_list_destructor(named_functions_);

	stt_applications_simple_list_destructor(applications_);

	stt_execution_requests_simple_list_destructor(execution_requests_);

#ifndef NDEBUG
	assert_expectations_on_stt_node_example_doc_four(ret_);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_four(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_DOC);
	assertion(node->doc_subnode_ != NULL);
	assertion(node->doc_subnode_->named_functions_ != NULL);
	assertion(node->doc_subnode_->named_functions_->first == NULL);
	assertion(node->doc_subnode_->named_functions_->next == NULL);
	assertion(node->doc_subnode_->applications_ != NULL);
	assertion(node->doc_subnode_->applications_->first == NULL);
	assertion(node->doc_subnode_->applications_->next == NULL);
	assertion(node->doc_subnode_->execution_requests_ != NULL);
	assertion(node->doc_subnode_->execution_requests_->first != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			node->doc_subnode_->execution_requests_->first);
	assertion(node->doc_subnode_->execution_requests_->next == NULL);
}

#endif

stt_node *
stt_node_example_doc_five()
{
	stt_named_function * named_function_foo_;
	stt_named_function * named_function_bar_;
	stt_named_functions_simple_list * named_functions_;
	stt_application * application_foo_;
	stt_application * application_bar_;
	stt_applications_simple_list * applications_;
	stt_execution_request * execution_request_baz_;
	stt_execution_requests_simple_list * execution_requests_;
	stt_node * ret_;

	named_function_foo_ = stt_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_foo_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_foo_);
#endif

	named_function_bar_ = stt_named_function_example_print_string_literal_bar();
	forced_assertion(named_function_bar_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			named_function_bar_);
#endif

	named_functions_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(named_functions_ != NULL);
#ifndef NDEBUG
	assertion(named_functions_->first == NULL);
	assertion(named_functions_->next == NULL);
#endif

	named_functions_ = stt_named_functions_simple_list_push_front(
			named_functions_, named_function_foo_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_foo_);
	assertion(named_functions_ != NULL);
#endif
	forced_assertion(named_functions_->first != NULL);
#ifndef NDEBUG
	assertion(named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_functions_->first);
	assertion(named_functions_->next == NULL);
#endif

	stt_named_function_destructor(named_function_foo_);

	named_functions_ = stt_named_functions_simple_list_push_front(
			named_functions_, named_function_bar_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			named_function_bar_);
	assertion(named_functions_ != NULL);
	assertion(named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			named_functions_->first);
	assertion(named_functions_->next != NULL);
	assertion(named_functions_->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_functions_->next->first);
	assertion(named_functions_->next->next == NULL);
#endif

	stt_named_function_destructor(named_function_bar_);

	application_foo_ = stt_application_example_print_foo();
	forced_assertion(application_foo_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_foo_);
#endif

	application_bar_ = stt_application_example_print_bar();
	forced_assertion(application_bar_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_bar(
			application_bar_);
#endif

	applications_ = stt_applications_simple_list_default_constructor();
	forced_assertion(applications_ != NULL);
#ifndef NDEBUG
	assertion(applications_->first == NULL);
	assertion(applications_->next == NULL);
#endif

	applications_ = stt_applications_simple_list_push_front(
			applications_, application_foo_);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_foo_);
	assertion(applications_ != NULL);
#endif
	forced_assertion(applications_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			applications_->first);
	assertion(applications_->next == NULL);
#endif

	stt_application_destructor(application_foo_);

	applications_ = stt_applications_simple_list_push_front(
			applications_, application_bar_);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_bar(
			application_bar_);
	assertion(applications_ != NULL);
	assertion(applications_->first != NULL);
	assert_expectations_on_stt_application_example_print_bar(
			applications_->first);
	assertion(applications_->next != NULL);
	assertion(applications_->next->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			applications_->next->first);
	assertion(applications_->next->next == NULL);
#endif

	stt_application_destructor(application_bar_);

	execution_request_baz_ = stt_execution_request_example_print_baz();
	forced_assertion(execution_request_baz_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_baz(
			execution_request_baz_);
#endif

	execution_requests_ =
			stt_execution_requests_simple_list_default_constructor();
	forced_assertion(execution_requests_ != NULL);
#ifndef NDEBUG
	assertion(execution_requests_->first == NULL);
	assertion(execution_requests_->next == NULL);
#endif

	execution_requests_ = stt_execution_requests_simple_list_push_front(
			execution_requests_, execution_request_baz_);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_baz(
			execution_request_baz_);
	assertion(execution_requests_ != NULL);
#endif
	forced_assertion(execution_requests_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_baz(
			execution_requests_->first);
	assertion(execution_requests_->next == NULL);
#endif

	stt_execution_request_destructor(execution_request_baz_);

	ret_ = stt_node_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_doc(ret_, named_functions_, applications_,
	                 execution_requests_);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_baz(
			execution_requests_->first);
	assertion(execution_requests_->next == NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_DOC);
#endif
	forced_assertion(ret_->doc_subnode_ != NULL);
	forced_assertion(ret_->doc_subnode_->execution_requests_ != NULL);
	forced_assertion(ret_->doc_subnode_->execution_requests_->first !=
			NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_baz(
			ret_->doc_subnode_->execution_requests_->first);
	assertion(ret_->doc_subnode_->execution_requests_->next == NULL);
#endif

	stt_named_functions_simple_list_destructor(named_functions_);
	stt_applications_simple_list_destructor(applications_);
	stt_execution_requests_simple_list_destructor(execution_requests_);

#ifndef NDEBUG
	assert_expectations_on_stt_node_example_doc_five(ret_);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_five(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_DOC);
	assertion(node->doc_subnode_ != NULL);
	assertion(node->doc_subnode_->named_functions_ != NULL);
	assertion(node->doc_subnode_->named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_bar(
			node->doc_subnode_->named_functions_->first);
	assertion(node->doc_subnode_->named_functions_->next != NULL);
	assertion(node->doc_subnode_->named_functions_->next->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			node->doc_subnode_->named_functions_->next->first);
	assertion(node->doc_subnode_->named_functions_->next->next == NULL);
	assertion(node->doc_subnode_->applications_ != NULL);
	assertion(node->doc_subnode_->applications_->first != NULL);
	assert_expectations_on_stt_application_example_print_bar(
			node->doc_subnode_->applications_->first);
	assertion(node->doc_subnode_->applications_->next != NULL);
	assertion(node->doc_subnode_->applications_->next->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			node->doc_subnode_->applications_->next->first);
	assertion(node->doc_subnode_->applications_->next->next == NULL);
	assertion(node->doc_subnode_->execution_requests_ != NULL);
	assertion(node->doc_subnode_->execution_requests_->first != NULL);
	assert_expectations_on_stt_execution_request_example_print_baz(
			node->doc_subnode_->execution_requests_->first);
	assertion(node->doc_subnode_->execution_requests_->next == NULL);
}

#endif

stt_node *
stt_node_example_doc_six()
{
	stt_named_function * named_function_foo_;
	stt_named_functions_simple_list * named_functions_;
	stt_application * application_foo_;
	stt_applications_simple_list * applications_;
	stt_execution_request * execution_request_foo_;
	stt_execution_requests_simple_list * execution_requests_;
	stt_node * ret_;

	named_function_foo_ = stt_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_foo_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_foo_);
#endif

	named_functions_ = stt_named_functions_simple_list_default_constructor();
	forced_assertion(named_functions_ != NULL);
#ifndef NDEBUG
	assertion(named_functions_->first == NULL);
	assertion(named_functions_->next == NULL);
#endif

	named_functions_ = stt_named_functions_simple_list_push_front(
			named_functions_, named_function_foo_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_foo_);
#endif
	forced_assertion(named_functions_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_functions_->first);
	assertion(named_functions_->next == NULL);
#endif

	stt_named_function_destructor(named_function_foo_);

	application_foo_ = stt_application_example_print_foo();
	forced_assertion(application_foo_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_foo_);
#endif

	applications_ = stt_applications_simple_list_default_constructor();
	forced_assertion(applications_ != NULL);
#ifndef NDEBUG
	assertion(applications_->first == NULL);
	assertion(applications_->next == NULL);
#endif

	applications_ = stt_applications_simple_list_push_front(
			applications_, application_foo_);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_foo_);
	assertion(applications_ != NULL);
#endif
	forced_assertion(applications_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			applications_->first);
	assertion(applications_->next == NULL);
#endif

	stt_application_destructor(application_foo_);

	execution_request_foo_ = stt_execution_request_example_print_foo();
	forced_assertion(execution_request_foo_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_foo_);
#endif

	execution_requests_ =
			stt_execution_requests_simple_list_default_constructor();
	forced_assertion(execution_requests_ != NULL);
#ifndef NDEBUG
	assertion(execution_requests_->first == NULL);
	assertion(execution_requests_->next == NULL);
#endif

	execution_requests_ = stt_execution_requests_simple_list_push_front(
			execution_requests_, execution_request_foo_);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_foo_);
	assertion(execution_requests_ != NULL);
#endif
	forced_assertion(execution_requests_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_requests_->first);
	assertion(execution_requests_->next == NULL);
#endif

	stt_execution_request_destructor(execution_request_foo_);

	ret_ = stt_node_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_doc(ret_, named_functions_, applications_,
	                 execution_requests_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_functions_->first);
	assertion(named_functions_->next == NULL);
	assert_expectations_on_stt_application_example_print_foo(
			applications_->first);
	assertion(applications_->next == NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_requests_->first);
	assertion(execution_requests_->next == NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_DOC);
#endif
	forced_assertion(ret_->doc_subnode_ != NULL);
	forced_assertion(ret_->doc_subnode_->named_functions_ != NULL);
	forced_assertion(ret_->doc_subnode_->named_functions_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			ret_->doc_subnode_->named_functions_->first);
	assertion(ret_->doc_subnode_->named_functions_->next == NULL);
#endif
	forced_assertion(ret_->doc_subnode_->applications_ != NULL);
	forced_assertion(ret_->doc_subnode_->applications_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			ret_->doc_subnode_->applications_->first);
	assertion(ret_->doc_subnode_->applications_->next == NULL);
#endif
	forced_assertion(ret_->doc_subnode_->execution_requests_ != NULL);
	forced_assertion(ret_->doc_subnode_->execution_requests_->first !=
			NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			ret_->doc_subnode_->execution_requests_->first);
	assertion(ret_->doc_subnode_->execution_requests_->next == NULL);
#endif

	stt_named_functions_simple_list_destructor(named_functions_);
	stt_applications_simple_list_destructor(applications_);
	stt_execution_requests_simple_list_destructor(execution_requests_);

#ifndef NDEBUG
	assert_expectations_on_stt_node_example_doc_six(ret_);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_doc_six(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_DOC);
	assertion(node->doc_subnode_ != NULL);
	assertion(node->doc_subnode_->named_functions_ != NULL);
	assertion(node->doc_subnode_->named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			node->doc_subnode_->named_functions_->first);
	assertion(node->doc_subnode_->named_functions_->next == NULL);
	assertion(node->doc_subnode_->applications_ != NULL);
	assertion(node->doc_subnode_->applications_->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			node->doc_subnode_->applications_->first);
	assertion(node->doc_subnode_->applications_->next == NULL);
	assertion(node->doc_subnode_->execution_requests_ != NULL);
	assertion(node->doc_subnode_->execution_requests_->first != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			node->doc_subnode_->execution_requests_->first);
	assertion(node->doc_subnode_->execution_requests_->next == NULL);
}

#endif

void
stt_node_copy_constructor_test_10_natural_literal()
{
	stt_node * node_zero_;
	amara_string * raw_natural_literal_;
	stt_node * node_one_;
	amara_boolean equality_;

	node_zero_ = stt_node_default_constructor();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	raw_natural_literal_ = amara_string_exhaustive_constructor("1");
#ifndef NDEBUG
	assertion(raw_natural_literal_ != NULL);
	assertion(raw_natural_literal_->value_ != NULL);
#endif

	stt_node_set_natural_literal(node_zero_, raw_natural_literal_);
#ifndef NDEBUG
	assertion(raw_natural_literal_->value_ != NULL);
	assertion(node_zero_->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(node_zero_->natural_literal_subnode_ != NULL);
	assertion(node_zero_->natural_literal_subnode_->raw_ != NULL);
	assertion(node_zero_->natural_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_natural_literal_,
			node_zero_->natural_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	node_one_ = stt_node_copy_constructor(node_zero_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(node_zero_->natural_literal_subnode_ != NULL);
	assertion(node_zero_->natural_literal_subnode_->raw_ != NULL);
	assertion(node_zero_->natural_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_natural_literal_,
			node_zero_->natural_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(node_one_->natural_literal_subnode_ != NULL);
	assertion(node_one_->natural_literal_subnode_->raw_ != NULL);
	assertion(node_one_->natural_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_natural_literal_,
			node_one_->natural_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	stt_node_destructor(node_one_);
	amara_string_destructor(raw_natural_literal_);
	stt_node_destructor(node_zero_);
}

void
stt_node_copy_constructor_test_20_integer_literal()
{
	stt_node * node_zero_;
	amara_string * raw_integer_literal_;
	stt_node * node_one_;
	amara_boolean equality_;

	node_zero_ = stt_node_default_constructor();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	raw_integer_literal_ = amara_string_exhaustive_constructor("-1");
	assertion(raw_integer_literal_ != NULL);
	assertion(raw_integer_literal_->value_ != NULL);

	stt_node_set_integer_literal(node_zero_, raw_integer_literal_);
	assertion(raw_integer_literal_->value_ != NULL);
	assertion(node_zero_->type_ == STT_NODE_TYPE_INTEGER_LITERAL);
	assertion(node_zero_->integer_literal_subnode_ != NULL);
	assertion(node_zero_->integer_literal_subnode_->raw_ != NULL);
	assertion(node_zero_->integer_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_integer_literal_,
			node_zero_->integer_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	node_one_ = stt_node_copy_constructor(node_zero_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_INTEGER_LITERAL);
	assertion(node_zero_->integer_literal_subnode_ != NULL);
	assertion(node_zero_->integer_literal_subnode_->raw_ != NULL);
	assertion(node_zero_->integer_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_integer_literal_,
			node_zero_->integer_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_INTEGER_LITERAL);
	assertion(node_one_->integer_literal_subnode_ != NULL);
	assertion(node_one_->integer_literal_subnode_->raw_ != NULL);
	assertion(node_one_->integer_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_integer_literal_,
			node_one_->integer_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	stt_node_destructor(node_one_);
	amara_string_destructor(raw_integer_literal_);
	stt_node_destructor(node_zero_);
}

void
stt_node_copy_constructor_test_30_rational_literal()
{
	stt_node * node_zero_;
	amara_string * raw_rational_literal_;
	stt_node * node_one_;
	amara_boolean equality_;

	node_zero_ = stt_node_default_constructor();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	raw_rational_literal_ = amara_string_exhaustive_constructor(".0"); /* XXX Must be changed when proper validation disallows this way to create the _number literal zero_ */
	assertion(raw_rational_literal_ != NULL);
	assertion(raw_rational_literal_->value_ != NULL);

	stt_node_set_rational_literal(node_zero_, raw_rational_literal_);
	assertion(raw_rational_literal_->value_ != NULL);
	assertion(node_zero_->type_ == STT_NODE_TYPE_RATIONAL_LITERAL);
	assertion(node_zero_->rational_literal_subnode_ != NULL);
	assertion(node_zero_->rational_literal_subnode_->raw_ != NULL);
	assertion(node_zero_->rational_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_rational_literal_,
			node_zero_->rational_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	node_one_ = stt_node_copy_constructor(node_zero_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_RATIONAL_LITERAL);
	assertion(node_zero_->rational_literal_subnode_ != NULL);
	assertion(node_zero_->rational_literal_subnode_->raw_ != NULL);
	assertion(node_zero_->rational_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_rational_literal_,
			node_zero_->rational_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_RATIONAL_LITERAL);
	assertion(node_one_->rational_literal_subnode_ != NULL);
	assertion(node_one_->rational_literal_subnode_->raw_ != NULL);
	assertion(node_one_->rational_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_rational_literal_,
			node_one_->rational_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	stt_node_destructor(node_one_);
	amara_string_destructor(raw_rational_literal_);
	stt_node_destructor(node_zero_);
}

void
stt_node_copy_constructor_test_31_identifier()
{
	stt_node * node_zero_;
	amara_string * identifier_;
	stt_node * node_one_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	node_zero_ = stt_node_default_constructor();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	identifier_ = amara_string_exhaustive_constructor("foo");
#ifndef NDEBUG
	assertion(identifier_ != NULL);
	assertion(identifier_->value_ != NULL);
#endif

	stt_node_set_identifier(node_zero_, identifier_);
#ifndef NDEBUG
	assertion(identifier_->value_ != NULL);
	assertion(node_zero_->type_ == STT_NODE_TYPE_IDENTIFIER);
	assertion(node_zero_->identifier_subnode_ != NULL);
	assertion(node_zero_->identifier_subnode_->value_ != NULL);
	assertion(node_zero_->identifier_subnode_->value_->value_ != NULL);
	equality_ = amara_string_equality(
			identifier_, node_zero_->identifier_subnode_->value_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	node_one_ = stt_node_copy_constructor(node_zero_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_IDENTIFIER);
	assertion(node_zero_->identifier_subnode_ != NULL);
	assertion(node_zero_->identifier_subnode_->value_ != NULL);
	assertion(node_zero_->identifier_subnode_->value_->value_ != NULL);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_IDENTIFIER);
	assertion(node_one_->identifier_subnode_ != NULL);
	assertion(node_one_->identifier_subnode_->value_ != NULL);
	assertion(node_one_->identifier_subnode_->value_->value_ != NULL);
	equality_ = amara_string_equality(
			node_zero_->identifier_subnode_->value_,
			node_one_->identifier_subnode_->value_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_node_destructor(node_one_);
	amara_string_destructor(identifier_);
	stt_node_destructor(node_zero_);
}

void
stt_node_copy_constructor_test_32_condition()
{
	stt_node * node_zero_;
	stt_condition * condition_;
	stt_node * node_one_;

	node_zero_ = stt_node_default_constructor();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	condition_ = stt_condition_example_simple_condition();
#ifndef NDEBUG
	assertion(condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_condition(
			condition_);
#endif

	stt_node_set_condition(node_zero_, condition_);
#ifndef NDEBUG
	assert_expectations_on_stt_condition_example_simple_condition(
			condition_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_CONDITION);
	assertion(node_zero_->condition_subnode_ != NULL);
	assertion(node_zero_->condition_subnode_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_condition(
			node_zero_->condition_subnode_->condition_);
#endif

	node_one_ = stt_node_copy_constructor(node_zero_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_CONDITION);
	assertion(node_zero_->condition_subnode_ != NULL);
	assertion(node_zero_->condition_subnode_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_condition(
			node_zero_->condition_subnode_->condition_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_CONDITION);
	assertion(node_one_->condition_subnode_ != NULL);
	assertion(node_one_->condition_subnode_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_condition(
			node_one_->condition_subnode_->condition_);
#endif

	stt_node_destructor(node_one_);
	stt_condition_destructor(condition_);
	stt_node_destructor(node_zero_);
}

void
stt_node_copy_constructor_test_33_expression()
{
	stt_node * node_zero_;
	stt_expression * expression_;
	stt_node * node_one_;

	node_zero_ = stt_node_default_constructor();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	expression_ = stt_expression_example_simple_conditional();
#ifndef NDEBUG
	assertion(expression_ != NULL);
	assert_expectations_on_stt_expression_example_simple_conditional(
			expression_);
#endif

	stt_node_set_expression(node_zero_, expression_);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_simple_conditional(
			expression_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_EXPRESSION);
	assertion(node_zero_->expression_subnode_ != NULL);
	assertion(node_zero_->expression_subnode_->expression_ != NULL);
	assert_expectations_on_stt_expression_example_simple_conditional(
			node_zero_->expression_subnode_->expression_);
#endif

	node_one_ = stt_node_copy_constructor(node_zero_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_EXPRESSION);
	assertion(node_zero_->expression_subnode_ != NULL);
	assertion(node_zero_->expression_subnode_->expression_ != NULL);
	assert_expectations_on_stt_expression_example_simple_conditional(
			node_zero_->expression_subnode_->expression_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_EXPRESSION);
	assertion(node_one_->expression_subnode_ != NULL);
	assertion(node_one_->expression_subnode_->expression_ != NULL);
	assert_expectations_on_stt_expression_example_simple_conditional(
			node_one_->expression_subnode_->expression_);
#endif

	stt_node_destructor(node_one_);
	stt_expression_destructor(expression_);
	stt_node_destructor(node_zero_);
}

void
stt_node_copy_constructor_test_34_where_binding()
{
	stt_node * node_zero_;
	stt_where_value_binding * where_binding_;
	stt_node * node_one_;

	node_zero_ = stt_node_default_constructor();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	where_binding_ = stt_where_value_binding_example_simple_value_bind_foo_to_zero();
#ifndef NDEBUG
	assertion(where_binding_ != NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			where_binding_);
#endif

	stt_node_set_where_value_binding(node_zero_, where_binding_);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			where_binding_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_WHERE_BINDING);
	assertion(node_zero_->where_value_binding_subnode_ != NULL);
	assertion(node_zero_->where_value_binding_subnode_->where_value_binding_ !=
			NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			node_zero_->where_value_binding_subnode_->where_value_binding_);
#endif

	node_one_ = stt_node_copy_constructor(node_zero_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_WHERE_BINDING);
	assertion(node_zero_->where_value_binding_subnode_ != NULL);
	assertion(node_zero_->where_value_binding_subnode_->where_value_binding_ !=
			NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			node_zero_->where_value_binding_subnode_->where_value_binding_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_WHERE_BINDING);
	assertion(node_one_->where_value_binding_subnode_ != NULL);
	assertion(node_one_->where_value_binding_subnode_->where_value_binding_ !=
			NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			node_one_->where_value_binding_subnode_->where_value_binding_);
#endif

	stt_node_destructor(node_one_);
	stt_where_value_binding_destructor(where_binding_);
	stt_node_destructor(node_zero_);
}

void
stt_node_copy_constructor_test_35_where_bindings()
{
	stt_node * node_zero_;
	stt_where_value_bindings_simple_list * where_bindings_;
	stt_node * node_one_;

	node_zero_ = stt_node_default_constructor();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	where_bindings_ = stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero();
#ifndef NDEBUG
	assertion(where_bindings_ != NULL);
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero(
			where_bindings_);
#endif

	stt_node_set_where_value_bindings(node_zero_, where_bindings_);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero(
			where_bindings_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_WHERE_BINDINGS);
	assertion(node_zero_->where_value_bindings_subnode_ != NULL);
	assertion(node_zero_->where_value_bindings_subnode_->where_value_bindings_ !=
			NULL);
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero(
			node_zero_->where_value_bindings_subnode_->where_value_bindings_);
#endif

	stt_where_value_bindings_simple_list_destructor(where_bindings_);

	node_one_ = stt_node_copy_constructor(node_zero_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_WHERE_BINDINGS);
	assertion(node_zero_->where_value_bindings_subnode_ != NULL);
	assertion(node_zero_->where_value_bindings_subnode_->where_value_bindings_ !=
			NULL);
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero(
			node_zero_->where_value_bindings_subnode_->where_value_bindings_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_WHERE_BINDINGS);
	assertion(node_one_->where_value_bindings_subnode_ != NULL);
	assertion(node_one_->where_value_bindings_subnode_->where_value_bindings_ !=
			NULL);
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero(
			node_one_->where_value_bindings_subnode_->where_value_bindings_);
#endif

	stt_node_destructor(node_one_);
	stt_node_destructor(node_zero_);
}

void
stt_node_copy_constructor_test_36_operation()
{
	stt_node * node_zero_;
	stt_operation * operation_;
	stt_node * node_one_;

	node_zero_ = stt_node_default_constructor();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	operation_ = stt_operation_example_print_string_literal_foo();
#ifndef NDEBUG
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operation_);
#endif

	stt_node_set_operation(node_zero_, operation_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operation_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_zero_->operation_subnode_ != NULL);
	assertion(node_zero_->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			node_zero_->operation_subnode_->operation_);
#endif

	node_one_ = stt_node_copy_constructor(node_zero_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_zero_->operation_subnode_ != NULL);
	assertion(node_zero_->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			node_zero_->operation_subnode_->operation_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_one_->operation_subnode_ != NULL);
	assertion(node_one_->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			node_one_->operation_subnode_->operation_);
#endif

	stt_node_destructor(node_one_);
	stt_operation_destructor(operation_);
	stt_node_destructor(node_zero_);
}

void
stt_node_copy_constructor_test_37_operations_list()
{
	stt_node * node_zero_;
	stt_operations_simple_list * operations_;
	stt_node * node_one_;

	node_zero_ = stt_node_default_constructor();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	operations_ = stt_operations_simple_list_example_print_foo();
#ifndef NDEBUG
	assertion(operations_ != NULL);
	assert_expectations_on_stt_operations_simple_list_example_print_foo(
			operations_);
#endif

	stt_node_set_operations_list(node_zero_, operations_);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_print_foo(
			operations_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(node_zero_->operations_list_subnode_ != NULL);
	assertion(node_zero_->operations_list_subnode_->operations_ != NULL);
	assert_expectations_on_stt_operations_simple_list_example_print_foo(
			node_zero_->operations_list_subnode_->operations_);
#endif

	stt_operations_simple_list_destructor(operations_);

	node_one_ = stt_node_copy_constructor(node_zero_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(node_zero_->operations_list_subnode_ != NULL);
	assertion(node_zero_->operations_list_subnode_->operations_ != NULL);
	assert_expectations_on_stt_operations_simple_list_example_print_foo(
			node_zero_->operations_list_subnode_->operations_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(node_one_->operations_list_subnode_ != NULL);
	assertion(node_one_->operations_list_subnode_->operations_ != NULL);
	assert_expectations_on_stt_operations_simple_list_example_print_foo(
			node_one_->operations_list_subnode_->operations_);
#endif

	stt_node_destructor(node_zero_);
	stt_node_destructor(node_one_);
}

void
stt_node_copy_constructor_test_40_named_function()
{
	stt_named_function * named_function_;
	stt_node * node_zero_;
	stt_node * node_one_;

	named_function_ = stt_named_function_example_print_string_literal_foo();
#ifndef NDEBUG
	assertion(named_function_ != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	node_zero_ = stt_node_default_constructor();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_named_function(node_zero_, named_function_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_zero_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
			node_zero_->named_function_subnode_);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	node_one_ = stt_node_copy_constructor(node_zero_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_zero_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
			node_zero_->named_function_subnode_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_one_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
			node_one_->named_function_subnode_);
#endif

	stt_node_destructor(node_one_);
	stt_node_destructor(node_zero_);
	stt_named_function_destructor(named_function_);
}

void
stt_node_copy_constructor_test_50_application()
{
	stt_application * application_;
	stt_node * node_zero_;
	stt_node * node_one_;

	application_ = stt_application_example_print_foo();
#ifndef NDEBUG
	assertion(application_ != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			application_);
#endif

	node_zero_ = stt_node_default_constructor();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_application(node_zero_, application_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_zero_->application_subnode_ != NULL);
	assert_expectations_on_stt_application_subnode_example_print_foo(
			node_zero_->application_subnode_);
	assert_expectations_on_stt_application_example_print_foo(
			application_);
#endif

	node_one_ = stt_node_copy_constructor(node_zero_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_zero_->application_subnode_ != NULL);
	assert_expectations_on_stt_application_subnode_example_print_foo(
			node_zero_->application_subnode_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_one_->application_subnode_ != NULL);
	assert_expectations_on_stt_application_subnode_example_print_foo(
			node_one_->application_subnode_);
#endif

	stt_node_destructor(node_one_);
	stt_node_destructor(node_zero_);
	stt_application_destructor(application_);
}

void
stt_node_copy_constructor_test_60_execution_request()
{
	stt_execution_request * execution_request_;
	stt_node * node_zero_;
	stt_node * node_one_;

	execution_request_ = stt_execution_request_example_print_foo();
#ifndef NDEBUG
	assertion(execution_request_ != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_);
#endif

	node_zero_ = stt_node_default_constructor();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_execution_request(node_zero_, execution_request_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_EXECUTION_REQUEST);
	assertion(node_zero_->execution_request_subnode_ != NULL);
	assert_expectations_on_stt_execution_request_subnode_example_print_foo(
			node_zero_->execution_request_subnode_);
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_);
#endif

	node_one_ = stt_node_copy_constructor(node_zero_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_EXECUTION_REQUEST);
	assertion(node_zero_->execution_request_subnode_ != NULL);
	assert_expectations_on_stt_execution_request_subnode_example_print_foo(
			node_zero_->execution_request_subnode_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_EXECUTION_REQUEST);
	assertion(node_one_->execution_request_subnode_ != NULL);
	assert_expectations_on_stt_execution_request_subnode_example_print_foo(
			node_one_->execution_request_subnode_);
#endif

	stt_node_destructor(node_one_);
	stt_node_destructor(node_zero_);
	stt_execution_request_destructor(execution_request_);
}

void
stt_node_copy_constructor_test_70_doc()
{
	stt_node * node_zero_;
	stt_node * node_one_;

	node_zero_ = stt_node_example_doc_zero();
	forced_assertion(node_zero_ != NULL);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_DOC);
	assert_expectations_on_stt_node_example_doc_zero(node_zero_);
#endif

	node_one_ = stt_node_copy_constructor(node_zero_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_DOC);
	assert_expectations_on_stt_node_example_doc_zero(node_zero_);
#endif
	forced_assertion(node_one_ != NULL);
#ifndef NDEBUG
	assertion(node_one_->type_ == STT_NODE_TYPE_DOC);
	assert_expectations_on_stt_node_example_doc_zero(node_one_);
#endif

	stt_node_destructor(node_one_);
	stt_node_destructor(node_zero_);
}

void
stt_node_copy_constructor_tests()
{
	stt_node_copy_constructor_test_10_natural_literal();
	stt_node_copy_constructor_test_20_integer_literal();
	stt_node_copy_constructor_test_30_rational_literal();
	stt_node_copy_constructor_test_31_identifier();
	stt_node_copy_constructor_test_32_condition();
	stt_node_copy_constructor_test_33_expression();
	stt_node_copy_constructor_test_34_where_binding();
	stt_node_copy_constructor_test_35_where_bindings();
	stt_node_copy_constructor_test_36_operation();
	stt_node_copy_constructor_test_37_operations_list();
	stt_node_copy_constructor_test_40_named_function();
	stt_node_copy_constructor_test_50_application();
	stt_node_copy_constructor_test_60_execution_request();
	stt_node_copy_constructor_test_70_doc();
}

void
stt_node_set_dice_expression_test_0()
{
	stt_node * node_;
	stt_dice_expression * dice_expression_;

	dice_expression_ = stt_dice_expression_example_single_vanilla_dice();
	forced_assertion(dice_expression_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_dice_expression_example_single_vanilla_dice(
			dice_expression_);
#endif

	node_ = stt_node_default_constructor();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_dice_expression(node_, dice_expression_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_EXPRESSION);
#endif
	forced_assertion(node_->expression_subnode_ != NULL);
	forced_assertion(node_->expression_subnode_->expression_ != NULL);
	forced_assertion(node_->expression_subnode_->expression_->sub_dice_ !=
			NULL);
#ifndef NDEBUG
	assertion(node_->expression_subnode_->expression_->type_ ==
			STT_EXPRESSION_TYPE_DICE);
	assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
			node_->expression_subnode_->expression_->sub_dice_);
#endif

	stt_dice_expression_destructor(dice_expression_);
	stt_node_destructor(node_);
}

void
stt_node_set_dice_expression_tests()
{
	stt_node_set_dice_expression_test_0();
}

void
stt_node_set_expression_test_10_string_literal()
{
	amara_string * string_literal_;
	stt_expression * expression_;
	stt_node * node_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	string_literal_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(string_literal_ != NULL);
	forced_assertion(string_literal_->value_ != NULL);

	expression_ = stt_expression_default_constructor();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_string_literal(expression_, string_literal_);
#ifndef NDEBUG
	assertion(string_literal_->value_ != NULL);
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL);
#endif
	forced_assertion(expression_->sub_string_literal_ != NULL);
	forced_assertion(expression_->sub_string_literal_->string_literal_ !=
			NULL);
	forced_assertion(expression_->sub_string_literal_->string_literal_->value_ !=
			NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(
			string_literal_,
			expression_->sub_string_literal_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	node_ = stt_node_default_constructor();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_expression(node_, expression_);
#ifndef NDEBUG
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL);
	assertion(expression_->sub_string_literal_ != NULL);
	assertion(expression_->sub_string_literal_->string_literal_ != NULL);
	assertion(expression_->sub_string_literal_->string_literal_->value_ !=
			NULL);
	equality_ = amara_string_equality(
			string_literal_,
			expression_->sub_string_literal_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(node_->type_ == STT_NODE_TYPE_EXPRESSION);
#endif
	forced_assertion(node_->expression_subnode_ != NULL);
	forced_assertion(node_->expression_subnode_->expression_ != NULL);
#ifndef NDEBUG
	assertion(node_->expression_subnode_->expression_->type_ ==
			STT_EXPRESSION_TYPE_STRING_LITERAL);
#endif
	forced_assertion(node_->expression_subnode_->expression_->sub_string_literal_ !=
			NULL);
	forced_assertion(node_->expression_subnode_->expression_->sub_string_literal_->string_literal_ !=
			NULL);
	forced_assertion(node_->expression_subnode_->expression_->sub_string_literal_->string_literal_->value_ !=
			NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(
			expression_->sub_string_literal_->string_literal_,
			node_->expression_subnode_->expression_->sub_string_literal_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_node_destructor(node_);
	stt_expression_destructor(expression_);
	amara_string_destructor(string_literal_);
}

void
stt_node_set_expression_test_15_identifier()
{
	amara_string * identifier_;
	stt_expression * expression_;
	stt_node * node_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	identifier_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(identifier_ != NULL);
	forced_assertion(identifier_->value_ != NULL);

	expression_ = stt_expression_default_constructor();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_identifier(expression_, identifier_);
#ifndef NDEBUG
	assertion(identifier_->value_ != NULL);
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_IDENTIFIER);
#endif
	forced_assertion(expression_->sub_identifier_ != NULL);
	forced_assertion(expression_->sub_identifier_->identifier_ !=
			NULL);
	forced_assertion(expression_->sub_identifier_->identifier_->value_ !=
			NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(
			identifier_,
			expression_->sub_identifier_->identifier_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	node_ = stt_node_default_constructor();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_expression(node_, expression_);
#ifndef NDEBUG
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_IDENTIFIER);
	assertion(expression_->sub_identifier_ != NULL);
	assertion(expression_->sub_identifier_->identifier_ != NULL);
	assertion(expression_->sub_identifier_->identifier_->value_ !=
			NULL);
	equality_ = amara_string_equality(
			identifier_,
			expression_->sub_identifier_->identifier_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(node_->type_ == STT_NODE_TYPE_EXPRESSION);
#endif
	forced_assertion(node_->expression_subnode_ != NULL);
	forced_assertion(node_->expression_subnode_->expression_ != NULL);
#ifndef NDEBUG
	assertion(node_->expression_subnode_->expression_->type_ ==
			STT_EXPRESSION_TYPE_IDENTIFIER);
#endif
	forced_assertion(node_->expression_subnode_->expression_->sub_identifier_ !=
			NULL);
	forced_assertion(node_->expression_subnode_->expression_->sub_identifier_->identifier_ !=
			NULL);
	forced_assertion(node_->expression_subnode_->expression_->sub_identifier_->identifier_->value_ !=
			NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(
			expression_->sub_identifier_->identifier_,
			node_->expression_subnode_->expression_->sub_identifier_->identifier_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_node_destructor(node_);
	stt_expression_destructor(expression_);
	amara_string_destructor(identifier_);
}

void
stt_node_set_expression_test_20_dice()
{
	stt_dice_expression * dice_expression_;
	stt_expression * expression_;
	stt_node * node_;

	dice_expression_ = stt_dice_expression_example_single_vanilla_dice();
	forced_assertion(dice_expression_ != NULL);
	forced_assertion(dice_expression_->left_hand_side_natural_ != NULL);  /* XXX */
	forced_assertion(dice_expression_->right_hand_side_natural_ !=  /* XXX */
			NULL);  /* XXX */
#ifndef NDEBUG
	assert_expectations_on_stt_dice_expression_example_single_vanilla_dice(
			dice_expression_);
#endif

	expression_ = stt_expression_default_constructor();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_dice(expression_, dice_expression_);
#ifndef NDEBUG
	assert_expectations_on_stt_dice_expression_example_single_vanilla_dice(
			dice_expression_);
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_DICE);
#endif
	forced_assertion(expression_->sub_dice_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
			expression_->sub_dice_);
#endif

	node_ = stt_node_default_constructor();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_expression(node_, expression_);
#ifndef NDEBUG
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_DICE);
	assertion(expression_->sub_dice_ != NULL);
	assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
			expression_->sub_dice_);
	assertion(node_->type_ == STT_NODE_TYPE_EXPRESSION);
#endif
	forced_assertion(node_->expression_subnode_ != NULL);
	forced_assertion(node_->expression_subnode_->expression_ != NULL);
#ifndef NDEBUG
	assertion(node_->expression_subnode_->expression_->type_ ==
			STT_EXPRESSION_TYPE_DICE);
#endif
	forced_assertion(node_->expression_subnode_->expression_->sub_dice_ !=
			NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_sub_dice_example_single_vanilla_dice(
			node_->expression_subnode_->expression_->sub_dice_);
#endif

	stt_node_destructor(node_);
	stt_expression_destructor(expression_);
	stt_dice_expression_destructor(dice_expression_);
}

void
stt_node_set_expression_tests()
{
	stt_node_set_expression_test_10_string_literal();
	stt_node_set_expression_test_15_identifier();
	stt_node_set_expression_test_20_dice();
}

void
stt_node_set_where_value_bindings_test_0()
{
	stt_where_value_bindings_simple_list * where_value_bindings_;
	stt_node * node_;

	where_value_bindings_ = stt_where_value_bindings_simple_list_default_constructor();
	forced_assertion(where_value_bindings_ != NULL);
#ifndef NDEBUG
	assertion(where_value_bindings_->first == NULL);
	assertion(where_value_bindings_->next == NULL);
#endif

	node_ = stt_node_default_constructor();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_where_value_bindings(node_, where_value_bindings_);
#ifndef NDEBUG
	assertion(where_value_bindings_->first == NULL);
	assertion(where_value_bindings_->next == NULL);
	assertion(node_->type_ == STT_NODE_TYPE_WHERE_BINDINGS);
#endif
	forced_assertion(node_->where_value_bindings_subnode_ != NULL);
	forced_assertion(node_->where_value_bindings_subnode_->where_value_bindings_ != NULL);
#ifndef NDEBUG
	assertion(node_->where_value_bindings_subnode_->where_value_bindings_->first == NULL);
	assertion(node_->where_value_bindings_subnode_->where_value_bindings_->next == NULL);
#endif

	stt_node_destructor(node_);
	stt_where_value_bindings_simple_list_destructor(where_value_bindings_);
}

void
stt_node_set_where_value_bindings_tests()
{
	stt_node_set_where_value_bindings_test_0();
}

void
stt_node_setters_tests()
{
	stt_node_set_dice_expression_tests();
	stt_node_set_expression_tests();
	stt_node_set_where_value_bindings_tests();
}

void
stt_node_validation_test_05_natural_literal()
{
	stt_node * node_;
	amara_string * raw_natural_literal_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	node_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	raw_natural_literal_ = amara_string_exhaustive_constructor("0");
#ifndef NDEBUG
	assertion(raw_natural_literal_ != NULL);
	assertion(raw_natural_literal_->value_ != NULL);
#endif

	stt_node_set_natural_literal(node_, raw_natural_literal_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(node_->natural_literal_subnode_ != NULL);
	assertion(node_->natural_literal_subnode_->raw_ != NULL);
	assertion(node_->natural_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_natural_literal_,
			node_->natural_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	assert_stt_node_is_valid(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(node_->natural_literal_subnode_ != NULL);
	assertion(node_->natural_literal_subnode_->raw_ != NULL);
	assertion(node_->natural_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_natural_literal_,
			node_->natural_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	amara_string_destructor(raw_natural_literal_);
	stt_node_destructor(node_);
}

void
stt_node_validation_test_10_integer_literal()
{
	stt_node * node_;
	amara_string * raw_integer_literal_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	node_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	raw_integer_literal_ = amara_string_exhaustive_constructor("-1");
#ifndef NDEBUG
	assertion(raw_integer_literal_ != NULL);
	assertion(raw_integer_literal_->value_ != NULL);
#endif

	stt_node_set_integer_literal(node_, raw_integer_literal_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_INTEGER_LITERAL);
	assertion(node_->integer_literal_subnode_ != NULL);
	assertion(node_->integer_literal_subnode_->raw_ != NULL);
	assertion(node_->integer_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_integer_literal_,
			node_->integer_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	assert_stt_node_is_valid(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_INTEGER_LITERAL);
	assertion(node_->integer_literal_subnode_ != NULL);
	assertion(node_->integer_literal_subnode_->raw_ != NULL);
	assertion(node_->integer_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_integer_literal_,
			node_->integer_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	amara_string_destructor(raw_integer_literal_);
	stt_node_destructor(node_);
}

void
stt_node_validation_test_15_rational_literal()
{
	stt_node * node_;
	amara_string * raw_rational_literal_;
	amara_boolean equality_;

	node_ = stt_node_default_constructor();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);

	raw_rational_literal_ = amara_string_exhaustive_constructor(".1");
	assertion(raw_rational_literal_ != NULL);
	assertion(raw_rational_literal_->value_ != NULL);

	stt_node_set_rational_literal(node_, raw_rational_literal_);
	assertion(node_->type_ == STT_NODE_TYPE_RATIONAL_LITERAL);
	assertion(node_->rational_literal_subnode_ != NULL);
	assertion(node_->rational_literal_subnode_->raw_ != NULL);
	assertion(node_->rational_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_rational_literal_,
			node_->rational_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	assert_stt_node_is_valid(node_);
	assertion(node_->type_ == STT_NODE_TYPE_RATIONAL_LITERAL);
	assertion(node_->rational_literal_subnode_ != NULL);
	assertion(node_->rational_literal_subnode_->raw_ != NULL);
	assertion(node_->rational_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_rational_literal_,
			node_->rational_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(raw_rational_literal_);
	stt_node_destructor(node_);
}

void
stt_node_validation_test_20_identifier()
{
	stt_node * node_;
	amara_string * identifier_;
	amara_boolean equality_;

	node_ = stt_node_default_constructor();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);

	identifier_ = amara_string_exhaustive_constructor("foo");
	assertion(identifier_ != NULL);
	assertion(identifier_->value_ != NULL);

	stt_node_set_identifier(node_, identifier_);
	assertion(node_->type_ == STT_NODE_TYPE_IDENTIFIER);
	assertion(node_->identifier_subnode_ != NULL);
	assertion(node_->identifier_subnode_->value_ != NULL);
	assertion(node_->identifier_subnode_->value_->value_ != NULL);
	equality_ = amara_string_equality(
			identifier_, node_->identifier_subnode_->value_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	assert_stt_node_is_valid(node_);
	assertion(node_->type_ == STT_NODE_TYPE_IDENTIFIER);
	assertion(node_->identifier_subnode_ != NULL);
	assertion(node_->identifier_subnode_->value_ != NULL);
	assertion(node_->identifier_subnode_->value_->value_ != NULL);
	equality_ = amara_string_equality(
			identifier_, node_->identifier_subnode_->value_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(identifier_);
	stt_node_destructor(node_);
}

void
stt_node_validation_test_21_condition()
{
	stt_node * node_;
	stt_condition * condition_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	node_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	condition_ = stt_condition_example_simple_condition();
#ifndef NDEBUG
	assertion(condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_condition(
			condition_);
#endif

	stt_node_set_condition(node_, condition_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_CONDITION);
	assertion(node_->condition_subnode_ != NULL);
	assert_expectations_on_stt_condition_example_simple_condition(
			node_->condition_subnode_->condition_);
	assert_expectations_on_stt_condition_example_simple_condition(
			condition_);
	equality_ = stt_condition_equality(
			node_->condition_subnode_->condition_, condition_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	assert_stt_node_is_valid(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_CONDITION);
	assertion(node_->condition_subnode_ != NULL);
	assertion(node_->condition_subnode_->condition_ != NULL);
	assert_expectations_on_stt_condition_example_simple_condition(
			node_->condition_subnode_->condition_);
	assert_expectations_on_stt_condition_example_simple_condition(
			condition_);
	equality_ = stt_condition_equality(
			node_->condition_subnode_->condition_, condition_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_condition_destructor(condition_);
	stt_node_destructor(node_);
}

void
stt_node_validation_test_22_expression()
{
	stt_node * node_;
	stt_expression * expression_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	node_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	expression_ = stt_expression_example_natural_zero();
#ifndef NDEBUG
	assertion(expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_);
#endif

	stt_node_set_expression(node_, expression_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_EXPRESSION);
	assertion(node_->expression_subnode_ != NULL);
	assertion(node_->expression_subnode_->expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			node_->expression_subnode_->expression_);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_);
	equality_ = stt_expression_equality(
			node_->expression_subnode_->expression_, expression_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	assert_stt_node_is_valid(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_EXPRESSION);
	assertion(node_->expression_subnode_ != NULL);
	assertion(node_->expression_subnode_->expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			node_->expression_subnode_->expression_);
	assert_expectations_on_stt_expression_example_natural_zero(
			expression_);
	equality_ = stt_expression_equality(
			node_->expression_subnode_->expression_, expression_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_node_destructor(node_);
	stt_expression_destructor(expression_);
}

void
stt_node_validation_test_23_where_binding()
{
	stt_node * node_;
	stt_where_value_binding * where_value_binding_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	node_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	where_value_binding_ =
			stt_where_value_binding_example_simple_value_bind();
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
			where_value_binding_);
#endif

	stt_node_set_where_value_binding(node_, where_value_binding_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_WHERE_BINDING);
	assertion(node_->where_value_binding_subnode_ != NULL);
	assertion(node_->where_value_binding_subnode_->where_value_binding_ !=
			NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
			node_->where_value_binding_subnode_->where_value_binding_);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
			where_value_binding_);
	equality_ = amara_string_equality(
			node_->where_value_binding_subnode_->where_value_binding_->value_name_,
			where_value_binding_->value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	equality_ = stt_expression_equality(
			node_->where_value_binding_subnode_->where_value_binding_->value_expression_,
			where_value_binding_->value_expression_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	assert_stt_node_is_valid(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_WHERE_BINDING);
	assertion(node_->where_value_binding_subnode_ != NULL);
	assertion(node_->where_value_binding_subnode_->where_value_binding_ !=
			NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
			node_->where_value_binding_subnode_->where_value_binding_);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
			where_value_binding_);
	equality_ = amara_string_equality(
			node_->where_value_binding_subnode_->where_value_binding_->value_name_,
			where_value_binding_->value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	equality_ = stt_expression_equality(
			node_->where_value_binding_subnode_->where_value_binding_->value_expression_,
			where_value_binding_->value_expression_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_where_value_binding_destructor(where_value_binding_);
	stt_node_destructor(node_);
}

void
stt_node_validation_test_24_where_bindings()
{
	stt_node * node_;
	stt_where_value_bindings_simple_list * where_value_bindings_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	node_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	where_value_bindings_ =
			stt_where_value_bindings_simple_list_example_simple_value_bind();
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind(
			where_value_bindings_);
#endif

	stt_node_set_where_value_bindings(node_, where_value_bindings_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_WHERE_BINDINGS);
	assertion(node_->where_value_bindings_subnode_ != NULL);
	assertion(node_->where_value_bindings_subnode_->where_value_bindings_ !=
			NULL);
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind(
			node_->where_value_bindings_subnode_->where_value_bindings_);
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind(
			where_value_bindings_);
	assertion(where_value_bindings_->next == NULL);
	assertion(node_->where_value_bindings_subnode_->where_value_bindings_->next ==
			NULL);
	equality_ = amara_string_equality(
			node_->where_value_bindings_subnode_->where_value_bindings_->first->value_name_,
			where_value_bindings_->first->value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	equality_ = stt_expression_equality(
			node_->where_value_bindings_subnode_->where_value_bindings_->first->value_expression_,
			where_value_bindings_->first->value_expression_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	assert_stt_node_is_valid(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_WHERE_BINDINGS);
	assertion(node_->where_value_bindings_subnode_ != NULL);
	assertion(node_->where_value_bindings_subnode_->where_value_bindings_ !=
			NULL);
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind(
			node_->where_value_bindings_subnode_->where_value_bindings_);
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind(
			where_value_bindings_);
	assertion(where_value_bindings_->next == NULL);
	assertion(node_->where_value_bindings_subnode_->where_value_bindings_->next ==
			NULL);
	equality_ = amara_string_equality(
			node_->where_value_bindings_subnode_->where_value_bindings_->first->value_name_,
			where_value_bindings_->first->value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	equality_ = stt_expression_equality(
			node_->where_value_bindings_subnode_->where_value_bindings_->first->value_expression_,
			where_value_bindings_->first->value_expression_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_where_value_bindings_simple_list_destructor(where_value_bindings_);
	stt_node_destructor(node_);
}

void
stt_node_validation_test_25_operation()
{
	stt_node * node_;
	stt_operation * operation_;

	operation_ = stt_operation_example_print_string_literal_foo();
#ifndef NDEBUG
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operation_);
#endif

	node_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_operation(node_, operation_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_->operation_subnode_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			node_->operation_subnode_->operation_);
#endif

	assert_stt_node_is_valid(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_->operation_subnode_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			node_->operation_subnode_->operation_);
#endif

	stt_node_destructor(node_);
	stt_operation_destructor(operation_);
}

/**  XXX arguable an empty operations list cannot make a valid syntax
 * tree node. */
void
stt_node_validation_test_30_operations_list()
{
	stt_node * node_;
	stt_operations_simple_list * operations_;

	operations_ = stt_operations_simple_list_default_constructor();
	assertion(operations_ != NULL);
	assertion(operations_->first == NULL);
	assertion(operations_->next == NULL);

	node_ = stt_node_default_constructor();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);

	stt_node_set_operations_list(node_, operations_);
	assertion(node_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(node_->operations_list_subnode_ != NULL);
	assertion(node_->operations_list_subnode_->operations_ != NULL);
	assertion(node_->operations_list_subnode_->operations_->first == NULL);
	assertion(node_->operations_list_subnode_->operations_->next == NULL);

	assert_stt_node_is_valid(node_);
	assertion(node_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(node_->operations_list_subnode_->operations_ != NULL);
	assertion(node_->operations_list_subnode_->operations_->first == NULL);
	assertion(node_->operations_list_subnode_->operations_->next == NULL);

	stt_node_destructor(node_);
	stt_operations_simple_list_destructor(operations_);
}

void
stt_node_validation_test_35_named_function()
{
	stt_node * node_;
	stt_named_function * named_function_;

	named_function_ = stt_named_function_example_print_string_literal_foo();
#ifndef NDEBUG
	assertion(named_function_ != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	node_ = stt_node_default_constructor();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);

	stt_node_set_named_function(node_, named_function_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
			node_->named_function_subnode_);
#endif

	assert_stt_node_is_valid(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
			node_->named_function_subnode_);
#endif

	stt_node_destructor(node_);
	stt_named_function_destructor(named_function_);
}

void
stt_node_validation_test_40_application()
{
	stt_node * node_;
	stt_application * application_;

	application_ = stt_application_example_print_foo();
	forced_assertion(application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_);
#endif

	node_ = stt_node_default_constructor();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);

	stt_node_set_application(node_, application_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_APPLICATION);
#endif
	forced_assertion(node_->application_subnode_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_subnode_example_print_foo(
			node_->application_subnode_);
#endif

	assert_stt_node_is_valid(node_);
	assertion(node_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_->application_subnode_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_subnode_example_print_foo(
			node_->application_subnode_);
#endif

	stt_node_destructor(node_);
	stt_application_destructor(application_);
}

void
stt_node_validation_test_45_execution_request()
{
	stt_node * node_;
	stt_execution_request * execution_request_;

	execution_request_ = stt_execution_request_example_print_foo();
#ifndef NDEBUG
	assertion(execution_request_ != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_);
#endif

	node_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_execution_request(node_, execution_request_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_EXECUTION_REQUEST);
	assertion(node_->execution_request_subnode_ != NULL);
	assert_expectations_on_stt_execution_request_subnode_example_print_foo(
			node_->execution_request_subnode_);
#endif

	assert_stt_node_is_valid(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_EXECUTION_REQUEST);
	assertion(node_->execution_request_subnode_ != NULL);
	assert_expectations_on_stt_execution_request_subnode_example_print_foo(
			node_->execution_request_subnode_);
#endif

	stt_node_destructor(node_);
	stt_execution_request_destructor(execution_request_);
}

/**  Friend declaration of private function in `stt_node.c` (so testing
 * an owned function. */
void
assert_all_subnodes_are_null(const stt_node * node)
;

void
stt_node_validation_test_50_doc()
{
	stt_named_function * named_function_;
	stt_named_functions_simple_list * named_functions_;
	stt_application * application_;
	stt_applications_simple_list * applications_;
	stt_execution_request * execution_request_;
	stt_execution_requests_simple_list * execution_requests_;
	stt_node * node_;

	named_function_ = stt_named_function_example_print_string_literal_foo();
#ifndef NDEBUG
	assertion(named_function_ != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	named_functions_ =
			stt_named_functions_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(named_functions_ != NULL);
	assertion(named_functions_->first == NULL);
	assertion(named_functions_->next == NULL);
#endif

	named_functions_ = stt_named_functions_simple_list_push_front(
			named_functions_, named_function_);
#ifndef NDEBUG
	assertion(named_functions_ != NULL);
	assertion(named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_functions_->first);
	assertion(named_functions_->next == NULL);
#endif

	application_ = stt_application_example_print_foo();
#ifndef NDEBUG
	assertion(application_ != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			application_);
#endif

	applications_ = stt_applications_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(applications_ != NULL);
	assertion(applications_->first == NULL);
	assertion(applications_->next == NULL);
#endif

	applications_ = stt_applications_simple_list_push_front(
			applications_, application_);
#ifndef NDEBUG
	assertion(applications_ != NULL);
	assertion(applications_->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			applications_->first);
	assertion(applications_->next == NULL);
#endif

	execution_request_ = stt_execution_request_example_print_foo();
#ifndef NDEBUG
	assertion(execution_request_ != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_);
#endif

	execution_requests_ =
			stt_execution_requests_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(execution_requests_ != NULL);
	assertion(execution_requests_->first == NULL);
	assertion(execution_requests_->next == NULL);
#endif

	execution_requests_ = stt_execution_requests_simple_list_push_front(
			execution_requests_, execution_request_);
#ifndef NDEBUG
	assertion(execution_requests_ != NULL);
	assertion(execution_requests_->first != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_requests_->first);
	assertion(execution_requests_->next == NULL);
#endif

	node_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(node_ != NULL);
	assert_all_subnodes_are_null(node_);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
#endif

	stt_node_set_doc(node_, named_functions_, applications_,
	                 execution_requests_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
	assertion(node_->doc_subnode_ != NULL);
	assert_expectations_on_stt_doc_subnode_example_print_string_literal_foo(
			node_->doc_subnode_);
#endif

	assert_stt_node_is_valid(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
	assertion(node_->doc_subnode_ != NULL);
	assert_expectations_on_stt_doc_subnode_example_print_string_literal_foo(
			node_->doc_subnode_);
#endif

	stt_node_destructor(node_);
	stt_execution_requests_simple_list_destructor(execution_requests_);
	stt_execution_request_destructor(execution_request_);
	stt_applications_simple_list_destructor(applications_);
	stt_application_destructor(application_);
	stt_named_functions_simple_list_destructor(named_functions_);
	stt_named_function_destructor(named_function_);
}

void
stt_node_validation_tests()
{
	stt_node_validation_test_05_natural_literal();
	stt_node_validation_test_10_integer_literal();
	stt_node_validation_test_15_rational_literal();
	stt_node_validation_test_20_identifier();
	stt_node_validation_test_21_condition();
	stt_node_validation_test_22_expression();
	stt_node_validation_test_23_where_binding();
	stt_node_validation_test_24_where_bindings();
	stt_node_validation_test_25_operation();
	stt_node_validation_test_30_operations_list();
	stt_node_validation_test_35_named_function();
	stt_node_validation_test_40_application();
	stt_node_validation_test_45_execution_request();
	stt_node_validation_test_50_doc();
}

void
stt_node_type_name_test_0_operation()
{
	stt_node * node_;
	amara_string * expected_node_type_name_;
	amara_string * node_type_name_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	node_ = stt_node_example_operation_print_string_literal_foo();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_OPERATION);
#endif
	forced_assertion(node_->operation_subnode_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_operation_print_string_literal_foo(
			node_);
#endif

	expected_node_type_name_ =
			amara_string_exhaustive_constructor("operation");
	forced_assertion(expected_node_type_name_ != NULL);
	forced_assertion(expected_node_type_name_->value_ != NULL);

	node_type_name_ = stt_node_type_name(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_->operation_subnode_ != NULL);
	assert_expectations_on_stt_node_example_operation_print_string_literal_foo(
			node_);
	assertion(node_type_name_ != NULL);
	assertion(node_type_name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_node_type_name_, node_type_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	amara_string_destructor(node_type_name_);
	amara_string_destructor(expected_node_type_name_);
	stt_node_destructor(node_);
}

void
stt_node_type_name_test_1_operations_list()
{
	stt_node * node_;
	amara_string * expected_node_type_name_;
	amara_string * node_type_name_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	node_ = stt_node_example_operations_list_print_string_literal_foo_and_then_print_string_literal_bar();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
#endif
	forced_assertion(node_->operations_list_subnode_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_operations_list_print_string_literal_foo_and_then_print_string_literal_bar(
			node_);
#endif

	expected_node_type_name_ =
			amara_string_exhaustive_constructor("operations_list");
	forced_assertion(expected_node_type_name_ != NULL);
	forced_assertion(expected_node_type_name_->value_ != NULL);

	node_type_name_ = stt_node_type_name(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(node_->operations_list_subnode_ != NULL);
	assert_expectations_on_stt_node_example_operations_list_print_string_literal_foo_and_then_print_string_literal_bar(
			node_);
	assertion(node_type_name_ != NULL);
	assertion(node_type_name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_node_type_name_, node_type_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	amara_string_destructor(node_type_name_);
	amara_string_destructor(expected_node_type_name_);
	stt_node_destructor(node_);
}

void
stt_node_type_name_test_2_named_function()
{
	stt_node * node_;
	amara_string * expected_node_type_name_;
	amara_string * node_type_name_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	node_ = stt_node_example_named_function_print_string_literal_foo();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
#endif
	forced_assertion(node_->named_function_subnode_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_named_function_print_string_literal_foo(
			node_);
#endif

	expected_node_type_name_ =
			amara_string_exhaustive_constructor("named_function");
	forced_assertion(expected_node_type_name_ != NULL);
	forced_assertion(expected_node_type_name_->value_ != NULL);

	node_type_name_ = stt_node_type_name(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_node_example_named_function_print_string_literal_foo(
			node_);
	assertion(node_type_name_ != NULL);
	assertion(node_type_name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_node_type_name_, node_type_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	amara_string_destructor(node_type_name_);
	amara_string_destructor(expected_node_type_name_);
	stt_node_destructor(node_);
}

void
stt_node_type_name_test_3_application()
{
	stt_node * node_;
	amara_string * expected_node_type_name_;
	amara_string * node_type_name_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	node_ = stt_node_example_application_print_string_literal_foo();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_APPLICATION);
#endif
	forced_assertion(node_->application_subnode_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_application_print_string_literal_foo(
			node_);
#endif

	expected_node_type_name_ =
			amara_string_exhaustive_constructor("application");
	forced_assertion(expected_node_type_name_ != NULL);
	forced_assertion(expected_node_type_name_->value_ != NULL);

	node_type_name_ = stt_node_type_name(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_->application_subnode_ != NULL);
	assert_expectations_on_stt_node_example_application_print_string_literal_foo(
			node_);
	assertion(node_type_name_ != NULL);
	assertion(node_type_name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_node_type_name_, node_type_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	amara_string_destructor(node_type_name_);
	amara_string_destructor(expected_node_type_name_);
	stt_node_destructor(node_);
}

void
stt_node_type_name_test_10_execution_request()
{
	stt_node * node_;
	amara_string * expected_node_type_name_;
	amara_string * node_type_name_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	node_ = stt_node_example_execution_request();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_EXECUTION_REQUEST);
#endif
	forced_assertion(node_->execution_request_subnode_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_execution_request(node_);
#endif

	expected_node_type_name_ =
			amara_string_exhaustive_constructor(
					"execution_request");
	forced_assertion(expected_node_type_name_ != NULL);
	forced_assertion(expected_node_type_name_->value_ != NULL);

	node_type_name_ = stt_node_type_name(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_EXECUTION_REQUEST);
	assertion(node_->execution_request_subnode_ != NULL);
	assert_expectations_on_stt_node_example_execution_request(node_);
#endif
	forced_assertion(node_type_name_ != NULL);
	forced_assertion(node_type_name_->value_ != NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(
			expected_node_type_name_, node_type_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	amara_string_destructor(node_type_name_);
	amara_string_destructor(expected_node_type_name_);
	stt_node_destructor(node_);
}

void
stt_node_type_name_test_20_doc()
{
	stt_node * node_;
	amara_string * expected_node_type_name_;
	amara_string * node_type_name_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	node_ = stt_node_example_doc_zero();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
#endif
	forced_assertion(node_->doc_subnode_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_doc_zero(node_);
#endif

	expected_node_type_name_ =
			amara_string_exhaustive_constructor("doc");
	forced_assertion(expected_node_type_name_ != NULL);
	forced_assertion(expected_node_type_name_->value_ != NULL);

	node_type_name_ = stt_node_type_name(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
	assertion(node_->doc_subnode_ != NULL);
	assert_expectations_on_stt_node_example_doc_zero(node_);
#endif
	forced_assertion(node_type_name_ != NULL);
	forced_assertion(node_type_name_->value_ != NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(
			expected_node_type_name_, node_type_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	amara_string_destructor(node_type_name_);
	amara_string_destructor(expected_node_type_name_);
	stt_node_destructor(node_);
}

void
stt_node_type_name_tests()
{
	stt_node_type_name_test_0_operation();
	stt_node_type_name_test_1_operations_list();
	stt_node_type_name_test_2_named_function();
	stt_node_type_name_test_3_application();
	stt_node_type_name_test_10_execution_request();
	stt_node_type_name_test_20_doc();
}

void
stt_nodes_substraction_test_0()
{
	stt_node * expression_0_;
	stt_node * expression_1_;
	stt_node * substraction_node_;

	expression_0_ = stt_node_example_expression_natural_literal_zero();
	forced_assertion(expression_0_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_expression_natural_literal_zero(
			expression_0_);
#endif

	expression_1_ = stt_node_example_expression_natural_literal_zero();
	forced_assertion(expression_1_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_expression_natural_literal_zero(
			expression_1_);
#endif

	substraction_node_ =
			stt_nodes_substraction(expression_0_, expression_1_);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_expression_natural_literal_zero(
			expression_0_);
	assert_expectations_on_stt_node_example_expression_natural_literal_zero(
			expression_1_);
#endif
	forced_assertion(substraction_node_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_expression_natural_literal_zero(
			substraction_node_);
#endif

	stt_node_destructor(substraction_node_);
	stt_node_destructor(expression_1_);
	stt_node_destructor(expression_0_);
}

void
stt_nodes_substraction_tests()
{
	stt_nodes_substraction_test_0();
}

void
stt_nodes_multiplication_test_0()
{
	stt_node * expression_0_;
	stt_node * expression_1_;
	stt_node * multiplication_node_;

	expression_0_ = stt_node_example_expression_natural_literal_zero();
	forced_assertion(expression_0_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_expression_natural_literal_zero(
			expression_0_);
#endif

	expression_1_ = stt_node_example_expression_natural_literal_zero();
	forced_assertion(expression_1_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_expression_natural_literal_zero(
			expression_1_);
#endif

	multiplication_node_ =
			stt_nodes_multiplication(expression_0_, expression_1_);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_expression_natural_literal_zero(
			expression_0_);
	assert_expectations_on_stt_node_example_expression_natural_literal_zero(
			expression_1_);
#endif
	forced_assertion(multiplication_node_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_expression_natural_literal_zero(
			multiplication_node_);
#endif

	stt_node_destructor(multiplication_node_);
	stt_node_destructor(expression_1_);
	stt_node_destructor(expression_0_);
}

void
stt_nodes_multiplication_tests()
{
	stt_nodes_multiplication_test_0();
}

void
stt_nodes_division_test_0()
{
	stt_node * expression_0_;
	stt_node * expression_1_;
	stt_node * division_node_;

	expression_0_ = stt_node_example_expression_natural_literal_zero();
	forced_assertion(expression_0_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_expression_natural_literal_zero(
			expression_0_);
#endif

	expression_1_ = stt_node_example_expression_natural_literal_one();
	forced_assertion(expression_1_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_expression_natural_literal_one(
			expression_1_);
#endif

	division_node_ = stt_nodes_division(expression_0_, expression_1_);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_expression_natural_literal_zero(
			expression_0_);
	assert_expectations_on_stt_node_example_expression_natural_literal_one(
			expression_1_);
#endif
	forced_assertion(division_node_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_expression_natural_literal_zero(
			division_node_);
#endif

	stt_node_destructor(division_node_);
	stt_node_destructor(expression_1_);
	stt_node_destructor(expression_0_);
}

void
stt_nodes_division_tests()
{
	stt_nodes_division_test_0();
}

void
register_named_function_test_0()
{
	stt_node * doc_fragment_node_;
#ifndef NDEBUG
	stt_node * doc_fragment_node__;
#endif
	stt_named_function * named_function_;
	stt_node * named_function_node_;

	doc_fragment_node_ = stt_node_default_constructor();
	forced_assertion(doc_fragment_node_ != NULL);

	doc_fragment_node_->doc_subnode_ =
			stt_doc_subnode_default_constructor(); /* XXX */
	doc_fragment_node_->type_ = STT_NODE_TYPE_DOC_FRAGMENT;  /* XXX */
#ifndef NDEBUG
	assert_clean_doc_fragment_node(doc_fragment_node_);
#endif

	named_function_ = stt_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	named_function_node_ = stt_node_default_constructor();
	forced_assertion(named_function_node_ != NULL);

	stt_node_set_named_function(named_function_node_, named_function_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);

	assert_clean_named_function_node(named_function_node_);

	/*   `named_function_node_->named_function_subnode_` is not NULL
	 * as per `assert_clean_named_function_node(
	 * named_function_node_);`. */
	/*
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_node_->named_function_subnode_->named_function_);
	*/

	/*   `named_function_node_->named_function_subnode_` is not NULL
	 * as per `assert_clean_named_function_node(
	 * named_function_node_);`. */
	assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
			named_function_node_->named_function_subnode_);
#endif

	stt_named_function_destructor(named_function_);

#ifndef NDEBUG
	doc_fragment_node__ =
#else
	doc_fragment_node_ =
#endif
			register_named_function(
					doc_fragment_node_,
					named_function_node_);
#ifndef NDEBUG
	assertion(doc_fragment_node__ == doc_fragment_node_);

	assert_clean_named_function_node(named_function_node_);

	/*   `named_function_node_->named_function_subnode_` is not NULL
	 * as per `assert_clean_named_function_node(
	 * named_function_node_);`. */
	assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
			named_function_node_->named_function_subnode_);

	assertion(doc_fragment_node_->type_ == STT_NODE_TYPE_DOC_FRAGMENT);

	assert_clean_doc_fragment_node(doc_fragment_node_);
#endif

	stt_node_destructor(named_function_node_);
	stt_node_destructor(doc_fragment_node_);
}

void
register_named_function_test_1()
{
	stt_node * doc_fragment_node_;
#ifndef NDEBUG
	stt_node * doc_fragment_node__;
#endif
	stt_named_function * named_function_;
	stt_node * named_function_node_;

	doc_fragment_node_ = stt_node_default_constructor();
	forced_assertion(doc_fragment_node_ != NULL);

	doc_fragment_node_->doc_subnode_ =
			stt_doc_subnode_default_constructor(); /* XXX */
	forced_assertion(doc_fragment_node_->doc_subnode_ != NULL);
	doc_fragment_node_->type_ = STT_NODE_TYPE_DOC_FRAGMENT;  /* XXX */
#ifndef NDEBUG
	assert_clean_doc_fragment_node(doc_fragment_node_);
	assertion(doc_fragment_node_->doc_subnode_->named_functions_ != NULL);
#endif

	/*
	doc_fragment_node_->doc_subnode_->named_functions_ =
			stt_named_functions_simple_list_default_constructor();
	forced_assertion(doc_fragment_node_->doc_subnode_->named_functions_ !=
			NULL);
#ifndef NDEBUG
	forced_assertion(doc_fragment_node_->doc_subnode_->named_functions_->first ==
			NULL);
	forced_assertion(doc_fragment_node_->doc_subnode_->named_functions_->next ==
			NULL);
#endif
	*/

	named_function_ = stt_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	named_function_node_ = stt_node_default_constructor();
	forced_assertion(named_function_node_ != NULL);

	stt_node_set_named_function(named_function_node_, named_function_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);

	assert_clean_named_function_node(named_function_node_);

	/*   `named_function_node_->named_function_subnode_` is not NULL
	 * as per `assert_clean_named_function_node(
	 * named_function_node_);`. */
	/*
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_node_->named_function_subnode_->named_function_);
	*/

	/*   `named_function_node_->named_function_subnode_` is not NULL
	 * as per `assert_clean_named_function_node(
	 * named_function_node_);`. */
	assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
			named_function_node_->named_function_subnode_);
#endif

	stt_named_function_destructor(named_function_);

#ifndef NDEBUG
	doc_fragment_node__ =
#else
	doc_fragment_node_ =
#endif
			register_named_function(
					doc_fragment_node_,
					named_function_node_);
#ifndef NDEBUG
	assertion(doc_fragment_node__ == doc_fragment_node_);

	assert_clean_named_function_node(named_function_node_);

	/*   `named_function_node_->named_function_subnode_` is not NULL
	 * as per `assert_clean_named_function_node(
	 * named_function_node_);`. */
	assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
			named_function_node_->named_function_subnode_);

	assertion(doc_fragment_node_->type_ == STT_NODE_TYPE_DOC_FRAGMENT);

	assert_clean_doc_fragment_node(doc_fragment_node_);
#endif

	stt_node_destructor(named_function_node_);
	stt_node_destructor(doc_fragment_node_);
}

void
register_named_function_tests()
{
	register_named_function_test_0();
	register_named_function_test_1();
}

void
register_application_test_0()
{
	stt_node * doc_fragment_node_;
#ifndef NDEBUG
	stt_node * doc_fragment_node__;
#endif
	stt_application * application_;
	stt_node * application_node_;

	doc_fragment_node_ = stt_node_default_constructor();
	forced_assertion(doc_fragment_node_ != NULL);

	doc_fragment_node_->doc_subnode_ =
			stt_doc_subnode_default_constructor(); /* XXX */
	doc_fragment_node_->type_ = STT_NODE_TYPE_DOC_FRAGMENT;  /* XXX */
#ifndef NDEBUG
	assert_clean_doc_fragment_node(doc_fragment_node_);
#endif

	application_ = stt_application_example_print_foo();
	forced_assertion(application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_);
#endif

	application_node_ = stt_node_default_constructor();
	forced_assertion(application_node_ != NULL);

	stt_node_set_application(application_node_, application_);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_);

	assert_clean_application_node(application_node_);

	/*   `application_node_->application_subnode_` should not be
	 * NULL as per `assert_clean_application_node(
	 * application_node_);`. */
	assert_expectations_on_stt_application_subnode_example_print_foo(
			application_node_->application_subnode_);
#endif

	stt_application_destructor(application_);

#ifndef NDEBUG
	doc_fragment_node__ =
#else
	doc_fragment_node_ =
#endif
			register_application(
					doc_fragment_node_,
					application_node_);
#ifndef NDEBUG
	assertion(doc_fragment_node__ == doc_fragment_node_);

	assert_clean_application_node(application_node_);

	/*   `application_node_->application_subnode_` should not be
	 * NULL as per `assert_clean_application_node(
	 * application_node_);`. */
	assert_expectations_on_stt_application_subnode_example_print_foo(
			application_node_->application_subnode_);

	assertion(doc_fragment_node_->type_ == STT_NODE_TYPE_DOC_FRAGMENT);

	assert_clean_doc_fragment_node(doc_fragment_node_);
#endif

	stt_node_destructor(application_node_);
	stt_node_destructor(doc_fragment_node_);
}

void
register_application_tests()
{
	register_application_test_0();
}

void
register_execution_request_test_0()
{
	stt_node * doc_fragment_node_;
#ifndef NDEBUG
	stt_node * doc_fragment_node__;
#endif
	stt_execution_request * execution_request_;
	stt_node * execution_request_node_;

	doc_fragment_node_ = stt_node_default_constructor();
	forced_assertion(doc_fragment_node_ != NULL);

	doc_fragment_node_->doc_subnode_ =
			stt_doc_subnode_default_constructor(); /* XXX scope transgression */
	forced_assertion(doc_fragment_node_->doc_subnode_ != NULL);
	doc_fragment_node_->type_ = STT_NODE_TYPE_DOC_FRAGMENT;  /* XXX scope transgression */
#ifndef NDEBUG
	assert_clean_doc_fragment_node(doc_fragment_node_);
#endif

	execution_request_ = stt_execution_request_example_print_foo();
	forced_assertion(execution_request_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_);
#endif

	execution_request_node_ = stt_node_default_constructor();
	forced_assertion(execution_request_node_ != NULL);

	stt_node_set_execution_request(execution_request_node_,
	                               execution_request_);
#ifndef NDEBUG
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_);

	assert_clean_execution_request_node(execution_request_node_);

	/*   `execution_request_node_->execution_request_subnode_`
	 * should not be NULL as per
	 * `assert_clean_execution_request_node(
	 * execution_request_node_);`. */
	assert_expectations_on_stt_execution_request_subnode_example_print_foo(
			execution_request_node_->execution_request_subnode_);
#endif

	stt_execution_request_destructor(execution_request_);

#ifndef NDEBUG
	doc_fragment_node__ =
#else
	doc_fragment_node_ =
#endif
			register_execution_request(
					doc_fragment_node_,
					execution_request_node_);
#ifndef NDEBUG
	assertion(doc_fragment_node__ == doc_fragment_node_);

	assert_clean_execution_request_node(execution_request_node_);

	/*   `execution_request_node_->execution_request_subnode_`
	 * should not be NULL as per
	 * `assert_clean_execution_request_node(
	 * execution_request_node_);`. */
	assert_expectations_on_stt_execution_request_subnode_example_print_foo(
			execution_request_node_->execution_request_subnode_);

	assertion(doc_fragment_node_->type_ == STT_NODE_TYPE_DOC_FRAGMENT);

	assert_clean_doc_fragment_node(doc_fragment_node_);
#endif

	stt_node_destructor(execution_request_node_);
	stt_node_destructor(doc_fragment_node_);
}

void
register_execution_request_tests()
{
	register_execution_request_test_0();
}

void
dump_syntax_tree_test_0()
{
	stt_node * doc_fragment_node_;
#ifndef NDEBUG
	stt_node * doc_fragment_node__;
#endif
	stt_named_function * named_function_;
	stt_node * named_function_node_;

	doc_fragment_node_ = stt_node_default_constructor();
	forced_assertion(doc_fragment_node_ != NULL);

	doc_fragment_node_->doc_subnode_ =
			stt_doc_subnode_default_constructor(); /* XXX */
	doc_fragment_node_->type_ = STT_NODE_TYPE_DOC_FRAGMENT;  /* XXX */
#ifndef NDEBUG
	assert_clean_doc_fragment_node(doc_fragment_node_);
#endif

	named_function_ = stt_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	named_function_node_ = stt_node_default_constructor();
	forced_assertion(named_function_node_ != NULL);

	stt_node_set_named_function(named_function_node_, named_function_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_);

	assert_clean_named_function_node(named_function_node_);

	/*   `named_function_node_->named_function_subnode_` is not NULL
	 * as per `assert_clean_named_function_node(
	 * named_function_node_);`. */
	/*
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			named_function_node_->named_function_subnode_->named_function_);
	*/

	/*   `named_function_node_->named_function_subnode_` is not NULL
	 * as per `assert_clean_named_function_node(
	 * named_function_node_);`. */
	assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
			named_function_node_->named_function_subnode_);
#endif

	stt_named_function_destructor(named_function_);

#ifndef NDEBUG
	doc_fragment_node__ =
#else
	doc_fragment_node_ =
#endif
			register_named_function(
					doc_fragment_node_,
					named_function_node_);
#ifndef NDEBUG
	assertion(doc_fragment_node__ == doc_fragment_node_);

	assert_clean_named_function_node(named_function_node_);

	/*   `named_function_node_->named_function_subnode_` is not NULL
	 * as per `assert_clean_named_function_node(
	 * named_function_node_);`. */
	assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
			named_function_node_->named_function_subnode_);

	assertion(doc_fragment_node_->type_ == STT_NODE_TYPE_DOC_FRAGMENT);

	assert_clean_doc_fragment_node(doc_fragment_node_);
#endif

	stt_node_destructor(named_function_node_);

	forced_assertion(doc_fragment_node_->type_ ==
			STT_NODE_TYPE_DOC_FRAGMENT);

	/*   TODO Do not finalize this manually this way, but with a
	 * function call. */
	doc_fragment_node_->type_ = STT_NODE_TYPE_DOC;

	dump_syntax_tree(doc_fragment_node_);

	stt_node_destructor(doc_fragment_node_);
}

void
dump_syntax_tree_test_1()
{
	stt_node * doc_fragment_node_;
#ifndef NDEBUG
	stt_node * doc_fragment_node__;
#endif
	stt_application * application_;
	stt_node * application_node_;

	doc_fragment_node_ = stt_node_default_constructor();
	forced_assertion(doc_fragment_node_ != NULL);

	doc_fragment_node_->doc_subnode_ =
			stt_doc_subnode_default_constructor(); /* XXX */
	doc_fragment_node_->type_ = STT_NODE_TYPE_DOC_FRAGMENT;  /* XXX */
#ifndef NDEBUG
	assert_clean_doc_fragment_node(doc_fragment_node_);
#endif

	application_ = stt_application_example_print_foo();
	forced_assertion(application_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_);
#endif

	application_node_ = stt_node_default_constructor();
	forced_assertion(application_node_ != NULL);

	stt_node_set_application(application_node_, application_);
#ifndef NDEBUG
	assert_expectations_on_stt_application_example_print_foo(
			application_);

	assert_clean_application_node(application_node_);

	/*   `application_node_->application_subnode_` is not NULL
	 * as per `assert_clean_application_node(
	 * application_node_);`. */
	/*
	assert_expectations_on_stt_application_example_print_foo(
			application_node_->application_subnode_->application_);
	*/

	/*   `application_node_->application_subnode_` is not NULL
	 * as per `assert_clean_application_node(
	 * application_node_);`. */
	assert_expectations_on_stt_application_subnode_example_print_foo(
			application_node_->application_subnode_);
#endif

	stt_application_destructor(application_);

#ifndef NDEBUG
	doc_fragment_node__ =
#else
	doc_fragment_node_ =
#endif
			register_application(
					doc_fragment_node_,
					application_node_);
#ifndef NDEBUG
	assertion(doc_fragment_node__ == doc_fragment_node_);

	assert_clean_application_node(application_node_);

	/*   `application_node_->application_subnode_` is not NULL
	 * as per `assert_clean_application_node(
	 * application_node_);`. */
	assert_expectations_on_stt_application_subnode_example_print_foo(
			application_node_->application_subnode_);

	assertion(doc_fragment_node_->type_ == STT_NODE_TYPE_DOC_FRAGMENT);

	assert_clean_doc_fragment_node(doc_fragment_node_);
#endif

	stt_node_destructor(application_node_);

	forced_assertion(doc_fragment_node_->type_ ==
			STT_NODE_TYPE_DOC_FRAGMENT);

	/*   TODO Do not finalize this manually this way, but with a
	 * function call. */
	doc_fragment_node_->type_ = STT_NODE_TYPE_DOC;

	dump_syntax_tree(doc_fragment_node_);

	stt_node_destructor(doc_fragment_node_);
}

void
dump_syntax_tree_tests()
{
	dump_syntax_tree_test_0();
	dump_syntax_tree_test_1();
}

void
look_for_undefined_labels_test_0()
{
	stt_node * node_;
	look_for_undefined_labels_ret * look_for_undefined_labels_ret_;

	node_ = stt_node_example_doc_zero();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
	assert_expectations_on_stt_node_example_doc_zero(node_);
#endif

	look_for_undefined_labels_ret_ = look_for_undefined_labels(
			node_);
	forced_assertion(look_for_undefined_labels_ret_ != NULL);
	forced_assertion(look_for_undefined_labels_ret_->status ==
			LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_SUCCESS);
#ifndef NDEBUG
	assertion(look_for_undefined_labels_ret_->messages == NULL);
#endif

	look_for_undefined_labels_ret_destructor(
			look_for_undefined_labels_ret_);
	stt_node_destructor(node_);
}

void
look_for_undefined_labels_test_1()
{
	stt_node * node_;
	look_for_undefined_labels_ret * look_for_undefined_labels_ret_;

	node_ = stt_node_example_doc_one();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
	assert_expectations_on_stt_node_example_doc_one(node_);
#endif

	look_for_undefined_labels_ret_ = look_for_undefined_labels(
			node_);
	forced_assertion(look_for_undefined_labels_ret_ != NULL);
	forced_assertion(look_for_undefined_labels_ret_->status ==
			LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_SUCCESS);
#ifndef NDEBUG
	assertion(look_for_undefined_labels_ret_->messages == NULL);
#endif

	look_for_undefined_labels_ret_destructor(
			look_for_undefined_labels_ret_);
	stt_node_destructor(node_);
}

void
look_for_undefined_labels_test_2()
{
	stt_node * node_;
	look_for_undefined_labels_ret * look_for_undefined_labels_ret_;
	amara_string * message_expectation_;
	amara_string * actual_message_;
	amara_boolean equality_;

	node_ = stt_node_example_doc_two();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
	assert_expectations_on_stt_node_example_doc_two(node_);
#endif

	message_expectation_ = amara_string_exhaustive_constructor(
			"error, function 'print_foo' not found but has been requested as entry point function by application 'cli_app_print_foo'");
	forced_assertion(message_expectation_ != NULL);
	forced_assertion(message_expectation_->value_ != NULL);

	look_for_undefined_labels_ret_ = look_for_undefined_labels(
			node_);
	forced_assertion(look_for_undefined_labels_ret_ != NULL);
	forced_assertion(look_for_undefined_labels_ret_->status ==
			LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR);
#ifndef NDEBUG
	assertion(look_for_undefined_labels_ret_->messages != NULL);
	assertion(look_for_undefined_labels_ret_->messages->first != NULL);
#endif
	actual_message_ = amara_string_exhaustive_constructor(
			look_for_undefined_labels_ret_->messages->first);
	forced_assertion(actual_message_ != NULL);
	forced_assertion(actual_message_->value_ != NULL);
	equality_ = amara_string_equality(
			actual_message_, message_expectation_);
	forced_assertion(equality_ == AMARA_BOOLEAN_TRUE);
#ifndef NDEBUG
	assertion(look_for_undefined_labels_ret_->messages->next == NULL);
#endif

	amara_string_destructor(message_expectation_);
	amara_string_destructor(actual_message_);
	look_for_undefined_labels_ret_destructor(
			look_for_undefined_labels_ret_);
	stt_node_destructor(node_);
}

void
look_for_undefined_labels_test_3()
{
	stt_node * node_;
	look_for_undefined_labels_ret * look_for_undefined_labels_ret_;
	amara_string * message_expectation_;
	amara_string * actual_message_;
	amara_boolean equality_;

	node_ = stt_node_example_doc_three();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
	assert_expectations_on_stt_node_example_doc_three(node_);
#endif

	message_expectation_ = amara_string_exhaustive_constructor(
			"error, function 'print_baz' not found but has been requested as entry point function by application 'cli_app_print_baz'");
	forced_assertion(message_expectation_ != NULL);
	forced_assertion(message_expectation_->value_ != NULL);

	look_for_undefined_labels_ret_ = look_for_undefined_labels(
			node_);
	forced_assertion(look_for_undefined_labels_ret_ != NULL);
	forced_assertion(look_for_undefined_labels_ret_->status ==
			LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR);
#ifndef NDEBUG
	assertion(look_for_undefined_labels_ret_->messages != NULL);
	assertion(look_for_undefined_labels_ret_->messages->first != NULL);
#endif
	actual_message_ = amara_string_exhaustive_constructor(
			look_for_undefined_labels_ret_->messages->first);
	forced_assertion(actual_message_ != NULL);
	forced_assertion(actual_message_->value_ != NULL);
	equality_ = amara_string_equality(
			actual_message_, message_expectation_);
	forced_assertion(equality_ == AMARA_BOOLEAN_TRUE);
#ifndef NDEBUG
	assertion(look_for_undefined_labels_ret_->messages->next == NULL);
#endif

	amara_string_destructor(message_expectation_);
	amara_string_destructor(actual_message_);
	look_for_undefined_labels_ret_destructor(
			look_for_undefined_labels_ret_);
	stt_node_destructor(node_);
}

void
look_for_undefined_labels_test_4()
{
	stt_node * node_;
	look_for_undefined_labels_ret * look_for_undefined_labels_ret_;
	amara_string * message_expectation_;
	amara_string * actual_message_;
	amara_boolean equality_;

	node_ = stt_node_example_doc_four();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
	assert_expectations_on_stt_node_example_doc_four(node_);
#endif

	message_expectation_ = amara_string_exhaustive_constructor(
			"error, application 'cli_app_print_foo' not found but has been requested to be executed");
	forced_assertion(message_expectation_ != NULL);
	forced_assertion(message_expectation_->value_ != NULL);

	look_for_undefined_labels_ret_ = look_for_undefined_labels(
			node_);
	forced_assertion(look_for_undefined_labels_ret_ != NULL);
	forced_assertion(look_for_undefined_labels_ret_->status ==
			LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR);
#ifndef NDEBUG
	assertion(look_for_undefined_labels_ret_->messages != NULL);
	assertion(look_for_undefined_labels_ret_->messages->first != NULL);
#endif
	actual_message_ = amara_string_exhaustive_constructor(
			look_for_undefined_labels_ret_->messages->first);
	forced_assertion(actual_message_ != NULL);
	forced_assertion(actual_message_->value_ != NULL);
	equality_ = amara_string_equality(
			actual_message_, message_expectation_);
	forced_assertion(equality_ == AMARA_BOOLEAN_TRUE);
#ifndef NDEBUG
	assertion(look_for_undefined_labels_ret_->messages->next == NULL);
#endif

	amara_string_destructor(message_expectation_);
	amara_string_destructor(actual_message_);
	look_for_undefined_labels_ret_destructor(
			look_for_undefined_labels_ret_);
	stt_node_destructor(node_);
}

void
look_for_undefined_labels_test_5()
{
	stt_node * node_;
	look_for_undefined_labels_ret * look_for_undefined_labels_ret_;
	amara_string * message_expectation_;
	amara_string * actual_message_;
	amara_boolean equality_;

	node_ = stt_node_example_doc_five();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
	assert_expectations_on_stt_node_example_doc_five(node_);
#endif

	message_expectation_ = amara_string_exhaustive_constructor(
			"error, application 'cli_app_print_baz' not found but has been requested to be executed");
	forced_assertion(message_expectation_ != NULL);
	forced_assertion(message_expectation_->value_ != NULL);

	look_for_undefined_labels_ret_ = look_for_undefined_labels(
			node_);
	forced_assertion(look_for_undefined_labels_ret_ != NULL);
	forced_assertion(look_for_undefined_labels_ret_->status ==
			LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR);
#ifndef NDEBUG
	assertion(look_for_undefined_labels_ret_->messages != NULL);
	assertion(look_for_undefined_labels_ret_->messages->first != NULL);
#endif
	actual_message_ = amara_string_exhaustive_constructor(
			look_for_undefined_labels_ret_->messages->first);
	forced_assertion(actual_message_ != NULL);
	forced_assertion(actual_message_->value_ != NULL);
	equality_ = amara_string_equality(
			actual_message_, message_expectation_);
	forced_assertion(equality_ == AMARA_BOOLEAN_TRUE);
#ifndef NDEBUG
	assertion(look_for_undefined_labels_ret_->messages->next == NULL);
#endif

	amara_string_destructor(message_expectation_);
	amara_string_destructor(actual_message_);
	look_for_undefined_labels_ret_destructor(
			look_for_undefined_labels_ret_);
	stt_node_destructor(node_);
}

void
look_for_undefined_labels_test_6()
{
	stt_node * node_;
	look_for_undefined_labels_ret * look_for_undefined_labels_ret_;

	node_ = stt_node_example_doc_six();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
	assert_expectations_on_stt_node_example_doc_six(node_);
#endif

	look_for_undefined_labels_ret_ = look_for_undefined_labels(
			node_);
	forced_assertion(look_for_undefined_labels_ret_ != NULL);
	forced_assertion(look_for_undefined_labels_ret_->status ==
			LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_SUCCESS);
#ifndef NDEBUG
	assertion(look_for_undefined_labels_ret_->messages == NULL);
#endif

	look_for_undefined_labels_ret_destructor(
			look_for_undefined_labels_ret_);
	stt_node_destructor(node_);
}

void
look_for_undefined_labels_tests()
{
	/*   One single named function with no dependencies. */
	look_for_undefined_labels_test_0();

	/*   One single named function with no dependencies and an
	 * application using it as entry point. */
	look_for_undefined_labels_test_1();

	/*   One application but no named functions, so the entry point
	 * function is not to be found. */
	look_for_undefined_labels_test_2();

	/*   Two named functions and an application, but none of the
	 * functions is the requested entry point named function for the
	 * application. */
	look_for_undefined_labels_test_3();

	/*   One execution request but there are no named functions or
	 * applications, so it must return some error messages. */
	look_for_undefined_labels_test_4();

	/*   Two applications and one execution request, but none of the
	 * applications is the application that the execution requests
	 * wants. */
	look_for_undefined_labels_test_5();

	/*   One single named function, an application using it as entry
	 * point, and an execution request of that application. */
	look_for_undefined_labels_test_6();

	/*   One single function, but depending on an undefined
	 * identifier. */
	/* FIXME the tested code does not exist yet.
	look_for_undefined_labels_test_7();
	*/
}

void
stt_node_tests()
{
	stt_node_copy_constructor_tests();
	stt_node_setters_tests();
	stt_node_validation_tests();
	stt_node_type_name_tests();
	stt_nodes_substraction_tests();
	stt_nodes_multiplication_tests();
	stt_nodes_division_tests();
	register_named_function_tests();
	register_application_tests();
	register_execution_request_tests();
	dump_syntax_tree_tests();
	look_for_undefined_labels_tests();
}
