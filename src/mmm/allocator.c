/*
 * Copyright 2020 Mercedes Catherine Salazar
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
 * mmm/allocator.c: Memory allocator.
 */

#include "allocator.h"

void *
amara_malloc_rtg_operation_arg_out_of_stt_operation_arg_ret()
{
	void * returning_;

#ifdef AMARA_USE_STD_CXX98
	/* FIXME */
#else
	returning_ = malloc(sizeof(rtg_operation_arg_out_of_stt_operation_arg_ret));
#endif
}

void *
amara_malloc(size_t bytes)
{
	void * returning_;

	returning_ = malloc(bytes);
	forced_assertion(returning_ != NULL);

	return returning_;
}
