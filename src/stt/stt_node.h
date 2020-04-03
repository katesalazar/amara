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
 * src/stt/stt_node.h: Amara syntax tree node.
 */

#ifndef __AMARA__SYNTAX_TREE__NODE__H__
#define __AMARA__SYNTAX_TREE__NODE__H__

/*   For `char_arrays_simple_list`. */
#include "../cmn/char_arrays_simple_list.h"

#include "stt_forward_declarations.h"

/*   For `stt_application_subnode`. */
#include "stt_application_subnode.h"

#include "stt_condition_subnode.h"

#include "stt_dice_expression.h"

/*   For `stt_doc_subnode`. */
#include "stt_doc_subnode.h"

/*   For `stt_execution_request_subnode`. */
#include "stt_execution_request_subnode.h"

#include "stt_expression_sub_dice.h"
#include "stt_expression_subnode.h"

/*   For `stt_named_function_subnode`. */
#include "stt_named_function_subnode.h"

/*   For `stt_identifier_subnode`. */
#include "stt_identifier_subnode.h"

#include "stt_integer_literal_subnode.h"

/*   For `stt_natural_literal_subnode`. */
#include "stt_natural_literal_subnode.h"

#include "stt_node_sub_function_call.h"

/*   For `stt_operation_subnode`. */
#include "stt_operation_subnode.h"

/*   For `stt_operations_list_subnode`. */
#include "stt_operations_list_subnode.h"

/*   For `stt_rational_literal_subnode`. */
#include "stt_rational_literal_subnode.h"

/*   For `stt_string_literal_subnode`. */
#include "stt_string_literal_subnode.h"

#include "stt_where_value_binding_subnode.h"
#include "stt_where_value_bindings_subnode.h"

typedef unsigned char stt_node_type;

/*   This is an enumeration. */
#define STT_NODE_TYPE_INVALID             0x00
#define STT_NODE_TYPE_STRING_LITERAL      0x21  /* 33: '!'. */
#define STT_NODE_TYPE_NATURAL_LITERAL     0x02
#define STT_NODE_TYPE_INTEGER_LITERAL     0x03
#define STT_NODE_TYPE_RATIONAL_LITERAL    0x04
#define STT_NODE_TYPE_IDENTIFIER          0x05
#define STT_NODE_TYPE_CONDITION           0x22  /* 34: '"'. */
#define STT_NODE_TYPE_EXPRESSION          0x23  /* 35: '#'. */
/**  A.K.A. `function_statement`. */
#define STT_NODE_TYPE_OPERATION           0x08
/**  A.K.A. `function_statements`. */
#define STT_NODE_TYPE_OPERATIONS_LIST     0x09
#define STT_NODE_TYPE_WHERE_BINDING       0x24  /* 36: '$'. */
#define STT_NODE_TYPE_WHERE_BINDINGS      0x0B  /* 11       */
#define STT_NODE_TYPE_NAMED_FUNCTION      0x0C  /* 12       */
#define STT_NODE_TYPE_APPLICATION         0x0D  /* 13       */
#define STT_NODE_TYPE_EXECUTION_REQUEST   0x0E  /* 14       */
#define STT_NODE_TYPE_DOC_FRAGMENT        0x0F  /* 15       */
#define STT_NODE_TYPE_DOC                 0x10  /* 16       */
#define STT_UNUSED                        0x7F  /* 127      */
#define STT_NODE_TYPE_CLI_OPERATIONS_LIST 0x81  /* 129      */
#define STT_NODE_TYPE_EMPTY_FUNCTION_CALL_ARGUMENTS_LIST 0x82  /* 130 */
#define STT_NODE_TYPE_FUNCTION_CALL_ARGUMENTS_LIST       0x83  /* 131 */
#define STT_NODE_TYPE_FUNCTION_CALL                      0x84  /* 132 */
#define STT_NODE_TYPE_ERRORED             0xFF  /* 255      */

