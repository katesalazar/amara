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
 * src/stt/stt_application_subnode_tests.c: Test the Amara syntax tree
 * application subnode.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_application_subnode`. */
#include "stt_application_subnode.h"

void
stt_application_subnode_construct_and_destruct_test_0()
{
	stt_application_subnode * stt_application_subnode_;
	stt_application_subnode_ =
			stt_application_subnode_default_constructor();
	assertion(stt_application_subnode_ != NULL);
	assertion(stt_application_subnode_->type_ ==
			STT_APPLICATION_SUBNODE_TYPE_INVALID);
	assertion(stt_application_subnode_->name_ == NULL);
	assertion(stt_application_subnode_->entry_point_function_name_ ==
			NULL);
	stt_application_subnode_destructor(stt_application_subnode_);
}

void
stt_application_subnode_construct_and_destruct_test_1()
{
	stt_application_subnode * application_subnode_zero_;
	stt_application_subnode * application_subnode_one_;
	amara_string * application_name_;
	amara_string * application_entry_point_function_name_;
	application_subnode_zero_ =
			stt_application_subnode_default_constructor();
	assertion(application_subnode_zero_ != NULL);
	assertion(application_subnode_zero_->type_ ==
			STT_APPLICATION_SUBNODE_TYPE_INVALID);
	assertion(application_subnode_zero_->name_ == NULL);
	assertion(application_subnode_zero_->entry_point_function_name_ ==
			NULL);
	application_name_ = amara_string_exhaustive_constructor("foo");
	application_entry_point_function_name_ =
			amara_string_exhaustive_constructor("bar");
	stt_application_subnode_set_name(
			application_subnode_zero_, application_name_);
	stt_application_subnode_set_entry_point_function_name(
			application_subnode_zero_,
			application_entry_point_function_name_);
	stt_application_subnode_set_type(
			application_subnode_zero_,
			STT_APPLICATION_SUBNODE_TYPE_CLI_APPLICATION);
	application_subnode_one_ =
			stt_application_subnode_copy_constructor(
					application_subnode_zero_);
	amara_string_destructor(application_entry_point_function_name_);
	amara_string_destructor(application_name_);
	stt_application_subnode_destructor(application_subnode_one_);
	stt_application_subnode_destructor(application_subnode_zero_);
}

void
stt_application_subnode_construct_and_destruct_tests()
{
	stt_application_subnode_construct_and_destruct_test_0();
	stt_application_subnode_construct_and_destruct_test_1();
}

void
stt_application_subnode_tests()
{
	stt_application_subnode_construct_and_destruct_tests();
}
