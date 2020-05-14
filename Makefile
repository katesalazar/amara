#
# Copyright 2018-2020 Mercedes Catherine Salazar
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Makefile: GNU `make` configuration for Amara.
#

# CFLAGS_GENERAL = -v
# $(info $(CFLAGS_GENERAL))
# CFLAGS_PARTICULAR_FLEX = -v
# $(info $(CFLAGS_PARTICULAR_FLEX))

UNAME_S = $(shell uname -s)
# $(info Platform: $(UNAME_S))

ifeq ($(UNAME_S), CYGWIN_NT-6.1)
#   Windows 7.
CYG = yes
else
CYG = no
endif

ifeq ($(UNAME_S), Darwin)
# BISON ?= /usr/local/Cellar/bison/3.4.1/bin/bison
BISON ?= bison
# FLEX ?= /usr/local/Cellar/flex/2.6.4/bin/flex
FLEX ?= flex
XCODE ?= 1
else
BISON ?= bison
FLEX ?= flex
XCODE ?= 0
endif

# XXX    Why did I remove `-ansi` from Darwin? Maybe related to the fact
# XXX  I was surely using llvm 9.0.0, but... why did I remove it?
#        If linking with `-ansi`, macOS is outputting: `clang: error: argument unused during compilation: '-ansi' [-Werror,-Wunused-command-line-argument]`
# FIXME    Bring back the `-ansi` flag to GENERAL; but only for compiles, not for links, when on Darwin. Always when on GNU/Linux.
ifneq ($(UNAME_S), Darwin)
CFLAGS_GENERAL += -ansi
# $(info $(CFLAGS_GENERAL))
CFLAGS_PARTICULAR_FLEX += -ansi
# $(info $(CFLAGS_PARTICULAR_FLEX))
else
CFLAGS_GENERAL += -D__APPLE__
CFLAGS_PARTICULAR_FLEX += -D__APPLE__
endif

ifeq ($(CYG), yes)
CFLAGS_GENERAL += -D__CYG__
endif

CFLAGS_GENERAL += -pedantic -Wall -Wextra
# $(info $(CFLAGS_GENERAL))
CFLAGS_PARTICULAR_FLEX += -pedantic -Wall -Wextra
# $(info $(CFLAGS_PARTICULAR_FLEX))

#   `-Werror`: Maybe this is causing issues to the `flex` output doc..?
CFLAGS_GENERAL += -Werror
# $(info $(CFLAGS_GENERAL))
# TODO    Here the differential condition is probably not the Darwin OS
# TODO  but some particular `flex` version.
# TODO    GCC 6 on debian stretch not able to compile the tokenizer
# TODO  built by `flex` 2.6.1 without removing `-Werror`.
# TODO    Apple Clang 9 on macOS High Sierra able to compile the
# TODO  tokenizer built by `flex 2.5.35 Apple(flex-31)` even when
# TODO  `-Werror` set.
ifeq ($(UNAME_S), Darwin)
CFLAGS_PARTICULAR_FLEX += -Werror
endif
# $(info $(CFLAGS_PARTICULAR_FLEX))

#   `-Wunused-result`: warn (and so error) if the return value of a
# function is not stored.
CFLAGS_GENERAL += -Wunused-result
# $(info $(CFLAGS_GENERAL))
CFLAGS_PARTICULAR_FLEX += -Wunused-result
# $(info $(CFLAGS_PARTICULAR_FLEX))

#   `-Werror=unused-but-set-variable` seems to be somehow implicit in
# Amazon Linux (GCC 4.8.5), but not in macOS Apple LLVM version 9.0.0
# (clang-900.0.37). There, it also has a different name, as it is called
# `-Wunused-variable`.
#   TODO: This should be activated for the compiler, not for the
# platform.
#   TODO: `-Wunused-variable` in clang is **not** a replacement for what
# `-Wunused-but-set-variable` does in GCC. Remove this block completely!
ifeq ($(UNAME_S), Darwin)
CFLAGS_GENERAL += -Werror=unused-variable
CFLAGS_PARTICULAR_FLEX += -Werror=unused-variable
endif

CFLAGS_GENERAL += -Wmissing-include-dirs
# $(info $(CFLAGS_GENERAL))
CFLAGS_PARTICULAR_FLEX += -Wmissing-include-dirs
# $(info $(CFLAGS_PARTICULAR_FLEX))

CFLAGS_GENERAL += -Wparentheses
# $(info CFLAGS_GENERAL: $(CFLAGS_GENERAL))
CFLAGS_PARTICULAR_FLEX += -Wparentheses
# $(info CFLAGS_PARTICULAR_FLEX: $(CFLAGS_PARTICULAR_FLEX))

ifeq ($(UNAME_S), Darwin)
CFLAGS_GENERAL += -DCLANG
endif

CFLAGS = $(CFLAGS_GENERAL)

CFLAGS_DEBUG = -O0 -g -fprofile-arcs -ftest-coverage

#   This is most probably temporarily.
CFLAGS_DEBUG += -DTRACE_BISON -DTRACE_FLEX

#   There is some documentation stating that using `valgrind` and
# `gprof` together brings up incompatibilities. Remove the `gprof` flag
# temporarily while figuring out a permanent solution to this issue.
# CFLAGS_DEBUG += -pg

ifeq ($(UNAME_S), Linux)
GCC_EQ_485 = $(shell expr `gcc -dumpversion | sed 's/\.\([0-9][0-9]\)/\1/g' | \
		sed 's/\.\([0-9]\)/0\1/g' | \
		sed 's/^[0-9]\{3,4\}$$/&00/'` = 40805)
endif

#   XXX
CC ?= cc
CXX ?= c++
C ?= $(CC)
STRIP = strip

CP = cp
MV = mv

#   `-no-pie` was added while fighting with an issue in `gprof`, might
# probably get out without breaking the build tests.
ifneq ($(UNAME_S), Darwin)
ifneq ($(UNAME_S), Linux)
CFLAGS_DEBUG += -no-pie
endif
ifeq ($(UNAME_S), Linux)
ifneq "$(GCC_EQ_485)" "1"
CFLAGS_DEBUG += -no-pie
endif
endif
endif

CFLAGS_RELEASE = -O2 -DNDEBUG

ifeq ($(XCODE), yes)
BISON_FLAGS ?= --no-lines
FLEX_FLAGS ?= --noline
endif

ifeq ($(C), g++)
    CEXT ?= cpp
    HEXT = h
    CFLAGS_GENERAL += -std=c++98 -DAMARA_USE_STD_CXX98
    ifeq ($(CYG), yes)
        #   Apply SO's answer 32952453 for question 18784112.
        CFLAGS_PARTICULAR_FLEX += -std=gnu++98 -DAMARA_USE_STD_GNUXX98
    else
        CFLAGS_PARTICULAR_FLEX += -std=c++98 -DAMARA_USE_STD_CXX98
    endif
else
    ifeq ($(C), clang++)
        CEXT ?= cpp
        HEXT = h
        CFLAGS_GENERAL += -std=c++98 -DAMARA_USE_STD_CXX98
        CFLAGS_PARTICULAR_FLEX += -std=c++98 -DAMARA_USE_STD_CXX98
    else
        CEXT ?= c
        HEXT = h
        CFLAGS_GENERAL += -std=c89 -DAMARA_USE_STD_C89
        CFLAGS_PARTICULAR_FLEX += -std=c89 -DAMARA_USE_STD_C89
    endif
endif

SRC_DIR = src

BUILD_DIR = build

BUILD_DIR_SRC = $(BUILD_DIR)/src

BUILD_DIR_DEBUG = $(BUILD_DIR)/debug

BUILD_DIR_RELEASE = $(BUILD_DIR)/release

RESOURCES_DIR = res

UTILS_DIR = utils

