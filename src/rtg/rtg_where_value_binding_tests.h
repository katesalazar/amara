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
 * src/rtg/rtg_where_value_binding_tests.h: Test the Amara run time
 * graph _where_ value binding.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__WHERE_VALUE_BINDING_TESTS__H__
#define __AMARA__RUN_TIME_GRAPH__WHERE_VALUE_BINDING_TESTS__H__

/*   For `typedef struct rtg_where_value_binding { ... }
 * rtg_where_value_binding`. */
#include "rtg_where_value_binding.h"

rtg_where_value_binding *
rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_rtg_where_value_binding_example_bind_value_foo_to_expression_natural_zero(
		const rtg_where_value_binding * where_value_binding)
;

#endif

rtg_where_value_binding *
rtg_where_value_binding_example_bind_value_bar_to_expression_natural_one(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_rtg_where_value_binding_example_bind_value_bar_to_expression_natural_one(
		const rtg_where_value_binding * where_value_binding)
;

#endif

#endif
