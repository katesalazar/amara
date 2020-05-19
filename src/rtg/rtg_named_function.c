/*
 * Copyright 2018-2020 Mercedes Catherine Salazar
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

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_named_function *)
#endif
			malloc(sizeof(rtg_named_function));
	forced_assertion(ret_ != NULL);

	ret_->where_value_bindings_ = NULL;
	ret_->operations_ = NULL;
	ret_->name_ = NULL;

	ret_->type_ = RTG_NAMED_FUNCTION_TYPE_INVALID;

	return ret_;
}

rtg_named_function *
rtg_named_function_exhaustive_constructor(
		unsigned char type, const amara_string * name,
		const rtg_operations_simple_list * operations,
		const rtg_where_value_bindings_simple_list * where_value_bindings)
{
	rtg_named_function * ret_;

	if (name == NULL || operations == NULL ||
			where_value_bindings == NULL) {

		assertion(type == RTG_NAMED_FUNCTION_TYPE_INVALID);
	} else {
		assertion(type != RTG_NAMED_FUNCTION_TYPE_INVALID);
	}

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_named_function *)
#endif
			malloc(sizeof(rtg_named_function));
	forced_assertion(ret_ != NULL);

#ifndef NDEBUG
	/*if (name == NULL) {
		assertion(operations == NULL);
		assertion(where_value_bindings == NULL);
	}
	if (operations == NULL) {
		assertion(name == NULL);
		assertion(where_value_bindings == NULL);
	}
	if (where_value_bindings == NULL) {
		assertion(name == NULL);
		assertion(operations == NULL);
	}*/
#endif

	/*   Subsidiary of the next conditioned block. */
#ifndef NDEBUG
	if (name == NULL) {
		assertion(name == NULL);
	}
	if (operations == NULL) {
		assertion(operations == NULL);
	}
	if (where_value_bindings == NULL) {
		assertion(where_value_bindings == NULL);
	}
	if (name == NULL || operations == NULL) {
		if (name == NULL) {
			assertion(name == NULL);
		}
		if (operations == NULL) {
			assertion(operations == NULL);
		}
		if (where_value_bindings == NULL) {
			assertion(where_value_bindings == NULL);
		}
	}
	if (operations == NULL || where_value_bindings == NULL) {
		if (name == NULL) {
			assertion(name == NULL);
		}
		if (operations == NULL) {
			assertion(operations == NULL);
		}
		if (where_value_bindings == NULL) {
			assertion(where_value_bindings == NULL);
		}
	}
#endif

	if (name == NULL || operations == NULL || where_value_bindings == NULL) {
		/*
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
		*/
		ret_->name_ = NULL;
		ret_->operations_ = NULL;
		ret_->where_value_bindings_ = NULL;
		ret_->type_ = RTG_NAMED_FUNCTION_TYPE_INVALID;
		return ret_;
	}
	ret_->name_ = amara_string_copy_constructor(name);
	forced_assertion(ret_->name_ != NULL);
	ret_->operations_ = rtg_operations_simple_list_copy_constructor(
			operations);
	forced_assertion(ret_->operations_ != NULL);
	ret_->where_value_bindings_ =
			rtg_where_value_bindings_simple_list_copy_constructor(
					where_value_bindings);
	forced_assertion(ret_->where_value_bindings_ != NULL);
	ret_->type_ = type;
	forced_assertion(ret_->type_ != RTG_NAMED_FUNCTION_TYPE_INVALID);
	return ret_;
}

rtg_named_function *
rtg_named_function_copy_constructor(const rtg_named_function * original)
{
#ifndef NDEBUG
	amara_boolean equality_;
#endif
	rtg_named_function * ret_;

#ifndef NDEBUG
	assertion(original != NULL);
	assertion(original->type_ != RTG_NAMED_FUNCTION_TYPE_INVALID);
	assertion(original->name_ != NULL);
	assertion(original->name_->value_ != NULL);
	assertion(original->operations_ != NULL);
	assertion(original->where_value_bindings_ != NULL);
#endif

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_named_function *)
#endif
			malloc(sizeof(rtg_named_function));
	forced_assertion(ret_ != NULL);

	ret_->where_value_bindings_ =
			rtg_where_value_bindings_simple_list_copy_constructor(
					original->where_value_bindings_);
	forced_assertion(ret_->where_value_bindings_ != NULL);

	ret_->operations_ = rtg_operations_simple_list_copy_constructor(
			original->operations_);
	forced_assertion(ret_->operations_ != NULL);

	ret_->name_ = amara_string_copy_constructor(original->name_);
	forced_assertion(ret_->name_ != NULL);
