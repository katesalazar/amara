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
 * src/stt/stt_where_value_bindings_simple_list.h: Amara syntax tree
 * _where_ value bindings simple list.
 */

#ifndef __AMARA__SYNTAX_TREE__WHERE_VALUE_BINDINGS_SIMPLE_LIST_TESTS__H__
#define __AMARA__SYNTAX_TREE__WHERE_VALUE_BINDINGS_SIMPLE_LIST_TESTS__H__

/*   For `typedef struct stt_where_value_bindings_simple_list { ... }
 * stt_where_value_bindings_simple_list;`. */
#include "stt_where_value_bindings_simple_list.h"

/**  Value `foo` is bound to the natural literal expression `0`. */
stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero(
		const stt_where_value_bindings_simple_list * where_value_bindings_)
;

#endif

/**  Aliased to `stt_where_value_bindings_simple_list_example_simple_value_bind_foo_to_zero(void)`. */
stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_example_simple_value_bind(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_bindings_simple_list_example_simple_value_bind(
		const stt_where_value_bindings_simple_list * where_value_bindings_)
;

#endif

stt_where_value_bindings_simple_list *
stt_where_value_bindings_simple_list_example_identifier_foo_is_bound_to_string_literal_foo(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_where_value_bindings_simple_list_example_identifier_foo_is_bound_to_string_literal_foo(
		const stt_where_value_bindings_simple_list * where_value_bindings_)
;

#endif

void
stt_where_value_bindings_simple_list_tests(void)
;

#endif
