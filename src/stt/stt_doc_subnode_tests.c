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
 * src/stt/stt_doc_subnode_tests.c: Test the Amara syntax tree document
 * subnode.
 */

#include "../asr/assertion.h"

#include "stt_application_tests.h"
#include "stt_doc_subnode.h"
#include "stt_doc_subnode_tests.h"
#include "stt_execution_request_tests.h"
#include "stt_named_function_tests.h"

#include "stt_named_functions_simple_list_tests.h"

stt_doc_subnode *
stt_doc_subnode_example_one_invalid_named_function()
{
	stt_named_functions_simple_list * named_functions_;
	stt_applications_simple_list * applications_;
	stt_execution_requests_simple_list * execution_requests_;
	stt_doc_subnode * ret_;

	named_functions_ =
			stt_named_functions_simple_list_example_one_invalid_named_function();
	forced_assertion(named_functions_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_functions_simple_list_example_one_invalid_named_function(
			named_functions_);
#endif

	applications_ = NULL;

	execution_requests_ = NULL;

	ret_ = stt_doc_subnode_exhaustive_constructor(
			named_functions_, applications_, execution_requests_);

	stt_named_functions_simple_list_destructor(named_functions_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_doc_subnode_example_one_invalid_named_function(
		const stt_doc_subnode * doc_subnode)
{
	assertion(doc_subnode != NULL);
	assertion(doc_subnode->named_functions_ != NULL);
	assertion(doc_subnode->named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_ill_formed_example_print_identifier_foo(
			doc_subnode->named_functions_->first);
	assertion(doc_subnode->named_functions_->next == NULL);
	assertion(doc_subnode->applications_ != NULL);
	assertion(doc_subnode->applications_->first == NULL);
	assertion(doc_subnode->applications_->next == NULL);
	assertion(doc_subnode->execution_requests_ != NULL);
	assertion(doc_subnode->execution_requests_->first == NULL);
	assertion(doc_subnode->execution_requests_->next == NULL);
}

#endif

stt_doc_subnode *
stt_doc_subnode_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(void)
{
	stt_named_functions_simple_list * named_functions_;
	stt_applications_simple_list * applications_;
	stt_execution_requests_simple_list * execution_requests_;
	stt_doc_subnode * ret_;

	named_functions_ =
			stt_named_functions_simple_list_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo();
	forced_assertion(named_functions_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_functions_simple_list_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
			named_functions_);
#endif

	applications_ = NULL;

	execution_requests_ = NULL;

	ret_ = stt_doc_subnode_exhaustive_constructor(
			named_functions_, applications_, execution_requests_);

	stt_named_functions_simple_list_destructor(named_functions_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_doc_subnode_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
		const stt_doc_subnode * subnode)
{
	assertion(subnode != NULL);
	assertion(subnode->named_functions_ != NULL);
	assert_expectations_on_stt_named_functions_simple_list_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
			subnode->named_functions_);
	assertion(subnode->applications_ != NULL);
	assertion(subnode->applications_->first == NULL);
	assertion(subnode->applications_->next == NULL);
	assertion(subnode->execution_requests_ != NULL);
	assertion(subnode->execution_requests_->first == NULL);
	assertion(subnode->execution_requests_->next == NULL);
}

#endif

#ifndef NDEBUG

void
assert_expectations_on_stt_doc_subnode_example_print_string_literal_foo(
		const stt_doc_subnode * subnode)
{
	assertion(subnode != NULL);
	assertion(subnode->named_functions_ != NULL);
	assertion(subnode->named_functions_->first != NULL);
	assert_expectations_on_stt_named_function_example_print_string_literal_foo(
			subnode->named_functions_->first);
	assertion(subnode->named_functions_->next == NULL);
	assertion(subnode->applications_ != NULL);
	assertion(subnode->applications_->first != NULL);
	assert_expectations_on_stt_application_example_print_foo(
			subnode->applications_->first);
	assertion(subnode->applications_->next == NULL);
	assertion(subnode->execution_requests_ != NULL);
	assertion(subnode->execution_requests_->first != NULL);
	assert_expectations_on_stt_execution_request_example_print_foo(
			subnode->execution_requests_->first);
	assertion(subnode->execution_requests_->next == NULL);
}

#endif

void
stt_doc_subnode_construct_and_destruct_test_0()
{
	stt_doc_subnode * doc_subnode_;

	doc_subnode_ = stt_doc_subnode_default_constructor();
	assertion(doc_subnode_ != NULL);
	assertion(doc_subnode_->named_functions_ != NULL);
	assertion(doc_subnode_->named_functions_->first == NULL);
	assertion(doc_subnode_->named_functions_->next == NULL);
	assertion(doc_subnode_->applications_ != NULL);
	assertion(doc_subnode_->applications_->first == NULL);
	assertion(doc_subnode_->applications_->next == NULL);
	assertion(doc_subnode_->execution_requests_ != NULL);
	assertion(doc_subnode_->execution_requests_->first == NULL);
	assertion(doc_subnode_->execution_requests_->next == NULL);
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

	named_function_ =
			stt_named_function_example_print_string_literal_foo();
	forced_assertion(named_function_ != NULL);

	named_functions_ =
			stt_named_functions_simple_list_default_constructor();
	forced_assertion(named_functions_ != NULL);

	named_functions_ = stt_named_functions_simple_list_push_front(
			named_functions_, named_function_);
	forced_assertion(named_functions_ != NULL);

	stt_named_function_destructor(named_function_);

	applications_ = stt_applications_simple_list_default_constructor();
	forced_assertion(applications_ != NULL);

	execution_requests_ = stt_execution_requests_simple_list_default_constructor();
	forced_assertion(execution_requests_ != NULL);

	doc_subnode_zero_ = stt_doc_subnode_exhaustive_constructor(
			named_functions_, applications_, execution_requests_);
	forced_assertion(doc_subnode_zero_ != NULL);
	forced_assertion(doc_subnode_zero_->named_functions_ != NULL);
	forced_assertion(doc_subnode_zero_->named_functions_->first != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_zero_->named_functions_->first->type_ !=
			STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(doc_subnode_zero_->named_functions_->next == NULL);
#endif
	forced_assertion(doc_subnode_zero_->applications_ != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_zero_->applications_->first == NULL);
	assertion(doc_subnode_zero_->applications_->next == NULL);
#endif
	forced_assertion(doc_subnode_zero_->execution_requests_ != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_zero_->execution_requests_->first == NULL);
	assertion(doc_subnode_zero_->execution_requests_->next == NULL);
#endif

	stt_named_functions_simple_list_destructor(named_functions_);
	stt_applications_simple_list_destructor(applications_);
	stt_execution_requests_simple_list_destructor(execution_requests_);

	doc_subnode_one_ = stt_doc_subnode_copy_constructor(doc_subnode_zero_);
	forced_assertion(doc_subnode_one_ != NULL);
	forced_assertion(doc_subnode_one_->named_functions_ != NULL);
	forced_assertion(doc_subnode_one_->named_functions_->first != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_one_->named_functions_->first->type_ !=
			STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(doc_subnode_one_->named_functions_->next == NULL);
#endif
	forced_assertion(doc_subnode_one_->applications_ != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_one_->applications_->first == NULL);
	assertion(doc_subnode_one_->applications_->next == NULL);
#endif
	forced_assertion(doc_subnode_one_->execution_requests_ != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_one_->execution_requests_->first == NULL);
	assertion(doc_subnode_one_->execution_requests_->next == NULL);
#endif

	stt_doc_subnode_destructor(doc_subnode_one_);
	stt_doc_subnode_destructor(doc_subnode_zero_);
}

/*
void
stt_doc_subnode_construct_and_destruct_test_2()
{
	stt_doc_subnode * doc_subnode_;
	stt_named_functions_simple_list * named_functions_;
	stt_applications_simple_list * applications_;
	stt_execution_requests_simple_list * execution_requests_;
	named_functions_ = NULL;
	applications_ = stt_applications_simple_list_default_constructor();
	execution_requests_ = stt_execution_requests_simple_list_default_constructor();
	doc_subnode_ = stt_doc_subnode_exhaustive_constructor(
			named_functions_, applications_, execution_requests_);
	assertion(doc_subnode_ != NULL);
	assertion(doc_subnode_->named_functions_ == NULL);
	assertion(doc_subnode_->applications_ != NULL);
	assertion(doc_subnode_->applications_->first == NULL);
	assertion(doc_subnode_->applications_->next == NULL);
	assertion(doc_subnode_->execution_requests_ != NULL);
	assertion(doc_subnode_->execution_requests_->first == NULL);
	assertion(doc_subnode_->execution_requests_->next == NULL);
	stt_execution_requests_simple_list_destructor(execution_requests_);
	stt_applications_simple_list_destructor(applications_);
	stt_doc_subnode_destructor(doc_subnode_);
}
*/

void
stt_doc_subnode_construct_and_destruct_test_3()
{
	stt_doc_subnode * doc_subnode_;
	stt_named_functions_simple_list * named_functions_;
	stt_applications_simple_list * applications_;
	stt_execution_requests_simple_list * execution_requests_;

	named_functions_ = NULL;
	applications_ = NULL;
	execution_requests_ = NULL;
	doc_subnode_ = stt_doc_subnode_exhaustive_constructor(
			named_functions_, applications_, execution_requests_);
	forced_assertion(doc_subnode_ != NULL);
	forced_assertion(doc_subnode_->named_functions_ != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_->named_functions_->first == NULL);
	assertion(doc_subnode_->named_functions_->next == NULL);
#endif
	forced_assertion(doc_subnode_->applications_ != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_->applications_->first == NULL);
	assertion(doc_subnode_->applications_->next == NULL);
#endif
	forced_assertion(doc_subnode_->execution_requests_ != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_->execution_requests_->first == NULL);
	assertion(doc_subnode_->execution_requests_->next == NULL);
#endif

	stt_doc_subnode_destructor(doc_subnode_);
}

void
stt_doc_subnode_construct_and_destruct_test_4()
{
	stt_doc_subnode * doc_subnode_zero_;
	stt_doc_subnode * doc_subnode_one_;
	stt_named_functions_simple_list * named_functions_;
	stt_applications_simple_list * applications_;
	stt_execution_requests_simple_list * execution_requests_;

	named_functions_ = NULL;
	applications_ = NULL;
	execution_requests_ = NULL;
	doc_subnode_zero_ = stt_doc_subnode_exhaustive_constructor(
			named_functions_, applications_, execution_requests_);
	forced_assertion(doc_subnode_zero_ != NULL);
	forced_assertion(doc_subnode_zero_->named_functions_ != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_zero_->named_functions_->first == NULL);
	assertion(doc_subnode_zero_->named_functions_->next == NULL);
#endif
	forced_assertion(doc_subnode_zero_->applications_ != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_zero_->applications_->first == NULL);
	assertion(doc_subnode_zero_->applications_->next == NULL);
#endif
	forced_assertion(doc_subnode_zero_->execution_requests_ != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_zero_->execution_requests_->first == NULL);
	assertion(doc_subnode_zero_->execution_requests_->next == NULL);
#endif

	doc_subnode_one_ = stt_doc_subnode_copy_constructor(doc_subnode_zero_);
	forced_assertion(doc_subnode_one_ != NULL);
	forced_assertion(doc_subnode_one_->named_functions_ != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_one_->named_functions_->first == NULL);
	assertion(doc_subnode_one_->named_functions_->next == NULL);
#endif
	forced_assertion(doc_subnode_one_->applications_ != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_one_->applications_->first == NULL);
	assertion(doc_subnode_one_->applications_->next == NULL);
#endif
	forced_assertion(doc_subnode_one_->execution_requests_ != NULL);
#ifndef NDEBUG
	assertion(doc_subnode_one_->execution_requests_->first == NULL);
	assertion(doc_subnode_one_->execution_requests_->next == NULL);
#endif

	stt_doc_subnode_destructor(doc_subnode_one_);
	stt_doc_subnode_destructor(doc_subnode_zero_);
}

void
stt_doc_subnode_exhaustive_constructor_test_0()
{
	stt_doc_subnode * subnode_;

	subnode_ = stt_doc_subnode_example_one_invalid_named_function();
	forced_assertion(subnode_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_doc_subnode_example_one_invalid_named_function(
			subnode_);
#endif

	stt_doc_subnode_destructor(subnode_);
}

void
stt_doc_subnode_exhaustive_constructor_test_1()
{
	stt_doc_subnode * subnode_;

	subnode_ = stt_doc_subnode_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo();
	forced_assertion(subnode_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_doc_subnode_example_one_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
			subnode_);
#endif

	stt_doc_subnode_destructor(subnode_);
}

void
stt_doc_subnode_exhaustive_constructor_tests()
{
	stt_doc_subnode_exhaustive_constructor_test_0();
	stt_doc_subnode_exhaustive_constructor_test_1();
}

void
stt_doc_subnode_constructors_tests()
{
	stt_doc_subnode_construct_and_destruct_test_0();
	stt_doc_subnode_construct_and_destruct_test_1();
	/*
	stt_doc_subnode_construct_and_destruct_test_2();
	*/
	stt_doc_subnode_construct_and_destruct_test_3();
	stt_doc_subnode_construct_and_destruct_test_4();
	stt_doc_subnode_exhaustive_constructor_tests();
}

void
stt_doc_subnode_tests()
{
	stt_doc_subnode_constructors_tests();
}
