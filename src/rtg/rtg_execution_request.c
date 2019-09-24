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

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_execution_request *)
#endif
			malloc(sizeof(rtg_execution_request));
	forced_assertion(ret_ != NULL);

	ret_->type_ = RTG_EXECUTION_REQUEST_TYPE_INVALID;
	ret_->application_ = NULL;

	return ret_;
}

rtg_execution_request *
rtg_execution_request_exhaustive_constructor(
		unsigned char requested_type,
		const rtg_application * application)
{
	rtg_execution_request * ret_;
	rtg_application * application_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_execution_request *)
#endif
			malloc(sizeof(rtg_execution_request));
	forced_assertion(ret_ != NULL);

#ifndef NDEBUG
	assertion(requested_type != RTG_APPLICATION_TYPE_INVALID);
	assertion(application != NULL);
#endif

	ret_->type_ = requested_type;

	application_ = rtg_application_copy_constructor(application);
	forced_assertion(application_ != NULL);
	ret_->application_ = application_;

	return ret_;
}

rtg_execution_request *
rtg_execution_request_copy_constructor(
		const rtg_execution_request * execution_request)
{
	rtg_execution_request * ret_;
	rtg_application * application_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_execution_request *)
#endif
			malloc(sizeof(rtg_execution_request));
	forced_assertion(ret_ != NULL);

	assertion(execution_request != NULL);
	ret_->type_ = execution_request->type_;

	application_ = rtg_application_copy_constructor(
			execution_request->application_);
	forced_assertion(application_ != NULL);
	ret_->application_ = application_;

	return ret_;
}

void
rtg_execution_request_destructor(
		rtg_execution_request * execution_request)
{
	assertion(execution_request != NULL);
	if (execution_request->type_ == RTG_EXECUTION_REQUEST_TYPE_INVALID) {
		assertion(execution_request->application_ == NULL);
	} else {
		rtg_application_destructor(execution_request->application_);
	}
	free(execution_request);
}

void
rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret_destructor(
		rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret * input_ret_)
{
	forced_assertion(input_ret_ != NULL);

	if (input_ret_->status ==
			RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

		if (input_ret_->execution_request != NULL) {

			rtg_execution_request_destructor(
					input_ret_->execution_request);
		}
	} else {
		assertion(input_ret_->status ==
					RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_APPLICATION_NOT_FOUND);

		;
	}

	free(input_ret_);
}

rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret *
rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list(
		const stt_execution_request * execution_request,
		const rtg_applications_simple_list * applications)
{
	rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret * ret_;
	amara_string * error_message_;
	amara_strings_simple_list * error_messages_;
	rtg_application * application_requested_to_be_executed_;
	rtg_applications_simple_list_find_by_name_ret * find_rtg_application_requested_to_be_executed_ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret *)
#endif
			malloc(sizeof(rtg_execution_request_out_of_stt_execution_request_and_rtg_applications_simple_list_ret));
	forced_assertion(ret_ != NULL);

	ret_->status = RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_INVALID;

	if (applications == NULL) {

		forced_assertion(execution_request != NULL);
		forced_assertion(execution_request->application_name_ !=
				NULL);
		forced_assertion(execution_request->application_name_->value_ !=
				NULL);
		forced_assertion(execution_request->application_name_->value_[0] !=
				0x00);

		ret_->status = RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_APPLICATION_NOT_FOUND;  /* XXX but the list is not null, not empty; maybe that's what should be signaled here... */
		error_messages_ = amara_strings_simple_list_default_constructor();
		forced_assertion(error_messages_ != NULL);
#ifndef NDEBUG
		assertion(error_messages_->first == NULL);
		assertion(error_messages_->next == NULL);
#endif

		error_message_ = amara_string_exhaustive_constructor_three(
				"unable to find application '",
				execution_request->application_name_->value_,
				"' requested to be executed");
		forced_assertion(error_message_ != NULL);
#ifndef NDEBUG
		assertion(error_message_->value_ != NULL);
#endif

		error_messages_ = amara_strings_simple_list_push_front(
				error_messages_, error_message_);
		forced_assertion(error_messages_ != NULL);
#ifndef NDEBUG
		assertion(error_messages_->first != NULL);
		assertion(error_messages_->next == NULL);
#endif

		ret_->error_messages = error_messages_;
		ret_->execution_request = NULL;

		return ret_;
	}

	/*   TODO defer this construction. */
	ret_->execution_request = rtg_execution_request_default_constructor();
	forced_assertion(ret_->execution_request != NULL);

	ret_->execution_request->type_ = RTG_EXECUTION_REQUEST_TYPE_INVALID;

	find_rtg_application_requested_to_be_executed_ret_ =
			rtg_applications_simple_list_find_by_name(
					applications,
					execution_request->application_name_);
	forced_assertion(find_rtg_application_requested_to_be_executed_ret_ !=
			NULL);

	if (find_rtg_application_requested_to_be_executed_ret_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_FOUND) {

		assertion(find_rtg_application_requested_to_be_executed_ret_->application !=
				NULL);

		application_requested_to_be_executed_ =
				find_rtg_application_requested_to_be_executed_ret_->application;

		find_rtg_application_requested_to_be_executed_ret_->application_was_moved =
				AMARA_BOOLEAN_TRUE;

		ret_->execution_request->application_ =
				application_requested_to_be_executed_;
		ret_->execution_request->type_ =
				RTG_EXECUTION_REQUEST_TYPE_CLI_APPLICATION;
		ret_->status = RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;

	} else {
		forced_assertion(find_rtg_application_requested_to_be_executed_ret_->status ==
				RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND);

		rtg_execution_request_destructor(ret_->execution_request);
		ret_->status = RTG_EXECUTION_REQUEST_OUT_OF_STT_EXECUTION_REQUEST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_APPLICATION_NOT_FOUND;
	}

	rtg_applications_simple_list_find_by_name_ret_destructor(
			find_rtg_application_requested_to_be_executed_ret_);

	return ret_;
}
