/*
 * Copyright 2018-2020 Mercedes Catherine Salazar
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
 * src/stt/stt_applications_simple_list_tests.h: Test the Amara syntax
 * tree applications simple list.
 */

#ifndef __AMARA__SYNTAX_TREE__APPLICATIONS_SIMPLE_LIST_TESTS__H__
#define __AMARA__SYNTAX_TREE__APPLICATIONS_SIMPLE_LIST_TESTS__H__

#include "../tst/tests_simple_list.h"

#include "stt_applications_simple_list.h"

stt_applications_simple_list *
stt_applications_simple_list_example_two_applications(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_applications_simple_list_example_two_applications(
		const stt_applications_simple_list * list)
;

#endif

void
stt_applications_simple_list_tests(void)
;

tests_simple_list *
register_stt_applications_simple_list_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

#endif
