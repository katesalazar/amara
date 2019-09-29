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
 * src/rtg/rtg_named_functions_simple_list_tests.c: Test the Amara run
 * time graph application named functions simple list.
 */

#include "../asr/assertion.h"

#include "../stt/stt_doc_subnode_tests.h"

#include "../stt/stt_named_functions_simple_list_tests.h"

#include "rtg_named_function_tests.h"

#include "rtg_named_functions_simple_list.h"

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_example_two_named_functions()
{
	rtg_named_functions_simple_list * ret_;
	rtg_named_function * named_function_;

	ret_ = rtg_named_functions_simple_list_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->first == NULL);
	assertion(ret_->next == NULL);
#endif

	named_function_ = rtg_named_function_example_print_string_literal_bar();
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_bar(
			named_function_);
#endif

	ret_ = rtg_named_functions_simple_list_push_front(
			ret_, named_function_);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_bar(
			named_function_);
#endif
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_bar(
			ret_->first);
	assertion(ret_->next == NULL);
#endif

	rtg_named_function_destructor(named_function_);

	named_function_ = rtg_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	ret_ = rtg_named_functions_simple_list_push_front(
			ret_, named_function_);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			named_function_);
#endif
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			ret_->first);
#endif
	forced_assertion(ret_->next != NULL);
	forced_assertion(ret_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_bar(
			ret_->next->first);
	assertion(ret_->next->next == NULL);
#endif

	rtg_named_function_destructor(named_function_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_named_functions_simple_list_example_two_named_functions(
		const rtg_named_functions_simple_list * list)
{
	assertion(list != NULL);
	assertion(list->first != NULL);
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			list->first);
	assertion(list->next != NULL);
	assertion(list->next->first != NULL);
	assert_expectations_on_rtg_named_function_example_print_string_literal_bar(
			list->next->first);
	assertion(list->next->next == NULL);
}

#endif

#ifndef NDEBUG

void
assert_expectations_on_rtg_named_functions_simple_list_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
		const rtg_named_functions_simple_list * list)
{
	assertion(list != NULL);
	assertion(list->first != NULL);
	assert_expectations_on_rtg_named_function_example_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
			list->first);
	assertion(list->next == NULL);
}

#endif

void
rtg_named_functions_simple_list_default_constructor_test()
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
rtg_named_functions_simple_list_copy_constructor_test_0()
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
rtg_named_functions_simple_list_copy_constructor_test_1()
{
	rtg_named_functions_simple_list * named_functions_zero_;
	rtg_named_functions_simple_list * named_functions_one_;
	rtg_named_function * example_function_;

	named_functions_zero_ =
			rtg_named_functions_simple_list_default_constructor();
	assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first == NULL);
	assertion(named_functions_zero_->next == NULL);

	example_function_ =
			rtg_named_function_example_print_string_literal_foo();
	forced_assertion(example_function_ != NULL);
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
rtg_named_functions_simple_list_copy_constructor_test_2()
{
	rtg_named_functions_simple_list * named_functions_zero_;
	rtg_named_functions_simple_list * named_functions_one_;
	rtg_named_function * example_function_zero_;
	rtg_named_function * example_function_one_;

	named_functions_zero_ =
			rtg_named_functions_simple_list_default_constructor();
	forced_assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first == NULL);
	assertion(named_functions_zero_->next == NULL);

	example_function_zero_ =
			rtg_named_function_example_print_string_literal_foo();
	/* TODO add missing assertions. */

	named_functions_zero_ = rtg_named_functions_simple_list_push_front(
			named_functions_zero_, example_function_zero_);
	assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first != NULL);
	assertion(named_functions_zero_->next == NULL);
	/* TODO add missing assertions. */

	example_function_one_ =
			rtg_named_function_example_print_string_literal_bar();
	forced_assertion(example_function_one_ != NULL);
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
rtg_named_functions_simple_list_copy_constructor_tests()
{
	rtg_named_functions_simple_list_copy_constructor_test_0();
	rtg_named_functions_simple_list_copy_constructor_test_1();
	rtg_named_functions_simple_list_copy_constructor_test_2();
}

