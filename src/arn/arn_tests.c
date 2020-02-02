/*
 * Copyright 2018, 2020 Mercedes Catherine Salazar
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
 * src/arn/arn_tests.c: Test the Amara applications runtime applications
 * runner and its classes.
 */

#include "arn_type_tests.h"
#include "arn_value_tests.h"
#include "arn_values_fixed_list_tests.h"
#include "arn_values_simple_list_tests.h"
#include "arn_variable_tests.h"
#include "arn_variables_simple_list_tests.h"

#include "arn_tests.h"

void
applications_runner_tests()
{
	arn_type_tests();
	arn_value_tests();
	arn_values_fixed_list_tests();
	arn_values_simple_list_tests();
	arn_variable_tests();
	arn_variables_simple_list_tests();
}

tests_simple_list *
register_applications_runner_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_arn_type_tests(tests);
	returning_ = register_arn_value_tests(returning_);
	returning_ = register_arn_values_fixed_list_tests(returning_);
	returning_ = register_arn_values_simple_list_tests(returning_);
	returning_ = register_arn_variable_tests(returning_);
	returning_ = register_arn_variables_simple_list_tests(returning_);
	return returning_;
}
