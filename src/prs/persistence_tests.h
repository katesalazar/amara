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
 * src/prs/persistence_tests.h: Tests for the persistence system.
 */

#include "../tst/tests_simple_list.h"

#ifndef __AMARA__PERSISTENCE__PERSISTENCE_TESTS__H__
#define __AMARA__PERSISTENCE__PERSISTENCE_TESTS__H__

void
persistence_tests(void)
;

tests_simple_list *
register_persistence_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

#endif
