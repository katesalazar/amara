/*
 * Copyright 2019, 2020 Mercedes Catherine Salazar
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

/**  For:
 *
 *     named_functions_and_applications_and_execution_requests :
 *       application named_functions_and_applications_and_execution_requests
 */
stt_node *
bison_annex_named_functions_and_applications_and_execution_requests_out_of_application_and_named_functions_and_applications_and_execution_requests(
		stt_node * application,
		stt_node * named_functions_and_applications_and_execution_requests)
__amara__warn_unused_result__
;

/**  For:
 *
 *     named_functions_and_applications_and_execution_requests :
 *       execution_request
 *       named_functions_and_applications_and_execution_requests
 */
stt_node *
bison_annex_named_functions_and_applications_and_execution_requests_out_of_execution_request_and_named_functions_and_applications_and_execution_requests(
		stt_node * execution_request,
		stt_node * named_functions_and_applications_and_execution_requests)
__amara__warn_unused_result__
;

stt_node *
named_functions_and_applications_and_execution_requests_out_of_ignored()
__amara__warn_unused_result__
;

/**  For:
 *
 *     cli_named_function :
 *       T_FUNCTION T_IDENTIFIER T_IS T_A
 *       T_COMMAND T_LINE T_INTERFACE T_APPLICATION T_FUNCTION
 *       T_AND function_receives_clause
 *       T_AND function_returns_clause
 *       function_side_effects_clause
 *       function_statements_clause
 *       function_where_clauses T_END T_FUNCTION T_IDENTIFIER
 */
stt_node *
bison_annex_cli_named_function_out_of_token_function_and_token_identifier_and_token_is_and_token_a_and_token_command_and_token_line_and_token_interface_and_token_application_and_token_function_and_token_and_and_function_receives_clause_and_token_and_and_function_returns_clause_and_function_side_effects_clause_and_function_statements_clause_and_function_where_clauses_and_token_end_and_token_function_and_token_identifier(
		unsigned char * must_call_YYERROR,
		stt_node * * node_for_yyerror,
		char * message_for_yyerror,
		stt_node * identifier_at_position_two,
		/*
		stt_node * function_receives_clause,
		stt_node * function_returns_clause,
		stt_node * function_side_effects_clause,
		*/
		stt_node * function_statements,
		stt_node * function_where_clauses,
		stt_node * identifier_at_position_twenty_one)
__amara__warn_unused_result__
;

/**  For:
 *
 *     function_sequential_statements :
 *       function_statement T_AND T_THEN function_sequential_statements
 */
stt_node *
bison_annex_function_sequential_statements_out_of_function_statement_and_token_and_and_token_then_and_function_sequential_statements(
		stt_node * function_statement,
		stt_node * function_sequential_statements)
__amara__warn_unused_result__
;

/**  For:
 *
 *     function_sequential_statements : function_statement
 */
stt_node *
bison_annex_function_sequential_statements_out_of_function_statement(
		stt_node * function_statement)
__amara__warn_unused_result__
;

/**  For:
 *
 *     function_parallel_statements :
 *       function_statement T_AND T_THEN function_parallel_statements
 */
stt_node *
bison_annex_function_parallel_statements_out_of_function_statement_and_token_and_and_token_then_and_function_parallel_statements(
		stt_node * function_statement,
		stt_node * function_parallel_statements)
__amara__warn_unused_result__
;

/**  For:
 *
 *     function_parallel_statements : function_statement
 */
stt_node *
bison_annex_function_parallel_statements_out_of_function_statement(
		stt_node * function_statement)
__amara__warn_unused_result__
;

/**  For:
 *
 *     function_statement : T_PRINT expression
 */
stt_node *
function_statement_out_of_token_print_and_expression(stt_node * expression)
__attribute__((warn_unused_result))
;

/**  For:
 *
 *     function_statement : T_NEW T_LINE
 */
