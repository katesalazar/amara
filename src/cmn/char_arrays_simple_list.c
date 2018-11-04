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
 * src/cmn/char_arrays_simple_list.c: Simple list of character arrays.
 */

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `int strcmp(const char * s1, const char * s2)`. */
#include <string.h>

/*   For `void assertion(int expression`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "char_arrays_simple_list.h"

char_arrays_simple_list *
char_arrays_simple_list_default_constructor()
{
	char_arrays_simple_list * ret_ = (char_arrays_simple_list *)
			malloc(sizeof(char_arrays_simple_list));
	ret_->first = NULL;
	ret_->next = NULL;
	return ret_;
}

char_arrays_simple_list *
char_arrays_simple_list_copy_constructor(const char_arrays_simple_list * list)
{
	char_arrays_simple_list * ret_;
	char_arrays_simple_list * ret_ptr_;
	const char_arrays_simple_list * list_ptr_;
	assertion(list != NULL);
	if (list->first == NULL) {
		assertion(list->next == NULL);
		ret_ = malloc(sizeof(char_arrays_simple_list));
		ret_->first = NULL;
		ret_->next = NULL;
		return ret_;
	}
	ret_ = malloc(sizeof(char_arrays_simple_list));
	assertion(list->first != NULL);
	ret_->first = malloc(strlen(list->first) + 1);
	strcpy(ret_->first, list->first);
	ret_ptr_ = ret_;
	list_ptr_ = list->next;
	while (list_ptr_ != NULL) {
		ret_ptr_->next = malloc(sizeof(char_arrays_simple_list));
		assertion(list_ptr_->first != NULL);
		ret_ptr_->next->first = malloc(strlen(list_ptr_->first) + 1);
		strcpy(ret_ptr_->next->first, list_ptr_->first);
		ret_ptr_ = ret_ptr_->next;
		list_ptr_ = list_ptr_->next;
	}
	ret_ptr_->next = NULL;
	return ret_;
}

void
char_arrays_simple_list_destructor(char_arrays_simple_list * list)
{
	char_arrays_simple_list * ptr_;
	while (list != NULL) {
		ptr_ = list->next;
		free(list);
		list = ptr_;
	}
}

char_arrays_simple_list *
char_arrays_simple_list_push_front(
		char_arrays_simple_list * list, char * char_array)
{
	char_arrays_simple_list * new_node_;
	assertion(list != NULL);
	assertion(char_array != NULL);
	if (list->first == NULL) {
		assertion(list->next == NULL);
		list->first = malloc(strlen(char_array) + 1);
		strcpy(list->first, char_array);
		return list;
	}
	new_node_ = malloc(sizeof(char_arrays_simple_list));
	new_node_->first = malloc(strlen(char_array) + 1);
	strcpy(new_node_->first, char_array);
	new_node_->next = list;
	return new_node_;
}

char_arrays_simple_list *
char_arrays_simple_list_concat(
		const char_arrays_simple_list * list_zero,
		const char_arrays_simple_list * list_one)
{
	/*   Input (`list_one` only) traverser. */
	char_arrays_simple_list * ptr_in_;
	/*   Output (`ret_`) traverser. */
	char_arrays_simple_list * ptr_out_;
	/*   To be returned. */
	char_arrays_simple_list * ret_;
	assertion(list_zero != NULL);
	assertion(list_one != NULL);
	if (list_zero->first == NULL) {
		assertion(list_zero->next == NULL);
		ret_ = char_arrays_simple_list_copy_constructor(list_one);
		return ret_;
	}
	if (list_one->first == NULL) {
		assertion(list_one->next == NULL);
		ret_ = char_arrays_simple_list_copy_constructor(list_zero);
		return ret_;
	}
	ret_ = char_arrays_simple_list_copy_constructor(list_zero);
	/*   Boot input traversal. */
	ptr_in_ = (char_arrays_simple_list *) list_one;
	/*   Advance output traversal to end of the partial result. */
	ptr_out_ = ret_;
	while (ptr_out_->next != NULL) {
		assertion(ptr_out_->first != NULL);
		ptr_out_ = ptr_out_->next;
	}
	/*   Traverse `list_one`, which is now granted not to be empty,
	 * while creating nodes in the `ret_` list. */
	while (ptr_in_ != NULL) {
		ptr_out_->next = char_arrays_simple_list_default_constructor();
		assertion(ptr_in_->first != NULL);
		ptr_out_->next->first = malloc(strlen(ptr_in_->first) + 1);
		strcpy(ptr_out_->next->first, ptr_in_->first);
		ptr_out_ = ptr_out_->next;
		ptr_in_ = ptr_in_->next;
	}
	ptr_out_->next = NULL;
	return ret_;
}

