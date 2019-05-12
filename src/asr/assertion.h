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
 * src/asr/assertion.h: Assertions utility.
 */

#ifndef __AMARA__ASSERTIONS__ASSERTION__H__
#define __AMARA__ASSERTIONS__ASSERTION__H__

void
assertion(int expression)
;

void
assertion_two(int expression, const char * message)
;

void
assertion_four(
		int expression, const char * location_message,
		const char * source_doc_name, const short source_doc_line)
;

void
assertion_five(
		int expression, const char * message,
		const char * location_message,
		const char * source_doc_name, const short source_doc_line)
;

#ifndef located_assertion
#define located_assertion(expression)                                         \
	assertion_four(                                                       \
			expression,                                           \
			"%s: %d\n", __FILE__, __LINE__)
#endif

#ifndef located_assertion_one
#define located_assertion_one(expression)                                     \
	located_assertion(expression)
#endif

#ifndef located_assertion_two
#define located_assertion_two(expression, message)                            \
	assertion_five(                                                       \
			expression, "%s (%s:%d)\n", message, __FILE__,        \
			__LINE__)
#endif

void
forced_assertion(int expression)
;

void
forced_assertion_two(int expression, const char * message)
;

void
forced_assertion_five(
		int expression, const char * message,
		const char * location_message,
		const char * source_doc_name, const short source_doc_line)
;

#ifndef located_forced_assertion_one
#define located_forced_assertion_one(expression)                              \
	forced_assertion_five(                                                \
			expression, "WARNING assertion failed",               \
			"%s (%s:%d)\n", __FILE__, __LINE__)
#endif

#ifndef located_forced_assertion
#define located_forced_assertion(expression)                                  \
	located_forced_assertion_one(expression)
#endif

#ifndef forced_located_assertion
#define forced_located_assertion(expression)                                  \
	located_forced_assertion_one(expression)
#endif

#ifndef located_forced_assertion_two
#define located_forced_assertion_two(expression, message)                     \
	forced_assertion_five(                                                \
			expression, message,                                  \
			"%s (%s:%d)\n", __FILE__, __LINE__)
#endif

void
forced_unsigned_char_equality_assertion_three(
		unsigned char actual, unsigned char expected,
		const char * message)
;

void
forced_unsigned_char_equality_assertion_five(
		unsigned char actual, unsigned char expected,
		const char * location_message, const char * source_doc_name,
		const short source_doc_line)
;

#ifndef located_forced_unsigned_char_equality_assertion_two
#define located_forced_unsigned_char_equality_assertion_two(                  \
		actual_, expected_)                                           \
	forced_unsigned_char_equality_assertion_five(                         \
			actual_, expected_, "%s: %d\n", __FILE__, __LINE__)
#endif

/*
void disarm_interim(char * message)
;
*/

/*
void
assertion_two_located_interim(
		int expression, const char * message, const char * source_doc,
		unsigned int source_line);
*/

void
interpret_and_assert(const char * expression)
;

void
interpret_and_assert_two(const char * expression, const char * message)
;

#endif
