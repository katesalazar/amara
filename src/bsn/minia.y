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
 * src/bsn/minia.y: Amara Minia scripts Bison parser.
 */

/* XXX    Consider replacing copied pointers for copy constructors.
 * XXX  See: `https://stackoverflow.com/questions/52103896/` and
 * XXX  `https://stackoverflow.com/questions/31104302/`.
 * XXX    Management possibilities:
 * XXX  - Transfer ownership of pointed structures elsewhere.
 * XXX    - Variant: Bison only stores pointers to pointers instead of
 * XXX      structs.
 * XXX    - Variant: Bison only stores UUIDs in character arrays,
 * XXX      effectively pointing to constructions stored elsewhere.
 * XXX  - Store variants serialized in an array. Seems valid, but what
 * XXX    is the cost of constant serialization and deserialization? */

/*   This `parse.error` `verbose` directive is very nice to show fairly
 * better syntax errors. However, it might cause trouble to some `bison`
 * versions. It has been found to be nice when using Bison `3.0.4` but
 * however causing build issues when using Bison `2.7`. Don't hesitate
 * to use it when developing, but try not to pass it to the CI monitored
 * branches for now. */
/*
%define parse.error verbose
*/

%parse-param { stt_node * syntax_tree }

%{

/*   For the `FILE` struct. */
#include <stdio.h>

/*   For `void exit(int status)`. */
#include <stdlib.h>

/*   For `size_t strlen(const char * s)`. */
#include <string.h>

/*   For `void assertion_two(int expression, const char * message)`. */
#include "../asr/assertion.h"

/*   For most basic arithmetic. */
#include "../brt/natural.h"

/*   For the syntax tree nodes and node types. */
#include "../stt/stt_node.h"

#include "bison_annex.h"

extern int yylex(void);

extern int yyparse(stt_node * syntax_tree);

extern FILE * miniain;

void yyerror(stt_node * syntax_tree, const char * s);

#ifdef TRACE_BISON
#undef TRACE_BISON
#endif
/* #define TRACE_BISON */

#ifdef TRACE_BISON
#define TRACE_BISON_CONSTANT_VALUE 0xFF
#else
#define TRACE_BISON_CONSTANT_VALUE 0x00
#endif

const unsigned char bison_trace_constant = TRACE_BISON_CONSTANT_VALUE;

void
bison_trace_chars_array(const char * message)
{
  if (bison_trace_constant) {
    fprintf(stderr, "%s", message);
  }
}

void
b_trace_chars_array(const char * message)
{
  bison_trace_chars_array(message);
}

void
bison_trace_unsigned_char(unsigned char value)
{
  if (bison_trace_constant) {
    fprintf(stderr, "%u", value);
  }
}

void
b_trace_unsigned_char(unsigned char value)
{
  bison_trace_unsigned_char(value);
}

%}

%union {
  stt_node * node;
}

%token T_AT_SYMBOL

%token<node> T_NATURAL_LITERAL
%token<node> T_INTEGER_LITERAL
%token<node> T_RATIONAL_LITERAL

%token T_A T_ALL T_AN T_AND T_APPLICATION T_ARGS T_AT T_AWESOME T_BOUND
%token T_CARRIAGE
%token T_CAUSES T_CHAIN T_COMMAND T_COMMANDS T_DIVISION
%token T_DOES T_EASE T_EFFECTS T_ELSE T_END
%token T_ENTRY T_FEED T_FORMULA T_FUNCTION T_GREATER T_IF T_INTEGER T_INTERFACE
%token T_IS T_IT T_LESS T_LINE T_NATURAL T_NEW
%token T_NO T_NOR
%token T_NOTHING T_OPERATOR T_POINT T_PRINT T_RATIONAL T_READ T_RECEIVES
%token T_RETURN T_RETURNS T_RUN T_SET T_SIDE T_SIMPLE T_SMALL T_SO
%token T_SUBSTRACTION
%token T_THAN T_THAT T_THE T_THEN T_THREAD T_TO
%token T_WHERE T_WITH T_WITHOUT

%token<node> T_STRING_LITERAL

%token<node> T_IDENTIFIER

%token<node> T_DICE_EXPRESSION

%left T_TYPE T_OF
%left T_MINUS
%left T_TIMES T_DIVIDED T_BY

%type<node> ignored
%type<node> condition
%type<node> expression
%type<node> function_where_clause
%type<node> function_where_clauses
%type<node> function_statement
%type<node> function_statements
%type<node> function_returns_clause
%type<node> function_receives_clause
%type<node> cli_named_function
%type<node> named_function
%type<node> cli_application
%type<node> application
%type<node> execution_request
%type<node> named_functions_and_applications_and_execution_requests
%type<node> document

%start document

%%

/*   A doc is a collection of functions, applications, and execution
 * requests. */
document :
  named_functions_and_applications_and_execution_requests
{
  b_trace_chars_array("document : named_functions_and_applications_and_execution_requests\n");
  syntax_tree = document_out_of_named_functions_and_applications_and_execution_requests(
      syntax_tree, $1);
  forced_assertion(syntax_tree != NULL);
}
;

named_functions_and_applications_and_execution_requests :
  named_function named_functions_and_applications_and_execution_requests
{
  b_trace_chars_array(
      "named_functions_and_applications_and_execution_requests : named_function named_functions_and_applicationss_and_execution_requests\n");
  $$ = named_functions_and_applications_and_execution_requests_out_of_named_function_and_named_functions_and_applications_and_execution_requests(
      $1, $2);
  forced_assertion($$ != NULL);
}
| application named_functions_and_applications_and_execution_requests
{
  b_trace_chars_array(
      "fns_and_apps_defs_and_exectn_reqs : app_def fns_and_apps_defs_and_exectn_reqs\n");
  if ($2 == NULL) {
    $$ = stt_node_default_constructor();
    $$->type_ = STT_NODE_TYPE_DOC_FRAGMENT;
    $$->doc_subnode_ = stt_doc_subnode_default_constructor();
    $$ = register_application($$, $1);
    assertion($$->doc_subnode_ != NULL);
    free($1->application_subnode_);
    free($1);
  } else {
    assertion_two($2->type_ = STT_NODE_TYPE_DOC_FRAGMENT,
        "unexpected type of `fns_and_apps_defs_and_exectn_reqs`");
    assertion($2->doc_subnode_ != NULL);
    $$ = register_application($2, $1);
    assertion($$->doc_subnode_ != NULL);
    free($1->application_subnode_);
    free($1);
  }
}
| execution_request named_functions_and_applications_and_execution_requests
{
  b_trace_chars_array(
      "fns_and_apps_defs_and_exectn_reqs : exectn fns_and_apps_defs_and_exectn_reqs\n");
  if ($2 == NULL) {
    $$ = stt_node_default_constructor();
    $$->type_ = STT_NODE_TYPE_DOC_FRAGMENT;
    $$->doc_subnode_ = stt_doc_subnode_default_constructor();
    $$ = register_execution_request($$, $1);
    assertion($$->doc_subnode_ != NULL);
    free($1->execution_request_subnode_);
    free($1);
  } else {
    assertion_two($2->type_ = STT_NODE_TYPE_DOC_FRAGMENT,
        "unexpected type of `fns_and_apps_defs_and_exectn_reqs`");
    assertion($2->doc_subnode_ != NULL);
    $$ = register_execution_request($2, $1);
    assertion($$->doc_subnode_ != NULL);
    free($1->execution_request_subnode_);
    free($1);
  }
}
| ignored
{
  b_trace_chars_array("fns_and_apps_defs_and_exectn_reqs : ignored\n");
  $$ = named_functions_and_applications_and_execution_requests_out_of_ignored();
  forced_assertion($$ != NULL);
}
;

