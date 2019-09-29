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
 * src/stt/stt_applications_simple_list.c: Amara syntax tree
 * applications simple list.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_applications_simple_list.h"

stt_applications_simple_list *
stt_applications_simple_list_default_constructor()
{
	stt_applications_simple_list * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_applications_simple_list *)
#endif
			malloc(sizeof(stt_applications_simple_list));
	forced_assertion(ret_ != NULL);

	ret_->first = NULL;
	ret_->next = NULL;

	return ret_;
}

stt_applications_simple_list *
stt_applications_simple_list_copy_constructor_inner(
		const stt_applications_simple_list * applications)
{
	stt_applications_simple_list * ret_;

	if (applications == NULL) {
		return NULL;
	}
	assertion(applications->first != NULL);

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_applications_simple_list *)
#endif
			malloc(sizeof(stt_applications_simple_list));
	forced_assertion(ret_ != NULL);

	ret_->first = stt_application_copy_constructor(applications->first);
	/*
	if (applications->next == NULL) {
		ret_->next = NULL;
		return ret_;
	}
	*/
	ret_->next = stt_applications_simple_list_copy_constructor_inner(
			applications->next);
	return ret_;
}

stt_applications_simple_list *
stt_applications_simple_list_copy_constructor(
		const stt_applications_simple_list * applications)
{
	stt_applications_simple_list * ret_;

	assertion(applications != NULL);

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_applications_simple_list *)
#endif
			malloc(sizeof(stt_applications_simple_list));
	forced_assertion(ret_ != NULL);

	if (applications->first == NULL) {
		ret_->first = NULL;
		assertion(applications->next == NULL);
		ret_->next = NULL;
		return ret_;
	}
	ret_->first = stt_application_copy_constructor(applications->first);
	if (applications->next == NULL) {
		ret_->next = NULL;
		return ret_;
	}
	ret_->next = stt_applications_simple_list_copy_constructor_inner(
			applications->next);
	return ret_;
}

void
stt_applications_simple_list_destructor_inner(
		stt_applications_simple_list * list)
;

void
stt_applications_simple_list_destructor_inner(
		stt_applications_simple_list * list)
{
	if (list != NULL) {
#ifndef NDEBUG
		assertion(list->first != NULL);
#endif
		stt_applications_simple_list_destructor_inner(list->next);
		stt_application_destructor(list->first);
		free(list);
	}
}

void
stt_applications_simple_list_destructor(
		stt_applications_simple_list * list)
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
		stt_applications_simple_list_destructor_inner(list);
	}
}

stt_applications_simple_list *
stt_applications_simple_list_push_front(
		stt_applications_simple_list * applications,
		const stt_application * application)
{
	stt_applications_simple_list * new_list_node_;
	assertion(applications != NULL);
	assertion(application != NULL);
	if (applications->first == NULL) {
		assertion(applications->next == NULL);
		applications->first =
				stt_application_copy_constructor(application);
		return applications;
	}

	new_list_node_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_applications_simple_list *)
#endif
			malloc(sizeof(stt_applications_simple_list));
	forced_assertion(new_list_node_ != NULL);

	new_list_node_->first = stt_application_copy_constructor(application);
	new_list_node_->next = applications;
	return new_list_node_;
}

stt_applications_simple_list_length_ret *
stt_applications_simple_list_length(const stt_applications_simple_list * list)
{
	stt_applications_simple_list_length_ret * ret_;
	const stt_applications_simple_list * ptr_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_applications_simple_list_length_ret *)
#endif
			malloc(sizeof(stt_applications_simple_list_length_ret));
	forced_assertion(ret_ != NULL);

	ret_->status = STT_APPLICATIONS_SIMPLE_LIST_LENGTH_RET_STATUS_INVALID;

#ifndef NDEBUG
	assertion(list != NULL);
#endif

	if (list->first == NULL) {

#ifndef NDEBUG
		assertion(list->next == NULL);
#endif
		ret_->length = 0;
		ret_->status = STT_APPLICATIONS_SIMPLE_LIST_LENGTH_RET_STATUS_SUCCESS;
		return ret_;
	}

	ret_->length = 0;

	ptr_ = list;
	while (ptr_ != NULL) {

		if (ret_->length >= 255) {

			ret_->status = STT_APPLICATIONS_SIMPLE_LIST_LENGTH_RET_STATUS_ERROR_OVERFLOW;
			return ret_;
		}

		ret_->length++;

		ptr_ = ptr_->next;
	}

	ret_->status = STT_APPLICATIONS_SIMPLE_LIST_LENGTH_RET_STATUS_SUCCESS;

	return ret_;
}
