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
 * src/prs/persistence.c: Amara code for interacting with persistent
 * document systems.
 */

/*   For `uint_fast8_t`. */
#include <stdint.h>

/*   For `void free(void * ptr)`. */
#include <stdlib.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For definitions. */
#include "persistence.h"

/*   For `dirent_wrapper_DIR * dirent_wrapper_opendir(const char *),
 * `DIRENT_WRAPPER_OPENDIR_RET_ERROR_ENOENT`... */
#include "../wrp/dirent_wrapper.h"

uint_fast8_t acquire_dir(const char * path_to)
{
	uint_fast8_t returning_;
	const dirent_wrapper * dirent_wrapper;
	dirent_wrapper = construct_dirent_wrapper();
	returning_ = acquire_dir_reflective(dirent_wrapper, path_to);
	destroy_dirent_wrapper(dirent_wrapper);
	return returning_;
}

uint_fast8_t acquire_dir_reflective(
		const dirent_wrapper * dirent_wrapper, const char * path_to)
{
	dirent_wrapper_opendir_ret * dirent_wrapper_opendir_ret_;
	dirent_wrapper_closedir_ret * dirent_wrapper_closedir_ret_;
	dirent_wrapper_opendir_ret_ =
			dirent_wrapper_opendir(dirent_wrapper, path_to);
	if (dirent_wrapper_opendir_ret_->dir) {
		/*   Directory exists. */

		/* TODO   Acquire the dir. */

		/*   After acquired, close the dir. */
		dirent_wrapper_closedir_ret_ = dirent_wrapper_closedir(
				dirent_wrapper,
				dirent_wrapper_opendir_ret_->dir);
		if (dirent_wrapper_closedir_ret_->value) {

			free(dirent_wrapper_closedir_ret_);
			free(dirent_wrapper_opendir_ret_);
			return PERSISTENCE_ACQUIRE_DIR_ERR_UNSPECIFIC;
		}

		/*   Finally, return success. */
		free(dirent_wrapper_closedir_ret_);
		free(dirent_wrapper_opendir_ret_);
		return PERSISTENCE_ACQUIRE_DIR_SUCCESS;
	} else if (dirent_wrapper_opendir_ret_->error_status_code ==
			DIRENT_WRAPPER_OPENDIR_RET_ERR_ENOENT) {

		/*   Directory does not exist. */
		free(dirent_wrapper_opendir_ret_);
		return PERSISTENCE_ACQUIRE_DIR_ERR_DIR_DOES_NOT_EXIST;
	} else {
		assertion(dirent_wrapper_opendir_ret_->error_status_code ==
				DIRENT_WRAPPER_OPENDIR_RET_ERR_UNQUALIFIED);

		/*   `opendir(const char *) failed for some other reason. */
		free(dirent_wrapper_opendir_ret_);
		return PERSISTENCE_ACQUIRE_DIR_ERR_UNSPECIFIC;
	}
}
