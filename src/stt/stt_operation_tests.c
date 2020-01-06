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
 * src/stt/stt_operation_tests.c: Test the Amara syntax tree application
 * function operation.
 */

#include "../asr/assertion.h"

#include "stt_node.h"

#include "stt_operation_arg_tests.h"

#include "stt_operation_tests.h"

stt_operation *
stt_operation_example_print_string_literal_foo()
{
	stt_operation * operation_;
	stt_operation_args_simple_list * operation_args_;
	stt_operation_arg * operation_arg_;
	stt_node * operation_arg_node_;
	stt_string_literal_subnode * operation_arg_node_string_literal_subnode_;
	amara_string * string_literal_;

	string_literal_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(string_literal_ != NULL);
	forced_assertion(string_literal_->value_ != NULL);

	operation_arg_node_string_literal_subnode_ =
			stt_string_literal_subnode_exhaustive_constructor(
					string_literal_);
	assertion(operation_arg_node_string_literal_subnode_ != NULL);

	amara_string_destructor(string_literal_);

	operation_arg_node_ = stt_node_default_constructor();
	assertion(operation_arg_node_ != NULL);

	operation_arg_node_->string_literal_subnode_ =
			operation_arg_node_string_literal_subnode_;
	operation_arg_node_->type_ = STT_NODE_TYPE_STRING_LITERAL;

	operation_arg_ = stt_operation_arg_default_constructor();
	forced_assertion(operation_arg_ != NULL);

	operation_arg_->node_ = operation_arg_node_;
	operation_arg_->type_ = STT_OPERATION_ARG_TYPE_VALID;

	operation_args_ = stt_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);

	operation_args_ = stt_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
#ifndef NDEBUG
	assertion(operation_args_ != NULL);
