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
 * src/rtg/rtg_operation_arg.c: Amara run time graph application
 * function operation argument.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_node`. */
#include "../stt/stt_node.h"

/*   For own definitions. */
#include "rtg_operation_arg.h"

rtg_operation_arg *
rtg_operation_arg_copy_constructor(const rtg_operation_arg * operation_arg)
{
	rtg_operation_arg * ret_;
	assertion(operation_arg != NULL);
	assertion(operation_arg->type_ != RTG_OPERATION_ARG_TYPE_INVALID);
	ret_ = malloc(sizeof(rtg_operation_arg));
	if (operation_arg->type_ == RTG_OPERATION_ARG_TYPE_STRING_LITERAL) {
		ret_->string_literal_ = amara_string_copy_constructor(
				operation_arg->string_literal_);
	}
	ret_->type_ = operation_arg->type_;
	return ret_;
}

rtg_operation_arg_out_of_stt_operation_arg_ret *
rtg_operation_arg_out_of_stt_operation_arg(
		const stt_operation_arg * operation_arg)
{
	rtg_operation_arg_out_of_stt_operation_arg_ret * ret_;
	rtg_operation_arg * sub_ret_;
	ret_ = malloc(sizeof(rtg_operation_arg_out_of_stt_operation_arg_ret));
	ret_->status = RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_INVALID;
	assertion(operation_arg != NULL);
	assertion(operation_arg->node_ != NULL);
	/* assert_stt_node_is_valid(operation_arg->node_); */
	/* TASK needs to be a string literal... */
	assertion(operation_arg->node_->type_ == STT_NODE_TYPE_STRING_LITERAL);
	assertion(operation_arg->node_->string_literal_subnode_ != NULL);
	assertion(operation_arg->node_->string_literal_subnode_->string_literal_ != NULL);
	assertion(operation_arg->node_->string_literal_subnode_->string_literal_->value_ != NULL);
	sub_ret_ = malloc(sizeof(rtg_operation_arg));
	sub_ret_->string_literal_ = amara_string_copy_constructor(
			operation_arg->node_->string_literal_subnode_->string_literal_);
	sub_ret_->type_ = RTG_OPERATION_ARG_TYPE_STRING_LITERAL;
	ret_->operation_arg = sub_ret_;
	ret_->status = RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_SUCCESS;
	return ret_;
}
