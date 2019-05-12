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
 * src/stt/stt_node_sub_call_options.c: Amara syntax tree node sub part.
 */

#include <stdlib.h>

#include "../asr/assertion.h"

#include "stt_node_sub_call_options.h"

stt_node_sub_call_options *
stt_node_sub_call_options_default_constructor()
{
	stt_node_sub_call_options * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_node_sub_call_options *)
#endif
			malloc(sizeof(stt_node_sub_call_options));
	forced_assertion(ret_ != NULL);

	/*   Uninitialized _ternary_ boolean variable, allow me. */
	ret_->builtin_function_ = NULL;

	return ret_;
}

stt_node_sub_call_options *
stt_node_sub_call_options_copy_constructor(
		const stt_node_sub_call_options * sub_call_options)
{
	stt_node_sub_call_options * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_node_sub_call_options *)
#endif
			malloc(sizeof(stt_node_sub_call_options));
	forced_assertion(ret_ != NULL);

	if (sub_call_options->builtin_function_ == NULL) {

		/*   Uninitialized _ternary_ boolean variable, allow me. */
		ret_->builtin_function_ = NULL;
	} else {

		ret_->builtin_function_ =
#ifdef AMARA_USE_STD_CXX98
				(amara_boolean *)
#endif
				malloc(sizeof(amara_boolean));
		forced_assertion(ret_->builtin_function_ != NULL);

		if ((* sub_call_options->builtin_function_) ==
				AMARA_BOOLEAN_TRUE) {

			(* ret_->builtin_function_) = AMARA_BOOLEAN_TRUE;
		} else {
			forced_assertion_two(
					(* sub_call_options->builtin_function_) ==
							AMARA_BOOLEAN_FALSE,
					"stt_node_sub_call_options.c: 73\n");

			(* ret_->builtin_function_) = AMARA_BOOLEAN_FALSE;
		}
	}

	return ret_;
}

void
stt_node_sub_call_options_destructor(stt_node_sub_call_options * sub)
{
	forced_assertion(sub != NULL);

	if (sub->builtin_function_ != NULL) {

		free(sub->builtin_function_);
	}

	free(sub);
}

void
stt_node_sub_call_options_set_builtin_function_true(
		stt_node_sub_call_options * sub)
{
	forced_assertion(sub != NULL);

	if (sub->builtin_function_ == NULL) {

		sub->builtin_function_ =
#ifdef AMARA_USE_STD_CXX98
				(amara_boolean *)
#endif
				malloc(sizeof(amara_boolean));
		forced_assertion(sub->builtin_function_ != NULL);
	}

	(* sub->builtin_function_) = AMARA_BOOLEAN_TRUE;
}
