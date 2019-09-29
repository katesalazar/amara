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
 * src/stt/stt_tests.c: Amara syntax tree tests.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `int strcmp(const char * s1, const char * s2)`. */
#include <string.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_application_tests`. */
#include "stt_application_tests.h"

/*   For `stt_applications_simple_list_tests`. */
#include "stt_applications_simple_list_tests.h"

/*   For `stt_application_subnode_tests`. */
#include "stt_application_subnode_tests.h"

/*   For `void stt_condition_tests()`. */
#include "stt_condition_tests.h"

/*   For `stt_condition_subnode_tests`. */
#include "stt_condition_subnode_tests.h"

/*   For `stt_dice_expression_tests`. */
#include "stt_dice_expression_tests.h"

#include "stt_doc_subnode_tests.h"

/*   For `stt_execution_request_tests`. */
#include "stt_execution_request_tests.h"

/*   For `stt_execution_requests_simple_list_tests`. */
#include "stt_execution_requests_simple_list_tests.h"

/*   For `stt_execution_request_subnode_tests`. */
#include "stt_execution_request_subnode_tests.h"

/*   For `void stt_expression_sub_conditional_tests()`. */
#include "stt_expression_sub_conditional_tests.h"

/*   For `void stt_expression_sub_dice_tests()`. */
#include "stt_expression_sub_dice_tests.h"

/*   For `void stt_expression_sub_identifier_tests()`. */
#include "stt_expression_sub_identifier_tests.h"

/*   For `void stt_expression_tests()`. */
#include "stt_expression_tests.h"

/*   For `void stt_expression_subnode_tests()`. */
#include "stt_expression_subnode_tests.h"

#include "stt_identifier_subnode_tests.h"

#include "stt_integer_literal_subnode_tests.h"

#include "stt_named_function_tests.h"
#include "stt_named_functions_simple_list_tests.h"
#include "stt_named_function_subnode_tests.h"

#include "stt_natural_literal_subnode_tests.h"

/*   For `stt_node`. */
#include "stt_node.h"

#include "stt_node_tests.h"

#include "stt_operation_arg_tests.h"

/*   For `stt_operation_args_simple_list_tests`. */
#include "stt_operation_args_simple_list_tests.h"

/*   For `stt_operation_subnode_tests`. */
#include "stt_operation_subnode_tests.h"

#include "stt_operation_tests.h"

/*   For `stt_operations_list_subnode_tests`. */
#include "stt_operations_list_subnode_tests.h"

/*   For `stt_operations_simple_list_tests`. */
#include "stt_operations_simple_list_tests.h"

#include "stt_rational_literal_subnode_tests.h"

#include "stt_string_literal_subnode_tests.h"

/*   For `stt_where_value_binding_tests`. */
#include "stt_where_value_binding_tests.h"

/*   For `stt_where_value_binding_subnode_tests`. */
#include "stt_where_value_binding_subnode_tests.h"

/*   For `stt_where_value_bindings_simple_list_tests`. */
#include "stt_where_value_bindings_simple_list_tests.h"

/*   For `stt_where_value_bindings_subnode_tests`. */
#include "stt_where_value_bindings_subnode_tests.h"

void
node_name_from_type_test_0()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_test_0()\n", __FILE__, __LINE__);
#endif
	const stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_ = stt_node_type_name(node_);
	const amara_string * expectation_ =
			amara_string_exhaustive_constructor("invalid");
	amara_boolean equality_;

	forced_assertion(expectation_ != NULL);

	equality_ = amara_string_equality(type_name_, expectation_);
	forced_assertion(equality_);

	amara_string_destructor((amara_string *) expectation_);
	amara_string_destructor((amara_string *) type_name_);
	stt_node_destructor(node_);
}

void
node_name_from_type_test_1()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_test_1()\n", __FILE__, __LINE__);
#endif
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	const amara_string * string_literal_;
	amara_boolean equality_;

	forced_assertion(node_ != NULL);

	string_literal_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(string_literal_ != NULL);

	stt_node_set_string_literal(node_, string_literal_);
	forced_assertion(node_->string_literal_subnode_ != NULL);
	forced_assertion(node_->string_literal_subnode_->string_literal_ !=
			NULL);
