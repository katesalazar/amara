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
 * src/bsn/bison_annex.c: Amara Minia scripts Bison parser helper
 * functions.
 */

#include <string.h>

#include "../stt/stt_named_function_call.h"

#include "bison_annex.h"

stt_node *
document_out_of_named_functions_and_applications_and_execution_requests(
		stt_node * syntax_tree,
		stt_node * named_functions_and_applications_and_execution_requests)
{
	stt_node * returning_;

#ifndef NDEBUG
	assertion(syntax_tree != NULL);
	assertion(named_functions_and_applications_and_execution_requests !=
			NULL);
#endif

	returning_ = syntax_tree;

	/*
	if ($1 == NULL) {

		returning_->type_ = STT_NODE_TYPE_INVALID;
	} else {
	*/

	assertion_two(
			named_functions_and_applications_and_execution_requests !=
					NULL,
			"`fns_and_apps_defs_and_exectn_reqs` unexpectedly NULL");
	assertion_two(
			named_functions_and_applications_and_execution_requests->type_ ==
					STT_NODE_TYPE_DOC_FRAGMENT,
			"unexpected type of `fns_and_apps_defs_and_exectn_reqs`");
	assertion_two(
			named_functions_and_applications_and_execution_requests->doc_subnode_ !=
					NULL,
			"`fns_and_apps_defs_and_exectn_reqs->doc` unexpectedly NULL");
	returning_->type_ = STT_NODE_TYPE_DOC;
	returning_->doc_subnode_ =
			named_functions_and_applications_and_execution_requests->doc_subnode_;

	forced_assertion(returning_->doc_subnode_->named_functions_ != NULL);

	/*
	if (returning_->doc_subnode_->named_functions_ == NULL) {

		returning_->doc_subnode_->named_functions_ =
				stt_named_functions_simple_list_default_constructor();
	}
	*/

	forced_assertion(returning_->doc_subnode_->applications_ != NULL);

	/*
	if (returning_->doc_subnode_->applications_ == NULL) {

		returning_->doc_subnode_->applications_ =
				stt_applications_simple_list_default_constructor();
	}
	*/

	forced_assertion(returning_->doc_subnode_->execution_requests_ != NULL);

	/*
	if (returning_->doc_subnode_->execution_requests_ == NULL) {

		returning_->doc_subnode_->execution_requests_ =
				stt_execution_requests_simple_list_default_constructor();
	}
	*/

	free(named_functions_and_applications_and_execution_requests);

	/*
	}
	*/

	return returning_;
}

stt_node *
named_functions_and_applications_and_execution_requests_out_of_named_function_and_named_functions_and_applications_and_execution_requests(
		stt_node * named_function,
		stt_node * named_functions_and_applications_and_execution_requests)
{
	stt_node * returning_;

#ifndef NDEBUG
	assertion(named_function != NULL);
	assertion(named_function->type_ == STT_NODE_TYPE_NAMED_FUNCTION);
	assertion(named_function->named_function_subnode_ != NULL);
	/* XXX ... */
#endif

	forced_assertion(named_functions_and_applications_and_execution_requests !=
			NULL);

	/*
	if (named_functions_and_applications_and_execution_requests == NULL) {
		returning_ = stt_node_default_constructor();
		forced_assertion(returning_ != NULL);
		returning_->type_ = STT_NODE_TYPE_DOC_FRAGMENT;
#ifndef NDBUG
		assertion(returning_->doc_subnode_ == NULL);
#endif
		returning_->doc_subnode_ =
				stt_doc_subnode_default_constructor();
		forced_assertion(returning_->doc_subnode_ != NULL);
		returning_ = register_named_function(
				returning_, named_function);
#ifndef NDEBUG
		assertion(returning_ != NULL);
#endif
		forced_assertion(returning_->doc_subnode_ != NULL);
		free(named_function->named_function_subnode_);
		free(named_function);
	} else {
	*/
#ifndef NDEBUG
		assertion_two(named_functions_and_applications_and_execution_requests->type_ ==
				STT_NODE_TYPE_DOC_FRAGMENT,
				"unexpected type of `fns_and_apps_defs_and_exectn_reqs`");
		assertion(named_functions_and_applications_and_execution_requests->doc_subnode_ !=
				NULL);
#endif
		returning_ = register_named_function(
				named_functions_and_applications_and_execution_requests,
				named_function);
#ifndef NDEBUG
		assertion(returning_->doc_subnode_ != NULL);
#endif

		/*
		free(named_function->named_function_subnode_);
		free(named_function);
		*/
		stt_node_destructor(named_function);
	/*
	}
	*/

	return returning_;
}

stt_node *
bison_annex_named_functions_and_applications_and_execution_requests_out_of_application_and_named_functions_and_applications_and_execution_requests(
		stt_node * application,
		stt_node * named_functions_and_applications_and_execution_requests)
{
	stt_node * returning_;

	forced_assertion(named_functions_and_applications_and_execution_requests !=
			NULL);

	/*
	if (named_functions_and_applications_and_execution_requests == NULL) {
		returning_ = stt_node_default_constructor();
		forced_assertion(returning_ != NULL);
		returning_->type_ = STT_NODE_TYPE_DOC_FRAGMENT;
		returning_->doc_subnode_ =
				stt_doc_subnode_default_constructor();
		forced_assertion(returning_->doc_subnode_ != NULL);
		returning_ = register_application(returning_, application);
#ifndef NDEBUG
		assertion(returning_->doc_subnode_ != NULL);
#endif
		free(application->application_subnode_);
		free(application);
	} else {
	*/
#ifndef NDEBUG
		assertion_two(
				named_functions_and_applications_and_execution_requests->type_ ==
						STT_NODE_TYPE_DOC_FRAGMENT,
				"unexpected type of `fns_and_apps_defs_and_exectn_reqs`");
		assertion(named_functions_and_applications_and_execution_requests->doc_subnode_ !=
				NULL);
#endif
		returning_ = register_application(
				named_functions_and_applications_and_execution_requests,
				application);
#ifndef NDEBUG
		assertion(returning_->doc_subnode_ != NULL);
#endif
		amara_string_destructor(
				application->application_subnode_->entry_point_function_name_);
		amara_string_destructor(
				application->application_subnode_->name_);
		free(application->application_subnode_);
		free(application);
	/*
	}
	*/
	return returning_;
}

