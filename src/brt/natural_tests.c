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
 * src/brt/natural_tests.c: Test the algebraic natural number class.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   TODO refactor in order to remove this weird dependency. */
/*   For `stt_node`. */
#include "../stt/stt_node.h"

/*   For own functions prototypes. */
#include "natural_tests.h"

natural *
natural_example_zero()
{
	amara_string * raw_natural_;
	natural * returning_;

	raw_natural_ = amara_string_exhaustive_constructor("0");
	forced_assertion(raw_natural_ != NULL);
	forced_assertion(raw_natural_->value_ != NULL);
#ifndef NDEBUG
	assertion(raw_natural_->value_[0] == 48);  /* 48: '0'. */
	assertion(raw_natural_->value_[1] == 0);  /* 0: '\0'. */
#endif

	returning_ = natural_exhaustive_constructor(raw_natural_);
#ifndef NDEBUG
	assertion(raw_natural_->value_ != NULL);
	assertion(raw_natural_->value_[0] == 48);  /* 48: '0'. */
	assertion(raw_natural_->value_[1] == 0);  /* 0: '\0'. */
#endif
	forced_assertion(returning_ != NULL);
	forced_assertion(returning_->raw_ != NULL);
	forced_assertion(returning_->raw_->value_ != NULL);
#ifndef NDEBUG
	assertion(returning_->raw_->value_[0] == 48);  /* 48: '0'. */
	assertion(returning_->raw_->value_[1] == 0);  /* 0: '\0'. */
#endif

	amara_string_destructor(raw_natural_);

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_natural_example_zero(const natural * zero)
{
	assertion(zero != NULL);
	assertion(zero->raw_ != NULL);
	assertion(zero->raw_->value_ != NULL);
	assertion(zero->raw_->value_[0] == 48);  /* 48: '0'. */
	assertion(zero->raw_->value_[1] == 0);  /* 0: '\0'. */
}

#endif

natural *
natural_example_one()
{
	amara_string * raw_natural_;
	natural * returning_;

	raw_natural_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_ != NULL);
	forced_assertion(raw_natural_->value_ != NULL);
#ifndef NDEBUG
	assertion(raw_natural_->value_[0] == 49);  /* 49: '1'. */
	assertion(raw_natural_->value_[1] == 0);  /* 0: '\0'. */
#endif

	returning_ = natural_exhaustive_constructor(raw_natural_);
#ifndef NDEBUG
	assertion(raw_natural_->value_ != NULL);
	assertion(raw_natural_->value_[0] == 49);  /* 49: '1'. */
	assertion(raw_natural_->value_[1] == 0);  /* 0: '\0'. */
#endif
	forced_assertion(returning_ != NULL);
	forced_assertion(returning_->raw_ != NULL);
	forced_assertion(returning_->raw_->value_ != NULL);
#ifndef NDEBUG
	assertion(returning_->raw_->value_[0] == 49);  /* 49: '1'. */
	assertion(returning_->raw_->value_[1] == 0);  /* 0: '\0'. */
#endif

	amara_string_destructor(raw_natural_);

	return returning_;
}

#ifndef NDEBUG
void
assert_expectations_on_natural_example_one(const natural * one)
{
	assertion(one != NULL);
	assertion(one->raw_ != NULL);
	assertion(one->raw_->value_ != NULL);
	assertion(one->raw_->value_[0] == 49);  /* 49: '1'. */
	assertion(one->raw_->value_[1] == 0);  /* 0: '\0'. */
}

#endif

natural *
natural_example_six()
{
	amara_string * raw_natural_;
	natural * returning_;

	raw_natural_ = amara_string_exhaustive_constructor("6");
	forced_assertion(raw_natural_ != NULL);
	forced_assertion(raw_natural_->value_ != NULL);
#ifndef NDEBUG
	assertion(raw_natural_->value_[0] == 54);  /* 54: '6'. */
	assertion(raw_natural_->value_[1] == 0);  /* 0: '\0'. */
#endif

	returning_ = natural_exhaustive_constructor(raw_natural_);
#ifndef NDEBUG
	assertion(raw_natural_->value_ != NULL);
	assertion(raw_natural_->value_[0] == 54);  /* 54: '6'. */
	assertion(raw_natural_->value_[1] == 0);  /* 0: '\0'. */
#endif
	forced_assertion(returning_ != NULL);
	forced_assertion(returning_->raw_ != NULL);
	forced_assertion(returning_->raw_->value_ != NULL);
#ifndef NDEBUG
	assertion(returning_->raw_->value_[0] == 54);  /* 54: '6'. */
	assertion(returning_->raw_->value_[1] == 0);  /* 0: '\0'. */
#endif

	amara_string_destructor(raw_natural_);

	return returning_;
}

#ifndef NDEBUG

void
assert_expectations_on_natural_example_six(const natural * six)
{
	assertion(six != NULL);
	assertion(six->raw_ != NULL);
	assertion(six->raw_->value_ != NULL);
	assertion(six->raw_->value_[0] == 54);  /* 54: '6'. */
	assertion(six->raw_->value_[1] == 0);  /* 0: '\0'. */
}

#endif

void
stt_node_natural_copy_test_0()
{
	natural * natural_;
	unsigned short unsigned_short_zero_;
	unsigned short unsigned_short_one_;
	natural * natural_zero_;
	natural * natural_one_;
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	amara_boolean equality_;

	natural_ = natural_default_constructor();
	forced_assertion(natural_ != NULL);
	forced_assertion(natural_->raw_ == NULL);

	unsigned_short_zero_ = 0;

	raw_natural_zero_ = amara_string_exhaustive_constructor("0");
	forced_assertion(raw_natural_zero_ != NULL);

	natural_zero_ = natural_exhaustive_constructor(raw_natural_zero_);
	forced_assertion(natural_zero_ != NULL);
#ifndef NDEBUG
	natural_assert_validity(natural_zero_);
#endif

	natural_copy_unsigned_short_into_natural(
			natural_, unsigned_short_zero_);
	forced_assertion(natural_->raw_ != NULL);
	forced_assertion(natural_->raw_->value_ != NULL);
	equality_ = amara_string_equality(natural_->raw_, natural_zero_->raw_);
	forced_assertion(equality_ == AMARA_BOOLEAN_TRUE);

	unsigned_short_one_ = 1;

	raw_natural_one_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_one_ != NULL);

	natural_one_ = natural_exhaustive_constructor(raw_natural_one_);
	forced_assertion(natural_one_ != NULL);
