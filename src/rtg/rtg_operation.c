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
#ifndef NDEBUG
			located_assertion(args->first == NULL);
#endif
		}
		ret_ = malloc(sizeof(rtg_operation));
		forced_assertion(ret_ != NULL);
		ret_->type_ = RTG_OPERATION_TYPE_INVALID;
		if (args != NULL) {
			ret_->args_ = rtg_operation_args_simple_list_copy_constructor(
					args);
			forced_assertion(ret_->args_ != NULL);
		} else {
			ret_->args_ = rtg_operation_args_simple_list_default_constructor();
			forced_assertion(ret_->args_ != NULL);
		}
		return ret_;
	}
#ifndef NDEBUG
	located_assertion(args != NULL);
#endif
	ret_ = malloc(sizeof(rtg_operation));
	forced_assertion(ret_ != NULL);
	ret_->args_ = rtg_operation_args_simple_list_copy_constructor(args);
	forced_assertion(ret_->args_ != NULL);
#ifndef NDEBUG
	located_assertion(type != RTG_OPERATION_TYPE_INVALID);
#endif
	if (type == RTG_OPERATION_TYPE_PRINT) {
#ifndef NDEBUG
		located_assertion(args->first != NULL);
#endif
		/* XXX Missing assertions here. */
		located_assertion(args->next == NULL);
		located_assertion(ret_->args_ != NULL);
		located_assertion(ret_->args_->first != NULL);
		/* XXX Missing assertions here. */
		located_assertion(ret_->args_->next == NULL);
	/*
	} else if (type == RTG_OPERATION_TYPE_ADDITION) {
		located_assertion(args->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		located_assertion(args->next != NULL);
		located_assertion(args->next->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		located_assertion(args->next->next == NULL);
		located_assertion(ret_->args_ != NULL);
		located_assertion(ret_->args_->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		located_assertion(ret_->args_->next != NULL);
		located_assertion(ret_->args_->next->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		located_assertion(ret_->args_->next->next == NULL);
	*/
	/*
	} else if (type == RTG_OPERATION_TYPE_PRINT_NO_CRLF) {
		located_assertion(args->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		located_assertion(args->next == NULL);
		located_assertion(ret_->args_ != NULL);
		located_assertion(ret_->args_->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		located_assertion(ret_->args_->next == NULL);
	*/
	} else if (type == RTG_OPERATION_TYPE_RETURN) {

		located_assertion(args->first != NULL);
		/* XXX Missing assertions here? */
		located_assertion(args->next == NULL);
		located_assertion(ret_->args_ != NULL);
		located_assertion(ret_->args_->first != NULL);
		/* XXX Missing assertions here? */
		located_assertion(ret_->args_->next == NULL);
	/*
	} else if (type == RTG_OPERATION_TYPE_READ_NATURAL_INTO_VARIABLE) {
		located_assertion(args->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		located_assertion(args->next == NULL);
		located_assertion(ret_->args_ != NULL);
		located_assertion(ret_->args_->first != NULL);
	*/
		/* XXX Missing assertions here. */
	/*
		located_assertion(ret_->args_->next == NULL);
	}
	*/
	} else {
		located_forced_unsigned_char_equality_assertion_two(type,
				RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE);
		located_assertion(args->first != NULL);
		/* XXX Missing assertions here. */
		located_assertion(args->next == NULL);
		located_assertion(ret_->args_ != NULL);
		located_assertion(ret_->args_->first != NULL);
		/* XXX Missing assertions here. */
		located_assertion(ret_->args_->next == NULL);
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

#ifdef DUMP_FLOW_TO_STDERR
		fprintf(stderr, "%u\n", operation->type_);
#endif
	}
	if (operation->type_ == RTG_OPERATION_TYPE_PRINT_CRLF) {
		/*   No args operation. */
		assertion(operation->args_->first == NULL);
	} else if (operation->type_ == RTG_OPERATION_TYPE_PRINT) {
		/*   One arg operation right now. Eventually, variable
		 * length. */
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->next == NULL);
	/*
	} else if (operation->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_TO_VARIABLE) {
	*/
		/*   One arg operation. */
	/*
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->next == NULL);
	*/
	/*
	} else if (operation->type_ == RTG_OPERATION_TYPE_MULTIPLICATION ||
			operation->type_ == RTG_OPERATION_TYPE_DIVISION ||
			operation->type_ == RTG_OPERATION_TYPE_ADDITION ||
			operation->type_ == RTG_OPERATION_TYPE_SUBSTRACTION) {

#ifndef NDEBUG
		if (operation->type_ == RTG_OPERATION_TYPE_ADDITION) {

			assertion(operation->type_ ==
					RTG_OPERATION_TYPE_ADDITION);
		} else if (operation->type_ ==
				RTG_OPERATION_TYPE_SUBSTRACTION) {

			assertion(operation->type_ ==
					RTG_OPERATION_TYPE_SUBSTRACTION);
		} else if (operation->type_ ==
				RTG_OPERATION_TYPE_MULTIPLICATION) {

			assertion(operation->type_ ==
					RTG_OPERATION_TYPE_MULTIPLICATION);
		} else {
			assertion(operation->type_ ==
					RTG_OPERATION_TYPE_DIVISION);
		}
#endif

	*/
		/*   Two args operation. */
	/*
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->next != NULL);
		assertion(operation->args_->next->first != NULL);
		assertion(operation->args_->next->next == NULL);
	*/
	} else if (operation->type_ == RTG_OPERATION_TYPE_RETURN) {

		/*   One arg operation. */
		located_assertion(operation->args_->first != NULL);
		located_assertion(operation->args_->next == NULL);
	/*
	} else if (operation->type_ ==
			RTG_FAKE_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION) {
	*/
		/*   One arg operation. */
	/*
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->next == NULL);
	*/
	/*
	} else if (operation->type_ != RTG_OPERATION_TYPE_PRINT_NO_CRLF) {
		assertion(operation->type_ ==
				RTG_OPERATION_TYPE_PRINT_NO_CRLF);
	*/
		/*   One arg operation. */
	/*
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->next == NULL);
	*/
	} else {
		forced_assertion(operation->type_ ==
				RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE);

		/*   One arg operation. */
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->next == NULL);
	}

	ret_ = malloc(sizeof(rtg_operation));
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
	} else if (operation_type == RTG_OPERATION_TYPE_RETURN) {
		returning_ = amara_string_exhaustive_constructor("return");
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
		const stt_where_value_bindings_simple_list * function_where_bindings,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
	rtg_operation_out_of_stt_operation_ret * ret_;
	rtg_operation * sub_ret_;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret * rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_;
	rtg_operation_args_simple_list * sub_ret_args_;

	forced_assertion_two(operation != NULL, "rtg_operation.c: 389\n");
	forced_assertion_two(operation->type_ != STT_OPERATION_TYPE_INVALID,
			"rtg_operation.c: 390\n");
	ret_ = malloc(sizeof(rtg_operation_out_of_stt_operation_ret));
	forced_assertion_two(ret_ != NULL, "rtg_operation.c: 393\n");
	ret_->status = RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_INVALID;
	ret_->error_messages = NULL;
	ret_->operation = NULL;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_ =
			rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list(
					operation->args_,
					operation->type_,
					function_where_bindings,
					rtg_named_functions);

	if (rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->status !=
			RTG_OPERATION_ARGS_SIMPLE_LIST_OUT_OF_STT_OPERATION_ARGS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

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

	forced_assertion_two(
			rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->status ==
					RTG_OPERATION_ARGS_SIMPLE_LIST_OUT_OF_STT_OPERATION_ARGS_SIMPLE_LIST_RET_STATUS_SUCCESS,
			"rtg_operation.c: 430\n");
	sub_ret_args_ = rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->operation_args;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_->operation_args =
			NULL;
	rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_destructor(
			rtg_operation_args_simple_list_out_of_stt_operation_args_simple_list_ret_);
	sub_ret_ = malloc(sizeof(rtg_operation));
	forced_assertion_two(sub_ret_ != NULL, "rtg_operation.c: 440\n");
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
	} else if (operation->type_ == STT_OPERATION_TYPE_RETURN) {  /* XXX */

		sub_ret_->type_ = RTG_OPERATION_TYPE_RETURN;  /* XXX */
	} else if (operation->type_ == STT_OPERATION_TYPE_RUN) {

		sub_ret_->type_ = RTG_OPERATION_TYPE_RUN;
	} else {
		forced_assertion_two(
				operation->type_ ==
						STT_OPERATION_TYPE_PRINT_CRLF,
				"rtg_operation.c: 485\n");
		sub_ret_->type_ = RTG_OPERATION_TYPE_PRINT_CRLF;
	}

	forced_assertion_two(ret_ != NULL, "rtg_operation.c: 492\n");
	ret_->operation = sub_ret_;
	ret_->status = RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS;

	return ret_;
}
