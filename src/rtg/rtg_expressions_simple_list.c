/*
 * Copyright 2019 Mercedes Catherine Salazar
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
 * src/rtg/rtg_expressions_simple_list.c: Amara run time graph
 * expressions simple list.
 */

#include "../asr/assertion.h"

#include "rtg_expression.h"

#include "rtg_expressions_simple_list.h"

void
rtg_expressions_simple_list_destructor_inner(
		rtg_expressions_simple_list * expressions)
;

void
rtg_expressions_simple_list_destructor_inner(
		rtg_expressions_simple_list * expressions)
{
	if (expressions != NULL) {

#ifndef NDEBUG
		assertion(expressions->first != NULL);
#endif
		rtg_expression_destructor(expressions->first);

		rtg_expressions_simple_list_destructor_inner(
				expressions->next);
	}
}

void
rtg_expressions_simple_list_destructor(
		rtg_expressions_simple_list * expressions)
{
#ifndef NDEBUG
	assertion(expressions != NULL);
#endif

	if (expressions->first == NULL) {

#ifndef NDEBUG
		assertion(expressions->next == NULL);
#endif
		free(expressions);
	} else {
		rtg_expressions_simple_list_destructor_inner(expressions);
	}
}

rtg_expressions_simple_list *
rtg_expressions_simple_list_out_of_stt_expressions_simple_list_inner(
		const stt_expressions_simple_list * stt_expressions,
		const rtg_named_functions_simple_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

rtg_expressions_simple_list *
rtg_expressions_simple_list_out_of_stt_expressions_simple_list_inner(
		const stt_expressions_simple_list * stt_expressions,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
	rtg_expression_out_of_stt_expression_ret * element_ret_;
	rtg_expressions_simple_list * ret_;

	if (stt_expressions == NULL) {

		return NULL;
	}

#ifndef NDEBUG
	assertion(stt_expressions->first != NULL);
#endif

	ret_ = malloc(sizeof(rtg_expressions_simple_list));
	forced_assertion(ret_ != NULL);
	element_ret_ = rtg_expression_out_of_stt_expression(
			stt_expressions->first, rtg_named_functions);
	forced_assertion(element_ret_ != NULL);
	forced_assertion(element_ret_->status ==
			RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS);
#ifndef NDEBUG
	/*
	assertion(element_ret_->messages == NULL);
	*/
#endif
	ret_->first = element_ret_->expression;
#ifndef NDEBUG
	assertion(ret_->first != NULL);
#endif
	ret_->next = rtg_expressions_simple_list_out_of_stt_expressions_simple_list_inner(
			stt_expressions->next, rtg_named_functions);
	/* forced_assertion(ret_->next != NULL); */  /* XXX */
	return ret_;
}

rtg_expressions_simple_list *
rtg_expressions_simple_list_out_of_stt_expressions_simple_list(
		const stt_expressions_simple_list * stt_expressions,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
	rtg_expressions_simple_list * ret_;

#ifndef NDEBUG
	assertion(stt_expressions != NULL);
#endif

	if (stt_expressions->first == NULL) {

#ifndef NDEBUG
		assertion(stt_expressions->next == NULL);
#endif
		ret_ = malloc(sizeof(rtg_expressions_simple_list));
		forced_assertion(ret_ != NULL);
		ret_->first = NULL;
		ret_->next = NULL;
		return ret_;
	} else {
		return rtg_expressions_simple_list_out_of_stt_expressions_simple_list_inner(
				stt_expressions, rtg_named_functions);
	}
}