#endif
	forced_assertion(operation_args_->first != NULL);

	stt_operation_arg_destructor(operation_arg_);

	operation_ = stt_operation_default_constructor();
	forced_assertion(operation_ != NULL);

	/* XXX */
	operation_->args_ = operation_args_;
	/* XXX */
	operation_->type_ = STT_OPERATION_TYPE_PRINT;

	return operation_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_example_print_string_literal_foo(
		const stt_operation * operation)
{
	const stt_operation_arg * operation_arg_;
	const stt_node * operation_arg_node_;
	const stt_string_literal_subnode * operation_arg_string_literal_subnode_;
	amara_string * expected_string_literal_;
	amara_boolean equality_;

	expected_string_literal_ = amara_string_exhaustive_constructor("foo");
	assertion(expected_string_literal_ != NULL);
	assertion(expected_string_literal_->value_ != NULL);

	assertion(operation != NULL);
	assertion(operation->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(operation->args_ != NULL);
	assertion(operation->args_->first != NULL);
	operation_arg_ = operation->args_->first;
	assertion(operation_arg_->type_ == STT_OPERATION_ARG_TYPE_VALID);
	assertion(operation_arg_->node_ != NULL);
	operation_arg_node_ = operation_arg_->node_;
	assertion(operation_arg_node_->type_ == STT_NODE_TYPE_STRING_LITERAL);
	assertion(operation_arg_node_->string_literal_subnode_ != NULL);
	operation_arg_string_literal_subnode_ =
			operation_arg_node_->string_literal_subnode_;
	assertion(operation_arg_string_literal_subnode_->string_literal_ !=
			NULL);
	assertion(operation_arg_string_literal_subnode_->string_literal_->value_ !=
			NULL);
	equality_ = amara_string_equality(
			expected_string_literal_,
			operation_arg_string_literal_subnode_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(operation->args_->next == NULL);

	amara_string_destructor(expected_string_literal_);
}

#endif

stt_operation *
stt_operation_example_print_string_literal_bar()
{
	stt_operation * operation_;
	stt_operation_args_simple_list * operation_args_;
	stt_operation_arg * operation_arg_;
	stt_node * operation_arg_node_;
	stt_string_literal_subnode * operation_arg_node_string_literal_subnode_;
	amara_string * string_literal_;

	string_literal_ = amara_string_exhaustive_constructor("bar");
	forced_assertion(string_literal_ != NULL);
#ifndef NDEBUG
	assertion(string_literal_->value_ != NULL);
#endif

	operation_arg_node_string_literal_subnode_ =
			stt_string_literal_subnode_exhaustive_constructor(
					string_literal_);
	forced_assertion(operation_arg_node_string_literal_subnode_ != NULL);
	/* XXX missing assertions */

	amara_string_destructor(string_literal_);

	operation_arg_node_ = stt_node_default_constructor();
	forced_assertion(operation_arg_node_ != NULL);
	/* XXX missing assertions ? */

	operation_arg_node_->string_literal_subnode_ =
			operation_arg_node_string_literal_subnode_;
	operation_arg_node_->type_ = STT_NODE_TYPE_STRING_LITERAL;

	operation_arg_ = stt_operation_arg_default_constructor();
	/* XXX missing assertions */

	operation_arg_->node_ = operation_arg_node_;
	operation_arg_->type_ = STT_OPERATION_ARG_TYPE_VALID;

	operation_args_ = stt_operation_args_simple_list_default_constructor();
	/* XXX missing assertions */

	operation_args_ = stt_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	/* XXX missing assertions */

	stt_operation_arg_destructor(operation_arg_);

	operation_ = stt_operation_default_constructor();
	/* XXX missing assertions */

	operation_->args_ = operation_args_;
	operation_->type_ = STT_OPERATION_TYPE_PRINT;

	return operation_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_example_print_string_literal_bar(
		const stt_operation * operation)
{
	const stt_operation_arg * operation_arg_;
	const stt_node * operation_arg_node_;
	const stt_string_literal_subnode * operation_arg_string_literal_subnode_;
	amara_string * expected_string_literal_;
	amara_boolean equality_;

	expected_string_literal_ = amara_string_exhaustive_constructor("bar");
	assertion(expected_string_literal_ != NULL);
	assertion(expected_string_literal_->value_ != NULL);

	assertion(operation != NULL);
	assertion(operation->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(operation->args_ != NULL);
	assertion(operation->args_->first != NULL);
	operation_arg_ = operation->args_->first;
	assertion(operation_arg_->type_ == STT_OPERATION_ARG_TYPE_VALID);
	assertion(operation_arg_->node_ != NULL);
	operation_arg_node_ = operation_arg_->node_;
	assertion(operation_arg_node_->type_ == STT_NODE_TYPE_STRING_LITERAL);
	assertion(operation_arg_node_->string_literal_subnode_ != NULL);
	operation_arg_string_literal_subnode_ =
			operation_arg_node_->string_literal_subnode_;
	assertion(operation_arg_string_literal_subnode_->string_literal_ !=
			NULL);
	assertion(operation_arg_string_literal_subnode_->string_literal_->value_ !=
			NULL);
	equality_ = amara_string_equality(
			expected_string_literal_,
			operation_arg_string_literal_subnode_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(operation->args_->next == NULL);

	amara_string_destructor(expected_string_literal_);
}

#endif

/*

stt_operation *
stt_operation_example_print_string_literal_foo_no_crlf()
{
	stt_operation * operation_;
	stt_operation_args_simple_list * operation_args_;
	stt_operation_arg * operation_arg_;
	stt_node * operation_arg_node_;
	stt_string_literal_subnode * operation_arg_node_string_literal_subnode_;
	amara_string * string_literal_;
	string_literal_ = amara_string_exhaustive_constructor("foo");
	operation_arg_node_string_literal_subnode_ =
			stt_string_literal_subnode_exhaustive_constructor(
					string_literal_);
	assertion(operation_arg_node_string_literal_subnode_ != NULL);
	operation_arg_node_ = stt_node_default_constructor();
	assertion(operation_arg_node_ != NULL);
	operation_arg_node_->string_literal_subnode_ =
			operation_arg_node_string_literal_subnode_;
	operation_arg_node_->type_ = STT_NODE_TYPE_STRING_LITERAL;
	operation_arg_ = stt_operation_arg_default_constructor();
	operation_arg_->node_ = operation_arg_node_;
	operation_arg_->type_ = STT_OPERATION_ARG_TYPE_VALID;
	operation_args_ = stt_operation_args_simple_list_default_constructor();
	operation_args_ = stt_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
	operation_ = stt_operation_default_constructor();
	operation_->args_ = operation_args_;
	operation_->type_ = STT_OPERATION_TYPE_PRINT_NO_CRLF;
	return operation_;
}

*/

stt_operation *
stt_operation_example_print_identifier_foo()
{
	stt_operation_arg * operation_arg_;
	stt_operation_args_simple_list * operation_args_;
	stt_operation * ret_;

	operation_arg_ = stt_operation_arg_example_identifier_foo();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			operation_arg_);
#endif

	operation_args_ = stt_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);
#endif

	operation_args_ = stt_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			operation_arg_);
#endif
	forced_assertion(operation_args_ != NULL);
	forced_assertion(operation_args_->first != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			operation_args_->first);
	assertion(operation_args_->next == NULL);
#endif

	stt_operation_arg_destructor(operation_arg_);

	ret_ = stt_operation_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_OPERATION_TYPE_INVALID);
#endif

	stt_operation_set_args(ret_, operation_args_);
#ifndef NDEBUG
	assertion(operation_args_->first != NULL);
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			operation_args_->first);
	assertion(operation_args_->next == NULL);
#endif
	forced_assertion(ret_->args_ != NULL);
#ifndef NDEBUG
	assertion(ret_->args_->first != NULL);
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			ret_->args_->first);
	assertion(ret_->args_->next == NULL);