#ifndef NDEBUG
	natural_assert_validity(natural_one_);
#endif

	natural_copy_unsigned_short_into_natural(
			natural_, unsigned_short_one_);
	forced_assertion(natural_->raw_ != NULL);
	forced_assertion(natural_->raw_->value_ != NULL);
	equality_ = amara_string_equality(natural_->raw_, natural_one_->raw_);
	forced_assertion(equality_ == AMARA_BOOLEAN_TRUE);

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
	amara_string * expectation_;
	stt_node * stt_node_substraction_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("3");
	forced_assertion(raw_natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_one_ != NULL);

	stt_node_zero_ = stt_node_default_constructor();
	forced_assertion(stt_node_zero_ != NULL);

	stt_node_one_ = stt_node_default_constructor();
	forced_assertion(stt_node_one_ != NULL);

	stt_node_set_natural_literal(stt_node_zero_, raw_natural_zero_);
	forced_assertion(stt_node_zero_->natural_literal_subnode_ != NULL);
	forced_assertion(stt_node_zero_->natural_literal_subnode_->raw_ !=
			NULL);
	forced_assertion(stt_node_zero_->natural_literal_subnode_->raw_->value_ !=
			NULL);

	amara_string_destructor(raw_natural_zero_);

	stt_node_set_natural_literal(stt_node_one_, raw_natural_one_);
	forced_assertion(stt_node_one_->natural_literal_subnode_ != NULL);
	forced_assertion(stt_node_one_->natural_literal_subnode_->raw_ !=
			NULL);
	forced_assertion(stt_node_one_->natural_literal_subnode_->raw_->value_ !=
			NULL);

	amara_string_destructor(raw_natural_one_);

	expectation_ = amara_string_exhaustive_constructor("2");

	stt_node_substraction_ = simplify_natural_literal_nodes_substraction(
			stt_node_zero_, stt_node_one_);
#ifndef NDEBUG
	assertion(stt_node_zero_->natural_literal_subnode_ != NULL);
	assertion(stt_node_zero_->natural_literal_subnode_->raw_ != NULL);
	assertion(stt_node_zero_->natural_literal_subnode_->raw_->value_ !=
			NULL);
	assertion(stt_node_one_->natural_literal_subnode_ != NULL);
	assertion(stt_node_one_->natural_literal_subnode_->raw_ != NULL);
	assertion(stt_node_one_->natural_literal_subnode_->raw_->value_ !=
			NULL);
#endif
	forced_assertion(stt_node_substraction_ != NULL);
#ifndef NDEBUG
	assertion(stt_node_substraction_->type_ ==
			STT_NODE_TYPE_NATURAL_LITERAL);
#endif
	forced_assertion(stt_node_substraction_->natural_literal_subnode_ != NULL);
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
#ifndef NDEBUG
	assertion(
			amara_string_equality(
					stt_node_substraction_->natural_literal_subnode_->raw_,
					expectation_
			) == AMARA_BOOLEAN_TRUE
	);
#endif

	amara_string_destructor(expectation_);

	stt_node_destructor(stt_node_one_);

	stt_node_destructor(stt_node_zero_);

	stt_node_destructor(stt_node_substraction_);
}

void
stt_node_natural_substraction_test_1()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	stt_node * stt_node_zero_;
	stt_node * stt_node_one_;
	stt_node * stt_node_substraction_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("3");
	forced_assertion(raw_natural_one_ != NULL);

	stt_node_zero_ = stt_node_default_constructor();
	forced_assertion(stt_node_zero_ != NULL);

	stt_node_one_ = stt_node_default_constructor();
	forced_assertion(stt_node_one_ != NULL);

	stt_node_set_natural_literal(stt_node_zero_, raw_natural_zero_);

	amara_string_destructor(raw_natural_zero_);

	stt_node_set_natural_literal(stt_node_one_, raw_natural_one_);

	amara_string_destructor(raw_natural_one_);

	stt_node_substraction_ = simplify_natural_literal_nodes_substraction(
			stt_node_zero_, stt_node_one_);

	stt_node_destructor(stt_node_one_);

	stt_node_destructor(stt_node_zero_);

	assertion(stt_node_substraction_ != NULL);
	/*
	assertion(stt_node_substraction_->type_ ==
			STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(stt_node_substraction_->natural_literal_subnode_ != NULL);
	*/

	/*   XXX This is this way because it is currently unimplemented. */
	assertion(stt_node_substraction_->type_ == STT_NODE_TYPE_INVALID);

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
	/*
	assertion(
			amara_string_equality(
					stt_node_substraction_->natural_literal_subnode_->raw_,
					amara_string_exhaustive_constructor(
							"2"
					)
			) == AMARA_BOOLEAN_TRUE
	);
	*/

	stt_node_destructor(stt_node_substraction_);
}

void
stt_node_natural_substraction_tests()
{
	stt_node_natural_substraction_test_0();
	stt_node_natural_substraction_test_1();
}

