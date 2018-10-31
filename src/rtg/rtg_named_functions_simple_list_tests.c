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
 * src/rtg/rtg_named_functions_simple_list_tests.c: Test the Amara run
 * time graph application named functions simple list.
 */

#include "../asr/assertion.h"
#include "rtg_named_function_tests.h"
#include "rtg_named_functions_simple_list.h"

void
rtg_named_functions_simple_list_construct_and_destruct_test_0()
{
	rtg_named_functions_simple_list * named_functions_zero_;

	named_functions_zero_ =
			rtg_named_functions_simple_list_default_constructor();
	assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first == NULL);
	assertion(named_functions_zero_->next == NULL);

	rtg_named_functions_simple_list_destructor(named_functions_zero_);
}

void
rtg_named_functions_simple_list_construct_and_destruct_test_1()
{
	rtg_named_functions_simple_list * named_functions_zero_;
	rtg_named_functions_simple_list * named_functions_one_;

	named_functions_zero_ =
			rtg_named_functions_simple_list_default_constructor();
	assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first == NULL);
	assertion(named_functions_zero_->next == NULL);

	named_functions_one_ =
			rtg_named_functions_simple_list_copy_constructor(
					named_functions_zero_);
	assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first == NULL);
	assertion(named_functions_zero_->next == NULL);
	assertion(named_functions_one_ != NULL);
	assertion(named_functions_one_->first == NULL);
	assertion(named_functions_one_->next == NULL);

	rtg_named_functions_simple_list_destructor(named_functions_one_);
	rtg_named_functions_simple_list_destructor(named_functions_zero_);
}

void
rtg_named_functions_simple_list_construct_and_destruct_test_2()
{
	rtg_named_functions_simple_list * named_functions_zero_;
	rtg_named_functions_simple_list * named_functions_one_;
	rtg_named_function * example_function_;

	named_functions_zero_ =
			rtg_named_functions_simple_list_default_constructor();
	assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first == NULL);
	assertion(named_functions_zero_->next == NULL);

	example_function_ = rtg_named_function_example_print_foo();
	assertion(example_function_ != NULL);
	assertion(example_function_->type_ ==
			RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(example_function_->operations_ != NULL);
	assertion(example_function_->operations_->first != NULL);
	assertion(example_function_->operations_->first->type_ ==
			RTG_OPERATION_TYPE_PRINT);
	assertion(example_function_->operations_->first->args_ != NULL);
	assertion(example_function_->operations_->first->args_->first != NULL);
	assertion(example_function_->operations_->first->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(example_function_->operations_->first->args_->next == NULL);
	assertion(example_function_->operations_->next == NULL);

	named_functions_zero_ = rtg_named_functions_simple_list_push_front(
			named_functions_zero_, example_function_);
	/* TODO add missing assertions. */

	named_functions_one_ =
			rtg_named_functions_simple_list_copy_constructor(
					named_functions_zero_);
	assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first != NULL);
	assertion(named_functions_zero_->next == NULL);
	assertion(named_functions_one_ != NULL);
	assertion(named_functions_one_->first != NULL);
	assertion(named_functions_one_->next == NULL);
	/* TODO missing assertions about the functions details. */

	rtg_named_function_destructor(example_function_);
	rtg_named_functions_simple_list_destructor(named_functions_one_);
	rtg_named_functions_simple_list_destructor(named_functions_zero_);
}

void
rtg_named_functions_simple_list_construct_and_destruct_test_3()
{
	rtg_named_functions_simple_list * named_functions_zero_;
	rtg_named_functions_simple_list * named_functions_one_;
	rtg_named_function * example_function_zero_;
	rtg_named_function * example_function_one_;

	named_functions_zero_ =
			rtg_named_functions_simple_list_default_constructor();
	assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first == NULL);
	assertion(named_functions_zero_->next == NULL);

	example_function_zero_ = rtg_named_function_example_print_foo();
	/* TODO add missing assertions. */

	named_functions_zero_ = rtg_named_functions_simple_list_push_front(
			named_functions_zero_, example_function_zero_);
	assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first != NULL);
	assertion(named_functions_zero_->next == NULL);
	/* TODO add missing assertions. */

	example_function_one_ = rtg_named_function_example_print_bar();
	/* TODO add missing assertions. */

	named_functions_zero_ = rtg_named_functions_simple_list_push_front(
			named_functions_zero_, example_function_one_);
	assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first != NULL);
	assertion(named_functions_zero_->next != NULL);
	assertion(named_functions_zero_->next->first != NULL);
	assertion(named_functions_zero_->next->next == NULL);
	/* TODO add missing assertions. */

	named_functions_one_ =
			rtg_named_functions_simple_list_copy_constructor(
					named_functions_zero_);
	assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first != NULL);
	assertion(named_functions_zero_->next != NULL);
	assertion(named_functions_zero_->next->first != NULL);
	assertion(named_functions_zero_->next->next == NULL);
	assertion(named_functions_one_ != NULL);
	assertion(named_functions_one_->first != NULL);
	assertion(named_functions_one_->next != NULL);
	assertion(named_functions_one_->next->first != NULL);
	assertion(named_functions_one_->next->next == NULL);
	/* TODO missing assertions about the functions details. */

	rtg_named_function_destructor(example_function_one_);
	rtg_named_function_destructor(example_function_zero_);
	rtg_named_functions_simple_list_destructor(named_functions_one_);
	rtg_named_functions_simple_list_destructor(named_functions_zero_);
}

