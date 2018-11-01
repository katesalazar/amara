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
 * src/tst/tests_runner.h: Amara tests runner.
 */

#ifndef __AMARA__TESTS__TESTS_RUNNER_H__
#define __AMARA__TESTS__TESTS_RUNNER_H__

#include "../cmn/amara_boolean.h"

/*   These are the valid values of `void run_tests()#uint_fast8_t
 * running_tests_`. */
#define RUNNING_TESTS_FALSE 0x00
#define RUNNING_TESTS_TRUE  0x01
#define RUNNING_TESTS_HOLD  0x02

/*   Call this to mark execution-wide that `amara` is running in tests
 * mode.
 *   Note: do **not** qualify this with `warn_unused_result`. */
unsigned char
running_tests(void)
;

/*   Call this to mark execution-wide that `amara` is not running in tests
 * mode.
 *   Note: do **not** qualify this with `warn_unused_result`. */
unsigned char
not_running_tests(void)
;

/*   Do not call this, ever. Unless from `void running_tests()`, or from
 * `void not_running_tests()`.
 *   @returns Whether `amara` is running in tests mode, or not. */
unsigned char
running_tests_ctl(unsigned char input)
__attribute__((warn_unused_result))
;

/*   Call this to start running the tests. */
void
run_tests(amara_boolean double_end_of_line_char)
;

#endif
