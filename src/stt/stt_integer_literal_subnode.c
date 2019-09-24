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
 * src/stt/stt_integer_literal_subnode.c: Amara syntax tree integer
 * literal subnode.
 */

/*   For `amara_string`. */
/* #include "../cmn/amara_string.h" */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `void assert_valid_raw_integer(
 * const amara_string * raw_integer)`. */
#include "../brt/integer.h"

/*   For own definitions. */
#include "stt_integer_literal_subnode.h"

stt_integer_literal_subnode *
stt_integer_literal_subnode_default_constructor()
{
	stt_integer_literal_subnode * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_integer_literal_subnode *)
#endif
			malloc(sizeof(stt_integer_literal_subnode));
	forced_assertion(ret_ != NULL);

	ret_->raw_ = NULL;

	return ret_;
}

stt_integer_literal_subnode *
stt_integer_literal_subnode_copy_constructor(
		const stt_integer_literal_subnode * subnode)
{
	stt_integer_literal_subnode * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_integer_literal_subnode *)
#endif
			malloc(sizeof(stt_integer_literal_subnode));
	forced_assertion(ret_ != NULL);

	assertion(subnode != NULL);
	assertion(subnode->raw_ != NULL);

	ret_->raw_ = amara_string_copy_constructor(subnode->raw_);
	forced_assertion(ret_->raw_ != NULL);

	return ret_;
}

void
validate_amara_string_as_integer_literal(const amara_string * raw)
{
	assert_valid_raw_integer(raw);
}

stt_integer_literal_subnode *
stt_integer_literal_subnode_exhaustive_constructor(const amara_string * raw)
{
	stt_integer_literal_subnode * ret_;

	validate_amara_string_as_integer_literal(raw);

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_integer_literal_subnode *)
#endif
			malloc(sizeof(stt_integer_literal_subnode));
	forced_assertion(ret_ != NULL);

	ret_->raw_ = amara_string_copy_constructor(raw);
	forced_assertion(ret_->raw_ != NULL);

	return ret_;
}

void
stt_integer_literal_subnode_destructor(stt_integer_literal_subnode * subnode)
{
	assertion(subnode != NULL);
	if (subnode->raw_ != NULL) {
		amara_string_destructor(subnode->raw_);
	}
	free(subnode);
}

amara_string *
stt_integer_literal_subnode_get_raw(
		const stt_integer_literal_subnode * subnode)
{
	assertion(subnode != NULL);
	assertion(subnode->raw_ != NULL);
	return subnode->raw_;
}

void
stt_integer_literal_subnode_set_raw(
		stt_integer_literal_subnode * subnode,
		const amara_string * raw)
{
	assertion(subnode != NULL);
	if (raw != NULL) {
		validate_amara_string_as_integer_literal(raw);
	}
	if (subnode->raw_ == NULL) {
		if (raw != NULL) {
			subnode->raw_ = amara_string_copy_constructor(raw);
		}
	} else {
		amara_string_destructor(subnode->raw_);
		if (raw != NULL) {
			subnode->raw_ = amara_string_copy_constructor(raw);
		} else {
			subnode->raw_ = NULL;
		}
	}
}

/* TODO missing equality function */
