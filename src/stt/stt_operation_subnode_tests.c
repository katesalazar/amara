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
 * src/stt/stt_operation_subnode_tests.c: Test the Amara syntax tree
 * application function operation subnode.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_operation_subnode`. */
#include "stt_operation_subnode.h"

#include "stt_operation_subnode_tests.h"

void
stt_operation_subnode_default_constructor_test_0()
{
	stt_operation_subnode * stt_operation_subnode_;

	stt_operation_subnode_ = stt_operation_subnode_default_constructor();
	forced_assertion(stt_operation_subnode_ != NULL);
	forced_assertion(stt_operation_subnode_->operation_ == NULL);

	stt_operation_subnode_destructor(stt_operation_subnode_);
}

void
stt_operation_subnode_default_constructor_tests()
{
	stt_operation_subnode_default_constructor_test_0();
}

tests_simple_list *
register_stt_operation_subnode_default_constructor_tests(
		tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_operation_subnode_default_constructor_tests(
		tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = tests;
	tests_simple_list_push_back(
			returning_,
			& stt_operation_subnode_default_constructor_test_0);
	return returning_;
}

void
stt_operation_subnode_constructors_tests()
{
	stt_operation_subnode_default_constructor_tests();
}

tests_simple_list *
register_stt_operation_subnode_constructors_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_operation_subnode_constructors_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_operation_subnode_default_constructor_tests(
			tests);
	return returning_;
}

void
stt_operation_subnode_tests()
{
	stt_operation_subnode_constructors_tests();
}

tests_simple_list *
register_stt_operation_subnode_tests(tests_simple_list * tests)
__amara__warn_unused_result__
;

tests_simple_list *
register_stt_operation_subnode_tests(tests_simple_list * tests)
{
	tests_simple_list * returning_;

	returning_ = register_stt_operation_subnode_constructors_tests(tests);
	return returning_;
}
