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
 * src/stt/stt_applications_simple_list_tests.c: Test the Amara syntax
 * tree applications simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_applications_simple_list`. */
#include "stt_applications_simple_list.h"

void
stt_applications_simple_list_construct_and_destruct_test_0()
{
	stt_applications_simple_list * list_;
	list_ = stt_applications_simple_list_default_constructor();
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
	stt_applications_simple_list_destructor(list_);
}

void
stt_applications_simple_list_construct_and_destruct_test_1()
{
	stt_applications_simple_list * list_zero_;
	stt_applications_simple_list * list_one_;
	list_zero_ = stt_applications_simple_list_default_constructor();
	assertion(list_zero_ != NULL);
	assertion(list_zero_->first == NULL);
	assertion(list_zero_->next == NULL);
	list_one_ = stt_applications_simple_list_copy_constructor(list_zero_);
	assertion(list_one_ != NULL);
	assertion(list_one_->first == NULL);
	assertion(list_one_->next == NULL);
	stt_applications_simple_list_destructor(list_zero_);
	stt_applications_simple_list_destructor(list_one_);
}

void
stt_applications_simple_list_construct_and_destruct_tests()
{
	stt_applications_simple_list_construct_and_destruct_test_0();
	stt_applications_simple_list_construct_and_destruct_test_1();
}

void
stt_applications_simple_list_tests()
{
	stt_applications_simple_list_construct_and_destruct_tests();
}
