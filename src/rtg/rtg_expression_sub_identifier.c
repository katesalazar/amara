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
 * src/rtg/rtg_expression_sub_identifier.c: Amara run time graph
 * identifier type of expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

/*   For own functions prototypes. */
#include "rtg_expression_sub_identifier.h"

rtg_expression_sub_identifier *
rtg_expression_sub_identifier_exhaustive_constructor(
		const amara_string * identifier)
{
	rtg_expression_sub_identifier * ret_;

#ifndef NDEBUG
	assertion(identifier != NULL);
	assertion(identifier->value_ != NULL);
#endif

	ret_ = malloc(sizeof(rtg_expression_sub_identifier));
	forced_assertion(ret_ != NULL);

	ret_->identifier_ = amara_string_copy_constructor(identifier);
	forced_assertion(ret_->identifier_ != NULL);

	return ret_;
}

rtg_expression_sub_identifier *
rtg_expression_sub_identifier_copy_constructor(
		const rtg_expression_sub_identifier * expression_sub_identifier)
{
	rtg_expression_sub_identifier * returning_;

#ifndef NDEBUG
	assertion(expression_sub_identifier != NULL);
	assertion(expression_sub_identifier->identifier_ != NULL);
	assertion(expression_sub_identifier->identifier_->value_ != NULL);
#endif

	returning_ = malloc(sizeof(rtg_expression_sub_identifier));
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	returning_->identifier_ = amara_string_copy_constructor(
			expression_sub_identifier->identifier_);
#ifndef NDEBUG
	assertion(returning_->identifier_ != NULL);
	assertion(returning_->identifier_->value_ != NULL);
#endif

	return returning_;
}

void
rtg_expression_sub_identifier_destructor(
		rtg_expression_sub_identifier * expression_sub_identifier)
{
#ifndef NDEBUG
	assertion(expression_sub_identifier != NULL);
	assertion(expression_sub_identifier->identifier_ != NULL);
	assertion(expression_sub_identifier->identifier_->value_ != NULL);
#endif

	amara_string_destructor(expression_sub_identifier->identifier_);
	free(expression_sub_identifier);
}

rtg_expression_sub_identifier *
rtg_expression_sub_identifier_out_of_stt_expression_sub_identifier(
		const stt_expression_sub_identifier * expression_sub_identifier)
{
	rtg_expression_sub_identifier * returning_;

#ifndef NDEBUG
	assertion(expression_sub_identifier != NULL);
	assertion(expression_sub_identifier->identifier_ != NULL);
#endif

	returning_ = malloc(sizeof(rtg_expression_sub_identifier));
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	returning_->identifier_ = amara_string_copy_constructor(
			expression_sub_identifier->identifier_);
#ifndef NDEBUG
	assertion(returning_->identifier_ != NULL);
#endif

	return returning_;
}

#ifndef NDEBUG

void
rtg_expression_sub_identifier_assert_validity(
		const rtg_expression_sub_identifier * expression_sub_identifier)
{
	assertion(expression_sub_identifier != NULL);
	assertion(expression_sub_identifier->identifier_ != NULL);
	assertion(expression_sub_identifier->identifier_->value_ != NULL);
}

#endif
