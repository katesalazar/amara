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
 * src/brt/integer_tests.c: Test the Algebraic integer number class.
 */

#include "integer.h"

#include "integer_tests.h"

void
raw_integer_validation_test_0()
{
	amara_string * raw_integer_;
	raw_integer_ = amara_string_exhaustive_constructor("-10");
	assert_valid_raw_integer(raw_integer_);
	amara_string_destructor(raw_integer_);
}

void
raw_integer_validation_tests()
{
	raw_integer_validation_test_0();
}

void
integer_tests()
{
	raw_integer_validation_tests();
}
