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
 * src/rtg/rtg_where_value_binding.h: Amara run time graph _where_ value
 * binding.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__WHERE_VALUE_BINDING__H__
#define __AMARA__RUN_TIME_GRAPH__WHERE_VALUE_BINDING__H__

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   For `stt_where_value_binding`. */
#include "../stt/stt_where_value_binding.h"

/*   For `rtg_expression`. */
#include "rtg_expression.h"

/**  Copy constructor. */
rtg_where_value_binding *
rtg_where_value_binding_copy_constructor(
		const rtg_where_value_binding * where_value_binding_)
__attribute__((warn_unused_result))
;

/**  Destructor. */
void
rtg_where_value_binding_destructor(
		rtg_where_value_binding * where_value_binding_)
;

#ifndef NDEBUG

/**  Health check. */
void
rtg_where_value_binding_assert_healthy(
		const rtg_where_value_binding * where_value_binding_)
;

#endif

typedef unsigned char rtg_where_value_binding_out_of_stt_where_value_binding_ret_status;

#define RTG_WHERE_VALUE_BINDING_OUT_OF_STT_WHERE_VALUE_BINDING_RET_STATUS_SUCCESS (rtg_where_value_binding_out_of_stt_where_value_binding_ret_status) 0x55

typedef struct rtg_where_value_binding_out_of_stt_where_value_binding_ret {

	rtg_where_value_binding_out_of_stt_where_value_binding_ret_status status;

	amara_string * error_messages;

	rtg_where_value_binding * where_value_binding;
} rtg_where_value_binding_out_of_stt_where_value_binding_ret
;

/**  Transformation constructor. */
rtg_where_value_binding_out_of_stt_where_value_binding_ret *
rtg_where_value_binding_out_of_stt_where_value_binding(
		const stt_where_value_binding * where_value_binding_)
__attribute__((warn_unused_result))
;

#endif
