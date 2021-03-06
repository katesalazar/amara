/*
 * Copyright 2018-2020 Mercedes Catherine Salazar
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
 * src/stt/stt_rational_literal_subnode_tests.c: Test the Amara syntax
 * tree rational literal subnode.
 */

#include "../asr/assertion.h"

#include "stt_rational_literal_subnode.h"

#include "stt_rational_literal_subnode_tests.h"

void stt_rational_literal_subnode_default_constructor_test_0()
{
	stt_rational_literal_subnode * rational_literal_subnode_;

	rational_literal_subnode_ =
			stt_rational_literal_subnode_default_constructor();
	forced_assertion(rational_literal_subnode_ != NULL);
	forced_assertion(rational_literal_subnode_->raw_ == NULL);
	stt_rational_literal_subnode_destructor(rational_literal_subnode_);
}

void stt_rational_literal_subnode_exhaustive_and_copy_constructors_test_0()
{
	stt_rational_literal_subnode * rational_literal_subnode_zero_;
	stt_rational_literal_subnode * rational_literal_subnode_one_;
	amara_string * raw_rational_literal_;

	rational_literal_subnode_zero_ =
			stt_rational_literal_subnode_default_constructor();
	forced_assertion(rational_literal_subnode_zero_ != NULL);
#ifndef NDEBUG
	assertion(rational_literal_subnode_zero_->raw_ == NULL);
#endif

	raw_rational_literal_ = amara_string_exhaustive_constructor("0.1");
	forced_assertion(raw_rational_literal_ != NULL);

	stt_rational_literal_subnode_set_raw(
			rational_literal_subnode_zero_, raw_rational_literal_);

	amara_string_destructor(raw_rational_literal_);

	rational_literal_subnode_one_ =
			stt_rational_literal_subnode_copy_constructor(
					rational_literal_subnode_zero_);
	forced_assertion(rational_literal_subnode_one_ != NULL);

	stt_rational_literal_subnode_destructor(
			rational_literal_subnode_zero_);
	stt_rational_literal_subnode_destructor(rational_literal_subnode_one_);
}

void
stt_rational_literal_subnode_constructors_tests()
{
	stt_rational_literal_subnode_default_constructor_test_0();
	stt_rational_literal_subnode_exhaustive_and_copy_constructors_test_0();
}

tests_simple_list *
register_stt_rational_literal_subnode_constructors_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_rational_literal_subnode_constructors_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_rational_literal_subnode_default_constructor_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_rational_literal_subnode_exhaustive_and_copy_constructors_test_0);
	return returning_;
}

void
stt_rational_literal_subnode_set_and_get_raw_test_0()
{
	stt_rational_literal_subnode * subnode_;
	amara_string * raw_rational_to_set_;
	amara_string * raw_rational_got_;
	amara_boolean equality_;

	subnode_ = stt_rational_literal_subnode_default_constructor();
	assertion(subnode_ != NULL);
	assertion(subnode_->raw_ == NULL);

	raw_rational_to_set_ = amara_string_exhaustive_constructor(".1");
	assertion(raw_rational_to_set_ != NULL);
	assertion(raw_rational_to_set_->value_ != NULL);

	stt_rational_literal_subnode_set_raw(subnode_, raw_rational_to_set_);
	assertion(subnode_->raw_ != NULL);
	assertion(raw_rational_to_set_ != NULL);
	assertion(raw_rational_to_set_->value_ != NULL);

	raw_rational_got_ = stt_rational_literal_subnode_get_raw(subnode_);
	assertion(subnode_->raw_ != NULL);
	assertion(raw_rational_got_ != NULL);
	assertion(raw_rational_got_->value_ != NULL);
	equality_ = amara_string_equality(
			raw_rational_to_set_, raw_rational_got_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(raw_rational_got_);
	amara_string_destructor(raw_rational_to_set_);
	stt_rational_literal_subnode_destructor(subnode_);
}

void
stt_rational_literal_subnode_set_and_get_raw_test_1()
{
	stt_rational_literal_subnode * subnode_;
	amara_string * raw_rational_to_set_zero_;
	amara_string * raw_rational_to_set_one_;
	amara_string * raw_rational_got_;

	subnode_ = stt_rational_literal_subnode_default_constructor();
	assertion(subnode_ != NULL);
	assertion(subnode_->raw_ == NULL);

	raw_rational_to_set_zero_ = amara_string_exhaustive_constructor(".1");
	assertion(raw_rational_to_set_zero_ != NULL);
	assertion(raw_rational_to_set_zero_->value_ != NULL);

	stt_rational_literal_subnode_set_raw(
			subnode_, raw_rational_to_set_zero_);
	assertion(subnode_->raw_ != NULL);
	assertion(raw_rational_to_set_zero_ != NULL);
	assertion(raw_rational_to_set_zero_->value_ != NULL);

	raw_rational_to_set_one_ = NULL;

	stt_rational_literal_subnode_set_raw(
			subnode_, raw_rational_to_set_one_);
	assertion(subnode_->raw_ == NULL);

	raw_rational_got_ = stt_rational_literal_subnode_get_raw(subnode_);
	assertion(subnode_->raw_ == NULL);
	assertion(raw_rational_got_ == NULL);

	amara_string_destructor(raw_rational_to_set_zero_);
	stt_rational_literal_subnode_destructor(subnode_);
}

void
stt_rational_literal_subnode_set_and_get_raw_tests()
{
	stt_rational_literal_subnode_set_and_get_raw_test_0();
	stt_rational_literal_subnode_set_and_get_raw_test_1();
}

tests_simple_list *
register_stt_rational_literal_subnode_set_and_get_raw_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_rational_literal_subnode_set_and_get_raw_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_rational_literal_subnode_set_and_get_raw_test_0);
	tests_simple_list_push_back(
			returning_,
			& stt_rational_literal_subnode_set_and_get_raw_test_1);
	return returning_;
}

void
stt_rational_literal_subnode_tests()
{
	stt_rational_literal_subnode_constructors_tests();
	stt_rational_literal_subnode_set_and_get_raw_tests();
}

tests_simple_list *
register_stt_rational_literal_subnode_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_rational_literal_subnode_constructors_tests(
			tests);
	returning_ = register_stt_rational_literal_subnode_set_and_get_raw_tests(
			returning_);
	return returning_;
}
