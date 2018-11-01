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
 * src/prs/persistence.h: Amara code for interacting with persistent
 * document systems.
 */

#ifndef __AMARA__PERSISTENCE__PERSISTENCE_H__
#define __AMARA__PERSISTENCE__PERSISTENCE_H__

/*   For `dirent_wrapper`. */
#include "../wrp/dirent_wrapper.h"

#define PERSISTENCE_ACQUIRE_DIR_SUCCESS                0x00
#define PERSISTENCE_ACQUIRE_DIR_ERR_DIR_DOES_NOT_EXIST 0x01
#define PERSISTENCE_ACQUIRE_DIR_ERR_UNSPECIFIC         0x02

/**   Acquires the directory `path_to`. */
unsigned char
acquire_dir(const char * path_to)
__attribute__((warn_unused_result));

/**   Acquires the directory `path_to`.
 *    You would normally want to use `unsigned char acquire_dir(const char *
 * path_to)` instead. */
unsigned char
acquire_dir_reflective(
		const dirent_wrapper * dirent_wrapper, const char * path_to)
__attribute__((warn_unused_result));

#endif
