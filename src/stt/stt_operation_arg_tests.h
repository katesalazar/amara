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
 * src/stt/stt_operation_arg_tests.h: Amara syntax tree application
 * function operation argument tests.
 */

#ifndef __AMARA__SYNTAX_TREE__OPERATION_ARG_TESTS__H__
#define __AMARA__SYNTAX_TREE__OPERATION_ARG_TESTS__H__

/*   For `typedef struct stt_operation_arg { ... } stt_operation_arg;`. */
#include "stt_operation_arg.h"

stt_operation_arg *
stt_operation_arg_example_natural_literal_zero(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_arg_example_natural_literal_zero(
		const stt_operation_arg * operation_arg)
;

#endif

stt_operation_arg *
stt_operation_arg_example_string_literal_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_arg_example_string_literal_foo(
		const stt_operation_arg * operation_arg)
;

#endif

stt_operation_arg *
stt_operation_arg_example_identifier_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_arg_example_identifier_foo(
		const stt_operation_arg * operation_arg)
;

#endif

#endif
