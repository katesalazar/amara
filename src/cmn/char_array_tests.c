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
 * src/cmn/char_array_tests.c: Test the utilities for character arrays.
 */

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `int strcmp(const char * s1, const char * s2)`. */
#include <string.h>

#include "../asr/assertion.h"

#include "char_array.h"

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
}

void
concatenate_two_char_arrays_tests()
{
	concatenate_two_char_arrays_test_0();
	concatenate_two_char_arrays_test_1();
}

void
char_array_tests()
{
	concatenate_two_char_arrays_tests();
}
