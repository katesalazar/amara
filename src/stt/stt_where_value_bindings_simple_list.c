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
 * src/stt/stt_where_value_bindings_simple_list.c: Amara syntax tree
 * _where_ value bindings simple list.
 */

#include "../asr/assertion.h"

#include "stt_where_value_bindings_simple_list.h"

stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_default_constructor()
{
	stt_where_value_bindings_simple_list * returning_;

	returning_ = malloc(sizeof(stt_where_value_bindings_simple_list));

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

	if (list == NULL) {
		return NULL;
	}

	assertion(list->first != NULL);
	assertion(list->next != NULL);

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
		ptr_->next = malloc(sizeof(
				stt_where_value_bindings_simple_list));
		ptr_->next->first = stt_where_value_binding_copy_constructor(
				addition);
		ptr_->next->next = NULL;
	}
}
