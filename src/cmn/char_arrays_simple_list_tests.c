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
 * src/cmn/char_arrays_simple_list_tests.c: Test the simple list of
 * character arrays.
 */

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `size_t strlen(const char * s)`. */
#include <string.h>

#include "../asr/assertion.h"

#include "char_arrays_simple_list.h"

#include "char_arrays_simple_list_tests.h"

/**  Destructive concatenation of two null lists. */
void
char_arrays_simple_list_concat_destructive_test_0()
{
	char_arrays_simple_list * list_zero_;
	char_arrays_simple_list * list_one_;
	char_arrays_simple_list * concatenation_;

	list_zero_ = NULL;

	list_one_ = NULL;

	concatenation_ = char_arrays_simple_list_concat_destructive(
			list_zero_, list_one_);

	assertion(concatenation_ == NULL);
}

/**  Destructive concatenation of an empty list and a null list. */
void
char_arrays_simple_list_concat_destructive_test_1()
{
	char_arrays_simple_list * list_zero_;
	char_arrays_simple_list * list_one_;
	char_arrays_simple_list * concatenation_;

	list_zero_ = char_arrays_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	list_one_ = NULL;

	concatenation_ = char_arrays_simple_list_concat_destructive(
			list_zero_, list_one_);
	assertion(list_zero_ == concatenation_);

	list_zero_ = NULL;

	char_arrays_simple_list_destructor(concatenation_);
}

/**  Destructive concatenation of two empty lists. */
void
char_arrays_simple_list_concat_destructive_test_2()
{
	char_arrays_simple_list * list_zero_;
	char_arrays_simple_list * list_one_;
	char_arrays_simple_list * concatenation_;

	list_zero_ = char_arrays_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	list_one_ = char_arrays_simple_list_default_constructor();
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	concatenation_ = char_arrays_simple_list_concat_destructive(
			list_zero_, list_one_);
	assertion(concatenation_ != NULL);
	assertion(concatenation_->first == NULL);
	assertion(concatenation_->next == NULL);

	list_zero_ = NULL;
	list_one_ = NULL;

	char_arrays_simple_list_destructor(concatenation_);
}

/**  Destructive concatenation of a list with one array of characters
 * and an empty list. */
void
char_arrays_simple_list_concat_destructive_test_3()
{
	char_arrays_simple_list * list_zero_;
	char * char_array_zero_;
	char_arrays_simple_list * list_one_;
	char_arrays_simple_list * concatenation_;

	list_zero_ = char_arrays_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	char_array_zero_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(1);
	forced_assertion_two(char_array_zero_ != NULL,
			"malloc failed, char_arrays_simple_list_tests.c: 124\n");
	* char_array_zero_ = 0;

	list_zero_ = char_arrays_simple_list_push_front(
			list_zero_, char_array_zero_);
	assertion(* char_array_zero_ == 0);
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first != NULL);
	assertion(* list_zero_->first == '\0');
	assertion(list_zero_->next == NULL);

	list_one_ = char_arrays_simple_list_default_constructor();
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	concatenation_ = char_arrays_simple_list_concat_destructive(
			list_zero_, list_one_);
	assertion(concatenation_ != NULL);
	assertion(concatenation_->first != NULL);
	assertion(* concatenation_->first == '\0');
	assertion(concatenation_->next == NULL);

	list_zero_ = NULL;
	list_one_ = NULL;

	char_arrays_simple_list_destructor(concatenation_);
}

/**  Destructive concatenation of an empty list and a list with one
 * array of characters. */
void
char_arrays_simple_list_concat_destructive_test_4()
{
	char_arrays_simple_list * list_zero_;
	char_arrays_simple_list * list_one_;
	char * char_array_one_;
	char_arrays_simple_list * concatenation_;

	list_zero_ = char_arrays_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	list_one_ = char_arrays_simple_list_default_constructor();
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	char_array_one_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(1);
	forced_assertion_two(char_array_one_ != NULL,
			"malloc failed: char_arrays_simple_list_tests.c: 179\n");
	* char_array_one_ = 0;

	list_one_ = char_arrays_simple_list_push_front(
			list_one_, char_array_one_);
	assertion(* char_array_one_ == 0);
	assertion(list_one_ != NULL);
	assertion(list_one_->first != NULL);
	assertion(* list_one_->first == '\0');
	assertion(list_one_->next == NULL);

	concatenation_ = char_arrays_simple_list_concat_destructive(
			list_zero_, list_one_);
	assertion(concatenation_ != NULL);
	assertion(concatenation_->first != NULL);
	assertion(* concatenation_->first == '\0');
	assertion(concatenation_->next == NULL);

	list_zero_ = NULL;
	list_one_ = NULL;

	char_arrays_simple_list_destructor(concatenation_);
}

