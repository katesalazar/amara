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
 * src/rtg/rtg_named_function.c: Amara run time graph application named
 * function.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "rtg_named_function.h"

rtg_named_function *
rtg_named_function_default_constructor()
{
	rtg_named_function * ret_;
	ret_ = malloc(sizeof(rtg_named_function));
	ret_->operations_ = NULL;
	ret_->name_ = NULL;
	ret_->type_ = RTG_NAMED_FUNCTION_TYPE_INVALID;
	return ret_;
}

rtg_named_function *
rtg_named_function_exhaustive_constructor(
		uint_fast8_t type, const amara_string * name,
		const rtg_operations_simple_list * operations)
{
	rtg_named_function * ret_;
	if (name == NULL || operations == NULL) {
		assertion(type == RTG_NAMED_FUNCTION_TYPE_INVALID);
	} else {
		assertion(type != RTG_NAMED_FUNCTION_TYPE_INVALID);
	}
	ret_ = malloc(sizeof(rtg_named_function));
	if (name == NULL || operations == NULL) {
		if (name == NULL) {
			ret_->name_ = NULL;
		} else {
			ret_->name_ = amara_string_copy_constructor(name);
		}
		if (operations == NULL) {
			ret_->operations_ = NULL;
		} else {
			ret_->operations_ =
					rtg_operations_simple_list_copy_constructor(
							operations);
		}
		ret_->type_ = RTG_NAMED_FUNCTION_TYPE_INVALID;
		return ret_;
	}
	ret_->name_ = amara_string_copy_constructor(name);
	ret_->operations_ = rtg_operations_simple_list_copy_constructor(
			operations);
	ret_->type_ = type;
	return ret_;
}

rtg_named_function *
rtg_named_function_copy_constructor(const rtg_named_function * original)
{
	rtg_named_function * ret_;
	assertion(original != NULL);
	assertion(original->type_ != RTG_NAMED_FUNCTION_TYPE_INVALID);
	assertion(original->name_ != NULL);
	assertion(original->name_->value_ != NULL);
	assertion(original->operations_ != NULL);
	ret_ = malloc(sizeof(rtg_named_function));
	ret_->operations_ = rtg_operations_simple_list_copy_constructor(original->operations_);
	ret_->name_ = amara_string_copy_constructor(original->name_);
	ret_->type_ = original->type_;
	return ret_;
}

void
rtg_named_function_destructor(rtg_named_function * named_function)
{
	assertion(named_function != NULL);
	if (named_function->type_ == RTG_NAMED_FUNCTION_TYPE_INVALID) {
		assertion(named_function->name_ == NULL);
		assertion(named_function->operations_ == NULL);
	} else {
		assertion(named_function->name_ != NULL);
		amara_string_destructor(named_function->name_);
		assertion(named_function->operations_ != NULL);
		rtg_operations_simple_list_destructor(
				named_function->operations_);
	}
	free(named_function);
}

void
rtg_named_function_out_of_stt_named_function_ret_destructor(
	rtg_named_function_out_of_stt_named_function_ret * rtg_named_function_out_of_stt_named_function_ret_)
{
	if (rtg_named_function_out_of_stt_named_function_ret_->status ==
			RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_SUCCESS) {
		if (rtg_named_function_out_of_stt_named_function_ret_->named_function_was_moved ==
				AMARA_BOOLEAN_FALSE) {
			rtg_named_function_destructor(
					rtg_named_function_out_of_stt_named_function_ret_->named_function);
		}
	} else {
		assertion(rtg_named_function_out_of_stt_named_function_ret_->status ==
					RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_INVALID ||
				rtg_named_function_out_of_stt_named_function_ret_->status ==
						RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_ERROR_UNSPECIFIC);
		assertion(rtg_named_function_out_of_stt_named_function_ret_->named_function ==
				NULL);
	}
	free(rtg_named_function_out_of_stt_named_function_ret_);
}

rtg_named_function_out_of_stt_named_function_ret *
rtg_named_function_out_of_stt_named_function(
		const stt_named_function * named_function)
{
	rtg_named_function_out_of_stt_named_function_ret * ret_;
	rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * sub_ret_;
	fprintf(stderr, "----> %s:%u rtg_named_function_out_of_stt_named_function_ret * rtg_named_function_out_of_stt_named_function(const stt_named_function *)\n",
			__FILE__, __LINE__);
	ret_ = malloc(sizeof(rtg_named_function_out_of_stt_named_function_ret));
	ret_->status = RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_INVALID;
	ret_->named_function = rtg_named_function_default_constructor();
	sub_ret_ = rtg_operations_simple_list_out_of_stt_operations_simple_list(
			named_function->operations_);
	assertion(sub_ret_ != NULL);
	assertion(sub_ret_->status ==
			RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	ret_->named_function->operations_ = sub_ret_->operations;
	sub_ret_->operations_were_moved = AMARA_BOOLEAN_TRUE;
	rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_destructor(
			sub_ret_);
	ret_->named_function->name_ =
			amara_string_copy_constructor(named_function->name_);
	ret_->named_function->type_ = named_function->type_;
	ret_->named_function_was_moved = AMARA_BOOLEAN_FALSE;
	ret_->status = RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_SUCCESS;
	fprintf(stderr, "<---- %s:%u rtg_named_function_out_of_stt_named_function_ret * rtg_named_function_out_of_stt_named_function(const stt_named_function *)\n",
			__FILE__, __LINE__);
	return ret_;
}
