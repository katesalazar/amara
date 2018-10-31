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
 * src/arn/arn_variables_simple_list_tests.c: Test the Amara application
 * run time variables simple list.
 */

#include "../asr/assertion.h"

#include "arn_variables_simple_list.h"

void
arn_variables_simple_list_construct_and_destruct_test_0()
{
	arn_variables_simple_list * variables_;
	variables_ = arn_variables_simple_list_default_constructor();
	assertion(variables_ != NULL);
	assertion(variables_->first == NULL);
	assertion(variables_->next == NULL);
	arn_variables_simple_list_destructor(variables_);
}

void
arn_variables_simple_list_construct_and_destruct_tests()
{
	arn_variables_simple_list_construct_and_destruct_test_0();
}

void
arn_variables_simple_list_tests()
{
	arn_variables_simple_list_construct_and_destruct_tests();
}