void
stt_node_natural_multiplication_test_0()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	stt_node * stt_node_zero_;
	stt_node * stt_node_one_;
	amara_string * expectation_;
	stt_node * stt_node_multiplication_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("3");
	forced_assertion(raw_natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_one_ != NULL);

	stt_node_zero_ = stt_node_default_constructor();
	forced_assertion(stt_node_zero_ != NULL);

	stt_node_one_ = stt_node_default_constructor();
	forced_assertion(stt_node_one_ != NULL);

	stt_node_set_natural_literal(stt_node_zero_, raw_natural_zero_);

	amara_string_destructor(raw_natural_zero_);

	stt_node_set_natural_literal(stt_node_one_, raw_natural_one_);

	amara_string_destructor(raw_natural_one_);

	expectation_ = amara_string_exhaustive_constructor("3");
	forced_assertion(expectation_ != NULL);

	stt_node_multiplication_ =
			simplify_natural_literal_nodes_multiplication(
					stt_node_zero_, stt_node_one_);

	assertion(stt_node_multiplication_ != NULL);
	assertion(stt_node_multiplication_->type_ ==
			STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(stt_node_multiplication_->natural_literal_subnode_ != NULL);
	/*
	assertion(stt_node_multiplication_->operation_subnode_->args_ != NULL);
	*/
	/*
	assertion(
			stt_operation_args_simple_list_length(
					stt_node_multiplication_->operation_subnode_->args_
			) == 2
	);
	*/
	assertion(
			amara_string_equality(
					stt_node_multiplication_->natural_literal_subnode_->raw_,
					expectation_
			) == AMARA_BOOLEAN_TRUE
	);

	amara_string_destructor(expectation_);

	stt_node_destructor(stt_node_one_);

	stt_node_destructor(stt_node_zero_);

	stt_node_destructor(stt_node_multiplication_);
}

void
stt_node_natural_multiplication_test_1()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	stt_node * stt_node_zero_;
	stt_node * stt_node_one_;
	amara_string * expectation_;
	stt_node * stt_node_multiplication_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("3");
	forced_assertion(raw_natural_one_ != NULL);

	stt_node_zero_ = stt_node_default_constructor();
	forced_assertion(stt_node_zero_ != NULL);

	stt_node_one_ = stt_node_default_constructor();
	forced_assertion(stt_node_one_ != NULL);

	stt_node_set_natural_literal(stt_node_zero_, raw_natural_zero_);

	amara_string_destructor(raw_natural_zero_);

	stt_node_set_natural_literal(stt_node_one_, raw_natural_one_);

	amara_string_destructor(raw_natural_one_);

	expectation_ = amara_string_exhaustive_constructor("3");
	forced_assertion(expectation_ != NULL);

	stt_node_multiplication_ =
			simplify_natural_literal_nodes_multiplication(
					stt_node_zero_, stt_node_one_);

	assertion(stt_node_multiplication_ != NULL);
	assertion(stt_node_multiplication_->type_ ==
			STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(stt_node_multiplication_->natural_literal_subnode_ != NULL);
	/*
	assertion(stt_node_multiplication_->operation_subnode_->args_ != NULL);
	*/
	/*
	assertion(
			stt_operation_args_simple_list_length(
					stt_node_multiplication_->operation_subnode_->args_
			) == 2
	);
	*/
	assertion(
			amara_string_equality(
					stt_node_multiplication_->natural_literal_subnode_->raw_,
					expectation_
			) == AMARA_BOOLEAN_TRUE
	);

	amara_string_destructor(expectation_);

	stt_node_destructor(stt_node_one_);

	stt_node_destructor(stt_node_zero_);

	stt_node_destructor(stt_node_multiplication_);
}

