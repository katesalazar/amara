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
 * src/rtg/rtg_where_value_binding.c: Amara run time graph _where_ value
 * binding.
 */

#include "../macros.h"

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `void * amara_malloc(size_t)`. */
#include "../mmm/allocator.h"

/*   For `void stt_where_value_binding_assert_purely_dice(const
 * stt_where_value_binding * this)` and `void
 * stt_where_value_binding_assert_purely_conditional(const
 * stt_where_value_binding * this)`. */
#include "../stt/stt_where_value_binding.h"

/*   For own definitions. */
#include "rtg_where_value_binding.h"

#if defined AMARA_USE_STD_C89
#define ALLOCATE_rtg_where_value_binding_out_of_stt_where_value_binding_ret amara_malloc(sizeof(rtg_where_value_binding_out_of_stt_where_value_binding_ret))
#define ALLOCATE_rtg_where_value_binding amara_malloc(sizeof(rtg_where_value_binding))
#elif defined AMARA_USE_STD_CXX98
#define ALLOCATE_rtg_where_value_binding (rtg_where_value_binding *) amara_malloc(sizeof(rtg_where_value_binding))
#else
#define ALLOCATE_rtg_where_value_binding PREPROCESSOR_FATAL
#endif

rtg_where_value_binding *
rtg_where_value_binding_copy_constructor(
		const rtg_where_value_binding * where_value_binding_)
{
#ifndef NDEBUG
	amara_boolean equality_;
#endif

	rtg_where_value_binding * returning_;

#ifndef NDEBUG
	assertion(where_value_binding_ != NULL);
	assertion(where_value_binding_->value_name_ != NULL);
	assertion(where_value_binding_->value_expression_ != NULL);
	assertion(where_value_binding_->value_expression_->type_ !=
			RTG_EXPRESSION_TYPE_INVALID);
#endif

	returning_ = ALLOCATE_rtg_where_value_binding;
	forced_assertion(returning_ != NULL);

	returning_->value_name_ = amara_string_copy_constructor(
			where_value_binding_->value_name_);
#ifndef NDEBUG
	assertion(returning_->value_name_ != NULL);
	assertion(returning_->value_name_->value_ != NULL);
	equality_ = amara_string_equality(
			returning_->value_name_,
			where_value_binding_->value_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
#endif

	returning_->value_expression_ = rtg_expression_copy_constructor(
			where_value_binding_->value_expression_);
#ifndef NDEBUG
	assertion(returning_->value_expression_ != NULL);
	assertion(returning_->value_expression_->type_ ==
			where_value_binding_->value_expression_->type_);
#endif

	return returning_;
}

void
rtg_where_value_binding_destructor(
		rtg_where_value_binding * where_value_binding_)
{
#ifndef NDEBUG
	assertion(where_value_binding_ != NULL);
#endif

	/*

	if (where_value_binding_->type_ ==
			RTG_WHERE_VALUE_BINDING_TYPE_INVALID) {

#ifndef NDEBUG
		assertion(where_value_binding_->value_name_ == NULL);
		assertion(where_value_binding_->value_expression_ == NULL);
#endif
	} else {

	*/

#ifndef NDEBUG
	assertion(where_value_binding_->value_name_ != NULL);
	assertion(where_value_binding_->value_expression_ != NULL);
#endif

		amara_string_destructor(where_value_binding_->value_name_);
		rtg_expression_destructor(
				where_value_binding_->value_expression_);

	/*

	}

	*/

	free(where_value_binding_);
}

#ifndef NDEBUG

void
rtg_where_value_binding_assert_healthy(
		const rtg_where_value_binding * where_value_binding_)
{
	assertion(where_value_binding_ != NULL);
	amara_string_assert_healthy(where_value_binding_->value_name_);
	rtg_expression_assert_healthy(where_value_binding_->value_expression_);
}

#endif

rtg_where_value_binding_out_of_stt_where_value_binding_ret *
rtg_where_value_binding_out_of_stt_where_value_binding(
		const stt_where_value_binding * where_value_binding)
{
	rtg_where_value_binding_out_of_stt_where_value_binding_ret * returning_;
	rtg_expression_out_of_stt_expression_ret * rtg_exp_ret_;
	rtg_where_value_binding * returning_sub_;

	assertion(where_value_binding != NULL);
	assertion(where_value_binding->value_name_ != NULL);
	assertion(where_value_binding->value_name_->value_ != NULL);
	assertion(where_value_binding->value_expression_ != NULL);
	assertion(where_value_binding->value_expression_->type_ != STT_EXPRESSION_TYPE_INVALID);

	returning_ = ALLOCATE_rtg_where_value_binding_out_of_stt_where_value_binding_ret;
	forced_assertion(returning_ != NULL);

	returning_sub_ = ALLOCATE_rtg_where_value_binding;
	forced_assertion(returning_sub_ != NULL);

	returning_sub_->value_name_ = amara_string_copy_constructor(where_value_binding->value_name_);

	/*

	returning_->value_expression_ = rtg_expression_default_constructor();

	if (where_value_binding_->value_expression_->type_ ==
			STT_EXPRESSION_TYPE_DICE) {

		stt_expression_assert_clean_dice(
				where_value_binding_->value_expression_*//*->sub_dice_*//*);*/

		/*
		returning_->value_expression_->sub_dice_ =
				rtg_expression_sub_dice_out_of_stt_expression_sub_dice(
						where_value_binding_->value_expression_->sub_dice_);

		returning_->value_expression_->type_ =
				RTG_EXPRESSION_TYPE_DICE;
		*/

	/*

		fixme
		rtg_expression_set_dice(;
	} else {
		assertion(where_value_binding_->value_expression_->type_ ==
				STT_EXPRESSION_TYPE_CONDITIONAL);

		stt_expression_assert_clean_conditional(
				where_value_binding_->value_expression_*//*->sub_conditional_*//*);

	*/

		/*
		returning_->value_expression_->sub_conditional_ =
				rtg_expression_sub_conditional_out_of_stt_expression_sub_conditional(
						where_value_binding_->value_expression_->sub_conditional_);

		returning_->value_expression_->type_ =
				RTG_EXPRESSION_TYPE_CONDITIONAL;
		*/

	/*

		fixme
		;
	}

	*/

	rtg_exp_ret_ = rtg_expression_out_of_stt_expression(where_value_binding->value_expression_);
#ifndef NDEBUG
	assertion(rtg_exp_ret_->status ==
			RTG_EXPRESSION_OUT_OF_STT_EXPRESSION_RET_STATUS_SUCCESS);
	assertion(rtg_exp_ret_->expression != NULL);
#endif

	returning_sub_->value_expression_ = rtg_exp_ret_->expression;
	rtg_exp_ret_->expression = NULL;
	rtg_expression_out_of_stt_expression_ret_destructor(rtg_exp_ret_);

	returning_->where_value_binding = returning_sub_;
	returning_->error_messages = NULL;
	returning_->status = RTG_WHERE_VALUE_BINDING_OUT_OF_STT_WHERE_VALUE_BINDING_RET_STATUS_SUCCESS;
	return returning_;
}
