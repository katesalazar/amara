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
 * src/rtg/rtg_operation_arg.c: Amara run time graph application
 * function operation argument.
 */

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_node`. */
#include "../stt/stt_node.h"

/*   For own definitions. */
#include "rtg_operation_arg.h"

rtg_operation_arg *
rtg_operation_arg_default_constructor()
{
	rtg_operation_arg * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_operation_arg *)
#endif
			malloc(sizeof(rtg_operation_arg));
	forced_assertion(ret_ != NULL);

	ret_->string_literal_ = NULL;
	ret_->natural_literal_ = NULL;
	ret_->integer_literal_ = NULL;
	ret_->rational_literal_ = NULL;
	ret_->identifier_ = NULL;
	ret_->expression_ = NULL;
	ret_->operation_ = NULL;
	ret_->type_ = RTG_OPERATION_ARG_TYPE_INVALID;

	return ret_;
}

rtg_operation_arg *
rtg_operation_arg_copy_constructor(const rtg_operation_arg * operation_arg)
{
	rtg_operation_arg * ret_;

#ifndef NDEBUG
	assertion(operation_arg != NULL);
	assertion(operation_arg->type_ != RTG_OPERATION_ARG_TYPE_INVALID);
#endif

	ret_ = rtg_operation_arg_default_constructor();
#ifndef NDEBUG
	assertion(ret_ != NULL);
#endif

	if (operation_arg->type_ == RTG_OPERATION_ARG_TYPE_STRING_LITERAL) {

#ifndef NDEBUG
		assertion(operation_arg->string_literal_ != NULL);
#endif
		ret_->string_literal_ = amara_string_copy_constructor(
				operation_arg->string_literal_);
#ifndef NDEBUG
		assertion(ret_->string_literal_ != NULL);
#endif
		ret_->natural_literal_ = NULL;
		ret_->integer_literal_ = NULL;
		ret_->rational_literal_ = NULL;
		ret_->identifier_ = NULL;
		ret_->expression_ = NULL;
		ret_->operation_ = NULL;
	} else if (operation_arg->type_ ==
			RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL) {

		ret_->string_literal_ = NULL;
#ifndef NDEBUG
		assertion(operation_arg->natural_literal_ != NULL);
#endif
		ret_->natural_literal_ = amara_string_copy_constructor(
				operation_arg->natural_literal_);
#ifndef NDEBUG
		assertion(ret_->natural_literal_ != NULL);
#endif
		ret_->integer_literal_ = NULL;
		ret_->rational_literal_ = NULL;
		ret_->identifier_ = NULL;
		ret_->expression_ = NULL;
		ret_->operation_ = NULL;
	} else if (operation_arg->type_ ==
			RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED) {

		ret_->string_literal_ = NULL;
		ret_->natural_literal_ = NULL;
		ret_->integer_literal_ = NULL;
		ret_->rational_literal_ = NULL;
#ifndef NDEBUG
		assertion(operation_arg->identifier_ != NULL);
#endif
		ret_->identifier_ = amara_string_copy_constructor(
				operation_arg->identifier_);
#ifndef NDEBUG
		assertion(ret_->identifier_ != NULL);
#endif
		ret_->expression_ = NULL;
		ret_->operation_ = NULL;
	/*
	} else if (operation_arg->type_ == RTG_OPERATION_ARG_TYPE_OPERATION) {

		ret_->string_literal_ = NULL;
		ret_->natural_literal_ = NULL;
		ret_->integer_literal_ = NULL;
		ret_->rational_literal_ = NULL;
		ret_->identifier_ = NULL;
		ret_->expression_ = NULL;
#ifndef NDEBUG
		assertion(operation_arg->operation_ != NULL);
#endif
		ret_->operation_ = rtg_operation_copy_constructor(
				operation_arg->operation_);
#ifndef NDEBUG
		assertion(ret_->operation_ != NULL);
#endif
	*/
	} else {
		forced_assertion(operation_arg->type_ ==
				RTG_OPERATION_ARG_TYPE_EXPRESSION);

#ifndef NDEBUG
		assertion(operation_arg->expression_ != NULL);
#endif
		ret_->expression_ = rtg_expression_copy_constructor(
				operation_arg->expression_);
#ifndef NDEBUG
		assertion(ret_->expression_ != NULL);
#endif
		ret_->string_literal_ = NULL;
		ret_->natural_literal_ = NULL;
		ret_->integer_literal_ = NULL;
		ret_->rational_literal_ = NULL;
		ret_->identifier_ = NULL;
		ret_->operation_ = NULL;
	}

	ret_->type_ = operation_arg->type_;

	return ret_;
}

void
rtg_operation_arg_destructor(rtg_operation_arg * operation_arg)
{
#ifndef NDEBUG
	assertion(operation_arg != NULL);
#endif

	if (operation_arg->type_ == RTG_OPERATION_ARG_TYPE_STRING_LITERAL) {

#ifndef NDEBUG
		assertion(operation_arg->string_literal_ != NULL);
		assertion(operation_arg->natural_literal_ == NULL);
		assertion(operation_arg->identifier_ == NULL);
		assertion(operation_arg->expression_ == NULL);
		assertion(operation_arg->operation_ == NULL);
#endif
		amara_string_destructor(operation_arg->string_literal_);
	} else if (operation_arg->type_ ==
			RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL) {

#ifndef NDEBUG
		assertion(operation_arg->string_literal_ == NULL);
		assertion(operation_arg->natural_literal_ != NULL);
		assertion(operation_arg->identifier_ == NULL);
		assertion(operation_arg->expression_ == NULL);
		assertion(operation_arg->operation_ == NULL);
#endif
		amara_string_destructor(operation_arg->natural_literal_);
	} else if (operation_arg->type_ ==
			RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED) {

#ifndef NDEBUG
		assertion(operation_arg->string_literal_ == NULL);
		assertion(operation_arg->natural_literal_ == NULL);
		assertion(operation_arg->identifier_ != NULL);
		assertion(operation_arg->expression_ == NULL);
		assertion(operation_arg->operation_ == NULL);
#endif
		amara_string_destructor(operation_arg->identifier_);
	} else if (operation_arg->type_ == RTG_OPERATION_ARG_TYPE_EXPRESSION) {

#ifndef NDEBUG
		assertion(operation_arg->string_literal_ == NULL);
		assertion(operation_arg->natural_literal_ == NULL);
		assertion(operation_arg->identifier_ == NULL);
		assertion(operation_arg->expression_ != NULL);
		assertion(operation_arg->operation_ == NULL);
#endif
		rtg_expression_destructor(operation_arg->expression_);
	/*
	} else if (operation_arg->type_ == RTG_OPERATION_ARG_TYPE_OPERATION) {

#ifndef NDEBUG
		assertion(operation_arg->string_literal_ == NULL);
		assertion(operation_arg->natural_literal_ == NULL);
		assertion(operation_arg->identifier_ == NULL);
		assertion(operation_arg->expression_ == NULL);
		assertion(operation_arg->operation_ != NULL);
#endif
		rtg_operation_destructor(operation_arg->operation_);
	*/
	} else {
#ifndef NDEBUG
		assertion(operation_arg->type_ ==
				RTG_OPERATION_ARG_TYPE_INVALID);
#endif

#ifndef NDEBUG
		assertion(operation_arg->string_literal_ == NULL);
		assertion(operation_arg->natural_literal_ == NULL);
		assertion(operation_arg->identifier_ == NULL);
		assertion(operation_arg->expression_ == NULL);
		assertion(operation_arg->operation_ == NULL);
#endif
	}

	free(operation_arg);
}

void
rtg_operation_arg_set_type(
		rtg_operation_arg * operation_arg, unsigned char type)
{
	if (type == RTG_OPERATION_ARG_TYPE_STRING_LITERAL) {
		assertion(operation_arg->string_literal_ != NULL);
		assertion(operation_arg->string_literal_->value_ != NULL);
		assertion(operation_arg->natural_literal_ == NULL);
		assertion(operation_arg->identifier_ == NULL);
		assertion(operation_arg->expression_ == NULL);
		assertion(operation_arg->operation_ == NULL);
		operation_arg->type_ = RTG_OPERATION_ARG_TYPE_STRING_LITERAL;
	} else if (type == RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL) {
		assertion(operation_arg->string_literal_ == NULL);
		assertion(operation_arg->natural_literal_ != NULL);
		assertion(operation_arg->natural_literal_->value_ != NULL);
		assertion(operation_arg->identifier_ == NULL);
		assertion(operation_arg->expression_ == NULL);
		assertion(operation_arg->operation_ == NULL);
		operation_arg->type_ = RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL;
	} else if (type == RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED) {
		assertion(operation_arg->string_literal_ == NULL);
		assertion(operation_arg->natural_literal_ == NULL);
		assertion(operation_arg->identifier_ != NULL);
		assertion(operation_arg->identifier_->value_ != NULL);
		assertion(operation_arg->expression_ == NULL);
		assertion(operation_arg->operation_ == NULL);
		operation_arg->type_ =
				RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED;
	} else {
		assertion(type == RTG_OPERATION_ARG_TYPE_INVALID);
		if (operation_arg->type_ ==
				RTG_OPERATION_ARG_TYPE_STRING_LITERAL) {
			assertion(operation_arg->string_literal_ != NULL);
			assertion(operation_arg->string_literal_->value_ !=
					NULL);
			amara_string_destructor(
					operation_arg->string_literal_);
			operation_arg->string_literal_ = NULL;
			operation_arg->type_ = RTG_OPERATION_ARG_TYPE_INVALID;
		} else {
			assertion(operation_arg->type_ ==
					RTG_OPERATION_ARG_TYPE_INVALID);
		}
	}
}

void
rtg_operation_arg_set_string_literal(
		rtg_operation_arg * operation_arg,
		const amara_string * string_literal)
{
	if (operation_arg->string_literal_ != NULL) {

		forced_assertion(operation_arg->string_literal_->value_ != NULL);
		amara_string_destructor(operation_arg->string_literal_);
		operation_arg->string_literal_ = NULL;
	}

	forced_assertion(string_literal != NULL);

	/*
	if (string_literal != NULL) {
	*/

		forced_assertion(string_literal->value_ != NULL);
		operation_arg->string_literal_ =
				amara_string_copy_constructor(string_literal);
	/*
	}
	*/
}

void
rtg_operation_arg_set_natural_literal(
		rtg_operation_arg * operation_arg,
		const amara_string * natural_literal)
{
	if (operation_arg->natural_literal_ != NULL) {

		forced_assertion(operation_arg->natural_literal_->value_ !=
				NULL);
		amara_string_destructor(operation_arg->natural_literal_);
		operation_arg->natural_literal_ = NULL;
	}

	forced_assertion(natural_literal != NULL);

	/*
	if (natural_literal != NULL) {
	*/

		forced_assertion(natural_literal->value_ != NULL);
		operation_arg->natural_literal_ =
				amara_string_copy_constructor(natural_literal);
	/*
	}
	*/
}

void
rtg_operation_arg_set_identifier(
		rtg_operation_arg * operation_arg,
		const amara_string * identifier)
{
	if (operation_arg->identifier_ != NULL) {

		forced_assertion(operation_arg->identifier_->value_ != NULL);
		amara_string_destructor(operation_arg->identifier_);
		operation_arg->identifier_ = NULL;
	}

	forced_assertion(identifier != NULL);

	/*
	if (identifier != NULL) {
	*/

		assertion(identifier->value_ != NULL);
		operation_arg->identifier_ =
				amara_string_copy_constructor(identifier);
	/*
	}
	*/
}

void
rtg_operation_arg_out_of_stt_operation_arg_ret_destructor(
		rtg_operation_arg_out_of_stt_operation_arg_ret * rtg_operation_arg_out_of_stt_operation_arg_ret_)
{
	forced_assertion(rtg_operation_arg_out_of_stt_operation_arg_ret_ != NULL);

	if (rtg_operation_arg_out_of_stt_operation_arg_ret_->status ==
			RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_SUCCESS) {

		forced_assertion(rtg_operation_arg_out_of_stt_operation_arg_ret_->operation_arg ==
				NULL);

		/*
		rtg_operation_arg_destructor(
				rtg_operation_arg_out_of_stt_operation_arg_ret_->operation_arg);
		*/
	} else {
		forced_assertion(rtg_operation_arg_out_of_stt_operation_arg_ret_->status ==
				RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_IDENTIFIER);

		forced_assertion(rtg_operation_arg_out_of_stt_operation_arg_ret_->operation_arg ==
				NULL);
		forced_assertion(rtg_operation_arg_out_of_stt_operation_arg_ret_->error_messages ==
				NULL);
	}

	free(rtg_operation_arg_out_of_stt_operation_arg_ret_);
}

/*
*/
/*   Forward this declaration in order to avoid a circular dependency. */
/*
rtg_operation_out_of_stt_operation_ret *
rtg_operation_out_of_stt_operation(const stt_operation * operation)
__attribute__((warn_unused_result))
;
*/

rtg_operation_arg_out_of_stt_operation_arg_ret *
rtg_operation_arg_out_of_stt_operation_arg(
		const stt_operation_arg * operation_arg,
		const stt_operation_type operation_type,
		const struct stt_where_value_bindings_simple_list * function_where_bindings)
{
	const stt_where_value_binding * target_where_value_binding_;
	rtg_expression_out_of_stt_expression_ret * rtg_expression_out_of_stt_expression_ret_;
	/*
	struct rtg_operation_out_of_stt_operation_ret * rtg_operation_out_of_stt_operation_ret_;
	*/
	rtg_operation_arg * sub_ret_;
	rtg_operation_arg_out_of_stt_operation_arg_ret * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_operation_arg_out_of_stt_operation_arg_ret *)
#endif
			malloc(sizeof(rtg_operation_arg_out_of_stt_operation_arg_ret));
	forced_assertion(ret_ != NULL);
	ret_->status = RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_INVALID;
	ret_->operation_arg = NULL;
	ret_->error_messages = NULL;
#ifndef NDEBUG
	assertion(operation_arg != NULL);
	assertion(operation_arg->node_ != NULL);
	/* assert_stt_node_is_valid(operation_arg->node_); */
#endif
	if (operation_arg->node_->type_ == STT_NODE_TYPE_STRING_LITERAL) {
#ifndef NDEBUG
		assert_clean_string_literal_node(operation_arg->node_);
		assertion(operation_arg->node_->string_literal_subnode_ !=
				NULL);
		assertion(operation_arg->node_->string_literal_subnode_->string_literal_ !=
				NULL);
		assertion(operation_arg->node_->string_literal_subnode_->string_literal_->value_ !=
				NULL);
#endif
		sub_ret_ =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operation_arg *)
#endif
				malloc(sizeof(rtg_operation_arg));
		forced_assertion(sub_ret_ != NULL);
		sub_ret_->string_literal_ = amara_string_copy_constructor(
				operation_arg->node_->string_literal_subnode_->string_literal_);
		sub_ret_->natural_literal_ = NULL;
		sub_ret_->integer_literal_ = NULL;
		sub_ret_->rational_literal_ = NULL;
		sub_ret_->identifier_ = NULL;
		sub_ret_->expression_ = NULL;
		sub_ret_->operation_ = NULL;
		sub_ret_->type_ = RTG_OPERATION_ARG_TYPE_STRING_LITERAL;
	} else if (operation_arg->node_->type_ == STT_NODE_TYPE_NATURAL_LITERAL) {
#ifndef NDEBUG
		assert_clean_natural_literal_node(operation_arg->node_);
#endif
		/*
		fprintf(stderr, "%s:%u: %u\n", __FILE__, __LINE__, operation_arg->node_->type_);
		*/
#ifndef NDEBUG
		assertion(operation_arg->node_->type_ == STT_NODE_TYPE_NATURAL_LITERAL);
		assertion(operation_arg->node_->natural_literal_subnode_ !=
				NULL);
		assertion(operation_arg->node_->natural_literal_subnode_->raw_ !=
				NULL);
#endif
		sub_ret_ =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operation_arg *)
#endif
				malloc(sizeof(rtg_operation_arg));
		forced_assertion(sub_ret_ != NULL);
		sub_ret_->string_literal_ = NULL;
		sub_ret_->natural_literal_ = amara_string_copy_constructor(
				operation_arg->node_->natural_literal_subnode_->raw_);
		sub_ret_->integer_literal_ = NULL;
		sub_ret_->rational_literal_ = NULL;
		sub_ret_->identifier_ = NULL;
		sub_ret_->expression_ = NULL;
		sub_ret_->operation_ = NULL;
		sub_ret_->type_ = RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL;
	/*
	} else if (operation_arg->node_->type_ ==
			STT_NODE_TYPE_INTEGER_LITERAL) {

		assert_clean_integer_literal_node(operation_arg->node_);
		assertion(operation_arg->node_->integer_literal_subnode_ !=
				NULL);
		assertion(operation_arg->node_->integer_literal_subnode_->raw_ !=
				NULL);
		assertion(operation_arg->node_->integer_literal_subnode_->raw_->value_ !=
				NULL);
		sub_ret_ =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operation_arg *)
#endif
				malloc(sizeof(rtg_operation_arg));
		forced_assertion(sub_ret_ != NULL);
		sub_ret_->string_literal_ = NULL;
		sub_ret_->natural_literal_ = NULL;
		sub_ret_->integer_literal_ = amara_string_copy_constructor(
				operation_arg->node_->integer_literal_subnode_->raw_);
		sub_ret_->rational_literal_ = NULL;
		sub_ret_->identifier_ = NULL;
		sub_ret_->expression_ = NULL;
		sub_ret_->operation_ = NULL;
		sub_ret_->type_ = RTG_OPERATION_ARG_TYPE_INTEGER_LITERAL;
	*/
	} else if (operation_arg->node_->type_ == STT_NODE_TYPE_IDENTIFIER) {
#ifndef NDEBUG
		assert_clean_identifier_node(operation_arg->node_);
		assertion(operation_arg->node_->identifier_subnode_ != NULL);
		assertion(operation_arg->node_->identifier_subnode_->value_ !=
				NULL);
#endif
		if (operation_type == STT_OPERATION_TYPE_PRINT) {

			/*   Operation depends on the identifier. */
			target_where_value_binding_ =
					stt_where_value_bindings_simple_list_find_by_value_name(
							function_where_bindings,
							operation_arg->node_->identifier_subnode_->value_);
		} else {

			/*   Operation does not depend on the
			 * identifier, but creates it, actually. */
			target_where_value_binding_ = NULL;
		}

/*   Subsidiary block. */
#ifndef NDEBUG
		if (operation_type == STT_OPERATION_TYPE_PRINT) {

			forced_assertion(operation_type ==
					STT_OPERATION_TYPE_PRINT);
		}

		/*
		reactivated flow for the example 1
		forced_assertion(target_where_value_binding_ == NULL);
		*/

		if (target_where_value_binding_ == NULL) {

			forced_assertion(target_where_value_binding_ == NULL);
		}
#endif

		/*
		reactivated flow for the example 1
		if (operation_type == STT_OPERATION_TYPE_PRINT) {
			forced_assertion(target_where_value_binding_ == NULL);
		*/

		if (
				/*   Operation depends on the
				 * identifier. */
				operation_type == STT_OPERATION_TYPE_PRINT
				/*   There is no _where value_ binding
				 * the requested name. */
				&& target_where_value_binding_ == NULL
		) {

			/*   Identifier not found in the function's scope. */
			ret_->operation_arg = NULL;
			ret_->error_messages =
					amara_strings_simple_list_exhaustive_constructor_three_to_one(
							"unable to resolve identifier '",
							operation_arg->node_->identifier_subnode_->value_->value_,
							"' in the function's where value bindings scope");
			forced_assertion(ret_->error_messages != NULL);
			ret_->status = RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_IDENTIFIER;
			return ret_;
		} else {
			/*   Found identifier in the function's scope. */

		sub_ret_ =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operation_arg *)
#endif
				malloc(sizeof(rtg_operation_arg));
		forced_assertion(sub_ret_ != NULL);
		sub_ret_->string_literal_ = NULL;
		sub_ret_->natural_literal_ = NULL;
		sub_ret_->integer_literal_ = NULL;
		sub_ret_->rational_literal_ = NULL;
		sub_ret_->identifier_ = amara_string_copy_constructor(
				operation_arg->node_->identifier_subnode_->value_); /* XXX */
		sub_ret_->expression_ = NULL;
		sub_ret_->operation_ = NULL;
		sub_ret_->type_ =
				RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED;
		}
	/*
	} else if (operation_arg->node_->type_ == STT_NODE_TYPE_OPERATION) {

		assert_clean_operation_node(operation_arg->node_);
		assertion(operation_arg->node_->type_ ==
				STT_NODE_TYPE_OPERATION);
		assertion(operation_arg->node_->operation_subnode_ != NULL);
		assertion(operation_arg->node_->operation_subnode_->operation_ !=
				NULL);
		sub_ret_ =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operation_arg *)
#endif
				malloc(sizeof(rtg_operation_arg));
		forced_assertion(sub_ret_ != NULL);
		rtg_operation_out_of_stt_operation_ret_ =
				rtg_operation_out_of_stt_operation(
						operation_arg->node_->operation_subnode_->operation_);
#ifndef NDEBUG
		assertion(rtg_operation_out_of_stt_operation_ret_->status ==
				RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS);
#endif
		sub_ret_->string_literal_ = NULL;
		sub_ret_->natural_literal_ = NULL;
		sub_ret_->integer_literal_ = NULL;
		sub_ret_->rational_literal_ = NULL;
		sub_ret_->identifier_ = NULL;
		sub_ret_->expression_ = NULL;
		sub_ret_->operation_ =
				rtg_operation_out_of_stt_operation_ret_->operation;
		rtg_operation_out_of_stt_operation_ret_->operation = NULL;
		rtg_operation_out_of_stt_operation_ret_destructor(
				rtg_operation_out_of_stt_operation_ret_);
		sub_ret_->type_ = RTG_OPERATION_ARG_TYPE_IDENTIFIER;
	*/
	} else {
#ifndef NDEBUG
		assertion(operation_arg->node_->type_ == STT_NODE_TYPE_EXPRESSION);
		assert_clean_expression_node(operation_arg->node_);
		assertion(operation_arg->node_->type_ ==
				STT_NODE_TYPE_EXPRESSION);
		assertion(operation_arg->node_->expression_subnode_ != NULL);
		assertion(operation_arg->node_->expression_subnode_->expression_ !=
				NULL);
#endif
		sub_ret_ =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operation_arg *)
#endif
				malloc(sizeof(rtg_operation_arg));
		forced_assertion(sub_ret_ != NULL);
		rtg_expression_out_of_stt_expression_ret_ =
				rtg_expression_out_of_stt_expression(
						operation_arg->node_->expression_subnode_->expression_
						/* FIXME: MUST RECEIVE FUNCTION WHERE VALUE BINDINGS TOO */
				);
#ifndef NDEBUG
		assertion(rtg_expression_out_of_stt_expression_ret_->status ==
				RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS);
#endif
		sub_ret_->string_literal_ = NULL;
		sub_ret_->natural_literal_ = NULL;
		sub_ret_->integer_literal_ = NULL;
		sub_ret_->rational_literal_ = NULL;
		sub_ret_->identifier_ = NULL;
		sub_ret_->expression_ =
				rtg_expression_out_of_stt_expression_ret_->expression;
		rtg_expression_out_of_stt_expression_ret_->expression = NULL;
		rtg_expression_out_of_stt_expression_ret_destructor(
				rtg_expression_out_of_stt_expression_ret_);
		sub_ret_->operation_ = NULL;
		sub_ret_->type_ = RTG_OPERATION_ARG_TYPE_EXPRESSION;
	}

	ret_->operation_arg = sub_ret_;
	ret_->error_messages = NULL;
	ret_->status = RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_SUCCESS;

	return ret_;
}
