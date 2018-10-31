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

#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `rtg_operation_args_simple_list_copy_constructor`. */
#include "rtg_operation_args_simple_list.h"

/*   For own definitions. */
#include "rtg_operation.h"

rtg_operation *
rtg_operation_exhaustive_constructor(
		uint_fast8_t type,
		const struct rtg_operation_args_simple_list * args)
{
	rtg_operation * ret_;
	if (type == RTG_OPERATION_TYPE_INVALID) {
		if (args != NULL) {
			assertion(args->first == NULL);
		}
		ret_ = malloc(sizeof(rtg_operation));
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
	ret_ = malloc(sizeof(rtg_operation));
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
	} else if (type == RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE) {
		assertion(args->first != NULL);
		/* XXX Missing assertions here. */
		assertion(args->next == NULL);
		assertion(ret_->args_ != NULL);
		assertion(ret_->args_->first != NULL);
		/* XXX Missing assertions here. */
		assertion(ret_->args_->next == NULL);
	} else if (type == RTG_OPERATION_TYPE_ADDITION) {
		assertion(args->first != NULL);
		/* XXX Missing assertions here. */
		assertion(args->next != NULL);
		assertion(args->next->first != NULL);
		/* XXX Missing assertions here. */
		assertion(args->next->next == NULL);
		assertion(ret_->args_ != NULL);
		assertion(ret_->args_->first != NULL);
		/* XXX Missing assertions here. */
		assertion(ret_->args_->next != NULL);
		assertion(ret_->args_->next->first != NULL);
		/* XXX Missing assertions here. */
		assertion(ret_->args_->next->next == NULL);
	} else if (type == RTG_OPERATION_TYPE_PRINT_NO_CRLF) {
		assertion(args->first != NULL);
		/* XXX Missing assertions here. */
		assertion(args->next == NULL);
		assertion(ret_->args_ != NULL);
		assertion(ret_->args_->first != NULL);
		/* XXX Missing assertions here. */
		assertion(ret_->args_->next == NULL);
	} else {
		assertion(type ==
				RTG_OPERATION_TYPE_READ_NATURAL_INTO_VARIABLE);
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
#endif
	assertion(operation->type_ != RTG_OPERATION_TYPE_INVALID);
	assertion(operation->args_ != NULL);
	if (operation->args_->first == NULL) {
		fprintf(stderr, "%u\n", operation->type_);
	}
	if (operation->type_ == RTG_OPERATION_TYPE_PRINT_CRLF) {
		/*   No args operation. */
		assertion(operation->args_->first == NULL);
	} else if (operation->type_ == RTG_OPERATION_TYPE_PRINT) {
		/*   One arg operation right now. Eventually, variable
		 * length. */
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->next == NULL);
	} else if (operation->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE) {
		/*   One arg operation. */
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->next == NULL);
	} else if (operation->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE) {
		/*   One arg operation. */
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->next == NULL);
	} else if (operation->type_ == RTG_OPERATION_TYPE_MULTIPLICATION ||
			operation->type_ == RTG_OPERATION_TYPE_DIVISION ||
			operation->type_ == RTG_OPERATION_TYPE_ADDITION ||
			operation->type_ == RTG_OPERATION_TYPE_SUBSTRACTION) {
		/*   Two args operation. */
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->next != NULL);
		assertion(operation->args_->next->first != NULL);
		assertion(operation->args_->next->next == NULL);
	} else if (operation->type_ ==
			RTG_FAKE_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION) {
		/*   One arg operation. */
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->next == NULL);
	} else {
		if (operation->type_ != RTG_OPERATION_TYPE_PRINT_NO_CRLF) {
			fprintf(stderr, "%u\n", operation->type_);
		}
		assertion(operation->type_ ==
				RTG_OPERATION_TYPE_PRINT_NO_CRLF);
		/*   One arg operation. */
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->next == NULL);
	}
	ret_ = malloc(sizeof(rtg_operation));
	ret_->args_ = rtg_operation_args_simple_list_copy_constructor(
			operation->args_);

	assertion(operation->type_ != RTG_OPERATION_TYPE_INVALID);

	if (operation->type_ != RTG_OPERATION_TYPE_INVALID /* &&
			operation->type_ !=  */) {
		fprintf(stderr, "%u\n", operation->type_);
#ifndef NDEBUG
		operation_type_as_string_ =
				rtg_operation_type_as_string(operation->type_);
		fprintf(stderr, "%s\n", operation_type_as_string_->value_);
		amara_string_destructor(operation_type_as_string_);
#endif
	}
	/*
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
		if (operation->args_ != NULL) {
			rtg_operation_args_simple_list_destructor(
					operation->args_);
		}
	} else {
		assertion(operation->args_ != NULL);
		rtg_operation_args_simple_list_destructor(operation->args_);
	}
	free(operation);
}

amara_string *
rtg_operation_type_as_string(uint_fast8_t operation_type)
{
	amara_string * returning_;
	if (operation_type == RTG_OPERATION_TYPE_PRINT) {
		returning_ = amara_string_exhaustive_constructor("print");
	} else if (operation_type == RTG_OPERATION_TYPE_PRINT_CRLF) {
		returning_ = amara_string_exhaustive_constructor("print crlf");
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
	} else if (operation_type ==
			RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE) {
		returning_ = amara_string_exhaustive_constructor(
				"read natural to value");
	} else if (operation_type ==
			RTG_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE) {
		returning_ = amara_string_exhaustive_constructor(
				"read natural to variable");
	} else if (operation_type ==
			RTG_FAKE_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION) {
		returning_ = amara_string_exhaustive_constructor(
				"fake operation resolve type of expression");
	} else if (operation_type == RTG_OPERATION_TYPE_PRINT_NO_CRLF) {
		returning_ = amara_string_exhaustive_constructor(
				"print without crlf");
	} else if (operation_type == RTG_OPERATION_TYPE_INVALID) {
		returning_ = amara_string_exhaustive_constructor(
				"invalid operation type");
	} else {
		returning_ = amara_string_exhaustive_constructor(
				"operation type not found");
	}
	return returning_;
}

void
rtg_operation_out_of_stt_operation_ret_destructor(
		rtg_operation_out_of_stt_operation_ret * input_ret)
{
	assertion(input_ret != NULL);
	assertion(input_ret->status ==
			RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS);
	/*
	if (input_ret->status ==
			RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS) {
	*/
		assertion(input_ret->operation != NULL);
		if (input_ret->operation_was_moved == AMARA_BOOLEAN_FALSE) {
			rtg_operation_destructor(input_ret->operation);
		}
	/*
	} else {
		assertion(input_ret->status ==
				RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_ERROR_UNSPECIFIC);
		assertion(input_ret->operation == NULL);
	}
	*/
	free(input_ret);
}

