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
 * src/asr/assertion.h: Assertions utility.
 */

#ifndef __AMARA__ASSERTIONS__ASSERTION__H__
#define __AMARA__ASSERTIONS__ASSERTION__H__

void
assertion(int expression);

void
assertion_two(int expression, const char * message);

void disarm_interim(char * message)
;

void
assertion_two_located_interim(
		int expression, const char * message, const char * source_doc,
		unsigned int source_line);

void
interpret_and_assert(const char * expression);

void
interpret_and_assert_two(const char * expression, const char * message);

#endif
