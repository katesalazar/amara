/*
 * Copyright 2018, 2020 Mercedes Catherine Salazar
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
 * src/stt/stt_where_value_bindings_subnode_tests.c: Test the Amara
 * syntax tree _where_ value bindings subnode.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_where_value_bindings_subnode`. */
#include "stt_where_value_bindings_subnode.h"

#include "stt_where_value_bindings_subnode_tests.h"

void
stt_where_value_bindings_subnode_default_constructor_test()
{
	stt_where_value_bindings_subnode * subnode_;

	subnode_ = stt_where_value_bindings_subnode_default_constructor();
#ifndef NDEBUG
	assertion(subnode_ != NULL);
	assertion(subnode_->where_value_bindings_ == NULL);
#endif

	stt_where_value_bindings_subnode_destructor(subnode_);
}

void
stt_where_value_bindings_subnode_exhaustive_constructor_test_0()
{
	stt_where_value_bindings_simple_list * list_;
	stt_where_value_bindings_subnode * subnode_;

	list_ = stt_where_value_bindings_simple_list_default_constructor();
#ifndef NDEBUG
	assertion(list_ != NULL);
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
#endif

	subnode_ = stt_where_value_bindings_subnode_exhaustive_constructor(
			list_);
#ifndef NDEBUG
	assertion(list_->first == NULL);
	assertion(list_->next == NULL);
	assertion(subnode_ != NULL);
	assertion(subnode_->where_value_bindings_ != NULL);
	assertion(subnode_->where_value_bindings_->first == NULL);
	assertion(subnode_->where_value_bindings_->next == NULL);
#endif

	stt_where_value_bindings_subnode_destructor(subnode_);

	stt_where_value_bindings_simple_list_destructor(list_);
}

void
stt_where_value_bindings_subnode_constructors_tests()
{
	stt_where_value_bindings_subnode_default_constructor_test();
	stt_where_value_bindings_subnode_exhaustive_constructor_test_0();
}

tests_simple_list *
register_stt_where_value_bindings_subnode_constructors_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_where_value_bindings_subnode_constructors_tests(
		tests_simple_list * tests)
{
	tests_simple_list_push_back(
			tests,
			& stt_where_value_bindings_subnode_default_constructor_test);
	tests_simple_list_push_back(
			tests,
			& stt_where_value_bindings_subnode_exhaustive_constructor_test_0);
	return tests;
}

void
stt_where_value_bindings_subnode_tests()
{
	stt_where_value_bindings_subnode_constructors_tests();
}

tests_simple_list *
register_stt_where_value_bindings_subnode_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_where_value_bindings_subnode_constructors_tests(
			tests);
	return returning_;
}