ignored :

{
  b_trace_chars_array("ignored : NOTHING\n");
  $$ = NULL;
}
;

application :
  cli_application
{
  b_trace_chars_array("application : cli_application\n");
  $$ = $1;
}
;

cli_application :
  T_APPLICATION T_IDENTIFIER T_IS T_A T_COMMAND T_LINE T_INTERFACE
  T_APPLICATION T_AND T_THE T_ENTRY T_POINT T_IS T_FUNCTION T_IDENTIFIER T_END
  T_APPLICATION T_IDENTIFIER
{
    b_trace_chars_array("cli_application : T_APPLICATION T_IDENTIFIER T_IS T_A ");
    b_trace_chars_array("T_COMMAND T_LINE T_INTERFACE ");
    b_trace_chars_array("T_APPLICATION ");
    b_trace_chars_array("T_AND T_THE T_ENTRY T_POINT T_IS T_FUNCTION ");
    b_trace_chars_array("T_IDENTIFIER T_END T_APPLICATION T_IDENTIFIER\n");

  /*   Abort with error if application names do not match. */

  assertion_two($2 != NULL, "`$2` unexpectedly NULL");
  if ($2->type_ != STT_NODE_TYPE_IDENTIFIER) {

#ifdef DUMP_FLOW_TO_STDERR
    /*
    fprintf(stderr, "%s:%u - $2->type: %u\n", __FILE__, __LINE__, $2->type_);
    */
#endif
  }
  assertion($2->type_ == STT_NODE_TYPE_IDENTIFIER);
  assertion($2->identifier_subnode_ != NULL);
  assertion($18 != NULL);
  assertion($18->type_ == STT_NODE_TYPE_IDENTIFIER);
  assertion($18->identifier_subnode_ != NULL);
  if (!amara_string_equality(
      $2->identifier_subnode_->value_, $18->identifier_subnode_->value_)) {
    yyerror(NULL, "application names do not match");
    YYERROR;
  }

  assertion($15->type_ == STT_NODE_TYPE_IDENTIFIER);
  assertion($15->identifier_subnode_ != NULL);

  $$ = stt_node_default_constructor();
  $$->application_subnode_ = stt_application_subnode_default_constructor();
  $$->application_subnode_->name_ = $2->identifier_subnode_->value_;
  $$->application_subnode_->entry_point_function_name_ =
      $15->identifier_subnode_->value_;
  $$->application_subnode_->type_ =
      STT_APPLICATION_SUBNODE_TYPE_CLI_APPLICATION;
  $$->type_ = STT_NODE_TYPE_APPLICATION;

  free($2->identifier_subnode_);
  free($2);
  free($15->identifier_subnode_);
  free($15);
  free($18->identifier_subnode_->value_);
  free($18->identifier_subnode_);
  free($18);
}
;

named_function :
  cli_named_function
{
  b_trace_chars_array("fn_def : cli_fn_def\n");
  $$ = $1;
}
;

cli_named_function :
  T_FUNCTION T_IDENTIFIER T_IS T_A T_COMMAND T_LINE T_INTERFACE
  T_APPLICATION T_FUNCTION T_AND function_receives_clause T_AND
  function_returns_clause function_side_effects_clause T_AND T_DOES
  function_statements function_where_clauses T_END T_FUNCTION T_IDENTIFIER
{
  b_trace_chars_array("cli_fn_def : T_FUNCTION T_IDENTIFIER T_IS T_A ");
  b_trace_chars_array("T_COMMAND T_LINE T_INTERFACE T_APPLICATION ");
  b_trace_chars_array("T_FUNCTION T_AND function_receives_clause T_AND ");
  b_trace_chars_array("function_returns_clause function_side_effects_clause ");
  b_trace_chars_array("T_AND T_DOES function_statements ");
  b_trace_chars_array("function_where_clauses T_END T_FUNCTION ");
  b_trace_chars_array("T_IDENTIFIER\n");

  /*   Abort with error if function names do not match. */

  assertion($2 != NULL);
  if ($2->type_ != STT_NODE_TYPE_IDENTIFIER) {

#ifdef DUMP_FLOW_TO_STDERR
    /*
    fprintf(stderr, "%s:%u - $2->type_: %u\n", __FILE__, __LINE__, $2->type_);
    */
#endif
  }
  assertion($2->type_ == STT_NODE_TYPE_IDENTIFIER);
  assertion($2->identifier_subnode_ != NULL);
  assertion($21 != NULL);
  assertion($21->type_ == STT_NODE_TYPE_IDENTIFIER);
  assertion($21->identifier_subnode_ != NULL);
  if (!amara_string_equality(
      $2->identifier_subnode_->value_, $21->identifier_subnode_->value_)) {
    yyerror(NULL, "function names do not match");
    YYERROR;
  }

  /*   Set node type. */
  $$ = stt_node_default_constructor();

  /*   Attach the function operations to this node. */
  /*   Those are hanging from $17 */
  assertion_two($17 != NULL, "`$17` unexpectedly NULL");
  if ($17->type_ != STT_NODE_TYPE_CLI_OPERATIONS_LIST) {

#ifdef DUMP_FLOW_TO_STDERR
    /*
    fprintf(stderr, "$17->type_: %u\n", $17->type_);
    */
#endif
  }
  assertion_two($17->type_ == STT_NODE_TYPE_CLI_OPERATIONS_LIST,
      "unexpected value for `$17->type_`");
  assertion_two($17->operations_list_subnode_ != NULL,
      "`$17->operations_list_subnode_` unexpectedly NULL");
  assertion_two(
      $17->operations_list_subnode_->operations_ != NULL,
      "`$17->operations_list_subnode_->operations_` unexpectedly NULL");
  assertion_two(
      $17->operations_list_subnode_->operations_->first != NULL,
      "`$17->operations_list_subnode_->operations_->first` unexpectedly NULL");
  assertion_two(
      $17->operations_list_subnode_->operations_->first->type_ !=
          STT_OPERATION_TYPE_INVALID,
      "`$17->operations_list_subnode_->operations_->first->type_` is invalid");

  assertion($18 != NULL);
  assertion($18->type_ == STT_NODE_TYPE_WHERE_BINDINGS);
  assertion($18->where_value_bindings_subnode_ != NULL);
  assertion($18->where_value_bindings_subnode_->where_value_bindings_ != NULL);

  /*
  TODO CHARACTERIZE THE FUNCTION AS A CLI FUNCTION */
  $$->named_function_subnode_ =
      stt_named_function_subnode_default_constructor();
  $$->named_function_subnode_->name_ = $2->identifier_subnode_->value_;
  $$->named_function_subnode_->operations_ =
      $17->operations_list_subnode_->operations_;
  $$->named_function_subnode_->where_value_bindings_ =
      $18->where_value_bindings_subnode_->where_value_bindings_;
  $$->named_function_subnode_->type_ =
      STT_NAMED_FUNCTION_SUBNODE_TYPE_CLI_APP_NAMED_FUNCTION;

  $$->type_ = STT_NODE_TYPE_NAMED_FUNCTION;

  free($2->identifier_subnode_);
  free($2);
  free($17->operations_list_subnode_);
  free($17);
  free($18->where_value_bindings_subnode_);
  free($18);
  free($21->identifier_subnode_->value_);
  free($21->identifier_subnode_);
  free($21);
}
;

