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
 * src/brt/natural_tests.c: Test the algebraic natural number class.
 */

#include "../asr/assertion.h"

#include "../cmn/amara_string.h"

#include "../stt/stt_node.h"

#include "natural.h"

#include "natural_tests.h"

void natural_substraction_test_0()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	stt_node * stt_node_zero_;
	stt_node * stt_node_one_;
	stt_node * stt_node_substraction_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("3");

	raw_natural_one_ = amara_string_exhaustive_constructor("1");

	stt_node_zero_ = stt_node_default_constructor();

	stt_node_one_ = stt_node_default_constructor();

	stt_node_set_natural_literal(stt_node_zero_, raw_natural_zero_);

	amara_string_destructor(raw_natural_zero_);

	stt_node_set_natural_literal(stt_node_one_, raw_natural_one_);

	amara_string_destructor(raw_natural_one_);

	stt_node_substraction_ = simplify_natural_literal_nodes_substraction(
			stt_node_zero_, stt_node_one_);

	stt_node_destructor(stt_node_one_);

	stt_node_destructor(stt_node_zero_);

	assertion(stt_node_substraction_ != NULL);
	assertion(stt_node_substraction_->type_ ==
			STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(stt_node_substraction_->natural_literal_subnode_ != NULL);
	/*
	assertion(stt_node_substraction_->operation_subnode_->args_ != NULL);
	*/
	/*
	assertion(
			stt_operation_args_simple_list_length(
					stt_node_substraction_->operation_subnode_->args_
			) == 2
	);
	*/
	assertion(
			amara_string_equality(
					stt_node_substraction_->natural_literal_subnode_->raw_,
					amara_string_exhaustive_constructor(
							"2"
					)
			) == AMARA_BOOLEAN_TRUE
	);

	stt_node_destructor(stt_node_substraction_);
}

/*
stt_node *
numeric_natural_nodes_substraction(
		const stt_node * node_zero, const stt_node * node_one)
*/

void natural_substraction_tests()
{
	natural_substraction_test_0();
}

void
natural_tests_()
{
	natural_substraction_tests();
/*	natural_multiplication_tests();
	67 * 5 == 79 EN MACOS, PERO ES UN ERROR, DBERA SER 335
	natural_division_tests();
	DESPUES 335 ENTRE 9 DEBE DAR 37*/
}
