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
 * src/rtg/rtg_expression.h: Amara run time graph expression.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__EXPRESSION__H__
#define __AMARA__RUN_TIME_GRAPH__EXPRESSION__H__

/*   For `stt_expression`. */
#include "../stt/stt_expression.h"

/*   For `rtg_expression_sub_conditional`. */
#include "rtg_expression_sub_conditional.h"

/*   For `rtg_expression_sub_dice`. */
#include "rtg_expression_sub_dice.h"

#include "rtg_expression_sub_function_call.h"

/*   For `rtg_expression_sub_identifier`. */
#include "rtg_expression_sub_identifier.h"

/*   For `rtg_expression_sub_natural_literal`. */
#include "rtg_expression_sub_natural_literal.h"

/*   For `rtg_expression_sub_string_literal`. */
#include "rtg_expression_sub_string_literal.h"

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
#define RTG_EXPRESSION_TYPE_FUNCTION_CALL       0x0E
#define RTG_EXPRESSION_TYPE_DICE                0x0D  /* A.K.A. CR, ^M, '\r', Carriage Return. */

typedef struct rtg_expression {

	unsigned char type_;

	rtg_expression_sub_string_literal * sub_string_literal_;

	rtg_expression_sub_natural_literal * sub_natural_literal_;

	rtg_expression_sub_identifier * sub_identifier_;

	struct rtg_expression_sub_conditional * sub_conditional_;

	struct rtg_expression_sub_function_call * sub_function_call_;

	rtg_expression_sub_dice * sub_dice_;
} rtg_expression
;

/**  Default constructor. */
rtg_expression *
rtg_expression_default_constructor(void)
__attribute__((warn_unused_result))
;

/**  Copy constructor. */
rtg_expression *
rtg_expression_copy_constructor(const rtg_expression * expression)
__attribute__((warn_unused_result))
;

/**  Destructor. */
void
rtg_expression_destructor(rtg_expression * expression)
;

/**  Setter. */
void
rtg_expression_set_identifier(
		rtg_expression * expression, const amara_string * identifier)
;

#ifndef NDEBUG

/**  Health check. */
void
rtg_expression_assert_healthy(const rtg_expression * expression)
;

#endif

/**  Equality. */
amara_boolean
rtg_expression_equality(const rtg_expression * e0, const rtg_expression * e1)
__attribute__((warn_unused_result))
;

/*   This is an enumeration. */

#define RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_INVALID 0x00
#define RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_expression_out_of_stt_expression_ret {

	unsigned char status;

	rtg_expression * expression;
} rtg_expression_out_of_stt_expression_ret
;

void
rtg_expression_out_of_stt_expression_ret_destructor(
		rtg_expression_out_of_stt_expression_ret * input_ret_)
;

/**  Transformation constructor with rich return type. */
rtg_expression_out_of_stt_expression_ret *
rtg_expression_out_of_stt_expression(
		const stt_expression * expression,
		const rtg_named_functions_simple_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
rtg_expression_assert_validity(const rtg_expression * expression)
;

#endif

#endif
