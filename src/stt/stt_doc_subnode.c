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
 * src/stt/stt_doc_subnode.c: Amara syntax tree document subnode.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_doc_subnode.h"

stt_doc_subnode *
stt_doc_subnode_default_constructor()
{
	stt_doc_subnode * returning_ = malloc(sizeof(stt_doc_subnode));
	returning_->functions_ = NULL;
	returning_->applications_ = NULL;
	returning_->execution_requests_ = NULL;
	return returning_;
}

stt_doc_subnode *
stt_doc_subnode_copy_constructor(const stt_doc_subnode * subnode)
{
	stt_doc_subnode * ret_;
	assertion(subnode != NULL);
	if (subnode->functions_ == NULL) {
		if (subnode->applications_ == NULL) {
			assertion(subnode->execution_requests_ != NULL);
		}
	}
	ret_ = malloc(sizeof(stt_doc_subnode));
	if (subnode->functions_ != NULL) {
		ret_->functions_ = stt_functions_simple_list_copy_constructor(
				subnode->functions_);
	} else if (subnode->applications_ != NULL) {
		ret_->applications_ =
				stt_applications_simple_list_copy_constructor(
						subnode->applications_);
	} else if (subnode->execution_requests_ != NULL) {
		ret_->execution_requests_ =
				stt_execution_requests_simple_list_copy_constructor(
						subnode->execution_requests_);
	}
	return ret_;
}

void
stt_doc_subnode_destructor(stt_doc_subnode * subnode)
{
	assertion(subnode != NULL);
	if (subnode->functions_ == NULL) {
		assertion(subnode->applications_ == NULL);
		assertion(subnode->execution_requests_ == NULL);
	} else {
		stt_functions_simple_list_destructor(subnode->functions_);
		stt_applications_simple_list_destructor(
				subnode->applications_);
		stt_execution_requests_simple_list_destructor(
				subnode->execution_requests_);
	}
	free(subnode);
}

rtg_functions_out_of_stt_doc_ret *
rtg_functions_out_of_stt_doc(const stt_doc_subnode * subnode)
{
	rtg_functions_out_of_stt_doc_ret * ret_;
	rtg_functions_simple_list_out_of_stt_functions_simple_list_ret * sub_ret_;
	fprintf(stderr, "%s:%u ----> rtg_functions_out_of_stt_doc_ret * rtg_functions_out_of_stt_doc(const stt_node *)\n",
			__FILE__, __LINE__);
	ret_ = malloc(sizeof(rtg_functions_out_of_stt_doc_ret));
	ret_->status = RTG_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_INVALID;
	ret_->functions = NULL;
	sub_ret_ = rtg_functions_simple_list_out_of_stt_functions_simple_list(
			subnode->functions_);
	if (sub_ret_->status ==
			RTG_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {
		ret_->status = RTG_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS;
		ret_->functions = sub_ret_->functions;
	}
	fprintf(stderr, "%s:%u <---- rtg_functions_out_of_stt_doc_ret * rtg_functions_out_of_stt_doc(const stt_node *)\n",
			__FILE__, __LINE__);
	return ret_;
}

rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list_ret *
rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list(
		const stt_doc_subnode * subnode,
		const rtg_functions_simple_list * functions)
{
	rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list_ret * ret_;
	rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_functions_simple_list_ret * sub_ret_;
	fprintf(stderr, "----> %s:%u rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list_ret * rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list(const stt_functions_simple_list *)\n",
			__FILE__, __LINE__);
	ret_ = malloc(sizeof(
			rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list_ret));
	ret_->status = RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	ret_->applications = NULL;
	sub_ret_ = rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_functions_simple_list(
			subnode->applications_, functions);
	if (sub_ret_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {
		ret_->status = RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
		ret_->applications = sub_ret_->applications;
	}
	fprintf(stderr, "<---- %s:%u rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list_ret * rtg_applications_out_of_stt_doc_and_rtg_functions_simple_list(const stt_functions_simple_list *)\n",
			__FILE__, __LINE__);
	return ret_;
}

rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret *
rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list(
		const stt_doc_subnode * subnode,
		const rtg_applications_simple_list * applications)
{
	rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret * ret_;
	rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list_ret * sub_ret_;
	ret_ = malloc(sizeof(
			rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret));
	ret_->status = RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	ret_->execution_requests = NULL;
	sub_ret_ = rtg_execution_requests_simple_list_out_of_stt_execution_requests_simple_list_and_rtg_applications_simple_list(
			subnode->execution_requests_, applications);
	if (sub_ret_->status ==
			RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {
		ret_->status = RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
		ret_->execution_requests = sub_ret_->execution_requests;
	}
	return ret_;
}
