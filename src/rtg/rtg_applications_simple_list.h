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
 * src/rtg/rtg_applications_simple_list.h: Amara run time graph
 * applications simple list.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__APPLICATIONS_SIMPLE_LIST__H__
#define __AMARA__RUN_TIME_GRAPH__APPLICATIONS_SIMPLE_LIST__H__

/*   For `stt_applications_simple_list`. */
#include "../stt/stt_applications_simple_list.h"

/*   For `rtg_application`. */
#include "rtg_application.h"

typedef struct rtg_applications_simple_list {
	rtg_application * first;
	struct rtg_applications_simple_list * next;
} rtg_applications_simple_list;

rtg_applications_simple_list *
rtg_applications_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_applications_simple_list *
rtg_applications_simple_list_copy_constructor(
		const rtg_applications_simple_list * list)
__attribute__((warn_unused_result))
;

void
rtg_applications_simple_list_destructor(
		rtg_applications_simple_list * list)
;

rtg_applications_simple_list *
rtg_applications_simple_list_push_front(
		rtg_applications_simple_list * applications,
		const rtg_application * application)
__attribute__((warn_unused_result))
;

#define RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_INVALID   0x00
#define RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS   0x0F
#define RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND 0xF0

typedef struct rtg_applications_simple_list_find_by_name_ret {
	unsigned char status;
	rtg_application * application;
	amara_boolean application_was_moved;
} rtg_applications_simple_list_find_by_name_ret;

void
rtg_applications_simple_list_find_by_name_ret_destructor(
		rtg_applications_simple_list_find_by_name_ret * input_ret)
;

rtg_applications_simple_list_find_by_name_ret *
rtg_applications_simple_list_find_by_name(
		const rtg_applications_simple_list * haystack,
		const amara_string * needle)
__attribute__((warn_unused_result))
;

#define RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID          0x00
#define RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS          0xFF

typedef struct rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret {
	unsigned char status;
	rtg_applications_simple_list * applications;
} rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret;

rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret *
rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list(
		const stt_applications_simple_list * stt_applications,
		const rtg_named_functions_simple_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

#define RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID 0x00
#define RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret {
	unsigned char status;
	rtg_applications_simple_list * applications;
	amara_boolean applications_were_moved;
} rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret;

void
rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_destructor(
		rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * input_ret)
;

rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret *
rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list(
		const stt_doc_subnode * subnode,
		const rtg_named_functions_simple_list * named_functions)
__attribute__((warn_unused_result))
;

#endif