void
stt_node_natural_multiplication_test_2()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	stt_node * stt_node_zero_;
	stt_node * stt_node_one_;
	amara_string * expectation_;
	stt_node * stt_node_multiplication_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("2");
	forced_assertion(raw_natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("3");
	forced_assertion(raw_natural_one_ != NULL);

	stt_node_zero_ = stt_node_default_constructor();
	forced_assertion(stt_node_zero_ != NULL);

	stt_node_one_ = stt_node_default_constructor();
	forced_assertion(stt_node_one_ != NULL);

	stt_node_set_natural_literal(stt_node_zero_, raw_natural_zero_);

	amara_string_destructor(raw_natural_zero_);

	stt_node_set_natural_literal(stt_node_one_, raw_natural_one_);

	amara_string_destructor(raw_natural_one_);

	expectation_ = amara_string_exhaustive_constructor("6");
	forced_assertion(expectation_ != NULL);

	stt_node_multiplication_ =
			simplify_natural_literal_nodes_multiplication(
					stt_node_zero_, stt_node_one_);

	assertion(stt_node_multiplication_ != NULL);
	assertion(stt_node_multiplication_->type_ ==
			STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(stt_node_multiplication_->natural_literal_subnode_ != NULL);
	/*
	assertion(stt_node_multiplication_->operation_subnode_->args_ != NULL);
	*/
	/*
	assertion(
			stt_operation_args_simple_list_length(
					stt_node_multiplication_->operation_subnode_->args_
			) == 2
	);
	*/
	assertion(
			amara_string_equality(
					stt_node_multiplication_->natural_literal_subnode_->raw_,
					expectation_
			) == AMARA_BOOLEAN_TRUE
	);

	amara_string_destructor(expectation_);

	stt_node_destructor(stt_node_one_);

	stt_node_destructor(stt_node_zero_);

	stt_node_destructor(stt_node_multiplication_);
}

/*

void
stt_node_natural_multiplication_test_3()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	stt_node * stt_node_zero_;
	stt_node * stt_node_one_;
	stt_node * stt_node_multiplication_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("256");

	raw_natural_one_ = amara_string_exhaustive_constructor("3");

	stt_node_zero_ = stt_node_default_constructor();

	stt_node_one_ = stt_node_default_constructor();

	stt_node_set_natural_literal(stt_node_zero_, raw_natural_zero_);

	amara_string_destructor(raw_natural_zero_);

	stt_node_set_natural_literal(stt_node_one_, raw_natural_one_);

	amara_string_destructor(raw_natural_one_);

	stt_node_multiplication_ =
			simplify_natural_literal_nodes_multiplication(
					stt_node_zero_, stt_node_one_);

	stt_node_destructor(stt_node_one_);

	stt_node_destructor(stt_node_zero_);

	assertion(stt_node_multiplication_ != NULL);
	assertion(stt_node_multiplication_->type_ ==
			STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(stt_node_multiplication_->natural_literal_subnode_ != NULL);
*/
	/*
	assertion(stt_node_multiplication_->operation_subnode_->args_ != NULL);
	*/
	/*
	assertion(
			stt_operation_args_simple_list_length(
					stt_node_multiplication_->operation_subnode_->args_
			) == 2
	);
	*/
/*
	assertion(
			amara_string_equality(
					stt_node_multiplication_->natural_literal_subnode_->raw_,
					amara_string_exhaustive_constructor(
							"6"
					)
			) == AMARA_BOOLEAN_TRUE
	);

	stt_node_destructor(stt_node_multiplication_);
}

*/

void
stt_node_natural_multiplication_tests()
{
	stt_node_natural_multiplication_test_0();
	stt_node_natural_multiplication_test_1();
	stt_node_natural_multiplication_test_2();
	/*
	stt_node_natural_multiplication_test_3();
	*/
}

void
stt_node_natural_division_test_0()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	stt_node * stt_node_zero_;
	stt_node * stt_node_one_;
	amara_string * expectation_;
	stt_node * stt_node_division_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("3");
	forced_assertion(raw_natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("2");
	forced_assertion(raw_natural_one_ != NULL);

	stt_node_zero_ = stt_node_default_constructor();
	forced_assertion(stt_node_zero_ != NULL);

	stt_node_one_ = stt_node_default_constructor();
	forced_assertion(stt_node_one_ != NULL);

	stt_node_set_natural_literal(stt_node_zero_, raw_natural_zero_);

	amara_string_destructor(raw_natural_zero_);

	stt_node_set_natural_literal(stt_node_one_, raw_natural_one_);

	amara_string_destructor(raw_natural_one_);

	expectation_ = amara_string_exhaustive_constructor("1");
	forced_assertion(expectation_ != NULL);

	stt_node_division_ = simplify_natural_literal_nodes_division(
			stt_node_zero_, stt_node_one_);

	assertion(stt_node_division_ != NULL);
	assertion(stt_node_division_->type_ ==
			STT_NODE_TYPE_NATURAL_LITERAL);
	assertion(stt_node_division_->natural_literal_subnode_ != NULL);
	/*
	assertion(stt_node_division_->operation_subnode_->args_ != NULL);
	*/
	/*
	assertion(
			stt_operation_args_simple_list_length(
					stt_node_division_->operation_subnode_->args_
			) == 2
	);
	*/
	assertion(
			amara_string_equality(
					stt_node_division_->natural_literal_subnode_->raw_,
					expectation_
			) == AMARA_BOOLEAN_TRUE
	);

	amara_string_destructor(expectation_);

	stt_node_destructor(stt_node_one_);

	stt_node_destructor(stt_node_zero_);

	stt_node_destructor(stt_node_division_);
}

void
stt_node_natural_division_tests()
{
	stt_node_natural_division_test_0();
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

	raw_natural_ = amara_string_exhaustive_constructor("90000");

	target_ = fit_raw_natural_in_unsigned_short(raw_natural_);
	assertion(target_ != NULL);
	assertion(target_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_ERR_NOT_FITTING);

	fit_raw_natural_in_unsigned_short_ret_destructor(target_);
	amara_string_destructor(raw_natural_);
}

void
natural_fit_raw_natural_in_unsigned_short_test_4()
{
	amara_string * raw_natural_;
	fit_raw_natural_in_unsigned_short_ret * target_;

	raw_natural_ = amara_string_exhaustive_constructor("66000");

	target_ = fit_raw_natural_in_unsigned_short(raw_natural_);
	assertion(target_ != NULL);
	assertion(target_->status ==
			FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_ERR_NOT_FITTING);

	fit_raw_natural_in_unsigned_short_ret_destructor(target_);
	amara_string_destructor(raw_natural_);
}

void
natural_fit_raw_natural_in_unsigned_short_test_5()
{
	amara_string * raw_natural_;
	fit_raw_natural_in_unsigned_short_ret * target_;

	raw_natural_ = amara_string_exhaustive_constructor("65000");

	target_ = fit_raw_natural_in_unsigned_short(raw_natural_);
	assertion(target_ != NULL);
	assertion(target_->status ==
			/* FIXME - THIS ACTUALLY SHOULD FIT, BUT IT IS A CASE YET TO BE IMPLEMENTED. */
			FIT_RAW_NATURAL_IN_UNSIGNED_SHORT_RET_STATUS_ERR_NOT_FITTING);

	fit_raw_natural_in_unsigned_short_ret_destructor(target_);
	amara_string_destructor(raw_natural_);
}

void
natural_fit_raw_natural_in_unsigned_short_test_6()
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
	natural_fit_raw_natural_in_unsigned_short_test_4();
	natural_fit_raw_natural_in_unsigned_short_test_5();
	natural_fit_raw_natural_in_unsigned_short_test_6();
}

void
natural_copy_pointer_to_unsigned_short_into_raw_natural_test_0()
{
	unsigned short * pointer_to_unsigned_short_;
	amara_string * raw_natural_;

	pointer_to_unsigned_short_ =
#ifdef AMARA_USE_STD_CXX98
			(unsigned short *)
#endif
			malloc(sizeof(unsigned short));
	forced_assertion_two(pointer_to_unsigned_short_ != NULL,
			"malloc failed\n");

	* pointer_to_unsigned_short_ = 0xFF;

	raw_natural_ = natural_copy_pointer_to_unsigned_short_into_raw_natural(
			pointer_to_unsigned_short_);
	assertion(raw_natural_ != NULL);
	assertion(raw_natural_->value_ != NULL);
	assertion(raw_natural_->value_[0] == '2');
	assertion(raw_natural_->value_[1] == '5');
	assertion(raw_natural_->value_[2] == '5');
	assertion(raw_natural_->value_[3] == '\0');

	amara_string_destructor(raw_natural_);
	free(pointer_to_unsigned_short_);
}

