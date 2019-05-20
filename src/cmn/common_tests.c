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
 * src/cmn/common_tests.c: Self explanatory...
 */

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `int strcmp(const char * s1, const char * s2)`. */
#include <string.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "amara_boolean.h"

#include "amara_string_tests.h"

#include "amara_strings_simple_list_tests.h"

/*   For `char * concatenate_two_char_arrays(const char * zero,
 * const char * one)`. */
#include "char_array.h"

#include "char_array_tests.h"

/*   For `char_array_simple_list` and its operations. */
#include "char_arrays_simple_list.h"

#include "char_arrays_simple_list_tests.h"

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
	fprintf(stderr, "%s\n", concat_);
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
	fprintf(stderr, "%s\n", zero_);
	fprintf(stderr, "%s\n", one_);
	fprintf(stderr, "%s\n", concat_);
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
	fprintf(stderr, "%s\n", zero_);
	fprintf(stderr, "%s\n", one_);
	fprintf(stderr, "%s\n", concat_);
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
char_arrays_concatenation_tests_()
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
char_array_tests_()
{
	char_arrays_concatenation_tests_();
}

void
char_arrays_simple_list_equality_test_0_()
{
	char_arrays_simple_list * zero_ = NULL;
	char_arrays_simple_list * one_ = NULL;
	unsigned char equality_ =
			char_arrays_simple_list_equality(zero_, one_);
	assertion(equality_);
}

void
char_arrays_simple_list_equality_test_1_()
{
	char_arrays_simple_list * zero_ =
			char_arrays_simple_list_default_constructor();
	char_arrays_simple_list * one_ =
			char_arrays_simple_list_default_constructor();
	unsigned char equality_ =
			char_arrays_simple_list_equality(zero_, one_);
	assertion(equality_);
}

void
char_arrays_simple_list_equality_tests_()
{
	char_arrays_simple_list_equality_test_0_();
	char_arrays_simple_list_equality_test_1_();
}

