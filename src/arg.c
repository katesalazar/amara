/*
 * Copyright 2018-2020 Mercedes Catherine Salazar
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
 * src/arg.c: Amara arguments parser.
 */

/* For `void * malloc(size_t)`. */
#include <stdlib.h>

/*   For `int strcmp(const char * s1, const char * s2)`, and
 * `char * strcpy(char * dest, const char * src)`, and
 * `size_t strlen(const char * s)`. */
#include <string.h>

/*   For `void assertion(int expression)`. */
#include "asr/assertion.h"

/* For definitions. */
#include "arg.h"

arg_ret * arg(const int argc, const char * * argv)
{
	arg_ret * ret;
	size_t argv_two_len;
	size_t argv_three_len;
	ret = (arg_ret *) malloc(sizeof(arg_ret));
	ret->value = ARG_RET_NONE;
	ret->option_zero = NULL;
	ret->option_one = NULL;
	if (argc == 1) {
		ret->value |= ARG_RET_PRINT_HELP;
	} else {
		if (argc == 2) {
			if (!strcmp(argv[1], "greet")) {
				ret->value |= ARG_RET_GREET;
			} else {
				ret->value |= ARG_RET_PRINT_HELP;
				ret->value |= ARG_RET_ERR;
			}
		} else if (argc == 3) {
			if (!strcmp(argv[1], "greet")) {
				ret->value |= ARG_RET_GREET;
				if (!strcmp(argv[2], "--no-banner")) {
					ret->value |= ARG_RET_NO_BANNER;
				} else {
					ret->value |= ARG_RET_PRINT_HELP;
					ret->value |= ARG_RET_ERR;
				}
			} else if (!strcmp(argv[1], "run")) {
				if (!strcmp(argv[2], "tests")) {
					ret->value |= ARG_RET_RUN_SCRAMBLED_TESTS;
				} else if (!strcmp(argv[2], "ordered_tests")) {
					ret->value |= ARG_RET_RUN_TESTS;
				} else if (!strcmp(argv[2], "scrambled_tests")) {
					ret->value |= ARG_RET_RUN_SCRAMBLED_TESTS;
				} else {
					ret->value |= ARG_RET_PRINT_HELP;
					ret->value |= ARG_RET_ERR;
				}
			} else if (!strcmp(argv[1], "assert")) {
				ret->value |= ARG_RET_ASSERT_EXPR;
				argv_two_len = strlen(argv[2]);
				ret->option_zero = (char *)
						malloc(argv_two_len + 1);
				strcpy(ret->option_zero, argv[2]);
				ret->option_one = NULL;
			} else {
				ret->value |= ARG_RET_PRINT_HELP;
				ret->value |= ARG_RET_ERR;
			}
		} else if (argc == 4) {
			if (!strcmp(argv[1], "run")) {
				if (!strcmp(argv[2], "tests")) {
					ret->value |= ARG_RET_RUN_SCRAMBLED_TESTS;
					if (!strcmp(argv[3], "--no-banner")) {
						ret->value |= ARG_RET_NO_BANNER;
					} else {
						ret->value |= ARG_RET_PRINT_HELP;
						ret->value |= ARG_RET_ERR;
					}
				} else if (!strcmp(argv[2], "ordered_tests")) {
					ret->value |= ARG_RET_RUN_TESTS;
					if (!strcmp(argv[3], "--no-banner")) {
						ret->value |= ARG_RET_NO_BANNER;
					} else {
						ret->value |= ARG_RET_PRINT_HELP;
						ret->value |= ARG_RET_ERR;
					}
				} else if (!strcmp(argv[2], "scrambled_tests")) {
					ret->value |= ARG_RET_RUN_SCRAMBLED_TESTS;
					if (!strcmp(argv[3], "--no-banner")) {
						ret->value |= ARG_RET_NO_BANNER;
					} else {
						ret->value |= ARG_RET_PRINT_HELP;
						ret->value |= ARG_RET_ERR;
					}
				} else if (!strcmp(argv[2], "app")) {
					ret->value |= ARG_RET_RUN_APP;
					argv_two_len = strlen(argv[3]);
					ret->option_zero = (char *)
							malloc(argv_two_len + 1);
					strcpy(ret->option_zero, argv[3]);
				} else if (!strcmp(argv[2], "ordered")) {
					if (!strcmp(argv[3], "tests")) {
						ret->value |= ARG_RET_RUN_TESTS;
					} else {
						ret->value |= ARG_RET_PRINT_HELP;
						ret->value |= ARG_RET_ERR;
					}
				} else if (!strcmp(argv[2], "scrambled")) {
					if (!strcmp(argv[3], "tests")) {
						ret->value |= ARG_RET_RUN_SCRAMBLED_TESTS;
					} else {
						ret->value |= ARG_RET_PRINT_HELP;
						ret->value |= ARG_RET_ERR;
					}
				} else {
					ret->value |= ARG_RET_PRINT_HELP;
					ret->value |= ARG_RET_ERR;
				}
			} else if (!strcmp(argv[1], "assert")) {
				ret->value |= ARG_RET_ASSERT_EXPR;
				argv_two_len = strlen(argv[2]);
				ret->option_zero = (char *)
						malloc(argv_two_len + 1);
				strcpy(ret->option_zero, argv[2]);
				if (!strcmp(argv[3], "--no-banner")) {
					ret->value |= ARG_RET_NO_BANNER;
				} else {
					argv_three_len = strlen(argv[3]);
					ret->option_one = (char *)
							malloc(argv_three_len + 1);
					strcpy(ret->option_one, argv[3]);
				}
			} else {
				ret->value |= ARG_RET_PRINT_HELP;
				ret->value |= ARG_RET_ERR;
			}
		} else if (argc == 5) {
			if (!strcmp(argv[1], "run")) {
				if (!strcmp(argv[2], "app")) {
					if (!strcmp(argv[4], "--no-banner")) {
						ret->value |= ARG_RET_RUN_APP;
						ret->value |= ARG_RET_NO_BANNER;
						argv_three_len = strlen(argv[3]);
						ret->option_zero = (char *)
								malloc(argv_three_len + 1);
						strcpy(ret->option_zero, argv[3]);
					} else {
						ret->value |= ARG_RET_PRINT_HELP;
						ret->value |= ARG_RET_ERR;
					}
				} else if (!strcmp(argv[2], "tests")) {
					if (!strcmp(argv[3], "in")) {
						if (!strcmp(argv[4], "order")) {
							ret->value |= ARG_RET_RUN_TESTS;
						} else {
							ret->value |= ARG_RET_PRINT_HELP;
							ret->value |= ARG_RET_ERR;
						}
					} else {
						ret->value |= ARG_RET_PRINT_HELP;
						ret->value |= ARG_RET_ERR;
					}
				} else {
					ret->value |= ARG_RET_PRINT_HELP;
					ret->value |= ARG_RET_ERR;
				}
			} else {
				ret->value |= ARG_RET_PRINT_HELP;
				ret->value |= ARG_RET_ERR;
			}
		} else {
			ret->value |= ARG_RET_PRINT_HELP;
			ret->value |= ARG_RET_ERR;
		}
	}
	return ret;
}

void
destroy_arg_ret(arg_ret * arg_ret)
{
	free(arg_ret->option_zero);
	free(arg_ret->option_one);
}
