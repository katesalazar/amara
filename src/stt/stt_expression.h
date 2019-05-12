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
 * src/stt/stt_expression.h: Amara syntax tree expression.
 */

#ifndef __AMARA__SYNTAX_TREE__EXPRESSION__H__
#define __AMARA__SYNTAX_TREE__EXPRESSION__H__

/*   For `typedef struct stt_dice_expression { ... }
 * stt_dice_expression`. */
#include "stt_forward_declarations.h"

/*   For `typedef struct stt_expression_sub_conditional { ... }
 * stt_expression_sub_conditional`. */
#include "stt_expression_sub_conditional.h"

/*   For `typedef struct stt_expression_sub_dice { ... }
 * stt_expression_sub_dice`. */
#include "stt_expression_sub_dice.h"

/*   For `typedef struct stt_expression_sub_identifier { ... }
 * stt_expression_sub_identifier`. */
#include "stt_expression_sub_identifier.h"

/*   For `typedef struct stt_expression_sub_natural_literal { ... }
 * stt_expression_sub_natural_literal`. */
#include "stt_expression_sub_natural_literal.h"

/*   For `typedef struct stt_expression_sub_string_literal { ... }
 * stt_expression_sub_string_literal`. */
#include "stt_expression_sub_string_literal.h"

#include "stt_expression_sub_function_call.h"

#define STT_EXPRESSION_TYPE_INVALID             0x00
#define STT_EXPRESSION_TYPE_STRING_LITERAL      0x01
/* #define STT_EXPRESSION_TYPE_BOOLEAN_LITERAL  0x02 */
#define STT_EXPRESSION_TYPE_NATURAL_LITERAL     0x03
/* #define STT_EXPRESSION_TYPE_INTEGER_LITERAL  0x04 */
/* #define STT_EXPRESSION_TYPE_RATIONAL_LITERAL 0x05 */
#define STT_EXPRESSION_TYPE_IDENTIFIER          0x06
#define STT_EXPRESSION_TYPE_CONDITIONAL         0x07
/* #define STT_EXPRESSION_TYPE_ADDITION         0x08 */
/* #define STT_EXPRESSION_TYPE_SUBSTRACTION     0x09 */
/* #define STT_EXPRESSION_TYPE_MULTIPLICATION   0x0A */
/* #define STT_EXPRESSION_TYPE_DIVISION         0x0B */
/* #define STT_EXPRESSION_TYPE_EXPONENTIATION   0x0C */
#define STT_EXPRESSION_TYPE_DICE                0x0D
#define STT_EXPRESSION_TYPE_FUNCTION_CALL       0x0E

typedef struct stt_expression {

	unsigned char type_;

	stt_expression_sub_string_literal * sub_string_literal_;

	stt_expression_sub_natural_literal * sub_natural_literal_;

	stt_expression_sub_identifier * sub_identifier_;

	struct stt_expression_sub_conditional * sub_conditional_;

	stt_expression_sub_dice * sub_dice_;

	struct stt_expression_sub_function_call * sub_function_call_;
} stt_expression
;

stt_expression *
stt_expression_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_expression *
stt_expression_copy_constructor(const stt_expression * expression)
__attribute__((warn_unused_result))
;

void
stt_expression_destructor(stt_expression * expression)
;

void
stt_expression_set_string_literal(
		stt_expression * expression,
		const amara_string * string_literal)
;

void
stt_expression_set_natural_literal(
		stt_expression * expression, const natural * natural_literal)
;

void
stt_expression_set_identifier(
		stt_expression * expression, const amara_string * identifier)
;

void
stt_expression_set_conditional(
		stt_expression * expression,
		const struct stt_expression_sub_conditional * expression_sub_conditional)
;

void
stt_expression_set_function_call(
		stt_expression * expression,
		const struct stt_expression_sub_function_call * sub_function_call)
;

/**  FIXME MUST CHANGE IN ORDER TO RECEIVE AN stt_expression_sub_dice */
void
stt_expression_set_dice(stt_expression * expression,
                        const stt_dice_expression * dice_expression)
;

amara_boolean
stt_expression_equality(const stt_expression * e0, const stt_expression * e1)
__attribute__((warn_unused_result))
;

amara_boolean
stt_expressions_equality(const stt_expression * e0, const stt_expression * e1)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
stt_expression_assert_clean_string_literal(const stt_expression * this)
;

void
stt_expression_assert_clean_natural_literal(const stt_expression * this)
;

void
stt_expression_assert_clean_identifier(const stt_expression * this)
;

void
stt_expression_assert_clean_conditional(const stt_expression * this)
;

void
stt_expression_assert_clean_function_call(const stt_expression * this)
;

void
stt_expression_assert_clean_dice(const stt_expression * this)
;

void
stt_expression_assert_cleanliness(const stt_expression * this)
;

#endif  /* NDEBUG */

#endif  /* __AMARA__SYNTAX_TREE__EXPRESSION__H__ */