function_receives_clause :
  T_RECEIVES function_receives_clause_inner
{
  b_trace_chars_array("cli_fn_receives_def : T_RECEIVES cli_fn_receives_def_inner\n");
}
;

function_receives_clause_inner :
  T_NOTHING T_AT T_ALL
{
  b_trace_chars_array("cli_fn_receives_def_inner : T_NOTHING T_AT T_ALL\n");
}
;

function_returns_clause :
  T_RETURNS function_returns_clause_inner
{
  b_trace_chars_array("function_returns_clause : T_RETURNS ");
  b_trace_chars_array("function_returns_clause_inner\n");
}
;

function_returns_clause_inner :
  T_NOTHING T_AT T_ALL
{
  b_trace_chars_array("function_returns_clause_inner : T_NOTHING T_AT ");
  b_trace_chars_array("T_ALL\n");
}
;

function_side_effects_clause :
  T_SO T_IT T_CAUSES T_SIDE T_EFFECTS
{
  b_trace_chars_array("function_side_effects_clause : T_SO T_IT T_CAUSES ");
  b_trace_chars_array("T_SIDE T_EFFECTS\n");
}
;

function_where_clauses :
  T_WHERE function_where_clause function_where_clauses
{
  stt_where_value_bindings_simple_list * where_value_bindings_;
  stt_where_value_binding * where_value_binding_;

  b_trace_chars_array("function_where_clauses : T_WHERE ");
  b_trace_chars_array("function_where_clause ");
  b_trace_chars_array("function_where_clauses\n");

  assertion($2 != NULL);
  assertion($2->type_ == STT_NODE_TYPE_WHERE_BINDING);
  assertion($2->where_value_binding_subnode_ != NULL);
  assertion($2->where_value_binding_subnode_->where_value_binding_ != NULL);

  where_value_binding_ = stt_where_value_binding_copy_constructor(
      $2->where_value_binding_subnode_->where_value_binding_);
  $$ = stt_node_default_constructor();

  assertion($3 != NULL);
  assertion($3->type_ == STT_NODE_TYPE_WHERE_BINDINGS);
  assertion($3->where_value_bindings_subnode_ != NULL);
  assertion($3->where_value_bindings_subnode_->where_value_bindings_ != NULL);
  /*
  if ($3 == NULL) {
    where_value_bindings_ =
        stt_where_value_bindings_simple_list_default_constructor();
  } else {
  */
    assertion($3->type_ == STT_NODE_TYPE_WHERE_BINDINGS);
    assertion($3->where_value_bindings_subnode_ != NULL);
    assertion($3->where_value_bindings_subnode_->where_value_bindings_ !=
        NULL);
    where_value_bindings_ =
        stt_where_value_bindings_simple_list_copy_constructor(
            $3->where_value_bindings_subnode_->where_value_bindings_);
  /*
  }
  */
  where_value_bindings_ = stt_where_value_bindings_simple_list_push_front(
      where_value_bindings_, where_value_binding_);
  stt_node_set_where_value_bindings($$, where_value_bindings_);
  stt_node_destructor($2);
  stt_node_destructor($3);
}
|
{
  stt_where_value_bindings_simple_list * where_value_bindings_;

  b_trace_chars_array("cli_fn_where_clauses : NOTHING\n");

  where_value_bindings_ =
      stt_where_value_bindings_simple_list_default_constructor();
  assertion(where_value_bindings_ != NULL);
  assertion(where_value_bindings_->first == NULL);
  assertion(where_value_bindings_->next == NULL);

  $$ = stt_node_default_constructor();
  stt_node_set_where_value_bindings($$, where_value_bindings_);
}
;

function_where_clause :
  T_IDENTIFIER T_IS T_BOUND T_TO expression
{
  stt_where_value_binding * where_value_binding_;

  b_trace_chars_array("function_where_clause : T_IDENTIFIER T_IS T_BOUND T_TO ");
  b_trace_chars_array("expression\n");

  assertion_two($1 != NULL, "543");
  assertion_two($1->type_ == STT_NODE_TYPE_IDENTIFIER, "544");
  assertion_two($1->identifier_subnode_ != NULL, "545");
  assertion_two($1->identifier_subnode_->value_ != NULL, "546");
  assertion_two($1->identifier_subnode_->value_->value_ != NULL, "547");
  assertion_two($5 != NULL, "548");

  /*
  if ($5->type_ == STT_NODE_TYPE_EXPRESSION) {
  */

    assertion_two($5->type_ == STT_NODE_TYPE_EXPRESSION, "549");
    assertion_two($5->expression_subnode_ != NULL, "550");
    assertion_two($5->expression_subnode_->expression_ != NULL, "551");
  /*
  } else {
    forced_assertion_two($5->type_ == STT_NODE_TYPE_IDENTIFIER, "556");

    FIXME
  }
  */

  where_value_binding_ = stt_where_value_binding_exhaustive_constructor(
      $1->identifier_subnode_->value_, $5->expression_subnode_->expression_);
  $$ = stt_node_default_constructor();
  stt_node_set_where_value_binding($$, where_value_binding_);
  stt_node_destructor($1);
  stt_node_destructor($5);
}
;

execution_request :
  T_RUN T_COMMAND T_LINE T_INTERFACE T_APPLICATION T_IDENTIFIER
{
  b_trace_chars_array("exectn_req : T_RUN T_COMMAND T_LINE T_INTERFACE ");
  b_trace_chars_array("T_APPLICATION T_IDENTIFIER\n");
  assertion_two($6 != NULL, "$6 unexpectedly NULL");
  assertion_two($6->type_ == STT_NODE_TYPE_IDENTIFIER,
      "unexpected value of $6->type_");
  assertion_two($6->identifier_subnode_->value_ != NULL,
      "$6->identifier_subnode_->value_ unexpectedly NULL");
  $$ = stt_node_default_constructor();
  $$->type_ = STT_NODE_TYPE_EXECUTION_REQUEST;
  $$->execution_request_subnode_ =
      stt_execution_request_subnode_default_constructor();
  $$->execution_request_subnode_->type_ =
      STT_EXECUTION_REQUEST_SUBNODE_TYPE_RUN_CLI_APPLICATION;
  $$->execution_request_subnode_->application_name_ =
      $6->identifier_subnode_->value_;

  free($6->identifier_subnode_);
  free($6);

  /* stt_node_destructor($6); */

  /* free($6); */
}
;

