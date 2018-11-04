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
 * src/stt/stt_dice_expression.h: Amara syntax tree dice expression.
 */

#ifndef __AMARA__SYNTAX_TREE__DICE_EXPRESSION__H__
#define __AMARA__SYNTAX_TREE__DICE_EXPRESSION__H__

#include "stt_forward_declarations.h"

#include "../brt/natural.h"

/**  FIXME REMOVE THIS */
stt_dice_expression *
stt_dice_expression_exhaustive_constructor(
		const struct natural * left_hand_side,
		const struct natural * right_hand_side)
__attribute__((warn_unused_result))
;

/**  FIXME REMOVE THIS */
void
stt_dice_expression_destructor(stt_dice_expression * dice_expression)
;

#endif
