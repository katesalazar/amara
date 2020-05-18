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
 * src/rtg/rtg_operation.c: Amara runtime graph application function
 * operation.
 */

#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `rtg_operation_args_simple_list_copy_constructor`. */
#include "rtg_operation_args_simple_list.h"

/*   For own definitions. */
#include "rtg_operation.h"

rtg_operation *
rtg_operation_exhaustive_constructor(
		const rtg_operation_type type,
		const struct rtg_operation_args_simple_list * args)
{
	rtg_operation * ret_;
	if (type == RTG_OPERATION_TYPE_INVALID) {
		if (args != NULL) {
			assertion(args->first == NULL);
		}
		ret_ =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operation *)
#endif
				malloc(sizeof(rtg_operation));
		forced_assertion(ret_ != NULL);
		ret_->type_ = RTG_OPERATION_TYPE_INVALID;
		if (args != NULL) {
			ret_->args_ = rtg_operation_args_simple_list_copy_constructor(
					args);
		} else {
			ret_->args_ = rtg_operation_args_simple_list_default_constructor();
		}
		return ret_;
	}
	assertion(args != NULL);
	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_operation *)
#endif
			malloc(sizeof(rtg_operation));
	forced_assertion(ret_ != NULL);
	ret_->args_ = rtg_operation_args_simple_list_copy_constructor(args);
	assertion(type != RTG_OPERATION_TYPE_INVALID);
	if (type == RTG_OPERATION_TYPE_PRINT) {
		assertion(args->first != NULL);
		/* XXX Missing assertions here. */
		assertion(args->next == NULL);
		assertion(ret_->args_ != NULL);
		assertion(ret_->args_->first != NULL);
		/* XXX Missing assertions here. */
		assertion(ret_->args_->next == NULL);
	/*
	} else if (type == RTG_OPERATION_TYPE_ADDITION) {
		assertion(args->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		assertion(args->next != NULL);
		assertion(args->next->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		assertion(args->next->next == NULL);
		assertion(ret_->args_ != NULL);
		assertion(ret_->args_->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		assertion(ret_->args_->next != NULL);
		assertion(ret_->args_->next->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		assertion(ret_->args_->next->next == NULL);
	*/
	/*
	} else if (type == RTG_OPERATION_TYPE_PRINT_NO_CRLF) {
		assertion(args->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		assertion(args->next == NULL);
		assertion(ret_->args_ != NULL);
		assertion(ret_->args_->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		assertion(ret_->args_->next == NULL);
	*/
	/*
	} else if (type == RTG_OPERATION_TYPE_READ_NATURAL_INTO_VARIABLE) {
		assertion(args->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		assertion(args->next == NULL);
		assertion(ret_->args_ != NULL);
		assertion(ret_->args_->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		assertion(ret_->args_->next == NULL);
	}
	*/
	} else {
		forced_assertion(type ==
				RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE);
		assertion(args->first != NULL);
		/* XXX Missing assertions here. */
		assertion(args->next == NULL);
		assertion(ret_->args_ != NULL);
		assertion(ret_->args_->first != NULL);
		/* XXX Missing assertions here. */
		assertion(ret_->args_->next == NULL);
	}

	ret_->type_ = type;
	return ret_;
}