void
natural_copy_pointer_to_unsigned_short_into_raw_natural_test_1()
{
	unsigned short * pointer_to_unsigned_short_;
	amara_string * raw_natural_;

	pointer_to_unsigned_short_ =
#ifdef AMARA_USE_STD_CXX98
			(unsigned short *)
#endif
			malloc(sizeof(unsigned short));
	forced_assertion_two(pointer_to_unsigned_short_ != NULL,
			"malloc failed\n");

	* pointer_to_unsigned_short_ = 0xFF;

	raw_natural_ = natural_copy_pointer_to_unsigned_short_into_raw_natural(
			pointer_to_unsigned_short_);
	assertion(raw_natural_ != NULL);
	assertion(raw_natural_->value_ != NULL);
	assertion(raw_natural_->value_[0] == '2');
	assertion(raw_natural_->value_[1] == '5');
	assertion(raw_natural_->value_[2] == '5');
	assertion(raw_natural_->value_[3] == '\0');
	/*assertion(raw_natural_->value_[4] == 'E');
	assertion(raw_natural_->value_[5] == '\0');*/

	amara_string_destructor(raw_natural_);
	free(pointer_to_unsigned_short_);
}

void
natural_copy_pointer_to_unsigned_short_into_raw_natural_tests()
{
	natural_copy_pointer_to_unsigned_short_into_raw_natural_test_0();
	natural_copy_pointer_to_unsigned_short_into_raw_natural_test_1();
}

void
natural_copy_unsigned_long_into_raw_natural_test_0()
{
	unsigned long unsigned_long_;
	amara_string * raw_natural_;

	unsigned_long_ = 0xFF;

	raw_natural_ = natural_copy_unsigned_long_into_raw_natural(
			unsigned_long_);
	assertion(raw_natural_ != NULL);
	assertion(raw_natural_->value_ != NULL);
	assertion(raw_natural_->value_[0] == '2');
	assertion(raw_natural_->value_[1] == '5');
	assertion(raw_natural_->value_[2] == '5');
	assertion(raw_natural_->value_[3] == '\0');

	amara_string_destructor(raw_natural_);
}

void
natural_copy_unsigned_long_into_raw_natural_tests()
{
	natural_copy_unsigned_long_into_raw_natural_test_0();
}

void
natural_copy_pointer_to_unsigned_long_into_raw_natural_test_0()
{
	unsigned long * pointer_to_unsigned_long_;
	amara_string * raw_natural_;

	pointer_to_unsigned_long_ =
#ifdef AMARA_USE_STD_CXX98
			(unsigned long *)
#endif
			malloc(sizeof(unsigned long));
	forced_assertion_two(pointer_to_unsigned_long_ != NULL, "malloc failed\n");

	* pointer_to_unsigned_long_ = 0xFF;

	raw_natural_ = natural_copy_pointer_to_unsigned_long_into_raw_natural(
			pointer_to_unsigned_long_);
	assertion(raw_natural_ != NULL);
	assertion(raw_natural_->value_ != NULL);
	assertion(raw_natural_->value_[0] == '2');
	assertion(raw_natural_->value_[1] == '5');
	assertion(raw_natural_->value_[2] == '5');
	assertion(raw_natural_->value_[3] == '\0');

	amara_string_destructor(raw_natural_);
	free(pointer_to_unsigned_long_);
}

void
natural_copy_pointer_to_unsigned_long_into_raw_natural_tests()
{
	natural_copy_pointer_to_unsigned_long_into_raw_natural_test_0();
}

void
well_formed_raw_natural_test_0()
{
	amara_string * raw_natural_;
	amara_boolean well_formed_;

	raw_natural_ = amara_string_exhaustive_constructor("0");
	forced_assertion(raw_natural_ != NULL);

	well_formed_ = well_formed_raw_natural(raw_natural_);
	forced_assertion(well_formed_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(raw_natural_);
}

void
well_formed_raw_natural_tests()
{
	well_formed_raw_natural_test_0();
}

void
raw_naturals_multiplication_as_raw_natural_test_0()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	amara_string * returned_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("256");
	forced_assertion(raw_natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_one_ != NULL);

	returned_ = raw_naturals_multiplication_as_raw_natural(
			raw_natural_zero_, raw_natural_one_);
	forced_assertion(returned_ != NULL);

	forced_assertion(returned_->value_[ 0] == 'M');
	forced_assertion(returned_->value_[ 1] == 'A');
	forced_assertion(returned_->value_[ 2] == 'C');
	forced_assertion(returned_->value_[ 3] == 'H');
	forced_assertion(returned_->value_[ 4] == 'I');
	forced_assertion(returned_->value_[ 5] == 'N');
	forced_assertion(returned_->value_[ 6] == 'E');
	forced_assertion(returned_->value_[ 7] == '_');
	forced_assertion(returned_->value_[ 8] == 'N');
	forced_assertion(returned_->value_[ 9] == 'U');
	forced_assertion(returned_->value_[10] == 'M');
	forced_assertion(returned_->value_[11] == 'E');
	forced_assertion(returned_->value_[12] == 'R');
	forced_assertion(returned_->value_[13] == 'I');
	forced_assertion(returned_->value_[14] == 'C');
	forced_assertion(returned_->value_[15] == '_');
	forced_assertion(returned_->value_[16] == 'O');
	forced_assertion(returned_->value_[17] == 'V');
	forced_assertion(returned_->value_[18] == 'E');
	forced_assertion(returned_->value_[19] == 'R');
	forced_assertion(returned_->value_[20] == 'F');
	forced_assertion(returned_->value_[21] == 'L');
	forced_assertion(returned_->value_[22] == 'O');
	forced_assertion(returned_->value_[23] == 'W');
	forced_assertion(returned_->value_[24] == 0x00);

	amara_string_destructor(raw_natural_zero_);
	amara_string_destructor(raw_natural_one_);
	amara_string_destructor(returned_);
}

