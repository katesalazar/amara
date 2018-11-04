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

#include "stt_doc_subnode_tests.h"
#include "stt_execution_request_tests.h"
#include "stt_execution_request_subnode_tests.h"

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
stt_node_example_operation_print_foo()
{
	stt_node * ret_;
	stt_operation * operation_;

	ret_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(ret_ != NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	operation_ = stt_operation_example_print_foo();
#ifndef NDEBUG
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(operation_);
#endif

	stt_node_set_operation(ret_, operation_);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(ret_->operation_subnode_ != NULL);
	assertion(ret_->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			ret_->operation_subnode_->operation_);
	assert_expectations_on_stt_operation_example_print_foo(operation_);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_operation_print_foo(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node->operation_subnode_ != NULL);
	assertion(node->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			node->operation_subnode_->operation_);
}

#endif

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

stt_node *
stt_node_example_operations_list_print_foo_and_then_print_bar()
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

	operation_zero_ = stt_operation_example_print_bar();
#ifndef NDEBUG
	assertion(operation_zero_ != NULL);
	assert_expectations_on_stt_operation_example_print_bar(
			operation_zero_);
#endif

	operation_one_ = stt_operation_example_print_foo();
#ifndef NDEBUG
	assertion(operation_one_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
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
	assert_expectations_on_stt_operation_example_print_bar(
			operations_->first);
	assertion(operations_->next == NULL);
#endif

	operations_ = stt_operations_simple_list_push_front(
			operations_, operation_one_);
#ifndef NDEBUG
	assertion(operations_ != NULL);
	assertion(operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			operations_->first);
	assertion(operations_->next != NULL);
	assertion(operations_->next->first != NULL);
	assert_expectations_on_stt_operation_example_print_bar(
			operations_->next->first);
	assertion(operations_->next->next == NULL);
#endif

	stt_node_set_operations_list(ret_, operations_);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(ret_->operations_list_subnode_ != NULL);
	assertion(ret_->operations_list_subnode_->operations_ != NULL);
	assertion(ret_->operations_list_subnode_->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			ret_->operations_list_subnode_->operations_->first);
	assertion(ret_->operations_list_subnode_->operations_->next != NULL);
	assertion(ret_->operations_list_subnode_->operations_->next->first !=
			NULL);
	assert_expectations_on_stt_operation_example_print_bar(
			ret_->operations_list_subnode_->operations_->next->first);
	assertion(ret_->operations_list_subnode_->operations_->next->next ==
			NULL);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_operations_list_print_foo_and_then_print_bar(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(node->operations_list_subnode_ != NULL);
	assertion(node->operations_list_subnode_->operations_ != NULL);
	assertion(node->operations_list_subnode_->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			node->operations_list_subnode_->operations_->first);
	assertion(node->operations_list_subnode_->operations_->next != NULL);
	assertion(node->operations_list_subnode_->operations_->next->first !=
			NULL);
	assert_expectations_on_stt_operation_example_print_bar(
			node->operations_list_subnode_->operations_->next->first);
	assertion(node->operations_list_subnode_->operations_->next->next ==
			NULL);
}

#endif

stt_node *
stt_node_example_named_function_print_foo()
{
	stt_node * ret_;
	stt_named_function * named_function_;

	ret_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(ret_ != NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);
#endif

	named_function_ = stt_named_function_example_print_foo();
#ifndef NDEBUG
	assertion(named_function_ != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_);
#endif

	stt_node_set_named_function(ret_, named_function_);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(ret_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_foo(
			ret_->named_function_subnode_);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_named_function_print_foo(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_foo(
			node->named_function_subnode_);
}

#endif

stt_node *
stt_node_example_application_print_foo()
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

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_node_example_application_print_foo(
		const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node->application_subnode_ != NULL);
	assert_expectations_on_stt_application_subnode_example_print_foo(
			node->application_subnode_);
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
#ifndef NDEBUG
	assertion(node_zero_ != NULL);
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
	assertion(node_zero_ != NULL);
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);

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
	assertion(node_zero_ != NULL);
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);

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
#ifndef NDEBUG
	assertion(node_zero_ != NULL);
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
#ifndef NDEBUG
	assertion(node_zero_ != NULL);
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
#ifndef NDEBUG
	assertion(node_zero_ != NULL);
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
#ifndef NDEBUG
	assertion(node_zero_ != NULL);
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
#ifndef NDEBUG
	assertion(node_zero_ != NULL);
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
	stt_where_value_bindings_simple_list_destructor(where_bindings_);
	stt_node_destructor(node_zero_);
}

void
stt_node_copy_constructor_test_36_operation()
{
	stt_node * node_zero_;
	stt_operation * operation_;
	stt_node * node_one_;

	node_zero_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(node_zero_ != NULL);
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);
#endif

	operation_ = stt_operation_example_print_foo();
#ifndef NDEBUG
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(operation_);
#endif

	stt_node_set_operation(node_zero_, operation_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_print_foo(operation_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_zero_->operation_subnode_ != NULL);
	assertion(node_zero_->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			node_zero_->operation_subnode_->operation_);
#endif

	node_one_ = stt_node_copy_constructor(node_zero_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_zero_->operation_subnode_ != NULL);
	assertion(node_zero_->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			node_zero_->operation_subnode_->operation_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_one_->operation_subnode_ != NULL);
	assertion(node_one_->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
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
#ifndef NDEBUG
	assertion(node_zero_ != NULL);
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

	stt_node_destructor(node_one_);
	stt_operations_simple_list_destructor(operations_);
	stt_node_destructor(node_zero_);
}

void
stt_node_copy_constructor_test_40_named_function()
{
	stt_named_function * named_function_;
	stt_node * node_zero_;
	stt_node * node_one_;

	named_function_ = stt_named_function_example_print_foo();
#ifndef NDEBUG
	assertion(named_function_ != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_);
#endif

	node_zero_ = stt_node_default_constructor();
	assertion(node_zero_ != NULL);
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);

	stt_node_set_named_function(node_zero_, named_function_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_zero_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_foo(
			node_zero_->named_function_subnode_);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_);
#endif

	node_one_ = stt_node_copy_constructor(node_zero_);
#ifndef NDEBUG
	assertion(node_zero_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_zero_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_foo(
			node_zero_->named_function_subnode_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_one_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_foo(
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
#ifndef NDEBUG
	assertion(node_zero_ != NULL);
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
#ifndef NDEBUG
	assertion(node_zero_ != NULL);
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

/*

void
stt_node_copy_constructor_test_70_doc()
{
	stt_named_functions_simple_list * named_functions_;
	stt_applications_simple_list * applications_;
	stt_execution_requests_simple_list * execution_requests_;
	stt_node * node_zero_;
	stt_node * node_one_;

	execution_request_ = stt_execution_request_example_print_foo();
#ifndef NDEBUG
	assertion(execution_request_ != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_);
#endif

	node_zero_ = stt_node_default_constructor();
#ifndef NDEBUG
	assertion(node_zero_ != NULL);
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
	assertion(node_zero_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_zero_->execution_request_subnode_ != NULL);
	assert_expectations_on_stt_execution_request_subnode_example_print_foo(
			node_zero_->execution_request_subnode_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_one_->execution_request_subnode_ != NULL);
	assert_expectations_on_stt_execution_request_subnode_example_print_foo(
			node_one_->execution_request_subnode_);
#endif

	stt_node_destructor(node_one_);
	stt_node_destructor(node_zero_);
	stt_execution_request_destructor(execution_request_);
}

*/

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
/*
	stt_node_copy_constructor_test_70_doc();
	*/
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

	operation_ = stt_operation_example_print_foo();
#ifndef NDEBUG
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(operation_);
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
	assert_expectations_on_stt_operation_example_print_foo(
			node_->operation_subnode_->operation_);
#endif

	assert_stt_node_is_valid(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_->operation_subnode_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
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

	named_function_ = stt_named_function_example_print_foo();
#ifndef NDEBUG
	assertion(named_function_ != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_);
#endif

	node_ = stt_node_default_constructor();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);

	stt_node_set_named_function(node_, named_function_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_foo(
			node_->named_function_subnode_);
#endif

	assert_stt_node_is_valid(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_foo(
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
	assertion(application_ != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			application_);

	node_ = stt_node_default_constructor();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);

	stt_node_set_application(node_, application_);
	assertion(node_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_->application_subnode_ != NULL);
	assert_expectations_on_stt_application_subnode_example_print_foo(
			node_->application_subnode_);

	assert_stt_node_is_valid(node_);
	assertion(node_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_->application_subnode_ != NULL);
	assert_expectations_on_stt_application_subnode_example_print_foo(
			node_->application_subnode_);

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

	named_function_ = stt_named_function_example_print_foo();
#ifndef NDEBUG
	assertion(named_function_ != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
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
	assert_expectations_on_stt_named_function_example_print_foo(
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
	assert_expectations_on_stt_doc_subnode_example_print_foo(
			node_->doc_subnode_);
#endif

	assert_stt_node_is_valid(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
	assertion(node_->doc_subnode_ != NULL);
	assert_expectations_on_stt_doc_subnode_example_print_foo(
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

	node_ = stt_node_example_operation_print_foo();
#ifndef NDEBUG
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_->operation_subnode_ != NULL);
	assert_expectations_on_stt_node_example_operation_print_foo(node_);
#endif

	expected_node_type_name_ =
			amara_string_exhaustive_constructor("operation");
#ifndef NDEBUG
	assertion(expected_node_type_name_ != NULL);
	assertion(expected_node_type_name_->value_ != NULL);
#endif

	node_type_name_ = stt_node_type_name(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_->operation_subnode_ != NULL);
	assert_expectations_on_stt_node_example_operation_print_foo(node_);
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

	node_ = stt_node_example_operations_list_print_foo_and_then_print_bar();
#ifndef NDEBUG
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(node_->operations_list_subnode_ != NULL);
	assert_expectations_on_stt_node_example_operations_list_print_foo_and_then_print_bar(
			node_);
#endif

	expected_node_type_name_ =
			amara_string_exhaustive_constructor("operations_list");
#ifndef NDEBUG
	assertion(expected_node_type_name_ != NULL);
	assertion(expected_node_type_name_->value_ != NULL);
#endif

	node_type_name_ = stt_node_type_name(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(node_->operations_list_subnode_ != NULL);
	assert_expectations_on_stt_node_example_operations_list_print_foo_and_then_print_bar(
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

	node_ = stt_node_example_named_function_print_foo();
#ifndef NDEBUG
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_node_example_named_function_print_foo(
			node_);
#endif

	expected_node_type_name_ =
			amara_string_exhaustive_constructor("named_function");
#ifndef NDEBUG
	assertion(expected_node_type_name_ != NULL);
	assertion(expected_node_type_name_->value_ != NULL);
#endif

	node_type_name_ = stt_node_type_name(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_node_example_named_function_print_foo(
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

	node_ = stt_node_example_application_print_foo();
#ifndef NDEBUG
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_->application_subnode_ != NULL);
	assert_expectations_on_stt_node_example_application_print_foo(node_);
#endif

	expected_node_type_name_ =
			amara_string_exhaustive_constructor("application");
#ifndef NDEBUG
	assertion(expected_node_type_name_ != NULL);
	assertion(expected_node_type_name_->value_ != NULL);
#endif

	node_type_name_ = stt_node_type_name(node_);
#ifndef NDEBUG
	assertion(node_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_->application_subnode_ != NULL);
	assert_expectations_on_stt_node_example_application_print_foo(
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
stt_node_type_name_tests()
{
	stt_node_type_name_test_0_operation();
	stt_node_type_name_test_1_operations_list();
	stt_node_type_name_test_2_named_function();
	stt_node_type_name_test_3_application();
}

void
stt_node_tests()
{
	stt_node_copy_constructor_tests();
	stt_node_validation_tests();
	stt_node_type_name_tests();
}