stt_node *
bison_annex_named_functions_and_applications_and_execution_requests_out_of_execution_request_and_named_functions_and_applications_and_execution_requests(
		stt_node * execution_request,
		stt_node * named_functions_and_applications_and_execution_requests)
{
	stt_node * returning_;

	forced_assertion(named_functions_and_applications_and_execution_requests !=
			NULL);

	/*
	if (named_functions_and_applications_and_execution_requests == NULL) {
		returning_ = stt_node_default_constructor();
		forced_assertion(returning_ != NULL);
		returning_->type_ = STT_NODE_TYPE_DOC_FRAGMENT;
		returning_->doc_subnode_ =
				stt_doc_subnode_default_constructor();
		forced_assertion(returning_->doc_subnode_ != NULL);
		returning_ = register_execution_request(
				returning_, execution_request);
#ifndef NDEBUG
		assertion(returning_->doc_subnode_ != NULL);
#endif
		free(execution_request->execution_request_subnode_);
		free(execution_request);
	} else {
	*/
#ifndef NDEBUG
		assertion_two(
				named_functions_and_applications_and_execution_requests->type_ ==
						STT_NODE_TYPE_DOC_FRAGMENT,
				"unexpected type of `fns_and_apps_defs_and_exectn_reqs`");
		assertion(named_functions_and_applications_and_execution_requests->doc_subnode_ !=
				NULL);
#endif
		returning_ = register_execution_request(
				named_functions_and_applications_and_execution_requests,
				execution_request);
#ifndef NDEBUG
		assertion(returning_->doc_subnode_ != NULL);
#endif
		amara_string_destructor(
				execution_request->execution_request_subnode_->application_name_);
		free(execution_request->execution_request_subnode_);
		free(execution_request);
	/*
	}
	*/
	return returning_;
}

stt_node *
named_functions_and_applications_and_execution_requests_out_of_ignored()
{
	stt_node * returning_;
	stt_doc_subnode * doc_subnode_;

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

	doc_subnode_ = stt_doc_subnode_default_constructor();
	forced_assertion(doc_subnode_ != NULL);

	stt_node_set_doc_fragment(returning_, doc_subnode_);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_NODE_TYPE_DOC_FRAGMENT);
	assertion(returning_->doc_subnode_ != NULL);
#endif

	stt_doc_subnode_destructor(doc_subnode_);

	return returning_;
}

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
		stt_node * function_statements_clause,
		stt_node * function_where_clauses,
		stt_node * identifier_at_position_twenty_one)
{
	stt_node * returning_;

	/*   Abort with error if function names do not match. */

	assertion(identifier_at_position_two != NULL);
	if (identifier_at_position_two->type_ != STT_NODE_TYPE_IDENTIFIER) {

#ifdef DUMP_FLOW_TO_STDERR
		/*
		fprintf(stderr, "%s:%u - identifier_at_position_two->type_: %u\n", __FILE__, __LINE__, $2->type_);
		*/
#endif
	}
	assertion(identifier_at_position_two->type_ ==
			STT_NODE_TYPE_IDENTIFIER);
	assertion(identifier_at_position_two->identifier_subnode_ != NULL);
	assertion(identifier_at_position_twenty_one != NULL);
	assertion(identifier_at_position_twenty_one->type_ ==
			STT_NODE_TYPE_IDENTIFIER);
	assertion(identifier_at_position_twenty_one->identifier_subnode_ !=
			NULL);
	if (AMARA_BOOLEAN_FALSE == amara_string_equality(
			identifier_at_position_two->identifier_subnode_->value_,
			identifier_at_position_twenty_one->identifier_subnode_->value_)) {

		stt_node_destructor(function_statements_clause);
		stt_node_destructor(function_where_clauses);
		stt_node_destructor(identifier_at_position_two);
		stt_node_destructor(identifier_at_position_twenty_one);

		/*   Previously like
		yyerror(NULL, "function names do not match");
		YYERROR;
		*/

		/*   Now with these three lines. */
		* must_call_YYERROR = 1;
		free(* node_for_yyerror);  /* XXX ??? */
		* node_for_yyerror = NULL;
		strcpy(message_for_yyerror, "function names do not match");  /* XXX fits because it's a large buffer. */

		returning_ = stt_node_default_constructor();
		forced_assertion(returning_ != NULL);

		return returning_;  /* XXX */
	}

	/*   Set node type. */
	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

	/*   Attach the function operations to this node. */
	/*   Those are hanging from `function_statements_clause`. */
	assertion_two(function_statements_clause != NULL,
			"`$17` unexpectedly NULL");
	if (function_statements_clause->type_ !=
			STT_NODE_TYPE_CLI_OPERATIONS_LIST) {

#ifdef DUMP_FLOW_TO_STDERR
		/*
		fprintf(stderr, "function_statements_clause->type_: %u\n",
		        $17->type_);
		*/
#endif
	}
	assertion_two(
			function_statements_clause->type_ ==
					STT_NODE_TYPE_CLI_OPERATIONS_LIST,
			"unexpected value for `function_statements_clause->type_`");
	assertion_two(
			function_statements_clause->operations_list_subnode_ !=
					NULL,
			"`function_statements_clause->operations_list_subnode_` unexpectedly NULL");
	assertion_two(
		function_statements_clause->operations_list_subnode_->operations_ !=
				NULL,
		"`function_statements_clause->operations_list_subnode_->operations_` unexpectedly NULL");
	assertion_two(
		function_statements_clause->operations_list_subnode_->operations_->first !=
				NULL,
		"`function_statements_clause->operations_list_subnode_->operations_->first` unexpectedly NULL");
	assertion_two(
		function_statements_clause->operations_list_subnode_->operations_->first->type_ !=
				STT_OPERATION_TYPE_INVALID,
		"`function_statements_clause->operations_list_subnode_->operations_->first->type_` is invalid");

	assertion(function_where_clauses != NULL);
	assertion(function_where_clauses->type_ ==
			STT_NODE_TYPE_WHERE_BINDINGS);
	assertion(function_where_clauses->where_value_bindings_subnode_ !=
			NULL);
	assertion(function_where_clauses->where_value_bindings_subnode_->where_value_bindings_ !=
			NULL);

	/*
	TODO CHARACTERIZE THE FUNCTION AS A CLI FUNCTION */
	returning_->named_function_subnode_ =
			stt_named_function_subnode_default_constructor();
	returning_->named_function_subnode_->name_ =
			identifier_at_position_two->identifier_subnode_->value_;
	returning_->named_function_subnode_->operations_ =
			function_statements_clause->operations_list_subnode_->operations_;
	returning_->named_function_subnode_->where_value_bindings_ =
			function_where_clauses->where_value_bindings_subnode_->where_value_bindings_;
	returning_->named_function_subnode_->type_ =
			STT_NAMED_FUNCTION_SUBNODE_TYPE_CLI_APP_NAMED_FUNCTION;

	returning_->type_ = STT_NODE_TYPE_NAMED_FUNCTION;

	free(identifier_at_position_two->identifier_subnode_);
	free(identifier_at_position_two);
	free(function_statements_clause->operations_list_subnode_);
	free(function_statements_clause);
	free(function_where_clauses->where_value_bindings_subnode_);
	free(function_where_clauses);
	amara_string_destructor(
			identifier_at_position_twenty_one->identifier_subnode_->value_);
	free(identifier_at_position_twenty_one->identifier_subnode_);
	free(identifier_at_position_twenty_one);

	return returning_;
}