void
raw_naturals_multiplication_as_raw_natural_test_1()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	amara_string * returned_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("256");
	forced_assertion(raw_natural_one_ != NULL);

	returned_ = raw_naturals_multiplication_as_raw_natural(
			raw_natural_zero_, raw_natural_one_);
	forced_assertion(returned_ != NULL);

	forced_assertion(returned_->value_[ 0] == 'M');
	forced_assertion(returned_->value_[ 1] == 'A');
	forced_assertion(returned_->value_[ 2] == 'C');
	forced_assertion(returned_->value_[ 3] == 'H');
	forced_assertion(returned_->value_[ 4] == 'I');
	forced_assertion(returned_->value_[ 5] == 'N');
	forced_assertion(returned_->value_[ 6] == 'E');
	forced_assertion(returned_->value_[ 7] == '_');
	forced_assertion(returned_->value_[ 8] == 'N');
	forced_assertion(returned_->value_[ 9] == 'U');
	forced_assertion(returned_->value_[10] == 'M');
	forced_assertion(returned_->value_[11] == 'E');
	forced_assertion(returned_->value_[12] == 'R');
	forced_assertion(returned_->value_[13] == 'I');
	forced_assertion(returned_->value_[14] == 'C');
	forced_assertion(returned_->value_[15] == '_');
	forced_assertion(returned_->value_[16] == 'O');
	forced_assertion(returned_->value_[17] == 'V');
	forced_assertion(returned_->value_[18] == 'E');
	forced_assertion(returned_->value_[19] == 'R');
	forced_assertion(returned_->value_[20] == 'F');
	forced_assertion(returned_->value_[21] == 'L');
	forced_assertion(returned_->value_[22] == 'O');
	forced_assertion(returned_->value_[23] == 'W');
	forced_assertion(returned_->value_[24] == 0x00);

	amara_string_destructor(raw_natural_zero_);
	amara_string_destructor(raw_natural_one_);
	amara_string_destructor(returned_);
}

void
raw_naturals_multiplication_as_raw_natural_tests()
{
	raw_naturals_multiplication_as_raw_natural_test_0();
	raw_naturals_multiplication_as_raw_natural_test_1();
}

void
raw_naturals_euclidean_quotient_as_raw_natural_test_0()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	amara_string * returned_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("65536");
	forced_assertion(raw_natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_one_ != NULL);

	returned_ = raw_naturals_euclidean_quotient_as_raw_natural(
			raw_natural_zero_, raw_natural_one_);
	forced_assertion(returned_ != NULL);

	forced_assertion(returned_->value_[ 0] == 'M');
	forced_assertion(returned_->value_[ 1] == 'A');
	forced_assertion(returned_->value_[ 2] == 'C');
	forced_assertion(returned_->value_[ 3] == 'H');
	forced_assertion(returned_->value_[ 4] == 'I');
	forced_assertion(returned_->value_[ 5] == 'N');
	forced_assertion(returned_->value_[ 6] == 'E');
	forced_assertion(returned_->value_[ 7] == '_');
	forced_assertion(returned_->value_[ 8] == 'N');
	forced_assertion(returned_->value_[ 9] == 'U');
	forced_assertion(returned_->value_[10] == 'M');
	forced_assertion(returned_->value_[11] == 'E');
	forced_assertion(returned_->value_[12] == 'R');
	forced_assertion(returned_->value_[13] == 'I');
	forced_assertion(returned_->value_[14] == 'C');
	forced_assertion(returned_->value_[15] == '_');
	forced_assertion(returned_->value_[16] == 'O');
	forced_assertion(returned_->value_[17] == 'V');
	forced_assertion(returned_->value_[18] == 'E');
	forced_assertion(returned_->value_[19] == 'R');
	forced_assertion(returned_->value_[20] == 'F');
	forced_assertion(returned_->value_[21] == 'L');
	forced_assertion(returned_->value_[22] == 'O');
	forced_assertion(returned_->value_[23] == 'W');
	forced_assertion(returned_->value_[24] == 0x00);

	amara_string_destructor(raw_natural_zero_);
	amara_string_destructor(raw_natural_one_);
	amara_string_destructor(returned_);
}

void
raw_naturals_euclidean_quotient_as_raw_natural_test_1()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	amara_string * returned_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("255");
	forced_assertion(raw_natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("255");
	forced_assertion(raw_natural_one_ != NULL);

	returned_ = raw_naturals_euclidean_quotient_as_raw_natural(
			raw_natural_zero_, raw_natural_one_);
	forced_assertion(returned_ != NULL);

	/*
	forced_assertion(returned_->value_[ 0] == 'M');
	*/
	forced_assertion(returned_->value_[0] == '1');

	/*
	forced_assertion(returned_->value_[ 1] == 'A');
	*/
	forced_assertion(returned_->value_[ 1] == 0x00);

	/*
	forced_assertion(returned_->value_[ 2] == 'C');
	forced_assertion(returned_->value_[ 3] == 'H');
	forced_assertion(returned_->value_[ 4] == 'I');
	forced_assertion(returned_->value_[ 5] == 'N');
	forced_assertion(returned_->value_[ 6] == 'E');
	forced_assertion(returned_->value_[ 7] == '_');
	forced_assertion(returned_->value_[ 8] == 'N');
	forced_assertion(returned_->value_[ 9] == 'U');
	forced_assertion(returned_->value_[10] == 'M');
	forced_assertion(returned_->value_[11] == 'E');
	forced_assertion(returned_->value_[12] == 'R');
	forced_assertion(returned_->value_[13] == 'I');
	forced_assertion(returned_->value_[14] == 'C');
	forced_assertion(returned_->value_[15] == '_');
	forced_assertion(returned_->value_[16] == 'O');
	forced_assertion(returned_->value_[17] == 'V');
	forced_assertion(returned_->value_[18] == 'E');
	forced_assertion(returned_->value_[19] == 'R');
	forced_assertion(returned_->value_[20] == 'F');
	forced_assertion(returned_->value_[21] == 'L');
	forced_assertion(returned_->value_[22] == 'O');
	forced_assertion(returned_->value_[23] == 'W');
	forced_assertion(returned_->value_[24] == 0x00);
	*/

	amara_string_destructor(raw_natural_zero_);
	amara_string_destructor(raw_natural_one_);
	amara_string_destructor(returned_);
}

