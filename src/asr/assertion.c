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
 * src/asr/assertion.c: Assertions utility.
 */

/*   For `void assert(scalar expression)`. */
#include <assert.h>

/*   For `uint_fast8_t`. */
#include <stdint.h>

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `int strcmp(const char * s1, const char * s2)`, and
 * `size_t strlen(const char * s)`. */
#include <string.h>

/*   For own definitions. */
#include "assertion.h"

void
assertion(int expression)
{
#ifdef NDEBUG
	if (!expression) {
		fprintf(stdout, "WARNING Assertion failed\n");
	}
#endif
	assert(expression);

	/* TODO    Convert to macro so this can be removed without
	 * TODO  triggering `-Werror,-Wunused-parameter`. */
	expression--;
}

void
assertion_two(int expression, const char * message)
{
	if (!expression) {
		fprintf(stderr, "%s", message);
	}
	assertion(expression);
}

/*
void disarm_interim(char * message)
{
	const uint_fast8_t traces_printing = 0x00;
	size_t i;
	assertion_two(message != NULL, "expectation was not met");
	if (traces_printing) {
		printf("%lu\n", strlen(message)); */ /* FIXME NOT PORTABLE!!! */ /*
	}
	if (strlen(message) == 0) {
		return;
	}
	for (i = 0; i < strlen(message) - 1; i++) {
		if (traces_printing) {
			printf("iterating... "); */ /* FIXME */ /*
			printf("%lu\n", i);
			printf("%d\n", message[i]);
			printf("%c\n", message[i]);
		}
		if (message[i] == '%' && (message[i + 1] == 's' || message[i + 1] == 'd' || message[i + 1] == 'n')) {
			if (traces_printing) {
				printf("%lu\n", i);
				printf("matches!\n"); */ /* FIXME */ /*
				printf("%lu\n", i);
				printf("%d\n", message[i]);
				printf("%c\n", message[i]);
				printf("%lu\n", i + 1);
				printf("%d\n", message[i + 1]);
				printf("%c\n", message[i + 1]);
			}
			message[i + 1] = '%';
			if (traces_printing) {
				printf("%lu\n", i);
			}
			i++;
			if (traces_printing) {
				printf("%lu\n", i);
			}
		}
	}
}
*/

/*
void
assertion_two_located_interim(
		int expression, const char * message, const char * source_doc,
		unsigned int source_line)
{
	char * message_copy;
	message_copy = NULL;
	if (!expression) {
*/
		/* TODO    Must change in order to use `int sprintf(char * str,
		 * TODO  const char * format, ...)` or one of its alternatives. */
/*
		message_copy = (char *) malloc(strlen(message) + 1);
		strcpy(message_copy, message);
		disarm_interim(message_copy);
		fprintf(stderr, "%s", message_copy);*/  /* XXX */
/*		fprintf(stderr, "%s:", source_doc); */ /* XXX */
/*		fprintf(stderr, "%d\n", source_line); */ /* XXX */
/*	}
	if (message_copy != NULL) {
		free(message_copy);
	}
	assertion(expression);
}
*/

void
interpret_and_assert(const char * expression)
{
	uint_fast8_t expression_numeric_value_;

	assertion(strlen(expression) == 1);
	if (!strcmp(expression, "0")) {
		expression_numeric_value_ = 0;
	} else {
		assertion(!strcmp(expression, "1"));
		expression_numeric_value_ = 1;
	}
	assertion(expression_numeric_value_);
}

void
interpret_and_assert_two(const char * expression, const char * message)
{
	uint_fast8_t expression_numeric_value_;

	assertion_two(strlen(expression) == 1, "expression uses an unexpected length");
	if (!strcmp(expression, "0")) {
		expression_numeric_value_ = 0;
	} else {
		assertion_two(!strcmp(expression, "1"), "unexpected expression");
		expression_numeric_value_ = 1;
	}
	assertion_two(expression_numeric_value_, message);
}
