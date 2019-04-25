/*
 * Copyright 2018-2019 Mercedes Catherine Salazar
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
 * src/rtg/rtg_named_functions_simple_list.c: Amara run time grap
 * application named functions simple list.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "rtg_named_functions_simple_list.h"

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_default_constructor()
{
	rtg_named_functions_simple_list * ret_;

	ret_ = malloc(sizeof(rtg_named_functions_simple_list));
	forced_assertion(ret_ != NULL);
	ret_->first = NULL;
	ret_->next = NULL;

	return ret_;
}

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_copy_constructor(
		const rtg_named_functions_simple_list * list)
{
	rtg_named_functions_simple_list * ret_;
	rtg_named_functions_simple_list * list_ptr_;
	rtg_named_functions_simple_list * ret_ptr_;
	rtg_named_function * named_function_;
	assertion(list != NULL);
	ret_ = malloc(sizeof(rtg_named_functions_simple_list));
	if (list->first == NULL) {
		ret_->first = NULL;
		assertion(list->next == NULL);
		ret_->next = NULL;
		return ret_;
	}
	list_ptr_ = (rtg_named_functions_simple_list *) list;
	ret_ptr_ = ret_;
	while (list_ptr_->next != NULL) {
		named_function_ = rtg_named_function_copy_constructor(
				list_ptr_->first);
		assertion(named_function_ != NULL);
		ret_ptr_->first = named_function_;
		ret_ptr_->next = malloc(sizeof(
				rtg_named_functions_simple_list));
		list_ptr_ = list_ptr_->next;
		ret_ptr_ = ret_ptr_->next;
	}
	named_function_ = rtg_named_function_copy_constructor(
			list_ptr_->first);
	assertion(named_function_ != NULL);
	ret_ptr_->first = named_function_;
	ret_ptr_->next = NULL;
	return ret_;
}

void
rtg_named_functions_simple_list_destructor(
		rtg_named_functions_simple_list * list)
{
	assertion(list != NULL);
	if (list->first == NULL) {
		assertion(list->next == NULL);
	} else {
		rtg_named_function_destructor(list->first);
	}
	if (list->next != NULL) {
		rtg_named_functions_simple_list_destructor(list->next);
	}
	free(list);
}

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_push_front(
		rtg_named_functions_simple_list * named_functions,
		const rtg_named_function * named_function)
{
	rtg_named_functions_simple_list * new_list_node_;
	assertion(named_functions != NULL);
	assertion(named_function != NULL);
	if (named_functions->first == NULL) {
		assertion(named_functions->next == NULL);
		named_functions->first = rtg_named_function_copy_constructor(
				named_function);
		return named_functions;
	}
	new_list_node_ = malloc(sizeof(rtg_named_functions_simple_list));
	new_list_node_->first =
			rtg_named_function_copy_constructor(named_function);
	new_list_node_->next = named_functions;
	return new_list_node_;
}

void
rtg_named_functions_simple_list_find_by_name_ret_destructor(
		rtg_named_functions_simple_list_find_by_name_ret * ret_)
{
	assertion(ret_ != NULL);
	if (ret_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS) {
		assertion(ret_->named_function != NULL);
		if (ret_->named_function_was_moved == AMARA_BOOLEAN_FALSE) {
			rtg_named_function_destructor(ret_->named_function);
			ret_->named_function = NULL; /* XXX Not actually necessary. */
		}
	} else {
		assertion(ret_->status ==
					RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND);
		assertion(ret_->named_function == NULL);
		assertion(ret_->named_function_was_moved ==
				AMARA_BOOLEAN_FALSE);
	}
	free(ret_);
}

rtg_named_functions_simple_list_find_by_name_ret *
rtg_named_functions_simple_list_find_by_name(
		const rtg_named_functions_simple_list * haystack,
		const amara_string * needle)
{
	rtg_named_functions_simple_list_find_by_name_ret * ret_;
	rtg_named_functions_simple_list_find_by_name_ret * rec_ret_;
	rtg_named_function * named_function_;

	ret_ = malloc(sizeof(
			rtg_named_functions_simple_list_find_by_name_ret));
	forced_assertion(ret_ != NULL);

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "----> %s:%u:rtg_named_functions_find_by_name_ret * rtg_named_functions_find_by_name(const rtg_named_functions_simple_list *, const amara_string *)\n",
			__FILE__, __LINE__);