void
raw_naturals_euclidean_quotient_as_raw_natural_test_2()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	amara_string * returned_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("255");
	forced_assertion(raw_natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("256");
	forced_assertion(raw_natural_one_ != NULL);

	returned_ = raw_naturals_euclidean_quotient_as_raw_natural(
			raw_natural_zero_, raw_natural_one_);
	forced_assertion(returned_ != NULL);

	forced_assertion(returned_->value_[ 0] == 'M');
	/*
	forced_assertion(returned_->value_[0] == '1');
	*/

	forced_assertion(returned_->value_[ 1] == 'A');
	/*
	forced_assertion(returned_->value_[ 1] == 0x00);
	*/

	forced_assertion(returned_->value_[ 2] == 'C');
	forced_assertion(returned_->value_[ 3] == 'H');
	forced_assertion(returned_->value_[ 4] == 'I');
	forced_assertion(returned_->value_[ 5] == 'N');
	forced_assertion(returned_->value_[ 6] == 'E');
	forced_assertion(returned_->value_[ 7] == '_');
	forced_assertion(returned_->value_[ 8] == 'N');
	forced_assertion(returned_->value_[ 9] == 'U');
	forced_assertion(returned_->value_[10] == 'M');
	forced_assertion(returned_->value_[11] == 'E');
	forced_assertion(returned_->value_[12] == 'R');
	forced_assertion(returned_->value_[13] == 'I');
	forced_assertion(returned_->value_[14] == 'C');
	forced_assertion(returned_->value_[15] == '_');
	forced_assertion(returned_->value_[16] == 'O');
	forced_assertion(returned_->value_[17] == 'V');
	forced_assertion(returned_->value_[18] == 'E');
	forced_assertion(returned_->value_[19] == 'R');
	forced_assertion(returned_->value_[20] == 'F');
	forced_assertion(returned_->value_[21] == 'L');
	forced_assertion(returned_->value_[22] == 'O');
	forced_assertion(returned_->value_[23] == 'W');
	forced_assertion(returned_->value_[24] == 0x00);

	amara_string_destructor(raw_natural_zero_);
	amara_string_destructor(raw_natural_one_);
	amara_string_destructor(returned_);
}