#ifndef NDEBUG
	assertion(ret_->name_->value_ != NULL);
	equality_ = amara_string_equality(original->name_, ret_->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	ret_->type_ = original->type_;

	return ret_;
}

void
rtg_named_function_destructor(rtg_named_function * named_function)
{
	forced_assertion(named_function != NULL);
	if (named_function->type_ == RTG_NAMED_FUNCTION_TYPE_INVALID) {
		assertion(named_function->name_ == NULL);
		assertion(named_function->operations_ == NULL);
		assertion(named_function->where_value_bindings_ == NULL);
	} else {
		assertion(named_function->name_ != NULL);
		amara_string_destructor(named_function->name_);
		assertion(named_function->operations_ != NULL);
		rtg_operations_simple_list_destructor(
				named_function->operations_);
		assertion(named_function->where_value_bindings_ != NULL);
		rtg_where_value_bindings_simple_list_destructor(
				named_function->where_value_bindings_);
	}
	free(named_function);
}

void
rtg_named_function_out_of_stt_named_function_ret_destructor(
	rtg_named_function_out_of_stt_named_function_ret * input_ret)
{
	if (input_ret->status ==
			RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_SUCCESS) {

		forced_assertion(input_ret->error_messages == NULL);

		forced_assertion(input_ret->named_function == NULL);
	} else {
		forced_assertion(input_ret->status ==
				RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION);

		forced_assertion(input_ret->error_messages == NULL);

		forced_assertion(input_ret->named_function == NULL);
	}

	free(input_ret);
}

rtg_named_function_out_of_stt_named_function_ret *
rtg_named_function_out_of_stt_named_function(
		const stt_named_function * named_function)
{
	rtg_named_function_out_of_stt_named_function_ret * ret_;
	rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * operations_sub_ret_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif
	/*
	rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_ret * where_value_bindings_sub_ret_;
	*/
	rtg_where_value_bindings_simple_list * where_value_bindings_sub_ret_sub_;

	/*
	fprintf(stderr, "----> %s:%u rtg_named_function_out_of_stt_named_function_ret * rtg_named_function_out_of_stt_named_function(const stt_named_function *)\n",
			__FILE__, __LINE__);
	*/

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_named_function_out_of_stt_named_function_ret *)
#endif
			malloc(sizeof(rtg_named_function_out_of_stt_named_function_ret));
	forced_assertion(ret_ != NULL);

	ret_->status = RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_INVALID;

	ret_->error_messages = NULL;

	ret_->named_function = rtg_named_function_default_constructor();
	forced_assertion(ret_->named_function != NULL);

	/*
	where_value_bindings_sub_ret_ =
	*/
	where_value_bindings_sub_ret_sub_ =
			rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list(
					named_function->where_value_bindings_);
	forced_assertion(where_value_bindings_sub_ret_sub_ != NULL);

	operations_sub_ret_ =
			rtg_operations_simple_list_out_of_stt_operations_simple_list(
					named_function->operations_,
					named_function->where_value_bindings_);
	forced_assertion(operations_sub_ret_ != NULL);

	if (operations_sub_ret_->status !=
			RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

		forced_assertion(operations_sub_ret_->status ==
				RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION);

		forced_assertion(operations_sub_ret_->error_messages != NULL);

		forced_assertion(operations_sub_ret_->operations == NULL);

		rtg_named_function_destructor(ret_->named_function);
		ret_->named_function = NULL;

		ret_->error_messages = operations_sub_ret_->error_messages;
		operations_sub_ret_->error_messages = NULL;

		rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_destructor(
				operations_sub_ret_);

		ret_->status = RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION;

		rtg_where_value_bindings_simple_list_destructor(
				where_value_bindings_sub_ret_sub_);

		return ret_;
	}

	forced_assertion(operations_sub_ret_->status ==
			RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);

