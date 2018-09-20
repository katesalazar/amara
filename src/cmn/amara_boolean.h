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
 * src/cmn/amara_boolean.h: Self explanatory...
 */

#ifndef __AMARA__COMMON__AMARA_BOOLEAN__H__
#define __AMARA__COMMON__AMARA_BOOLEAN__H__

/*   For `uint_fast8_t`. */
#include <stdint.h>

typedef uint_fast8_t amara_boolean;

#define AMARA_BOOLEAN_FALSE 0x00
#define AMARA_BOOLEAN_TRUE (uint_fast8_t) ~AMARA_BOOLEAN_FALSE

#endif
