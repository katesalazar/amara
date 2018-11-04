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
stt_where_value_bindings_simple_list_tests()
{
	stt_where_value_bindings_simple_list_constructors_tests();
}
