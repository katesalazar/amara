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
 * src/stt/stt_expression_subnode.c: Amara syntax tree expression
 * subnode.
 */

/*   For `typedef struct stt_expression_subnode { ... }
 * stt_expression_subnode`. */
#include "stt_expression_subnode.h"

stt_expression_subnode *
stt_expression_subnode_exhaustive_constructor(
		const stt_expression * expression)
{
	stt_expression_subnode * returning_;

	assertion(expression != NULL);
	assertion(expression->type_ != STT_EXPRESSION_TYPE_INVALID);

	returning_ = malloc(sizeof(stt_expression_subnode));

	returning_->expression_ = stt_expression_copy_constructor(expression);
	assertion(returning_->expression_ != NULL);

	return returning_;
}

stt_expression_subnode *
stt_expression_subnode_copy_constructor(
		const stt_expression_subnode * expression_subnode)
{
	stt_expression_subnode * returning_;

	assertion(expression_subnode != NULL);
	assertion(expression_subnode->expression_ != NULL);
	assertion(expression_subnode->expression_->type_ !=
			STT_EXPRESSION_TYPE_INVALID);

	returning_ = malloc(sizeof(stt_expression_subnode));

	returning_->expression_ = stt_expression_copy_constructor(
			expression_subnode->expression_);
	assertion(returning_->expression_ != NULL);

	return returning_;
}

void
stt_expression_subnode_destructor(stt_expression_subnode * subnode)
{
	assertion(subnode != NULL);
	assertion(subnode->expression_ != NULL);
	stt_expression_destructor(subnode->expression_);
	free(subnode);
}
