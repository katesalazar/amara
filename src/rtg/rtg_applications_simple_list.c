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
    if (list == NULL) {
        return rtg_applications_simple_list_default_constructor();
    }
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
    if (list == NULL) {
        return;
    }
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
		applications->first =
				rtg_application_copy_constructor(application);
		return applications;
	}
	applications_new_simple_list_node_ =
			malloc(sizeof(rtg_applications_simple_list));
	applications_new_simple_list_node_->first =
			rtg_application_copy_constructor(application);
	applications_new_simple_list_node_->next = applications;
	return applications_new_simple_list_node_;
}

void
rtg_applications_simple_list_find_by_name_ret_destructor(
		rtg_applications_simple_list_find_by_name_ret * input_ret)
{
	assertion(input_ret != NULL);
	if (input_ret->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_FOUND) {
		assertion(input_ret->application != NULL);
		if (input_ret->application_was_moved == AMARA_BOOLEAN_FALSE) {
			rtg_application_destructor(input_ret->application);
		}
	} else {
		assertion(input_ret->status ==
				RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND);
		assertion(input_ret->application == NULL);
	}
	free(input_ret);
}

rtg_applications_simple_list_find_by_name_ret *
rtg_applications_simple_list_find_by_name_inner(
		const rtg_applications_simple_list * haystack,
		const amara_string * needle)
__attribute__((warn_unused_result))
;

rtg_applications_simple_list_find_by_name_ret *
rtg_applications_simple_list_find_by_name_inner(
		const rtg_applications_simple_list * haystack,
		const amara_string * needle)
{
	rtg_applications_simple_list_find_by_name_ret * ret_;
	rtg_applications_simple_list_find_by_name_ret * rec_ret_;
	ret_ = malloc(sizeof(rtg_applications_simple_list_find_by_name_ret));
	ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_INVALID;
	ret_->application = NULL;
	ret_->application_was_moved = AMARA_BOOLEAN_FALSE;
	if (haystack == NULL) {
		ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND;
		ret_->application = NULL;
		ret_->application_was_moved = AMARA_BOOLEAN_FALSE;
		return ret_;
	}
	assertion(haystack->first != NULL);
	assertion(haystack->first->name_ != NULL);
	assertion(haystack->first->name_->value_ != NULL);
	if (amara_string_equality(haystack->first->name_, needle)) {
		ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_FOUND;
		ret_->application = rtg_application_copy_constructor(
				haystack->first);
		ret_->application_was_moved = AMARA_BOOLEAN_FALSE;
		return ret_;
	}
	rec_ret_ = rtg_applications_simple_list_find_by_name_inner(
			haystack->next, needle);
	if (rec_ret_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_FOUND) {
		assertion(rec_ret_->application_was_moved ==
				AMARA_BOOLEAN_FALSE);
		ret_->application = rec_ret_->application;
		rec_ret_->application_was_moved = AMARA_BOOLEAN_TRUE;
		ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_FOUND;
		rtg_applications_simple_list_find_by_name_ret_destructor(
				rec_ret_);
		return ret_;
	}
	assertion(rec_ret_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND);
	assertion(rec_ret_->application == NULL);
	assertion(rec_ret_->application_was_moved == AMARA_BOOLEAN_FALSE);
	ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND;
	assertion(ret_->application == NULL);
	assertion(ret_->application_was_moved == AMARA_BOOLEAN_FALSE);
	rtg_applications_simple_list_find_by_name_ret_destructor(rec_ret_);
	return ret_;
}

