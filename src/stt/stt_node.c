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
 * src/stt/stt_node.c: Amara syntax tree node.
 */

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `void * malloc(size_t size)`. */
/* #include <stdlib.h> */

/*   For `int strcmp(const char * s1, const char * s2)`. */
/* #include <string.h> */

/*   For custom assertions. */
#include "../asr/assertion.h"

/*   For `char * concatenate_four_char_arrays(const char * zero, const
 * char * one, const char * two, cont char * three)`. */
#include "../cmn/char_array.h"

/*   For `stt_operations_simple_list_copy_constructor`. */
#include "stt_operations_simple_list.h"

/*   For own definitions. */
#include "stt_node.h"

stt_node *
stt_node_default_constructor()
{
	stt_node * returning_ = malloc(sizeof(stt_node));
	returning_->type_ = SYNTAX_TREE_NODE_TYPE_INVALID;
	returning_->string_literal_subnode_ = NULL;
	returning_->natural_literal_subnode_ = NULL;
	returning_->integer_literal_subnode_ = NULL;
	returning_->rational_literal_subnode_ = NULL;
	returning_->operation_subnode_ = NULL;
	returning_->named_function_subnode_ = NULL;
	returning_->application_subnode_ = NULL;
	returning_->identifier_subnode_ = NULL;
	returning_->operations_list_subnode_ = NULL;
	returning_->doc_subnode_ = NULL;
	returning_->execution_request_subnode_ = NULL;
	return returning_;
}

void
assert_stt_node_is_valid(const stt_node * node)
{
	assertion(node->type_ != SYNTAX_TREE_NODE_TYPE_INVALID);
	if (node->type_ == SYNTAX_TREE_NODE_TYPE_STRING_LITERAL) {
		assertion(node->string_literal_subnode_ != NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
	} else if (node->type_ == SYNTAX_TREE_NODE_TYPE_NATURAL) {
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ != NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
	} else if (node->type_ == STT_NODE_TYPE_INTEGER_LITERAL) {
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ != NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
	} else if (node->type_ == SYNTAX_TREE_NODE_TYPE_RATIONAL) {
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ != NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
	} else if (node->type_ == SYNTAX_TREE_NODE_TYPE_OPERATION) {
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ != NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
	} else if (node->type_ == STT_NODE_TYPE_NAMED_FUNCTION) {
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ != NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
	} else if (node->type_ == SYNTAX_TREE_NODE_TYPE_APPLICATION) {
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ != NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
	} else if (node->type_ == SYNTAX_TREE_NODE_TYPE_IDENTIFIER) {
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ != NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
	} else if (node->type_ == SYNTAX_TREE_NODE_TYPE_OPERATIONS_LIST) {
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ != NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
	} else if (node->type_ == SYNTAX_TREE_NODE_TYPE_DOC) {
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ != NULL);
		assertion(node->execution_request_subnode_ == NULL);
	} else {
		assertion(node->type_ ==
				SYNTAX_TREE_NODE_TYPE_EXECUTION_REQUEST);
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ != NULL);
	}
}

stt_node *
stt_node_copy_constructor(const stt_node * node)
{
	stt_node * ret_;
	assertion(node->type_ != SYNTAX_TREE_NODE_TYPE_INVALID);
	ret_ = stt_node_default_constructor();
	if (node->type_ == SYNTAX_TREE_NODE_TYPE_STRING_LITERAL) {
		assert_pure_string_literal_node(node);
		ret_->string_literal_subnode_ =
				stt_string_literal_subnode_copy_constructor(
						node->string_literal_subnode_);
		ret_->type_ = SYNTAX_TREE_NODE_TYPE_STRING_LITERAL;
		return ret_;
	}
	if (node->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
		assert_pure_natural_literal_node(node);
		ret_->natural_literal_subnode_ =
				stt_natural_literal_subnode_copy_constructor(
						node->natural_literal_subnode_);
		ret_->type_ = STT_NODE_TYPE_NATURAL_LITERAL;
		return ret_;
	}
	if (node->type_ == STT_NODE_TYPE_INTEGER_LITERAL) {
		assert_pure_integer_literal_node(node);
		ret_->integer_literal_subnode_ =
				stt_integer_literal_subnode_copy_constructor(
						node->integer_literal_subnode_);
		ret_->type_ = STT_NODE_TYPE_INTEGER_LITERAL;
		return ret_;
	}
	if (node->type_ == SYNTAX_TREE_NODE_TYPE_RATIONAL) {
		assert_pure_rational_literal_node(node);
		ret_->rational_literal_subnode_ =
				stt_rational_literal_subnode_copy_constructor(
						node->rational_literal_subnode_);
		ret_->type_ = SYNTAX_TREE_NODE_TYPE_RATIONAL;
		return ret_;
	}
	if (node->type_ == SYNTAX_TREE_NODE_TYPE_OPERATION) {
		assert_pure_operation_node(node);
		ret_->operation_subnode_ =
				stt_operation_subnode_copy_constructor(
						node->operation_subnode_);
		ret_->type_ = SYNTAX_TREE_NODE_TYPE_OPERATION;
		return ret_;
	}
	if (node->type_ == STT_NODE_TYPE_NAMED_FUNCTION) {
		assert_pure_named_function_node(node);
		ret_->named_function_subnode_ =
				stt_named_function_subnode_copy_constructor(
						node->named_function_subnode_);
		ret_->type_ = STT_NODE_TYPE_NAMED_FUNCTION;
		return ret_;
	}
	if (node->type_ == SYNTAX_TREE_NODE_TYPE_APPLICATION) {
		assert_pure_application_node(node);
		ret_->application_subnode_ =
				stt_application_subnode_copy_constructor(
						node->application_subnode_);
		ret_->type_ = SYNTAX_TREE_NODE_TYPE_APPLICATION;
		return ret_;
	}
	if (node->type_ == SYNTAX_TREE_NODE_TYPE_IDENTIFIER) {
		assert_pure_identifier_node(node);
		ret_->identifier_subnode_ =
				stt_identifier_subnode_copy_constructor(
						node->identifier_subnode_);
		ret_->type_ = SYNTAX_TREE_NODE_TYPE_IDENTIFIER;
		return ret_;
	}
	if (node->type_ == SYNTAX_TREE_NODE_TYPE_OPERATIONS_LIST) {
		assert_pure_operations_list_node(node);
		ret_->operations_list_subnode_ =
				stt_operations_list_subnode_copy_constructor(
						node->operations_list_subnode_);
		ret_->type_ = SYNTAX_TREE_NODE_TYPE_OPERATIONS_LIST;
		return ret_;
	}
	if (node->type_ == SYNTAX_TREE_NODE_TYPE_DOC) {
		assert_pure_doc_node(node);
		ret_->doc_subnode_ = stt_doc_subnode_copy_constructor(
				node->doc_subnode_);
		ret_->type_ = SYNTAX_TREE_NODE_TYPE_DOC;
		return ret_;
	}
	if (node->type_ == SYNTAX_TREE_NODE_TYPE_EXECUTION_REQUEST) {
		assert_pure_execution_request_node(node);
		ret_->execution_request_subnode_ =
				stt_execution_request_subnode_copy_constructor(
						node->execution_request_subnode_);
		ret_->type_ = SYNTAX_TREE_NODE_TYPE_EXECUTION_REQUEST;
		return ret_;
	}
	assertion_two(AMARA_BOOLEAN_FALSE, "reached unreachable code");
	ret_->type_ = SYNTAX_TREE_NODE_TYPE_INVALID;
	return ret_;
}