#endif

	stt_operation_args_simple_list_destructor(operation_args_);

	stt_operation_set_type(ret_, STT_OPERATION_TYPE_PRINT);
	forced_assertion(ret_->type_ == STT_OPERATION_TYPE_PRINT);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_example_print_identifier_foo(
		const stt_operation * operation)
{
	assertion(operation != NULL);
	assertion(operation->type_ == STT_OPERATION_TYPE_PRINT);
	assertion(operation->args_ != NULL);
	assertion(operation->args_->first != NULL);
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			operation->args_->first);
	assertion(operation->args_->next == NULL);
}

#endif

stt_operation *
stt_operation_example_read_natural_into_foo(void)
{
	stt_operation_arg * operation_arg_;
	stt_operation_args_simple_list * operation_args_;
	stt_operation * ret_;

	operation_arg_ = stt_operation_arg_example_identifier_foo();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			operation_arg_);
#endif

	operation_args_ = stt_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);
#endif

	operation_args_ = stt_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			operation_arg_);
#endif
	forced_assertion(operation_args_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_->first != NULL);
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			operation_args_->first);
	assertion(operation_args_->next == NULL);
#endif

	stt_operation_arg_destructor(operation_arg_);

	ret_ = stt_operation_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_OPERATION_TYPE_INVALID);
#endif

	stt_operation_set_args(ret_, operation_args_);

	stt_operation_args_simple_list_destructor(operation_args_);

	stt_operation_set_type(ret_,
	                       STT_OPERATION_TYPE_READ_NATURAL_INTO_VALUE);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_example_read_natural_into_foo(
		const stt_operation * operation)
{
	assertion(operation != NULL);
	assertion(operation->type_ ==
			STT_OPERATION_TYPE_READ_NATURAL_INTO_VALUE);
	assertion(operation->args_ != NULL);
	assertion(operation->args_->first != NULL);
	assertion(operation->args_->first->type_ ==
			STT_OPERATION_ARG_TYPE_VALID);
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			operation->args_->first);
	assertion(operation->args_->next == NULL);
}

#endif

stt_operation *
stt_operation_example_read_integer_into_foo(void)
{
	stt_operation_arg * operation_arg_;
	stt_operation_args_simple_list * operation_args_;
	stt_operation * ret_;

	operation_arg_ = stt_operation_arg_example_identifier_foo();
	forced_assertion(operation_arg_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			operation_arg_);
#endif

	operation_args_ = stt_operation_args_simple_list_default_constructor();
	forced_assertion(operation_args_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_->first == NULL);
	assertion(operation_args_->next == NULL);
#endif

	operation_args_ = stt_operation_args_simple_list_push_front(
			operation_args_, operation_arg_);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			operation_arg_);
#endif
	forced_assertion(operation_args_ != NULL);
#ifndef NDEBUG
	assertion(operation_args_->first != NULL);
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			operation_args_->first);
	assertion(operation_args_->next == NULL);
#endif

	stt_operation_arg_destructor(operation_arg_);

	ret_ = stt_operation_default_constructor();
	forced_assertion(ret_ != NULL);
#ifndef NDEBUG
	assertion(ret_->type_ == STT_OPERATION_TYPE_INVALID);