char_arrays_simple_list *
char_arrays_simple_list_concat_destructive(
		char_arrays_simple_list * list_zero,
		char_arrays_simple_list * list_one)
{
	char_arrays_simple_list * list_zero_;
	char_arrays_simple_list * list_one_;
	char_arrays_simple_list * ptr_;
	char_arrays_simple_list * ret_;

	if (list_zero == NULL) {
		return list_one;
	}

	if (list_one == NULL) {
		return list_zero;
	}

	if (list_zero->first == NULL) {
		assertion(list_zero->next == NULL);
		if (list_one->first == NULL) {
			assertion(list_one->next == NULL);
			return list_zero;
		}
		list_zero_ = list_zero;
		list_one_ = list_one->next;
		list_zero_->first = list_one->first;
	} else {
		list_zero_ = list_zero;
		list_one_ = list_one;
	}

	ret_ = list_zero_;
	ptr_ = list_zero_;
	while (ptr_->next != NULL) {
		ptr_ = ptr_->next;
	}
	if (list_one_ == NULL) {
		ptr_->next = NULL;
	} else if (list_one_->first == NULL) {
		assertion(list_one_->next == NULL);
		ptr_->next = NULL;
	} else {
		ptr_->next = list_one_;
	}

	return ret_;
}

amara_boolean
char_arrays_simple_list_equality(
		const char_arrays_simple_list * list_zero,
		const char_arrays_simple_list * list_one)
{
	const char_arrays_simple_list * list_zero_ptr_;
	const char_arrays_simple_list * list_one_ptr_;

	if (list_zero == NULL) {

		if (list_one == NULL) {

			return AMARA_BOOLEAN_TRUE;
		} else {

			if (list_one->first == NULL) {

#ifndef NDEBUG
				assertion(list_one->next == NULL);
#endif
				return AMARA_BOOLEAN_TRUE;
			} else {

				return AMARA_BOOLEAN_FALSE;
			}
		}
	}

	if (list_one == NULL) {

#ifndef NDEBUG
		/*   By virtue of previous flows. */
		assertion(list_zero != NULL);
#endif

		if (list_zero->first == NULL) {

#ifndef NDEBUG
			assertion(list_zero->next == NULL);
#endif
			return AMARA_BOOLEAN_TRUE;
		} else {

			return AMARA_BOOLEAN_FALSE;
		}
	}

	list_zero_ptr_ = list_zero;
	list_one_ptr_ = list_one;
	while (list_zero_ptr_ != NULL) {
		if (list_one_ptr_ == NULL) {
			return AMARA_BOOLEAN_FALSE;
		} else {
			/*
			assertion(list_zero_ptr_->first != NULL ||
					list_zero_ptr_->next == NULL);
			*/
			if (list_zero_ptr_->first == NULL) {
				assertion(list_zero_ptr_->next == NULL);
			}
			/*
			assertion(list_one_ptr_->first != NULL ||
					list_one_ptr_->next == NULL);
			*/
			if (list_one_ptr_->first == NULL) {
				assertion(list_one_ptr_->next == NULL);
			}
			if (list_zero_ptr_->first == NULL) {
				assertion(list_one_ptr_->first == NULL);
				list_zero_ptr_ = list_zero_ptr_->next;
				list_one_ptr_ = list_one_ptr_->next;
			} else {
				if (!strcmp(list_zero_ptr_->first,
						list_one_ptr_->first)) {
					list_zero_ptr_ = list_zero_ptr_->next;
					list_one_ptr_ = list_one_ptr_->next;
				} else {
					return AMARA_BOOLEAN_FALSE;
				}
			}
		}
	}
	if (list_one_ptr_ == NULL) {
		return AMARA_BOOLEAN_TRUE;
	} else {
		return AMARA_BOOLEAN_FALSE;
	}
}
