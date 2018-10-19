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

#include "../asr/assertion.h"

#include "stt_where_value_bindings_subnode.h"

stt_where_value_bindings_subnode *
stt_where_value_bindings_subnode_exhaustive_constructor(
		const stt_where_value_bindings_simple_list * list)
{
	stt_where_value_bindings_subnode * returning_;

	assertion(list != NULL);

	returning_ = malloc(sizeof(stt_where_value_bindings_subnode));

	returning_->where_value_bindings_ =
			stt_where_value_bindings_simple_list_copy_constructor(
					list);

	return returning_;
}