/**  Destructive concatenation of a list with two arrays of characters
 * and an empty list. */
void
char_arrays_simple_list_concat_destructive_test_5()
{
	char_arrays_simple_list * list_zero_;
	char * char_array_zero_;
	char * char_array_one_;
	char_arrays_simple_list * list_one_;
	char_arrays_simple_list * concatenation_;

	list_zero_ = char_arrays_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	char_array_zero_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(1);
	forced_assertion_two(char_array_zero_ != NULL,
			"malloc failed: char_arrays_simple_list_tests.c: 225\n");
	* char_array_zero_ = 0;

	list_zero_ = char_arrays_simple_list_push_front(
			list_zero_, char_array_zero_);
	assertion(* char_array_zero_ == 0);
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first != NULL);
	assertion(* list_zero_->first == '\0');
	assertion(list_zero_->next == NULL);

	char_array_one_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(char_array_one_ != NULL,
			"malloc failed: char_arrays_simple_list_tests.c: 242\n");
	* char_array_one_ = 0x30;  /* ASCII 48: '0'. */
	* (char_array_one_ + 1) = 0x00;  /* ASCII 0: '\0'. */

	list_zero_ = char_arrays_simple_list_push_front(
			list_zero_, char_array_one_);
	assertion(* char_array_one_ == 0x30);  /* ASCII 48: '0'. */
	assertion(* (char_array_one_ + 1) == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first != NULL);
	assertion(* list_zero_->first == 0x30);  /* ASCII 48: '0'. */
	assertion(* (list_zero_->first + 1) == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next != NULL);
	assertion(list_zero_->next->first != NULL);
	assertion(* list_zero_->next->first == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next->next == NULL);

	list_one_ = char_arrays_simple_list_default_constructor();
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	concatenation_ = char_arrays_simple_list_concat_destructive(
			list_zero_, list_one_);
	assertion(concatenation_ != NULL);
	assertion(concatenation_->first != NULL);
	assertion(* concatenation_->first == 0x30);  /* ASCII 48: '0'. */
	assertion(* (concatenation_->first + 1) == 0x00);  /* ASCII 0: '\0'. */
	assertion(concatenation_->next != NULL);
	assertion(concatenation_->next->first != NULL);
	assertion(* concatenation_->next->first == 0x00);  /* ASCII 0: '\0'. */
	assertion(concatenation_->next->next == NULL);

	list_zero_ = NULL;
	list_one_ = NULL;

	char_arrays_simple_list_destructor(concatenation_);
}

/**  Destructive concatenation of a list with one array of characters
 * and another list with two arrays of characters. */
