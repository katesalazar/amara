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
 * src/stt/stt_operation_arg.c: Amara syntax tree application function
 * operation argument.
 */

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `void stt_node_destructor(stt_node const * node)`. */
#include "stt_node.h"

/*   For own definitions. */
#include "stt_operation_arg.h"

stt_operation_arg *
stt_operation_arg_default_constructor()
{
	stt_operation_arg * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_operation_arg *)
#endif
			malloc(sizeof(stt_operation_arg));
	forced_assertion(ret_ != NULL);

	ret_->type_ = STT_OPERATION_ARG_TYPE_INVALID;

	/*
	ret_->raw_ = NULL;
	*/

	ret_->node_ = NULL;

	return ret_;
}

/*   Forward declarations for `stt_operation_arg *
 * stt_operation_arg_copy_constructor(const stt_operation_arg *)`. */
void
assert_stt_node_is_valid(const struct stt_node * node)
;

/*   Forward declarations for `stt_operation_arg *
 * stt_operation_arg_copy_constructor(const stt_operation_arg *)`. */
struct stt_node *
stt_node_copy_constructor(const struct stt_node * node)
__attribute__((warn_unused_result))
;

stt_operation_arg *
stt_operation_arg_copy_constructor(const stt_operation_arg * operation_arg)
{
	stt_operation_arg * ret_;

	assertion(operation_arg->type_ != STT_OPERATION_ARG_TYPE_INVALID);

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_operation_arg *)
#endif
			malloc(sizeof(stt_operation_arg));
	forced_assertion(ret_ != NULL);

	/*
	assertion(operation_arg->raw_ != NULL);
	assertion(operation_arg->raw_->value_ != NULL);
	*/
	assertion(operation_arg->node_ != NULL);

	assert_stt_node_is_valid(operation_arg->node_);

	ret_->node_ = stt_node_copy_constructor(operation_arg->node_);
	forced_assertion(ret_->node_ != NULL);

	/*
	ret_->raw_ = amara_string_copy_constructor(operation_arg->raw_);
	*/

	ret_->type_ = operation_arg->type_;

	return ret_;
}

void
stt_operation_arg_destructor(const stt_operation_arg * operation_arg)
{
#ifndef NDEBUG
	assertion(operation_arg != NULL);
	assertion(operation_arg->type_ == STT_OPERATION_ARG_TYPE_VALID);
#endif
	stt_node_destructor(operation_arg->node_);
	free((stt_operation_arg *) operation_arg);
}

void
stt_operation_arg_set_type(
		stt_operation_arg * operation_arg,
		const stt_operation_arg_type type)
{
	forced_assertion(operation_arg != NULL);
	forced_assertion(type == STT_OPERATION_ARG_TYPE_VALID);
	forced_assertion(operation_arg->type_ ==
			/*
			STT_OPERATION_ARG_TYPE_INVALID
			*/
			STT_OPERATION_ARG_TYPE_VALID
	);
	operation_arg->type_ = STT_OPERATION_ARG_TYPE_VALID;
}

void
stt_operation_arg_set_node(
		stt_operation_arg * operation_arg,
		const struct stt_node * node)
{
	forced_assertion(operation_arg != NULL);
	forced_assertion(operation_arg->type_ ==
			STT_OPERATION_ARG_TYPE_INVALID);
	operation_arg->node_ = stt_node_copy_constructor(node);
	operation_arg->type_ = STT_OPERATION_ARG_TYPE_VALID;
}

void
stt_operation_arg_set_string_literal(
		stt_operation_arg * operation_arg,
		const amara_string * string_literal)
{
	forced_assertion(operation_arg != NULL);
	forced_assertion(operation_arg->type_ ==
			STT_OPERATION_ARG_TYPE_INVALID);
	operation_arg->node_ = stt_node_default_constructor();
	stt_node_set_string_literal(operation_arg->node_, string_literal);
	/*
	stt_node_set_type(operation_arg->node_, STT_NODE_TYPE_STRING_LITERAL);
	*/
	operation_arg->type_ = STT_OPERATION_ARG_TYPE_VALID;
}

void
stt_operation_arg_set_identifier(
		stt_operation_arg * operation_arg,
		const amara_string * identifier)
{
	forced_assertion(operation_arg != NULL);
	forced_assertion(operation_arg->type_ ==
			STT_OPERATION_ARG_TYPE_INVALID);
	operation_arg->node_ = stt_node_default_constructor();
	stt_node_set_identifier(operation_arg->node_, identifier);
	/*
	stt_node_set_type(operation_arg->node_, STT_NODE_TYPE_IDENTIFIER);
	*/
	operation_arg->type_ = STT_OPERATION_ARG_TYPE_VALID;
}

amara_boolean
stt_operation_arg_equality(
		const stt_operation_arg * oa0, const stt_operation_arg * oa1)
{
#ifndef NDEBUG
	assertion(oa0 != NULL);
	assertion(oa1 != NULL);
#endif

#ifndef NDEBUG
	assertion(oa0->type_ == STT_OPERATION_ARG_TYPE_VALID);
	assertion(oa1->type_ == STT_OPERATION_ARG_TYPE_VALID);
#endif

#ifndef NDEBUG
	assertion(oa0->node_ != NULL);
	assertion(oa1->node_ != NULL);
#endif

	return stt_nodes_equality(oa0->node_, oa1->node_);
}

amara_boolean
stt_operation_args_equality(
		const stt_operation_arg * oa0, const stt_operation_arg * oa1)
{
	return stt_operation_arg_equality(oa0, oa1);
}