rtg_operation *
rtg_operation_copy_constructor(const rtg_operation * operation)
{
	rtg_operation * ret_;
#ifndef NDEBUG
	amara_string * operation_type_as_string_;
	assertion(operation->type_ != RTG_OPERATION_TYPE_INVALID);
#endif
	forced_assertion(operation->args_ != NULL);
	if (operation->args_->first == NULL) {

#ifdef DUMP_FLOW_TO_STDERR
		fprintf(stderr, "%u\n", operation->type_);
#endif
	}
	if (operation->type_ == RTG_OPERATION_TYPE_PRINT_CRLF) {
		/*   No args operation. */
		forced_assertion(operation->args_->first == NULL);
	} else if (operation->type_ == RTG_OPERATION_TYPE_PRINT) {
		/*   One arg operation right now. Eventually, variable
		 * length. */
		forced_assertion(operation->args_->first != NULL);
		forced_assertion(operation->args_->next == NULL);
	/*
	} else if (operation->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE) {
	*/
		/*   One arg operation. */
	/*
		forced_assertion(operation->args_->first != NULL);
		forced_assertion(operation->args_->next == NULL);
	*/
	/*
	} else if (operation->type_ == RTG_OPERATION_TYPE_MULTIPLICATION ||
			operation->type_ == RTG_OPERATION_TYPE_DIVISION ||
			operation->type_ == RTG_OPERATION_TYPE_ADDITION ||
			operation->type_ == RTG_OPERATION_TYPE_SUBSTRACTION) {

#ifndef NDEBUG
		if (operation->type_ == RTG_OPERATION_TYPE_ADDITION) {

			forced_assertion(operation->type_ ==
					RTG_OPERATION_TYPE_ADDITION);
		} else if (operation->type_ ==
				RTG_OPERATION_TYPE_SUBSTRACTION) {

			forced_assertion(operation->type_ ==
					RTG_OPERATION_TYPE_SUBSTRACTION);
		} else if (operation->type_ ==
				RTG_OPERATION_TYPE_MULTIPLICATION) {

			forced_assertion(operation->type_ ==
					RTG_OPERATION_TYPE_MULTIPLICATION);
		} else {
			forced_assertion(operation->type_ ==
					RTG_OPERATION_TYPE_DIVISION);
		}
#endif

	*/
		/*   Two args operation. */
	/*
		forced_assertion(operation->args_->first != NULL);
		forced_assertion(operation->args_->next != NULL);
		forced_assertion(operation->args_->next->first != NULL);
		forced_assertion(operation->args_->next->next == NULL);
	} else if (operation->type_ ==
			RTG_FAKE_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION) {
	*/
		/*   One arg operation. */
	/*
		forced_assertion(operation->args_->first != NULL);
		forced_assertion(operation->args_->next == NULL);
	*/
	/*
	} else if (operation->type_ != RTG_OPERATION_TYPE_PRINT_NO_CRLF) {
		forced_assertion(operation->type_ ==
				RTG_OPERATION_TYPE_PRINT_NO_CRLF);
	*/
		/*   One arg operation. */
	/*
		forced_assertion(operation->args_->first != NULL);
		forced_assertion(operation->args_->next == NULL);
	*/
	} else if (operation->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE) {

		/*   One arg operation. */
		forced_assertion(operation->args_->first != NULL);
		forced_assertion(operation->args_->next == NULL);
	} else {
		forced_assertion(operation->type_ ==
				RTG_OPERATION_TYPE_EXECUTION);

		/*   One arg operation. */
		forced_assertion(operation->args_->first != NULL);
		forced_assertion(operation->args_->next == NULL);
	}

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_operation *)
#endif
			malloc(sizeof(rtg_operation));
	forced_assertion(ret_ != NULL);
	ret_->args_ = rtg_operation_args_simple_list_copy_constructor(
			operation->args_);

	assertion(operation->type_ != RTG_OPERATION_TYPE_INVALID);

	/*
	if (operation->type_ != RTG_OPERATION_TYPE_INVALID *//* &&
			operation->type_ !=  *//*) {*/

#ifdef DUMP_FLOW_TO_STDERR
		fprintf(stderr, "%u\n", operation->type_);
#endif

#ifndef NDEBUG
		operation_type_as_string_ =
				rtg_operation_type_as_string(operation->type_);

#ifdef DUMP_FLOW_TO_STDERR
		fprintf(stderr, "%s\n", operation_type_as_string_->value_);
#endif

		amara_string_destructor(operation_type_as_string_);
#endif

	/*
	}
	assertion(operation->type_ == RTG_OPERATION_TYPE_INVALID);
	*/

	ret_->type_ = operation->type_;
	return ret_;
}

