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
 * src/rtg/rtg_execution_requests_simple_list.c: Amara run time graph
 * application execution requests simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "rtg_execution_requests_simple_list.h"

rtg_execution_requests_simple_list *
rtg_execution_requests_simple_list_default_constructor()
{
	rtg_execution_requests_simple_list * ret_;

	ret_ = malloc(sizeof(rtg_execution_requests_simple_list));
	forced_assertion(ret_ != NULL);
	ret_->first = NULL;
	ret_->next = NULL;

	return ret_;
}

rtg_execution_requests_simple_list *
rtg_execution_requests_simple_list_copy_constructor(
		const rtg_execution_requests_simple_list * list)
{
	rtg_execution_requests_simple_list * ret_;
	const rtg_execution_requests_simple_list * list_ptr_;
	rtg_execution_requests_simple_list * ret_ptr_;
	rtg_execution_request * execution_request_;

	if (list == NULL) {
		return rtg_execution_requests_simple_list_default_constructor();
	}

	ret_ = malloc(sizeof(rtg_execution_requests_simple_list));
	forced_assertion(ret_ != NULL);
	if (list->first == NULL) {
		assertion(list->next == NULL);
		ret_->first = NULL;
		ret_->next = NULL;
		return ret_;
	}
	list_ptr_ = list;
	ret_ptr_ = ret_;
	while (list_ptr_->next != NULL) {
		execution_request_ = rtg_execution_request_copy_constructor(
				list_ptr_->first);
		assertion(execution_request_ != NULL);
		ret_ptr_->first = execution_request_;
		ret_ptr_->next = malloc(sizeof(
				rtg_execution_requests_simple_list));
		list_ptr_ = list_ptr_->next;
		ret_ptr_ = ret_ptr_->next;
	}
	execution_request_ = rtg_execution_request_copy_constructor(
			list_ptr_->first);
	assertion(execution_request_ != NULL);
	ret_ptr_->first = execution_request_;
	ret_ptr_->next = NULL;
	return ret_;
}

void
rtg_execution_requests_simple_list_destructor(
		rtg_execution_requests_simple_list * list)
{
	if (list == NULL) {
		return;
	}
	assertion(list != NULL);
	if (list->first == NULL) {
		assertion(list->next == NULL);
	} else {
		rtg_execution_request_destructor(list->first);
	}
	if (list->next != NULL) {
		rtg_execution_requests_simple_list_destructor(list->next);
	}
	free(list);
}

rtg_execution_requests_simple_list *
rtg_execution_requests_simple_list_push_front(
		rtg_execution_requests_simple_list * execution_requests,
		const rtg_execution_request * execution_request)
{
	rtg_execution_requests_simple_list * new_node_;
	assertion(execution_requests != NULL);
	if (execution_requests->first == NULL) {
		assertion(execution_requests->next == NULL);
		execution_requests->first =
				rtg_execution_request_copy_constructor(
						execution_request);
		return execution_requests;
	}
	new_node_ = malloc(sizeof(rtg_execution_requests_simple_list));
	new_node_->first = rtg_execution_request_copy_constructor(
			execution_request);
	new_node_->next = execution_requests;
	return new_node_;
}

rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret *
rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list(
		const stt_execution_requests_simple_list * stt_execution_requests,
		const rtg_applications_simple_list * rtg_applications)
{
	rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret * ret_;
	rtg_execution_requests_simple_list * sub_ret_;
	rtg_execution_requests_simple_list * sub_ret_ptr_;
	const stt_execution_requests_simple_list * stt_execution_requests_ptr_;
	rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret * sub_ret_execution_request_ret_;

	ret_ = malloc(sizeof(
			rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret));
	forced_assertion(ret_ != NULL);

	ret_->error_messages = NULL;
	ret_->status = RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_INVALID;

	if (stt_execution_requests == NULL ||
			stt_execution_requests->first == NULL) {

		if (stt_execution_requests != NULL) {

#ifndef NDEBUG
			assertion(stt_execution_requests->first == NULL);
			assertion(stt_execution_requests->next == NULL);
#endif
		}
		ret_->execution_requests =
				rtg_execution_requests_simple_list_default_constructor();
		ret_->error_messages = NULL;
		ret_->status = RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
		return ret_;
	}
	forced_assertion(stt_execution_requests->first != NULL);
	sub_ret_ = malloc(sizeof(rtg_execution_requests_simple_list));
	forced_assertion(sub_ret_ != NULL);
	sub_ret_execution_request_ret_ =
			rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list(
					stt_execution_requests->first,
					rtg_applications);
	assertion(sub_ret_execution_request_ret_ != NULL);
	if (sub_ret_execution_request_ret_->status ==
			RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_APPLICATION_NOT_FOUND) {

#ifndef NDEBUG
		assertion(ret_->error_messages == NULL);
#endif
		ret_->error_messages =
				sub_ret_execution_request_ret_->error_messages;
		ret_->status = RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_ONE_OR_MORE_APPLICATIONS_NOT_FOUND;
	} else {
	assertion(sub_ret_execution_request_ret_->status ==
			RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);

		;
	}
	sub_ret_->first = sub_ret_execution_request_ret_->execution_request;
	sub_ret_execution_request_ret_->execution_request = NULL;
	rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_destructor(
			sub_ret_execution_request_ret_);
	stt_execution_requests_ptr_ = stt_execution_requests;
	sub_ret_ptr_ = sub_ret_;
	while (stt_execution_requests_ptr_->next != NULL) {
		assertion(stt_execution_requests_ptr_->next->first != NULL);
		sub_ret_ptr_->next = malloc(sizeof(rtg_execution_requests_simple_list));
		forced_assertion(sub_ret_ptr_->next != NULL);
		sub_ret_execution_request_ret_ =
				rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list(
						stt_execution_requests_ptr_->next->first,
						rtg_applications);
		assertion(sub_ret_execution_request_ret_ != NULL);
		assertion(sub_ret_execution_request_ret_->status ==
				RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
		sub_ret_ptr_->next->first = sub_ret_execution_request_ret_->execution_request;
		sub_ret_execution_request_ret_->execution_request = NULL;
		rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_destructor(
				sub_ret_execution_request_ret_);
		stt_execution_requests_ptr_ = stt_execution_requests_ptr_->next;
		sub_ret_ptr_ = sub_ret_ptr_->next;
	}
	sub_ret_ptr_->next = NULL;
	ret_->execution_requests = sub_ret_;

	if (ret_->status ==
			RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_ONE_OR_MORE_APPLICATIONS_NOT_FOUND) {

		forced_assertion(ret_->error_messages != NULL);
	} else {
		forced_assertion(ret_->status ==
				RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_INVALID);

		forced_assertion(ret_->error_messages == NULL);
		ret_->status = RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
	}

	return ret_;
}

void
rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_destructor(
		rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret * rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_)
{
	forced_assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_ !=
			NULL);

	forced_assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->status ==
			RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);

	/*
	if (rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->status ==
			RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {
	*/

		forced_assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests ==
				NULL);

		/*
		if (rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests != NULL) {

			forced_assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests !=
					NULL);

			rtg_execution_requests_simple_list_destructor(
					rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests);
		}
		*/
	/*
	} else {
		forced_assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->status ==
				RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_INVALID);

		forced_assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests ==
				NULL);
	}
	*/

	free(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_);
}

rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret *
rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list(
		const stt_doc_subnode * subnode,
		const rtg_applications_simple_list * applications)
{
	rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret * ret_;
	rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret * sub_ret_;
	ret_ = malloc(sizeof(
			rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret));
	ret_->status = RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	ret_->execution_requests = NULL;
	sub_ret_ = rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list(
			subnode->execution_requests_, applications);
	if (sub_ret_->status ==
			RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

		ret_->status = RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
#ifndef NDEBUG
		assertion(sub_ret_->error_messages == NULL);
#endif
		ret_->error_messages = NULL;
		ret_->execution_requests = sub_ret_->execution_requests;
		sub_ret_->execution_requests = NULL;
	/*
	} else if (sub_ret_->status ==
				RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC) {

		ret_->status = RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC;
		forced_assertion(ret_->error_messages != NULL);
		ret_->error_messages = sub_ret_->error_messages;
		sub_ret_->error_messages = NULL;
#ifndef NDEBUG
		assertion(sub_ret_->execution_requests == NULL);
#endif
		ret_->execution_requests = NULL;
	*/
	} else {
		forced_assertion(sub_ret_->status ==
			RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_ONE_OR_MORE_APPLICATIONS_NOT_FOUND);

		ret_->status = RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_ONE_OR_MORE_APPLICATIONS_REQUESTED_TO_BE_EXECUTED_NOT_FOUND;
		forced_assertion(sub_ret_->error_messages != NULL);
		ret_->error_messages = sub_ret_->error_messages;
		sub_ret_->error_messages = NULL;
		ret_->execution_requests = sub_ret_->execution_requests;
		sub_ret_->execution_requests = NULL;
	}

	/*
	rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret_destructor(
			sub_ret_);
	*/
	free(sub_ret_);

	return ret_;
}
