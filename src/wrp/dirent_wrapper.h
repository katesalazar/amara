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
 * src/wrp/dirent_wrapper.h: Amara wrapper for <dirent.h>.
 */

#ifndef __AMARA__WRAPPERS__DIRENT_WRAPPER__H__
#define __AMARA__WRAPPERS__DIRENT_WRAPPER__H__

/*   For `DIR`. */
#include <dirent.h>

/*   Enumeration. Manipulation status of the `dirent_wrapper_opendir_ret *
 * dirent_wrapper_opendir(const dirent_wrapper * dirent_wrapper,
 * const char * name)` operation. */
#define DIRENT_WRAPPER_OPENDIR_RET_MANIPULATED_FALSE 0x00
#define DIRENT_WRAPPER_OPENDIR_RET_MANIPULATED_TRUE  0x01

/*   Here errors can start from 0 because success is implicit by
 * `dirent_wrapper_opendir_ret.dir` being not `NULL`. This is an
 * enumeration. */
#define DIRENT_WRAPPER_OPENDIR_RET_ERR_ENOENT      0x00
#define DIRENT_WRAPPER_OPENDIR_RET_ERR_UNQUALIFIED 0x80

#define DIRENT_WRAPPER_CLOSEDIR_RET_MANIPULATED_FALSE 0x00
#define DIRENT_WRAPPER_CLOSEDIR_RET_MANIPULATED_TRUE  0x01

/*   Here errors can start from 0 because success is implicit by
 * `dirent_wrapper_closedir_ret.value` being `0`. This is an
 * enumeration, not a mask. */
#define DIRENT_WRAPPER_CLOSEDIR_RET_ERR_EBADF 0x00
#define DIRENT_WRAPPER_CLOSEDIR_RET_ERR_ENOENT 0x01

/*   Enumeration. */
#define DIRENT_WRAPPER_MANIPULATION_FALSE 0x00
#define DIRENT_WRAPPER_MANIPULATION_TRUE  0x01

/*   Mask. */
#define DIRENT_WRAPPER_MANIPULATION_VALUES_NONE                       0x00
#define DIRENT_WRAPPER_MANIPULATION_VALUES_OPENDIR_FORCE_SUCCESS      0x01
#define DIRENT_WRAPPER_MANIPULATION_VALUES_OPENDIR_FORCE_EMIT_EACCESS 0x02
#define DIRENT_WRAPPER_MANIPULATION_VALUES_CLOSEDIR_FORCE_EMIT_EBADF  0x04
#define DIRENT_WRAPPER_MANIPULATION_VALUES_OPENDIR_FORCE_EMIT_ENOENT  0x08

typedef struct {
	unsigned char manipulation_values;
} manipulation_details;

typedef struct {
	unsigned char manipulation;
	manipulation_details * manipulation_details;
} dirent_wrapper;

typedef struct {
	/*   This is the interface to the return type of the wrapped syscall
	 * itself. */
	DIR * dir;
	/*   This is used to signal potential errors (`<error.h>` `errno`) like
	 * e.g. the directory does not exist. */
	unsigned char error_status_code;
	/*   This is used to mark that the result is affected of
	 * manipulation. */
	unsigned char dyed;
} dirent_wrapper_opendir_ret;

typedef struct {
	/*   This is the interface to the return type of the wrapped syscall
	 * itself. */
	int value;
	/*   This is used to signal potential errors (`<error.h>` `errno`) like
	 * e.g. the input directory stream descriptor is invalid. */
	unsigned char error_status_code;
	/*   This is used to mark that the result is affected of
	 * manipulation. */
	unsigned char dyed;
} dirent_wrapper_closedir_ret;

dirent_wrapper *
construct_dirent_wrapper(void)
__attribute__((warn_unused_result));

void
destroy_dirent_wrapper(const dirent_wrapper * dirent_wrapper)
;

dirent_wrapper_opendir_ret *
dirent_wrapper_opendir(
		const dirent_wrapper * dirent_wrapper, const char * name)
__attribute__((warn_unused_result));

dirent_wrapper_closedir_ret *
dirent_wrapper_closedir(const dirent_wrapper * dirent_wrapper, DIR * dirp)
__attribute__((warn_unused_result));

void
dirent_wrapper_reflect_add_flags(
		dirent_wrapper * dirent_wrapper, unsigned char flags)
;

void
dirent_wrapper_reflect_remove_flags(
		dirent_wrapper * dirent_wrapper, unsigned char flags)
;

#endif
