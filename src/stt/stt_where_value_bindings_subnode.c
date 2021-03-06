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
 * src/stt/stt_where_value_bindings_subnode.c: Amara syntax tree _where_
 * value bindings subnode.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

#include "stt_where_value_bindings_subnode.h"

stt_where_value_bindings_subnode *
stt_where_value_bindings_subnode_default_constructor()
{
	stt_where_value_bindings_subnode * returning_;

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_where_value_bindings_subnode *)
#endif
			malloc(sizeof(stt_where_value_bindings_subnode));
	forced_assertion(returning_ != NULL);

	returning_->where_value_bindings_ = NULL;

	return returning_;
}

stt_where_value_bindings_subnode *
stt_where_value_bindings_subnode_exhaustive_constructor(
		const stt_where_value_bindings_simple_list * list)
{
	stt_where_value_bindings_subnode * returning_;

	assertion(list != NULL);

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_where_value_bindings_subnode *)
#endif
			malloc(sizeof(stt_where_value_bindings_subnode));
	forced_assertion(returning_ != NULL);

	returning_->where_value_bindings_ =
			stt_where_value_bindings_simple_list_copy_constructor(
					list);
	forced_assertion(returning_->where_value_bindings_ != NULL);
	if (list->first == NULL) {
#ifndef NDEBUG
		assertion(returning_->where_value_bindings_->first == NULL);
#endif
	} else {
		forced_assertion(returning_->where_value_bindings_->first != NULL);
	}

	return returning_;
}

stt_where_value_bindings_subnode *
stt_where_value_bindings_subnode_copy_constructor(
		const stt_where_value_bindings_subnode * stt_where_value_bindings_subnode_)
{
	stt_where_value_bindings_subnode * returning_;

	assertion(stt_where_value_bindings_subnode_ != NULL);
	assertion(stt_where_value_bindings_subnode_->where_value_bindings_ !=
			NULL);

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_where_value_bindings_subnode *)
#endif
			malloc(sizeof(stt_where_value_bindings_subnode));
	forced_assertion(returning_ != NULL);

	returning_->where_value_bindings_ =
			stt_where_value_bindings_simple_list_copy_constructor(
					stt_where_value_bindings_subnode_->where_value_bindings_);
	forced_assertion(returning_->where_value_bindings_ != NULL);

	return returning_;
}

void
stt_where_value_bindings_subnode_destructor(
		stt_where_value_bindings_subnode * stt_where_value_bindings_subnode_)
{
	assertion(stt_where_value_bindings_subnode_ != NULL);

	if (stt_where_value_bindings_subnode_->where_value_bindings_ != NULL) {

		stt_where_value_bindings_simple_list_destructor(
				stt_where_value_bindings_subnode_->where_value_bindings_);
	}

	free(stt_where_value_bindings_subnode_);
}
