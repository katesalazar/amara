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

/*   For `uint_fast8_t`. */
#include <stdint.h>

/*   For the `FILE` struct. */
#include <stdio.h>

/*   For `void exit(int status)`. */
#include <stdlib.h>

/*   For `size_t strlen(const char * s)`. */
#include <string.h>

/*   For `void assertion_two_located_interim(int expression,
 * const char * message, const char * source_doc,
 * unsigned int source_line)`. */
#include "../asr/assertion.h"

/*   For most basic arithmetic. */
#include "../brt/natural.h"

/*   For the syntax tree nodes and node types. */
#include "../stt/stt_node.h"

extern int yylex();

extern int yyparse();

extern FILE * miniain;

void yyerror(stt_node * syntax_tree, const char * s);

#ifdef TRACE_BISON
#define TRACE_BISON_CONSTANT_VALUE 0xFF
#else
#define TRACE_BISON_CONSTANT_VALUE 0x00
#endif

const uint_fast8_t bison_trace_constant = TRACE_BISON_CONSTANT_VALUE;

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
bison_trace_uint_fast8_t(uint_fast8_t value)
{
  if (bison_trace_constant) {
    fprintf(stderr, "%u", value);
  }
}

void
b_trace_uintfast8t(uint_fast8_t value)
{
  bison_trace_uint_fast8_t(value);
}

%}

%union {
  stt_node * node;
}

%token<node> T_NATURAL
%token<node> T_INTEGER
%token<node> T_RATIONAL

%token T_A T_ALL T_AN T_AND T_APPLICATION T_ARGS T_AT T_AWESOME T_CARRIAGE
%token T_CAUSES T_CHAIN T_COMMAND T_COMMANDS T_DIVISION
%token T_DOES T_EASE T_EFFECTS
%token T_ENTRY T_FEED T_FUNCTION T_INTERFACE T_IS T_IT T_LINE T_NO
%token T_NOR
%token T_NOTHING T_OF T_OPERATOR T_POINT T_PRINT T_RECEIVES
%token T_RETURN T_RETURNS T_RUN T_SIDE T_SMALL T_SO T_SUBSTRACTION T_THAT T_THE
%token T_TYPE
%token T_WITH T_WITHOUT

%token<node> T_STRING_LITERAL

%token<node> T_IDENTIFIER

%right T_MINUS
%right T_DIVIDED_BY

%type<node> string_lvalue
%type<node> numeric_lvalue
%type<node> number_literal
%type<node> printable
%type<node> lvalue
%type<node> cli_fn_op
%type<node> cli_fn_ops
%type<node> cli_fn_def
%type<node> fn_def
%type<node> cli_app_def
%type<node> app_def
%type<node> exectn_req
%type<node> fns_and_apps_defs_and_exectn_reqs
%type<node> doc

%start doc

%%

/*   A doc is a collection of functions, applications, and execution
 * requests. */
doc :
  fns_and_apps_defs_and_exectn_reqs
{
  b_trace_chars_array("doc : fns_and_apps_defs_and_exectn_reqs\n");
  assertion_two($1 != NULL, "`fns_and_apps_defs_and_exectn_reqs` unexpectedly NULL");
  assertion_two($1->type_ == SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT,
      "unexpected type of `fns_and_apps_defs_and_exectn_reqs`");
  assertion_two($1->doc_subnode_ != NULL,
      "`fns_and_apps_defs_and_exectn_reqs->doc` unexpectedly NULL");
  syntax_tree->type_ = SYNTAX_TREE_NODE_TYPE_DOC;
  syntax_tree->doc_subnode_ = $1->doc_subnode_;
  free($1);
}
;

