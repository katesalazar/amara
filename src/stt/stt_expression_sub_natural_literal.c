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
 * src/stt/stt_expression_sub_natural_literal.c: Amara syntax tree
 * natural literal type of expression.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

/*   For `typedef struct natural { ... } natural`. */
/* #include "../brt/brt_forward_declarations.h" */

/*   For `natural * natural_copy_constructor(const natural * natural)`. */
#include "../brt/natural.h"

/*   For `stt_expression_sub_natural_literal`. */
#include "stt_expression_sub_natural_literal.h"

stt_expression_sub_natural_literal *
stt_expression_sub_natural_literal_copy_constructor(
		const stt_expression_sub_natural_literal * expression_sub_natural_literal)
{
	stt_expression_sub_natural_literal * returning_;

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
			(stt_expression_sub_natural_literal *)
#endif
			malloc(sizeof(stt_expression_sub_natural_literal));
	forced_assertion(returning_ != NULL);

	returning_->natural_literal_ = natural_copy_constructor(
			expression_sub_natural_literal->natural_literal_);
#ifndef NDEBUG
	assertion(returning_->natural_literal_ != NULL);
	assertion(returning_->natural_literal_->raw_ != NULL);
	assertion(returning_->natural_literal_->raw_->value_ != NULL);
#endif

	return returning_;
}

stt_expression_sub_natural_literal *
stt_expression_sub_natural_literal_exhaustive_constructor(
		const natural * natural_literal)
{
	stt_expression_sub_natural_literal * returning_;

#ifndef NDEBUG
	assertion(natural_literal != NULL);
	assertion(natural_literal->raw_ != NULL);
	assertion(natural_literal->raw_->value_ != NULL);
#endif

	returning_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_expression_sub_natural_literal *)
#endif
			malloc(sizeof(stt_expression_sub_natural_literal));
	forced_assertion(returning_ != NULL);

	returning_->natural_literal_ =
			natural_copy_constructor(natural_literal);
#ifndef NDEBUG
	assertion(returning_->natural_literal_ != NULL);
	assertion(returning_->natural_literal_->raw_ != NULL);
	assertion(returning_->natural_literal_->raw_->value_ != NULL);
#endif

	return returning_;
}

void
stt_expression_sub_natural_literal_destructor(
		stt_expression_sub_natural_literal * expression_sub_natural_literal)
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
