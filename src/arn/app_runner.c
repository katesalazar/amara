/*
 * Copyright 2018-2019 Mercedes Catherine Salazar
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
 * src/arn/app_runner.c: Amara applications runtime applications runner.
 */

/* XXX */
#define __AMARA__POSIX

#ifdef __AMARA__POSIX
#include <unistd.h>
#endif

/*   For `int printf(const char *, ...)`, and for
 * `FILE * fopen(const char * pathname, const char * mode)`. */
#include <stdio.h>

/*   For `void free(void * ptr)`. */
#include <stdlib.h>

/*   For `size_t strlen(const char * s)`. */
#include <string.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `unsigned char acquire_dir(const char *)`. */
#include "../prs/persistence.h"

/*   For `rtg_application`. */
#include "../rtg/rtg_application.h"

/*   For `rtg_doc`. */
#include "../rtg/rtg_doc.h"

/*   For `rtg_execution_requests_simple_list`. */
#include "../rtg/rtg_execution_requests_simple_list.h"

/*   For `rtg_named_function`. */
#include "../rtg/rtg_named_function.h"

/*   For `rtg_operation`. */
#include "../rtg/rtg_operation.h"

/*   For `rtg_operations_simple_list`. */
#include "../rtg/rtg_operations_simple_list.h"

/*   For `st_node`. */
#include "../stt/stt_node.h"

/*   For `arn_values_fixed_list`. */
#include "arn_values_fixed_list.h"

/*   For `arn_values_simple_list`. */
#include "arn_values_simple_list.h"
/* #include "arn_variables_simple_list.h" */

/*   For definitions. */
#include "app_runner.h"

#define MAIN_NAME "main.minia"

unsigned char
run_app_dir_exists(const char * app_name)
__attribute__((warn_unused_result))
;

unsigned char
run_app_main_doc_exists(
		const char * app_name, const FILE * main_doc_descriptor)
__attribute__((warn_unused_result))
;

unsigned char
run_app(const char * app_name)
{
	unsigned char acquire_dir_return_status_;
	unsigned char inner_status_;
#ifdef __AMARA__POSIX
	char * cwd_buffer_;
	char * getcwd_return_;
#endif

#ifdef __AMARA__POSIX
	cwd_buffer_ = malloc(4096);
	forced_assertion(cwd_buffer_ != NULL);
	getcwd_return_ = getcwd(cwd_buffer_, 3072);

#ifdef DUMP_FLOW_TO_STDERR
	printf("cwd: %s\n", getcwd_return_);
	printf("cwd: %s\n", cwd_buffer_);
#endif

	forced_assertion(getcwd_return_ == cwd_buffer_);

    /* XXX could react differently depending on the value of cwd?
     * XXX /Users/uprego/Desktop/dat/not_backed_up/own/github_katesalazar/amara
     * XXX vs
     * XXX /Users/uprego/Library/Developer/Xcode/DerivedData/amara-crvidgitfstppwaorggtbfqtzsnb/Build/Products/Debug
     */
    if (strstr(cwd_buffer_, "/Library/Developer/Xcode/DerivedData/") != NULL) {
		printf("%s\n", app_name);  /* FIXME if the app_name is a relative path, it's going to be most probably wrong. So if this is a test, it arguably can be simply ignored. If the path is absolute, it's going to be right, probably. */
	} else {
		/*   Not using Xcode. On GNU/Linux, probably? */
	}
#endif

	acquire_dir_return_status_ = 0x00;
	printf("Running app '%s'...\n", app_name);
	acquire_dir_return_status_ = acquire_dir(app_name);
	if (acquire_dir_return_status_ ==
			PERSISTENCE_ACQUIRE_DIR_ERR_DIR_DOES_NOT_EXIST) {
		printf("An error happened while accessing the dir '%s'. ",
				app_name);
		printf("The directory does not exist.\n");
		return APP_RUNNER_RUN_APP_RET_ERROR_DIR_DOES_NOT_EXIST;
	}
	inner_status_ = run_app_dir_exists(app_name);
	return inner_status_;
}

unsigned char
run_app_dir_exists(const char * app_name)
{
	unsigned char app_name_len_;
	const char * path_to_main_;
	const char * appended_;
	unsigned char must_append_slash_;
	unsigned char path_to_main_len_;
	FILE * main_doc_descriptor_;
	unsigned char inner_status_;
	app_name_len_ = strlen(app_name);
	assertion(app_name_len_ < 0x7F);
	if (app_name[app_name_len_ - 1] == '/') {
		must_append_slash_ = 0x00;
	} else {
		must_append_slash_ = 0xFF;
	}
	appended_ = (const char *) malloc(sizeof(MAIN_NAME) + 1);
	forced_assertion(appended_ != NULL);
	strcpy((char *) appended_, MAIN_NAME);
	path_to_main_len_ = app_name_len_ + (must_append_slash_ ? 1 : 0) +
			strlen(appended_);
	path_to_main_ = (const char *) malloc(path_to_main_len_ + 1);
	strcpy((char *) path_to_main_, app_name);
	strcat((char *) path_to_main_, must_append_slash_ ? "/" : "");
	strcat((char *) path_to_main_, appended_);
	free((char *) appended_);
	appended_ = NULL;
	main_doc_descriptor_ = fopen(path_to_main_, "r");
	if (main_doc_descriptor_ == NULL) {
		free((char *) path_to_main_);
		return APP_RUNNER_RUN_APP_RET_ERROR_DOC_DOES_NOT_EXIST;
	}
	inner_status_ = run_app_main_doc_exists(
			app_name, main_doc_descriptor_);
	assertion(path_to_main_ != NULL);
	free((char *) path_to_main_);
	assertion(inner_status_ == 0x00);
	return 0x00;
}

