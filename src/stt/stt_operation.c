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
 * src/stt/stt_operation.c: Amara syntax tree application function
 * operation.
 */

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_operation.h"

stt_operation *
stt_operation_default_constructor()
{
	stt_operation * returning_ = malloc(sizeof(stt_operation));
	returning_->type_ = STT_OPERATION_TYPE_INVALID;
	returning_->args_ = NULL;
	return returning_;
}

stt_operation *
stt_operation_copy_constructor(const stt_operation * operation)
{
	stt_operation * ret_;
	assertion(operation != NULL);
	assertion(operation->type_ != STT_OPERATION_TYPE_INVALID);
	ret_ = malloc(sizeof(stt_operation));
	ret_->args_ = stt_operation_args_simple_list_copy_constructor(
			operation->args_);
	ret_->type_ = operation->type_;
	return ret_;
}

void
stt_operation_destructor(stt_operation * operation)
{
	assertion(operation != NULL);
	if (operation->type_ == STT_OPERATION_TYPE_INVALID) {
		assertion(operation->args_ == NULL);
	} else if (operation->type_ == STT_OPERATION_TYPE_PRINT) {
		assertion(operation->args_ != NULL);
		stt_operation_args_simple_list_destructor(operation->args_);
	} else {
		assertion(operation->type_ ==
				STT_OPERATION_TYPE_PRINT_NO_CRLF);
		assertion(operation->args_ != NULL);
		stt_operation_args_simple_list_destructor(operation->args_);
	}
	free(operation);
}

