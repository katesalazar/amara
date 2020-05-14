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

#include "../asr/assertion.h"

#include "stt_named_function_call.h"

stt_named_function_call *
stt_named_function_call_exhaustive_constructor(
		const struct stt_node * function_name_identifier,
		const struct stt_node * call_arguments)
{
	forced_assertion(function_name_identifier == NULL);  /* XXX */
	forced_assertion(call_arguments == NULL);  /* XXX */

	forced_assertion(0);  /* XXX */
	return NULL;  /* XXX */
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
