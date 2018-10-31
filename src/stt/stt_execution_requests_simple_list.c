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
 * src/stt/stt_execution_requests_simple_list.c: Amara syntax tree
 * application execution requests simple list.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_execution_requests_simple_list.h"

stt_execution_requests_simple_list *
stt_execution_requests_simple_list_default_constructor()
{
	stt_execution_requests_simple_list * ret_;
	ret_ = malloc(sizeof(stt_execution_requests_simple_list));
	ret_->first = NULL;
	ret_->next = NULL;
	return ret_;
}

stt_execution_requests_simple_list *
stt_execution_requests_simple_list_copy_constructor_inner(
		const stt_execution_requests_simple_list * execution_requests)
{
	stt_execution_requests_simple_list * ret_;
	assertion(execution_requests != NULL);
	ret_ = malloc(sizeof(stt_execution_requests_simple_list));
	assertion(execution_requests->first != NULL);
	ret_->first = stt_execution_request_copy_constructor(
			execution_requests->first);
	if (execution_requests->next == NULL) {
		ret_->next = NULL;
	} else {
		ret_->next = stt_execution_requests_simple_list_copy_constructor_inner(
				execution_requests->next);
		assertion(ret_->next != NULL);
	}
	return ret_;
}

stt_execution_requests_simple_list *
stt_execution_requests_simple_list_copy_constructor(
		const stt_execution_requests_simple_list * execution_requests)
{
	stt_execution_requests_simple_list * ret_;
	assertion(execution_requests != NULL);
	ret_ = malloc(sizeof(stt_execution_requests_simple_list));
	if (execution_requests->first == NULL) {
		ret_->first = NULL;
		assertion(execution_requests->next == NULL);
		ret_->next = NULL;
		return ret_;
	}
	ret_ = stt_execution_requests_simple_list_copy_constructor_inner(
			execution_requests);
	return ret_;
}

void
stt_execution_requests_simple_list_destructor_inner(
		stt_execution_requests_simple_list * list)
{
	if (list != NULL) {
		assertion(list->first != NULL);
		stt_execution_requests_simple_list_destructor_inner(
				list->next);
		stt_execution_request_destructor(list->first);
		free(list);
	}
}

void
stt_execution_requests_simple_list_destructor(
		stt_execution_requests_simple_list * list)
{
	assertion(list != NULL);
	if (list->first == NULL) {
		assertion(list->next == NULL);
	} else {
		stt_execution_requests_simple_list_destructor_inner(
				list->next);
		stt_execution_request_destructor(list->first);
	}
	free(list);
}

uint_fast8_t
stt_execution_requests_simple_list_length(
		stt_execution_requests_simple_list * list)
{
	uint_fast8_t returning_ = 0;
	while (list != NULL) {
		if (returning_ >= UINT8_MAX) {
			fprintf(stderr, "%s:%u (uint_fast8_t functions_list_length(functions_list *)): fatal\n",
					__FILE__, __LINE__);
			exit(EXIT_FAILURE);
		}
		list = list->next;
		returning_++;
	}
	return returning_;
}

stt_execution_requests_simple_list *
stt_execution_requests_simple_list_push_front(
		stt_execution_requests_simple_list * execution_requests,
		const stt_execution_request * execution_request)
{
	stt_execution_requests_simple_list * new_list_head_;
	assertion(execution_requests != NULL);
	assertion(execution_request != NULL);
	if (execution_requests->first != NULL) {
		new_list_head_ = malloc(sizeof(
				stt_execution_requests_simple_list));
		new_list_head_->first =
				stt_execution_request_copy_constructor(
						execution_request);
		new_list_head_->next = execution_requests;
		return new_list_head_;
	}
	assertion(execution_requests->next == NULL);
	execution_requests->first =
			stt_execution_request_copy_constructor(
					execution_request);
	return execution_requests;
}
