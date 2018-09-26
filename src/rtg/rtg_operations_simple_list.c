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
 * src/rtg/rtg_operations_simple_list.c: Amara runtime graph application
 * function operations simple list.
 */

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "rtg_operations_simple_list.h"

rtg_operations_simple_list *
rtg_operations_simple_list_copy_constructor(
		const rtg_operations_simple_list * list)
{
	rtg_operations_simple_list * ret_;
	const rtg_operations_simple_list * list_ptr_;
	rtg_operations_simple_list * ret_ptr_;
	rtg_operation * operation_;
	assertion(list != NULL);
	ret_ = malloc(sizeof(rtg_operations_simple_list));
	if (list->first == NULL) {
		ret_->first = NULL;
		assertion(list->next == NULL);
		ret_->next = NULL;
		return ret_;
	}
	list_ptr_ = list;
	ret_ptr_ = ret_;
	while (list_ptr_->next != NULL) {
		operation_ = rtg_operation_copy_constructor(list_ptr_->first);
		assertion(operation_ != NULL);
		ret_ptr_->first = operation_;
		ret_ptr_->next = malloc(sizeof(rtg_operations_simple_list));
		list_ptr_ = list_ptr_->next;
		ret_ptr_ = ret_ptr_->next;
	}
	operation_ = rtg_operation_copy_constructor(list_ptr_->first);
	assertion(operation_ != NULL);
	ret_ptr_->first = operation_;
	ret_ptr_->next = NULL;
	return ret_;
}

void
rtg_operations_simple_list_destructor(rtg_operations_simple_list * list)
{
	assertion(list != NULL);
	if (list->first == NULL) {
		assertion(list->next == NULL);
	} else {
		rtg_operation_destructor(list->first);
	}
	if (list->next != NULL) {
		rtg_operations_simple_list_destructor(list->next);
	}
	free(list);
}

void
rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_destructor(
		rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_)
{
	assertion(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_ !=
			NULL);
	if (rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->status ==
			RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {
		assertion(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->operations !=
				NULL);
		if (rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->operations_were_moved ==
				AMARA_BOOLEAN_FALSE) {
			rtg_operations_simple_list_destructor(
					rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->operations);
		}
	} else {
		assertion(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->status ==
					RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_INVALID ||
				rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->status ==
						RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC);
		assertion(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->operations ==
				NULL);
	}
	free(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_);
}

rtg_operations_simple_list_out_of_stt_operations_simple_list_ret *
rtg_operations_simple_list_out_of_stt_operations_simple_list(
		const stt_operations_simple_list * list)
{
	rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * ret_;
	rtg_operations_simple_list * ret_list_;
	const stt_operations_simple_list * list_ptr_;
	rtg_operations_simple_list * ret_list_ptr_;
	rtg_operation_out_of_stt_operation_ret * single_operation_transformation_;
	rtg_operation * new_rtg_op_;
	fprintf(stderr, "%s:%u ----> rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * rtg_operations_simple_list_out_of_stt_operations_simple_list(const stt_operations_simple_list *)\n",
			__FILE__, __LINE__);
	ret_ = malloc(sizeof(
			rtg_operations_simple_list_out_of_stt_operations_simple_list_ret));
	ret_->status = RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	ret_->operations = NULL;
	if (list == NULL) {
		ret_list_ = NULL;
		ret_->operations = ret_list_;
		ret_->status = RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
		fprintf(stderr, "%s:%u <---- rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * rtg_operations_simple_list_out_of_stt_operations_simple_list(const stt_operations_simple_list *)\n",
				__FILE__, __LINE__);
		return ret_;
	}
	assertion(list->first != NULL);
	ret_list_ = malloc(sizeof(rtg_operations_simple_list));
	single_operation_transformation_ =
			rtg_operation_out_of_stt_operation(list->first);
	assertion(single_operation_transformation_->status ==
			RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS);
	new_rtg_op_ = single_operation_transformation_->operation;
	single_operation_transformation_->operation_was_moved =
			AMARA_BOOLEAN_TRUE;
	rtg_operation_out_of_stt_operation_ret_destructor(
			single_operation_transformation_);
	ret_list_->first = new_rtg_op_;
	list_ptr_ = list;
	ret_list_ptr_ = ret_list_;
	while (list_ptr_->next != NULL) {
		ret_list_ptr_->next =
				malloc(sizeof(rtg_operations_simple_list));
		single_operation_transformation_ =
				rtg_operation_out_of_stt_operation(
						list->next->first);
		assertion(single_operation_transformation_->status ==
				RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS);
		new_rtg_op_ = single_operation_transformation_->operation;
		single_operation_transformation_->operation_was_moved =
				AMARA_BOOLEAN_TRUE;
		rtg_operation_out_of_stt_operation_ret_destructor(
				single_operation_transformation_);
		ret_list_ptr_->next->first = new_rtg_op_;
		list_ptr_ = list_ptr_->next;
		ret_list_ptr_ = ret_list_ptr_->next;
	}
	ret_list_ptr_->next = NULL;
	ret_->operations = ret_list_;
	ret_->status = RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
	fprintf(stderr, "%s:%u <---- rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * rtg_operations_simple_list_out_of_stt_operations_simple_list(const stt_operations_simple_list *)\n",
			__FILE__, __LINE__);
	return ret_;
}