function_statements :
  function_statement T_AND T_THEN function_statements
{
  stt_operations_simple_list * new_node_;
  b_trace_chars_array("cli_fn_ops : cli_fn_op T_AND T_THEN cli_fn_ops\n");
  assertion($1 != NULL);
  assertion($1->type_ == STT_NODE_TYPE_OPERATION);
  assertion($1->operation_subnode_ != NULL);
  assertion($1->operation_subnode_->operation_ != NULL);
  assertion($4 != NULL);
  assertion($4->type_ == STT_NODE_TYPE_CLI_OPERATIONS_LIST);
  assertion($4->operations_list_subnode_ != NULL);
  new_node_ = stt_operations_simple_list_default_constructor();
  new_node_->first = $1->operation_subnode_->operation_;
  new_node_->next = $4->operations_list_subnode_->operations_;
  $4->operations_list_subnode_->operations_ = new_node_;
  $$ = $4;
  free($1->operation_subnode_);
  free($1);
}
| function_statement
{
  b_trace_chars_array("cli_fn_ops : cli_fn_op\n");
  assertion($1 != NULL);
  assertion($1->type_ == STT_NODE_TYPE_OPERATION);
  assertion($1->operation_subnode_ != NULL);
  assertion($1->operation_subnode_->operation_ != NULL);
  $$ = stt_node_default_constructor();
  $$->operations_list_subnode_ =
      stt_operations_list_subnode_default_constructor();
  $$->operations_list_subnode_->operations_ =
      stt_operations_simple_list_default_constructor();
  $$->operations_list_subnode_->operations_->first =
      $1->operation_subnode_->operation_;
  $$->operations_list_subnode_->operations_->next = NULL;
  $$->type_ = STT_NODE_TYPE_CLI_OPERATIONS_LIST;
  free($1->operation_subnode_);
  free($1);
}
;

function_statement :
  T_PRINT expression
{
  b_trace_chars_array("function_statement : T_PRINT expression\n");
  $$ = function_statement_out_of_token_print_and_expression($2);
  forced_assertion($$ != NULL);
}
| T_NEW T_LINE
{
  b_trace_chars_array("function_statement : T_NEW T_LINE\n");
  $$ = function_statement_out_of_token_new_and_token_line();
  forced_assertion($$ != NULL);
}
| T_READ T_NATURAL T_IDENTIFIER
{
  b_trace_chars_array("cli_fn_op : T_READ T_NATURAL T_IDENTIFIER\n");
  assertion($3 != NULL);
  assertion($3->type_ == STT_NODE_TYPE_IDENTIFIER);
  $$ = stt_node_default_constructor();
  $$->operation_subnode_ = stt_operation_subnode_default_constructor();
  $$->operation_subnode_->operation_ = stt_operation_default_constructor();
  $$->operation_subnode_->operation_->args_ =
      stt_operation_args_simple_list_default_constructor();
  $$->operation_subnode_->operation_->args_->first =
      stt_operation_arg_default_constructor();
  $$->operation_subnode_->operation_->args_->first->node_ = $3;
  $$->operation_subnode_->operation_->args_->first->type_ = $3->type_;
  $$->operation_subnode_->operation_->type_ =
      STT_OPERATION_TYPE_READ_NATURAL_TO_VALUE;
  $$->type_ = STT_NODE_TYPE_OPERATION;
}
;

expression :
  T_IF condition T_THEN expression T_ELSE expression T_END T_IF
{
  stt_expression_sub_conditional * expression_sub_conditional_;
  stt_expression * expression_;

  b_trace_chars_array("expression : T_IF condition T_THEN expression T_ELSE ");
  b_trace_chars_array("expression T_END T_IF\n");

  assertion($2 != NULL);
  assertion($2->type_ == STT_NODE_TYPE_CONDITION);
  assertion($2->condition_subnode_ != NULL);
  assertion($2->condition_subnode_->condition_ != NULL);
  assertion($2->condition_subnode_->condition_->type_ !=
      STT_CONDITION_TYPE_INVALID);
  assertion($4 != NULL);
  if ($4->type_ != STT_NODE_TYPE_EXPRESSION) {

#ifdef DUMP_FLOW_TO_STDERR
    /*
    fprintf(stderr, "%u\n", $4->type_);
    */
#endif
  }
  assertion($4->type_ == STT_NODE_TYPE_EXPRESSION);
  assertion($4->expression_subnode_ != NULL);
  assertion($4->expression_subnode_->expression_ != NULL);
  assertion($4->expression_subnode_->expression_->type_ !=
      STT_EXPRESSION_TYPE_INVALID);
  assertion($6 != NULL);
  assertion($6->type_ == STT_NODE_TYPE_EXPRESSION);
  assertion($6->expression_subnode_ != NULL);
  assertion($6->expression_subnode_->expression_ != NULL);
  assertion($6->expression_subnode_->expression_->type_ !=
      STT_EXPRESSION_TYPE_INVALID);

  $$ = stt_node_default_constructor();
  assertion($$->type_ == STT_NODE_TYPE_INVALID);
  /* assert_all_subnodes_are_null($$); */

  expression_sub_conditional_ =
      stt_expression_sub_conditional_default_constructor();

  stt_expression_sub_conditional_set_condition(
      expression_sub_conditional_, $2->condition_subnode_->condition_);
  stt_expression_sub_conditional_set_expression_then(
      expression_sub_conditional_, $4->expression_subnode_->expression_);
  stt_expression_sub_conditional_set_expression_else(
      expression_sub_conditional_, $6->expression_subnode_->expression_);

  expression_ = stt_expression_default_constructor();
  stt_expression_set_conditional(expression_, expression_sub_conditional_);

  stt_node_set_expression($$, expression_);
}
| T_STRING_LITERAL
{
  stt_expression * expression_;
#ifndef NDEBUG
  amara_boolean equality_;
#endif

  b_trace_chars_array("expression : T_STRING_LITERAL\n");

#ifndef NDEBUG
  assertion($1 != NULL);
  assertion_two(
      $1->type_ == STT_NODE_TYPE_STRING_LITERAL,
      "unexpected node type at %s:%d\n");
  assertion($1->string_literal_subnode_ != NULL);
  assertion($1->string_literal_subnode_->string_literal_ != NULL);
  assertion($1->string_literal_subnode_->string_literal_->value_ != NULL);
  assert_clean_string_literal_node($1);
#endif

  $$ = stt_node_default_constructor();
#ifndef NDEBUG
  assertion($$ != NULL);
  assertion($$->type_ == STT_NODE_TYPE_INVALID);
#endif

  expression_ = stt_expression_default_constructor();
#ifndef NDEBUG
  assertion(expression_ != NULL);
  assertion(expression_->type_ == STT_EXPRESSION_TYPE_INVALID);
#endif

  stt_expression_set_string_literal(
      expression_, $1->string_literal_subnode_->string_literal_);
#ifndef NDEBUG
  assertion(expression_->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL);
  assertion(expression_->sub_string_literal_ != NULL);
  assertion(expression_->sub_string_literal_->string_literal_ != NULL);
  assertion(expression_->sub_string_literal_->string_literal_->value_ != NULL);
  assertion_two(
      $1->type_ == STT_NODE_TYPE_STRING_LITERAL, "unexpected node type...\n");
  assertion($1->string_literal_subnode_ != NULL);
  assertion($1->string_literal_subnode_->string_literal_ != NULL);
  assertion($1->string_literal_subnode_->string_literal_->value_ != NULL);
  equality_ = amara_string_equality(
      expression_->sub_string_literal_->string_literal_,
      $1->string_literal_subnode_->string_literal_);
  assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

  stt_node_set_expression($$, expression_);
#ifndef NDEBUG
  assertion($$->type_ == STT_NODE_TYPE_EXPRESSION);
  assertion($$->expression_subnode_ != NULL);
  assertion($$->expression_subnode_->expression_ != NULL);
  assertion(expression_->type_ == STT_EXPRESSION_TYPE_STRING_LITERAL);
  assertion(expression_->sub_string_literal_ != NULL);
  assertion(expression_->sub_string_literal_->string_literal_ != NULL);
  assertion(expression_->sub_string_literal_->string_literal_->value_ != NULL);
  equality_ = stt_expression_equality(
      $$->expression_subnode_->expression_, expression_);
  assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

  stt_expression_destructor(expression_);
  stt_node_destructor($1);
}
/*
| T_TYPE T_OF expression
{
  char * value_char_array_;
  stt_operation_arg * operation_arg_for_node_;
  b_trace_chars_array("string_value : T_TYPE T_OF numeric_value\n");
  if ($3->type_ == STT_NODE_TYPE_OPERATION) {
    assert_clean_operation_node($3);
    assertion($3->operation_subnode_ != NULL);
    assertion($3->operation_subnode_->operation_ != NULL);
    assertion($3->operation_subnode_->operation_->type_ !=
        STT_OPERATION_TYPE_INVALID);
    $$ = stt_node_default_constructor();
    $$->operation_subnode_ = stt_operation_subnode_default_constructor();
    $$->operation_subnode_->operation_ = stt_operation_default_constructor();
    $$->operation_subnode_->operation_->args_ =
        stt_operation_args_simple_list_default_constructor();
    operation_arg_for_node_ = stt_operation_arg_default_constructor();
    operation_arg_for_node_->node_ = $3;
    operation_arg_for_node_->type_ = STT_OPERATION_ARG_TYPE_VALID;
    $$->operation_subnode_->operation_->args_ =
        stt_operation_args_simple_list_push_front(
            $$->operation_subnode_->operation_->args_,
            operation_arg_for_node_);
    $$->operation_subnode_->operation_->type_ =
        STT_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION;
    $$->type_ = STT_NODE_TYPE_OPERATION;
  } else {
  assertion_two($3->type_ == STT_NODE_TYPE_NATURAL_LITERAL,
      "unexpected node type at %s:%d\n");
  assert_clean_natural_literal_node($3);
  value_char_array_ = malloc(strlen("natural") + 1);
  strcpy(value_char_array_, "natural");
  $$ = stt_node_default_constructor();
  $$->string_literal_subnode_ =
      stt_string_literal_subnode_default_constructor();
  $$->string_literal_subnode_->string_literal_ =
      amara_string_default_constructor();
  amara_string_set_value(
      $$->string_literal_subnode_->string_literal_, value_char_array_);
  $$->type_ = STT_NODE_TYPE_STRING_LITERAL;
*/
  /* amara_string_destructor($3->natural_subnode_->raw_); */
  /* stt_natural_subnode_destructor($3->natural_subnode_); */
