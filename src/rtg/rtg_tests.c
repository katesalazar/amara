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
 * src/rtg/rtg_tests.h: Test the Amara run time graph.
 */

#include "rtg_application_tests.h"
#include "rtg_applications_simple_list_tests.h"
#include "rtg_doc_tests.h"
#include "rtg_execution_request_tests.h"
#include "rtg_execution_requests_simple_list_tests.h"
#include "rtg_named_function_tests.h"
#include "rtg_named_functions_simple_list_tests.h"
#include "rtg_operation_arg_tests.h"
#include "rtg_operation_args_simple_list_tests.h"
#include "rtg_operation_tests.h"
#include "rtg_operations_simple_list_tests.h"

void
run_time_graph_tests()
{
	rtg_operation_arg_tests();
	rtg_operation_args_simple_list_tests();
	rtg_operation_tests();
	rtg_operations_simple_list_tests();
	rtg_named_function_tests();
	rtg_named_functions_simple_list_tests();
	rtg_application_tests();
	rtg_applications_simple_list_tests();
	rtg_execution_request_tests();
	rtg_execution_requests_simple_list_tests();
	rtg_doc_tests();
}
