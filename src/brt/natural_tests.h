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
 * src/brt/natural_tests.h: Test the algebraic natural number class.
 */

#ifndef __AMARA__BASIC_ARITHMETIC__NATURAL_TESTS__H__
#define __AMARA__BASIC_ARITHMETIC__NATURAL_TESTS__H__

/*   For the `natural` class. */
#include "natural.h"

natural *
natural_example_zero(void)
;

#ifndef NDEBUG

void
assert_expectations_on_natural_example_zero(const natural * zero)
;

#endif

natural *
natural_example_one(void)
;

#ifndef NDEBUG

void
assert_expectations_on_natural_example_one(const natural * one)
;

#endif

natural *
natural_example_six(void)
;

#ifndef NDEBUG

void
assert_expectations_on_natural_example_six(const natural * six)
;

#endif

void
natural_tests(void)
;

#endif
