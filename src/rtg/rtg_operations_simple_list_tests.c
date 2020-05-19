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
 * src/rtg/rtg_operations_simple_list_tests.c: Test the Amara runtime
 * graph application function operations simple list.
 */

#include "../asr/assertion.h"

#include "../cmn/amara_string_tests.h"

#include "rtg_operation_tests.h"

#include "rtg_operations_simple_list.h"

#include "rtg_operations_simple_list_tests.h"

#ifndef NDEBUG

void
assert_expectations_on_rtg_operations_simple_list_example_print_identifier_foo(
		const rtg_operations_simple_list * list)
{
	assertion(list != NULL);
	assertion(list->first != NULL);
	assert_expectations_on_rtg_operation_example_print_identifier_foo(
			list->first);
	assertion(list->next == NULL);
}

#endif

void
rtg_operations_simple_list_copy_constructor_test_0()
{
	rtg_operations_simple_list * operations_zero_;
	rtg_operations_simple_list * operations_one_;

	operations_zero_ = rtg_operations_simple_list_default_constructor();
	forced_assertion(operations_zero_ != NULL);
	forced_assertion(operations_zero_->first == NULL);
	forced_assertion(operations_zero_->next == NULL);

	operations_one_ = rtg_operations_simple_list_copy_constructor(
			operations_zero_);
	forced_assertion(operations_zero_->first == NULL);
	forced_assertion(operations_zero_->next == NULL);
	forced_assertion(operations_one_ != NULL);
	forced_assertion(operations_one_->first == NULL);
	forced_assertion(operations_one_->next == NULL);

	rtg_operations_simple_list_destructor(operations_zero_);

	rtg_operations_simple_list_destructor(operations_one_);
}