# SRC = \
	$(SRC_DIR)/cmn/amara_string.c \
	$(SRC_DIR)/cmn/amara_string_tests.c \
	$(SRC_DIR)/cmn/amara_strings_simple_list.c \
	$(SRC_DIR)/cmn/amara_strings_simple_list_tests.c \
	$(SRC_DIR)/arn/app_runner.c \
	$(SRC_DIR)/arn/app_runner_tests.c \
	$(SRC_DIR)/arn/arn_tests.c \
	$(SRC_DIR)/arn/arn_type.c \
	$(SRC_DIR)/arn/arn_type_tests.c \
	$(SRC_DIR)/arn/arn_value.c \
	$(SRC_DIR)/arn/arn_value_tests.c \
	$(SRC_DIR)/arn/arn_values_fixed_list.c \
	$(SRC_DIR)/arn/arn_values_fixed_list_tests.c \
	$(SRC_DIR)/arn/arn_values_simple_list.c \
	$(SRC_DIR)/arn/arn_values_simple_list_tests.c \
	$(SRC_DIR)/arn/arn_variable.c \
	$(SRC_DIR)/arn/arn_variable_tests.c \
	$(SRC_DIR)/arn/arn_variables_simple_list.c \
	$(SRC_DIR)/arn/arn_variables_simple_list_tests.c \
	$(SRC_DIR)/arg.c \
	$(SRC_DIR)/asr/assertion.c \
	$(SRC_DIR)/brt/basic_arithmetic_tests.c \
	$(SRC_DIR)/bsn/bison_tests.c \
	$(SRC_DIR)/cmn/char_array.c \
	$(SRC_DIR)/cmn/char_array_tests.c \
	$(SRC_DIR)/cmn/char_arrays_simple_list.c \
	$(SRC_DIR)/cmn/char_arrays_simple_list_tests.c \
	$(SRC_DIR)/cmn/common_tests.c \
	$(SRC_DIR)/log/logging.c \
	$(SRC_DIR)/wrp/dirent_wrapper.c \
	$(SRC_DIR)/bsn/flex_tests.c \
	$(SRC_DIR)/brt/integer.c \
	$(SRC_DIR)/brt/integer_tests.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/bsn/lex.minia.c \
	$(SRC_DIR)/bsn/minia.tab.c \
	$(SRC_DIR)/brt/natural.c \
	$(SRC_DIR)/brt/natural_tests.c \
	$(SRC_DIR)/prs/persistence.c \
	$(SRC_DIR)/prs/persistence_tests.c \
	$(SRC_DIR)/brt/rational.c \
	$(SRC_DIR)/brt/rational_tests.c \
	$(SRC_DIR)/mmm/allocator.c \
	$(SRC_DIR)/rtg/rtg_application.c \
	$(SRC_DIR)/rtg/rtg_application_tests.c \
	$(SRC_DIR)/rtg/rtg_applications_simple_list.c \
	$(SRC_DIR)/rtg/rtg_applications_simple_list_tests.c \
	$(SRC_DIR)/rtg/rtg_condition.c \
	$(SRC_DIR)/rtg/rtg_condition_tests.c \
	$(SRC_DIR)/rtg/rtg_doc.c \
	$(SRC_DIR)/rtg/rtg_doc_tests.c \
	$(SRC_DIR)/rtg/rtg_execution_request.c \
	$(SRC_DIR)/rtg/rtg_execution_request_tests.c \
	$(SRC_DIR)/rtg/rtg_execution_requests_simple_list.c \
	$(SRC_DIR)/rtg/rtg_execution_requests_simple_list_tests.c \
	$(SRC_DIR)/rtg/rtg_expression.c \
	$(SRC_DIR)/rtg/rtg_expression_sub_conditional.c \
	$(SRC_DIR)/rtg/rtg_expression_sub_conditional_tests.c \
	$(SRC_DIR)/rtg/rtg_expression_sub_dice.c \
	$(SRC_DIR)/rtg/rtg_expression_sub_dice_tests.c \
	$(SRC_DIR)/rtg/rtg_expression_sub_identifier.c \
	$(SRC_DIR)/rtg/rtg_expression_sub_identifier_tests.c \
	$(SRC_DIR)/rtg/rtg_expression_sub_natural_literal.c \
	$(SRC_DIR)/rtg/rtg_expression_sub_string_literal.c \
	$(SRC_DIR)/rtg/rtg_expression_tests.c \
	$(SRC_DIR)/rtg/rtg_named_function.c \
	$(SRC_DIR)/rtg/rtg_named_function_call.c \
	$(SRC_DIR)/rtg/rtg_named_function_tests.c \
	$(SRC_DIR)/rtg/rtg_named_functions_simple_list.c \
	$(SRC_DIR)/rtg/rtg_named_functions_simple_list_tests.c \
	$(SRC_DIR)/rtg/rtg_operation.c \
	$(SRC_DIR)/rtg/rtg_operation_arg.c \
	$(SRC_DIR)/rtg/rtg_operation_arg_tests.c \
	$(SRC_DIR)/rtg/rtg_operation_args_simple_list.c \
	$(SRC_DIR)/rtg/rtg_operation_args_simple_list_tests.c \
	$(SRC_DIR)/rtg/rtg_operation_tests.c \
	$(SRC_DIR)/rtg/rtg_operations_simple_list.c \
	$(SRC_DIR)/rtg/rtg_operations_simple_list_tests.c \
	$(SRC_DIR)/rtg/rtg_tests.c \
	$(SRC_DIR)/rtg/rtg_where_value_binding.c \
	$(SRC_DIR)/rtg/rtg_where_value_binding_tests.c \
	$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list.c \
	$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list_tests.c \
	$(SRC_DIR)/tst/tests_pseudo_random_numbers_generation.c \
	$(SRC_DIR)/tst/tests_pseudo_random_numbers_generation_tests.c \
	$(SRC_DIR)/tst/tests_runner.c \
	$(SRC_DIR)/tst/tests_simple_list.c \
	$(SRC_DIR)/tst/tests_simple_list_tests.c \
	$(SRC_DIR)/stt/stt_application.c \
	$(SRC_DIR)/stt/stt_application_subnode.c \
	$(SRC_DIR)/stt/stt_application_subnode_tests.c \
	$(SRC_DIR)/stt/stt_application_tests.c \
	$(SRC_DIR)/stt/stt_applications_simple_list.c \
	$(SRC_DIR)/stt/stt_applications_simple_list_tests.c \
	$(SRC_DIR)/stt/stt_condition.c \
	$(SRC_DIR)/stt/stt_condition_subnode.c \
	$(SRC_DIR)/stt/stt_condition_subnode_tests.c \
	$(SRC_DIR)/stt/stt_condition_tests.c \
	$(SRC_DIR)/stt/stt_dice_expression.c \
	$(SRC_DIR)/stt/stt_dice_expression_tests.c \
	$(SRC_DIR)/stt/stt_doc_subnode.c \
	$(SRC_DIR)/stt/stt_doc_subnode_tests.c \
	$(SRC_DIR)/stt/stt_execution_request.c \
	$(SRC_DIR)/stt/stt_execution_request_subnode.c \
	$(SRC_DIR)/stt/stt_execution_request_subnode_tests.c \
	$(SRC_DIR)/stt/stt_execution_request_tests.c \
	$(SRC_DIR)/stt/stt_execution_requests_simple_list.c \
	$(SRC_DIR)/stt/stt_execution_requests_simple_list_tests.c \
	$(SRC_DIR)/stt/stt_expression.c \
	$(SRC_DIR)/stt/stt_expression_sub_conditional.c \
	$(SRC_DIR)/stt/stt_expression_sub_conditional_tests.c \
	$(SRC_DIR)/stt/stt_expression_sub_dice.c \
	$(SRC_DIR)/stt/stt_expression_sub_dice_tests.c \
	$(SRC_DIR)/stt/stt_expression_sub_identifier.c \
	$(SRC_DIR)/stt/stt_expression_sub_identifier_tests.c \
	$(SRC_DIR)/stt/stt_expression_sub_natural_literal.c \
	$(SRC_DIR)/stt/stt_expression_sub_string_literal.c \
	$(SRC_DIR)/stt/stt_expression_subnode.c \
	$(SRC_DIR)/stt/stt_expression_subnode_tests.c \
	$(SRC_DIR)/stt/stt_expression_tests.c \
	$(SRC_DIR)/stt/stt_named_function.c \
	$(SRC_DIR)/stt/stt_named_function_call.c \
	$(SRC_DIR)/stt/stt_named_function_subnode.c \
	$(SRC_DIR)/stt/stt_named_function_subnode_tests.c \
	$(SRC_DIR)/stt/stt_named_function_tests.c \
	$(SRC_DIR)/stt/stt_named_functions_simple_list.c \
	$(SRC_DIR)/stt/stt_named_functions_simple_list_tests.c \
	$(SRC_DIR)/stt/stt_identifier_subnode.c \
	$(SRC_DIR)/stt/stt_identifier_subnode_tests.c \
	$(SRC_DIR)/stt/stt_integer_literal_subnode.c \
	$(SRC_DIR)/stt/stt_integer_literal_subnode_tests.c \
	$(SRC_DIR)/stt/stt_natural_literal_subnode.c \
	$(SRC_DIR)/stt/stt_natural_literal_subnode_tests.c \
	$(SRC_DIR)/stt/stt_node.c \
	$(SRC_DIR)/stt/stt_node_sub_named_function_call.c \
	$(SRC_DIR)/stt/stt_node_sub_named_function_call_arguments.c \
	$(SRC_DIR)/stt/stt_node_tests.c \
	$(SRC_DIR)/stt/stt_operation.c \
	$(SRC_DIR)/stt/stt_operation_arg.c \
	$(SRC_DIR)/stt/stt_operation_arg_tests.c \
	$(SRC_DIR)/stt/stt_operation_args_simple_list.c \
	$(SRC_DIR)/stt/stt_operation_args_simple_list_tests.c \
	$(SRC_DIR)/stt/stt_operation_subnode.c \
	$(SRC_DIR)/stt/stt_operation_subnode_tests.c \
	$(SRC_DIR)/stt/stt_operation_tests.c \
	$(SRC_DIR)/stt/stt_operations_list_subnode.c \
	$(SRC_DIR)/stt/stt_operations_list_subnode_tests.c \
	$(SRC_DIR)/stt/stt_operations_simple_list.c \
	$(SRC_DIR)/stt/stt_operations_simple_list_tests.c \
	$(SRC_DIR)/stt/stt_rational_literal_subnode.c \
	$(SRC_DIR)/stt/stt_rational_literal_subnode_tests.c \
	$(SRC_DIR)/stt/stt_string_literal_subnode.c \
	$(SRC_DIR)/stt/stt_string_literal_subnode_tests.c \
	$(SRC_DIR)/stt/stt_tests.c \
	$(SRC_DIR)/stt/stt_where_value_binding.c \
	$(SRC_DIR)/stt/stt_where_value_binding_subnode.c \
	$(SRC_DIR)/stt/stt_where_value_binding_subnode_tests.c \
	$(SRC_DIR)/stt/stt_where_value_binding_tests.c \
	$(SRC_DIR)/stt/stt_where_value_bindings_simple_list.c \
	$(SRC_DIR)/stt/stt_where_value_bindings_simple_list_tests.c \
	$(SRC_DIR)/stt/stt_where_value_bindings_subnode.c \
	$(SRC_DIR)/stt/stt_where_value_bindings_subnode_tests.c

