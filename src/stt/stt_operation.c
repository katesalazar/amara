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
 * src/stt/stt_operation.c: Amara syntax tree application function
 * operation.
 */

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "stt_node.h"

/*   For own definitions. */
#include "stt_operation.h"

stt_operation *
stt_operation_default_constructor()
{
	stt_operation * returning_;

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_operation *)
#endif
			malloc(sizeof(stt_operation));
	forced_assertion(returning_ != NULL);

	returning_->type_ = STT_OPERATION_TYPE_INVALID;
	returning_->args_ = NULL;

	return returning_;
}

stt_operation *
stt_operation_copy_constructor(const stt_operation * operation)
{
	stt_operation * ret_;

	assertion(operation != NULL);
	assertion(operation->type_ != STT_OPERATION_TYPE_INVALID);

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_operation *)
#endif
			malloc(sizeof(stt_operation));
	forced_assertion(ret_ != NULL);

	ret_->args_ = stt_operation_args_simple_list_copy_constructor(
			operation->args_);
	forced_assertion(ret_->args_ != NULL);

	ret_->type_ = operation->type_;

	return ret_;
}

void
stt_operation_destructor(stt_operation * operation)
{
	assertion(operation != NULL);

	if (operation->type_ == STT_OPERATION_TYPE_INVALID) {

		assertion(operation->args_ == NULL);
	/*
	} else if (operation->type_ == STT_OPERATION_TYPE_PRINT_NO_CRLF) {

		assertion(operation->args_ != NULL);
		stt_operation_args_simple_list_destructor(operation->args_);
	*/
	} else if (operation->type_ ==
			STT_OPERATION_TYPE_READ_NATURAL_INTO_VALUE) {

		assertion(operation->args_ != NULL);
		stt_operation_args_simple_list_destructor(operation->args_);
	} else if (operation->type_ ==
			STT_OPERATION_TYPE_READ_INTEGER_INTO_VALUE) {

		assertion(operation->args_ != NULL);
		stt_operation_args_simple_list_destructor(operation->args_);
	} else if (operation->type_ ==
				STT_OPERATION_TYPE_PRINT) {

		assertion(operation->args_ != NULL);
		stt_operation_args_simple_list_destructor(operation->args_);
	} else {
		assertion(operation->type_ ==
				STT_OPERATION_TYPE_PRINT_CRLF);

		assertion(operation->args_ != NULL);
		stt_operation_args_simple_list_destructor(operation->args_);
	}

	ALSO TYPE EXECUTION

	free(operation);
}

void
stt_operation_set_type(
		stt_operation * operation, const stt_operation_type type)
{
	forced_assertion(operation != NULL);

	if (type == STT_OPERATION_TYPE_READ_NATURAL_INTO_VALUE) {

		forced_assertion(operation->type_ ==
				STT_OPERATION_TYPE_INVALID);

		forced_assertion(operation->args_ != NULL);
		forced_assertion(operation->args_->first != NULL);
		forced_assertion(operation->args_->first->type_ ==
				STT_OPERATION_ARG_TYPE_VALID);
		forced_assertion(operation->args_->first->node_ != NULL);
		stt_node_forced_assertion_clean_identifier_node(
				operation->args_->first->node_);
		forced_assertion(operation->args_->next == NULL);
	} else if (type == STT_OPERATION_TYPE_PRINT) {

		forced_assertion(type ==
				STT_OPERATION_TYPE_PRINT);

		forced_assertion(operation->args_ != NULL);
		forced_assertion(operation->args_->first != NULL);
		forced_assertion(operation->args_->first->type_ ==
				STT_OPERATION_ARG_TYPE_VALID);
		forced_assertion(operation->args_->first->node_ != NULL);
		stt_node_forced_assertion_clean_identifier_node(
				operation->args_->first->node_);
		forced_assertion(operation->args_->next == NULL);
	} else if (type == STT_OPERATION_TYPE_READ_INTEGER_INTO_VALUE) {

		forced_assertion(operation->type_ ==
				STT_OPERATION_TYPE_INVALID);

		forced_assertion(operation->args_ != NULL);
		forced_assertion(operation->args_->first != NULL);
		forced_assertion(operation->args_->first->type_ ==
				STT_OPERATION_ARG_TYPE_VALID);
		forced_assertion(operation->args_->first->node_ != NULL);
		stt_node_forced_assertion_clean_identifier_node(
				operation->args_->first->node_);
		forced_assertion(operation->args_->next == NULL);
	} else {
		forced_assertion(type == STT_OPERATION_TYPE_EXECUTION);

		forced_assertion(operation->type_ ==
				STT_OPERATION_TYPE_INVALID);

		forced_assertion(operation->args_ != NULL);
		forced_assertion(operation->args_->first != NULL);
		forced_assertion(operation->args_->first->type_ ==
				STT_OPERATION_ARG_TYPE_VALID);
		forced_assertion(operation->args_->first->node_ != NULL);
		stt_node_forced_assertion_clean_function_call_node(
				operation->args_->first->node_);
		forced_assertion(operation->args_->next == NULL);
	}

	forced_assertion(operation->args_ != NULL);

	operation->type_ = type;
}

void
stt_operation_set_args(
		stt_operation * operation,
		const stt_operation_args_simple_list * args)
{
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	forced_assertion(operation != NULL);
	forced_assertion(operation->type_ == STT_OPERATION_TYPE_INVALID);
	forced_assertion(args != NULL);
	forced_assertion(operation->args_ == NULL);
	operation->args_ =
			stt_operation_args_simple_list_copy_constructor(args);
	forced_assertion(operation->args_ != NULL);
#ifndef NDEBUG
	equality_ = stt_operation_args_simple_list_equality(
			operation->args_, args);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif
}

amara_boolean
stt_operation_equality(const stt_operation * o0, const stt_operation * o1)
{
	/*
	amara_boolean equality_;
	*/

#ifndef NDEBUG
	assertion(o0 != NULL);
	assertion(o1 != NULL);
#endif

	if (o0->type_ != o1->type_) {

		return AMARA_BOOLEAN_FALSE;
	}

#ifndef NDEBUG
	assertion(o0->args_ != NULL);
	assertion(o1->args_ != NULL);
#endif

	return stt_operation_args_simple_list_equality(o0->args_, o1->args_);
}

amara_boolean
stt_operations_equality(const stt_operation * o0, const stt_operation * o1)
{
	return stt_operation_equality(o0, o1);
}
