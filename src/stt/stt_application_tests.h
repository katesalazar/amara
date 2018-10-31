#ifndef __AMARA__SYNTAX_TREE__APPLICATION_TESTS__H__
#define __AMARA__SYNTAX_TREE__APPLICATION_TESTS__H__

#include "stt_application.h"

stt_application *
stt_application_example_print_foo(void)
__attribute__((warn_unused_result))
;

void
assert_expectations_on_stt_application_example_print_foo(
		const stt_application * application)
;

stt_application *
stt_application_example_print_bar(void)
__attribute__((warn_unused_result))
;

void
assert_expectations_on_stt_application_example_print_bar(
		const stt_application * application)
;

void
stt_application_tests(void)
;

#endif