BUILD_SRC = \
	$(BUILD_DIR_SRC)/cmn/amara_string.$(CEXT) \
	$(BUILD_DIR_SRC)/cmn/amara_string_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/app_runner.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/app_runner_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/arn_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/arn_type.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/arn_type_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/arn_value.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/arn_value_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/arn_variable.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/arn_variable_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/arg.$(CEXT) \
	$(BUILD_DIR_SRC)/asr/assertion.$(CEXT) \
	$(BUILD_DIR_SRC)/brt/basic_arithmetic_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/bsn/bison_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/cmn/char_array.$(CEXT) \
	$(BUILD_DIR_SRC)/cmn/char_array_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/cmn/common_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/log/logging.$(CEXT) \
	$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$(CEXT) \
	$(BUILD_DIR_SRC)/bsn/flex_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/brt/integer.$(CEXT) \
	$(BUILD_DIR_SRC)/brt/integer_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/main.$(CEXT) \
	$(BUILD_DIR_SRC)/bsn/bison_annex.$(CEXT) \
	$(BUILD_DIR_SRC)/bsn/lex.minia.$(CEXT) \
	$(BUILD_DIR_SRC)/bsn/minia.tab.$(CEXT) \
	$(BUILD_DIR_SRC)/brt/natural.$(CEXT) \
	$(BUILD_DIR_SRC)/brt/natural_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/prs/persistence.$(CEXT) \
	$(BUILD_DIR_SRC)/prs/persistence_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/brt/rational.$(CEXT) \
	$(BUILD_DIR_SRC)/brt/rational_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/mmm/allocator.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_application.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_condition.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_doc.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_doc_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_execution_request_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_expression.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_natural_literal.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_string_literal.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_named_function_call.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_operation.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_operation_arg_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$(CEXT) \
	$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/tst/tests_runner.$(CEXT) \
	$(BUILD_DIR_SRC)/tst/tests_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/tst/tests_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_application.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_application_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_application_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_condition.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_condition_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_condition_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_dice_expression.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_execution_request.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_expression.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_expression_sub_natural_literal.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_expression_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_expression_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_named_function.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_named_function_call.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_identifier_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_node.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_node_sub_named_function_call.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_node_sub_named_function_call_arguments.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_node_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_operation.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_operation_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$(CEXT) \
	$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$(CEXT)

define debug_and_release_OBJS_definition
OBJ_$(BUILD_TYPE) = \
		$$(BUILD_DIR_$(BUILD_TYPE))/allocator.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/amara_string.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/amara_string_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/amara_strings_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/amara_strings_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/app_runner.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/app_runner_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arn_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arn_type.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arn_type_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arn_value.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arn_value_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arn_values_fixed_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arn_values_fixed_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arn_values_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arn_values_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arn_variable.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arn_variable_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arn_variables_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arn_variables_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/arg.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/assertion.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/basic_arithmetic_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/bison_annex.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/bison_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/char_array.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/char_array_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/char_arrays_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/char_arrays_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/common_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/logging.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/dirent_wrapper.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/flex_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/integer.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/integer_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/main.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/lex.minia.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/minia.tab.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/natural.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/natural_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/persistence.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/persistence_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rational.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rational_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_application.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_application_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_applications_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_applications_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_condition.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_condition_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_doc.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_doc_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_execution_request.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_execution_request_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_execution_requests_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_execution_requests_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_conditional.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_conditional_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_dice.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_dice_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_identifier.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_identifier_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_natural_literal.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_string_literal.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_named_function.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_named_function_call.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_named_function_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_named_functions_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_named_functions_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operation.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operation_arg.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operation_arg_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operation_args_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operation_args_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operation_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operations_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operations_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_where_value_binding.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_where_value_binding_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_where_value_bindings_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_where_value_bindings_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/rtg_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/tests_pseudo_random_numbers_generation.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/tests_pseudo_random_numbers_generation_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/tests_runner.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/tests_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/tests_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_application.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_application_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_application_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_application_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_applications_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_applications_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_condition.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_condition_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_condition_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_condition_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_dice_expression.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_dice_expression_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_doc_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_doc_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_execution_request.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_execution_request_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_execution_request_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_execution_request_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_execution_requests_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_execution_requests_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_conditional.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_conditional_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_dice.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_dice_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_identifier.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_identifier_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_natural_literal.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_string_literal.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_function.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_function_call.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_function_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_function_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_function_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_functions_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_functions_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_identifier_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_identifier_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_integer_literal_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_integer_literal_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_natural_literal_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_natural_literal_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_node.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_node_sub_named_function_call.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_node_sub_named_function_call_arguments.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_node_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_arg.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_arg_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_args_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_args_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_operations_list_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_operations_list_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_operations_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_operations_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_rational_literal_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_rational_literal_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_string_literal_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_string_literal_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_binding.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_binding_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_binding_subnode_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_binding_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_bindings_simple_list.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_bindings_simple_list_tests.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_bindings_subnode.o \
		$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_bindings_subnode_tests.o
endef

$(foreach BUILD_TYPE, DEBUG RELEASE, $(eval $(debug_and_release_OBJS_definition)))

DEBUG_RESOURCES = \
		$(RESOURCES_DIR)/minia.grammar

default: \
	checkdirs \
	$(BUILD_DIR_RELEASE)/amara

#   `amara_not_stripped` is implicit in `amara`.
all: \
	checkdirs \
	$(BUILD_DIR_RELEASE)/amara_not_stripped \
	$(BUILD_DIR_RELEASE)/amara \
	$(BUILD_DIR_DEBUG)/amara_g \
	$(BUILD_DIR_DEBUG)/stripped_amara_g \
	$(DEBUG_RESOURCES)

#   All of the directory structure is created at once, even those parts
# that might not going to be used, because this allows to avoid a whole
# class of issues that can happen when directories are set as
# prerequisites for their docs. Some OS might update the date of the dir
# if a new file is copied or even just modified inside, giving birth to
# egg-and-chicken circular dependency issues when calling `make`.
checkdirs: \
	$(BUILD_DIR_SRC) \
	$(BUILD_DIR_SRC)/arn \
	$(BUILD_DIR_SRC)/asr \
	$(BUILD_DIR_SRC)/brt \
	$(BUILD_DIR_SRC)/bsn \
	$(BUILD_DIR_SRC)/cmn \
	$(BUILD_DIR_SRC)/ftr \
	$(BUILD_DIR_SRC)/log \
	$(BUILD_DIR_SRC)/mmm \
	$(BUILD_DIR_SRC)/prs \
	$(BUILD_DIR_SRC)/rtg \
	$(BUILD_DIR_SRC)/stt \
	$(BUILD_DIR_SRC)/tst \
	$(BUILD_DIR_SRC)/wrp \
	$(BUILD_DIR_RELEASE) \
	$(BUILD_DIR_DEBUG)

$(BUILD_DIR):
	mkdir $@

$(BUILD_DIR_SRC) \
		$(BUILD_DIR_SRC)/arn \
		$(BUILD_DIR_SRC)/asr \
		$(BUILD_DIR_SRC)/brt \
		$(BUILD_DIR_SRC)/bsn \
		$(BUILD_DIR_SRC)/cmn \
		$(BUILD_DIR_SRC)/ftr \
		$(BUILD_DIR_SRC)/log \
		$(BUILD_DIR_SRC)/mmm \
		$(BUILD_DIR_SRC)/prs \
		$(BUILD_DIR_SRC)/rtg \
		$(BUILD_DIR_SRC)/stt \
		$(BUILD_DIR_SRC)/tst \
		$(BUILD_DIR_SRC)/wrp \
		$(BUILD_DIR_DEBUG) \
		$(BUILD_DIR_RELEASE):
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

amara: \
		checkdirs \
		$(BUILD_DIR_RELEASE)/amara

#   Bear in mind, `$(BUILD_DIR_DEBUG)/stripped_amara_g` is not a target
# of `$(BUILD_DIR_DEBUG)/amara_g`.
amara_g: \
		checkdirs \
		$(BUILD_DIR_DEBUG)/amara_g \
		$(DEBUG_RESOURCES)

#   `make release` is synctactic sugar for `make amara`.
release: \
		amara

#   `make debug` is synctactic sugar for `make amara_g`.
debug: \
		amara_g

$(BUILD_DIR_SRC)/bsn/minia.y: \
		$(SRC_DIR)/bsn/minia.y
	$(CP) $< $@

