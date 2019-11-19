/*
 * Copyright 2019 Mercedes Catherine Salazar
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
 * src/bsn/bison_annex.h: Amara Minia scripts Bison parser helper
 * functions.
 */

#ifndef __AMARA__BISON__BISON_ANNEX__H__
#define __AMARA__BISON__BISON_ANNEX__H__

#include "../stt/stt_node.h"

stt_node *
document_out_of_named_functions_and_applications_and_execution_requests(
		stt_node * syntax_tree,
		stt_node * named_functions_and_applications_and_execution_requests)
__amara__warn_unused_result__
;

stt_node *
named_functions_and_applications_and_execution_requests_out_of_named_function_and_named_functions_and_applications_and_execution_requests(
		stt_node * named_function,
		stt_node * named_functions_and_applications_and_execution_requests)
__attribute__((warn_unused_result))
;

stt_node *
named_functions_and_applications_and_execution_requests_out_of_ignored()
__amara__warn_unused_result__
;

stt_node *
function_statement_out_of_token_print_and_expression(stt_node * expression)
__attribute__((warn_unused_result))
;

stt_node *
function_statement_out_of_token_new_and_token_line()
__attribute__((warn_unused_result))
;

#endif