void
raw_naturals_euclidean_quotient_as_raw_natural_test_3()
{
	amara_string * raw_natural_zero_;
	amara_string * raw_natural_one_;
	amara_string * returned_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("256");
	forced_assertion(raw_natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("256");
	forced_assertion(raw_natural_one_ != NULL);

	returned_ = raw_naturals_euclidean_quotient_as_raw_natural(
			raw_natural_zero_, raw_natural_one_);
	forced_assertion(returned_ != NULL);

	forced_assertion(returned_->value_[ 0] == 'M');
	/*
	forced_assertion(returned_->value_[0] == '1');
	*/

	forced_assertion(returned_->value_[ 1] == 'A');
	/*
	forced_assertion(returned_->value_[ 1] == 0x00);
	*/

	forced_assertion(returned_->value_[ 2] == 'C');
	forced_assertion(returned_->value_[ 3] == 'H');
	forced_assertion(returned_->value_[ 4] == 'I');
	forced_assertion(returned_->value_[ 5] == 'N');
	forced_assertion(returned_->value_[ 6] == 'E');
	forced_assertion(returned_->value_[ 7] == '_');
	forced_assertion(returned_->value_[ 8] == 'N');
	forced_assertion(returned_->value_[ 9] == 'U');
	forced_assertion(returned_->value_[10] == 'M');
	forced_assertion(returned_->value_[11] == 'E');
	forced_assertion(returned_->value_[12] == 'R');
	forced_assertion(returned_->value_[13] == 'I');
	forced_assertion(returned_->value_[14] == 'C');
	forced_assertion(returned_->value_[15] == '_');
	forced_assertion(returned_->value_[16] == 'O');
	forced_assertion(returned_->value_[17] == 'V');
	forced_assertion(returned_->value_[18] == 'E');
	forced_assertion(returned_->value_[19] == 'R');
	forced_assertion(returned_->value_[20] == 'F');
	forced_assertion(returned_->value_[21] == 'L');
	forced_assertion(returned_->value_[22] == 'O');
	forced_assertion(returned_->value_[23] == 'W');
	forced_assertion(returned_->value_[24] == 0x00);

	amara_string_destructor(raw_natural_zero_);
	amara_string_destructor(raw_natural_one_);
	amara_string_destructor(returned_);
}

void
raw_naturals_euclidean_quotient_as_raw_natural_tests()
{
	raw_naturals_euclidean_quotient_as_raw_natural_test_0();
	raw_naturals_euclidean_quotient_as_raw_natural_test_1();
	raw_naturals_euclidean_quotient_as_raw_natural_test_2();
	raw_naturals_euclidean_quotient_as_raw_natural_test_3();
}

void
naturals_less_than_test_0()
{
	amara_string * raw_natural_zero_;
	natural * natural_zero_;
	amara_string * raw_natural_one_;
	natural * natural_one_;
	amara_boolean result_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("0");
	forced_assertion(raw_natural_zero_ != NULL);

	natural_zero_ = natural_exhaustive_constructor(raw_natural_zero_);
	forced_assertion(natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_one_ != NULL);

	natural_one_ = natural_exhaustive_constructor(raw_natural_one_);
	forced_assertion(natural_one_ != NULL);

	result_ = naturals_less_than(natural_zero_, natural_one_);
	forced_assertion(result_ == AMARA_BOOLEAN_TRUE);

	natural_destructor(natural_one_);
	amara_string_destructor(raw_natural_one_);
	natural_destructor(natural_zero_);
	amara_string_destructor(raw_natural_zero_);
}

void
naturals_less_than_test_1()
{
	amara_string * raw_natural_zero_;
	natural * natural_zero_;
	amara_string * raw_natural_one_;
	natural * natural_one_;
	amara_boolean result_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("10");
	forced_assertion(raw_natural_zero_ != NULL);

	natural_zero_ = natural_exhaustive_constructor(raw_natural_zero_);
	forced_assertion(natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("11");
	forced_assertion(raw_natural_one_ != NULL);

	natural_one_ = natural_exhaustive_constructor(raw_natural_one_);
	forced_assertion(natural_one_ != NULL);

	result_ = naturals_less_than(natural_zero_, natural_one_);
	forced_assertion(result_ == AMARA_BOOLEAN_TRUE);

	natural_destructor(natural_one_);
	amara_string_destructor(raw_natural_one_);
	natural_destructor(natural_zero_);
	amara_string_destructor(raw_natural_zero_);
}

void
naturals_less_than_test_2()
{
	amara_string * raw_natural_zero_;
	natural * natural_zero_;
	amara_string * raw_natural_one_;
	natural * natural_one_;
	amara_boolean result_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_zero_ != NULL);

	natural_zero_ = natural_exhaustive_constructor(raw_natural_zero_);
	forced_assertion(natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("0");
	forced_assertion(raw_natural_one_ != NULL);

	natural_one_ = natural_exhaustive_constructor(raw_natural_one_);
	forced_assertion(natural_one_ != NULL);

	result_ = naturals_less_than(natural_zero_, natural_one_);
	forced_assertion(result_ == AMARA_BOOLEAN_FALSE);

	natural_destructor(natural_one_);
	amara_string_destructor(raw_natural_one_);
	natural_destructor(natural_zero_);
	amara_string_destructor(raw_natural_zero_);
}

void
naturals_less_than_tests()
{
	naturals_less_than_test_0();
	naturals_less_than_test_1();
	naturals_less_than_test_2();
}

void
naturals_greater_than_test_0()
{
	amara_string * raw_natural_zero_;
	natural * natural_zero_;
	amara_string * raw_natural_one_;
	natural * natural_one_;
	amara_boolean result_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_zero_ != NULL);

	natural_zero_ = natural_exhaustive_constructor(raw_natural_zero_);
	forced_assertion(natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("0");
	forced_assertion(raw_natural_one_ != NULL);

	natural_one_ = natural_exhaustive_constructor(raw_natural_one_);
	forced_assertion(natural_one_ != NULL);

	result_ = naturals_greater_than(natural_zero_, natural_one_);
	forced_assertion(result_ == AMARA_BOOLEAN_TRUE);

	natural_destructor(natural_one_);
	amara_string_destructor(raw_natural_one_);
	natural_destructor(natural_zero_);
	amara_string_destructor(raw_natural_zero_);
}

void
naturals_greater_than_test_1()
{
	amara_string * raw_natural_zero_;
	natural * natural_zero_;
	amara_string * raw_natural_one_;
	natural * natural_one_;
	amara_boolean result_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("11");
	forced_assertion(raw_natural_zero_ != NULL);

	natural_zero_ = natural_exhaustive_constructor(raw_natural_zero_);
	forced_assertion(natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("10");
	forced_assertion(raw_natural_one_ != NULL);

	natural_one_ = natural_exhaustive_constructor(raw_natural_one_);
	forced_assertion(natural_one_ != NULL);

	result_ = naturals_greater_than(natural_zero_, natural_one_);
	forced_assertion(result_ == AMARA_BOOLEAN_TRUE);

	natural_destructor(natural_one_);
	amara_string_destructor(raw_natural_one_);
	natural_destructor(natural_zero_);
	amara_string_destructor(raw_natural_zero_);
}

void
naturals_greater_than_test_2()
{
	amara_string * raw_natural_zero_;
	natural * natural_zero_;
	amara_string * raw_natural_one_;
	natural * natural_one_;
	amara_boolean result_;

	raw_natural_zero_ = amara_string_exhaustive_constructor("0");
	forced_assertion(raw_natural_zero_ != NULL);

	natural_zero_ = natural_exhaustive_constructor(raw_natural_zero_);
	forced_assertion(natural_zero_ != NULL);

	raw_natural_one_ = amara_string_exhaustive_constructor("1");
	forced_assertion(raw_natural_one_ != NULL);

	natural_one_ = natural_exhaustive_constructor(raw_natural_one_);
	forced_assertion(natural_one_ != NULL);

	result_ = naturals_greater_than(natural_zero_, natural_one_);
	forced_assertion(result_ == AMARA_BOOLEAN_FALSE);

	natural_destructor(natural_one_);
	amara_string_destructor(raw_natural_one_);
	natural_destructor(natural_zero_);
	amara_string_destructor(raw_natural_zero_);
}

void
naturals_greater_than_tests()
{
	naturals_greater_than_test_0();
	naturals_greater_than_test_1();
	naturals_greater_than_test_2();
}

void
natural_tests()
{
	stt_node_natural_copy_tests();
	stt_node_natural_substraction_tests();
	stt_node_natural_multiplication_tests();
	stt_node_natural_division_tests();
	/*
	67 * 5 == 79 EN MACOS, PERO ES UN ERROR, DBERA SER 335
	natural_division_tests();
	DESPUES 335 ENTRE 9 DEBE DAR 37
	*/
	natural_fit_raw_natural_in_unsigned_short_tests();
	natural_copy_pointer_to_unsigned_short_into_raw_natural_tests();
	natural_copy_unsigned_long_into_raw_natural_tests();
	natural_copy_pointer_to_unsigned_long_into_raw_natural_tests();
	well_formed_raw_natural_tests();
	raw_naturals_multiplication_as_raw_natural_tests();
	raw_naturals_euclidean_quotient_as_raw_natural_tests();
	naturals_less_than_tests();
	naturals_greater_than_tests();
}
