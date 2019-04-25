%{

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
 * src/bsn/minia.l: Amara Minia scripts Flex scanner.
 */

%}

%option noinput
%option nounput
%option noyywrap

%{

/*   For `int fileno(FILE * stream)`, which is necessary not by
 * `minia.l` but for `lex.minia.c`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "../stt/stt_dice_expression.h"

/*   For the bison nodes and node types. */
#include "../stt/stt_node.h"

#define YY_DECL int yylex()

#include "minia.tab.h"

#ifdef TRACE_FLEX
#define TRACE_FLEX_CONSTANT_VALUE 0xFF
#else
#define TRACE_FLEX_CONSTANT_VALUE 0x00
#endif

const unsigned char trace_flex_constant = TRACE_FLEX_CONSTANT_VALUE;

void
trace_flex_one(const char * s0)
{
  if (trace_flex_constant) {
    fprintf(stderr, "%s", s0);
  }
}

void
trace_flex_three(const char * s0, const char * s1, const char * s2)
{
  if (trace_flex_constant) {
    fprintf(stderr, "%s", s0);
    fprintf(stderr, "%s", s1);
    fprintf(stderr, "%s", s2);
  }
}

%}

%%

! {
    /*   ASCII 0x21
       Decimal 33. */
    trace_flex_three("ignoring excl mark ('", yytext, "')\n");
}

\" {

    trace_flex_three("ignoring double quote ('", yytext, "')\n");
}

# {
    /*   ASCII 0x23
     * Decimal 35. */
    trace_flex_three("ignoring hash character ('", yytext, "')\n");
}

\$ {
    /*   ASCII 0x24
     * Decimal 36. */
    trace_flex_three("ignoring dollar character ('", yytext, "')\n");
}

% {
    /*   ASCII 0x25
     * Decimal 37. */
    trace_flex_three("ignoring percent character ('", yytext, "')\n");
}

& {
    trace_flex_three("ignoring ampersand ('", yytext, "')\n");
}

' {
    trace_flex_three("ignoring single quote (\"", yytext, "\")\n");
}

\( {
    trace_flex_three("ignoring parens opening ('", yytext, "')\n");
}

\) {
    trace_flex_three("ignoring parens closing ('", yytext, "')\n");
}

\* {
    /*   ASCII 0x2A
     * Decimal 42. */
    trace_flex_three("ignoring asterisk ('", yytext, "')\n");
}

\+ {
    trace_flex_three("ignoring plus sign ('", yytext, "')\n");
}

, {
    trace_flex_three("ignoring comma ('", yytext, "')\n");
}

- {
    trace_flex_three("ignoring minus sign / n dash ('", yytext, "')\n");
}

\. {
    trace_flex_three("ignoring dot ('", yytext, "')\n");
}

\/ {
    /*   ASCII 0x2F
     * Decimal 47. */
    trace_flex_three("ignoring slash ('", yytext, "')\n");
}

\: {
/* 0x34 */
    trace_flex_three("ignoring colon ('", yytext, "')\n");
}

; {
/* 0x35 */
    trace_flex_three("ignoring semicolon ('", yytext, "')\n");
}

\< {
/* 0x36 */
    trace_flex_three("ignoring _less than symbol_ ('", yytext, "')\n");
}

= {
/* 0x37 */
    trace_flex_three("ignoring _equals symbol_ ('", yytext, "')\n");
}

> {
/* 0x38 */
    trace_flex_three("ignoring _greater than symbol_ ('", yytext, "')\n");
}

\? {

    /*   ASCII 0x39
     * Decimal 63. */

    trace_flex_three("ignoring extraneous interrogation symbol ('", yytext,
                     "')\n");
}

@ {
    /*   ASCII 0x40
     * Decimal 64. */

    /*
    trace_flex_three("found extraneous _at symbol_ ('", yytext, "')\n");
    return T_AT_SYMBOL;
    */

    trace_flex_three("ignoring extraneous _at symbol_ ('", yytext, "')\n");
}

