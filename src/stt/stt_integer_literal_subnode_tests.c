/*
 * Copyright 2018, 2020 Mercedes Catherine Salazar
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
 * src/stt/stt_integer_literal_subnode.c: Test the Amara syntax tree
 * integer subnode.
 */

#include "../asr/assertion.h"

#include "stt_integer_literal_subnode.h"

#include "stt_integer_literal_subnode_tests.h"

void stt_integer_literal_subnode_default_constructor_test_0()
{
	stt_integer_literal_subnode * integer_literal_subnode_;

	integer_literal_subnode_ =
			stt_integer_literal_subnode_default_constructor();
	forced_assertion(integer_literal_subnode_ != NULL);
	forced_assertion(integer_literal_subnode_->raw_ == NULL);

	stt_integer_literal_subnode_destructor(integer_literal_subnode_);
}

void stt_integer_literal_subnode_copy_constructor_test_0()
{
	stt_integer_literal_subnode * integer_literal_subnode_zero_;
	stt_integer_literal_subnode * integer_literal_subnode_one_;
	amara_string * raw_integer_;
	amara_boolean equality_;

	integer_literal_subnode_zero_ =
			stt_integer_literal_subnode_default_constructor();
	assertion(integer_literal_subnode_zero_ != NULL);
	assertion(integer_literal_subnode_zero_->raw_ == NULL);

	raw_integer_ = amara_string_exhaustive_constructor("-1");
	assertion(raw_integer_ != NULL);

	stt_integer_literal_subnode_set_raw(
			integer_literal_subnode_zero_, raw_integer_);
	assertion(integer_literal_subnode_zero_->raw_ != NULL);
	equality_ = amara_string_equality(
			integer_literal_subnode_zero_->raw_, raw_integer_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	integer_literal_subnode_one_ =
			stt_integer_literal_subnode_copy_constructor(
					integer_literal_subnode_zero_);
	assertion(integer_literal_subnode_one_ != NULL);
	assertion(integer_literal_subnode_one_->raw_ != NULL);
	equality_ = amara_string_equality(
			integer_literal_subnode_one_->raw_, raw_integer_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(raw_integer_);
	stt_integer_literal_subnode_destructor(integer_literal_subnode_one_);
	stt_integer_literal_subnode_destructor(integer_literal_subnode_zero_);
}

void stt_integer_literal_subnode_constructors_tests()
{
	stt_integer_literal_subnode_default_constructor_test_0();
	stt_integer_literal_subnode_copy_constructor_test_0();
}

tests_simple_list *
register_stt_integer_literal_subnode_constructors_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_integer_literal_subnode_constructors_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_integer_literal_subnode_default_constructor_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_integer_literal_subnode_copy_constructor_test_0);
	return returning_;
}