void
rtg_operation_destructor(rtg_operation * operation)
{
	assertion(operation != NULL);

	if (operation->type_ == RTG_OPERATION_TYPE_INVALID) {

		forced_assertion(operation->args_ != NULL);

		/*
		if (operation->args_ != NULL) {
		*/

			rtg_operation_args_simple_list_destructor(
					operation->args_);
		/*
		}
		*/
	} else {

		assertion(operation->args_ != NULL);
		rtg_operation_args_simple_list_destructor(operation->args_);
	}

	free(operation);
}

amara_string *
rtg_operation_type_as_string(const rtg_operation_type operation_type)
{
	amara_string * returning_;
	if (operation_type == RTG_OPERATION_TYPE_PRINT) {
		returning_ = amara_string_exhaustive_constructor("print");
	} else if (operation_type == RTG_OPERATION_TYPE_PRINT_CRLF) {
		returning_ = amara_string_exhaustive_constructor("print crlf");
	/*
	} else if (operation_type == RTG_OPERATION_TYPE_MULTIPLICATION) {
		returning_ = amara_string_exhaustive_constructor(
				"multiplication");
	} else if (operation_type == RTG_OPERATION_TYPE_DIVISION) {
		returning_ = amara_string_exhaustive_constructor("division");
	} else if (operation_type == RTG_OPERATION_TYPE_ADDITION) {
		returning_ = amara_string_exhaustive_constructor("addition");
	} else if (operation_type == RTG_OPERATION_TYPE_SUBSTRACTION) {
		returning_ = amara_string_exhaustive_constructor(
				"substraction");
	*/
	/*
	} else if (operation_type == RTG_OPERATION_TYPE_INVALID) {

		returning_ = amara_string_exhaustive_constructor(
				"invalid operation type");
	*/
	} else {
		assertion(operation_type ==
			RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE);

		returning_ = amara_string_exhaustive_constructor(
				"read natural to value");
	/*
	} else if (operation_type ==
			RTG_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE) {
		returning_ = amara_string_exhaustive_constructor(
				"read natural to variable");
	*/
	/*
	} else if (operation_type ==
			RTG_FAKE_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION) {
		returning_ = amara_string_exhaustive_constructor(
				"fake operation resolve type of expression");
	*/
	/*
	} else if (operation_type == RTG_OPERATION_TYPE_PRINT_NO_CRLF) {
		returning_ = amara_string_exhaustive_constructor(
				"print without crlf");
	*/
	/*
	} else {
		returning_ = amara_string_exhaustive_constructor(
				"operation type not found");
	*/
	}
	return returning_;
}

void
rtg_operation_out_of_stt_operation_ret_destructor(
		rtg_operation_out_of_stt_operation_ret * input_ret)
{
	forced_assertion(input_ret != NULL);

	/*
	assertion(input_ret->status ==
			RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS);
	*/

	if (input_ret->status ==
			RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS) {

		forced_assertion(input_ret->error_messages == NULL);

		forced_assertion(input_ret->operation == NULL);

		/*
		if (input_ret->operation != NULL) {

			rtg_operation_destructor(input_ret->operation);
		}
		*/
	} else {
		forced_assertion(input_ret->status ==
				RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER);

		forced_assertion(input_ret->error_messages == NULL);
		forced_assertion(input_ret->operation == NULL);
	}

	free(input_ret);
}

