/*
 * Copyright 2018-2019 Mercedes Catherine Salazar
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

void
assertion(int expression)
;

/*   For `stt_operations_simple_list_destructor`. */
#include "stt_operations_simple_list.h"

/*   For own declarations: `STT_NAMED_FUNCTION_TYPE_INVALID` and others. */
#include "stt_named_function.h"

stt_named_function *
stt_named_function_default_constructor()
{
	stt_named_function * ret_;
	ret_ = malloc(sizeof(stt_named_function));
	ret_->type_ = STT_NAMED_FUNCTION_TYPE_INVALID;
	ret_->name_ = NULL;
	ret_->operations_ = NULL;
	ret_->where_value_bindings_ = NULL;
	return ret_;
}

stt_named_function *
stt_named_function_exhaustive_constructor(
		unsigned char type, const amara_string * name,
		const stt_operations_simple_list * operations,
		const stt_where_value_bindings_simple_list * where_value_bindings_)
{
	stt_named_function * ret_;
	if (type == STT_NAMED_FUNCTION_TYPE_INVALID) {
		assertion(name == NULL);
		assertion(operations == NULL);
		assertion(where_value_bindings_ == NULL);
		ret_ = malloc(sizeof(stt_named_function));
		ret_->type_ = STT_NAMED_FUNCTION_TYPE_INVALID;
		ret_->name_ = NULL;
		ret_->operations_ = NULL;
		ret_->where_value_bindings_ = NULL;
		return ret_;
	}
	assertion(type == STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(name != NULL);
	assertion(name->value_ != NULL);
	assertion(operations != NULL);
	/*
	assertion(operations->first != NULL);
	assertion(operations->first->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(operations->first->args_ != NULL);
	assertion(operations->first->args_->first != NULL);
	*/
	/* .... but many of this has to be removed anyway */
	/*
	assertion(operations->first->args_->next == NULL);
	assertion(operations->next == NULL);
	*/

	ret_ = malloc(sizeof(stt_named_function));
	forced_assertion(ret_ != NULL);
	ret_->type_ = STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION;
	ret_->name_ = amara_string_copy_constructor(name);
	ret_->operations_ = stt_operations_simple_list_copy_constructor(
			operations);

	if (where_value_bindings_ != NULL) {

	ret_->where_value_bindings_ =
			stt_where_value_bindings_simple_list_copy_constructor(
					where_value_bindings_);
	} else {
		ret_->where_value_bindings_ =
				stt_where_value_bindings_simple_list_default_constructor();
	}

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
	assertion(named_function->where_value_bindings_ != NULL);
	ret_ = malloc(sizeof(stt_named_function));
	ret_->operations_ = stt_operations_simple_list_copy_constructor(
			named_function->operations_);
	ret_->where_value_bindings_ =
			stt_where_value_bindings_simple_list_copy_constructor(
					named_function->where_value_bindings_);
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
		stt_named_function * named_function, unsigned char type)
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

stt_named_function *
stt_named_function_out_of_stt_named_function_subnode(
		const stt_named_function_subnode * named_function_subnode)
{
	stt_named_function * returning_;
	amara_boolean equality_;

	assertion(named_function_subnode != NULL);
	assertion(named_function_subnode->type_ !=
			STT_NAMED_FUNCTION_SUBNODE_TYPE_INVALID);
	assertion(named_function_subnode->name_ != NULL);
	assertion(named_function_subnode->name_->value_ != NULL);
	assertion(named_function_subnode->operations_ != NULL);
	assertion(named_function_subnode->where_value_bindings_ != NULL);

	assertion(named_function_subnode->type_ ==
			STT_NAMED_FUNCTION_SUBNODE_TYPE_CLI_APP_NAMED_FUNCTION);

	returning_ = stt_named_function_exhaustive_constructor(
			STT_NAMED_FUNCTION_TYPE_CLI_APP_NAMED_FUNCTION,
			named_function_subnode->name_,
			named_function_subnode->operations_,
			named_function_subnode->where_value_bindings_);
	assertion(returning_ != NULL);
	assertion(returning_->type_ ==
			STT_NAMED_FUNCTION_TYPE_CLI_APP_NAMED_FUNCTION);
	assertion(returning_->name_ != NULL);
	assertion(returning_->name_->value_ != NULL);
	equality_ = amara_string_equality(
			named_function_subnode->name_, returning_->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(returning_->operations_ != NULL);
	assertion(returning_->where_value_bindings_ != NULL);

	return returning_;
}
