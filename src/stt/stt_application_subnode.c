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
 * src/stt/stt_application_subnode.c: Amara syntax tree application
 * subnode.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_application_subnode.h"

stt_application_subnode *
stt_application_subnode_default_constructor()
{
	stt_application_subnode * returning_ =
			malloc(sizeof(stt_application_subnode));
	returning_->type_ = STT_APPLICATION_SUBNODE_TYPE_INVALID;
	returning_->name_ = NULL;
	returning_->entry_point_function_name_ = NULL;
	return returning_;
}

stt_application_subnode *
stt_application_subnode_copy_constructor(
		const stt_application_subnode * subnode)
{
	stt_application_subnode * ret_;
	assertion(subnode != NULL);
	assertion(subnode->type_ != STT_APPLICATION_SUBNODE_TYPE_INVALID);
	assertion(subnode->name_ != NULL);
	assertion(subnode->name_->value_ != NULL);
	assertion(subnode->entry_point_function_name_ != NULL);
	assertion(subnode->entry_point_function_name_->value_ != NULL);
	ret_ = malloc(sizeof(stt_application_subnode));
	ret_->entry_point_function_name_ = amara_string_copy_constructor(
			subnode->entry_point_function_name_);
	ret_->name_ = amara_string_copy_constructor(subnode->name_);
	ret_->type_ = subnode->type_;
	return ret_;
}

void
stt_application_subnode_destructor(stt_application_subnode * subnode)
{
	assertion(subnode != NULL);
	if (subnode->type_ == STT_APPLICATION_SUBNODE_TYPE_INVALID) {
		assertion(subnode->name_ == NULL);
		assertion(subnode->entry_point_function_name_ == NULL);
	} else {
		assertion(subnode->type_ ==
				STT_APPLICATION_SUBNODE_TYPE_CLI_APPLICATION);
		amara_string_destructor(subnode->name_);
		subnode->name_ = NULL;
		free(subnode->entry_point_function_name_);
		subnode->entry_point_function_name_ = NULL;
	}
	free(subnode);
}
