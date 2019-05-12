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
 * src/rtg/rtg_expression_sub_identifier.h: Amara run time graph
 * identifier type of expression.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__EXPRESSION_SUB_IDENTIFIER__H__
#define __AMARA__RUN_TIME_GRAPH__EXPRESSION_SUB_IDENTIFIER__H__

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   For `stt_expression_sub_identifier`. */
#include "../stt/stt_expression_sub_identifier.h"

typedef struct rtg_expression_sub_identifier {

	amara_string * identifier_;
} rtg_expression_sub_identifier
;

/**  Exhaustive constructor. */
rtg_expression_sub_identifier *
rtg_expression_sub_identifier_exhaustive_constructor(
		const amara_string * identifier)
__attribute__((warn_unused_result))
;

/**  Copy constructor. */
rtg_expression_sub_identifier *
rtg_expression_sub_identifier_copy_constructor(
		const rtg_expression_sub_identifier * expression_sub_identifier)
__attribute__((warn_unused_result))
;

void
rtg_expression_sub_identifier_destructor(
		rtg_expression_sub_identifier * expression_sub_identifier)
;

/**  Transformation constructor. */
rtg_expression_sub_identifier *
rtg_expression_sub_identifier_out_of_stt_expression_sub_identifier(
		const stt_expression_sub_identifier * expression_sub_identifier)
__attribute__((warn_unused_result))
;

#ifndef NDEBUG

void
rtg_expression_sub_identifier_assert_validity(
		const rtg_expression_sub_identifier * expression_sub_identifier)
;

#endif

#endif