#ifndef NDEBUG
	/*   Subsidiary. */
	forced_assertion(named_function->where_value_bindings_ != NULL);

	/*   Subsidiary. */
	/*
	if (where_value_bindings_sub_ret_sub_->first == NULL) {

		forced_assertion(named_function->where_value_bindings_ == NULL ||
				named_function->where_value_bindings_->first == NULL);

		if (named_function->where_value_bindings_ != NULL) {

			forced_assertion(named_function->where_value_bindings_->first ==
					NULL);
		}
	}
	*/

	/*   Subsidiary. */
	/*
	forced_assertion(named_function->where_value_bindings_->first == NULL);
	*/

	/*
	forced_assertion(where_value_bindings_sub_ret_sub_->first != NULL ||
			named_function->where_value_bindings_ == NULL ||
			named_function->where_value_bindings_->first == NULL);
	*/

	if (where_value_bindings_sub_ret_sub_->first == NULL) {

		forced_assertion_two(named_function->where_value_bindings_ != NULL,
				"rtg_named_function.c: 330");
		forced_assertion_two(named_function->where_value_bindings_->first == NULL,
				"rtg_named_function.c: 332");
	} else {
		forced_assertion_two(where_value_bindings_sub_ret_sub_->first != NULL,
				"rtg_named_function.c: 334");
	}