void
rtg_named_functions_simple_list_construct_and_destruct_tests()
{
	rtg_named_functions_simple_list_construct_and_destruct_test_0();
	rtg_named_functions_simple_list_construct_and_destruct_test_1();
	rtg_named_functions_simple_list_construct_and_destruct_test_2();
	rtg_named_functions_simple_list_construct_and_destruct_test_3();
}

/*   Search in a null list. */
void
rtg_named_functions_simple_list_find_by_name_test_0()
{
	rtg_named_functions_simple_list * haystack_;
	amara_string * needle_;
	rtg_named_functions_simple_list_find_by_name_ret * search_result_;

	haystack_ = NULL;

	needle_ = amara_string_exhaustive_constructor("whatever");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_named_functions_simple_list_find_by_name(
			haystack_, needle_);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND);
	assertion(search_result_->named_function == NULL);
	assertion(search_result_->named_function_was_moved ==
			AMARA_BOOLEAN_FALSE);

	rtg_named_functions_simple_list_find_by_name_ret_destructor(
			search_result_);
	amara_string_destructor(needle_);
}

/*   Search in an empty list. */
void
rtg_named_functions_simple_list_find_by_name_test_1()
{
	rtg_named_functions_simple_list * haystack_;
	amara_string * needle_;
	rtg_named_functions_simple_list_find_by_name_ret * search_result_;

	haystack_ = rtg_named_functions_simple_list_default_constructor();
	assertion(haystack_ != NULL);
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);

	needle_ = amara_string_exhaustive_constructor("whatever");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_named_functions_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND);
	assertion(search_result_->named_function == NULL);
	assertion(search_result_->named_function_was_moved ==
			AMARA_BOOLEAN_FALSE);

	rtg_named_functions_simple_list_find_by_name_ret_destructor(
			search_result_);
	amara_string_destructor(needle_);
	rtg_named_functions_simple_list_destructor(haystack_);
}

/*   Search for something that is in the list. Do not move it out of the
 * result struct. */
void
rtg_named_functions_simple_list_find_by_name_test_2()
{
	rtg_named_functions_simple_list * haystack_;
	rtg_named_function * named_function_;
	amara_string * needle_;
	rtg_named_functions_simple_list_find_by_name_ret * search_result_;

	haystack_ = rtg_named_functions_simple_list_default_constructor();
	assertion(haystack_ != NULL);
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);

	named_function_ = rtg_named_function_example_print_foo();
	assertion(named_function_ != NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			named_function_);

	haystack_ = rtg_named_functions_simple_list_push_front(
			haystack_, named_function_);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			haystack_->first);
	assertion(haystack_->next == NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			named_function_);

	needle_ = amara_string_exhaustive_constructor("print_foo");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_named_functions_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
	assertion(haystack_->next == NULL);
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS);
	assertion(search_result_->named_function != NULL);
	assertion(search_result_->named_function_was_moved ==
			AMARA_BOOLEAN_FALSE);

	rtg_named_functions_simple_list_find_by_name_ret_destructor(
			search_result_);
	amara_string_destructor(needle_);
	rtg_named_function_destructor(named_function_);
	rtg_named_functions_simple_list_destructor(haystack_);
}

/*   Search for something that is in the list. Move it out of the result
 * struct. */
void
rtg_named_functions_simple_list_find_by_name_test_3()
{
	rtg_named_functions_simple_list * haystack_;
	rtg_named_function * named_function_;
	amara_string * needle_;
	rtg_named_functions_simple_list_find_by_name_ret * search_result_;
	rtg_named_function * extracted_search_result_;

	haystack_ = rtg_named_functions_simple_list_default_constructor();
	assertion(haystack_ != NULL);
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);

	named_function_ = rtg_named_function_example_print_foo();
	assertion(named_function_ != NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			named_function_);

	haystack_ = rtg_named_functions_simple_list_push_front(
			haystack_, named_function_);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			haystack_->first);
	assertion(haystack_->next == NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			named_function_);

	needle_ = amara_string_exhaustive_constructor("print_foo");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_named_functions_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
	assertion(haystack_->next == NULL);
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS);
	assertion(search_result_->named_function != NULL);
	assertion(search_result_->named_function_was_moved ==
			AMARA_BOOLEAN_FALSE);

	extracted_search_result_ = search_result_->named_function;
	search_result_->named_function_was_moved = AMARA_BOOLEAN_TRUE;

	rtg_named_function_destructor(extracted_search_result_);
	rtg_named_functions_simple_list_find_by_name_ret_destructor(
			search_result_);
	amara_string_destructor(needle_);
	rtg_named_function_destructor(named_function_);
	rtg_named_functions_simple_list_destructor(haystack_);
}

