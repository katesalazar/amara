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
 * src/rtg/rtg_operations_simple_list.c: Amara runtime graph application
 * function operations simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "rtg_operations_simple_list.h"

rtg_operations_simple_list *
rtg_operations_simple_list_copy_constructor(rtg_operations_simple_list * list)
{
	rtg_operations_simple_list * ret_;
	rtg_operations_simple_list * list_ptr_;
	rtg_operations_simple_list * ret_ptr_;
	rtg_operation * operation_;
	assertion(list != NULL);
	ret_ = malloc(sizeof(rtg_operations_simple_list));
	if (list->first == NULL) {
		ret_->first = NULL;
		assertion(list->next == NULL);
		ret_->next = NULL;
		return ret_;
	}
	list_ptr_ = list;
	ret_ptr_ = ret_;
	while (list_ptr_->next != NULL) {
		operation_ = rtg_operation_copy_constructor(list_ptr_->first);
		assertion(operation_ != NULL);
		ret_ptr_->first = operation_;
		ret_ptr_->next = malloc(sizeof(rtg_operations_simple_list));
		list_ptr_ = list_ptr_->next;
		ret_ptr_ = ret_ptr_->next;
	}
	operation_ = rtg_operation_copy_constructor(list_ptr_->first);
	assertion(operation_ != NULL);
	ret_ptr_->first = operation_;
	ret_ptr_->next = NULL;
	return ret_;
}
