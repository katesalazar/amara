/*
 * Copyright 2019 Mercedes Catherine Salazar
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
 * src/tst/tests_pseudo_random_numbers_generation.h: Amara tests pseudo
 * random number generation helper functions.
 */

#ifndef __AMARA__TESTS__TESTS_PSEUDO_RANDOM_NUMBERS_GENERATION__H__
#define __AMARA__TESTS__TESTS_PSEUDO_RANDOM_NUMBERS_GENERATION__H__

/*   For `__amara__warn_unused_result__`. */
#include "../definitions.h"

/**  In order to avoid chicken and egg problems, the tests package
 * defines, tests and uses (in that particular order) its own pseudo
 * random number generation helper functions before running any of the
 * other tests. Such random numbers generation is a necessary
 * dependency, because the tests runner has to scramble tests randomly.
 *   It will use a random seed. */
int
tests_prng_next_integer_between_two(const int smallest, const int largest)
__amara__warn_unused_result__
;

/**  In order to avoid chicken and egg problems, the tests package
 * defines, tests and uses (in that particular order) its own pseudo
 * random number generation helper functions before running any of the
 * other tests. Such random numbers generation is a necessary
 * dependency, because the tests runner has to scramble tests randomly.
 *   It will use the seed passed as argument, but if the seed isn't the
 * same as the seed already configured, it will reset the seed, and
 * therefore pseudo random number generation will from then on be reset
 * to that seed. */
int
tests_prng_next_integer_between_three(
		const int seed, const int smallest, const int largest)
__amara__warn_unused_result__
;

#endif
