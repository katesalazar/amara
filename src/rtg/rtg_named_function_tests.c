/*
 * Copyright 2018-2020 Mercedes Catherine Salazar
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
 * src/rtg/rtg_named_function_tests.c: Test the Amara run time graph
 * application named function.
 */

#include "../asr/assertion.h"

#include "rtg_operation_tests.h"

#include "rtg_operations_simple_list_tests.h"

#include "rtg_where_value_bindings_simple_list_tests.h"

#include "rtg_named_function_tests.h"

rtg_named_function *
rtg_named_function_example_print_string_literal_foo()
{
	rtg_where_value_bindings_simple_list * where_value_bindings_;
	rtg_operation * operation_;
	rtg_operations_simple_list * operations_;
	amara_string * amara_string_foo_;
	amara_string * amara_string_print_foo_;
	rtg_named_function * named_function_;

	where_value_bindings_ =
			rtg_where_value_bindings_simple_list_default_constructor();
	forced_assertion(where_value_bindings_ != NULL);
#ifndef NDEBUG
	assertion(where_value_bindings_->first == NULL);
	assertion(where_value_bindings_->next == NULL);
#endif

	operation_ = rtg_operation_example_print_string_literal_foo();
	forced_assertion(operation_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_rtg_operation_example_print_string_literal_foo(
			operation_);
#endif

	operations_ = rtg_operations_simple_list_default_constructor();
	forced_assertion(operations_ != NULL);
#ifndef NDEBUG
	assertion(operations_->first == NULL);
	assertion(operations_->next == NULL);
#endif

	operations_ = rtg_operations_simple_list_push_front(
			operations_, operation_);
#ifndef NDEBUG
	assertion(operations_ != NULL);
	assertion(operations_->first != NULL);
	assert_expectations_on_rtg_operation_example_print_string_literal_foo(
			operations_->first);
	assertion(operations_->next == NULL);
#endif

	rtg_operation_destructor(operation_);

	amara_string_foo_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(amara_string_foo_ != NULL);

	amara_string_print_foo_ = amara_string_exhaustive_constructor(
			"print_foo");
	forced_assertion(amara_string_print_foo_ != NULL);

	named_function_ = rtg_named_function_exhaustive_constructor(
			RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION,
			amara_string_print_foo_, operations_,
			where_value_bindings_);
#ifndef NDEBUG
	assertion(named_function_ != NULL);
	assertion(named_function_->name_ != NULL);
	assertion(named_function_->name_->value_ != NULL);
	assertion(amara_string_equality(
			named_function_->name_, amara_string_print_foo_));
	assertion(named_function_->operations_ != NULL);
	assertion(named_function_->operations_->first != NULL);
	assertion(named_function_->operations_->first->type_ ==
			RTG_OPERATION_TYPE_PRINT);
	assertion(named_function_->operations_->first->args_ != NULL);
	assertion(named_function_->operations_->first->args_->first != NULL);
	assertion(named_function_->operations_->first->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
	assertion(named_function_->operations_->first->args_->first->string_literal_ !=
			NULL);
	assertion(amara_string_equality(
			named_function_->operations_->first->args_->first->string_literal_,
			amara_string_foo_));
	assertion(named_function_->operations_->next == NULL);
#endif

	rtg_where_value_bindings_simple_list_destructor(where_value_bindings_);
	rtg_operations_simple_list_destructor(operations_);
	amara_string_destructor(amara_string_foo_);
	amara_string_destructor(amara_string_print_foo_);

	return named_function_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_named_function_example_print_string_literal_foo(
		const rtg_named_function * named_function)
{
	amara_string * expected_named_function_name_;
	amara_boolean equality_;

	expected_named_function_name_ =
			amara_string_exhaustive_constructor("print_foo");
	assertion(expected_named_function_name_ != NULL);
	assertion(expected_named_function_name_->value_ != NULL);

	assertion(named_function != NULL);
	assertion(named_function->type_ ==
			RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	equality_ = amara_string_equality(
			expected_named_function_name_, named_function->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(named_function->operations_ != NULL);
	assertion(named_function->operations_->first != NULL);
	assert_expectations_on_rtg_operation_example_print_string_literal_foo(
			named_function->operations_->first);
	assertion(named_function->operations_->next == NULL);

	amara_string_destructor(expected_named_function_name_);
}

#endif

rtg_named_function *
rtg_named_function_example_print_string_literal_bar()
{
	rtg_where_value_bindings_simple_list * where_value_bindings_;
	rtg_operation * operation_;
	rtg_operations_simple_list * operations_;
	amara_string * amara_string_print_bar_;
	rtg_named_function * named_function_;
	amara_string * amara_string_bar_;

	where_value_bindings_ =
			rtg_where_value_bindings_simple_list_default_constructor();
	forced_assertion(where_value_bindings_ != NULL);

	operation_ = rtg_operation_example_print_string_literal_bar();
	forced_assertion(operation_ != NULL);

	operations_ = rtg_operations_simple_list_default_constructor();
	forced_assertion(operations_ != NULL);

	operations_ = rtg_operations_simple_list_push_front(
			operations_, operation_);
	forced_assertion(operations_ != NULL);

	rtg_operation_destructor(operation_);

	amara_string_print_bar_ =
			amara_string_exhaustive_constructor("print_bar");
	forced_assertion(amara_string_print_bar_ != NULL);

	amara_string_bar_ = amara_string_exhaustive_constructor("bar");
	forced_assertion(amara_string_bar_ != NULL);

	named_function_ = rtg_named_function_exhaustive_constructor(
			RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION,
			amara_string_print_bar_, operations_,
			where_value_bindings_);
	forced_assertion(named_function_ != NULL);
	forced_assertion(named_function_->name_ != NULL);
	forced_assertion(named_function_->name_->value_ != NULL);
#ifndef NDEBUG
	assertion(amara_string_equality(
			named_function_->name_, amara_string_print_bar_));
#endif
	forced_assertion(named_function_->operations_ != NULL);
	forced_assertion(named_function_->operations_->first != NULL);
#ifndef NDEBUG
	assertion(named_function_->operations_->first->type_ ==
			RTG_OPERATION_TYPE_PRINT);
#endif
	forced_assertion(named_function_->operations_->first->args_ != NULL);
	forced_assertion(named_function_->operations_->first->args_->first !=
			NULL);
#ifndef NDEBUG
	assertion(named_function_->operations_->first->args_->first->type_ ==
			RTG_OPERATION_ARG_TYPE_STRING_LITERAL);
#endif
	forced_assertion(named_function_->operations_->first->args_->first->string_literal_ !=
			NULL);
#ifndef NDEBUG
	assertion(amara_string_equality(
			named_function_->operations_->first->args_->first->string_literal_,
			amara_string_bar_));
	assertion(named_function_->operations_->next == NULL);
#endif

	rtg_where_value_bindings_simple_list_destructor(where_value_bindings_);
	rtg_operations_simple_list_destructor(operations_);
	amara_string_destructor(amara_string_print_bar_);
	amara_string_destructor(amara_string_bar_);

	return named_function_;
}

#ifndef NDEBUG

void
assert_expectations_on_rtg_named_function_example_print_string_literal_bar(
		const rtg_named_function * named_function)
{
	amara_string * expected_named_function_name_;
	amara_boolean equality_;

	expected_named_function_name_ =
			amara_string_exhaustive_constructor("print_bar");
	assertion(expected_named_function_name_ != NULL);
	assertion(expected_named_function_name_->value_ != NULL);

	assertion(named_function != NULL);
	assertion(named_function->type_ ==
			RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	equality_ = amara_string_equality(
			expected_named_function_name_, named_function->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(named_function->operations_ != NULL);
	assertion(named_function->operations_->first != NULL);
	assert_expectations_on_rtg_operation_example_print_string_literal_bar(
			named_function->operations_->first);
	assertion(named_function->operations_->next == NULL);

	amara_string_destructor(expected_named_function_name_);
}

#endif

#ifndef NDEBUG

void
assert_expectations_on_rtg_named_function_example_valid_named_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
		const rtg_named_function * named_function)
{
	assertion(named_function != NULL);
	assertion(named_function->type_ ==
			RTG_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(named_function->operations_ != NULL);
	assert_expectations_on_rtg_operations_simple_list_example_print_identifier_foo(
			named_function->operations_);
	assertion(named_function->where_value_bindings_ != NULL);
	assert_expectations_on_rtg_where_value_bindings_simple_list_example_identifier_foo_is_bound_to_string_literal_foo(
			named_function->where_value_bindings_);
}

#endif

void
rtg_named_function_exhaustive_constructor_test_0()
{
	rtg_named_function * named_function_;

	named_function_ = rtg_named_function_exhaustive_constructor(
			RTG_NAMED_FUNCTION_TYPE_INVALID, NULL, NULL, NULL);
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assertion(named_function_->type_ == RTG_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ == NULL);
	assertion(named_function_->operations_ == NULL);
	assertion(named_function_->where_value_bindings_ == NULL);
#endif

	rtg_named_function_destructor(named_function_);
}

void
rtg_named_function_exhaustive_constructor_test_1()
{
	amara_string * name_;
	rtg_named_function * named_function_;

	name_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(name_ != NULL);

	named_function_ = rtg_named_function_exhaustive_constructor(
			RTG_NAMED_FUNCTION_TYPE_INVALID, name_, NULL, NULL);
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assertion(named_function_->type_ == RTG_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ == NULL);
	assertion(named_function_->operations_ == NULL);
	assertion(named_function_->where_value_bindings_ == NULL);
#endif

	rtg_named_function_destructor(named_function_);
	amara_string_destructor(name_);
}

void
rtg_named_function_exhaustive_constructor_test_2()
{
	rtg_operations_simple_list * operations_;
	rtg_named_function * named_function_;

	operations_ = rtg_operations_simple_list_default_constructor();
	forced_assertion(operations_ != NULL);

	named_function_ = rtg_named_function_exhaustive_constructor(
			RTG_NAMED_FUNCTION_TYPE_INVALID, NULL, operations_,
			NULL);
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assertion(named_function_->type_ == RTG_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ == NULL);
	assertion(named_function_->operations_ == NULL);
	assertion(named_function_->where_value_bindings_ == NULL);
#endif

	rtg_named_function_destructor(named_function_);
	rtg_operations_simple_list_destructor(operations_);
}

void
rtg_named_function_exhaustive_constructor_test_3()
{
	rtg_where_value_bindings_simple_list * where_bindings_;
	rtg_named_function * named_function_;

	where_bindings_ =
			rtg_where_value_bindings_simple_list_default_constructor();
	forced_assertion(where_bindings_ != NULL);

	named_function_ = rtg_named_function_exhaustive_constructor(
			RTG_NAMED_FUNCTION_TYPE_INVALID, NULL, NULL,
			where_bindings_);
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assertion(named_function_->type_ == RTG_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ == NULL);
	assertion(named_function_->operations_ == NULL);
	assertion(named_function_->where_value_bindings_ == NULL);
#endif

	rtg_named_function_destructor(named_function_);
	rtg_where_value_bindings_simple_list_destructor(where_bindings_);
}

void
rtg_named_function_exhaustive_constructor_test_4()
{
	amara_string * name_;
	rtg_operations_simple_list * operations_;
	rtg_named_function * named_function_;

	name_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(name_ != NULL);

	operations_ = rtg_operations_simple_list_default_constructor();
	forced_assertion(operations_ != NULL);

	named_function_ = rtg_named_function_exhaustive_constructor(
			RTG_NAMED_FUNCTION_TYPE_INVALID, name_, operations_,
			NULL);
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assertion(named_function_->type_ == RTG_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ == NULL);
	assertion(named_function_->operations_ == NULL);
	assertion(named_function_->where_value_bindings_ == NULL);
#endif

	rtg_named_function_destructor(named_function_);
	rtg_operations_simple_list_destructor(operations_);
	amara_string_destructor(name_);
}

void
rtg_named_function_exhaustive_constructor_tests()
{
	rtg_named_function_exhaustive_constructor_test_0();
	rtg_named_function_exhaustive_constructor_test_1();
	rtg_named_function_exhaustive_constructor_test_2();
	rtg_named_function_exhaustive_constructor_test_3();
	rtg_named_function_exhaustive_constructor_test_4();
}

void
rtg_named_function_constructors_tests()
{
	rtg_named_function_exhaustive_constructor_tests();
}

tests_simple_list *
register_rtg_named_function_constructors_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_rtg_named_function_constructors_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& rtg_named_function_exhaustive_constructor_test_0);
	tests_simple_list_push_back(
			tests,
			& rtg_named_function_exhaustive_constructor_test_1);
	tests_simple_list_push_back(
			tests,
			& rtg_named_function_exhaustive_constructor_test_2);
	tests_simple_list_push_back(
			tests,
			& rtg_named_function_exhaustive_constructor_test_3);
	tests_simple_list_push_back(
			tests,
			& rtg_named_function_exhaustive_constructor_test_4);
	return tests;
}

void
rtg_named_function_tests()
{
	rtg_named_function_constructors_tests();
}

tests_simple_list *
register_rtg_named_function_tests(tests_simple_list * tests)
{
	return register_rtg_named_function_constructors_tests(tests);
}
