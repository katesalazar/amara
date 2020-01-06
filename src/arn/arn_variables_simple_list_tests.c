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
 * src/arn/arn_variables_simple_list_tests.c: Test the Amara application
 * run time variables simple list.
 */

#include "../asr/assertion.h"

#include "arn_variables_simple_list.h"

#include "arn_variables_simple_list_tests.h"

void
arn_variables_simple_list_default_constructor_test()
{
	arn_variables_simple_list * variables_;

	variables_ = arn_variables_simple_list_default_constructor();
	forced_assertion(variables_ != NULL);
	assertion(variables_->first == NULL);
	assertion(variables_->next == NULL);
	arn_variables_simple_list_destructor(variables_);
}

void
arn_variables_simple_list_constructors_tests()
{
	arn_variables_simple_list_default_constructor_test();
}

tests_simple_list *
register_arn_variables_simple_list_constructors_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_arn_variables_simple_list_constructors_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& arn_variables_simple_list_default_constructor_test);
	return tests;
}

void
arn_variables_simple_list_tests()
{
	arn_variables_simple_list_constructors_tests();
}

tests_simple_list *
register_arn_variables_simple_list_tests(tests_simple_list * tests)
{
	return register_arn_variables_simple_list_constructors_tests(tests);
}
