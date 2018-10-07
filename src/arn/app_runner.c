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
 * src/arn/app_runner.c: Amara applications runtime applications runner.
 */

/*   For `uint_fast8_t`. */
#include <stdint.h>

/*   For `int printf(const char *, ...)`, and for
 * `FILE * fopen(const char * pathname, const char * mode)`. */
#include <stdio.h>

/*   For `void free(void * ptr)`. */
#include <stdlib.h>

/*   For `size_t strlen(const char * s)`. */
#include <string.h>

/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `uint_fast8_t acquire_dir(const char *)`. */
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

#include "arn_values_fixed_list.h"
/* #include "arn_values_simple_list.h" */
#include "arn_variables_simple_list.h"

/*   For definitions. */
#include "app_runner.h"

#define MAIN_NAME "main.minia"

uint_fast8_t
run_app_dir_exists(const char * app_name)
__attribute__((warn_unused_result))
;

uint_fast8_t
run_app_main_doc_exists(
		const char * app_name, const FILE * main_doc_descriptor)
__attribute__((warn_unused_result))
;

uint_fast8_t run_app(const char * app_name)
{
	uint_fast8_t acquire_dir_return_status_;
	uint_fast8_t inner_status_;
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

uint_fast8_t run_app_dir_exists(const char * app_name)
{
	uint_fast8_t app_name_len_;
	const char * path_to_main_;
	const char * appended_;
	uint_fast8_t must_append_slash_;
	uint_fast8_t path_to_main_len_;
	FILE * main_doc_descriptor_;
	uint_fast8_t inner_status_;
	app_name_len_ = strlen(app_name);
	assertion(app_name_len_ < 0x7F);
	if (app_name[app_name_len_ - 1] == '/') {
		must_append_slash_ = 0x00;
	} else {
		must_append_slash_ = 0xFF;
	}
	appended_ = (const char *) malloc(sizeof(MAIN_NAME) + 1);
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

uint_fast8_t
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
			fprintf(stderr, "%s\n", ptr_->first);
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

	assertion(rtg_doc_out_of_stt_doc_ret_->status ==
			RTG_DOC_OUT_OF_STT_DOC_RET_STATUS_SUCCESS);

	process_rtg_doc_execution_requests_ret_ =
			process_rtg_doc_execution_requests(
					rtg_doc_out_of_stt_doc_ret_->doc);

	assertion(process_rtg_doc_execution_requests_ret_->status ==
			PROCESS_RTG_DOC_EXECUTION_REQUESTS_RET_STATUS_SUCCESS);

	process_rtg_doc_execution_requests_ret_destructor(
			process_rtg_doc_execution_requests_ret_);
	process_rtg_doc_execution_requests_ret_ = NULL;

	rtg_doc_out_of_stt_doc_ret_destructor(rtg_doc_out_of_stt_doc_ret_);

	return APP_RUNNER_RUN_APP_RET_SUCCESS;
}

typedef arn_value arn_operation_returned_value
;

arn_operation_returned_value *
run_operation(
		const rtg_operation * operation,
		arn_values_fixed_list * values/*,
		const arn_variables_simple_list * variables*/)
__attribute__((warn_unused_result))
;

arn_operation_returned_value *
run_operation(
		const rtg_operation * operation,
		arn_values_fixed_list * values/*,
		const arn_variables_simple_list * variables*/)
{
	unsigned int natural_read_;
	int items_read_ct_;
	/**  In case one `arn_value` has to be searched in the `values`
	 * `arn_values_simple_list` of known values at this scope. */
	arn_value * value_;
	/**  In case the operation includes the interpretation of
	 * another operation, this stores the returned value by that
	 * nested operation. */
	arn_operation_returned_value * operation_returned_value_;
	/**  In case this operation must return some value, this is
	 * where the value is stored before returning. */
	arn_operation_returned_value * returning_;
#ifndef NDEBUG
	amara_string * operation_type_as_string_;
#endif
	fprintf(stderr, "----> %s:%u (%s)\n", __FILE__, __LINE__,
			"void run_operation(const operation *)");
	if (operation->type_ == RTG_OPERATION_TYPE_PRINT ||
			operation->type_ == RTG_OPERATION_TYPE_PRINT_NO_CRLF) {
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
			value_ = arn_values_fixed_list_find_value_by_name(
					values,
					operation->args_->first->identifier_);
			assertion(value_ != NULL); /* XXX it might not be, and then must raise semantic error */
			assertion(value_->type_ ==
					ARN_VALUE_TYPE_ASSIGNED_NATURAL); /* XXX might be string literal, other number class, etc. */
			natural_assert_validity(value_->natural_);
			printf("%s", value_->natural_->raw_->value_);
		} else {
			assertion(operation->args_->first->type_ ==
					RTG_OPERATION_ARG_TYPE_OPERATION);
			operation_returned_value_ = run_operation(
					operation->args_->first->operation_,
					values);
			assertion(operation_returned_value_ != NULL);
			if (operation_returned_value_->type_ ==
					ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL) {
				assertion(operation_returned_value_->natural_ != NULL);
				natural_assert_validity(
						operation_returned_value_->natural_);
				printf("%s",
				       operation_returned_value_->natural_->raw_->value_);
			} else {
				assertion(operation_returned_value_->type_ ==
						ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_STRING);
				assertion(operation_returned_value_->string_ != NULL);
				printf("%s", operation_returned_value_->string_->value_);
			}
		}
		if (operation->type_ == RTG_OPERATION_TYPE_PRINT) {
			/*
			printf("\n");
			*/
		} else {
			assertion(operation->type_ ==
					RTG_OPERATION_TYPE_PRINT_NO_CRLF);
		}
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
		items_read_ct_ = scanf("%u", & natural_read_);
		assertion(items_read_ct_ == 1);
		arn_values_fixed_list_assign_natural_out_of_unsigned_int(
				values,
				operation->args_->first->identifier_,
				natural_read_);
		/* XXX return the read value? the identifier? */

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

		/* FIXME resolve the identifier actually */
		fprintf(stderr, "%s\n", operation->args_->first->identifier_->value_);
		assertion(!strcmp(operation->args_->first->identifier_->value_, "i_fahrenheit"));
		assertion(values != NULL);
		assertion(values->first != NULL);
		assertion(values->first->name_ != NULL);
		assertion(values->first->name_->value_ != NULL);
		assertion(!strcmp(values->first->name_->value_, "i_fahrenheit"));
		assertion(values->first->type_ == ARN_VALUE_TYPE_ASSIGNED_NATURAL);
		assertion(values->first->natural_ != NULL);
		assertion(values->first->natural_->raw_ != NULL);
		assertion(values->first->natural_->raw_->value_ != NULL);
		assertion(!strcmp(values->first->natural_->raw_->value_, "99"));

		/* FIXME DO THE SUBSTRACTION ACTUALLY
		operation_returned_value_->natural_->raw_->value_
		*/
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

		/*   Run the nested operation. */
		operation_returned_value_ = run_operation(
				operation->args_->first->operation_, values);
		assertion(operation_returned_value_ != NULL);
		assertion(operation_returned_value_->type_ ==
				ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);
		assertion(operation_returned_value_->natural_ != NULL);
		natural_assert_validity(operation_returned_value_->natural_);

		/* FIXME DO THE MULTIPLICATION ACTUALLY
		operation_returned_value_->natural_->raw_->value_
		*/
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

		/*   Run the nested operation. */
		operation_returned_value_ = run_operation(
				operation->args_->first->operation_, values);
		assertion(operation_returned_value_ != NULL);
		assertion(operation_returned_value_->type_ ==
				ARN_VALUE_TYPE_ANONYMOUS_ASSIGNED_NATURAL);
		assertion(operation_returned_value_->natural_ != NULL);
		natural_assert_validity(operation_returned_value_->natural_);

		/* FIXME DO THE DIVISION ACTUALLY
		operation_returned_value_->natural_->raw_->value_
		*/
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

		/*   Run the nested operation. */
		operation_returned_value_ = run_operation(
				operation->args_->first->operation_, values);
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

arn_named_function_returned_value *
run_named_function(
		const rtg_named_function * function,
		arn_values_fixed_list * values/*,
		const arn_variables_simple_list * variables*/)
__attribute__((warn_unused_result))
;

arn_named_function_returned_value *
run_named_function(
		const rtg_named_function * function,
		arn_values_fixed_list * values/*,
		const arn_variables_simple_list * variables*/)
{
	const rtg_operations_simple_list * operations_ptr_;
	arn_operation_returned_value * operation_returned_value_;
	fprintf(stderr, "----> %s:%u (%s)\n", __FILE__, __LINE__,
			"void run_function(const function *)");
	operation_returned_value_ = NULL;
	operations_ptr_ = function->operations_;
	while (operations_ptr_ != NULL) {
		operation_returned_value_ = run_operation(
				operations_ptr_->first, values/*, variables*/);
		operations_ptr_ = operations_ptr_->next;
	}
	return operation_returned_value_;
}

void
run_application(const rtg_application * application)
{
	const rtg_named_function * entry_point_function_;
	arn_values_fixed_list * values_;
	arn_named_function_returned_value * entry_point_function_returned_value_;
	/* arn_variables_simple_list * variables_; */
	fprintf(stderr, "----> %s:%u (%s)\n", __FILE__, __LINE__,
			"void run_application(const application *)");
	values_ = arn_values_fixed_list_default_constructor();
	/* variables_ = arn_variables_simple_list_default_constructor(); */
	entry_point_function_ = application->entry_point_function_;
	entry_point_function_returned_value_ = run_named_function(
			entry_point_function_, values_/*, variables_*/);

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
	ret_->status = PROCESS_RTG_DOC_EXECUTION_REQUESTS_RET_STATUS_INVALID;
	assertion(doc != NULL);
	execution_requests_ptr_ = doc->execution_requests_;
	while (execution_requests_ptr_ != NULL) {
		run_application(execution_requests_ptr_->first->application_);
		execution_requests_ptr_ = execution_requests_ptr_->next;
	}
	ret_->status = PROCESS_RTG_DOC_EXECUTION_REQUESTS_RET_STATUS_SUCCESS;
	return ret_;
}
