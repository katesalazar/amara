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
 * src/rtg/rtg_named_functions_fixed_list.h: Amara run time graph
 * application named functions fixed list.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTIONS_FIXED_LIST__H__
#define __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTIONS_FIXED_LIST__H__

/*
#include "../cmn/amara_strings_simple_list.h"
*/

/*   For `stt_doc_subnode`. */
#include "../stt/stt_doc_subnode.h"

/*   For `stt_named_functions_simple_list`. */
#include "../stt/stt_named_functions_simple_list.h"

/*   For `rtg_named_function`. */
#include "rtg_named_function.h"

rtg_named_functions_fixed_list *
rtg_named_functions_fixed_list_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_named_functions_fixed_list *
rtg_named_functions_fixed_list_copy_constructor(
		const rtg_named_functions_simple_list * list)
__attribute__((warn_unused_result))
;

void
rtg_named_functions_fixed_list_destructor(
		rtg_named_functions_fixed_list * list)
;


/**  Pushes a reference to `named_function` at the back of
 * `named_functions`. */
void
rtg_named_functions_fixed_list_push_reference_back(
		rtg_named_functions_fixed_list * named_functions,
		const struct rtg_named_function * named_function)
;

/*

#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_INVALID   0x00
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_SUCCESS   0x0F
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_FIND_BY_NAME_RET_STATUS_NOT_FOUND 0xF0

typedef struct rtg_named_functions_simple_list_find_by_name_ret {

	unsigned char status;

	struct rtg_named_function * named_function;
} rtg_named_functions_simple_list_find_by_name_ret
;

void
rtg_named_functions_simple_list_find_by_name_ret_destructor(
		rtg_named_functions_simple_list_find_by_name_ret * ret_)
;

rtg_named_functions_simple_list_find_by_name_ret *
rtg_named_functions_simple_list_find_by_name(
		const rtg_named_functions_simple_list * haystack,
		const amara_string * needle)
__attribute__((warn_unused_result))
;

#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_INVALID 0x00
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION 0x0E
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_NAMED_FUNCTIONS_SIMPLE_LIST_OUT_OF_STT_NAMED_FUNCTIONS_SIMPLE_LIST_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_named_functions_simple_list_out_of_stt_named_functions_simpe_list_ret {

	unsigned char status;

	amara_strings_simple_list * error_messages;

	rtg_named_functions_simple_list * named_functions;
} rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret
;

*/

/**  Among possible other things, has to transform any present
 * stt_named_function inside, to an rtg_named_function, and
 * add that rtg_named_function to rtg_named_functions, and probably
 * add a pointer to that same rtg_named_function somewhere in the
 * returned structure. */
/*
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list_ret *
rtg_named_functions_simple_list_out_of_stt_named_functions_simple_list(
		const stt_named_functions_simple_list * list,
		rtg_named_functions_fixed_list * rtg_named_functions)
__attribute__((warn_unused_result))
;
*/

#define ENLARGE_RTG_NAMED_FUNCTIONS_FIXED_LIST_WITH_RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_INVALID 0x00
#define ENLARGE_RTG_NAMED_FUNCTIONS_FIXED_LIST_WITH_RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_ERROR_UNABLE_TO_RESOLVE_AT_LEAST_ONE_IDENTIFIER_IN_AT_LEAST_ONE_OPERATION_IN_AT_LEAST_ONE_FUNCTION 0x0E
#define ENLARGE_RTG_NAMED_FUNCTIONS_FIXED_LIST_WITH_RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define ENLARGE_RTG_NAMED_FUNCTIONS_FIXED_LIST_WITH_RTG_NAMED_FUNCTIONS_OUT_OF_STT_DOC_RET_STATUS_SUCCESS 0xFF

typedef struct enlarge_rtg_named_functions_fixed_list_with_rtg_named_functions_out_of_stt_doc_ret {

	unsigned char status;

	amara_strings_simple_list * error_messages;
} enlarge_rtg_named_functions_fixed_list_with_rtg_named_functions_out_of_stt_doc_ret
;

void
enlarge_rtg_named_functions_fixed_list_with_rtg_named_functions_out_of_stt_doc_ret_destructor(
		enlarge_rtg_named_functions_fixed_list_with_rtg_named_functions_out_of_stt_doc_ret * rtg_named_functions_out_of_stt_doc_ret_)
;

/**  Among possible other things, has to transform any present
 * stt_named_function inside, to an rtg_named_function, and
 * add that rtg_named_function to rtg_named_functions, and probably
 * add a pointer to that same rtg_named_function somewhere in the
 * returned structure.
 *   @param subnode Doc subnode from which to build new run time graph
 * functions.
 *   @param rtg_named_functions Already existing run time graph named
 * functions, from other previous docs, or from builtins, etc. */
enlarge_rtg_named_functions_fixed_list_with_rtg_named_functions_out_of_stt_doc_ret *
enlarge_rtg_named_functions_fixed_list_with_rtg_named_functions_out_of_stt_doc(
		const stt_doc_subnode * subnode,
		rtg_named_functions_fixed_list * rtg_named_functions)
__attribute__((warn_unused_result))
;

#endif
