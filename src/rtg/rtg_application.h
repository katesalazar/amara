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
 * src/rtg/rtg_application.h: Amara run time graph application.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__APPLICATION__H__
#define __AMARA__RUN_TIME_GRAPH__APPLICATION__H__

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   For `stt_application`. */
#include "../stt/stt_application.h"

/*   For `rtg_function`. */
#include "rtg_function.h"

/*   For `rtg_functions_simple_list`. */
#include "rtg_functions_simple_list.h"

#define RTG_APPLICATION_TYPE_INVALID 0x00

typedef struct rtg_application {
	uint_fast8_t type_;
	amara_string * name_;
	rtg_function * entry_point_function_;
} rtg_application;

rtg_application *
rtg_application_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_application *
rtg_application_copy_constructor(const rtg_application * application)
__attribute__((warn_unused_result))
;

void
rtg_application_destructor(rtg_application * application)
;

#define RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID 0x00
#define RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x00
#define RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_application_out_of_stt_application_and_rtg_functions_simple_list_ret {
	uint_fast8_t status;
	rtg_application * application;
	amara_boolean application_was_moved;
} rtg_application_out_of_stt_application_and_rtg_functions_simple_list_ret;

void
rtg_application_out_of_stt_application_and_rtg_functions_simple_list_ret_destructor(
		rtg_application_out_of_stt_application_and_rtg_functions_simple_list_ret * rtg_application_out_of_stt_application_and_rtg_functions_simple_list_ret_)
;

rtg_application_out_of_stt_application_and_rtg_functions_simple_list_ret *
rtg_application_out_of_stt_application_and_rtg_functions_simple_list(
		const stt_application * application,
		const rtg_functions_simple_list * functions)
__attribute__((warn_unused_result))
;

#endif
