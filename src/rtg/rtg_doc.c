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
 * src/rtg/rtg_doc.c: Amara run time graph document.
 */

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "rtg_named_functions_fixed_list.h"

/*   For `rtg_named_functions_simple_list_copy_constructor`. */
#include "rtg_named_functions_simple_list.h"

/*   For `rtg_applications_simple_list_copy_constructor`. */
#include "rtg_applications_simple_list.h"

/*   For `rtg_execution_requests_simple_list_copy_constructor`. */
#include "rtg_execution_requests_simple_list.h"

/*   For own definitions. */
#include "rtg_doc.h"

rtg_doc *
rtg_doc_default_constructor()
{
	rtg_doc * ret_;

	ret_ = malloc(sizeof(rtg_doc));
	forced_assertion(ret_ != NULL);
	ret_->functions_ = rtg_named_functions_simple_list_default_constructor();
	ret_->applications_ =
			rtg_applications_simple_list_default_constructor();
	ret_->execution_requests_ =
			rtg_execution_requests_simple_list_default_constructor();

	return ret_;
}

rtg_doc *
rtg_doc_exhaustive_constructor(
		const rtg_named_functions_simple_list * named_functions,
		rtg_applications_simple_list * applications,
		rtg_execution_requests_simple_list * execution_requests)
{
	rtg_doc * ret_;

	ret_ = malloc(sizeof(rtg_doc));
	forced_assertion(ret_ != NULL);
	ret_->functions_ =
			rtg_named_functions_simple_list_deep_copy_constructor(
					named_functions);
	ret_->applications_ = rtg_applications_simple_list_copy_constructor(
			applications);
	ret_->execution_requests_ =
			rtg_execution_requests_simple_list_copy_constructor(
					execution_requests);

	return ret_;
}

void
rtg_doc_destructor(rtg_doc * doc)
{
	rtg_named_functions_simple_list_deep_destructor(doc->functions_);
	rtg_applications_simple_list_destructor(doc->applications_);
	rtg_execution_requests_simple_list_destructor(
			doc->execution_requests_);
	free(doc);
}

void
rtg_doc_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret_destructor(
		rtg_doc_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret * rtg_doc_out_of_stt_doc_ret_)
{
	located_assertion(rtg_doc_out_of_stt_doc_ret_ != NULL);

	/*
	located_assertion(
			rtg_doc_out_of_stt_doc_ret_->status ==
					RTG_DOC_OUT_OF_STT_DOC_RET_STATUS_SUCCESS);
	*/

	if (rtg_doc_out_of_stt_doc_ret_->status ==
			RTG_DOC_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_SUCCESS) {

		located_assertion(rtg_doc_out_of_stt_doc_ret_->doc != NULL);
		rtg_doc_destructor(rtg_doc_out_of_stt_doc_ret_->doc);
	} else if (rtg_doc_out_of_stt_doc_ret_->status ==
			RTG_DOC_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_ERROR_ONE_OR_MORE_APPLICATIONS_REQUESTED_TO_BE_EXECUTED_NOT_FOUND) {

		located_assertion(rtg_doc_out_of_stt_doc_ret_->doc == NULL);
	} else {
		located_forced_unsigned_char_equality_assertion_two(
				rtg_doc_out_of_stt_doc_ret_->status,
				RTG_DOC_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_INVALID);

		located_assertion(rtg_doc_out_of_stt_doc_ret_->doc == NULL);
	}

	free(rtg_doc_out_of_stt_doc_ret_);
}