#endif

	ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_INVALID;
	ret_->named_function = NULL;
	ret_->named_function_was_moved = AMARA_BOOLEAN_FALSE;
	if (haystack == NULL || haystack->first == NULL) {
		ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND;
		ret_->named_function = NULL;
		ret_->named_function_was_moved = AMARA_BOOLEAN_FALSE;

#ifdef DUMP_FLOW_TO_STDERR
		fprintf(stderr, "<---- %s:%u:find_rtg_named_function_by_name_ret * find_rtg_named_function_by_name(const amara_string *, const rtg_named_functions_simple_list *) - not found\n",
				__FILE__, __LINE__);
#endif

		return ret_;
	}
	assertion(needle != NULL);
	if (amara_string_equality(haystack->first->name_, needle)) {
		ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS;
		named_function_ = rtg_named_function_copy_constructor(haystack->first);
		ret_->named_function = named_function_;
		ret_->named_function_was_moved = AMARA_BOOLEAN_FALSE;

#ifdef DUMP_FLOW_TO_STDERR
		fprintf(stderr, "<---- %s:%u:find_rtg_named_function_by_name_ret * find_rtg_named_function_by_name(const amara_string *, const rtg_named_functions_simple_list *) - found\n",
				__FILE__, __LINE__);
#endif

		return ret_;
	}

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "--85- %s:%u:find_rtg_named_function_by_name_ret * find_rtg_named_function_by_name(const amara_string *, const rtg_named_functions_simple_list *) - looking in next\n",
			__FILE__, __LINE__);
#endif

	rec_ret_ = rtg_named_functions_simple_list_find_by_name(
			haystack->next, needle);
	ret_->status = rec_ret_->status;
	if (rec_ret_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS) {
		assertion(rec_ret_->named_function != NULL);
		assertion(rec_ret_->named_function_was_moved ==
				AMARA_BOOLEAN_FALSE);
		rec_ret_->named_function_was_moved = AMARA_BOOLEAN_TRUE;
		ret_->named_function = rec_ret_->named_function;
		ret_->named_function_was_moved = AMARA_BOOLEAN_FALSE;
	} else {
		assertion(rec_ret_->status ==
				RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND);
		assertion(rec_ret_->named_function == NULL);
		assertion(rec_ret_->named_function_was_moved ==
				AMARA_BOOLEAN_FALSE);
		ret_->named_function = NULL;
		ret_->named_function_was_moved = AMARA_BOOLEAN_FALSE;
	}
	rtg_named_functions_simple_list_find_by_name_ret_destructor(rec_ret_);

#ifdef DUMP_FLOW_TO_SDERR
	fprintf(stderr, "<---- %s:%u:find_rtg_named_function_by_name_ret * find_rtg_named_function_by_name(const amara_string *, const rtg_named_functions_simple_list *) - returning recursive case result inconditionally\n",
			__FILE__, __LINE__);
#endif

	return ret_;
}

rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(
		const stt_named_functions_simple_list * list)
{
	rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * ret_;
	rtg_named_functions_simple_list * sub_ret_;
	rtg_named_functions_simple_list * sub_ret_ptr_;
	const stt_named_functions_simple_list * list_ptr_;
	rtg_named_function_out_of_stt_named_function_ret * sub_ret_fun_ret_;

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "%s:%u ----> rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(const stt_named_functions_simple_list *)\n",
			__FILE__, __LINE__);
#endif

	ret_ = malloc(sizeof(
			rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret));
	forced_assertion(ret_ != NULL);

	ret_->error_messages = NULL;
	ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID;

	if (list == NULL || list->first == NULL) {

		if (list != NULL) {

#ifndef NDEBUG
			assertion(list->first == NULL);
			assertion(list->next == NULL);
#endif
		}

		ret_->named_functions =
				rtg_named_functions_simple_list_default_constructor();
		forced_assertion(ret_->named_functions != NULL);
#ifndef NDEBUG
		assertion(ret_->named_functions->first == NULL);
		assertion(ret_->named_functions->next == NULL);
#endif
		ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;

#ifdef DUMP_FLOW_TO_STDERR
		fprintf(stderr, "%s:%u <---- rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(const stt_named_functions_simple_list *)\n",
				__FILE__, __LINE__);
#endif

		return ret_;
	}

	assertion(list->first != NULL);

	sub_ret_ = malloc(sizeof(rtg_named_functions_simple_list));
	forced_assertion(sub_ret_ != NULL);

	sub_ret_fun_ret_ = rtg_named_function_out_of_stt_named_function(list->first);
	forced_assertion(sub_ret_fun_ret_ != NULL);

	if (sub_ret_fun_ret_->status !=
			RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_SUCCESS) {

		forced_assertion(sub_ret_fun_ret_->status ==
				RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION);

		forced_assertion(sub_ret_fun_ret_->error_messages != NULL);

		forced_assertion(sub_ret_fun_ret_->named_function == NULL);

		ret_->named_functions = NULL;

		ret_->error_messages = sub_ret_fun_ret_->error_messages;
		sub_ret_fun_ret_->error_messages = NULL;

		rtg_named_function_out_of_stt_named_function_ret_destructor(
				sub_ret_fun_ret_);

		ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION;

		return ret_;
	}

	forced_assertion(sub_ret_fun_ret_->status ==
			RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_SUCCESS);

	sub_ret_->first = sub_ret_fun_ret_->named_function;
	sub_ret_fun_ret_->named_function = NULL;
	rtg_named_function_out_of_stt_named_function_ret_destructor(
			sub_ret_fun_ret_);
	list_ptr_ = list;
	sub_ret_ptr_ = sub_ret_;
	while (list_ptr_->next != NULL) {

		forced_assertion(list_ptr_->next->first != NULL);

		sub_ret_ptr_->next = malloc(
				sizeof(rtg_named_functions_simple_list));
		forced_assertion(sub_ret_ptr_->next != NULL);

		sub_ret_fun_ret_ =
				rtg_named_function_out_of_stt_named_function(
						list_ptr_->next->first);
#ifndef NDEBUG
		assertion(sub_ret_fun_ret_ != NULL);
		assertion(sub_ret_fun_ret_->status ==
				RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_SUCCESS);
#endif

		sub_ret_ptr_->next->first = sub_ret_fun_ret_->named_function;
		sub_ret_fun_ret_->named_function = NULL;
		rtg_named_function_out_of_stt_named_function_ret_destructor(
				sub_ret_fun_ret_);
		list_ptr_ = list_ptr_->next;
		sub_ret_ptr_ = sub_ret_ptr_->next;
	}
	sub_ret_ptr_->next = NULL;

	ret_->named_functions = sub_ret_;
	ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;