rtg_operation_out_of_stt_operation_ret *
rtg_operation_out_of_stt_operation(const stt_operation * operation)
{
	rtg_operation_out_of_stt_operation_ret * ret_;
	rtg_operation * sub_ret_;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret * rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_;
	rtg_operation_args_simple_list * sub_ret_args_;
	assertion(operation != NULL);
	assertion(operation->type_ != STT_OPERATION_TYPE_INVALID);
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
	if (operation->type_ == STT_OPERATION_TYPE_PRINT) {
		sub_ret_->type_ = RTG_OPERATION_TYPE_PRINT;
	} else if (operation->type_ ==
				STT_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE) {
		sub_ret_->type_ = RTG_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE;
	} else if (operation->type_ ==
				STT_OPERATION_TYPE_READ_NATURAL_TO_VALUE) {
		sub_ret_->type_ = RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE;
	} else if (operation->type_ == STT_OPERATION_TYPE_MULTIPLICATION) {
		sub_ret_->type_ = RTG_OPERATION_TYPE_MULTIPLICATION;
	} else if (operation->type_ == STT_OPERATION_TYPE_DIVISION) {
		sub_ret_->type_ = RTG_OPERATION_TYPE_DIVISION;
	} else if (operation->type_ == STT_OPERATION_TYPE_ADDITION) {
		sub_ret_->type_ = RTG_OPERATION_TYPE_ADDITION;
	} else if (operation->type_ == STT_OPERATION_TYPE_SUBSTRACTION) {
		sub_ret_->type_ = RTG_OPERATION_TYPE_SUBSTRACTION;
	} else if (operation->type_ ==
			STT_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION) {
		sub_ret_->type_ =
				RTG_FAKE_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION;
	} else if (operation->type_ == STT_OPERATION_TYPE_PRINT_CRLF) {
		sub_ret_->type_ = RTG_OPERATION_TYPE_PRINT_CRLF;
	} else {
		if (operation->type_ != STT_OPERATION_TYPE_PRINT_NO_CRLF) {
			fprintf(stderr, "%u\n", operation->type_);
		}
		assertion(operation->type_ ==
				STT_OPERATION_TYPE_PRINT_NO_CRLF);
	}
	ret_ = malloc(sizeof(rtg_operation_out_of_stt_operation_ret));
	ret_->operation = sub_ret_;
	ret_->status = RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS;
	return ret_;
}
