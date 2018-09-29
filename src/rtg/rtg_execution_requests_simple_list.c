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
	assertion(list != NULL);
	ret_ = malloc(sizeof(rtg_execution_requests_simple_list));
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
	ret_->status = RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	if (stt_execution_requests == NULL) {
		ret_->execution_requests = NULL;
		return ret_;
	}
	assertion(stt_execution_requests->first != NULL);
	sub_ret_ = malloc(sizeof(rtg_execution_requests_simple_list));
	sub_ret_execution_request_ret_ =
			rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list(
					stt_execution_requests->first,
					rtg_applications);
	assertion(sub_ret_execution_request_ret_ != NULL);
	assertion(sub_ret_execution_request_ret_->status ==
			RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	sub_ret_->first = sub_ret_execution_request_ret_->execution_request;
	stt_execution_requests_ptr_ = stt_execution_requests;
	sub_ret_ptr_ = sub_ret_;
	while (stt_execution_requests_ptr_->next != NULL) {
		assertion(stt_execution_requests_ptr_->next->first != NULL);
		sub_ret_ptr_->next = malloc(sizeof(rtg_execution_requests_simple_list));
		sub_ret_execution_request_ret_ =
				rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list(
						stt_execution_requests_ptr_->next->first,
						rtg_applications);
		assertion(sub_ret_execution_request_ret_ != NULL);
		assertion(sub_ret_execution_request_ret_->status ==
				RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
		sub_ret_ptr_->next->first = sub_ret_execution_request_ret_->execution_request;
		stt_execution_requests_ptr_ = stt_execution_requests_ptr_->next;
		sub_ret_ptr_ = sub_ret_ptr_->next;
	}
	sub_ret_ptr_->next = NULL;
	ret_->execution_requests = sub_ret_;
	ret_->status = RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
	return ret_;
}
