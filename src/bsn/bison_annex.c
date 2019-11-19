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
 * src/bsn/bison_annex.c: Amara Minia scripts Bison parser helper
 * functions.
 */

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

  assertion_two(named_functions_and_applications_and_execution_requests != NULL,
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
  returning_->doc_subnode_ = named_functions_and_applications_and_execution_requests->doc_subnode_;

  if (returning_->doc_subnode_->named_functions_ == NULL) {

    returning_->doc_subnode_->named_functions_ =
        stt_named_functions_simple_list_default_constructor();
  }

  if (returning_->doc_subnode_->applications_ == NULL) {

    returning_->doc_subnode_->applications_ =
        stt_applications_simple_list_default_constructor();
  }

  if (returning_->doc_subnode_->execution_requests_ == NULL) {

    returning_->doc_subnode_->execution_requests_ =
        stt_execution_requests_simple_list_default_constructor();
  }

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
		free(named_function->named_function_subnode_);
		free(named_function);
	}

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

		assert_clean_expression_node(expression);
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
