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
 * src/stt/stt_operation_subnode.c: Amara syntax tree application
 * function operation subnode.
 */

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_operation_subnode.h"

stt_operation_subnode *
stt_operation_subnode_default_constructor()
{
	stt_operation_subnode * ret_ = malloc(sizeof(stt_operation_subnode));
	ret_->operation_ = NULL;
	return ret_;
}

stt_operation_subnode *
stt_operation_subnode_copy_constructor(const stt_operation_subnode * subnode)
{
	stt_operation_subnode * ret_;
	assertion(subnode != NULL);
	assertion(subnode->operation_ != NULL);
	assertion(subnode->operation_->type_ != STT_OPERATION_TYPE_INVALID);
	ret_ = malloc(sizeof(stt_operation_subnode));
	ret_->operation_ = stt_operation_copy_constructor(subnode->operation_);
	return ret_;
}

void
stt_operation_subnode_destructor(stt_operation_subnode * subnode)
{
	assertion(subnode != NULL);
	if (subnode->operation_ != NULL) {
		stt_operation_destructor(subnode->operation_);
	}
	free(subnode);
}