/*   Search for something that is not in the list (but the list is not
 * empty). */
void
rtg_named_functions_simple_list_find_by_name_test_4()
{
	rtg_named_functions_simple_list * haystack_;
	rtg_named_function * named_function_;
	amara_string * needle_;
	rtg_named_functions_simple_list_find_by_name_ret * search_result_;

	haystack_ = rtg_named_functions_simple_list_default_constructor();
	assertion(haystack_ != NULL);
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);

	named_function_ = rtg_named_function_example_print_foo();
	assertion(named_function_ != NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			named_function_);

	haystack_ = rtg_named_functions_simple_list_push_front(
			haystack_, named_function_);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			haystack_->first);
	assertion(haystack_->next == NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			named_function_);

	needle_ = amara_string_exhaustive_constructor("print_foa");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_named_functions_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
	assertion(haystack_->next == NULL);
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND);
	assertion(search_result_->named_function == NULL);
	assertion(search_result_->named_function_was_moved ==
			AMARA_BOOLEAN_FALSE);

	rtg_named_functions_simple_list_find_by_name_ret_destructor(
			search_result_);
	amara_string_destructor(needle_);
	rtg_named_function_destructor(named_function_);
	rtg_named_functions_simple_list_destructor(haystack_);
}

/*   Search for something that is in the list, but not in the head of
 * the list, but in the second position or beyond. */
void
rtg_named_functions_simple_list_find_by_name_test_5()
{
	rtg_named_functions_simple_list * haystack_;
	rtg_named_function * named_function_zero_;
	rtg_named_function * named_function_one_;
	amara_string * needle_;
	rtg_named_functions_simple_list_find_by_name_ret * search_result_;

	haystack_ = rtg_named_functions_simple_list_default_constructor();
	assertion(haystack_ != NULL);
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);

	named_function_zero_ = rtg_named_function_example_print_foo();
	assertion(named_function_zero_ != NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			named_function_zero_);

	haystack_ = rtg_named_functions_simple_list_push_front(
			haystack_, named_function_zero_);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			haystack_->first);
	assertion(haystack_->next == NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			named_function_zero_);

	named_function_one_ = rtg_named_function_example_print_bar();
	assertion(named_function_one_ != NULL);
	assert_expectations_on_rtg_named_function_example_print_bar(
			named_function_one_);

	haystack_ = rtg_named_functions_simple_list_push_front(
			haystack_, named_function_one_);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_named_function_example_print_bar(
			haystack_->first);
	assertion(haystack_->next != NULL);
	assertion(haystack_->next->first != NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			haystack_->next->first);
	assertion(haystack_->next->next == NULL);
	assert_expectations_on_rtg_named_function_example_print_bar(
			named_function_one_);

	needle_ = amara_string_exhaustive_constructor("print_foo");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_named_functions_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
	assertion(haystack_->next != NULL);
	assertion(haystack_->next->first != NULL);
	assert_expectations_on_rtg_named_function_example_print_foo(
			haystack_->next->first);
	assertion(haystack_->next->next == NULL);
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS);
	assertion(search_result_->named_function != NULL);
	assertion(search_result_->named_function_was_moved ==
			AMARA_BOOLEAN_FALSE);

	rtg_named_functions_simple_list_find_by_name_ret_destructor(
			search_result_);
	amara_string_destructor(needle_);
	rtg_named_function_destructor(named_function_one_);
	rtg_named_function_destructor(named_function_zero_);
	rtg_named_functions_simple_list_destructor(haystack_);
}

void
rtg_named_functions_simple_list_find_by_name_tests()
{
	rtg_named_functions_simple_list_find_by_name_test_0();
	rtg_named_functions_simple_list_find_by_name_test_1();
	rtg_named_functions_simple_list_find_by_name_test_2();
	rtg_named_functions_simple_list_find_by_name_test_3();
	rtg_named_functions_simple_list_find_by_name_test_4();
	rtg_named_functions_simple_list_find_by_name_test_5();
}

void
rtg_named_functions_simple_list_tests()
{
	rtg_named_functions_simple_list_construct_and_destruct_tests();
	rtg_named_functions_simple_list_find_by_name_tests();
}
