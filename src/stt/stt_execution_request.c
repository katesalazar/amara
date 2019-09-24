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
 * src/stt/stt_execution_request.c: Amara syntax tree application
 * execution request.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "stt_execution_request.h"

stt_execution_request *
stt_execution_request_default_constructor()
{
	stt_execution_request * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_execution_request *)
#endif
			malloc(sizeof(stt_execution_request));
	forced_assertion(ret_ != NULL);

	ret_->application_name_ = NULL;
	ret_->type_ = STT_EXECUTION_REQUEST_TYPE_INVALID;

	return ret_;
}

stt_execution_request *
stt_execution_request_copy_constructor(
		const stt_execution_request * execution_request)
{
	stt_execution_request * ret_;

	assertion(execution_request != NULL);
	assertion(execution_request->type_ !=
			STT_EXECUTION_REQUEST_TYPE_INVALID);
	assertion(execution_request->application_name_ != NULL);
	assertion(execution_request->application_name_->value_ != NULL);

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_execution_request *)
#endif
			malloc(sizeof(stt_execution_request));
	forced_assertion(ret_ != NULL);

	ret_->application_name_ = amara_string_copy_constructor(
			execution_request->application_name_);

	ret_->type_ = execution_request->type_;

	return ret_;
}

void
stt_execution_request_destructor(stt_execution_request * execution_request_)
{
	assertion(execution_request_ != NULL);
	if (execution_request_->type_ == STT_EXECUTION_REQUEST_TYPE_INVALID) {
		assertion(execution_request_->application_name_ == NULL);
	} else {
		assertion(execution_request_->type_ ==
				STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);
		assertion(execution_request_->application_name_ != NULL);
		amara_string_destructor(execution_request_->application_name_);
	}
	free(execution_request_);
}

void
stt_execution_request_set_type(
		stt_execution_request * execution_request, unsigned char type)
{
	assertion(execution_request->type_ ==
			STT_EXECUTION_REQUEST_TYPE_INVALID);
	assertion(type == STT_EXECUTION_REQUEST_TYPE_CLI_APPLICATION);
	assertion(execution_request->application_name_ != NULL);
	assertion(execution_request->application_name_->value_ != NULL);
	execution_request->type_ = type;
}

void
stt_execution_request_set_application_name(
		stt_execution_request * execution_request,
		const amara_string * application_name)
{
	assertion(execution_request->type_ ==
			STT_EXECUTION_REQUEST_TYPE_INVALID);
	assertion(execution_request->application_name_ == NULL);
	execution_request->application_name_ =
			(amara_string *) application_name;
}
