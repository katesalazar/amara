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
 * src/stt/stt_named_function_call.c: TODO
 */

/*   For `NULL`. */
#include <stdlib.h>

#include "../macros.h"

#include "../asr/assertion.h"

#include "../mmm/allocator.h"

#include "../stt/stt_node.h"

#include "stt_named_function_call.h"

stt_named_function_call *
stt_named_function_call_copy_constructor(
		const stt_named_function_call * named_function_call)
{
	stt_named_function_call * returning_;

	forced_assertion(named_function_call != NULL);
#ifndef NDEBUG
	assertion(named_function_call->function_name_identifier_ != NULL);
	stt_node_assertion_clean_identifier_node(named_function_call->function_name_identifier_);
	assertion(named_function_call->call_arguments_ != NULL);
	stt_node_assertion_clean_named_function_call_arguments_list_node(named_function_call->call_arguments_);
#endif

#if defined AMARA_USE_STD_C89
	returning_ = amara_malloc(sizeof(stt_named_function_call));
#elif defined AMARA_USE_STD_CXX98
	returning_ = (stt_named_function_call *) amara_malloc(sizeof(stt_named_function_call));
#else
	PREPROCESSOR_ASSERT(AMARA_BOOLEAN_FALSE, stt_named_function_call);
#endif
	forced_assertion(returning_ != NULL);

	returning_->function_name_identifier_ = stt_node_copy_constructor(named_function_call->function_name_identifier_);
	forced_assertion(returning_->function_name_identifier_ != NULL);

	returning_->call_arguments_ = stt_node_copy_constructor(named_function_call->call_arguments_);
	forced_assertion(returning_->call_arguments_ != NULL);

	return returning_;
}

stt_named_function_call *
stt_named_function_call_exhaustive_constructor(
		const struct stt_node * function_name_identifier,
		const struct stt_node * call_arguments)
{
	stt_named_function_call * returning_;

	forced_assertion(function_name_identifier != NULL);
	stt_node_forced_assertion_clean_identifier_node(function_name_identifier);
	forced_assertion(call_arguments != NULL);
	stt_node_forced_assertion_clean_named_function_call_arguments_list_node(call_arguments);

#if defined AMARA_USE_STD_C89
	returning_ = amara_malloc(sizeof(stt_named_function_call));
#elif defined AMARA_USE_STD_CXX98
	returning_ = (stt_named_function_call *) amara_malloc(sizeof(stt_named_function_call));
#else
	PREPROCESSOR_ASSERT(AMARA_BOOLEAN_FALSE, stt_named_function_call);
#endif
	forced_assertion(returning_ != NULL);

	returning_->function_name_identifier_ = stt_node_copy_constructor(function_name_identifier);
	forced_assertion(returning_->function_name_identifier_ != NULL);

	returning_->call_arguments_ = stt_node_copy_constructor(call_arguments);
	forced_assertion(returning_->call_arguments_ != NULL);

	return returning_;
}

void
stt_named_function_call_destructor(stt_named_function_call * nfc)
{
	forced_assertion(nfc != NULL);

	forced_assertion(0);  /* XXX */
}

amara_boolean
stt_named_function_call_equality(
		const stt_named_function_call * nfc0,
		const stt_named_function_call * nfc1)
{
	forced_assertion(nfc0 != NULL);
	forced_assertion(nfc1 != NULL);

	forced_assertion(0);  /* XXX */
	return AMARA_BOOLEAN_FALSE;  /* XXX */
}

amara_boolean
stt_named_function_calls_equality(
		const stt_named_function_call * nfc0,
		const stt_named_function_call * nfc1)
{
	return stt_named_function_call_equality(nfc0, nfc1);
}