void
char_arrays_simple_list_concat_destructive_test_6()
{
	char_arrays_simple_list * list_zero_;
	char * char_array_zero_;
	char * char_array_one_;
	char * char_array_two_;
	char_arrays_simple_list * list_one_;
	char_arrays_simple_list * concatenation_;

	list_zero_ = char_arrays_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	char_array_zero_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(char_array_zero_ != NULL,
			"malloc failed, char_arrays_simple_list_tests.c: 304\n");
	* char_array_zero_ = 0x30;  /* ASCII 48: '0'. */
	* (char_array_zero_ + 1) = 0x00;  /* ASCII 0: '\0'. */

	list_zero_ = char_arrays_simple_list_push_front(
			list_zero_, char_array_zero_);
	assertion(* char_array_zero_ == 0x30);  /* ASCII 48: '0'. */
	assertion(* (char_array_zero_ + 1) == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first != NULL);
	assertion(* list_zero_->first == 0x30);  /* ASCII 48: '0'. */
	assertion(* (list_zero_->first + 1) == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next == NULL);

	list_one_ = char_arrays_simple_list_default_constructor();
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	char_array_two_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(char_array_two_ != NULL,
			"malloc failed, char_arrays_simple_list_tests.c: 329\n");
	* char_array_two_ = 0x32;  /* ASCII 50: '2'. */
	* (char_array_two_ + 1) = 0x00;  /* ASCII 0: '\0'. */

	list_one_ = char_arrays_simple_list_push_front(
			list_one_, char_array_two_);
	assertion(* char_array_two_ == 0x32);  /* ASCII 50: '2'. */
	assertion(* (char_array_two_ + 1) == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_ != NULL);
	assertion(list_one_->first != NULL);
	assertion(* list_one_->first == 0x32);  /* ASCII 50: '2'. */
	assertion(* (list_one_->first + 1) == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->next == NULL);

	char_array_one_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(2);
	forced_assertion_two(char_array_one_ != NULL,
			"malloc failed, char_arrays_simple_list_tests.c: 349\n");
	* char_array_one_ = 0x31;  /* ASCII 49: '1'. */
	* (char_array_one_ + 1) = 0x00;  /* ASCII 0: '\0'. */

	list_one_ = char_arrays_simple_list_push_front(
			list_one_, char_array_one_);
	assertion(* char_array_one_ == 0x31);  /* ASCII 49: '1'. */
	assertion(* (char_array_one_ + 1) == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_ != NULL);
	assertion(list_one_->first != NULL);
	assertion(* list_one_->first == 0x31);  /* ASCII 49: '1'. */
	assertion(* (list_one_->first + 1) == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->next != NULL);
	assertion(list_one_->next->first != NULL);
	assertion(* list_one_->next->first == 0x32);  /* ASCII 50: '2'. */
	/* ASCII 0: '\0'. */
	assertion(* (list_one_->next->first + 1) == 0x00);
	assertion(list_one_->next->next == NULL);

	concatenation_ = char_arrays_simple_list_concat_destructive(
			list_zero_, list_one_);
	assertion(concatenation_ != NULL);
	assertion(concatenation_->first != NULL);
	assertion(* concatenation_->first == 0x30);  /* ASCII 48: '0'. */
	assertion(* (concatenation_->first + 1) == 0x00);  /* ASCII 0: '\0'. */
	assertion(concatenation_->next != NULL);
	assertion(concatenation_->next->first != NULL);
	assertion(* concatenation_->next->first == 0x31);  /* ASCII 49: '1'. */
	/* ASCII 0: '\0'. */
	assertion(* (concatenation_->next->first + 1) == 0x00);
	assertion(concatenation_->next->next != NULL);
	assertion(concatenation_->next->next->first != NULL);
	/* ASCII 50: '2'. */
	assertion(* concatenation_->next->next->first == 0x32);
	/* ASCII 0: '\0'. */
	assertion(* (concatenation_->next->next->first + 1) == 0x00);
	assertion(concatenation_->next->next->next == NULL);

	list_zero_ = NULL;
	list_one_ = NULL;

	char_arrays_simple_list_destructor(concatenation_);
}

void
char_arrays_simple_list_concat_destructive_tests()
{
	char_arrays_simple_list_concat_destructive_test_0();
	char_arrays_simple_list_concat_destructive_test_1();
	char_arrays_simple_list_concat_destructive_test_2();
	char_arrays_simple_list_concat_destructive_test_3();
	char_arrays_simple_list_concat_destructive_test_4();
	char_arrays_simple_list_concat_destructive_test_5();
	char_arrays_simple_list_concat_destructive_test_6();
}

void
char_arrays_simple_list_push_front_test_0()
{
	char_arrays_simple_list * char_arrays_;
	char * char_array_zero_;
	char * char_array_one_;

	char_array_zero_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(1);
	forced_assertion_two(char_array_zero_ != NULL, "malloc failed\n");
	* char_array_zero_ = '\0';

	char_array_one_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(1);
	forced_assertion_two(char_array_one_ != NULL, "malloc failed\n");
	* char_array_one_ = '\0';

	char_arrays_ = char_arrays_simple_list_default_constructor();
	assertion(char_arrays_ != NULL);
	assertion(char_arrays_->first == NULL);
	assertion(char_arrays_->next == NULL);

	char_arrays_ = char_arrays_simple_list_push_front(
			char_arrays_, char_array_zero_);
	assertion(char_arrays_ != NULL);
	assertion(char_arrays_->first != NULL);
	assertion(* char_arrays_->first == '\0');
	assertion(char_arrays_->next == NULL);
	assertion(* char_array_zero_ == '\0');
	assertion(char_arrays_->first != char_array_zero_);

	char_arrays_ = char_arrays_simple_list_push_front(
			char_arrays_, char_array_one_);
	assertion(char_arrays_ != NULL);
	assertion(char_arrays_->first != NULL);
	assertion(* char_arrays_->first == '\0');
	assertion(char_arrays_->next != NULL);
	assertion(char_arrays_->next->first != NULL);
	assertion(* char_arrays_->next->first == '\0');
	assertion(char_arrays_->next->next == NULL);
	assertion(* char_array_zero_ == '\0');
	assertion(char_arrays_->first != char_array_zero_);
	assertion(* char_array_one_ == '\0');
	assertion(char_arrays_->next->first != char_array_one_);

	free(char_array_one_);
	free(char_array_zero_);
	char_arrays_simple_list_destructor(char_arrays_);
}

