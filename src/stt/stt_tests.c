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
 * src/stt/stt_tests.c: Amara syntax tree tests.
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `int strcmp(const char * s1, const char * s2)`. */
#include <string.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_node`. */
#include "stt_node.h"

void
node_name_from_type_test_0()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_test_0()\n", __FILE__, __LINE__);
#endif
	const stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_ = stt_node_type_name(node_);
	const amara_string * expectation_ =
			amara_string_exhaustive_constructor("invalid");
	amara_boolean equality_ = amara_string_equality(
			type_name_, expectation_);
	assertion(equality_);
	amara_string_destructor((amara_string *) expectation_);
	amara_string_destructor((amara_string *) type_name_);
	stt_node_destructor(node_);
}

void
node_name_from_type_test_1()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_test_1()\n", __FILE__, __LINE__);
#endif
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	const amara_string * string_literal_;
	amara_boolean equality_;
	string_literal_ = amara_string_exhaustive_constructor("foo");
	stt_node_set_string_literal(node_, string_literal_);
	type_name_ = stt_node_type_name(node_);
	expectation_ = amara_string_exhaustive_constructor("string_literal");
	equality_ = amara_string_equality(type_name_, expectation_);
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: equality_: %u\n", __FILE__, __LINE__, equality_);
#endif
	assertion(equality_);
	amara_string_destructor((amara_string *) expectation_);
	amara_string_destructor((amara_string *) type_name_);
	stt_node_destructor(node_);
}

void
node_name_from_type_test_2()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_test_2()\n", __FILE__, __LINE__);
#endif
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	const amara_string * raw_natural_;
	amara_boolean equality_;
	raw_natural_ = amara_string_exhaustive_constructor("15");
	stt_node_set_natural(node_, raw_natural_);
	type_name_ = stt_node_type_name(node_);
	expectation_ = amara_string_exhaustive_constructor("natural");
	equality_ = amara_string_equality(type_name_, expectation_);
	assertion(equality_);
	amara_string_destructor((amara_string *) expectation_);
	amara_string_destructor((amara_string *) type_name_);
	stt_node_destructor(node_);
}

void
node_name_from_type_test_3()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_test_3()\n", __FILE__, __LINE__);
#endif
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	const amara_string * raw_integer_;
	amara_boolean equality_;
	raw_integer_ = amara_string_exhaustive_constructor("-1");
	stt_node_set_integer(node_, raw_integer_);
	type_name_ = stt_node_type_name(node_);
	expectation_ = amara_string_exhaustive_constructor("integer");
	equality_ = amara_string_equality(type_name_, expectation_);
	assertion(equality_);
	amara_string_destructor((amara_string *) expectation_);
	amara_string_destructor((amara_string *) type_name_);
	stt_node_destructor(node_);
}

void
node_name_from_type_test_4()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_test_4()\n", __FILE__, __LINE__);
#endif
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	const amara_string * raw_rational_;
	amara_boolean equality_;
	raw_rational_ = amara_string_exhaustive_constructor(".6");
	stt_node_set_rational(node_, raw_rational_);
	type_name_ = stt_node_type_name(node_);
	expectation_ = amara_string_exhaustive_constructor("rational");
	equality_ = amara_string_equality(type_name_, expectation_);
	assertion(equality_);
	amara_string_destructor((amara_string *) expectation_);
	amara_string_destructor((amara_string *) type_name_);
	stt_node_destructor(node_);
}

/*
void
node_name_from_type_test_5()
{
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	amara_boolean equality_;
	node_->type_ = SYNTAX_TREE_NODE_TYPE_OPERATION;
	type_name_ = stt_node_type_name(node_);
	expectation_ = amara_string_exhaustive_constructor("operation");
	equality_ = amara_string_equality(type_name_, expectation_);
	assertion(equality_);
	amara_string_destructor((amara_string *) expectation_);
	amara_string_destructor((amara_string *) type_name_);
	stt_node_destructor(node_);
}

void
node_name_from_type_test_6()
{
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	amara_boolean equality_;
	node_->type_ = SYNTAX_TREE_NODE_TYPE_FUNCTION;
	type_name_ = stt_node_type_name(node_);
	expectation_ = amara_string_exhaustive_constructor("function");
	equality_ = amara_string_equality(type_name_, expectation_);
	assertion(equality_);
	amara_string_destructor((amara_string *) expectation_);
	amara_string_destructor((amara_string *) type_name_);
	stt_node_destructor(node_);
}

void
node_name_from_type_test_7()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_test_7()\n", __FILE__, __LINE__);
#endif
	stt_node * node_ = stt_node_default_constructor();
	const amara_string * type_name_;
	const amara_string * expectation_;
	amara_boolean equality_;
	node_->type_ = SYNTAX_TREE_NODE_TYPE_APPLICATION;
	type_name_ = stt_node_type_name(node_);
	expectation_ = amara_string_exhaustive_constructor("application");
	equality_ = amara_string_equality(type_name_, expectation_);
	assertion(equality_);
	amara_string_destructor((amara_string *) expectation_);
	amara_string_destructor((amara_string *) type_name_);
	stt_node_destructor(node_);
}
*/

void
node_name_from_type_tests()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void node_name_from_type_tests()\n", __FILE__, __LINE__);
#endif
	node_name_from_type_test_0();
	node_name_from_type_test_1();
	node_name_from_type_test_2();
	node_name_from_type_test_3();
	node_name_from_type_test_4();
	/*
	node_name_from_type_test_5();
	node_name_from_type_test_6();
	node_name_from_type_test_7();
	*/
}

void
stt_node_tests()
{
	node_name_from_type_tests();
}

void
syntax_tree_tests()
{
#ifdef TRACE_STEPS_IN
	fprintf(stderr, "----> %s:%u: void syntax_tree_tests()\n", __FILE__, __LINE__);
#endif
	stt_node_tests();
}
