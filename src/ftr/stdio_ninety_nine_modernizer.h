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
 * src/ftr/stdio_ninety_nine_modernizer.h: An attempt at being C99
 * compatible without being C99 compatible.
 */

#ifndef __AMARA__FUTURE__STDIO_NINETY_NINE_MODERNIZER__H__
#define __AMARA__FUTURE__STDIO_NINETY_NINE_MODERNIZER__H__

#ifndef CLANG

/*   For `size_t`. */
#include <stdio.h>

int
snprintf(char * str, size_t size, const char * format, ...)
__attribute__((warn_unused_result))
;

#endif

#endif
