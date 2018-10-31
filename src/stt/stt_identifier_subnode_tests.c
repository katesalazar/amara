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
 * src/stt/stt_identifier_subnode_tests.c: Amara syntax tree identifier
 * subnode. An identifier does not have any atomic sense, so do not look
 * for the run time graph counter part of this class.
 */

#include "../asr/assertion.h"
#include "stt_identifier_subnode.h"

void stt_identifier_subnode_construct_and_destruct_test_0()
{
	stt_identifier_subnode * identifier_subnode_;
	identifier_subnode_ = stt_identifier_subnode_default_constructor();
	assertion(identifier_subnode_ != NULL);
	assertion(identifier_subnode_->value_ == NULL);
	stt_identifier_subnode_destructor(identifier_subnode_);
}

void stt_identifier_subnode_construct_and_destruct_tests()
{
	stt_identifier_subnode_construct_and_destruct_test_0();
}

void
stt_identifier_subnode_setter_test_0()
{
	stt_identifier_subnode * identifier_subnode_;
	amara_string * identifier_;

	identifier_subnode_ = stt_identifier_subnode_default_constructor();
	assertion(identifier_subnode_ != NULL);
	assertion(identifier_subnode_->value_ == NULL);

	identifier_ = NULL;

	stt_identifier_subnode_set_value(identifier_subnode_, identifier_);
	assertion(identifier_subnode_->value_ == NULL);

	stt_identifier_subnode_destructor(identifier_subnode_);
}

void
stt_identifier_subnode_setter_test_1()
{
	stt_identifier_subnode * identifier_subnode_;
	amara_string * identifier_zero_;
	amara_string * identifier_one_;

	identifier_subnode_ = stt_identifier_subnode_default_constructor();
	assertion(identifier_subnode_ != NULL);
	assertion(identifier_subnode_->value_ == NULL);

	identifier_zero_ = amara_string_exhaustive_constructor("foo");
	assertion(identifier_zero_ != NULL);
	assertion(identifier_zero_->value_ != NULL);

	stt_identifier_subnode_set_value(
			identifier_subnode_, identifier_zero_);
	assertion(identifier_subnode_->value_ != NULL);
	assertion(identifier_subnode_->value_->value_ != NULL);
	assertion(identifier_zero_->value_ != NULL);

	identifier_one_ = NULL;

	stt_identifier_subnode_set_value(identifier_subnode_, identifier_one_);
	assertion(identifier_subnode_->value_ == NULL);

	amara_string_destructor(identifier_zero_);
	stt_identifier_subnode_destructor(identifier_subnode_);
}

void
stt_identifier_subnode_setter_tests()
{
	stt_identifier_subnode_setter_test_0();
	stt_identifier_subnode_setter_test_1();
}

void
stt_identifier_subnode_tests()
{
	stt_identifier_subnode_construct_and_destruct_tests();
	stt_identifier_subnode_setter_tests();
}
