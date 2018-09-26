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
 * src/stt/stt_doc_subnode.h: Amara syntax tree document subnode.
 */

#ifndef __AMARA__SYNTAX_TREE__DOC_SUBNODE__H__
#define __AMARA__SYNTAX_TREE__DOC_SUBNODE__H__

/*   For `rtg_functions_simple_list`. */
#include "../rtg/rtg_functions_simple_list.h"

/*   For `rtg_applications_simple_list`. */
#include "../rtg/rtg_applications_simple_list.h"

/*   For `rtg_execution_requests_simple_list`. */
#include "../rtg/rtg_execution_requests_simple_list.h"

/*   For `stt_functions_simple_list`. */
#include "stt_functions_simple_list.h"

/*   For `stt_applications_simple_list`. */
#include "stt_applications_simple_list.h"

/*   For `stt_execution_requests_simple_list`. */
#include "stt_execution_requests_simple_list.h"

typedef struct stt_doc_subnode {
	stt_functions_simple_list * functions_;
	stt_applications_simple_list * applications_;
	stt_execution_requests_simple_list * execution_requests_;
} stt_doc_subnode;

stt_doc_subnode *
stt_doc_subnode_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_doc_subnode *
stt_doc_subnode_copy_constructor(const stt_doc_subnode * subnode)
__attribute__((warn_unused_result))
;

void
stt_doc_subnode_destructor(stt_doc_subnode * subnode)
;

#define RTG_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_INVALID 0x00
#define RTG_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_functions_out_of_stt_doc_ret {
	uint_fast8_t status;
	rtg_functions_simple_list * functions;
	amara_boolean functions_were_moved;
} rtg_functions_out_of_stt_doc_ret;

void
rtg_functions_out_of_stt_doc_ret_destructor(
		rtg_functions_out_of_stt_doc_ret * rtg_functions_out_of_stt_doc_ret_)
;

rtg_functions_out_of_stt_doc_ret *
rtg_functions_out_of_stt_doc(const stt_doc_subnode * subnode)
__attribute__((warn_unused_result))
;

#define RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID 0x00
#define RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list_ret {
	uint_fast8_t status;
	rtg_applications_simple_list * applications;
	amara_boolean applications_were_moved;
} rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list_ret;

void
rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list_ret_destructor(
		rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list_ret * rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list_ret_)
;

rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list_ret *
rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list(
		const stt_doc_subnode * subnode,
		const rtg_functions_simple_list * functions)
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
