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
 * src/rtg/rtg_operation_args_simple_list.c: Amara runtime graph
 * application function operation arguments simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "rtg_operation_args_simple_list.h"

rtg_operation_args_simple_list *
rtg_operation_args_simple_list_default_constructor()
{
	rtg_operation_args_simple_list * ret_;

	ret_ = malloc(sizeof(rtg_operation_args_simple_list));
	forced_assertion(ret_ != NULL);
	ret_->first = NULL;
	ret_->next = NULL;

	return ret_;
}

rtg_operation_args_simple_list *
rtg_operation_args_simple_list_copy_constructor(
		const rtg_operation_args_simple_list * operation_args)
{
	rtg_operation_args_simple_list * ret_;
	const rtg_operation_args_simple_list * operation_args_ptr_;
	rtg_operation_args_simple_list * ret_ptr_;
	rtg_operation_arg * operation_arg_;

	forced_assertion(operation_args != NULL);

	ret_ = malloc(sizeof(rtg_operation_args_simple_list));
	forced_assertion(ret_ != NULL);

	if (operation_args->first == NULL) {
		ret_->first = NULL;
		assertion(operation_args->next == NULL);
		ret_->next = NULL;
		return ret_;
	}
	operation_args_ptr_ = operation_args;
	ret_ptr_ = ret_;
	while (operation_args_ptr_->next != NULL) {
		assertion(operation_args_ptr_->first != NULL);
		operation_arg_ = rtg_operation_arg_copy_constructor(
				operation_args_ptr_->first);
		assertion(operation_arg_ != NULL);
		ret_ptr_->first = operation_arg_;
		ret_ptr_->next =
				malloc(sizeof(rtg_operation_args_simple_list));
		operation_args_ptr_ = operation_args_ptr_->next;
		ret_ptr_ = ret_ptr_->next;
	}
	assertion(operation_args_ptr_->first != NULL);
	operation_arg_ = rtg_operation_arg_copy_constructor(
			operation_args_ptr_->first);
	assertion(operation_arg_ != NULL);
	ret_ptr_->first = operation_arg_;
	ret_ptr_->next = NULL;
	return ret_;
}

void
rtg_operation_args_simple_list_destructor(
		rtg_operation_args_simple_list * operation_args)
{
	assertion(operation_args != NULL);
	if (operation_args->first == NULL) {
		assertion(operation_args->next == NULL);
	} else {
		rtg_operation_arg_destructor(operation_args->first);
	}
	if (operation_args->next != NULL) {
		rtg_operation_args_simple_list_destructor(
				operation_args->next);
	}
}

rtg_operation_args_simple_list *
rtg_operation_args_simple_list_push_front(
		rtg_operation_args_simple_list * operation_args,
		const struct rtg_operation_arg * operation_arg)
{
	rtg_operation_args_simple_list * new_list_node_;
	assertion(operation_args != NULL);
	assertion(operation_arg != NULL);
	if (operation_args->first == NULL) {
		assertion(operation_args->next == NULL);
		operation_args->first = rtg_operation_arg_copy_constructor(
				operation_arg);
		return operation_args;
	}
	new_list_node_ = malloc(sizeof(rtg_operation_arg));
	new_list_node_->first = rtg_operation_arg_copy_constructor(
			operation_arg);
	new_list_node_->next = operation_args;
	return new_list_node_;
}

unsigned char
rtg_operation_args_simple_list_length_inner(
		const rtg_operation_args_simple_list * operation_args)
{
	unsigned char ret_;
	unsigned char sub_ret_;
	assertion(operation_args != NULL);
	assertion(operation_args->first != NULL);
	if (operation_args->next == NULL) {
		ret_ = 1;
		return ret_;
	}
	sub_ret_ = rtg_operation_args_simple_list_length_inner(
			operation_args->next);
	assertion_two(sub_ret_ < 0xFF, "arithmetic overflow");
	ret_ = sub_ret_ + 1;
	return ret_;
}

unsigned char
rtg_operation_args_simple_list_length(
		const rtg_operation_args_simple_list * operation_args)
{
	assertion(operation_args != NULL);
	if (operation_args->first == NULL) {
		assertion(operation_args->next == NULL);
		return 0;
	}
	return rtg_operation_args_simple_list_length_inner(operation_args);
}

void
rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_destructor(
		rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret * input_ret)\
{
	forced_assertion(input_ret != NULL);

	if (input_ret->status ==
			RTG_OPERATION_ARGS_SIMPLE_LIST_OUT_OF_STT_OPERATION_ARGS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

		forced_assertion(input_ret->operation_args == NULL);

		/*
		if (input_ret->operation_args != NULL) {

			rtg_operation_args_simple_list_destructor(
					input_ret->operation_args);
		}
		*/
	} else {
		forced_assertion(input_ret->status ==
				RTG_OPERATION_ARGS_SIMPLE_LIST_OUT_OF_STT_OPERATION_ARGS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER);

		forced_assertion(input_ret->operation_args == NULL);
	}

	free(input_ret);
}

rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret *
rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list(
		const stt_operation_args_simple_list * operation_args,
		const stt_operation_type operation_type,
		const stt_where_value_bindings_simple_list * function_where_bindings,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret * ret_;
	rtg_operation_args_simple_list * sub_ret_;
	const stt_operation_args_simple_list * operation_args_ptr_;
	rtg_operation_args_simple_list * sub_ret_ptr_;
	rtg_operation_arg_out_of_stt_operation_arg_ret * sub_ret_ptr_element_ret_;
	rtg_operation_arg * sub_ret_ptr_element_;

	ret_ = malloc(sizeof(
			rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret));
	forced_assertion(ret_ != NULL);
	ret_->status = RTG_OPERATION_ARGS_SIMPLE_LIST_OUT_OF_STT_OPERATION_ARGS_SIMPLE_LIST_RET_STATUS_INVALID;
	ret_->error_messages = NULL;
	ret_->operation_args = NULL;
	assertion(operation_args != NULL);
	sub_ret_ = malloc(sizeof(rtg_operation_args_simple_list));
	forced_assertion(sub_ret_ != NULL);
	if (operation_args->first == NULL) {
		sub_ret_->first = NULL;
		assertion(operation_args->next == NULL);
		sub_ret_->next = NULL;
		ret_->operation_args = sub_ret_;
		ret_->status = RTG_OPERATION_ARGS_SIMPLE_LIST_OUT_OF_STT_OPERATION_ARGS_SIMPLE_LIST_RET_STATUS_SUCCESS;
		return ret_;
	}
	operation_args_ptr_ = operation_args;
	sub_ret_ptr_ = sub_ret_;
	while (operation_args_ptr_->next != NULL) {
		assertion(operation_args_ptr_->first != NULL);
		sub_ret_ptr_element_ret_ =
				rtg_operation_arg_out_of_stt_operation_arg(
						operation_args_ptr_->first,
						operation_type,
						function_where_bindings,
						rtg_named_functions);
		assertion(sub_ret_ptr_element_ret_->status ==
				RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_SUCCESS);
		sub_ret_ptr_element_ = sub_ret_ptr_element_ret_->operation_arg;
		sub_ret_ptr_element_ret_->operation_arg = NULL;
		rtg_operation_arg_out_of_stt_operation_arg_ret_destructor(
				sub_ret_ptr_element_ret_);
		sub_ret_ptr_->first = sub_ret_ptr_element_;
		sub_ret_ptr_->next =
				malloc(sizeof(rtg_operation_args_simple_list));
		forced_assertion(sub_ret_ptr_->next != NULL);
		operation_args_ptr_ = operation_args_ptr_->next;
		sub_ret_ptr_ = sub_ret_ptr_->next;
	}
	assertion(operation_args_ptr_->first != NULL);
	sub_ret_ptr_element_ret_ = rtg_operation_arg_out_of_stt_operation_arg(
			operation_args_ptr_->first, operation_type,
			function_where_bindings, rtg_named_functions);
	forced_assertion(sub_ret_ptr_element_ret_ != NULL);

	if (sub_ret_ptr_element_ret_->status !=
			RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_SUCCESS) {

		assertion(sub_ret_ptr_element_ret_->status ==
				RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_IDENTIFIER);

		ret_->operation_args = NULL;
		ret_->error_messages =
				sub_ret_ptr_element_ret_->error_messages;
		sub_ret_ptr_element_ret_->error_messages = NULL;

		forced_assertion(sub_ret_ptr_element_ret_->operation_arg ==
				NULL);
		rtg_operation_arg_out_of_stt_operation_arg_ret_destructor(
				sub_ret_ptr_element_ret_);
		/*
		free(sub_ret_ptr_element_ret_);
		*/

		ret_->status = RTG_OPERATION_ARGS_SIMPLE_LIST_OUT_OF_STT_OPERATION_ARGS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER;

		return ret_;
	}

	assertion(sub_ret_ptr_element_ret_->status ==
			RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_SUCCESS);
	sub_ret_ptr_element_ = sub_ret_ptr_element_ret_->operation_arg;
	sub_ret_ptr_element_ret_->operation_arg = NULL;
	rtg_operation_arg_out_of_stt_operation_arg_ret_destructor(
			sub_ret_ptr_element_ret_);
	sub_ret_ptr_->first = sub_ret_ptr_element_;
	sub_ret_ptr_->next = NULL;
	ret_->operation_args = sub_ret_;
	ret_->status = RTG_OPERATION_ARGS_SIMPLE_LIST_OUT_OF_STT_OPERATION_ARGS_SIMPLE_LIST_RET_STATUS_SUCCESS;

	return ret_;
}
