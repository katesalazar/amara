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
 * src/stt/stt_operation_args_simple_list.c: Amara syntax tree
 * application function operation arguments simple list.
 */

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "stt_node.h"

/*   For own definitions. */
#include "stt_operation_args_simple_list.h"

stt_operation_args_simple_list *
stt_operation_args_simple_list_default_constructor()
{
	stt_operation_args_simple_list * ret_;

	ret_ = malloc(sizeof(stt_operation_args_simple_list));
	forced_assertion(ret_ != NULL);
	ret_->first = NULL;
	ret_->next = NULL;

	return ret_;
}

stt_operation_args_simple_list *
stt_operation_args_simple_list_copy_constructor_inner(
		const stt_operation_args_simple_list * operation_args)
__attribute__((warn_unused_result))
;

stt_operation_args_simple_list *
stt_operation_args_simple_list_copy_constructor_inner(
		const stt_operation_args_simple_list * operation_args)
{
	stt_operation_args_simple_list * ret_;

	if (operation_args == NULL) {
		ret_ = NULL;
		return ret_;
	}
	forced_assertion(operation_args->first != NULL);
	ret_ = malloc(sizeof(stt_operation_args_simple_list));
	forced_assertion(ret_ != NULL);
	ret_->first = stt_operation_arg_copy_constructor(
			operation_args->first);
	forced_assertion(ret_->first != NULL);
	ret_->next = stt_operation_args_simple_list_copy_constructor_inner(
			operation_args->next);
	return ret_;
}

stt_operation_args_simple_list *
stt_operation_args_simple_list_copy_constructor(
		const stt_operation_args_simple_list * operation_args)
{
	stt_operation_args_simple_list * ret_;
	assertion(operation_args != NULL);
	ret_ = malloc(sizeof(stt_operation_args_simple_list));
	if (operation_args->first == NULL) {
		ret_->first = NULL;
		assertion(operation_args->next == NULL);
		ret_->next = NULL;
		return ret_;
	}
	ret_->first = stt_operation_arg_copy_constructor(
			operation_args->first);

	/*
	assertion(operation_args->next == NULL);
	*/

	if (operation_args->next == NULL) {

		ret_->next = NULL;
		return ret_;
	}
	ret_->next = stt_operation_args_simple_list_copy_constructor_inner(
			operation_args->next);
	return ret_;
}

void
stt_operation_args_simple_list_destructor(
		stt_operation_args_simple_list * list)
{
	forced_assertion(list != NULL);

	if (list->first == NULL) {

#ifndef NDEBUG
		assertion(list->next == NULL);
#endif
	}

	if (list->next != NULL) {

		stt_operation_args_simple_list_destructor(list->next);
	}

	free(list);
}

stt_operation_args_simple_list *
stt_operation_args_simple_list_push_front(
		stt_operation_args_simple_list * operation_args,
		const stt_operation_arg * operation_arg)
{
	stt_operation_args_simple_list * new_list_node_;

	forced_assertion(operation_args != NULL);

	forced_assertion(operation_arg != NULL);

	if (operation_args->first == NULL) {

#ifndef NDEBUG
		assertion(operation_args->next == NULL);
#endif
		operation_args->first = stt_operation_arg_copy_constructor(
				operation_arg);
		forced_assertion(operation_args->first != NULL);
		return operation_args;
	}
	new_list_node_ = malloc(sizeof(stt_operation_args_simple_list));
	forced_assertion(new_list_node_ != NULL);
	new_list_node_->first = stt_operation_arg_copy_constructor(
			operation_arg);
	forced_assertion(new_list_node_->first != NULL);
	new_list_node_->next = operation_args;
	return new_list_node_;
}

amara_boolean
stt_operation_args_simple_list_equality(
		const stt_operation_args_simple_list * l0,
		const stt_operation_args_simple_list * l1)
{
	amara_boolean equality_;

	forced_assertion(l0 != NULL);
	forced_assertion(l0->first != NULL);
	forced_assertion(l0->first->type_ ==
			STT_OPERATION_ARG_TYPE_VALID);
	forced_assertion(l0->first->node_ != NULL);
	/*
	forced_assertion(l0->first->node_->type_ == STT_NODE_TYPE_IDENTIFIER);
	forced_assertion(l0->first->node_->identifier_subnode_ != NULL);
	forced_assertion(l0->first->node_->identifier_subnode_->value_ !=
			NULL);
	*/
	forced_assertion(l0->next == NULL);
	forced_assertion(l1 != NULL);
	forced_assertion(l1->first != NULL);
	forced_assertion(l1->first->type_ ==
			STT_OPERATION_ARG_TYPE_VALID);
	forced_assertion(l1->first->node_ != NULL);
	/*
	forced_assertion(l1->first->node_->type_ == STT_NODE_TYPE_IDENTIFIER);
	forced_assertion(l1->first->node_->identifier_subnode_ != NULL);
	forced_assertion(l1->first->node_->identifier_subnode_->value_ !=
			NULL);
	*/
	forced_assertion(l1->next == NULL);

	/*
	equality_ = amara_string_equality(
			l0->first->node_->identifier_subnode_->value_,
			l1->first->node_->identifier_subnode_->value_);
	*/

	equality_ = stt_node_equality(l0->first->node_, l1->first->node_);

	forced_assertion(equality_ == AMARA_BOOLEAN_TRUE);

	return AMARA_BOOLEAN_TRUE;
}
