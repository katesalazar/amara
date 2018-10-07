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
	returning_->named_functions_ = NULL;
	returning_->applications_ = NULL;
	returning_->execution_requests_ = NULL;
	return returning_;
}

stt_doc_subnode *
stt_doc_subnode_exhaustive_constructor(
		const stt_named_functions_simple_list * named_functions,
		const stt_applications_simple_list * applications,
		const stt_execution_requests_simple_list * execution_requests)
{
	stt_doc_subnode * ret_;
	if (named_functions == NULL) {
		if (applications == NULL) {
			assertion(execution_requests != NULL);
			assertion(execution_requests->first != NULL);
		/* } else {
			assertion(applications->first != NULL); */
		}
	/* } else {
		assertion(named_functions->first != NULL); */
	}
	ret_ = malloc(sizeof(stt_doc_subnode));
	if (named_functions != NULL /* && named_functions->first != NULL */) {
		ret_->named_functions_ =
				stt_named_functions_simple_list_copy_constructor(
						named_functions);
	}
	if (applications != NULL /* && applications->first != NULL */) {
		ret_->applications_ =
				stt_applications_simple_list_copy_constructor(
						applications);
	}
	if (execution_requests != NULL /* && execution_requests->first != NULL */) {
		ret_->execution_requests_ =
				stt_execution_requests_simple_list_copy_constructor(
						execution_requests);
	}
	return ret_;
}

stt_doc_subnode *
stt_doc_subnode_copy_constructor(const stt_doc_subnode * subnode)
{
	stt_doc_subnode * ret_;
	assertion(subnode != NULL);
	if (subnode->named_functions_ == NULL) {
		if (subnode->applications_ == NULL) {
			assertion(subnode->execution_requests_ != NULL);
		}
	}
	ret_ = malloc(sizeof(stt_doc_subnode));
	if (subnode->named_functions_ != NULL) {
		ret_->named_functions_ =
				stt_named_functions_simple_list_copy_constructor(
						subnode->named_functions_);
	}
	if (subnode->applications_ != NULL) {
		ret_->applications_ =
				stt_applications_simple_list_copy_constructor(
						subnode->applications_);
	}
	if (subnode->execution_requests_ != NULL) {
		ret_->execution_requests_ =
				stt_execution_requests_simple_list_copy_constructor(
						subnode->execution_requests_);
	}
	return ret_;
}

void
stt_doc_subnode_destructor(stt_doc_subnode * subnode)
{
	assertion(subnode != NULL); /* XXX */
	if (subnode->named_functions_ == NULL) { /* XXX */
		assertion(subnode->applications_ == NULL); /* XXX */
		assertion(subnode->execution_requests_ == NULL); /* XXX */
	} else { /* XXX */
		if (subnode->named_functions_ != NULL) { /* XXX */
			stt_named_functions_simple_list_destructor( /* XXX */
					subnode->named_functions_); /* XXX */
		} /* XXX */
		if (subnode->applications_ != NULL) { /* XXX */
			stt_applications_simple_list_destructor( /* XXX */
					subnode->applications_); /* XXX */
		} /* XXX */
		if (subnode->execution_requests_ != NULL) { /* XXX */
			stt_execution_requests_simple_list_destructor( /* XXX */
					subnode->execution_requests_); /* XXX */
		} /* XXX */
	} /* XXX */
	free(subnode); /* XXX */
}

void
rtg_named_functions_out_of_stt_doc_ret_destructor(
		rtg_named_functions_out_of_stt_doc_ret * rtg_named_functions_out_of_stt_doc_ret_)
{
	assertion(rtg_named_functions_out_of_stt_doc_ret_ != NULL);
	if (rtg_named_functions_out_of_stt_doc_ret_->status ==
			RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS) {
		assertion(rtg_named_functions_out_of_stt_doc_ret_->named_functions !=
				NULL);
		if (rtg_named_functions_out_of_stt_doc_ret_->named_functions_were_moved ==
				AMARA_BOOLEAN_FALSE) {
			rtg_named_functions_simple_list_destructor(
					rtg_named_functions_out_of_stt_doc_ret_->named_functions);
		}
	} else {
		assertion(rtg_named_functions_out_of_stt_doc_ret_->status ==
					RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_INVALID /* ||
				rtg_named_functions_out_of_stt_doc_ret_->status ==
						RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_ERROR_UNSPECIFIC */);
		assertion(rtg_named_functions_out_of_stt_doc_ret_->named_functions ==
				NULL);
	}
	free(rtg_named_functions_out_of_stt_doc_ret_);
}

