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
 * src/stt/stt_expression_sub_string_literal.c: Amara syntax tree string
 * literal type of expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

/*   For `stt_expression_sub_string_literal`. */
#include "stt_expression_sub_string_literal.h"

stt_expression_sub_string_literal *
stt_expression_sub_string_literal_copy_constructor(
		const stt_expression_sub_string_literal * expression_sub_string_literal)
{
	stt_expression_sub_string_literal * returning_;

#ifndef NDEBUG
	assertion(expression_sub_string_literal != NULL);
	assertion(expression_sub_string_literal->string_literal_ != NULL);
	assertion(expression_sub_string_literal->string_literal_->value_ !=
			NULL);
#endif

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_expression_sub_string_literal *)
#endif
			malloc(sizeof(stt_expression_sub_string_literal));
	forced_assertion(returning_ != NULL);

	returning_->string_literal_ = amara_string_copy_constructor(
			expression_sub_string_literal->string_literal_);
	forced_assertion(returning_->string_literal_ != NULL);
	forced_assertion(returning_->string_literal_->value_ != NULL);

	return returning_;
}

stt_expression_sub_string_literal *
stt_expression_sub_string_literal_exhaustive_constructor(
		const amara_string * string_literal)
{
	stt_expression_sub_string_literal * returning_;

#ifndef NDEBUG
	assertion(string_literal != NULL);
	assertion(string_literal->value_ != NULL);
#endif

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_expression_sub_string_literal *)
#endif
			malloc(sizeof(stt_expression_sub_string_literal));
	forced_assertion(returning_ != NULL);

	returning_->string_literal_ =
			amara_string_copy_constructor(string_literal);
#ifndef NDEBUG
	assertion(returning_->string_literal_ != NULL);
	assertion(returning_->string_literal_->value_ != NULL);
#endif

	return returning_;
}


void
stt_expression_sub_string_literal_destructor(
		stt_expression_sub_string_literal * expression_sub_string_literal)
{
#ifndef NDEBUG
	assertion(expression_sub_string_literal != NULL);
	assertion(expression_sub_string_literal->string_literal_ != NULL);
	assertion(expression_sub_string_literal->string_literal_->value_ !=
			NULL);
#endif

	amara_string_destructor(
			expression_sub_string_literal->string_literal_);
	free(expression_sub_string_literal);
}
