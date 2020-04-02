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
 * src/stt/stt_node_sub_function_call.c: A syntax tree node can
 * represent a function call. If so, it holds some information that is
 * stored in this "sub" enttity.
 */

#include <stdlib.h>

#include "../asr/assertion.h"

#include "stt_node_sub_function_call.h"

/**  Forward declaration. */
struct stt_node *
stt_node_copy_constructor(const struct stt_node * node)
__amara__warn_unused_result__
;

stt_node_sub_function_call *
stt_node_sub_function_call_copy_constructor(
		const stt_node_sub_function_call * sub_function_call)
{
	stt_node_sub_function_call_pending_semantic_checks * returning_pending_semantic_checks_;
	stt_node_sub_function_call * returning_;

	forced_assertion(sub_function_call != NULL);
	forced_assertion(sub_function_call->pending_semantic_checks_ != NULL);

	returning_pending_semantic_checks_ =
#ifdef USE_STD_CXX_98
			(stt_node_sub_function_call_pending_semantic_checks *)
#endif
			malloc(sizeof(stt_node_sub_function_call_pending_semantic_checks));
	forced_assertion(returning_pending_semantic_checks_ != NULL);

	returning_pending_semantic_checks_->called_function_has_no_return_value_ =
			AMARA_BOOLEAN_FALSE;

	returning_ =
#ifdef USE_STD_CXX_98
			(stt_node_sub_function_call *)
#endif
			malloc(sizeof(stt_node_sub_function_call));
	forced_assertion(returning_ != NULL);

	returning_->pending_semantic_checks_ =
			returning_pending_semantic_checks_;

	returning_->function_name_identifier_ = stt_node_copy_constructor(
			sub_function_call->function_name_identifier_);
	forced_assertion(returning_->function_name_identifier_ != NULL);

	returning_->call_arguments_ = stt_node_copy_constructor(
			sub_function_call->call_arguments_);
	forced_assertion(returning_->call_arguments_ != NULL);

	return returning_;
}

stt_node_sub_function_call *
stt_node_sub_function_call_exhaustive_constructor(
		struct stt_node * function_name_identifier,
		struct stt_node * call_arguments)
{
	stt_node_sub_function_call * returning_;
	stt_node_sub_function_call_pending_semantic_checks * returning_pending_semantic_checks_;

	returning_ =
#ifdef USE_STD_CXX_98
			(stt_node_sub_function_call *)
#endif
			malloc(sizeof(stt_node_sub_function_call));
	forced_assertion(returning_ != NULL);

	returning_->function_name_identifier_ =
			/*
			stt_node_copy_constructor(
			*/
					function_name_identifier
			/*
			)
			*/
			;
	forced_assertion(returning_->function_name_identifier_ != NULL);

	returning_->call_arguments_ =
			/*
			stt_node_copy_constructor(
			*/
					call_arguments
			/*
			)
			*/
			;
	forced_assertion(returning_->call_arguments_ != NULL);

	returning_pending_semantic_checks_ =
#ifdef USE_STD_CXX_98
			(stt_node_sub_function_call_pending_semantic_checks *)
#endif
			malloc(sizeof(stt_node_sub_function_call_pending_semantic_checks));
	forced_assertion(returning_pending_semantic_checks_ != NULL);

	returning_pending_semantic_checks_->called_function_has_no_return_value_ =
			0;

	returning_->pending_semantic_checks_ =
			returning_pending_semantic_checks_;

	return returning_;
}
