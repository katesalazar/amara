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
 * src/arn/arn_variable.h: Amara application run time variable.
 */

#ifndef __AMARA__APPLICATIONS_RUNNER__VARIABLE__H__
#define __AMARA__APPLICATIONS_RUNNER__VARIABLE__H__

#include "../asr/assertion.h"
#include "../brt/natural.h"
#include "../cmn/amara_string.h"

#define ARN_VARIABLE_TYPE_INVALID            0x00
#define ARN_VARIABLE_TYPE_UNDEFINED          0x01
#define ARN_VARIABLE_TYPE_UNASSIGNED_NATURAL 0x10
#define ARN_VARIABLE_TYPE_ASSIGNED_NATURAL   0x11

typedef struct arn_variable {
	unsigned char type_;
	amara_string * name_;
	/*
	amara_string * raw_natural_;
	amara_boolean raw_natural_was_moved_;
	*/
	natural * natural_;
	amara_boolean natural_was_moved_;
} arn_variable
;

arn_variable *
arn_variable_default_constructor(void)
__attribute__((warn_unused_result))
;

void
arn_variable_destructor(arn_variable * variable)
;

/*

void
arn_variable_set_name(arn_variable * variable, const amara_string * name)
;

void
arn_variable_set_natural(arn_variable * variable, const natural * natural)
;

*/

/**  Pre: the variable is not assigned (type not
 * `ARN_VARIABLE_TYPE_ASSIGNED_NATURAL`). */
/*
void
arn_variable_assign_natural_out_of_unsigned_int(
		arn_variable * variable,
		const unsigned int unsigned_int)
;
*/

#endif