stt_node *
minia_bison_main(FILE * file)
__attribute__((warn_unused_result))
;

unsigned char
run_app_main_doc_exists(
		const char * app_name, const FILE * main_doc_descriptor)
{
	stt_node * minia_bison_main_ret_;
	look_for_undefined_labels_ret * look_for_undefined_labels_ret_;
	process_rtg_doc_execution_requests_ret * process_rtg_doc_execution_requests_ret_;
	char_arrays_simple_list * ptr_;
	rtg_doc_out_of_stt_doc_ret * rtg_doc_out_of_stt_doc_ret_;
	assertion(main_doc_descriptor != NULL);
	assertion(app_name != NULL);

	minia_bison_main_ret_ = minia_bison_main((FILE *) main_doc_descriptor);
	assertion(minia_bison_main_ret_ != NULL);

	dump_syntax_tree(minia_bison_main_ret_);

	look_for_undefined_labels_ret_ =
			look_for_undefined_labels(minia_bison_main_ret_);

	if (look_for_undefined_labels_ret_->status !=
			LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_OK) {
		assertion(look_for_undefined_labels_ret_->status ==
				LOOK_FOR_UNDEFINED_LABELS_RET_STATUS_ERROR);
		fprintf(stderr, "error: undefined labels exist\n");
		fprintf(stderr, "%s:%u - look_for_undefined_labels_ret_->status: %u\n",
				__FILE__, __LINE__,
				look_for_undefined_labels_ret_->status);
		ptr_ = look_for_undefined_labels_ret_->messages;
		while (ptr_ != NULL) {
#ifdef DUMP_FLOW_TO_STDERR
			fprintf(stderr, "%s\n", ptr_->first);
#endif
			ptr_ = ptr_->next;
		}
		look_for_undefined_labels_ret_destructor(
				look_for_undefined_labels_ret_);
		look_for_undefined_labels_ret_ = NULL;
		return APP_RUNNER_RUN_APP_RET_ERROR_MALFORMED_DOC;
	}

	/*   If there were no undefined labels, defined labels
	 * have already been used to help all necessary pointer
	 * resolutions. */
	look_for_undefined_labels_ret_destructor(
			look_for_undefined_labels_ret_);
	look_for_undefined_labels_ret_ = NULL;

	/*   Now it is known there are no missing labels, ask for a run
	 * time ready graph where all labels (currently, only function
	 * names and application names, but not yet variable identifiers
	 * or type analysis) have been turned to entity pointers. */
	rtg_doc_out_of_stt_doc_ret_ =
			rtg_doc_out_of_stt_doc(minia_bison_main_ret_);

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "app_runner:225\n");
#endif

	forced_assertion(rtg_doc_out_of_stt_doc_ret_->status ==
			RTG_DOC_OUT_OF_STT_DOC_RET_STATUS_SUCCESS);

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "app_runner:230\n");
#endif

	process_rtg_doc_execution_requests_ret_ =
			process_rtg_doc_execution_requests(
					rtg_doc_out_of_stt_doc_ret_->doc);

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "app_runner:236\n");
#endif

	forced_assertion(process_rtg_doc_execution_requests_ret_->status ==
			PROCESS_RTG_DOC_EXECUTION_REQUESTS_RET_STATUS_SUCCESS);

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "app_runner:241\n");
#endif

	process_rtg_doc_execution_requests_ret_destructor(
			process_rtg_doc_execution_requests_ret_);
	process_rtg_doc_execution_requests_ret_ = NULL;

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "app_runner:247\n");
#endif

	rtg_doc_out_of_stt_doc_ret_destructor(rtg_doc_out_of_stt_doc_ret_);

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "app_runner:251\n");
#endif

	return APP_RUNNER_RUN_APP_RET_SUCCESS;
}

typedef arn_value arn_condition_evaluated_value
;

typedef arn_value arn_expression_evaluated_value
;

#ifndef NDEBUG

/**  Type check failsafe. */
amara_boolean
assert_types_compatible_for_condition_type_less_than(
		arn_value * left_hand_side_value_,
		arn_value * right_hand_side_value_)
;

#endif

#ifndef NDEBUG

