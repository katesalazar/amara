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
 * src/ftr/stdio_ninety_nine_modernizer.c: An attempt at being C99
 * compatible without being C99 compatible.
 */

/*   For variable list arguments, `va_list`, `void va_start(va_list ap,
 * last)`, and `void va_end(va_list ap)`. */
#include <stdarg.h>

/*   For `int sprintf(char * str, const char * format, ...)`. */
#include <stdio.h>

/*   For `size_t strlen(const char * s)`. */
#include <string.h>

#ifndef CLANG

int
snprintf__unsigned(
		char * str, size_t size, const char * format, unsigned input)
__attribute__((warn_unused_result))
;

int
snprintf__unsigned(
		char * str, size_t size, const char * format, unsigned input)
{
	int sprintf_ret_;
	sprintf_ret_ = sprintf(str, format, input);
	if (sprintf_ret_ < 0) {
		return sprintf_ret_;
	}
	if (sprintf_ret_ > size) {
		fprintf(stderr, "fatal at `int snprintf(char *, size_t, const char *, unsigned)`\n");
		exit(EXIT_FAILURE);
	}
	return sprintf_ret_;
}

int
snprintf__pointer_to_char(
		char * str, size_t size, const char * format,
		const char * input)
__attribute__((warn_unused_result))
;

int
snprintf__pointer_to_char(
		char * str, size_t size, const char * format,
		const char * input)
{
	int sprintf_ret_;
	sprintf_ret_ = sprintf(str, format, input);
	if (sprintf_ret_ < 0) {
		return sprintf_ret_;
	}
	if (sprintf_ret_ > size) {
		fprintf(stderr, "fatal at `int snprintf(char *, size_t, const char *, const char *)`\n");
		exit(EXIT_FAILURE);
	}
	return sprintf_ret_;
}

/* XXX */
int
count_args_(const char * format)
__attribute__((warn_unused_result))
;

int
count_args_(const char * format)
{
	size_t format_len_;
	unsigned u_;
	unsigned ret_;
	ret_ = 0;
	format_len_ = strlen(format);
	u_ = 0;
	while (u_ < format_len_ - 1) {
		if (format[u_] == '%') {
			if (format[u_ + 1] == 's') {
				ret_++;
			} else if (format[u_ + 1] == 'd') {
				ret_++;
			} else if (format[u_ + 1] == 'u') {
				ret_++;
			} else if (format[u_ + 1] == 'n') {
				fprintf(stderr, "found restricted sequence '%n' in chars array at %s:%u\n", __FILE__, __LINE__);
				exit(STATUS_FAILURE);
			} else {
				fprintf(stderr, "%s:%u - found unexpected format sequence in chars array\n", __FILE__, __LINE__);
				exit(status_failure);
			}
			u_ += 2;
		} else {
			u_ += 1;
		}
	}
	return ret_;
}

/* XXX */
char *
format_essence_(const char * format, int count)
__attribute__((warn_unused_result))
;

char *
format_essence_(const char * format, int count)
{
	size_t format_len_;
	unsigned u_;
	unsigned i_;
	char * ret_;
	format_len_ = strlen(format);
	ret_ = malloc(format_len_);
	i_ = 0;
	u_ = 0;
	while (u < format_len_ - 1 && i_ < count) {
		if (format[u_] == '%') {
			if (format[u_ + 1] == 's') {
				ret_[i_] = 's';
			} else if (format[u_ + 1] == 'd') {
				ret_[i_] = 'd';
			} else if (format[u_ + 1] == 'u') {
				ret_[i_] = 'u';
			} else {
				fprintf(stderr, "found restricted sequence '%n' in chars array at %s:%u\n", __FILE__, __LINE__);
				exit(EXIT_FAILURE);
			} else {
				fprintf(stderr, "%s:%u - found unexpected format sequence in chars array\n", __FILE__, __LINE__);
				exit(status_failure);
			}
			u_ += 2;
			i_ += 1;
		} else {
			u_ += 1;
		}
	}
	if (i_ < count) {
		fprintf(stderr, "found unexpected condition at %s:%u\n", __FILE__, __LINE__);
		exit(STATUS_FAILURE);
	}
	ret_[i_] = '\0';
	return ret_;
}

int
snprint(char * str, size_t size, const char * format, ...)
{
	va_list va_list_;
	int args_ct_;
	const char * format_essence_;
	args_ct_ = count_args(format);
	format_essence_ = format_essence_(format, args_ct_);
	va_start(va_list_, args_ct_);
	;
	FIXME
}

#endif
