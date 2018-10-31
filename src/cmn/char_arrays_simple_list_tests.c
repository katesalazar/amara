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
 * src/cmn/char_arrays_simple_list_tests.c: Test the simple list of
 * character arrays.
 */

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

#include "../asr/assertion.h"

#include "char_arrays_simple_list.h"

#include "char_arrays_simple_list_tests.h"

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

	char_arrays_simple_list_destructor(concatenation_);
}

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

	char_array_zero_ = malloc(1);
	* char_array_zero_ = 0;

	list_zero_ = char_arrays_simple_list_push_front(
			list_zero_, char_array_zero_);
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

	char_array_one_ = malloc(1);
	* char_array_one_ = 0;

	list_one_ = char_arrays_simple_list_push_front(
			list_one_, char_array_one_);
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

void
char_arrays_simple_list_concat_destructive_tests()
{
	char_arrays_simple_list_concat_destructive_test_0();
	char_arrays_simple_list_concat_destructive_test_1();
	char_arrays_simple_list_concat_destructive_test_2();
	char_arrays_simple_list_concat_destructive_test_3();
	char_arrays_simple_list_concat_destructive_test_4();
}

void
char_arrays_simple_list_push_front_test_0()
{
	char_arrays_simple_list * char_arrays_;
	char * char_array_zero_;
	char * char_array_one_;

	char_array_zero_ = malloc(1);
	* char_array_zero_ = '\0';

	char_array_one_ = malloc(1);
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

void
char_arrays_simple_list_tests()
{
	char_arrays_simple_list_concat_destructive_tests();
	char_arrays_simple_list_push_front_tests();
}