amara_boolean
assert_types_compatible_for_condition_type_less_than(
		arn_value * left_hand_side_value_,
		arn_value * right_hand_side_value_)
{
	forced_assertion(left_hand_side_value_ != NULL);
	forced_assertion(left_hand_side_value_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);

	forced_assertion(right_hand_side_value_ != NULL);
	forced_assertion(right_hand_side_value_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);

	return AMARA_BOOLEAN_TRUE;
}

#endif

#ifndef NDEBUG

/**  Type check failsafe. */
amara_boolean
assert_types_compatible_for_condition_type_greater_than(
		arn_value * left_hand_side_value_,
		arn_value * right_hand_side_value_)
;

#endif

#ifndef NDEBUG

amara_boolean
assert_types_compatible_for_condition_type_greater_than(
		arn_value * left_hand_side_value_,
		arn_value * right_hand_side_value_)
{
	forced_assertion(left_hand_side_value_ != NULL);
	forced_assertion(left_hand_side_value_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);

	forced_assertion(right_hand_side_value_ != NULL);
	forced_assertion(right_hand_side_value_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);

	return AMARA_BOOLEAN_TRUE;
}

#endif

arn_value *
arn_value_out_of_rtg_literal_expression(
		const rtg_expression * expression)
__attribute__((warn_unused_result))
;

arn_value *
arn_value_out_of_rtg_literal_expression(
		const rtg_expression * expression)
{
	arn_value * returning_;

	forced_assertion(expression != NULL);

	forced_assertion(expression->type_ ==
			RTG_EXPRESSION_TYPE_NATURAL_LITERAL);

	returning_ = arn_value_default_constructor();
	forced_assertion(returning_ != NULL);

	arn_value_characterize_as_natural(returning_);

	arn_value_set_natural(
			returning_,
			expression->sub_natural_literal_->natural_literal_);

	return returning_;
}

arn_condition_evaluated_value *
evaluate_condition(const rtg_condition * condition,
                   const arn_values_simple_list * values)
__attribute__((warn_unused_result))
;

arn_condition_evaluated_value *
evaluate_condition(const rtg_condition * condition,
                   const arn_values_simple_list * values)
{
	amara_boolean condition_is_binary_;

	/**  This is a non owned reference. */
	amara_string * left_hand_side_requested_identifier_;

	/**  This is a non owned reference. */
	arn_value * left_hand_side_requested_identifier_value_;

	if (condition->type_ == RTG_CONDITION_TYPE_LESS_THAN) {

		condition_is_binary_ = AMARA_BOOLEAN_TRUE;
	} else {
		forced_assertion(condition->type_ ==
				RTG_CONDITION_TYPE_GREATER_THAN);

		condition_is_binary_ = AMARA_BOOLEAN_TRUE;
	}

	forced_assertion(condition_is_binary_ == AMARA_BOOLEAN_TRUE);

	forced_assertion(condition->left_hand_side_expression_ != NULL);
	forced_assertion(condition->left_hand_side_expression_->type_ ==
			RTG_EXPRESSION_TYPE_IDENTIFIER);

	left_hand_side_requested_identifier_ =
			condition->left_hand_side_expression_->sub_identifier_->identifier_;

	left_hand_side_requested_identifier_value_ =
			arn_values_simple_list_find_value_by_name_return_reference(
					values,
					left_hand_side_requested_identifier_);

	/* FIXME - must find the bounded value - there must be a way to find a bound value, if not, there should be no rtg condition ! */
	forced_assertion(values != NULL);
	forced_assertion(values->first != NULL);
	if (values->next != NULL) {
		forced_assertion(values->next->first != NULL);
	}

	forced_assertion(condition->right_hand_side_expression_ != NULL);
	forced_assertion(condition->right_hand_side_expression_->type_ ==
			RTG_EXPRESSION_TYPE_NATURAL_LITERAL);

	if (condition->type_ == RTG_CONDITION_TYPE_LESS_THAN) {

		/**  Types are guaranteed to be compatible by semantic analysis
		 * (undertaken by the `stt` to `rtg` stage). This is failsafe
		 * check. */
#ifndef NDEBUG
		assert_types_compatible_for_condition_type_less_than(
				left_hand_side_requested_identifier_value_,
				arn_value_out_of_rtg_literal_expression(
						condition->right_hand_side_expression_));
#endif

		forced_assertion(left_hand_side_requested_identifier_value_->type_ ==
				ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);

		forced_assertion(condition->right_hand_side_expression_->type_ ==
				RTG_EXPRESSION_TYPE_NATURAL_LITERAL);

		if (naturals_less_than(
				left_hand_side_requested_identifier_value_->natural_,
				condition->right_hand_side_expression_->sub_natural_literal_->natural_literal_)) {

			return arn_value_out_of_amara_boolean(
					AMARA_BOOLEAN_TRUE);
		} else {

			return arn_value_out_of_amara_boolean(
					AMARA_BOOLEAN_FALSE);
		}
	} else {
		forced_assertion(condition->type_ ==
				RTG_CONDITION_TYPE_GREATER_THAN);

		/**  Types are guaranteed to be compatible by semantic analysis
		 * (undertaken by the `stt` to `rtg` stage). This is failsafe
		 * check. */
#ifndef NDEBUG
		assert_types_compatible_for_condition_type_greater_than(
				left_hand_side_requested_identifier_value_,
				arn_value_out_of_rtg_literal_expression(
						condition->right_hand_side_expression_));
#endif

		forced_assertion(left_hand_side_requested_identifier_value_->type_ ==
				ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);

		forced_assertion(condition->right_hand_side_expression_->type_ ==
				RTG_EXPRESSION_TYPE_NATURAL_LITERAL);

		if (naturals_greater_than(
				left_hand_side_requested_identifier_value_->natural_,
				condition->right_hand_side_expression_->sub_natural_literal_->natural_literal_)) {

			return arn_value_out_of_amara_boolean(
					AMARA_BOOLEAN_TRUE);
		} else {

			return arn_value_out_of_amara_boolean(
					AMARA_BOOLEAN_FALSE);
		}
	}
}

