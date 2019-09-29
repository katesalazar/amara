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
 * src/tst/tests_runner.c: Amara tests runner.
 */

/*   For `int printf(const char *, ...)`. */
#include <stdio.h>

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `char * strcpy(char * dest, const char * src)`. */
#include <string.h>

#include "../arn/app_runner_tests.h"

#include "../arn/arn_tests.h"

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `void basic_arithmetic_tests()`. */
#include "../brt/basic_arithmetic_tests.h"

#include "../bsn/bison_tests.h"

#include "../bsn/flex_tests.h"

/*   For `void common_tests()`. */
#include "../cmn/common_tests.h"

/*   For `void persistence_tests()`. */
#include "../prs/persistence_tests.h"

#include "../rtg/rtg_tests.h"

/*   For `void syntax_tree_tests()`. */
#include "../stt/stt_tests.h"

/*   For definitions. */
#include "tests_runner.h"

unsigned char
running_tests()
{
	return running_tests_ctl(RUNNING_TESTS_TRUE);
}

unsigned char
not_running_tests()
{
	return running_tests_ctl(RUNNING_TESTS_FALSE);
}

unsigned char
running_tests_ctl(unsigned char input)
{
	static unsigned char running_tests_;
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

/*
void
disarm_interim_test_0()
{
	char * message;
	message = malloc(1);
	strcpy(message, "");
	disarm_interim(message);
	assertion(!strcmp(message, ""));
}

void
disarm_interim_test_1()
{
	char * message;
	message = malloc(strlen(" %n ") + 1);
	strcpy(message, " %n ");
	disarm_interim(message);
	assertion(!strcmp(message, " %% "));
}

void
disarm_interim_tests()
{
	disarm_interim_test_0();
	disarm_interim_test_1();
}
*/

void
assertion_tests()
{
	interpret_and_assert("1");
	/*
	disarm_interim_tests();
	*/
}

void
run_tests(amara_boolean double_end_of_line_char)
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void run_tests(uint_fast8_t)\n", __FILE__, __LINE__);
#endif

	running_tests();

	printf("Running tests...\n");

	/* printf("%d\n", running_tests_ctl(RUNNING_TESTS_HOLD)); */ /* XXX */

	applications_runner_tests();

	assertion_tests();

	common_tests();

	basic_arithmetic_tests();

	persistence_tests();

	syntax_tree_tests();

	flex_tests();

	bison_tests();

	run_time_graph_tests();

	app_runner_tests();

	printf("... done\n");

	if (double_end_of_line_char) {
		printf("\n");
	}

	not_running_tests();
}
