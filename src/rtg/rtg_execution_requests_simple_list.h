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
 * src/rtg/rtg_execution_requests_simple_list.h: Amara run time graph
 * application execution requests simple list.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__EXECUTION_REQUESTS_SIMPLE_LIST__H__
#define __AMARA__RUN_TIME_GRAPH__EXECUTION_REQUESTS_SIMPLE_LIST__H__

/*   For `stt_doc_subnode`. */
#include "../stt/stt_doc_subnode.h"

/*   For `stt_execution_requests_simple_list`. */
#include "../stt/stt_execution_requests_simple_list.h"

/*   For `rtg_applications_simple_list`. */
#include "rtg_applications_simple_list.h"

/*   For `rtg_execution_request`. */
#include "rtg_execution_request.h"

typedef struct rtg_execution_requests_simple_list {
	rtg_execution_request * first;
	struct rtg_execution_requests_simple_list * next;
} rtg_execution_requests_simple_list;

rtg_execution_requests_simple_list *
rtg_execution_requests_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_execution_requests_simple_list *
rtg_execution_requests_simple_list_copy_constructor(
		const rtg_execution_requests_simple_list * list)
__attribute__((warn_unused_result))
;

void
rtg_execution_requests_simple_list_destructor(
		rtg_execution_requests_simple_list * list)
;

rtg_execution_requests_simple_list *
rtg_execution_requests_simple_list_push_front(
		rtg_execution_requests_simple_list * execution_requests,
		const rtg_execution_request * execution_request)
__attribute__((warn_unused_result))
;

#define RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_INVALID 0x00
#define RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret {
	uint_fast8_t status;
	rtg_execution_requests_simple_list * execution_requests;
} rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret;

/*
void
rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret_destructor(
		rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret * rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret_)
;
*/

rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret *
rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list(
		const stt_execution_requests_simple_list * stt_execution_requests,
		const rtg_applications_simple_list * rtg_applications)
__attribute__((warn_unused_result))
;

#define RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_INVALID 0x00
#define RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret {
	uint_fast8_t status;
	rtg_execution_requests_simple_list * execution_requests;
	amara_boolean execution_requests_were_moved;
} rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret;

void
rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_destructor(
		rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret * rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_)
;

rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret *
rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list(
		const stt_doc_subnode * subnode,
		const rtg_applications_simple_list * applications)
__attribute__((warn_unused_result))
;

#endif
