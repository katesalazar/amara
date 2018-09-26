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
 * src/rtg/rtg_execution_request.h: Amara run time graph application
 * execution request.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__EXECUTION_REQUEST__H__
#define __AMARA__RUN_TIME_GRAPH__EXECUTION_REQUEST__H__

/*   For `rtg_application`. */
#include "rtg_application.h"

/*   For `rtg_applications_simple_list`. */
#include "rtg_applications_simple_list.h"

#define RTG_EXECUTION_REQUEST_TYPE_INVALID         0x00
#define RTG_EXECUTION_REQUEST_TYPE_CLI_APPLICATION 0xFF

typedef struct rtg_execution_request {
	uint_fast8_t type_;
	/*   Postponed execution requests of functions and operations. */
	/*
	rtg_operation * operation_;
	rtg_function * function_;
	*/
	rtg_application * application_;
} rtg_execution_request;

rtg_execution_request *
rtg_execution_request_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_execution_request *
rtg_execution_request_copy_constructor(
		const rtg_execution_request * execution_request)
__attribute__((warn_unused_result))
;

void
rtg_execution_request_destructor(
		rtg_execution_request * execution_request)
;

#define RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_INVALID 0x00
#define RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret {
	uint_fast8_t status;
	rtg_execution_request * execution_request;
	amara_boolean execution_request_was_moved;
} rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret;

void
rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_destructor(
		rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret * rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_)
;

rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret *
rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list(
		const stt_execution_request * execution_request,
		const rtg_applications_simple_list * applications)
__attribute__((warn_unused_result))
;

#endif