rtg_operation_out_of_stt_operation_ret *
rtg_operation_out_of_stt_operation(
		const stt_operation * operation,
		const struct stt_where_value_bindings_simple_list * function_where_bindings)
{
	rtg_operation_out_of_stt_operation_ret * ret_;
	rtg_operation * sub_ret_;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret * rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_;
	rtg_operation_args_simple_list * sub_ret_args_;

	forced_assertion(operation != NULL);
	forced_assertion(operation->type_ != STT_OPERATION_TYPE_INVALID);
#ifdef AMARA_USE_STD_CXX98
	ret_ = (rtg_operation_out_of_stt_operation_ret *) malloc(sizeof(rtg_operation_out_of_stt_operation_ret));
#else
	ret_ = malloc(sizeof(rtg_operation_out_of_stt_operation_ret));
#endif
	forced_assertion(ret_ != NULL);
	ret_->status = RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_INVALID;
	ret_->error_messages = NULL;
	ret_->operation = NULL;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_ = rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list(operation->args_, operation->type_, function_where_bindings);

	if (rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->status != RTG_OPERATION_ARGS_SIMPLE_LIST_OUT_OF_STT_OPERATION_ARGS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

		assertion(rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->status ==
				RTG_OPERATION_ARGS_SIMPLE_LIST_OUT_OF_STT_OPERATION_ARGS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER);

		assertion(rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->error_messages !=
				NULL);

		assertion(rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->operation_args ==
				NULL);

		ret_->operation = NULL;

		ret_->error_messages =
				rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->error_messages;
		rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->error_messages =
				NULL;

		rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_destructor(
				rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_);

		ret_->status = RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER;

		return ret_;
	}

	forced_assertion(rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->status ==
			RTG_OPERATION_ARGS_SIMPLE_LIST_OUT_OF_STT_OPERATION_ARGS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	sub_ret_args_ = rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->operation_args;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->operation_args =
			NULL;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_destructor(
			rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_);
	sub_ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_operation *)
#endif
			malloc(sizeof(rtg_operation));
	forced_assertion(sub_ret_ != NULL);
	sub_ret_->args_ = sub_ret_args_;

	if (operation->type_ == STT_OPERATION_TYPE_PRINT) {

		sub_ret_->type_ = RTG_OPERATION_TYPE_PRINT;
	/*
	} else if (operation->type_ ==
			STT_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE) {

		sub_ret_->type_ = RTG_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE;
	*/
	} else if (operation->type_ ==
			STT_OPERATION_TYPE_READ_NATURAL_TO_VALUE) {

		sub_ret_->type_ = RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE;
	} else if (operation->type_ ==
			STT_OPERATION_TYPE_READ_INTEGER_INTO_VALUE) {

		sub_ret_->type_ = RTG_OPERATION_TYPE_READ_INTEGER_INTO_VALUE;

	/*} else if (operation->type_ == STT_OPERATION_TYPE_MULTIPLICATION) {*/  /* XXX */

		/*sub_ret_->type_ = RTG_OPERATION_TYPE_MULTIPLICATION;*/  /* XXX */
	/*} else if (operation->type_ == STT_OPERATION_TYPE_DIVISION) {*/  /* XXX */

		/*sub_ret_->type_ = RTG_OPERATION_TYPE_DIVISION;*/  /* XXX */
	/*} else if (operation->type_ == STT_OPERATION_TYPE_ADDITION) {*/  /* XXX */

		/*sub_ret_->type_ = RTG_OPERATION_TYPE_ADDITION;*/  /* XXX */
	/*} else if (operation->type_ == STT_OPERATION_TYPE_SUBSTRACTION) {*/  /* XXX */

		/*sub_ret_->type_ = RTG_OPERATION_TYPE_SUBSTRACTION;*/  /* XXX */
	/*} else if (operation->type_ ==*/  /* XXX */
			/*STT_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION) {*/  /* XXX */

		/*sub_ret_->type_ =*/  /* XXX */
				/*RTG_FAKE_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION;*/  /* XXX */
	/*
	} else if (operation->type_ != STT_OPERATION_TYPE_PRINT_NO_CRLF) {

		assertion(operation->type_ ==
				STT_OPERATION_TYPE_PRINT_NO_CRLF);
	*/
	} else if (operation->type_ == STT_OPERATION_TYPE_PRINT_CRLF) {
		sub_ret_->type_ = RTG_OPERATION_TYPE_PRINT_CRLF;
	} else {
		forced_assertion(operation->type_ ==
				STT_OPERATION_TYPE_EXECUTION);
		sub_ret_->type_ = RTG_OPERATION_TYPE_EXECUTION;
	}

	forced_assertion(ret_ != NULL);
	ret_->operation = sub_ret_;
	ret_->status = RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS;

	return ret_;
}
