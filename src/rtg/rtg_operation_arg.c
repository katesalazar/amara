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

#include "../mmm/allocator.h"

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_node`. */
#include "../stt/stt_node.h"

#include "../stt/stt_named_function_call.h"

#include "rtg_forward_declarations.h"

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
rtg_operation_arg_set_named_function_call(
		rtg_operation_arg * operation_arg,
		const rtg_named_function_call * named_function_call)
{
	forced_assertion(operation_arg != NULL);
	forced_assertion(named_function_call != NULL);

	forced_assertion(0);  /* XXX */
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

/**  Friend declaration. */
rtg_named_functions_simple_list_find_by_name_ret *
rtg_named_functions_simple_list_find_by_name(
		const rtg_named_functions_simple_list * haystack,
		const amara_string * needle)
__attribute__((warn_unused_result))
;

/**  Friend declaration. */
amara_boolean
rtg_named_function_callable_from_stt_named_function_call(
		const rtg_named_function * named_function,
		const stt_named_function_call * named_function_call)
__amara__warn_unused_result__
;

rtg_operation_arg_out_of_stt_operation_arg_ret *
rtg_operation_arg_out_of_stt_operation_arg(
		const stt_operation_arg * operation_arg,
		const stt_operation_type operation_type,
		const struct stt_where_value_bindings_simple_list * function_where_bindings,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
	/**  TODO What was this for? */
	const stt_where_value_binding * target_where_value_binding_;
	/**  TODO What was this for? */
	rtg_expression_out_of_stt_expression_ret * rtg_expression_out_of_stt_expression_ret_;
	/*
	struct rtg_operation_out_of_stt_operation_ret * rtg_operation_out_of_stt_operation_ret_;
	*/
	/**  Returned entity. */
	rtg_operation_arg_out_of_stt_operation_arg_ret * ret_;
	/**  Returned entity's sub entity. */
	rtg_operation_arg * sub_ret_;
	/**  In case the operation arg is a function call, the function
	 * to be called will have to be found. */
	rtg_named_functions_simple_list_find_by_name_ret * find_rtg_named_function_ret_;
	/**  In case the operation argument is a function call, once the
	 * function to be called is found, it must be checked that the
	 * particular function is actually callable from the function
	 * call (types compatibility, etc.). */
	amara_boolean function_callable_from_current_call_;
	/**  Holds the return of the order to create an RTG named
	 * function call out of an STT named function call and the
	 * corresponding RTG named function. */
	rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function_ret * rtg_named_function_call_transformation_ret_;

#ifdef AMARA_USE_STD_CXX98
	ret_ = (rtg_operation_arg_out_of_stt_operation_arg_ret *) amara_malloc(sizeof(rtg_operation_arg_out_of_stt_operation_arg_ret));
	/*
	ret_ = (rtg_operation_arg_out_of_stt_operation_arg_ret *) amara_malloc_rtg_operation_arg_out_of_stt_operation_arg_ret();
	*/
#else
	ret_ = amara_malloc(sizeof(rtg_operation_arg_out_of_stt_operation_arg_ret));
	/*
	ret_ = amara_malloc_rtg_operation_arg_out_of_stt_operation_arg_ret();
	*/
#endif
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
		assertion(operation_arg->node_->string_literal_subnode_ != NULL);
		assertion(operation_arg->node_->string_literal_subnode_->string_literal_ != NULL);
		assertion(operation_arg->node_->string_literal_subnode_->string_literal_->value_ != NULL);
#endif
		sub_ret_ =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operation_arg *)
#endif
				malloc(sizeof(rtg_operation_arg));
		forced_assertion(sub_ret_ != NULL);
		sub_ret_->string_literal_ = amara_string_copy_constructor(operation_arg->node_->string_literal_subnode_->string_literal_);
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
		assertion(operation_arg->node_->natural_literal_subnode_ != NULL);
		assertion(operation_arg->node_->natural_literal_subnode_->raw_ != NULL);
#endif
		sub_ret_ =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operation_arg *)
#endif
				malloc(sizeof(rtg_operation_arg));
		forced_assertion(sub_ret_ != NULL);
		sub_ret_->string_literal_ = NULL;
		sub_ret_->natural_literal_ = amara_string_copy_constructor(operation_arg->node_->natural_literal_subnode_->raw_);
		sub_ret_->integer_literal_ = NULL;
		sub_ret_->rational_literal_ = NULL;
		sub_ret_->identifier_ = NULL;
		sub_ret_->expression_ = NULL;
		sub_ret_->operation_ = NULL;
		sub_ret_->type_ = RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL;
	/*
	} else if (operation_arg->node_->type_ == STT_NODE_TYPE_INTEGER_LITERAL) {
#ifndef NDEBUG
		assert_clean_integer_literal_node(operation_arg->node_);
		assertion(operation_arg->node_->integer_literal_subnode_ != NULL);
		assertion(operation_arg->node_->integer_literal_subnode_->raw_ != NULL);
		assertion(operation_arg->node_->integer_literal_subnode_->raw_->value_ != NULL);
#endif
		sub_ret_ =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operation_arg *)
#endif
				malloc(sizeof(rtg_operation_arg));
		forced_assertion(sub_ret_ != NULL);
		sub_ret_->string_literal_ = NULL;
		sub_ret_->natural_literal_ = NULL;
		sub_ret_->integer_literal_ = amara_string_copy_constructor(operation_arg->node_->integer_literal_subnode_->raw_);
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
			target_where_value_binding_ = stt_where_value_bindings_simple_list_find_by_value_name(function_where_bindings, operation_arg->node_->identifier_subnode_->value_);
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

		if (1
				/*   Operation depends on the
				 * identifier. */
				&& operation_type == STT_OPERATION_TYPE_PRINT
				/*   There is no _where value_ binding
				 * the requested name. */
				&& target_where_value_binding_ == NULL
		) {

			/*   Identifier not found in the function's scope. */
			ret_->operation_arg = NULL;
			ret_->error_messages = amara_strings_simple_list_exhaustive_constructor_three_to_one("unable to resolve identifier '", operation_arg->node_->identifier_subnode_->value_->value_, "' in the function's where value bindings scope");
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
			sub_ret_->identifier_ = amara_string_copy_constructor(operation_arg->node_->identifier_subnode_->value_); /* XXX */
		sub_ret_->expression_ = NULL;
		sub_ret_->operation_ = NULL;
			sub_ret_->type_ = RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED;
		}
	/*
	} else if (operation_arg->node_->type_ == STT_NODE_TYPE_OPERATION) {

#ifndef NDEBUG
		assert_clean_operation_node(operation_arg->node_);
		assertion(operation_arg->node_->operation_subnode_ != NULL);
		assertion(operation_arg->node_->operation_subnode_->operation_ != NULL);
#endif
		sub_ret_ =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operation_arg *)
#endif
				malloc(sizeof(rtg_operation_arg));
		forced_assertion(sub_ret_ != NULL);
		rtg_operation_out_of_stt_operation_ret_ = rtg_operation_out_of_stt_operation(operation_arg->node_->operation_subnode_->operation_);
#ifndef NDEBUG
		assertion(rtg_operation_out_of_stt_operation_ret_->status == RTG_OPERATION_OUT_OF_STT_OPERATION_RET_STATUS_SUCCESS);
#endif
		sub_ret_->string_literal_ = NULL;
		sub_ret_->natural_literal_ = NULL;
		sub_ret_->integer_literal_ = NULL;
		sub_ret_->rational_literal_ = NULL;
		sub_ret_->identifier_ = NULL;
		sub_ret_->expression_ = NULL;
		sub_ret_->operation_ = rtg_operation_out_of_stt_operation_ret_->operation;
		rtg_operation_out_of_stt_operation_ret_->operation = NULL;
		rtg_operation_out_of_stt_operation_ret_destructor(rtg_operation_out_of_stt_operation_ret_);
		sub_ret_->type_ = RTG_OPERATION_ARG_TYPE_IDENTIFIER;
	*/
	} else if (operation_arg->node_->type_ == STT_NODE_TYPE_EXPRESSION) {
#ifndef NDEBUG
		assert_clean_expression_node(operation_arg->node_);
		assertion(operation_arg->node_->expression_subnode_ != NULL);
		assertion(operation_arg->node_->expression_subnode_->expression_ != NULL);
#endif
		sub_ret_ =
#ifdef AMARA_USE_STD_CXX98
				(rtg_operation_arg *)
#endif
				malloc(sizeof(rtg_operation_arg));
		forced_assertion(sub_ret_ != NULL);
		rtg_expression_out_of_stt_expression_ret_ = rtg_expression_out_of_stt_expression(operation_arg->node_->expression_subnode_->expression_);  /* FIXME: MUST RECEIVE FUNCTION WHERE VALUE BINDINGS TOO */
#ifndef NDEBUG
		assertion(rtg_expression_out_of_stt_expression_ret_->status == RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS);
#endif
		sub_ret_->string_literal_ = NULL;
		sub_ret_->natural_literal_ = NULL;
		sub_ret_->integer_literal_ = NULL;
		sub_ret_->rational_literal_ = NULL;
		sub_ret_->identifier_ = NULL;
		sub_ret_->expression_ = rtg_expression_out_of_stt_expression_ret_->expression;
		rtg_expression_out_of_stt_expression_ret_->expression = NULL;
		rtg_expression_out_of_stt_expression_ret_destructor(rtg_expression_out_of_stt_expression_ret_);
		sub_ret_->operation_ = NULL;
		sub_ret_->type_ = RTG_OPERATION_ARG_TYPE_EXPRESSION;
	} else {
		forced_assertion(operation_arg->node_->type_ == STT_NODE_TYPE_NAMED_FUNCTION_CALL);
#ifndef NDEBUG
		stt_node_assertion_clean_function_call_node(operation_arg->node_);
		assertion(operation_arg->node_->sub_named_function_call_ != NULL);
		assertion(operation_arg->node_->sub_named_function_call_->named_function_call_ != NULL);
		assertion(operation_arg->node_->sub_named_function_call_->named_function_call_->function_name_identifier_ != NULL);
		assertion(operation_arg->node_->sub_named_function_call_->named_function_call_->function_name_identifier_->identifier_subnode_ != NULL);
		assertion(operation_arg->node_->sub_named_function_call_->named_function_call_->function_name_identifier_->identifier_subnode_->value_ != NULL);
		assertion(operation_arg->node_->sub_named_function_call_->named_function_call_->function_name_identifier_->identifier_subnode_->value_->value_ != NULL);
		assertion(operation_arg->node_->sub_named_function_call_->named_function_call_->call_arguments_ != NULL);
		assertion(operation_arg->node_->sub_named_function_call_->named_function_call_->pending_semantic_checks_ != NULL);
		assertion(operation_arg->node_->sub_named_function_call_->named_function_call_->pending_semantic_checks_->called_function_has_no_return_value_ == AMARA_BOOLEAN_FALSE);
		assertion(operation_type == STT_NODE_TYPE_OPERATION);  /* XXX */
		/* assertion(operation_type != STT_NODE_TYPE_EXECUTION); */  /* XXX */
#endif
		find_rtg_named_function_ret_ = rtg_named_functions_simple_list_find_by_name(rtg_named_functions, operation_arg->node_->sub_named_function_call_->named_function_call_->function_name_identifier_->identifier_subnode_->value_);
		forced_assertion(find_rtg_named_function_ret_ != NULL);
		if (find_rtg_named_function_ret_->status == RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND) {
			forced_assertion(ret_->operation_arg == NULL);
			ret_->error_messages = amara_strings_simple_list_exhaustive_constructor_three_to_one("unable to find function '", operation_arg->node_->sub_named_function_call_->named_function_call_->function_name_identifier_->identifier_subnode_->value_->value_, "' requested as function to be called (rtg_operation.c:658)");
			ret_->status = RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_IDENTIFIER;
			return ret_;
		}
		/*   Function to be called has been found at this point. */
		if (operation_arg->node_->sub_named_function_call_->named_function_call_->pending_semantic_checks_->called_function_has_no_return_value_ == AMARA_BOOLEAN_TRUE) {
			forced_assertion(0);  /* FIXXXME FIXME XXX */
		} else {
			forced_assertion(0);  /* FIXXXME FIXME XXX */
		}
		function_callable_from_current_call_ = rtg_named_function_callable_from_stt_named_function_call(find_rtg_named_function_ret_->named_function, operation_arg->node_->sub_named_function_call_->named_function_call_);
		forced_assertion(function_callable_from_current_call_ == AMARA_BOOLEAN_TRUE);
		sub_ret_ = rtg_operation_arg_default_constructor();
		forced_assertion(sub_ret_ != NULL);
		rtg_named_function_call_transformation_ret_ = rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function(operation_arg->node_->sub_named_function_call_->named_function_call_, find_rtg_named_function_ret_->named_function);
		forced_assertion(rtg_named_function_call_transformation_ret_->status == RTG_NAMED_FUNCTION_CALL_OUT_OF_STT_NAMED_FUNCTION_CALL_AND_RTG_NAMED_FUNCTION_RET_STATUS_SUCCESS);
		rtg_operation_arg_set_named_function_call(sub_ret_, rtg_named_function_call_transformation_ret_->named_function_call);
#ifndef NDEBUG
		assertion(sub_ret_->type_ == RTG_OPERATION_ARG_TYPE_NAMED_FUNCTION_CALL);
#endif
		rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function_ret_destructor(rtg_named_function_call_transformation_ret_);
	}  /* End switching on `operation_arg->node_->type_`. */
	ret_->operation_arg = sub_ret_;
	ret_->error_messages = NULL;
	ret_->status = RTG_OPERATION_ARG_OUT_OF_STT_OPERATION_ARG_RET_STATUS_SUCCESS;
	return ret_;
}
