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
 * src/rtg/rtg_forward_declarations.h: Some Amara run time graph forward
 * declarations.
 */

#ifndef __AMARA__RTG_FORWARD_DECLARATIONS__H__
#define __AMARA__RTG_FORWARD_DECLARATIONS__H__

#include "../cmn/amara_string.h"

/*   This is an enumeration, however it should probably become a mask
 * somewhat soon. */

#define RTG_NAMED_FUNCTION_TYPE_INVALID      0x00
#define RTG_NAMED_FUNCTION_TYPE_PURE_FUNCTION 0x0F
#define RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION 0xF0

typedef struct rtg_named_function {

	unsigned char type_;

	amara_string * name_;

	struct rtg_operations_simple_list * operations_;

	struct rtg_where_value_bindings_simple_list * where_value_bindings_;
} rtg_named_function;

typedef struct rtg_named_functions_simple_list {

	struct rtg_named_function * first;

	struct rtg_named_functions_simple_list * next;
} rtg_named_functions_simple_list
;

typedef struct rtg_named_functions_fixed_list {

	struct rtg_named_function * first;

	struct rtg_named_functions_fixed_list * next;
} rtg_named_functions_fixed_list
;

/*

struct rtg_named_functions_simple_list {

	struct rtg_named_function * first;

	struct rtg_named_functions_simple_list * next;
}
;

*/

#endif