void
rtg_named_functions_simple_list_transformation_constructor_test_0()
{
	stt_named_functions_simple_list * stt_named_functions_;
	rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * transformation_ret_;
	rtg_named_functions_simple_list * rtg_named_functions_;

	stt_named_functions_ = NULL;

	transformation_ret_ =
			rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(
					stt_named_functions_);
	forced_assertion(transformation_ret_ != NULL);
#ifndef NDEBUG
	assertion(transformation_ret_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
#endif
	forced_assertion(transformation_ret_->named_functions != NULL);
#ifndef NDEBUG
	assertion(transformation_ret_->named_functions->first == NULL);
	assertion(transformation_ret_->named_functions->next == NULL);
#endif

	rtg_named_functions_ = transformation_ret_->named_functions;

	free(transformation_ret_);

	rtg_named_functions_simple_list_destructor(rtg_named_functions_);
}

void
rtg_named_functions_simple_list_transformation_constructor_test_1()
{
	stt_named_functions_simple_list * stt_named_functions_;
	rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * transformation_ret_;
	rtg_named_functions_simple_list * rtg_named_functions_;

	stt_named_functions_ = stt_named_functions_simple_list_example_two_named_functions();
	forced_assertion(stt_named_functions_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_functions_simple_list_example_two_named_functions(
			stt_named_functions_);
#endif

	transformation_ret_ =
			rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(
					stt_named_functions_);
#ifndef NDEBUG
	assert_expectations_on_stt_named_functions_simple_list_example_two_named_functions(
			stt_named_functions_);
#endif
	forced_assertion(transformation_ret_ != NULL);
#ifndef NDEBUG
	assertion(transformation_ret_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
#endif
	forced_assertion(transformation_ret_->named_functions != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_functions_simple_list_example_two_named_functions(
			transformation_ret_->named_functions);
#endif

	stt_named_functions_simple_list_destructor(stt_named_functions_);

	rtg_named_functions_ = transformation_ret_->named_functions;

	free(transformation_ret_);

	rtg_named_functions_simple_list_destructor(rtg_named_functions_);
}

void
rtg_named_functions_simple_list_transformation_constructor_test_2()
{
	stt_doc_subnode * stt_doc_subnode_;
	rtg_named_functions_out_of_stt_doc_ret * transformation_ret_;
	amara_string * expected_error_message_;
	amara_boolean equality_;

	stt_doc_subnode_ =
			stt_doc_subnode_example_one_invalid_named_function();
	forced_assertion(stt_doc_subnode_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_doc_subnode_example_one_invalid_named_function(
			stt_doc_subnode_);
#endif

	expected_error_message_ = amara_string_exhaustive_constructor(
			"unable to resolve identifier 'foo' in the function's where value bindings scope");
	forced_assertion(expected_error_message_ != NULL);

	transformation_ret_ =
			rtg_named_functions_out_of_stt_doc(stt_doc_subnode_);
#ifndef NDEBUG
	assert_expectations_on_stt_doc_subnode_example_one_invalid_named_function(
			stt_doc_subnode_);
#endif
	forced_assertion(transformation_ret_ != NULL);
	forced_assertion(transformation_ret_->status ==
			RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION);
	forced_assertion(transformation_ret_->error_messages != NULL);
	equality_ = amara_strings_equality(
			transformation_ret_->error_messages->first,
			expected_error_message_);
	forced_assertion(equality_ == AMARA_BOOLEAN_TRUE);
#ifndef NDEBUG
	assertion(transformation_ret_->named_functions == NULL);
#endif

	stt_doc_subnode_destructor(stt_doc_subnode_);
	amara_string_destructor(expected_error_message_);
	rtg_named_functions_out_of_stt_doc_ret_destructor(transformation_ret_);
}

void
rtg_named_functions_simple_list_transformation_constructor_test_3()
{
	stt_doc_subnode * stt_doc_subnode_;
	rtg_named_functions_out_of_stt_doc_ret * transformation_ret_;

	stt_doc_subnode_ =
			stt_doc_subnode_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo();
	forced_assertion(stt_doc_subnode_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_doc_subnode_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
			stt_doc_subnode_);
#endif

	transformation_ret_ =
			rtg_named_functions_out_of_stt_doc(stt_doc_subnode_);
#ifndef NDEBUG
	assert_expectations_on_stt_doc_subnode_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
			stt_doc_subnode_);
#endif
	forced_assertion(transformation_ret_ != NULL);
	forced_assertion(transformation_ret_->status ==
			RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS);
	forced_assertion(transformation_ret_->error_messages == NULL);
	forced_assertion(transformation_ret_->named_functions != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_functions_simple_list_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
			transformation_ret_->named_functions);
#endif

	stt_doc_subnode_destructor(stt_doc_subnode_);
	rtg_named_functions_out_of_stt_doc_ret_destructor(transformation_ret_);
}

void
rtg_named_functions_simple_list_transformation_constructor_tests()
{
	rtg_named_functions_simple_list_transformation_constructor_test_0();
	rtg_named_functions_simple_list_transformation_constructor_test_1();
	rtg_named_functions_simple_list_transformation_constructor_test_2();
	rtg_named_functions_simple_list_transformation_constructor_test_3();
}

void
rtg_named_functions_simple_list_constructors_tests()
{
	rtg_named_functions_simple_list_default_constructor_test();
	rtg_named_functions_simple_list_copy_constructor_tests();
	rtg_named_functions_simple_list_transformation_constructor_tests();
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

	named_function_ =
			rtg_named_function_example_print_string_literal_foo();
	assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	haystack_ = rtg_named_functions_simple_list_push_front(
			haystack_, named_function_);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			haystack_->first);
#endif
	assertion(haystack_->next == NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			named_function_);
#endif

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

	named_function_ =
			rtg_named_function_example_print_string_literal_foo();
	assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	haystack_ = rtg_named_functions_simple_list_push_front(
			haystack_, named_function_);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			haystack_->first);
#endif
	assertion(haystack_->next == NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			named_function_);
#endif

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

	named_function_ =
			rtg_named_function_example_print_string_literal_foo();
	assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			named_function_);
#endif

	haystack_ = rtg_named_functions_simple_list_push_front(
			haystack_, named_function_);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			haystack_->first);
#endif
	assertion(haystack_->next == NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			named_function_);
#endif

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

	named_function_zero_ =
			rtg_named_function_example_print_string_literal_foo();
	assertion(named_function_zero_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			named_function_zero_);
#endif

	haystack_ = rtg_named_functions_simple_list_push_front(
			haystack_, named_function_zero_);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			haystack_->first);
#endif
	assertion(haystack_->next == NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			named_function_zero_);
#endif

	named_function_one_ =
			rtg_named_function_example_print_string_literal_bar();
	assertion(named_function_one_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_bar(
			named_function_one_);
#endif

	haystack_ = rtg_named_functions_simple_list_push_front(
			haystack_, named_function_one_);
	assertion(haystack_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_bar(
			haystack_->first);
#endif
	assertion(haystack_->next != NULL);
	assertion(haystack_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			haystack_->next->first);
#endif
	assertion(haystack_->next->next == NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_bar(
			named_function_one_);
#endif

	needle_ = amara_string_exhaustive_constructor("print_foo");
	assertion(needle_ != NULL);
	assertion(needle_->value_ != NULL);

	search_result_ = rtg_named_functions_simple_list_find_by_name(
			haystack_, needle_);
	assertion(haystack_ != NULL);
	assertion(haystack_->first != NULL);
	assertion(haystack_->next != NULL);
	assertion(haystack_->next->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
			haystack_->next->first);
#endif
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
	rtg_named_functions_simple_list_constructors_tests();
	rtg_named_functions_simple_list_find_by_name_tests();
}
