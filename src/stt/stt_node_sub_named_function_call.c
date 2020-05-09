/*
 * Copyright 2020 Mercedes Catherine Salazar
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
 * src/stt/stt_node_sub_named_function_call.c: A syntax tree node can
 * represent a function call. If so, it holds some information that is
 * stored in this "sub" enttity.
 */

/*
#include <stdlib.h>
*/

#include "../asr/assertion.h"

#include "../mmm/allocator.h"

#include "stt_named_function_call.h"

#include "stt_node_sub_named_function_call.h"

/**  Forward declaration. */
struct stt_node *
stt_node_copy_constructor(const struct stt_node * node)
__amara__warn_unused_result__
;

stt_node_sub_named_function_call *
stt_node_sub_named_function_call_copy_constructor(
		const stt_node_sub_named_function_call * node_sub_named_function_call)
{
	stt_node_sub_named_function_call * returning_;

	forced_assertion(node_sub_named_function_call != NULL);
#ifndef NDEBUG
	assertion(node_sub_named_function_call->named_function_call_ != NULL);
	assertion(node_sub_named_function_call->named_function_call_->function_name_identifier_ != NULL);
	assertion(node_sub_named_function_call->named_function_call_->pending_semantic_checks_ != NULL);
#endif

#ifdef AMARA_USE_STD_CXX98
	returning_ = (stt_node_sub_named_function_call *) malloc(sizeof(stt_node_sub_named_function_call));
#else
	returning_ = malloc(sizeof(stt_node_sub_named_function_call));
#endif
	forced_assertion(returning_ != NULL);

	returning_->named_function_call_ = stt_named_function_call_copy_constructor(node_sub_named_function_call->named_function_call_);
	forced_assertion(returning_->named_function_call_ != NULL);

	return returning_;
}

stt_node_sub_named_function_call *
stt_node_sub_named_function_call_exhaustive_constructor(
		struct stt_named_function_call * named_function_call)
{
	stt_node_sub_named_function_call * returning_;

#ifdef AMARA_USE_STD_CXX98
	returning_ = (stt_node_sub_named_function_call *) amara_malloc(sizeof(stt_node_sub_named_function_call));
#else
	returning_ = amara_malloc(sizeof(stt_node_sub_named_function_call));
#endif
	forced_assertion(returning_ != NULL);

	returning_->named_function_call_ = stt_named_function_call_copy_constructor(named_function_call);
	forced_assertion(returning_->named_function_call_ != NULL);

	return returning_;
}

/**  Friend declaration. */
void
stt_node_destructor(struct stt_node const * node)
;

void
stt_node_sub_named_function_call_destructor(
		stt_node_sub_named_function_call  * sfc)
{
#ifndef NDEBUG
	assertion(sfc->function_name_identifier_ != NULL);
#endif
	stt_node_destructor(sfc->function_name_identifier_);

#ifndef NDEBUG
	assertion(sfc->call_arguments_ != NULL);
#endif
	stt_node_destructor(sfc->call_arguments_);

#ifndef NDEBUG
	assertion(sfc->pending_semantic_checks_ != NULL);
#endif
	free(sfc->pending_semantic_checks_);
	free(sfc);
}

/**  Friend declaration. */
amara_boolean
stt_nodes_equality(const struct stt_node * n0, const struct stt_node * n1)
__amara__warn_unused_result__
;

amara_boolean
stt_node_sub_named_function_call_equality(
		const stt_node_sub_named_function_call * s0,
		const stt_node_sub_named_function_call * s1)
{
	amara_boolean equality_;

	forced_assertion(s0 != NULL);
	forced_assertion(s1 != NULL);

	forced_assertion(s0->function_name_identifier_ != NULL);
	/*
	forced_assertion(s0->function_name_identifier_->value_ != NULL);
	*/
	forced_assertion(s1->function_name_identifier_ != NULL);
	/*
	forced_assertion(s1->function_name_identifier_->value_ != NULL);
	equality_ = amara_strings_equality(s0->function_name_identifier_,
	                                   s1->function_name_identifier_);
	*/
	equality_ = stt_nodes_equality(s0->function_name_identifier_,
	                               s1->function_name_identifier_);
	if (equality_ == AMARA_BOOLEAN_FALSE) {
		return AMARA_BOOLEAN_FALSE;
	}

	forced_assertion(s0->call_arguments_ != NULL);
	forced_assertion(s1->call_arguments_ != NULL);
	return stt_nodes_equality(s0->call_arguments_, s1->call_arguments_);

	/*   Pending semantic checks remain TODO at this function. */
}
