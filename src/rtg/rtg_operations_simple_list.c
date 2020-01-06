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
rtg_operations_simple_list_default_constructor()
{
	rtg_operations_simple_list * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_operations_simple_list *)
#endif
			malloc(sizeof(rtg_operations_simple_list));
	forced_assertion(ret_ != NULL);
	ret_->first = NULL;
	ret_->next = NULL;

	return ret_;
}

rtg_operations_simple_list *
rtg_operations_simple_list_copy_constructor(
		const rtg_operations_simple_list * list)
{
	rtg_operations_simple_list * ret_;
	const rtg_operations_simple_list * list_ptr_;
	rtg_operations_simple_list * ret_ptr_;
	rtg_operation * operation_;

	assertion(list != NULL);
	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_operations_simple_list *)
#endif
			malloc(sizeof(rtg_operations_simple_list));
	forced_assertion(ret_ != NULL);
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
		ret_ptr_->next =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operations_simple_list *)
#endif
				malloc(sizeof(rtg_operations_simple_list));
		forced_assertion(ret_ptr_->next != NULL);
		list_ptr_ = list_ptr_->next;
		ret_ptr_ = ret_ptr_->next;
	}
	operation_ = rtg_operation_copy_constructor(list_ptr_->first);
	forced_assertion(operation_ != NULL);
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

rtg_operations_simple_list *
rtg_operations_simple_list_push_front(
		rtg_operations_simple_list * operations,
		rtg_operation * operation)
{
	rtg_operations_simple_list * new_operations_list_node_;

	assertion(operations != NULL);
	assertion(operation != NULL);
	if (operations->first == NULL) {
		assertion(operations->next == NULL);
		operations->first = rtg_operation_copy_constructor(operation);
		return operations;
	}
	new_operations_list_node_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_operations_simple_list *)
#endif
			malloc(sizeof(rtg_operations_simple_list));
	forced_assertion(new_operations_list_node_ != NULL);
	new_operations_list_node_->first =
			rtg_operation_copy_constructor(operation);
	new_operations_list_node_->next = operations;
	return new_operations_list_node_;
}

void
rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_destructor(
		rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_)
{
	forced_assertion(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_ !=
			NULL);

	if (rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->status ==
			RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

		forced_assertion(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->operations ==
				NULL);

		/*
		if (rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->operations !=
				NULL) {

			rtg_operations_simple_list_destructor(
					rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->operations);
		}
		*/

		forced_assertion(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->error_messages ==
				NULL);
	} else {
		forced_assertion(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->status ==
				RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION);

		forced_assertion(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->error_messages ==
				NULL);

		forced_assertion(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_->operations ==
				NULL);
	}

	free(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_);
}

rtg_operations_simple_list_out_of_stt_operations_simple_list_ret *
rtg_operations_simple_list_out_of_stt_operations_simple_list(
		const stt_operations_simple_list * operations,
		const struct stt_where_value_bindings_simple_list * function_where_bindings)
{
	rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * ret_;
	rtg_operations_simple_list * ret_list_;
	const stt_operations_simple_list * operations_ptr_;
	rtg_operations_simple_list * ret_list_ptr_;
	rtg_operation_out_of_stt_operation_ret * single_operation_transformation_;
	rtg_operation * new_rtg_op_;

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "%s:%u ----> rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * rtg_operations_simple_list_out_of_stt_operations_simple_list(const stt_operations_simple_list *)\n",
			__FILE__, __LINE__);
#endif

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret *)
#endif
			malloc(sizeof(rtg_operations_simple_list_out_of_stt_operations_simple_list_ret));
	forced_assertion(ret_ != NULL);
	ret_->status = RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	ret_->error_messages = NULL;
	ret_->operations = NULL;
	if (operations == NULL || operations->first == NULL) {
		ret_list_ = rtg_operations_simple_list_default_constructor();
		forced_assertion(ret_list_ != NULL);
#ifndef NDEBUG
		assertion(ret_list_->first == NULL);
		assertion(ret_list_->next == NULL);
#endif
		ret_->operations = ret_list_;
		ret_->status = RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;

#ifdef DUMP_FLOW_TO_STDERR
		fprintf(stderr, "%s:%u <---- rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * rtg_operations_simple_list_out_of_stt_operations_simple_list(const stt_operations_simple_list *)\n",
				__FILE__, __LINE__);
#endif

		return ret_;
	}
	assertion(operations->first != NULL);

	ret_list_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_operations_simple_list *)
#endif
			malloc(sizeof(rtg_operations_simple_list));
	forced_assertion(ret_list_ != NULL);

#ifndef NDEBUG
	ret_list_->first = NULL;
	ret_list_->next = NULL;
#endif

	single_operation_transformation_ =
			rtg_operation_out_of_stt_operation(
					operations->first,
					function_where_bindings);
	forced_assertion(single_operation_transformation_ != NULL);

	if (single_operation_transformation_->status !=
			RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS) {

		forced_assertion(single_operation_transformation_->status ==
				RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER);

		forced_assertion(single_operation_transformation_->error_messages !=
				NULL);

		forced_assertion(single_operation_transformation_->operation ==
				NULL);

		ret_->operations = NULL;

		ret_->error_messages =
				single_operation_transformation_->error_messages;
		single_operation_transformation_->error_messages = NULL;

		rtg_operation_out_of_stt_operation_ret_destructor(
				single_operation_transformation_);

		ret_->status = RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION;

		free(ret_list_);  /* XXX */

		return ret_;
	}

	assertion(single_operation_transformation_->status ==
			RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS);
	new_rtg_op_ = single_operation_transformation_->operation;
	single_operation_transformation_->operation = NULL;
	rtg_operation_out_of_stt_operation_ret_destructor(
			single_operation_transformation_);
	ret_list_->first = new_rtg_op_;
	operations_ptr_ = operations;
	ret_list_ptr_ = ret_list_;
	while (operations_ptr_->next != NULL) {
		ret_list_ptr_->next =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operations_simple_list *)
#endif
				malloc(sizeof(rtg_operations_simple_list));
		forced_assertion(ret_list_ptr_->next != NULL);
		single_operation_transformation_ =
				rtg_operation_out_of_stt_operation(
						operations_ptr_->next->first,
						function_where_bindings);
		assertion(single_operation_transformation_->status ==
				RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS);
		new_rtg_op_ = single_operation_transformation_->operation;
		single_operation_transformation_->operation = NULL;
		rtg_operation_out_of_stt_operation_ret_destructor(
				single_operation_transformation_);
		ret_list_ptr_->next->first = new_rtg_op_;
		operations_ptr_ = operations_ptr_->next;
		ret_list_ptr_ = ret_list_ptr_->next;
	}
	ret_list_ptr_->next = NULL;
	ret_->operations = ret_list_;
	ret_->status = RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "%s:%u <---- rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * rtg_operations_simple_list_out_of_stt_operations_simple_list(const stt_operations_simple_list *)\n",
			__FILE__, __LINE__);
#endif

	return ret_;
}