/*
  stt_node_destructor($3);
  }
}
*/
| T_IDENTIFIER
{
  stt_expression * expression_;

  b_trace_chars_array("expression : T_IDENTIFIER\n");
  assertion_two($1->type_ == STT_NODE_TYPE_IDENTIFIER, "888");
  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */
  assert_clean_identifier_node($1);
  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */

  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */
  expression_ = stt_expression_default_constructor();
  forced_assertion_two(expression_ != NULL, "892");
  forced_assertion_two(expression_->type_ == STT_EXPRESSION_TYPE_INVALID,
                       "896");
  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */

  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */
  assertion_two($1->identifier_subnode_ != NULL, "894");
  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */
  assertion_two($1->identifier_subnode_->value_ != NULL, "895");
  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */
  stt_expression_set_identifier(expression_, $1->identifier_subnode_->value_);
  forced_assertion_two(expression_->type_ == STT_EXPRESSION_TYPE_IDENTIFIER,
                       "907");
  forced_assertion_two(expression_->sub_identifier_ != NULL,
                       "909");
  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */

  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */
  $$ = stt_node_default_constructor();
  forced_assertion_two($$ != NULL, "899");
  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */

  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */
  stt_node_set_expression($$, expression_);
  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */

  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */
  stt_expression_destructor(expression_);
  /*
  fprintf(stderr, "%s:%u\n", __FILE__, __LINE__);
  */
}
/*
| T_LEFT_PARENS expression T_RIGHT_PARENS
{
  b_trace_chars_array(
      "numeric_value : T_LEFT_PARENS numeric_value T_RIGHT_PARENS\n");
  if ($2->type_ == STT_NODE_TYPE_IDENTIFIER) {
    assert_clean_identifier_node($2);
  } else if ($2->type_ != STT_NODE_TYPE_OPERATION) {
  assertion($2->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
    assert_clean_natural_literal_node($2);
  } else {
    assertion($2->type_ == STT_NODE_TYPE_OPERATION);
    assert_clean_operation_node($2);
  }
  $$ = $2;
}
*/
| expression T_TIMES expression
{
  /*
  stt_expression * left_expression_;
  stt_expression * right_expression_;
  */

  b_trace_chars_array(
      "expression : expression T_TIMES expression\n");

  $$ = stt_nodes_multiplication($1, $3);

  stt_node_destructor($1);
  stt_node_destructor($3);

  /*
  fprintf(stderr, "%u\n", $1->type_);
  fprintf(stderr, "%u\n", $3->type_);
  if ($1->type_ == STT_NODE_TYPE_NATURAL_LITERAL &&
      $3->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
  */
  /* XXX here is asserted a natural literal, but it can be either:
         - natural literal
         - variable
         - operation (including variables and natural literals) */
  /*
  assertion($1->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
  assertion($3->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
  $$ = simplify_natural_literal_nodes_multiplication($1, $3);
  stt_node_destructor($1);
  stt_node_destructor($3);
  } else
  if ($1->type_ == STT_NODE_TYPE_OPERATION) {
  */
    /* assertion($1->type_ == STT_NODE_TYPE_IDENTIFIER); */ /* FIXME */
    /*
    $$ = stt_node_default_constructor();
    $$->operation_subnode_ = stt_operation_subnode_default_constructor();
    $$->operation_subnode_->operation_ = stt_operation_default_constructor();
    $$->operation_subnode_->operation_->args_ =
        stt_operation_args_simple_list_default_constructor();
    first_operation_arg_ = stt_operation_arg_default_constructor();
    first_operation_arg_->node_ = $1;
    first_operation_arg_->type_ = STT_OPERATION_ARG_TYPE_VALID; *//* XXX */
    /*
    second_operation_arg_ = stt_operation_arg_default_constructor();
    second_operation_arg_->node_ = $3;
    second_operation_arg_->type_ = STT_OPERATION_ARG_TYPE_VALID;
    $$->operation_subnode_->operation_->args_ =
        stt_operation_args_simple_list_push_front(
            $$->operation_subnode_->operation_->args_, second_operation_arg_);
    $$->operation_subnode_->operation_->args_ =
        stt_operation_args_simple_list_push_front(
            $$->operation_subnode_->operation_->args_, first_operation_arg_);
    $$->operation_subnode_->operation_->type_ =
        STT_OPERATION_TYPE_MULTIPLICATION;
    $$->type_ = STT_NODE_TYPE_OPERATION;
  }
  */
}
| expression T_DIVIDED T_BY expression
{
  /*
  stt_operation_arg * first_operation_arg_;
  stt_operation_arg * second_operation_arg_;
  */

  b_trace_chars_array(
      "expression : expression T_DIVIDED T_BY expression\n");

  $$ = stt_nodes_division($1, $4);

  stt_node_destructor($1);
  stt_node_destructor($4);

  /*
  fprintf(stderr, "%u\n", $1->type_);

  fprintf(stderr, "%u\n", $1->type_);
  fprintf(stderr, "%u\n", $4->type_);
  b_trace_chars_array(
      "numeric_value : numeric_value T_DIVIDED_BY numeric_value\n");
  if ($1->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
  assertion_two($1->type_ == STT_NODE_TYPE_NATURAL_LITERAL,
      "unexpected node type at %s:%d\n");
  assertion_two($4->type_ == STT_NODE_TYPE_NATURAL_LITERAL,
      "unexpected node type at %s:%d\n");
  $$ = simplify_natural_literal_nodes_division($1, $4);
  stt_node_destructor($1);
  stt_node_destructor($4);
  } else {
    assertion($1->type_ == STT_NODE_TYPE_OPERATION); *//* XXX but it can actually be an identifier legally */
    /*
    assertion($1->operation_subnode_ != NULL);
    assertion($1->operation_subnode_->operation_ != NULL);
    assertion($1->operation_subnode_->operation_->type_ !=
        STT_OPERATION_TYPE_INVALID);
    if ($1->operation_subnode_->operation_->type_ ==
        STT_OPERATION_TYPE_MULTIPLICATION) {
      assertion($1->operation_subnode_->operation_->args_ != NULL);
      assertion($1->operation_subnode_->operation_->args_->first != NULL);
      assertion($1->operation_subnode_->operation_->args_->next != NULL);
      assertion($1->operation_subnode_->operation_->args_->next->first !=
          NULL);
    } else {
      fprintf(stderr, "%u\n", $1->operation_subnode_->operation_->type_);
      assertion(0); *//* XXX */
    /*
    }
    assertion($4->type_ == STT_NODE_TYPE_NATURAL_LITERAL); *//* XXX but this is not quite true, just adding this temporarily. */
    /*
    $$ = stt_node_default_constructor();
    $$->operation_subnode_ = stt_operation_subnode_default_constructor();
    $$->operation_subnode_->operation_ = stt_operation_default_constructor();
    $$->operation_subnode_->operation_->args_ =
        stt_operation_args_simple_list_default_constructor();
    first_operation_arg_ = stt_operation_arg_default_constructor();
    first_operation_arg_->node_ = $1;
    first_operation_arg_->type_ = STT_OPERATION_ARG_TYPE_VALID; *//* XXX */
    /*
    second_operation_arg_ = stt_operation_arg_default_constructor();
    second_operation_arg_->node_ = $4;
    second_operation_arg_->type_ = STT_OPERATION_ARG_TYPE_VALID;
    $$->operation_subnode_->operation_->args_ =
        stt_operation_args_simple_list_push_front(
            $$->operation_subnode_->operation_->args_, second_operation_arg_);
    $$->operation_subnode_->operation_->args_ =
        stt_operation_args_simple_list_push_front(
            $$->operation_subnode_->operation_->args_, first_operation_arg_);
    $$->operation_subnode_->operation_->type_ =
        STT_OPERATION_TYPE_DIVISION;
    $$->type_ = STT_NODE_TYPE_OPERATION;
  }
  */
}
| expression T_MINUS expression
{
  /*
  stt_operation_arg * first_operation_arg_;
  stt_operation_arg * second_operation_arg_;
  */

  b_trace_chars_array(
      "expression : expression T_MINUS expression\n");

  $$ = stt_nodes_substraction($1, $3);

  stt_node_destructor($1);
  stt_node_destructor($3);

  /*
  if ($1->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
  assertion_two($3->type_ == STT_NODE_TYPE_NATURAL_LITERAL,
      "unexpected node type at %s:%d\n");
  $$ = simplify_natural_literal_nodes_substraction($1, $3); *//* TODO must reword this `numeric` to `numeric literal` or something. */
  /* amara_string_destructor($1->natural_subnode_->raw_);
  stt_natural_subnode_destructor($1->natural_subnode_); */
  /*
  stt_node_destructor($1);
  */
  /* amara_string_destructor($3->natural_subnode_->raw_);
  stt_natural_subnode_destructor($3->natural_subnode_); */
  /*
  stt_node_destructor($3);
  } else {
    assertion($1->type_ == STT_NODE_TYPE_IDENTIFIER);
    $$ = stt_node_default_constructor();
    $$->operation_subnode_ = stt_operation_subnode_default_constructor();
    $$->operation_subnode_->operation_ = stt_operation_default_constructor();
    $$->operation_subnode_->operation_->args_ =
        stt_operation_args_simple_list_default_constructor();
    first_operation_arg_ = stt_operation_arg_default_constructor();
    first_operation_arg_->node_ = $1;
    first_operation_arg_->type_ = STT_OPERATION_ARG_TYPE_VALID; *//* XXX */
  /*
    second_operation_arg_ = stt_operation_arg_default_constructor();
    second_operation_arg_->node_ = $3;
    second_operation_arg_->type_ = STT_OPERATION_ARG_TYPE_VALID;
    $$->operation_subnode_->operation_->args_ =
        stt_operation_args_simple_list_push_front(
            $$->operation_subnode_->operation_->args_, second_operation_arg_);
    $$->operation_subnode_->operation_->args_ =
        stt_operation_args_simple_list_push_front(
            $$->operation_subnode_->operation_->args_, first_operation_arg_);
    $$->operation_subnode_->operation_->type_ =
        STT_OPERATION_TYPE_SUBSTRACTION;
    $$->type_ = STT_NODE_TYPE_OPERATION;
  }
  */
}
| T_DICE_EXPRESSION
{
  b_trace_chars_array("expression : T_DICE_EXPRESSION\n");

  assertion($1 != NULL);
  assertion($1->type_ == STT_NODE_TYPE_EXPRESSION);
  assertion($1->expression_subnode_ != NULL);
  assertion($1->expression_subnode_->expression_ != NULL);
  assertion($1->expression_subnode_->expression_->type_ ==
      STT_EXPRESSION_TYPE_DICE);

  $$ = $1;
}
| T_NATURAL_LITERAL
{
  natural * natural_;
  stt_expression * expression_;

  b_trace_chars_array("number_literal : T_NATURAL_LITERAL\n");
  assertion_two($1->type_ == STT_NODE_TYPE_NATURAL_LITERAL,
      "unexpected node type at %s:%d\n");
  assert_clean_natural_literal_node($1);
  b_trace_chars_array("number_literal (");
  b_trace_chars_array($$->natural_literal_subnode_->raw_->value_);
  b_trace_chars_array(") : T_NATURAL_LITERAL (");
  b_trace_chars_array($1->natural_literal_subnode_->raw_->value_);
  b_trace_chars_array(")\n");

  natural_ = natural_exhaustive_constructor(
      $1->natural_literal_subnode_->raw_);
  expression_ = stt_expression_default_constructor();
  stt_expression_set_natural_literal(expression_, natural_);
  $$ = stt_node_default_constructor();
  stt_node_set_expression($$, expression_);
#ifndef NDEBUG
  assertion($$ != NULL);
  assertion($$->type_ == STT_NODE_TYPE_EXPRESSION);
  assertion($$->expression_subnode_ != NULL);
  assertion($$->expression_subnode_->expression_ != NULL);
  assertion($$->expression_subnode_->expression_->type_ ==
      STT_EXPRESSION_TYPE_NATURAL_LITERAL);
  assertion($$->expression_subnode_->expression_->sub_natural_literal_ != NULL);
  assertion($$->expression_subnode_->expression_->sub_natural_literal_->natural_literal_ != NULL);
  assertion($$->expression_subnode_->expression_->sub_natural_literal_->natural_literal_->raw_ != NULL);
  assertion($$->expression_subnode_->expression_->sub_natural_literal_->natural_literal_->raw_->value_ != NULL);
#endif

  natural_destructor(natural_);
  stt_expression_destructor(expression_);
  stt_node_destructor($1);
#ifndef NDEBUG
  assertion($$ != NULL);
  assertion($$->type_ == STT_NODE_TYPE_EXPRESSION);
  assertion($$->expression_subnode_ != NULL);
  assertion($$->expression_subnode_->expression_ != NULL);
  assertion($$->expression_subnode_->expression_->type_ ==
      STT_EXPRESSION_TYPE_NATURAL_LITERAL);
  assertion($$->expression_subnode_->expression_->sub_natural_literal_ != NULL);
  assertion($$->expression_subnode_->expression_->sub_natural_literal_->natural_literal_ != NULL);
  assertion($$->expression_subnode_->expression_->sub_natural_literal_->natural_literal_->raw_ != NULL);
  assertion($$->expression_subnode_->expression_->sub_natural_literal_->natural_literal_->raw_->value_ != NULL);
#endif
}
| T_INTEGER_LITERAL
{
  b_trace_chars_array("number_literal : T_INTEGER_LITERAL\n");
  assertion_two($1->type_ == STT_NODE_TYPE_INTEGER_LITERAL /* XXX */,
      "unexpected node type at %s:%d\n");
  $$ = $1;
}
| T_RATIONAL_LITERAL
{
  b_trace_chars_array("number_literal : T_RATIONAL_LITERAL\n");
  assertion_two($1->type_ == STT_NODE_TYPE_RATIONAL_LITERAL /* XXX */,
      "unexpected node type at %s:%d\n");
  $$ = $1;
}
;