#endif

	stt_operation_set_args(ret_, operation_args_);

	stt_operation_args_simple_list_destructor(operation_args_);

	stt_operation_set_type(ret_,
	                       STT_OPERATION_TYPE_READ_INTEGER_INTO_VALUE);

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_stt_operation_example_read_integer_into_foo(
		const stt_operation * operation)
{
	assertion(operation != NULL);
	assertion(operation->type_ ==
			STT_OPERATION_TYPE_READ_INTEGER_INTO_VALUE);
	assertion(operation->args_ != NULL);
	assertion(operation->args_->first != NULL);
	assertion(operation->args_->first->type_ ==
			STT_OPERATION_ARG_TYPE_VALID);
	assert_expectations_on_stt_operation_arg_example_identifier_foo(
			operation->args_->first);
	assertion(operation->args_->next == NULL);
}

#endif

void
stt_operation_default_constructor_test_0()
{
	stt_operation * operation_;

	operation_ = stt_operation_default_constructor();
	assertion(operation_ != NULL);
	assertion(operation_->type_ == STT_OPERATION_TYPE_INVALID);
	assertion(operation_->args_ == NULL);

	stt_operation_destructor(operation_);
}

/*

void
stt_operation_construct_and_destruct_test_1()
{
	stt_operation * operation_;
	amara_string * expected_string_;
	amara_boolean equality_;

	expected_string_ = amara_string_exhaustive_constructor("foo");
	assertion(expected_string_ != NULL);
	assertion(expected_string_->value_ != NULL);

	operation_ = stt_operation_example_print_foo_no_crlf();
	assertion(operation_ != NULL);
	assertion(operation_->type_ == STT_OPERATION_TYPE_PRINT_NO_CRLF);
	assertion(operation_->args_ != NULL);
	assertion(operation_->args_->first != NULL);
	assertion(operation_->args_->first->type_ ==
			STT_OPERATION_ARG_TYPE_VALID);
	assertion(operation_->args_->first->node_ != NULL);
	assertion(operation_->args_->first->node_->type_ ==
			STT_NODE_TYPE_STRING_LITERAL);
	assertion(operation_->args_->first->node_->string_literal_subnode_ !=
			NULL);
	assertion(operation_->args_->first->node_->string_literal_subnode_->string_literal_ !=
			NULL);
	assertion(operation_->args_->first->node_->string_literal_subnode_->string_literal_->value_ !=
			NULL);
	equality_ = amara_string_equality(
			expected_string_,
			operation_->args_->first->node_->string_literal_subnode_->string_literal_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(operation_->args_->next == NULL);

	stt_operation_destructor(operation_);
}

*/

void
stt_operation_default_constructor_tests()
{
	stt_operation_default_constructor_test_0();
}

tests_simple_list *
register_stt_operation_default_constructor_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_operation_default_constructor_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests, & stt_operation_default_constructor_test_0);
	return tests;
}

void
stt_operation_destructor_test_0()
{
	stt_operation * operation_;

	operation_ = stt_operation_example_read_natural_into_foo();
	forced_assertion(operation_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_read_natural_into_foo(
			operation_);
#endif

	stt_operation_destructor(operation_);
}

void
stt_operation_destructor_test_1()
{
	stt_operation * operation_;

	operation_ = stt_operation_example_read_integer_into_foo();
	forced_assertion(operation_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_stt_operation_example_read_integer_into_foo(
			operation_);
#endif

	stt_operation_destructor(operation_);
}

void
stt_operation_destructor_tests()
{
	stt_operation_destructor_test_0();
	stt_operation_destructor_test_1();
}

tests_simple_list *
register_stt_operation_destructor_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_operation_destructor_tests(tests_simple_list * tests)
{
	tests_simple_list_push_back(tests, & stt_operation_destructor_test_0);
	tests_simple_list_push_back(tests, & stt_operation_destructor_test_1);
	return tests;
}

void
stt_operation_constructors_tests()
{
	stt_operation_default_constructor_tests();
	/*
	stt_operation_construct_and_destruct_test_1();
	*/
	stt_operation_destructor_tests();
}

tests_simple_list *
register_stt_operation_constructors_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_operation_constructors_tests(tests_simple_list * tests)
{
	return register_stt_operation_destructor_tests(
			register_stt_operation_default_constructor_tests(
				tests));
}

void
stt_operation_tests()
{
	stt_operation_constructors_tests();
}

tests_simple_list *
register_stt_operation_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_operation_constructors_tests(tests);
	return returning_;
}
