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
 * src/rtg/rtg_applications_simple_list_tests.c: Test the Amara run time
 * graph applications simple list.
 */

#include "../asr/assertion.h"

#include "../stt/stt_applications_simple_list_tests.h"

#include "../stt/stt_node_tests.h"

#include "rtg_application_tests.h"

#include "rtg_applications_simple_list.h"

#include "rtg_applications_simple_list_tests.h"

#include "rtg_named_functions_simple_list_tests.h"

#ifndef NDEBUG

void
assert_expectations_on_rtg_applications_simple_list_example_two_applications(
		const rtg_applications_simple_list * list)
{
	assertion(list != NULL);
	assertion(list->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			list->first);
	assertion(list->next != NULL);
	assertion(list->next->first != NULL);
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			list->next->first);
	assertion(list->next->next == NULL);
}

#endif

void
rtg_applications_simple_list_default_constructor_test()
{
	rtg_applications_simple_list * applications_list_;

	applications_list_ =
			rtg_applications_simple_list_default_constructor();
	forced_assertion(applications_list_ != NULL);
#ifndef NDEBUG
	assertion(applications_list_->first == NULL);
	assertion(applications_list_->next == NULL);
#endif

	rtg_applications_simple_list_destructor(applications_list_);
}

void
rtg_applications_simple_list_copy_constructor_test_0()
{
	rtg_applications_simple_list * applications_list_zero_;
	rtg_applications_simple_list * applications_list_one_;

	applications_list_zero_ =
			rtg_applications_simple_list_default_constructor();
	forced_assertion(applications_list_zero_ != NULL);
#ifndef NDEBUG
	assertion(applications_list_zero_->first == NULL);
	assertion(applications_list_zero_->next == NULL);
#endif

	applications_list_one_ = rtg_applications_simple_list_copy_constructor(
			applications_list_zero_);
#ifndef NDEBUG
	assertion(applications_list_zero_->first == NULL);
	assertion(applications_list_zero_->next == NULL);
#endif
	forced_assertion(applications_list_one_ != NULL);
#ifndef NDEBUG
	assertion(applications_list_one_->first == NULL);
	assertion(applications_list_one_->next == NULL);
#endif

	rtg_applications_simple_list_destructor(applications_list_one_);
	rtg_applications_simple_list_destructor(applications_list_zero_);
}

void
rtg_applications_simple_list_copy_constructor_test_1()
{
	rtg_applications_simple_list * applications_list_zero_;
	rtg_applications_simple_list * applications_list_one_;
	rtg_application * application_zero_;

	applications_list_zero_ =
			rtg_applications_simple_list_default_constructor();
	forced_assertion(applications_list_zero_ != NULL);
#ifndef NDEBUG
	assertion(applications_list_zero_->first == NULL);
	assertion(applications_list_zero_->next == NULL);
#endif

	application_zero_ = rtg_application_example_cli_app_print_foo();
	forced_assertion(application_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_zero_);
#endif

	applications_list_zero_ = rtg_applications_simple_list_push_front(
			applications_list_zero_, application_zero_);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_zero_);
#endif
	forced_assertion(applications_list_zero_ != NULL);
	forced_assertion(applications_list_zero_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			applications_list_zero_->first);
	assertion(applications_list_zero_->next == NULL);
#endif

	rtg_application_destructor(application_zero_);

	applications_list_one_ = rtg_applications_simple_list_copy_constructor(
			applications_list_zero_);
	forced_assertion(applications_list_zero_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			applications_list_zero_->first);
	assertion(applications_list_zero_->next == NULL);
#endif
	forced_assertion(applications_list_one_ != NULL);
	forced_assertion(applications_list_one_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			applications_list_one_->first);
	assertion(applications_list_one_->next == NULL);
#endif

	rtg_applications_simple_list_destructor(applications_list_one_);
	rtg_applications_simple_list_destructor(applications_list_zero_);
}