#   It's most probably not required to go back to the source but... well
# maybe it's tidier like this.
$(BUILD_DIR_SRC)/bsn/minia.tab.$(CEXT): \
		$(BUILD_DIR_SRC)/bsn/minia.y \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT)
	find $(BUILD_DIR_SRC)/bsn/ -type d && \
			pwd && \
			ls $(BUILD_DIR_SRC)/bsn/ && \
			cd $(BUILD_DIR_SRC)/bsn/ && \
			pwd && \
			$(BISON) \
					--name-prefix minia \
					--defines \
					--graph \
					--report=all \
					--verbose \
					$(BISON_FLAGS) \
					minia.y && \
			ls ./
	find $(BUILD_DIR_SRC)/bsn/ -type d && \
			ls $(BUILD_DIR_SRC)/bsn/ && \
			$(MV) $(BUILD_DIR_SRC)/bsn/minia.tab.c $(BUILD_DIR_SRC)/bsn/minia.tab.c__ && \
			ls $(BUILD_DIR_SRC)/bsn/ && \
			$(MV) $(BUILD_DIR_SRC)/bsn/minia.tab.c__ $(BUILD_DIR_SRC)/bsn/minia.tab.$(CEXT) && \
			ls $(BUILD_DIR_SRC)/bsn/

$(BUILD_DIR_SRC)/bsn/minia.tab.$(HEXT): \
		$(BUILD_DIR_SRC)/bsn/minia.tab.$(CEXT)

$(BUILD_DIR_SRC)/bsn/minia.l: \
		$(SRC_DIR)/bsn/minia.l
	$(CP) $< $@

#   It's most probably not required to go back to the source but... well
# maybe it's tidier like this.
$(BUILD_DIR_SRC)/bsn/lex.minia.$(CEXT): \
		$(BUILD_DIR_SRC)/bsn/minia.l \
		$(BUILD_DIR_SRC)/bsn/minia.tab.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	pwd && \
			cd $(BUILD_DIR_SRC)/bsn/ && \
			pwd && \
			$(FLEX) \
				-P minia \
				$(FLEX_FLAGS) \
				-o lex.minia.$(CEXT) \
				minia.l && \
			cd ../../../ && \
			pwd

#   Creates `amara_g_not_stripped` too, only in order for CI not to
# behave oddly, however at the moment `amara_g_not_stripped` is
# deprecated in favor of just `amara_g`.
$(BUILD_DIR_DEBUG)/amara_g: \
		$(OBJ_DEBUG)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -o $@ $(OBJ_DEBUG)
	$(CP) $@ $(BUILD_DIR_DEBUG)/amara_g_not_stripped

$(BUILD_DIR_DEBUG)/stripped_amara_g : \
		$(BUILD_DIR_DEBUG)/amara_g
	$(CP) $< $@
	$(STRIP) $@

$(BUILD_DIR_RELEASE)/amara_not_stripped: \
		$(OBJ_RELEASE)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -o $@ $(OBJ_RELEASE)

$(BUILD_DIR_RELEASE)/amara : \
		$(BUILD_DIR_RELEASE)/amara_not_stripped
	$(CP) $< $@
	$(STRIP) $@

$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT): \
		$(SRC_DIR)/cmn/amara_string.h \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/amara_string.$(CEXT): \
		$(SRC_DIR)/cmn/amara_string.c
	$(CP) $< $@

#   This GNU Make definition:
#
#       define amara_string_OBJ_RULE
#       $$(BUILD_DIR_$(BUILD_TYPE))/amara_string.o: \
#       		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(CEXT) \
#       		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT)
#       	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
#       endef
#
#   When looping on $(BUILD_TYPE) for values `DEBUG` and `RELEASE`, is
# going to unfold into:
#
#       $(BUILD_DIR_DEBUG)/amara_string.o: \
#       		$(BUILD_DIR_SRC)/cmn/amara_string.$(CEXT) \
#       		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
#       	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<
#       $(BUILD_DIR_RELEASE)/amara_string.o: \
#       		$(BUILD_DIR_SRC)/cmn/amara_string.$(CEXT) \
#       		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
#       	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<
#
define amara_string_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/amara_string.o: \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(CEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/cmn/amara_string_tests.$(HEXT): \
		$(SRC_DIR)/cmn/amara_string_tests.h \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/amara_string_tests.$(CEXT): \
		$(SRC_DIR)/cmn/amara_string_tests.c \
		$(BUILD_DIR_SRC)/log/logging.$(HEXT)
	$(CP) $< $@

define amara_string_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/amara_string_tests.o: \
		$$(BUILD_DIR_SRC)/cmn/amara_string_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(HEXT): \
		$(SRC_DIR)/cmn/amara_strings_simple_list.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(CEXT): \
		$(SRC_DIR)/cmn/amara_strings_simple_list.c
	$(CP) $< $@

define amara_strings_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/amara_strings_simple_list.o: \
		$$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/cmn/amara_strings_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/cmn/amara_strings_simple_list_tests.c
	$(CP) $< $@

define amara_strings_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/amara_strings_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arg.$(HEXT): \
		$(SRC_DIR)/arg.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arg.$(CEXT): \
		$(SRC_DIR)/arg.c
	$(CP) $< $@

define arg_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arg.o: \
		$$(BUILD_DIR_SRC)/arg.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arg.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/definitions.$(HEXT): \
		$(SRC_DIR)/definitions.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/amara_boolean.$(HEXT): \
		$(SRC_DIR)/cmn/amara_boolean.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/asr/assertion.$(HEXT): \
		$(SRC_DIR)/asr/assertion.h \
		$(BUILD_DIR_SRC)/cmn/amara_boolean.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/asr/assertion.$(CEXT): \
		$(SRC_DIR)/asr/assertion.c
	$(CP) $< $@

define assertion_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/assertion.o: \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(CEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/brt/basic_arithmetic_tests.$(HEXT): \
		$(SRC_DIR)/brt/basic_arithmetic_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/basic_arithmetic_tests.$(CEXT): \
		$(SRC_DIR)/brt/basic_arithmetic_tests.c
	$(CP) $< $@

define basic_arithmetic_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/basic_arithmetic_tests.o: \
		$$(BUILD_DIR_SRC)/brt/basic_arithmetic_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/brt/basic_arithmetic_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/integer_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/rational_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/tst/tests_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/bsn/bison_annex.$(HEXT): \
		$(SRC_DIR)/bsn/bison_annex.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/bsn/bison_annex.$(CEXT): \
		$(SRC_DIR)/bsn/bison_annex.c
	$(CP) $< $@

define bison_annex_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/bison_annex.o: \
		$$(BUILD_DIR_SRC)/bsn/bison_annex.$$(CEXT) \
		$$(BUILD_DIR_SRC)/bsn/bison_annex.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/bsn/bison_tests.$(HEXT): \
		$(SRC_DIR)/bsn/bison_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/bsn/bison_tests.$(CEXT): \
		$(SRC_DIR)/bsn/bison_tests.c
	$(CP) $< $@

define bison_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/bison_tests.o: \
		$$(BUILD_DIR_SRC)/bsn/bison_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/bsn/bison_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/bsn/minia.tab.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/app_runner.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/cmn/char_array.$(HEXT): \
		$(SRC_DIR)/cmn/char_array.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/char_array.$(CEXT): \
		$(SRC_DIR)/cmn/char_array.c
	$(CP) $< $@

define char_array_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/char_array.o: \
		$$(BUILD_DIR_SRC)/cmn/char_array.$$(CEXT) \
		$$(BUILD_DIR_SRC)/cmn/char_array.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(HEXT): \
		$(SRC_DIR)/cmn/char_arrays_simple_list.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(CEXT): \
		$(SRC_DIR)/cmn/char_arrays_simple_list.c
	$(CP) $< $@

define char_arrays_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/char_arrays_simple_list.o: \
		$$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/cmn/char_arrays_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/cmn/char_arrays_simple_list_tests.c
	$(CP) $< $@

define char_arrays_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/char_arrays_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/cmn/char_array_tests.$(HEXT): \
		$(SRC_DIR)/cmn/char_array_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/char_array_tests.$(CEXT): \
		$(SRC_DIR)/cmn/char_array_tests.c
	$(CP) $< $@

define char_array_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/char_array_tests.o: \
		$$(BUILD_DIR_SRC)/cmn/char_array_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/cmn/char_array_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/char_array.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/cmn/common_tests.$(HEXT): \
		$(SRC_DIR)/cmn/common_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/common_tests.$(CEXT): \
		$(SRC_DIR)/cmn/common_tests.c
	$(CP) $< $@

define common_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/common_tests.o: \
		$$(BUILD_DIR_SRC)/cmn/common_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/cmn/common_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT) \
		$$(BUILD_DIR_SRC)/tst/tests_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/main.$(CEXT): \
		$(SRC_DIR)/main.c
	$(CP) $< $@

define main_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/main.o: \
		$$(BUILD_DIR_SRC)/main.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arg.$$(HEXT) \
		$$(BUILD_DIR_SRC)/prs/persistence.$$(HEXT) \
		$$(BUILD_DIR_SRC)/tst/tests_runner.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/app_runner.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

define lex.minia_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/lex.minia.o: \
		$$(BUILD_DIR_SRC)/bsn/lex.minia.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT)
	$$(C) $$(CFLAGS_PARTICULAR_FLEX) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

define minia.tab_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/minia.tab.o: \
		$$(BUILD_DIR_SRC)/bsn/minia.tab.$$(CEXT) \
		$$(BUILD_DIR_SRC)/bsn/minia.tab.$$(HEXT) \
		$$(BUILD_DIR_SRC)/bsn/minia.y \
		$$(BUILD_DIR_SRC)/bsn/bison_annex.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/brt/brt_forward_declarations.$(HEXT): \
		$(SRC_DIR)/brt/brt_forward_declarations.h \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/natural.$(HEXT): \
		$(SRC_DIR)/brt/natural.h \
		$(BUILD_DIR_SRC)/brt/brt_forward_declarations.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/ftr/stdio_ninety_nine_modernizer.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/natural.$(CEXT): \
		$(SRC_DIR)/brt/natural.c
	$(CP) $< $@

