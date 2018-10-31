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
 * src/rtg/rtg_applications_simple_list_tests.c: Test the Amara run time
 * graph applications simple list.
 */

#include "../asr/assertion.h"

#include "rtg_application_tests.h"
#include "rtg_applications_simple_list.h"

#include "rtg_applications_simple_list_tests.h"

void
rtg_applications_simple_list_construct_and_destruct_test_0()
{
	rtg_applications_simple_list * applications_list_;
	applications_list_ =
			rtg_applications_simple_list_default_constructor();
	rtg_applications_simple_list_destructor(applications_list_);
}

void
rtg_applications_simple_list_construct_and_destruct_test_1()
{
	rtg_applications_simple_list * applications_list_zero_;
	rtg_applications_simple_list * applications_list_one_;

	applications_list_zero_ =
			rtg_applications_simple_list_default_constructor();
	assertion(applications_list_zero_ != NULL);
	assertion(applications_list_zero_->first == NULL);
	assertion(applications_list_zero_->next == NULL);

	applications_list_one_ = rtg_applications_simple_list_copy_constructor(
			applications_list_zero_);
	assertion(applications_list_one_ != NULL);
	assertion(applications_list_one_->first == NULL);
	assertion(applications_list_one_->next == NULL);

	rtg_applications_simple_list_destructor(applications_list_one_);
	rtg_applications_simple_list_destructor(applications_list_zero_);
}