stt_node *
stt_node_wrapping_raw_natural(const amara_string * raw_natural)
{
	stt_node * returning_;
	amara_string * copy_;
	returning_ = stt_node_default_constructor();
	copy_ = amara_string_copy_constructor(raw_natural);
	returning_->natural_literal_subnode_ =
			stt_natural_literal_subnode_exhaustive_constructor(
					copy_);
	amara_string_destructor(copy_);
	returning_->type_ = SYNTAX_TREE_NODE_TYPE_NATURAL;
	return returning_;
}

void
assert_all_subnodes_are_null(const stt_node * node)
;

void
assert_all_subnodes_are_null(const stt_node * node)
{
	assertion(node->string_literal_subnode_ == NULL);
	assertion(node->natural_literal_subnode_ == NULL);
	assertion(node->integer_literal_subnode_ == NULL);
	assertion(node->rational_literal_subnode_ == NULL);
	assertion(node->operation_subnode_ == NULL);
	assertion(node->named_function_subnode_ == NULL);
	assertion(node->application_subnode_ == NULL);
	assertion(node->identifier_subnode_ == NULL);
	assertion(node->operations_list_subnode_ == NULL);
	assertion(node->doc_subnode_ == NULL);
	assertion(node->execution_request_subnode_ == NULL);
	assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_INVALID);
}

void
stt_node_destructor(stt_node const * node)
{
	switch (node->type_) {
	case SYNTAX_TREE_NODE_TYPE_STRING_LITERAL:
		assertion(node->string_literal_subnode_ != NULL);
		stt_string_literal_subnode_destructor(
				node->string_literal_subnode_);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
		break;
	case SYNTAX_TREE_NODE_TYPE_NATURAL:
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ != NULL);
		stt_natural_literal_subnode_destructor(
				node->natural_literal_subnode_);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
		break;
	case STT_NODE_TYPE_INTEGER_LITERAL:
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ != NULL);
		stt_integer_literal_subnode_destructor(
				node->integer_literal_subnode_);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
		break;
	case SYNTAX_TREE_NODE_TYPE_RATIONAL:
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ != NULL);
		stt_rational_literal_subnode_destructor(
				node->rational_literal_subnode_);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
		break;
	case SYNTAX_TREE_NODE_TYPE_OPERATION:
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ != NULL);
		stt_operation_subnode_destructor(node->operation_subnode_);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
		break;
	case STT_NODE_TYPE_NAMED_FUNCTION:
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ != NULL);
		stt_named_function_subnode_destructor(
				node->named_function_subnode_);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
		break;
	case SYNTAX_TREE_NODE_TYPE_APPLICATION:
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ != NULL);
		stt_application_subnode_destructor(node->application_subnode_);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
		break;
	case SYNTAX_TREE_NODE_TYPE_IDENTIFIER:
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ != NULL);
		stt_identifier_subnode_destructor(node->identifier_subnode_);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
		break;
	case SYNTAX_TREE_NODE_TYPE_OPERATIONS_LIST:
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ != NULL);
		stt_operations_list_subnode_destructor(
				node->operations_list_subnode_);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ == NULL);
		break;
	case SYNTAX_TREE_NODE_TYPE_DOC:
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ != NULL);
		stt_doc_subnode_destructor(node->doc_subnode_);
		assertion(node->execution_request_subnode_ == NULL);
		break;
	case SYNTAX_TREE_NODE_TYPE_EXECUTION_REQUEST:
		assertion(node->string_literal_subnode_ == NULL);
		assertion(node->natural_literal_subnode_ == NULL);
		assertion(node->integer_literal_subnode_ == NULL);
		assertion(node->rational_literal_subnode_ == NULL);
		assertion(node->operation_subnode_ == NULL);
		assertion(node->named_function_subnode_ == NULL);
		assertion(node->application_subnode_ == NULL);
		assertion(node->identifier_subnode_ == NULL);
		assertion(node->operations_list_subnode_ == NULL);
		assertion(node->doc_subnode_ == NULL);
		assertion(node->execution_request_subnode_ != NULL);
		stt_execution_request_subnode_destructor(
				node->execution_request_subnode_);
		break;
	default:
		assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_INVALID);
		assert_all_subnodes_are_null(node);
		break;
	}
	free((stt_node *) node);
}

