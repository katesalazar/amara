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
 * src/rtg/rtg_doc_tests.c: Test the Amara run time graph document.
 */

#include "../asr/assertion.h"
#include "rtg_doc.h"

void
rtg_doc_construct_and_destruct_test_0()
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
rtg_doc_construct_and_destruct_tests()
{
	rtg_doc_construct_and_destruct_test_0();
}

void
rtg_doc_tests()
{
	rtg_doc_construct_and_destruct_tests();
}