condition :
  expression T_IS T_LESS T_THAN expression
{
  natural * left_hand_expression_natural_;
  stt_expression * left_hand_expression_;
  natural * right_hand_expression_natural_;
  stt_expression * right_hand_expression_;
  stt_condition * condition_;

  b_trace_chars_array("condition : expression T_IS T_LESS T_THAN expression\n");

  assertion($1 != NULL);
  if ($1->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
    assertion($1->natural_literal_subnode_ != NULL);
    assertion($1->natural_literal_subnode_->raw_ != NULL);
    assertion($1->natural_literal_subnode_->raw_->value_ != NULL);
    assert_valid_raw_natural($1->natural_literal_subnode_->raw_);
  } else if ($1->type_ == STT_NODE_TYPE_IDENTIFIER) {
    assertion($1->identifier_subnode_ != NULL);
    assertion($1->identifier_subnode_->value_ != NULL);
  } else {
    if ($1->type_ != STT_NODE_TYPE_EXPRESSION) {

#ifdef DUMP_FLOW_TO_STDERR
      fprintf(stderr, "%u\n", $1->type_);
#endif
    }
    assertion($1->type_ == STT_NODE_TYPE_EXPRESSION);
    assertion($1->expression_subnode_ != NULL);
    assertion($1->expression_subnode_->expression_ != NULL);
  }

  assertion($5 != NULL);
  if ($5->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
    assertion($5->natural_literal_subnode_ != NULL);
    assertion($5->natural_literal_subnode_->raw_ != NULL);
    assertion($5->natural_literal_subnode_->raw_->value_ != NULL);
    assert_valid_raw_natural($5->natural_literal_subnode_->raw_);
  } else if ($5->type_ == STT_NODE_TYPE_IDENTIFIER) {
    assertion($5->identifier_subnode_ != NULL);
    assertion($5->identifier_subnode_->value_ != NULL);
  } else {
    if ($5->type_ != STT_NODE_TYPE_EXPRESSION) {

#ifdef DUMP_FLOW_TO_STDERR
      fprintf(stderr, "%u\n", $5->type_);
#endif
    }
    assertion($5->type_ == STT_NODE_TYPE_EXPRESSION);
    assertion($5->expression_subnode_ != NULL);
    assertion($5->expression_subnode_->expression_ != NULL);
  }

  left_hand_expression_ = NULL;
  if ($1->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
    left_hand_expression_ = stt_expression_default_constructor();
    left_hand_expression_natural_ =
        natural_exhaustive_constructor($1->natural_literal_subnode_->raw_);
    stt_expression_set_natural_literal(
        left_hand_expression_, left_hand_expression_natural_);
  } else if ($1->type_ == STT_NODE_TYPE_IDENTIFIER) {
    left_hand_expression_ = stt_expression_default_constructor();
    stt_expression_set_identifier(
        left_hand_expression_, $1->identifier_subnode_->value_);
  } else {
    assertion($1->type_ == STT_NODE_TYPE_EXPRESSION);
    left_hand_expression_ = stt_expression_copy_constructor(
        $1->expression_subnode_->expression_);
  }

  right_hand_expression_ = NULL;
  if ($5->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
    right_hand_expression_ = stt_expression_default_constructor();
    right_hand_expression_natural_ =
        natural_exhaustive_constructor($5->natural_literal_subnode_->raw_);
    stt_expression_set_natural_literal(
        right_hand_expression_, right_hand_expression_natural_);
  } else {
    assertion($5->type_ == STT_NODE_TYPE_EXPRESSION);
    right_hand_expression_ = stt_expression_copy_constructor(
        $5->expression_subnode_->expression_);
  }

  condition_ = stt_condition_default_constructor();
  stt_condition_initialize_less_than(
      condition_, left_hand_expression_, right_hand_expression_);

  $$ = stt_node_default_constructor();
  stt_node_set_condition($$, condition_);

  stt_node_destructor($1);
  stt_node_destructor($5);
}
| expression T_IS T_GREATER T_THAN expression
{
  natural * left_hand_expression_natural_;
  stt_expression * left_hand_expression_;
  natural * right_hand_expression_natural_;
  stt_expression * right_hand_expression_;
  stt_condition * condition_;

  b_trace_chars_array("condition : expression T_IS T_GREATER T_THAN expression\n");

  assertion($1 != NULL);
  if ($1->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
    assertion($1->natural_literal_subnode_ != NULL);
    assertion($1->natural_literal_subnode_->raw_ != NULL);
    assertion($1->natural_literal_subnode_->raw_->value_ != NULL);
    assert_valid_raw_natural($1->natural_literal_subnode_->raw_);
  } else if ($1->type_ == STT_NODE_TYPE_IDENTIFIER) {
    assertion($1->identifier_subnode_ != NULL);
    assertion($1->identifier_subnode_->value_ != NULL);
  } else {
    if ($1->type_ != STT_NODE_TYPE_EXPRESSION) {

#ifdef DUMP_FLOW_TO_STDERR
      fprintf(stderr, "%u\n", $1->type_);
#endif
    }
    assertion($1->type_ == STT_NODE_TYPE_EXPRESSION);
    assertion($1->expression_subnode_ != NULL);
    assertion($1->expression_subnode_->expression_ != NULL);
  }

  assertion($5 != NULL);
  if ($5->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
    assertion($5->natural_literal_subnode_ != NULL);
    assertion($5->natural_literal_subnode_->raw_ != NULL);
    assertion($5->natural_literal_subnode_->raw_->value_ != NULL);
    assert_valid_raw_natural($5->natural_literal_subnode_->raw_);
  } else if ($5->type_ == STT_NODE_TYPE_IDENTIFIER) {
    assertion($5->identifier_subnode_ != NULL);
    assertion($5->identifier_subnode_->value_ != NULL);
  } else {
    if ($5->type_ != STT_NODE_TYPE_EXPRESSION) {

#ifdef DUMP_FLOW_TO_STDERR
      fprintf(stderr, "%u\n", $5->type_);
#endif
    }
    assertion($5->type_ == STT_NODE_TYPE_EXPRESSION);
    assertion($5->expression_subnode_ != NULL);
    assertion($5->expression_subnode_->expression_ != NULL);
  }

  left_hand_expression_ = NULL;
  if ($1->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
    left_hand_expression_ = stt_expression_default_constructor();
    left_hand_expression_natural_ =
        natural_exhaustive_constructor($1->natural_literal_subnode_->raw_);
    stt_expression_set_natural_literal(
        left_hand_expression_, left_hand_expression_natural_);
  } else if ($1->type_ == STT_NODE_TYPE_IDENTIFIER) {
    left_hand_expression_ = stt_expression_default_constructor();
    stt_expression_set_identifier(
        left_hand_expression_, $1->identifier_subnode_->value_);
  } else {
    assertion($1->type_ == STT_NODE_TYPE_EXPRESSION);
    left_hand_expression_ = stt_expression_copy_constructor(
        $1->expression_subnode_->expression_);
  }

  right_hand_expression_ = NULL;
  if ($5->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
    right_hand_expression_ = stt_expression_default_constructor();
    right_hand_expression_natural_ =
        natural_exhaustive_constructor($5->natural_literal_subnode_->raw_);
    stt_expression_set_natural_literal(
        right_hand_expression_, right_hand_expression_natural_);
  } else {
    assertion($5->type_ == STT_NODE_TYPE_EXPRESSION);
    right_hand_expression_ = stt_expression_copy_constructor(
        $5->expression_subnode_->expression_);
  }

  condition_ = stt_condition_default_constructor();
  stt_condition_initialize_greater_than(
      condition_, left_hand_expression_, right_hand_expression_);

  $$ = stt_node_default_constructor();
  stt_node_set_condition($$, condition_);

  stt_node_destructor($1);
  stt_node_destructor($5);
}
;