arn_expression_evaluated_value *
evaluate_expression(const rtg_expression * expression,
                    const arn_values_simple_list * values/*,
                    const arn_variables_simple_list * variables*/)
__attribute__((warn_unused_result))
;

arn_expression_evaluated_value *
evaluate_expression(const rtg_expression * expression,
                    const arn_values_simple_list * values/*,
                    const arn_variables_simple_list * variables*/)
{
	/**  The expression is evaluated to some value, and this is the
	 * local variable where the value is stored before returning. */
	arn_expression_evaluated_value * returning_;
	arn_condition_evaluated_value * condition_value_;

	returning_ = NULL;

	if (expression->type_ == RTG_EXPRESSION_TYPE_STRING_LITERAL) {

#ifndef NDEBUG
		assertion(expression->sub_string_literal_ != NULL);
		assertion(expression->sub_string_literal_->string_literal_ !=
				NULL);
		assertion(expression->sub_string_literal_->string_literal_->value_ !=
				NULL);
#endif

		returning_ = arn_value_default_constructor();
#ifndef NDEBUG
		assertion(returning_ != NULL);
		assertion(returning_->type_ == ARN_VALUE_TYPE_INVALID);
#endif

		arn_value_characterize_as_string(returning_);
#ifndef NDEBUG
		assertion(returning_->type_ ==
				ARN_VALUE_TYPE_ANONYMOUS_UNASSIGNED_STRING);
		assertion(returning_->string_ == NULL);
#endif

		arn_value_set_string(
				returning_,
				expression->sub_string_literal_->string_literal_);
#ifndef NDEBUG
		assertion(returning_->type_ ==
				ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING);
		assertion(returning_->string_was_moved == AMARA_BOOLEAN_FALSE);
		assertion(returning_->string_ != NULL);
		assertion(returning_->string_->value_ != AMARA_BOOLEAN_FALSE);
#endif
	} else if (expression->type_ == RTG_EXPRESSION_TYPE_IDENTIFIER) {

		forced_assertion_two(expression->sub_identifier_ != NULL,
				"app_runner.c: 545");
		forced_assertion_two(expression->sub_identifier_->identifier_ != NULL,
				"app_runner.c: 546");

		forced_assertion_two(values != NULL,
				"identifier binding not found");

		forced_assertion_two(values->first != NULL,
				"identifier binding not found");
		forced_assertion_two(values->first->name_ != NULL,
				"identifier binding not found");
		forced_assertion_two(expression->sub_identifier_ != NULL,
				"app_runner.c: 552");

		if (amara_strings_equality(
				values->first->name_,
				expression->sub_identifier_->identifier_) ==
						AMARA_BOOLEAN_TRUE) {

			/* XXX Maybe better a reference? */
			return arn_value_copy_constructor(values->first);
		} else {

			/* XXX Maybe better an iterative search? */
			return evaluate_expression(expression, values->next);
		}
	} else {
#ifndef NDEBUG
		forced_assertion(expression->type_ ==
				RTG_EXPRESSION_TYPE_CONDITIONAL);
#endif

		forced_assertion(expression->sub_conditional_ != NULL);
		forced_assertion(expression->sub_conditional_->if_ != NULL);
		forced_assertion(expression->sub_conditional_->if_->next_if_ ==
				NULL);
		forced_assertion(expression->sub_conditional_->if_->expression_else_ !=
				NULL);
		forced_assertion(expression->sub_conditional_->if_->expression_then_ !=
				NULL);
		forced_assertion(expression->sub_conditional_->if_->condition_ !=
				NULL);

		condition_value_ = evaluate_condition(
				expression->sub_conditional_->if_->condition_,
				values);

		forced_assertion(condition_value_->type_ = ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_BOOLEAN);
		forced_assertion(condition_value_->boolean_ != NULL);

		if ((* (condition_value_->boolean_)) == AMARA_BOOLEAN_TRUE) {

			return evaluate_expression(
					expression->sub_conditional_->if_->expression_then_,
					values);
		} else {
			forced_assertion((* (condition_value_->boolean_)) ==
					AMARA_BOOLEAN_FALSE);

			return evaluate_expression(
					expression->sub_conditional_->if_->expression_else_,
					values);
		}
	}

	return returning_;
}

