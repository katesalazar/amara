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
 * src/cmn/amara_string_tests.c: Test the Amara string class.
 */

#include "../asr/assertion.h"
#include "amara_string.h"

void
amara_string_construct_and_destruct_test_0()
{
	amara_string * amara_string_;
	amara_string_ = amara_string_default_constructor();
	assertion(amara_string_ != NULL);
	assertion(amara_string_->value_ == NULL);
	amara_string_destructor(amara_string_);
}

void
amara_string_construct_and_destruct_test_1()
{
	amara_string * amara_string_;
	amara_string_ = amara_string_exhaustive_constructor("foo");
	assertion(amara_string_ != NULL);
	assertion(amara_string_->value_ != NULL);
	amara_string_destructor(amara_string_);
}

void
amara_string_construct_and_destruct_tests()
{
	amara_string_construct_and_destruct_test_0();
	amara_string_construct_and_destruct_test_1();
}

void
amara_string_tests()
{
	amara_string_construct_and_destruct_tests();
}
