/*
 * Copyright 2019-2020 Mercedes Catherine Salazar
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
 * src/tst/tests_pseudo_random_numbers_generation.c: Amara tests pseudo
 * random number generation helper functions.
 */

/*   For `INT_MAX`. */
#include <limits.h>

/*   For `time_t time(time_t * tloc)`. */
#include <time.h>

/*   For `void forced_assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "tests_pseudo_random_numbers_generation.h"

int
tests_prng_next_integer_between_two(const int smallest, const int largest)
{
	static int seed_is_initialized_ = 0;
	static int seed_;

	if (!seed_is_initialized_) {
		seed_ = time(NULL);
		seed_is_initialized_ = 1;
	}

	/*   Use a random seed. */
	return tests_prng_next_integer_between_three(seed_, smallest, largest);
}

int
tests_prng_next_integer_between_three(
		const int seed, const int smallest, const int largest)
{
	static int seed_is_initialized_ = 0;
	static int seed_;
	static int next_has_been_defined_ = 0;
	static int next_;
	int must_reset_sequence_ = 0;

	if (!seed_is_initialized_) {
		seed_ = seed;
		seed_is_initialized_ = 1;
	} else if (seed != seed_) {
		seed_ = seed;
		must_reset_sequence_ = 1;
	}

	if (!next_has_been_defined_) {
		next_ = seed_;
		next_has_been_defined_ = 1;
	}

	if (must_reset_sequence_) {
#ifndef NDEBUG
		assertion(seed_is_initialized_ == 1);
		assertion(next_has_been_defined_ == 1);
#endif
		next_ = seed_;
	}

	forced_assertion(smallest > -1);
	/* potentially too strong assumption. also unnecessary from the point of view that this is going to be used just only for scrambling the unit tests.
	forced_assertion(largest <= INT_MAX - 1);
	*/
	/* explicit paper assumption. */
	forced_assertion(largest <= 32768 - 1);

	/*   Will generate the next pseudo random number using an
	 * algorithm seen in
	 * `https://pubs.opengroup.org/onlinepubs/009695399/functions/rand.html`.
	 *   See also: `https://stackoverflow.com/q/8569113`.
	 *   See also: `http://citeseer.ist.psu.edu/viewdoc/download;jsessionid=4F8F207F726CB56B4630F8155F748256?doi=10.1.1.53.3686&rep=rep1&type=pdf`
	 * linked from 8569113 at `stackoverflow.com`.
	 */

	next_ = next_ * 1103515245 + 12345;
	do {
		next_ = ((unsigned) (next_ / 65536)) % (largest + 1);

		if (next_ == 0) {  /* XXX ??? */
			next_++;  /* XXX ??? */
		}  /* XXX ??? */

	} while (next_ < smallest || next_ > largest);

	forced_assertion(next_ >= smallest);
	forced_assertion(next_ <= largest);

	return next_;
}

