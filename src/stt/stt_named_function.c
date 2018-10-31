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
 * src/stt/stt_named_function.c: Amara syntax tree application named
 * function.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_operations_simple_list_destructor`. */
#include "stt_operations_simple_list.h"

/*   For own definitions. */
#include "stt_named_function.h"

stt_named_function *
stt_named_function_default_constructor()
{
	stt_named_function * ret_;
	ret_ = malloc(sizeof(stt_named_function));
	ret_->type_ = STT_NAMED_FUNCTION_TYPE_INVALID;
	ret_->name_ = NULL;
	ret_->operations_ = NULL;
	return ret_;
}

stt_named_function *
stt_named_function_exhaustive_constructor(
		uint_fast8_t type,
		const amara_string * name,
		const stt_operations_simple_list * operations)
{
	stt_named_function * ret_;
	if (type == STT_NAMED_FUNCTION_TYPE_INVALID) {
		assertion(name == NULL);
		assertion(operations == NULL);
		ret_ = malloc(sizeof(stt_named_function));
		ret_->type_ = STT_NAMED_FUNCTION_TYPE_INVALID;
		ret_->name_ = NULL;
		ret_->operations_ = NULL;
		return ret_;
	}
	assertion(type == STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(name != NULL);
	assertion(name->value_ != NULL);
	assertion(operations != NULL);
	assertion(operations->first != NULL);
	assertion(operations->first->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(operations->first->args_ != NULL);
	assertion(operations->first->args_->first != NULL);
	/* .... but many of this has to be removed anyway */
	assertion(operations->first->args_->next == NULL);
	assertion(operations->next == NULL);
	ret_ = malloc(sizeof(stt_named_function));
	ret_->type_ = STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION;
	ret_->name_ = amara_string_copy_constructor(name);
	ret_->operations_ = stt_operations_simple_list_copy_constructor(
			operations);
	return ret_;
}

stt_named_function *
stt_named_function_copy_constructor(const stt_named_function * named_function)
{
	stt_named_function * ret_;
	assertion(named_function != NULL);
	assertion(named_function->type_ != STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function->name_ != NULL);
	assertion(named_function->name_->value_ != NULL);
	assertion(named_function->operations_ != NULL);
	ret_ = malloc(sizeof(stt_named_function));
	ret_->operations_ = stt_operations_simple_list_copy_constructor(
			named_function->operations_);
	ret_->name_ = amara_string_copy_constructor(named_function->name_);
	ret_->type_ = named_function->type_;
	return ret_;
}

void
stt_named_function_destructor(stt_named_function * named_function)
{
	assertion(named_function != NULL);
	if (named_function->type_ == STT_NAMED_FUNCTION_TYPE_INVALID) {
		assertion(named_function->name_ == NULL);
		assertion(named_function->operations_ == NULL);
	} else {
		assertion(named_function->type_ ==
				STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
		assertion(named_function->name_ != NULL);
		amara_string_destructor(named_function->name_);
		assertion(named_function->operations_ != NULL);
		stt_operations_simple_list_destructor(
				named_function->operations_);
	}
	free(named_function);
}

void
stt_named_function_set_type(
		stt_named_function * named_function, uint_fast8_t type)
{
	assertion(named_function != NULL);
	assertion(type == STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(named_function->type_ == STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function->name_ != NULL);
	assertion(named_function->operations_ != NULL);
	named_function->type_ = type;
}

void
stt_named_function_set_name(
		stt_named_function * named_function, const amara_string * name)
{
	assertion(named_function != NULL);
	assertion(name != NULL);
	assertion(named_function->type_ == STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function->name_ == NULL);
	named_function->name_ = amara_string_copy_constructor(name);
}

void
stt_named_function_set_operations(
		stt_named_function * named_function,
		const stt_operations_simple_list * operations)
{
	assertion(named_function != NULL);
	assertion(operations != NULL);
	assertion(named_function->type_ == STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function->operations_ == NULL);
	named_function->operations_ =
			stt_operations_simple_list_copy_constructor(
					operations);
}
