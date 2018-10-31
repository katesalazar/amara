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
 * src/stt/stt_operations_list_subnode.c: Amara syntax tree application
 * function operations list subnode.
 */

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_operations_list_subnode.h"

stt_operations_list_subnode *
stt_operations_list_subnode_default_constructor()
{
	stt_operations_list_subnode * returning_;

	returning_ = malloc(sizeof(stt_operations_list_subnode));

	returning_->operations_ = NULL;

	return returning_;
}

stt_operations_list_subnode *
stt_operations_list_subnode_copy_constructor(
		const stt_operations_list_subnode * subnode)
{
	stt_operations_list_subnode * ret_;

	assertion(subnode != NULL);
	assertion(subnode->operations_ != NULL);

	ret_ = malloc(sizeof(stt_operations_list_subnode));

	ret_->operations_ = stt_operations_simple_list_copy_constructor(
			subnode->operations_);

	return ret_;
}

stt_operations_list_subnode *
stt_operations_list_subnode_exhaustive_constructor(
		const stt_operations_simple_list * operations)
{
	stt_operations_list_subnode * ret_;

	assertion(operations != NULL);

	ret_ = malloc(sizeof(stt_operations_list_subnode));

	ret_->operations_ = stt_operations_simple_list_copy_constructor(
			operations);

	return ret_;
}

void
stt_operations_list_subnode_destructor(stt_operations_list_subnode * subnode)
{
	assertion(subnode != NULL);
	if (subnode->operations_ != NULL) {
		stt_operations_simple_list_destructor(subnode->operations_);
	}
	free(subnode);
}
