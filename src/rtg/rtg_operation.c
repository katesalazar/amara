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
 * src/rtg/rtg_operation.c: Amara runtime graph application function
 * operation.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `rtg_operation_args_simple_list_copy_constructor`. */
#include "rtg_operation_args_simple_list.h"

/*   For own definitions. */
#include "rtg_operation.h"

rtg_operation *
rtg_operation_copy_constructor(const rtg_operation * operation)
{
	rtg_operation * ret_;
	ret_ = malloc(sizeof(rtg_operation));
	ret_->args_ = rtg_operation_args_simple_list_copy_constructor(
			operation->args_);
	ret_->type_ = operation->type_;
	return ret_;
}

void
rtg_operation_destructor(rtg_operation * operation)
{
	assertion(operation != NULL);
	if (operation->type_ == RTG_OPERATION_TYPE_INVALID) {
		assertion(operation->args_ == NULL);
	} else {
		assertion(operation->args_ != NULL);
		rtg_operation_args_simple_list_destructor(operation->args_);
	}
	free(operation);
}

void
rtg_operation_out_of_stt_operation_ret_destructor(
		rtg_operation_out_of_stt_operation_ret * rtg_operation_out_of_stt_operation_ret_)
{
	assertion(rtg_operation_out_of_stt_operation_ret_ != NULL);
	if (rtg_operation_out_of_stt_operation_ret_->status ==
			RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS) {
		assertion(rtg_operation_out_of_stt_operation_ret_->operation !=
				NULL);
		if (rtg_operation_out_of_stt_operation_ret_->operation_was_moved ==
				AMARA_BOOLEAN_FALSE) {
			rtg_operation_destructor(
					rtg_operation_out_of_stt_operation_ret_->operation);
		}
	} else {
		assertion(rtg_operation_out_of_stt_operation_ret_->status ==
					RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_INVALID ||
				rtg_operation_out_of_stt_operation_ret_->status ==
					RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_ERROR_UNSPECIFIC);
		assertion(rtg_operation_out_of_stt_operation_ret_->operation ==
				NULL);
	}
	free(rtg_operation_out_of_stt_operation_ret_);
}

rtg_operation_out_of_stt_operation_ret *
rtg_operation_out_of_stt_operation(const stt_operation * operation)
{
	rtg_operation_out_of_stt_operation_ret * ret_;
	rtg_operation * sub_ret_;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret * rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_;
	rtg_operation_args_simple_list * sub_ret_args_;
	assertion(operation != NULL);
	ret_ = malloc(sizeof(rtg_operation_out_of_stt_operation_ret));
	ret_->status = RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_INVALID;
	ret_->operation = NULL;
	ret_->operation_was_moved = AMARA_BOOLEAN_FALSE;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_ =
			rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list(
					operation->args_);
	assertion(rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->status ==
			RTG_OPERATION_ARGS_SIMPLE_LIST_OUT_OF_STT_OPERATION_ARGS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	sub_ret_args_ = rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->operation_args;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->operation_args_were_moved =
			AMARA_BOOLEAN_TRUE;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_destructor(
			rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_);
	sub_ret_ = malloc(sizeof(rtg_operation));
	sub_ret_->args_ = sub_ret_args_;
	sub_ret_->type_ = operation->type_;
	ret_ = malloc(sizeof(rtg_operation_out_of_stt_operation_ret));
	ret_->operation = sub_ret_;
	ret_->status = RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS;
	return ret_;
}
