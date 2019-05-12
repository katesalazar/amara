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

	returning_ = malloc(sizeof(stt_operation));
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
	ret_ = malloc(sizeof(stt_operation));
	ret_->args_ = stt_operation_args_simple_list_copy_constructor(
			operation->args_);
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
	} else {
		assertion(operation->type_ ==
				STT_OPERATION_TYPE_PRINT);

		assertion(operation->args_ != NULL);
		stt_operation_args_simple_list_destructor(operation->args_);
	}

	free(operation);
}

void
stt_operation_set_type(
		stt_operation * operation, const stt_operation_type type)
{
	forced_assertion_two(operation != NULL, "stt_operation.c: 95\n");

	if (type == STT_OPERATION_TYPE_RETURN) {

		forced_assertion_two(
				operation->type_ == STT_OPERATION_TYPE_INVALID,
				"stt_operation.c: 99\n");

		forced_assertion_two(operation->args_ != NULL, "stt_operation.c: 103\n");
		forced_assertion_two(operation->args_->first != NULL, "stt_operation.c: 104\n");
		forced_assertion_two(operation->args_->first->type_ ==
				STT_OPERATION_ARG_TYPE_VALID, "stt_operation.c: 105\n");
		forced_assertion_two(operation->args_->first->node_ != NULL, "stt_operation.c: 107\n");
		assert_clean_expression_node(operation->args_->first->node_);
		forced_assertion_two(operation->args_->next == NULL, "stt_operation.c: 109\n");
	} else if (type == STT_OPERATION_TYPE_READ_NATURAL_INTO_VALUE) {

		forced_assertion_two(
				operation->type_ == STT_OPERATION_TYPE_INVALID,
				"stt_operation.c: 99\n");

		forced_assertion_two(operation->args_ != NULL, "stt_operation.c: 103\n");
		forced_assertion_two(operation->args_->first != NULL, "stt_operation.c: 104\n");
		forced_assertion_two(operation->args_->first->type_ ==
				STT_OPERATION_ARG_TYPE_VALID, "stt_operation.c: 105\n");
		forced_assertion_two(operation->args_->first->node_ != NULL, "stt_operation.c: 107\n");
		assert_clean_identifier_node(operation->args_->first->node_);
		forced_assertion_two(operation->args_->next == NULL, "stt_operation.c: 109\n");
	} else if (type == STT_OPERATION_TYPE_PRINT) {

		forced_assertion_two(type == STT_OPERATION_TYPE_PRINT,
				"stt_operation.c: 112\n");

		forced_assertion_two(operation->args_ != NULL, "stt_operation.c: 115\n");
		forced_assertion_two(operation->args_->first != NULL, "stt_operation.c: 116\n");
		forced_assertion_two(
				operation->args_->first->type_ ==
						STT_OPERATION_ARG_TYPE_VALID,
				"stt_operation.c: 117\n");
		forced_assertion_two(operation->args_->first->node_ != NULL, "stt_operation.c: 121\n");
		assert_clean_identifier_node(operation->args_->first->node_);
		forced_assertion_two(operation->args_->next == NULL, "stt_operation.c: 123\n");
	} else if (type == STT_OPERATION_TYPE_RUN) {

		forced_assertion_two(operation->args_ != NULL, "stt_operation.c: 139\n");
		forced_assertion_two(operation->args_->first != NULL, "stt_operation.c: 140\n");
		forced_assertion_two(operation->args_->first->type_ == STT_OPERATION_ARG_TYPE_VALID, "stt_operation.c: 140\n");
		forced_assertion_two(operation->args_->first->node_ != NULL, "stt_operation.c: 143\n");
		located_assertion_one(operation->args_->next == NULL);
		assert_clean_expression_node(operation->args_->first->node_);
		located_assertion_one(operation->args_->next == NULL);

		/*
		FIXME
		*/
	} else {
		forced_assertion_two(
				type == STT_OPERATION_TYPE_READ_INTEGER_INTO_VALUE,
				"stt_operation.c: 125\n");

		forced_assertion_two(
				operation->type_ == STT_OPERATION_TYPE_INVALID,
				"stt_operation.c: 129\n");

		forced_assertion_two(operation->args_ != NULL, "stt_operation.c: 133\n");
		forced_assertion_two(operation->args_->first != NULL, "stt_operation.c: 134\n");
		forced_assertion_two(
				operation->args_->first->type_ ==
						STT_OPERATION_ARG_TYPE_VALID,
				"stt_operation.c: 135\n");
		forced_assertion_two(operation->args_->first->node_ != NULL,
				"stt_operation.c: 139\n");
		assert_clean_identifier_node(operation->args_->first->node_);
		forced_assertion_two(operation->args_->next == NULL,
				"stt_operation.c: 142\n");
	}

	forced_assertion_two(operation->args_ != NULL,
			"stt_operation.c: 146\n");

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
stt_operation_is_cli_operation(const stt_operation * operation)
{
	forced_assertion_two(operation != NULL, "stt_operation.c: 168\n");

	if (operation->type_ == STT_OPERATION_TYPE_RETURN) {

		return AMARA_BOOLEAN_FALSE;
	} else if (operation->type_ == STT_OPERATION_TYPE_PRINT) {

		return AMARA_BOOLEAN_TRUE;
	} else if (operation->type_ == STT_OPERATION_TYPE_NEW_LINE) {

		return AMARA_BOOLEAN_TRUE;
	} else {
		forced_assertion_two(
				operation->type_ == STT_OPERATION_TYPE_READ_NATURAL_TO_VALUE,
				"stt_operation.c: 180\n");

		return AMARA_BOOLEAN_TRUE;
	}
}
