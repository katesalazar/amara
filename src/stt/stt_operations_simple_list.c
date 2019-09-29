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
 * src/stt/stt_operations_simple_list.c: Amara syntax tree application
 * function operations simple list.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_operations_simple_list.h"

stt_operations_simple_list *
stt_operations_simple_list_default_constructor()
{
	stt_operations_simple_list * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_operations_simple_list *)
#endif
			malloc(sizeof(stt_operations_simple_list));
	forced_assertion(ret_ != NULL);

	ret_->first = NULL;
	ret_->next = NULL;

	return ret_;
}

stt_operations_simple_list *
stt_operations_simple_list_copy_constructor_inner(
		const stt_operations_simple_list * operations)
{
	stt_operations_simple_list * ret_;

	if (operations != NULL) {

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_operations_simple_list *)
#endif
			malloc(sizeof(stt_operations_simple_list));
	forced_assertion(ret_ != NULL);

#ifndef NDEBUG
	assertion(operations->first != NULL);
#endif
	ret_->first = stt_operation_copy_constructor(operations->first);
	forced_assertion(ret_->first != NULL);

	ret_->next = stt_operations_simple_list_copy_constructor_inner(
			operations->next);
	} else {
		ret_ = NULL;
	}
	return ret_;
}

stt_operations_simple_list *
stt_operations_simple_list_copy_constructor(
		const stt_operations_simple_list * operations)
{
	stt_operations_simple_list * ret_;

#ifndef NDEBUG
	assertion(operations != NULL);
#endif

	if (operations->first == NULL) {

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_operations_simple_list *)
#endif
			malloc(sizeof(stt_operations_simple_list));
	forced_assertion(ret_ != NULL);

		ret_->first = NULL;
#ifndef NDEBUG
		assertion(operations->next == NULL);
#endif
		ret_->next = NULL;
		return ret_;
	}
	return stt_operations_simple_list_copy_constructor_inner(
			operations);
}

void
stt_operations_simple_list_destructor_inner(stt_operations_simple_list * list)
;

void
stt_operations_simple_list_destructor_inner(stt_operations_simple_list * list)
{
	if (list != NULL) {

		stt_operations_simple_list_destructor_inner(list->next);
#ifndef NDEBUG
		assertion(list->first != NULL);
#endif
		stt_operation_destructor(list->first);
		free(list);
	}
}

void
stt_operations_simple_list_destructor(stt_operations_simple_list * list)
{
#ifndef NDEBUG
	assertion(list != NULL);
#endif
	if (list->first == NULL) {

#ifndef NDEBUG
		assertion(list->next == NULL);
#endif
		free(list);
	} else {
		stt_operations_simple_list_destructor_inner(list);
	}
}

stt_operations_simple_list *
stt_operations_simple_list_push_front(
		stt_operations_simple_list * operations,
		const stt_operation * operation)
{
	stt_operations_simple_list * new_operations_list_node_;

#ifndef NDEBUG
	assertion(operations != NULL);
	assertion(operation != NULL);
#endif

	if (operations->first == NULL) {

#ifndef NDEBUG
		assertion(operations->next == NULL);
#endif

		operations->first = stt_operation_copy_constructor(operation);
		return operations;
	}

	new_operations_list_node_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_operations_simple_list *)
#endif
			malloc(sizeof(stt_operations_simple_list));
	forced_assertion(new_operations_list_node_ != NULL);

	new_operations_list_node_->first =
			stt_operation_copy_constructor(operation);
	forced_assertion(new_operations_list_node_->first != NULL);

	new_operations_list_node_->next = operations;

	return new_operations_list_node_;
}

void
stt_operations_simple_list_push_back(
		stt_operations_simple_list * operations,
		const stt_operation * operation)
{
	forced_assertion(operations != NULL);
	forced_assertion(operation != NULL);
	forced_assertion(operations->first == NULL); /* FIXME */
	operations->first = stt_operation_copy_constructor(operation);
	forced_assertion(operations->first != NULL);
	forced_assertion(operations->next == NULL); /* FIXME */
}

amara_boolean
stt_operations_simple_list_equality_inner(
		const stt_operations_simple_list * l0,
		const stt_operations_simple_list * l1)
__attribute__((warn_unused_result))
;

amara_boolean
stt_operations_simple_list_equality_inner(
		const stt_operations_simple_list * l0,
		const stt_operations_simple_list * l1)
{
	amara_boolean firsts_equal_;

	if (l0 == NULL) {

		if (l1 == NULL) {

			return AMARA_BOOLEAN_TRUE;
		} else {

			return AMARA_BOOLEAN_FALSE;
		}
	} else {

		if (l1 == NULL) {

			return AMARA_BOOLEAN_FALSE;
		} else {

#ifndef NDEBUG
			assertion(l0->first != NULL);
			assertion(l1->first != NULL);
#endif
			firsts_equal_ = stt_operations_equality(
					l0->first, l1->first);
			if (firsts_equal_ == AMARA_BOOLEAN_FALSE) {
				return AMARA_BOOLEAN_FALSE;
			} else {
				return stt_operations_simple_list_equality_inner(
						l0->next, l1->next);
			}
		}
	}
}

amara_boolean
stt_operations_simple_list_equality(
		const stt_operations_simple_list * l0,
		const stt_operations_simple_list * l1)
{
#ifndef NDEBUG
	assertion(l0 != NULL);
	assertion(l1 != NULL);
#endif

	if (l0->first == NULL) {

#ifndef NDEBUG
		assertion(l0->next == NULL);
#endif
		if (l1->first == NULL) {

#ifndef NDEBUG
			assertion(l1->next == NULL);
#endif
			return AMARA_BOOLEAN_TRUE;
		}
		return AMARA_BOOLEAN_FALSE;
	} else if (l1->first == NULL) {

#ifndef NDEBUG
		assertion(l1->next == NULL);
#endif
		return AMARA_BOOLEAN_FALSE;
	} else {
		return stt_operations_simple_list_equality_inner(l0, l1);
	}
}

amara_boolean
stt_operations_simple_lists_equality(
		const stt_operations_simple_list * l0,
		const stt_operations_simple_list * l1)
{
	return stt_operations_simple_list_equality(l0, l1);
}
