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
 * src/stt/stt_where_value_binding.c: Amara syntax tree _where_ value
 * binding.
 */

#include "../asr/assertion.h"

#include "stt_where_value_binding.h"

stt_where_value_binding *
stt_where_value_binding_default_constructor()
{
	stt_where_value_binding * returning_;

	returning_ = malloc(sizeof(stt_where_value_binding));
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	returning_->value_name_ = NULL;

	returning_->value_expression_ = NULL;

	return returning_;
}

stt_where_value_binding *
stt_where_value_binding_copy_constructor(
		const stt_where_value_binding * where_value_binding_)
{
	stt_where_value_binding * returning_;

	assertion(where_value_binding_ != NULL);
	assertion(where_value_binding_->value_name_ != NULL);
	assertion(where_value_binding_->value_expression_ != NULL);

	returning_ = malloc(sizeof(stt_where_value_binding));

	returning_->value_name_ = amara_string_copy_constructor(
			where_value_binding_->value_name_);

	returning_->value_expression_ = stt_expression_copy_constructor(
			where_value_binding_->value_expression_);

	return returning_;
}

stt_where_value_binding *
stt_where_value_binding_exhaustive_constructor(
		const amara_string * value_name_,
		const stt_expression * value_expression_)
{
	stt_where_value_binding * returning_;

	assertion(value_name_ != NULL);
	assertion(value_name_->value_ != NULL);
	assertion(value_expression_ != NULL);
	assertion(value_expression_->type_ != STT_EXPRESSION_TYPE_INVALID);

	returning_ = malloc(sizeof(stt_where_value_binding));

	returning_->value_name_ = amara_string_copy_constructor(value_name_);

	returning_->value_expression_ =
			stt_expression_copy_constructor(value_expression_);

	return returning_;
}

void
stt_where_value_binding_destructor(
		stt_where_value_binding * stt_where_value_binding_)
{
#ifndef NDEBUG
	assertion(stt_where_value_binding_ != NULL);
#endif

	if (stt_where_value_binding_->value_name_ != NULL) {

#ifndef NDEBUG
		assertion(stt_where_value_binding_->value_name_->value_ !=
				NULL);
		assertion(stt_where_value_binding_->value_expression_ != NULL);
		assertion(stt_where_value_binding_->value_expression_->type_ !=
				STT_EXPRESSION_TYPE_INVALID);
#endif

		amara_string_destructor(stt_where_value_binding_->value_name_);

		stt_expression_destructor(
				stt_where_value_binding_->value_expression_);
	}

	free(stt_where_value_binding_);
}
