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
 * src/arn/app_runner.h: Amara applications runtime applications runner.
 */

#ifndef __AMARA__APPLICATIONS_RUNNER__APP_RUNNER_H__
#define __AMARA__APPLICATIONS_RUNNER__APP_RUNNER_H__

/*   For `rtg_doc`. */
#include "../rtg/rtg_doc.h"

/*   For `stt_node`. */
#include "../stt/stt_node.h"

#define APP_RUNNER_RUN_APP_RET_SUCCESS                0x00
#define APP_RUNNER_RUN_APP_RET_ERROR_DIR_DOES_NOT_EXIST 0x01
#define APP_RUNNER_RUN_APP_RET_ERROR_DOC_DOES_NOT_EXIST 0x02
#define APP_RUNNER_RUN_APP_RET_ERROR_MALFORMED_DOC      0x04

unsigned char
run_app(const char * app_name)
__attribute__((warn_unused_result));

#define PROCESS_RTG_DOC_EXECUTION_REQUESTS_RET_STATUS_INVALID 0x00
#define PROCESS_RTG_DOC_EXECUTION_REQUESTS_RET_STATUS_SUCCESS 0xFF

typedef struct process_rtg_doc_execution_requests_ret {
	unsigned char status;
} process_rtg_doc_execution_requests_ret;

void
process_rtg_doc_execution_requests_ret_destructor(
		process_rtg_doc_execution_requests_ret * process_rtg_doc_execution_requests_ret_)
;

process_rtg_doc_execution_requests_ret *
process_rtg_doc_execution_requests(const rtg_doc * doc)
__attribute__((warn_unused_result))
;


#endif
