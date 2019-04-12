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
 * src/cmn/amara_string_tests.h: Test the Amara string class.
 */

#ifndef __AMARA__COMMON__AMARA_STRING_TESTS__H__
#define __AMARA__COMMON__AMARA_STRING_TESTS__H__

#include "amara_string.h"

amara_string *
amara_string_example_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_amara_string_example_foo(const amara_string * string)
;

#endif

amara_string *
amara_string_example_bar(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_amara_string_example_bar(const amara_string * string)
;

#endif

void
amara_string_tests(void)
;

#endif
