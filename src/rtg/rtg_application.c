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
 * src/rtg/rtg_application.c: Amara run time graph application.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "rtg_application.h"

rtg_application *
rtg_application_default_constructor()
{
	rtg_application * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_application *)
#endif
			malloc(sizeof(rtg_application));
	forced_assertion(ret_ != NULL);

	ret_->entry_point_function_ = NULL;
	ret_->name_ = NULL;
	ret_->type_ = RTG_APPLICATION_TYPE_INVALID;

	return ret_;
}

rtg_application *
rtg_application_copy_constructor(const rtg_application * application)
{
	rtg_application * ret_;

	assertion(application != NULL);
	assertion(application->name_ != NULL);
	assertion(application->name_->value_ != NULL);
	assertion(application->entry_point_function_ != NULL);

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_application *)
#endif
			malloc(sizeof(rtg_application));
	forced_assertion(ret_ != NULL);

	ret_->entry_point_function_ = rtg_named_function_copy_constructor(
			application->entry_point_function_);

	ret_->name_ = amara_string_copy_constructor(application->name_);

	ret_->type_ = application->type_;

	return ret_;
}

void
rtg_application_destructor(rtg_application * application)
{
	assertion(application != NULL);

	if (application->type_ == RTG_APPLICATION_TYPE_INVALID) {

		assertion(application->name_ == NULL);
		assertion(application->entry_point_function_ == NULL);
	} else {

		assertion(application->name_ != NULL);
		amara_string_destructor(application->name_);
		assertion(application->entry_point_function_ != NULL);
		rtg_named_function_destructor(
				application->entry_point_function_);
	}

	free(application);
}

void
rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret_destructor(
		rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret * input_ret)
{
	forced_assertion(input_ret != NULL);

	if (input_ret->status ==
			RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

		if (input_ret->application != NULL) {
			rtg_application_destructor(input_ret->application);
		}
	} else {
		forced_assertion(input_ret->status ==
				RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_FIND_ENTRY_POINT_FUNCTION_FOR_APPLICATION);

		forced_assertion(input_ret->error_messages == NULL);

		forced_assertion(input_ret->application == NULL);
	}

	free(input_ret);
}

rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret *
rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list(
		const stt_application * application,
		const rtg_named_functions_simple_list * named_functions)
{
	rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret * ret_;
	rtg_named_function * application_entry_point_function_;
	rtg_named_functions_simple_list_find_by_name_ret * find_entry_point_rtg_named_function_ret_;

	/*
	fprintf(stderr, "----> rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret * rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list(const stt_application *, const rtg_named_functions_simple_list *) (%s:%u)\n",
			__FILE__, __LINE__);
	*/

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret *)
#endif
			malloc(sizeof(rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret));
	forced_assertion(ret_ != NULL);
	ret_->status = RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	ret_->error_messages = NULL;
	find_entry_point_rtg_named_function_ret_ =
			rtg_named_functions_simple_list_find_by_name(
					named_functions,
					application->entry_point_function_name_);
	assertion_two(find_entry_point_rtg_named_function_ret_ != NULL,
			"unable to find function with particular name in list of functions (returned NULL)");

	if (find_entry_point_rtg_named_function_ret_->status !=
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS) {

		forced_assertion(find_entry_point_rtg_named_function_ret_->status ==
				RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND);

		forced_assertion(find_entry_point_rtg_named_function_ret_->named_function ==
				NULL);

		rtg_named_functions_simple_list_find_by_name_ret_destructor(
				find_entry_point_rtg_named_function_ret_);

		ret_->application = NULL;
		ret_->error_messages =
				amara_strings_simple_list_exhaustive_constructor_three_to_one(
						"unable to find function named '",
						application->entry_point_function_name_->value_,
						"' in the functions list of the doc");
		forced_assertion(ret_->error_messages != NULL);
		forced_assertion(ret_->error_messages->first != NULL);
#ifndef NDEBUG
		assertion(ret_->error_messages->next == NULL);
#endif
		ret_->status = RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_FIND_ENTRY_POINT_FUNCTION_FOR_APPLICATION;

		return ret_;
	}

	assertion_two(
			find_entry_point_rtg_named_function_ret_->status ==
					RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS,
			"unable to find function with particular name in list of functions (returned a non success return status code)");
	assertion_two(
			find_entry_point_rtg_named_function_ret_->named_function !=
					NULL,
			"unable to find function with particular name in list of functions (function set to NULL inconsistently given the status code returned was success)");
	application_entry_point_function_ =
			find_entry_point_rtg_named_function_ret_->named_function;
	find_entry_point_rtg_named_function_ret_->named_function_was_moved =
			AMARA_BOOLEAN_TRUE;
	rtg_named_functions_simple_list_find_by_name_ret_destructor(
			find_entry_point_rtg_named_function_ret_);
	assertion(application_entry_point_function_ != NULL);
	ret_->application = rtg_application_default_constructor();
	forced_assertion(ret_->application != NULL);
	ret_->application->entry_point_function_ =
			application_entry_point_function_;
	ret_->application->name_ =
			amara_string_copy_constructor(application->name_);
	ret_->application->type_ = application->type_;
	ret_->status = RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;

	/*
	fprintf(stderr, "<---- rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret * rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list(const stt_application *, const rtg_named_functions_simple_list *) (%s:%u)\n",
			__FILE__, __LINE__);
	*/

	return ret_;
}
