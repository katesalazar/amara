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
 * src/stt/stt_condition_subnode_tests.h: Test the Amara syntax tree
 * condition subnode.
 */

#ifndef __AMARA__SYNTAX_TREE__CONDITION_SUBNODE_TESTS__H__
#define __AMARA__SYNTAX_TREE__CONDITION_SUBNODE_TESTS__H__

/*   For `stt_condition_subnode`. */
#include "stt_condition_subnode.h"

#ifndef NDEBUG

void
assert_expectations_on_stt_condition_subnode_example_simple_condition(
		const stt_condition_subnode * condition_subnode)
;

#endif

void
stt_condition_subnode_tests(void)
;

#endif
