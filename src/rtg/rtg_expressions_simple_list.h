/*
 * Copyright 2019 Mercedes Catherine Salazar
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
 * src/rtg/rtg_expressions_simple_list.h: Amara run time graph
 * expressions simple list.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__EXPRESSIONS_SIMPLE_LIST__H__
#define __AMARA__RUN_TIME_GRAPH__EXPRESSIONS_SIMPLE_LIST__H__

#include "../stt/stt_expressions_simple_list.h"

typedef struct rtg_expressions_simple_list {

	struct rtg_expression * first;

	struct rtg_expressions_simple_list * next;
} rtg_expressions_simple_list
;

/**  Destructor. */
void
rtg_expressions_simple_list_destructor(
		rtg_expressions_simple_list * expressions)
;

/**  Transformation constructor. */
rtg_expressions_simple_list *
rtg_expressions_simple_list_out_of_stt_expressions_simple_list(
		const stt_expressions_simple_list * stt_expressions,
		const rtg_named_functions_simple_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

#endif