void
rtg_applications_simple_list_copy_constructor_test_2()
{
	rtg_applications_simple_list * applications_list_zero_;
	rtg_applications_simple_list * applications_list_one_;
	rtg_application * application_zero_;
	rtg_application * application_one_;

	applications_list_zero_ =
			rtg_applications_simple_list_default_constructor();
	forced_assertion(applications_list_zero_ != NULL);
#ifndef NDEBUG
	assertion(applications_list_zero_->first == NULL);
	assertion(applications_list_zero_->next == NULL);
#endif

	application_zero_ = rtg_application_example_cli_app_print_foo();
	forced_assertion(application_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_zero_);
#endif

	applications_list_zero_ = rtg_applications_simple_list_push_front(
			applications_list_zero_, application_zero_);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_zero_);
#endif
	forced_assertion(applications_list_zero_ != NULL);
	forced_assertion(applications_list_zero_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_zero_);
	assertion(applications_list_zero_->next == NULL);
#endif

	rtg_application_destructor(application_zero_);

	application_one_ = rtg_application_example_cli_app_print_bar();
	forced_assertion(application_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			application_one_);
#endif

	applications_list_zero_ = rtg_applications_simple_list_push_front(
			applications_list_zero_, application_one_);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			application_one_);
#endif
	forced_assertion(applications_list_zero_ != NULL);
	forced_assertion(applications_list_zero_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			applications_list_zero_->first);
#endif
	forced_assertion(applications_list_zero_->next != NULL);
	forced_assertion(applications_list_zero_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			applications_list_zero_->next->first);
	assertion(applications_list_zero_->next->next == NULL);
#endif

	rtg_application_destructor(application_one_);

	applications_list_one_ = rtg_applications_simple_list_copy_constructor(
			applications_list_zero_);
	forced_assertion(applications_list_zero_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			applications_list_zero_->first);
#endif
	forced_assertion(applications_list_zero_->next != NULL);
	forced_assertion(applications_list_zero_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			applications_list_zero_->next->first);
	assertion(applications_list_zero_->next->next == NULL);
#endif
	forced_assertion(applications_list_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			applications_list_one_->first);
#endif
	forced_assertion(applications_list_one_->next != NULL);
	forced_assertion(applications_list_one_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			applications_list_one_->next->first);
	assertion(applications_list_one_->next->next == NULL);
#endif

	rtg_applications_simple_list_destructor(applications_list_one_);
	rtg_applications_simple_list_destructor(applications_list_zero_);
}

void
rtg_applications_simple_list_copy_constructor_tests()
{
	rtg_applications_simple_list_copy_constructor_test_0();
	rtg_applications_simple_list_copy_constructor_test_1();
	rtg_applications_simple_list_copy_constructor_test_2();
}

