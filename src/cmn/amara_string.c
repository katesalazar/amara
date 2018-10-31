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
 * src/cmn/amara_string.c: Self explanatory...
 */

/*   For `int fprintf(FILE * restrict stream,
 * const char * restrict format, ...)`. */
#include <stdio.h>

/*   For `size_t strlen(const char * s)` and `char * strcpy(char * dest,
 * const char * src)`. */
#include <string.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "amara_string.h"

amara_string *
amara_string_default_constructor()
{
	amara_string * ret_ = malloc(sizeof(amara_string));
	ret_->value_ = NULL;
	return ret_;
}

amara_string *
amara_string_exhaustive_constructor(const char * value)
{
	amara_string * ret_ = malloc(sizeof(amara_string));
	ret_->value_ = malloc(strlen(value) + 1);
	strcpy(ret_->value_, value);
	return ret_;
}

amara_string *
amara_string_copy_constructor(const amara_string * as)
{
	amara_string * ret_ = malloc(sizeof(amara_string));
	char * as_value_ = amara_string_get_value(as);
	ret_->value_ = malloc(strlen(as_value_) + 1);
	strcpy(ret_->value_, as_value_);
	free(as_value_);
	return ret_;
}

void
amara_string_destructor(amara_string * string)
{
	assertion(string != NULL);
	if (string->value_ != NULL) {
		free(string->value_);
	}
	free(string);
}

char *
amara_string_get_value(const amara_string * string)
{
	char * value_copy_ = malloc(strlen(string->value_) + 1);
	strcpy(value_copy_, string->value_);
	return value_copy_;
}

void
amara_string_set_value(amara_string * string, const char * value)
{
	string->value_ = malloc(strlen(value) + 1);
	strcpy(string->value_, value);
}

size_t
amara_string_length(const amara_string * string)
{
	assertion(string != NULL);
	assertion(string->value_ != NULL);
	return strlen(string->value_);
}

int
amara_string_strcmp(const amara_string * s1, const amara_string * s2)
{
	assertion(s1 != NULL);
	assertion(s1->value_ != NULL);
	assertion(s2 != NULL);
	assertion(s2->value_ != NULL);
	fprintf(stderr, "%s:%u:s1->value_: %s\n", __FILE__, __LINE__, s1->value_);
	fprintf(stderr, "%s:%u:s2->value_: %s\n", __FILE__, __LINE__, s2->value_);
	return strcmp(s1->value_, s2->value_);
}

amara_boolean
amara_string_equality(const amara_string * a1, const amara_string * a2)
{
	int amara_string_strcmp_ret_;
	if (a1 == NULL && a2 == NULL) { /* XXX */
		return AMARA_BOOLEAN_TRUE; /* XXX */
	} /* XXX */
	if (a1 == NULL) {
		return AMARA_BOOLEAN_FALSE;
	}
	if (a2 == NULL) {
		return AMARA_BOOLEAN_FALSE;
	}
	amara_string_strcmp_ret_ = amara_string_strcmp(a1, a2);
	if (amara_string_strcmp_ret_) {
		return AMARA_BOOLEAN_FALSE;
	} else {
		return AMARA_BOOLEAN_TRUE;
	}
}
