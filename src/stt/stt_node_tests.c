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
 * src/stt/stt_node_tests.c: Test the Amara syntax tree node.
 */

#include "../asr/assertion.h"

#include "stt_application_subnode_tests.h"
#include "stt_application_tests.h"
#include "stt_doc_subnode_tests.h"
#include "stt_execution_request_tests.h"
#include "stt_execution_request_subnode_tests.h"
#include "stt_named_function_subnode_tests.h"
#include "stt_named_function_tests.h"
#include "stt_node.h"
#include "stt_operation_tests.h"

#include "stt_node_tests.h"

stt_node *
stt_node_example_operation_print_foo()
{
	stt_node * ret_;
	stt_operation * operation_;

	ret_ = stt_node_default_constructor();
	assertion(ret_ != NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);

	operation_ = stt_operation_example_print_foo();
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(operation_);

	stt_node_set_operation(ret_, operation_);
	assertion(ret_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(ret_->operation_subnode_ != NULL);
	assertion(ret_->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			ret_->operation_subnode_->operation_);
	assert_expectations_on_stt_operation_example_print_foo(operation_);

	return ret_;
}

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

stt_node *
stt_node_example_operation_print_bar()
{
	stt_node * ret_;
	stt_operation * operation_;

	ret_ = stt_node_default_constructor();
	assertion(ret_ != NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);

	operation_ = stt_operation_example_print_bar();
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_bar(operation_);

	stt_node_set_operation(ret_, operation_);
	assertion(ret_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(ret_->operation_subnode_ != NULL);
	assertion(ret_->operation_subnode_->operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_bar(
			ret_->operation_subnode_->operation_);
	assert_expectations_on_stt_operation_example_print_bar(operation_);

	return ret_;
}

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

stt_node *
stt_node_example_operations_list_print_foo_and_then_print_bar()
{
	stt_node * ret_;
	stt_operation * operation_zero_;
	stt_operation * operation_one_;
	stt_operations_simple_list * operations_;

	ret_ = stt_node_default_constructor();
	assertion(ret_ != NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);

	operation_zero_ = stt_operation_example_print_bar();
	assertion(operation_zero_ != NULL);
	assert_expectations_on_stt_operation_example_print_bar(
			operation_zero_);

	operation_one_ = stt_operation_example_print_foo();
	assertion(operation_one_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			operation_one_);

	operations_ = stt_operations_simple_list_default_constructor();
	assertion(operations_ != NULL);
	assertion(operations_->first == NULL);
	assertion(operations_->next == NULL);

	operations_ = stt_operations_simple_list_push_front(
			operations_, operation_zero_);
	assertion(operations_ != NULL);
	assertion(operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_bar(
			operations_->first);
	assertion(operations_->next == NULL);

	operations_ = stt_operations_simple_list_push_front(
			operations_, operation_one_);
	assertion(operations_ != NULL);
	assertion(operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			operations_->first);
	assertion(operations_->next != NULL);
	assertion(operations_->next->first != NULL);
	assert_expectations_on_stt_operation_example_print_bar(
			operations_->next->first);
	assertion(operations_->next->next == NULL);

	stt_node_set_operations_list(ret_, operations_);
	assertion(ret_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(ret_->operations_list_subnode_ != NULL);
	assertion(ret_->operations_list_subnode_->operations_ != NULL);
	assertion(ret_->operations_list_subnode_->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			ret_->operations_list_subnode_->operations_->first);
	assertion(ret_->operations_list_subnode_->operations_->next != NULL);
	assertion(ret_->operations_list_subnode_->operations_->next->first != NULL);
	assert_expectations_on_stt_operation_example_print_bar(
			ret_->operations_list_subnode_->operations_->next->first);
	assertion(ret_->operations_list_subnode_->operations_->next->next == NULL);

	return ret_;
}

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

stt_node *
stt_node_example_named_function_print_foo()
{
	stt_node * ret_;
	stt_named_function * named_function_;

	ret_ = stt_node_default_constructor();
	assertion(ret_ != NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);

	named_function_ = stt_named_function_example_print_foo();
	assertion(named_function_ != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_);

	stt_node_set_named_function(ret_, named_function_);
	assertion(ret_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(ret_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_foo(
			ret_->named_function_subnode_);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_);

	return ret_;
}

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

stt_node *
stt_node_example_application_print_foo()
{
	stt_node * ret_;
	stt_application * application_;

	ret_ = stt_node_default_constructor();
	assertion(ret_ != NULL);
	assertion(ret_->type_ == STT_NODE_TYPE_INVALID);

	application_ = stt_application_example_print_foo();
	assertion(application_ != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			application_);

	stt_node_set_application(ret_, application_);
	assertion(ret_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(ret_->application_subnode_ != NULL);
	assert_expectations_on_stt_application_subnode_example_print_foo(
			ret_->application_subnode_);
	assert_expectations_on_stt_application_example_print_foo(
			application_);

	return ret_;
}

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

void
stt_node_copy_constructor_test_0_integer_literal()
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
stt_node_copy_constructor_test_1_rational_literal()
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
stt_node_copy_constructor_test_2_named_function()
{
	stt_named_function * named_function_;
	stt_node * node_zero_;
	stt_node * node_one_;

	named_function_ = stt_named_function_example_print_foo();
	assertion(named_function_ != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_);

	node_zero_ = stt_node_default_constructor();
	assertion(node_zero_ != NULL);
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);

	stt_node_set_named_function(node_zero_, named_function_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_zero_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_foo(
			node_zero_->named_function_subnode_);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_);

	node_one_ = stt_node_copy_constructor(node_zero_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_zero_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_foo(
			node_zero_->named_function_subnode_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_one_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_foo(
			node_one_->named_function_subnode_);

	stt_node_destructor(node_one_);
	stt_node_destructor(node_zero_);
	stt_named_function_destructor(named_function_);
}

void
stt_node_copy_constructor_test_3_application()
{
	stt_application * application_;
	stt_node * node_zero_;
	stt_node * node_one_;

	application_ = stt_application_example_print_foo();
	assertion(application_ != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			application_);

	node_zero_ = stt_node_default_constructor();
	assertion(node_zero_ != NULL);
	assertion(node_zero_->type_ == STT_NODE_TYPE_INVALID);

	stt_node_set_application(node_zero_, application_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_zero_->application_subnode_ != NULL);
	assert_expectations_on_stt_application_subnode_example_print_foo(
			node_zero_->application_subnode_);
	assert_expectations_on_stt_application_example_print_foo(
			application_);

	node_one_ = stt_node_copy_constructor(node_zero_);
	assertion(node_zero_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_zero_->application_subnode_ != NULL);
	assert_expectations_on_stt_application_subnode_example_print_foo(
			node_zero_->application_subnode_);
	assertion(node_one_ != NULL);
	assertion(node_one_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_one_->application_subnode_ != NULL);
	assert_expectations_on_stt_application_subnode_example_print_foo(
			node_one_->application_subnode_);

	stt_node_destructor(node_one_);
	stt_node_destructor(node_zero_);
	stt_application_destructor(application_);
}

void
stt_node_copy_constructor_tests()
{
	stt_node_copy_constructor_test_0_integer_literal();
	stt_node_copy_constructor_test_1_rational_literal();
	stt_node_copy_constructor_test_2_named_function();
	stt_node_copy_constructor_test_3_application();
}

void
stt_node_validation_test_0_integer_literal()
{
	stt_node * node_;
	amara_string * raw_integer_literal_;
	amara_boolean equality_;

	node_ = stt_node_default_constructor();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);

	raw_integer_literal_ = amara_string_exhaustive_constructor("-1");
	assertion(raw_integer_literal_ != NULL);
	assertion(raw_integer_literal_->value_ != NULL);

	stt_node_set_integer_literal(node_, raw_integer_literal_);
	assertion(node_->type_ == STT_NODE_TYPE_INTEGER_LITERAL);
	assertion(node_->integer_literal_subnode_ != NULL);
	assertion(node_->integer_literal_subnode_->raw_ != NULL);
	assertion(node_->integer_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_integer_literal_,
			node_->integer_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	assert_stt_node_is_valid(node_);
	assertion(node_->type_ == STT_NODE_TYPE_INTEGER_LITERAL);
	assertion(node_->integer_literal_subnode_ != NULL);
	assertion(node_->integer_literal_subnode_->raw_ != NULL);
	assertion(node_->integer_literal_subnode_->raw_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_integer_literal_,
			node_->integer_literal_subnode_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(raw_integer_literal_);
	stt_node_destructor(node_);
}

void
stt_node_validation_test_1_rational_literal()
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
stt_node_validation_test_2_identifier()
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
stt_node_validation_test_3_operation()
{
	stt_node * node_;
	stt_operation * operation_;

	operation_ = stt_operation_example_print_foo();
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(operation_);

	node_ = stt_node_default_constructor();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);

	stt_node_set_operation(node_, operation_);
	assertion(node_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_->operation_subnode_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			node_->operation_subnode_->operation_);

	assert_stt_node_is_valid(node_);
	assertion(node_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_->operation_subnode_ != NULL);
	assert_expectations_on_stt_operation_example_print_foo(
			node_->operation_subnode_->operation_);

	stt_node_destructor(node_);
	stt_operation_destructor(operation_);
}

/**  XXX arguable an empty operations list cannot make a valid syntax
 * tree node. */
void
stt_node_validation_test_4_operations_list()
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
stt_node_validation_test_5_named_function()
{
	stt_node * node_;
	stt_named_function * named_function_;

	named_function_ = stt_named_function_example_print_foo();
	assertion(named_function_ != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_);

	node_ = stt_node_default_constructor();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);

	stt_node_set_named_function(node_, named_function_);
	assertion(node_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_foo(
			node_->named_function_subnode_);

	assert_stt_node_is_valid(node_);
	assertion(node_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_named_function_subnode_example_print_foo(
			node_->named_function_subnode_);

	stt_node_destructor(node_);
	stt_named_function_destructor(named_function_);
}

void
stt_node_validation_test_6_application()
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
stt_node_validation_test_7_execution_request()
{
	stt_node * node_;
	stt_execution_request * execution_request_;

	execution_request_ = stt_execution_request_example_print_foo();
	assertion(execution_request_ != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_);

	node_ = stt_node_default_constructor();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);

	stt_node_set_execution_request(node_, execution_request_);
	assertion(node_->type_ == STT_NODE_TYPE_EXECUTION_REQUEST);
	assertion(node_->execution_request_subnode_ != NULL);
	assert_expectations_on_stt_execution_request_subnode_example_print_foo(
			node_->execution_request_subnode_);

	assert_stt_node_is_valid(node_);
	assertion(node_->type_ == STT_NODE_TYPE_EXECUTION_REQUEST);
	assertion(node_->execution_request_subnode_ != NULL);
	assert_expectations_on_stt_execution_request_subnode_example_print_foo(
			node_->execution_request_subnode_);

	stt_node_destructor(node_);
	stt_execution_request_destructor(execution_request_);
}

/**  Friend declaration of private function in `stt_node.c` (so testing
 * an owned function. */
void
assert_all_subnodes_are_null(const stt_node * node)
;

void
stt_node_validation_test_8_doc()
{
	stt_named_function * named_function_;
	stt_named_functions_simple_list * named_functions_;
	stt_application * application_;
	stt_applications_simple_list * applications_;
	stt_execution_request * execution_request_;
	stt_execution_requests_simple_list * execution_requests_;
	stt_node * node_;

	named_function_ = stt_named_function_example_print_foo();
	assertion(named_function_ != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_function_);

	named_functions_ =
			stt_named_functions_simple_list_default_constructor();
	assertion(named_functions_ != NULL);
	assertion(named_functions_->first == NULL);
	assertion(named_functions_->next == NULL);

	named_functions_ = stt_named_functions_simple_list_push_front(
			named_functions_, named_function_);
	assertion(named_functions_ != NULL);
	assertion(named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_foo(
			named_functions_->first);
	assertion(named_functions_->next == NULL);

	application_ = stt_application_example_print_foo();
	assertion(application_ != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			application_);

	applications_ = stt_applications_simple_list_default_constructor();
	assertion(applications_ != NULL);
	assertion(applications_->first == NULL);
	assertion(applications_->next == NULL);

	applications_ = stt_applications_simple_list_push_front(
			applications_, application_);
	assertion(applications_ != NULL);
	assertion(applications_->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			applications_->first);
	assertion(applications_->next == NULL);

	execution_request_ = stt_execution_request_example_print_foo();
	assertion(execution_request_ != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_request_);

	execution_requests_ =
			stt_execution_requests_simple_list_default_constructor();
	assertion(execution_requests_ != NULL);
	assertion(execution_requests_->first == NULL);
	assertion(execution_requests_->next == NULL);

	execution_requests_ = stt_execution_requests_simple_list_push_front(
			execution_requests_, execution_request_);
	assertion(execution_requests_ != NULL);
	assertion(execution_requests_->first != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			execution_requests_->first);
	assertion(execution_requests_->next == NULL);

	node_ = stt_node_default_constructor();
	assertion(node_ != NULL);
	assert_all_subnodes_are_null(node_);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);

	stt_node_set_doc(node_, named_functions_, applications_,
	                 execution_requests_);
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
	assertion(node_->doc_subnode_ != NULL);
	assert_expectations_on_stt_doc_subnode_example_print_foo(
			node_->doc_subnode_);

	assert_stt_node_is_valid(node_);
	assertion(node_->type_ == STT_NODE_TYPE_DOC);
	assertion(node_->doc_subnode_ != NULL);
	assert_expectations_on_stt_doc_subnode_example_print_foo(
			node_->doc_subnode_);

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
	stt_node_validation_test_0_integer_literal();
	stt_node_validation_test_1_rational_literal();
	stt_node_validation_test_2_identifier();
	stt_node_validation_test_3_operation();
	stt_node_validation_test_4_operations_list();
	stt_node_validation_test_5_named_function();
	stt_node_validation_test_6_application();
	stt_node_validation_test_7_execution_request();
	stt_node_validation_test_8_doc();
}

void
stt_node_type_name_test_0_operation()
{
	stt_node * node_;
	amara_string * expected_node_type_name_;
	amara_string * node_type_name_;
	amara_boolean equality_;

	node_ = stt_node_example_operation_print_foo();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_->operation_subnode_ != NULL);
	assert_expectations_on_stt_node_example_operation_print_foo(node_);

	expected_node_type_name_ =
			amara_string_exhaustive_constructor("operation");
	assertion(expected_node_type_name_ != NULL);
	assertion(expected_node_type_name_->value_ != NULL);

	node_type_name_ = stt_node_type_name(node_);
	assertion(node_->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node_->operation_subnode_ != NULL);
	assert_expectations_on_stt_node_example_operation_print_foo(node_);
	assertion(node_type_name_ != NULL);
	assertion(node_type_name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_node_type_name_, node_type_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

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
	amara_boolean equality_;

	node_ = stt_node_example_operations_list_print_foo_and_then_print_bar();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(node_->operations_list_subnode_ != NULL);
	assert_expectations_on_stt_node_example_operations_list_print_foo_and_then_print_bar(
			node_);

	expected_node_type_name_ =
			amara_string_exhaustive_constructor("operations_list");
	assertion(expected_node_type_name_ != NULL);
	assertion(expected_node_type_name_->value_ != NULL);

	node_type_name_ = stt_node_type_name(node_);
	assertion(node_->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(node_->operations_list_subnode_ != NULL);
	assert_expectations_on_stt_node_example_operations_list_print_foo_and_then_print_bar(
			node_);
	assertion(node_type_name_ != NULL);
	assertion(node_type_name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_node_type_name_, node_type_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

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
	amara_boolean equality_;

	node_ = stt_node_example_named_function_print_foo();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_node_example_named_function_print_foo(
			node_);

	expected_node_type_name_ =
			amara_string_exhaustive_constructor("named_function");
	assertion(expected_node_type_name_ != NULL);
	assertion(expected_node_type_name_->value_ != NULL);

	node_type_name_ = stt_node_type_name(node_);
	assertion(node_->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node_->named_function_subnode_ != NULL);
	assert_expectations_on_stt_node_example_named_function_print_foo(
			node_);
	assertion(node_type_name_ != NULL);
	assertion(node_type_name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_node_type_name_, node_type_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

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
	amara_boolean equality_;

	node_ = stt_node_example_application_print_foo();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_->application_subnode_ != NULL);
	assert_expectations_on_stt_node_example_application_print_foo(node_);

	expected_node_type_name_ =
			amara_string_exhaustive_constructor("application");
	assertion(expected_node_type_name_ != NULL);
	assertion(expected_node_type_name_->value_ != NULL);

	node_type_name_ = stt_node_type_name(node_);
	assertion(node_->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node_->application_subnode_ != NULL);
	assert_expectations_on_stt_node_example_application_print_foo(
			node_);
	assertion(node_type_name_ != NULL);
	assertion(node_type_name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_node_type_name_, node_type_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

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
