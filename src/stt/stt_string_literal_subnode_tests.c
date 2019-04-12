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
 * src/stt/stt_string_literal_subnode_tests.c: Test the Amara syntax
 * tree string literal subnode class.
 */

#include "../asr/assertion.h"

#include "stt_string_literal_subnode.h"

#include "stt_string_literal_subnode_tests.h"

void
stt_string_literal_subnode_set_string_literal_test_0()
{
	stt_string_literal_subnode * subnode_;
	amara_string * foo_;
	amara_string * bar_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	foo_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(foo_ != NULL);
	forced_assertion(foo_->value_ != NULL);

	subnode_ = stt_string_literal_subnode_exhaustive_constructor(foo_);
	forced_assertion(subnode_ != NULL);
	forced_assertion(subnode_->string_literal_ != NULL);
	forced_assertion(subnode_->string_literal_->value_ != NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(foo_, subnode_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	bar_ = amara_string_exhaustive_constructor("bar");
	forced_assertion(bar_ != NULL);
	forced_assertion(bar_->value_ != NULL);

	stt_string_literal_subnode_set_string_literal(subnode_, bar_);
	forced_assertion(subnode_->string_literal_ != NULL);
	forced_assertion(subnode_->string_literal_->value_ != NULL);
#ifndef NDEBUG
	assertion(bar_->value_ != NULL);
	equality_ = amara_string_equality(bar_, subnode_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	amara_string_destructor(bar_);
	stt_string_literal_subnode_destructor(subnode_);
	amara_string_destructor(foo_);
}

void
stt_string_literal_subnode_set_string_literal_test_1()
{
	stt_string_literal_subnode * subnode_;
	amara_string * foo_;
	amara_string * bar_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	foo_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(foo_ != NULL);
	forced_assertion(foo_->value_ != NULL);

	subnode_ = stt_string_literal_subnode_exhaustive_constructor(foo_);
	forced_assertion(subnode_ != NULL);
	forced_assertion(subnode_->string_literal_ != NULL);
	forced_assertion(subnode_->string_literal_->value_ != NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(foo_, subnode_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	bar_ = NULL;

	stt_string_literal_subnode_set_string_literal(subnode_, bar_);
#ifndef NDEBUG
	assertion(subnode_->string_literal_ == NULL);
	equality_ = amara_string_equality(bar_, subnode_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_string_literal_subnode_destructor(subnode_);
	amara_string_destructor(foo_);
}

void
stt_string_literal_subnode_set_string_literal_test_2()
{
	stt_string_literal_subnode * subnode_;
	amara_string * foo_;
	amara_string * bar_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	foo_ = NULL;

	subnode_ = stt_string_literal_subnode_exhaustive_constructor(foo_);
	forced_assertion(subnode_ != NULL);
	forced_assertion(subnode_->string_literal_ != NULL);
	forced_assertion(subnode_->string_literal_->value_ != NULL);
#ifndef NDEBUG
	equality_ = amara_string_equality(foo_, subnode_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	bar_ = amara_string_exhaustive_constructor("bar");
	forced_assertion(bar_ != NULL);
	forced_assertion(bar_->value_ != NULL);

	stt_string_literal_subnode_set_string_literal(subnode_, bar_);
#ifndef NDEBUG
	assertion(subnode_->string_literal_ != NULL);
	assertion(subnode_->string_literal_->value_ != NULL);
	equality_ = amara_string_equality(bar_, subnode_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	amara_string_destructor(bar_);
	stt_string_literal_subnode_destructor(subnode_);
}

void
stt_string_literal_subnode_set_string_literal_tests()
{
	stt_string_literal_subnode_set_string_literal_test_0();
	stt_string_literal_subnode_set_string_literal_test_1();
	stt_string_literal_subnode_set_string_literal_test_2();
}

void
stt_string_literal_subnode_equality_test_0()
{
	stt_string_literal_subnode * subnode_zero_;
	stt_string_literal_subnode * subnode_one_;
	amara_string * foo_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	foo_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(foo_ != NULL);
	forced_assertion(foo_->value_ != NULL);

	subnode_zero_ = stt_string_literal_subnode_exhaustive_constructor(
			foo_);
	forced_assertion(subnode_zero_ != NULL);
	forced_assertion(subnode_zero_->string_literal_ != NULL);
	forced_assertion(subnode_zero_->string_literal_->value_ != NULL);
#ifndef NDEBUG
	assertion(foo_->value_ != NULL);
	equality_ = amara_string_equality(
			foo_, subnode_zero_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	subnode_one_ = stt_string_literal_subnode_exhaustive_constructor(
			foo_);
	forced_assertion(subnode_one_ != NULL);
	forced_assertion(subnode_one_->string_literal_ != NULL);
	forced_assertion(subnode_one_->string_literal_->value_ != NULL);
#ifndef NDEBUG
	assertion(foo_->value_ != NULL);
	equality_ = amara_string_equality(
			foo_, subnode_zero_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

#ifndef NDEBUG
	equality_ = stt_string_literal_subnode_equality(
			subnode_zero_, subnode_one_);
	assertion(subnode_zero_->string_literal_ != NULL);
	assertion(subnode_zero_->string_literal_->value_ != NULL);
	assertion(subnode_one_->string_literal_ != NULL);
	assertion(subnode_one_->string_literal_->value_ != NULL);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_string_literal_subnode_destructor(subnode_one_);
	stt_string_literal_subnode_destructor(subnode_zero_);
	amara_string_destructor(foo_);
}

void
stt_string_literal_subnode_equality_test_1()
{
	stt_string_literal_subnode * subnode_zero_;
	stt_string_literal_subnode * subnode_one_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	subnode_zero_ = stt_string_literal_subnode_default_constructor();
	forced_assertion(subnode_zero_ != NULL);
	forced_assertion(subnode_zero_->string_literal_ == NULL);

	subnode_one_ = stt_string_literal_subnode_default_constructor();
	forced_assertion(subnode_one_ != NULL);
	forced_assertion(subnode_one_->string_literal_ == NULL);

#ifndef NDEBUG
	equality_ = stt_string_literal_subnode_equality(
			subnode_zero_, subnode_one_);
	assertion(subnode_zero_->string_literal_ == NULL);
	assertion(subnode_one_->string_literal_ == NULL);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	stt_string_literal_subnode_destructor(subnode_one_);
	stt_string_literal_subnode_destructor(subnode_zero_);
}

void
stt_string_literal_subnode_equality_tests()
{
	stt_string_literal_subnode_equality_test_0();
	stt_string_literal_subnode_equality_test_1();
}

void
stt_string_literal_subnode_tests()
{
	stt_string_literal_subnode_set_string_literal_tests();
	stt_string_literal_subnode_equality_tests();
}