void
stt_node_set_string_literal(
		stt_node * node, const amara_string * string_literal)
{
	assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_INVALID);
	assert_all_subnodes_are_null(node);
	node->string_literal_subnode_ =
			stt_string_literal_subnode_exhaustive_constructor(
					string_literal);
	node->type_ = SYNTAX_TREE_NODE_TYPE_STRING_LITERAL;
}

void
stt_node_set_natural_literal(
		stt_node * node, const amara_string * raw_natural_literal)
{
	assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_INVALID);
	assert_all_subnodes_are_null(node);
	node->natural_literal_subnode_ =
			stt_natural_literal_subnode_exhaustive_constructor(
					raw_natural_literal);
	node->type_ = SYNTAX_TREE_NODE_TYPE_NATURAL;
}

void
stt_node_set_integer_literal(
		stt_node * node, const amara_string * raw_integer_literal)
{
	assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_INVALID);
	assert_all_subnodes_are_null(node);
	node->integer_literal_subnode_ =
			stt_integer_literal_subnode_exhaustive_constructor(
					raw_integer_literal);
	node->type_ = STT_NODE_TYPE_INTEGER_LITERAL;
}

void
stt_node_set_rational_literal(
		stt_node * node, const amara_string * raw_rational_literal)
{
	assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_INVALID);
	assert_all_subnodes_are_null(node);
	node->rational_literal_subnode_ =
			stt_rational_literal_subnode_exhaustive_constructor(
					raw_rational_literal);
	node->type_ = SYNTAX_TREE_NODE_TYPE_RATIONAL;
}

void
stt_node_set_identifier(stt_node * node, const amara_string * identifier)
{
	assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_INVALID);
	assert_all_subnodes_are_null(node);
	node->identifier_subnode_ =
			stt_identifier_subnode_exhaustive_constructor(
					identifier);
	node->type_ = SYNTAX_TREE_NODE_TYPE_IDENTIFIER;
}

void
stt_node_set_operation(stt_node * node, const stt_operation * operation)
{
	assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_INVALID);
	assert_all_subnodes_are_null(node);
	node->operation_subnode_ =
			stt_operation_subnode_exhaustive_constructor(
					operation);
	node->type_ = SYNTAX_TREE_NODE_TYPE_OPERATION;
}

void
stt_node_set_operations_list(
		stt_node * node, const stt_operations_simple_list * operations)
{
	assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_INVALID);
	assert_all_subnodes_are_null(node);
	node->operations_list_subnode_ =
			stt_operations_list_subnode_exhaustive_constructor(
					operations);
	node->type_ = STT_NODE_TYPE_OPERATIONS_LIST;
}

void
stt_node_set_named_function(
		stt_node * node, const stt_named_function * named_function)
{
	assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_INVALID);
	assert_all_subnodes_are_null(node);
	node->named_function_subnode_ =
			stt_named_function_subnode_exhaustive_constructor(
					named_function);
	node->type_ = STT_NODE_TYPE_NAMED_FUNCTION;
}

void
stt_node_set_application(stt_node * node, const stt_application * application)
{
	assertion(node->type_ == STT_NODE_TYPE_INVALID);
	assert_all_subnodes_are_null(node);
	node->application_subnode_ =
			stt_application_subnode_exhaustive_constructor(
					application);
	node->type_ = STT_NODE_TYPE_APPLICATION;
}

void
stt_node_set_execution_request(stt_node * node,
                               const stt_execution_request * execution_request)
{
	assertion(node->type_ == STT_NODE_TYPE_INVALID);
	assert_all_subnodes_are_null(node);
	node->execution_request_subnode_ =
			stt_execution_request_subnode_exhaustive_constructor(
					execution_request);
	node->type_ = STT_NODE_TYPE_EXECUTION_REQUEST;
}

void
stt_node_set_doc(
		stt_node * node,
		const stt_named_functions_simple_list * named_functions,
		const stt_applications_simple_list * applications,
		const stt_execution_requests_simple_list * execution_requests)
{
	assertion(node->type_ == STT_NODE_TYPE_INVALID);
	assert_all_subnodes_are_null(node);
	node->doc_subnode_ = stt_doc_subnode_exhaustive_constructor(
			named_functions, applications, execution_requests);
	node->type_ = STT_NODE_TYPE_DOC;
}

