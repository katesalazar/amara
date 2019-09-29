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
 * src/stt/stt_execution_request_subnode.c: Amara syntax tree
 * application execution request subnode.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_execution_request_subnode.h"

stt_execution_request_subnode *
stt_execution_request_subnode_default_constructor()
{
	stt_execution_request_subnode * returning_;

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_execution_request_subnode *)
#endif
			malloc(sizeof(stt_execution_request_subnode));
	forced_assertion(returning_ != NULL);

	returning_->type_ = STT_EXECUTION_REQUEST_SUBNODE_TYPE_INVALID;
	returning_->application_name_ = NULL;

	return returning_;
}

stt_execution_request_subnode *
stt_execution_request_subnode_copy_constructor(
		const stt_execution_request_subnode * subnode)
{
	stt_execution_request_subnode * ret_;

	assertion(subnode != NULL);
	assertion(subnode->type_ != STT_EXECUTION_REQUEST_SUBNODE_TYPE_INVALID);
	assertion(subnode->application_name_ != NULL);
	assertion(subnode->application_name_->value_ != NULL);

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_execution_request_subnode *)
#endif
			malloc(sizeof(stt_execution_request_subnode));
	forced_assertion(ret_ != NULL);

	ret_->application_name_ = amara_string_copy_constructor(
			subnode->application_name_);
	ret_->type_ = subnode->type_;

	return ret_;
}

stt_execution_request_subnode *
stt_execution_request_subnode_exhaustive_constructor(
		const stt_execution_request * execution_request)
{
	stt_execution_request_subnode * ret_;

	assertion(execution_request != NULL);
	assertion(execution_request->type_ !=
			STT_EXECUTION_REQUEST_TYPE_INVALID);
	assertion(execution_request->application_name_ != NULL);
	assertion(execution_request->application_name_->value_ != NULL);

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_execution_request_subnode *)
#endif
			malloc(sizeof(stt_execution_request_subnode));
	forced_assertion(ret_ != NULL);

	ret_->application_name_ = amara_string_copy_constructor(
			execution_request->application_name_);

	assertion(execution_request->type_ ==
			STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);
	ret_->type_ = STT_EXECUTION_REQUEST_SUBNODE_TYPE_RUN_CLI_APPLICATION;

	return ret_;
}

void
stt_execution_request_subnode_destructor(
		stt_execution_request_subnode * subnode)
{
#ifndef NDEBUG
	assertion(subnode != NULL);
#endif
	if (subnode->type_ == STT_EXECUTION_REQUEST_SUBNODE_TYPE_INVALID) {
#ifndef NDEBUG
		assertion(subnode->application_name_ == NULL);
#endif
	} else {
#ifndef NDEBUG
		assertion(subnode->application_name_ != NULL);
#endif
		amara_string_destructor(subnode->application_name_);
	}
	free(subnode);
}
