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
 * src/stt/stt_expression_sub_dice.h: Amara syntax tree dice type of
 * expression.
 */

#ifndef __AMARA__SYNTAX_TREE__EXPRESSION_SUB_DICE__H__
#define __AMARA__SYNTAX_TREE__EXPRESSION_SUB_DICE__H__

/*   For `typedef struct natural { ... } natural;`. */
#include "../brt/brt_forward_declarations.h"

typedef struct stt_expression_sub_dice {

	natural * left_hand_side_natural_;

	natural * right_hand_side_natural_;
} stt_expression_sub_dice
;

stt_expression_sub_dice *
stt_expression_sub_dice_exhaustive_constructor(
		const natural * left_hand_side,
		const natural * right_hand_side)
__attribute__((warn_unused_result))
;

stt_expression_sub_dice *
stt_expression_sub_dice_copy_constructor(
		const stt_expression_sub_dice * expression_sub_dice)
__attribute__((warn_unused_result))
;

void
stt_expression_sub_dice_destructor(
		stt_expression_sub_dice * stt_expression_sub_dice_)
;

amara_boolean
stt_expression_sub_dice_equality(
		const stt_expression_sub_dice * esd0,
		const stt_expression_sub_dice * esd1)
__attribute__((warn_unused_result))
;

amara_boolean
stt_expression_sub_dices_equality(
		const stt_expression_sub_dice * esd0,
		const stt_expression_sub_dice * esd1)
__attribute__((warn_unused_result))
;

#endif
