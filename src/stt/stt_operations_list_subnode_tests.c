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
 * src/stt/stt_operations_list_subnode_tests.c: Test the Amara syntax
 * tree application function operations list subnode.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "stt_operation_tests.h"
/*   For `stt_operations_list_subnode`. */
 #include "stt_operations_list_subnode.h"

#include "stt_operations_list_subnode_tests.h"

stt_operations_list_subnode *
stt_operations_list_subnode_example_print_foo()
{
	stt_operations_list_subnode * subnode_;
	stt_operations_simple_list * operations_;
	stt_operation * operation_;

	operation_ = stt_operation_example_print_string_literal_foo();
	forced_assertion(operation_ != NULL);
	/* TODO add missing assertions. */

	operations_ = stt_operations_simple_list_default_constructor();
	forced_assertion(operations_ != NULL);
#ifndef NDEBUG
	assertion(operations_->first == NULL);
	assertion(operations_->next == NULL);
#endif

	operations_ = stt_operations_simple_list_push_front(
			operations_, operation_);
	forced_assertion(operations_ != NULL);
	forced_assertion(operations_->first != NULL);
#ifndef NDEBUG
	assertion(operations_->next == NULL);
#endif

	subnode_ = stt_operations_list_subnode_default_constructor();
	forced_assertion(subnode_ != NULL);
#ifndef NDEBUG
	/* assertion(subnode_->type_ == STT_OPERATIONS_LIST_SUBNODE_TYPE_INVALID); */
	assertion(subnode_->operations_ == NULL);
#endif

	subnode_->operations_ =
			stt_operations_simple_list_copy_constructor(
					operations_);
	forced_assertion(subnode_->operations_ != NULL);
	forced_assertion(subnode_->operations_->first != NULL);
#ifndef NDEBUG
	assertion(subnode_->operations_->next == NULL);
#endif

	/* stt_operations_list_subnode_destructor(subnode_); */
	stt_operations_simple_list_destructor(operations_);
	stt_operation_destructor(operation_);

	return subnode_;
}

void
stt_operations_list_subnode_construct_and_destruct_test_0()
{
	stt_operations_list_subnode * subnode_;

	subnode_ = stt_operations_list_subnode_default_constructor();
	forced_assertion(subnode_ != NULL);
#ifndef NDEBUG
	assertion(subnode_->operations_ == NULL);
#endif

	stt_operations_list_subnode_destructor(subnode_);
}

void
stt_operations_list_subnode_construct_and_destruct_test_1()
{
	stt_operations_list_subnode * subnode_zero_;
	stt_operations_list_subnode * subnode_one_;

	subnode_zero_ = stt_operations_list_subnode_example_print_foo();
	forced_assertion(subnode_zero_ != NULL);
	forced_assertion(subnode_zero_->operations_ != NULL);
	assertion(subnode_zero_->operations_->first != NULL);
#ifndef NDEBUG
	assertion(subnode_zero_->operations_->next == NULL);
#endif

	subnode_one_ = stt_operations_list_subnode_copy_constructor(
			subnode_zero_);
	forced_assertion(subnode_one_ != NULL);
	forced_assertion(subnode_one_->operations_ != NULL);
	forced_assertion(subnode_one_->operations_->first != NULL);
#ifndef NDEBUG
	assertion(subnode_one_->operations_->next == NULL);
#endif

	stt_operations_list_subnode_destructor(subnode_one_);
	stt_operations_list_subnode_destructor(subnode_zero_);
}

void
stt_operations_list_subnode_construct_and_destruct_tests()
{
	stt_operations_list_subnode_construct_and_destruct_test_0();
	stt_operations_list_subnode_construct_and_destruct_test_1();
}

void
stt_operations_list_subnode_tests()
{
	stt_operations_list_subnode_construct_and_destruct_tests();
}
