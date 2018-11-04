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
 * src/stt/stt_operation_args_simple_list.c: Amara syntax tree
 * application function operation arguments simple list.
 */

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_operation_args_simple_list.h"

stt_operation_args_simple_list *
stt_operation_args_simple_list_default_constructor()
{
	stt_operation_args_simple_list * ret_;
	ret_ = malloc(sizeof(stt_operation_args_simple_list));
	ret_->first = NULL;
	ret_->next = NULL;
	return ret_;
}

/*

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
	assertion(operation_args->first != NULL);
	ret_ = malloc(sizeof(stt_operation_args_simple_list));
	ret_->first = stt_operation_arg_copy_constructor(
			operation_args->first);
	ret_->next = stt_operation_args_simple_list_copy_constructor_inner(
			operation_args->next);
	return ret_;
}

*/

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
	if (operation_args->next == NULL) {
	*/
	assertion(operation_args->next == NULL);
		ret_->next = NULL;
		return ret_;
	/*
	}
	ret_->next = stt_operation_args_simple_list_copy_constructor_inner(
			operation_args->next);
	return ret_;
	*/
}

void
stt_operation_args_simple_list_destructor(
		stt_operation_args_simple_list * list)
{
#ifndef NDEBUG
	assertion(list != NULL);
#endif

	if (list->first == NULL) {

#ifndef NDEBUG
		assertion(list->next == NULL);
#endif
	}

	if (list->next != NULL) {

		/* XXX Remove recursive call in all destructors of this sources subdirectory. */
		stt_operation_args_simple_list_destructor(list->next);
	}

	free(list);
}

stt_operation_args_simple_list *
stt_operation_args_simple_list_push_front(
		stt_operation_args_simple_list * operation_args,
		const stt_operation_arg * operation_arg)
{
	/*
	stt_operation_args_simple_list * new_list_node_;
	*/

#ifndef NDEBUG
	assertion(operation_args != NULL);
#endif

#ifndef NDEBUG
	assertion(operation_arg != NULL);
#endif

	/*
	if (operation_args->first == NULL) {
	*/
	assertion(operation_args->first == NULL);
		assertion(operation_args->next == NULL);
		operation_args->first = stt_operation_arg_copy_constructor(
				operation_arg);
		return operation_args;
	/*
	}
	new_list_node_ = malloc(sizeof(stt_operation_args_simple_list));
	new_list_node_->first = stt_operation_arg_copy_constructor(
			operation_arg);
	new_list_node_->next = operation_args;
	return new_list_node_;
	*/
}
