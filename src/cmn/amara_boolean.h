/*
 * Copyright 2018, 2020 Mercedes Catherine Salazar
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

typedef unsigned char amara_boolean;

/*   Hexadecimal:  0x ...0...0
 *   Binary:          00000000
 *   Decimal:                0 */
#define AMARA_BOOLEAN_INVALID ((unsigned char) 0x00)
/*   Hexadecimal:  0x ...5...5
 *   Binary:          01010101
 *   Decimal:         ???????? */
#define AMARA_BOOLEAN_FALSE ((unsigned char) 0x55)
/*   Hexadecimal:  0x ...a...a
 *   Binary:          10101010
 *   Decimal:         ???????? */
#define AMARA_BOOLEAN_TRUE ((unsigned char) (~ ((unsigned char) AMARA_BOOLEAN_FALSE)))

#endif
