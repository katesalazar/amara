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
 * src/rtg/rtg_named_functions_simple_list.h: Amara run time graph
 * application named functions simple list.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTIONS_SIMPLE_LIST__H__
#define __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTIONS_SIMPLE_LIST__H__

#include "../cmn/amara_strings_simple_list.h"

/*   For `stt_doc_subnode`. */
#include "../stt/stt_doc_subnode.h"

/*   For `stt_named_functions_simple_list`. */
#include "../stt/stt_named_functions_simple_list.h"

/*   For `rtg_named_function`. */
#include "rtg_named_function.h"

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_shallow_copy_constructor(
		const rtg_named_functions_simple_list * list)
__attribute__((warn_unused_result))
;

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_deep_copy_constructor(
		const rtg_named_functions_simple_list * list)
__attribute__((warn_unused_result))
;

/**  Destroys only the list, leaving the list elements be. */
void
rtg_named_functions_simple_list_shallow_destructor(
		rtg_named_functions_simple_list * list)
;

/**  Destroys both the list and its elements. */
void
rtg_named_functions_simple_list_deep_destructor(
		rtg_named_functions_simple_list * list)
;

rtg_named_functions_simple_list *
rtg_named_functions_simple_list_push_front(
		rtg_named_functions_simple_list * named_functions,
		const struct rtg_named_function * named_function)
__attribute__((warn_unused_result))
;

/**  Pushes a reference to `named_function` in the front of
 * `named_functions`, so returning the new pointer to `named_functions`. */
rtg_named_functions_simple_list *
rtg_named_functions_simple_list_push_reference_in_front(
		rtg_named_functions_simple_list * named_functions,
		const struct rtg_named_function * named_function)
__attribute__((warn_unused_result))
;

/**  Every RTG named function being held in `to_be_appended_from_here`
 * gets in `to_be_appended_to_here`, however references to those RTG
 * named functions are copied, instead of deep or shallow copying those
 * RTG named functions. */
rtg_named_functions_simple_list *
rtg_named_functions_simple_list_append_all_references_at_end(
		rtg_named_functions_simple_list * to_be_appended_to_here,
		const rtg_named_functions_simple_list * to_be_appended_from_here)
__attribute__((warn_unused_result))
;

#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_INVALID   0x00
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS   0x0F
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND 0xF0

typedef struct rtg_named_functions_simple_list_find_by_name_ret {

	unsigned char status;

	struct rtg_named_function * named_function;

	amara_boolean named_function_was_moved;  /* FIXME Remove this */
} rtg_named_functions_simple_list_find_by_name_ret
;

void
rtg_named_functions_simple_list_find_by_name_ret_destructor(
		rtg_named_functions_simple_list_find_by_name_ret * ret_)
;

/**  Returns a copy (deep, or shallow?) of the RTG named function,
 * not a reference to the RTG named function that resides in the `haystack`. */
rtg_named_functions_simple_list_find_by_name_ret *
rtg_named_functions_simple_list_find_by_name(
		const rtg_named_functions_simple_list * haystack,
		const amara_string * needle)
__attribute__((warn_unused_result))
;

#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_INVALID 0x00
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION 0x0E
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_named_functions_simple_list_out_of_stt_named_functions_simpe_list_and_rtg_named_functions_fixed_list_ret {

	unsigned char status;

	amara_strings_simple_list * error_messages;

	/*   This holds a list of the RTG named functions extracted from
	 * the passed STT named functions list. Pointers are shared with the other
	 * `new_named_functions_directory_` list. */
	const rtg_named_functions_simple_list * new_named_functions_transformed;

	/*   This holds a list of the new RTG named functions directory,
	 * including previously existing RTG named functions together
	 * with the RTG named functions transformed from the passed STT
	 * doc. Pointers are shared with the other
	 * `new_named_functions_transformed_from_doc_` list. */
	/*
	const rtg_named_functions_fixed_list * new_named_functions_directory;
	*/
} rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_fixed_list_ret
;

