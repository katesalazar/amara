/*
 * Copyright 2019 Mercedes Catherine Salazar
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
 * src/stt/stt_node_sub_expressions_list.c: Amara syntax tree node sub
 * part.
 */

#include "../asr/assertion.h"

#include "stt_node_sub_expressions_list.h"

stt_node_sub_expressions_list *
stt_node_sub_expressions_list_default_constructor()
{
	stt_node_sub_expressions_list * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_node_sub_expressions_list *)
#endif
			malloc(sizeof(stt_node_sub_expressions_list));
	forced_assertion(ret_ != NULL);

	ret_->expressions_list_ =
			stt_expressions_simple_list_default_constructor();
	forced_assertion(ret_->expressions_list_ != NULL);

	return ret_;
}

stt_node_sub_expressions_list *
stt_node_sub_expressions_list_copy_constructor(
		const stt_node_sub_expressions_list * sub_expressions_list)
{
	stt_node_sub_expressions_list * ret_;

#ifndef NDEBUG
	assertion(sub_expressions_list != NULL);
	assertion(sub_expressions_list->expressions_list_ != NULL);
#endif

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_node_sub_expressions_list *)
#endif
			malloc(sizeof(stt_node_sub_expressions_list));
	forced_assertion(ret_ != NULL);

	ret_->expressions_list_ = stt_expressions_simple_list_copy_constructor(
			sub_expressions_list->expressions_list_);

	return ret_;
}

void
stt_node_sub_expressions_list_destructor(stt_node_sub_expressions_list * sub)
{
#ifndef NDEBUG
	assertion(sub != NULL);
	assertion(sub->expressions_list_ != NULL);
#endif

	stt_expressions_simple_list_destructor(sub->expressions_list_);
	free(sub);
}