typedef arn_value arn_operation_returned_value
;

arn_operation_returned_value *
run_operation(const rtg_operation * operation,
              const arn_values_simple_list * values/*,
              const arn_variables_simple_list * variables*/)
__attribute__((warn_unused_result))
;

arn_operation_returned_value *
run_operation(const rtg_operation * operation,
              const arn_values_simple_list * values/*,
              const arn_variables_simple_list * variables*/)
{
	/*   Copy of the parameter `values` in a local variable, because
	 * not all list implementations hold the pointer to their head. */
	arn_values_simple_list * values_;

	unsigned short natural_read_;

	int items_read_ct_;

	/**  In case one `arn_value` has to be searched in the `values`
	 * `arn_values_simple_list` of known values at this scope. */
	arn_value * value_;

	/**  In case the operation includes the evaluation of an
	 * expression (most likely will), this stores the value that
	 * expression is evaluated to. */
	arn_expression_evaluated_value * expression_evaluated_value_;

	/**  In case the operation includes the interpretation of
	 * another operation, this stores the returned value by that
	 * nested operation. */
	/*
	arn_operation_returned_value * operation_returned_value_;
	*/

	/*   In case this operation must return some value, this is
	 * where the value is stored before returning. */
	/*
	arn_operation_returned_value * returning_;
	*/

#ifndef NDEBUG
	amara_string * operation_type_as_string_;
#endif

	fprintf(stderr, "----> %s:%u (%s)\n", __FILE__, __LINE__,
			"void run_operation(const operation *)");

	values_ = (arn_values_simple_list *) values;

	if (operation->type_ == RTG_OPERATION_TYPE_PRINT /*||
			operation->type_ == RTG_OPERATION_TYPE_PRINT_NO_CRLF*/) {

		assertion(operation->args_ != NULL);
		assertion(rtg_operation_args_simple_list_length(
				operation->args_) == 1);
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->first->type_ !=
				RTG_OPERATION_ARG_TYPE_INVALID);
		if (operation->args_->first->type_ ==
				RTG_OPERATION_ARG_TYPE_STRING_LITERAL) {
			assertion(operation->args_->first->string_literal_ !=
					NULL);
			assertion(operation->args_->first->string_literal_->value_ !=
					NULL);
			printf("%s", operation->args_->first->string_literal_->value_);
		} else if (operation->args_->first->type_ ==
					RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL) {
			assertion(operation->args_->first->natural_literal_ !=
					NULL);
			assertion(operation->args_->first->natural_literal_->value_ !=
					NULL);
			printf("%s", operation->args_->first->natural_literal_->value_);
		} else if (operation->args_->first->type_ ==
					RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED) {
			assertion(operation->args_->first->identifier_ != NULL);
			assertion(operation->args_->first->identifier_->value_ !=
					NULL);
			value_ = arn_values_simple_list_find_value_by_name_return_reference(
					values_,
					operation->args_->first->identifier_);
			if (value_ == NULL) {
				fprintf(stderr, "%s\n",
				        operation->args_->first->identifier_->value_);
			}
			assertion(value_ != NULL); /* XXX it might not be, and then must raise semantic error */
			fprintf(stderr, "%u\n", value_->type_);
			/******* FIXME this assertion below is failing...... */
			assertion(value_->type_ ==
						ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL 
					|| value_->type_ ==
							ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL); /* XXX might be string literal, other number class, etc. */
			/******* FIXME this assertion above is failing...... */
			natural_assert_validity(value_->natural_);
			printf("%s", value_->natural_->raw_->value_);
		/*
		} else if (operation->args_->first->type_ ==
					RTG_OPERATION_ARG_TYPE_OPERATION) {

			operation_returned_value_ = run_operation(
					operation->args_->first->operation_,
					values_);
#ifndef NDEBUG
			assertion(operation_returned_value_ != NULL);
#endif
			if (operation_returned_value_->type_ ==
					ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL) {
#ifndef NDEBUG
				assertion(operation_returned_value_->natural_ !=
						NULL);
				natural_assert_validity(
						operation_returned_value_->natural_);
#endif
				printf("%s",
				       operation_returned_value_->natural_->raw_->value_);
			} else {
#ifndef NDEBUG
				assertion(operation_returned_value_->type_ ==
						ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING);
#endif

#ifndef NDEBUG
				assertion(operation_returned_value_->string_ !=
						NULL);
				assertion(operation_returned_value_->string_->value_ !=
						NULL);
#endif
				printf("%s",
				       operation_returned_value_->string_->value_);
			}
		*/
		} else if (operation->args_->first->type_ ==
				RTG_OPERATION_ARG_TYPE_EXPRESSION) {

			expression_evaluated_value_ = evaluate_expression(
					operation->args_->first->expression_,
					values);
			forced_assertion(expression_evaluated_value_ != NULL);

#ifndef NDEBUG
			/*
			assertion(expression_evaluated_value_->type_ ==
					ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING);
			*/
#endif

			if (expression_evaluated_value_->type_ ==
					ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING) {

#ifndef NDEBUG
			assertion(expression_evaluated_value_->string_ != NULL);
			assertion(expression_evaluated_value_->string_->value_ !=
					NULL);
#endif
			printf("%s",
			       expression_evaluated_value_->string_->value_);
			} else {
				forced_assertion_two(expression_evaluated_value_->type_ == ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL,
						"unexpected behavior, app_runner.c: 761");

#ifndef NDEBUG
				assertion_two(expression_evaluated_value_->natural_ != NULL,
						"app_runner.c: 764");
				assertion_two(expression_evaluated_value_->natural_->raw_ != NULL,
						"app_runner.c: 765");
				assertion_two(expression_evaluated_value_->natural_->raw_->value_ != NULL,
						"app_runner.c: 766");
#endif
				printf("%s",
				       expression_evaluated_value_->natural_->raw_->value_);
			}
		}
		forced_assertion(operation->type_ == RTG_OPERATION_TYPE_PRINT);
		/*
		if (operation->type_ == RTG_OPERATION_TYPE_PRINT) {
		*/
			/*
			printf("\n");
			*/
		/*
		} else {
			assertion(operation->type_ ==
					RTG_OPERATION_TYPE_PRINT_NO_CRLF);
		}
		*/
		/* XXX return the printed value? a description of the operation ran? */
	} else if (operation->type_ == RTG_OPERATION_TYPE_PRINT_CRLF) {
		assertion(operation->args_ != NULL);
		assertion(rtg_operation_args_simple_list_length(
				operation->args_) == 0);
		assertion(operation->args_->first == NULL);
		assertion(operation->args_->next == NULL);
		printf("\n");
		/* XXX return the printed value? a description of the operation ran? */
	} else if (operation->type_ ==
			RTG_OPERATION_TYPE_READ_NATURAL_TO_VALUE) {
		assertion(operation->args_ != NULL);
		assertion(rtg_operation_args_simple_list_length(
				operation->args_) == 1);
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->next == NULL);
		assertion(operation->args_->first->type_ ==
				RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED);
		/*
		assert_variable_is_known(
				variables,
				operation->args_->first->identifier_);
		*/
		fflush(stdout); /* XXX this is a bit of an invasion. maybe better provide a scripting level flush, or (probably best) flush right after printing. */
		items_read_ct_ = scanf("%hu", & natural_read_);
		assertion(items_read_ct_ == 1);
		values_ = arn_values_simple_list_assign_natural_out_of_unsigned_short(
				values_,
				operation->args_->first->identifier_,
				natural_read_);
		/* XXX return the read value? the identifier? */

	/*
	} else if (operation->type_ == RTG_OPERATION_TYPE_SUBSTRACTION) {
		assertion(operation->args_ != NULL);
		assertion(rtg_operation_args_simple_list_length(
				operation->args_) == 2);
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->first->type_ == RTG_OPERATION_ARG_TYPE_IDENTIFIER_TO_BE_RESOLVED);
		assertion(operation->args_->first->identifier_ != NULL);
		assertion(operation->args_->first->identifier_->value_ != NULL);
		assertion(operation->args_->next != NULL);
		assertion(operation->args_->next->first != NULL);
		assertion(operation->args_->next->first->type_ == RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL);
	*/

		/* FIXME resolve the identifier actually */
	/*
		fprintf(stderr, "%s\n", operation->args_->first->identifier_->value_);
		assertion(!strcmp(operation->args_->first->identifier_->value_, "i_fahrenheit"));
		assertion(values_ != NULL);
		assertion(values_->first != NULL);
		assertion(values_->first->name_ != NULL);
		assertion(values_->first->name_->value_ != NULL);
		assertion(!strcmp(
				values_->first->name_->value_,
				"i_fahrenheit"));
		assertion(values_->first->type_ ==
				ARN_VALUE_TYPE_NAMED_ASSIGNED_NATURAL);
		assertion(values_->first->natural_ != NULL);
		assertion(values_->first->natural_->raw_ != NULL);
		assertion(values_->first->natural_->raw_->value_ != NULL);
		assertion(!strcmp(values_->first->natural_->raw_->value_, "99"));
	*/

		/* FIXME DO THE SUBSTRACTION ACTUALLY
		operation_returned_value_->natural_->raw_->value_
		*/
	/*
		fprintf(stderr, "%s\n", operation->args_->next->first->natural_literal_->value_);
		assertion(!strcmp(operation->args_->next->first->natural_literal_->value_, "32"));
		returning_ = arn_value_default_constructor();
		returning_->natural_ = natural_default_constructor();
		returning_->natural_->raw_ = amara_string_exhaustive_constructor("67");
		returning_->type_ = ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL;
		return returning_;

	} else if (operation->type_ == RTG_OPERATION_TYPE_MULTIPLICATION) {
		assertion(operation->args_ != NULL);
		assertion(rtg_operation_args_simple_list_length(
				operation->args_) == 2);
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->first->type_ == RTG_OPERATION_ARG_TYPE_OPERATION);
		assertion(operation->args_->next != NULL);
		assertion(operation->args_->next->first != NULL);
		assertion(operation->args_->next->first->type_ == RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL);
	*/

		/*   Run the nested operation. */
	/*
		operation_returned_value_ = run_operation(
				operation->args_->first->operation_, values_);
		assertion(operation_returned_value_ != NULL);
		assertion(operation_returned_value_->type_ ==
				ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);
		assertion(operation_returned_value_->natural_ != NULL);
		natural_assert_validity(operation_returned_value_->natural_);
	*/

		/* FIXME DO THE MULTIPLICATION ACTUALLY
		operation_returned_value_->natural_->raw_->value_
		*/
	/*
		fprintf(stderr, "%s\n", operation_returned_value_->natural_->raw_->value_);
		fprintf(stderr, "%s\n", operation->args_->next->first->natural_literal_->value_);
		assertion(!strcmp(operation_returned_value_->natural_->raw_->value_, "67"));
		assertion(!strcmp(operation->args_->next->first->natural_literal_->value_, "5"));
		returning_ = arn_value_default_constructor();
		returning_->natural_ = natural_default_constructor();
		returning_->natural_->raw_ = amara_string_exhaustive_constructor("335");
		returning_->type_ = ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL;
		return returning_;

	} else if (operation->type_ == RTG_OPERATION_TYPE_DIVISION) {
		assertion(operation->args_ != NULL);
		assertion(rtg_operation_args_simple_list_length(
				operation->args_) == 2);
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->first->type_ == RTG_OPERATION_ARG_TYPE_OPERATION);
		assertion(operation->args_->next != NULL);
		assertion(operation->args_->next->first != NULL);
		assertion(operation->args_->next->first->type_ == RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL);
	*/

		/*   Run the nested operation. */
	/*
		operation_returned_value_ = run_operation(
				operation->args_->first->operation_, values_);
		assertion(operation_returned_value_ != NULL);
		assertion(operation_returned_value_->type_ ==
				ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);
		assertion(operation_returned_value_->natural_ != NULL);
		natural_assert_validity(operation_returned_value_->natural_);
	*/

		/* FIXME DO THE DIVISION ACTUALLY
		operation_returned_value_->natural_->raw_->value_
		*/
	/*
		fprintf(stderr, "%s\n", operation_returned_value_->natural_->raw_->value_);
		fprintf(stderr, "%s\n", operation->args_->next->first->natural_literal_->value_);
		assertion(!strcmp(operation_returned_value_->natural_->raw_->value_, "335"));
		assertion(!strcmp(operation->args_->next->first->natural_literal_->value_, "9"));
		returning_ = arn_value_default_constructor();
		returning_->natural_ = natural_default_constructor();
		returning_->natural_->raw_ = amara_string_exhaustive_constructor("37");
		returning_->type_ = ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL;
		return returning_;

	} else if (operation->type_ ==
			RTG_FAKE_OPERATION_TYPE_RESOLVE_TYPE_OF_EXPRESSION) {
		assertion(operation->args_ != NULL);
		assertion(rtg_operation_args_simple_list_length(
				operation->args_) == 1);
		assertion(operation->args_->first != NULL);
		assertion(operation->args_->first->type_ == RTG_OPERATION_ARG_TYPE_OPERATION);
		assertion(operation->args_->next == NULL);
	*/

		/*   Run the nested operation. */
	/*
		operation_returned_value_ = run_operation(
				operation->args_->first->operation_, values_);
		assertion(operation_returned_value_ != NULL);
		assertion(operation_returned_value_->type_ ==
				ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);
		assertion(operation_returned_value_->natural_ != NULL);
		natural_assert_validity(operation_returned_value_->natural_);

		returning_ = arn_value_default_constructor();
		returning_->string_ =
				amara_string_exhaustive_constructor("natural");
		returning_->type_ = ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING;
		return returning_;
	*/

	} else {
		if (operation->type_ != RTG_OPERATION_TYPE_INVALID) {
			fprintf(stderr, "%u\n", operation->type_);
		}
#ifndef NDEBUG
		operation_type_as_string_ =
				rtg_operation_type_as_string(operation->type_);
		fprintf(stderr, "%s\n", operation_type_as_string_->value_);
		amara_string_destructor(operation_type_as_string_);
#endif
		assertion(operation->type_ == RTG_OPERATION_TYPE_INVALID); /* XXX missing the operation types arithmetic addition, substraction, multiplication, division... */
		printf("!!!\n");
	}
	return NULL; /* XXX */
}

