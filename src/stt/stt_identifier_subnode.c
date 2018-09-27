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
 * src/stt/stt_identifier_subnode.c: Amara syntax tree identifier
 * subnode. An identifier does not have any atomic sense, so do not look
 * for the run time graph counter part of this class.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_identifier_subnode.h"

stt_identifier_subnode *
stt_identifier_subnode_default_constructor()
{
	stt_identifier_subnode * ret_;
	ret_ = malloc(sizeof(stt_identifier_subnode));
	ret_->value_ = NULL;
	return ret_;
}

stt_identifier_subnode *
stt_identifier_subnode_copy_constructor(const stt_identifier_subnode * subnode)
{
	stt_identifier_subnode * ret_;
	assertion(subnode != NULL);
	assertion(subnode->value_ != NULL);
	assertion(subnode->value_->value_ != NULL);
	ret_ = malloc(sizeof(stt_identifier_subnode));
	ret_->value_ = amara_string_copy_constructor(subnode->value_);
	return ret_;
}

void
stt_identifier_subnode_destructor(stt_identifier_subnode * subnode)
{
	assertion(subnode != NULL);
	if (subnode->value_ != NULL) {
		assertion(subnode->value_->value_ != NULL);
		amara_string_destructor(subnode->value_);
	}
	free(subnode);
}

void
stt_identifier_subnode_set_value(
		stt_identifier_subnode * subnode, amara_string * value)
{
	assertion(subnode != NULL);
	if (subnode->value_ != NULL) {
		amara_string_destructor(subnode->value_);
	}
	if (value != NULL) {
		subnode->value_ = amara_string_copy_constructor(value);
	}
}