stt_node *
function_statement_out_of_token_new_and_token_line(void)
__attribute__((warn_unused_result))
;

/**  To be called from:
 *
 *     function_where_clauses :
 *       T_WHERE function_where_clause function_where_clauses
 */
stt_node *
bison_annex_function_where_clauses_out_of_token_where_and_function_where_clause_and_function_where_clauses(
		stt_node * function_where_clause,
		stt_node * function_where_clauses)
__amara__warn_unused_result__
;

/**  To be called from:
 *
 *     function_where_clauses : NOTHING
 */
stt_node *
bison_annex_function_where_clauses_out_of_nothing(void)
__amara__warn_unused_result__
;

/**  To be called from:
 *
 *     function_where_clause : T_IDENTIFIER T_IS T_BOUND T_TO expression
 */
stt_node *
function_where_clause_out_of_token_identifier_and_token_is_and_token_bound_and_token_to_and_expression(
		stt_node * identifier, stt_node * expression)
__amara__warn_unused_result__
;

/**  To be called from:
 *
 *     function_statement : T_EXECUTE function_executable_expression
 */
stt_node*
bison_annex_function_statement_out_of_token_execute_and_nonterminal_function_executable_expression(
		stt_node * function_executable_expression)
__amara__warn_unused_result__
;

/**  To be called from:
 *
 *     function_executable_expression : function_call_without_return_value
 */
stt_node *
bison_annex_function_executable_expression_out_of_nonterminal_function_call_without_return_value(
		stt_node * function_call_without_return_value)
__amara__warn_unused_result__
;

/**  To be called from:
 *
 *     function_call_without_return_value : function_call
 */
stt_node *
bison_annex_function_call_without_return_value_out_of_nonterminal_function_call(
		stt_node * function_call)
__amara__warn_unused_result__
;

/**  To be called from:
 *
 *     function_call : T_CALL T_FUNCTION T_IDENTIFIER function_call_arguments
 */
stt_node *
bison_annex_function_call_out_of_token_call_and_token_function_and_token_identifier_and_nonterminal_function_call_arguments(
		stt_node * identifier_node, stt_node * function_call_arguments_node)
__amara__warn_unused_result__
;

/**  To be called from:
 *
 *     function_call_arguments : T_WITH T_NO T_ARGUMENTS T_AT T_ALL
 */
stt_node *
bison_annex_function_call_arguments_out_of_token_with_and_token_no_and_token_arguments_and_token_at_and_token_all()
__amara__warn_unused_result__
;

/**  For:
 *
 *     expression :
 *       T_IF condition T_THEN expression T_ELSE expression T_END T_IF
 */
stt_node *
bison_annex_expression_out_of_token_if_and_condition_and_token_then_and_expression_and_token_else_and_expression_and_token_end_and_token_if(
		stt_node * condition, stt_node * expression_then,
		stt_node * expression_else)
__amara__warn_unused_result__
;

/**  For:
 *
 *     expression : T_STRING_LITERAL
 */
stt_node *
bison_annex_expression_out_of_token_string_literal(stt_node * string_literal)
__amara__warn_unused_result__
;

/**  For:
 *
 *     expression : T_NATURAL_LITERAL
 */
stt_node *
bison_annex_expression_out_of_token_natural_literal(
		stt_node * natural_literal)
__amara__warn_unused_result__
;

/**  For:
 *
 *     condition: expression T_IS T_LESS T_THAN expression
 */
stt_node *
bison_annex_condition_out_of_expression_and_token_is_and_token_less_and_token_than_and_expression(
		stt_node * left_expression, stt_node * right_expression)
__amara__warn_unused_result__
;

/**  For:
 *
 *     condition: expression T_IS T_GREATER T_THAN expression
 */
stt_node *
bison_annex_condition_out_of_expression_and_token_is_and_token_greater_and_token_than_and_expression(
		stt_node * left_expression, stt_node * right_expression)
__amara__warn_unused_result__
;

#endif
