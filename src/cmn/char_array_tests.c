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
 * src/cmn/char_array_tests.c: Test the utilities for character arrays.
 */

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `void free(void * ptr)`. */
#include <stdlib.h>

/*   For `int strcmp(const char * s1, const char * s2)`. */
#include <string.h>

#include "../asr/assertion.h"

#include "../log/logging.h"

#include "char_array.h"

#include "char_array_tests.h"

void
concatenate_two_char_arrays_test_0()
{
	const char * zero_ = "\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
01234567890123_";
	const char * one_ = "";
	const char * concat_ = concatenate_two_char_arrays(zero_, one_);
	const char * expectation_ = "ERROR the `zero` string is larger than \
the implemented maximum";
	const int strcmp_ret_ = strcmp(concat_, expectation_);
	fprintf(stderr, "%s\n", zero_);
	fprintf(stderr, "%s\n", one_);
	fprintf(stderr, "%s\n", concat_);
	assertion(!strcmp_ret_);
	free((char *) concat_);
	amara_log("ran test concatenate_two_char_arrays_test_0");
}

void
concatenate_two_char_arrays_test_1()
{
	const char * zero_ = "";
	const char * one_ = "\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
01234567890123_";
	const char * concat_ = concatenate_two_char_arrays(zero_, one_);
	const char * expectation_ = "ERROR the concatenation is clearly larger\
 than the implemented maximum";
	const int strcmp_ret_ = strcmp(concat_, expectation_);
	fprintf(stderr, "%s\n", zero_);
	fprintf(stderr, "%s\n", one_);
	fprintf(stderr, "%s\n", concat_);
	assertion(!strcmp_ret_);
	free((char *) concat_);
	amara_log("ran test concatenate_two_char_arrays_test_1");
}

void
concatenate_two_char_arrays_tests()
{
	concatenate_two_char_arrays_test_0();
	concatenate_two_char_arrays_test_1();
}

tests_simple_list *
register_concatenate_two_char_arrays_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_concatenate_two_char_arrays_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_, & concatenate_two_char_arrays_test_0);
	tests_simple_list_push_back(
			returning_, & concatenate_two_char_arrays_test_1);
	return returning_;
}

void
char_array_tests()
{
	concatenate_two_char_arrays_tests();
}

tests_simple_list *
register_char_array_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_concatenate_two_char_arrays_tests(tests);
	return returning_;
}
