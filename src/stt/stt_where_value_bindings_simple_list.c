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
 * src/stt/stt_where_value_bindings_simple_list.c: Amara syntax tree
 * _where_ value bindings simple list.
 */

#include "../asr/assertion.h"

#include "stt_where_value_bindings_simple_list.h"

stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_default_constructor()
{
	stt_where_value_bindings_simple_list * returning_;

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_where_value_bindings_simple_list *)
#endif
			malloc(sizeof(stt_where_value_bindings_simple_list));
	forced_assertion(returning_ != NULL);

	returning_->first = NULL;
	returning_->next = NULL;

	return returning_;
}

stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_copy_constructor_inner(
		const stt_where_value_bindings_simple_list * list)
__attribute__((warn_unused_result))
;

stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_copy_constructor_inner(
		const stt_where_value_bindings_simple_list * list)
{
	stt_where_value_bindings_simple_list * returning_;

	/*
	assertion(list != NULL);
	*/
	/* XXX */
	/**/
	if (list == NULL) {
		return NULL;
	}
	/**/

	assertion(list->first != NULL);

	returning_ = stt_where_value_bindings_simple_list_default_constructor();
	returning_->first =
			stt_where_value_binding_copy_constructor(list->first);
	returning_->next = stt_where_value_bindings_simple_list_copy_constructor_inner(
			list->next);

	return returning_;
}

stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_copy_constructor(
		const stt_where_value_bindings_simple_list * list)
{
	stt_where_value_bindings_simple_list * returning_;

	assertion(list != NULL);

	if (list->first == NULL) {
		assertion(list->next == NULL);
		returning_ = stt_where_value_bindings_simple_list_default_constructor();
		return returning_;
	}

	return stt_where_value_bindings_simple_list_copy_constructor_inner(
			list);
}

void
stt_where_value_bindings_simple_list_destructor_inner(
		stt_where_value_bindings_simple_list * list)
;

void
stt_where_value_bindings_simple_list_destructor_inner(
		stt_where_value_bindings_simple_list * list)
{
	if (list != NULL) {
		stt_where_value_bindings_simple_list_destructor_inner(
				list->next);
#ifndef NDEBUG
		assertion(list->first != NULL);
#endif
		stt_where_value_binding_destructor(list->first);
		free(list);
	}
}

void
stt_where_value_bindings_simple_list_destructor(
		stt_where_value_bindings_simple_list * list)
{
	assertion(list != NULL);
	if (list->first == NULL) {
		assertion(list->next == NULL);
		free(list);
	} else {
		stt_where_value_bindings_simple_list_destructor_inner(list);
	}
}

/**  `list` already checked as not NULL.
 *   `addition` already checked as not NULL. */
stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_push_front_inner(
		stt_where_value_bindings_simple_list * list,
		const stt_where_value_binding * addition)
__attribute__((warn_unused_result))
;

stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_push_front_inner(
		stt_where_value_bindings_simple_list * list,
		const stt_where_value_binding * addition)
{
	stt_where_value_bindings_simple_list * new_node_;

	new_node_ = (stt_where_value_bindings_simple_list *) malloc(sizeof(
			stt_where_value_bindings_simple_list));
	forced_assertion(new_node_ != NULL);

	new_node_->first = stt_where_value_binding_copy_constructor(addition);
	forced_assertion(new_node_->first != NULL);

	new_node_->next = list;

	return new_node_;
}

stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_push_front(
		stt_where_value_bindings_simple_list * list,
		const stt_where_value_binding * addition)
{
	forced_assertion(list != NULL);
	forced_assertion(addition != NULL);

	if (list->first == NULL) {

#ifndef NDEBUG
		assertion(list->next == NULL);
#endif

		list->first = stt_where_value_binding_copy_constructor(
				addition);
		forced_assertion(list->first != NULL);

		return list;
	}

	return stt_where_value_bindings_simple_list_push_front_inner(
			list, addition);
}

