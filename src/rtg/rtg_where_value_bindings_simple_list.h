/*
 * Copyright 2018, 2020 Mercedes Catherine Salazar
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

/*   For `__amara__warn_unused_result__`. */
#include "../definitions.h"

/*   For `stt_where_value_bindings_simple_list`. */
#include "../stt/stt_where_value_bindings_simple_list.h"

/*   For `rtg_where_value_binding`. */
#include "rtg_where_value_binding.h"

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

typedef unsigned char rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_ret_status;

#define RTG_WHERE_VALUE_BINDINGS_SIMPLE_LIST_OUT_OF_STT_WHERE_VALUE_BINDINGS_SIMPLE_LIST_RET_STATUS_SUCCESS 0x55

/**  TODO. */
typedef struct rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_ret {

    /**  Return status. */
    rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_ret_status status;

    /**  Error messages. */
    amara_string * error_messages;

    /**  The returned list. */
    rtg_where_value_bindings_simple_list * where_value_bindings;
} rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_ret
;

void
rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_ret_destructor(
		rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_ret * input_ret)
;

/**  Transformation constructor (legacy code, particular case: there are
 * no RTG named functions known yet). */
rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_ret *
rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list(
		const stt_where_value_bindings_simple_list * list)
__amara__warn_unused_result__
;

typedef unsigned char rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_and_rtg_named_functions_ret_status;

/*
#define RTG_WHERE_VALUE_BINDINGS_SIMPLE_LIST_OUT_OF_STT_WHERE_VALUE_BINDINGS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_RET_STATUS_INVALID 0x00
 */
#define RTG_WHERE_VALUE_BINDINGS_SIMPLE_LIST_OUT_OF_STT_WHERE_VALUE_BINDINGS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_RET_STATUS_SUCCESS 0x55
/*
#define RTG_WHERE_VALUE_BINDINGS_SIMPLE_LIST_OUT_OF_STT_WHERE_VALUE_BINDINGS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_RET_STATUS_ERROR (unsigned char) 0xFF
*/

/**  TODO. */
typedef struct rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_and_rtg_named_functions_ret {

	/**  Return status. */
	rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_and_rtg_named_functions_ret_status status;

	/**  Error messages. */
	amara_string * error_messages;

	/**  The returned list. */
	rtg_where_value_bindings_simple_list * where_value_bindings;
} rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_and_rtg_named_functions_ret
;

/**  Transformation constructor (general case). */
rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_and_rtg_named_functions_ret *
rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_and_rtg_named_functions(
		const stt_where_value_bindings_simple_list * list,
		const rtg_named_functions_simple_list * rtg_named_functions)
__amara__warn_unused_result__
;

#endif