fns_and_apps_defs_and_exectn_reqs :
  fn_def fns_and_apps_defs_and_exectn_reqs
{
  b_trace_chars_array(
      "fns_and_apps_defs_and_exectn_reqs : fn_def fns_and_apps_defs_and_exectn_reqs\n");
  if ($2 == NULL) {
    $$ = stt_node_default_constructor();
    $$->type_ = SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT;
    $$->doc_subnode_ = stt_doc_subnode_default_constructor();
    $$ = register_function($$, $1);
    assertion($$->doc_subnode_ != NULL);
    free($1->function_subnode_);
    free($1);
  } else {
    assertion_two($2->type_ = SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT,
        "unexpected type of `fns_and_apps_defs_and_exectn_reqs`");
    assertion($2->doc_subnode_ != NULL);
    $$ = register_function($2, $1);
    assertion($$->doc_subnode_ != NULL);
    free($1->function_subnode_);
    free($1);
  }
}
| app_def fns_and_apps_defs_and_exectn_reqs
{
  b_trace_chars_array(
      "fns_and_apps_defs_and_exectn_reqs : app_def fns_and_apps_defs_and_exectn_reqs\n");
  if ($2 == NULL) {
    $$ = stt_node_default_constructor();
    $$->type_ = SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT;
    $$->doc_subnode_ = stt_doc_subnode_default_constructor();
    $$ = register_application($$, $1);
    assertion($$->doc_subnode_ != NULL);
    free($1->application_subnode_);
    free($1);
  } else {
    assertion_two($2->type_ = SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT,
        "unexpected type of `fns_and_apps_defs_and_exectn_reqs`");
    assertion($2->doc_subnode_ != NULL);
    $$ = register_application($2, $1);
    assertion($$->doc_subnode_ != NULL);
    free($1->application_subnode_);
    free($1);
  }
}
| exectn_req fns_and_apps_defs_and_exectn_reqs
{
  b_trace_chars_array(
      "fns_and_apps_defs_and_exectn_reqs : exectn fns_and_apps_defs_and_exectn_reqs\n");
  if ($2 == NULL) {
    $$ = stt_node_default_constructor();
    $$->type_ = SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT;
    $$->doc_subnode_ = stt_doc_subnode_default_constructor();
    $$ = register_execution_request($$, $1);
    assertion($$->doc_subnode_ != NULL);
    free($1->execution_request_subnode_);
    free($1);
  } else {
    assertion_two($2->type_ = SYNTAX_TREE_NODE_TYPE_DOC_FRAGMENT,
        "unexpected type of `fns_and_apps_defs_and_exectn_reqs`");
    assertion($2->doc_subnode_ != NULL);
    $$ = register_execution_request($2, $1);
    assertion($$->doc_subnode_ != NULL);
    free($1->execution_request_subnode_);
    free($1);
  }
}
|
{
  b_trace_chars_array("fns_and_apps_defs_and_exectn_reqs : \n");
  $$ = NULL;
}
;

app_def :
  cli_app_def
{
  b_trace_chars_array("app : cli_app\n");
  $$ = $1;
}
;

cli_app_def :
  T_APPLICATION T_IDENTIFIER T_IS T_AN T_AWESOME T_COMMAND T_LINE T_INTERFACE
  T_APPLICATION T_AND T_THE T_ENTRY T_POINT T_IS T_FUNCTION T_IDENTIFIER T_AND
    T_THAT T_IS T_APPLICATION T_IDENTIFIER
{
    b_trace_chars_array("cli_app_def : T_APPLICATION T_IDENTIFIER T_IS T_AN ");
    b_trace_chars_array("T_AWESOME T_COMMAND T_LINE T_INTERFACE ");
    b_trace_chars_array("T_APPLICATION ");
    b_trace_chars_array("T_AND T_THE T_ENTRY T_POINT T_IS T_FUNCTION ");
    b_trace_chars_array("T_IDENTIFIER T_AND ");
    b_trace_chars_array("T_THAT T_IS T_APPLICATION T_IDENTIFIER\n");

  /*   Abort with error if application names do not match. */

  assertion_two($2 != NULL, "`$2` unexpectedly NULL");
  if ($2->type_ != SYNTAX_TREE_NODE_TYPE_IDENTIFIER) {
    fprintf(stderr, "%s:%u - $2->type: %u\n", __FILE__, __LINE__, $2->type_);
  }
  assertion($2->type_ == SYNTAX_TREE_NODE_TYPE_IDENTIFIER);
  assertion($2->identifier_subnode_ != NULL);
  assertion($21 != NULL);
  assertion($21->type_ == SYNTAX_TREE_NODE_TYPE_IDENTIFIER);
  assertion($21->identifier_subnode_ != NULL);
  if (!amara_string_equality(
      $2->identifier_subnode_->value_, $21->identifier_subnode_->value_)) {
    yyerror(NULL, "application names do not match");
    YYERROR;
  }

  assertion($16->type_ == SYNTAX_TREE_NODE_TYPE_IDENTIFIER);
  assertion($16->identifier_subnode_ != NULL);

  $$ = stt_node_default_constructor();
  $$->application_subnode_ = stt_application_subnode_default_constructor();
  $$->application_subnode_->name_ = $2->identifier_subnode_->value_;
  $$->application_subnode_->entry_point_function_name_ =
      $16->identifier_subnode_->value_;
  $$->application_subnode_->type_ =
      STT_APPLICATION_SUBNODE_TYPE_CLI_APPLICATION;
  $$->type_ = SYNTAX_TREE_NODE_TYPE_APPLICATION;

  free($2->identifier_subnode_);
  free($2);
  free($16->identifier_subnode_);
  free($16);
  free($21->identifier_subnode_->value_);
  free($21->identifier_subnode_);
  free($21);
}
;