define natural_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/natural.o: \
		$$(BUILD_DIR_SRC)/brt/natural.$$(CEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/brt/natural_tests.$(HEXT): \
		$(SRC_DIR)/brt/natural_tests.h \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(CP) $< $@

# TODO remove this dependency on stt_node.$(HEXT)
$(BUILD_DIR_SRC)/brt/natural_tests.$(CEXT): \
		$(SRC_DIR)/brt/natural_tests.c \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(CP) $< $@

define natural_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/natural_tests.o: \
		$$(BUILD_DIR_SRC)/brt/natural_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/brt/natural_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/brt/integer.$(HEXT): \
		$(SRC_DIR)/brt/integer.h \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/integer.$(CEXT): \
		$(SRC_DIR)/brt/integer.c
	$(CP) $< $@

define integer_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/integer.o: \
		$$(BUILD_DIR_SRC)/brt/integer.$$(CEXT) \
		$$(BUILD_DIR_SRC)/brt/integer.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/brt/integer_tests.$(HEXT): \
		$(SRC_DIR)/brt/integer_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/integer_tests.$(CEXT): \
		$(SRC_DIR)/brt/integer_tests.c
	$(CP) $< $@

define integer_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/integer_tests.o: \
		$$(BUILD_DIR_SRC)/brt/integer_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/brt/integer_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/integer.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/brt/rational.$(HEXT): \
		$(SRC_DIR)/brt/rational.h \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/rational.$(CEXT): \
		$(SRC_DIR)/brt/rational.c
	$(CP) $< $@

define rational_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rational.o: \
		$$(BUILD_DIR_SRC)/brt/rational.$$(CEXT) \
		$$(BUILD_DIR_SRC)/brt/rational.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/brt/rational_tests.$(HEXT): \
		$(SRC_DIR)/brt/rational_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/rational_tests.$(CEXT): \
		$(SRC_DIR)/brt/rational_tests.c
	$(CP) $< $@

define rational_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rational_tests.o: \
		$$(BUILD_DIR_SRC)/brt/rational_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/brt/rational_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/rational.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/app_runner.$(HEXT): \
		$(SRC_DIR)/arn/app_runner.h \
		$(BUILD_DIR_SRC)/rtg/rtg_doc.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/app_runner.$(CEXT): \
		$(SRC_DIR)/arn/app_runner.c
	$(CP) $< $@

define app_runner_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/app_runner.o: \
		$$(BUILD_DIR_SRC)/arn/app_runner.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/app_runner.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_application.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$$(HEXT) \
		$$(BUILD_DIR_SRC)/prs/persistence.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/app_runner_tests.$(HEXT): \
		$(SRC_DIR)/arn/app_runner_tests.h \
		$(BUILD_DIR_SRC)/arn/arn_value_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/app_runner_tests.$(CEXT): \
		$(SRC_DIR)/arn/app_runner_tests.c
	$(CP) $< $@

define app_runner_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/app_runner_tests.o: \
		$$(BUILD_DIR_SRC)/arn/app_runner_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/app_runner_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/app_runner.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/arn_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_tests.c
	$(CP) $< $@

define arn_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arn_tests.o: \
		$$(BUILD_DIR_SRC)/arn/arn_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_type_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_variable.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_variable_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_value_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/arn_type.$(HEXT): \
		$(SRC_DIR)/arn/arn_type.h \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_type.$(CEXT): \
		$(SRC_DIR)/arn/arn_type.c
	$(CP) $< $@

define arn_type_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arn_type.o: \
		$$(BUILD_DIR_SRC)/arn/arn_type.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_type.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/arn_type_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_type_tests.h \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_type_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_type_tests.c
	$(CP) $< $@

define arn_type_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arn_type_tests.o: \
		$$(BUILD_DIR_SRC)/arn/arn_type_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_type_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/log/logging.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT): \
		$(SRC_DIR)/arn/arn_value.h \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_value.$(CEXT): \
		$(SRC_DIR)/arn/arn_value.c
	$(CP) $< $@

define arn_value_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arn_value.o: \
		$$(BUILD_DIR_SRC)/arn/arn_value.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_value.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/arn_value_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_value_tests.h \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_value_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_value_tests.c
	$(CP) $< $@

define arn_value_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arn_value_tests.o: \
		$$(BUILD_DIR_SRC)/arn/arn_value_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_value_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_value.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$(HEXT): \
		$(SRC_DIR)/arn/arn_values_fixed_list.h \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$(CEXT): \
		$(SRC_DIR)/arn/arn_values_fixed_list.c
	$(CP) $< $@

define arn_values_fixed_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arn_values_fixed_list.o: \
		$$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_value.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_values_fixed_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_values_fixed_list_tests.c
	$(CP) $< $@

define arn_values_fixed_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arn_values_fixed_list_tests.o: \
		$$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_value_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_value.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$(HEXT): \
		$(SRC_DIR)/arn/arn_values_simple_list.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$(CEXT): \
		$(SRC_DIR)/arn/arn_values_simple_list.c
	$(CP) $< $@

define arn_values_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arn_values_simple_list.o: \
		$$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_value.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_values_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_values_simple_list_tests.c
	$(CP) $< $@

define arn_values_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arn_values_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_value.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_value_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/arn_variable.$(HEXT): \
		$(SRC_DIR)/arn/arn_variable.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_variable.$(CEXT): \
		$(SRC_DIR)/arn/arn_variable.c
	$(CP) $< $@

define arn_variable_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arn_variable.o: \
		$$(BUILD_DIR_SRC)/arn/arn_variable.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_variable.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/arn_variable_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_variable_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_variable_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_variable_tests.c
	$(CP) $< $@

define arn_variable_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arn_variable_tests.o: \
		$$(BUILD_DIR_SRC)/arn/arn_variable_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_variable_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_variable.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$(HEXT): \
		$(SRC_DIR)/arn/arn_variables_simple_list.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$(CEXT): \
		$(SRC_DIR)/arn/arn_variables_simple_list.c
	$(CP) $< $@

define arn_variables_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arn_variables_simple_list.o: \
		$$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_variable.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_variables_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_variables_simple_list_tests.c
	$(CP) $< $@

define arn_variables_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/arn_variables_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/arn_variable.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/bsn/flex_tests.$(HEXT): \
		$(SRC_DIR)/bsn/flex_tests.h \
		$(BUILD_DIR_SRC)/arn/app_runner.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/bsn/flex_tests.$(CEXT): \
		$(SRC_DIR)/bsn/flex_tests.c
	$(CP) $< $@

define flex_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/flex_tests.o: \
		$$(BUILD_DIR_SRC)/bsn/flex_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/bsn/flex_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/bsn/minia.l \
		$$(BUILD_DIR_SRC)/bsn/minia.tab.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/log/logging.$(HEXT): \
		$(SRC_DIR)/log/logging.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/log/logging.$(CEXT): \
		$(SRC_DIR)/log/logging.c
	$(CP) $< $@

define logging_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/logging.o: \
		$$(BUILD_DIR_SRC)/log/logging.$$(CEXT) \
		$$(BUILD_DIR_SRC)/log/logging.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/mmm/allocator.$(HEXT): \
		$(SRC_DIR)/mmm/allocator.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/mmm/allocator.$(CEXT): \
		$(SRC_DIR)/mmm/allocator.c \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(CP) $< $@

define allocator_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/allocator.o: \
		$$(BUILD_DIR_SRC)/mmm/allocator.$$(CEXT) \
		$$(BUILD_DIR_SRC)/mmm/allocator.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/prs/persistence.$(HEXT): \
		$(SRC_DIR)/prs/persistence.h \
		$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/prs/persistence.$(CEXT): \
		$(SRC_DIR)/prs/persistence.c
	$(CP) $< $@

define persistence_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/persistence.o: \
		$$(BUILD_DIR_SRC)/prs/persistence.$$(CEXT) \
		$$(BUILD_DIR_SRC)/prs/persistence.$$(HEXT) \
		$$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/prs/persistence_tests.$(HEXT): \
		$(SRC_DIR)/prs/persistence_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/prs/persistence_tests.$(CEXT): \
		$(SRC_DIR)/prs/persistence_tests.c
	$(CP) $< $@

define persistence_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/persistence_tests.o: \
		$$(BUILD_DIR_SRC)/prs/persistence_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/prs/persistence_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$(HEXT): \
		$(SRC_DIR)/tst/tests_pseudo_random_numbers_generation.h \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$(CEXT): \
		$(SRC_DIR)/tst/tests_pseudo_random_numbers_generation.c
	$(CP) $< $@

define tests_pseudo_random_numbers_generation_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/tests_pseudo_random_numbers_generation.o: \
		$$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$$(CEXT) \
		$$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation_tests.$(HEXT): \
		$(SRC_DIR)/tst/tests_pseudo_random_numbers_generation_tests.h \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation_tests.$(CEXT): \
		$(SRC_DIR)/tst/tests_pseudo_random_numbers_generation_tests.c
	$(CP) $< $@

