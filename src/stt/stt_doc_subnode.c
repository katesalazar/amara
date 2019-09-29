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
	stt_doc_subnode * returning_;

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_doc_subnode *)
#endif
			malloc(sizeof(stt_doc_subnode));
	forced_assertion(returning_ != NULL);

	returning_->named_functions_ =
			stt_named_functions_simple_list_default_constructor();
	forced_assertion(returning_->named_functions_ != NULL);

	returning_->applications_ =
			stt_applications_simple_list_default_constructor();
	forced_assertion(returning_->applications_ != NULL);

	returning_->execution_requests_ =
			stt_execution_requests_simple_list_default_constructor();
	forced_assertion(returning_->execution_requests_ != NULL);

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
		/*if (applications == NULL) {
			assertion(execution_requests != NULL);
			assertion(execution_requests->first != NULL);
		*//* } else {
			assertion(applications->first != NULL); */
		/*}*/
	/* } else {
		assertion(named_functions->first != NULL); */
		assertion(applications == NULL);
		assertion(execution_requests == NULL);
	}

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_doc_subnode *)
#endif
			malloc(sizeof(stt_doc_subnode));
	forced_assertion(ret_ != NULL);

	if (named_functions != NULL /* && named_functions->first != NULL */) {
		ret_->named_functions_ =
				stt_named_functions_simple_list_copy_constructor(
						named_functions);
		forced_assertion(ret_->named_functions_ != NULL);
	} else {
		ret_->named_functions_ =
				stt_named_functions_simple_list_default_constructor();
		forced_assertion(ret_->named_functions_ != NULL);
	}
	if (applications != NULL /* && applications->first != NULL */) {
		ret_->applications_ =
				stt_applications_simple_list_copy_constructor(
						applications);
		forced_assertion(ret_->applications_ != NULL);
	} else {
		ret_->applications_ =
				stt_applications_simple_list_default_constructor();
		forced_assertion(ret_->applications_ != NULL);
	}
	if (execution_requests != NULL /* && execution_requests->first != NULL */) {
		ret_->execution_requests_ =
				stt_execution_requests_simple_list_copy_constructor(
						execution_requests);
		forced_assertion(ret_->execution_requests_ != NULL);
	} else {
		ret_->execution_requests_ =
				stt_execution_requests_simple_list_default_constructor();
		forced_assertion(ret_->execution_requests_ != NULL);
	}
	return ret_;
}

stt_doc_subnode *
stt_doc_subnode_copy_constructor(const stt_doc_subnode * subnode)
{
	stt_doc_subnode * ret_;
	assertion(subnode != NULL);
	assertion(subnode->named_functions_ != NULL);
	/*
	if (subnode->named_functions_ == NULL) {
	*/
		/*if (subnode->applications_ == NULL) {
			assertion(subnode->execution_requests_ != NULL);
		}*/
	/*
		assertion(subnode->applications_ == NULL);
		assertion(subnode->execution_requests_ == NULL);
	}
	*/

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_doc_subnode *)
#endif
			malloc(sizeof(stt_doc_subnode));
	forced_assertion(ret_ != NULL);

	assertion(subnode->named_functions_ != NULL);
	/*
	if (subnode->named_functions_ != NULL) {
	*/
		ret_->named_functions_ =
				stt_named_functions_simple_list_copy_constructor(
						subnode->named_functions_);
	/*
	} else {
		ret_->named_functions_ =
				stt_named_functions_simple_list_default_constructor();
	}
	*/
	assertion(subnode->applications_ != NULL);
	/*
	if (subnode->applications_ != NULL) {
	*/
		ret_->applications_ =
				stt_applications_simple_list_copy_constructor(
						subnode->applications_);
	/*
	} else {
		ret_->applications_ =
				stt_applications_simple_list_default_constructor();
	}
	*/
	assertion(subnode->execution_requests_ != NULL);
	/*
	if (subnode->execution_requests_ != NULL) {
	*/
		ret_->execution_requests_ =
				stt_execution_requests_simple_list_copy_constructor(
						subnode->execution_requests_);
	/*
	} else {
		ret_->execution_requests_ =
				stt_execution_requests_simple_list_default_constructor();
	}
	*/
	return ret_;
}

void
stt_doc_subnode_destructor(stt_doc_subnode * subnode)
{
	forced_assertion(subnode != NULL); /* XXX */

	/* if (subnode->named_functions_ == NULL) { *//* XXX */

		/* assertion(subnode->applications_ == NULL); *//* XXX */
		/* assertion(subnode->execution_requests_ == NULL); *//* XXX */
	/* } else { *//* XXX */

		assertion(subnode->named_functions_ != NULL);
		/*if (subnode->named_functions_ != NULL) {*/ /* XXX */
			stt_named_functions_simple_list_destructor( /* XXX */
					subnode->named_functions_); /* XXX */
		/*}*/ /* XXX */

		assertion(subnode->applications_ != NULL);
		/*
		if (subnode->applications_ != NULL) {
		*/

			stt_applications_simple_list_destructor(
					subnode->applications_);
		/*
		}
		*/

		assertion(subnode->execution_requests_ != NULL);
		/*
		if (subnode->execution_requests_ != NULL) {
		*/

			stt_execution_requests_simple_list_destructor(
					subnode->execution_requests_);
		/*
		}
		*/
	/* } *//* XXX */

	free(subnode); /* XXX */
}