#ifndef NDEBUG
	equality_ = amara_strings_equality(
			string_literal_,
			node_->string_literal_subnode_->string_literal_);
	assertion(AMARA_BOOLEAN_TRUE == equality_);
#endif

	amara_string_destructor((amara_string *) string_literal_);

	type_name_ = stt_node_type_name(node_);
	forced_assertion(type_name_ != NULL);

	expectation_ = amara_string_exhaustive_constructor("string_literal");
	forced_assertion(expectation_ != NULL);

	equality_ = amara_string_equality(type_name_, expectation_);
	forced_assertion(equality_);

	amara_string_destructor((amara_string *) expectation_);
	amara_string_destructor((amara_string *) type_name_);
	stt_node_destructor(node_);
}

void
node_name_from_type_test_2()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_test_2()\n", __FILE__, __LINE__);
#endif
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	const amara_string * raw_natural_;
	amara_boolean equality_;

	forced_assertion(node_ != NULL);

	raw_natural_ = amara_string_exhaustive_constructor("15");
	forced_assertion(raw_natural_ != NULL);

	stt_node_set_natural_literal(node_, raw_natural_);
	forced_assertion(node_->natural_literal_subnode_ != NULL);
	forced_assertion(node_->natural_literal_subnode_->raw_ != NULL);
#ifndef NDEBUG
	equality_ = amara_strings_equality(
			raw_natural_,
			node_->natural_literal_subnode_->raw_);
	assertion(AMARA_BOOLEAN_TRUE == equality_);
#endif

	amara_string_destructor((amara_string *) raw_natural_);

	type_name_ = stt_node_type_name(node_);
	forced_assertion(type_name_ != NULL);

	expectation_ = amara_string_exhaustive_constructor("natural");
	forced_assertion(expectation_ != NULL);

	equality_ = amara_string_equality(type_name_, expectation_);
	forced_assertion(equality_);

	stt_node_destructor(node_);
	amara_string_destructor((amara_string *) type_name_);
	amara_string_destructor((amara_string *) expectation_);
}

void
node_name_from_type_test_3()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_test_3()\n", __FILE__, __LINE__);
#endif
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	const amara_string * raw_integer_;
	amara_boolean equality_;

	forced_assertion(node_ != NULL);

	raw_integer_ = amara_string_exhaustive_constructor("-1");
	forced_assertion(raw_integer_ != NULL);

	stt_node_set_integer_literal(node_, raw_integer_);

	amara_string_destructor((amara_string *) raw_integer_);

	type_name_ = stt_node_type_name(node_);
	forced_assertion(type_name_ != NULL);

	expectation_ = amara_string_exhaustive_constructor("integer");
	forced_assertion(expectation_ != NULL);

	equality_ = amara_string_equality(type_name_, expectation_);
	forced_assertion(equality_);

	stt_node_destructor(node_);
	amara_string_destructor((amara_string *) type_name_);
	amara_string_destructor((amara_string *) expectation_);
}

void
node_name_from_type_test_4()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_test_4()\n", __FILE__, __LINE__);
#endif
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	const amara_string * raw_rational_literal_;
	amara_boolean equality_;

	forced_assertion(node_ != NULL);

	raw_rational_literal_ = amara_string_exhaustive_constructor(".6");
	forced_assertion(raw_rational_literal_ != NULL);

	stt_node_set_rational_literal(node_, raw_rational_literal_);

	amara_string_destructor((amara_string *) raw_rational_literal_);

	type_name_ = stt_node_type_name(node_);
	forced_assertion(type_name_ != NULL);

	expectation_ = amara_string_exhaustive_constructor("rational");
	forced_assertion(expectation_ != NULL);

	equality_ = amara_string_equality(type_name_, expectation_);
	forced_assertion(equality_);

	stt_node_destructor(node_);
	amara_string_destructor((amara_string *) type_name_);
	amara_string_destructor((amara_string *) expectation_);
}

