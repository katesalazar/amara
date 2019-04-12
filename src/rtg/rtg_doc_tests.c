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
 * src/rtg/rtg_doc_tests.c: Test the Amara run time graph document.
 */

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
	assertion(doc_ != NULL);
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

	/* FIXME missing destructor calls. */
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

	/* FIXME missing destructor calls. */
}

void
rtg_doc_transformation_constructor_tests()
{
	rtg_doc_transformation_constructor_test_0();
	rtg_doc_transformation_constructor_test_4();
}

void
rtg_doc_constructors_tests()
{
	rtg_doc_default_constructor_tests();
	rtg_doc_transformation_constructor_tests();
}

void
rtg_doc_tests()
{
	rtg_doc_constructors_tests();
}