rtg_named_functions_out_of_stt_doc_ret *
rtg_named_functions_out_of_stt_doc(const stt_doc_subnode * subnode)
{
	rtg_named_functions_out_of_stt_doc_ret * ret_;
	rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * sub_ret_;
	fprintf(stderr, "%s:%u ----> rtg_named_functions_out_of_stt_doc_ret * rtg_named_functions_out_of_stt_doc(const stt_node *)\n",
			__FILE__, __LINE__);
	ret_ = malloc(sizeof(rtg_named_functions_out_of_stt_doc_ret));
	ret_->status = RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_INVALID;
	ret_->named_functions = NULL;
	sub_ret_ = rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(
			subnode->named_functions_);
	if (sub_ret_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {
		ret_->status = RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS;
		ret_->named_functions = sub_ret_->named_functions;
	} else {
		assertion(sub_ret_->status ==
				RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC);
		assertion(sub_ret_->named_functions == NULL);
	}
	free(sub_ret_);
	fprintf(stderr, "%s:%u <---- rtg_named_functions_out_of_stt_doc_ret * rtg_named_functions_out_of_stt_doc(const stt_node *)\n",
			__FILE__, __LINE__);
	return ret_;
}

void
rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_destructor(
		rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_)
{
	assertion(rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_ !=
			NULL);
	if (rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_->status ==
			RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {
		assertion(rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_->applications !=
				NULL);
		if (rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_->applications_were_moved ==
				AMARA_BOOLEAN_FALSE) {
			rtg_applications_simple_list_destructor(
					rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_->applications);
		}
	} else {
		assertion(rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_->status ==
					RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID /* ||
				rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_->status ==
						RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC */);
		assertion(rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_->applications ==
				NULL);
	}
	free(rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_);
}

rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret *
rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list(
		const stt_doc_subnode * subnode,
		const rtg_named_functions_simple_list * functions)
{
	rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * ret_;
	rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list_ret * sub_ret_;
	fprintf(stderr, "----> %s:%u rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list(const stt_functions_simple_list *)\n",
			__FILE__, __LINE__);
	ret_ = malloc(sizeof(
			rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret));
	ret_->status = RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID;
	ret_->applications = NULL;
	sub_ret_ = rtg_applications_simple_list_out_of_stt_applications_simple_list_and_rtg_named_functions_simple_list(
			subnode->applications_, functions);
	if (sub_ret_->status ==
			RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {
		ret_->status = RTG_APPLICATIONS_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
		ret_->applications = sub_ret_->applications;
	} else {
		assertion(sub_ret_->status ==
				RTG_APPLICATIONS_SIMPLE_LIST_OUT_OF_STT_APPLICATIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC);
		assertion(sub_ret_->applications == NULL);
	}
	free(sub_ret_);
	fprintf(stderr, "<---- %s:%u rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * rtg_applications_out_of_stt_doc_and_rtg_named_functions_simple_list(const stt_functions_simple_list *)\n",
			__FILE__, __LINE__);
	return ret_;
}

void
rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_destructor(
		rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret * rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_)
{
	assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_ !=
			NULL);
	if (rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->status ==
			RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {
		assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests !=
				NULL);
		if (rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests_were_moved ==
				AMARA_BOOLEAN_FALSE) {
			rtg_execution_requests_simple_list_destructor(
					rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests);
		}
	} else {
		assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->status ==
					RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_INVALID /* ||
				rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->status ==
						RTG_EXECUTION_REQUESTS_OUT_OF_STT_DOC_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC */);
		assertion(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_->execution_requests ==
				NULL);
	}
	free(rtg_execution_requests_out_of_stt_doc_and_rtg_applications_simple_list_ret_);
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
	} else {
		assertion(sub_ret_->status ==
				RTG_EXECUTION_REQUESTS_SIMPLE_LIST_OUT_OF_STT_EXECUTION_REQUESTS_SIMPLE_LIST_AND_RTG_APPLICATIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC);
		assertion(sub_ret_->execution_requests == NULL);
	}
	free(sub_ret_);
	return ret_;
}
