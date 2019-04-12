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
 * src/rtg/rtg_named_function_tests.h: Test the Amara run time graph
 * application named function.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTION_TESTS__H__
#define __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTION_TESTS__H__

#include "rtg_named_function.h"

rtg_named_function *
rtg_named_function_example_print_string_literal_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
		const rtg_named_function * named_function)
;

#endif

rtg_named_function *
rtg_named_function_example_print_string_literal_bar(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_rtg_named_function_example_print_string_literal_bar(
		const rtg_named_function * named_function)
;

#endif

#ifndef NDEBUG

void
assert_expectations_on_rtg_named_function_example_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
		const rtg_named_function * named_function)
;

#endif

void
rtg_named_function_tests(void)
;

#endif
