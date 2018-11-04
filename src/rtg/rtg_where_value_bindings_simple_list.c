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
 * src/rtg/rtg_where_value_bindings_simple_list.c: Amara run time graph
 * _where_ value bindings simple list.
 */

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For own definitions. */
#include "rtg_where_value_bindings_simple_list.h"

rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_copy_constructor_inner(
        const rtg_where_value_bindings_simple_list * list)
__attribute__((warn_unused_result))
;

rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_copy_constructor_inner(
		const rtg_where_value_bindings_simple_list * list)
{
	rtg_where_value_bindings_simple_list * returning_;

	if (list == NULL) {
		return NULL;
	}

	returning_ = malloc(sizeof(rtg_where_value_bindings_simple_list));
#ifndef NDEBUG
	assertion(returning_ != NULL);
#endif

	returning_->first = rtg_where_value_binding_copy_constructor(
			list->first);
#ifndef NDEBUG
	assertion(returning_->first != NULL);
	assertion(returning_->first->value_name_ != NULL);
	assertion(returning_->first->value_expression_ != NULL);
#endif

	returning_->next =
			rtg_where_value_bindings_simple_list_copy_constructor_inner(
					list->next);

	return returning_;
}

rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_default_constructor()
{
    rtg_where_value_bindings_simple_list * returning_;
    returning_ = malloc(sizeof(rtg_where_value_bindings_simple_list));
    returning_->first = NULL;
    returning_->next = NULL;
    return returning_;
}

rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_copy_constructor(
         const rtg_where_value_bindings_simple_list * list)
{
    rtg_where_value_bindings_simple_list * returning_;

#ifndef NDEBUG
    assertion(list != NULL);
#endif
    if (list->first == NULL) {

#ifndef NDEBUG
        assertion(list->next == NULL);
#endif
        returning_ = malloc(sizeof(rtg_where_value_bindings_simple_list));
#ifndef NDEBUG
        assertion(returning_ != NULL);
#endif

        returning_->first = NULL;
        returning_->next = NULL;
        return returning_;
    }

    returning_ = rtg_where_value_bindings_simple_list_copy_constructor_inner(list);
#ifndef NDEBUG
    assertion(returning_ != NULL);
#endif

    return returning_;
}

void
rtg_where_value_bindings_simple_list_destructor(
		rtg_where_value_bindings_simple_list * list)
{
	rtg_where_value_bindings_simple_list * ptr_;
	rtg_where_value_bindings_simple_list * ptr_delete_;

#ifndef NDEBUG
	assertion(list != NULL);
#endif

	if (list->first == NULL) {

#ifndef NDEBUG
		assertion(list->next == NULL);
#endif

		free(list);
	} else {

		ptr_ = list;
		while (ptr_ != NULL) {

#ifndef NDEBUG
			assertion(ptr_->first != NULL);
#endif
			rtg_where_value_binding_destructor(
					ptr_->first);
			ptr_delete_ = ptr_;
			ptr_ = ptr_->next;
			free(ptr_delete_);
		}
	}
}

#ifndef NDEBUG

void
rtg_where_value_bindings_simple_list_assert_healthy_inner(
		const rtg_where_value_bindings_simple_list * list)
{
	if (list != NULL) {

		assertion(list->first != NULL);
		rtg_where_value_bindings_simple_list_assert_healthy_inner(
				list->next);
	}
}

void
rtg_where_value_bindings_simple_list_assert_healthy(
		const rtg_where_value_bindings_simple_list * list)
{
	assertion(list != NULL);

	if (list->first == NULL) {

		assertion(list->next == NULL);
	} else {

		rtg_where_value_bindings_simple_list_assert_healthy_inner(
				list);
	}
}

#endif

rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_push_front_inner(
		rtg_where_value_bindings_simple_list * list,
		const rtg_where_value_binding * element)
__attribute__((warn_unused_result))
;

rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_push_front_inner(
		rtg_where_value_bindings_simple_list * list,
		const rtg_where_value_binding * element)
{
	rtg_where_value_bindings_simple_list * new_list_node_;

#ifndef NDEBUG
	assertion(list != NULL);
	assertion(list->first != NULL);
	assertion(element != NULL);
	assertion(element->value_name_ != NULL);
	assertion(element->value_expression_ != NULL);
	assertion(element->value_expression_->type_ !=
			RTG_EXPRESSION_TYPE_INVALID);
#endif

	new_list_node_ = malloc(sizeof(rtg_where_value_bindings_simple_list));
#ifndef NDEBUG
	assertion(new_list_node_ != NULL);
#endif

	new_list_node_->first =
			rtg_where_value_binding_copy_constructor(element);
#ifndef NDEBUG
	assertion(new_list_node_->first != NULL);
	rtg_where_value_binding_assert_healthy(new_list_node_->first);
#endif

	new_list_node_->next = list;

	return new_list_node_;
}

rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_push_front(
		rtg_where_value_bindings_simple_list * list,
		const rtg_where_value_binding * element)
{
#ifndef NDEBUG
	const rtg_where_value_bindings_simple_list * returning_;
	amara_boolean equality_;
#endif

#ifndef NDEBUG
	assertion(list != NULL);
	assertion(element != NULL);
	assertion(element->value_name_ != NULL);
	assertion(element->value_expression_ != NULL);
	assertion(element->value_expression_->type_ !=
			RTG_EXPRESSION_TYPE_INVALID);
#endif

	if (list->first == NULL) {

#ifndef NDEBUG
		assertion(list->next == NULL);
#endif

		list->first = rtg_where_value_binding_copy_constructor(
				element);
#ifndef NDEBUG
		assertion(list->first != NULL);
		assertion(list->first->value_name_ != NULL);
		equality_ = amara_string_equality(
				list->first->value_name_,
				element->value_name_);
		assertion(equality_ == AMARA_BOOLEAN_TRUE);
		assertion(list->first->value_expression_ != NULL);
		{
		amara_boolean equality__;
		equality__ = rtg_expression_equality(
				list->first->value_expression_,
				element->value_expression_);
		assertion(equality__ == AMARA_BOOLEAN_TRUE);
		}
#endif

		return list;
	}

#ifndef NDEBUG
	returning_ =
#else
	return
#endif
			rtg_where_value_bindings_simple_list_push_front_inner(
					list, element);
#ifndef NDEBUG
	return (rtg_where_value_bindings_simple_list *) returning_;
#endif
}

rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_inner(
		stt_where_value_bindings_simple_list * list)
__attribute__((warn_unused_result))
;

rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_inner(
		stt_where_value_bindings_simple_list * list)
{
	rtg_where_value_bindings_simple_list * returning_;

	if (list == NULL) {
		return NULL;
	}

	assertion(list->first != NULL);

	returning_ = malloc(sizeof(rtg_where_value_bindings_simple_list));

	returning_->first =
			rtg_where_value_binding_out_of_stt_where_value_binding(
					list->first);

	returning_->next =
			rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_inner(
					list->next);

	return returning_;
}

rtg_where_value_bindings_simple_list *
rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list(
		stt_where_value_bindings_simple_list * list)
{
	rtg_where_value_bindings_simple_list * returning_;

	/* if (list == NULL) { *//* XXX *//*
		return NULL; *//* XXX *//*
	} *//* XXX */

	assertion(list != NULL);

	if (list->first == NULL) {
		returning_ = malloc(sizeof(
				rtg_where_value_bindings_simple_list));

		returning_->first = NULL;
		returning_->next = NULL;
		return returning_;
	}

	return rtg_where_value_bindings_simple_list_out_of_stt_where_value_bindings_simple_list_inner(
			list);
}
