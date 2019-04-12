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
 * src/stt/stt_condition_tests.h: Test the Amara syntax tree condition.
 */

#ifndef __AMARA__SYNTAX_TREE__CONDITION_TESTS__H__
#define __AMARA__SYNTAX_TREE__CONDITION_TESTS__H__

/*   For `stt_condition`. */
#include "stt_condition.h"

/**  `0 less than 1`. */
stt_condition *
stt_condition_example_simple_condition(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_condition_example_simple_condition(
		const stt_condition * condition)
;

#endif

/**  A simple true condition. */
stt_condition *
stt_condition_example_simple_true_condition(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_condition_example_simple_true_condition(
		const stt_condition * condition)
;

#endif

/**  A simple _less than_ true condition. */
stt_condition *
stt_condition_example_simple_lt_true_condition(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_condition_example_simple_lt_true_condition(
		const stt_condition * condition)
;

#endif

/**  A simple _greater than_ true condition. */
stt_condition *
stt_condition_example_simple_gt_true_condition(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_condition_example_simple_gt_true_condition(
		const stt_condition * condition)
;

#endif

stt_condition *
stt_condition_example_simple_greater_than_condition(void)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
assert_expectations_on_stt_condition_example_simple_greater_than_condition(
		const stt_condition * condition)
;

#endif

void
stt_condition_tests(void)
;

#endif
