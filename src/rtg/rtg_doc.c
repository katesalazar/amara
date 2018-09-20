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
 * src/rtg/rtg_doc.c: Amara run time graph document.
 */

/*   For `rtg_functions_simple_list_copy_constructor`. */
#include "rtg_functions_simple_list.h"

/*   For `rtg_applications_simple_list_copy_constructor`. */
#include "rtg_applications_simple_list.h"

/*   For `rtg_execution_requests_simple_list_copy_constructor`. */
#include "rtg_execution_requests_simple_list.h"

/*   For own definitions. */
#include "rtg_doc.h"

rtg_doc *
rtg_doc_exhaustive_constructor(
		rtg_functions_simple_list * functions,
		rtg_applications_simple_list * applications,
		rtg_execution_requests_simple_list * execution_requests)
{
	rtg_doc * ret_ = malloc(sizeof(rtg_doc));
	ret_->functions_ =
			rtg_functions_simple_list_copy_constructor(functions);
	ret_->applications_ = rtg_applications_simple_list_copy_constructor(
			applications);
	ret_->execution_requests_ =
			rtg_execution_requests_simple_list_copy_constructor(
					execution_requests);
	return ret_;
}
