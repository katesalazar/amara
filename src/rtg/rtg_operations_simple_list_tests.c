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
 * src/rtg/rtg_operations_simple_list_tests.c: Test the Amara runtime
 * graph application function operations simple list.
 */

#include "../asr/assertion.h"

#include "rtg_operation_tests.h"

#include "rtg_operations_simple_list.h"

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

	assertion(operations_zero_ != NULL);
	assertion(operations_zero_->first == NULL);
	assertion(operations_zero_->next == NULL);

	operations_one_ = rtg_operations_simple_list_copy_constructor(
			operations_zero_);

	assertion(operations_zero_->first == NULL);
	assertion(operations_zero_->next == NULL);

	assertion(operations_one_ != NULL);
	assertion(operations_one_->first == NULL);
	assertion(operations_one_->next == NULL);

	rtg_operations_simple_list_destructor(operations_one_);

	rtg_operations_simple_list_destructor(operations_zero_);
}

void
rtg_operations_simple_list_copy_constructor_test_1()
{
	rtg_operations_simple_list * operations_zero_;
	rtg_operations_simple_list * operations_one_;
	rtg_operation * operation_zero_;

	operations_zero_ = rtg_operations_simple_list_default_constructor();

	assertion(operations_zero_ != NULL);
	assertion(operations_zero_->first == NULL);
	assertion(operations_zero_->next == NULL);

	operation_zero_ = rtg_operation_example_print_string_literal_foo();

	assertion(operation_zero_ != NULL);
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
	assertion(operation_zero_->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operation_zero_->args_->first->string_literal_ != NULL);
	assertion(amara_string_equality(
			operation_zero_->args_->first->string_literal_,
			amara_string_exhaustive_constructor("foo")));
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
			amara_string_exhaustive_constructor("foo")));
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
			amara_string_exhaustive_constructor("foo")));
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
			amara_string_exhaustive_constructor("foo")));
	assertion(operations_zero_->next == NULL);

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
			amara_string_exhaustive_constructor("foo")));
	assertion(operations_one_->next == NULL);

	rtg_operations_simple_list_destructor(operations_one_);

	rtg_operations_simple_list_destructor(operations_zero_);
}

void
rtg_operations_simple_list_copy_constructor_test_2()
{
	rtg_operations_simple_list * operations_zero_;
	rtg_operations_simple_list * operations_one_;
	rtg_operation * operation_zero_;
	rtg_operation * operation_one_;

	operations_zero_ = rtg_operations_simple_list_default_constructor();

	assertion(operations_zero_ != NULL);
	assertion(operations_zero_->first == NULL);
	assertion(operations_zero_->next == NULL);

	operation_zero_ = rtg_operation_example_print_string_literal_foo();

	assertion(operation_zero_ != NULL);
	assertion(operation_zero_->type_ == RTG_OPERATION_TYPE_PRINT);
	assertion(operation_zero_->args_ != NULL);
	assertion(operation_zero_->args_->first != NULL);
	assertion(operation_zero_->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(operation_zero_->args_->first->string_literal_ != NULL);
	assertion(amara_string_equality(
			operation_zero_->args_->first->string_literal_,
			amara_string_exhaustive_constructor("foo")));
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
			amara_string_exhaustive_constructor("foo")));
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
			amara_string_exhaustive_constructor("foo")));
	assertion(operation_zero_->args_->next == NULL);

	rtg_operation_destructor(operation_zero_);

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
			amara_string_exhaustive_constructor("bar")));
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
			amara_string_exhaustive_constructor("bar")));
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
			amara_string_exhaustive_constructor("bar")));
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
			amara_string_exhaustive_constructor("bar")));
	assertion(operations_one_->next != NULL);

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

void
rtg_operations_simple_list_transformation_constructor_test_0()
{
	stt_operations_simple_list * stt_operations_;
	rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * transformation_ret_;
	rtg_operations_simple_list * rtg_operations_;

	stt_operations_ = stt_operations_simple_list_default_constructor();
	forced_assertion(stt_operations_ != NULL);
#ifndef NDEBUG
	assertion(stt_operations_->first == NULL);
	assertion(stt_operations_->next == NULL);
#endif

	transformation_ret_ =
			rtg_operations_simple_list_out_of_stt_operations_simple_list(
					stt_operations_, NULL);
#ifndef NDEBUG
	assertion(stt_operations_->first == NULL);
	assertion(stt_operations_->next == NULL);
#endif
	forced_assertion(transformation_ret_ != NULL);
	forced_assertion(transformation_ret_->status ==
			RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
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
	rtg_operations_simple_list_out_of_stt_operations_simple_list_ret * transformation_ret_;
	rtg_operations_simple_list * rtg_operations_;

	transformation_ret_ =
			rtg_operations_simple_list_out_of_stt_operations_simple_list(
					NULL, NULL);
	forced_assertion(transformation_ret_ != NULL);
	forced_assertion(transformation_ret_->status ==
			RTG_OPERATIONS_SIMPLE_LIST_OUT_OF_STT_OPERATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
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

void
rtg_operations_simple_list_tests()
{
	rtg_operations_simple_list_copy_constructor_tests();
	rtg_operations_simple_list_transformation_constructor_tests();
}