define tests_pseudo_random_numbers_generation_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/tests_pseudo_random_numbers_generation_tests.o: \
		$$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/tst/tests_runner.$(HEXT): \
		$(SRC_DIR)/tst/tests_runner.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/tst/tests_runner.$(CEXT): \
		$(SRC_DIR)/tst/tests_runner.c
	$(CP) $< $@

define tests_runner_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/tests_runner.o: \
		$$(BUILD_DIR_SRC)/tst/tests_runner.$$(CEXT) \
		$$(BUILD_DIR_SRC)/tst/tests_runner.$$(HEXT) \
		$$(BUILD_DIR_SRC)/tst/tests_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/bsn/flex_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/arn/app_runner_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT): \
		$(SRC_DIR)/tst/tests_simple_list.h \
		$(BUILD_DIR_SRC)/definitions.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/tst/tests_simple_list.$(CEXT): \
		$(SRC_DIR)/tst/tests_simple_list.c
	$(CP) $< $@

define tests_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/tests_simple_list.o: \
		$$(BUILD_DIR_SRC)/tst/tests_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/tst/tests_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/tst/tests_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/tst/tests_simple_list_tests.h \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/tst/tests_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/tst/tests_simple_list_tests.c
	$(CP) $< $@

define tests_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/tests_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/tst/tests_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/tst/tests_simple_list_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$(HEXT): \
		$(SRC_DIR)/wrp/dirent_wrapper.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$(CEXT): \
		$(SRC_DIR)/wrp/dirent_wrapper.c
	$(CP) $< $@

define dirent_wrapper_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/dirent_wrapper.o: \
		$$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$$(CEXT) \
		$$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_application.h \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_application.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_application.c
	$(CP) $< $@

define rtg_application_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_application.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_application.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_application.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_application.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_application_tests.h \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_application_tests.c
	$(CP) $< $@

define rtg_application_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_application_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_application.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_application.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_application_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_applications_simple_list.h \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_applications_simple_list.c
	$(CP) $< $@

define rtg_applications_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_applications_simple_list.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_application.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_applications_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_applications_simple_list_tests.c
	$(CP) $< $@

define rtg_applications_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_applications_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_condition.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_condition.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_condition.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_condition.c
	$(CP) $< $@

define rtg_condition_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_condition.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_condition.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_condition.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_condition_tests.h \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_condition_tests.c
	$(CP) $< $@

define rtg_condition_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_condition_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_condition.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_condition_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_doc.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_doc.h \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_doc.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_doc.c
	$(CP) $< $@

define rtg_doc_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_doc.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_doc.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_doc.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_doc_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_doc_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_doc_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_doc_tests.c
	$(CP) $< $@

define rtg_doc_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_doc_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_doc_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_doc_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_doc.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_execution_request.h \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_execution_request.c
	$(CP) $< $@

define rtg_execution_request_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_execution_request.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_application.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_execution_request_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_execution_request_tests.h \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_execution_request_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_execution_request_tests.c
	$(CP) $< $@

define rtg_execution_request_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_execution_request_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_execution_request_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_execution_request_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_application.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list.h \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list.c \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT)
	$(CP) $< $@

define rtg_execution_requests_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_execution_requests_simple_list.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list_tests.h \
		$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list_tests.c
	$(CP) $< $@

define rtg_execution_requests_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_execution_requests_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression.h \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_natural_literal.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_string_literal.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression.c
	$(CP) $< $@

define rtg_expression_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional.h \
		$(BUILD_DIR_SRC)/rtg/rtg_condition.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional.c
	$(CP) $< $@

define rtg_expression_sub_conditional_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_conditional.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional_tests.h \
		$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional_tests.c
	$(CP) $< $@

define rtg_expression_sub_conditional_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_conditional_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice.c
	$(CP) $< $@

define rtg_expression_sub_dice_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_dice.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice_tests.c
	$(CP) $< $@

define rtg_expression_sub_dice_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_dice_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier.h \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier.c
	$(CP) $< $@

define rtg_expression_sub_identifier_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_identifier.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier_tests.c
	$(CP) $< $@

define rtg_expression_sub_identifier_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_identifier_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_natural_literal.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_natural_literal.h \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_natural_literal.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_natural_literal.c
	$(CP) $< $@

define rtg_expression_sub_natural_literal_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_natural_literal.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_natural_literal.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_natural_literal.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_string_literal.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_string_literal.h \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_string_literal.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_string_literal.c
	$(CP) $< $@

define rtg_expression_sub_string_literal_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_sub_string_literal.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_string_literal.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_string_literal.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_tests.h \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_tests.c
	$(CP) $< $@

define rtg_expression_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_expression_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_forward_declarations.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_forward_declarations.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_named_function_call.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_named_function_call.h \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function_call_arguments_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_named_function_call_argument.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_named_function_call_argument.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_named_function_call_arguments_simple_list.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_named_function_call_arguments_simple_list.h \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function_call_argument.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_named_function.h \
		$(BUILD_DIR_SRC)/rtg/rtg_forward_declarations.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_call.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_named_function.c
	$(CP) $< $@

define rtg_named_function_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_named_function.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_named_function_call.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_named_function_call.c
	$(CP) $< $@

define rtg_named_function_call_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_named_function_call.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function_call.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function_call.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_named_function_tests.h \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_named_function_tests.c
	$(CP) $< $@

define rtg_named_function_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_named_function_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list.h \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list.c
	$(CP) $< $@

define rtg_named_functions_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_named_functions_simple_list.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list_tests.c
	$(CP) $< $@

define rtg_named_functions_simple_list_tests_OBJ_RULE
#   `stt_doc_subnode` is dependency to `stt_doc_subnode_tests`, however
# I observed that Make for Cygwin sometimes seems not to handle
# transitive dependencies completely alright.
#   So `stt_doc_subnode` is being **temporarily** added here.
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_named_functions_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operation.h \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operation.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operation.c
	$(CP) $< $@

define rtg_operation_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operation.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operation_arg.h \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function_call.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operation_arg.c
	$(CP) $< $@

define rtg_operation_arg_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operation_arg.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$$(HEXT) \
		$$(BUILD_DIR_SRC)/mmm/allocator.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_operation_arg_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operation_arg_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operation_arg_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operation_arg_tests.c
	$(CP) $< $@

define rtg_operation_arg_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operation_arg_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_arg_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_arg_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operation_args_simple_list.h \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operation_args_simple_list.c
	$(CP) $< $@

define rtg_operation_args_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operation_args_simple_list.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operation_args_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operation_args_simple_list_tests.c
	$(CP) $< $@

define rtg_operation_args_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operation_args_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operation_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operation_tests.c
	$(CP) $< $@

define rtg_operation_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operation_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operations_simple_list.h \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operations_simple_list.c
	$(CP) $< $@

define rtg_operations_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operations_simple_list.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operations_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operations_simple_list_tests.c
	$(CP) $< $@

define rtg_operations_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_operations_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_tests.c \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request_tests.$(HEXT)
	$(CP) $< $@

define rtg_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_binding.h \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_binding.c
	$(CP) $< $@

define rtg_where_value_binding_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_where_value_binding.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_binding_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_binding_tests.c
	$(CP) $< $@

define rtg_where_value_binding_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_where_value_binding_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list.h \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list.c
	$(CP) $< $@

define rtg_where_value_bindings_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_where_value_bindings_simple_list.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list_tests.c
	$(CP) $< $@

define rtg_where_value_bindings_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/rtg_where_value_bindings_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/ftr/stdio_ninety_nine_modernizer.$(HEXT): \
		$(SRC_DIR)/ftr/stdio_ninety_nine_modernizer.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT): \
		$(SRC_DIR)/stt/stt_application.h \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_application.$(CEXT): \
		$(SRC_DIR)/stt/stt_application.c
	$(CP) $< $@

define stt_application_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_application.o: \
		$$(BUILD_DIR_SRC)/stt/stt_application.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_application.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_application_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_application_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_application_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_application_subnode.c
	$(CP) $< $@

define stt_application_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_application_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_application_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_application_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_application_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_application_subnode_tests.c
	$(CP) $< $@

define stt_application_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_application_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_application_subnode.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_application_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_application_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_application_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_application_tests.c
	$(CP) $< $@

define stt_application_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_application_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_application_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_application_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_application.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT): \
		$(SRC_DIR)/stt/stt_applications_simple_list.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(CEXT): \
		$(SRC_DIR)/stt/stt_applications_simple_list.c
	$(CP) $< $@

define stt_applications_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_applications_simple_list.o: \
		$$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_application.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_applications_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_applications_simple_list_tests.c
	$(CP) $< $@

define stt_applications_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_applications_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_application_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT): \
		$(SRC_DIR)/stt/stt_condition.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_condition.$(CEXT): \
		$(SRC_DIR)/stt/stt_condition.c
	$(CP) $< $@

define stt_condition_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_condition.o: \
		$$(BUILD_DIR_SRC)/stt/stt_condition.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_condition.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_forward_declarations.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_condition_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_condition_subnode.c \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT)
	$(CP) $< $@

define stt_condition_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_condition_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_condition.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_condition_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_condition_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_condition_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_condition_subnode_tests.c
	$(CP) $< $@

define stt_condition_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_condition_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_condition_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_condition_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_condition_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_condition_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_condition_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_condition_tests.c
	$(CP) $< $@

