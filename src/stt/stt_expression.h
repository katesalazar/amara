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
 * stt_dice_expression;`. */
#include "stt_forward_declarations.h"

/*   For `typedef struct stt_expression_sub_dice { ... }
 * stt_expression_sub_dice;`. */
#include "stt_expression_sub_dice.h"

#define STT_EXPRESSION_TYPE_INVALID        0x00
#define STT_EXPRESSION_TYPE_IF_THEN_ELSE   0x01
#define STT_EXPRESSION_TYPE_ADDITION       0x02
#define STT_EXPRESSION_TYPE_SUBSTRACTION   0x03
#define STT_EXPRESSION_TYPE_MULTIPLICATION 0x04
#define STT_EXPRESSION_TYPE_DIVISION       0x05
#define STT_EXPRESSION_TYPE_DICE           0x06

typedef struct stt_expression {
	unsigned char type_;
	stt_expression_sub_dice * sub_dice_;
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
stt_expression_set_dice(stt_expression * expression,
                        const stt_dice_expression * dice_expression)
;

void
stt_expression_destructor(stt_expression * expression)
;

#endif
