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
 * src/stt/stt_string_literal_subnode_tests.c: Test the Amara syntax
 * tree string literal subnode class.
 */

#include "../asr/assertion.h"
#include "stt_string_literal_subnode.h"

void
stt_string_literal_subnode_equality_test_0()
{
	stt_string_literal_subnode * subnode_zero_;
	stt_string_literal_subnode * subnode_one_;
	amara_string * foo_;
	amara_boolean equality_;
	foo_ = amara_string_exhaustive_constructor("foo");
	subnode_zero_ = stt_string_literal_subnode_exhaustive_constructor(
			foo_);
	subnode_one_ = stt_string_literal_subnode_exhaustive_constructor(
			foo_);
	equality_ = stt_string_literal_subnode_equality(
			subnode_zero_, subnode_one_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	stt_string_literal_subnode_destructor(subnode_one_);
	stt_string_literal_subnode_destructor(subnode_zero_);
}

void
stt_string_literal_subnode_equality_tests()
{
	stt_string_literal_subnode_equality_test_0();
}

void
stt_string_literal_subnode_tests()
{
	stt_string_literal_subnode_equality_tests();
}