stt_node *
bison_annex_function_sequential_statements_out_of_function_statement_and_token_and_and_token_then_and_function_sequential_statements(
		stt_node * function_statement,
		stt_node * function_sequential_statements)
{
	stt_node * returning_;
	stt_operations_simple_list * new_node_sub_child_;

#ifndef NDEBUG
	assertion(function_statement != NULL);
	assertion(function_statement->type_ == STT_NODE_TYPE_OPERATION);
	assertion(function_statement->operation_subnode_ != NULL);
	assertion(function_statement->operation_subnode_->operation_ != NULL);
	assertion(function_sequential_statements != NULL);
	assertion(function_sequential_statements->type_ ==
			STT_NODE_TYPE_CLI_OPERATIONS_LIST);
	assertion(function_sequential_statements->operations_list_subnode_ !=
			NULL);
#endif

#ifndef NDEBUG
	assertion(function_sequential_statements->operations_list_subnode_->operations_->first !=
			NULL);
#endif

	new_node_sub_child_ = stt_operations_simple_list_default_constructor();
	forced_assertion(new_node_sub_child_ != NULL);

	new_node_sub_child_->first =
			function_statement->operation_subnode_->operation_;

	new_node_sub_child_->next =
			function_sequential_statements->operations_list_subnode_->operations_;

	function_sequential_statements->operations_list_subnode_->operations_ =
			new_node_sub_child_;

	returning_ = function_sequential_statements;

	free(function_statement->operation_subnode_);

	free(function_statement);

	return returning_;
}

stt_node *
bison_annex_function_sequential_statements_out_of_function_statement(
		stt_node * function_statement)
{
	stt_node * returning_;

#ifndef NDEBUG
	assertion(function_statement != NULL);
	assertion(function_statement->type_ == STT_NODE_TYPE_OPERATION);
	assertion(function_statement->operation_subnode_ != NULL);
	assertion(function_statement->operation_subnode_->operation_ != NULL);
#endif

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

	returning_->operations_list_subnode_ =
			stt_operations_list_subnode_default_constructor();
	forced_assertion(returning_->operations_list_subnode_ != NULL);

	returning_->operations_list_subnode_->operations_ =
			stt_operations_simple_list_default_constructor();
	forced_assertion(returning_->operations_list_subnode_->operations_ !=
			NULL);

	returning_->operations_list_subnode_->operations_->first =
			function_statement->operation_subnode_->operation_;

	returning_->operations_list_subnode_->operations_->next = NULL;

	returning_->type_ = STT_NODE_TYPE_CLI_OPERATIONS_LIST;

	free(function_statement->operation_subnode_);

	free(function_statement);

	return returning_;
}

stt_node *
bison_annex_function_parallel_statements_out_of_function_statement_and_token_and_and_token_then_and_function_parallel_statements(
		stt_node * function_statement,
		stt_node * function_parallel_statements)
{
	return
			/* XXX IT IS NOT REALLY PARALLEL ON THE INSIDE, ONLY THE SYNTAX IS ADDED. TRULY PARALLEL EXECUTION REMAINS TODO :) */
			bison_annex_function_sequential_statements_out_of_function_statement_and_token_and_and_token_then_and_function_sequential_statements(  /* XXX */
					function_statement,  /* XXX */
					function_parallel_statements);  /* XXX */
}

stt_node *
bison_annex_function_parallel_statements_out_of_function_statement(
		stt_node * function_statement)
{
	return
			/* XXX IT IS NOT REALLY PARALLEL ON THE INSIDE, ONLY THE SYNTAX IS ADDED. TRULY PARALLEL EXECUTION REMAINS TODO :) */
			bison_annex_function_sequential_statements_out_of_function_statement(  /* XXX */
					function_statement);  /* XXX */
}

stt_node *
function_statement_out_of_token_print_and_expression(stt_node * expression)
{
	stt_node * returning_;

#ifdef DUMP_FLOW_TO_STDERR
	/*
	fprintf(stderr, "%u\n", $2->type_);
	*/
#endif

#ifndef NDEBUG
	assertion(expression != NULL);
	assertion(expression->type_ == STT_NODE_TYPE_EXPRESSION);
#endif

	/*
	if ($2->type_ == STT_NODE_TYPE_STRING_LITERAL) {

		assert_clean_string_literal_node($2);
	} else if ($2->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {

		assert_clean_natural_literal_node($2);
	} else if ($2->type_ == STT_NODE_TYPE_OPERATION) {

		assert_clean_operation_node($2);
		assertion($2->operation_subnode_ != NULL);
		assertion($2->operation_subnode_->operation_ != NULL);
		assertion($2->operation_subnode_->operation_->type_ !=
				STT_OPERATION_TYPE_INVALID);
	} else if ($2->type_ == STT_NODE_TYPE_EXPRESSION) {
	*/

#ifndef NDEBUG
		assert_clean_expression_node(expression);
#endif
	/*
	} else {
		assertion($2->type_ == STT_NODE_TYPE_IDENTIFIER);

		assert_clean_identifier_node($2);
	}
	*/

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

#ifndef NDEBUG
	assertion(returning_->operation_subnode_ == NULL);
#endif
	returning_->operation_subnode_ =
			stt_operation_subnode_default_constructor();
	forced_assertion(returning_->operation_subnode_ != NULL);

#ifndef NDEBUG
	assertion(returning_->operation_subnode_->operation_ == NULL);
#endif
	returning_->operation_subnode_->operation_ =
			stt_operation_default_constructor();
	forced_assertion(returning_->operation_subnode_->operation_ != NULL);

#ifndef NDEBUG
	assertion(returning_->operation_subnode_->operation_->type_ ==
			STT_OPERATION_TYPE_INVALID);
#endif
	returning_->operation_subnode_->operation_->type_ =
		STT_OPERATION_TYPE_PRINT;

#ifndef NDEBUG
	assertion(returning_->operation_subnode_->operation_->args_ == NULL);
#endif
	returning_->operation_subnode_->operation_->args_ =
			stt_operation_args_simple_list_default_constructor();
	forced_assertion(returning_->operation_subnode_->operation_->args_ !=
			NULL);

#ifndef NDEBUG
	assertion(returning_->operation_subnode_->operation_->args_->first ==
			NULL);
#endif
	returning_->operation_subnode_->operation_->args_->first =
			stt_operation_arg_default_constructor();
	forced_assertion(returning_->operation_subnode_->operation_->args_->first !=
			NULL);

#ifndef NDEBUG
	assertion(returning_->operation_subnode_->operation_->args_->first->type_ ==
			STT_OPERATION_ARG_TYPE_INVALID);
#endif
	returning_->operation_subnode_->operation_->args_->first->type_ =
			STT_OPERATION_ARG_TYPE_VALID;

	returning_->operation_subnode_->operation_->args_->first->node_ =
			expression;

#ifndef NDEBUG
	assertion(returning_->operation_subnode_->operation_->args_->next ==
			NULL);
#endif
	/*
	returning_->operation_subnode_->operation_->args_->next = NULL;
	*/

	returning_->type_ = STT_NODE_TYPE_OPERATION;

	return returning_;
}

