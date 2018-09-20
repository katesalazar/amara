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
 * src/rtg/rtg_applications_simple_list.c: Amara run time graph
 * applications simple list.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `rtg_functions_simple_list`. */
#include "../rtg/rtg_functions_simple_list.h"

/*   For own definitions. */
#include "rtg_applications_simple_list.h"

rtg_applications_simple_list *
rtg_applications_simple_list_copy_constructor(
		rtg_applications_simple_list * list)
{
	rtg_applications_simple_list * ret_;
	rtg_applications_simple_list * list_ptr_;
	rtg_applications_simple_list * ret_ptr_;
	rtg_application * ret_app_;
	assertion(list != NULL);
	ret_ = malloc(sizeof(rtg_applications_simple_list));
	if (list->first == NULL) {
		ret_->first = NULL;
		assertion(list->next == NULL);
		ret_->next = NULL;
		return ret_;
	}
	ret_ = malloc(sizeof(rtg_applications_simple_list));
	ret_app_ = rtg_application_copy_constructor(list->first);
	ret_->first = ret_app_;
	list_ptr_ = list;
	ret_ptr_ = ret_;
	while (list_ptr_->next != NULL) {
		ret_ptr_->next = malloc(sizeof(rtg_applications_simple_list));
		assertion(list_ptr_->next->first != NULL);
		ret_app_ = rtg_application_copy_constructor(
				list_ptr_->next->first);
		ret_ptr_->next->first = ret_app_;
		list_ptr_ = list_ptr_->next;
		ret_ptr_ = ret_ptr_->next;
	}
	ret_ptr_->next = NULL;
	return ret_;
}

/*

#define FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_INVALID   0x00
#define FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_SUCCESS   0x0F
#define FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_NOT_FOUND 0xF0

typedef struct find_rtg_application_by_name_ret {
	uint_fast8_t status;
	rtg_application * application;
} find_rtg_application_by_name_ret;

*/

find_rtg_application_by_name_ret *
find_rtg_application_by_name(
		const amara_string * needle,
		const rtg_applications_simple_list * haystack)
{
	find_rtg_application_by_name_ret * ret_;
	find_rtg_application_by_name_ret * rec_ret_;
	rtg_application * application_;
	ret_ = malloc(sizeof(find_rtg_application_by_name_ret));
	ret_->status = FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_INVALID;
	ret_->application = NULL;
	if (haystack == NULL) {
		ret_->status = FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_NOT_FOUND;
		ret_->application = NULL;
		return ret_;
	}
	assertion(needle != NULL);
	if (amara_string_equality(haystack->first->name_, needle)) {
		ret_->status = FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_SUCCESS;
		application_ = rtg_application_copy_constructor(haystack->first);
		ret_->application = application_;
		return ret_;
	}
	rec_ret_ = find_rtg_application_by_name(needle, haystack->next);
	ret_->status = rec_ret_->status;
	ret_->application = rec_ret_->application;
	free(rec_ret_);
	return ret_;
}

rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_functions_simple_list_ret *
rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_functions_simple_list(
		const stt_applications_simple_list * stt_applications,
		const rtg_functions_simple_list * rtg_functions)
{
	rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_functions_simple_list_ret * ret_;
	rtg_applications_simple_list * sub_ret_;
	rtg_applications_simple_list * sub_ret_ptr_;
	const stt_applications_simple_list * stt_applications_ptr_;
	rtg_application_out_of_stt_application_and_rtg_functions_simple_list_ret * sub_ret_app_ret_;
	fprintf(stderr, "----> rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_functions_simple_list_ret * rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_functions_simple_list(const stt_applications_simple_list *, const rtg_functions_simple_list *) (%s:%u)\n",
			__FILE__, __LINE__);
	ret_ = malloc(sizeof(
			rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_functions_simple_list_ret));
	ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	if (stt_applications == NULL) {
		ret_->applications = NULL;
		fprintf(stderr, "<---- rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_functions_simple_list_ret * rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_functions_simple_list(const stt_applications_simple_list *, const rtg_functions_simple_list *) (%s:%u)\n",
				__FILE__, __LINE__);
		return ret_;
	}
	assertion(stt_applications->first != NULL);
	sub_ret_ = malloc(sizeof(rtg_applications_simple_list));
	sub_ret_app_ret_ =
			rtg_application_out_of_stt_application_and_rtg_functions_simple_list(
					stt_applications->first,
					rtg_functions);
	assertion(sub_ret_app_ret_ != NULL);
	assertion(sub_ret_app_ret_->status ==
			RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	sub_ret_->first = sub_ret_app_ret_->application;
	stt_applications_ptr_ = stt_applications;
	sub_ret_ptr_ = sub_ret_;
	while (stt_applications_ptr_->next != NULL) {
		assertion(stt_applications_ptr_->next->first != NULL);
		sub_ret_ptr_->next = malloc(sizeof(rtg_applications_simple_list));
		sub_ret_app_ret_ =
				rtg_application_out_of_stt_application_and_rtg_functions_simple_list(
						stt_applications_ptr_->next->first,
						rtg_functions);
		assertion(sub_ret_app_ret_ != NULL);
		assertion(sub_ret_app_ret_->status ==
				RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
		sub_ret_ptr_->next->first = sub_ret_app_ret_->application;
		stt_applications_ptr_ = stt_applications_ptr_->next;
		sub_ret_ptr_ = sub_ret_ptr_->next;
	}
	sub_ret_ptr_->next = NULL;
	ret_->applications = sub_ret_;
	ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
	fprintf(stderr, "<---- rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_functions_simple_list_ret * rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_functions_simple_list(const stt_applications_simple_list *, const rtg_functions_simple_list *) (%s:%u)\n",
			__FILE__, __LINE__);
	return ret_;
}