amara_string *
stt_node_type_name(const stt_node * node)
{
	switch (node->type_) {
	case SYNTAX_TREE_NODE_TYPE_STRING_LITERAL:
		return amara_string_exhaustive_constructor("string_literal");
	case SYNTAX_TREE_NODE_TYPE_NATURAL:
		return amara_string_exhaustive_constructor("natural");
	case STT_NODE_TYPE_INTEGER_LITERAL:
		return amara_string_exhaustive_constructor("integer");
	case SYNTAX_TREE_NODE_TYPE_RATIONAL:
		return amara_string_exhaustive_constructor("rational");
	case SYNTAX_TREE_NODE_TYPE_OPERATION:
		return amara_string_exhaustive_constructor("operation");
	case STT_NODE_TYPE_NAMED_FUNCTION:
		return amara_string_exhaustive_constructor("named_function");
	case SYNTAX_TREE_NODE_TYPE_APPLICATION:
		return amara_string_exhaustive_constructor("application");
	case SYNTAX_TREE_NODE_TYPE_IDENTIFIER:
		return amara_string_exhaustive_constructor("identifier");
	case SYNTAX_TREE_NODE_TYPE_OPERATIONS_LIST:
		return amara_string_exhaustive_constructor("operations_list");
	case SYNTAX_TREE_NODE_TYPE_DOC:
		return amara_string_exhaustive_constructor("doc");
	case SYNTAX_TREE_NODE_TYPE_EXECUTION_REQUEST:
		return amara_string_exhaustive_constructor(
				"execution_request");
	default:
		assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_INVALID);
		return amara_string_exhaustive_constructor("invalid");
	}
}

stt_node *
register_named_function(stt_node * node, const stt_node * named_function_node)
{
	stt_named_function * new_named_function_;
	stt_named_functions_simple_list * new_named_functions_list_node_;
	assertion_two(node != NULL, "unexpected value NULL for `node`");
	if (node->type_ != SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT) {
		fprintf(stderr, "%s:%u:%u\n", __FILE__, __LINE__, node->type_);
	}
	assertion_two(node->type_ == SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT,
	              "unexpected value for `node->type`");
	assertion_two(node->doc_subnode_ != NULL,
			"unexpected value for `node->doc`");
	assertion_two(named_function_node != NULL,
			"`named_function_node` unexepectedly NULL");
	assertion_two(
			named_function_node->type_ ==
					STT_NODE_TYPE_NAMED_FUNCTION,
			"unexpected value at `named_function_node->type`");
	new_named_function_ = malloc(sizeof(stt_named_function));
	new_named_function_->name_ = amara_string_copy_constructor(
			named_function_node->named_function_subnode_->name_);
	new_named_function_->operations_ =
			stt_operations_simple_list_copy_constructor(
					named_function_node->named_function_subnode_->operations_);
	new_named_function_->type_ =
			named_function_node->named_function_subnode_->type_;
	new_named_functions_list_node_ =
			malloc(sizeof(stt_named_functions_simple_list));
	new_named_functions_list_node_->first = new_named_function_;
	new_named_functions_list_node_->next =
			node->doc_subnode_->named_functions_;
	node->doc_subnode_->named_functions_ = new_named_functions_list_node_;
	return node;
}

stt_node *
register_application(stt_node * node, const stt_node * application_node)
{
	stt_application * new_application_;
	stt_applications_simple_list * new_applications_list_node_;
	assertion_two(node != NULL, "unexpected value NULL for `node`");
	if (node->type_ != SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT) {
		fprintf(stderr, "%s:%u:%u\n", __FILE__, __LINE__, node->type_);
	}
	assertion_two(node->type_ == SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT,
	              "unexpected value %u for `node->type`");
	assertion_two(node->doc_subnode_ != NULL,
			"unexpected value for `node->doc`");
	assertion_two(application_node != NULL,
			"`application_node` unexpectedly NULL");
	assertion_two(application_node->type_ ==
			SYNTAX_TREE_NODE_TYPE_APPLICATION,
			"unexpected value at `application_node->type`");
	new_application_ = malloc(sizeof(stt_application));
	new_application_->name_ =
			application_node->application_subnode_->name_;
	new_application_->type_ =
			application_node->application_subnode_->type_;
	new_application_->entry_point_function_name_ =
			application_node->application_subnode_
					->entry_point_function_name_;
	new_applications_list_node_ =
			malloc(sizeof(stt_applications_simple_list));
	new_applications_list_node_->first = new_application_;
	new_applications_list_node_->next = node->doc_subnode_->applications_;
	node->doc_subnode_->applications_ = new_applications_list_node_;
	return node;
}

