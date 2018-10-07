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
 * src/rtg/rtg_named_functions_simple_list.c: Amara run time grap
 * application named functions simple list.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "rtg_named_functions_simple_list.h"

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_default_constructor()
{
	rtg_named_functions_simple_list * ret_;
	ret_ = malloc(sizeof(rtg_named_functions_simple_list));
	ret_->first = NULL;
	ret_->next = NULL;
	return ret_;
}

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_copy_constructor(
		const rtg_named_functions_simple_list * list)
{
	rtg_named_functions_simple_list * ret_;
	rtg_named_functions_simple_list * list_ptr_;
	rtg_named_functions_simple_list * ret_ptr_;
	rtg_named_function * named_function_;
	assertion(list != NULL);
	ret_ = malloc(sizeof(rtg_named_functions_simple_list));
	if (list->first == NULL) {
		ret_->first = NULL;
		assertion(list->next == NULL);
		ret_->next = NULL;
		return ret_;
	}
	list_ptr_ = (rtg_named_functions_simple_list *) list;
	ret_ptr_ = ret_;
	while (list_ptr_->next != NULL) {
		named_function_ = rtg_named_function_copy_constructor(
				list_ptr_->first);
		assertion(named_function_ != NULL);
		ret_ptr_->first = named_function_;
		ret_ptr_->next = malloc(sizeof(
				rtg_named_functions_simple_list));
		list_ptr_ = list_ptr_->next;
		ret_ptr_ = ret_ptr_->next;
	}
	named_function_ = rtg_named_function_copy_constructor(
			list_ptr_->first);
	assertion(named_function_ != NULL);
	ret_ptr_->first = named_function_;
	ret_ptr_->next = NULL;
	return ret_;
}

void
rtg_named_functions_simple_list_destructor(
		rtg_named_functions_simple_list * list)
{
	assertion(list != NULL);
	if (list->first == NULL) {
		assertion(list->next == NULL);
	} else {
		rtg_named_function_destructor(list->first);
	}
	if (list->next != NULL) {
		rtg_named_functions_simple_list_destructor(list->next);
	}
	free(list);
}

void
find_rtg_named_function_by_name_ret_destructor(
		find_rtg_named_function_by_name_ret * find_rtg_named_function_by_name_ret_)
{
	assertion(find_rtg_named_function_by_name_ret_ != NULL);
	if (find_rtg_named_function_by_name_ret_->status ==
			FIND_RTG_NAMED_FUNCTION_BY_NAME_RET_STATUS_SUCCESS) {
		assertion(find_rtg_named_function_by_name_ret_->named_function !=
				NULL);
		if (find_rtg_named_function_by_name_ret_->named_function_was_moved ==
				AMARA_BOOLEAN_FALSE) {
			rtg_named_function_destructor(
					find_rtg_named_function_by_name_ret_->named_function);
		}
	} else {
		assertion(find_rtg_named_function_by_name_ret_->status ==
					FIND_RTG_NAMED_FUNCTION_BY_NAME_RET_STATUS_NOT_FOUND ||
				find_rtg_named_function_by_name_ret_->status ==
						FIND_RTG_NAMED_FUNCTION_BY_NAME_RET_STATUS_INVALID);
		assertion(find_rtg_named_function_by_name_ret_->named_function == NULL);
	}
	free(find_rtg_named_function_by_name_ret_);
}

