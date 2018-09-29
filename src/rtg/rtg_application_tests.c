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
 * src/rtg/rtg_application_tests.c: Test the Amara run time graph
 * application.
 */

#include "../asr/assertion.h"
#include "rtg_application.h"
#include "rtg_application_tests.h"

void
rtg_application_construct_and_destruct_test_0()
{
	rtg_application * application_;
	application_ = rtg_application_default_constructor();
	assertion(application_ != NULL);
	assertion(application_->type_ == RTG_APPLICATION_TYPE_INVALID);
	assertion(application_->name_ == NULL);
	assertion(application_->entry_point_function_ == NULL);
	rtg_application_destructor(application_);
}

void
rtg_application_construct_and_destruct_tests()
{
	rtg_application_construct_and_destruct_test_0();
}

void
rtg_application_tests()
{
	rtg_application_construct_and_destruct_tests();
}
