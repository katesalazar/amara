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
 * src/stt/stt_application.c: Amara syntax tree application.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_application.h"

stt_application *
stt_application_copy_constructor(const stt_application * application)
{
	stt_application * ret_;
	assertion(application != NULL);
	assertion(application->type_ != STT_APPLICATION_TYPE_INVALID);
	assertion(application->name_ != NULL);
	assertion(application->name_->value_ != NULL);
	assertion(application->entry_point_function_name_ != NULL);
	assertion(application->entry_point_function_name_->value_ != NULL);
	ret_ = malloc(sizeof(stt_application));
	ret_->entry_point_function_name_ = amara_string_copy_constructor(
			application->entry_point_function_name_);
	ret_->name_ = amara_string_copy_constructor(application->name_);
	ret_->type_ = application->type_;
	return ret_;
}

void
stt_application_destructor(stt_application * application)
{
	if (application->name_ != NULL) {
		amara_string_destructor(application->name_);
	}
	if (application->entry_point_function_name_ != NULL) {
		amara_string_destructor(
				application->entry_point_function_name_);
	}
	free(application);
}
