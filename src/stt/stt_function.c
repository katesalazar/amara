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
 * src/stt/stt_function.c: Amara syntax tree application function.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_operations_simple_list_destructor`. */
#include "stt_operations_simple_list.h"

/*   For own definitions. */
#include "stt_function.h"

stt_function *
stt_function_default_constructor()
{
	stt_function * ret_;
	ret_ = malloc(sizeof(stt_function));
	ret_->type_ = STT_FUNCTION_TYPE_INVALID;
	ret_->name_ = NULL;
	ret_->operations_ = NULL;
	return ret_;
}

stt_function *
stt_function_copy_constructor(const stt_function * function)
{
	stt_function * ret_;
	assertion(function != NULL);
	assertion(function->type_ != STT_FUNCTION_TYPE_INVALID);
	assertion(function->name_ != NULL);
	assertion(function->name_->value_ != NULL);
	assertion(function->operations_ != NULL);
	ret_ = malloc(sizeof(stt_function));
	ret_->operations_ = stt_operations_simple_list_copy_constructor(
			function->operations_);
	ret_->name_ = amara_string_copy_constructor(function->name_);
	ret_->type_ = function->type_;
	return ret_;
}

void
stt_function_destructor(stt_function * function)
{
	assertion(function != NULL);
	if (function->type_ == STT_FUNCTION_TYPE_INVALID) {
		assertion(function->name_ == NULL);
		assertion(function->operations_ == NULL);
	} else {
		assertion(function->type_ == STT_FUNCTION_TYPE_CLI_FUNCTION);
		assertion(function->name_ != NULL);
		amara_string_destructor(function->name_);
		assertion(function->operations_ != NULL);
		stt_operations_simple_list_destructor(function->operations_);
	}
	free(function);
}

void
stt_function_set_type(stt_function * function, uint_fast8_t type)
{
	assertion(function != NULL);
	assertion(type == STT_FUNCTION_TYPE_CLI_FUNCTION);
	assertion(function->type_ == STT_FUNCTION_TYPE_INVALID);
	assertion(function->name_ != NULL);
	assertion(function->operations_ != NULL);
	function->type_ = type;
}

void
stt_function_set_name(stt_function * function, const amara_string * name)
{
	assertion(function != NULL);
	assertion(name != NULL);
	assertion(function->type_ == STT_FUNCTION_TYPE_INVALID);
	assertion(function->name_ == NULL);
	function->name_ = amara_string_copy_constructor(name);
}

void
stt_function_set_operations(
		stt_function * function,
		const stt_operations_simple_list * operations)
{
	assertion(function != NULL);
	assertion(operations != NULL);
	assertion(function->type_ == STT_FUNCTION_TYPE_INVALID);
	assertion(function->operations_ == NULL);
	function->operations_ = stt_operations_simple_list_copy_constructor(
			operations);
}