stt_node *
function_statement_out_of_token_new_and_token_line()
{
	stt_node * returning_;

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

	returning_->operation_subnode_ =
			stt_operation_subnode_default_constructor();
	forced_assertion(returning_->operation_subnode_ != NULL);

#ifndef NDEBUG
	assertion(returning_->operation_subnode_->operation_ == NULL);
#endif
	returning_->operation_subnode_->operation_ =
			stt_operation_default_constructor();
	forced_assertion(returning_->operation_subnode_->operation_ != NULL);

	returning_->operation_subnode_->operation_->type_ =
			STT_OPERATION_TYPE_PRINT_CRLF;

#ifndef NDEBUG
	assertion(returning_->operation_subnode_->operation_->args_ == NULL);
#endif
	returning_->operation_subnode_->operation_->args_ =
			stt_operation_args_simple_list_default_constructor();
	forced_assertion(returning_->operation_subnode_->operation_->args_ !=
			NULL);

	returning_->type_ = STT_NODE_TYPE_OPERATION;

	return returning_;
}

stt_node *
bison_annex_function_where_clauses_out_of_token_where_and_function_where_clause_and_function_where_clauses(
		stt_node * function_where_clause,
		stt_node * function_where_clauses)
{
	stt_node * returning_;
	stt_where_value_bindings_simple_list * where_value_bindings_;
	stt_where_value_binding * where_value_binding_;

#ifndef NDEBUG
	assertion(function_where_clause != NULL);
	assertion(function_where_clause->type_ == STT_NODE_TYPE_WHERE_BINDING);
	assertion(function_where_clause->where_value_binding_subnode_ != NULL);
	assertion(function_where_clause->where_value_binding_subnode_->where_value_binding_ !=
			NULL);
#endif

	where_value_binding_ = stt_where_value_binding_copy_constructor(
			function_where_clause->where_value_binding_subnode_->where_value_binding_);
	forced_assertion(where_value_binding_ != NULL);
	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

#ifndef NDEBUG
	assertion(function_where_clauses != NULL);
	assertion(function_where_clauses->type_ ==
			STT_NODE_TYPE_WHERE_BINDINGS);
	assertion(function_where_clauses->where_value_bindings_subnode_ !=
			NULL);
	assertion(function_where_clauses->where_value_bindings_subnode_->where_value_bindings_ !=
			NULL);
#endif
	/*
	if (function_where_clauses == NULL) {
		where_value_bindings_ =
				stt_where_value_bindings_simple_list_default_constructor();
	} else {
	*/
#ifndef NDEBUG
		assertion(function_where_clauses->type_ ==
				STT_NODE_TYPE_WHERE_BINDINGS);
		assertion(function_where_clauses->where_value_bindings_subnode_ !=
				NULL);
		assertion(function_where_clauses->where_value_bindings_subnode_->where_value_bindings_ !=
				NULL);
#endif
		where_value_bindings_ =
				stt_where_value_bindings_simple_list_copy_constructor(
						function_where_clauses->where_value_bindings_subnode_->where_value_bindings_);
		forced_assertion(where_value_bindings_ != NULL);
	/*
	}
	*/
	where_value_bindings_ = stt_where_value_bindings_simple_list_push_front(
			where_value_bindings_, where_value_binding_);
	forced_assertion(where_value_bindings_ != NULL);  /* XXX ??? */

	stt_where_value_binding_destructor(where_value_binding_);

	stt_node_set_where_value_bindings(returning_, where_value_bindings_);

	stt_where_value_bindings_simple_list_destructor(where_value_bindings_);

	stt_node_destructor(function_where_clause);

	stt_node_destructor(function_where_clauses);

	return returning_;
}

stt_node *
bison_annex_function_where_clauses_out_of_nothing(void)
{
	stt_node * returning_;
	stt_where_value_bindings_simple_list * where_value_bindings_;

	where_value_bindings_ =
			stt_where_value_bindings_simple_list_default_constructor();
	forced_assertion(where_value_bindings_ != NULL);
#ifndef NDEBUG
	assertion(where_value_bindings_->first == NULL);
	assertion(where_value_bindings_->next == NULL);
#endif

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

	stt_node_set_where_value_bindings(returning_, where_value_bindings_);
	forced_assertion(returning_->where_value_bindings_subnode_ != NULL);
	forced_assertion(returning_->where_value_bindings_subnode_->where_value_bindings_ !=
			NULL);
	/* XXX missing assertions. here. */

	stt_where_value_bindings_simple_list_destructor(where_value_bindings_);

	return returning_;
}

