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

/*   For `rtg_named_functions_simple_list`. */
#include "../rtg/rtg_named_functions_simple_list.h"

/*   For own definitions. */
#include "rtg_applications_simple_list.h"

rtg_applications_simple_list *
rtg_applications_simple_list_default_constructor()
{
	rtg_applications_simple_list * ret_;
	ret_ = malloc(sizeof(rtg_applications_simple_list));
	ret_->first = NULL;
	ret_->next = NULL;
	return ret_;
}

rtg_applications_simple_list *
rtg_applications_simple_list_copy_constructor(
		const rtg_applications_simple_list * list)
{
	rtg_applications_simple_list * ret_;
	const rtg_applications_simple_list * list_ptr_;
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

void
rtg_applications_simple_list_destructor(
		rtg_applications_simple_list * list)
{
	assertion(list != NULL);
	if (list->first == NULL) {
		assertion(list->next == NULL);
	} else {
		rtg_application_destructor(list->first);
	}
	if (list->next != NULL) {
		rtg_applications_simple_list_destructor(list->next);
	}
	free(list);
}

rtg_applications_simple_list *
rtg_applications_simple_list_push_front(
		rtg_applications_simple_list * applications,
		const rtg_application * application)
{
	rtg_applications_simple_list * applications_new_simple_list_node_;
	assertion(applications != NULL);
	assertion(application != NULL);
	if (applications->first == NULL) {
		assertion(applications->next == NULL);
		applications->first = (rtg_application *) application;
		return applications;
	}
	applications_new_simple_list_node_ =
			malloc(sizeof(rtg_applications_simple_list));
	applications_new_simple_list_node_->first =
			(rtg_application *) application;
	applications_new_simple_list_node_->next = applications;
	return applications_new_simple_list_node_;
}

void
find_rtg_application_by_name_ret_destructor(
		find_rtg_application_by_name_ret * find_rtg_application_by_name_ret_)
{
	assertion(find_rtg_application_by_name_ret_ != NULL);
	if (find_rtg_application_by_name_ret_->status ==
			FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_SUCCESS) {
		assertion(find_rtg_application_by_name_ret_->application != NULL);
		if (find_rtg_application_by_name_ret_->application_was_moved ==
				AMARA_BOOLEAN_FALSE) {
			rtg_application_destructor(
					find_rtg_application_by_name_ret_->application);
		}
	} else {
		assertion(find_rtg_application_by_name_ret_->status ==
					FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_NOT_FOUND /* ||
				find_rtg_application_by_name_ret_->status ==
						FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_INVALID */);
		assertion(find_rtg_application_by_name_ret_->application == NULL);
	}
	free(find_rtg_application_by_name_ret_);
}

find_rtg_application_by_name_ret *
find_rtg_application_by_name_inner(
		const amara_string * needle,
		const rtg_applications_simple_list * haystack)
{
	find_rtg_application_by_name_ret * ret_;
	find_rtg_application_by_name_ret * rec_ret_;
	ret_ = malloc(sizeof(find_rtg_application_by_name_ret));
	ret_->status = FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_INVALID;
	ret_->application = NULL;
	ret_->application_was_moved = AMARA_BOOLEAN_FALSE;
	if (haystack == NULL) {
		ret_->status = FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_NOT_FOUND;
		ret_->application = NULL;
		ret_->application_was_moved = AMARA_BOOLEAN_FALSE;
		return ret_;
	}
	assertion(haystack->first != NULL);
	assertion(haystack->first->name_ != NULL);
	assertion(haystack->first->name_->value_ != NULL);
	if (amara_string_equality(haystack->first->name_, needle)) {
		ret_->status = FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_SUCCESS;
		ret_->application = rtg_application_copy_constructor(
				haystack->first);
		ret_->application_was_moved = AMARA_BOOLEAN_FALSE;
		return ret_;
	}
	rec_ret_ = find_rtg_application_by_name_inner(needle, haystack->next);
	if (rec_ret_->status ==
			FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_SUCCESS) {
		assertion(rec_ret_->application_was_moved ==
				AMARA_BOOLEAN_FALSE);
		ret_->application = rec_ret_->application;
		ret_->status = FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_SUCCESS;
		find_rtg_application_by_name_ret_destructor(rec_ret_);
		return ret_;
	}
	assertion(rec_ret_->status ==
			FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_NOT_FOUND);
	assertion(rec_ret_->application == NULL);
	assertion(rec_ret_->application_was_moved == AMARA_BOOLEAN_FALSE);
	ret_->status = FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_NOT_FOUND;
	assertion(ret_->application == NULL);
	assertion(ret_->application_was_moved == AMARA_BOOLEAN_FALSE);
	find_rtg_application_by_name_ret_destructor(rec_ret_);
	return ret_;
}

find_rtg_application_by_name_ret *
find_rtg_application_by_name(
		const amara_string * needle,
		const rtg_applications_simple_list * haystack)
{
	find_rtg_application_by_name_ret * ret_;
	find_rtg_application_by_name_ret * rec_ret_;
	ret_ = malloc(sizeof(find_rtg_application_by_name_ret));
	ret_->status = FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_INVALID;
	ret_->application = NULL;
	ret_->application_was_moved = AMARA_BOOLEAN_FALSE;
	assertion(haystack != NULL);
	if (haystack->first == NULL) {
		assertion(haystack->next == NULL);
		ret_->status = FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_NOT_FOUND;
		return ret_;
	}
	rec_ret_ = find_rtg_application_by_name_inner(needle, haystack);
	if (rec_ret_->status ==
			FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_SUCCESS) {
		assertion(rec_ret_->application != NULL);
		assertion(rec_ret_->application_was_moved ==
				AMARA_BOOLEAN_FALSE);
		ret_->application = rec_ret_->application;
		rec_ret_->application_was_moved = AMARA_BOOLEAN_TRUE;
		find_rtg_application_by_name_ret_destructor(rec_ret_);
		ret_->status = FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_SUCCESS;
		return ret_;
	}
	assertion(rec_ret_->status ==
			FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_NOT_FOUND);
	assertion(rec_ret_->application == NULL);
	assertion(rec_ret_->application_was_moved == AMARA_BOOLEAN_FALSE);
	ret_->status = FIND_RTG_APPLICATION_BY_NAME_RET_STATUS_NOT_FOUND;
	find_rtg_application_by_name_ret_destructor(rec_ret_);
	return ret_;
}

rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret *
rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list(
		const stt_applications_simple_list * stt_applications,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
	rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret * ret_;
	rtg_applications_simple_list * sub_ret_;
	rtg_applications_simple_list * sub_ret_ptr_;
	const stt_applications_simple_list * stt_applications_ptr_;
	rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret * sub_ret_app_ret_;
	fprintf(stderr, "----> rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret * rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list(const stt_applications_simple_list *, const rtg_named_functions_simple_list *) (%s:%u)\n",
			__FILE__, __LINE__);
	ret_ = malloc(sizeof(
			rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret));
	ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	if (stt_applications == NULL) {
		ret_->applications = NULL;
		fprintf(stderr, "<---- rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret * rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list(const stt_applications_simple_list *, const rtg_named_functions_simple_list *) (%s:%u)\n",
				__FILE__, __LINE__);
		return ret_;
	}
	assertion(stt_applications->first != NULL);
	sub_ret_ = malloc(sizeof(rtg_applications_simple_list));
	sub_ret_app_ret_ =
			rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list(
					stt_applications->first,
					rtg_named_functions);
	assertion(sub_ret_app_ret_ != NULL);
	assertion(sub_ret_app_ret_->status ==
			RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	sub_ret_->first = sub_ret_app_ret_->application;
	sub_ret_app_ret_->application_was_moved = AMARA_BOOLEAN_TRUE;
	rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret_destructor(
			sub_ret_app_ret_);
	stt_applications_ptr_ = stt_applications;
	sub_ret_ptr_ = sub_ret_;
	while (stt_applications_ptr_->next != NULL) {
		assertion(stt_applications_ptr_->next->first != NULL);
		sub_ret_ptr_->next = malloc(sizeof(rtg_applications_simple_list));
		sub_ret_app_ret_ =
				rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list(
						stt_applications_ptr_->next->first,
						rtg_named_functions);
		assertion(sub_ret_app_ret_ != NULL);
		assertion(sub_ret_app_ret_->status ==
				RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
		sub_ret_ptr_->next->first = sub_ret_app_ret_->application;
		sub_ret_app_ret_->application_was_moved = AMARA_BOOLEAN_TRUE;
		rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret_destructor(
				sub_ret_app_ret_);
		stt_applications_ptr_ = stt_applications_ptr_->next;
		sub_ret_ptr_ = sub_ret_ptr_->next;
	}
	sub_ret_ptr_->next = NULL;
	ret_->applications = sub_ret_;
	ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
	fprintf(stderr, "<---- rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret * rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list(const stt_applications_simple_list *, const rtg_named_functions_simple_list *) (%s:%u)\n",
			__FILE__, __LINE__);
	return ret_;
}