#define BISON_RET_INVALID                   7
#define BISON_RET_SUCCESS                   0
#define BISON_RET_FAILURE_INVALID_INPUT     1
#define BISON_RET_FAILURE_MEMORY_EXHAUSTION 2

/*   `stt_node` for '**S**yn**t**ax **t**ree node'. */
typedef struct stt_node {

	stt_node_type type_;

	stt_string_literal_subnode * string_literal_subnode_;

	stt_natural_literal_subnode * natural_literal_subnode_;

	stt_integer_literal_subnode * integer_literal_subnode_;

	stt_rational_literal_subnode * rational_literal_subnode_;

	stt_identifier_subnode * identifier_subnode_;

	stt_condition_subnode * condition_subnode_;

	stt_expression_subnode * expression_subnode_;

	stt_where_value_binding_subnode * where_value_binding_subnode_;

	stt_where_value_bindings_subnode * where_value_bindings_subnode_;

	stt_operation_subnode * operation_subnode_;

	stt_operations_list_subnode * operations_list_subnode_;

	stt_named_function_subnode * named_function_subnode_;

	stt_application_subnode * application_subnode_;

	stt_execution_request_subnode * execution_request_subnode_;

	stt_doc_subnode * doc_subnode_;

	stt_node_sub_function_call * sub_function_call_;

	/**  Bison `yyparse` function is supposed  to return 0, 1 or 2. */
	int bison_ret_;
} stt_node
;

stt_node *
stt_node_default_constructor(void)
__attribute__((warn_unused_result))
;

void
assert_stt_node_is_valid(const stt_node * node)
;

stt_node *
stt_node_copy_constructor(const stt_node * node)
__attribute__((warn_unused_result))
;

/*   `raw_natural` must be a valid raw natural: only digits and no
 * unnecessary left padding zeroes. */
stt_node *
stt_node_wrapping_raw_natural(const amara_string * raw_natural)
__attribute__((warn_unused_result))
;

void
stt_node_destructor(stt_node const * node)
;

void
stt_node_set_type(stt_node * node, const stt_node_type type)
;

void
stt_node_set_string_literal(
		stt_node * node, const amara_string * string_literal)
;

void
stt_node_set_natural_literal(
		stt_node * node, const amara_string * raw_natural_literal)
;

void
stt_node_set_integer_literal(
		stt_node * node, const amara_string * raw_integer_literal)
;

void
stt_node_set_rational_literal(
		stt_node * node, const amara_string * raw_rational_literal)
;

void
stt_node_set_identifier(stt_node * node, const amara_string * identifier)
;

void
stt_node_set_condition(stt_node * node, const stt_condition * condition)
;

void
stt_node_set_dice_expression(
		stt_node * node, const stt_dice_expression * dice_expression)
;

void
stt_node_set_expression(stt_node * node, const stt_expression * expression)
;

void
stt_node_set_where_value_binding(
		stt_node * node,
		const stt_where_value_binding * where_value_binding)
;

void
stt_node_set_where_value_bindings(
		stt_node * node,
		const stt_where_value_bindings_simple_list * where_value_bindings)
;

void
stt_node_set_operation(stt_node * node, const stt_operation * operation)
;

void
stt_node_set_operations_list(
		stt_node * node, const stt_operations_simple_list * operations)
;

void
stt_node_set_named_function(
		stt_node * node, const stt_named_function * named_function)
;

void
stt_node_set_application(stt_node * node, const stt_application * application)
;

void
stt_node_set_execution_request(stt_node * node,
                               const stt_execution_request * execution_request)
;

void
stt_node_set_doc_fragment(
		stt_node * node, const stt_doc_subnode * doc_subnode)
;

void
stt_node_set_doc_by_components(
		stt_node * node,
		const stt_named_functions_simple_list * named_functions,
		const stt_applications_simple_list * applications,
		const stt_execution_requests_simple_list * execution_requests)
;

amara_boolean
stt_node_equality(const stt_node * n0, const stt_node * n1)
__attribute__((warn_unused_result))
;

amara_boolean
stt_nodes_equality(const stt_node * n0, const stt_node * n1)
__attribute__((warn_unused_result))
;

