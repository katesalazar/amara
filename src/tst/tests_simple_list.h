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
 * src/tst/tests_simple_list.h: Amara tests simple_list.
 */

#ifndef __AMARA__TESTS__TESTS_SIMPLE_LIST__H__
#define __AMARA__TESTS__TESTS_SIMPLE_LIST__H__

#include "../definitions.h"

typedef struct tests_simple_list {

	void (* first)(void);

	struct tests_simple_list * next;
} tests_simple_list
;

tests_simple_list *
tests_simple_list_default_constructor(void)
__amara__warn_unused_result__
;

/*   Creates a deep copy of the structure, where each output element is
 * a shallow copy of each input element. */
tests_simple_list *
tests_simple_list_copy_constructor(const tests_simple_list * list)
__amara__warn_unused_result__
;

void
tests_simple_list_destructor(tests_simple_list * tests)
;

void
tests_simple_list_push_back(tests_simple_list * list, void (* test)(void))
;

int
tests_simple_list_length(const tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
tests_simple_list_scramble_tests(const tests_simple_list * tests)
__amara__warn_unused_result__
;

void
tests_simple_list_run_tests(const tests_simple_list * tests)
;

#endif
