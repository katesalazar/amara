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
 * src/rtg/rtg_execution_request.c: Amara run time graph application
 * execution request.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_execution_request`. */
#include "../stt/stt_execution_request.h"

/*   For own definitions. */
#include "rtg_execution_request.h"

rtg_execution_request *
rtg_execution_request_default_constructor()
{
	rtg_execution_request * ret_;
	ret_ = malloc(sizeof(rtg_execution_request));
	ret_->type_ = RTG_EXECUTION_REQUEST_TYPE_INVALID;
	ret_->application_ = NULL;
	return ret_;
}

rtg_execution_request *
rtg_execution_request_copy_constructor(
		const rtg_execution_request * execution_request)
{
	rtg_execution_request * ret_;
	rtg_application * application_;
	ret_ = malloc(sizeof(rtg_execution_request));
	assertion(execution_request != NULL);
	ret_->type_ = execution_request->type_;
	application_ = rtg_application_copy_constructor(
			execution_request->application_);
	assertion(application_ != NULL);
	ret_->application_ = application_;
	return ret_;
}

rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret *
rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list(
		const stt_execution_request * execution_request,
		const rtg_applications_simple_list * applications)
{
	rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret * ret_;
	rtg_application * application_requested_to_be_executed_;
	find_rtg_application_by_name_ret * find_rtg_application_requested_to_be_executed_ret_;
	ret_ = malloc(sizeof(
			rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret));
	ret_->status = RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	ret_->execution_request = rtg_execution_request_default_constructor();
	ret_->execution_request->type_ = RTG_EXECUTION_REQUEST_TYPE_INVALID;
	find_rtg_application_requested_to_be_executed_ret_ = find_rtg_application_by_name(
			execution_request->application_name_, applications);
	assertion(find_rtg_application_requested_to_be_executed_ret_ != NULL);
	assertion(find_rtg_application_requested_to_be_executed_ret_->status ==
			FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_SUCCESS);
	assertion(find_rtg_application_requested_to_be_executed_ret_->application != NULL);
	application_requested_to_be_executed_ =
			find_rtg_application_requested_to_be_executed_ret_->application;
	assertion(application_requested_to_be_executed_ != NULL);
	ret_->execution_request->application_ = application_requested_to_be_executed_;
	ret_->execution_request->type_ = RTG_EXECUTION_REQUEST_TYPE_CLI_APPLICATION;
	ret_->status = RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
	return ret_;
}
