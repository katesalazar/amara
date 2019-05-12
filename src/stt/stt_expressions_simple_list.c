/*
 * Copyright 2019 Mercedes Catherine Salazar
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
 * src/stt/stt_expressions_simple_list.c: Amara syntax tree expressions
 * simple listt.
 */

#include "../asr/assertion.h"

#include "stt_expressions_simple_list.h"

stt_expressions_simple_list *
stt_expressions_simple_list_default_constructor()
{
	stt_expressions_simple_list * ret_;

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_expressions_simple_list *)
#endif
			malloc(sizeof(stt_expressions_simple_list));
	forced_assertion(ret_ != NULL);

	ret_->first = NULL;
	ret_->next = NULL;

	return ret_;
}

stt_expressions_simple_list *
stt_expressions_simple_list_copy_constructor_inner(
		const stt_expressions_simple_list * expressions_list)
__attribute__((warn_unused_result))
;

stt_expressions_simple_list *
stt_expressions_simple_list_copy_constructor_inner(
		const stt_expressions_simple_list * expressions_list)
{
	stt_expressions_simple_list * ret_;

	if (expressions_list == NULL) {

		return NULL;
	}

#ifndef NDEBUG
	located_assertion(expressions_list->first != NULL);
#endif

	ret_ =
#ifdef AMARA_USE_STD_CXX98
			(stt_expressions_simple_list *)
#endif
			malloc(sizeof(stt_expressions_simple_list));
	located_forced_assertion_one(ret_ != NULL);

	ret_->first = stt_expression_copy_constructor(expressions_list->first);
	located_forced_assertion_one(ret_->first != NULL);

	if (expressions_list->first == NULL) {

#ifndef NDEBUG
		assertion(expressions_list->next == NULL);
#endif

		ret_->next = NULL;
	} else {

		ret_->next =
				stt_expressions_simple_list_copy_constructor_inner(
						expressions_list->next);
        if (expressions_list->next != NULL) {
            located_forced_assertion_one(ret_->next != NULL); }
	}

	return ret_;
}

stt_expressions_simple_list *
stt_expressions_simple_list_copy_constructor(
		const stt_expressions_simple_list * expressions_list)
{
	stt_expressions_simple_list * ret_;

#ifndef NDEBUG
	assertion(expressions_list != NULL);
#endif

	if (expressions_list->first == NULL) {

#ifndef NDEBUG
		assertion(expressions_list->next == NULL);
#endif

		ret_ = stt_expressions_simple_list_default_constructor();
		forced_assertion(ret_ != NULL);

		return ret_;
	}

	return stt_expressions_simple_list_copy_constructor_inner(
			expressions_list);
}

void
stt_expressions_simple_list_destructor_inner(
		stt_expressions_simple_list * list)
;

void
stt_expressions_simple_list_destructor_inner(
		stt_expressions_simple_list * list)
{
	if (list != NULL) {

#ifndef NDEBUG
		assertion(list->first != NULL);
#endif

		stt_expression_destructor(list->first);

		stt_expressions_simple_list_destructor_inner(list->next);
	}

	free(list);
}

void
stt_expressions_simple_list_destructor(stt_expressions_simple_list * list)
{
#ifndef NDEBUG
	assertion(list != NULL);
#endif

	if (list->first == NULL) {

#ifndef NDEBUG
		assertion(list->next == NULL);
#endif

		free(list);
	} else {
		stt_expressions_simple_list_destructor_inner(list);
	}
}

stt_expressions_simple_list *
stt_expressions_simple_list_push_front(
		const stt_expressions_simple_list * expressions_list,
		const struct stt_expression * expression)
{
	stt_expressions_simple_list * new_node_;

#ifndef NDEBUG
	assertion(expressions_list != NULL);
	assertion(expression != NULL);
#endif

	new_node_ = malloc(sizeof(stt_expressions_simple_list));
	forced_assertion(new_node_ != NULL);

	new_node_->first = stt_expression_copy_constructor(expression);
	forced_assertion(new_node_->first != NULL);

	if (expressions_list->first == NULL) {
#ifndef NDEBUG
		assertion(expressions_list->next == NULL);
#endif
		new_node_->next = NULL;
	} else {
		new_node_->next = stt_expressions_simple_list_copy_constructor(
				expressions_list);
		forced_assertion(new_node_->next != NULL);
	}

	return new_node_;
}

signed short
stt_expressions_simple_list_length_inner(
		const stt_expressions_simple_list * expressions_list)
__attribute__((warn_unused_result))
;

signed short
stt_expressions_simple_list_length_inner(
		const stt_expressions_simple_list * expressions_list)
{
	if (expressions_list != NULL) {
#ifndef NDEBUG
		assertion(expressions_list->first != NULL);
#endif
		return 1 + stt_expressions_simple_list_length_inner(
				expressions_list->next);
	}
	return 0;  /* XXX */
}

signed short
stt_expressions_simple_list_length(
		const stt_expressions_simple_list * expressions_list)
{
#ifndef NDEBUG
	assertion(expressions_list != NULL);
#endif
	if (expressions_list->first == NULL) {
#ifndef NDEBUG
		assertion(expressions_list->next == NULL);
#endif
		return 0;
	}
	return stt_expressions_simple_list_length_inner(expressions_list);
}

amara_boolean
stt_expressions_simple_list_equality_inner(
		const stt_expressions_simple_list * l0,
		const stt_expressions_simple_list * l1)
__attribute__((warn_unused_result))
;

amara_boolean
stt_expressions_simple_list_equality_inner(
		const stt_expressions_simple_list * l0,
		const stt_expressions_simple_list * l1)
{
	amara_boolean equality_;
    
    if (l0 == NULL) {
        if (l1 == NULL) {
            return AMARA_BOOLEAN_TRUE;
        }
        return AMARA_BOOLEAN_FALSE;
    }
    if (l1 == NULL) {
        /* l0 != NULL */
        return AMARA_BOOLEAN_FALSE;
    }

	if (l0->first == NULL) {

#ifndef NDEBUG
		assertion(l0->next == NULL);
#endif

		if (l1->first == NULL) {

#ifndef NDEBUG
			assertion(l1->next == NULL);
#endif

			return AMARA_BOOLEAN_TRUE;
		}

		return AMARA_BOOLEAN_FALSE;
	}

	equality_ = stt_expressions_equality(l0->first, l1->first);

	if (equality_ == AMARA_BOOLEAN_FALSE) {

		return AMARA_BOOLEAN_FALSE;
	}

	return stt_expressions_simple_list_equality_inner(l0->next, l1->next);
}

amara_boolean
stt_expressions_simple_list_equality(
		const stt_expressions_simple_list * l0,
		const stt_expressions_simple_list * l1)
{
#ifndef NDEBUG
	assertion(l0 != NULL);
	assertion(l1 != NULL);
#endif

	if (l0->first == NULL) {

#ifndef NDEBUG
		assertion(l0->next == NULL);
#endif

		if (l1->first == NULL) {

#ifndef NDEBUG
			assertion(l1->next == NULL);
#endif

			return AMARA_BOOLEAN_TRUE;
		}

		return AMARA_BOOLEAN_FALSE;
	}

	return stt_expressions_simple_list_equality_inner(l0, l1);
}
