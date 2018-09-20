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
	ret_ = malloc(sizeof(rtg_application));
	ret_->entry_point_function_ = NULL;
	ret_->name_ = NULL;
	ret_->type_ = RTG_APPLICATION_TYPE_INVALID;
	return ret_;
}

rtg_application *
rtg_application_copy_constructor(const rtg_application * application)
{
	rtg_application * ret_;
	ret_ = malloc(sizeof(rtg_application));
	ret_->entry_point_function_ = rtg_function_copy_constructor(
			application->entry_point_function_);
	ret_->name_ = amara_string_copy_constructor(application->name_);
	ret_->type_ = application->type_;
	return ret_;
}

rtg_application_out_of_stt_application_and_rtg_functions_simple_list_ret *
rtg_application_out_of_stt_application_and_rtg_functions_simple_list(
		const stt_application * application,
		const rtg_functions_simple_list * functions)
{
	rtg_application_out_of_stt_application_and_rtg_functions_simple_list_ret * ret_;
	rtg_function * application_entry_point_function_;
	find_rtg_function_by_name_ret * find_entry_point_rtg_function_ret_;
	fprintf(stderr, "----> rtg_application_out_of_stt_application_and_rtg_functions_simple_list_ret * rtg_application_out_of_stt_application_and_rtg_functions_simple_list(const stt_application *, const rtg_functions_simple_list *) (%s:%u)\n",
			__FILE__, __LINE__);
	ret_ = malloc(sizeof(
			rtg_application_out_of_stt_application_and_rtg_functions_simple_list_ret));
	ret_->status = RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	ret_->application = rtg_application_default_constructor();
	find_entry_point_rtg_function_ret_ = find_rtg_function_by_name(
			application->entry_point_function_name_, functions);
	assertion_two(find_entry_point_rtg_function_ret_ != NULL,
			"unable to find function with particular name in list of functions (returned NULL)");
	assertion_two(
			find_entry_point_rtg_function_ret_->status ==
					FIND_RTG_FUNCTION_BY_NAME_RET_STATUS_SUCCESS,
			"unable to find function with particular name in list of functions (returned a non success return status code)");
	assertion_two(find_entry_point_rtg_function_ret_->function != NULL,
			"unable to find function with particular name in list of functions (function set to NULL inconsistently given the status code returned was success)");
	application_entry_point_function_ =
			find_entry_point_rtg_function_ret_->function;
	assertion(application_entry_point_function_ != NULL);
	ret_->application->entry_point_function_ =
			application_entry_point_function_;
	ret_->application->name_ =
			amara_string_copy_constructor(application->name_);
	ret_->application->type_ = application->type_;
	ret_->status = RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
	fprintf(stderr, "<---- rtg_application_out_of_stt_application_and_rtg_functions_simple_list_ret * rtg_application_out_of_stt_application_and_rtg_functions_simple_list(const stt_application *, const rtg_functions_simple_list *) (%s:%u)\n",
			__FILE__, __LINE__);
	return ret_;
}
