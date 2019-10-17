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
 * src/tst/tests_simple_list.c: Amara tests simple_list.
 */

/*   For `void * malloc(size_t)`. */
#include <stdlib.h>

#include "../asr/assertion.h"

/*   For own prototypes. */
#include "tests_simple_list.h"

tests_simple_list *
tests_simple_list_default_constructor(void)
{
	tests_simple_list * returning_;

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(tests_simple_list *)
#endif
			malloc(sizeof(tests_simple_list));
	forced_assertion(returning_ != NULL);

	returning_->first = NULL;
	returning_->next = NULL;

	return returning_;
}

tests_simple_list *
tests_simple_list_copy_constructor_inner(const tests_simple_list * list)
__amara__warn_unused_result__
;

tests_simple_list *
tests_simple_list_copy_constructor_inner(const tests_simple_list * list)
{
	tests_simple_list * ret_;

	if (list == NULL) {
		return NULL;
	}

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(tests_simple_list *)
#endif
			malloc(sizeof(tests_simple_list));
	forced_assertion(ret_ != NULL);

#ifndef NDEBUG
	assertion(list->first != NULL);
#endif
	ret_->first = list->first;

	ret_->next = tests_simple_list_copy_constructor_inner(list->next);

	return ret_;
}

tests_simple_list *
tests_simple_list_copy_constructor(const tests_simple_list * list)
{
	tests_simple_list * returning_;

#ifndef NDEBUG
	assertion(list != NULL);
#endif

	if (list->first == NULL) {

#ifndef NDEBUG
		assertion(list->next == NULL);
#endif
		returning_ =
#ifdef AMARA_USE_STD_CXX98
				(tests_simple_list *)
#endif
				malloc(sizeof(tests_simple_list));
		forced_assertion(returning_ != NULL);

		returning_->first = NULL;
		returning_->next = NULL;

		return returning_;
	}

	return tests_simple_list_copy_constructor_inner(list);
}

void
tests_simple_list_destructor_inner(tests_simple_list * tests)
;

void
tests_simple_list_destructor_inner(tests_simple_list * tests)
{
	if (tests != NULL) {

#ifndef NDEBUG
		assertion(tests->first != NULL);
#endif
		/*   The test can not be destroyed... */

		tests_simple_list_destructor_inner(tests->next);

		free(tests);
	}
}

void
tests_simple_list_destructor(tests_simple_list * tests)
{
#ifndef NDEBUG
	assertion(tests != NULL);
#endif

	if (tests->first == NULL) {

#ifndef NDEBUG
		assertion(tests->next == NULL);
#endif

		free(tests);
	} else {
		tests_simple_list_destructor_inner(tests);
	}
}

void
tests_simple_list_push_back(tests_simple_list * list, void (* test)(void))
{
	tests_simple_list * ptr_;

#ifndef NDEBUG
	assertion(list != NULL);
#endif

	if (list->first == NULL) {
		list->first = test;
	} else {
		ptr_ = list;
		while (ptr_->next != NULL) {
			ptr_ = ptr_->next;
		}

		ptr_->next =
#ifdef AMARA_USE_STD_CXX98
				(tests_simple_list *)
#endif
				malloc(sizeof(tests_simple_list));
		forced_assertion(ptr_->next != NULL);

		ptr_->next->first = test;

		ptr_->next->next = NULL;
	}
}

int
tests_simple_list_length(const tests_simple_list * tests)
{
	int ret_;
	const tests_simple_list * ptr_;

#ifndef NDEBUG
	assertion(tests != NULL);
#endif

	ret_ = 0;
	ptr_ = tests;
	while (ptr_ != NULL) {
		ret_ += 1;
		ptr_ = ptr_->next;
	}

	return ret_;
}

tests_simple_list *
tests_simple_list_scramble_tests(const tests_simple_list * tests)
{
	tests_simple_list * tests_copy_;
	int tests_copy_len_;
	tests_simple_list * scrambled_tests_;

	/*   Two lists, one empty and the other has the elements in
	 * order. */

	tests_copy_ = tests_simple_list_copy_constructor(tests);
	forced_assertion(tests_copy_ != NULL);

	scrambled_tests_ = tests_simple_list_default_constructor();
	forced_assertion(scrambled_tests_ != NULL);

	/*   While one of the lists holds elements... */

	tests_copy_len_ = tests_simple_list_length(tests_copy_);

	/*   Loop this: pick randomly an element out of the elements
	 * list and append it at the end of the other list, which
	 * initially was empty. */

	/* XXX */

	/*   Repeat until all of the elements have been moved from one
	 * of the lists to the other. */

	/* XXX */

	return NULL;  /* XXX */
}

void
tests_simple_list_run_tests(const tests_simple_list * tests)
{
	const tests_simple_list * ptr_;

	ptr_ = tests;

	while (ptr_ != NULL) {
		ptr_->first();
		ptr_ = ptr_->next;
	}
}
