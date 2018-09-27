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
 * src/stt/stt_integer_subnode.c: Test the Amara syntax tree integer
 * subnode.
 */

#include "../asr/assertion.h"
#include "stt_integer_subnode.h"

void stt_integer_subnode_construct_and_destruct_test_0()
{
	stt_integer_subnode * integer_subnode_;
	integer_subnode_ = stt_integer_subnode_default_constructor();
	assertion(integer_subnode_ != NULL);
	assertion(integer_subnode_->raw_ == NULL);
	stt_integer_subnode_destructor(integer_subnode_);
}

void stt_integer_subnode_construct_and_destruct_test_1()
{
	stt_integer_subnode * integer_subnode_zero_;
	stt_integer_subnode * integer_subnode_one_;
	amara_string * raw_integer_;
	integer_subnode_zero_ = stt_integer_subnode_default_constructor();
	assertion(integer_subnode_zero_ != NULL);
	assertion(integer_subnode_zero_->raw_ == NULL);
	raw_integer_ = amara_string_exhaustive_constructor("-1");
	stt_integer_subnode_set_raw(integer_subnode_zero_, raw_integer_);
	integer_subnode_one_ = stt_integer_subnode_copy_constructor(
			integer_subnode_zero_);
	assertion(integer_subnode_one_ != NULL);
	assertion(integer_subnode_one_->raw_ != NULL);
	amara_string_destructor(raw_integer_);
	stt_integer_subnode_destructor(integer_subnode_one_);
	stt_integer_subnode_destructor(integer_subnode_zero_);
}

void stt_integer_subnode_construct_and_destruct_tests()
{
	stt_integer_subnode_construct_and_destruct_test_0();
	stt_integer_subnode_construct_and_destruct_test_1();
}

void
stt_integer_subnode_tests()
{
	stt_integer_subnode_construct_and_destruct_tests();
}