define stt_condition_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_condition_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_condition_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_condition_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_condition.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_dice_expression.$(HEXT): \
		$(SRC_DIR)/stt/stt_dice_expression.h \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_dice_expression.$(CEXT): \
		$(SRC_DIR)/stt/stt_dice_expression.c
	$(CP) $< $@

define stt_dice_expression_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_dice_expression.o: \
		$$(BUILD_DIR_SRC)/stt/stt_dice_expression.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_dice_expression.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_dice_expression_tests.h \
		$(BUILD_DIR_SRC)/brt/natural_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_dice_expression_tests.c
	$(CP) $< $@

define stt_dice_expression_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_dice_expression_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_dice_expression.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_doc_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_doc_subnode.c
	$(CP) $< $@

define stt_doc_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_doc_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_doc_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_doc_subnode_tests.c
	$(CP) $< $@

define stt_doc_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_doc_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_execution_request.$(HEXT): \
		$(SRC_DIR)/stt/stt_execution_request.h \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_execution_request.$(CEXT): \
		$(SRC_DIR)/stt/stt_execution_request.c
	$(CP) $< $@

define stt_execution_request_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_execution_request.o: \
		$$(BUILD_DIR_SRC)/stt/stt_execution_request.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_request.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_execution_request_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_execution_request.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_execution_request_subnode.c
	$(CP) $< $@

define stt_execution_request_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_execution_request_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_execution_request_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_execution_request_subnode_tests.c
	$(CP) $< $@

define stt_execution_request_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_execution_request_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_execution_request_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_execution_request_tests.c
	$(CP) $< $@

define stt_execution_request_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_execution_request_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_request.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT): \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list.h \
		$(BUILD_DIR_SRC)/stt/stt_execution_request.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(CEXT): \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list.c
	$(CP) $< $@

define stt_execution_requests_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_execution_requests_simple_list.o: \
		$$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_request.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list_tests.c
	$(CP) $< $@

define stt_execution_requests_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_execution_requests_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression.h \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_natural_literal.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression.c
	$(CP) $< $@

define stt_expression_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression.o: \
		$$(BUILD_DIR_SRC)/stt/stt_expression.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_conditional.h \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_conditional.c
	$(CP) $< $@

define stt_expression_sub_conditional_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_conditional.o: \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$$(HEXT) \
		$$(BUILD_DIR_SRC)/definitions.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_conditional_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_condition_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_conditional_tests.c
	$(CP) $< $@

define stt_expression_sub_conditional_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_conditional_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_dice.h \
		$(BUILD_DIR_SRC)/brt/brt_forward_declarations.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_dice.c
	$(CP) $< $@

define stt_expression_sub_dice_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_dice.o: \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_dice_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_dice_tests.c
	$(CP) $< $@

define stt_expression_sub_dice_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_dice_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_identifier.h \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_identifier.c
	$(CP) $< $@

define stt_expression_sub_identifier_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_identifier.o: \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_identifier_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_identifier_tests.c
	$(CP) $< $@

define stt_expression_sub_identifier_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_identifier_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_expression_sub_natural_literal.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_natural_literal.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_natural_literal.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_natural_literal.c
	$(CP) $< $@

define stt_expression_sub_natural_literal_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_natural_literal.o: \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_natural_literal.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_natural_literal.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_string_literal.h \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_string_literal.c
	$(CP) $< $@

define stt_expression_sub_string_literal_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_sub_string_literal.o: \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_subnode.c
	$(CP) $< $@

define stt_expression_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_expression_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_subnode_tests.c
	$(CP) $< $@

define stt_expression_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_expression_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_expression_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_tests.c \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$(HEXT)
	$(CP) $< $@

define stt_expression_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_expression_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_expression_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_function.h \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_function.$(CEXT): \
		$(SRC_DIR)/stt/stt_named_function.c
	$(CP) $< $@

define stt_named_function_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_function.o: \
		$$(BUILD_DIR_SRC)/stt/stt_named_function.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_named_function_call.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_function_call.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_function_call.$(CEXT): \
		$(SRC_DIR)/stt/stt_named_function_call.c
	$(CP) $< $@

define stt_named_function_call_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_function_call.o: \
		$$(BUILD_DIR_SRC)/stt/stt_named_function_call.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function_call.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_named_function_call_arguments.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_function_call_arguments.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_function_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_named_function_subnode.c
	$(CP) $< $@

define stt_named_function_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_function_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_function_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_named_function_subnode_tests.c
	$(CP) $< $@

define stt_named_function_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_function_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_function_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_named_function_tests.c
	$(CP) $< $@

define stt_named_function_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_function_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(CEXT): \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.c
	$(CP) $< $@

define stt_named_functions_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_functions_simple_list.o: \
		$$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_functions_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_named_functions_simple_list_tests.c
	$(CP) $< $@

define stt_named_functions_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_named_functions_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_identifier_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_identifier_subnode.c
	$(CP) $< $@

define stt_identifier_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_identifier_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_identifier_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_identifier_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_identifier_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_identifier_subnode_tests.c
	$(CP) $< $@

define stt_identifier_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_identifier_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_identifier_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_identifier_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_integer_literal_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_integer_literal_subnode.c
	$(CP) $< $@

define stt_integer_literal_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_integer_literal_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/integer.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_integer_literal_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_integer_literal_subnode_tests.c
	$(CP) $< $@

define stt_integer_literal_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_integer_literal_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/integer.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_natural_literal_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_natural_literal_subnode.c
	$(CP) $< $@

define stt_natural_literal_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_natural_literal_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_natural_literal_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_natural_literal_subnode_tests.c
	$(CP) $< $@

define stt_natural_literal_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_natural_literal_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_forward_declarations.$(HEXT): \
		$(SRC_DIR)/stt/stt_forward_declarations.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT): \
		$(SRC_DIR)/stt/stt_node.h \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_forward_declarations.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node_sub_named_function_call.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node_sub_named_function_call_arguments.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_node.$(CEXT): \
		$(SRC_DIR)/stt/stt_node.c
	$(CP) $< $@

define stt_node_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_node.o: \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/char_array.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_node_sub_named_function_call.$(HEXT): \
		$(SRC_DIR)/stt/stt_node_sub_named_function_call.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_node_sub_named_function_call.$(CEXT): \
		$(SRC_DIR)/stt/stt_node_sub_named_function_call.c
	$(CP) $< $@

define stt_node_sub_named_function_call_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_node_sub_named_function_call.o: \
		$$(BUILD_DIR_SRC)/stt/stt_node_sub_named_function_call.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node_sub_named_function_call.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_node_sub_named_function_call_arguments.$(HEXT): \
		$(SRC_DIR)/stt/stt_node_sub_named_function_call_arguments.h \
		$(BUILD_DIR_SRC)/stt/stt_named_function_call_arguments.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_node_sub_named_function_call_arguments.$(CEXT): \
		$(SRC_DIR)/stt/stt_node_sub_named_function_call_arguments.c
	$(CP) $< $@

define stt_node_sub_named_function_call_arguments_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_node_sub_named_function_call_arguments.o: \
		$$(BUILD_DIR_SRC)/stt/stt_node_sub_named_function_call_arguments.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node_sub_named_function_call_arguments.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_node_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_node_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_node_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_node_tests.c
	$(CP) $< $@

define stt_node_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_node_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_node_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/char_array.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation.h \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation.c
	$(CP) $< $@

define stt_operation_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation.o: \
		$$(BUILD_DIR_SRC)/stt/stt_operation.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_arg.h \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_arg.c
	$(CP) $< $@

define stt_operation_arg_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_arg.o: \
		$$(BUILD_DIR_SRC)/stt/stt_operation_arg.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_arg.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_arg_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_arg_tests.c
	$(CP) $< $@

define stt_operation_arg_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_arg_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_arg.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_args_simple_list.h \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_args_simple_list.c
	$(CP) $< $@

define stt_operation_args_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_args_simple_list.o: \
		$$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_arg.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_args_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_args_simple_list_tests.c
	$(CP) $< $@

define stt_operation_args_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_args_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_subnode.c
	$(CP) $< $@

define stt_operation_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_operation_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_subnode_tests.c
	$(CP) $< $@

define stt_operation_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_operation_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_tests.c
	$(CP) $< $@

define stt_operation_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_operation_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_operation_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_operations_list_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_operations_list_subnode.c
	$(CP) $< $@

define stt_operations_list_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_operations_list_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_operations_list_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_operations_list_subnode_tests.c
	$(CP) $< $@

define stt_operations_list_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_operations_list_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT): \
		$(SRC_DIR)/stt/stt_operations_simple_list.h \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/definitions.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(CEXT): \
		$(SRC_DIR)/stt/stt_operations_simple_list.c
	$(CP) $< $@

define stt_operations_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_operations_simple_list.o: \
		$$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_operations_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_operations_simple_list_tests.c
	$(CP) $< $@

define stt_operations_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_operations_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_operation_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_rational_literal_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_rational_literal_subnode.c
	$(CP) $< $@

define stt_rational_literal_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_rational_literal_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/natural.$$(HEXT) \
		$$(BUILD_DIR_SRC)/brt/rational.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_rational_literal_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_rational_literal_subnode_tests.c
	$(CP) $< $@

define stt_rational_literal_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_rational_literal_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_string_literal_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_string_literal_subnode.c
	$(CP) $< $@

