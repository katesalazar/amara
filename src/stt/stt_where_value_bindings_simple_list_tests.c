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
 * src/stt/stt_where_value_bindings_simple_list.c: Amara syntax tree
 * _where_ value bindings simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_where_value_binding *
 * stt_where_value_binding_example_simple_value_bind()`. */
#include "stt_where_value_binding_tests.h"

/*   For `typedef struct stt_where_value_bindings_simple_list { ... }
 * stt_where_value_bindings_simple_list`. */
#include "stt_where_value_bindings_simple_list.h"

stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero(void)
{
	stt_where_value_binding * where_value_binding_;
	stt_where_value_bindings_simple_list * where_value_bindings_;

	where_value_binding_ =
			stt_where_value_binding_example_simple_value_bind_foo_to_zero();
#ifndef NDEBUG
	assertion(where_value_binding_ != NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			where_value_binding_);
#endif

	where_value_bindings_ =
			stt_where_value_bindings_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(where_value_bindings_ != NULL);
	assertion(where_value_bindings_->first == NULL);
	assertion(where_value_bindings_->next == NULL);
#endif

	/*
	where_value_bindings_ =
	*/
			stt_where_value_bindings_simple_list_push_back(
					where_value_bindings_,
					where_value_binding_);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			where_value_binding_);
	/*
	assertion(where_value_bindings_ != NULL);
	*/
	assertion(where_value_bindings_->first != NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			where_value_bindings_->first);
	assertion(where_value_bindings_->next == NULL);
#endif

	/*
	stt_where_value_bindings_simple_list_destructor(where_value_bindings_);
	*/
	stt_where_value_binding_destructor(where_value_binding_);

	return where_value_bindings_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero(
		const stt_where_value_bindings_simple_list * where_value_bindings_)
{
	assertion(where_value_bindings_ != NULL);
	assertion(where_value_bindings_->first != NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			where_value_bindings_->first);
	assertion(where_value_bindings_->next == NULL);
}

#endif

stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_example_simple_value_bind(void)
{
	return stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero();
}

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind(
		const stt_where_value_bindings_simple_list * where_value_bindings_)
{
	assertion(where_value_bindings_ != NULL);
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero(
			where_value_bindings_);
}

#endif

stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_example_identifier_foo_is_bound_to_string_literal_foo()
{
	stt_where_value_binding * where_binding_;
	stt_where_value_bindings_simple_list * ret_;

	where_binding_ = stt_where_value_binding_example_identifier_foo_is_bound_to_string_literal_foo();
	forced_assertion(where_binding_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_identifier_foo_is_bound_to_string_literal_foo(
			where_binding_);
#endif

	ret_ = stt_where_value_bindings_simple_list_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first == NULL);
	assertion(ret_->next == NULL);
#endif

	stt_where_value_bindings_simple_list_push_back(ret_, where_binding_);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_identifier_foo_is_bound_to_string_literal_foo(
			where_binding_);
	assertion(ret_->first != NULL);
	assert_expectations_on_stt_where_value_binding_example_identifier_foo_is_bound_to_string_literal_foo(
			ret_->first);
#endif

	stt_where_value_binding_destructor(where_binding_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_bindings_simple_list_example_identifier_foo_is_bound_to_string_literal_foo(
		const stt_where_value_bindings_simple_list * where_value_bindings_)
{
	assertion(where_value_bindings_ != NULL);
	assertion(where_value_bindings_->first != NULL);
	assert_expectations_on_stt_where_value_binding_example_identifier_foo_is_bound_to_string_literal_foo(
			where_value_bindings_->first);
	assertion(where_value_bindings_->next == NULL);
}

#endif

void
stt_where_value_bindings_simple_list_default_constructor_test()
{
	stt_where_value_bindings_simple_list * list_;

	list_ = stt_where_value_bindings_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
#endif

	stt_where_value_bindings_simple_list_destructor(list_);
}

void
stt_where_value_bindings_simple_list_copy_constructor_test()
{
	stt_where_value_binding * element_;
	stt_where_value_bindings_simple_list * original_;
	stt_where_value_bindings_simple_list * copy_;

	element_ = stt_where_value_binding_example_simple_value_bind();
#ifndef NDEBUG
	assertion(element_ != NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
			element_);
#endif

	original_ = stt_where_value_bindings_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(original_ != NULL);
	assertion(original_->first == NULL);
	assertion(original_->next == NULL);
#endif

	stt_where_value_bindings_simple_list_push_back(original_, element_);
#ifndef NDEBUG
	assertion(original_->first != NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
			original_->first);
	assertion(original_->next == NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
			element_);
#endif

	copy_ = stt_where_value_bindings_simple_list_copy_constructor(
			original_);
#ifndef NDEBUG
	assertion(original_->first != NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
			original_->first);
	assertion(original_->next == NULL);
	assertion(copy_ != NULL);
	assertion(copy_->first != NULL);
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
			copy_->first);
	assertion(copy_->next == NULL);
#endif

	stt_where_value_bindings_simple_list_destructor(copy_);
	stt_where_value_bindings_simple_list_destructor(original_);
	stt_where_value_binding_destructor(element_);
}

void
stt_where_value_bindings_simple_list_constructors_tests()
{
	stt_where_value_bindings_simple_list_default_constructor_test();
	stt_where_value_bindings_simple_list_copy_constructor_test();
}

void
stt_where_value_bindings_simple_list_find_by_value_name_test_0()
{
	stt_where_value_bindings_simple_list * haystack_;
	amara_string * needle_;
	stt_where_value_binding * result_;

	haystack_ = NULL;

	needle_ = NULL;

	result_ = stt_where_value_bindings_simple_list_find_by_value_name(
			haystack_, needle_);
	forced_assertion(result_ == NULL);
}

void
stt_where_value_bindings_simple_list_find_by_value_name_test_1()
{
	stt_where_value_bindings_simple_list * haystack_;
	amara_string * needle_;
	stt_where_value_binding * result_;

	haystack_ = stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero();
	forced_assertion(haystack_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero(
			haystack_);
#endif

	needle_ = NULL;

	result_ = stt_where_value_bindings_simple_list_find_by_value_name(
			haystack_, needle_);
	forced_assertion(result_ == NULL);

	stt_where_value_bindings_simple_list_destructor(haystack_);
}

void
stt_where_value_bindings_simple_list_find_by_value_name_test_2()
{
	stt_where_value_bindings_simple_list * haystack_;
	amara_string * needle_;
	stt_where_value_binding * result_;
	amara_boolean equality_;

	haystack_ = stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero();
	forced_assertion(haystack_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero(
			haystack_);
#endif

	needle_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(needle_ != NULL);
	forced_assertion(needle_->value_ != NULL);

	result_ = stt_where_value_bindings_simple_list_find_by_value_name(
			haystack_, needle_);
	forced_assertion(result_ != NULL);
	forced_assertion(result_->value_name_ != NULL);
	forced_assertion(result_->value_name_->value_ != NULL);
	equality_ = amara_strings_equality(result_->value_name_, needle_);
	forced_assertion(equality_ == AMARA_BOOLEAN_TRUE);

	stt_where_value_bindings_simple_list_destructor(haystack_);
	amara_string_destructor(needle_);
}

void
stt_where_value_bindings_simple_list_find_by_value_name_test_3()
{
	stt_where_value_bindings_simple_list * haystack_;
	amara_string * needle_;
	stt_where_value_binding * result_;

	haystack_ = stt_where_value_bindings_simple_list_default_constructor();
	forced_assertion(haystack_ != NULL);
#ifndef NDEBUG
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);
#endif

	needle_ = amara_string_exhaustive_constructor("something");
	forced_assertion(needle_ != NULL);

	result_ = stt_where_value_bindings_simple_list_find_by_value_name(
			haystack_, needle_);
#ifndef NDEBUG
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);
#endif
	forced_assertion(result_ == NULL);

	stt_where_value_bindings_simple_list_destructor(haystack_);

	amara_string_destructor(needle_);
}

void
stt_where_value_bindings_simple_list_find_by_value_name_tests()
{
	stt_where_value_bindings_simple_list_find_by_value_name_test_0();
	stt_where_value_bindings_simple_list_find_by_value_name_test_1();
	stt_where_value_bindings_simple_list_find_by_value_name_test_2();
	stt_where_value_bindings_simple_list_find_by_value_name_test_3();
}

void
stt_where_value_bindings_simple_list_push_front_test_0()
{
	stt_where_value_binding * where_value_binding_zero_;
	stt_where_value_binding * where_value_binding_one_;
	stt_where_value_bindings_simple_list * list_;

	where_value_binding_zero_ = stt_where_value_binding_example_simple_value_bind_foo_to_zero();
	forced_assertion(where_value_binding_zero_ != NULL);
	/* XXX missing assertions */

	where_value_binding_one_ = stt_where_value_binding_example_simple_value_bind_bar_to_one();
	forced_assertion(where_value_binding_one_ != NULL);
	/* XXX missing assertions */

	list_ = stt_where_value_bindings_simple_list_default_constructor();
	forced_assertion(list_ != NULL);
	/* XXX missing assertions */

	list_ = stt_where_value_bindings_simple_list_push_front(
			list_, where_value_binding_zero_);
	/* XXX missing assertions */
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			list_->first);
	/* XXX missing assertions */
#endif

	stt_where_value_binding_destructor(where_value_binding_zero_);

	list_ = stt_where_value_bindings_simple_list_push_front(
			list_, where_value_binding_one_);
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_bar_to_one(
			list_->first);
	/* XXX missing assertions */
	assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
			list_->next->first);
	/* XXX missing assertions */
#endif

	stt_where_value_binding_destructor(where_value_binding_one_);

	stt_where_value_bindings_simple_list_destructor(list_);
}

void
stt_where_value_bindings_simple_list_push_front_tests()
{
	stt_where_value_bindings_simple_list_push_front_test_0();
}

void
stt_where_value_bindings_simple_list_push_back_test_0()
{
	stt_where_value_bindings_simple_list * list_;

	list_ = stt_where_value_bindings_simple_list_example_identifier_foo_is_bound_to_string_literal_foo();
	forced_assertion(list_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_bindings_simple_list_example_identifier_foo_is_bound_to_string_literal_foo(
			list_);
#endif

	stt_where_value_bindings_simple_list_destructor(list_);
}

void
stt_where_value_bindings_simple_list_push_back_tests()
{
	stt_where_value_bindings_simple_list_push_back_test_0();
}

void
stt_where_value_bindings_simple_list_tests()
{
	stt_where_value_bindings_simple_list_constructors_tests();
	stt_where_value_bindings_simple_list_find_by_value_name_tests();
	stt_where_value_bindings_simple_list_push_front_tests();
	stt_where_value_bindings_simple_list_push_back_tests();
}
