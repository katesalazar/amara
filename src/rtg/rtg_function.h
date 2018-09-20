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
 * src/rtg/rtg_function.h: Amara run time graph application function.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__FUNCTION__H__
#define __AMARA__RUN_TIME_GRAPH__FUNCTION__H__

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   For `stt_function`. */
#include "../stt/stt_function.h"

/*   For `rtg_operations_simple_list`. */
#include "rtg_operations_simple_list.h"

/*   This is an enumeration, however it should probably become a mask
 * somewhat soon. */

#define RTG_FUNCTION_TYPE_INVALID      0x00
#define RTG_FUNCTION_TYPE_CLI_FUNCTION 0xFF

typedef struct rtg_function {
	uint_fast8_t type_;
	amara_string * name_;
	rtg_operations_simple_list * operations_;
} rtg_function;

rtg_function *
rtg_function_default_constructor(void)
__attribute__((warn_unused_result))
;

rtg_function *
rtg_function_copy_constructor(const rtg_function * original)
__attribute__((warn_unused_result))
;

#define RTG_FUNCTION_OUT_OF_STT_FUNCTION_RET_STATUS_INVALID 0x00
#define RTG_FUNCTION_OUT_OF_STT_FUNCTION_RET_STATUS_SUCCESS 0xFF

typedef struct rtg_function_out_of_stt_function_ret {
	uint_fast8_t status;
	rtg_function * function;
} rtg_function_out_of_stt_function_ret;

rtg_function_out_of_stt_function_ret *
rtg_function_out_of_stt_function(const stt_function * function)
__attribute__((warn_unused_result))
;

#endif