stt_node *
function_where_clause_out_of_token_identifier_and_token_is_and_token_bound_and_token_to_and_expression(
		stt_node * identifier, stt_node * expression)
{
	stt_node * returning_;
	stt_where_value_binding * where_value_binding_;

#ifndef NDEBUG
	assertion_two(identifier != NULL, "543");
	assertion_two(identifier->type_ == STT_NODE_TYPE_IDENTIFIER, "544");
	assertion_two(identifier->identifier_subnode_ != NULL, "545");
	assertion_two(identifier->identifier_subnode_->value_ != NULL, "546");
	assertion_two(identifier->identifier_subnode_->value_->value_ != NULL,
			"547");
	assertion_two(expression != NULL, "548");
#endif

	/*
	if (expression->type_ == STT_NODE_TYPE_EXPRESSION) {
	*/

#ifndef NDEBUG
		assertion_two(expression->type_ == STT_NODE_TYPE_EXPRESSION,
				"549");
		assertion_two(expression->expression_subnode_ != NULL, "550");
		assertion_two(
				expression->expression_subnode_->expression_ !=
						NULL,
				"551");
#endif
	/*
	} else {
		forced_assertion_two(
				expression->type_ == STT_NODE_TYPE_IDENTIFIER,
				"556");

		FIXME
	}
	*/

	where_value_binding_ = stt_where_value_binding_exhaustive_constructor(
			identifier->identifier_subnode_->value_,
			expression->expression_subnode_->expression_);
	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);
	stt_node_set_where_value_binding(returning_, where_value_binding_);

	stt_where_value_binding_destructor(where_value_binding_);

	stt_node_destructor(identifier);

	stt_node_destructor(expression);

	return returning_;
}

/*
stt_node *
bison_annex_function_statement_out_of_token_execute_and_nonterminal_function_executable_expression(
		stt_node * function_executable_expression)
{
#ifndef NDEBUG
	assertion(function_executable_expression != NULL);
#endif
	forced_assertion(function_executable_expression->type_ ==  *//* XXX *//*
			STT_NODE_TYPE_INVALID);  *//* XXX *//*
	function_executable_expression->type_ = STT_NODE_TYPE_OPERATION;  *//* XXX *//*
	return function_executable_expression;  *//* XXX *//*
}
*/

stt_node*
bison_annex_function_statement_out_of_token_execute_and_nonterminal_function_executable_expression(
		stt_node * function_executable_expression)
{
	stt_node * returning_;
	stt_operation_arg * operation_arg_;
	stt_operation_args_simple_list * operation_args_;

#ifndef NDEBUG
	assertion(function_executable_expression != NULL);
#endif
	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

	returning_->operation_subnode_ =
			stt_operation_subnode_default_constructor();
	forced_assertion(returning_->operation_subnode_ != NULL);

	returning_->operation_subnode_->operation_ =
			stt_operation_default_constructor();
	forced_assertion(returning_->operation_subnode_->operation_ != NULL);

	operation_args_ = stt_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);

	operation_arg_ = stt_operation_arg_default_constructor();
	forced_assertion(operation_arg_ != NULL);

	stt_operation_arg_set_node(
			operation_arg_, function_executable_expression);

	operation_args_ = stt_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);

	stt_operation_set_args(
			returning_->operation_subnode_->operation_,
			operation_args_);

	stt_operation_set_type(
			returning_->operation_subnode_->operation_,
			STT_OPERATION_TYPE_EXECUTION);

	stt_node_set_type(returning_, STT_NODE_TYPE_OPERATION);

	return returning_;
}

stt_node *
bison_annex_function_executable_expression_out_of_nonterminal_function_call_without_return_value(
		stt_node * function_call_without_return_value)
{
	stt_node * returning_;

/*
	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

	returning_->operation_subnode_ =
			stt_operation_subnode_default_constructor();
	forced_assertion(returning_->operation_subnode_ != NULL);

	returning_->operation_subnode_->operation_ =
			stt_operation_default_constructor();
	forced_assertion(returning_->operation_subnode_->operation_ != NULL);

	stt_operation_set_args(function_call_without_return_value);
*/

	returning_ = function_call_without_return_value;

	return returning_;
}

stt_node *
bison_annex_function_call_without_return_value_out_of_nonterminal_function_call(
		stt_node * function_call)
{
#ifndef NDEBUG
	assertion(function_call != NULL);
	assertion(function_call->type_ == STT_NODE_TYPE_NAMED_FUNCTION_CALL);
	assertion(function_call->sub_named_function_call_ != NULL);
	assertion(function_call->sub_named_function_call_->named_function_call_ != NULL);
	assertion(function_call->sub_named_function_call_->named_function_call_->pending_semantic_checks_ != NULL);
	assertion(function_call->sub_named_function_call_->named_function_call_->pending_semantic_checks_->called_function_has_no_return_value_ == AMARA_BOOLEAN_INVALID);
#endif
	function_call->sub_named_function_call_->named_function_call_->pending_semantic_checks_->called_function_has_no_return_value_ = AMARA_BOOLEAN_TRUE;
	return function_call;
}

stt_node *
bison_annex_function_call_out_of_token_call_and_token_function_and_token_identifier_and_nonterminal_function_call_arguments(
		stt_node * identifier_node, stt_node * function_call_arguments_node)
{
	stt_node * returning_;
	stt_named_function_call * named_function_call_;

#ifndef NDEBUG
	assertion(identifier_node != NULL);
	assertion(identifier_node->type_ == STT_NODE_TYPE_IDENTIFIER);
	assertion(identifier_node->identifier_subnode_ != NULL);
	assertion(identifier_node->identifier_subnode_->value_ != NULL);
	assertion(identifier_node->identifier_subnode_->value_->value_ != NULL);

	assertion(function_call_arguments_node != NULL);
	if (function_call_arguments_node->type_ == STT_NODE_TYPE_NAMED_FUNCTION_CALL_ARGUMENTS_LIST) {
		assertion(function_call_arguments_node->type_ ==  STT_NODE_TYPE_NAMED_FUNCTION_CALL_ARGUMENTS_LIST);
		assertion(function_call_arguments_node->sub_named_function_call_arguments_ != NULL);
		assertion(function_call_arguments_node->sub_named_function_call_arguments_->named_function_call_arguments_ != NULL);
	} else {
		assertion(function_call_arguments_node->type_ ==  STT_NODE_TYPE_EMPTY_NAMED_FUNCTION_CALL_ARGUMENTS_LIST);
		assertion(function_call_arguments_node->sub_named_function_call_arguments_ == NULL);
	}
#endif

	named_function_call_ =
			stt_named_function_call_exhaustive_constructor(
					identifier_node, function_call_arguments_node);
	forced_assertion(named_function_call_ != NULL);

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

	returning_->sub_named_function_call_ =
			stt_node_sub_named_function_call_exhaustive_constructor(
					named_function_call_);
	forced_assertion(returning_->sub_named_function_call_ != NULL);

	returning_->type_ = STT_NODE_TYPE_NAMED_FUNCTION_CALL;

	return returning_;
}

