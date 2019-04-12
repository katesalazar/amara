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
 * src/stt/stt_named_function_subnode.c: Amara syntax tree application
 * named function subnode.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `STT_NAMED_FUNCTION_TYPE_INVALID`. */
#include "stt_named_function.h"

/*   For own definitions. */
#include "stt_named_function_subnode.h"

stt_named_function_subnode *
stt_named_function_subnode_default_constructor()
{
	stt_named_function_subnode * returning_ =
			malloc(sizeof(stt_named_function_subnode));

	returning_->type_ = STT_NAMED_FUNCTION_SUBNODE_TYPE_INVALID;
	returning_->name_ = NULL;
	returning_->operations_ = NULL;
	returning_->where_value_bindings_ = NULL;

	return returning_;
}

stt_named_function_subnode *
stt_named_function_subnode_copy_constructor(
		const stt_named_function_subnode * subnode)
{
	stt_named_function_subnode * ret_;

	assertion(subnode != NULL);
	assertion(subnode->type_ != STT_NAMED_FUNCTION_SUBNODE_TYPE_INVALID);
	assertion(subnode->name_ != NULL);
	assertion(subnode->operations_ != NULL);
	assertion(subnode->where_value_bindings_ != NULL);

	ret_ = malloc(sizeof(stt_named_function_subnode));

	ret_->where_value_bindings_ =
			stt_where_value_bindings_simple_list_copy_constructor(
					subnode->where_value_bindings_);

	ret_->operations_ = stt_operations_simple_list_copy_constructor(
			subnode->operations_);

	ret_->name_ = amara_string_copy_constructor(subnode->name_);

	assertion(subnode->type_ ==
			STT_NAMED_FUNCTION_SUBNODE_TYPE_CLI_APP_NAMED_FUNCTION);
	ret_->type_ = subnode->type_;

	return ret_;
}

stt_named_function_subnode *
stt_named_function_subnode_exhaustive_constructor(
		const stt_named_function * named_function)
{
	stt_named_function_subnode * ret_;

	assertion(named_function != NULL);
	assertion(named_function->type_ != STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function->name_ != NULL);
	assertion(named_function->operations_ != NULL);

	ret_ = malloc(sizeof(stt_named_function_subnode));

	ret_->where_value_bindings_ =
			stt_where_value_bindings_simple_list_copy_constructor(
					named_function->where_value_bindings_);

	ret_->operations_ = stt_operations_simple_list_copy_constructor(
			named_function->operations_);

	ret_->name_ = amara_string_copy_constructor(named_function->name_);

	assertion(named_function->type_ ==
			STT_NAMED_FUNCTION_TYPE_CLI_APP_NAMED_FUNCTION);
	ret_->type_ = STT_NAMED_FUNCTION_SUBNODE_TYPE_CLI_APP_NAMED_FUNCTION;

	return ret_;
}

void
stt_named_function_subnode_destructor(stt_named_function_subnode * subnode)
{
	assertion(subnode != NULL);
	if (subnode->type_ == STT_NAMED_FUNCTION_SUBNODE_TYPE_INVALID) {
		assertion(subnode->name_ == NULL);
		assertion(subnode->operations_ == NULL);
	} else {
		assertion(subnode->name_ != NULL);
		amara_string_destructor(subnode->name_);
		/*
		subnode->name_ = NULL;
		*/
		assertion(subnode->operations_ != NULL);
		stt_operations_simple_list_destructor(subnode->operations_);
		/*
		subnode->operations_ = NULL;
		*/
#ifndef NDEBUG
		assertion(subnode->where_value_bindings_ != NULL);
#endif
		stt_where_value_bindings_simple_list_destructor(
				subnode->where_value_bindings_);
	}
	free(subnode);
}
