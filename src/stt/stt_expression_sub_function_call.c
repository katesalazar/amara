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
 * src/stt/stt_expression_sub_function_call.c: Amara syntax tree
 * function call type of expression sub node.
 */

#include "../asr/assertion.h"

#include "stt_expression_sub_function_call.h"

stt_expression_sub_function_call *
stt_expression_sub_function_call_copy_constructor(
		const stt_expression_sub_function_call * expression_sub_function_call)
{
	stt_expression_sub_function_call * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_expression_sub_function_call *)
#endif
			malloc(sizeof(stt_expression_sub_function_call));
	forced_assertion(ret_ != NULL);

#ifndef NDEBUG
	assertion(expression_sub_function_call != NULL);
#endif

#ifndef NDEBUG
	assertion(expression_sub_function_call->function_name_ != NULL);
#endif

	ret_->function_name_ = amara_string_copy_constructor(
			expression_sub_function_call->function_name_);
	forced_assertion(ret_->function_name_ != NULL);

#ifndef NDEBUG
	assertion(expression_sub_function_call->call_arguments_ != NULL);
#endif

	ret_->call_arguments_ = stt_expressions_simple_list_copy_constructor(
			expression_sub_function_call->call_arguments_);
	forced_assertion(ret_->call_arguments_ != NULL);

	if (expression_sub_function_call->builtin_function_ == NULL) {

		ret_->builtin_function_ =
#ifdef AMARA_USE_STD_CXX98
				(amara_boolean *)
#endif
				malloc(sizeof(amara_boolean));
		forced_assertion(ret_->builtin_function_ != NULL);
		(* (ret_->builtin_function_)) = AMARA_BOOLEAN_FALSE;
	} else {

		ret_->builtin_function_ =
#ifdef AMARA_USE_STD_CXX98
				(amara_boolean *)
#endif
				malloc(sizeof(amara_boolean));
		forced_assertion(ret_->builtin_function_ != NULL);

		if ((* (expression_sub_function_call->builtin_function_)) ==
				AMARA_BOOLEAN_TRUE) {

			(* (ret_->builtin_function_)) = AMARA_BOOLEAN_TRUE;
		} else {

			(* (ret_->builtin_function_)) = AMARA_BOOLEAN_FALSE;
		}
	}

	return ret_;
}

stt_expression_sub_function_call *
stt_expression_sub_function_call_exhaustive_constructor(
		const amara_string * function_name,
		const struct stt_expressions_simple_list * call_arguments,
		const amara_boolean * builtin_function)
{
	stt_expression_sub_function_call * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_expression_sub_function_call *)
#endif
			malloc(sizeof(stt_expression_sub_function_call));
	forced_assertion(ret_ != NULL);

#ifndef NDEBUG
	assertion(function_name != NULL);
#endif

	ret_->function_name_ = amara_string_copy_constructor(function_name);
	forced_assertion(ret_->function_name_ != NULL);

#ifndef NDEBUG
	assertion(call_arguments != NULL);
#endif

	ret_->call_arguments_ = stt_expressions_simple_list_copy_constructor(
			call_arguments);
	forced_assertion(ret_->call_arguments_ != NULL);

	if (builtin_function == NULL) {

		ret_->builtin_function_ =
#ifdef AMARA_USE_STD_CXX98
				(amara_boolean *)
#endif
				malloc(sizeof(amara_boolean));
		forced_assertion(ret_->builtin_function_ != NULL);
		(* (ret_->builtin_function_)) = AMARA_BOOLEAN_FALSE;
	} else {

		ret_->builtin_function_ =
#ifdef AMARA_USE_STD_CXX98
				(amara_boolean *)
#endif
				malloc(sizeof(amara_boolean));
		forced_assertion(ret_->builtin_function_ != NULL);

		if ((* builtin_function) == AMARA_BOOLEAN_TRUE) {

			(* (ret_->builtin_function_)) = AMARA_BOOLEAN_TRUE;
		} else {

			(* (ret_->builtin_function_)) = AMARA_BOOLEAN_FALSE;
		}
	}

	return ret_;
}

void
stt_expression_sub_function_call_destructor(
		stt_expression_sub_function_call * expression_sub_function_call)
{
#ifndef NDEBUG
	assertion_two(expression_sub_function_call != NULL, "stt_expression_sub_function_call.c: 153\n");
#endif

#ifndef NDEBUG
	assertion_two(expression_sub_function_call->function_name_ != NULL, "stt_expression_sub_function_call.c: 154\n");
#endif

	amara_string_destructor(expression_sub_function_call->function_name_);

#ifndef NDEBUG
	assertion_two(expression_sub_function_call->call_arguments_ != NULL, "stt_expression_sub_function_call.c: 155\n");
#endif

	stt_expressions_simple_list_destructor(
			expression_sub_function_call->call_arguments_);

#ifndef NDEBUG
	assertion_two(expression_sub_function_call->builtin_function_ != NULL, "stt_expression_sub_function_call.c: 156\n");
#endif

	free(expression_sub_function_call->builtin_function_);

	free(expression_sub_function_call);
}

amara_boolean
stt_expression_sub_function_call_equality(
		const stt_expression_sub_function_call * o0,
		const stt_expression_sub_function_call * o1)
{
	amara_boolean ret_;

#ifndef NDEBUG
	assertion_two(o0 != NULL, "stt_expression_sub_function_call.c: 184\n");
	assertion_two(o1 != NULL, "stt_expression_sub_function_call.c: 185\n");
#endif

#ifndef NDEBUG
	assertion_two(o0->function_name_ != NULL, "stt_expression_sub_function_call.c: 189\n");
	assertion_two(o1->function_name_ != NULL, "stt_expression_sub_function_call.c: 192\n");
#endif

	ret_ = amara_strings_equality(o0->function_name_, o1->function_name_);

	if (ret_ == AMARA_BOOLEAN_FALSE) {

		return ret_;
	}

#ifndef NDEBUG
	assertion_two(o0->call_arguments_ != NULL, "stt_expression_sub_function_call.c: 190\n");
	assertion_two(o1->call_arguments_ != NULL, "stt_expression_sub_function_call.c: 193\n");
#endif

	ret_ = stt_expressions_simple_list_equality(
			o0->call_arguments_, o1->call_arguments_);

	if (ret_ == AMARA_BOOLEAN_FALSE) {

		return ret_;
	}

#ifndef NDEBUG
	assertion_two(o0->builtin_function_ != NULL, "stt_expression_sub_function_call.c: 191\n");
	assertion_two(o1->builtin_function_ != NULL, "stt_expression_sub_function_call.c: 194\n");
#endif

	if ((* (o0->builtin_function_)) != (* (o1->builtin_function_))) {

		return AMARA_BOOLEAN_FALSE;
	}

	return AMARA_BOOLEAN_TRUE;
}