void
rtg_operations_simple_list_copy_constructor_test_1()
{
	rtg_operations_simple_list * operations_zero_;
	amara_string * amara_string_foo_;
	rtg_operation * operation_zero_;
	rtg_operations_simple_list * operations_one_;

	operations_zero_ = rtg_operations_simple_list_default_constructor();
	forced_assertion(operations_zero_ != NULL);
	forced_assertion(operations_zero_->first == NULL);
	forced_assertion(operations_zero_->next == NULL);

	amara_string_foo_ = amara_string_example_foo();
	forced_assertion(amara_string_foo_ != NULL);
	forced_assertion(amara_string_foo_->value_ != NULL);

	operation_zero_ = rtg_operation_example_print_string_literal_foo();
	forced_assertion(operation_zero_ != NULL);
	/* XXX */
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_PRINT);
	/* XXX */
	assertion(operation_zero_->args_ != NULL);
	/* XXX */
	assertion(operation_zero_->args_->first != NULL);
	/* XXX */
	assertion(operation_zero_->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	/* XXX */
	assertion(operation_zero_->args_->first->string_literal_ != NULL);
	/* XXX */
	assertion(amara_string_equality(
			operation_zero_->args_->first->string_literal_,
			amara_string_foo_));
	/* XXX */
	assertion(operation_zero_->args_->next == NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_example_print_string_literal_foo(
			operation_zero_);
#endif

	operations_zero_ = rtg_operations_simple_list_push_front(
			operations_zero_, operation_zero_);
	forced_assertion(operations_zero_ != NULL);
	assertion(operations_zero_->first != NULL);
	assertion(operations_zero_->first->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operations_zero_->first->args_ != NULL);
	assertion(operations_zero_->first->args_->first != NULL);
	assertion(operations_zero_->first->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operations_zero_->first->args_->first->string_literal_ !=
			NULL);
	assertion(amara_string_equality(
			operations_zero_->first->args_->first->string_literal_,
			amara_string_foo_));
	assertion(operations_zero_->next == NULL);
	assertion(operation_zero_ != NULL);
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_PRINT);
	forced_assertion(operation_zero_->args_ != NULL);
	forced_assertion(operation_zero_->args_->first != NULL);
	assertion(operation_zero_->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	forced_assertion(operation_zero_->args_->first->string_literal_ != NULL);
	assertion(amara_string_equality(
			operation_zero_->args_->first->string_literal_,
			amara_string_foo_));
	assertion(operation_zero_->args_->next == NULL);

	rtg_operation_destructor(operation_zero_);

	operations_one_ = rtg_operations_simple_list_copy_constructor(
			operations_zero_);
	assertion(operations_zero_ != NULL);
	assertion(operations_zero_->first != NULL);
	assertion(operations_zero_->first->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operations_zero_->first->args_ != NULL);
	assertion(operations_zero_->first->args_->first != NULL);
	assertion(operations_zero_->first->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operations_zero_->first->args_->first->string_literal_ !=
			NULL);
	assertion(amara_string_equality(
			operations_zero_->first->args_->first->string_literal_,
			amara_string_foo_));
	assertion(operations_zero_->next == NULL);
	forced_assertion(operations_one_ != NULL);
	forced_assertion(operations_one_->first != NULL);
	assertion(operations_one_->first->type_ == RTG_OPERATION_TYPE_PRINT);
	forced_assertion(operations_one_->first->args_ != NULL);
	forced_assertion(operations_one_->first->args_->first != NULL);
	assertion(operations_one_->first->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	forced_assertion(operations_one_->first->args_->first->string_literal_ !=
			NULL);
	assertion(amara_string_equality(
			operations_one_->first->args_->first->string_literal_,
			amara_string_foo_));
	assertion(operations_one_->next == NULL);

	amara_string_destructor(amara_string_foo_);

	rtg_operations_simple_list_destructor(operations_one_);

	rtg_operations_simple_list_destructor(operations_zero_);
}

void
rtg_operations_simple_list_copy_constructor_test_2()
{
	rtg_operations_simple_list * operations_zero_;
	amara_string * amara_string_foo_;
	rtg_operation * operation_zero_;
	amara_string * amara_string_bar_;
	rtg_operation * operation_one_;
	rtg_operations_simple_list * operations_one_;

	operations_zero_ = rtg_operations_simple_list_default_constructor();
	forced_assertion(operations_zero_ != NULL);
	assertion(operations_zero_->first == NULL);
	assertion(operations_zero_->next == NULL);

	amara_string_foo_ = amara_string_example_foo();
	forced_assertion(amara_string_foo_ != NULL);
	/*
	assert_expectations_on_amara_string_example_foo(amara_string_foo_);
	*/

	operation_zero_ = rtg_operation_example_print_string_literal_foo();
	forced_assertion(operation_zero_ != NULL);
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_PRINT);
	forced_assertion(operation_zero_->args_ != NULL);
	forced_assertion(operation_zero_->args_->first != NULL);
	assertion(operation_zero_->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	forced_assertion(operation_zero_->args_->first->string_literal_ != NULL);
	assertion(amara_string_equality(
			operation_zero_->args_->first->string_literal_,
			amara_string_foo_));
	assertion(operation_zero_->args_->next == NULL);

	operations_zero_ = rtg_operations_simple_list_push_front(
			operations_zero_, operation_zero_);

	assertion(operations_zero_ != NULL);
	assertion(operations_zero_->first != NULL);
	assertion(operations_zero_->first->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operations_zero_->first->args_ != NULL);
	assertion(operations_zero_->first->args_->first != NULL);
	assertion(operations_zero_->first->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operations_zero_->first->args_->first->string_literal_ !=
			NULL);
	assertion(amara_string_equality(
			operations_zero_->first->args_->first->string_literal_,
			amara_string_foo_));
	assertion(operations_zero_->next == NULL);

	assertion(operation_zero_ != NULL);
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
	assertion(operation_zero_->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operation_zero_->args_->first->string_literal_ != NULL);
	assertion(amara_string_equality(
			operation_zero_->args_->first->string_literal_,
			amara_string_foo_));
	assertion(operation_zero_->args_->next == NULL);

	amara_string_destructor(amara_string_foo_);

	rtg_operation_destructor(operation_zero_);

	amara_string_bar_ = amara_string_example_bar();
	forced_assertion(amara_string_bar_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_bar(amara_string_bar_);
#endif

	operation_one_ = rtg_operation_example_print_string_literal_bar();

	assertion(operation_one_ != NULL);
	assertion(operation_one_->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operation_one_->args_ != NULL);
	assertion(operation_one_->args_->first != NULL);
	assertion(operation_one_->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operation_one_->args_->first->string_literal_ != NULL);
	assertion(amara_string_equality(
			operation_one_->args_->first->string_literal_,
			amara_string_bar_));
	assertion(operation_one_->args_->next == NULL);

	operations_zero_ = rtg_operations_simple_list_push_front(
			operations_zero_, operation_one_);

	assertion(operation_one_ != NULL);
	assertion(operation_one_->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operation_one_->args_ != NULL);
	assertion(operation_one_->args_->first != NULL);
	assertion(operation_one_->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operation_one_->args_->first->string_literal_ != NULL);
	assertion(amara_string_equality(
			operation_one_->args_->first->string_literal_,
			amara_string_bar_));
	assertion(operation_one_->args_->next == NULL);

	rtg_operation_destructor(operation_one_);

	operations_one_ = rtg_operations_simple_list_copy_constructor(
			operations_zero_);

	assertion(operations_zero_ != NULL);
	assertion(operations_zero_->first != NULL);
	assertion(operations_zero_->first->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operations_zero_->first->args_ != NULL);
	assertion(operations_zero_->first->args_->first != NULL);
	assertion(operations_zero_->first->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operations_zero_->first->args_->first->string_literal_ !=
			NULL);
	assertion(amara_string_equality(
			operations_zero_->first->args_->first->string_literal_,
			amara_string_bar_));
	assertion(operations_zero_->next != NULL);

	assertion(operations_one_ != NULL);
	assertion(operations_one_->first != NULL);
	assertion(operations_one_->first->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operations_one_->first->args_ != NULL);
	assertion(operations_one_->first->args_->first != NULL);
	assertion(operations_one_->first->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operations_one_->first->args_->first->string_literal_ !=
			NULL);
	assertion(amara_string_equality(
			operations_one_->first->args_->first->string_literal_,
			amara_string_bar_));
	assertion(operations_one_->next != NULL);

	amara_string_destructor(amara_string_bar_);

	rtg_operations_simple_list_destructor(operations_one_);

	rtg_operations_simple_list_destructor(operations_zero_);
}

void
rtg_operations_simple_list_copy_constructor_tests()
{
	rtg_operations_simple_list_copy_constructor_test_0();
	rtg_operations_simple_list_copy_constructor_test_1();
	rtg_operations_simple_list_copy_constructor_test_2();
}

tests_simple_list *
register_rtg_operations_simple_list_copy_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_operations_simple_list_copy_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& rtg_operations_simple_list_copy_constructor_test_0);
	tests_simple_list_push_back(
			tests,
			& rtg_operations_simple_list_copy_constructor_test_1);
	tests_simple_list_push_back(
			tests,
			& rtg_operations_simple_list_copy_constructor_test_2);
	return tests;
}

void
rtg_operations_simple_list_transformation_constructor_test_0()
{
	stt_operations_simple_list * stt_operations_;
	rtg_operations_simple_list_out_of_stt_operations_simple_list_and_stt_where_value_bindings_simple_list_and_rtg_named_functions_simple_list_ret * transformation_ret_;
	rtg_operations_simple_list * rtg_operations_;

	stt_operations_ = stt_operations_simple_list_default_constructor();
	forced_assertion(stt_operations_ != NULL);
#ifndef NDEBUG
	assertion(stt_operations_->first == NULL);
	assertion(stt_operations_->next == NULL);
#endif

	transformation_ret_ = rtg_operations_simple_list_out_of_stt_operations_simple_list_and_stt_where_value_bindings_simple_list_and_rtg_named_functions_simple_list(stt_operations_, NULL, NULL);
#ifndef NDEBUG
	assertion(stt_operations_->first == NULL);
	assertion(stt_operations_->next == NULL);
#endif
	forced_assertion(transformation_ret_ != NULL);
	forced_assertion(transformation_ret_->status ==
			RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_AND_STT_WHERE_VALUE_BINDINGS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	forced_assertion(transformation_ret_->operations != NULL);
#ifndef NDEBUG
	assertion(transformation_ret_->operations->first == NULL);
	assertion(transformation_ret_->operations->next == NULL);
#endif

	stt_operations_simple_list_destructor(stt_operations_);

	rtg_operations_ = transformation_ret_->operations;
	transformation_ret_->operations = NULL;

	free(transformation_ret_);
	rtg_operations_simple_list_destructor(rtg_operations_);
}

void
rtg_operations_simple_list_transformation_constructor_test_1()
{
	rtg_operations_simple_list_out_of_stt_operations_simple_list_and_stt_where_value_bindings_simple_list_and_rtg_named_functions_simple_list_ret * transformation_ret_;
	rtg_operations_simple_list * rtg_operations_;

	transformation_ret_ = rtg_operations_simple_list_out_of_stt_operations_simple_list_and_stt_where_value_bindings_simple_list_and_rtg_named_functions_simple_list(NULL, NULL, NULL);
	forced_assertion(transformation_ret_ != NULL);
	forced_assertion(transformation_ret_->status ==
			RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_AND_STT_WHERE_VALUE_BINDINGS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	forced_assertion(transformation_ret_->operations != NULL);
#ifndef NDEBUG
	assertion(transformation_ret_->operations->first == NULL);
	assertion(transformation_ret_->operations->next == NULL);
#endif

	rtg_operations_ = transformation_ret_->operations;
	transformation_ret_->operations = NULL;

	free(transformation_ret_);
	rtg_operations_simple_list_destructor(rtg_operations_);
}

void
rtg_operations_simple_list_transformation_constructor_tests()
{
	rtg_operations_simple_list_transformation_constructor_test_0();
	rtg_operations_simple_list_transformation_constructor_test_1();
}

tests_simple_list *
register_rtg_operations_simple_list_transformation_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_operations_simple_list_transformation_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& rtg_operations_simple_list_transformation_constructor_test_0);
	tests_simple_list_push_back(
			tests,
			& rtg_operations_simple_list_transformation_constructor_test_1);
	return tests;
}

void
rtg_operations_simple_list_tests()
{
	rtg_operations_simple_list_copy_constructor_tests();
	rtg_operations_simple_list_transformation_constructor_tests();
}

tests_simple_list *
register_rtg_operations_simple_list_tests(tests_simple_list * tests)
{
	return register_rtg_operations_simple_list_transformation_constructor_tests(
	       register_rtg_operations_simple_list_copy_constructor_tests(
	               tests));
}