\[ {
    /*   ASCII 0x5B
     * Decimal 91. */
    trace_flex_three("ignoring square bracket opening ('", yytext, "')\n");
}

\\ {

    trace_flex_three("ignoring backslash ('", yytext, "')\n");
}

] {

    trace_flex_three("ignoring square bracket closing ('", yytext, "')\n");
}

\^ {

    trace_flex_three("ignoring upper angle / circumflex ('", yytext, "')\n");
}

_ {

    trace_flex_three("ignoring underscore ('", yytext, "')\n");
}

` {
    /*   ASCII 0x60
     * Decimal 96. */
    trace_flex_three("ignoring backtick quote ('", yytext, "')\n");
}

\{ {
    /*   ASCII 0x7B
     * Decimal 123. */
    trace_flex_three("ignoring brace opening ('", yytext, "')\n");
}

\| {
    trace_flex_three("ignoring vertical bar ('", yytext, "')\n");
}

\} {
    trace_flex_three("ignoring brace closing ('", yytext, "')\n");
}

~ {
    /*   ASCII 0x7E
     * Decimal 126. */
    trace_flex_three("ignoring tilde ('", yytext, "')\n");
}

[Ee][Xx][Tt][Ee][Nn][s][i][o][n]([^Ee]|[Ee][^Xx]|[e][x][^Tt]|[e][x][t][^Ee]|[e][x][t][e][^Nn]|exten[^Ss]|extens[^Ii]|extensi[^Oo]|extensio[^Nn]|extension[^ \n\t]|extension[ \n\t]+[^Ee]|extension[ \n\t]+e[^n]|extension[ \n\t]+en[^d]|extension[ \n\t]+end[^s])*extension[ \n\t]+ends {

    /*   Extensions are implementation dependent. */
    trace_flex_three("ignoring extension ('", yytext, "')\n");
  }

[Cc][Oo][Mm][Mm][Ee][Nn][Tt]([^c]|c[^o]|co[^m]|com[^m]|comm[^e]|comme[^n]|commen[^t]|comment[^ \n\t]|comment[ \n\t]+[^e]|comment[ \n\t]+e[^n]|comment[ \n\t]+en[^d]|comment[ \n\t]+end[^s])*[c][o][m][m][e][n][t][ \n\t]+[e][n][d][s] {

    /*   Comments are ignored. */
    trace_flex_three("ignoring comment ('", yytext, "')\n");
  }

[ \n\t]         {
                    if (yytext[0] == ' ') {
      trace_flex_one("discarding whitespace (space)\n");
                    } else if (yytext[0] == '\t') {
      trace_flex_one("discarding whitespace (tab)\n");
                    } else {
                      assertion(yytext[0] == '\n');
      trace_flex_one("discarding whitespace (line feed)\n");
                    }
    /*   Ignore all white space. */
                }

-[1-9][0-9]* {
    trace_flex_three("returning T_INTEGER_LITERAL (", yytext, ")\n");
    assertion_two(0, "unimplemented code at %s:%d\n");
    return T_INTEGER_LITERAL;
  }

-?(0|[1-9][0-9]*)\.[0-9]*[1-9] {
    trace_flex_three("returning T_RATIONAL_LITERAL (", yytext, ")\n");
    assertion_two(0, "unimplemented code at %s:%d\n");
    return T_RATIONAL_LITERAL;
                }

[1-9]d([468]|12|20) {
    char * dice_left_hand_side_char_array_;
    amara_string * dice_left_hand_side_raw_natural_;
    natural * dice_left_hand_side_;
    char * dice_right_hand_side_char_array_;
    amara_string * dice_right_hand_side_raw_natural_;
    natural * dice_right_hand_side_;
    /**  FIXME MUST RETURN NOT AN stt_dice_expression BUT AN stt_expression CORRECTLY SET TO the STT_EXPRESSION_TYPE_DICE TYPE AND WITH ITS DATA HANGING FROM THE stt_expression_sub_dice SUB. */
    stt_dice_expression * dice_expression_;

    trace_flex_three("returning T_DICE_EXPRESSION (", yytext, ")\n");

    assertion(yytext[0] > 48 && yytext[0] < 58);
    dice_left_hand_side_char_array_ = malloc(1 + 1);
    dice_left_hand_side_char_array_[0] = yytext[0];
    dice_left_hand_side_char_array_[1] = '\0';
    dice_left_hand_side_raw_natural_ =
        amara_string_exhaustive_constructor(dice_left_hand_side_char_array_);
    dice_left_hand_side_ =
        natural_exhaustive_constructor(dice_left_hand_side_raw_natural_);

    assertion(yytext[1] == 'd');

    if (yytext[2] == '4' || yytext[2] == '6' || yytext[2] == '8') {
      dice_right_hand_side_char_array_ = malloc(1 + 1);
      dice_right_hand_side_char_array_[0] = yytext[2];
      dice_right_hand_side_char_array_[1] = '\0';
    } else {
      assertion(yytext[2] == '1' || yytext[2] == '2');
      dice_right_hand_side_char_array_ = malloc(2 + 1);
      dice_right_hand_side_char_array_[0] = yytext[2];
      if (yytext[2] == '1') {
        assertion(yytext[3] == '2');
      } else if (yytext[2] == '2') {
        assertion(yytext[3] == '0');
      }
      dice_right_hand_side_char_array_[1] = yytext[3];
      dice_right_hand_side_char_array_[2] = '\0';
    }
    dice_right_hand_side_raw_natural_ =
        amara_string_exhaustive_constructor(dice_right_hand_side_char_array_);
    dice_right_hand_side_ =
        natural_exhaustive_constructor(dice_right_hand_side_raw_natural_);

    dice_expression_ = stt_dice_expression_exhaustive_constructor(
        dice_left_hand_side_, dice_right_hand_side_);

    minialval.node = stt_node_default_constructor();
    stt_node_set_dice_expression(minialval.node, dice_expression_);

    stt_dice_expression_destructor(dice_expression_);
    natural_destructor(dice_right_hand_side_);
    amara_string_destructor(dice_right_hand_side_raw_natural_);
    free(dice_right_hand_side_char_array_);
    natural_destructor(dice_left_hand_side_);
    amara_string_destructor(dice_left_hand_side_raw_natural_);
    free(dice_left_hand_side_char_array_);

    return T_DICE_EXPRESSION;
  }

(0|[1-9][0-9]*) {
    unsigned char single_byte_indexer_;
    /* unsigned short double_byte_indexer_; */
    amara_string * raw_;
    char * raw_char_array_;

    trace_flex_three("returning T_NATURAL_LITERAL (", yytext, ")\n");

    minialval.node = stt_node_default_constructor();
    minialval.node->natural_literal_subnode_ =
        stt_natural_literal_subnode_default_constructor();

                  /*   This is a little bit weirder than it should,
                   * because of removing the single quotes from the
                   * string. */
    raw_char_array_ = (char *) malloc(minialeng + 1);
    assertion_two(minialeng < 0x7F,
        "consider making the flow for `double_byte_indexer_` when necessary over `single_byte_indexer_`");
                  for (
        single_byte_indexer_ = 0; single_byte_indexer_ < minialeng;
        single_byte_indexer_++)
                  {
      raw_char_array_[single_byte_indexer_] = yytext[single_byte_indexer_];
                  }
    raw_char_array_[single_byte_indexer_] = '\0';
    raw_ = amara_string_default_constructor();
    amara_string_set_value(raw_, raw_char_array_);
    free(raw_char_array_);
    stt_natural_literal_subnode_set_raw(
        minialval.node->natural_literal_subnode_, raw_);
    minialval.node->type_ = STT_NODE_TYPE_NATURAL_LITERAL;
    amara_string_destructor(raw_);
    return T_NATURAL_LITERAL;
                }

without {
    trace_flex_three("returning T_WITHOUT (", yytext, ")\n");
    return T_WITHOUT;
  }

with            {
    trace_flex_three("returning T_WITH (", yytext, ")\n");
                  return T_WITH;
                }

where {
    trace_flex_three("returning T_WHERE (", yytext, ")\n");
    return T_WHERE;
  }

type {
    trace_flex_three("returning T_TYPE (", yytext, ")\n");
    return T_TYPE;
  }

to {
    trace_flex_three("returning T_TO (", yytext, ")\n");
    return T_TO;
  }

thread {
    trace_flex_three("returning T_THREAD (", yytext, ")\n");
    return T_THREAD;
  }

then {
    trace_flex_three("returning T_THEN (", yytext, ")\n");
    return T_THEN;
  }

the {
    trace_flex_three("returning T_THE (", yytext, ")\n");
    return T_THE;
  }

that {
    trace_flex_three("returning T_THAT (", yytext, ")\n");
    return T_THAT;
  }

than {
    trace_flex_three("returning T_THAN (", yytext, ")\n");
    return T_THAN;
  }

times {
    trace_flex_three("returning T_TIMES (", yytext, ")\n");
    return T_TIMES;
  }

substraction {
    trace_flex_three("returning T_SUBSTRACTION (", yytext, ")\n");
    return T_SUBSTRACTION;
  }

so {
    trace_flex_three("returning T_SO (", yytext, ")\n");
    return T_SO;
  }

small {
    trace_flex_three("returning T_SMALL (", yytext, ")\n");
    return T_SMALL;
  }

simple {
    trace_flex_three("returning T_SIMPLE (", yytext, ")\n");
    return T_SIMPLE;
  }

side {
    trace_flex_three("returning T_SIDE (", yytext, ")\n");
    return T_SIDE;
  }

set {
    trace_flex_three("returning T_SET (", yytext, ")\n");
    return T_SET;
  }

run {
    trace_flex_three("returning T_RUN (", yytext, ")\n");
    return T_RUN;
  }

returns         {
    trace_flex_three("returning T_RETURNS (", yytext, ")\n");
                  return T_RETURNS;
                }

return {
    trace_flex_three("returning T_RETURN (", yytext, ")\n");
    return T_RETURN;
  }

receives        {
    trace_flex_three("returning T_RECEIVES (", yytext, ")\n");
                  return T_RECEIVES;
                }

read {
    trace_flex_three("returning T_READ (", yytext, ")\n");
    return T_READ;
  }

rational {
    trace_flex_three("returning T_RATIONAL (", yytext, ")\n");
    return T_RATIONAL;
  }

print           {
    trace_flex_three("returning T_PRINT (", yytext, ")\n");
                  return T_PRINT;
                }

point           {
    trace_flex_three("returning T_POINT (", yytext, ")\n");
                  return T_POINT;
                }

operator {
    trace_flex_three("returning T_OPERATOR (", yytext, ")\n");
    return T_OPERATOR;
  }

of {
    trace_flex_three("returning T_OF (", yytext, ")\n");
    return T_OF;
  }

nothing         {
    trace_flex_three("returning T_NOTHING (", yytext, ")\n");
                  return T_NOTHING;
                }

nor {
    trace_flex_three("returning T_NOR (", yytext, ")\n");
    return T_NOR;
  }

no              {
    trace_flex_three("returning T_NO (", yytext, ")\n");
                  return T_NO;
                }

new {
    trace_flex_three("returning T_NEW (", yytext, ")\n");
    return T_NEW;
  }

natural {
    trace_flex_three("returning T_NATURAL (", yytext, ")\n");
    return T_NATURAL;
  }

minus {
    trace_flex_three("returning T_MINUS (", yytext, ")\n");
    return T_MINUS;
  }

line {
    trace_flex_three("returning T_LINE (", yytext, ")\n");
    return T_LINE;
  }

less {
    trace_flex_three("returning T_LESS (", yytext, ")\n");
    return T_LESS;
  }

it {
    trace_flex_three("returning T_IT (", yytext, ")\n");
    return T_IT;
  }

is              {
    trace_flex_three("returning T_IS (", yytext, ")\n");
                  return T_IS;
                }

if {
    trace_flex_three("returning T_IF (", yytext, ")\n");
    return T_IF;
  }

interface {
    trace_flex_three("returning T_INTERFACE (", yytext, ")\n");
    return T_INTERFACE;
  }

integer {
    trace_flex_three("returning T_INTEGER (", yytext, ")\n");
    return T_INTEGER;
  }

greater {
    trace_flex_three("returning T_GREATER (", yytext, ")\n");
    return T_GREATER;
  }

function        {
    trace_flex_three("returning T_FUNCTION (", yytext, ")\n");
                  return T_FUNCTION;
                }

formula {
    trace_flex_three("returning T_FORMULA (", yytext, ")\n");
    return T_FORMULA;
  }

feed {
    trace_flex_three("returning T_FEED (", yytext, ")\n");
    return T_FEED;
  }

entry           {
    trace_flex_three("returning T_ENTRY (", yytext, ")\n");
                  return T_ENTRY;
                }

end {
    trace_flex_three("returning T_END (", yytext, ")\n");
    return T_END;
  }

else {
    trace_flex_three("returning T_ELSE (", yytext, ")\n");
    return T_ELSE;
  }

effects {
    trace_flex_three("returning T_EFFECTS (", yytext, ")\n");
    return T_EFFECTS;
  }

ease            {
    trace_flex_three("returning T_EASE (", yytext, ")\n");
                  return T_EASE;
                }

does            {
    trace_flex_three("returning T_DOES (", yytext, ")\n");
                  return T_DOES;
                }

division {
    trace_flex_three("returning T_DIVISION (", yytext, ")\n");
    return T_DIVISION;
  }

divided {
    trace_flex_three("returning T_DIVIDED (", yytext, ")\n");
    return T_DIVIDED;
  }

by {
    trace_flex_three("returning T_BY (", yytext, ")\n");
    return T_BY;
  }

commands {
    trace_flex_three("returning T_COMMANDS (", yytext, ")\n");
    return T_COMMANDS;
  }

command {
    trace_flex_three("returning T_COMMAND (", yytext, ")\n");
    return T_COMMAND;
                }

chain {
    trace_flex_three("returning T_CHAIN (", yytext, ")\n");
    return T_CHAIN;
  }

causes {
    trace_flex_three("returning T_CAUSES (", yytext, ")\n");
    return T_CAUSES;
  }

carriage {
    trace_flex_three("returning T_CARRIAGE (", yytext, ")\n");
    return T_CARRIAGE;
  }

awesome         {
    trace_flex_three("returning T_AWESOME (", yytext, ")\n");
                  return T_AWESOME;
                }

at              {
    trace_flex_three("returning T_AT (", yytext, ")\n");
                  return T_AT;
                }

args            {
    trace_flex_three("returning T_ARGS (", yytext, ")\n");
                  return T_ARGS;
                }

application {
    trace_flex_three("returning T_APPLICATION (", yytext, ")\n");
    return T_APPLICATION;
                }

and             {
    trace_flex_three("returning T_AND (", yytext, ")\n");
                  return T_AND;
                }

an              {
    trace_flex_three("returning T_AN (", yytext, ")\n");
                  return T_AN;
                }

[Aa][Ll][Ll] {
    trace_flex_three("returning T_ALL (", yytext, ")\n");
                  return T_ALL;
                }

[Aa] {
    trace_flex_three("returning T_A (", yytext, ")\n");
                  return T_A;
                }

[Ss][Tt][Rr][Ii][Nn][Gg][ \n\t]+[Ll][Ii][Tt][Ee][Rr][Aa][Ll]([^Ss]|[Ss][^t]|[s][t][^r]|str[^i]|stri[^n]|strin[^g]|string[^ \n\t]|string[ \n\t]+[^l]|string[ \n\t]+l[^i]|string[ \n\t]+li[^t]|string[ \n\t]+lit[^e]|string[ \n\t]+lite[^r]|string[ \n\t]+liter[^a]|string[ \n\t]+litera[^l]|string[ \n\t]+literal[^ \n\t]|string[ \n\t]+literal[ \n\t][^e]|string[ \n\t]+literal[ \n\t]+e[^n]|string[ \n\t+]literal[ \n\t]+en[^d]|string[ \n\t]+literal[ \n\t]+end[^s])+[s][t][r][i][n][g][ \n\t]+[l][i][t][e][r][a][l][ \n\t]+[e][n][d][s] {

    unsigned char single_byte_indexer_;
    /* unsigned short double_byte_indexer_; */
    amara_string * value_;
    char * value_char_array_;

    trace_flex_three("returning T_STRING_LITERAL (", yytext, ")\n");

    minialval.node = stt_node_default_constructor();
    minialval.node->type_ = STT_NODE_TYPE_STRING_LITERAL;
    minialval.node->string_literal_subnode_ =
        stt_string_literal_subnode_default_constructor();

                  /*   This is a little bit weirder than it should,
     * because of removing the single or double quotes from the
                   * string. */
    value_char_array_ = (char *) malloc(
        minialeng -
        /* when it was delimited by single or double quotes.
        2
        */
        /* XXX only considering one single space
         * "foo"
         *   (- 2)
         * string literal foo string literal ends
         * ^^^^^^^^^^^^^^^   ^^^^^^^^^^^^^^^^^^^^
         *     15 total         20 total
         *   (- (15 + 20 = 35) */
        35
        /*   0x00 terminator. */
        + 1);
    assertion_two(minialeng < 0x7F,
        "consider making the flow for `double_byte_indexer_` when necessary over `single_byte_indexer_`");
                  for (
        single_byte_indexer_ = 0; single_byte_indexer_ < minialeng - 15 - 20;
        single_byte_indexer_++)
                  {
      fprintf(stderr, "parsing string literal: char '%c')\n", yytext[single_byte_indexer_ + 15]);
      value_char_array_[single_byte_indexer_] = yytext[single_byte_indexer_ + 15];
                  }
    value_char_array_[single_byte_indexer_] = '\0';
    value_ = amara_string_default_constructor();
    amara_string_set_value(value_, value_char_array_);
    stt_string_literal_subnode_set_string_literal(
        minialval.node->string_literal_subnode_, value_);
    amara_string_destructor(value_);
    free(value_char_array_);
                  return T_STRING_LITERAL;
                }

[a-z][0-9_a-z]* {

    unsigned char single_byte_indexer_;
    /* unsigned short double_bytes_indexer_; */
    amara_string * value_;
    char * value_char_array_;

    trace_flex_three("returning T_IDENTIFIER (", yytext, ")\n");

    /* XXX Can use just `strdup`, but I was just copying code from the string literals extractor so it's OK. */
    value_char_array_ = (char *) malloc(minialeng + 1);
    assertion_two(minialeng < 0x7F,
        "start considering the flow for `double_bytes_indexer_` when necessary over `single_byte_indexer_`");
    for (
        single_byte_indexer_ = 0; single_byte_indexer_ < minialeng;
        single_byte_indexer_++) {
      value_char_array_[single_byte_indexer_] = yytext[single_byte_indexer_];
    }
    value_char_array_[single_byte_indexer_] = '\0';
    value_ = amara_string_default_constructor();
    amara_string_set_value(value_, value_char_array_);
    free(value_char_array_);
    minialval.node = stt_node_default_constructor();
    stt_node_set_identifier(minialval.node, value_);
    amara_string_destructor(value_);
                  return T_IDENTIFIER;
                }

%%
