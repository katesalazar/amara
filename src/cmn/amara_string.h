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
 * src/cmn/amara_string.h: Self explanatory...
 */

#ifndef __AMARA__COMMON__AMARA_STRING__H__
#define __AMARA__COMMON__AMARA_STRING__H__

/*   For `size_t`. */
#include "stdlib.h"

/*   For `amara_boolean`. */
#include "amara_boolean.h"

typedef struct amara_string {

	char * value_;
} amara_string;

amara_string *
amara_string_default_constructor(void)
__attribute__((warn_unused_result))
;

/*   This is not destructive on the argument. Also it doesn't receive
 * ownership of the argument. */
amara_string *
amara_string_exhaustive_constructor(const char * value)
__attribute__((warn_unused_result))
;

amara_string *
amara_string_exhaustive_constructor_three(
		const char * ca0, const char * ca1, const char * ca2)
__attribute__((warn_unused_result))
;

/*   This is not destructive on the argument. Also it doesn't receive
 * ownership of the argument. */
amara_string *
amara_string_copy_constructor(const amara_string * as)
__attribute__((warn_unused_result))
;

/**  Destructor. */
void
amara_string_destructor(amara_string * string)
;

#ifndef NDEBUG

/**  Health check. */
void
amara_string_assert_healthy(const amara_string * string)
;

#endif

char *
amara_string_get_value(const amara_string * string)
__attribute__((warn_unused_result))
;

void
amara_string_set_value(amara_string * string, const char * value)
;

size_t
amara_string_length(const amara_string * s)
__attribute__((warn_unused_result))
;

/*   Given that the implementation is with `char *`, then this basically
 * is a wrapper on `int strcmp(const char * s1, const char * s2)`.
 *   Once the implementation is no longer based on `char *`, this shall
 * become deprecated. */
int
amara_string_strcmp(const amara_string * s1, const amara_string * s2)
__attribute__((warn_unused_result))
;

amara_boolean
amara_string_equality(const amara_string * a1, const amara_string * a2)
__attribute__((warn_unused_result))
;

amara_boolean
amara_strings_equality(const amara_string * a1, const amara_string * a2)
__attribute__((warn_unused_result))
;

amara_boolean
amara_identifiers_equality(
		const amara_string * i0, const amara_string * i1)
__attribute__((warn_unused_result))
;

#endif