rtg_doc_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret *
rtg_doc_out_of_stt_doc_and_rtg_named_functions_fixed_list(
		const stt_node * node,
		rtg_named_functions_fixed_list * rtg_named_functions)
{
	rtg_doc_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret * ret_;
	rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret * rtg_named_functions_simple_list_out_of_stt_doc_ret_;
	rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_;
	rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret * rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_;
	const rtg_named_functions_simple_list * rtg_named_functions_;
	rtg_applications_simple_list * rtg_applications_;
	rtg_execution_requests_simple_list * rtg_execution_requests_;

	fprintf(stderr, "%s:%u ----> rtg_doc_out_of_stt_doc_ret * rtg_doc_out_of_stt_doc(const stt_node *)\n",
			__FILE__, __LINE__);

	ret_ = malloc(sizeof(rtg_doc_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret));
#ifndef NDEBUG
	assertion(ret_ != NULL);
#endif
	ret_->status = RTG_DOC_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_INVALID;
	ret_->doc = NULL;
	ret_->error_messages = NULL;

	assertion(node->type_ == STT_NODE_TYPE_DOC);

	rtg_named_functions = NULL;  /* XXX */

	rtg_named_functions_simple_list_out_of_stt_doc_ret_ =
			rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list(
					node->doc_subnode_,
					rtg_named_functions)
			/*
			NULL
			*/
	;
	assertion(rtg_named_functions_simple_list_out_of_stt_doc_ret_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_SUCCESS);
	rtg_named_functions_ =
			rtg_named_functions_simple_list_out_of_stt_doc_ret_->new_named_functions_transformed_from_doc;
	rtg_named_functions_simple_list_out_of_stt_doc_ret_->new_named_functions_transformed_from_doc = NULL;

	rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_ =
			rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list(
					node->doc_subnode_,
					rtg_named_functions_);
	assertion(rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_->status ==
			RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
	rtg_applications_ =
			rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_->applications;
	rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_->applications =
			NULL;

	rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_ =
			rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list(
					node->doc_subnode_, rtg_applications_);

	if (rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->status ==
			RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

#ifndef NDEBUG
		assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->error_messages ==
				NULL);
		assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests !=
				NULL);
#endif
	} else {
		forced_assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->status ==
				RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_ONE_OR_MORE_APPLICATIONS_REQUESTED_TO_BE_EXECUTED_NOT_FOUND);

		ret_->status = RTG_DOC_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_ERROR_ONE_OR_MORE_APPLICATIONS_REQUESTED_TO_BE_EXECUTED_NOT_FOUND;
		forced_assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->error_messages !=
				NULL);
		ret_->error_messages = rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->error_messages;
		rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->error_messages = NULL;

		assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests !=
				NULL);

		/*
		if (rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests !=
				NULL) {
		*/

			rtg_execution_requests_simple_list_destructor(  /* XXX */
					rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests);  /* XXX */
			rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests = NULL;  /* XXX */

			free(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_);  /* XXX */
		/*
		}
		*/

		rtg_named_functions_simple_list_deep_destructor(
				(rtg_named_functions_simple_list *) rtg_named_functions_);
		rtg_applications_simple_list_destructor(rtg_applications_);

		rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_destructor(
				rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_);

		/*
		rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret_destructor(
				rtg_named_functions_simple_list_out_of_stt_doc_ret_);
		*/

		return ret_;
	}

#ifndef NDEBUG
	assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->error_messages == NULL);
#endif
	rtg_execution_requests_ =
			rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests;
	rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests = NULL;

	ret_->doc = rtg_doc_exhaustive_constructor(
			rtg_named_functions_, rtg_applications_,
			rtg_execution_requests_);

	rtg_named_functions_simple_list_deep_destructor(
			(rtg_named_functions_simple_list *) rtg_named_functions_);
	rtg_applications_simple_list_destructor(rtg_applications_);
	rtg_execution_requests_simple_list_destructor(rtg_execution_requests_);

	ret_->status = RTG_DOC_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_SUCCESS;

	rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_destructor(
			rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_);
	rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_ =
			NULL;

	rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_destructor(
			rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_);
	rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_ =
			NULL;

	/*
	rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret_destructor(
			rtg_named_functions_simple_list_out_of_stt_doc_ret_);
	*/
	rtg_named_functions_simple_list_out_of_stt_doc_ret_ = NULL;

	fprintf(stderr, "%s:%u <---- rtg_doc_out_of_stt_doc_ret * rtg_doc_out_of_stt_doc(const stt_node *)\n",
			__FILE__, __LINE__);

	return ret_;
}
