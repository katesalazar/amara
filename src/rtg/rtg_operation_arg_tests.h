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
 * src/rtg/rtg_operation_arg_tests.h: Test the Amara run time graph
 * application function operation argument class.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__OPERATION_ARG_TESTS__H__
#define __AMARA__RUN_TIME_GRAPH__OPERATION_ARG_TESTS__H__

rtg_operation_arg *
rtg_operation_arg_example_string_literal_foo(void)
__attribute__((warn_unused_result))
;

void
assert_expectations_on_rtg_operation_arg_example_string_literal_foo(
		const rtg_operation_arg * operation_arg)
;

rtg_operation_arg *
rtg_operation_arg_example_identifier_foo(void)
__attribute__((warn_unused_result))
;

void
assert_expectations_on_rtg_operation_arg_example_identifier_foo(
		const rtg_operation_arg * operation_arg)
;

rtg_operation_arg *
rtg_operation_arg_example_identifier_bar(void)
__attribute__((warn_unused_result))
;

void
assert_expectations_on_rtg_operation_arg_example_identifier_bar(
		const rtg_operation_arg * operation_arg)
;

void
rtg_operation_arg_tests(void)
;

#endif
