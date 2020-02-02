/*
 * Copyright 2018, 2020 Mercedes Catherine Salazar
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
 * src/stt/stt_identifier_subnode_tests.h: Amara syntax tree identifier
 * subnode. An identifier does not have any atomic sense, so do not look
 * for the run time graph counter part of this class.
 */

#ifndef __AMARA__SYNTAX_TREE__IDENTIFIER_SUBNODE_TESTS__H__
#define __AMARA__SYNTAX_TREE__IDENTIFIER_SUBNODE_TESTS__H__

#include "../tst/tests_simple_list.h"

void
stt_identifier_subnode_tests(void)
;

tests_simple_list *
register_stt_identifier_subnode_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

#endif