typedef arn_value arn_named_function_returned_value
;

/**  Run a named function.
 *   @param function Named function to run.
 *   @param function_scope_values Values valid in this function's scope.
 *    param function_scope_variables Variables valid in this function's
 * scope.
 *   @see `void run_application(const rtg_application * application)`. */
arn_named_function_returned_value *
run_named_function(const rtg_named_function * function,
                   const arn_values_fixed_list * function_scope_values/*,
                   const arn_variables_simple_list * function_scope_variables*/)
__attribute__((warn_unused_result))
;

arn_named_function_returned_value *
run_named_function(const rtg_named_function * function,
                   const arn_values_fixed_list * function_scope_values/*,
                   const arn_variables_simple_list * function_scope_variables*/)
{
	const rtg_operations_simple_list * operations_ptr_;
	const rtg_where_value_bindings_simple_list * where_value_bindings_;
	const arn_values_fixed_list * where_values_;
	arn_values_simple_list * operation_scope_values_;
	arn_operation_returned_value * operation_returned_value_;

	fprintf(stderr, "----> %s:%u (%s)\n", __FILE__, __LINE__,
			"void run_function(const function *)");

	operation_returned_value_ = NULL;

	operations_ptr_ = function->operations_;

	where_value_bindings_ = function->where_value_bindings_;
	where_values_ = arn_values_fixed_list_out_of_rtg_where_value_bindings_simple_list(
			where_value_bindings_);
	operation_scope_values_ = arn_values_simple_list_default_constructor();

	/* XXX is this dangerous if theres no refcount? is it correct if shadowing is not allowed? */
	operation_scope_values_ =
			arn_values_simple_list_push_front_as_references_all_elements_of_arn_values_fixed_list(
					operation_scope_values_,
					function_scope_values);

	/* XXX is this dangerous if theres no refcount? is it correct if shadowing is not allowed? */
	operation_scope_values_ =
			arn_values_simple_list_push_front_as_references_all_elements_of_arn_values_fixed_list(
					operation_scope_values_,
					where_values_);

	while (operations_ptr_ != NULL) {

		/* operation_scope_values_ not correctly initialized? */
		operation_returned_value_ = run_operation(
				operations_ptr_->first,
				operation_scope_values_/*,
				function_scope_variables*/);
		operations_ptr_ = operations_ptr_->next;
	}
	return operation_returned_value_;
}