stt_node *
register_execution_request(
		stt_node * node, const stt_node * execution_request_node)
{
	stt_execution_request * new_execution_request_;
	stt_execution_requests_simple_list * new_execution_requests_list_node_;
	assertion_two(node != NULL, "unexpected value NULL for `node`");
	if (node->type_ != SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT) {
		fprintf(stderr, "%s:%u:%u\n", __FILE__, __LINE__, node->type_);
	}
	assertion_two(node->type_ == SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT,
	              "unexpected value %u for `node->type`");
	assertion_two(node->doc_subnode_ != NULL,
			"unexpected value for `node->doc_subnode_`");
	assertion_two(execution_request_node != NULL,
			"`execution_request_node` unexpectedly NULL");
	assertion_two(execution_request_node->type_ ==
			SYNTAX_TREE_NODE_TYPE_EXECUTION_REQUEST,
			"unexpected value at `execution_request_node->type_`");
	new_execution_request_ = malloc(sizeof(stt_execution_request));
	new_execution_request_->type_ =
			execution_request_node->execution_request_subnode_->type_;
	new_execution_request_->application_name_ =
			execution_request_node->execution_request_subnode_->application_name_;
	new_execution_requests_list_node_ =
			malloc(sizeof(stt_execution_requests_simple_list));
	new_execution_requests_list_node_->first = new_execution_request_;
	new_execution_requests_list_node_->next =
			node->doc_subnode_->execution_requests_;
	node->doc_subnode_->execution_requests_ =
			new_execution_requests_list_node_;
	return node;
}

void
dump_syntax_tree(const stt_node * node)
{
	unsigned char named_functions_len_;
	stt_applications_simple_list * applications_ptr_;
	unsigned char applications_len_;
	stt_application * application_;
	char * entry_point_function_name_chars_array_;
	fprintf(stderr, "%s:%u ----> void dump_syntax_tree(const stt_node *)\n",
			__FILE__, __LINE__);
	assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_DOC);
	assertion(node->doc_subnode_->named_functions_ != NULL);
	assertion(node->doc_subnode_->applications_ != NULL);
	assertion(node->doc_subnode_->execution_requests_ != NULL); /* In the future, this won't be true (for libraries). */
	named_functions_len_ = stt_named_functions_simple_list_length(
			node->doc_subnode_->named_functions_);
	fprintf(stderr, "%s:%u - %u named_functions\n", __FILE__, __LINE__, named_functions_len_);
	applications_len_ = stt_applications_simple_list_length(
			node->doc_subnode_->applications_);
	fprintf(stderr, "%s:%u - %u applications\n", __FILE__, __LINE__,
			applications_len_);
	applications_ptr_ = node->doc_subnode_->applications_;
	while (applications_ptr_ != NULL) {
		application_ = applications_ptr_->first;
		assertion(application_->name_ != NULL);
		assertion(application_->type_ != STT_APPLICATION_TYPE_INVALID);
		fprintf(stderr, "%s:%u - %u\n", __FILE__, __LINE__, application_->type_);
		assertion(application_->entry_point_function_name_ != NULL);
		assertion(
				amara_string_length(
						application_->entry_point_function_name_
				) < 32
		);
		entry_point_function_name_chars_array_ =
				amara_string_get_value(
						application_->entry_point_function_name_);
		fprintf(stderr, "%s:%u - %s\n", __FILE__, __LINE__, entry_point_function_name_chars_array_);
		free(entry_point_function_name_chars_array_);
		applications_ptr_ = applications_ptr_->next;
	}
	fprintf(stderr, "%s:%u <---- void dump_syntax_tree(const stt_node *)\n",
			__FILE__, __LINE__);
}

void
look_for_undefined_labels_ret_destructor(
		look_for_undefined_labels_ret * look_for_undefined_labels_ret_)
{
	assertion(look_for_undefined_labels_ret_ != NULL);
	if (look_for_undefined_labels_ret_->messages != NULL) {
		char_arrays_simple_list_destructor(
				look_for_undefined_labels_ret_->messages);
	}
	free(look_for_undefined_labels_ret_);
}

look_for_undefined_labels_ret *
look_for_undefined_labels_in_named_functions_(const stt_node * node)
__attribute__((warn_unused_result))
;

look_for_undefined_labels_ret *
look_for_undefined_labels_in_named_functions_(const stt_node * node)
{
	look_for_undefined_labels_ret * ret_;
	fprintf(stderr, "%s:%u ----> look_for_undefined_labels_ret * look_for_undefined_labels_in_named_functions(const stt_node *)\n",
			__FILE__, __LINE__);
	ret_ = malloc(sizeof(look_for_undefined_labels_ret));
	ret_->status = LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_INVALID;
	ret_->messages = NULL;
	assertion(node != NULL);
	assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_DOC);
	assertion(node->doc_subnode_ != NULL);
	ret_->status = LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_OK;
	fprintf(stderr, "%s:%u <---- look_for_undefined_labels_ret * look_for_undefined_labels_in_named_functions(const stt_node *)\n",
			__FILE__, __LINE__);
	return ret_;
}

look_for_undefined_labels_ret *
look_for_undefined_labels_in_applications_(const stt_node * node)
__attribute__((warn_unused_result))
;

