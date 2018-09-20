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
 * src/tst/tests_runner.c: Amara tests runner.
 */

/*   For `uint_fast8_t`. */
#include <stdint.h>

/*   For `int printf(const char *, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `void basic_arithmetic_tests()`. */
#include "../brt/basic_arithmetic_tests.h"

/*   For `void common_tests()`. */
#include "../cmn/common_tests.h"

/*   For `void persistence_tests()`. */
#include "../prs/persistence_tests.h"

/*   For `void syntax_tree_tests()`. */
#include "../stt/stt_tests.h"

/*   For definitions. */
#include "tests_runner.h"

uint_fast8_t
running_tests()
{
	return running_tests_ctl(RUNNING_TESTS_TRUE);
}

uint_fast8_t
not_running_tests()
{
	return running_tests_ctl(RUNNING_TESTS_FALSE);
}

uint_fast8_t
running_tests_ctl(uint_fast8_t input)
{
	static uint_fast8_t running_tests_;
	if (input == RUNNING_TESTS_TRUE) {
		running_tests_ = RUNNING_TESTS_TRUE;
	/*
	} else if (input == RUNNING_TESTS_FALSE) {
	*/
	} else {
		assertion(input == RUNNING_TESTS_FALSE);
		running_tests_ = RUNNING_TESTS_FALSE;
	/*
	} else {
		assert(input == RUNNING_TESTS_HOLD);
	*/
	}
	return running_tests_;
}

void
assertion_tests()
{
	interpret_and_assert("1");
}

void
run_tests(uint_fast8_t double_end_of_line_char)
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void run_tests(uint_fast8_t)\n", __FILE__, __LINE__);
#endif
	running_tests();
	printf("Running tests...\n");
	/* printf("%d\n", running_tests_ctl(RUNNING_TESTS_HOLD)); */ /* XXX */

	assertion_tests();
	basic_arithmetic_tests();
	common_tests();
	persistence_tests();
	syntax_tree_tests();

	printf("... done\n");
	if (double_end_of_line_char) {
		printf("\n");
	}
	not_running_tests();
}
