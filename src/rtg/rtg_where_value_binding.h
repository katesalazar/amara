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

/**  Run time graph _where_ value name to expression bind. */
typedef struct rtg_where_value_binding {

	/**  Run time graph _where_ value: name. */
	amara_string * value_name_;

	/**  Run time graph _where_ value: expression bound. */
	rtg_expression * value_expression_;
} rtg_where_value_binding
;

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

/**  Transformation constructor. */
rtg_where_value_binding *
rtg_where_value_binding_out_of_stt_where_value_binding(
		const stt_where_value_binding * where_value_binding_)
__attribute__((warn_unused_result))
;

#endif
