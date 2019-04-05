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
 * src/arn/arn_type.h: Amara application run time value type. A value is
 * basically a constant.
 */

#ifndef __AMARA__APPLICATIONS_RUNNER__TYPE__H__
#define __AMARA__APPLICATIONS_RUNNER__TYPE__H__

/*   For `amara_string`. */
#include "../cmn/amara_string.h"

/*   For `rtg_expression`. */
#include "../rtg/rtg_expression.h"

typedef unsigned char arn_type_type;

/**  Likely just created. */
#define ARN_TYPE_TYPE_INVALID             0x20
/**  String type. This is read as "the _type_ of this `arn_type` object
 * is the _type_ `string`. */
#define ARN_TYPE_TYPE_STRING              0x21
/**  Boolean type. This is read as "the _type_ of this `arn_type` object
 * is the _type_ `boolean`. */
#define ARN_TYPE_TYPE_BOOLEAN             0x22
/**  Algebraic natural number type. */
#define ARN_TYPE_TYPE_NATURAL             0x23
/**  An error type happened evaluation. This is read as "the _type_ of
 * this `arn_type` object is 'a type error happened'". */
#define ARN_TYPE_TYPE_TYPE_ERROR_HAPPENED 0x7E

/*
arn_type_type
arn_type_type_ill(void)
__attribute__((warn_unused_result))
;
*/

/**  Valid means that is not _invalid_. */
amara_boolean
arn_type_type_is_valid(arn_type_type type_type)
__attribute__((warn_unused_result))
;

/*
amara_boolean
arn_type_type_is_known(arn_type_type type_type)
__attribute__((warn_unused_result))
;
*/

/**  Healthy means that no error has happened. */
/*
amara_boolean
arn_type_type_is_healthy(arn_type_type type_type)
__attribute__((warn_unused_result))
;
*/

/**  Ill means that an error has happened. */
/*
amara_boolean
arn_type_type_is_ill(arn_type_type type_type)
__attribute__((warn_unused_result))
;
*/

typedef struct arn_type {
	arn_type_type type_;
	amara_string * name_;
} arn_type
;

arn_type *
arn_type_default_constructor(void)
__attribute__((warn_unused_result))
;

void
arn_type_destructor(arn_type * type)
;

arn_type *
arn_type_out_of_rtg_expression(const rtg_expression * expression)
__attribute__((warn_unused_result))
;

/**  This is read as `amara_string` which is the 'name' of the 'type'
 * extracted from the `type` of the 'type'. */
amara_string *
arn_type_type_name_out_of_type_type(arn_type_type type_type)
__attribute__((warn_unused_result))
;

#endif
