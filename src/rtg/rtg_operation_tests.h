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
 * src/rtg/rtg_operation_tests.h: Test the Amara runtime graph
 * application function operation.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__OPERATION_TESTS__H__
#define __AMARA__RUN_TIME_GRAPH__OPERATION_TESTS__H__

#include "rtg_operation.h"

rtg_operation *
rtg_operation_example_print_foo(void)
__attribute__((warn_unused_result))
;

void
assert_expectations_on_rtg_operation_example_print_foo(
		const rtg_operation * operation)
;

rtg_operation *
rtg_operation_example_print_bar(void)
__attribute__((warn_unused_result))
;

void
assert_expectations_on_rtg_operation_example_print_bar(
		const rtg_operation * operation)
;

rtg_operation *
rtg_operation_example_read_natural_into_i_foo(void)
__attribute__((warn_unused_result))
;

void
rtg_operation_tests(void)
;

#endif
