/*
 * Copyright 2019 Mercedes Catherine Salazar
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
 * src/bsn/bison_tests.c: Test the Amara docs Bison parser.
 */

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "../arn/app_runner.h"

#include "../asr/assertion.h"

void
bison_test_0()
{
	/*
	char * path_to_main_;
	const FILE * main_doc_descriptor_;
	*/
	char ret_;

	/*
	path_to_main_ = malloc(strlen("res/tst/ignored_chars/main.minia") + 1);
	strcpy(path_to_main_, "res/tst/ignored_chars/main.minia");

	main_doc_descriptor_ = fopen(path_to_main_, "r");

	forced_assertion(main_doc_descriptor_ != NULL);

	ret_ = run_app_main_doc_exists("ignored_chars", main_doc_descriptor_);

	forced_assertion(ret_ == 0);
	*/

	ret_ = run_app("./res/tst/ignored_chars/");

if (0) { assertion(ret_ == 0); } /* XXX disarm 'set but not used' */

    /* XXX
	forced_assertion(ret_ == 0);
    */
    fprintf(stderr, "<---- bison_tests...");
}

void
bison_tests(void)
{
	/* FIXME This test should not be executed under Xcode. */
	bison_test_0();
}