void
char_arrays_simple_list_push_front_tests()
{
	char_arrays_simple_list_push_front_test_0();
}

#ifndef NDEBUG

void
char_arrays_simple_list_equality_test_0()
{
	char_arrays_simple_list * list_zero_;
	char_arrays_simple_list * list_one_;
	amara_boolean equality_;

	list_zero_ = NULL;

	list_one_ = NULL;

	equality_ = char_arrays_simple_list_equality(list_zero_, list_one_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
}

#endif

#ifndef NDEBUG

void
char_arrays_simple_list_equality_test_1()
{
	char_arrays_simple_list * list_zero_;
	char_arrays_simple_list * list_one_;
	amara_boolean equality_;

	list_zero_ = char_arrays_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	list_one_ = NULL;

	equality_ = char_arrays_simple_list_equality(list_zero_, list_one_);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	char_arrays_simple_list_destructor(list_zero_);
}

#endif

#ifndef NDEBUG

void
char_arrays_simple_list_equality_test_2()
{
	char_arrays_simple_list * list_zero_;
	char_arrays_simple_list * list_one_;
	amara_boolean equality_;

	list_zero_ = NULL;

	list_one_ = char_arrays_simple_list_default_constructor();
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	equality_ = char_arrays_simple_list_equality(list_zero_, list_one_);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	char_arrays_simple_list_destructor(list_one_);
}

#endif

#ifndef NDEBUG

void
char_arrays_simple_list_equality_test_3()
{
	char_arrays_simple_list * list_zero_;
	char_arrays_simple_list * list_one_;
	char * foo_;
	amara_boolean equality_;

	list_zero_ = char_arrays_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	foo_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(strlen("foo") + 1);
	forced_assertion_two(foo_ != NULL, "malloc failed\n");
	strcpy(foo_, "foo");
	assertion(foo_[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(foo_[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[3] == 0x00);  /* ASCII 0: '\0'. */

	list_zero_ = char_arrays_simple_list_push_front(
			list_zero_, foo_);
	assertion(foo_[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(foo_[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->first != NULL);
	assertion(list_zero_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_zero_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next == NULL);

	list_one_ = NULL;

	equality_ = char_arrays_simple_list_equality(list_zero_, list_one_);
	assertion(list_zero_->first != NULL);
	assertion(list_zero_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_zero_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next == NULL);
	assertion(equality_ == AMARA_BOOLEAN_FALSE);

	free(foo_);
	char_arrays_simple_list_destructor(list_zero_);
}

#endif

#ifndef NDEBUG

void
char_arrays_simple_list_equality_test_4()
{
	char_arrays_simple_list * list_zero_;
	char_arrays_simple_list * list_one_;
	char * foo_;
	amara_boolean equality_;

	list_zero_ = NULL;

	list_one_ = char_arrays_simple_list_default_constructor();
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	foo_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(strlen("foo") + 1);
	forced_assertion_two(foo_ != NULL, "malloc failed\n");
	strcpy(foo_, "foo");
	assertion(foo_[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(foo_[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[3] == 0x00);  /* ASCII 0: '\0'. */

	list_one_ = char_arrays_simple_list_push_front(
			list_one_, foo_);
	assertion(foo_[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(foo_[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->first != NULL);
	assertion(list_one_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_one_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_one_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_one_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->next == NULL);

	equality_ = char_arrays_simple_list_equality(list_zero_, list_one_);
	assertion(list_one_->first != NULL);
	assertion(list_one_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_one_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_one_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_one_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->next == NULL);
	assertion(equality_ == AMARA_BOOLEAN_FALSE);

	free(foo_);
	char_arrays_simple_list_destructor(list_one_);
}

#endif

#ifndef NDEBUG

void
char_arrays_simple_list_equality_test_5()
{
	char_arrays_simple_list * list_zero_;
	char_arrays_simple_list * list_one_;
	char * foo_;
	char * bar_;
	amara_boolean equality_;

	list_zero_ = char_arrays_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	list_one_ = char_arrays_simple_list_default_constructor();
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	foo_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(strlen("foo") + 1);
	forced_assertion_two(foo_ != NULL, "malloc failed\n");
	strcpy(foo_, "foo");
	assertion(foo_[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(foo_[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[3] == 0x00);  /* ASCII 0: '\0'. */

	bar_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(strlen("bar") + 1);
	forced_assertion_two(bar_ != NULL, "malloc failed\n");
	strcpy(bar_, "bar");
	assertion(bar_[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(bar_[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(bar_[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(bar_[3] == 0x00);  /* ASCII 0: '\0'. */

	list_zero_ = char_arrays_simple_list_push_front(
			list_zero_, bar_);
	assertion(bar_[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(bar_[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(bar_[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(bar_[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->first != NULL);
	assertion(list_zero_->first[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(list_zero_->first[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(list_zero_->first[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(list_zero_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next == NULL);

	list_zero_ = char_arrays_simple_list_push_front(
			list_zero_, foo_);
	assertion(foo_[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(foo_[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->first != NULL);
	assertion(list_zero_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_zero_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next != NULL);
	assertion(list_zero_->next->first != NULL);
	assertion(list_zero_->next->first[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(list_zero_->next->first[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(list_zero_->next->first[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(list_zero_->next->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next->next == NULL);

	list_one_ = char_arrays_simple_list_push_front(
			list_one_, foo_);
	assertion(foo_[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(foo_[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->first != NULL);
	assertion(list_one_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_one_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_one_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_one_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->next == NULL);

	equality_ = char_arrays_simple_list_equality(list_zero_, list_one_);
	assertion(list_zero_->first != NULL);
	assertion(list_zero_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_zero_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next != NULL);
	assertion(list_zero_->next->first != NULL);
	assertion(list_zero_->next->first[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(list_zero_->next->first[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(list_zero_->next->first[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(list_zero_->next->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next->next == NULL);
	assertion(list_one_->first != NULL);
	assertion(list_one_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_one_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_one_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_one_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->next == NULL);
	assertion(equality_ == AMARA_BOOLEAN_FALSE);

	free(bar_);
	free(foo_);
	char_arrays_simple_list_destructor(list_one_);
	char_arrays_simple_list_destructor(list_zero_);
}

#endif

#ifndef NDEBUG

void
char_arrays_simple_list_equality_test_6()
{
	char_arrays_simple_list * list_zero_;
	char_arrays_simple_list * list_one_;
	char * foo_;
	char * bar_;
	amara_boolean equality_;

	list_zero_ = char_arrays_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	list_one_ = char_arrays_simple_list_default_constructor();
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	foo_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(strlen("foo") + 1);
	forced_assertion_two(foo_ != NULL, "malloc failed\n");
	strcpy(foo_, "foo");
	assertion(foo_[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(foo_[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[3] == 0x00);  /* ASCII 0: '\0'. */

	bar_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(strlen("bar") + 1);
	forced_assertion_two(bar_ != NULL,
			"malloc failed, char_arrays_simple_list_tests.c: 810\n");
	assertion(bar_ != NULL);
	strcpy(bar_, "bar");
	assertion(bar_[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(bar_[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(bar_[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(bar_[3] == 0x00);  /* ASCII 0: '\0'. */

	list_zero_ = char_arrays_simple_list_push_front(
			list_zero_, foo_);
	assertion(foo_[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(foo_[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->first != NULL);
	assertion(list_zero_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_zero_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next == NULL);

	list_one_ = char_arrays_simple_list_push_front(
			list_one_, bar_);
	assertion(bar_[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(bar_[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(bar_[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(bar_[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->first != NULL);
	assertion(list_one_->first[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(list_one_->first[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(list_one_->first[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(list_one_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->next == NULL);

	list_one_ = char_arrays_simple_list_push_front(
			list_one_, foo_);
	assertion(foo_[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(foo_[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->first != NULL);
	assertion(list_one_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_one_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_one_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_one_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->next != NULL);
	assertion(list_one_->next->first != NULL);
	assertion(list_one_->next->first[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(list_one_->next->first[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(list_one_->next->first[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(list_one_->next->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->next->next == NULL);

	equality_ = char_arrays_simple_list_equality(list_zero_, list_one_);
	assertion(list_zero_->first != NULL);
	assertion(list_zero_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_zero_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next == NULL);
	assertion(list_one_->first != NULL);
	assertion(list_one_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_one_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_one_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_one_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->next != NULL);
	assertion(list_one_->next->first != NULL);
	assertion(list_one_->next->first[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(list_one_->next->first[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(list_one_->next->first[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(list_one_->next->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->next->next == NULL);
	assertion(equality_ == AMARA_BOOLEAN_FALSE);

	free(bar_);
	free(foo_);
	char_arrays_simple_list_destructor(list_one_);
	char_arrays_simple_list_destructor(list_zero_);
}

#endif

#ifndef NDEBUG

void
char_arrays_simple_list_equality_test_7()
{
	char_arrays_simple_list * list_zero_;
	char_arrays_simple_list * list_one_;
	char * foo_;
	char * bar_;
	amara_boolean equality_;

	list_zero_ = char_arrays_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);

	list_one_ = char_arrays_simple_list_default_constructor();
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);

	foo_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(strlen("foo") + 1);
	forced_assertion_two(foo_ != NULL,
			"malloc failed, char_arrays_simple_list_tests.c: 848\n");
	strcpy(foo_, "foo");
	assertion(foo_[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(foo_[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[3] == 0x00);  /* ASCII 0: '\0'. */

	bar_ =
#ifdef AMARA_USE_STD_CXX98
			(char *)
#endif
			malloc(strlen("bar") + 1);
	forced_assertion_two(bar_ != NULL,
			"malloc failed, char_arrays_simple_list_tests.c: 862\n");
	assertion(bar_ != NULL);
	strcpy(bar_, "bar");
	assertion(bar_[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(bar_[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(bar_[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(bar_[3] == 0x00);  /* ASCII 0: '\0'. */

	list_zero_ = char_arrays_simple_list_push_front(
			list_zero_, foo_);
	assertion(foo_[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(foo_[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(foo_[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->first != NULL);
	assertion(list_zero_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_zero_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next == NULL);

	list_one_ = char_arrays_simple_list_push_front(
			list_one_, bar_);
	assertion(bar_[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(bar_[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(bar_[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(bar_[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->first != NULL);
	assertion(list_one_->first[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(list_one_->first[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(list_one_->first[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(list_one_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->next == NULL);

	equality_ = char_arrays_simple_list_equality(list_zero_, list_one_);
	assertion(list_zero_->first != NULL);
	assertion(list_zero_->first[0] == 0x66);  /* ASCII 102: 'f'. */
	assertion(list_zero_->first[1] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[2] == 0x6F);  /* ASCII 111: 'o'. */
	assertion(list_zero_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_zero_->next == NULL);
	assertion(list_one_->first != NULL);
	assertion(list_one_->first[0] == 0x62);  /* ASCII 98: 'b'. */
	assertion(list_one_->first[1] == 0x61);  /* ASCII 97: 'a'. */
	assertion(list_one_->first[2] == 0x72);  /* ASCII 114: 'r'. */
	assertion(list_one_->first[3] == 0x00);  /* ASCII 0: '\0'. */
	assertion(list_one_->next == NULL);
	assertion(equality_ == AMARA_BOOLEAN_FALSE);

	free(bar_);
	free(foo_);
	char_arrays_simple_list_destructor(list_one_);
	char_arrays_simple_list_destructor(list_zero_);
}

#endif

void
char_arrays_simple_list_equality_tests()
{
#ifndef NDEBUG
	char_arrays_simple_list_equality_test_0();
	char_arrays_simple_list_equality_test_1();
	char_arrays_simple_list_equality_test_2();
	char_arrays_simple_list_equality_test_3();
	char_arrays_simple_list_equality_test_4();
	char_arrays_simple_list_equality_test_5();
	char_arrays_simple_list_equality_test_6();
	char_arrays_simple_list_equality_test_7();
#endif
}

void
char_arrays_simple_list_tests()
{
	char_arrays_simple_list_concat_destructive_tests();
	char_arrays_simple_list_push_front_tests();
	char_arrays_simple_list_equality_tests();
}
