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
 * src/stt/stt_where_value_binding_tests.c: Test the Amara syntax tree
 * _where_ value binding.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_expression * stt_expression_example_natural_zero()`. */
#include "stt_expression_tests.h"

/*   For own functions prototypes. */
#include "stt_where_value_binding_tests.h"

stt_where_value_binding *
stt_where_value_binding_example_simple_value_bind_foo_to_zero()
{
	amara_string * value_name_;
	stt_expression * value_expression_;
	stt_where_value_binding * returning_;

	value_name_ = amara_string_exhaustive_constructor("foo");
#ifndef NDEBUG
	assertion(value_name_ != NULL);
	assertion(value_name_->value_ != NULL);
	assertion(value_name_->value_[0] == 0x66);  /* 106: 'f'. */
	assertion(value_name_->value_[1] == 0x6F);  /* 111: 'o'. */
	assertion(value_name_->value_[2] == 0x6F);  /* 111: 'o'. */
	assertion(value_name_->value_[3] == 0x00);  /* 0: '\0'. */
#endif

	value_expression_ = stt_expression_example_natural_zero();
#ifndef NDEBUG
	assertion(value_expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			value_expression_);
#endif

	returning_ = stt_where_value_binding_exhaustive_constructor(
			value_name_, value_expression_);
#ifndef NDEBUG
	assertion(returning_ != NULL);
	assertion(returning_->value_name_ != NULL);
	assertion(returning_->value_name_->value_ != NULL);
	assertion(returning_->value_name_->value_[0] == 0x66);  /* 106: 'f'. */
	assertion(returning_->value_name_->value_[1] == 0x6F);  /* 111: 'o'. */
	assertion(returning_->value_name_->value_[2] == 0x6F);  /* 111: 'o'. */
	assertion(returning_->value_name_->value_[3] == 0x00);  /* 0: '\0'. */
	assertion(returning_->value_expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			returning_->value_expression_);
#endif

	amara_string_destructor(value_name_);
	stt_expression_destructor(value_expression_);

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
		const stt_where_value_binding * where_value_binding_)
{
	assertion(where_value_binding_ != NULL);
	assertion(where_value_binding_->value_name_ != NULL);
	assertion(where_value_binding_->value_name_->value_ != NULL);
	/* 106: 'f'. */
	assertion(where_value_binding_->value_name_->value_[0] == 0x66);
	/* 111: 'o'. */
	assertion(where_value_binding_->value_name_->value_[1] == 0x6F);
	/* 111: 'o'. */
	assertion(where_value_binding_->value_name_->value_[2] == 0x6F);
	/* 0: '\0'. */
	assertion(where_value_binding_->value_name_->value_[3] == 0x00);
	assertion(where_value_binding_->value_expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_zero(
			where_value_binding_->value_expression_);
}

#endif


stt_where_value_binding *
stt_where_value_binding_example_simple_value_bind_bar_to_one()
{
	amara_string * value_name_;
	stt_expression * value_expression_;
	stt_where_value_binding * returning_;

	value_name_ = amara_string_exhaustive_constructor("bar");
#ifndef NDEBUG
	assertion(value_name_ != NULL);
	assertion(value_name_->value_ != NULL);
	assertion(value_name_->value_[0] == 0x62);  /* 98: 'b'. */
	assertion(value_name_->value_[1] == 0x61);  /* 97: 'a'. */
	assertion(value_name_->value_[2] == 0x72);  /* 114: 'r'. */
	assertion(value_name_->value_[3] == 0x00);  /* 0: '\0'. */
#endif

	value_expression_ = stt_expression_example_natural_one();
#ifndef NDEBUG
	assertion(value_expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_one(
			value_expression_);
#endif

	returning_ = stt_where_value_binding_exhaustive_constructor(
			value_name_, value_expression_);
#ifndef NDEBUG
	assertion(returning_ != NULL);
	assertion(returning_->value_name_ != NULL);
	assertion(returning_->value_name_->value_ != NULL);
	assertion(returning_->value_name_->value_[0] == 0x62);  /* 98: 'b'. */
	assertion(returning_->value_name_->value_[1] == 0x61);  /* 97: 'a'. */
	assertion(returning_->value_name_->value_[2] == 0x72);  /* 114: 'r'. */
	assertion(returning_->value_name_->value_[3] == 0x00);  /* 0: '\0'. */
	assertion(returning_->value_expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_one(
			returning_->value_expression_);
#endif

	amara_string_destructor(value_name_);
	stt_expression_destructor(value_expression_);

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_binding_example_simple_value_bind_bar_to_one(
		const stt_where_value_binding * where_value_binding_)
{
	assertion(where_value_binding_ != NULL);
	assertion(where_value_binding_->value_name_ != NULL);
	assertion(where_value_binding_->value_name_->value_ != NULL);
	/* 98: 'b'. */
	assertion(where_value_binding_->value_name_->value_[0] == 0x62);
	/* 97: 'a'. */
	assertion(where_value_binding_->value_name_->value_[1] == 0x61);
	/* 114: 'r'. */
	assertion(where_value_binding_->value_name_->value_[2] == 0x72);
	/* 0: '\0'. */
	assertion(where_value_binding_->value_name_->value_[3] == 0x00);
	assertion(where_value_binding_->value_expression_ != NULL);
	assert_expectations_on_stt_expression_example_natural_one(
			where_value_binding_->value_expression_);
}

#endif

stt_where_value_binding *
stt_where_value_binding_example_simple_value_bind()
{
	return stt_where_value_binding_example_simple_value_bind_foo_to_zero();
}

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
		const stt_where_value_binding * where_value_binding_)
{
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			where_value_binding_);
}

#endif

stt_where_value_binding *
stt_where_value_binding_example_identifier_foo_is_bound_to_string_literal_foo()
{
	amara_string * foo_;
	stt_expression * expression_;
	stt_where_value_binding * where_binding_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	foo_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(foo_ != NULL);
	forced_assertion(foo_->value_ != NULL);

	expression_ = stt_expression_example_string_literal_foo();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_string_literal_foo(
			expression_);
#endif

	where_binding_ = stt_where_value_binding_exhaustive_constructor(
			foo_, expression_);
	forced_assertion(where_binding_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_string_literal_foo(
			expression_);
	equality_ = amara_strings_equality(foo_, where_binding_->value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			where_binding_->value_expression_);
#endif

	amara_string_destructor(foo_);

	stt_expression_destructor(expression_);

	return where_binding_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_binding_example_identifier_foo_is_bound_to_string_literal_foo(
		const stt_where_value_binding * where_value_binding_)
{
	assertion(where_value_binding_ != NULL);
	assertion(where_value_binding_->value_name_ != NULL);
	assertion(where_value_binding_->value_name_->value_ != NULL);
	assertion(where_value_binding_->value_name_->value_[0] == 'f');
	assertion(where_value_binding_->value_name_->value_[1] == 'o');
	assertion(where_value_binding_->value_name_->value_[2] == 'o');
	assertion(where_value_binding_->value_name_->value_[3] == '\0');
	assertion(where_value_binding_->value_expression_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_foo(
			where_value_binding_->value_expression_);
}

#endif

stt_where_value_binding *
stt_where_value_binding_example_identifier_bar_is_bound_to_string_literal_bar()
{
	amara_string * bar_;
	stt_expression * expression_;
	stt_where_value_binding * where_binding_;
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	bar_ = amara_string_exhaustive_constructor("bar");
	forced_assertion(bar_ != NULL);
	forced_assertion(bar_->value_ != NULL);

	expression_ = stt_expression_example_string_literal_bar();
	forced_assertion(expression_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_string_literal_bar(
			expression_);
#endif

	where_binding_ = stt_where_value_binding_exhaustive_constructor(
			bar_, expression_);
	forced_assertion(where_binding_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_expression_example_string_literal_bar(
			expression_);
	equality_ = amara_strings_equality(bar_, where_binding_->value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assert_expectations_on_stt_expression_example_string_literal_bar(
			where_binding_->value_expression_);
#endif

	amara_string_destructor(bar_);

	stt_expression_destructor(expression_);

	return where_binding_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_binding_example_identifier_bar_is_bound_to_string_literal_bar(
		const stt_where_value_binding * where_value_binding_)
{
	assertion(where_value_binding_ != NULL);
	assertion(where_value_binding_->value_name_ != NULL);
	assertion(where_value_binding_->value_name_->value_ != NULL);
	assertion(where_value_binding_->value_name_->value_[0] == 'b');
	assertion(where_value_binding_->value_name_->value_[1] == 'a');
	assertion(where_value_binding_->value_name_->value_[2] == 'r');
	assertion(where_value_binding_->value_name_->value_[3] == '\0');
	assertion(where_value_binding_->value_expression_ != NULL);
	assert_expectations_on_stt_expression_example_string_literal_bar(
			where_value_binding_->value_expression_);
}

#endif

void
stt_where_value_binding_default_constructor_test()
{
	stt_where_value_binding * where_value_binding_;

	where_value_binding_ = stt_where_value_binding_default_constructor();
	forced_assertion(where_value_binding_ != NULL);
#ifndef NDEBUG
	assertion(where_value_binding_->value_name_ == NULL);
	assertion(where_value_binding_->value_expression_ == NULL);
#endif

	stt_where_value_binding_destructor(where_value_binding_);
}

void
stt_where_value_binding_default_constructor_tests()
{
	stt_where_value_binding_default_constructor_test();
}

tests_simple_list *
register_stt_where_value_binding_default_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_where_value_binding_default_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_where_value_binding_default_constructor_test);
	return returning_;
}

void
stt_where_value_binding_exhaustive_constructor_test_0()
{
	stt_where_value_binding * where_value_binding_;

	where_value_binding_ =
			stt_where_value_binding_example_simple_value_bind_foo_to_zero();
	forced_assertion(where_value_binding_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			where_value_binding_);
#endif

	stt_where_value_binding_destructor(where_value_binding_);
}

void
stt_where_value_binding_exhaustive_constructor_test_1()
{
	stt_where_value_binding * where_value_binding_;

	where_value_binding_ =
			stt_where_value_binding_example_simple_value_bind_bar_to_one();
	forced_assertion(where_value_binding_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_bar_to_one(
			where_value_binding_);
#endif

	stt_where_value_binding_destructor(where_value_binding_);
}

void
stt_where_value_binding_exhaustive_constructor_test_2()
{
	stt_where_value_binding * where_value_binding_;

	where_value_binding_ =
			stt_where_value_binding_example_identifier_foo_is_bound_to_string_literal_foo();
	forced_assertion(where_value_binding_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_identifier_foo_is_bound_to_string_literal_foo(
			where_value_binding_);
#endif

	stt_where_value_binding_destructor(where_value_binding_);
}

void
stt_where_value_binding_exhaustive_constructor_tests()
{
	stt_where_value_binding_exhaustive_constructor_test_0();
	stt_where_value_binding_exhaustive_constructor_test_1();
	stt_where_value_binding_exhaustive_constructor_test_2();
}

tests_simple_list *
register_stt_where_value_binding_exhaustive_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_where_value_binding_exhaustive_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& stt_where_value_binding_exhaustive_constructor_test_0);
	tests_simple_list_push_back(
			tests,
			& stt_where_value_binding_exhaustive_constructor_test_1);
	tests_simple_list_push_back(
			tests,
			& stt_where_value_binding_exhaustive_constructor_test_2);
	return tests;
}

void
stt_where_value_binding_constructors_tests()
{
	stt_where_value_binding_default_constructor_tests();
	stt_where_value_binding_exhaustive_constructor_tests();
}

tests_simple_list *
register_stt_where_value_binding_constructors_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_where_value_binding_constructors_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_where_value_binding_default_constructor_tests(
			tests);
	returning_ = register_stt_where_value_binding_exhaustive_constructor_tests(
			tests);
	return returning_;
}

void
stt_where_value_binding_equality_test_0()
{
	stt_where_value_binding * wvb0_;
	stt_where_value_binding * wvb1_;
	amara_boolean equality_;

	wvb0_ = stt_where_value_binding_example_simple_value_bind_foo_to_zero();
	forced_assertion(wvb0_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			wvb0_);
#endif

	wvb1_ = stt_where_value_binding_example_simple_value_bind_foo_to_zero();
	forced_assertion(wvb1_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			wvb1_);
#endif

	equality_ = stt_where_value_bindings_equality(wvb0_, wvb1_);
	forced_assertion(equality_ == AMARA_BOOLEAN_TRUE);

	stt_where_value_binding_destructor(wvb0_);
	stt_where_value_binding_destructor(wvb1_);
}

void
stt_where_value_binding_equality_test_1()
{
	stt_where_value_binding * wvb0_;
	stt_where_value_binding * wvb1_;
	amara_boolean equality_;

	wvb0_ = stt_where_value_binding_example_simple_value_bind_foo_to_zero();
	forced_assertion(wvb0_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			wvb0_);
#endif

	wvb1_ = stt_where_value_binding_example_simple_value_bind_foo_to_zero();
	forced_assertion(wvb1_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			wvb1_);
#endif

	forced_assertion(wvb1_->value_name_ != NULL);
	forced_assertion(wvb1_->value_name_->value_ != NULL);
	forced_assertion(wvb1_->value_name_->value_[0] == 'f');
	forced_assertion(wvb1_->value_name_->value_[1] == 'o');
	forced_assertion(wvb1_->value_name_->value_[2] == 'o');
	forced_assertion(wvb1_->value_name_->value_[3] == '\0');
	wvb1_->value_name_->value_[0] = 'b';
	wvb1_->value_name_->value_[1] = 'a';
	wvb1_->value_name_->value_[2] = 'r';

	equality_ = stt_where_value_bindings_equality(wvb0_, wvb1_);
	forced_assertion(equality_ == AMARA_BOOLEAN_FALSE);

	stt_where_value_binding_destructor(wvb0_);
	stt_where_value_binding_destructor(wvb1_);
}

void
stt_where_value_binding_equality_tests()
{
	stt_where_value_binding_equality_test_0();
	stt_where_value_binding_equality_test_1();
}

void
stt_where_value_binding_tests()
{
	stt_where_value_binding_constructors_tests();
	stt_where_value_binding_equality_tests();
}

tests_simple_list *
register_stt_where_value_binding_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_where_value_binding_constructors_tests(
			tests);
	return returning_;
}
