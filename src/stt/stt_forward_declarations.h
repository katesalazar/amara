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
 * src/stt/stt_forward_declarations.h: Some Amara syntax tree type
 * forward declarations.
 */

#ifndef __AMARA__SYNTAX_TREE__FORWARD_DECLARATIONS__H__
#define __AMARA__SYNTAX_TREE__FORWARD_DECLARATIONS__H__

/**  This belongs to `stt_dice_expression.h`. */
typedef struct stt_dice_expression {
	struct natural * left_hand_side_natural_;
	struct natural * right_hand_side_natural_;
} stt_dice_expression
;

#endif
