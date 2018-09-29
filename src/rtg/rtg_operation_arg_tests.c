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
 * src/rtg/rtg_operation_arg_tests.c: Test the Amara run time graph
 * application function operation argument class.
 */

#include "../asr/assertion.h"
#include "rtg_operation_arg.h"

void
rtg_operation_arg_type_setter_test_0()
{
	rtg_operation_arg * operation_arg_;
	operation_arg_ = rtg_operation_arg_default_constructor();
	assertion(operation_arg_ != NULL);
	assertion(operation_arg_->type_ == RTG_OPERATION_ARG_TYPE_INVALID);
	rtg_operation_arg_set_string_literal(
			operation_arg_,
			amara_string_exhaustive_constructor("foo"));
	assertion(amara_string_equality(
			operation_arg_->string_literal_,
			amara_string_exhaustive_constructor("foo")));
	rtg_operation_arg_set_string_literal(
			operation_arg_,
			amara_string_exhaustive_constructor("bar"));
	assertion(amara_string_equality(
			operation_arg_->string_literal_,
			amara_string_exhaustive_constructor("bar")));
	rtg_operation_arg_set_type(
			operation_arg_,
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	rtg_operation_arg_destructor(operation_arg_);
}

void
rtg_operation_arg_type_setter_tests()
{
	rtg_operation_arg_type_setter_test_0();
	/*
	rtg_operation_arg_type_setter_test_1();
	*/
}

void
rtg_operation_arg_setters_tests()
{
	rtg_operation_arg_type_setter_tests();
}

void
rtg_operation_arg_tests()
{
	rtg_operation_arg_setters_tests();
}