#ifdef DUMP_TRACE_TO_STDERR
	fprintf(stderr, "%s:%u <---- rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(const stt_named_functions_simple_list *)\n",
			__FILE__, __LINE__);
#endif

	return ret_;
}

void
rtg_named_functions_out_of_stt_doc_ret_destructor(
		rtg_named_functions_out_of_stt_doc_ret * rtg_named_functions_out_of_stt_doc_ret_)
{
	forced_assertion(rtg_named_functions_out_of_stt_doc_ret_ != NULL);

	if (rtg_named_functions_out_of_stt_doc_ret_->status ==
			RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS) {

		forced_assertion(rtg_named_functions_out_of_stt_doc_ret_->error_messages ==
				NULL);

		if (rtg_named_functions_out_of_stt_doc_ret_->named_functions !=
				NULL) {

			rtg_named_functions_simple_list_destructor(
					rtg_named_functions_out_of_stt_doc_ret_->named_functions);
		}
	} else {
		forced_assertion(rtg_named_functions_out_of_stt_doc_ret_->status ==
					RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION);

		forced_assertion(rtg_named_functions_out_of_stt_doc_ret_->error_messages !=
				NULL);

		amara_strings_simple_list_destructor(
				rtg_named_functions_out_of_stt_doc_ret_->error_messages);

		forced_assertion(rtg_named_functions_out_of_stt_doc_ret_->named_functions ==
				NULL);
	}

	free(rtg_named_functions_out_of_stt_doc_ret_);
}

rtg_named_functions_out_of_stt_doc_ret *
rtg_named_functions_out_of_stt_doc(const stt_doc_subnode * subnode)
{
	rtg_named_functions_out_of_stt_doc_ret * ret_;
	rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * sub_ret_;

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "%s:%u ----> rtg_named_functions_out_of_stt_doc_ret * rtg_named_functions_out_of_stt_doc(const stt_node *)\n",
			__FILE__, __LINE__);
#endif

	ret_ = malloc(sizeof(rtg_named_functions_out_of_stt_doc_ret));
	forced_assertion(ret_ != NULL);

	ret_->status = RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_INVALID;

	ret_->error_messages = NULL;

	ret_->named_functions = NULL;

	sub_ret_ = rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(
			subnode->named_functions_);
	forced_assertion(sub_ret_ != NULL);

	if (sub_ret_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

		ret_->status = RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS;

		ret_->named_functions = sub_ret_->named_functions;
	} else {
		forced_assertion(sub_ret_->status ==
				RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION);

		forced_assertion(sub_ret_->error_messages != NULL);

#ifndef NDEBUG
		assertion(sub_ret_->named_functions == NULL);
#endif

		ret_->named_functions = NULL;

		ret_->error_messages = sub_ret_->error_messages;
		sub_ret_->error_messages = NULL;

		ret_->status = RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION;
	}

	free(sub_ret_);

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "%s:%u <---- rtg_named_functions_out_of_stt_doc_ret * rtg_named_functions_out_of_stt_doc(const stt_node *)\n",
			__FILE__, __LINE__);
#endif

	return ret_;
}
