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
 * src/stt/stt_natural_literal_subnode_tests.c: Test the Amara syntax
 * tree natural literal subnode.
 */

#include "../asr/assertion.h"

#include "stt_natural_literal_subnode.h"

#include "stt_natural_literal_subnode_tests.h"

void
stt_natural_literal_subnode_default_constructor_test_0()
{
	stt_natural_literal_subnode * natural_literal_subnode_;

	natural_literal_subnode_ =
			stt_natural_literal_subnode_default_constructor();
	forced_assertion(natural_literal_subnode_ != NULL);
	forced_assertion(natural_literal_subnode_->raw_ == NULL);

	stt_natural_literal_subnode_destructor(natural_literal_subnode_);
}

void
stt_natural_literal_subnode_constructors_tests()
{
	stt_natural_literal_subnode_default_constructor_test_0();
}

tests_simple_list *
register_stt_natural_literal_subnode_constructors_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_natural_literal_subnode_constructors_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_natural_literal_subnode_default_constructor_test_0);
	return returning_;
}

void
stt_natural_literal_subnode_setter_test_0()
{
	stt_natural_literal_subnode * natural_literal_subnode_;
	amara_string * raw_natural_;
	amara_boolean equality_;

	natural_literal_subnode_ =
			stt_natural_literal_subnode_default_constructor();
	assertion(natural_literal_subnode_ != NULL);
	assertion(natural_literal_subnode_->raw_ == NULL);

	raw_natural_ = amara_string_exhaustive_constructor("0");

	stt_natural_literal_subnode_set_raw(
			natural_literal_subnode_, raw_natural_);

	equality_ = amara_string_equality(
			natural_literal_subnode_->raw_, raw_natural_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(raw_natural_);
	stt_natural_literal_subnode_destructor(natural_literal_subnode_);
}

void
stt_natural_literal_subnode_setter_test_1()
{
	stt_natural_literal_subnode * natural_literal_subnode_;
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	amara_boolean equality_;

	natural_literal_subnode_ =
			stt_natural_literal_subnode_default_constructor();
	assertion(natural_literal_subnode_ != NULL);
	assertion(natural_literal_subnode_->raw_ == NULL);

	raw_natural_zero_ = amara_string_exhaustive_constructor("0");

	stt_natural_literal_subnode_set_raw(
			natural_literal_subnode_, raw_natural_zero_);

	equality_ = amara_string_equality(
			natural_literal_subnode_->raw_, raw_natural_zero_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	raw_natural_one_ = amara_string_exhaustive_constructor("1");

	stt_natural_literal_subnode_set_raw(
			natural_literal_subnode_, raw_natural_one_);

	equality_ = amara_string_equality(
			natural_literal_subnode_->raw_, raw_natural_one_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(raw_natural_one_);
	amara_string_destructor(raw_natural_zero_);
	stt_natural_literal_subnode_destructor(natural_literal_subnode_);
}

void
stt_natural_literal_subnode_setter_tests()
{
	stt_natural_literal_subnode_setter_test_0();
	stt_natural_literal_subnode_setter_test_1();
}

tests_simple_list *
register_stt_natural_literal_subnode_setter_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_natural_literal_subnode_setter_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_natural_literal_subnode_setter_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_natural_literal_subnode_setter_test_1);
	return returning_;
}

void
stt_natural_literal_subnode_tests()
{
	stt_natural_literal_subnode_constructors_tests();
	stt_natural_literal_subnode_setter_tests();
}

tests_simple_list *
register_stt_natural_literal_subnode_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_natural_literal_subnode_constructors_tests(
			tests);
	returning_ = register_stt_natural_literal_subnode_setter_tests(
			returning_);
	return returning_;
}
