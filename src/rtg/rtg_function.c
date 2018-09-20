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
 * src/rtg/rtg_function.c: Amara run time graph application function.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "rtg_function.h"

rtg_function *
rtg_function_default_constructor()
{
	rtg_function * ret_;
	ret_ = malloc(sizeof(rtg_function));
	ret_->operations_ = NULL;
	ret_->name_ = NULL;
	ret_->type_ = RTG_FUNCTION_TYPE_INVALID;
	return ret_;
}

rtg_function *
rtg_function_copy_constructor(const rtg_function * original)
{
	rtg_function * ret_;
	ret_ = malloc(sizeof(rtg_function));
	ret_->operations_ = rtg_operations_simple_list_copy_constructor(original->operations_);
	ret_->name_ = amara_string_copy_constructor(original->name_);
	ret_->type_ = original->type_;
	return ret_;
}

rtg_function_out_of_stt_function_ret *
rtg_function_out_of_stt_function(const stt_function * function)
{
	rtg_function_out_of_stt_function_ret * ret_;
	rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * sub_ret_;
	fprintf(stderr, "----> %s:%u rtg_function_out_of_stt_function_ret * rtg_function_out_of_stt_function(const stt_function *)\n",
			__FILE__, __LINE__);
	ret_ = malloc(sizeof(rtg_function_out_of_stt_function_ret));
	ret_->status = RTG_FUNCTION_OUT_OF_STT_FUNCTION_RET_STATUS_INVALID;
	ret_->function = rtg_function_default_constructor();
	sub_ret_ = rtg_operations_simple_list_out_of_stt_operations_simple_list(
			function->operations_);
	assertion(sub_ret_ != NULL);
	assertion(sub_ret_->status ==
			RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	ret_->function->operations_ = sub_ret_->operations;
	ret_->function->name_ = amara_string_copy_constructor(function->name_);
	ret_->function->type_ = function->type_;
	ret_->status = RTG_FUNCTION_OUT_OF_STT_FUNCTION_RET_STATUS_SUCCESS;
	fprintf(stderr, "<---- %s:%u rtg_function_out_of_stt_function_ret * rtg_function_out_of_stt_function(const stt_function *)\n",
			__FILE__, __LINE__);
	return ret_;
}
