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
char_arrays_simple_list_concat(
		const char_arrays_simple_list * list_zero,
		const char_arrays_simple_list * list_one)
{
	char_arrays_simple_list * ptr_in_;
	char_arrays_simple_list * ptr_out_;
	char_arrays_simple_list * ret_;
	ret_ = char_arrays_simple_list_default_constructor();
	ptr_in_ = (char_arrays_simple_list *) list_zero;
	ptr_out_ = ret_;
	while (ptr_in_ != NULL) {
		ptr_out_->first = ptr_in_->first;
		if (ptr_in_->next != NULL) {
			ptr_out_->next = char_arrays_simple_list_default_constructor();
			ptr_in_ = ptr_in_->next;
			ptr_out_ = ptr_out_->next;
		} else {
			ptr_in_ = ptr_in_->next;
			ptr_out_->next = NULL;
		}
	}
	ptr_in_ = (char_arrays_simple_list *) list_one;
	while (ptr_in_ != NULL) {
		ptr_out_->first = ptr_in_->first;
		if (ptr_in_->next != NULL) {
			ptr_out_->next = char_arrays_simple_list_default_constructor();
			ptr_in_ = ptr_in_->next;
			ptr_out_ = ptr_out_->next;
		} else {
			ptr_in_ = ptr_in_->next;
			ptr_out_->next = NULL;
		}
	}
	return ret_;
}

char_arrays_simple_list *
char_arrays_simple_list_concat_destructive(
		char_arrays_simple_list * list_zero,
		char_arrays_simple_list * list_one)
{
	char_arrays_simple_list * ptr_;
	char_arrays_simple_list * ret_;
	ret_ = list_zero;
	ptr_ = list_zero;
	if (list_zero == NULL) {
		return list_one;
	}
	if (list_one == NULL) {
		return list_zero;
	}
	while (ptr_->next != NULL) {
		ptr_->next = ptr_->next->next;
	}
	ptr_->next = list_one;
	return ret_;
}

uint_fast8_t
char_arrays_simple_list_equality(
		const char_arrays_simple_list * list_zero,
		const char_arrays_simple_list * list_one)
{
	while (list_zero != NULL) {
		if (list_one == NULL) {
			return 0x00;
		} else {
			assertion(list_zero->first != NULL ||
					list_zero->next == NULL);
			assertion(list_one->first != NULL ||
					list_one->next == NULL);
			if (list_zero->first == NULL) {
				assertion(list_one->first == NULL);
				list_zero = list_zero->next;
				list_one = list_one->next;
			} else {
				if (strcmp(list_zero->first,
						list_one->first)) {
					list_zero = list_zero->next;
					list_one = list_one->next;
				} else {
					return 0x00;
				}
			}
		}
	}
	if (list_one == NULL) {
		return 0xFF;
	} else {
		return 0x00;
	}
}
