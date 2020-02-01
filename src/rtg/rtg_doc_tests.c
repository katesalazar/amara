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
 * src/rtg/rtg_doc_tests.c: Test the Amara run time graph document.
 */

#include <stdio.h>

#include "../asr/assertion.h"

#include "../stt/stt_node_tests.h"

/*
#include "../stt/stt_node.h"
*/

#include "rtg_doc.h"

void
rtg_doc_default_constructor_test_0()
{
	rtg_doc * doc_;

	doc_ = rtg_doc_default_constructor();
	forced_assertion(doc_ != NULL);
	assertion(doc_->functions_ != NULL);
	assertion(doc_->functions_->first == NULL);
	assertion(doc_->functions_->next == NULL);
	assertion(doc_->applications_ != NULL);
	assertion(doc_->applications_->first == NULL);
	assertion(doc_->applications_->next == NULL);
	assertion(doc_->execution_requests_ != NULL);
	assertion(doc_->execution_requests_->first == NULL);
	assertion(doc_->execution_requests_->next == NULL);

	rtg_doc_destructor(doc_);
}

void
rtg_doc_default_constructor_tests()
{
	rtg_doc_default_constructor_test_0();
}

tests_simple_list *
register_rtg_doc_default_constructor_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_doc_default_constructor_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(tests,
			            & rtg_doc_default_constructor_test_0);
	return tests;
}

void
rtg_doc_transformation_constructor_test_0()
{
	stt_node * stt_doc_;
	rtg_doc_out_of_stt_doc_ret * rtg_doc_ret_;
	/*
	rtg_doc * rtg_doc_;
	*/

	stt_doc_ = stt_node_example_doc_zero();
	forced_assertion(stt_doc_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_doc_zero(stt_doc_);
#endif

	rtg_doc_ret_ = rtg_doc_out_of_stt_doc(stt_doc_);
	forced_assertion(rtg_doc_ret_ != NULL);
#ifndef NDEBUG
	/*
	assert_expectations_on_rtg_doc_example_zero(rtg_doc_);
	*/
#endif

	stt_node_destructor(stt_doc_);
	rtg_doc_out_of_stt_doc_ret_destructor(rtg_doc_ret_);

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "<---- test_0...\n");
#endif
}

void
rtg_doc_transformation_constructor_test_4()
{
	stt_node * stt_doc_;
	rtg_doc_out_of_stt_doc_ret * rtg_doc_ret_;
	/*
	rtg_doc * rtg_doc_;
	*/

	stt_doc_ = stt_node_example_doc_four();
	forced_assertion(stt_doc_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_doc_four(stt_doc_);
#endif

	rtg_doc_ret_ = rtg_doc_out_of_stt_doc(stt_doc_);
	forced_assertion(rtg_doc_ret_ != NULL);
#ifndef NDEBUG
	/*
	assert_expectations_on_rtg_doc_example_zero(rtg_doc_);
	*/
#endif

	stt_node_destructor(stt_doc_);
	rtg_doc_out_of_stt_doc_ret_destructor(rtg_doc_ret_);

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "<---- test_4...\n");
#endif
}

void
rtg_doc_transformation_constructor_tests()
{
	rtg_doc_transformation_constructor_test_0();
	rtg_doc_transformation_constructor_test_4();
}

tests_simple_list *
register_rtg_doc_transformation_constructor_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_doc_transformation_constructor_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests, & rtg_doc_transformation_constructor_test_0);
	tests_simple_list_push_back(
			tests, & rtg_doc_transformation_constructor_test_4);
	return tests;
}

void
rtg_doc_constructors_tests()
{
	rtg_doc_default_constructor_tests();
	rtg_doc_transformation_constructor_tests();
}

tests_simple_list *
register_rtg_doc_constructors_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_doc_constructors_tests(tests_simple_list * tests)
{
	return register_rtg_doc_transformation_constructor_tests(
	       register_rtg_doc_default_constructor_tests(tests));
}

void
rtg_doc_tests()
{
	rtg_doc_constructors_tests();
}

tests_simple_list *
register_rtg_doc_tests(tests_simple_list * tests)
{
	return
			register_rtg_doc_constructors_tests(
			tests
			)
			;
}