void
char_arrays_simple_list_concatenation_test_0()
{
	char_arrays_simple_list * zero_;
	char_arrays_simple_list * one_;
	char_arrays_simple_list * concat_;
	unsigned char zero_one_equality_;
	unsigned char zero_concat_equality_;
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
char_arrays_simple_list_concatenation_test_1()
{
	char_arrays_simple_list * zero_;
	char_arrays_simple_list * one_;
	char_arrays_simple_list * concat_;
	char_arrays_simple_list * expectation_;
	amara_boolean zero_one_equality_;
	amara_boolean concat_equals_expectation_;

	zero_ = char_arrays_simple_list_default_constructor();
	one_ = char_arrays_simple_list_default_constructor();
	expectation_ = char_arrays_simple_list_default_constructor();

	zero_one_equality_ = char_arrays_simple_list_equality(zero_, one_);
	assertion(zero_one_equality_ == AMARA_BOOLEAN_TRUE);

	zero_->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(zero_->first != NULL, "malloc failed\n");
	strcpy(zero_->first, "a");
	assertion(zero_->next == NULL);

	expectation_->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(expectation_->first != NULL, "malloc failed\n");

	strcpy(expectation_->first, "a");
	assertion(expectation_->next == NULL);

	concat_ = char_arrays_simple_list_concat(zero_, one_);
	concat_equals_expectation_ = char_arrays_simple_list_equality(
			expectation_, concat_);
	assertion(concat_equals_expectation_ == AMARA_BOOLEAN_TRUE);

	char_arrays_simple_list_destructor(zero_);
	char_arrays_simple_list_destructor(one_);
	char_arrays_simple_list_destructor(concat_);
	char_arrays_simple_list_destructor(expectation_);
}

void
char_arrays_simple_list_concatenation_test_2()
{
	char_arrays_simple_list * zero_;
	char_arrays_simple_list * one_;
	char_arrays_simple_list * concat_;
	char_arrays_simple_list * expectation_;
	amara_boolean zero_one_equality_;
	amara_boolean concat_equals_expectation_;

	zero_ = char_arrays_simple_list_default_constructor();
	one_ = char_arrays_simple_list_default_constructor();
	expectation_ = char_arrays_simple_list_default_constructor();

	zero_one_equality_ = char_arrays_simple_list_equality(zero_, one_);
	assertion(zero_one_equality_ == AMARA_BOOLEAN_TRUE);

	one_->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(one_->first != NULL, "malloc failed\n");
	strcpy(one_->first, "a");
	assertion(one_->next == NULL);

	expectation_->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(expectation_->first != NULL, "malloc failed\n");
	strcpy(expectation_->first, "a");
	assertion(expectation_->next == NULL);

	concat_ = char_arrays_simple_list_concat(zero_, one_);
	concat_equals_expectation_ = char_arrays_simple_list_equality(
			expectation_, concat_);
	assertion(concat_equals_expectation_ == AMARA_BOOLEAN_TRUE);

	char_arrays_simple_list_destructor(zero_);
	char_arrays_simple_list_destructor(one_);
	char_arrays_simple_list_destructor(concat_);
	char_arrays_simple_list_destructor(expectation_);
}

void
char_arrays_simple_list_concatenation_test_3()
{
	char_arrays_simple_list * zero_;
	char_arrays_simple_list * one_;
	char_arrays_simple_list * concat_;
	char_arrays_simple_list * expectation_;
	amara_boolean zero_one_equality_;
	amara_boolean concat_equals_expectation_;

	zero_ = char_arrays_simple_list_default_constructor();
	one_ = char_arrays_simple_list_default_constructor();
	expectation_ = char_arrays_simple_list_default_constructor();

	zero_one_equality_ = char_arrays_simple_list_equality(zero_, one_);
	assertion(zero_one_equality_ == AMARA_BOOLEAN_TRUE);

	zero_->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(zero_->first != NULL, "malloc failed\n");
	strcpy(zero_->first, "a");
	assertion(zero_->next == NULL);

	one_->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(one_->first != NULL, "malloc failed\n");
	strcpy(one_->first, "b");
	assertion(one_->next == NULL);

	expectation_->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(expectation_->first != NULL, "malloc failed\n");
	strcpy(expectation_->first, "a");
	expectation_->next = char_arrays_simple_list_default_constructor();
	expectation_->next->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(expectation_->next->first != NULL,
			"malloc failed\n");
	strcpy(expectation_->next->first, "b");
	assertion(expectation_->next->next == NULL);

	concat_ = char_arrays_simple_list_concat(zero_, one_);
	concat_equals_expectation_ = char_arrays_simple_list_equality(
			expectation_, concat_);
	assertion(concat_equals_expectation_ == AMARA_BOOLEAN_TRUE);

	char_arrays_simple_list_destructor(zero_);
	char_arrays_simple_list_destructor(one_);
	char_arrays_simple_list_destructor(concat_);
	char_arrays_simple_list_destructor(expectation_);
}

void
char_arrays_simple_list_concatenation_test_4()
{
	char_arrays_simple_list * zero_;
	char_arrays_simple_list * one_;
	char_arrays_simple_list * concat_;
	char_arrays_simple_list * expectation_;
	amara_boolean zero_one_equality_;
	amara_boolean concat_equals_expectation_;

	zero_ = char_arrays_simple_list_default_constructor();
	one_ = char_arrays_simple_list_default_constructor();
	expectation_ = char_arrays_simple_list_default_constructor();

	zero_one_equality_ = char_arrays_simple_list_equality(zero_, one_);
	assertion(zero_one_equality_ == AMARA_BOOLEAN_TRUE);

	zero_->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(zero_->first != NULL, "malloc failed\n");
	strcpy(zero_->first, "a");
	zero_->next = char_arrays_simple_list_default_constructor();
	zero_->next->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(zero_->next->first != NULL, "malloc failed\n");
	strcpy(zero_->next->first, "b");
	assertion(zero_->next->next == NULL);

	one_->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(one_->first != NULL, "malloc failed\n");
	strcpy(one_->first, "c");
	one_->next = char_arrays_simple_list_default_constructor();
	one_->next->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(one_->next->first != NULL, "malloc failed\n");
	strcpy(one_->next->first, "d");
	assertion(one_->next->next == NULL);

	expectation_->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(expectation_->first != NULL, "malloc failed\n");
	strcpy(expectation_->first, "a");
	expectation_->next = char_arrays_simple_list_default_constructor();
	expectation_->next->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(expectation_->next->first != NULL,
			"malloc failed\n");
	strcpy(expectation_->next->first, "b");
	expectation_->next->next =
			char_arrays_simple_list_default_constructor();
	expectation_->next->next->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(expectation_->next->next->first != NULL,
			"malloc failed\n");
	strcpy(expectation_->next->next->first, "c");
	expectation_->next->next->next =
			char_arrays_simple_list_default_constructor();
	expectation_->next->next->next->first =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(expectation_->next->next->next->first != NULL,
			"malloc failed\n");
	strcpy(expectation_->next->next->next->first, "d");
	assertion(expectation_->next->next->next->next == NULL);

	concat_ = char_arrays_simple_list_concat(zero_, one_);
	concat_equals_expectation_ = char_arrays_simple_list_equality(
			expectation_, concat_);
	assertion(concat_equals_expectation_ == AMARA_BOOLEAN_TRUE);

	char_arrays_simple_list_destructor(zero_);
	char_arrays_simple_list_destructor(one_);
	char_arrays_simple_list_destructor(concat_);
	char_arrays_simple_list_destructor(expectation_);
}

void
char_arrays_simple_list_concatenation_tests_()
{
	char_arrays_simple_list_concatenation_test_0();
	char_arrays_simple_list_concatenation_test_1();
	char_arrays_simple_list_concatenation_test_2();
	char_arrays_simple_list_concatenation_test_3();
	char_arrays_simple_list_concatenation_test_4();
}

void
char_arrays_simple_list_tests_()
{
	char_arrays_simple_list_equality_tests_();
	char_arrays_simple_list_concatenation_tests_();
}

void
common_tests()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void common_tests()\n", __FILE__, __LINE__);
#endif

	char_array_tests_();

	char_array_tests();

	char_arrays_simple_list_tests_();

	char_arrays_simple_list_tests();

	amara_string_tests();

	amara_strings_simple_list_tests();
}