void
run_application(const rtg_application * application)
;

void
run_application(const rtg_application * application)
{
	const rtg_named_function * entry_point_function_;
	arn_values_fixed_list * global_values_scope_;
	arn_named_function_returned_value * entry_point_function_returned_value_;
	/* arn_variables_simple_list * variables_; */

#ifdef DUMP_FLOW_TO_STDERR
	fprintf(stderr, "----> %s:%u (%s)\n", __FILE__, __LINE__,
			"void run_application(const application *)");
#endif

	global_values_scope_ = arn_values_fixed_list_default_constructor();
	/* variables_ = arn_variables_simple_list_default_constructor(); */
	entry_point_function_ = application->entry_point_function_;
	entry_point_function_returned_value_ = run_named_function(
			entry_point_function_, global_values_scope_/*,
			variables_*/);

	/*
	assertion(entry_point_function_returned_value_ != NULL);
	assertion(entry_point_function_returned_value_->type_ ==
			ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);
	*/
	assertion(entry_point_function_returned_value_ == NULL);
}

void
process_rtg_doc_execution_requests_ret_destructor(
		process_rtg_doc_execution_requests_ret * process_rtg_doc_execution_requests_ret_)
{
	free(process_rtg_doc_execution_requests_ret_);
}

process_rtg_doc_execution_requests_ret *
process_rtg_doc_execution_requests(const rtg_doc * doc)
{
	process_rtg_doc_execution_requests_ret * ret_;
	rtg_execution_requests_simple_list * execution_requests_ptr_;

	ret_ = malloc(sizeof(process_rtg_doc_execution_requests_ret));
	forced_assertion(ret_ != NULL);
	ret_->status = PROCESS_RTG_DOC_EXECUTION_REQUESTS_RET_STATUS_INVALID;
	forced_assertion(doc != NULL);
	execution_requests_ptr_ = doc->execution_requests_;
	forced_assertion_two(doc->execution_requests_ != NULL, "abcdef");
	if (doc->execution_requests_->first != NULL) {
		forced_assertion_two(doc->execution_requests_->first != NULL,
				"cdefgh");
	while (execution_requests_ptr_ != NULL) {
		run_application(execution_requests_ptr_->first->application_);
		execution_requests_ptr_ = execution_requests_ptr_->next;
	}
	} else {
		forced_assertion_two(doc->execution_requests_->next == NULL,
				"fghijk");
	}
	ret_->status = PROCESS_RTG_DOC_EXECUTION_REQUESTS_RET_STATUS_SUCCESS;
	return ret_;
}
