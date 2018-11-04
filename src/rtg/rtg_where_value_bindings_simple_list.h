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
 * src/rtg/rtg_where_value_bindings_simple_list.h: Amara run time graph
 * _where_ value bindings simple list.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__WHERE_VALUE_BINDINGS_SIMPLE_LIST__H__
#define __AMARA__RUN_TIME_GRAPH__WHERE_VALUE_BINDINGS_SIMPLE_LIST__H__

/*   For `stt_where_value_bindings_simple_list`. */
#include "../stt/stt_where_value_bindings_simple_list.h"

/*   For `rtg_where_value_binding`. */
#include "rtg_where_value_binding.h"

/**  List of run time _where_ values names and value bindings. */
typedef struct rtg_where_value_bindings_simple_list {
	rtg_where_value_binding * first;
	struct rtg_where_value_bindings_simple_list * next;
} rtg_where_value_bindings_simple_list
;

/**  Default constructor. */
rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

/**  Copy constructor. */
rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_copy_constructor(
         const rtg_where_value_bindings_simple_list * list)
__attribute__((warn_unused_result))
;

/**  Destructor. */
void
rtg_where_value_bindings_simple_list_destructor(
		rtg_where_value_bindings_simple_list * list)
;

#ifndef NDEBUG

/**  Health check. */
void
rtg_where_value_bindings_simple_list_assert_healthy(
		const rtg_where_value_bindings_simple_list * list)
;

#endif

/**  Push front. */
rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_push_front(
		rtg_where_value_bindings_simple_list * list,
		const rtg_where_value_binding * element)
__attribute__((warn_unused_result))
;

/**  Transformation constructor. */
rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list(
		stt_where_value_bindings_simple_list * list)
__attribute__((warn_unused_result))
;

#endif