void
rtg_applications_simple_list_construct_and_destruct_test_2()
{
	rtg_applications_simple_list * applications_list_zero_;
	rtg_applications_simple_list * applications_list_one_;
	rtg_application * application_zero_;

	applications_list_zero_ =
			rtg_applications_simple_list_default_constructor();
	assertion(applications_list_zero_ != NULL);
	assertion(applications_list_zero_->first == NULL);
	assertion(applications_list_zero_->next == NULL);

	application_zero_ = rtg_application_example_cli_app_print_foo();
	assertion(application_zero_ != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_zero_);
	assertion(application_zero_->entry_point_function_ != NULL);
	assertion(application_zero_->entry_point_function_->type_ ==
			RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(application_zero_->entry_point_function_->operations_ !=
			NULL);
	assertion(application_zero_->entry_point_function_->operations_->first !=
			NULL);
	assertion(application_zero_->entry_point_function_->operations_->next ==
			NULL);

	applications_list_zero_ = rtg_applications_simple_list_push_front(
			applications_list_zero_, application_zero_);
	assertion(applications_list_zero_ != NULL);
	assertion(applications_list_zero_->first != NULL);
	assertion(applications_list_zero_->next == NULL);

	applications_list_one_ = rtg_applications_simple_list_copy_constructor(
			applications_list_zero_);
	assertion(applications_list_one_ != NULL);
	assertion(applications_list_one_->first != NULL);
	assertion(applications_list_one_->next == NULL);

	rtg_applications_simple_list_destructor(applications_list_one_);
	rtg_applications_simple_list_destructor(applications_list_zero_);
}

void
rtg_applications_simple_list_construct_and_destruct_test_3()
{
	rtg_applications_simple_list * applications_list_zero_;
	rtg_applications_simple_list * applications_list_one_;
	rtg_application * application_zero_;
	rtg_application * application_one_;

	applications_list_zero_ =
			rtg_applications_simple_list_default_constructor();
	assertion(applications_list_zero_ != NULL);
	assertion(applications_list_zero_->first == NULL);
	assertion(applications_list_zero_->next == NULL);

	application_zero_ = rtg_application_example_cli_app_print_foo();
	assertion(application_zero_ != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_zero_);
	assertion(application_zero_->entry_point_function_ != NULL);
	assertion(application_zero_->entry_point_function_->type_ ==
			RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(application_zero_->entry_point_function_->operations_ !=
			NULL);
	assertion(application_zero_->entry_point_function_->operations_->first !=
			NULL);
	assertion(application_zero_->entry_point_function_->operations_->next ==
			NULL);

	applications_list_zero_ = rtg_applications_simple_list_push_front(
			applications_list_zero_, application_zero_);
	assertion(applications_list_zero_ != NULL);
	assertion(applications_list_zero_->first != NULL);
	assertion(applications_list_zero_->next == NULL);

	application_one_ = rtg_application_example_cli_app_print_bar();
	assertion(application_one_ != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			application_one_);
	assertion(application_one_->entry_point_function_ != NULL);
	assertion(application_one_->entry_point_function_->type_ ==
			RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(application_one_->entry_point_function_->operations_ !=
			NULL);
	assertion(application_one_->entry_point_function_->operations_->first !=
			NULL);
	assertion(application_one_->entry_point_function_->operations_->next ==
			NULL);

	applications_list_zero_ = rtg_applications_simple_list_push_front(
			applications_list_zero_, application_one_);
	assertion(applications_list_zero_ != NULL);
	assertion(applications_list_zero_->first != NULL);
	assertion(applications_list_zero_->next != NULL);
	assertion(applications_list_zero_->next->first != NULL);
	assertion(applications_list_zero_->next->next == NULL);

	applications_list_one_ = rtg_applications_simple_list_copy_constructor(
			applications_list_zero_);
	assertion(applications_list_one_ != NULL);
	assertion(applications_list_one_->first != NULL);
	assertion(applications_list_one_->next != NULL);
	assertion(applications_list_one_->next->first != NULL);
	assertion(applications_list_one_->next->next == NULL);

	rtg_applications_simple_list_destructor(applications_list_one_);
	rtg_applications_simple_list_destructor(applications_list_zero_);
}

void
rtg_applications_simple_list_construct_and_destruct_tests()
{
	rtg_applications_simple_list_construct_and_destruct_test_0();
	rtg_applications_simple_list_construct_and_destruct_test_1();
	rtg_applications_simple_list_construct_and_destruct_test_2();
	rtg_applications_simple_list_construct_and_destruct_test_3();
}

/**  Search in an empty list. */
void
rtg_applications_simple_list_find_by_name_test_0()
{
	rtg_applications_simple_list * haystack_;
	amara_string * needle_;
	rtg_applications_simple_list_find_by_name_ret * search_result_;

	haystack_ = rtg_applications_simple_list_default_constructor();
	assertion(haystack_ != NULL);
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);

	needle_ = amara_string_exhaustive_constructor("foo");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_applications_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND);
	assertion(search_result_->application == NULL);
	assertion(search_result_->application_was_moved ==
			AMARA_BOOLEAN_FALSE);

	rtg_applications_simple_list_find_by_name_ret_destructor(
			search_result_);
	amara_string_destructor(needle_);
	rtg_applications_simple_list_destructor(haystack_);
}

/**  Search for an application that exists and is the single element of
 * the haystack list. Move it out from the returned struct. */
void
rtg_applications_simple_list_find_by_name_test_1()
{
	rtg_applications_simple_list * haystack_;
	rtg_application * application_;
	amara_string * needle_;
	rtg_applications_simple_list_find_by_name_ret * search_result_;
	rtg_application * found_application_;

	haystack_ = rtg_applications_simple_list_default_constructor();
	assertion(haystack_ != NULL);
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);

	application_ = rtg_application_example_cli_app_print_foo();
	assertion(application_ != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);

	haystack_ = rtg_applications_simple_list_push_front(
			haystack_, application_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
	assertion(haystack_->next == NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);

	needle_ = amara_string_exhaustive_constructor("cli_app_print_foo");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_applications_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
	assertion(haystack_->next == NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS);
	assertion(search_result_->application != NULL);
	assertion(search_result_->application_was_moved ==
			AMARA_BOOLEAN_FALSE);

	found_application_ = search_result_->application;
	search_result_->application_was_moved = AMARA_BOOLEAN_TRUE;

	rtg_application_destructor(found_application_);
	rtg_applications_simple_list_find_by_name_ret_destructor(
			search_result_);
	amara_string_destructor(needle_);
	rtg_application_destructor(application_);
	rtg_applications_simple_list_destructor(haystack_);
}

/**  Search for an application that exists and is the single element in
 * the haystack list. Do not move it out from the returned struct. */
void
rtg_applications_simple_list_find_by_name_test_2()
{
	rtg_applications_simple_list * haystack_;
	rtg_application * application_;
	amara_string * needle_;
	rtg_applications_simple_list_find_by_name_ret * search_result_;

	haystack_ = rtg_applications_simple_list_default_constructor();
	assertion(haystack_ != NULL);
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);

	application_ = rtg_application_example_cli_app_print_foo();
	assertion(application_ != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);

	haystack_ = rtg_applications_simple_list_push_front(
			haystack_, application_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
	assertion(haystack_->next == NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);

	needle_ = amara_string_exhaustive_constructor("cli_app_print_foo");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_applications_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
	assertion(haystack_->next == NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS);
	assertion(search_result_->application != NULL);
	assertion(search_result_->application_was_moved ==
			AMARA_BOOLEAN_FALSE);

	rtg_applications_simple_list_find_by_name_ret_destructor(
			search_result_);
	amara_string_destructor(needle_);
	rtg_application_destructor(application_);
	rtg_applications_simple_list_destructor(haystack_);
}

/**  Search for an application that does not exist in the list, and the
 * list has only one element. */
void
rtg_applications_simple_list_find_by_name_test_3()
{
	rtg_applications_simple_list * haystack_;
	rtg_application * application_;
	amara_string * needle_;
	rtg_applications_simple_list_find_by_name_ret * search_result_;

	haystack_ = rtg_applications_simple_list_default_constructor();
	assertion(haystack_ != NULL);
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);

	application_ = rtg_application_example_cli_app_print_foo();
	assertion(application_ != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);

	haystack_ = rtg_applications_simple_list_push_front(
			haystack_, application_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
	assertion(haystack_->next == NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);

	needle_ = amara_string_exhaustive_constructor("foo");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_applications_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
	assertion(haystack_->next == NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND);
	assertion(search_result_->application == NULL);
	assertion(search_result_->application_was_moved ==
			AMARA_BOOLEAN_FALSE);

	rtg_applications_simple_list_find_by_name_ret_destructor(
			search_result_);
	amara_string_destructor(needle_);
	rtg_application_destructor(application_);
	rtg_applications_simple_list_destructor(haystack_);
}

/**  Search for an application that exists, and is the second element,
 * **not the first one**, in the haystack list. */
void
rtg_applications_simple_list_find_by_name_test_4()
{
	rtg_applications_simple_list * haystack_;
	rtg_application * application_zero_;
	rtg_application * application_one_;
	amara_string * needle_;
	rtg_applications_simple_list_find_by_name_ret * search_result_;

	haystack_ = rtg_applications_simple_list_default_constructor();
	assertion(haystack_ != NULL);
	assertion(haystack_->first == NULL);
	assertion(haystack_->next == NULL);

	application_zero_ = rtg_application_example_cli_app_print_bar();
	assertion(application_zero_ != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			application_zero_);

	haystack_ = rtg_applications_simple_list_push_front(
			haystack_, application_zero_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			haystack_->first);
	assertion(haystack_->next == NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			application_zero_);

	application_one_ = rtg_application_example_cli_app_print_foo();
	assertion(application_one_ != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_one_);

	haystack_ = rtg_applications_simple_list_push_front(
			haystack_, application_one_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
	assertion(haystack_->next != NULL);
	assertion(haystack_->next->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			haystack_->next->first);
	assertion(haystack_->next->next == NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_one_);

	needle_ = amara_string_exhaustive_constructor("cli_app_print_bar");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_applications_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
	assertion(haystack_->next != NULL);
	assertion(haystack_->next->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			haystack_->next->first);
	assertion(haystack_->next->next == NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS);
	assertion(search_result_->application != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			search_result_->application);
	assertion(search_result_->application_was_moved ==
			AMARA_BOOLEAN_FALSE);

	rtg_applications_simple_list_find_by_name_ret_destructor(
			search_result_);
	amara_string_destructor(needle_);
	rtg_application_destructor(application_one_);
	rtg_application_destructor(application_zero_);
	rtg_applications_simple_list_destructor(haystack_);
}

void
rtg_applications_simple_list_find_by_name_tests()
{
	rtg_applications_simple_list_find_by_name_test_0();
	rtg_applications_simple_list_find_by_name_test_1();
	rtg_applications_simple_list_find_by_name_test_2();
	rtg_applications_simple_list_find_by_name_test_3();
	rtg_applications_simple_list_find_by_name_test_4();
}

void
rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_test_0()
{
	stt_applications_simple_list * stt_applications_;
	rtg_named_functions_simple_list * rtg_functions_;
	rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret * target_ret_;

	stt_applications_ = stt_applications_simple_list_default_constructor();
	assertion(stt_applications_ != NULL);
	assertion(stt_applications_->first == NULL);
	assertion(stt_applications_->next == NULL);

	rtg_functions_ = NULL;

	target_ret_ = rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list(
			stt_applications_, rtg_functions_);
	assertion(stt_applications_->first == NULL);
	assertion(stt_applications_->next == NULL);
	assertion(target_ret_ != NULL);
	assertion(target_ret_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID);
	assertion(target_ret_->applications == NULL);
	/*
	assertion(target_ret_->applications_were_moved == AMARA_BOOLEAN_FALSE);
	*/

	/*
	rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret_destructor(
			target_ret_);
	*/
	free(target_ret_);

	stt_applications_simple_list_destructor(stt_applications_);
}

void
rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_tests()
{
	rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_test_0();
}

void
rtg_applications_simple_list_tests()
{
	rtg_applications_simple_list_construct_and_destruct_tests();
	rtg_applications_simple_list_find_by_name_tests();
	rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_tests();
}
