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
 * src/rtg/rtg_named_functions_simple_list_tests.c: Test the Amara run
 * time graph application named functions simple list.
 */

#include "../asr/assertion.h"
#include "rtg_named_functions_simple_list.h"

void
rtg_named_functions_simple_list_construct_and_destruct_test_0()
{
	rtg_named_functions_simple_list * named_functions_zero_;
	named_functions_zero_ =
			rtg_named_functions_simple_list_default_constructor();
	assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first == NULL);
	assertion(named_functions_zero_->next == NULL);
	rtg_named_functions_simple_list_destructor(named_functions_zero_);
}

void
rtg_named_functions_simple_list_construct_and_destruct_test_1()
{
	rtg_named_functions_simple_list * named_functions_zero_;
	rtg_named_functions_simple_list * named_functions_one_;
	named_functions_zero_ =
			rtg_named_functions_simple_list_default_constructor();
	assertion(named_functions_zero_ != NULL);
	assertion(named_functions_zero_->first == NULL);
	assertion(named_functions_zero_->next == NULL);
	named_functions_one_ =
			rtg_named_functions_simple_list_copy_constructor(
					named_functions_zero_);
	assertion(named_functions_one_ != NULL);
	assertion(named_functions_one_->first == NULL);
	assertion(named_functions_one_->next == NULL);
	rtg_named_functions_simple_list_destructor(named_functions_one_);
	rtg_named_functions_simple_list_destructor(named_functions_zero_);
}

void
rtg_named_functions_simple_list_construct_and_destruct_tests()
{
	rtg_named_functions_simple_list_construct_and_destruct_test_0();
	rtg_named_functions_simple_list_construct_and_destruct_test_1();
}

void
rtg_named_functions_simple_list_tests()
{
	rtg_named_functions_simple_list_construct_and_destruct_tests();
}
