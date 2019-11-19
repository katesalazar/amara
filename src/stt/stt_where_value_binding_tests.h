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
 * src/stt/stt_where_value_binding_tests.h: Test the Amara syntax tree
 * _where_ value binding.
 */

#ifndef __AMARA__SYNTAX_TREE__WHERE_VALUE_BINDING_TESTS__H__
#define __AMARA__SYNTAX_TREE__WHERE_VALUE_BINDING_TESTS__H__

/*   For `stt_where_value_binding`. */
#include "stt_where_value_binding.h"

/**  Value `foo` is bound to the natural literal expression `0`. */
stt_where_value_binding *
stt_where_value_binding_example_simple_value_bind_foo_to_zero(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_binding_example_simple_value_bind_foo_to_zero(
		const stt_where_value_binding * where_value_binding_)
;

#endif

/**  Value `bar` is bound to the natural literal expression `1`. */
stt_where_value_binding *
stt_where_value_binding_example_simple_value_bind_bar_to_one(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_binding_example_simple_value_bind_bar_to_one(
		const stt_where_value_binding * where_value_binding_)
;

#endif

/**  Value `foo` is bound to the natural literal expression `0`. */
stt_where_value_binding *
stt_where_value_binding_example_simple_value_bind(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_binding_example_simple_value_bind(
		const stt_where_value_binding * where_value_binding_)
;

#endif

stt_where_value_binding *
stt_where_value_binding_example_identifier_foo_is_bound_to_string_literal_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_binding_example_identifier_foo_is_bound_to_string_literal_foo(
		const stt_where_value_binding * where_value_binding_)
;

#endif

stt_where_value_binding *
stt_where_value_binding_example_identifier_bar_is_bound_to_string_literal_bar(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_binding_example_identifier_bar_is_bound_to_string_literal_bar(
		const stt_where_value_binding * where_value_binding_)
;

#endif

void
stt_where_value_binding_tests(void)
;

#endif
