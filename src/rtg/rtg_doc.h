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
 * src/rtg/rtg_doc.h: Amara run time graph document.
 */

#ifndef __AMARA__RUN_TIME_GRAPH__DOC__H__
#define __AMARA__RUN_TIME_GRAPH__DOC__H__

/*   For `rtg_functions_simple_list`. */
#include "rtg_functions_simple_list.h"

/*   For `rtg_applications_simple_list`. */
#include "rtg_applications_simple_list.h"

/*   For `rtg_execution_requests_simple_list`. */
#include "rtg_execution_requests_simple_list.h"

typedef struct rtg_doc {
	rtg_functions_simple_list * functions_;
	rtg_applications_simple_list * applications_;
	rtg_execution_requests_simple_list * execution_requests_;
} rtg_doc;

rtg_doc *
rtg_doc_exhaustive_constructor(
		rtg_functions_simple_list * functions,
		rtg_applications_simple_list * applications,
		rtg_execution_requests_simple_list * execution_requests)
__attribute__((warn_unused_result))
;

#endif
