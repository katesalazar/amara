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
 * src/stt/stt_named_function_subnode_tests.h: Test the Amara syntax
 * tree application named function subnode.
 */

#ifndef __AMARA__SYNTAX_TREE__NAMED_FUNCTION_SUBNODE_TESTS__H__
#define __AMARA__SYNTAX_TREE__NAMED_FUNCTION_SUBNODE_TESTS__H__

#include "../tst/tests_simple_list.h"

#include "stt_named_function_subnode.h"

#ifndef NDEBUG

void
assert_expectations_on_stt_named_function_subnode_example_print_string_literal_foo(
		const stt_named_function_subnode * subnode)
;

#endif

void
stt_named_function_subnode_tests(void)
;

tests_simple_list *
register_stt_named_function_subnode_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

#endif