fn_def :
  cli_fn_def
{
  b_trace_chars_array("fn_def : cli_fn_def\n");
  $$ = $1;
}
;

cli_fn_def :
  T_FUNCTION T_IDENTIFIER T_IS T_AN T_AWESOME T_COMMAND T_LINE T_INTERFACE
  T_APPLICATION T_FUNCTION T_AND T_RECEIVES T_NOTHING T_AT T_ALL T_AND
  T_RETURNS
    T_NOTHING T_AT T_ALL T_SO T_IT T_CAUSES T_SIDE T_EFFECTS T_AND T_DOES
    cli_fn_ops cli_fn_def_with_clause T_AND T_THAT T_IS T_FUNCTION
    T_IDENTIFIER
{
  b_trace_chars_array("cli_fn_def : T_FUNCTION T_IDENTIFIER T_RECEIVES ");
  b_trace_chars_array("T_NOTHING ");
  b_trace_chars_array("T_AT T_ALL T_AND T_RETURNS T_NOTHING T_AT T_ALL T_SO ");
  b_trace_chars_array("T_IT ");
  b_trace_chars_array("T_CAUSES T_SIDE T_EFFECTS T_AND T_DOES cli_fn_ops ");
  b_trace_chars_array("cli_fn_def_with_clause T_AND T_THAT T_IS T_FUNCTION ");
  b_trace_chars_array("T_IDENTIFIER\n");

  /*   Abort with error if function names do not match. */

  assertion($2 != NULL);
  if ($2->type_ != SYNTAX_TREE_NODE_TYPE_IDENTIFIER) {
    fprintf(stderr, "%s:%u - $2->type_: %u\n", __FILE__, __LINE__, $2->type_);
  }
  assertion($2->type_ == SYNTAX_TREE_NODE_TYPE_IDENTIFIER);
  assertion($2->identifier_subnode_ != NULL);
  assertion($34 != NULL);
  assertion($34->type_ == SYNTAX_TREE_NODE_TYPE_IDENTIFIER);
  assertion($34->identifier_subnode_ != NULL);
  if (!amara_string_equality(
      $2->identifier_subnode_->value_, $34->identifier_subnode_->value_)) {
    yyerror(NULL, "function names do not match");
    YYERROR;
  }

  /*   Set node type. */
  $$ = stt_node_default_constructor();

  /*   Attach the function operations to this node. */
  /*   Those are hanging from $28 */
  assertion_two($28 != NULL, "`$28` unexpectedly NULL");
  if ($28->type_ != SYNTAX_TREE_NODE_TYPE_CLI_OPERATIONS_LIST) {
    fprintf(stderr, "$28->type_: %u\n", $28->type_);
  }
  assertion_two($28->type_ == SYNTAX_TREE_NODE_TYPE_CLI_OPERATIONS_LIST,
      "unexpected value for `$28->type_`");
  assertion_two_located_interim($28->operations_list_subnode_ != NULL,
      "`$28->operations_list_subnode_` unexpectedly NULL", __FILE__, __LINE__);
  assertion_two_located_interim(
      $28->operations_list_subnode_->operations_ != NULL,
      "`$28->operations_list_subnode_->operations_` unexpectedly NULL",
      __FILE__, __LINE__);
  assertion_two_located_interim(
      $28->operations_list_subnode_->operations_->first != NULL,
      "`$28->operations_list_subnode_->operations_->first` unexpectedly NULL",
      __FILE__, __LINE__);
  assertion_two_located_interim(
      $28->operations_list_subnode_->operations_->first->type_ !=
          STT_OPERATION_TYPE_INVALID,
      "`$28->operations_list_subnode_->operations_->first->type_` is invalid",
      __FILE__, __LINE__);

  /*
  TODO CHARACTERIZE THE FUNCTION AS A CLI FUNCTION */
  $$->function_subnode_ = stt_function_subnode_default_constructor();
  $$->function_subnode_->name_ = $2->identifier_subnode_->value_;
  $$->function_subnode_->operations_ =
      $28->operations_list_subnode_->operations_;
  $$->function_subnode_->type_ = FUNCTION_SUBNODE_TYPE_CLI_FUNCTION;

  $$->type_ = SYNTAX_TREE_NODE_TYPE_FUNCTION;

  free($2->identifier_subnode_);
  free($2);
  free($28->operations_list_subnode_);
  free($28);
  free($34->identifier_subnode_->value_);
  free($34->identifier_subnode_);
  free($34);
}
;