look_for_undefined_labels_ret *
look_for_undefined_labels_in_applications_(const stt_node * node)
{
	look_for_undefined_labels_ret * ret_;
	stt_named_functions_simple_list * named_functions_ptr_;
	stt_applications_simple_list * applications_ptr_;
	amara_boolean function_name_found_;
	amara_string * target_entry_point_function_name_;
	char_arrays_simple_list * messages_ptr_;
	const char * target_entry_point_function_name_chars_array_;
	const char * applications_ptr_first_name_chars_array_;
	ret_ = malloc(sizeof(look_for_undefined_labels_ret));
	ret_->status = LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_INVALID;
	ret_->messages = NULL;
	assertion(node != NULL);
	assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_DOC);
	assertion(node->doc_subnode_ != NULL);
	applications_ptr_ = node->doc_subnode_->applications_;
	while (applications_ptr_ != NULL) {
		target_entry_point_function_name_ =
				applications_ptr_->first->entry_point_function_name_;
		named_functions_ptr_ = node->doc_subnode_->named_functions_;
		function_name_found_ = AMARA_BOOLEAN_FALSE;
		while (named_functions_ptr_ != NULL) {
			function_name_found_ = amara_string_equality(
					named_functions_ptr_->first->name_,
					target_entry_point_function_name_);
			if (function_name_found_) {
				break;
			}
			named_functions_ptr_ = named_functions_ptr_->next;
		}
		if (named_functions_ptr_ == NULL) {
			/*   No function with a matching name with the
			 * requested function as entry point for this
			 * application was found in the functions list. */
			messages_ptr_ = ret_->messages;
			ret_->messages =
					char_arrays_simple_list_default_constructor();
			target_entry_point_function_name_chars_array_ =
					amara_string_get_value(
							target_entry_point_function_name_);
			applications_ptr_first_name_chars_array_ =
					amara_string_get_value(
							applications_ptr_->first->name_);
			ret_->messages->first = concatenate_four_char_arrays(
					"error, function '",
					target_entry_point_function_name_chars_array_,
					"' not found but has been requested as entry point function by application '",
					applications_ptr_first_name_chars_array_);
			free((char *) target_entry_point_function_name_chars_array_);
			free((char *) applications_ptr_first_name_chars_array_);
			ret_->messages->next = messages_ptr_;
			ret_->status = LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR;
		} else {
			/*   Entry point function name found. */
			assertion(function_name_found_);
		}
		applications_ptr_ = applications_ptr_->next;
	}
	return ret_;
}

look_for_undefined_labels_ret *
look_for_undefined_labels_in_execution_requests_(const stt_node * node)
__attribute__((warn_unused_result))
;

look_for_undefined_labels_ret *
look_for_undefined_labels_in_execution_requests_(const stt_node * node)
{
	look_for_undefined_labels_ret * ret_;
	stt_applications_simple_list * applications_ptr_;
	stt_execution_requests_simple_list * execution_requests_ptr_;
	amara_boolean application_name_found_;
	const amara_string * target_application_requested_to_be_run_name_;
	const char * target_application_requested_to_be_run_name_chars_array_;
	char_arrays_simple_list * messages_ptr_;
	ret_ = malloc(sizeof(look_for_undefined_labels_ret));
	ret_->status = LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_INVALID;
	ret_->messages = NULL;
	assertion(node != NULL);
	assertion(node->type_ == SYNTAX_TREE_NODE_TYPE_DOC);
	assertion(node->doc_subnode_ != NULL);
	execution_requests_ptr_ = node->doc_subnode_->execution_requests_;
	while (execution_requests_ptr_ != NULL) {
		target_application_requested_to_be_run_name_ =
				execution_requests_ptr_->first->application_name_;
		applications_ptr_ = node->doc_subnode_->applications_;
		application_name_found_ = AMARA_BOOLEAN_FALSE;
		while (applications_ptr_ != NULL) {
			application_name_found_ = amara_string_equality(
					applications_ptr_->first->name_,
					target_application_requested_to_be_run_name_);
			if (application_name_found_) {
				break;
			}
			applications_ptr_ = applications_ptr_->next;
		}
		if (applications_ptr_ == NULL) {
			/*   No application with a matching name with
			 * the requested application as application to
			 * be run by this execution request was found in
			 * the applications list. */
			messages_ptr_ = ret_->messages;
			ret_->messages = char_arrays_simple_list_default_constructor();
			target_application_requested_to_be_run_name_chars_array_ =
					amara_string_get_value(
							target_application_requested_to_be_run_name_);
			ret_->messages->first = concatenate_three_char_arrays(
					"error, application '",
					target_application_requested_to_be_run_name_chars_array_,
					"' not found but has been requested to be executed");
			free((char *) target_application_requested_to_be_run_name_chars_array_);
			ret_->messages->next = messages_ptr_;
			ret_->status = LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR;
		} else {
			/*   Application to be run was found. */
			assertion(application_name_found_);
		}
		execution_requests_ptr_ = execution_requests_ptr_->next;
	}
	return ret_;
}

