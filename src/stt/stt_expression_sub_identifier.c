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
 * src/stt/stt_expression_sub_identifier.c: Amara syntax tree identifier
 * type of expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

/*   For `stt_expression_sub_identifier`. */
#include "stt_expression_sub_identifier.h"

stt_expression_sub_identifier *
stt_expression_sub_identifier_exhaustive_constructor(
		const amara_string * identifier)
{
	stt_expression_sub_identifier * returning_;

#ifndef NDEBUG
	assertion(identifier != NULL);
	assertion(identifier->value_ != NULL);
#endif

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_expression_sub_identifier *)
#endif
			malloc(sizeof(stt_expression_sub_identifier));
	forced_assertion(returning_ != NULL);

	returning_->identifier_ = amara_string_copy_constructor(identifier);
#ifndef NDEBUG
	assertion(returning_->identifier_ != NULL);
#endif

	return returning_;
}

stt_expression_sub_identifier *
stt_expression_sub_identifier_copy_constructor(
		const stt_expression_sub_identifier * expression_sub_identifier)
{
	stt_expression_sub_identifier * returning_;

#ifndef NDEBUG
	assertion(expression_sub_identifier != NULL);
	assertion(expression_sub_identifier->identifier_ != NULL);
	assertion(expression_sub_identifier->identifier_->value_ != NULL);
#endif

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_expression_sub_identifier *)
#endif
			malloc(sizeof(stt_expression_sub_identifier));
	forced_assertion(returning_ != NULL);

	returning_->identifier_ = amara_string_copy_constructor(
			expression_sub_identifier->identifier_);
#ifndef NDEBUG
	assertion(returning_->identifier_ != NULL);
#endif

	return returning_;
}

void
stt_expression_sub_identifier_destructor(
		stt_expression_sub_identifier * expression_sub_identifier)
{
#ifndef NDEBUG
	assertion(expression_sub_identifier != NULL);
	assertion(expression_sub_identifier->identifier_ != NULL);
	assertion(expression_sub_identifier->identifier_->value_ != NULL);
#endif

	amara_string_destructor(
			expression_sub_identifier->identifier_);
	free(expression_sub_identifier);
}