/*
cli_fn_receives_def :
  T_RECEIVES cli_fn_receives_def_inner
{
  b_trace_chars_array("cli_fn_receives_def : T_RECEIVES cli_fn_receives_def_inner\n");
}
;

cli_fn_receives_def_inner :
  T_NO T_ARGS T_AT T_ALL
{
  b_trace_chars_array("cli_fn_receives_def_inner : T_NO T_ARGS T_AT T_ALL\n");
}
;
*/

cli_fn_def_with_clause :
  T_WITH T_EASE
{
  b_trace_chars_array("cli_fn_def_with_clause : T_WITH T_EASE\n"); /* XXX */
}
| T_WITH T_A T_SMALL T_CHAIN T_OF T_COMMANDS
{
  b_trace_chars_array("cli_fn_def_with_clause : T_WITH T_A T_SMALL T_CHAIN T_OF ");
  b_trace_chars_array("T_COMMANDS\n");  /* XXX */
}
| T_WITH T_A T_SUBSTRACTION T_OPERATOR
{
  b_trace_chars_array("cli_fn_def_with_clause : T_WITH T_A T_SUBSTRACTION ");
  b_trace_chars_array("T_OPERATOR"); /* XXX */
}
| T_WITH T_A T_DIVISION T_OPERATOR
{
  b_trace_chars_array("cli_fn_def_with_clause : T_WITH T_A T_DIVISION ");
  b_trace_chars_array("T_OPERATOR"); /* XXX */
}
;

exectn_req :
  T_RUN T_COMMAND T_LINE T_INTERFACE T_APPLICATION T_IDENTIFIER
{
  b_trace_chars_array("exectn_req : T_RUN T_COMMAND T_LINE T_INTERFACE ");
  b_trace_chars_array("T_APPLICATION T_IDENTIFIER\n");
  assertion_two($6 != NULL, "$6 unexpectedly NULL");
  assertion_two($6->type_ == SYNTAX_TREE_NODE_TYPE_IDENTIFIER,
      "unexpected value of $6->type_");
  assertion_two($6->identifier_subnode_->value_ != NULL,
      "$6->identifier_subnode_->value_ unexpectedly NULL");
  $$ = stt_node_default_constructor();
  $$->type_ = SYNTAX_TREE_NODE_TYPE_EXECUTION_REQUEST;
  $$->execution_request_subnode_ =
      stt_execution_request_subnode_default_constructor();
  $$->execution_request_subnode_->type_ =
      EXECUTION_REQUEST_SUBNODE_TYPE_RUN_CLI_APPLICATION;
  $$->execution_request_subnode_->application_name_ =
      $6->identifier_subnode_->value_;

  free($6->identifier_subnode_);
  free($6);

  /* stt_node_destructor($6); */

  /* free($6); */
}
;

