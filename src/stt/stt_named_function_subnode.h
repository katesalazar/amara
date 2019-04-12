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
 * src/stt/stt_named_function_subnode.h: Amara syntax tree application
 * named function subnode.
 */

#ifndef __AMARA__SYNTAX_TREE__NAMED_FUNCTION_SUBNODE__H__
#define __AMARA__SYNTAX_TREE__NAMED_FUNCTION_SUBNODE__H__

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   For `stt_named_function`. */
#include "stt_forward_declarations.h"

/*   For `stt_operations_simple_list.h`. */
#include "stt_operations_simple_list.h"

#include "stt_where_value_bindings_simple_list.h"

/*   Enumeration. */
#define STT_NAMED_FUNCTION_SUBNODE_TYPE_INVALID      0x00
#define STT_NAMED_FUNCTION_SUBNODE_TYPE_CLI_APP_NAMED_FUNCTION 0xFF

typedef struct stt_named_function_subnode {

	unsigned char type_;

	amara_string * name_;

	stt_operations_simple_list * operations_;

	stt_where_value_bindings_simple_list * where_value_bindings_;
} stt_named_function_subnode;

stt_named_function_subnode *
stt_named_function_subnode_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_named_function_subnode *
stt_named_function_subnode_copy_constructor(
		const stt_named_function_subnode * subnode)
__attribute__((warn_unused_result))
;

stt_named_function_subnode *
stt_named_function_subnode_exhaustive_constructor(
		const stt_named_function * named_function)
__attribute__((warn_unused_result))
;

void
stt_named_function_subnode_destructor(stt_named_function_subnode * subnode)
;

#endif
