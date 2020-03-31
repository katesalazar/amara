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

#include "tests_simple_list_tests.h"

#include "tests_pseudo_random_numbers_generation_tests.h"

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
assertion_test_0()
{
	interpret_and_assert("1");
	/*
	disarm_interim_tests();
	*/
}

void
assertion_tests()
{
	assertion_test_0();
}

tests_simple_list *
register_assertion_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_assertion_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(returning_, & assertion_test_0);
	return returning_;
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

	assertion_tests();

	common_tests();

	basic_arithmetic_tests();

	persistence_tests();

	syntax_tree_tests();

	flex_tests();

	bison_tests();

	run_time_graph_tests();

	applications_runner_tests();

	app_runner_tests();

	applications_runner_tests();

	printf("... done\n");

	if (double_end_of_line_char) {
		printf("\n");
	}

	not_running_tests();
}

tests_simple_list *
register_tests(const tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_tests(const tests_simple_list * tests)
{
	tests_simple_list * returning_;

	forced_assertion(tests != NULL);
#ifndef NDEBUG
	assertion(tests->first == NULL);
	assertion(tests->next == NULL);
#endif

	returning_ = (tests_simple_list *) tests;

	returning_ = register_assertion_tests(returning_);
	forced_assertion(returning_ != NULL);

	returning_ = register_common_tests(returning_);
	forced_assertion(returning_ != NULL);

	returning_ = register_basic_arithmetic_tests(returning_);
	forced_assertion(returning_ != NULL);

	returning_ = register_persistence_tests(returning_);

	returning_ = register_syntax_tree_tests(returning_);
	forced_assertion(returning_ != NULL);

	returning_ = register_flex_tests(returning_);

	returning_ = register_bison_tests(returning_);

	returning_ = register_run_time_graph_tests(returning_);

	returning_ = register_applications_runner_tests(returning_);
	forced_assertion(returning_ != NULL);

	returning_ = register_app_runner_tests(returning_);

	return returning_;
}

void
run_scrambled_tests(amara_boolean double_end_of_line_char)
{
	tests_simple_list * tests_;
	tests_simple_list * tests__;
	tests_simple_list * scrambled_tests_;

	running_tests();

	printf("Running tests...\n");

	tests_simple_list_tests();

	tests_pseudo_random_numbers_generation_tests();

	tests_ = tests_simple_list_default_constructor();
	forced_assertion(tests_ != NULL);

	tests__ = register_tests(tests_);
	forced_assertion(tests__ != NULL);

	/*
	tests_simple_list_destructor(tests_);
	*/

	tests_ = tests__;

	scrambled_tests_ = tests_simple_list_scramble_tests(tests_);

	tests_simple_list_destructor(tests_);

	tests_simple_list_run_tests(scrambled_tests_);

	tests_simple_list_destructor(scrambled_tests_);

	printf("... done\n");

	if (double_end_of_line_char) {
		printf("\n");
	}

	not_running_tests();
}
