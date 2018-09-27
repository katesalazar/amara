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
 * src/rtg/rtg_applications_simple_list_tests.c: Test the Amara run time
 * graph applications simple list.
 */

#include "rtg_applications_simple_list.h"

void
rtg_applications_simple_list_construct_and_destruct_test_0()
{
	rtg_applications_simple_list * applications_list_;
	applications_list_ =
			rtg_applications_simple_list_default_constructor();
	rtg_applications_simple_list_destructor(applications_list_);
}

void
rtg_applications_simple_list_construct_and_destruct_test_1()
{
	rtg_applications_simple_list * applications_list_zero_;
	rtg_applications_simple_list * applications_list_one_;
	applications_list_zero_ =
			rtg_applications_simple_list_default_constructor();
	applications_list_one_ = rtg_applications_simple_list_copy_constructor(
			applications_list_zero_);
	rtg_applications_simple_list_destructor(applications_list_one_);
	rtg_applications_simple_list_destructor(applications_list_zero_);
}

void
rtg_applications_simple_list_construct_and_destruct_tests()
{
	rtg_applications_simple_list_construct_and_destruct_test_0();
	rtg_applications_simple_list_construct_and_destruct_test_1();
}

void
rtg_applications_simple_list_tests()
{
	rtg_applications_simple_list_construct_and_destruct_tests();
}