void
stt_where_value_bindings_simple_list_push_back(
		stt_where_value_bindings_simple_list * list,
		const stt_where_value_binding * addition)
{
	stt_where_value_bindings_simple_list * ptr_;

	assertion(list != NULL);
	assertion(addition != NULL);

	if (list->first == NULL) {

		assertion(list->next == NULL);
		list->first = stt_where_value_binding_copy_constructor(
				addition);
	} else {

		ptr_ = list;
		while (ptr_->next != NULL) {
			ptr_ = ptr_->next;
		}
		ptr_->next =
#ifdef AMARA_USE_STD_CXX98
				(struct stt_where_value_bindings_simple_list *)
#endif
				malloc(sizeof(stt_where_value_bindings_simple_list));
		ptr_->next->first = stt_where_value_binding_copy_constructor(
				addition);
		ptr_->next->next = NULL;
	}
}

/**  Returns a pointer **without** ownership, or `NULL` if not found. */
stt_where_value_binding *
stt_where_value_bindings_simple_list_find_by_value_name_inner(
		const stt_where_value_bindings_simple_list * value_bindings_haystack,
		const amara_string * needle_value_name)
__attribute__((warn_unused_result))
;

stt_where_value_binding *
stt_where_value_bindings_simple_list_find_by_value_name_inner(
		const stt_where_value_bindings_simple_list * value_bindings_haystack,
		const amara_string * needle_value_name)
{
	amara_boolean equality_;
	/*
	stt_where_value_binding * ret_;
	*/

	if (value_bindings_haystack == NULL) {

		return NULL;
	}

#ifndef NDEBUG
	assertion(value_bindings_haystack->first != NULL);
#endif

	forced_assertion(value_bindings_haystack->first->value_name_ != NULL);
	forced_assertion(value_bindings_haystack->first->value_name_->value_ !=
			NULL);

	equality_ = amara_strings_equality(
			value_bindings_haystack->first->value_name_,
			needle_value_name);

	if (equality_ == AMARA_BOOLEAN_TRUE) {

		return value_bindings_haystack->first;
	}

	return stt_where_value_bindings_simple_list_find_by_value_name_inner(
			value_bindings_haystack->next, needle_value_name);
}

stt_where_value_binding *
stt_where_value_bindings_simple_list_find_by_value_name(
		const stt_where_value_bindings_simple_list * value_bindings_haystack,
		const amara_string * needle_value_name)
{
	if (value_bindings_haystack == NULL) {

		return NULL;
	}

	if (value_bindings_haystack->first == NULL) {

#ifndef NDEBUG
		assertion(value_bindings_haystack->next == NULL);
#endif

		return NULL;
	}

	return stt_where_value_bindings_simple_list_find_by_value_name_inner(
			value_bindings_haystack, needle_value_name);
}

amara_boolean
stt_where_value_bindings_simple_list_equality_inner(
		const stt_where_value_bindings_simple_list * l0,
		const stt_where_value_bindings_simple_list * l1)
__attribute__((warn_unused_result))
;

amara_boolean
stt_where_value_bindings_simple_list_equality_inner(
		const stt_where_value_bindings_simple_list * l0,
		const stt_where_value_bindings_simple_list * l1)
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
			firsts_equal_ = stt_where_value_bindings_equality(
					l0->first, l1->first);
			if (firsts_equal_ == AMARA_BOOLEAN_FALSE) {
				return AMARA_BOOLEAN_FALSE;
			} else {
				return stt_where_value_bindings_simple_list_equality_inner(
						l0->next, l1->next);
			}
		}
	}
}

amara_boolean
stt_where_value_bindings_simple_list_equality(
		const stt_where_value_bindings_simple_list * l0,
		const stt_where_value_bindings_simple_list * l1)
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
		return stt_where_value_bindings_simple_list_equality_inner(
				l0, l1);
	}
}

amara_boolean
stt_where_value_bindings_simple_lists_equality(
		const stt_where_value_bindings_simple_list * l0,
		const stt_where_value_bindings_simple_list * l1)
{
	return stt_where_value_bindings_simple_list_equality(l0, l1);
}