#endif

	ret_->named_function->where_value_bindings_ =
			where_value_bindings_sub_ret_sub_;

	ret_->named_function->operations_ = operations_sub_ret_->operations;
	operations_sub_ret_->operations = NULL;
	rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_destructor(
			operations_sub_ret_);

	ret_->named_function->name_ =
			amara_string_copy_constructor(named_function->name_);

	forced_assertion(ret_->named_function->name_ != NULL);
	forced_assertion(ret_->named_function->name_->value_ != NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(
			ret_->named_function->name_, named_function->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

#ifndef NDEBUG
	assertion(named_function->type_ ==
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
#endif

	ret_->named_function->type_ = RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION;

	ret_->status = RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_SUCCESS;

	/*
	fprintf(stderr, "<---- %s:%u rtg_named_function_out_of_stt_named_function_ret * rtg_named_function_out_of_stt_named_function(const stt_named_function *)\n",
			__FILE__, __LINE__);
	*/

	return ret_;
}

void
rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret_destructor(
		rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret * input_ret)
{
#ifndef NDEBUG
	assertion(input_ret != NULL);
#endif
	forced_assertion(input_ret->status ==
			RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	forced_assertion(input_ret->error_messages == NULL);
	forced_assertion(input_ret->named_function == NULL);
	free(input_ret);
}

rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret *
rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list(
		const stt_named_function * stt_named_function,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
	rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret * ret_;
	rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * operations_sub_ret_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif
	rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_and_rtg_named_functions_ret * where_value_bindings_sub_ret_;
	rtg_where_value_bindings_simple_list * where_value_bindings_sub_ret_sub_;

	/*
	fprintf(stderr, "----> %s:%u rtg_named_function_out_of_stt_named_function_ret * rtg_named_function_out_of_stt_named_function(const stt_named_function *)\n",
			__FILE__, __LINE__);
	*/

#ifdef AMARA_USE_STD_CXX98
	ret_ = (rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret *) malloc(sizeof(rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret));
#else
	ret_ = malloc(sizeof(rtg_named_function_out_of_stt_named_function_ret));
#endif
	forced_assertion(ret_ != NULL);

	ret_->status = RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_INVALID;

	ret_->error_messages = NULL;

	ret_->named_function = rtg_named_function_default_constructor();
	forced_assertion(ret_->named_function != NULL);

	where_value_bindings_sub_ret_ = rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_and_rtg_named_functions(stt_named_function->where_value_bindings_, rtg_named_functions);
	forced_assertion(where_value_bindings_sub_ret_ != NULL);
	forced_assertion(where_value_bindings_sub_ret_->status == RTG_WHERE_VALUE_BINDINGS_SIMPLE_LIST_OUT_OF_STT_WHERE_VALUE_BINDINGS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_RET_STATUS_SUCCESS);

	operations_sub_ret_ = rtg_operations_simple_list_out_of_stt_operations_simple_list_and_stt_where_value_bindings_simple_list_and_rtg_named_functions(stt_named_function->operations_, stt_named_function->where_value_bindings_, rtg_named_functions);
	forced_assertion(operations_sub_ret_ != NULL);

	if (operations_sub_ret_->status != RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_AND_STT_WHERE_VALUE_BINDINGS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_RET_STATUS_SUCCESS) {

		forced_assertion(operations_sub_ret_->status == RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION);

		forced_assertion(operations_sub_ret_->error_messages != NULL);

		forced_assertion(operations_sub_ret_->operations == NULL);

		rtg_named_function_destructor(ret_->named_function);
		ret_->named_function = NULL;

		ret_->error_messages = operations_sub_ret_->error_messages;
		operations_sub_ret_->error_messages = NULL;

		rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_destructor(operations_sub_ret_);

		ret_->status = RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION;

		rtg_where_value_bindings_simple_list_destructor(where_value_bindings_sub_ret_sub_);

		return ret_;
	}

	forced_assertion(operations_sub_ret_->status == RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);

#ifndef NDEBUG
	/*   Subsidiary. */
	forced_assertion(stt_named_function->where_value_bindings_ != NULL);

	/*   Subsidiary. */
	/*
	if (where_value_bindings_sub_ret_sub_->first == NULL) {

		forced_assertion(stt_named_function->where_value_bindings_ == NULL || stt_named_function->where_value_bindings_->first == NULL);

		if (stt_named_function->where_value_bindings_ != NULL) {

			forced_assertion(stt_named_function->where_value_bindings_->first == NULL);
		}
	}
	*/

	/*   Subsidiary. */
	/*
	forced_assertion(stt_named_function->where_value_bindings_->first == NULL);
	*/

	/*
	forced_assertion(where_value_bindings_sub_ret_sub_->first != NULL || stt_named_function->where_value_bindings_ == NULL || stt_named_function->where_value_bindings_->first == NULL);
	*/

	if (where_value_bindings_sub_ret_sub_->first == NULL) {

		forced_assertion_two(stt_named_function->where_value_bindings_ != NULL, "rtg_named_function.c: 330");
		forced_assertion_two(stt_named_function->where_value_bindings_->first == NULL, "rtg_named_function.c: 332");
	} else {
		forced_assertion_two(where_value_bindings_sub_ret_sub_->first != NULL, "rtg_named_function.c: 334");
	}
#endif

	ret_->named_function->where_value_bindings_ = where_value_bindings_sub_ret_sub_;

	ret_->named_function->operations_ = operations_sub_ret_->operations;
	operations_sub_ret_->operations = NULL;
	rtg_operations_simple_list_out_of_stt_operations_simple_list_ret_destructor(operations_sub_ret_);

	ret_->named_function->name_ = amara_string_copy_constructor(stt_named_function->name_);

	forced_assertion(ret_->named_function->name_ != NULL);
	forced_assertion(ret_->named_function->name_->value_ != NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(ret_->named_function->name_, stt_named_function->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

#ifndef NDEBUG
	assertion(stt_named_function->type_ == STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
#endif

	ret_->named_function->type_ = RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION;

	ret_->status = RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_SUCCESS;

	/*
	fprintf(stderr, "<---- %s:%u rtg_named_function_out_of_stt_named_function_ret * rtg_named_function_out_of_stt_named_function(const stt_named_function *)\n",
			__FILE__, __LINE__);
	*/

	return ret_;
}

amara_boolean
rtg_named_function_callable_from_stt_named_function_call(
		const rtg_named_function * named_function,
		const stt_named_function_call * named_function_call)
{
	forced_assertion(named_function != NULL);
	forced_assertion(named_function_call != NULL);

	forced_assertion(0);  /* XXX */
	return AMARA_BOOLEAN_FALSE;  /* XXX */
}
