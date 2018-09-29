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
 * src/stt/stt_rational_subnode_tests.c: Test the Amara syntax tree
 * rational subnode.
 */

#include "../asr/assertion.h"
#include "stt_rational_subnode.h"

void stt_rational_subnode_construct_and_destruct_test_0()
{
	stt_rational_subnode * rational_subnode_;
	rational_subnode_ = stt_rational_subnode_default_constructor();
	assertion(rational_subnode_ != NULL);
	assertion(rational_subnode_->raw_ == NULL);
	stt_rational_subnode_destructor(rational_subnode_);
}

void stt_rational_subnode_construct_and_destruct_test_1()
{
	stt_rational_subnode * rational_subnode_zero_;
	stt_rational_subnode * rational_subnode_one_;
	amara_string * raw_rational_;
	rational_subnode_zero_ = stt_rational_subnode_default_constructor();
	assertion(rational_subnode_zero_ != NULL);
	assertion(rational_subnode_zero_->raw_ == NULL);
	raw_rational_ = amara_string_exhaustive_constructor("0.1");
	stt_rational_subnode_set_raw(
			rational_subnode_zero_, raw_rational_);
	rational_subnode_one_ = stt_rational_subnode_copy_constructor(rational_subnode_zero_);
	stt_rational_subnode_destructor(rational_subnode_one_);
	stt_rational_subnode_destructor(rational_subnode_zero_);
}

void stt_rational_subnode_construct_and_destruct_tests()
{
	stt_rational_subnode_construct_and_destruct_test_0();
	stt_rational_subnode_construct_and_destruct_test_1();
}

void
stt_rational_subnode_tests()
{
	stt_rational_subnode_construct_and_destruct_tests();
}