stt_node *
bison_annex_function_call_arguments_out_of_token_with_and_token_no_and_token_arguments_and_token_at_and_token_all()
{
	stt_node * returning_;

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

	returning_->type_ = STT_NODE_TYPE_EMPTY_NAMED_FUNCTION_CALL_ARGUMENTS_LIST;  /* XXX */

	return returning_;
}

stt_node *
bison_annex_expression_out_of_token_if_and_condition_and_token_then_and_expression_and_token_else_and_expression_and_token_end_and_token_if(
		stt_node * condition, stt_node * expression_then,
		stt_node * expression_else)
{
	stt_node * returning_;
	stt_expression_sub_conditional * expression_sub_conditional_;
	stt_expression * expression_;

#ifndef NDEBUG
	assertion(condition != NULL);
	assertion(condition->type_ == STT_NODE_TYPE_CONDITION);
	assertion(condition->condition_subnode_ != NULL);
	assertion(condition->condition_subnode_->condition_ != NULL);
	assertion(condition->condition_subnode_->condition_->type_ !=
			STT_CONDITION_TYPE_INVALID);
	assertion(expression_then != NULL);
	if (expression_then->type_ != STT_NODE_TYPE_EXPRESSION) {

#ifdef DUMP_FLOW_TO_STDERR
		/*
		fprintf(stderr, "%u\n", expression_then->type_);
		*/
#endif
	}
	assertion(expression_then->type_ == STT_NODE_TYPE_EXPRESSION);
	assertion(expression_then->expression_subnode_ != NULL);
	assertion(expression_then->expression_subnode_->expression_ != NULL);
	assertion(expression_then->expression_subnode_->expression_->type_ !=
			STT_EXPRESSION_TYPE_INVALID);
	assertion(expression_else != NULL);
	assertion(expression_else->type_ == STT_NODE_TYPE_EXPRESSION);
	assertion(expression_else->expression_subnode_ != NULL);
	assertion(expression_else->expression_subnode_->expression_ != NULL);
	assertion(expression_else->expression_subnode_->expression_->type_ !=
			STT_EXPRESSION_TYPE_INVALID);
#endif

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_NODE_TYPE_INVALID);
	/* assert_all_subnodes_are_null(returning_); */
#endif

	expression_sub_conditional_ =
			stt_expression_sub_conditional_default_constructor();
	forced_assertion(expression_sub_conditional_ != NULL);

	stt_expression_sub_conditional_set_condition(
			expression_sub_conditional_, condition->condition_subnode_->condition_);

	stt_node_destructor(condition);

	stt_expression_sub_conditional_set_expression_then(
			expression_sub_conditional_, expression_then->expression_subnode_->expression_);

	stt_node_destructor(expression_then);

	stt_expression_sub_conditional_set_expression_else(
			expression_sub_conditional_, expression_else->expression_subnode_->expression_);

	stt_node_destructor(expression_else);

	expression_ = stt_expression_default_constructor();
	forced_assertion(expression_ != NULL);

	stt_expression_set_conditional(
			expression_, expression_sub_conditional_);

	stt_expression_sub_conditional_destructor(expression_sub_conditional_);

	stt_node_set_expression(returning_, expression_);

	stt_expression_destructor(expression_);

	return returning_;
}

stt_node *
bison_annex_expression_out_of_token_string_literal(stt_node * string_literal)
{
	stt_node * returning_;
	stt_expression * expression_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

#ifndef NDEBUG
	assertion(string_literal != NULL);
	assertion_two(
			string_literal->type_ == STT_NODE_TYPE_STRING_LITERAL,
			"unexpected node type at %s:%d\n");
	assertion(string_literal->string_literal_subnode_ != NULL);
	assertion(string_literal->string_literal_subnode_->string_literal_ !=
			NULL);
	assertion(string_literal->string_literal_subnode_->string_literal_->value_ !=
			NULL);
	assert_clean_string_literal_node(string_literal);
#endif

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_NODE_TYPE_INVALID);
#endif

	expression_ = stt_expression_default_constructor();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

	stt_expression_set_string_literal(
			expression_,
			string_literal->string_literal_subnode_->string_literal_);
#ifndef NDEBUG
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL);
#endif
	forced_assertion(expression_->sub_string_literal_ != NULL);
	forced_assertion(expression_->sub_string_literal_->string_literal_ !=
			NULL);
	forced_assertion(expression_->sub_string_literal_->string_literal_->value_ !=
			NULL);
