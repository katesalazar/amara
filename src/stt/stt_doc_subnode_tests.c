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
 * src/stt/stt_doc_subnode_tests.c: Test the Amara syntax tree document
 * subnode.
 */

#include "../asr/assertion.h"
#include "stt_doc_subnode.h"
#include "stt_doc_subnode_tests.h"
#include "stt_named_function_tests.h"

void
stt_doc_subnode_construct_and_destruct_test_0()
{
	stt_doc_subnode * doc_subnode_;
	doc_subnode_ = stt_doc_subnode_default_constructor();
	assertion(doc_subnode_ != NULL);
	assertion(doc_subnode_->named_functions_ == NULL);
	assertion(doc_subnode_->applications_ == NULL);
	assertion(doc_subnode_->execution_requests_ == NULL);
	stt_doc_subnode_destructor(doc_subnode_);
}

void
stt_doc_subnode_construct_and_destruct_test_1()
{
	stt_doc_subnode * doc_subnode_zero_;
	stt_doc_subnode * doc_subnode_one_;
	stt_named_function * named_function_;
	stt_named_functions_simple_list * named_functions_;
	stt_applications_simple_list * applications_;
	stt_execution_requests_simple_list * execution_requests_;
	named_function_ = stt_named_function_example_print_foo();
	named_functions_ =
			stt_named_functions_simple_list_default_constructor();
	named_functions_ = stt_named_functions_simple_list_push_front(
			named_functions_, named_function_);
	applications_ = stt_applications_simple_list_default_constructor();
	assertion(applications_ != NULL);
	execution_requests_ = stt_execution_requests_simple_list_default_constructor();
	doc_subnode_zero_ = stt_doc_subnode_exhaustive_constructor(
			named_functions_, applications_, execution_requests_);
	assertion(doc_subnode_zero_ != NULL);
	assertion(doc_subnode_zero_->named_functions_ != NULL);
	assertion(doc_subnode_zero_->named_functions_->first != NULL);
	assertion(doc_subnode_zero_->named_functions_->first->type_ !=
			STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(doc_subnode_zero_->named_functions_->next == NULL);
	assertion(doc_subnode_zero_->applications_ != NULL);
	assertion(doc_subnode_zero_->applications_->first == NULL);
	assertion(doc_subnode_zero_->applications_->next == NULL);
	assertion(doc_subnode_zero_->execution_requests_ != NULL);
	assertion(doc_subnode_zero_->execution_requests_->first == NULL);
	assertion(doc_subnode_zero_->execution_requests_->next == NULL);
	doc_subnode_one_ = stt_doc_subnode_copy_constructor(doc_subnode_zero_);
	assertion(doc_subnode_one_ != NULL);
	assertion(doc_subnode_one_->named_functions_ != NULL);
	assertion(doc_subnode_one_->named_functions_->first != NULL);
	assertion(doc_subnode_one_->named_functions_->first->type_ !=
			STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(doc_subnode_one_->named_functions_->next == NULL);
	assertion(doc_subnode_one_->applications_ != NULL);
	assertion(doc_subnode_one_->applications_->first == NULL);
	assertion(doc_subnode_one_->applications_->next == NULL);
	assertion(doc_subnode_one_->execution_requests_ != NULL);
	assertion(doc_subnode_one_->execution_requests_->first == NULL);
	assertion(doc_subnode_one_->execution_requests_->next == NULL);
	stt_doc_subnode_destructor(doc_subnode_one_);
	stt_named_functions_simple_list_destructor(named_functions_);
	stt_named_function_destructor(named_function_);
	stt_doc_subnode_destructor(doc_subnode_zero_);
}

void
stt_doc_subnode_construct_and_destruct_tests()
{
	stt_doc_subnode_construct_and_destruct_test_0();
	stt_doc_subnode_construct_and_destruct_test_1();
}

void
stt_doc_subnode_tests()
{
	stt_doc_subnode_construct_and_destruct_tests();
}
