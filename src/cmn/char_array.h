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
 * src/cmn/char_array.h: Utilities for character arrays.
 */

#ifndef __AMARA__COMMON__CHAR_ARRAY__H__
#define __AMARA__COMMON__CHAR_ARRAY__H__

/*   This is non destructive on the input arguments.
 *   Never returns a char array larger than 255 bytes long. */
char *
concatenate_two_char_arrays(const char * zero, const char * one)
__attribute__((warn_unused_result))
;

/*   This is non destructive on the input arguments.
 *   Never returns a char array larger than 255 bytes long. */
char *
concatenate_three_char_arrays(
		const char * zero, const char * one, const char * two)
__attribute__((warn_unused_result))
;

/*   This is non destructive on the input arguments.
 *   Never returns a char array larger than 255 bytes long. */
char *
concatenate_four_char_arrays(
		const char * zero, const char * one, const char * two,
		const char * three)
__attribute__((warn_unused_result))
;

#endif
