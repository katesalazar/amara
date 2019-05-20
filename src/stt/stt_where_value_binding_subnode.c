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
 * src/stt/stt_where_binding_subnode.c: Amara syntax tree _where_ value
 * binding sub node.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

#include "stt_where_value_binding_subnode.h"

stt_where_value_binding_subnode *
stt_where_value_binding_subnode_default_constructor()
{
	stt_where_value_binding_subnode * returning_;

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_where_value_binding_subnode *)
#endif
			malloc(sizeof(stt_where_value_binding_subnode));
	forced_assertion(returning_ != NULL);

	returning_->where_value_binding_ = NULL;

	return returning_;
}

stt_where_value_binding_subnode *
stt_where_value_binding_subnode_exhaustive_constructor(
		const stt_where_value_binding * where_value_binding)
{
	stt_where_value_binding_subnode * returning_;

#ifndef NDEBUG
	assertion(where_value_binding != NULL);
	assertion(where_value_binding->value_name_ != NULL);
	assertion(where_value_binding->value_expression_ != NULL);
	assertion(where_value_binding->value_expression_->type_ !=
			STT_EXPRESSION_TYPE_INVALID);
#endif

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_where_value_binding_subnode *)
#endif
			malloc(sizeof(stt_where_value_binding_subnode));
	forced_assertion(returning_ != NULL);

	returning_->where_value_binding_ =
			stt_where_value_binding_copy_constructor(
					where_value_binding);
	forced_assertion(returning_->where_value_binding_ != NULL);

	return returning_;
}

stt_where_value_binding_subnode *
stt_where_value_binding_subnode_copy_constructor(
		const stt_where_value_binding_subnode * where_value_binding_subnode_)
{
	stt_where_value_binding_subnode * returning_;

#ifndef NDEBUG
	assertion(where_value_binding_subnode_ != NULL);
	assertion(where_value_binding_subnode_->where_value_binding_ != NULL);
	assertion(where_value_binding_subnode_->where_value_binding_->value_name_ !=
			NULL);
	assertion(where_value_binding_subnode_->where_value_binding_->value_name_->value_ !=
			NULL);
	assertion(where_value_binding_subnode_->where_value_binding_->value_expression_ !=
			NULL);
	assertion(where_value_binding_subnode_->where_value_binding_->value_expression_->type_ !=
			STT_EXPRESSION_TYPE_INVALID);
#endif

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_where_value_binding_subnode *)
#endif
			malloc(sizeof(stt_where_value_binding_subnode));
	forced_assertion(returning_ != NULL);

	returning_->where_value_binding_ =
			stt_where_value_binding_copy_constructor(
					where_value_binding_subnode_->where_value_binding_);
	forced_assertion(returning_->where_value_binding_ != NULL);

	return returning_;
}

void
stt_where_value_binding_subnode_destructor(
		stt_where_value_binding_subnode * stt_where_value_binding_subnode_)
{
#ifndef NDEBUG
	assertion(stt_where_value_binding_subnode_ != NULL);
#endif

	if (stt_where_value_binding_subnode_->where_value_binding_ != NULL) {

#ifndef NDEBUG
		assertion(stt_where_value_binding_subnode_->where_value_binding_->value_name_ !=
				NULL);
		assertion(stt_where_value_binding_subnode_->where_value_binding_->value_name_->value_ !=
				NULL);
		assertion(stt_where_value_binding_subnode_->where_value_binding_->value_expression_ !=
				NULL);
		assertion(stt_where_value_binding_subnode_->where_value_binding_->value_expression_->type_ !=
				STT_EXPRESSION_TYPE_INVALID);
#endif

		stt_where_value_binding_destructor(
				stt_where_value_binding_subnode_->where_value_binding_);
	}

	free(stt_where_value_binding_subnode_);
}