find_rtg_named_function_by_name_ret *
find_rtg_named_function_by_name(
		const amara_string * needle,
		const rtg_named_functions_simple_list * haystack)
{
	find_rtg_named_function_by_name_ret * ret_;
	find_rtg_named_function_by_name_ret * rec_ret_;
	rtg_named_function * named_function_;
	ret_ = malloc(sizeof(find_rtg_named_function_by_name_ret));
	fprintf(stderr, "----> %s:%u:find_rtg_named_function_by_name_ret * find_rtg_named_function_by_name(const amara_string *, const rtg_named_functions_simple_list *)\n",
			__FILE__, __LINE__);
	ret_->status = FIND_RTG_NAMED_FUNCTION_BY_NAME_RET_STATUS_INVALID;
	ret_->named_function = NULL;
	ret_->named_function_was_moved = AMARA_BOOLEAN_FALSE;
	if (haystack == NULL) {
		ret_->status = FIND_RTG_NAMED_FUNCTION_BY_NAME_RET_STATUS_NOT_FOUND;
		ret_->named_function = NULL;
		ret_->named_function_was_moved = AMARA_BOOLEAN_FALSE;
		fprintf(stderr, "<---- %s:%u:find_rtg_named_function_by_name_ret * find_rtg_named_function_by_name(const amara_string *, const rtg_named_functions_simple_list *) - not found\n",
				__FILE__, __LINE__);
		return ret_;
	}
	assertion(needle != NULL);
	if (amara_string_equality(haystack->first->name_, needle)) {
		ret_->status = FIND_RTG_NAMED_FUNCTION_BY_NAME_RET_STATUS_SUCCESS;
		named_function_ = rtg_named_function_copy_constructor(haystack->first);
		ret_->named_function = named_function_;
		ret_->named_function_was_moved = AMARA_BOOLEAN_FALSE;
		fprintf(stderr, "<---- %s:%u:find_rtg_named_function_by_name_ret * find_rtg_named_function_by_name(const amara_string *, const rtg_named_functions_simple_list *) - found\n",
				__FILE__, __LINE__);
		return ret_;
	}
	fprintf(stderr, "--85- %s:%u:find_rtg_named_function_by_name_ret * find_rtg_named_function_by_name(const amara_string *, const rtg_named_functions_simple_list *) - looking in next\n",
			__FILE__, __LINE__);
	rec_ret_ = find_rtg_named_function_by_name(needle, haystack->next);
	ret_->status = rec_ret_->status;
	ret_->named_function = rec_ret_->named_function;
	rec_ret_->named_function_was_moved = AMARA_BOOLEAN_TRUE;
	find_rtg_named_function_by_name_ret_destructor(rec_ret_);
	fprintf(stderr, "<---- %s:%u:find_rtg_named_function_by_name_ret * find_rtg_named_function_by_name(const amara_string *, const rtg_named_functions_simple_list *) - returning recursive case result inconditionally\n",
			__FILE__, __LINE__);
	return ret_;
}

rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(
		const stt_named_functions_simple_list * list)
{
	rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * ret_;
	rtg_named_functions_simple_list * sub_ret_;
	rtg_named_functions_simple_list * sub_ret_ptr_;
	const stt_named_functions_simple_list * list_ptr_;
	rtg_named_function_out_of_stt_named_function_ret * sub_ret_fun_ret_;
	fprintf(stderr, "%s:%u ----> rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(const stt_named_functions_simple_list *)\n",
			__FILE__, __LINE__);
	ret_ = malloc(sizeof(
			rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret));
	ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	if (list == NULL) {
		ret_->named_functions = NULL;
		fprintf(stderr, "%s:%u <---- rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(const stt_named_functions_simple_list *)\n",
				__FILE__, __LINE__);
		return ret_;
	}
	assertion(list->first != NULL);
	sub_ret_ = malloc(sizeof(rtg_named_functions_simple_list));
	sub_ret_fun_ret_ = rtg_named_function_out_of_stt_named_function(list->first);
	assertion(sub_ret_fun_ret_ != NULL);
	assertion(sub_ret_fun_ret_->status ==
			RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_SUCCESS);
	sub_ret_->first = sub_ret_fun_ret_->named_function;
	sub_ret_fun_ret_->named_function_was_moved = AMARA_BOOLEAN_TRUE;
	rtg_named_function_out_of_stt_named_function_ret_destructor(
			sub_ret_fun_ret_);
	list_ptr_ = list;
	sub_ret_ptr_ = sub_ret_;
	while (list_ptr_->next != NULL) {
		assertion(list_ptr_->next->first != NULL);
		sub_ret_ptr_->next = malloc(
				sizeof(rtg_named_functions_simple_list));
		sub_ret_fun_ret_ =
				rtg_named_function_out_of_stt_named_function(
						list_ptr_->next->first);
		assertion(sub_ret_fun_ret_ != NULL);
		assertion(sub_ret_fun_ret_->status ==
				RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_SUCCESS);
		sub_ret_ptr_->next->first = sub_ret_fun_ret_->named_function;
		sub_ret_fun_ret_->named_function_was_moved =
				AMARA_BOOLEAN_TRUE;
		rtg_named_function_out_of_stt_named_function_ret_destructor(
				sub_ret_fun_ret_);
		list_ptr_ = list_ptr_->next;
		sub_ret_ptr_ = sub_ret_ptr_->next;
	}
	sub_ret_ptr_->next = NULL;
	ret_->named_functions = sub_ret_;
	ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
	fprintf(stderr, "%s:%u <---- rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(const stt_named_functions_simple_list *)\n",
			__FILE__, __LINE__);
	return ret_;
}
