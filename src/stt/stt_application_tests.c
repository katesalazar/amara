/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_application`. */
#include "stt_application.h"

stt_application *
stt_application_example_print_foo()
{
	stt_application * application_;
	application_ = stt_application_default_constructor();
	application_->name_ = amara_string_exhaustive_constructor(
			"cli_app_print_foo");
	application_->entry_point_function_name_ =
			amara_string_exhaustive_constructor("print_foo");
	application_->type_ = STT_APPLICATION_TYPE_CLI_APPLICATION;
	return application_;
}

stt_application *
stt_application_example_print_bar()
{
	stt_application * application_;
	application_ = stt_application_default_constructor();
	application_->name_ = amara_string_exhaustive_constructor(
			"cli_app_print_bar");
	application_->entry_point_function_name_ =
			amara_string_exhaustive_constructor("print_bar");
	application_->type_ = STT_APPLICATION_TYPE_CLI_APPLICATION;
	return application_;
}

void
assert_expectations_on_stt_application_example_print_foo(
		const stt_application * application)
{
	amara_string * application_name_;
	amara_string * entry_point_function_name_;
	amara_boolean equality_;

	application_name_ = amara_string_exhaustive_constructor(
			"cli_app_print_foo");
	assertion(application_name_ != NULL);
	assertion(application_name_->value_ != NULL);

	entry_point_function_name_ =
			amara_string_exhaustive_constructor("print_foo");
	assertion(entry_point_function_name_ != NULL);
	assertion(entry_point_function_name_->value_ != NULL);

	assertion(application != NULL);
	assertion(application->type_ == STT_APPLICATION_TYPE_CLI_APPLICATION);
	assertion(application->name_ != NULL);
	assertion(application->name_->value_ != NULL);
	equality_ = amara_string_equality(
			application->name_, application_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(application->entry_point_function_name_ != NULL);
	assertion(application->entry_point_function_name_->value_ != NULL);
	equality_ = amara_string_equality(
			application->entry_point_function_name_,
			entry_point_function_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(entry_point_function_name_);
	amara_string_destructor(application_name_);
}

void
assert_expectations_on_stt_application_example_print_bar(
		const stt_application * application)
{
	amara_string * application_name_;
	amara_string * entry_point_function_name_;
	amara_boolean equality_;

	application_name_ = amara_string_exhaustive_constructor(
			"cli_app_print_bar");
	assertion(application_name_ != NULL);
	assertion(application_name_->value_ != NULL);

	entry_point_function_name_ =
			amara_string_exhaustive_constructor("print_bar");
	assertion(entry_point_function_name_ != NULL);
	assertion(entry_point_function_name_->value_ != NULL);

	assertion(application != NULL);
	assertion(application->type_ == STT_APPLICATION_TYPE_CLI_APPLICATION);
	assertion(application->name_ != NULL);
	assertion(application->name_->value_ != NULL);
	equality_ = amara_string_equality(
			application->name_, application_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);
	assertion(application->entry_point_function_name_ != NULL);
	assertion(application->entry_point_function_name_->value_ != NULL);
	equality_ = amara_string_equality(
			application->entry_point_function_name_,
			entry_point_function_name_);
	assertion(equality_ == AMARA_BOOLEAN_TRUE);

	amara_string_destructor(entry_point_function_name_);
	amara_string_destructor(application_name_);
}

void
stt_application_construct_and_destruct_test_0()
{
	stt_application * stt_application_;
	stt_application_ = stt_application_default_constructor();
	assertion(stt_application_ != NULL);
	assertion(stt_application_->type_ == STT_APPLICATION_TYPE_INVALID);
	assertion(stt_application_->name_ == NULL);
	assertion(stt_application_->entry_point_function_name_ == NULL);
	stt_application_destructor(stt_application_);
}

void
stt_application_construct_and_destruct_test_1()
{
	stt_application * application_zero_;
	stt_application * application_one_;
	amara_string * application_zero_name_;
	amara_string * application_zero_entry_point_function_name_;
	application_zero_name_ = amara_string_exhaustive_constructor(
			"foo");
	application_zero_entry_point_function_name_ =
			amara_string_exhaustive_constructor("bar");
	application_zero_ = stt_application_exhaustive_constructor(
			application_zero_name_,
			application_zero_entry_point_function_name_,
			STT_APPLICATION_EXHAUSTIVE_CONSTRUCTOR_FLAG_CLI_APPLICATION);
	assertion(application_zero_ != NULL);
	assertion(application_zero_->type_ ==
			STT_APPLICATION_TYPE_CLI_APPLICATION);
	assertion(amara_string_equality(
			application_zero_->name_, application_zero_name_));
	assertion(amara_string_equality(
			application_zero_->entry_point_function_name_,
			application_zero_entry_point_function_name_));
	application_one_ = stt_application_copy_constructor(application_zero_);
	assertion(application_one_ != NULL);
	assertion(application_one_->type_ ==
			STT_APPLICATION_TYPE_CLI_APPLICATION);
	assertion(amara_string_equality(
			application_one_->name_, application_zero_name_));
	assertion(amara_string_equality(
			application_one_->entry_point_function_name_,
			application_zero_entry_point_function_name_));
	amara_string_destructor(application_zero_entry_point_function_name_);
	amara_string_destructor(application_zero_name_);
	stt_application_destructor(application_one_);
	stt_application_destructor(application_zero_);
}

void
stt_application_construct_and_destruct_tests()
{
	stt_application_construct_and_destruct_test_0();
	stt_application_construct_and_destruct_test_1();
}

void
stt_application_tests()
{
	stt_application_construct_and_destruct_tests();
}
