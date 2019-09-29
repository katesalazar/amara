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
 * src/stt/stt_named_functions_simple_list.c: Amara syntax tree
 * application functions simple list.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_named_functions_simple_list.h"

stt_named_functions_simple_list *
stt_named_functions_simple_list_default_constructor(void)
{
	stt_named_functions_simple_list * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_named_functions_simple_list *)
#endif
			malloc(sizeof(stt_named_functions_simple_list));
	forced_assertion(ret_ != NULL);

	ret_->first = NULL;
	ret_->next = NULL;

	return ret_;
}

stt_named_functions_simple_list *
stt_named_functions_simple_list_copy_constructor_inner(
		const stt_named_functions_simple_list * named_functions)
{
	stt_named_functions_simple_list * ret_;

	assertion(named_functions != NULL);
	assertion(named_functions->first != NULL);

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_named_functions_simple_list *)
#endif
			malloc(sizeof(stt_named_functions_simple_list));
	forced_assertion(ret_ != NULL);

	ret_->first = stt_named_function_copy_constructor(
			named_functions->first);
	forced_assertion(ret_->first != NULL);
	if (named_functions->next == NULL) {
		ret_->next = NULL;
		return ret_;
	}
	ret_->next = stt_named_functions_simple_list_copy_constructor(
			named_functions->next);

	return ret_;
}

stt_named_functions_simple_list *
stt_named_functions_simple_list_copy_constructor(
		const stt_named_functions_simple_list * named_functions)
{
	stt_named_functions_simple_list * ret_;

	assertion(named_functions != NULL);

	if (named_functions->first == NULL) {

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_named_functions_simple_list *)
#endif
			malloc(sizeof(stt_named_functions_simple_list));
	forced_assertion(ret_ != NULL);

		ret_->first = NULL;
		assertion(named_functions->next == NULL);
		ret_->next = NULL;
		return ret_;
	}
	/*
	ret_->first = stt_named_function_copy_constructor(
			named_functions->first);
	if (named_functions->next == NULL) {
		ret_->next = NULL;
		return ret_;
	}
	ret_->next = stt_named_functions_simple_list_copy_constructor_inner(
			named_functions->next);
	return ret_;
	*/
	return stt_named_functions_simple_list_copy_constructor_inner(
			named_functions);
}

void
stt_named_functions_simple_list_destructor_inner(
		stt_named_functions_simple_list * list)
{
	if (list != NULL) {
		stt_named_functions_simple_list_destructor_inner(list->next);
#ifndef NDEBUG
		assertion(list->first != NULL);
#endif
		stt_named_function_destructor(list->first);
		free(list);
	}
}

void
stt_named_functions_simple_list_destructor(
		stt_named_functions_simple_list * list)
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
		stt_named_functions_simple_list_destructor_inner(list);
	}
}

unsigned char
stt_named_functions_simple_list_length(stt_named_functions_simple_list * list)
{
	unsigned char returning_;
	stt_named_functions_simple_list * ptr_;

	if (list == NULL) {

		return 0;
	} else if (list->first == NULL) {

		forced_assertion(list->next == NULL);
		return 0;
	}

	ptr_ = list;
	returning_ = 0;
	while (ptr_ != NULL) {
		forced_assertion(returning_ < 0xFF);  /* 255. */
		/*
		if (returning_ >= 255) {
			fprintf(stderr, "%s:%u (unsigned char stt_named_functions_simple_list_length(stt_named_functions_simple_list *)): fatal\n",
					__FILE__, __LINE__);
			exit(EXIT_FAILURE);
		}
		*/
		ptr_ = ptr_->next;
		returning_++;
	}
	return returning_;
}

stt_named_functions_simple_list *
stt_named_functions_simple_list_push_front(
		stt_named_functions_simple_list * named_functions,
		const stt_named_function * named_function)
{
	stt_named_functions_simple_list * new_named_functions_simple_list_node_;
	assertion(named_functions != NULL);
	assertion(named_function != NULL);
	if (named_functions->first == NULL) {
		assertion(named_functions->next == NULL);
		named_functions->first = stt_named_function_copy_constructor(
				named_function);
		return named_functions;
	}

	new_named_functions_simple_list_node_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_named_functions_simple_list *)
#endif
			malloc(sizeof(stt_named_functions_simple_list));
	forced_assertion(new_named_functions_simple_list_node_ != NULL);

	new_named_functions_simple_list_node_->first =
			stt_named_function_copy_constructor(named_function);
	new_named_functions_simple_list_node_->next = named_functions;
	return new_named_functions_simple_list_node_;
}