/**  Among possible other things, has to transform any present
 * `stt_named_function` inside `list`, to an `rtg_named_function`, and
 * add that rtg_named_function to rtg_named_functions, and probably
 * add a pointer to that same rtg_named_function somewhere in the
 * returned structure. */
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_fixed_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_fixed_list(
		const stt_named_functions_simple_list * list,
		const rtg_named_functions_fixed_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID 0x00
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION 0x0E
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_AND_RTG_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_named_functions_simple_list_out_of_stt_named_functions_simpe_list_and_rtg_named_functions_simple_list_ret {

	unsigned char status;

	amara_strings_simple_list * error_messages;

	/*   This holds a list of the RTG named functions extracted from
	 * the passed STT named functions list. Pointers are shared with the other
	 * `new_named_functions_directory_` list. */
	const rtg_named_functions_simple_list * new_named_functions_transformed;

	/*   This holds a list of the new RTG named functions directory,
	 * including previously existing RTG named functions together
	 * with the RTG named functions transformed from the passed STT
	 * doc. Pointers are shared with the other
	 * `new_named_functions_transformed_from_doc_` list. */
	const rtg_named_functions_simple_list * new_named_functions_directory;
} rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret
;

/**  Among possible other things, has to transform any present
 * `stt_named_function` inside `list`, to an `rtg_named_function`, and
 * add that rtg_named_function to rtg_named_functions, and probably
 * add a pointer to that same rtg_named_function somewhere in the
 * returned structure. */
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_and_rtg_named_functions_simple_list(
		const stt_named_functions_simple_list * list,
		const rtg_named_functions_simple_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_INVALID 0x00
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION 0x0E
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_DOC_AND_RTG_NAMED_FUNCTIONS_FIXED_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret {

	unsigned char status;

	amara_strings_simple_list * error_messages;

	const rtg_named_functions_simple_list * new_named_functions_transformed_from_doc;
} rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret
;

void
rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret_destructor(
		rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret * rtg_named_functions_out_of_stt_doc_ret_)
;

/**  Among other possible things, has to transform any present
 * `stt_named_function` inside, to an `rtg_named_function`, and add that
 * `rtg_named_function` to both the `rtg_named_functions` list (i.e. the
 * RTG named functions directory) of every
 * RTG named function found (or provided) so far, apart from adding it
 * to the returned structure. */
rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list_ret *
rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_fixed_list(
		const stt_doc_subnode * subnode,
		struct rtg_named_functions_fixed_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

#define RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_INVALID 0x00
#define RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION 0x0E
#define RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_simple_list_ret {

	unsigned char status;

	amara_strings_simple_list * error_messages;

	/*   This holds a list of the RTG named functions extracted from
	 * the passed STT doc. Pointers are shared with the other
	 * `new_named_functions_directory_` list. */
	const rtg_named_functions_simple_list * new_named_functions_transformed_from_doc;

	/*   This holds a list of the new RTG named functions directory,
	 * including previously existing RTG named functions together
	 * with the RTG named functions transformed from the passed STT
	 * doc. Pointers are shared with the other
	 * `new_named_functions_transformed_from_doc_` list. */
	const rtg_named_functions_simple_list * new_named_functions_directory;
} rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_simple_list_ret
;

void
rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_simple_list_ret_destructor(
		rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_simple_list_ret * rtg_named_functions_out_of_stt_doc_ret_)
;

/**  Among other possible things, has to transform any present
 * `stt_named_function` inside, to an `rtg_named_function`, and add that
 * `rtg_named_function` to both a new list of `rtg_named_functions` (the
 * RTG named functions directory, which is a fixed list, passed in/as
 * `rtg_named_functions`), and to a new list of RTG named functions
 * which holds only the new RTG named functions created by parsing the
 * passed doc (which is returned).
 *   @param subnode Doc subnode from which to build new run time graph
 * functions.
 *   @param rtg_named_functions Already existing run time graph named
 * functions, from other previous docs, or from builtins, etc.
 *   @return RTG named functions created because of parsing
 * `stt_doc_subnode` (i.e. not every one, but all will be at
 * `rtg_named_functions` when this function returns). */
rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_doc_and_rtg_named_functions_simple_list(
		const stt_doc_subnode * subnode,
		const rtg_named_functions_simple_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

#endif