define stt_string_literal_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_string_literal_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_boolean.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_string_literal_subnode_tests.h \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_string_literal_subnode_tests.c
	$(CP) $< $@

define stt_string_literal_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_string_literal_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_boolean.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_tests.c \
		$(BUILD_DIR_SRC)/stt/stt_node_tests.$(HEXT)
	$(CP) $< $@

define stt_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_node_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding.h \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding.c
	$(CP) $< $@

define stt_where_value_binding_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_binding.o: \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$$(HEXT) \
		$$(BUILD_DIR_SRC)/cmn/amara_string.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_expression.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode.c
	$(CP) $< $@

define stt_where_value_binding_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_binding_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode_tests.c
	$(CP) $< $@

define stt_where_value_binding_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_binding_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding_tests.c
	$(CP) $< $@

define stt_where_value_binding_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_binding_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list.h \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list.c
	$(CP) $< $@

define stt_where_value_bindings_simple_list_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_bindings_simple_list.o: \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list_tests.c
	$(CP) $< $@

define stt_where_value_bindings_simple_list_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_bindings_simple_list_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode.c
	$(CP) $< $@

define stt_where_value_bindings_subnode_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_bindings_subnode.o: \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode_tests.c
	$(CP) $< $@

define stt_where_value_bindings_subnode_tests_OBJ_RULE
$$(BUILD_DIR_$(BUILD_TYPE))/stt_where_value_bindings_subnode_tests.o: \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$$(CEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$$(HEXT) \
		$$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$$(HEXT) \
		$$(BUILD_DIR_SRC)/asr/assertion.$$(HEXT)
	$$(C) $$(CFLAGS) $$(CFLAGS_$(BUILD_TYPE)) -c -o $$@ $$<
endef

#   This GNU Make definition:
#
#     define debug_release_loop
#     $$(foreach BUILD_TYPE, DEBUG RELEASE, $$(eval $$($(DOC)_OBJ_RULE)))
#     endef
#
#   When looping on $(DOC) for values `amara_string`,
# `amara_string_tests`, `amara_strings_simple_list`... etc; is going to
# unfold into:
#
#     $(foreach BUILD_TYPE, DEBUG RELEASE, $(eval $(amara_string_OBJ_RULE)))
#     $(foreach BUILD_TYPE, DEBUG RELEASE, $(eval $(amara_string_tests_OBJ_RULE)))
#     $(foreach BUILD_TYPE, DEBUG RELEASE, $(eval $(amara_strings_simple_list_OBJ_RULE)))
#     [...]
#
define debug_release_loop
$$(foreach BUILD_TYPE, DEBUG RELEASE, $$(eval $$($(DOC)_OBJ_RULE)))
endef

$(foreach DOC, \
	allocator \
	amara_string amara_string_tests \
	amara_strings_simple_list amara_strings_simple_list_tests \
	arg \
	assertion \
	basic_arithmetic_tests \
	bison_annex \
	bison_tests \
	char_array char_array_tests \
	char_arrays_simple_list char_arrays_simple_list_tests \
	common_tests \
	main \
	lex.minia \
	minia.tab \
	natural natural_tests \
	integer integer_tests \
	rational rational_tests \
	app_runner app_runner_tests \
	arn_tests \
	arn_type arn_type_tests \
	arn_value arn_value_tests \
	arn_values_fixed_list arn_values_fixed_list_tests \
	arn_values_simple_list arn_values_simple_list_tests \
	arn_variable arn_variable_tests \
	arn_variables_simple_list arn_variables_simple_list_tests \
	flex_tests \
	logging \
	persistence persistence_tests \
	tests_pseudo_random_numbers_generation tests_pseudo_random_numbers_generation_tests \
	tests_runner \
	tests_simple_list tests_simple_list_tests \
	dirent_wrapper \
	rtg_application rtg_application_tests \
	rtg_applications_simple_list rtg_applications_simple_list_tests \
	rtg_condition rtg_condition_tests \
	rtg_doc rtg_doc_tests \
	rtg_execution_request rtg_execution_request_tests \
	rtg_execution_requests_simple_list rtg_execution_requests_simple_list_tests \
	rtg_expression rtg_expression_tests \
	rtg_expression_sub_conditional rtg_expression_sub_conditional_tests \
	rtg_expression_sub_dice rtg_expression_sub_dice_tests \
	rtg_expression_sub_identifier rtg_expression_sub_identifier_tests \
	rtg_expression_sub_natural_literal \
	rtg_expression_sub_string_literal \
	rtg_named_function rtg_named_function_tests \
	rtg_named_function_call \
	rtg_named_functions_simple_list rtg_named_functions_simple_list_tests \
	rtg_operation rtg_operation_tests \
	rtg_operation_arg rtg_operation_arg_tests \
	rtg_operation_args_simple_list rtg_operation_args_simple_list_tests \
	rtg_operations_simple_list rtg_operations_simple_list_tests \
	rtg_tests \
	rtg_where_value_binding rtg_where_value_binding_tests \
	rtg_where_value_bindings_simple_list rtg_where_value_bindings_simple_list_tests \
	stt_application stt_application_tests \
	stt_application_subnode stt_application_subnode_tests \
	stt_applications_simple_list stt_applications_simple_list_tests \
	stt_condition stt_condition_tests \
	stt_condition_subnode stt_condition_subnode_tests \
	stt_dice_expression stt_dice_expression_tests \
	stt_doc_subnode stt_doc_subnode_tests \
	stt_execution_request stt_execution_request_tests \
	stt_execution_request_subnode stt_execution_request_subnode_tests \
	stt_execution_requests_simple_list stt_execution_requests_simple_list_tests \
	stt_expression stt_expression_tests \
	stt_expression_sub_conditional stt_expression_sub_conditional_tests \
	stt_expression_sub_dice stt_expression_sub_dice_tests \
	stt_expression_sub_identifier stt_expression_sub_identifier_tests \
	stt_expression_sub_natural_literal \
	stt_expression_sub_string_literal \
	stt_expression_subnode stt_expression_subnode_tests \
	stt_named_function stt_named_function_tests \
	stt_named_function_call \
	stt_named_function_subnode stt_named_function_subnode_tests \
	stt_named_functions_simple_list stt_named_functions_simple_list_tests \
	stt_identifier_subnode stt_identifier_subnode_tests \
	stt_integer_literal_subnode stt_integer_literal_subnode_tests \
	stt_natural_literal_subnode stt_natural_literal_subnode_tests \
	stt_node stt_node_tests \
	stt_node_sub_named_function_call \
	stt_node_sub_named_function_call_arguments \
	stt_operation stt_operation_tests \
	stt_operation_arg stt_operation_arg_tests \
	stt_operation_args_simple_list stt_operation_args_simple_list_tests \
	stt_operation_subnode stt_operation_subnode_tests \
	stt_operations_list_subnode stt_operations_list_subnode_tests \
	stt_operations_simple_list stt_operations_simple_list_tests \
	stt_rational_literal_subnode stt_rational_literal_subnode_tests \
	stt_string_literal_subnode stt_string_literal_subnode_tests \
	stt_tests \
	stt_where_value_binding stt_where_value_binding_tests \
	stt_where_value_binding_subnode stt_where_value_binding_subnode_tests \
	stt_where_value_bindings_simple_list stt_where_value_bindings_simple_list_tests \
	stt_where_value_bindings_subnode stt_where_value_bindings_subnode_tests \
	, $(eval $(debug_release_loop)))

# TODO   Fix `utils/grammar/bison_extractor.py` into accepting (requiring, actually) `-i` and `-o` parameters, then simplify this sh.
$(RESOURCES_DIR)/minia.grammar: $(SRC_DIR)/bsn/minia.y
	pwd && \
			cd $(UTILS_DIR)/grammar/ && \
			pwd && \
			./bison_extractor.py && \
			cd ../../ && \
			pwd

.PHONY: \
		all \
		clean \
		default \
		checkdirs \
		amara \
		amara_g \
		release \
		debug

clean:
	rm -fv \
			$(SRC_DIR)/bsn/minia.tab.c \
			$(SRC_DIR)/bsn/minia.tab.cpp \
			$(SRC_DIR)/bsn/lex.minia.c \
			$(SRC_DIR)/bsn/lex.minia.cpp \
			$(SRC_DIR)/bsn/minia.tab.h \
			$(BUILD_DIR_SRC)/*.c \
			$(BUILD_DIR_SRC)/*.cpp \
			$(BUILD_DIR_SRC)/*/*.c \
			$(BUILD_DIR_SRC)/*/*.cpp \
			$(BUILD_DIR_SRC)/*/*.h \
			$(BUILD_DIR_RELEASE)/amara_not_stripped \
			$(BUILD_DIR_RELEASE)/amara \
			$(BUILD_DIR_DEBUG)/amara_g \
			$(BUILD_DIR_DEBUG)/stripped_amara_g \
			$(BUILD_DIR_RELEASE)/*.o \
			$(BUILD_DIR_DEBUG)/*.o \
			$(BUILD_DIR_DEBUG)/*.gcno \
			$(BUILD_DIR_DEBUG)/*.gcda
	rm -rfv $(BUILD_DIR_RELEASE)
	rm -rfv $(BUILD_DIR_DEBUG)
	rm -rfv $(BUILD_DIR_SRC)
	rm -rfv $(BUILD_DIR)