cli_fn_ops :
  cli_fn_op T_AND cli_fn_ops
{
  stt_operations_simple_list * new_node_;
  b_trace_chars_array("cli_fn_ops : cli_fn_op T_AND cli_fn_ops\n");
  assertion($1 != NULL);
  assertion($1->type_ == SYNTAX_TREE_NODE_TYPE_OPERATION);
  assertion($1->operation_subnode_ != NULL);
  assertion($1->operation_subnode_->operation_ != NULL);
  assertion($3 != NULL);
  assertion($3->type_ == SYNTAX_TREE_NODE_TYPE_CLI_OPERATIONS_LIST);
  assertion($3->operations_list_subnode_ != NULL);
  new_node_ = stt_operations_simple_list_default_constructor();
  new_node_->first = $1->operation_subnode_->operation_;
  new_node_->next = $3->operations_list_subnode_->operations_;
  $3->operations_list_subnode_->operations_ = new_node_;
  $$ = $3;
  free($3);
  free($1->operation_subnode_);
  free($1);
}
| cli_fn_op
{
  b_trace_chars_array("cli_fn_ops : cli_fn_op\n");
  assertion($1 != NULL);
  assertion($1->type_ == SYNTAX_TREE_NODE_TYPE_OPERATION);
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
  $$->type_ = SYNTAX_TREE_NODE_TYPE_CLI_OPERATIONS_LIST;
  free($1->operation_subnode_);
  free($1);
}
;

cli_fn_op :
  T_PRINT printable
{
  b_trace_chars_array("cli_fn_op : T_PRINT printable\n");
  b_trace_chars_array("type of printable: ");
  b_trace_uintfast8t($2->type_);
  b_trace_chars_array("\n");
  if ($2->type_ == SYNTAX_TREE_NODE_TYPE_STRING_LITERAL) {
    assert_pure_string_literal_node($2);
  } else {
    assertion_two_located_interim($2->type_ == SYNTAX_TREE_NODE_TYPE_NATURAL,
        "unexpected node type at %s:%d\n", __FILE__, __LINE__);
    assert_pure_natural_node($2);
  }
  $$ = stt_node_default_constructor();
  $$->operation_subnode_ = stt_operation_subnode_default_constructor();
  $$->operation_subnode_->operation_ = stt_operation_default_constructor();
  $$->operation_subnode_->operation_->type_ = STT_OPERATION_TYPE_PRINT;
  $$->operation_subnode_->operation_->args_ =
      stt_operation_args_simple_list_default_constructor();
  $$->operation_subnode_->operation_->args_->first =
      stt_operation_arg_default_constructor();
  $$->operation_subnode_->operation_->args_->first->type_ = $2->type_;
  $$->operation_subnode_->operation_->args_->first->node_ = $2;
  $$->operation_subnode_->operation_->args_->next = NULL;
  $$->type_ = SYNTAX_TREE_NODE_TYPE_OPERATION;
}
| T_PRINT printable T_WITHOUT T_LINE T_FEED T_NOR T_CARRIAGE T_RETURN
{
  b_trace_chars_array(
      "cli_fn_op : T_PRINT printable T_WITHOUT T_LINE T_FEED ");
  b_trace_chars_array("T_NOR T_CARRIAGE T_RETURN\n");
  if ($2->type_ == SYNTAX_TREE_NODE_TYPE_STRING_LITERAL) {
    assert_pure_string_literal_node($2);
  } else {
    assertion_two_located_interim($2->type_ == SYNTAX_TREE_NODE_TYPE_NATURAL,
        "unexpected node type at %s:%d\n", __FILE__, __LINE__);
    assert_pure_natural_node($2);
  }
  $$ = stt_node_default_constructor();
  $$->operation_subnode_ = stt_operation_subnode_default_constructor();
  $$->operation_subnode_->operation_ = stt_operation_default_constructor();
  $$->operation_subnode_->operation_->type_ = STT_OPERATION_TYPE_PRINT_NO_CRLF;
  $$->operation_subnode_->operation_->args_ =
      stt_operation_args_simple_list_default_constructor();
  $$->operation_subnode_->operation_->args_->first =
      stt_operation_arg_default_constructor();
  $$->operation_subnode_->operation_->args_->first->type_ = $2->type_;
  $$->operation_subnode_->operation_->args_->first->node_ = $2;
  $$->operation_subnode_->operation_->args_->next = NULL;
  $$->type_ = SYNTAX_TREE_NODE_TYPE_OPERATION;
}
;

