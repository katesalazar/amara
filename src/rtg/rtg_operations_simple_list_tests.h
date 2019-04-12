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
 * src/rtg/rtg_operations_simple_list_tests.h: Test the Amara runtime
 * graph application function operations simple list.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__OPERATIONS_SIMPLE_LIST_TESTS__H__
#define __AMARA__RUN_TIME_GRAPH__OPERATIONS_SIMPLE_LIST_TESTS__H__

#ifndef NDEBUG

void
assert_expectations_on_rtg_operations_simple_list_example_print_identifier_foo(
		const rtg_operations_simple_list * list)
;

#endif

void
rtg_operations_simple_list_tests(void)
;

#endif