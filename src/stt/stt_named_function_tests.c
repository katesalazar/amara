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
 * src/stt/stt_named_function_tests.c: Test the Amara syntax tree
 * application named function.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

void
assertion(int expression)
;

#include "stt_named_function_tests.h"

#include "stt_operation_tests.h"

#include "stt_operations_simple_list_tests.h"

#include "stt_where_value_bindings_simple_list_tests.h"

stt_named_function *
stt_named_function_example_print_string_literal_foo()
{
	amara_string * name_;
	stt_named_function * ret_;
	stt_operations_simple_list * operations_;
	stt_operation * operation_;
	stt_where_value_bindings_simple_list * where_value_bindings_;

	operation_ = stt_operation_example_print_string_literal_foo();
	forced_assertion(operation_ != NULL);
#ifndef NDEBUG
	assertion(operation_->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first != NULL);
	assertion(operation_->args_->first->type_ ==
			STT_OPERATION_ARG_TYPE_VALID);
	assertion(operation_->args_->first->node_ != NULL);
	/*
	assertion(operation_->args_->first->node_->type_ ==
			STT_NODE_TYPE_STRING_LITERAL);
	assertion(operation_->args_->first->node_->string_literal_subnode_ !=
			NULL);
	assertion(operation_->args_->first->node_->string_literal_subnode_->value_ !=
			NULL);
	assertion(amara_string_equality(
			operation_->args_->first->node_->string_literal_subnode_->value_,
			amara_string_exhaustive_constructor("foo"));
	*/
	assertion(operation_->args_->next == NULL);
#endif

	operations_ = stt_operations_simple_list_default_constructor();
	forced_assertion(operations_ != NULL);
#ifndef NDEBUG
	/* TODO missing assertions here. */
#endif

	operations_ = stt_operations_simple_list_push_front(
			operations_, operation_);
#ifndef NDEBUG
	/* TODO missing assertions here. */
#endif

	stt_operation_destructor(operation_);

	where_value_bindings_ =
			stt_where_value_bindings_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(where_value_bindings_ != NULL);
	assertion(where_value_bindings_->first == NULL);
	assertion(where_value_bindings_->next == NULL);
#endif

	name_ = amara_string_exhaustive_constructor("print_foo");
	forced_assertion(name_ != NULL);
	forced_assertion(name_->value_ != NULL);

	ret_ = stt_named_function_exhaustive_constructor(
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION, name_,
			operations_, where_value_bindings_);
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(ret_->name_ != NULL);
	assertion(ret_->name_->value_ != NULL);
	assertion(
			amara_string_equality(
					ret_->name_, name_
			) == AMARA_BOOLEAN_TRUE);
	assertion(ret_->operations_ != NULL);
	assertion(ret_->operations_->first != NULL);
	assertion(ret_->operations_->first->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(ret_->operations_->first->args_ != NULL);
	assertion(ret_->operations_->first->args_->first != NULL);
	assertion(ret_->operations_->first->args_->first->type_ ==
			STT_OPERATION_ARG_TYPE_VALID);
	/*
	assertion(
			amara_string_equality(
					ret_->operations_->first->args_->first->string_literal_,
					amara_string_exhaustive_constructor(
							"foo")
			) == AMARA_BOOLEAN_TRUE);
	*/
	assertion(ret_->operations_->first->args_->next == NULL);
	assertion(ret_->operations_->next == NULL);
	assertion(ret_->where_value_bindings_ != NULL);
	assertion(ret_->where_value_bindings_->first == NULL);
	assertion(ret_->where_value_bindings_->next == NULL);
#endif

	amara_string_destructor(name_);
	stt_operations_simple_list_destructor(operations_);
	stt_where_value_bindings_simple_list_destructor(where_value_bindings_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_named_function_example_print_string_literal_foo(
		const stt_named_function * named_function)
{
	amara_string * expected_named_function_name_;
	amara_boolean equality_;

	expected_named_function_name_ =
			amara_string_exhaustive_constructor("print_foo");
	assertion(expected_named_function_name_ != NULL);
	assertion(expected_named_function_name_->value_ != NULL);

	assertion(named_function != NULL);
	assertion(named_function->type_ ==
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(named_function->name_ != NULL);
	assertion(named_function->name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_named_function_name_, named_function->name_);
	assertion(equality_ = AMARA_BOOLEAN_TRUE);
	assertion(named_function->operations_ != NULL);
	assertion(named_function->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			named_function->operations_->first);
	assertion(named_function->operations_->next == NULL);
	assertion(named_function->where_value_bindings_ != NULL);
	assertion(named_function->where_value_bindings_->first == NULL);
	assertion(named_function->where_value_bindings_->next == NULL);

	amara_string_destructor(expected_named_function_name_);
}

#endif

stt_named_function *
stt_named_function_example_print_string_literal_bar()
{
	amara_string * name_;
	stt_named_function * ret_;
	stt_operations_simple_list * operations_;
	stt_operation * operation_;
	stt_where_value_bindings_simple_list * where_value_bindings_;

	operation_ = stt_operation_example_print_string_literal_bar();
	forced_assertion(operation_ != NULL);
#ifndef NDEBUG
	assertion(operation_->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first != NULL);
	assertion(operation_->args_->first->type_ ==
			STT_OPERATION_ARG_TYPE_VALID);
	assertion(operation_->args_->first->node_ != NULL);
	/*
	assertion(operation_->args_->first->node_->type_ ==
			STT_NODE_TYPE_STRING_LITERAL);
	assertion(operation_->args_->first->node_->string_literal_subnode_ !=
			NULL);
	assertion(operation_->args_->first->node_->string_literal_subnode_->value_ !=
			NULL);
	assertion(amara_string_equality(
			operation_->args_->first->node_->string_literal_subnode_->value_,
			amara_string_exhaustive_constructor("bar"));
	*/
	assertion(operation_->args_->next == NULL);
#endif

	operations_ = stt_operations_simple_list_default_constructor();
#ifndef NDEBUG
	/* TODO missing assertions here. */
#endif

	operations_ = stt_operations_simple_list_push_front(
			operations_, operation_);
	forced_assertion(operations_ != NULL);
#ifndef NDEBUG
	/* TODO missing assertions here. */
#endif

	stt_operation_destructor(operation_);

	where_value_bindings_ =
			stt_where_value_bindings_simple_list_default_constructor();
	forced_assertion(where_value_bindings_ != NULL);
#ifndef NDEBUG
	assertion(where_value_bindings_->first == NULL);
	assertion(where_value_bindings_->next == NULL);
#endif

	name_= amara_string_exhaustive_constructor("print_bar");
	forced_assertion(name_ != NULL);
	forced_assertion(name_->value_ != NULL);

	ret_ = stt_named_function_exhaustive_constructor(
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION, name_,
			operations_, where_value_bindings_);
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(ret_->name_ != NULL);
	assertion(ret_->name_->value_ != NULL);
	assertion(
			amara_string_equality(
					ret_->name_,
					name_
			) == AMARA_BOOLEAN_TRUE);
	assertion(ret_->operations_ != NULL);
	assertion(ret_->operations_->first != NULL);
	assertion(ret_->operations_->first->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(ret_->operations_->first->args_ != NULL);
	assertion(ret_->operations_->first->args_->first != NULL);
	assertion(ret_->operations_->first->args_->first->type_ ==
			STT_OPERATION_ARG_TYPE_VALID);
	/*
	assertion(
			amara_string_equality(
					ret_->operations_->first->args_->first->string_literal_,
					name_
			) == AMARA_BOOLEAN_TRUE);
	*/
	assertion(ret_->operations_->first->args_->next == NULL);
	assertion(ret_->operations_->next == NULL);
	assertion(ret_->where_value_bindings_ != NULL);
	assertion(ret_->where_value_bindings_->first == NULL);
	assertion(ret_->where_value_bindings_->next == NULL);
#endif

	amara_string_destructor(name_);
	stt_operations_simple_list_destructor(operations_);
	stt_where_value_bindings_simple_list_destructor(where_value_bindings_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_named_function_example_print_string_literal_bar(
		const stt_named_function * named_function)
{
	amara_string * expected_named_function_name_;
	amara_boolean equality_;

	expected_named_function_name_ =
			amara_string_exhaustive_constructor("print_bar");
	assertion(expected_named_function_name_ != NULL);
	assertion(expected_named_function_name_->value_ != NULL);

	assertion(named_function != NULL);
	assertion(named_function->type_ ==
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(named_function->name_ != NULL);
	assertion(named_function->name_->value_ != NULL);
	equality_ = amara_string_equality(
			expected_named_function_name_, named_function->name_);
	assertion(equality_ = AMARA_BOOLEAN_TRUE);
	assertion(named_function->operations_ != NULL);
	assertion(named_function->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_bar(
			named_function->operations_->first);
	assertion(named_function->operations_->next == NULL);
	assertion(named_function->where_value_bindings_ != NULL);
	assertion(named_function->where_value_bindings_->first == NULL);
	assertion(named_function->where_value_bindings_->next == NULL);

	amara_string_destructor(expected_named_function_name_);
}

#endif

stt_named_function *
stt_named_function_ill_formed_example_print_identifier_foo()
{
	stt_named_function_type type_;
	amara_string * name_;
	stt_operation * operation_;
	stt_operations_simple_list * operations_;
	stt_where_value_bindings_simple_list * where_bindings_;
	stt_named_function * ret_;

	type_ = STT_NAMED_FUNCTION_TYPE_CLI_APP_NAMED_FUNCTION;

	name_ = amara_string_exhaustive_constructor("invalid");
	forced_assertion(name_ != NULL);
#ifndef NDEBUG
	assertion(name_->value_ != NULL);
	assertion(name_->value_[0] == 'i');
	assertion(name_->value_[1] == 'n');
	assertion(name_->value_[2] == 'v');
	assertion(name_->value_[3] == 'a');
	assertion(name_->value_[4] == 'l');
	assertion(name_->value_[5] == 'i');
	assertion(name_->value_[6] == 'd');
	assertion(name_->value_[7] == '\0');
#endif

	operation_ = stt_operation_example_print_identifier_foo();
	forced_assertion(operation_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			operation_);
#endif

	operations_ = stt_operations_simple_list_default_constructor();
	forced_assertion(operations_ != NULL);
#ifndef NDEBUG
	assertion(operations_->first == NULL);
	assertion(operations_->next == NULL);
#endif

	operations_ = stt_operations_simple_list_push_front(operations_,
	                                                    operation_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			operation_);
#endif
	forced_assertion(operations_ != NULL);
	forced_assertion(operations_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			operations_->first);
	assertion(operations_->next == NULL);
#endif

	stt_operation_destructor(operation_);

	where_bindings_ = NULL;

	ret_ = stt_named_function_exhaustive_constructor(
			type_, name_, operations_, where_bindings_);
#ifndef NDEBUG
	assertion(name_->value_ != NULL);
	assertion(name_->value_[0] == 'i');
	assertion(name_->value_[1] == 'n');
	assertion(name_->value_[2] == 'v');
	assertion(name_->value_[3] == 'a');
	assertion(name_->value_[4] == 'l');
	assertion(name_->value_[5] == 'i');
	assertion(name_->value_[6] == 'd');
	assertion(name_->value_[7] == '\0');
	assertion(operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			operations_->first);
	assertion(operations_->next == NULL);
#endif
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_ill_formed_example_print_identifier_foo(
			ret_);
#endif

	amara_string_destructor(name_);
	stt_operations_simple_list_destructor(operations_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_named_function_ill_formed_example_print_identifier_foo(
		const stt_named_function * named_function)
{
	assertion(named_function != NULL);
	assertion(named_function->type_ ==
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(named_function->name_ != NULL);
	assertion(named_function->name_->value_ != NULL);
	assertion(named_function->name_->value_[0] == 'i');
	assertion(named_function->name_->value_[1] == 'n');
	assertion(named_function->name_->value_[2] == 'v');
	assertion(named_function->name_->value_[3] == 'a');
	assertion(named_function->name_->value_[4] == 'l');
	assertion(named_function->name_->value_[5] == 'i');
	assertion(named_function->name_->value_[6] == 'd');
	assertion(named_function->name_->value_[7] == '\0');
	assertion(named_function->where_value_bindings_ != NULL);
	assertion(named_function->where_value_bindings_->first == NULL);
	assertion(named_function->where_value_bindings_->next == NULL);
	assertion(named_function->operations_ != NULL);
	assertion(named_function->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_identifier_foo(
			named_function->operations_->first);
	assertion(named_function->operations_->next == NULL);
}

#endif

stt_named_function *
stt_named_function_example_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(void)
{
	amara_string * name_;
	stt_operations_simple_list * operations_;
	stt_where_value_bindings_simple_list * where_bindings_;
	stt_named_function * ret_;

	name_ = amara_string_exhaustive_constructor(
			"cli_app_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo");
	forced_assertion(name_ != NULL);

	operations_ = stt_operations_simple_list_example_print_identifier_foo();
	forced_assertion(operations_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_print_identifier_foo(
			operations_);
#endif

	where_bindings_ = stt_where_value_bindings_simple_list_example_identifier_foo_is_bound_to_string_literal_foo();
	forced_assertion(where_bindings_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_where_value_bindings_simple_list_example_identifier_foo_is_bound_to_string_literal_foo(
			where_bindings_);
#endif

	ret_ = stt_named_function_exhaustive_constructor(
			STT_NAMED_FUNCTION_TYPE_CLI_APP_NAMED_FUNCTION, name_,
			operations_, where_bindings_);
#ifndef NDEBUG
	assert_expectations_on_stt_operations_simple_list_example_print_identifier_foo(
			operations_);
	assert_expectations_on_stt_where_value_bindings_simple_list_example_identifier_foo_is_bound_to_string_literal_foo(
			where_bindings_);
#endif
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_example_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
			ret_);
#endif

	amara_string_destructor(name_);
	stt_operations_simple_list_destructor(operations_);
	stt_where_value_bindings_simple_list_destructor(where_bindings_);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_named_function_example_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo(
		const stt_named_function * named_function)
{
	amara_string * function_name_expectation_;
	amara_boolean equality_;

	function_name_expectation_ = amara_string_exhaustive_constructor(
			"cli_app_function_print_identifier_foo_where_identifier_foo_is_bound_to_string_literal_foo");
	forced_assertion(function_name_expectation_ != NULL);
	forced_assertion(function_name_expectation_->value_ != NULL);

	assertion(named_function != NULL);
	assertion(named_function->name_ != NULL);
	assertion(named_function->name_->value_ != NULL);
	equality_ = amara_strings_equality(
			function_name_expectation_, named_function->name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(named_function->operations_ != NULL);
	assertion(named_function->operations_->first != NULL);
	assertion(named_function->operations_->next == NULL);
	assertion(named_function->where_value_bindings_ != NULL);
	assertion(named_function->where_value_bindings_->first != NULL);
	assertion(named_function->where_value_bindings_->next == NULL);

	amara_string_destructor(function_name_expectation_);
}

#endif

void
stt_named_function_default_constructor_test_0()
{
	stt_named_function * named_function_;

	named_function_ = stt_named_function_default_constructor();
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assertion(named_function_->type_ == STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ == NULL);
	assertion(named_function_->operations_ == NULL);
	assertion(named_function_->where_value_bindings_ == NULL);
#endif

	stt_named_function_destructor(named_function_);
}

void
stt_named_function_default_constructor_tests()
{
	stt_named_function_default_constructor_test_0();
}

tests_simple_list *
register_stt_named_function_default_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_named_function_default_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& stt_named_function_default_constructor_test_0);
	return tests;
}

void
stt_named_function_exhaustive_constructor_test_0()
{
	stt_named_function * named_function_;

	named_function_ = stt_named_function_exhaustive_constructor(
			STT_NAMED_FUNCTION_TYPE_INVALID, NULL, NULL, NULL);
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assertion(named_function_->type_ == STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ == NULL);
	assertion(named_function_->operations_ == NULL);
	assertion(named_function_->where_value_bindings_ == NULL);
#endif

	stt_named_function_destructor(named_function_);
}

void
stt_named_function_exhaustive_constructor_test_1()
{
	stt_named_function * named_function_;

	named_function_ = stt_named_function_ill_formed_example_print_identifier_foo();
	forced_assertion(named_function_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_named_function_ill_formed_example_print_identifier_foo(
			named_function_);
#endif

	stt_named_function_destructor(named_function_);
}

void
stt_named_function_exhaustive_constructor_tests()
{
	stt_named_function_exhaustive_constructor_test_0();
	stt_named_function_exhaustive_constructor_test_1();
}

tests_simple_list *
register_stt_named_function_exhaustive_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_named_function_exhaustive_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& stt_named_function_exhaustive_constructor_test_0);
	tests_simple_list_push_back(
			tests,
			& stt_named_function_exhaustive_constructor_test_1);
	return tests;
}

void
stt_named_function_constructors_tests()
{
	stt_named_function_default_constructor_tests();
	stt_named_function_exhaustive_constructor_tests();
}

tests_simple_list *
register_stt_named_function_constructors_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_named_function_constructors_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_named_function_default_constructor_tests(
			tests);
	returning_ = register_stt_named_function_exhaustive_constructor_tests(
			returning_);
	return returning_;
}

void
stt_named_function_setters_test_0()
{
	stt_named_function * named_function_;
	amara_string * name_;
	amara_boolean equality_;
	stt_operations_simple_list * operations_;
	stt_operation * operation_;

	named_function_ = stt_named_function_default_constructor();
	assertion(named_function_ != NULL);
	assertion(named_function_->type_ == STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ == NULL);
	assertion(named_function_->operations_ == NULL);

	name_ = amara_string_exhaustive_constructor("print_foo");
	assertion(name_ != NULL);
	assertion(name_->value_ != NULL);

	stt_named_function_set_name(named_function_, name_);
	assertion(named_function_->type_ == STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ != NULL);
	assertion(named_function_->name_->value_ != NULL);
	assertion(named_function_->operations_ == NULL);
	assertion(name_->value_ != NULL);
	equality_ = amara_string_equality(named_function_->name_, name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	operations_ = stt_operations_simple_list_default_constructor();
	assertion(operations_ != NULL);
	assertion(operations_->first == NULL);
	assertion(operations_->next == NULL);

	operation_ = stt_operation_example_print_string_literal_foo();
#ifndef NDEBUG
	assertion(operation_ != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operation_);
#endif

	operations_ = stt_operations_simple_list_push_front(
			operations_, operation_);
#ifndef NDEBUG
	assertion(operations_ != NULL);
	assertion(operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operations_->first);
	assertion(operations_->next == NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operation_);
#endif

	stt_named_function_set_operations(named_function_, operations_);
#ifndef NDEBUG
	assertion(named_function_->type_ == STT_NAMED_FUNCTION_TYPE_INVALID);
	assertion(named_function_->name_ != NULL);
	assertion(named_function_->name_->value_ != NULL);
	assertion(name_->value_ != NULL);
	equality_ = amara_string_equality(named_function_->name_, name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(named_function_->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			named_function_->operations_->first);
	assertion(named_function_->operations_->next == NULL);
	assertion(operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			operations_->first);
	assertion(operations_->next == NULL);
#endif

	stt_named_function_set_type(named_function_,
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
#ifndef NDEBUG
	assertion(named_function_->type_ ==
			STT_NAMED_FUNCTION_TYPE_CLI_APP_FUNCTION);
	assertion(named_function_->name_ != NULL);
	assertion(named_function_->name_->value_ != NULL);
	assertion(name_->value_ != NULL);
	equality_ = amara_string_equality(named_function_->name_, name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(named_function_->operations_->first != NULL);
	assert_expectations_on_stt_operation_example_print_string_literal_foo(
			named_function_->operations_->first);
	assertion(named_function_->operations_->next == NULL);
#endif

	stt_operation_destructor(operation_);
	stt_operations_simple_list_destructor(operations_);
	amara_string_destructor(name_);
	stt_named_function_destructor(named_function_);
}

void
stt_named_function_setters_tests()
{
	stt_named_function_setters_test_0();
}

tests_simple_list *
register_stt_named_function_setters_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_named_function_setters_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(tests,
	                            & stt_named_function_setters_test_0);
	return tests;
}

void
stt_named_function_tests()
{
	stt_named_function_constructors_tests();
	stt_named_function_setters_tests();
}

tests_simple_list *
register_stt_named_function_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_named_function_constructors_tests(tests);
	returning_ = register_stt_named_function_setters_tests(returning_);
	return returning_;
}
