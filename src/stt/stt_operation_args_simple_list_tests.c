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
 * src/stt/stt_operation_args_simple_list_tests.c: Test the Amara syntax
 * tree application function operation arguments simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_operation_args_simple_list`. */
#include "stt_operation_args_simple_list.h"

void
stt_operation_args_simple_list_copy_constructor_test_0()
{
	stt_operation_args_simple_list * stt_operation_args_simple_list_original;
	const stt_operation_args_simple_list * stt_operation_args_simple_list_clone;
	stt_operation_args_simple_list_original =
			stt_operation_args_simple_list_default_constructor();
	stt_operation_args_simple_list_clone =
			stt_operation_args_simple_list_copy_constructor(
					stt_operation_args_simple_list_original);
	assertion(stt_operation_args_simple_list_original != NULL);
	assertion(stt_operation_args_simple_list_original->first == NULL);
	assertion(stt_operation_args_simple_list_original->next == NULL);
	assertion(stt_operation_args_simple_list_clone != NULL);
	assertion(stt_operation_args_simple_list_clone->first == NULL);
	assertion(stt_operation_args_simple_list_clone->next == NULL);
}

void
stt_operation_args_simple_list_copy_constructor_tests()
{
	stt_operation_args_simple_list_copy_constructor_test_0();
}

void
stt_operation_args_simple_list_tests()
{
	stt_operation_args_simple_list_copy_constructor_tests();
}