printable :
  lvalue
{
  /* TODO   Likely `lvalue` is bad wording choice here. */
  b_trace_chars_array("printable : lvalue\n");
  if ($1->type_ == SYNTAX_TREE_NODE_TYPE_STRING_LITERAL) {
    assert_pure_string_literal_node($1);
  } else {
    assertion_two_located_interim($1->type_ == SYNTAX_TREE_NODE_TYPE_NATURAL,
        "unexpected node type at %s:%d\n", __FILE__, __LINE__);
    assert_pure_natural_node($1);
  }
  $$ = $1;
}
;

lvalue :
  string_lvalue
{
  /* TODO   Likely `lvalue` is bad wording choice here. */
  b_trace_chars_array("lvalue : string_lvalue\n");
  assertion_two_located_interim(
      $1->type_ == SYNTAX_TREE_NODE_TYPE_STRING_LITERAL,
      "unexpected node type at %s:%d\n", __FILE__, __LINE__);
  assert_pure_string_literal_node($1);
  $$ = $1;
}
| numeric_lvalue
{
  /* TODO   Likely `lvalue` is bad wording choice here. */
  b_trace_chars_array("lvalue : numeric_lvalue\n");
  assertion_two_located_interim($1->type_ == SYNTAX_TREE_NODE_TYPE_NATURAL,
      "unexpected node type at %s:%d\n", __FILE__, __LINE__);
  assert_pure_natural_node($1);
  $$ = $1;
}
;

string_lvalue :
  T_STRING_LITERAL
{
  /* TODO   Likely `lvalue` is bad wording choice here. */
  b_trace_chars_array("string_lvalue : T_STRING_LITERAL\n");
  assertion_two_located_interim(
      $1->type_ == SYNTAX_TREE_NODE_TYPE_STRING_LITERAL,
      "unexpected node type at %s:%d\n", __FILE__, __LINE__);
  assert_pure_string_literal_node($1);
  $$ = $1;
}
| T_TYPE T_OF numeric_lvalue
{
  /* TODO   Likely `lvalue` is bad wording choice here. */
  char * value_char_array_;
  b_trace_chars_array("string_lvalue : T_TYPE T_OF numeric_lvalue\n");
  assertion_two_located_interim($3->type_ == SYNTAX_TREE_NODE_TYPE_NATURAL,
      "unexpected node type at %s:%d\n", __FILE__, __LINE__);
  assert_pure_natural_node($3);
  value_char_array_ = malloc(strlen("natural") + 1);
  strcpy(value_char_array_, "natural");
  $$ = stt_node_default_constructor();
  $$->string_literal_subnode_ =
      stt_string_literal_subnode_default_constructor();
  $$->string_literal_subnode_->string_literal_ =
      amara_string_default_constructor();
  amara_string_set_value(
      $$->string_literal_subnode_->string_literal_, value_char_array_);
  $$->type_ = SYNTAX_TREE_NODE_TYPE_STRING_LITERAL;
  amara_string_destructor($3->natural_subnode_->raw_);
  stt_natural_subnode_destructor($3->natural_subnode_);
  stt_node_destructor($3);
}
;

