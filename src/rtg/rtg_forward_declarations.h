/*
 * Copyright 2020 Mercedes Catherine Salazar
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
 * src/rtg/rtg_forward_declarations.h: Some Amara run time graph
 * forward declarations.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__FORWARD_DECLARATIONS__H__
#define __AMARA__RUN_TIME_GRAPH__FORWARD_DECLARATIONS__H__

/*   For `natural`. */
#include "../brt/natural.h"

#define RTG_OPERATION_TYPE_INVALID                         0x00
#define RTG_OPERATION_TYPE_PRINT                           0x03
#define RTG_OPERATION_TYPE_PRINT_CRLF                      0x0C
#define RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE           0xBF
#define RTG_OPERATION_TYPE_READ_NATURAL_INTO_VALUE \
		RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE
#define RTG_OPERATION_TYPE_READ_INTEGER_INTO_VALUE         0xC0
/*
#define RTG_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE        0xC1
#define RTG_OPERATION_TYPE_READ_NATURAL_INTO_VARIABLE \
		RTG_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE
*/
/*
#define RTG_FAKE_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION 0xC2 *//*   Must remain resolved by semantic analysis by the time run time comes. */
#define RTG_OPERATION_TYPE_EXECUTION                       0xD0
/*
#define RTG_OPERATION_TYPE_PRINT_NO_CRLF                   0xFF
*/

typedef unsigned char rtg_operation_type;

typedef struct rtg_operation {

	rtg_operation_type type_;

	struct rtg_operation_args_simple_list * args_;
} rtg_operation
;

typedef struct rtg_operations_simple_list {

	rtg_operation * first;

	struct rtg_operations_simple_list * next;
} rtg_operations_simple_list
;

typedef struct rtg_expression_sub_string_literal {

	amara_string * string_literal_;
} rtg_expression_sub_string_literal
;

typedef struct rtg_expression_sub_natural_literal {

	natural * natural_literal_;
} rtg_expression_sub_natural_literal
;

typedef struct rtg_expression_sub_identifier {

	amara_string * identifier_;
} rtg_expression_sub_identifier
;

typedef struct rtg_expression_sub_dice {

	natural * left_hand_side_natural_;

	natural * right_hand_side_natural_;
} rtg_expression_sub_dice
;

/*   This is an enumeration. */

#define RTG_EXPRESSION_TYPE_INVALID             0x00
#define RTG_EXPRESSION_TYPE_STRING_LITERAL      0x01
/* #define RTG_EXPRESSION_TYPE_BOOLEAN_LITERAL  0x02 */
#define RTG_EXPRESSION_TYPE_NATURAL_LITERAL     0x03  /* A.K.A. EOM, ETX, ^C, '\x03', End of Text. */
/* #define RTG_EXPRESSION_TYPE_INTEGER_LITERAL  0x04 */
/* #define RTG_EXPRESSION_TYPE_RATIONAL_LITERAL 0x05 */
#define RTG_EXPRESSION_TYPE_IDENTIFIER          0x06  /* A.K.A. RU, ACK, ^F, '\x06', Acknowledgement. */
#define RTG_EXPRESSION_TYPE_CONDITIONAL         0x07  /* A.K.A. BELL, BEL, ^G, '\a', Bell. */
/* #define RTG_EXPRESSION_TYPE_ADDITION         0x08 */
/* #define RTG_EXPRESSION_TYPE_SUBSTRACTION     0x09 */
/* #define RTG_EXPRESSION_TYPE_MULTIPLICATION   0x0A */
/* #define RTG_EXPRESSION_TYPE_DIVISION         0x0B */
/* #define RTG_EXPRESSION_TYPE_EXPONENTIATION   0x0C */
#define RTG_EXPRESSION_TYPE_DICE                0x0D  /* A.K.A. CR, ^M, '\r', Carriage Return. */

typedef struct rtg_expression {

	unsigned char type_;

	rtg_expression_sub_string_literal * sub_string_literal_;

	rtg_expression_sub_natural_literal * sub_natural_literal_;

	rtg_expression_sub_identifier * sub_identifier_;

	struct rtg_expression_sub_conditional * sub_conditional_;

	rtg_expression_sub_dice * sub_dice_;
} rtg_expression
;

/**  Run time graph _where_ value name to expression bind. */
typedef struct rtg_where_value_binding {

	/**  Run time graph _where_ value: name. */
	amara_string * value_name_;

	/**  Run time graph _where_ value: expression bound. */
	rtg_expression * value_expression_;
} rtg_where_value_binding
;

/**  List of run time _where_ values names and value bindings. */
typedef struct rtg_where_value_bindings_simple_list {

	rtg_where_value_binding * first;

	struct rtg_where_value_bindings_simple_list * next;
} rtg_where_value_bindings_simple_list
;

typedef struct rtg_named_function {

	unsigned char type_;

	amara_string * name_;

	rtg_operations_simple_list * operations_;

	rtg_where_value_bindings_simple_list * where_value_bindings_;
} rtg_named_function
;

typedef struct rtg_named_functions_simple_list {

	rtg_named_function * first;

	struct rtg_named_functions_simple_list * next;
} rtg_named_functions_simple_list
;

#endif
