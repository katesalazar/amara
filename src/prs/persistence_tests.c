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
 * src/prs/persistence_tests.c: Tests for the persistence system.
 */

/*   For `int printf(const char * format, ...)`. */
#include <stdio.h>

/*   For `uint_fast8_t acquire_dir(const char * path_to)`. */
#include "persistence.h"

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `dirent_wrapper`. */
/* #include "../wrp/dirent_wrapper.h" */

/*   For definitions. */
#include "persistence_tests.h"

void
acquire_dir_tests()
;

void
acquire_dir_tests()
{
	dirent_wrapper * dirent_wrapper_;
	uint_fast8_t acquire_dir_ret_;

	dirent_wrapper_ = construct_dirent_wrapper();

	/*   Manipulate `dirent_wrapper` to return close directory errors. */
	dirent_wrapper_reflect_add_flags(
			dirent_wrapper_,
			DIRENT_WRAPPER_MANIPULATION_VALUES_OPENDIR_FORCE_SUCCESS);
	assertion_two(
			dirent_wrapper_->manipulation ==
					DIRENT_WRAPPER_MANIPULATION_TRUE,
			"dirent.h wrapper has been requested to activate manipulation flags, but it isn't marked as manipulated");
	dirent_wrapper_reflect_add_flags(
			dirent_wrapper_,
			DIRENT_WRAPPER_MANIPULATION_VALUES_CLOSEDIR_FORCE_EMIT_EBADF);
	assertion_two(
			dirent_wrapper_->manipulation ==
					DIRENT_WRAPPER_MANIPULATION_TRUE,
			"dirent.h wrapper has been requested to activate manipulation flags, but it isn't marked as manipulated");

	/*   Order to acquire a dir that will not be possible to be closed
	 * right after opening it. */
	acquire_dir_ret_ = acquire_dir_reflective(
			dirent_wrapper_,
			"/PATH/TO/SOME/DIR/WHICH/DOES/NOT/EXIST/14242352345/");

	assertion(acquire_dir_ret_ == PERSISTENCE_ACQUIRE_DIR_ERR_UNSPECIFIC);

	/*   Reset `dirent_wrapper` flags. */
	dirent_wrapper_reflect_remove_flags(
			dirent_wrapper_,
			DIRENT_WRAPPER_MANIPULATION_VALUES_OPENDIR_FORCE_SUCCESS);
	assertion(dirent_wrapper_->manipulation ==
			DIRENT_WRAPPER_MANIPULATION_TRUE);
	dirent_wrapper_reflect_remove_flags(
			dirent_wrapper_,
			DIRENT_WRAPPER_MANIPULATION_VALUES_CLOSEDIR_FORCE_EMIT_EBADF);
	assertion(dirent_wrapper_->manipulation ==
			DIRENT_WRAPPER_MANIPULATION_FALSE);

	/*   Manipulate `dirent_wrapper` to return an open directory
	 * error. There are no permissions to access the directory. */
	dirent_wrapper_reflect_add_flags(
			dirent_wrapper_,
			DIRENT_WRAPPER_MANIPULATION_VALUES_OPENDIR_FORCE_EMIT_EACCESS);
	assertion(dirent_wrapper_->manipulation ==
			DIRENT_WRAPPER_MANIPULATION_TRUE);

	/*   Order to acquire a dir that will not be possible to be
	 * opened, as the user is not supposed to have permission to do
	 * so. */
	acquire_dir_ret_ = acquire_dir_reflective(
			dirent_wrapper_,
			"/NO/MATTER/WHAT/I/WRITE/HERE/IT/IS/SUPPOSED/TO/EMIT/EACCESS/");

	assertion(acquire_dir_ret_ == PERSISTENCE_ACQUIRE_DIR_ERR_UNSPECIFIC);

	/*   Reset `dirent_wrapper` flags. */
	dirent_wrapper_reflect_remove_flags(
			dirent_wrapper_,
			DIRENT_WRAPPER_MANIPULATION_VALUES_OPENDIR_FORCE_EMIT_EACCESS);
	assertion(dirent_wrapper_->manipulation ==
			DIRENT_WRAPPER_MANIPULATION_FALSE);

	/*   Manipulate `dirent_wrapper` to return an open directory
	 * error. The directory does not seem to exist. */
	dirent_wrapper_reflect_add_flags(
			dirent_wrapper_,
			DIRENT_WRAPPER_MANIPULATION_VALUES_OPENDIR_FORCE_EMIT_ENOENT);
	assertion(dirent_wrapper_->manipulation ==
			DIRENT_WRAPPER_MANIPULATION_TRUE);

	/*   Order to acquire a dir that will not be possible to be
	 * opened, as it is supposed not to exist. */
	acquire_dir_ret_ = acquire_dir_reflective(
			dirent_wrapper_,
			"/NO/MATTER/WHAT/I/WRITE/HERE/IT/IS/SUPPOSED/TO/EMIT/ENOENT/");
	assertion(acquire_dir_ret_ =
			PERSISTENCE_ACQUIRE_DIR_ERR_DIR_DOES_NOT_EXIST);

	destroy_dirent_wrapper(dirent_wrapper_);
}

void
persistence_tests()
{
	acquire_dir_tests();
}
