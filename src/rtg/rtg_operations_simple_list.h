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
 * src/rtg/rtg_operations_simple_list.h: Amara runtime graph application
 * function operations simple list.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__OPERATIONS_SIMPLE_LIST__H__
#define __AMARA__RUN_TIME_GRAPH__OPERATIONS_SIMPLE_LIST__H__

/*   For `rtg_operation`. */
#include "rtg_operation.h"

typedef struct rtg_operations_simple_list {
	rtg_operation * first;
	struct rtg_operations_simple_list * next;
} rtg_operations_simple_list;

rtg_operations_simple_list *
rtg_operations_simple_list_copy_constructor(rtg_operations_simple_list * list)
__attribute__((warn_unused_result))
;

#endif
