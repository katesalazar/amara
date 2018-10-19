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
 * src/stt/stt_condition.h: Amara syntax tree condition.
 */

#ifndef __AMARA__SYNTAX_TREE__CONDITION__H__
#define __AMARA__SYNTAX_TREE__CONDITION__H__

#include "stt_expression.h"

typedef struct stt_condition {
	unsigned char type_;
	stt_expression * left_hand_side_expression_;
	stt_expression * right_hand_side_expression_;
} stt_condition
;

#endif