%%

#ifdef NO_LOOPED_MINIAPARSE
#undef NO_LOOPED_MINIAPARSE
#endif
/* #define NO_LOOPED_MINIAPARSE */

stt_node *
minia_bison_main(FILE * file)
{
  const int miniaparse_ret_success_ = 0;
  const int miniaparse_ret_failed_because_of_invalid_input_ = 1;
  const int miniaparse_ret_failed_due_to_memory_exhaustion_ = 2;
  int miniaparse_ret_;
  stt_node * shared_with_miniaparse_;
  stt_node * returning_; /* XXX */
  miniain = file;
  shared_with_miniaparse_ = stt_node_default_constructor();

#ifdef NO_LOOPED_YYPARSE
  miniaparse_ret_ = miniaparse(shared_with_miniaparse_);
#else
        do {
    miniaparse_ret_ = miniaparse(shared_with_miniaparse_);
        } while (!feof(miniain));
#endif

  if (miniaparse_ret_ == miniaparse_ret_success_) {
    if (shared_with_miniaparse_->type_ != STT_NODE_TYPE_DOC) {

#ifdef DUMP_FLOW_TO_STDERR
      fprintf(stderr, "shared_with_miniaparse_->type_: %u\n",
          shared_with_miniaparse_->type_);
#endif
    }
    returning_ = stt_node_default_constructor();  /* XXX */
    returning_->type_ = shared_with_miniaparse_->type_; /* XXX */
    /*
    if (shared_with_miniaparse_->type_ == STT_NODE_TYPE_DOC) {
    */
    assertion_two(
        shared_with_miniaparse_->type_ == STT_NODE_TYPE_DOC,
        "unexpected type of `shared_with_miniaparse_->type_`");
    assertion_two(shared_with_miniaparse_->doc_subnode_ != NULL,
        "`shared_with_miniaparse_->doc_subnode_` unexpectedly set `NULL`");
    returning_->doc_subnode_ = shared_with_miniaparse_->doc_subnode_; /* XXX */
    /*
    }
    */
    free(shared_with_miniaparse_); /* XXX */
    return returning_; /* XXX */
  } else if (miniaparse_ret_ ==
      miniaparse_ret_failed_because_of_invalid_input_) {
    /* XXX */
    return NULL; /* XXX */
  } else {
    assertion(miniaparse_ret_ ==
        miniaparse_ret_failed_due_to_memory_exhaustion_);
    /* XXX */
    return NULL; /* XXX */
  }
}

void
yyerror(stt_node * syntax_tree, const char * msg)
{
        fprintf(stderr, "parse error: %s\n", msg);
  if (syntax_tree == NULL) {
    fprintf(stderr, "`syntax_tree`: NULL\n");
  }
        exit(1);
}

/*
void amara_destroy_flex_buffer();
*/

/*
int
miniawrap()
{
*/
  /* reset lines counter to zero? */

  /*   Mainly because of a need of the non-reentrant C scanner. See:
   * http://westes.github.io/flex/manual/Memory-leak-_002d-16386-bytes-allocated-by-malloc_002e.html#Memory-leak-_002d-16386-bytes-allocated-by-malloc_002e
   */
  /*   FIXME Maybe this has to be run once before exiting. */
  /*
  amara_destroy_flex_buffer();
  */

/*
  return 1;
}
*/
