/*
 * Copyright 2020 Mercedes Catherine Salazar
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
 * src/tst/tests_simple_list_tests.c: Tests the tests simple list.
 */

#include <stdlib.h>

#include "../asr/assertion.h"

#include "tests_simple_list.h"

void
tests_simple_list_copy_constructor_test_0()
{
	tests_simple_list * l0_;
	tests_simple_list * l1_;

	l0_ = tests_simple_list_default_constructor();
	forced_assertion(l0_ != NULL);
#ifndef NDEBUG
	assertion(l0_->first == NULL);
	assertion(l0_->next == NULL);
#endif

	l1_ = tests_simple_list_copy_constructor(l0_);
	forced_assertion(l1_ != NULL);
#ifndef NDEBUG
	assertion(l1_->first == NULL);
	assertion(l1_->next == NULL);
#endif

	tests_simple_list_destructor(l1_);
	tests_simple_list_destructor(l0_);
}

void
tests_simple_list_copy_constructor_tests()
{
	tests_simple_list_copy_constructor_test_0();
}

void
tests_simple_list_constructors_tests()
{
	tests_simple_list_copy_constructor_tests();
}

void
tests_simple_list_tests()
{
	tests_simple_list_constructors_tests();
}
