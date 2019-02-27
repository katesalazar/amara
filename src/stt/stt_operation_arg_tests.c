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
 * src/stt/stt_operation_arg_tests.c: Amara syntax tree application
 * function operation argument tests.
 */

/*   For `typedef struct stt_node { ... } stt_node;`. */
/*#include "stt_node.h"*/

/*   For `stt_node * stt_node_example_natural_literal_zero()`. */
#include "stt_node_tests.h"

/*   For own prototypes. */
#include "stt_operation_arg_tests.h"

stt_operation_arg *
stt_operation_arg_example_natural_literal_zero(void)
{
	stt_operation_arg * ret_;
	stt_node * node_;

	ret_ = stt_operation_arg_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_OPERATION_ARG_TYPE_INVALID);
#endif

	node_ = stt_node_example_natural_literal_zero();
	forced_assertion(node_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_natural_literal_zero(
			node_);
#endif

	stt_operation_arg_set_node(ret_, node_);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_natural_literal_zero(
			node_);
	assertion(ret_->type_ == STT_OPERATION_ARG_TYPE_VALID);
#endif
	forced_assertion(ret_->node_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_node_example_natural_literal_zero(
			ret_->node_);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_arg_example_natural_literal_zero(
		const stt_operation_arg * operation_arg)
{
	assertion(operation_arg != NULL);
	assertion(operation_arg->type_ == STT_OPERATION_ARG_TYPE_VALID);
	assertion(operation_arg->node_ != NULL);
	assert_expectations_on_stt_node_example_natural_literal_zero(
			operation_arg->node_);
}

#endif

stt_operation_arg *
stt_operation_arg_example_string_literal_foo(void)
{
	amara_string * string_literal_;
	stt_operation_arg * ret_;

	string_literal_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(string_literal_ != NULL);
	forced_assertion(string_literal_->value_ != NULL);
#ifndef NDEBUG
	assertion(string_literal_->value_[0] == 'f');
	assertion(string_literal_->value_[1] == 'o');
	assertion(string_literal_->value_[2] == 'o');
	assertion(string_literal_->value_[3] == '\0');
#endif

	ret_ = stt_operation_arg_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_OPERATION_ARG_TYPE_INVALID);
#endif

	stt_operation_arg_set_string_literal(ret_, string_literal_);
	forced_assertion(ret_->node_ != NULL);
	forced_assertion(ret_->node_->string_literal_subnode_ != NULL);
	/* TODO missing assertions */

	stt_operation_arg_set_type(ret_, STT_OPERATION_ARG_TYPE_VALID);

	amara_string_destructor(string_literal_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_arg_example_string_literal_foo(
		const stt_operation_arg * operation_arg)
{
	assertion(operation_arg != NULL);
	assertion(operation_arg->type_ == STT_OPERATION_ARG_TYPE_VALID);
	assertion(operation_arg->node_ != NULL);
	assertion(operation_arg->node_->type_ == STT_NODE_TYPE_STRING_LITERAL);
	assertion(operation_arg->node_->string_literal_subnode_ != NULL);
	assertion(operation_arg->node_->string_literal_subnode_->string_literal_ !=
			NULL);
	assertion(operation_arg->node_->string_literal_subnode_->string_literal_->value_ !=
			NULL);
	assertion(operation_arg->node_->string_literal_subnode_->string_literal_->value_[0] ==
			'f');
	assertion(operation_arg->node_->string_literal_subnode_->string_literal_->value_[1] ==
			'o');
	assertion(operation_arg->node_->string_literal_subnode_->string_literal_->value_[2] ==
			'o');
	assertion(operation_arg->node_->string_literal_subnode_->string_literal_->value_[3] ==
			'\0');
}

#endif

stt_operation_arg *
stt_operation_arg_example_identifier_foo(void)
{
	amara_string * identifier_;
	stt_operation_arg * ret_;

	identifier_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(identifier_ != NULL);
	forced_assertion(identifier_->value_ != NULL);
#ifndef NDEBUG
	assertion(identifier_->value_[0] == 'f');
	assertion(identifier_->value_[1] == 'o');
	assertion(identifier_->value_[2] == 'o');
	assertion(identifier_->value_[3] == '\0');
#endif

	ret_ = stt_operation_arg_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_OPERATION_ARG_TYPE_INVALID);
#endif

	stt_operation_arg_set_identifier(ret_, identifier_);
	forced_assertion(ret_->node_ != NULL);
	forced_assertion(ret_->node_->identifier_subnode_ != NULL);
	/* TODO missing assertions */

	stt_operation_arg_set_type(ret_, STT_OPERATION_ARG_TYPE_VALID);

	amara_string_destructor(identifier_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_arg_example_identifier_foo(
		const stt_operation_arg * operation_arg)
{
	assertion(operation_arg != NULL);
	assertion(operation_arg->type_ == STT_OPERATION_ARG_TYPE_VALID);
	assertion(operation_arg->node_ != NULL);
	assertion(operation_arg->node_->type_ == STT_NODE_TYPE_IDENTIFIER);
	assertion(operation_arg->node_->identifier_subnode_ != NULL);
	assertion(operation_arg->node_->identifier_subnode_->value_ !=
			NULL);
	assertion(operation_arg->node_->identifier_subnode_->value_->value_ !=
			NULL);
	assertion(operation_arg->node_->identifier_subnode_->value_->value_[0] ==
			'f');
	assertion(operation_arg->node_->identifier_subnode_->value_->value_[1] ==
			'o');
	assertion(operation_arg->node_->identifier_subnode_->value_->value_[2] ==
			'o');
	assertion(operation_arg->node_->identifier_subnode_->value_->value_[3] ==
			'\0');
}

#endif
