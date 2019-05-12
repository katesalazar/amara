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
rtg_named_functions_simple_list_shallow_copy_constructor(
		const rtg_named_functions_simple_list * list)
{
	rtg_named_functions_simple_list * ret_;
	rtg_named_functions_simple_list * list_ptr_;
	rtg_named_functions_simple_list * ret_ptr_;
	rtg_named_function * named_function_;

#ifndef NDEBUG
	assertion(list != NULL);
#endif

	ret_ = malloc(sizeof(rtg_named_functions_simple_list));
	forced_assertion(ret_ != NULL);
	if (list->first == NULL) {
		ret_->first = NULL;
		assertion(list->next == NULL);
		ret_->next = NULL;
		return ret_;
	}
	list_ptr_ = (rtg_named_functions_simple_list *) list;
	ret_ptr_ = ret_;
	while (list_ptr_->next != NULL) {
		named_function_ = list_ptr_->first;
		forced_assertion(named_function_ != NULL);
		ret_ptr_->first = named_function_;
		ret_ptr_->next = malloc(sizeof(
				rtg_named_functions_simple_list));
		forced_assertion(ret_ptr_->next != NULL);
		list_ptr_ = list_ptr_->next;
		ret_ptr_ = ret_ptr_->next;
	}
	named_function_ = list_ptr_->first;
	forced_assertion(named_function_ != NULL);
	ret_ptr_->first = named_function_;
	ret_ptr_->next = NULL;
	return ret_;
}

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_deep_copy_constructor(
		const rtg_named_functions_simple_list * list)
{
	rtg_named_functions_simple_list * ret_;
	rtg_named_functions_simple_list * list_ptr_;
	rtg_named_functions_simple_list * ret_ptr_;
	rtg_named_function * named_function_;

#ifndef NDEBUG
	assertion(list != NULL);
#endif

	ret_ = malloc(sizeof(rtg_named_functions_simple_list));
	forced_assertion(ret_ != NULL);
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
		forced_assertion(named_function_ != NULL);
		ret_ptr_->first = named_function_;
		ret_ptr_->next = malloc(sizeof(
				rtg_named_functions_simple_list));
		forced_assertion(ret_ptr_->next != NULL);
		list_ptr_ = list_ptr_->next;
		ret_ptr_ = ret_ptr_->next;
	}
	named_function_ = rtg_named_function_copy_constructor(
			list_ptr_->first);
	forced_assertion(named_function_ != NULL);
	ret_ptr_->first = named_function_;
	ret_ptr_->next = NULL;
	return ret_;
}

void
rtg_named_functions_simple_list_shallow_destructor(
		rtg_named_functions_simple_list * list)
{
	assertion(list != NULL);
	if (list->first == NULL) {
		assertion(list->next == NULL);
	} else {
		/*
		rtg_named_function_destructor(list->first);
		*/
	}
	if (list->next != NULL) {
		rtg_named_functions_simple_list_shallow_destructor(list->next);
	}
	free(list);
}

