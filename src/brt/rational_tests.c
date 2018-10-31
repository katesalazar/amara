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
 * src/brt/rational_tests.c: Test the Amara algebraic rational number
 * class.
 */

#include "../asr/assertion.h"
#include "../cmn/amara_string.h"

#include "rational.h"

void
assert_valid_raw_rational_test_0()
{
	amara_string * raw_rational_;

	raw_rational_ = amara_string_exhaustive_constructor("-.1");
	assertion(raw_rational_ != NULL);
	assertion(raw_rational_->value_ != NULL);

	assert_valid_raw_rational(raw_rational_);
	assertion(raw_rational_->value_ != NULL);

	amara_string_destructor(raw_rational_);
}

void
assert_valid_raw_rational_tests()
{
	assert_valid_raw_rational_test_0();
}

void
rational_tests()
{
	assert_valid_raw_rational_tests();
}
