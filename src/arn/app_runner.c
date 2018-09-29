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

/*   For `rtg_function`. */
#include "../rtg/rtg_function.h"

/*   For `rtg_operation`. */
#include "../rtg/rtg_operation.h"

/*   For `rtg_operations_simple_list`. */
#include "../rtg/rtg_operations_simple_list.h"

/*   For `st_node`. */
#include "../stt/stt_node.h"

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
	} else {
		/*   If there were no undefined labels, defined labels
		 * have already been used to help all necessary pointer
		 * resolutions. */
		look_for_undefined_labels_ret_destructor(
				look_for_undefined_labels_ret_);
		look_for_undefined_labels_ret_ = NULL;

		/*   Now it is known there are no missing labels, ask
		 * for a run time ready graph where all labels have been
		 * turned to entity pointers. */
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

		rtg_doc_out_of_stt_doc_ret_destructor(
				rtg_doc_out_of_stt_doc_ret_);

		return APP_RUNNER_RUN_APP_RET_SUCCESS;
	}
}

void
run_operation(const rtg_operation * operation)
{
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
		} else {
			assertion(operation->args_->first->type_ ==
					RTG_OPERATION_ARG_TYPE_NATURAL_LITERAL);
			assertion(operation->args_->first->natural_literal_ !=
					NULL);
			assertion(operation->args_->first->natural_literal_->value_ !=
					NULL);
			printf("%s", operation->args_->first->natural_literal_->value_);
		}
		if (operation->type_ == RTG_OPERATION_TYPE_PRINT) {
			printf("\n");
		} else {
			assertion(operation->type_ ==
					RTG_OPERATION_TYPE_PRINT_NO_CRLF);
		}
	} else {
		assertion(operation->type_ == RTG_OPERATION_TYPE_INVALID);
		printf("!!!\n");
	}
}

void
run_function(const rtg_function * function)
{
	const rtg_operations_simple_list * operations_ptr_;
	fprintf(stderr, "----> %s:%u (%s)\n", __FILE__, __LINE__,
			"void run_function(const function *)");
	operations_ptr_ = function->operations_;
	while (operations_ptr_ != NULL) {
		run_operation(operations_ptr_->first);
		operations_ptr_ = operations_ptr_->next;
	}
}

void
run_application(const rtg_application * application)
{
	const rtg_function * entry_point_function_;
	fprintf(stderr, "----> %s:%u (%s)\n", __FILE__, __LINE__,
			"void run_application(const application *)");
	entry_point_function_ = application->entry_point_function_;
	run_function(entry_point_function_);
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