numeric_lvalue :
  number_literal
{
  /* TODO   Likely `lvalue` is bad wording choice here. */
  b_trace_chars_array("numeric_lvalue : number_literal\n");
  assertion_two_located_interim($1->type_ == SYNTAX_TREE_NODE_TYPE_NATURAL,
      "unexpected node type at %s:%d\n", __FILE__, __LINE__);
  assert_pure_natural_node($1);
  $$ = $1;
}
| numeric_lvalue T_DIVIDED_BY numeric_lvalue
{
  /* TODO   Likely `lvalue` is bad wording choice here. */
  b_trace_chars_array(
      "numeric_lvalue : numeric_lvalue T_DIVIDED_BY numeric_lvalue\n");
  assertion_two_located_interim($1->type_ == SYNTAX_TREE_NODE_TYPE_NATURAL,
      "unexpected node type at %s:%d\n", __FILE__, __LINE__);
  assertion_two_located_interim($3->type_ == SYNTAX_TREE_NODE_TYPE_NATURAL,
      "unexpected node type at %s:%d\n", __FILE__, __LINE__);
  $$ = numeric_natural_nodes_division($1, $3);
  amara_string_destructor($1->natural_subnode_->raw_);
  stt_natural_subnode_destructor($1->natural_subnode_);
  stt_node_destructor($1);
  amara_string_destructor($3->natural_subnode_->raw_);
  stt_natural_subnode_destructor($3->natural_subnode_);
  stt_node_destructor($3);
}
| numeric_lvalue T_MINUS numeric_lvalue
{
  /* TODO   Likely `lvalue` is bad wording choice here. */
  b_trace_chars_array(
      "numeric_lvalue : numeric_lvalue T_MINUS numeric_lvalue\n");
  assertion_two_located_interim($1->type_ == SYNTAX_TREE_NODE_TYPE_NATURAL,
      "unexpected node type at %s:%d\n", __FILE__, __LINE__);
  assertion_two_located_interim($3->type_ == SYNTAX_TREE_NODE_TYPE_NATURAL,
      "unexpected node type at %s:%d\n", __FILE__, __LINE__);
  $$ = numeric_natural_nodes_substraction($1, $3);
  amara_string_destructor($1->natural_subnode_->raw_);
  stt_natural_subnode_destructor($1->natural_subnode_);
  stt_node_destructor($1);
  amara_string_destructor($3->natural_subnode_->raw_);
  stt_natural_subnode_destructor($3->natural_subnode_);
  stt_node_destructor($3);
}
;

number_literal :
  T_NATURAL
{
  b_trace_chars_array("number_literal : T_NATURAL\n");
  assertion_two_located_interim($1->type_ == SYNTAX_TREE_NODE_TYPE_NATURAL,
      "unexpected node type at %s:%d\n", __FILE__, __LINE__);
  assert_pure_natural_node($1);
  $$ = $1;
  b_trace_chars_array("number_literal (");
  b_trace_chars_array($$->natural_subnode_->raw_->value_);
  b_trace_chars_array(") : T_NATURAL (");
  b_trace_chars_array($1->natural_subnode_->raw_->value_);
  b_trace_chars_array(")\n");
}
| T_INTEGER
{
  b_trace_chars_array("number_literal : T_INTEGER\n");
  assertion_two_located_interim($1->type_ == SYNTAX_TREE_NODE_TYPE_STRING_LITERAL /* XXX */,
      "unexpected node type at %s:%d\n", __FILE__, __LINE__);
  $$ = $1;
}
| T_RATIONAL
{
  b_trace_chars_array("number_literal : T_RATIONAL\n");
  assertion_two_located_interim($1->type_ == SYNTAX_TREE_NODE_TYPE_STRING_LITERAL /* XXX */,
      "unexpected node type at %s:%d\n", __FILE__, __LINE__);
  $$ = $1;
}
;

%%

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
        do {
    miniaparse_ret_ = miniaparse(shared_with_miniaparse_);
        } while (!feof(miniain));
  if (miniaparse_ret_ == miniaparse_ret_success_) {
    if (shared_with_miniaparse_->type_ != SYNTAX_TREE_NODE_TYPE_DOC) {
      fprintf(stderr, "shared_with_miniaparse_->type_: %u\n",
          shared_with_miniaparse_->type_);
    }
    assertion_two(
        shared_with_miniaparse_->type_ == SYNTAX_TREE_NODE_TYPE_DOC,
        "unexpected type of `shared_with_miniaparse_->type_`");
    assertion_two(shared_with_miniaparse_->doc_subnode_ != NULL,
        "`shared_with_miniaparse_->doc_subnode_` unexpectedly set `NULL`");
    returning_ = stt_node_default_constructor();  /* XXX */
    returning_->type_ = shared_with_miniaparse_->type_; /* XXX */
    returning_->doc_subnode_ = shared_with_miniaparse_->doc_subnode_; /* XXX */
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
