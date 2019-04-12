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
 * src/wrp/dirent_wrapper.c: Amara wrapper for <dirent.h>.
 */

/*   For `errno`. */
#include <errno.h>

/*   For `DIR` and `DIR * opendir(const char *)`. */
#include <dirent.h>

/*   For `void * malloc(size_t)`. */
#include <stdlib.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For definitions. */
#include "dirent_wrapper.h"

dirent_wrapper *
construct_dirent_wrapper()
{
	dirent_wrapper * returning_;
	returning_ = (dirent_wrapper *) malloc(sizeof(dirent_wrapper));
	returning_->manipulation = DIRENT_WRAPPER_MANIPULATION_FALSE;
	returning_->manipulation_details = NULL;
	return returning_;
}

void
destroy_dirent_wrapper(const dirent_wrapper * dirent_wrapper)
{
	if (dirent_wrapper->manipulation_details != NULL) {
		free(dirent_wrapper->manipulation_details);
	}
	free((void *) dirent_wrapper);
}

dirent_wrapper_opendir_ret *
dirent_wrapper_opendir(
		const dirent_wrapper * dirent_wrapper, const char * name)
{
	dirent_wrapper_opendir_ret * dirent_wrapper_opendir_ret_;
	DIR * opendir_ret_;

	assertion_two(
			dirent_wrapper != NULL,
			"passed a NULL dirent.h wrapper to function call");

	dirent_wrapper_opendir_ret_ = (dirent_wrapper_opendir_ret *)
			malloc(sizeof(dirent_wrapper_opendir_ret));

	dirent_wrapper_opendir_ret_->dyed =
			DIRENT_WRAPPER_OPENDIR_RET_MANIPULATED_FALSE;

	if (dirent_wrapper->manipulation == DIRENT_WRAPPER_MANIPULATION_TRUE) {
		if (dirent_wrapper->manipulation_details->manipulation_values &
				DIRENT_WRAPPER_MANIPULATION_VALUES_OPENDIR_FORCE_SUCCESS) {
			/*   It is manipulated, so must return success. Do not
			 * perform the real operation. */
			opendir_ret_ = (DIR *) 0xFF;
			dirent_wrapper_opendir_ret_->dyed =
					DIRENT_WRAPPER_OPENDIR_RET_MANIPULATED_TRUE;
		} else if (dirent_wrapper->manipulation_details->manipulation_values &
				DIRENT_WRAPPER_MANIPULATION_VALUES_OPENDIR_FORCE_EMIT_EACCESS) {
			/*   It is manipulated, so must return what is supposed
			 * to return. */
			opendir_ret_ = NULL;
			dirent_wrapper_opendir_ret_->error_status_code =
					DIRENT_WRAPPER_OPENDIR_RET_ERR_UNQUALIFIED;
			dirent_wrapper_opendir_ret_->dir = NULL;
			dirent_wrapper_opendir_ret_->dyed =
					DIRENT_WRAPPER_OPENDIR_RET_MANIPULATED_TRUE;
			return dirent_wrapper_opendir_ret_;
		} else {
			assertion(dirent_wrapper->manipulation_details->manipulation_values &
					DIRENT_WRAPPER_MANIPULATION_VALUES_OPENDIR_FORCE_EMIT_ENOENT);
			/*   It is manipulated, so must return what is supposed
			 * to return. */
			opendir_ret_ = NULL;
			dirent_wrapper_opendir_ret_->error_status_code =
					DIRENT_WRAPPER_OPENDIR_RET_ERR_ENOENT;
			dirent_wrapper_opendir_ret_->dir = NULL;
			dirent_wrapper_opendir_ret_->dyed =
					DIRENT_WRAPPER_OPENDIR_RET_MANIPULATED_TRUE;
			return dirent_wrapper_opendir_ret_;
		}
	} else {
		/*   No manipulation, os must perform the real operation. */
		opendir_ret_ = opendir(name);
	}

	dirent_wrapper_opendir_ret_->dir = opendir_ret_;

	if (opendir_ret_) {
		/*   The directory exists. */
		/*   There is no need to do anything. We could set
		 * `dirent_wrapper_opendir_ret_.error_status_code` with
		 * something marking success, but that is not necessary,
		 * because success is implicit in returning
		 * `dirent_wrapper_opendir_ret_.dir` set not to `NULL`. */
	} else if (ENOENT == errno) {
		/*   The directory does not exist. */
		dirent_wrapper_opendir_ret_->error_status_code =
				DIRENT_WRAPPER_OPENDIR_RET_ERR_ENOENT;
	} else {
		/* `opendir(const char *) failed for some other reason. */
		dirent_wrapper_opendir_ret_->error_status_code =
				DIRENT_WRAPPER_OPENDIR_RET_ERR_UNQUALIFIED;
	}
	return dirent_wrapper_opendir_ret_;
}

