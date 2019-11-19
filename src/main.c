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
 * src/main.c: Amara `main` function.
 */

/*   For `int printf(const char *, ...)`. */
#include <stdio.h>

/*   For `void free(void *)`. */
#include <stdlib.h>

/*   For `void run_app(const char *)`. */
#include "arn/app_runner.h"

/*   For `void interpret_and_assert(const char * expression)`. */
#include "asr/assertion.h"

/*   For `void run_tests()`. */
#include "tst/tests_runner.h"

/*   For `ARG_RET_ERR`, `ARG_RET_PRINT_HELP`, `ARG_RET_RUN_TESTS`,
 * `ARG_RET_RUN_APP`... */
#include "arg.h"

/*   For `unsigned char acquire_dir(const char *)`. */
#include "prs/persistence.h"

#define AMARA_MAIN_RET_SUCCESS 0x00
#define AMARA_MAIN_RET_ERR     0x01

unsigned char
amara_main(const int argc, const char * * argv)
__attribute__((warn_unused_result))
;

void
banner()
{
	printf(" ____________________\n");
	printf("|   _  _ _  _  _ _   |\n");
	printf("|  (_|| | |(_|| (_|  |\n");
	printf("|____________________|\n");
	printf("\n");
}

void
greet(amara_boolean double_end_of_line_char)
{
	printf("Wish you have a wonderful day!\n");
	if (double_end_of_line_char) {
		printf("\n");
	}
}

void
print_help()
{
	printf("Usage:\n");
	printf("    AMARA\n");
	printf("        (prints this help)\n");
	printf("    AMARA greet [OPTIONS...]\n");
	printf("        (greets)\n");
	printf("    AMARA assert EXPR [OPTIONS...]\n");
	printf("        (tries to assert an expression)\n");
	printf("    AMARA assert EXPR MSG [OPTIONS...]\n");
	printf("        (tries to assert an expression, printing the ");
	printf("message if the assertion fails)\n");
	printf("    AMARA run tests [OPTIONS...]\n");
	printf("        (runs the rests)\n");
	printf("    AMARA run app DIR [OPTIONS...]\n");
	printf("        (runs the application in DIR)\n");
	printf("\n");
	printf("Options:  --no-banner  Don't print the greeting ");
	printf("banner.\n\n");
}

/* XXX friend declaration. */
void amara_destroy_flex_buffer(void);

unsigned char
amara_main(const int argc, const char * * argv)
{
	const arg_ret * arg_;
	amara_boolean print_banner_;
	unsigned char app_runner_ret_;
	unsigned char returning_;
	returning_ = AMARA_MAIN_RET_ERR;
	arg_ = arg(argc, argv);
	if (arg_->value & ARG_RET_ERR) {
		printf("An unknown error happened while processing ");
		printf("arguments.\n\n");
	}
	if (arg_->value & ARG_RET_NO_BANNER) {
		print_banner_ = AMARA_BOOLEAN_FALSE;
	} else {
		print_banner_ = AMARA_BOOLEAN_TRUE;
	}
	if (print_banner_ == AMARA_BOOLEAN_TRUE) {
		banner();
	}
	if (arg_->value & ARG_RET_PRINT_HELP) {
		print_help();
	} else if (arg_->value & ARG_RET_GREET) {
		greet(print_banner_);
		returning_ = AMARA_MAIN_RET_SUCCESS;
	} else if (arg_->value & ARG_RET_ASSERT_EXPR) {
		if (arg_->option_one) {
			interpret_and_assert_two(
					arg_->option_zero, arg_->option_one);
		} else {
			interpret_and_assert(arg_->option_zero);
		}
		returning_ = AMARA_MAIN_RET_SUCCESS;
	} else if (arg_->value & ARG_RET_RUN_TESTS) {
		run_tests(print_banner_);

		/* XXX */
		amara_destroy_flex_buffer();

		returning_ = AMARA_MAIN_RET_SUCCESS;
	} else {
		assertion(arg_->value & ARG_RET_RUN_APP);
		app_runner_ret_ = run_app(arg_->option_zero);
		if (app_runner_ret_ == APP_RUNNER_RUN_APP_RET_SUCCESS) {
			returning_ = AMARA_MAIN_RET_SUCCESS;
		} else if (app_runner_ret_ == APP_RUNNER_RUN_APP_RET_ERROR_DIR_DOES_NOT_EXIST) {
			returning_ = AMARA_MAIN_RET_ERR;
		} else {
			assertion_two(
					APP_RUNNER_RUN_APP_RET_ERROR_DOC_DOES_NOT_EXIST ==
							app_runner_ret_,
					"unexpected return value for function `? run_app(?)`");
			returning_ = AMARA_MAIN_RET_ERR;
		}
	}
	destroy_arg_ret((arg_ret *) arg_);
	free((arg_ret *) arg_);
	return returning_;
}

int
main(int argc, const char * * argv)
{
	unsigned char amara_main_ret_;

	amara_main_ret_ = amara_main(argc, argv);

	assertion(amara_main_ret_ <= 0x7F);

	return amara_main_ret_;
}
