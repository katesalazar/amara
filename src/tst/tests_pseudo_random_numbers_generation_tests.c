/*
 * Copyright 2020 Mercedes Catherine Salazar
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
 * src/tst/tests_pseudo_random_numbers_generation_tests.c: Tests that
 * test the Amara tests pseudo random number generation helper
 * functions. These tests are executed always in a unique order, without
 * being scrambled, in order to avoid chicken-and-egg problems.
 */

#include <stdio.h>  /* XXX INTERIM */

#include "../asr/assertion.h"

#include "tests_pseudo_random_numbers_generation.h"

void
tests_prng_next_integer_between_three_test_0()
{
	short int seed_;
	short int min_;
	short int max_;
	short int random_;
	short int iteration_;

	seed_ = 0;
	min_ = 1;
	max_ = 1024;
	iteration_ = 0;

	do {
		random_ = tests_prng_next_integer_between_three(
				seed_, min_, max_);

		if (iteration_ == 0) {
			forced_assertion(random_ == 1);
		} else if (iteration_ == 1) {
			forced_assertion(random_ == 438);
		} else if (iteration_ == 2) {
			forced_assertion(random_ == 357);
		} else if (iteration_ == 3) {
			forced_assertion(random_ == 410);
		} else if (iteration_ == 4) {
			forced_assertion(random_ == 900);
		} else if (iteration_ == 5) {
			forced_assertion(random_ == 284);
		} else if (iteration_ == 6) {
			forced_assertion(random_ == 1023);
		} else if (iteration_ == 7) {
			forced_assertion(random_ == 891);
		} else {
			forced_assertion(iteration_ == 8);
			forced_assertion(random_ == 309);
		/*
		} else {
			printf("%d\n", random_);
			forced_assertion(random_ == 12);
		*/
		}

		iteration_++;
	} while (iteration_ < 9);
}

void
tests_prng_next_integer_between_three_test_1()
{
	short int seed_;
	short int min_;
	short int max_;
	short int random_;
	short int iteration_;

	seed_ = 0;
	min_ = 1;
	max_ = 32;
	iteration_ = 0;

	do {
		random_ = tests_prng_next_integer_between_three(
				seed_, min_, max_);

		if (iteration_ == 0) {
			forced_assertion(random_ == 18);
		} else if (iteration_ == 1) {
			forced_assertion(random_ == 32);
		} else if (iteration_ == 2) {
			forced_assertion(random_ == 17);
		} else if (iteration_ == 3) {
			forced_assertion(random_ == 17);
		} else if (iteration_ == 4) {
			forced_assertion(random_ == 17);
		} else if (iteration_ == 5) {
			forced_assertion(random_ == 17);
		} else if (iteration_ == 6) {
			forced_assertion(random_ == 17);
		} else if (iteration_ == 7) {
			forced_assertion(random_ == 17);
		} else {
			forced_assertion(iteration_ == 8);
			forced_assertion(random_ == 17);
		/*
		} else {
			printf("%d\n", random_);
			forced_assertion(random_ == 12);
		*/
		}

		iteration_++;
	} while (iteration_ < 9);
}

void
tests_prng_next_integer_between_three_test_2()
{
	short int seed_;
	short int min_;
	short int max_;
	short int random_;
	short int iteration_;

	seed_ = 0;
	min_ = 1;
	max_ = 1024;
	iteration_ = 0;

	do {
		random_ = tests_prng_next_integer_between_three(
				seed_, min_, max_);

		if (iteration_ == 0) {
			forced_assertion(random_ == 532);
		} else if (iteration_ == 1) {
			forced_assertion(random_ == 44);
		} else if (iteration_ == 2) {
			forced_assertion(random_ == 514);
		} else if (iteration_ == 3) {
			forced_assertion(random_ == 37);
		} else if (iteration_ == 4) {
			forced_assertion(random_ == 454);
		} else if (iteration_ == 5) {
			forced_assertion(random_ == 451);
		} else if (iteration_ == 6) {
			forced_assertion(random_ == 97);
		} else if (iteration_ == 7) {
			forced_assertion(random_ == 37);
		} else {
			forced_assertion(iteration_ == 8);
			forced_assertion(random_ == 454);
		/*
		} else {
			printf("%d\n", random_);
			forced_assertion(random_ == 12);
		*/
		}

		iteration_++;
	} while (iteration_ < 9);
}

void
tests_prng_next_integer_between_three_test_3()
{
	short int seed_;
	short int min_;
	short int max_;
	short int random_;
	short int iteration_;

	seed_ = 0;
	min_ = 1;
	max_ = 1024;
	iteration_ = 0;

	do {
		random_ = tests_prng_next_integer_between_three(
				seed_, min_, max_);

		if (iteration_ == 0) {
			forced_assertion(random_ == 451);
		} else if (iteration_ == 1) {
			forced_assertion(random_ == 97);
		} else if (iteration_ == 2) {
			forced_assertion(random_ == 37);
		} else if (iteration_ == 3) {
			forced_assertion(random_ == 454);
		} else if (iteration_ == 4) {
			forced_assertion(random_ == 451);
		} else if (iteration_ == 5) {
			forced_assertion(random_ == 97);
		} else if (iteration_ == 6) {
			forced_assertion(random_ == 37);
		} else if (iteration_ == 7) {
			forced_assertion(random_ == 454);
		} else {
			forced_assertion(iteration_ == 8);
			forced_assertion(random_ == 451);
		/*
		} else {
			printf("%d\n", random_);
			forced_assertion(random_ == 12);
		*/
		}

		iteration_++;
	} while (iteration_ < 9);
}

void
tests_prng_next_integer_between_three_test_4()
{/*
	short int seed_zero_;
	short int seed_one_;
	short int random_;

	seed_zero_ = 0;
	seed_one_ = 1;

	*/
}

void
tests_prng_next_integer_between_three_tests()
{
	tests_prng_next_integer_between_three_test_0();
	tests_prng_next_integer_between_three_test_1();
	tests_prng_next_integer_between_three_test_2();
	tests_prng_next_integer_between_three_test_3();
	tests_prng_next_integer_between_three_test_4();
}

void
tests_pseudo_random_numbers_generation_tests()
{
	tests_prng_next_integer_between_three_tests();
}
