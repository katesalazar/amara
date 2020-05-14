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
 * src/rtg/rtg_named_function_call.c: Amara runtime graph named function
 * call.
 */

#include "../asr/assertion.h"

#include "rtg_named_function_call.h"

void
rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function_ret_destructor(
		rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function_ret * input_ret)
{
	forced_assertion(input_ret != NULL);
	forced_assertion(input_ret->status == RTG_NAMED_FUNCTION_CALL_OUT_OF_STT_NAMED_FUNCTION_CALL_AND_RTG_NAMED_FUNCTION_RET_STATUS_INVALID);
	forced_assertion(input_ret->error_messages == NULL);
	forced_assertion(input_ret->named_function_call == NULL);
}

rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function_ret *
rtg_named_function_call_out_of_stt_named_function_call_and_rtg_named_function(
		const stt_named_function_call * named_function_call,
		const rtg_named_function * named_function)
{
	forced_assertion(named_function_call == NULL);  /* XXX */
	forced_assertion(named_function == NULL);  /* XXX */

	forced_assertion(0);  /* XXX */
	return NULL;  /* XXX */
}
