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

void
stt_node_natural_copy_test_0()
{
	natural * natural_;
	unsigned int unsigned_int_zero_;
	unsigned int unsigned_int_one_;
	natural * natural_zero_;
	natural * natural_one_;
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	amara_boolean equality_;

	natural_ = natural_default_constructor();
	assertion(natural_ != NULL);
	assertion(natural_->raw_ == NULL);

	unsigned_int_zero_ = 0;

	raw_natural_zero_ = amara_string_exhaustive_constructor("0");

	natural_zero_ = natural_exhaustive_constructor(raw_natural_zero_);
	assertion(natural_zero_ != NULL);
	natural_assert_validity(natural_zero_);

	natural_copy_unsigned_int_into_natural(natural_, unsigned_int_zero_);
	assertion(natural_->raw_ != NULL);
	assertion(natural_->raw_->value_ != NULL);
	equality_ = amara_string_equality(natural_->raw_, natural_zero_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	unsigned_int_one_ = 1;

	raw_natural_one_ = amara_string_exhaustive_constructor("1");

	natural_one_ = natural_exhaustive_constructor(raw_natural_one_);
	assertion(natural_one_ != NULL);
	natural_assert_validity(natural_one_);

	natural_copy_unsigned_int_into_natural(natural_, unsigned_int_one_);
	assertion(natural_->raw_ != NULL);
	assertion(natural_->raw_->value_ != NULL);
	equality_ = amara_string_equality(natural_->raw_, natural_one_->raw_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(raw_natural_one_);
	amara_string_destructor(raw_natural_zero_);
	natural_destructor(natural_one_);
	natural_destructor(natural_zero_);
	natural_destructor(natural_);
}

void
stt_node_natural_copy_tests()
{
	stt_node_natural_copy_test_0();
}

void
stt_node_natural_substraction_test_0()
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

void
stt_node_natural_substraction_tests()
{
	stt_node_natural_substraction_test_0();
}

void
stt_node_natural_multiplication_test_0()
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

	stt_node_substraction_ = simplify_natural_literal_nodes_multiplication(
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
							"3"
					)
			) == AMARA_BOOLEAN_TRUE
	);

	stt_node_destructor(stt_node_substraction_);
}

void
stt_node_natural_multiplication_test_1()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	stt_node * stt_node_zero_;
	stt_node * stt_node_one_;
	stt_node * stt_node_substraction_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("1");

	raw_natural_one_ = amara_string_exhaustive_constructor("3");

	stt_node_zero_ = stt_node_default_constructor();

	stt_node_one_ = stt_node_default_constructor();

	stt_node_set_natural_literal(stt_node_zero_, raw_natural_zero_);

	amara_string_destructor(raw_natural_zero_);

	stt_node_set_natural_literal(stt_node_one_, raw_natural_one_);

	amara_string_destructor(raw_natural_one_);

	stt_node_substraction_ = simplify_natural_literal_nodes_multiplication(
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
							"3"
					)
			) == AMARA_BOOLEAN_TRUE
	);

	stt_node_destructor(stt_node_substraction_);
}

void
stt_node_natural_multiplication_test_2()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	stt_node * stt_node_zero_;
	stt_node * stt_node_one_;
	stt_node * stt_node_substraction_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("2");

	raw_natural_one_ = amara_string_exhaustive_constructor("3");

	stt_node_zero_ = stt_node_default_constructor();

	stt_node_one_ = stt_node_default_constructor();

	stt_node_set_natural_literal(stt_node_zero_, raw_natural_zero_);

	amara_string_destructor(raw_natural_zero_);

	stt_node_set_natural_literal(stt_node_one_, raw_natural_one_);

	amara_string_destructor(raw_natural_one_);

	stt_node_substraction_ = simplify_natural_literal_nodes_multiplication(
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
							"6"
					)
			) == AMARA_BOOLEAN_TRUE
	);

	stt_node_destructor(stt_node_substraction_);
}

void
stt_node_natural_multiplication_tests()
{
	stt_node_natural_multiplication_test_0();
	stt_node_natural_multiplication_test_1();
	stt_node_natural_multiplication_test_2();
}

void
natural_fit_raw_natural_in_unsigned_short_test_0()
{
	amara_string * raw_natural_;
	fit_raw_natural_in_unsigned_short_ret * target_;

	raw_natural_ = amara_string_exhaustive_constructor("9999");

	target_ = fit_raw_natural_in_unsigned_short(raw_natural_);
	assertion(target_ != NULL);
	assertion(target_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_OK);
	assertion(target_->value == 9999);

	fit_raw_natural_in_unsigned_short_ret_destructor(target_);
	amara_string_destructor(raw_natural_);
}

void
natural_fit_raw_natural_in_unsigned_short_test_1()
{
	amara_string * raw_natural_;
	fit_raw_natural_in_unsigned_short_ret * target_;

	raw_natural_ = amara_string_exhaustive_constructor("10000");

	target_ = fit_raw_natural_in_unsigned_short(raw_natural_);
	assertion(target_ != NULL);
	assertion(target_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_OK);
	assertion(target_->value == 10000);

	fit_raw_natural_in_unsigned_short_ret_destructor(target_);
	amara_string_destructor(raw_natural_);
}

void
natural_fit_raw_natural_in_unsigned_short_test_2()
{
	amara_string * raw_natural_;
	fit_raw_natural_in_unsigned_short_ret * target_;

	raw_natural_ = amara_string_exhaustive_constructor("60000");

	target_ = fit_raw_natural_in_unsigned_short(raw_natural_);
	assertion(target_ != NULL);
	assertion(target_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_OK);
	assertion(target_->value == 60000);

	fit_raw_natural_in_unsigned_short_ret_destructor(target_);
	amara_string_destructor(raw_natural_);
}

void
natural_fit_raw_natural_in_unsigned_short_test_3()
{
	amara_string * raw_natural_;
	fit_raw_natural_in_unsigned_short_ret * target_;

	raw_natural_ = amara_string_exhaustive_constructor("100000");

	target_ = fit_raw_natural_in_unsigned_short(raw_natural_);
	assertion(target_ != NULL);
	assertion(target_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_ERR_NOT_FITTING);

	fit_raw_natural_in_unsigned_short_ret_destructor(target_);
	amara_string_destructor(raw_natural_);
}

void
natural_fit_raw_natural_in_unsigned_short_tests()
{
	natural_fit_raw_natural_in_unsigned_short_test_0();
	natural_fit_raw_natural_in_unsigned_short_test_1();
	natural_fit_raw_natural_in_unsigned_short_test_2();
	natural_fit_raw_natural_in_unsigned_short_test_3();
}

void
natural_tests()
{
	stt_node_natural_copy_tests();
	stt_node_natural_substraction_tests();
	stt_node_natural_multiplication_tests();
	/*
	67 * 5 == 79 EN MACOS, PERO ES UN ERROR, DBERA SER 335
	natural_division_tests();
	DESPUES 335 ENTRE 9 DEBE DAR 37
	*/
	natural_fit_raw_natural_in_unsigned_short_tests();
}
