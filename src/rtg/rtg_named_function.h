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
 * src/rtg/rtg_named_function.h: Amara run time graph application named
 * function.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTION__H__
#define __AMARA__RUN_TIME_GRAPH__NAMED_FUNCTION__H__

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   For `stt_named_function`. */
#include "../stt/stt_named_function.h"

/*   For `rtg_operations_simple_list`. */
#include "rtg_operations_simple_list.h"

/*   This is an enumeration, however it should probably become a mask
 * somewhat soon. */

#define RTG_NAMED_FUNCTION_TYPE_INVALID      0x00
#define RTG_NAMED_FUNCTION_TYPE_PURE_FUNCTION 0x0F
#define RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION 0xF0

typedef struct rtg_named_function {
	unsigned char type_;
	amara_string * name_;
	rtg_operations_simple_list * operations_;
} rtg_named_function;

rtg_named_function *
rtg_named_function_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_named_function *
rtg_named_function_exhaustive_constructor(
		unsigned char type, const amara_string * name,
		const rtg_operations_simple_list * operations)
__attribute__((warn_unused_result))
;

rtg_named_function *
rtg_named_function_copy_constructor(const rtg_named_function * original)
__attribute__((warn_unused_result))
;

void
rtg_named_function_destructor(rtg_named_function * named_function)
;

#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_INVALID          0x00
#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_ERROR_UNSPECIFIC 0x0F
#define RTG_NAMED_FUNCTION_OUT_OF_STT_NAMED_FUNCTION_RET_STATUS_SUCCESS          0xFF

typedef struct rtg_named_function_out_of_stt_named_function_ret {
	unsigned char status;
	rtg_named_function * named_function;
	amara_boolean named_function_was_moved;
} rtg_named_function_out_of_stt_named_function_ret;

void
rtg_named_function_out_of_stt_named_function_ret_destructor(
	rtg_named_function_out_of_stt_named_function_ret * input_ret)
;

rtg_named_function_out_of_stt_named_function_ret *
rtg_named_function_out_of_stt_named_function(
		const stt_named_function * named_function)
__attribute__((warn_unused_result))
;

#endif
