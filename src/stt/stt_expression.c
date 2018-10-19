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
 * src/stt/stt_expression.c: Amara syntax tree expression.
 */

#include <stdlib.h>

#include "../asr/assertion.h"

#include "stt_expression.h"

stt_expression *
stt_expression_copy_constructor(const stt_expression * expression)
{
	stt_expression * returning_;

	assertion(expression != NULL);
	assertion(expression->type_ != STT_EXPRESSION_TYPE_INVALID);

	returning_ = malloc(sizeof(stt_expression));

	returning_->type_ = expression->type_;

	return returning_;
}