rtg_applications_simple_list_find_by_name_ret *
rtg_applications_simple_list_find_by_name(
		const rtg_applications_simple_list * haystack,
		const amara_string * needle)
{
	rtg_applications_simple_list_find_by_name_ret * ret_;
	rtg_applications_simple_list_find_by_name_ret * rec_ret_;
	ret_ = malloc(sizeof(rtg_applications_simple_list_find_by_name_ret));
	ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_INVALID;
	ret_->application = NULL;
	ret_->application_was_moved = AMARA_BOOLEAN_FALSE;
	assertion(haystack != NULL);
	if (haystack->first == NULL) {
		assertion(haystack->next == NULL);
		ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND;
		return ret_;
	}
	rec_ret_ = rtg_applications_simple_list_find_by_name_inner(
			haystack, needle);
	if (rec_ret_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_FOUND) {
		assertion(rec_ret_->application != NULL);
		assertion(rec_ret_->application_was_moved ==
				AMARA_BOOLEAN_FALSE);
		ret_->application = rec_ret_->application;
		rec_ret_->application_was_moved = AMARA_BOOLEAN_TRUE;
		rtg_applications_simple_list_find_by_name_ret_destructor(
				rec_ret_);
		ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_FOUND;
		return ret_;
	}
	assertion(rec_ret_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND);
	assertion(rec_ret_->application == NULL);
	assertion(rec_ret_->application_was_moved == AMARA_BOOLEAN_FALSE);
	ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND;
	rtg_applications_simple_list_find_by_name_ret_destructor(rec_ret_);
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
	forced_assertion(ret_ != NULL);
	ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID;

	/*
	if (stt_applications == NULL || stt_applications->first == NULL) {
	*/

	forced_assertion(stt_applications != NULL);
	if (stt_applications->first == NULL) {

		forced_assertion(stt_applications->first == NULL);

		/*
		if (stt_applications->first == NULL) {
		*/

			assertion(stt_applications->next == NULL);
		/*
		}
		*/

		ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
		ret_->applications = NULL;

		fprintf(stderr, "<---- rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret * rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list(const stt_applications_simple_list *, const rtg_named_functions_simple_list *) (%s:%u)\n",
				__FILE__, __LINE__);

		return ret_;
	}
	assertion(stt_applications->first != NULL);
	sub_ret_ = malloc(sizeof(rtg_applications_simple_list));
	forced_assertion(sub_ret_ != NULL);
	sub_ret_app_ret_ =
			rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list(
					stt_applications->first,
					rtg_named_functions);
	assertion(sub_ret_app_ret_ != NULL);

	if (sub_ret_app_ret_->status !=
			RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

		assertion(sub_ret_app_ret_->status ==
				RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_FIND_ENTRY_POINT_FUNCTION_FOR_APPLICATION);

		assertion(sub_ret_app_ret_->error_messages != NULL);

		assertion(sub_ret_app_ret_->application == NULL);

		ret_->applications = NULL;

		ret_->error_messages = sub_ret_app_ret_->error_messages;
		sub_ret_app_ret_->error_messages = NULL;

		rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret_destructor(
				sub_ret_app_ret_);

		ret_->status = RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_FIND_ENTRY_POINT_FUNCTION_FOR_AT_LEAST_ONE_APPLICATION;

		return ret_;
	}

	assertion(sub_ret_app_ret_->status ==
			RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	sub_ret_->first = sub_ret_app_ret_->application;
	sub_ret_app_ret_->application = NULL;
	rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list_ret_destructor(
			sub_ret_app_ret_);
	stt_applications_ptr_ = stt_applications;
	sub_ret_ptr_ = sub_ret_;
	while (stt_applications_ptr_->next != NULL) {
		assertion(stt_applications_ptr_->next->first != NULL);
		sub_ret_ptr_->next = malloc(sizeof(rtg_applications_simple_list));
		forced_assertion(sub_ret_ptr_->next != NULL);
		sub_ret_app_ret_ =
				rtg_application_out_of_stt_application_and_rtg_named_functions_simple_list(
						stt_applications_ptr_->next->first,
						rtg_named_functions);
		assertion(sub_ret_app_ret_ != NULL);
		assertion(sub_ret_app_ret_->status ==
				RTG_APPLICATION_OUT_OF_STT_APPLICATION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
		sub_ret_ptr_->next->first = sub_ret_app_ret_->application;
		sub_ret_app_ret_->application = NULL;
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

void
rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_destructor(
		rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * input_ret)
{
	forced_assertion(input_ret != NULL);

	if (input_ret->status ==
			RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

		forced_assertion(input_ret->applications == NULL);

		/*
		if (input_ret->applications != NULL) {

			rtg_applications_simple_list_destructor(
					input_ret->applications);
		}
		*/
	} else {
		forced_assertion(input_ret->status ==
				RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_FIND_ENTRY_POINT_FUNCTION_FOR_AT_LEAST_ONE_APPLICATION);

		forced_assertion(input_ret->error_messages != NULL);

		amara_strings_simple_list_destructor(
				input_ret->error_messages);

		forced_assertion(input_ret->applications == NULL);
	}

	free(input_ret);
}

rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret *
rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list(
		const stt_doc_subnode * subnode,
		const rtg_named_functions_simple_list * functions)
{
	rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * ret_;
	rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret * sub_ret_;

	fprintf(stderr, "----> %s:%u rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list(const stt_functions_simple_list *)\n",
			__FILE__, __LINE__);

	ret_ = malloc(sizeof(
			rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret));
	forced_assertion(ret_ != NULL);
	ret_->status = RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	ret_->applications = NULL;
	sub_ret_ = rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list(
			subnode->applications_, functions);
	forced_assertion(sub_ret_ != NULL);

	if (sub_ret_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

		ret_->status = RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
		ret_->applications = sub_ret_->applications;
	} else {
		forced_assertion(sub_ret_->status ==
				RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_FIND_ENTRY_POINT_FUNCTION_FOR_AT_LEAST_ONE_APPLICATION);

		forced_assertion(sub_ret_->error_messages != NULL);

		ret_->error_messages = sub_ret_->error_messages;
		sub_ret_->error_messages = NULL;

		forced_assertion(sub_ret_->applications == NULL);

		ret_->applications = NULL;

		ret_->status = RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_FIND_ENTRY_POINT_FUNCTION_FOR_AT_LEAST_ONE_APPLICATION;
	}

	free(sub_ret_);

	fprintf(stderr, "<---- %s:%u rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list(const stt_functions_simple_list *)\n",
			__FILE__, __LINE__);

	return ret_;
}
