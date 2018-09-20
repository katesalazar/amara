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
 * src/cmn/common_tests.c: Self explanatory...
 */

/*   For `uint_fast8_t`. */
#include <stdint.h>

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `int strcmp(const char * s1, const char * s2)`. */
#include <string.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `char * concatenate_two_char_arrays(const char * zero,
 * const char * one)`. */
#include "char_array.h"

/*   For `char_array_simple_list` and its operations. */
#include "char_arrays_simple_list.h"

void
char_arrays_concatenation_test_0()
{
	const char * zero_ = "";
	const char * one_ = "";
	const char * concat_ = concatenate_two_char_arrays(zero_, one_);
	assertion(!strcmp(concat_, ""));
}

void
char_arrays_concatenation_test_1()
{
	const char * zero_ = "foo";
	const char * one_ = "";
	const char * concat_ = concatenate_two_char_arrays(zero_, one_);
	assertion(!strcmp(concat_, zero_));
}

void
char_arrays_concatenation_test_2()
{
	const char * zero_ = "";
	const char * one_ = "bar";
	const char * concat_ = concatenate_two_char_arrays(zero_, one_);
	assertion(!strcmp(concat_, one_));
}

void
char_arrays_concatenation_test_3()
{
	const char * zero_ = "foo";
	const char * one_ = "bar";
	const char * concat_ = concatenate_two_char_arrays(zero_, one_);
	const int strcmp_ret_ = strcmp(concat_, "foobar");
	if (strcmp_ret_) {
		fprintf(stderr, "%s\n", concat_);
	}
	assertion(!strcmp_ret_);
}

void
char_arrays_concatenation_test_4()
{
	const char * zero_ = "\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
01234567890123";
	const char * one_ = "";
	const char * concat_ = concatenate_two_char_arrays(zero_, one_);
	const char * expectation_ = "\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
01234567890123"; /* FIXME ??? */
	const int strcmp_ret_ = strcmp(concat_, expectation_);
	if (strcmp_ret_) {
		fprintf(stderr, "%s\n", zero_);
		fprintf(stderr, "%s\n", one_);
		fprintf(stderr, "%s\n", concat_);
	}
	assertion(!strcmp_ret_);
}

void
char_arrays_concatenation_test_5()
{
	const char * zero_ = "";
	const char * one_ = "\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
01234567890123";
	const char * concat_ = concatenate_two_char_arrays(zero_, one_);
	const char * expectation_ = "\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
0123456789012345678901234567890123456789\
01234567890123"; /* FIXME ??? */
	const int strcmp_ret_ = strcmp(concat_, expectation_);
	if (strcmp_ret_) {
		fprintf(stderr, "%s\n", zero_);
		fprintf(stderr, "%s\n", one_);
		fprintf(stderr, "%s\n", concat_);
	}
	assertion(!strcmp_ret_);
}

void
char_arrays_concatenation_test_6()
{
	const char * zero_ = "";
	const char * one_ = "";
	const char * two_ = "";
	const char * concat_ =
			concatenate_three_char_arrays(zero_, one_, two_);
	const int strcmp_ret_ = strcmp(concat_, zero_);
	assertion(!strcmp_ret_);
}

void
char_arrays_concatenation_test_7()
{
	const char * zero_ = "";
	const char * one_ = "";
	const char * two_ = "";
	const char * three_ = "";
	const char * concat_ = concatenate_four_char_arrays(
			zero_, one_, two_, three_);
	const int strcmp_ret_ = strcmp(concat_, zero_);
	assertion(!strcmp_ret_);
}

void
char_arrays_concatenation_tests()
{
	char_arrays_concatenation_test_0();
	char_arrays_concatenation_test_1();
	char_arrays_concatenation_test_2();
	char_arrays_concatenation_test_3();
	char_arrays_concatenation_test_4();
	char_arrays_concatenation_test_5();
	char_arrays_concatenation_test_6();
	char_arrays_concatenation_test_7();
}

void
char_array_tests()
{
	char_arrays_concatenation_tests();
}

void
char_arrays_simple_list_equality_test_0()
{
	char_arrays_simple_list * zero_ = NULL;
	char_arrays_simple_list * one_ = NULL;
	uint_fast8_t equality_ = char_arrays_simple_list_equality(zero_, one_);
	assertion(equality_);
}

void
char_arrays_simple_list_equality_test_1()
{
	char_arrays_simple_list * zero_ =
			char_arrays_simple_list_default_constructor();
	char_arrays_simple_list * one_ =
			char_arrays_simple_list_default_constructor();
	uint_fast8_t equality_ = char_arrays_simple_list_equality(zero_, one_);
	assertion(equality_);
}

void
char_arrays_simple_list_equality_tests()
{
	char_arrays_simple_list_equality_test_0();
}

void
char_arrays_simple_list_concatenation_test_0()
{
	char_arrays_simple_list * zero_;
	char_arrays_simple_list * one_;
	char_arrays_simple_list * concat_;
	uint_fast8_t zero_one_equality_;
	uint_fast8_t zero_concat_equality_;
	zero_ = char_arrays_simple_list_default_constructor();
	one_ = char_arrays_simple_list_default_constructor();
	zero_one_equality_ = char_arrays_simple_list_equality(zero_, one_);
	assertion(zero_one_equality_);
	concat_ = char_arrays_simple_list_concat(zero_, one_);
	zero_concat_equality_ =
			char_arrays_simple_list_equality(zero_, concat_);
	assertion(zero_concat_equality_);
	char_arrays_simple_list_destructor(zero_);
	char_arrays_simple_list_destructor(one_);
	char_arrays_simple_list_destructor(concat_);
}

void
char_arrays_simple_list_concatenation_tests()
{
	char_arrays_simple_list_concatenation_test_0();
}

void
char_arrays_simple_list_tests()
{
	char_arrays_simple_list_equality_tests();
	char_arrays_simple_list_concatenation_tests();
}

void
common_tests()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void common_tests()\n", __FILE__, __LINE__);
#endif
	char_array_tests();
	char_arrays_simple_list_tests();
}