/*
 * Copyright 2019 Mercedes Catherine Salazar
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
 * src/cmn/amara_strings_simple_list.c: Simple list of strings.
 */

#include "../asr/assertion.h"

#include "amara_strings_simple_list.h"

amara_strings_simple_list *
amara_strings_simple_list_default_constructor(void)
{
	amara_strings_simple_list * ret_;

	ret_ = malloc(sizeof(amara_strings_simple_list));
	forced_assertion(ret_ != NULL);
	ret_->first = NULL;
	ret_->next = NULL;

	return ret_;
}

amara_strings_simple_list *
amara_strings_simple_list_exhaustive_constructor_three_to_one(
		const char * ca0, const char * ca1, const char * ca2)
{
	amara_string * string_;
	amara_strings_simple_list * ret_;

	string_ = amara_string_exhaustive_constructor_three(ca0, ca1, ca2);
	forced_assertion(string_ != NULL);
	forced_assertion(string_->value_ != NULL);

	ret_ = amara_strings_simple_list_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first == NULL);
	assertion(ret_->next == NULL);
#endif

	ret_ = amara_strings_simple_list_push_front(ret_, string_);
#ifndef NDEBUG
	assertion(string_->value_ != NULL);
#endif
	forced_assertion(ret_->first != NULL);
	forced_assertion(ret_->first->value_ != NULL);
#ifndef NDEBUG
	assertion(ret_->next == NULL);
#endif

	amara_string_destructor(string_);

	return ret_;
}

void
amara_strings_simple_list_destructor(amara_strings_simple_list * list)
{
	if (list != NULL) {

		if (list->first == NULL) {

#ifndef NDEBUG
			assertion(list->next == NULL);
#endif
		} else {

			amara_strings_simple_list_destructor(list->next);

			amara_string_destructor(list->first);
		}

		free(list);
	}
}

amara_strings_simple_list *
amara_strings_simple_list_push_front(
		amara_strings_simple_list * list, const amara_string * string)
{
	amara_strings_simple_list * new_list_node_;

#ifndef NDEBUG
	assertion(list != NULL);
#endif

	if (list->first == NULL) {

#ifndef NDEBUG
		assertion(list->next == NULL);
#endif

		list->first = amara_string_copy_constructor(string);

		return list;
	} else {

		new_list_node_ = malloc(sizeof(amara_strings_simple_list));
		forced_assertion(new_list_node_ != NULL);
		new_list_node_->first = amara_string_copy_constructor(string);
		new_list_node_->next = list;

		return new_list_node_;
	}
}