look_for_undefined_labels_ret *
look_for_undefined_labels(const stt_node * node)
{
	char_arrays_simple_list * temp_;
	look_for_undefined_labels_ret * named_functions_sub_ret_;
	look_for_undefined_labels_ret * applications_sub_ret_;
	look_for_undefined_labels_ret * execution_requests_sub_ret_;
	look_for_undefined_labels_ret * ret_ =
			malloc(sizeof(look_for_undefined_labels_ret));
	ret_->status = LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_INVALID;
	ret_->messages = NULL;
	assertion_two(node != NULL, "unexpected value NULL for `node`");
	assertion_two(node->type_ == SYNTAX_TREE_NODE_TYPE_DOC,
	              "unexpected value %u for `node->type`");
	assertion_two(node->doc_subnode_ != NULL,
	              "`node->doc` unexpectedly NULL");
	named_functions_sub_ret_ =
			look_for_undefined_labels_in_named_functions_(node);
	if (named_functions_sub_ret_->status ==
			LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR) {
		ret_->status = LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR;
		temp_ = ret_->messages;
		ret_->messages = char_arrays_simple_list_concat_destructive(
				temp_,
				named_functions_sub_ret_->messages);
	}
	applications_sub_ret_ =
			look_for_undefined_labels_in_applications_(node);
	if (applications_sub_ret_->status ==
			LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR) {
		ret_->status = LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR;
		temp_ = ret_->messages;
		ret_->messages = char_arrays_simple_list_concat_destructive(
				temp_,
				applications_sub_ret_->messages);
	}
	execution_requests_sub_ret_ =
			look_for_undefined_labels_in_execution_requests_(node);
	if (execution_requests_sub_ret_->status ==
			LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR) {
		ret_->status = LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR;
		temp_ = ret_->messages;
		ret_->messages = char_arrays_simple_list_concat_destructive(
				temp_,
				execution_requests_sub_ret_->messages);
	}
	if (ret_->status == LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_INVALID) {
		ret_->status = LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_OK;
	}
	look_for_undefined_labels_ret_destructor(
			execution_requests_sub_ret_);
	execution_requests_sub_ret_ = NULL;
	look_for_undefined_labels_ret_destructor(
			applications_sub_ret_);
	applications_sub_ret_ = NULL;
	look_for_undefined_labels_ret_destructor(
			named_functions_sub_ret_);
	named_functions_sub_ret_ = NULL;
	return ret_;
}

void
assert_pure_integer_literal_node(const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_INTEGER_LITERAL);
	assertion(node->string_literal_subnode_ == NULL);
	assertion(node->natural_literal_subnode_ == NULL);
	assertion(node->integer_literal_subnode_ != NULL);
	assertion(node->integer_literal_subnode_->raw_ != NULL);
	assertion(node->rational_literal_subnode_ == NULL);
	assertion(node->operation_subnode_ == NULL);
	assertion(node->operations_list_subnode_ == NULL);
	assertion(node->named_function_subnode_ == NULL);
	assertion(node->application_subnode_ == NULL);
	assertion(node->identifier_subnode_ == NULL);
	assertion(node->execution_request_subnode_ == NULL);
	assertion(node->doc_subnode_ == NULL);
}

void
assert_pure_rational_literal_node(const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_RATIONAL_LITERAL);
	assertion(node->string_literal_subnode_ == NULL);
	assertion(node->natural_literal_subnode_ == NULL);
	assertion(node->integer_literal_subnode_ == NULL);
	assertion(node->rational_literal_subnode_ != NULL);
	assertion(node->rational_literal_subnode_->raw_ != NULL);
	assertion(node->operation_subnode_ == NULL);
	assertion(node->operations_list_subnode_ == NULL);
	assertion(node->named_function_subnode_ == NULL);
	assertion(node->application_subnode_ == NULL);
	assertion(node->identifier_subnode_ == NULL);
	assertion(node->execution_request_subnode_ == NULL);
	assertion(node->doc_subnode_ == NULL);
}

void
assert_pure_operation_node(const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_OPERATION);
	assertion(node->string_literal_subnode_ == NULL);
	assertion(node->natural_literal_subnode_ == NULL);
	assertion(node->integer_literal_subnode_ == NULL);
	assertion(node->rational_literal_subnode_ == NULL);
	assertion(node->operation_subnode_ != NULL);
	assertion(node->operation_subnode_->operation_ != NULL);
	assertion(node->operation_subnode_->operation_->type_ !=
			STT_OPERATION_TYPE_INVALID);
	assertion(node->operations_list_subnode_ == NULL);
	assertion(node->named_function_subnode_ == NULL);
	assertion(node->application_subnode_ == NULL);
	assertion(node->identifier_subnode_ == NULL);
	assertion(node->execution_request_subnode_ == NULL);
	assertion(node->doc_subnode_ == NULL);
}

void
assert_pure_operations_list_node(const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_OPERATIONS_LIST);
	assertion(node->string_literal_subnode_ == NULL);
	assertion(node->natural_literal_subnode_ == NULL);
	assertion(node->integer_literal_subnode_ == NULL);
	assertion(node->rational_literal_subnode_ == NULL);
	assertion(node->operation_subnode_ == NULL);
	assertion(node->operations_list_subnode_ != NULL);
	assertion(node->operations_list_subnode_->operations_ != NULL);
	assertion(node->named_function_subnode_ == NULL);
	assertion(node->application_subnode_ == NULL);
	assertion(node->identifier_subnode_ == NULL);
	assertion(node->execution_request_subnode_ == NULL);
	assertion(node->doc_subnode_ == NULL);
}

void
assert_pure_named_function_node(const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(node->string_literal_subnode_ == NULL);
	assertion(node->natural_literal_subnode_ == NULL);
	assertion(node->integer_literal_subnode_ == NULL);
	assertion(node->rational_literal_subnode_ == NULL);
	assertion(node->operation_subnode_ == NULL);
	assertion(node->operations_list_subnode_ == NULL);
	assertion(node->named_function_subnode_ != NULL);
	assertion(node->named_function_subnode_->type_ !=
			STT_NAMED_FUNCTION_SUBNODE_TYPE_INVALID);
	assertion(node->named_function_subnode_->name_ != NULL);
	assertion(node->named_function_subnode_->operations_ != NULL);
	assertion(node->application_subnode_ == NULL);
	assertion(node->identifier_subnode_ == NULL);
	assertion(node->execution_request_subnode_ == NULL);
	assertion(node->doc_subnode_ == NULL);
}

