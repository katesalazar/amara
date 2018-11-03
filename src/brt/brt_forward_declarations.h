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
 * src/brt/brt_forward_declarations.h: Basic arithmetic forward
 * declarations.
 */

#ifndef __AMARA__BASIC_ARITHMETIC__FORWARD_DECLARATIONS__H__
#define __AMARA__BASIC_ARITHMETIC__FORWARD_DECLARATIONS__H__

/*   For `typedef struct amara_string { ... } amara_string;`. */
#include "../cmn/amara_string.h"

typedef struct natural {
	amara_string * raw_;
} natural
;

#endif