#ifndef NDEBUG
	assertion_two(string_literal->type_ == STT_NODE_TYPE_STRING_LITERAL,
			"unexpected node type...\n");
	assertion(string_literal->string_literal_subnode_ != NULL);
	assertion(string_literal->string_literal_subnode_->string_literal_ !=
			NULL);
	assertion(string_literal->string_literal_subnode_->string_literal_->value_ !=
			NULL);
	equality_ = amara_string_equality(
			expression_->sub_string_literal_->string_literal_,
			string_literal->string_literal_subnode_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_node_set_expression(returning_, expression_);
#ifndef NDEBUG
	assertion(returning_->type_ == STT_NODE_TYPE_EXPRESSION);
#endif
	forced_assertion(returning_->expression_subnode_ != NULL);
	forced_assertion(returning_->expression_subnode_->expression_ != NULL);
#ifndef NDEBUG
	assertion(expression_->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL);
	assertion(expression_->sub_string_literal_ != NULL);
	assertion(expression_->sub_string_literal_->string_literal_ != NULL);
	assertion(expression_->sub_string_literal_->string_literal_->value_ !=
			NULL);
	equality_ = stt_expression_equality(
			returning_->expression_subnode_->expression_,
			expression_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_expression_destructor(expression_);

	stt_node_destructor(string_literal);

	return returning_;
}

/**  Friend declaration. */
void
b_trace_chars_array(const char * message)
;

stt_node *
bison_annex_expression_out_of_token_natural_literal(
		stt_node * natural_literal)
{
	stt_node * returning_;
	natural * natural_;
	stt_expression * expression_;

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

#ifndef NDEBUG
	assertion_two(natural_literal->type_ == STT_NODE_TYPE_NATURAL_LITERAL,
			"unexpected node type at %s:%d\n");
	assert_clean_natural_literal_node(natural_literal);
#endif
	/*
	b_trace_chars_array("number_literal (");
	b_trace_chars_array(
			returning_->natural_literal_subnode_->raw_->value_);  LINE SEGFAULTS!!!
	b_trace_chars_array(") : T_NATURAL_LITERAL (");
	b_trace_chars_array(
			natural_literal->natural_literal_subnode_->raw_->value_);
	b_trace_chars_array(")\n");
	*/

	natural_ = natural_exhaustive_constructor(
			natural_literal->natural_literal_subnode_->raw_);
	forced_assertion(natural_ != NULL);

	expression_ = stt_expression_default_constructor();
	forced_assertion(expression_ != NULL);

	stt_expression_set_natural_literal(expression_, natural_);

	stt_node_set_expression(returning_, expression_);
#ifndef NDEBUG
	assertion(returning_ != NULL);
	assertion(returning_->type_ == STT_NODE_TYPE_EXPRESSION);
	assertion(returning_->expression_subnode_ != NULL);
	assertion(returning_->expression_subnode_->expression_ != NULL);
	assertion(returning_->expression_subnode_->expression_->type_ ==
			STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(returning_->expression_subnode_->expression_->sub_natural_literal_ !=
			NULL);
	assertion(returning_->expression_subnode_->expression_->sub_natural_literal_->natural_literal_ !=
			NULL);
	assertion(returning_->expression_subnode_->expression_->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(returning_->expression_subnode_->expression_->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
#endif

	natural_destructor(natural_);

	stt_expression_destructor(expression_);

	stt_node_destructor(natural_literal);

#ifndef NDEBUG
	assertion(returning_ != NULL);
	assertion(returning_->type_ == STT_NODE_TYPE_EXPRESSION);
	assertion(returning_->expression_subnode_ != NULL);
	assertion(returning_->expression_subnode_->expression_ != NULL);
	assertion(returning_->expression_subnode_->expression_->type_ ==
			STT_EXPRESSION_TYPE_NATURAL_LITERAL);
	assertion(returning_->expression_subnode_->expression_->sub_natural_literal_ !=
			NULL);
	assertion(returning_->expression_subnode_->expression_->sub_natural_literal_->natural_literal_ !=
			NULL);
	assertion(returning_->expression_subnode_->expression_->sub_natural_literal_->natural_literal_->raw_ !=
			NULL);
	assertion(returning_->expression_subnode_->expression_->sub_natural_literal_->natural_literal_->raw_->value_ !=
			NULL);
#endif

	return returning_;
}

stt_node *
bison_annex_condition_out_of_expression_and_token_is_and_token_less_and_token_than_and_expression(
		stt_node * left_expression, stt_node * right_expression)
{
	stt_node * returning_;
	/*
	natural * left_hand_expression_natural_;
	*/
	stt_expression * left_hand_expression_;
	/*
	natural * right_hand_expression_natural_;
	*/
	stt_expression * right_hand_expression_;
	stt_condition * condition_;

#ifndef NDEBUG
	assertion(left_expression != NULL);
	assertion(left_expression->type_ == STT_NODE_TYPE_EXPRESSION);
	/*
	if (left_expression->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
		assertion(left_expression->natural_literal_subnode_ != NULL);
		assertion(left_expression->natural_literal_subnode_->raw_ !=
				NULL);
		assertion(left_expression->natural_literal_subnode_->raw_->value_ !=
				NULL);
		assert_valid_raw_natural(
				left_expression->natural_literal_subnode_->raw_);
	} else if (left_expression->type_ == STT_NODE_TYPE_IDENTIFIER) {
		assertion(left_expression->identifier_subnode_ != NULL);
		assertion(left_expression->identifier_subnode_->value_ !=
				NULL);
	} else {
	*/
		if (left_expression->type_ != STT_NODE_TYPE_EXPRESSION) {

#ifdef DUMP_FLOW_TO_STDERR
			fprintf(stderr, "%u\n", left_expression->type_);
#endif
		}
		assertion(left_expression->type_ == STT_NODE_TYPE_EXPRESSION);
		assertion(left_expression->expression_subnode_ != NULL);
		assertion(left_expression->expression_subnode_->expression_ !=
				NULL);
	/*
	}
	*/
#endif

#ifndef NDEBUG
	assertion(right_expression != NULL);
	assertion(right_expression->type_ == STT_NODE_TYPE_EXPRESSION);
	/*
	if (right_expression->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
		assertion(right_expression->natural_literal_subnode_ != NULL);
		assertion(right_expression->natural_literal_subnode_->raw_ !=
				NULL);
		assertion(right_expression->natural_literal_subnode_->raw_->value_ !=
				NULL);
		assert_valid_raw_natural(
				right_expression->natural_literal_subnode_->raw_);
	} else if (right_expression->type_ == STT_NODE_TYPE_IDENTIFIER) {
		assertion(right_expression->identifier_subnode_ != NULL);
		assertion(right_expression->identifier_subnode_->value_ !=
				NULL);
	} else {
	*/
		if (right_expression->type_ != STT_NODE_TYPE_EXPRESSION) {

#ifdef DUMP_FLOW_TO_STDERR
			fprintf(stderr, "%u\n", right_expression->type_);
#endif
		}
		assertion(right_expression->type_ == STT_NODE_TYPE_EXPRESSION);
		assertion(right_expression->expression_subnode_ != NULL);
		assertion(right_expression->expression_subnode_->expression_ !=
				NULL);
	/*
	}
	*/
#endif

	left_hand_expression_ = NULL;
	forced_assertion(left_expression->type_ == STT_NODE_TYPE_EXPRESSION);
	/*
	if (left_expression->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
		left_hand_expression_ = stt_expression_default_constructor();
		forced_assertion(left_hand_expression_ != NULL);
		left_hand_expression_natural_ =
				natural_exhaustive_constructor(
						left_expression->natural_literal_subnode_->raw_);
		forced_assertion(left_hand_expression_natural_ != NULL);
		stt_expression_set_natural_literal(
				left_hand_expression_,
				left_hand_expression_natural_);
	} else if (left_expression->type_ == STT_NODE_TYPE_IDENTIFIER) {
		left_hand_expression_ = stt_expression_default_constructor();
		forced_assertion(left_hand_expression_ != NULL);
		stt_expression_set_identifier(
				left_hand_expression_,
				left_expression->identifier_subnode_->value_);
	} else {
		forced_assertion(left_expression->type_ == STT_NODE_TYPE_EXPRESSION);
		*/

		left_hand_expression_ = stt_expression_copy_constructor(
				left_expression->expression_subnode_->expression_);
	/*
	}
	*/

	stt_node_destructor(left_expression);

	right_hand_expression_ = NULL;
	forced_assertion(right_expression->type_ == STT_NODE_TYPE_EXPRESSION);
	/*
	if (right_expression->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
		right_hand_expression_ = stt_expression_default_constructor();
		forced_assertion(right_hand_expression_ != NULL);
		right_hand_expression_natural_ =
				natural_exhaustive_constructor(
						right_expression->natural_literal_subnode_->raw_);
		forced_assertion(right_hand_expression_natural_ != NULL);
		stt_expression_set_natural_literal(
				right_hand_expression_,
				right_hand_expression_natural_);
	} else {
	*/
		forced_assertion(right_expression->type_ ==
				STT_NODE_TYPE_EXPRESSION);

		right_hand_expression_ = stt_expression_copy_constructor(
				right_expression->expression_subnode_->expression_);
	/*
	}
	*/

	stt_node_destructor(right_expression);

	condition_ = stt_condition_default_constructor();
	forced_assertion(condition_ != NULL);

	stt_condition_initialize_less_than(
			condition_, left_hand_expression_,
			right_hand_expression_);

	stt_expression_destructor(left_hand_expression_);
	stt_expression_destructor(right_hand_expression_);

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

	stt_node_set_condition(returning_, condition_);

	stt_condition_destructor(condition_);

	return returning_;
}

stt_node *
bison_annex_condition_out_of_expression_and_token_is_and_token_greater_and_token_than_and_expression(
		stt_node * left_expression, stt_node * right_expression)
{
	stt_node * returning_;
	/*
	natural * left_hand_expression_natural_;
	*/
	stt_expression * left_hand_expression_;
	/*
	natural * right_hand_expression_natural_;
	*/
	stt_expression * right_hand_expression_;
	stt_condition * condition_;

#ifndef NDEBUG
	assertion(left_expression != NULL);
	assertion(left_expression->type_ == STT_NODE_TYPE_EXPRESSION);
	/*
	if (left_expression->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
		assertion(left_expression->natural_literal_subnode_ != NULL);
		assertion(left_expression->natural_literal_subnode_->raw_ !=
				NULL);
		assertion(left_expression->natural_literal_subnode_->raw_->value_ !=
				NULL);
		assert_valid_raw_natural(
				left_expression->natural_literal_subnode_->raw_);
	} else if (left_expression->type_ == STT_NODE_TYPE_IDENTIFIER) {
		assertion(left_expression->identifier_subnode_ != NULL);
		assertion(left_expression->identifier_subnode_->value_ !=
				NULL);
	} else {
	*/
		if (left_expression->type_ != STT_NODE_TYPE_EXPRESSION) {

#ifdef DUMP_FLOW_TO_STDERR
			fprintf(stderr, "%u\n", left_expression->type_);
#endif
		}
		assertion(left_expression->type_ == STT_NODE_TYPE_EXPRESSION);
		assertion(left_expression->expression_subnode_ != NULL);
		assertion(left_expression->expression_subnode_->expression_ !=
				NULL);
	/*
	}
	*/
#endif

#ifndef NDEBUG
	assertion(right_expression != NULL);
	assertion(right_expression->type_ == STT_NODE_TYPE_EXPRESSION);
	/*
	if (right_expression->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
		assertion(right_expression->natural_literal_subnode_ != NULL);
		assertion(right_expression->natural_literal_subnode_->raw_ !=
				NULL);
		assertion(right_expression->natural_literal_subnode_->raw_->value_ !=
				NULL);
		assert_valid_raw_natural(
				right_expression->natural_literal_subnode_->raw_);
	} else if (right_expression->type_ == STT_NODE_TYPE_IDENTIFIER) {
		assertion(right_expression->identifier_subnode_ != NULL);
		assertion(right_expression->identifier_subnode_->value_ !=
				NULL);
	} else {
	*/
		if (right_expression->type_ != STT_NODE_TYPE_EXPRESSION) {

#ifdef DUMP_FLOW_TO_STDERR
			fprintf(stderr, "%u\n", right_expression->type_);
#endif
		}
		assertion(right_expression->type_ == STT_NODE_TYPE_EXPRESSION);
		assertion(right_expression->expression_subnode_ != NULL);
		assertion(right_expression->expression_subnode_->expression_ !=
				NULL);
	/*
	}
	*/
#endif

	left_hand_expression_ = NULL;
	forced_assertion(left_expression->type_ == STT_NODE_TYPE_EXPRESSION);
	/*
	if (left_expression->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
		left_hand_expression_ = stt_expression_default_constructor();
		forced_assertion(left_hand_expression_ != NULL);
		left_hand_expression_natural_ =
				natural_exhaustive_constructor(
						left_expression->natural_literal_subnode_->raw_);
		forced_assertion(left_hand_expression_natural_ != NULL);
		stt_expression_set_natural_literal(
				left_hand_expression_,
				left_hand_expression_natural_);
	} else if (left_expression->type_ == STT_NODE_TYPE_IDENTIFIER) {
		left_hand_expression_ = stt_expression_default_constructor();
		forced_assertion(left_hand_expression_ != NULL);
		stt_expression_set_identifier(
				left_hand_expression_,
				left_expression->identifier_subnode_->value_);
	} else {
		forced_assertion(left_expression->type_ == STT_NODE_TYPE_EXPRESSION);
		*/

		left_hand_expression_ = stt_expression_copy_constructor(
				left_expression->expression_subnode_->expression_);
	/*
	}
	*/

	stt_node_destructor(left_expression);

	right_hand_expression_ = NULL;
	forced_assertion(right_expression->type_ == STT_NODE_TYPE_EXPRESSION);
	/*
	if (right_expression->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
		right_hand_expression_ = stt_expression_default_constructor();
		forced_assertion(right_hand_expression_ != NULL);
		right_hand_expression_natural_ =
				natural_exhaustive_constructor(
						right_expression->natural_literal_subnode_->raw_);
		forced_assertion(right_hand_expression_natural_ != NULL);
		stt_expression_set_natural_literal(
				right_hand_expression_,
				right_hand_expression_natural_);
	} else {
		forced_assertion(right_expression->type_ ==
				STT_NODE_TYPE_EXPRESSION);
		*/

		right_hand_expression_ = stt_expression_copy_constructor(
				right_expression->expression_subnode_->expression_);
	/*
	}
	*/

	stt_node_destructor(right_expression);

	condition_ = stt_condition_default_constructor();
	forced_assertion(condition_ != NULL);

	stt_condition_initialize_greater_than(
			condition_, left_hand_expression_,
			right_hand_expression_);

	stt_expression_destructor(left_hand_expression_);
	stt_expression_destructor(right_hand_expression_);

	returning_ = stt_node_default_constructor();
	forced_assertion(returning_ != NULL);

	stt_node_set_condition(returning_, condition_);

	stt_condition_destructor(condition_);

	return returning_;
}