void stt_integer_literal_subnode_get_raw_test_0()
{
	stt_integer_literal_subnode * integer_literal_subnode_;
	amara_string * raw_integer_;
	amara_string * extracted_raw_integer_;
	amara_boolean equality_;

	raw_integer_ = amara_string_exhaustive_constructor("-1");
	assertion(raw_integer_ != NULL);
	assertion(raw_integer_->value_ != NULL);

	integer_literal_subnode_ =
			stt_integer_literal_subnode_exhaustive_constructor(
					raw_integer_);
	assertion(integer_literal_subnode_ != NULL);
	assertion(integer_literal_subnode_->raw_ != NULL);
	equality_ = amara_string_equality(
			integer_literal_subnode_->raw_, raw_integer_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	extracted_raw_integer_ = stt_integer_literal_subnode_get_raw(
			integer_literal_subnode_);
	assertion(integer_literal_subnode_->raw_ != NULL);
	equality_ = amara_string_equality(
			integer_literal_subnode_->raw_, raw_integer_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	equality_ = amara_string_equality(
			raw_integer_, extracted_raw_integer_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	stt_integer_literal_subnode_destructor(integer_literal_subnode_);
	amara_string_destructor(raw_integer_);
}

void stt_integer_literal_subnode_get_raw_tests()
{
	stt_integer_literal_subnode_get_raw_test_0();
}

tests_simple_list *
register_stt_integer_literal_subnode_get_raw_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_integer_literal_subnode_get_raw_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_integer_literal_subnode_get_raw_test_0);
	return returning_;
}

void stt_integer_literal_subnode_set_raw_test_0()
{
	stt_integer_literal_subnode * subnode_;
	amara_string * raw_integer_;
	amara_boolean equality_;

	subnode_ = stt_integer_literal_subnode_default_constructor();
	assertion(subnode_ != NULL);
	assertion(subnode_->raw_ == NULL);

	raw_integer_ = amara_string_exhaustive_constructor("-1");
	assertion(raw_integer_ != NULL);
	assertion(raw_integer_->value_ != NULL);

	stt_integer_literal_subnode_set_raw(subnode_, raw_integer_);
	assertion(subnode_->raw_ != NULL);
	equality_ = amara_string_equality(subnode_->raw_, raw_integer_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(raw_integer_);
	stt_integer_literal_subnode_destructor(subnode_);
}

void stt_integer_literal_subnode_set_raw_test_1()
{
	stt_integer_literal_subnode * subnode_;
	amara_string * raw_integer_;

	subnode_ = stt_integer_literal_subnode_default_constructor();
	assertion(subnode_ != NULL);
	assertion(subnode_->raw_ == NULL);

	raw_integer_ = NULL;

	stt_integer_literal_subnode_set_raw(subnode_, raw_integer_);
	assertion(subnode_->raw_ == NULL);

	stt_integer_literal_subnode_destructor(subnode_);
}

void stt_integer_literal_subnode_set_raw_test_2()
{
	stt_integer_literal_subnode * subnode_;
	amara_string * raw_integer_zero_;
	amara_string * raw_integer_one_;
	amara_boolean equality_;

	raw_integer_zero_ = amara_string_exhaustive_constructor("-1");
	assertion(raw_integer_zero_ != NULL);
	assertion(raw_integer_zero_->value_ != NULL);

	subnode_ = stt_integer_literal_subnode_exhaustive_constructor(
			raw_integer_zero_);
	assertion(subnode_ != NULL);
	assertion(subnode_->raw_ != NULL);
	equality_ = amara_string_equality(subnode_->raw_, raw_integer_zero_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	raw_integer_one_ = amara_string_exhaustive_constructor("-2");
	assertion(raw_integer_one_ != NULL);
	assertion(raw_integer_one_->value_ != NULL);
	equality_ = amara_string_equality(raw_integer_zero_, raw_integer_one_);
	assertion(equality_ == AMARA_BOOLEAN_FALSE);

	stt_integer_literal_subnode_set_raw(subnode_, raw_integer_one_);
	assertion(subnode_->raw_ != NULL);
	equality_ = amara_string_equality(subnode_->raw_, raw_integer_one_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(raw_integer_one_);
	amara_string_destructor(raw_integer_zero_);
	stt_integer_literal_subnode_destructor(subnode_);
}

void stt_integer_literal_subnode_set_raw_test_3()
{
	stt_integer_literal_subnode * subnode_;
	amara_string * raw_integer_zero_;
	amara_string * raw_integer_one_;
	amara_boolean equality_;

	raw_integer_zero_ = amara_string_exhaustive_constructor("-1");
	assertion(raw_integer_zero_ != NULL);
	assertion(raw_integer_zero_->value_ != NULL);

	subnode_ = stt_integer_literal_subnode_exhaustive_constructor(
			raw_integer_zero_);
	assertion(subnode_ != NULL);
	assertion(subnode_->raw_ != NULL);
	equality_ = amara_string_equality(subnode_->raw_, raw_integer_zero_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	raw_integer_one_ = NULL;

	stt_integer_literal_subnode_set_raw(subnode_, raw_integer_one_);
	assertion(subnode_->raw_ == NULL);

	amara_string_destructor(raw_integer_zero_);
	stt_integer_literal_subnode_destructor(subnode_);
}

void stt_integer_literal_subnode_set_raw_tests()
{
	stt_integer_literal_subnode_set_raw_test_0();
	stt_integer_literal_subnode_set_raw_test_1();
	stt_integer_literal_subnode_set_raw_test_2();
	stt_integer_literal_subnode_set_raw_test_3();
}

tests_simple_list *
register_stt_integer_literal_subnode_set_raw_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_integer_literal_subnode_set_raw_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_integer_literal_subnode_set_raw_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_integer_literal_subnode_set_raw_test_1);
	tests_simple_list_push_back(
			returning_,
			& stt_integer_literal_subnode_set_raw_test_2);
	tests_simple_list_push_back(
			returning_,
			& stt_integer_literal_subnode_set_raw_test_3);
	return returning_;
}

void
stt_integer_literal_subnode_tests()
{
	stt_integer_literal_subnode_constructors_tests();
	stt_integer_literal_subnode_get_raw_tests();
	stt_integer_literal_subnode_set_raw_tests();
}

tests_simple_list *
register_stt_integer_literal_subnode_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_integer_literal_subnode_constructors_tests(
			tests);
	returning_ = register_stt_integer_literal_subnode_get_raw_tests(
			returning_);
	returning_ = register_stt_integer_literal_subnode_set_raw_tests(
			returning_);
	return returning_;
}
