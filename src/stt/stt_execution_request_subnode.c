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
	stt_execution_request_subnode * returning_ =
			malloc(sizeof(stt_execution_request_subnode));
	returning_->type_ = EXECUTION_REQUEST_SUBNODE_TYPE_INVALID;
	returning_->application_name_ = NULL;
	return returning_;
}

stt_execution_request_subnode *
stt_execution_request_subnode_copy_constructor(
		const stt_execution_request_subnode * subnode)
{
	stt_execution_request_subnode * ret_;
	assertion(subnode != NULL);
	assertion(subnode->type_ != EXECUTION_REQUEST_SUBNODE_TYPE_INVALID);
	assertion(subnode->application_name_ != NULL);
	assertion(subnode->application_name_->value_ != NULL);
	ret_ = malloc(sizeof(stt_execution_request_subnode));
	ret_->application_name_ = amara_string_copy_constructor(
			subnode->application_name_);
	ret_->type_ = subnode->type_;
	return ret_;
}

void
stt_execution_request_subnode_destructor(
		stt_execution_request_subnode * subnode)
{
	assertion(subnode != NULL);
	if (subnode->type_ == EXECUTION_REQUEST_SUBNODE_TYPE_INVALID) {
		assertion(subnode->application_name_ == NULL);
	} else {
		assertion(subnode->application_name_ != NULL);
		free((char *) subnode->application_name_);
		subnode->application_name_ = NULL;
	}
	free(subnode);
}
