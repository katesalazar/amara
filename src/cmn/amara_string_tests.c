/*
 * Copyright 2018-2019 Mercedes Catherine Salazar
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
 * src/cmn/amara_string_tests.c: Test the Amara string class.
 */

/*   For `int strcmp(const char * s1, const char * s2)`. */
#include <string.h>

#include "../asr/assertion.h"

#include "amara_string_tests.h"

amara_string *
amara_string_example_foo()
{
	amara_string * ret_;

	ret_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->value_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_foo(ret_);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_amara_string_example_foo(const amara_string * string)
{
	assertion(string != NULL);
	assertion(string->value_ != NULL);
	assertion(string->value_[0] == 'f');
	assertion(string->value_[1] == 'o');
	assertion(string->value_[2] == 'o');
	assertion(string->value_[3] == '\0');
}

#endif

amara_string *
amara_string_example_bar()
{
	amara_string * ret_;

	ret_ = amara_string_exhaustive_constructor("bar");
	forced_assertion(ret_ != NULL);
	forced_assertion(ret_->value_ != NULL);
#ifndef NDEBUG
	assert_expectations_on_amara_string_example_bar(ret_);
#endif

	return ret_;
}

#ifndef NDEBUG

void
assert_expectations_on_amara_string_example_bar(const amara_string * string)
{
	assertion(string != NULL);
	assertion(string->value_ != NULL);
	assertion(string->value_[0] == 'b');
	assertion(string->value_[1] == 'a');
	assertion(string->value_[2] == 'r');
	assertion(string->value_[3] == '\0');
}

#endif

void
amara_string_construct_and_destruct_test_0()
{
	amara_string * amara_string_;
	amara_string_ = amara_string_default_constructor();
	assertion(amara_string_ != NULL);
	assertion(amara_string_->value_ == NULL);
	amara_string_destructor(amara_string_);
}

void
amara_string_construct_and_destruct_test_1()
{
	amara_string * amara_string_;
	amara_string_ = amara_string_exhaustive_constructor("foo");
	assertion(amara_string_ != NULL);
	assertion(amara_string_->value_ != NULL);
	assertion(!strcmp(amara_string_->value_, "foo"));
	amara_string_destructor(amara_string_);
}

void
amara_string_construct_and_destruct_tests()
{
	amara_string_construct_and_destruct_test_0();
	amara_string_construct_and_destruct_test_1();
}

void
amara_string_equality_test_0()
{
	amara_string * a1;
	amara_string * a2;
	amara_boolean equality_;

	a1 = NULL;
	a2 = amara_string_exhaustive_constructor("");
	assertion(a2 != NULL);
	assertion(a2->value_ != NULL);

	equality_ = amara_string_equality(a1, a2);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);  /* XXX */

	amara_string_destructor(a2);
}

#ifndef NDEBUG
#endif

void
amara_string_equality_test_1()
{
	amara_string * a1_;
	amara_string * a2_;
	amara_boolean equality_;

	a1_ = amara_string_exhaustive_constructor("foo");
	assertion(a1_ != NULL);
	assertion(a1_->value_ != NULL);

	a2_ = NULL;

	equality_ = amara_string_equality(a1_, a2_);
	assertion(equality_ == AMARA_BOOLEAN_FALSE);

	amara_string_destructor(a1_);
}

#ifndef NDEBUG
#endif

void
amara_string_equality_test_2()
{
	amara_string * a1_;
	amara_string * a2_;
	amara_boolean equality_;

	a1_ = amara_string_exhaustive_constructor("");
	assertion(a1_ != NULL);
	assertion(a1_->value_ != NULL);

	a2_ = NULL;

	equality_ = amara_string_equality(a1_, a2_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(a1_);
}

void
amara_string_equality_test_3()
{
	amara_string * a1_;
	amara_string * a2_;
	amara_boolean equality_;

	a1_ = NULL;

	a2_ = amara_string_exhaustive_constructor("foo");
	assertion(a2_ != NULL);
	assertion(a2_->value_ != NULL);

	equality_ = amara_string_equality(a1_, a2_);
	assertion(equality_ == AMARA_BOOLEAN_FALSE);

	amara_string_destructor(a2_);
}

#ifndef NDEBUG

void
amara_string_assert_healthy_test_0()
{
	amara_string * as_;

	as_ = amara_string_exhaustive_constructor("foo");
	forced_assertion(as_ != NULL);
#ifndef NDEBUG
	assertion(as_->value_ != NULL);
	assertion(as_->value_[0] == 'f');
	assertion(as_->value_[1] == 'o');
	assertion(as_->value_[2] == 'o');
	assertion(as_->value_[3] == '\0');
#endif

	amara_string_assert_healthy(as_);
#ifndef NDEBUG
	assertion(as_->value_ != NULL);
	assertion(as_->value_[0] == 'f');
	assertion(as_->value_[1] == 'o');
	assertion(as_->value_[2] == 'o');
	assertion(as_->value_[3] == '\0');
#endif

	amara_string_destructor(as_);
}

void
amara_string_assert_healthy_tests()
{
	amara_string_assert_healthy_test_0();
}

#endif

#ifndef NDEBUG
#endif
void
amara_string_equality_tests()
{
	amara_string_equality_test_0();
#ifndef NDEBUG
#endif
	amara_string_equality_test_1();
#ifndef NDEBUG
#endif
	amara_string_equality_test_2();
	amara_string_equality_test_3();
}

void
amara_string_tests()
{
	amara_string_construct_and_destruct_tests();
#ifndef NDEBUG
	amara_string_assert_healthy_tests();
#endif
	amara_string_equality_tests();
}