void
assert_pure_application_node(const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_APPLICATION);
	assertion(node->string_literal_subnode_ == NULL);
	assertion(node->natural_literal_subnode_ == NULL);
	assertion(node->integer_literal_subnode_ == NULL);
	assertion(node->rational_literal_subnode_ == NULL);
	assertion(node->operation_subnode_ == NULL);
	assertion(node->operations_list_subnode_ == NULL);
	assertion(node->named_function_subnode_ == NULL);
	assertion(node->application_subnode_ != NULL);
	assertion(node->application_subnode_->type_ !=
			STT_APPLICATION_SUBNODE_TYPE_INVALID);
	assertion(node->application_subnode_->name_ != NULL);
	assertion(node->application_subnode_->entry_point_function_name_ !=
			NULL);
	assertion(node->identifier_subnode_ == NULL);
	assertion(node->execution_request_subnode_ == NULL);
	assertion(node->doc_subnode_ == NULL);
}

void
assert_pure_identifier_node(const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_IDENTIFIER);
	assertion(node->application_subnode_ == NULL);
	assertion(node->doc_subnode_ == NULL);
	assertion(node->named_function_subnode_ == NULL);
	assertion(node->identifier_subnode_ != NULL);
	assertion(node->identifier_subnode_->value_ != NULL);
	assertion(node->integer_literal_subnode_ == NULL);
	assertion(node->natural_literal_subnode_ == NULL);
	assertion(node->operation_subnode_ == NULL);
	assertion(node->operations_list_subnode_ == NULL);
	assertion(node->rational_literal_subnode_ == NULL);
	assertion(node->string_literal_subnode_ == NULL);
}

void
assert_pure_natural_literal_node(const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(node->application_subnode_ == NULL);
	assertion(node->doc_subnode_ == NULL);
	assertion(node->named_function_subnode_ == NULL);
	assertion(node->identifier_subnode_ == NULL);
	assertion(node->integer_literal_subnode_ == NULL);
	assertion(node->natural_literal_subnode_ != NULL);
	assertion(node->natural_literal_subnode_->raw_ != NULL);
	assertion(node->operation_subnode_ == NULL);
	assertion(node->operations_list_subnode_ == NULL);
	assertion(node->rational_literal_subnode_ == NULL);
	assertion(node->string_literal_subnode_ == NULL);
}

void
assert_pure_string_literal_node(const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_STRING_LITERAL);
	assertion(node->application_subnode_ == NULL);
	assertion(node->doc_subnode_ == NULL);
	assertion(node->named_function_subnode_ == NULL);
	assertion(node->identifier_subnode_ == NULL);
	assertion(node->integer_literal_subnode_ == NULL);
	assertion(node->natural_literal_subnode_ == NULL);
	assertion(node->operation_subnode_ == NULL);
	assertion(node->operations_list_subnode_ == NULL);
	assertion(node->rational_literal_subnode_ == NULL);
	assertion(node->string_literal_subnode_ != NULL);
	assertion(node->string_literal_subnode_->string_literal_ != NULL);
}

void
assert_pure_execution_request_node(const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_EXECUTION_REQUEST);
	assertion(node->string_literal_subnode_ == NULL);
	assertion(node->natural_literal_subnode_ == NULL);
	assertion(node->integer_literal_subnode_ == NULL);
	assertion(node->rational_literal_subnode_ == NULL);
	assertion(node->operation_subnode_ == NULL);
	assertion(node->operations_list_subnode_ == NULL);
	assertion(node->named_function_subnode_ == NULL);
	assertion(node->application_subnode_ == NULL);
	assertion(node->identifier_subnode_ == NULL);
	assertion(node->execution_request_subnode_ != NULL);
	assertion(node->execution_request_subnode_->type_ !=
			STT_EXECUTION_REQUEST_SUBNODE_TYPE_INVALID);
	assertion(node->execution_request_subnode_->application_name_ != NULL);
	assertion(node->doc_subnode_ == NULL);
}

void
assert_pure_doc_node(const stt_node * node)
{
	assertion(node != NULL);
	assertion(node->type_ == STT_NODE_TYPE_DOC);
	assertion(node->string_literal_subnode_ == NULL);
	assertion(node->natural_literal_subnode_ == NULL);
	assertion(node->integer_literal_subnode_ == NULL);
	assertion(node->rational_literal_subnode_ == NULL);
	assertion(node->operation_subnode_ == NULL);
	assertion(node->operations_list_subnode_ == NULL);
	assertion(node->named_function_subnode_ == NULL);
	assertion(node->application_subnode_ == NULL);
	assertion(node->identifier_subnode_ == NULL);
	assertion(node->execution_request_subnode_ == NULL);
	assertion(node->doc_subnode_ != NULL);
	assertion(node->doc_subnode_->named_functions_ != NULL);
	assertion(node->doc_subnode_->applications_ != NULL);
	assertion(node->doc_subnode_->execution_requests_ != NULL);
}