void
rtg_applications_simple_list_transformation_constructor_test_0()
{
	stt_applications_simple_list * stt_applications_;
	rtg_named_functions_simple_list * rtg_functions_;
	rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret * target_ret_;

	stt_applications_ = stt_applications_simple_list_default_constructor();
	forced_assertion(stt_applications_ != NULL);
#ifndef NDEBUG
	assertion(stt_applications_->first == NULL);
	assertion(stt_applications_->next == NULL);
#endif

	rtg_functions_ = NULL;

	target_ret_ = rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list(
			stt_applications_, rtg_functions_);
#ifndef NDEBUG
	assertion(stt_applications_->first == NULL);
	assertion(stt_applications_->next == NULL);
#endif
	forced_assertion(target_ret_ != NULL);
#ifndef NDEBUG
	assertion(target_ret_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
#endif
	forced_assertion(target_ret_->applications == NULL);
#ifndef NDEBUG
	/*
	assertion(target_ret_->applications_were_moved == AMARA_BOOLEAN_FALSE);
	*/
#endif

	/*
	rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret_destructor(
			target_ret_);
	*/
	free(target_ret_);

	stt_applications_simple_list_destructor(stt_applications_);
}

void
rtg_applications_simple_list_transformation_constructor_test_1()
{
	stt_applications_simple_list * stt_applications_;
	rtg_named_functions_simple_list * rtg_named_functions_;
	rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret * target_ret_;

	stt_applications_ = stt_applications_simple_list_example_two_applications();
	forced_assertion(stt_applications_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_applications_simple_list_example_two_applications(
			stt_applications_);
#endif

	rtg_named_functions_ = rtg_named_functions_simple_list_example_two_named_functions();
	forced_assertion(rtg_named_functions_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_functions_simple_list_example_two_named_functions(
			rtg_named_functions_);
#endif

	target_ret_ = rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list(
			stt_applications_, rtg_named_functions_);
#ifndef NDEBUG
	assert_expectations_on_stt_applications_simple_list_example_two_applications(
			stt_applications_);
#endif
	forced_assertion(target_ret_ != NULL);
#ifndef NDEBUG
	assertion(target_ret_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
#endif
	forced_assertion(target_ret_->applications != NULL);
#ifndef NDEBUG
	/*
	assertion(target_ret_->applications_were_moved == AMARA_BOOLEAN_FALSE);
	*/
	assert_expectations_on_rtg_applications_simple_list_example_two_applications(
			target_ret_->applications);
#endif

#ifndef NDEBUG
	assertion(target_ret_->error_messages == NULL);
#endif
	rtg_applications_simple_list_destructor(target_ret_->applications);
	/*
	rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret_destructor(
			target_ret_);
	*/
	free(target_ret_);

	rtg_named_functions_simple_list_destructor(rtg_named_functions_);

	stt_applications_simple_list_destructor(stt_applications_);
}

void
rtg_applications_simple_list_transformation_constructor_test_2()
{
	stt_node * stt_doc_node_;
	stt_doc_subnode * stt_doc_subnode_;
	rtg_named_functions_out_of_stt_doc_ret * rtg_named_functions_out_of_stt_doc_ret_;
	rtg_named_functions_simple_list * rtg_named_functions_;
	rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * rtg_applications_out_of_stt_doc_and_rtg_named_functions_ret_;

	stt_doc_node_ = stt_node_example_doc_two();
	forced_assertion(stt_doc_node_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_doc_two(stt_doc_node_);
#endif

	forced_assertion(stt_doc_node_->type_ == STT_NODE_TYPE_DOC);
	forced_assertion(stt_doc_node_->doc_subnode_ != NULL);

	stt_doc_subnode_ = stt_doc_subnode_copy_constructor(
			stt_doc_node_->doc_subnode_);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_doc_two(stt_doc_node_);
#endif
	/* TODO missing assertions? */

	stt_node_destructor(stt_doc_node_);

	rtg_named_functions_out_of_stt_doc_ret_ =
			rtg_named_functions_out_of_stt_doc(stt_doc_subnode_);
	forced_assertion(rtg_named_functions_out_of_stt_doc_ret_ != NULL);
#ifndef NDEBUG
	assertion(rtg_named_functions_out_of_stt_doc_ret_->error_messages ==
			NULL);
#endif
	forced_assertion(rtg_named_functions_out_of_stt_doc_ret_->named_functions !=
			NULL);
#ifndef NDEBUG
	assertion(rtg_named_functions_out_of_stt_doc_ret_->named_functions->first ==
			NULL);
	assertion(rtg_named_functions_out_of_stt_doc_ret_->named_functions->next ==
			NULL);
#endif

	rtg_named_functions_ = rtg_named_functions_out_of_stt_doc_ret_->named_functions;
	forced_assertion(rtg_named_functions_ != NULL);
#ifndef NDEBUG
	/* TODO missing assertions? */
#endif
	rtg_named_functions_out_of_stt_doc_ret_->named_functions = NULL;

	rtg_named_functions_out_of_stt_doc_ret_destructor(
			rtg_named_functions_out_of_stt_doc_ret_);

	rtg_applications_out_of_stt_doc_and_rtg_named_functions_ret_ =
			rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list(
					stt_doc_subnode_,
					rtg_named_functions_);
#ifndef NDEBUG
	/* TODO missing assertions? */
#endif
	forced_assertion(rtg_applications_out_of_stt_doc_and_rtg_named_functions_ret_ !=
			NULL);
#ifndef NDEBUG
	assertion(rtg_applications_out_of_stt_doc_and_rtg_named_functions_ret_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_FIND_ENTRY_POINT_FUNCTION_FOR_AT_LEAST_ONE_APPLICATION);
	assertion(rtg_applications_out_of_stt_doc_and_rtg_named_functions_ret_->applications ==
			NULL);
#endif

	stt_doc_subnode_destructor(stt_doc_subnode_);

	rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_destructor(
			rtg_applications_out_of_stt_doc_and_rtg_named_functions_ret_);

	rtg_named_functions_simple_list_destructor(rtg_named_functions_);
}

void
rtg_applications_simple_list_transformation_constructor_tests()
{
	rtg_applications_simple_list_transformation_constructor_test_0();
	rtg_applications_simple_list_transformation_constructor_test_1();
	rtg_applications_simple_list_transformation_constructor_test_2();
}

void
rtg_applications_simple_list_constructors_tests()
{
	rtg_applications_simple_list_default_constructor_test();
	rtg_applications_simple_list_copy_constructor_tests();
	rtg_applications_simple_list_transformation_constructor_tests();
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
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);
#endif

	haystack_ = rtg_applications_simple_list_push_front(
			haystack_, application_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
#endif
	assertion(haystack_->next == NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);
#endif

	needle_ = amara_string_exhaustive_constructor("cli_app_print_foo");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_applications_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
#endif
	assertion(haystack_->next == NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_FOUND);
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
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);
#endif

	haystack_ = rtg_applications_simple_list_push_front(
			haystack_, application_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
#endif
	assertion(haystack_->next == NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);
#endif

	needle_ = amara_string_exhaustive_constructor("cli_app_print_foo");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_applications_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
#endif
	assertion(haystack_->next == NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_FOUND);
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
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);
#endif

	haystack_ = rtg_applications_simple_list_push_front(
			haystack_, application_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
#endif
	assertion(haystack_->next == NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_);
#endif

	needle_ = amara_string_exhaustive_constructor("foo");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_applications_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
#endif
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
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			application_zero_);
#endif

	haystack_ = rtg_applications_simple_list_push_front(
			haystack_, application_zero_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			haystack_->first);
#endif
	assertion(haystack_->next == NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			application_zero_);
#endif

	application_one_ = rtg_application_example_cli_app_print_foo();
	assertion(application_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_one_);
#endif

	haystack_ = rtg_applications_simple_list_push_front(
			haystack_, application_one_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
#endif
	assertion(haystack_->next != NULL);
	assertion(haystack_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			haystack_->next->first);
#endif
	assertion(haystack_->next->next == NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			application_one_);
#endif

	needle_ = amara_string_exhaustive_constructor("cli_app_print_bar");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_applications_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_foo(
			haystack_->first);
#endif
	assertion(haystack_->next != NULL);
	assertion(haystack_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			haystack_->next->first);
#endif
	assertion(haystack_->next->next == NULL);
	assertion(needle_->value_ != NULL);
	assertion(search_result_ != NULL);
	assertion(search_result_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_FOUND);
	assertion(search_result_->application != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_application_example_cli_app_print_bar(
			search_result_->application);
#endif
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
rtg_applications_simple_list_tests()
{
	rtg_applications_simple_list_constructors_tests();
	rtg_applications_simple_list_find_by_name_tests();
}
