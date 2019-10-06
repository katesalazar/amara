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
 * src/asr/assertion.c: Assertions utility.
 */

/*   For `void assert(scalar expression)`. */
#include <assert.h>

/*   XXX won't be available in every system. */
#include <execinfo.h>

/*   For `int fprintf(FILE * stream, const char * format, ...)`. */
#include <stdio.h>

/*   For `void * malloc(size_t size)`. */
#include <stdlib.h>

/*   For `int strcmp(const char * s1, const char * s2)`, and
 * `size_t strlen(const char * s)`. */
#include <string.h>

/*   For own definitions. */
#include "assertion.h"

#ifdef INTERRUPT_INSTEAD_OF_FAIL_TO_ASSERT
#undef INTERRUPT_INSTEAD_OF_FAIL_TO_ASSERT
#endif
/* #define INTERRUPT_INSTEAD_OF_FAIL_TO_ASSERT */

#ifdef INTERRUPT_INSTEAD_OF_FAIL_TO_ASSERT
#include <signals.h>  /* XXX it is <signal.h>, I just want it to fail on
                             first time used in order to know I'm
                             activating the stimulus correctly. */
#endif

void
assertion(int expression)
{
	assertion_two(expression, "WARNING Assertion failed\n");
}

void
assertion_two(int expression, const char * message)
{
	if (!expression) {
		fprintf(stderr, "%s\n", message);
	}

	assert(expression);

	/* TODO    Convert to macro so this can be removed without
	 * TODO  triggering `-Werror,-Wunused-parameter`. */
	expression--;
}

void
forced_assertion(int expression)
{
	forced_assertion_two(expression, "WARNING Assertion failed\n");
}

void
forced_assertion_two(int expression, const char * message)
{
	/**  FIXME This repeated allocation MUST be removed. */
	void * call_stack[128];
	char * * call_stack_strings;
	short i, frames;

	if (!expression) {
		fprintf(stderr, "%s\n", message);

	/* WARNING THIS IS ONLY VALID IN LINUX AND MACO (http://stackoverflow.com/questions/3899870/) */
	frames = backtrace(call_stack, 128);
	call_stack_strings = backtrace_symbols(call_stack, frames);
	for (i = 0; i < frames; i++) {
		printf("%s\n", call_stack_strings[i]);
	}
	free(call_stack_strings);

	}

#ifdef INTERRUPT_INSTEAD_OF_FAIL_TO_ASSERT
	if (!expression) {
		raise(SIGINT);
	}
#else
	assert(expression);
#endif

	if (!expression) {
		exit(1); /* FIXME 1..? */
	}
}

/*
void disarm_interim(char * message)
{
	const unsigned char traces_printing = 0x00;
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
	unsigned char expression_numeric_value_;

	assertion(strlen(expression) == 1);

	assertion(expression[0] != '\0');
	assertion(expression[0] >= '0');
	assertion(expression[0] <= '1');
	assertion(expression[1] == '\0');

	expression_numeric_value_ = expression[0] - 48;

	assertion(expression_numeric_value_);
}

void
interpret_and_assert_two(const char * expression, const char * message)
{
	unsigned char expression_numeric_value_;

	assertion_two(strlen(expression) == 1, "expression uses an unexpected length");

	assertion_two(expression[0] != '\0', "unexpected expression");
	assertion_two(expression[0] >= '0', "unexpected expression");
	assertion_two(expression[0] <= '1', "unexpected expression");
	assertion_two(expression[1] == '\0', "unexpected expression");

	expression_numeric_value_ = expression[0] - 48;

	assertion_two(expression_numeric_value_, message);
}
