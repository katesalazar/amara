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
 * src/arn/arn_value.h: Amara application run time value. A value is
 * basically a constant.
 */

#ifndef __AMARA__APPLICATIONS_RUNNER__VALUE__H__
#define __AMARA__APPLICATIONS_RUNNER__VALUE__H__

#include "../asr/assertion.h"
#include "../brt/natural.h"
#include "../cmn/amara_string.h"

/**  Likely just created. */
#define ARN_VALUE_TYPE_INVALID            0x00
/**  Likely just created and then just named but not typed as of any
 * particular type (!). */
#define ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE 0x01
/**  Likely named unassigned string value. */
#define ARN_VALUE_TYPE_NAMED_UNASSIGNED_STRING       0x0F
/**  Likely named unassigned natural value. */
#define ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL      0x10
/**  Named assigned string value. */
#define ARN_VALUE_TYPE_NAMED_ASSIGNED_STRING         0x11
/**  Named assigned natural value. */
#define ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL        0x12
/**  Likely the result of running some [intermediate] operation, or some
 * named function, or... */
#define ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING     0x13 /* XXX remove the _assigned_ part? */
#define ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL    0x14 /* XXX remove the _assigned_ part? */
#define ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_STRING   0x15 /* XXX */
#define ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_NATURAL  0x16 /* XXX */

typedef struct arn_value {
	unsigned char type_;
	amara_string * name_;
	amara_string * string_;
	amara_boolean string_was_moved_;
	natural * natural_;
	amara_boolean natural_was_moved_;
} arn_value
;

arn_value *
arn_value_default_constructor(void)
__attribute__((warn_unused_result))
;

arn_value *
arn_value_copy_constructor(const arn_value * value)
__attribute__((warn_unused_result))
;

void
arn_value_destructor(arn_value * value)
;

/**  XXX Must change into a returned struct, able to mark an error in the operation. */
void
arn_value_characterize_as_string(arn_value * value)
;

/**  XXX Must change into a returned struct, able to mark an error in the operation. */
void
arn_value_characterize_as_natural(arn_value * value)
;

void
arn_value_set_name(arn_value * value, const amara_string * name)
;

void
arn_value_set_string(arn_value * value, const amara_string * string)
;

void
arn_value_set_natural(arn_value * value, const natural * natural)
;

/* This is an enumeration. */
#define ARN_VALUE_ASSIGN_NATURAL_OUT_OF_UNSIGNED_INT_RET_STATUS_INVALID                 0x00
#define ARN_VALUE_ASSIGN_NATURAL_OUT_OF_UNSIGNED_INT_RET_STATUS_ERROR_NO_TYPE           0x01
#define ARN_VALUE_ASSIGN_NATURAL_OUT_OF_UNSIGNED_INT_RET_STATUS_ERROR_INVALID_TYPE      0x02
#define ARN_VALUE_ASSIGN_NATURAL_OUT_OF_UNSIGNED_INT_RET_STATUS_ERROR_INCOMPATIBLE_TYPE 0x03
#define ARN_VALUE_ASSIGN_NATURAL_OUT_OF_UNSIGNED_INT_RET_STATUS_ERROR_ALREADY_ASSIGNED  0x04
#define ARN_VALUE_ASSIGN_NATURAL_OUT_OF_UNSIGNED_INT_RET_STATUS_SUCCESS                 0xFF

typedef struct arn_value_assign_natural_out_of_unsigned_int_ret {
	unsigned char status;
} arn_value_assign_natural_out_of_unsigned_int_ret
;

/**  Pre: the value is not assigned (type not
 * `ARN_VALUE_TYPE_ASSIGNED_NATURAL`). */
arn_value_assign_natural_out_of_unsigned_int_ret *
arn_value_assign_natural_out_of_unsigned_int(
		arn_value * value,
		const unsigned int unsigned_int)
;

#endif
