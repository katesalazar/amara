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
 * src/stt/stt_natural_subnode.c: Amara syntax tree natural subnode.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `void assert_valid_raw_natural(
 * const amara_string * raw_natural)`. */
#include "../brt/natural.h"

/*   For own definitions. */
#include "stt_natural_subnode.h"

stt_natural_subnode *
stt_natural_subnode_default_constructor()
{
	stt_natural_subnode * ret_ = malloc(sizeof(stt_natural_subnode));
	ret_->raw_ = NULL;
	return ret_;
}

stt_natural_subnode *
stt_natural_subnode_copy_constructor(const stt_natural_subnode * subnode)
{
	stt_natural_subnode * ret_ = malloc(sizeof(stt_natural_subnode));
	assertion(subnode != NULL);
	assertion(subnode->raw_ != NULL);
	ret_->raw_ = amara_string_copy_constructor(subnode->raw_);
	return ret_;
}

void
validate_amara_string_as_natural(const amara_string * raw)
{
	assert_valid_raw_natural(raw);
}

stt_natural_subnode *
stt_natural_subnode_exhaustive_constructor(const amara_string * raw)
{
	stt_natural_subnode * ret_;
	validate_amara_string_as_natural(raw);
	ret_ = malloc(sizeof(stt_natural_subnode));
	ret_->raw_ = amara_string_copy_constructor(raw);
	return ret_;
}

void
stt_natural_subnode_destructor(stt_natural_subnode * subnode)
{
	assertion(subnode != NULL);
	assertion(subnode->raw_ != NULL);
	amara_string_destructor(subnode->raw_);
	free(subnode);
}

void
stt_natural_subnode_set_raw(
		stt_natural_subnode * subnode, const amara_string * raw)
{
	validate_amara_string_as_natural(raw);
	assertion(subnode != NULL);
	if (subnode->raw_ != NULL) {
		amara_string_destructor(subnode->raw_);
		subnode->raw_ = NULL;
	}
	if (raw != NULL) {
		subnode->raw_ = amara_string_copy_constructor(raw);
	}
}

/* TODO missing equality function */
