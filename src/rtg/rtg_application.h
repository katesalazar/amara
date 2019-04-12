/*
 * Copyright 2018-2019 Mercedes Catherine Salazar
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

/*   For `rtg_named_function`. */
#include "rtg_named_function.h"

/*   For `rtg_named_functions_simple_list`. */
#include "rtg_named_functions_simple_list.h"

#define RTG_APPLICATION_TYPE_INVALID 0x00
#define RTG_APPLICATION_TYPE_CLI_APPLICATION 0xFF

typedef struct rtg_application {

	unsigned char type_;

	amara_string * name_;

	rtg_named_function * entry_point_function_;
} rtg_application
;

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

#define RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID 0x00
#define RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_FIND_ENTRY_POINT_FUNCTION_FOR_APPLICATION 0x0E
#define RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret {

	unsigned char status;

	amara_strings_simple_list * error_messages;

	rtg_application * application;
} rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret
;

void
rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret_destructor(
		rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret * input_ret)
;

rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret *
rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list(
		const stt_application * application,
		const rtg_named_functions_simple_list * named_functions)
__attribute__((warn_unused_result))
;

#endif
