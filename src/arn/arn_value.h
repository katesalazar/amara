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
 * src/arn/arn_value.h: Amara application run time value. A value is
 * basically a constant.
 */

#ifndef __AMARA__APPLICATIONS_RUNNER__VALUE__H__
#define __AMARA__APPLICATIONS_RUNNER__VALUE__H__

#include "../brt/natural.h"

#include "../cmn/amara_string.h"

#include "../rtg/rtg_where_value_binding.h"

/**  Likely just created. */
#define ARN_VALUE_TYPE_INVALID                       0x20  /* 32: ' '. */
/**  Likely just created and then just named but not typed as of any
 * particular type (!). */
#define ARN_VALUE_TYPE_NAMED_VALUE_OF_UNDEFINED_TYPE 0x21
/**  Likely named unassigned string value. */
#define ARN_VALUE_TYPE_NAMED_UNASSIGNED_STRING       0x22
#define ARN_VALUE_TYPE_NAMED_UNASSIGNED_BOOLEAN      0x71
/**  Likely named unassigned natural value. */
#define ARN_VALUE_TYPE_NAMED_UNASSIGNED_NATURAL      0x23
/**  Named assigned string value. */
#define ARN_VALUE_TYPE_NAMED_ASSIGNED_STRING         0x24
/**  Named assigned natural value. */
#define ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL        0x25  /* 37: ..... */
/**  Likely the result of running some [intermediate] operation, or some
 * named function, or... */
#define ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING     0x26  /* XXX remove the _assigned_ part? */
#define ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_BOOLEAN    0x27  /* 39: ..... */
#define ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL    0x28  /* 40: '('. */  /* XXX remove the _assigned_ part? */
#define ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_STRING   0x29  /* XXX ??? */
#define ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_BOOLEAN  0x72
#define ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_NATURAL  0x2A  /* XXX ??? */

/**  Application run time value. */
typedef struct arn_value {

	/**  `Application run time value` type. Enumeration. */
	unsigned char type_;

    /**  `Application run time value` name, if any. */
	amara_string * name_;

    /**  `Application run time value` value, if `string` type. */
	amara_string * string_;
	amara_boolean string_was_moved;

    /**  `Application run time value` value, if `boolean` type. */
	amara_boolean * boolean_;
	amara_boolean boolean_was_moved;

    /**  `Application run time value` value, if `natural` type. */
	natural * natural_;
	amara_boolean natural_was_moved;
} arn_value
;

/**  Default constructor. */
arn_value *
arn_value_default_constructor(void)
__attribute__((warn_unused_result))
;

/**  Copy constructor. */
arn_value *
arn_value_copy_constructor(const arn_value * value)
__attribute__((warn_unused_result))
;

/**  Transformation constructor. */
arn_value *
arn_value_out_of_amara_boolean(const amara_boolean boolean)
__attribute__((warn_unused_result))
;

void
arn_value_destructor(arn_value * value)
;

/**  Transformation constructor. */
arn_value *
arn_value_bind_where_value(const rtg_where_value_binding * where_value_binding)
__attribute__((warn_unused_result))
;

/**  XXX Must change into a returned struct, able to mark an error in the operation. */
void
arn_value_characterize_as_string(arn_value * value)
;

/**  XXX Must change into a returned struct, able to mark an error in the operation. */
void
arn_value_characterize_as_boolean(arn_value * value)
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
arn_value_set_boolean(arn_value * value, const amara_boolean boolean)
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

typedef struct arn_value_assign_natural_out_of_unsigned_short_ret {

	unsigned char status;
} arn_value_assign_natural_out_of_unsigned_short_ret
;

/**  Pre: the value is not assigned (type not
 * `ARN_VALUE_TYPE_ASSIGNED_NATURAL`). */
arn_value_assign_natural_out_of_unsigned_short_ret *
arn_value_assign_natural_out_of_unsigned_short(
		arn_value * value,
		const unsigned short unsigned_short)
;

#endif
