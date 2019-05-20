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
 * src/rtg/rtg_expression_sub_natural_literal.c: Amara run time graph
 * natural literal type of expression.
 */

/*   For own functions prototypes. */
#include "rtg_expression_sub_natural_literal.h"

rtg_expression_sub_natural_literal *
rtg_expression_sub_natural_literal_copy_constructor(
		const rtg_expression_sub_natural_literal * expression_sub_natural_literal)
{
	rtg_expression_sub_natural_literal * returning_;

#ifndef NDEBUG
	assertion(expression_sub_natural_literal != NULL);
	assertion(expression_sub_natural_literal->natural_literal_ != NULL);
	assertion(expression_sub_natural_literal->natural_literal_->raw_ !=
			NULL);
	assertion(expression_sub_natural_literal->natural_literal_->raw_->value_ !=
			NULL);
#endif

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_expression_sub_natural_literal *)
#endif
			malloc(sizeof(rtg_expression_sub_natural_literal));
	forced_assertion(returning_ != NULL);

	returning_->natural_literal_ = natural_copy_constructor(
			expression_sub_natural_literal->natural_literal_);
#ifndef NDEBUG
	assertion(returning_->natural_literal_ != NULL);
#endif

	return returning_;
}

void
rtg_expression_sub_natural_literal_destructor(
		rtg_expression_sub_natural_literal * expression_sub_natural_literal)
{
#ifndef NDEBUG
	assertion(expression_sub_natural_literal != NULL);
	assertion(expression_sub_natural_literal->natural_literal_ != NULL);
	assertion(expression_sub_natural_literal->natural_literal_->raw_ !=
			NULL);
	assertion(expression_sub_natural_literal->natural_literal_->raw_->value_ !=
			NULL);
#endif

	natural_destructor(expression_sub_natural_literal->natural_literal_);
	free(expression_sub_natural_literal);
}

#ifndef NDEBUG

void
rtg_expression_sub_natural_literal_assert_healthy(
		const rtg_expression_sub_natural_literal * expression_sub_natural_literal)
{
	assertion(expression_sub_natural_literal != NULL);
	natural_assert_healthy(
			expression_sub_natural_literal->natural_literal_);
}

#endif

rtg_expression_sub_natural_literal *
rtg_expression_sub_natural_literal_out_of_stt_expression_sub_natural_literal(
		const stt_expression_sub_natural_literal * expression_sub_natural_literal)
{
	rtg_expression_sub_natural_literal * returning_;

#ifndef NDEBUG
	assertion(expression_sub_natural_literal != NULL);
	assertion(expression_sub_natural_literal->natural_literal_ != NULL);
#endif

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(rtg_expression_sub_natural_literal *)
#endif
			malloc(sizeof(rtg_expression_sub_natural_literal));
	forced_assertion(returning_ != NULL);

	returning_->natural_literal_ = natural_copy_constructor(
			expression_sub_natural_literal->natural_literal_);
	assertion(returning_->natural_literal_ != NULL);

	return returning_;
}
