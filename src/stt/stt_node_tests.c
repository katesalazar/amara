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
 * src/stt/stt_node_tests.c: Test the Amara syntax tree node.
 */

#include "../asr/assertion.h"
#include "stt_node.h"
#include "stt_operation_tests.h"

void
stt_node_validation_test_0_integer()
{
	stt_node * node_;
	stt_integer_literal_subnode * subnode_;
	amara_string * raw_integer_;
	node_ = stt_node_default_constructor();
	raw_integer_ = amara_string_exhaustive_constructor("-1");
	subnode_ = stt_integer_literal_subnode_exhaustive_constructor(
			raw_integer_);
	amara_string_destructor(raw_integer_);
	node_->integer_literal_subnode_ = subnode_;
	node_->type_ = STT_NODE_TYPE_INTEGER_LITERAL;
	assert_stt_node_is_valid(node_);
	stt_node_destructor(node_);
}

void
stt_node_validation_test_1_rational()
{
	stt_node * node_;
	stt_rational_subnode * subnode_;
	amara_string * raw_rational_;
	node_ = stt_node_default_constructor();
	raw_rational_ = amara_string_exhaustive_constructor(".1");
	subnode_ = stt_rational_subnode_exhaustive_constructor(raw_rational_);
	amara_string_destructor(raw_rational_);
	node_->rational_subnode_ = subnode_;
	node_->type_ = SYNTAX_TREE_NODE_TYPE_RATIONAL;
	assert_stt_node_is_valid(node_);
	stt_node_destructor(node_);
}

void
stt_node_validation_test_2_identifier()
{
	stt_node * node_;
	stt_identifier_subnode * subnode_;
	amara_string * identifier_;
	node_ = stt_node_default_constructor();
	identifier_ = amara_string_exhaustive_constructor("foo");
	subnode_ = stt_identifier_subnode_exhaustive_constructor(identifier_);
	amara_string_destructor(identifier_);
	node_->identifier_subnode_ = subnode_;
	node_->type_ = SYNTAX_TREE_NODE_TYPE_IDENTIFIER;
	assert_stt_node_is_valid(node_);
	stt_node_destructor(node_);
}

void
stt_node_validation_test_3_operation()
{
	stt_node * node_;
	/* stt_operation_subnode * subnode_; */
	stt_operation * operation_;
	operation_ = stt_operation_example_print_foo();
	assertion(operation_ != NULL);
	assertion(operation_->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first != NULL);
	assertion(operation_->args_->first != NULL);
	assertion(operation_->args_->next == NULL);
	/*
	subnode_ = stt_operation_subnode_exhaustive_constructor(operation_);
	assertion(subnode_ != NULL);
	assertion(subnode_->operation_ != NULL);
	*/
	node_ = stt_node_default_constructor();
	assertion(node_ != NULL);
	assertion(node_->type_ == STT_NODE_TYPE_INVALID);
	/* node_->stt_node_set_operation_subnode(subnode_); */
	stt_node_set_operation(node_, operation_);
	assertion(node_->type_ == STT_NODE_TYPE_OPERATION);
	assert_stt_node_is_valid(node_);
	stt_node_destructor(node_);
	/* stt_operation_subnode_destructor(subnode_); */
	stt_operation_destructor(operation_);
}

void
stt_node_validation_tests()
{
	stt_node_validation_test_0_integer();
	stt_node_validation_test_1_rational();
	stt_node_validation_test_2_identifier();
	stt_node_validation_test_3_operation();
}

void
stt_node_tests()
{
	stt_node_validation_tests();
}
