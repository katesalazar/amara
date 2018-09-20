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
 * src/stt/stt_functions_simple_list.c: Amara syntax tree application
 * functions simple list.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_functions_simple_list.h"

stt_functions_simple_list *
stt_functions_simple_list_copy_constructor_inner(
		const stt_functions_simple_list * functions)
{
	stt_functions_simple_list * ret_;
	assertion(functions != NULL);
	assertion(functions->first != NULL);
	ret_ = malloc(sizeof(stt_functions_simple_list));
	ret_->first = stt_function_copy_constructor(functions->first);
	if (functions->next == NULL) {
		ret_->next = NULL;
		return ret_;
	}
	ret_->next = stt_functions_simple_list_copy_constructor(
			functions->next);
	return ret_;
}

stt_functions_simple_list *
stt_functions_simple_list_copy_constructor(
		const stt_functions_simple_list * functions)
{
	stt_functions_simple_list * ret_;
	assertion(functions != NULL);
	ret_ = malloc(sizeof(stt_functions_simple_list));
	if (functions->first == NULL) {
		ret_->first = NULL;
		assertion(functions->next == NULL);
		ret_->next = NULL;
		return ret_;
	}
	ret_->first = stt_function_copy_constructor(functions->first);
	if (functions->next == NULL) {
		ret_->next = NULL;
		return ret_;
	}
	ret_->next = stt_functions_simple_list_copy_constructor_inner(
			functions->next);
	return ret_;
}

void
stt_functions_simple_list_destructor(
		stt_functions_simple_list * list)
{
	stt_functions_simple_list * ptr_;
	assertion(list != NULL);
	while (list != NULL) {
		stt_function_destructor(list->first);
		ptr_ = list;
		list = list->next;
		free(ptr_);
	}
}

uint_fast8_t
stt_functions_simple_list_length(stt_functions_simple_list * list)
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