dirent_wrapper_closedir_ret *
dirent_wrapper_closedir(const dirent_wrapper * dirent_wrapper, DIR * dirp)
{
	dirent_wrapper_closedir_ret * dirent_wrapper_closedir_ret_;
	int closedir_ret_;

	assertion(dirent_wrapper != NULL);

	dirent_wrapper_closedir_ret_ = (dirent_wrapper_closedir_ret *)
		malloc(sizeof(dirent_wrapper_closedir_ret));

	dirent_wrapper_closedir_ret_->dyed =
			DIRENT_WRAPPER_CLOSEDIR_RET_MANIPULATED_FALSE;

	if (dirent_wrapper->manipulation == DIRENT_WRAPPER_MANIPULATION_TRUE &&
			dirent_wrapper->manipulation_details->manipulation_values &
					DIRENT_WRAPPER_MANIPULATION_VALUES_CLOSEDIR_FORCE_EMIT_EBADF) {
		closedir_ret_ = -1;
		dirent_wrapper_closedir_ret_->value = closedir_ret_;
		dirent_wrapper_closedir_ret_->error_status_code =
				DIRENT_WRAPPER_CLOSEDIR_RET_ERR_EBADF;
		dirent_wrapper_closedir_ret_->dyed =
				DIRENT_WRAPPER_CLOSEDIR_RET_MANIPULATED_TRUE;
		return dirent_wrapper_closedir_ret_;
	} else {
		closedir_ret_ = closedir(dirp);
	}
	dirent_wrapper_closedir_ret_->value = closedir_ret_;
	if (closedir_ret_) {
		assertion(EBADF == errno);
		dirent_wrapper_closedir_ret_->error_status_code =
				DIRENT_WRAPPER_CLOSEDIR_RET_ERR_EBADF;
	}
	/*   Else there is no need to do anything. We could set
	 * `dirent_wrapper_closedir_ret_.error_status_code` with something
	 * marking success, but that is not necessary, because success is
	 * implicit in returning `dirent_wrapper_closedir_ret_.value` set to
	 * `0`, according the interface contract. */
	return dirent_wrapper_closedir_ret_;
}

void
dirent_wrapper_reflect_add_flags(
		dirent_wrapper * dirent_wrapper, unsigned char flags)
{
	const manipulation_details * manipulation_details_;
	assertion_two(dirent_wrapper != NULL,
			"dirent.h wrapper must be not null in order to remove flags from it");
	assertion_two(flags, "must choose at least one flag to set, can not add _no_ flags");
	/* TODO   Assert that the flags is not currently set. And add a variant of this function, which would be fundamentally the same like this, but it must be repeatable (this one, by contrast, **not**). */
	if (dirent_wrapper->manipulation ==
				DIRENT_WRAPPER_MANIPULATION_FALSE) {
		assertion_two(!dirent_wrapper->manipulation_details,
				"if you are requesting to remove flags from a dirent.h wrapper, then its manipulation details should not be NULL");
		manipulation_details_ =
				(void *) malloc(sizeof(manipulation_details));
		dirent_wrapper->manipulation_details =
				(manipulation_details *) manipulation_details_;
		dirent_wrapper->manipulation_details->manipulation_values =
				DIRENT_WRAPPER_MANIPULATION_VALUES_NONE;
	}
	dirent_wrapper->manipulation = DIRENT_WRAPPER_MANIPULATION_TRUE;
	dirent_wrapper->manipulation_details->manipulation_values |= flags;
}

void
dirent_wrapper_reflect_remove_flags(
		dirent_wrapper * dirent_wrapper, unsigned char flags)
{
	assertion(dirent_wrapper != NULL);
	assertion(dirent_wrapper->manipulation ==
			DIRENT_WRAPPER_MANIPULATION_TRUE);
	assertion(dirent_wrapper->manipulation_details != NULL);
	dirent_wrapper->manipulation_details->manipulation_values &= ~flags;
	if (!dirent_wrapper->manipulation_details->manipulation_values) {
		free(dirent_wrapper->manipulation_details);
		dirent_wrapper->manipulation_details = NULL;
		dirent_wrapper->manipulation =
				DIRENT_WRAPPER_MANIPULATION_FALSE;
	}
}