/*
void
node_name_from_type_test_5()
{
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	amara_boolean equality_;
	node_->type_ = STT_NODE_TYPE_OPERATION;
	type_name_ = stt_node_type_name(node_);
	expectation_ = amara_string_exhaustive_constructor("operation");
	equality_ = amara_string_equality(type_name_, expectation_);
	assertion(equality_);
	amara_string_destructor((amara_string *) expectation_);
	amara_string_destructor((amara_string *) type_name_);
	stt_node_destructor(node_);
}

void
node_name_from_type_test_6()
{
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	amara_boolean equality_;
	node_->type_ = STT_NODE_TYPE_FUNCTION;
	type_name_ = stt_node_type_name(node_);
	expectation_ = amara_string_exhaustive_constructor("function");
	equality_ = amara_string_equality(type_name_, expectation_);
	assertion(equality_);
	amara_string_destructor((amara_string *) expectation_);
	amara_string_destructor((amara_string *) type_name_);
	stt_node_destructor(node_);
}

void
node_name_from_type_test_7()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_test_7()\n", __FILE__, __LINE__);
#endif
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	amara_boolean equality_;
	node_->type_ = STT_NODE_TYPE_APPLICATION;
	type_name_ = stt_node_type_name(node_);
	expectation_ = amara_string_exhaustive_constructor("application");
	equality_ = amara_string_equality(type_name_, expectation_);
	assertion(equality_);
	amara_string_destructor((amara_string *) expectation_);
	amara_string_destructor((amara_string *) type_name_);
	stt_node_destructor(node_);
}
*/

void
node_name_from_type_test_for_identifier_node()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_test_for_identifier_node()\n", __FILE__, __LINE__);
#endif
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	const amara_string * identifier_;
	amara_boolean equality_;

	forced_assertion(node_ != NULL);

	identifier_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(identifier_ != NULL);

	stt_node_set_identifier(node_, identifier_);

	amara_string_destructor((amara_string *) identifier_);

	/*
	node_->type_ = STT_NODE_TYPE_IDENTIFIER;
	*/

	type_name_ = stt_node_type_name(node_);
	forced_assertion(type_name_ != NULL);

	expectation_ = amara_string_exhaustive_constructor("identifier");
	forced_assertion(expectation_ != NULL);

	equality_ = amara_string_equality(type_name_, expectation_);
	forced_assertion(equality_);

	stt_node_destructor(node_);
	amara_string_destructor((amara_string *) type_name_);
	amara_string_destructor((amara_string *) expectation_);
}

void
node_name_from_type_tests()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_tests()\n", __FILE__, __LINE__);
#endif
	node_name_from_type_test_0();
	node_name_from_type_test_1();
	node_name_from_type_test_2();
	node_name_from_type_test_3();
	node_name_from_type_test_4();
	/*
	node_name_from_type_test_5();
	node_name_from_type_test_6();
	node_name_from_type_test_7();
	*/
	node_name_from_type_test_for_identifier_node();
}

void
syntax_tree_tests_()
{
	stt_string_literal_subnode_tests();

	stt_natural_literal_subnode_tests();

	stt_integer_literal_subnode_tests();

	stt_rational_literal_subnode_tests();

	stt_identifier_subnode_tests();

	stt_dice_expression_tests();

	stt_expression_sub_identifier_tests();
	stt_expression_sub_dice_tests();
	stt_expression_sub_conditional_tests();
	stt_expression_tests();
	stt_expression_subnode_tests();

	stt_condition_tests();
	stt_condition_subnode_tests();

	stt_where_value_binding_tests();
	stt_where_value_binding_subnode_tests();
	stt_where_value_bindings_simple_list_tests();
	stt_where_value_bindings_subnode_tests();

	stt_operation_arg_tests();
	stt_operation_args_simple_list_tests();
	stt_operation_tests();
	stt_operation_subnode_tests();
	stt_operations_simple_list_tests();
	stt_operations_list_subnode_tests();

	stt_named_function_tests();
	stt_named_function_subnode_tests();
	stt_named_functions_simple_list_tests();

	stt_application_tests();
	stt_application_subnode_tests();
	stt_applications_simple_list_tests();

	stt_execution_request_tests();
	stt_execution_request_subnode_tests();
	stt_execution_requests_simple_list_tests();

	stt_doc_subnode_tests();

	stt_node_tests();

	node_name_from_type_tests();
}

void
syntax_tree_tests()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void syntax_tree_tests()\n", __FILE__, __LINE__);
#endif
	syntax_tree_tests_();
}
