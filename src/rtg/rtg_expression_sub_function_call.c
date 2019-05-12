/*
 * Copyright 2019 Mercedes Catherine Salazar
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
 * src/rtg/rtg_expression_sub_function_call.c: Amara run time graph
 * function call type of expression.
 */

#include "../asr/assertion.h"

#include "rtg_expression_sub_function_call.h"

rtg_expression_sub_function_call *
rtg_expression_sub_function_call_exhaustive_constructor(
		const rtg_named_function * function,
		const rtg_expressions_simple_list * arguments)
{
	rtg_expression_sub_function_call * ret_;

#ifndef NDEBUG
	assertion(function != NULL);
	assertion(arguments != NULL);
#endif

	ret_ = malloc(sizeof(rtg_expression_sub_function_call));
	forced_assertion(ret_ != NULL);

	ret_->function_ = (rtg_named_function *) function;

	ret_->arguments_ = (rtg_expressions_simple_list *) arguments;

	return ret_;
}

/**  This is actually a _second degree inner_ to {@link
 * rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call}
 * so at the same time an inner to {@link
 * rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_inner}
 * which is an inner per se.
 *   @param stt_expression_sub_function_call Syntax Tree expression
 * sub (typed _function call_) to be converted into a Run Time Graph
 * expression sub equivalent (typed _function call_ too).
 *   @param rtg_named_function Run Time Graph function to be called,
 * after being successfully found by {@link
 * rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call}
 * and corresponding inner {@link
 * rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_inner}
 *   @param rtg_named_functions Every known named function, of course
 * including builtins to begin with, also including every known parsed
 * user defined named function (`stt_named_function`) that has been
 * already transformed to an `rtg_named_function`. `stt_named_function`
 * is no more than a transitional transient object with the goal to be
 * an intermediate step for getting one corresponding
 * `rtg_named_function` to be added to the global RTG named functions
 * directory, which is actually this param. */
rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret *
rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_and_rtg_named_function(
		const stt_expression_sub_function_call * stt_expression_sub_function_call,
		const rtg_named_function * rtg_named_function,
		const rtg_named_functions_simple_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret *
rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_and_rtg_named_function(
		const stt_expression_sub_function_call * stt_expression_sub_function_call,
		const rtg_named_function * rtg_named_function,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
#ifndef NDEBUG
	amara_string * concatenate_as_string_;
#endif
	rtg_expressions_simple_list * call_arguments_;
	rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret * ret_;
	rtg_expression_sub_function_call * sub_ret_;

#ifndef NDEBUG
	assertion(stt_expression_sub_function_call != NULL);
	assertion(stt_expression_sub_function_call->builtin_function_ != NULL);
	assertion(stt_expression_sub_function_call->function_name_ != NULL);
	assertion(stt_expression_sub_function_call->call_arguments_ != NULL);
	assertion(rtg_named_function != NULL);
#endif

#ifndef NDEBUG
	assertion(stt_expression_sub_function_call->function_name_->value_ !=
			NULL);
	concatenate_as_string_ =
			amara_string_exhaustive_constructor("concatenate");
	if (amara_identifiers_equality(
			stt_expression_sub_function_call->function_name_,
			concatenate_as_string_) == AMARA_BOOLEAN_TRUE) {
		/* It is a known builtin for which two and only two is the number of arguments. */
		located_assertion(stt_expression_sub_function_call->call_arguments_->first != NULL);
		assertion(stt_expression_sub_function_call->call_arguments_->next != NULL);
		assertion(stt_expression_sub_function_call->call_arguments_->next->first != NULL);
		assertion(stt_expression_sub_function_call->call_arguments_->next->next == NULL);
	}
	amara_string_destructor(concatenate_as_string_);
#endif

	call_arguments_ =
			rtg_expressions_simple_list_out_of_stt_expressions_simple_list(
					stt_expression_sub_function_call->call_arguments_,
					rtg_named_functions);
	forced_assertion(call_arguments_ != NULL);

	sub_ret_ = rtg_expression_sub_function_call_exhaustive_constructor(
			rtg_named_function, call_arguments_);

	ret_ = malloc(sizeof(
			rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret));
	forced_assertion(ret_ != NULL);
	ret_->error_messages = NULL;
	ret_->ret = sub_ret_;
	ret_->status = RTG_EXPRESSION_SUB_FUNCTION_CALL_OUT_OF_STT_EXPRESSION_SUB_FUNCTION_CALL_RET_STATUS_SUCCESS;

	rtg_expressions_simple_list_destructor(call_arguments_);

	return ret_;
}

/**  @param remaining_rtg_named_functions Same as
 * `all_rtg_named_functions`, but in iteration at this point, in order
 * to find the called function.
 *   @param all_rtg_named_functions Have to be passed down because each
 * of the call arguments is an expression, and as such it could be any
 * function call. */
rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret *
rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_inner(
		const stt_expression_sub_function_call * stt_expression_sub_function_call,
		const rtg_named_functions_simple_list * remaining_rtg_named_functions,
		const rtg_named_functions_simple_list * all_rtg_named_functions)
__attribute__((warn_unused_result))
;

rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret *
rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_inner(
		const stt_expression_sub_function_call * stt_expression_sub_function_call,
		const rtg_named_functions_simple_list * remaining_rtg_named_functions,
		const rtg_named_functions_simple_list * all_rtg_named_functions)
{
#ifndef NDEBUG
	amara_string * concatenate_as_string_;
#endif
	amara_boolean equality_;
	rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret * ret_;
	rtg_expression_sub_function_call * sub_ret_;

#ifndef NDEBUG
	assertion(stt_expression_sub_function_call != NULL);
	assertion(stt_expression_sub_function_call->builtin_function_ != NULL);
	assertion(stt_expression_sub_function_call->function_name_ != NULL);
	assertion(stt_expression_sub_function_call->call_arguments_ != NULL);
#endif

#ifndef NDEBUG
	assertion(stt_expression_sub_function_call->function_name_->value_ !=
			NULL);
	concatenate_as_string_ =
			amara_string_exhaustive_constructor("concatenate");
	if (amara_identifiers_equality(
			stt_expression_sub_function_call->function_name_,
			concatenate_as_string_) == AMARA_BOOLEAN_TRUE) {
		/* It is a known builtin for which two and only two is the number of arguments. */
		located_assertion(stt_expression_sub_function_call->call_arguments_->first != NULL);
		assertion(stt_expression_sub_function_call->call_arguments_->next != NULL);
		assertion(stt_expression_sub_function_call->call_arguments_->next->first != NULL);
		assertion(stt_expression_sub_function_call->call_arguments_->next->next == NULL);
	}
	amara_string_destructor(concatenate_as_string_);
#endif

	if (remaining_rtg_named_functions == NULL) {

		ret_ = malloc(sizeof(
				rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret));
		forced_assertion(ret_ != NULL);
		ret_->status = RTG_EXPRESSION_SUB_FUNCTION_CALL_OUT_OF_STT_EXPRESSION_SUB_FUNCTION_CALL_RET_STATUS_ERROR_FUNCTION_NOT_FOUND;
		forced_assertion(stt_expression_sub_function_call->function_name_ !=
				NULL);
		forced_assertion(stt_expression_sub_function_call->function_name_->value_ !=
				NULL);
		ret_->error_messages =
				amara_strings_simple_list_exhaustive_constructor_three_to_one(
						"unabe to find function named '",
						stt_expression_sub_function_call->function_name_->value_,
						"' in an **empty** rtg functions list");
		forced_assertion(ret_->error_messages != NULL);
#ifndef NDEBUG
		assertion(ret_->error_messages->first != NULL);
#endif
		/**/
		sub_ret_ = NULL;
		ret_->ret = sub_ret_;
		/**/
#ifndef NDEBUG
		assertion(ret_->ret == NULL);
#endif
		return ret_;
	}

	located_forced_assertion(remaining_rtg_named_functions->first != NULL);

#ifndef NDEBUG
	assertion(stt_expression_sub_function_call->function_name_->value_ !=
			NULL);
	assertion(remaining_rtg_named_functions->first->name_ != NULL);
	assertion(remaining_rtg_named_functions->first->name_->value_ != NULL);
#endif

	equality_ = amara_identifiers_equality(
			stt_expression_sub_function_call->function_name_,
			remaining_rtg_named_functions->first->name_);

	if (equality_ == AMARA_BOOLEAN_TRUE) {

		return rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_and_rtg_named_function(
				stt_expression_sub_function_call,
				remaining_rtg_named_functions->first,
				all_rtg_named_functions);
	}

	return rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_inner(
			stt_expression_sub_function_call,
			remaining_rtg_named_functions->next,
			all_rtg_named_functions);;
}

rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret *
rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call(
		const stt_expression_sub_function_call * stt_expression_sub_function_call,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
#ifndef NDEBUG
	amara_string * concatenate_as_string_;
#endif
	rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret * ret_;
	rtg_expression_sub_function_call * sub_ret_;

#ifndef NDEBUG
	assertion(stt_expression_sub_function_call != NULL);
	assertion(stt_expression_sub_function_call->builtin_function_ != NULL);
	assertion(stt_expression_sub_function_call->function_name_ != NULL);
	assertion(stt_expression_sub_function_call->call_arguments_ != NULL);
	located_assertion(rtg_named_functions != NULL);
#else
	/* FIXME */
	stt_expression_sub_function_call = NULL;
	rtg_named_functions = NULL;
#endif

#ifndef NDEBUG
	assertion(stt_expression_sub_function_call->function_name_->value_ !=
			NULL);
	concatenate_as_string_ =
			amara_string_exhaustive_constructor("concatenate");
	if (amara_identifiers_equality(
			stt_expression_sub_function_call->function_name_,
			concatenate_as_string_) == AMARA_BOOLEAN_TRUE) {
		/* It is a known builtin for which two and only two is the number of arguments. */
		located_assertion(stt_expression_sub_function_call->call_arguments_->first != NULL);
		assertion(stt_expression_sub_function_call->call_arguments_->next != NULL);
		assertion(stt_expression_sub_function_call->call_arguments_->next->first != NULL);
		assertion(stt_expression_sub_function_call->call_arguments_->next->next == NULL);
	}
	amara_string_destructor(concatenate_as_string_);
#endif

	/* FIXME */
	sub_ret_ = NULL;

	if (rtg_named_functions == NULL ||
			rtg_named_functions->first == NULL) {

		if (rtg_named_functions != NULL) {
			located_assertion(rtg_named_functions->next == NULL);
		}

		ret_ = malloc(sizeof(
				rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_ret));
		forced_assertion(ret_ != NULL);
		ret_->status = RTG_EXPRESSION_SUB_FUNCTION_CALL_OUT_OF_STT_EXPRESSION_SUB_FUNCTION_CALL_RET_STATUS_ERROR_FUNCTION_NOT_FOUND;
		forced_assertion(stt_expression_sub_function_call->function_name_ !=
				NULL);
		forced_assertion(stt_expression_sub_function_call->function_name_->value_ !=
				NULL);
		ret_->error_messages =
				amara_strings_simple_list_exhaustive_constructor_three_to_one(
						"unabe to find function named '",
						stt_expression_sub_function_call->function_name_->value_,
						"' in a **null** rtg functions list");
		forced_assertion(ret_->error_messages != NULL);
#ifndef NDEBUG
		assertion(ret_->error_messages->first != NULL);
#endif
		ret_->ret = sub_ret_;
#ifndef NDEBUG
		assertion(ret_->ret == NULL);
#endif
		return ret_;
	}

	return rtg_expression_sub_function_call_out_of_stt_expression_sub_function_call_inner(
			stt_expression_sub_function_call, rtg_named_functions,
			rtg_named_functions);
}
