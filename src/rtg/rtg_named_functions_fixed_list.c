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
 * src/rtg/rtg_named_functions_fixed_list.c: Amara run time graph
 * application named functions fixed list.
 */

/*   For owned function prototypes. */
#include "rtg_named_functions_fixed_list.h"

rtg_named_functions_fixed_list *
rtg_named_functions_fixed_list_default_constructor(void)
{
	rtg_named_functions_fixed_list * ret_;

	ret_ = malloc(sizeof(rtg_named_functions_fixed_list));
	forced_assertion(ret_ != NULL);
	ret_->first = NULL;
	ret_->next = NULL;

	return ret_;
}

void
rtg_named_functions_fixed_list_destructor_inner(
		rtg_named_functions_fixed_list * list)
;

void
rtg_named_functions_fixed_list_destructor_inner(
		rtg_named_functions_fixed_list * list)
{
	if (list == NULL) {
#ifndef NDEBUG
		assertion(list->first != NULL);
#endif
		rtg_named_function_destructor(list->first);
		rtg_named_functions_fixed_list_destructor_inner(list->next);
	}
	free(list);
}

void
rtg_named_functions_fixed_list_destructor(
		rtg_named_functions_fixed_list * list)
{
#ifndef NDEBUG
	assertion(list != NULL);
#endif
	if (list->first == NULL) {
#ifndef NDEBUG
		assertion(list->next == NULL);
#endif
	} else {
		rtg_named_functions_fixed_list_destructor_inner(list);
	}
	free(list);
}

void
rtg_named_functions_fixed_list_push_reference_back_inner(
		rtg_named_functions_fixed_list * named_functions,
		const struct rtg_named_function * named_function)
;

void
rtg_named_functions_fixed_list_push_reference_back_inner(
		rtg_named_functions_fixed_list * named_functions,
		const struct rtg_named_function * named_function)
{
#ifndef NDEBUG
	assertion(named_functions != NULL);
	/* named_function is already checked as not null */
#endif
	if (named_functions->next == NULL) {
		named_functions->next =
				malloc(sizeof(rtg_named_functions_fixed_list));
		forced_assertion(named_functions->next != NULL);
		named_functions->next->first =
				(struct rtg_named_function *) named_function;
		named_functions->next->next = NULL;
	} else {
		rtg_named_functions_fixed_list_push_reference_back_inner(
				named_functions->next, named_function);
	}
}

void
rtg_named_functions_fixed_list_push_reference_back(
		rtg_named_functions_fixed_list * named_functions,
		const struct rtg_named_function * named_function)
{
	/*
	rtg_named_functions_fixed_list * new_list_node_;
	*/

#ifndef NDEBUG
	assertion(named_functions != NULL);
	assertion(named_function != NULL);
#endif
	if (named_functions->first == NULL) {
#ifndef NDEBUG
		assertion(named_functions->next == NULL);
#endif
		named_functions->first =
				(struct rtg_named_function *) named_function;
	} else if (named_functions->next == NULL) {
		named_functions->next =
				malloc(sizeof(rtg_named_functions_fixed_list));
		forced_assertion(named_functions->next != NULL);
		named_functions->next->first =
				(struct rtg_named_function *) named_function;
		named_functions->next->next = NULL;
	} else {
		rtg_named_functions_fixed_list_push_reference_back_inner(
				named_functions->next, named_function);
	}
}

void
enlarge_rtg_named_functions_fixed_list_with_rtg_named_functions_out_of_stt_doc_ret_destructor(
		enlarge_rtg_named_functions_fixed_list_with_rtg_named_functions_out_of_stt_doc_ret * rtg_named_functions_out_of_stt_doc_ret_)
{
	forced_assertion(rtg_named_functions_out_of_stt_doc_ret_ != NULL);

	forced_assertion(rtg_named_functions_out_of_stt_doc_ret_->status ==
			ENLARGE_RTG_NAMED_FUNCTIONS_FIXED_LIST_WITH_RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_INVALID);
	forced_assertion(rtg_named_functions_out_of_stt_doc_ret_->error_messages ==
			NULL);

	free(rtg_named_functions_out_of_stt_doc_ret_);
	rtg_named_functions_out_of_stt_doc_ret_ = NULL;
}

enlarge_rtg_named_functions_fixed_list_with_rtg_named_functions_out_of_stt_doc_ret *
enlarge_rtg_named_functions_fixed_list_with_rtg_named_functions_out_of_stt_doc(
		const stt_doc_subnode * subnode,
		rtg_named_functions_fixed_list * rtg_named_functions)
{
	forced_assertion(subnode != NULL);
	forced_assertion(rtg_named_functions != NULL);

	/* XXX
	subnode = NULL;
	*/
	/* XXX
	rtg_named_functions = NULL;
	*/

	return NULL;
}
