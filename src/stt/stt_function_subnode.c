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
 * src/stt/stt_function_subnode.c: Amara syntax tree application
 * function subnode.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_function_subnode.h"

stt_function_subnode *
stt_function_subnode_default_constructor()
{
	stt_function_subnode * returning_ =
			malloc(sizeof(stt_function_subnode));
	returning_->type_ = STT_FUNCTION_SUBNODE_TYPE_INVALID;
	returning_->name_ = NULL;
	returning_->operations_ = NULL;
	return returning_;
}

stt_function_subnode *
stt_function_subnode_copy_constructor(const stt_function_subnode * subnode)
{
	stt_function_subnode * ret_;
	assertion(subnode != NULL);
	assertion(subnode->type_ != STT_FUNCTION_SUBNODE_TYPE_INVALID);
	assertion(subnode->name_ != NULL);
	assertion(subnode->operations_ != NULL);
	ret_ = malloc(sizeof(stt_function_subnode));
	ret_->operations_ = stt_operations_simple_list_copy_constructor(
			subnode->operations_);
	ret_->name_ = amara_string_copy_constructor(subnode->name_);
	ret_->type_ = subnode->type_;
	return ret_;
}

void
stt_function_subnode_destructor(stt_function_subnode * subnode)
{
	assertion(subnode != NULL);
	if (subnode->type_ == STT_FUNCTION_SUBNODE_TYPE_INVALID) {
		assertion(subnode->name_ == NULL);
		assertion(subnode->operations_ == NULL);
	} else {
		assertion(subnode->name_ != NULL);
		amara_string_destructor(subnode->name_);
		subnode->name_ = NULL;
		assertion(subnode->operations_ != NULL);
		stt_operations_simple_list_destructor(subnode->operations_);
		subnode->operations_ = NULL;
	}
	free(subnode);
}
