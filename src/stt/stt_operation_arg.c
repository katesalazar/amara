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
 * src/stt/stt_operation_arg.c: Amara syntax tree application function
 * operation argument.
 */

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_operation_arg.h"

stt_operation_arg *
stt_operation_arg_default_constructor()
{
	stt_operation_arg * ret_;
	ret_ = malloc(sizeof(stt_operation_arg));
	ret_->type_ = OPERATION_ARG_TYPE_INVALID;
	/*
	ret_->raw_ = NULL;
	*/
	ret_->node_ = NULL;
	return ret_;
}

/*   Forward declarations for `stt_operation_arg *
 * stt_operation_arg_copy_constructor(const stt_operation_arg *)`. */
void
assert_stt_node_is_valid(const struct stt_node * node)
;

/*   Forward declarations for `stt_operation_arg *
 * stt_operation_arg_copy_constructor(const stt_operation_arg *)`. */
struct stt_node *
stt_node_copy_constructor(const struct stt_node * node)
__attribute__((warn_unused_result))
;

stt_operation_arg *
stt_operation_arg_copy_constructor(const stt_operation_arg * operation_arg)
{
	stt_operation_arg * ret_;
	assertion(operation_arg->type_ != OPERATION_ARG_TYPE_INVALID);
	ret_ = malloc(sizeof(stt_operation_arg));
	/*
	assertion(operation_arg->raw_ != NULL);
	assertion(operation_arg->raw_->value_ != NULL);
	*/
	assertion(operation_arg->node_ != NULL);
	assert_stt_node_is_valid(operation_arg->node_);
	ret_->node_ = stt_node_copy_constructor(operation_arg->node_);
	/*
	ret_->raw_ = amara_string_copy_constructor(operation_arg->raw_);
	*/
	ret_->type_ = operation_arg->type_;
	return ret_;
}
