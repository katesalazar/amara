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
 * src/arg.h: Amara arguments parser.
 */

/* For `uint_fast8_t`. */
#include <stdint.h>

typedef struct {
	uint_fast8_t value;

	/*   When running an app, this is the app's directory. When
	 * asserting an expression, this is the expression. */
	char * option_zero;

	/*   When running an app, this has to be NULL. When asserting
	 * an expression, this is an optional message to be printed if
	 * `amara` fails to assert the expression. */
	char * option_one;
} arg_ret;

#define ARG_RET_NONE        0x00
#define ARG_RET_PRINT_HELP 0x01
#define ARG_RET_RUN_TESTS  0x02
#define ARG_RET_RUN_APP    0x04
#define ARG_RET_GREET      0x08
#define ARG_RET_UNUSED_2   0x10
#define ARG_RET_NO_BANNER   0x20
#define ARG_RET_ASSERT_EXPR 0x40
#define ARG_RET_ERR        0x80

arg_ret *
arg(const int argc, const char * * argv)
__attribute__((warn_unused_result));

void
destroy_arg_ret(arg_ret * arg_ret);
