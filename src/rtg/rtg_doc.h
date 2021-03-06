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
 * src/rtg/rtg_doc.h: Amara run time graph document.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__DOC__H__
#define __AMARA__RUN_TIME_GRAPH__DOC__H__

/*   For `stt_node`. */
#include "../stt/stt_node.h"

/*   For `rtg_named_functions_simple_list`. */
#include "rtg_named_functions_simple_list.h"

/*   For `rtg_applications_simple_list`. */
#include "rtg_applications_simple_list.h"

/*   For `rtg_execution_requests_simple_list`. */
#include "rtg_execution_requests_simple_list.h"

/**  @see stt_doc_subnode. */
typedef struct rtg_doc {

	/**  @see stt_named_functions_simple_list. */
	rtg_named_functions_simple_list * functions_;

	rtg_applications_simple_list * applications_;

	rtg_execution_requests_simple_list * execution_requests_;
} rtg_doc;

rtg_doc *
rtg_doc_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_doc *
rtg_doc_exhaustive_constructor(
		rtg_named_functions_simple_list * named_functions,
		rtg_applications_simple_list * applications,
		rtg_execution_requests_simple_list * execution_requests)
__attribute__((warn_unused_result))
;

void
rtg_doc_destructor(rtg_doc * doc)
;

#define RTG_DOC_OUT_OF_STT_DOC_RET_STATUS_INVALID 0x00
#define RTG_DOC_OUT_OF_STT_DOC_RET_STATUS_SUCCESS          0x0F
#define RTG_DOC_OUT_OF_STT_DOC_RET_STATUS_ERROR_ONE_OR_MORE_APPLICATIONS_REQUESTED_TO_BE_EXECUTED_NOT_FOUND 0x0A
#define RTG_DOC_OUT_OF_STT_DOC_RET_STATUS_ERROR_UNSPECIFIC 0xF0

typedef struct rtg_doc_out_of_stt_doc_ret {

	unsigned char status;

	amara_strings_simple_list * error_messages;

	rtg_doc * doc;
} rtg_doc_out_of_stt_doc_ret
;

void
rtg_doc_out_of_stt_doc_ret_destructor(
		rtg_doc_out_of_stt_doc_ret * rtg_doc_out_of_stt_doc_ret_)
;

rtg_doc_out_of_stt_doc_ret *
rtg_doc_out_of_stt_doc(const stt_node * node)
__attribute__((warn_unused_result))
;

#endif