amara_string *
stt_node_type_name(const stt_node * node)
__attribute__((warn_unused_result))
;

stt_node *
stt_nodes_multiplication(const stt_node * node_0, const stt_node * node_1)
__attribute__((warn_unused_result))
;

stt_node *
stt_nodes_division(const stt_node * node_0, const stt_node * node_1)
__attribute__((warn_unused_result))
;

stt_node *
stt_nodes_substraction(const stt_node * node_0, const stt_node * node_1)
__attribute__((warn_unused_result))
;

/*   Decorates `node` registering function `function`.
 *   WATCH OUT, EDITS IN PLACE. */
stt_node *
register_named_function(stt_node * node, const stt_node * named_function_node)
__attribute__((warn_unused_result))
;

/*   Decorates `node` registering application `application`.
 *   WATCH OUT, EDITS IN PLACE. */
stt_node *
register_application(stt_node * node, const stt_node * application_node)
__attribute__((warn_unused_result))
;

/*   Decorates `node` registering execution request `execution_request`.
 *   WATCH OUT, EDITS IN PLACE. */
stt_node *
register_execution_request(
		stt_node * node, const stt_node * execution_request_node)
__attribute__((warn_unused_result))
;

void
dump_syntax_tree(const stt_node * node)
;

/*   Enumeration. */

#define LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_INVALID 0x00
#define LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_OK      0x0F
#define LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_SUCCESS LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_OK
#define LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR   0xF0

typedef struct look_for_undefined_labels_ret {

	unsigned char status;

	char_arrays_simple_list * messages;
} look_for_undefined_labels_ret
;

void
look_for_undefined_labels_ret_destructor(
		look_for_undefined_labels_ret * look_for_undefined_labels_ret_)
;

look_for_undefined_labels_ret *
look_for_undefined_labels(const stt_node * node)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_clean_string_literal_node(const stt_node * node)
;

void
assert_clean_natural_literal_node(const stt_node * node)
;

void
assert_clean_integer_literal_node(const stt_node * node)
;

void
assert_clean_rational_literal_node(const stt_node * node)
;

void
assert_clean_identifier_node(const stt_node * node)
;

void
assert_clean_condition_node(const stt_node * node)
;

void
assert_clean_expression_node(const stt_node * node)
;

void
assert_clean_where_value_binding_node(const stt_node * node)
;

void
assert_clean_where_value_bindings_node(const stt_node * node)
;

void
assert_clean_operation_node(const stt_node * node)
;

void
assert_clean_operations_list_node(const stt_node * node)
;

void
assert_clean_named_function_node(const stt_node * node)
;

void
assert_clean_application_node(const stt_node * node)
;

void
assert_clean_execution_request_node(const stt_node * node)
;

void
assert_clean_doc_fragment_node(const stt_node * node)
;

void
assert_clean_doc_node(const stt_node * node)
;

void
stt_node_assert_clean_function_call_node(const stt_node * node)
;

void
stt_node_assert_clean_empty_function_call_arguments_list_node(
		const stt_node * node)
;

#endif

/*   Non destructive in its arguments.
 *   `node_zero` minus `node_one`. */
struct stt_node *
simplify_natural_literal_nodes_substraction(
		const struct stt_node * node_zero,
		const struct stt_node * node_one)
__attribute__((warn_unused_result))
;

/*   Non destructive in its arguments.
 *   `node_zero` divided by `node_one`. */
struct stt_node *
simplify_natural_literal_nodes_multiplication(
		const struct stt_node * node_zero,
		const struct stt_node * node_one)
__attribute__((warn_unused_result))
;

/*   Non destructive in its arguments.
 *   `node_zero` divided by `node_one`.
 *   Note that euclidean
 * division is performed, if (because) arguments are naturals. */
struct stt_node *
simplify_natural_literal_nodes_division(
		const struct stt_node * node_zero,
		const struct stt_node * node_one)
__attribute__((warn_unused_result))
;

#endif
