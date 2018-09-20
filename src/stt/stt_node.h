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
 * src/stt/stt_node.h: Amara syntax tree node.
 */

#ifndef __AMARA__SYNTAX_TREE__NODE__H__
#define __AMARA__SYNTAX_TREE__NODE__H__

/*   For `uint_fast8_t`. */
#include <stdint.h>

/*   For `char_arrays_simple_list`. */
#include "../cmn/char_arrays_simple_list.h"

/*   For `rtg_doc`. */
#include "../rtg/rtg_doc.h"

/*   For `stt_application_subnode`. */
#include "stt_application_subnode.h"

/*   For `stt_doc_subnode`. */
#include "stt_doc_subnode.h"

/*   For `stt_execution_request_subnode`. */
#include "stt_execution_request_subnode.h"

/*   For `stt_function_subnode`. */
#include "stt_function_subnode.h"

/*   For `stt_identifier_subnode`. */
#include "stt_identifier_subnode.h"

/*   For `stt_integer_subnode`. */
#include "stt_integer_subnode.h"

/*   For `stt_natural_subnode`. */
#include "stt_natural_subnode.h"

/*   For `stt_operation_subnode`. */
#include "stt_operation_subnode.h"

/*   For `stt_operations_list_subnode`. */
#include "stt_operations_list_subnode.h"

/*   For `stt_rational_subnode`. */
#include "stt_rational_subnode.h"

/*   For `stt_string_literal_subnode`. */
#include "stt_string_literal_subnode.h"

/*   This is an enumeration. */
#define SYNTAX_TREE_NODE_TYPE_INVALID            0x00
#define SYNTAX_TREE_NODE_TYPE_STRING_LITERAL      0x01
#define STT_NODE_TYPE_STRING_LITERAL SYNTAX_TREE_NODE_TYPE_STRING_LITERAL
#define SYNTAX_TREE_NODE_TYPE_NATURAL            0x02
#define SYNTAX_TREE_NODE_TYPE_INTEGER            0x03
#define SYNTAX_TREE_NODE_TYPE_RATIONAL           0x04
#define SYNTAX_TREE_NODE_TYPE_OPERATION          0x05
#define SYNTAX_TREE_NODE_TYPE_OPERATIONS_LIST     0x09
#define SYNTAX_TREE_NODE_TYPE_FUNCTION           0x06
#define SYNTAX_TREE_NODE_TYPE_APPLICATION        0x07
#define SYNTAX_TREE_NODE_TYPE_IDENTIFIER         0x08
#define SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT       0x10
#define SYNTAX_TREE_NODE_TYPE_DOC                0x11
#define SYNTAX_TREE_NODE_TYPE_EXECUTION_REQUEST  0x12
#define SYNTAX_TREE_NODE_TYPE_CLI_OPERATIONS_LIST 0x13
#define SYNTAX_TREE_NODE_TYPE_ERRORED            0xFF

/*   `stt_node` for '**S**yn**t**ax **t**ree node'. */
typedef struct stt_node {
	uint_fast8_t type_;
	stt_string_literal_subnode * string_literal_subnode_;
	stt_natural_subnode * natural_subnode_;
	stt_integer_subnode * integer_subnode_;
	stt_rational_subnode * rational_subnode_;
	stt_operation_subnode * operation_subnode_;
	stt_operations_list_subnode * operations_list_subnode_;
	stt_function_subnode * function_subnode_;
	stt_application_subnode * application_subnode_;
	stt_identifier_subnode * identifier_subnode_;
	stt_execution_request_subnode * execution_request_subnode_;
	stt_doc_subnode * doc_subnode_;
} stt_node;

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
stt_node_destructor(stt_node const *)
;

void
stt_node_set_string_literal(
		stt_node * node, const amara_string * string_literal)
;

void
stt_node_set_natural(
		stt_node * node, const amara_string * raw_natural)
;

void
stt_node_set_integer(
		stt_node * node, const amara_string * raw_integer)
;

void
stt_node_set_rational(
		stt_node * node, const amara_string * raw_rational)
;

amara_string *
stt_node_type_name(const stt_node * node)
__attribute__((warn_unused_result))
;

/*   Decorates `node` registering function `function`. */
stt_node *
register_function(stt_node * node, const stt_node * function_node)
__attribute__((warn_unused_result));

/*   Decorates `node` registering application `application`. */
stt_node *
register_application(stt_node * node, const stt_node * application_node)
__attribute__((warn_unused_result));

/*   Decorates `node` registering execution request `execution_request`. */
stt_node *
register_execution_request(
		stt_node * node, const stt_node * execution_request_node)
__attribute__((warn_unused_result));

void
dump_syntax_tree(const stt_node * node)
;

/*   Enumeration. */

#define LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_INVALID 0x00
#define LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_OK      0x0F
#define LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR   0xF0

typedef struct look_for_undefined_labels_ret {
	uint_fast8_t status_;
	char_arrays_simple_list * messages_;
	/* rtg_doc * rtg_doc_; */ /* migrated to somewhere else */
} look_for_undefined_labels_ret;

look_for_undefined_labels_ret *
look_for_undefined_labels(const stt_node * node)
__attribute__((warn_unused_result));

#define RTG_DOC_OUT_OF_STT_DOC_RET_STATUS_INVALID 0x00
#define RTG_DOC_OUT_OF_STT_DOC_RET_STATUS_OK      0x0F
#define RTG_DOC_OUT_OF_STT_DOC_RET_STATUS_ERROR   0xF0

typedef struct rtg_doc_out_of_stt_doc_ret {
	uint_fast8_t status_;
	rtg_doc * doc_;
} rtg_doc_out_of_stt_doc_ret;

rtg_doc_out_of_stt_doc_ret *
rtg_doc_out_of_stt_doc(const stt_node * node)
__attribute__((warn_unused_result));

/*

#define RTG_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_INVALID 0x00
#define RTG_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_functions_out_of_stt_doc_ret {
	uint_fast8_t status_;
	rtg_functions_simple_list * rtg_functions_;
} rtg_functions_out_of_stt_doc_ret;

#define RTG_APPLICATIONS_OUT_OF_STT_DOC_RET_STATUS_INVALID 0x00
#define RTG_APPLICACIONS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_applications_out_of_stt_doc_ret {
	uint_fast8_t status_;
	rtg_applications_simple_list * rtg_applications_;
} rtg_applications_out_of_stt_doc_ret;

#define RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_RET_STATUS_INVALID 0x00
#define RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_execution_requests_out_of_stt_doc_ret {
	uint_fast8_t status_;
	rtg_execution_requests_simple_list * rtg_execution_requests_;
} rtg_execution_requests_out_of_stt_doc_ret;

*/

void
assert_pure_natural_node(const stt_node * node)
;

void
assert_pure_string_literal_node(const stt_node * node)
;

#endif
