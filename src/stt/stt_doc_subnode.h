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
 * src/stt/stt_doc_subnode.h: Amara syntax tree document subnode.
 */

#ifndef __AMARA__SYNTAX_TREE__DOC_SUBNODE__H__
#define __AMARA__SYNTAX_TREE__DOC_SUBNODE__H__

/*   For `rtg_named_functions_simple_list`. */
/* #include "../rtg/rtg_named_functions_simple_list.h" */

/*   For `rtg_applications_simple_list`. */
/* #include "../rtg/rtg_applications_simple_list.h" */

/*   For `rtg_execution_requests_simple_list`. */
/* #include "../rtg/rtg_execution_requests_simple_list.h" */

/*   For `stt_named_functions_simple_list`. */
#include "stt_named_functions_simple_list.h"

/*   For `stt_applications_simple_list`. */
#include "stt_applications_simple_list.h"

/*   For `stt_execution_requests_simple_list`. */
#include "stt_execution_requests_simple_list.h"

typedef struct stt_doc_subnode {

	stt_named_functions_simple_list * named_functions_;

	stt_applications_simple_list * applications_;

	stt_execution_requests_simple_list * execution_requests_;
} stt_doc_subnode
;

stt_doc_subnode *
stt_doc_subnode_default_constructor(void)
__attribute__((warn_unused_result))
;

stt_doc_subnode *
stt_doc_subnode_exhaustive_constructor(
		const stt_named_functions_simple_list * named_functions,
		const stt_applications_simple_list * applications,
		const stt_execution_requests_simple_list * execution_requests)
__attribute__((warn_unused_result))
;

stt_doc_subnode *
stt_doc_subnode_copy_constructor(const stt_doc_subnode * subnode)
__attribute__((warn_unused_result))
;

void
stt_doc_subnode_destructor(stt_doc_subnode * subnode)
;

#endif
