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
 * src/arn/arn_variable_tests.c: Test the Amara application run time
 * variable.
 */

#include "../asr/assertion.h"

#include "arn_variable.h"

#include "arn_variable_tests.h"

void
arn_variable_default_constructor_test()
{
	arn_variable * variable_;

	variable_ = arn_variable_default_constructor();
	forced_assertion(variable_ != NULL);
	assertion(variable_->type_ == ARN_VARIABLE_TYPE_INVALID);
	assertion(variable_->name_ == NULL);
	assertion(variable_->natural_ == NULL);
	assertion(variable_->natural_was_moved_ == AMARA_BOOLEAN_FALSE);
	arn_variable_destructor(variable_);
}

void
arn_variable_constructors_tests()
{
	arn_variable_default_constructor_test();
}

tests_simple_list *
register_arn_variable_constructors_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_arn_variable_constructors_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests, & arn_variable_default_constructor_test);
	return tests;
}

void
arn_variable_tests()
{
	arn_variable_constructors_tests();
}

tests_simple_list *
register_arn_variable_tests(tests_simple_list * tests)
{
	return register_arn_variable_constructors_tests(tests);
}