void
rtg_named_functions_simple_list_deep_destructor(
		rtg_named_functions_simple_list * list)
{
	assertion(list != NULL);
	if (list->first == NULL) {
		assertion(list->next == NULL);
	} else {
		rtg_named_function_destructor(list->first);
	}
	if (list->next != NULL) {
		rtg_named_functions_simple_list_deep_destructor(list->next);
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

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_push_reference_in_front(
		rtg_named_functions_simple_list * named_functions,
		const struct rtg_named_function * named_function)
{
    rtg_named_functions_simple_list * new_node_;
    
#ifndef NDEBUG
    assertion(named_functions != NULL);
    assertion(named_function != NULL);
#endif
    
    if (named_functions->first == NULL) {
#ifndef NDEBUG
        assertion(named_functions->next == NULL);
#endif
        named_functions->first = (struct rtg_named_function *) named_function;
        return named_functions;
    }
    
        new_node_ = rtg_named_functions_simple_list_default_constructor();
        forced_assertion(new_node_ != NULL);
        new_node_->first = (struct rtg_named_function *) named_function;
        new_node_->next = named_functions;
        return new_node_;
}

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_append_all_references_at_end(
		rtg_named_functions_simple_list * to_be_appended_to_here,
		const rtg_named_functions_simple_list * to_be_appended_from_here)
{
    rtg_named_functions_simple_list * ptr_;
    
#ifndef NDEBUG
    assertion(to_be_appended_to_here != NULL);
    assertion(to_be_appended_from_here != NULL);
#endif
    
    if (to_be_appended_from_here->first == NULL) {
#ifndef NDEBUG
        assertion(to_be_appended_from_here->next == NULL);
        #endif
        /* Nothing to be appended, just return the destination */
        return to_be_appended_to_here;
    }
    
    if (to_be_appended_to_here->first == NULL) {
#ifndef NDEBUG
        assertion(to_be_appended_to_here->next == NULL);
#endif
        /* all of the source gets appended in the empty destination, this means a copy of the destination can be returned. */
        return rtg_named_functions_simple_list_shallow_copy_constructor(
            to_be_appended_from_here);
    }
    
    /* must scroll to almost the end */
    ptr_ = to_be_appended_to_here;
    while (ptr_->next != NULL) {
        ptr_ = ptr_->next;
    }
    
    /* then hang them to the destination from a shallow copy of the source */
    ptr_->next = rtg_named_functions_simple_list_shallow_copy_constructor(
                                                                          to_be_appended_from_here);
    
    return to_be_appended_to_here;
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

rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_fixed_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_fixed_list(
		const stt_named_functions_simple_list * list,
		const rtg_named_functions_fixed_list * rtg_named_functions)
{
	rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_fixed_list_ret * ret_;

	forced_assertion(list != NULL);
	forced_assertion(rtg_named_functions != NULL);

	ret_ =
			malloc(sizeof(rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_fixed_list_ret));
	forced_assertion(ret_ != NULL);

	ret_->error_messages = NULL;  /* XXX */
	ret_->new_named_functions_transformed = NULL;  /* XXX */

	return ret_;
}

rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_iterative(
		const stt_named_functions_simple_list * list,
		const rtg_named_functions_simple_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_iterative(
		const stt_named_functions_simple_list * list,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
	rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret * ret_;
	rtg_named_functions_simple_list * sub_ret_;
	rtg_named_functions_simple_list * sub_ret_ptr_;
	const stt_named_functions_simple_list * list_ptr_;
	rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret * sub_ret_fun_ret_;

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "%s:%u ----> rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(const stt_named_functions_simple_list *)\n",
			__FILE__, __LINE__);
#endif

    /*
    bug en esta FUNCIOn - las rtgfunciones que se van creando no se van apilando a la lista que se usa pra resolver las llamadas a funcion, con lo cual como en rtg_named_functions esta la concatenate, se puede crear la concatenate 2 texts, pero como en rtg_named_functions no llega a estar la concatenate 2 texts, resulta que la concatenate 3 texts no se puede llegar a crear bien

     solucion - las functiones (at the time of writing es solo una pero en el futuro serian siempre muchas) en rtg_named_functions apendarlas todas a sub_ret_ en algun momento de la ejecucion, probablemente
     tan pronto como ya haya una funcion correctamete creada en sub_ret_
     ademas apendar las rtg_named_functions como pushes de referencias, no como pushes de copias, esto creo que sería muy muy importante

     el problema es que la sub_ret_ se va construyendo de forma iterativa y com el sub_ret_ptr_, entonces habria que tener cuidado extra, con eso.

     */

	ret_ = malloc(sizeof(
			rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret));
	forced_assertion(ret_ != NULL);

	ret_->error_messages = NULL;
	ret_->new_named_functions_transformed = NULL;
	ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID;

	if (list == NULL || list->first == NULL) {

		if (list != NULL) {

#ifndef NDEBUG
			assertion(list->first == NULL);
			assertion(list->next == NULL);
#endif
		}

		ret_->new_named_functions_transformed =
				rtg_named_functions_simple_list_default_constructor();
		forced_assertion(ret_->new_named_functions_transformed != NULL);
#ifndef NDEBUG
		assertion(ret_->new_named_functions_transformed->first == NULL);
		assertion(ret_->new_named_functions_transformed->next == NULL);
#endif
		ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;

#ifdef DUMP_FLOW_TO_STDERR
		fprintf(stderr, "%s:%u <---- rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(const stt_named_functions_simple_list *)\n",
				__FILE__, __LINE__);
#endif

		return ret_;
	}

	assertion(list->first != NULL);

	sub_ret_ =
			/* malloc(sizeof(rtg_named_functions_simple_list)) */
			rtg_named_functions_simple_list_default_constructor()
	;
	forced_assertion(sub_ret_ != NULL);

	/*
	 * JUSTO AQUI, PROBABLEMENTE, COPIAR TODAS LAS RTG_NAMED_FUNCTIONS COMO REFERENCIAS (NO COMO COPIAS) EN LA SUB_RET_ */

	sub_ret_fun_ret_ = rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list(
			list->first, rtg_named_functions);
	forced_assertion(sub_ret_fun_ret_ != NULL);

	if (sub_ret_fun_ret_->status !=
			RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

		forced_assertion(sub_ret_fun_ret_->status ==
				RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION);

		forced_assertion(sub_ret_fun_ret_->error_messages != NULL);

		forced_assertion(sub_ret_fun_ret_->new_named_function == NULL);

		ret_->new_named_functions_transformed = NULL;

		ret_->error_messages = sub_ret_fun_ret_->error_messages;
		sub_ret_fun_ret_->error_messages = NULL;

		rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret_destructor(
				sub_ret_fun_ret_);

		ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION;

		return ret_;
	}

	forced_assertion(sub_ret_fun_ret_->status ==
			RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);

	sub_ret_->first = sub_ret_fun_ret_->new_named_function;
	sub_ret_fun_ret_->new_named_function = NULL;
	rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret_destructor(
			sub_ret_fun_ret_);
	list_ptr_ = list;
	sub_ret_ptr_ = sub_ret_;
	while (list_ptr_->next != NULL) {

		forced_assertion(list_ptr_->next->first != NULL);

		sub_ret_ptr_->next =
				/*
				malloc(sizeof(rtg_named_functions_simple_list))
				*/
				rtg_named_functions_simple_list_default_constructor()
		;
		forced_assertion(sub_ret_ptr_->next != NULL);

		sub_ret_fun_ret_ =
				rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list(
						list_ptr_->next->first,
						rtg_named_functions);
#ifndef NDEBUG
		assertion(sub_ret_fun_ret_ != NULL);
		assertion(sub_ret_fun_ret_->status ==
				RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
#endif

		sub_ret_ptr_->next->first = sub_ret_fun_ret_->new_named_function;
		sub_ret_fun_ret_->new_named_function = NULL;
		rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret_destructor(
				sub_ret_fun_ret_);
		list_ptr_ = list_ptr_->next;
		sub_ret_ptr_ = sub_ret_ptr_->next;
	}
	sub_ret_ptr_->next = NULL;

	ret_->new_named_functions_transformed = sub_ret_;
	ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;

#ifdef DUMP_TRACE_TO_STDERR
	fprintf(stderr, "%s:%u <---- rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret * rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(const stt_named_functions_simple_list *)\n",
			__FILE__, __LINE__);
#endif

	return ret_;
}

/**  @param list Can be null. */
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_recursive_inner(
		const stt_named_functions_simple_list * list,
		const rtg_named_functions_simple_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_recursive_inner(
		const stt_named_functions_simple_list * list,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
	rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret * ret_;
	rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list_ret * sub_zero_ret_;
	rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret * sub_one_ret_;
	rtg_named_functions_simple_list * ret_sub_;
	/*
	rtg_named_function * new_rtg_named_function_;
	*/

	/*   If the list is empty, there is nothing to do but to return
	 * success and emptyness */

	if (list == NULL) {
		ret_ = malloc(sizeof(rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret));
		forced_assertion(ret_ != NULL);
		ret_->error_messages = NULL;
		ret_->new_named_functions_transformed =
				rtg_named_functions_simple_list_default_constructor();
		forced_assertion(ret_->new_named_functions_transformed != NULL);
		forced_assertion(ret_->new_named_functions_directory != NULL);  /* XXX */
		ret_->new_named_functions_directory = rtg_named_functions;
		ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
		return ret_;
	}

	/* list->next can be null */
	/* list->first is guaranteed not to be null */
#ifndef NDEBUG
	assertion(list->first != NULL);
#endif

	/*   Transform the head of the list */

	sub_zero_ret_ = rtg_named_function_out_of_stt_named_function_and_rtg_named_functions_simple_list(
			list->first, rtg_named_functions);
	forced_assertion(sub_zero_ret_ != NULL);

	if (sub_zero_ret_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION) {

		/*   If an error happened, stop processing the list. */

		forced_assertion(sub_zero_ret_->error_messages != NULL);
#ifndef NDEBUG
		assertion(sub_zero_ret_->new_named_function == NULL);
#endif
		forced_assertion(sub_zero_ret_->new_named_functions_directory !=
				NULL);

		ret_ = malloc(sizeof(rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret));
		forced_assertion(ret_ != NULL);
		ret_->error_messages = sub_zero_ret_->error_messages;  /* XXX */
		sub_zero_ret_->error_messages = NULL;  /* XXX */
		ret_->new_named_functions_transformed = NULL;
		ret_->new_named_functions_directory = rtg_named_functions;
		ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION;
		return ret_;
	}

	forced_assertion(sub_zero_ret_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);

	forced_assertion(sub_zero_ret_->error_messages == NULL);

	forced_assertion(sub_zero_ret_->new_named_functions_directory != NULL);

    /* transform the rest of the list. must pass the new directory to the recursive call */

    sub_one_ret_ =
    rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_recursive_inner(list->next, sub_zero_ret_->new_named_functions_directory
    );
    forced_assertion(sub_one_ret_ != NULL);

    /* Set to null this moved (or else at least invalidated) pointer */
    sub_zero_ret_->new_named_functions_directory = NULL;

    forced_assertion(sub_one_ret_->status ==
                     RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS);
    forced_assertion(sub_one_ret_->error_messages == NULL);
	forced_assertion(
			sub_one_ret_->new_named_functions_transformed != NULL);
    forced_assertion(sub_one_ret_->new_named_functions_directory != NULL);

    /* create the returned RTG named functions list */

    ret_sub_ = rtg_named_functions_simple_list_default_constructor();
	ret_sub_ = rtg_named_functions_simple_list_push_reference_in_front(
			ret_sub_, sub_zero_ret_->new_named_function);
	ret_sub_ = rtg_named_functions_simple_list_append_all_references_at_end(
			ret_sub_, sub_one_ret_->new_named_functions_transformed);
    sub_zero_ret_->new_named_function = NULL;

	/* set null invalidated pointer */
	sub_one_ret_->new_named_functions_transformed = NULL;


    /* prepare the returned structure. must return the directory returned by the recursive call */

    ret_ = malloc(sizeof(rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret));
    forced_assertion(ret_ != NULL);
    ret_->error_messages = NULL;
	ret_->new_named_functions_transformed = ret_sub_;
    ret_sub_ = NULL;
    forced_assertion(sub_one_ret_->new_named_functions_directory != NULL);
    ret_->new_named_functions_directory = sub_one_ret_->new_named_functions_directory;
    sub_one_ret_->new_named_functions_directory = NULL;
    ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;

    return ret_;
}

/**  @param list Should not be null. */
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_recursive(
		const stt_named_functions_simple_list * list,
		const rtg_named_functions_simple_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_recursive(
		const stt_named_functions_simple_list * list,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
	rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret * ret_;

	/*
	forced_assertion(list != NULL);
	*/
	if (list == NULL) {
		ret_ = malloc(sizeof(rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret));
		forced_assertion(ret_ != NULL);
		ret_->error_messages = NULL;
		ret_->new_named_functions_transformed =
				rtg_named_functions_simple_list_default_constructor();
		forced_assertion(
				ret_->new_named_functions_transformed != NULL);
		forced_assertion(ret_->new_named_functions_directory != NULL);  /* XXX */
		ret_->new_named_functions_directory = rtg_named_functions;
		ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
		return ret_;
	}

	if (list->first == NULL) {
#ifndef NDEBUG
		assertion(list->next == NULL);
#endif
		ret_ = malloc(sizeof(rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret));
		forced_assertion(ret_ != NULL);
		ret_->error_messages = NULL;
		ret_->new_named_functions_transformed =
				rtg_named_functions_simple_list_default_constructor();
		forced_assertion(
				ret_->new_named_functions_transformed != NULL);
		forced_assertion(ret_->new_named_functions_directory != NULL);  /* XXX */
		ret_->new_named_functions_directory = rtg_named_functions;
		ret_->status = RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS;
	}

	return rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_recursive_inner(
			list, rtg_named_functions);
}

rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list(
		const stt_named_functions_simple_list * list,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
	return rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_recursive(
			list, rtg_named_functions);
}

/*   XXX */
rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret *
rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list(
		const stt_doc_subnode * subnode,
		struct rtg_named_functions_fixed_list * rtg_named_functions)
{
	rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret * ret_;
	rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_fixed_list_ret * sub_ret_;

	forced_assertion(subnode != NULL);
	forced_assertion(rtg_named_functions != NULL);

	forced_assertion(subnode->named_functions_ != NULL);

	sub_ret_ = rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_fixed_list(
			subnode->named_functions_, rtg_named_functions);
	forced_assertion(sub_ret_ != NULL);

	ret_ =
		malloc(sizeof(rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret));
	forced_assertion(ret_ != NULL);

	forced_assertion(sub_ret_->error_messages == NULL);
	ret_->error_messages = NULL;
	forced_assertion(sub_ret_->new_named_functions_transformed != NULL);
	ret_->new_named_functions_transformed_from_doc =
			sub_ret_->new_named_functions_transformed;

	free(sub_ret_);

	return ret_;
}

void
rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_destructor(
		rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * rtg_named_functions_out_of_stt_doc_ret_)
{
	forced_assertion(rtg_named_functions_out_of_stt_doc_ret_ != NULL);

	if (rtg_named_functions_out_of_stt_doc_ret_->status ==
			RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS) {

		forced_assertion(rtg_named_functions_out_of_stt_doc_ret_->error_messages ==
				NULL);

		if (rtg_named_functions_out_of_stt_doc_ret_->new_named_functions_transformed_from_doc !=
				NULL) {

			rtg_named_functions_simple_list_deep_destructor(
					(rtg_named_functions_simple_list *) rtg_named_functions_out_of_stt_doc_ret_->new_named_functions_transformed_from_doc);
		}
	} else {
		forced_assertion(rtg_named_functions_out_of_stt_doc_ret_->status ==
					RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION);

		forced_assertion(rtg_named_functions_out_of_stt_doc_ret_->error_messages !=
				NULL);

		amara_strings_simple_list_destructor(
				rtg_named_functions_out_of_stt_doc_ret_->error_messages);

		forced_assertion(rtg_named_functions_out_of_stt_doc_ret_->new_named_functions_transformed_from_doc ==
				NULL);
	}

	free(rtg_named_functions_out_of_stt_doc_ret_);
}

rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_simple_list(
		const stt_doc_subnode * subnode,
		const rtg_named_functions_simple_list * rtg_named_functions)
{
	rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * ret_;
	rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret * sub_ret_;

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "%s:%u ----> rtg_named_functions_out_of_stt_doc_ret * rtg_named_functions_out_of_stt_doc(const stt_node *)\n",
			__FILE__, __LINE__);
#endif

	ret_ = malloc(sizeof(rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_simple_list_ret));
	forced_assertion(ret_ != NULL);

	ret_->status = RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_INVALID;

	ret_->error_messages = NULL;

	ret_->new_named_functions_transformed_from_doc = NULL;

	sub_ret_ = rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list(
			subnode->named_functions_, rtg_named_functions);
	forced_assertion(sub_ret_ != NULL);

	if (sub_ret_->status ==
			RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS) {

		ret_->status = RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS;

		ret_->new_named_functions_transformed_from_doc =
				sub_ret_->new_named_functions_transformed;
        ret_->new_named_functions_directory = sub_ret_->new_named_functions_directory;
	} else {
		forced_assertion(sub_ret_->status ==
				RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION);

		forced_assertion(sub_ret_->error_messages != NULL);

#ifndef NDEBUG
		assertion(sub_ret_->new_named_functions_transformed == NULL);
#endif

		ret_->new_named_functions_transformed_from_doc = NULL;

		ret_->new_named_functions_directory = rtg_named_functions;

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
