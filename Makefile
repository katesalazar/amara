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

CFLAGS_GENERAL += -pedantic -Wall -Wextra
# $(info $(CFLAGS_GENERAL))
CFLAGS_PARTICULAR_FLEX += -pedantic -Wall -Wextra
# $(info $(CFLAGS_PARTICULAR_FLEX))

#   `-Werror`: Maybe this is causing issues to the `flex` output doc..?
CFLAGS_GENERAL += -Werror
# $(info $(CFLAGS_GENERAL))
# TODO    Here the differential condition is probably not the Darwin OS
# TODO  but some particular `flex` version.
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

#   This for legacy compatibility...
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
CC ?= gcc
CXX ?= g++
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
    CEXT = cpp
    HEXT = h
    CFLAGS_GENERAL += -std=c++98 -DAMARA_USE_STD_CXX98
    CFLAGS_PARTICULAR_FLEX += -std=c++98 -DAMARA_USE_STD_CXX98
else
    ifeq ($(C), clang++)
        CEXT = cpp
        HEXT = h
        CFLAGS_GENERAL += -std=c++98 -DAMARA_USE_STD_CXX98
        CFLAGS_PARTICULAR_FLEX += -std=c++98 -DAMARA_USE_STD_CXX98
    else
        CEXT = c
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
OBJ_DEBUG = \
		$(BUILD_DIR_DEBUG)/amara_string.o \
		$(BUILD_DIR_DEBUG)/amara_string_tests.o \
		$(BUILD_DIR_DEBUG)/amara_strings_simple_list.o \
		$(BUILD_DIR_DEBUG)/amara_strings_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/app_runner.o \
		$(BUILD_DIR_DEBUG)/app_runner_tests.o \
		$(BUILD_DIR_DEBUG)/arn_tests.o \
		$(BUILD_DIR_DEBUG)/arn_type.o \
		$(BUILD_DIR_DEBUG)/arn_type_tests.o \
		$(BUILD_DIR_DEBUG)/arn_value.o \
		$(BUILD_DIR_DEBUG)/arn_value_tests.o \
		$(BUILD_DIR_DEBUG)/arn_values_fixed_list.o \
		$(BUILD_DIR_DEBUG)/arn_values_fixed_list_tests.o \
		$(BUILD_DIR_DEBUG)/arn_values_simple_list.o \
		$(BUILD_DIR_DEBUG)/arn_values_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/arn_variable.o \
		$(BUILD_DIR_DEBUG)/arn_variable_tests.o \
		$(BUILD_DIR_DEBUG)/arn_variables_simple_list.o \
		$(BUILD_DIR_DEBUG)/arn_variables_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/arg.o \
		$(BUILD_DIR_DEBUG)/assertion.o \
		$(BUILD_DIR_DEBUG)/basic_arithmetic_tests.o \
		$(BUILD_DIR_DEBUG)/bison_annex.o \
		$(BUILD_DIR_DEBUG)/bison_tests.o \
		$(BUILD_DIR_DEBUG)/char_array.o \
		$(BUILD_DIR_DEBUG)/char_array_tests.o \
		$(BUILD_DIR_DEBUG)/char_arrays_simple_list.o \
		$(BUILD_DIR_DEBUG)/char_arrays_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/common_tests.o \
		$(BUILD_DIR_DEBUG)/logging.o \
		$(BUILD_DIR_DEBUG)/dirent_wrapper.o \
		$(BUILD_DIR_DEBUG)/flex_tests.o \
		$(BUILD_DIR_DEBUG)/integer.o \
		$(BUILD_DIR_DEBUG)/integer_tests.o \
		$(BUILD_DIR_DEBUG)/main.o \
		$(BUILD_DIR_DEBUG)/lex.minia.o \
		$(BUILD_DIR_DEBUG)/minia.tab.o \
		$(BUILD_DIR_DEBUG)/natural.o \
		$(BUILD_DIR_DEBUG)/natural_tests.o \
		$(BUILD_DIR_DEBUG)/persistence.o \
		$(BUILD_DIR_DEBUG)/persistence_tests.o \
		$(BUILD_DIR_DEBUG)/rational.o \
		$(BUILD_DIR_DEBUG)/rational_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_application.o \
		$(BUILD_DIR_DEBUG)/rtg_application_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_applications_simple_list.o \
		$(BUILD_DIR_DEBUG)/rtg_applications_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_condition.o \
		$(BUILD_DIR_DEBUG)/rtg_condition_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_doc.o \
		$(BUILD_DIR_DEBUG)/rtg_doc_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_execution_request.o \
		$(BUILD_DIR_DEBUG)/rtg_execution_request_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_execution_requests_simple_list.o \
		$(BUILD_DIR_DEBUG)/rtg_execution_requests_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_expression.o \
		$(BUILD_DIR_DEBUG)/rtg_expression_sub_conditional.o \
		$(BUILD_DIR_DEBUG)/rtg_expression_sub_conditional_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_expression_sub_dice.o \
		$(BUILD_DIR_DEBUG)/rtg_expression_sub_dice_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_expression_sub_identifier.o \
		$(BUILD_DIR_DEBUG)/rtg_expression_sub_identifier_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_expression_sub_natural_literal.o \
		$(BUILD_DIR_DEBUG)/rtg_expression_sub_string_literal.o \
		$(BUILD_DIR_DEBUG)/rtg_expression_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_named_function.o \
		$(BUILD_DIR_DEBUG)/rtg_named_function_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_named_functions_simple_list.o \
		$(BUILD_DIR_DEBUG)/rtg_named_functions_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_operation.o \
		$(BUILD_DIR_DEBUG)/rtg_operation_arg.o \
		$(BUILD_DIR_DEBUG)/rtg_operation_arg_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_operation_args_simple_list.o \
		$(BUILD_DIR_DEBUG)/rtg_operation_args_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_operation_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_operations_simple_list.o \
		$(BUILD_DIR_DEBUG)/rtg_operations_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_where_value_binding.o \
		$(BUILD_DIR_DEBUG)/rtg_where_value_binding_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_where_value_bindings_simple_list.o \
		$(BUILD_DIR_DEBUG)/rtg_where_value_bindings_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/rtg_tests.o \
		$(BUILD_DIR_DEBUG)/tests_pseudo_random_numbers_generation.o \
		$(BUILD_DIR_DEBUG)/tests_pseudo_random_numbers_generation_tests.o \
		$(BUILD_DIR_DEBUG)/tests_runner.o \
		$(BUILD_DIR_DEBUG)/tests_simple_list.o \
		$(BUILD_DIR_DEBUG)/stt_application.o \
		$(BUILD_DIR_DEBUG)/stt_application_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_application_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_application_tests.o \
		$(BUILD_DIR_DEBUG)/stt_applications_simple_list.o \
		$(BUILD_DIR_DEBUG)/stt_applications_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/stt_condition.o \
		$(BUILD_DIR_DEBUG)/stt_condition_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_condition_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_condition_tests.o \
		$(BUILD_DIR_DEBUG)/stt_dice_expression.o \
		$(BUILD_DIR_DEBUG)/stt_dice_expression_tests.o \
		$(BUILD_DIR_DEBUG)/stt_doc_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_doc_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_execution_request.o \
		$(BUILD_DIR_DEBUG)/stt_execution_request_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_execution_request_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_execution_request_tests.o \
		$(BUILD_DIR_DEBUG)/stt_execution_requests_simple_list.o \
		$(BUILD_DIR_DEBUG)/stt_execution_requests_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/stt_expression.o \
		$(BUILD_DIR_DEBUG)/stt_expression_sub_conditional.o \
		$(BUILD_DIR_DEBUG)/stt_expression_sub_conditional_tests.o \
		$(BUILD_DIR_DEBUG)/stt_expression_sub_dice.o \
		$(BUILD_DIR_DEBUG)/stt_expression_sub_dice_tests.o \
		$(BUILD_DIR_DEBUG)/stt_expression_sub_identifier.o \
		$(BUILD_DIR_DEBUG)/stt_expression_sub_identifier_tests.o \
		$(BUILD_DIR_DEBUG)/stt_expression_sub_natural_literal.o \
		$(BUILD_DIR_DEBUG)/stt_expression_sub_string_literal.o \
		$(BUILD_DIR_DEBUG)/stt_expression_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_expression_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_expression_tests.o \
		$(BUILD_DIR_DEBUG)/stt_named_function.o \
		$(BUILD_DIR_DEBUG)/stt_named_function_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_named_function_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_named_function_tests.o \
		$(BUILD_DIR_DEBUG)/stt_named_functions_simple_list.o \
		$(BUILD_DIR_DEBUG)/stt_named_functions_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/stt_identifier_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_identifier_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_integer_literal_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_integer_literal_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_natural_literal_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_natural_literal_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_node.o \
		$(BUILD_DIR_DEBUG)/stt_node_tests.o \
		$(BUILD_DIR_DEBUG)/stt_operation.o \
		$(BUILD_DIR_DEBUG)/stt_operation_arg.o \
		$(BUILD_DIR_DEBUG)/stt_operation_arg_tests.o \
		$(BUILD_DIR_DEBUG)/stt_operation_args_simple_list.o \
		$(BUILD_DIR_DEBUG)/stt_operation_args_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/stt_operation_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_operation_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_operation_tests.o \
		$(BUILD_DIR_DEBUG)/stt_operations_list_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_operations_list_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_operations_simple_list.o \
		$(BUILD_DIR_DEBUG)/stt_operations_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/stt_rational_literal_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_rational_literal_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_string_literal_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_string_literal_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_tests.o \
		$(BUILD_DIR_DEBUG)/stt_where_value_binding.o \
		$(BUILD_DIR_DEBUG)/stt_where_value_binding_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_where_value_binding_subnode_tests.o \
		$(BUILD_DIR_DEBUG)/stt_where_value_binding_tests.o \
		$(BUILD_DIR_DEBUG)/stt_where_value_bindings_simple_list.o \
		$(BUILD_DIR_DEBUG)/stt_where_value_bindings_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/stt_where_value_bindings_subnode.o \
		$(BUILD_DIR_DEBUG)/stt_where_value_bindings_subnode_tests.o
OBJ_RELEASE = \
		$(BUILD_DIR_RELEASE)/amara_string.o \
		$(BUILD_DIR_RELEASE)/amara_string_tests.o \
		$(BUILD_DIR_RELEASE)/amara_strings_simple_list.o \
		$(BUILD_DIR_RELEASE)/amara_strings_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/app_runner.o \
		$(BUILD_DIR_RELEASE)/app_runner_tests.o \
		$(BUILD_DIR_RELEASE)/arn_tests.o \
		$(BUILD_DIR_RELEASE)/arn_type.o \
		$(BUILD_DIR_RELEASE)/arn_type_tests.o \
		$(BUILD_DIR_RELEASE)/arn_value.o \
		$(BUILD_DIR_RELEASE)/arn_value_tests.o \
		$(BUILD_DIR_RELEASE)/arn_values_fixed_list.o \
		$(BUILD_DIR_RELEASE)/arn_values_fixed_list_tests.o \
		$(BUILD_DIR_RELEASE)/arn_values_simple_list.o \
		$(BUILD_DIR_RELEASE)/arn_values_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/arn_variable.o \
		$(BUILD_DIR_RELEASE)/arn_variable_tests.o \
		$(BUILD_DIR_RELEASE)/arn_variables_simple_list.o \
		$(BUILD_DIR_RELEASE)/arn_variables_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/arg.o \
		$(BUILD_DIR_RELEASE)/assertion.o \
		$(BUILD_DIR_RELEASE)/basic_arithmetic_tests.o \
		$(BUILD_DIR_RELEASE)/bison_annex.o \
		$(BUILD_DIR_RELEASE)/bison_tests.o \
		$(BUILD_DIR_RELEASE)/char_array.o \
		$(BUILD_DIR_RELEASE)/char_array_tests.o \
		$(BUILD_DIR_RELEASE)/char_arrays_simple_list.o \
		$(BUILD_DIR_RELEASE)/char_arrays_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/common_tests.o \
		$(BUILD_DIR_RELEASE)/logging.o \
		$(BUILD_DIR_RELEASE)/dirent_wrapper.o \
		$(BUILD_DIR_RELEASE)/flex_tests.o \
		$(BUILD_DIR_RELEASE)/integer.o \
		$(BUILD_DIR_RELEASE)/integer_tests.o \
		$(BUILD_DIR_RELEASE)/main.o \
		$(BUILD_DIR_RELEASE)/lex.minia.o \
		$(BUILD_DIR_RELEASE)/minia.tab.o \
		$(BUILD_DIR_RELEASE)/natural.o \
		$(BUILD_DIR_RELEASE)/natural_tests.o \
		$(BUILD_DIR_RELEASE)/persistence.o \
		$(BUILD_DIR_RELEASE)/persistence_tests.o \
		$(BUILD_DIR_RELEASE)/rational.o \
		$(BUILD_DIR_RELEASE)/rational_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_application.o \
		$(BUILD_DIR_RELEASE)/rtg_application_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_applications_simple_list.o \
		$(BUILD_DIR_RELEASE)/rtg_applications_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_condition.o \
		$(BUILD_DIR_RELEASE)/rtg_condition_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_doc.o \
		$(BUILD_DIR_RELEASE)/rtg_doc_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_execution_request.o \
		$(BUILD_DIR_RELEASE)/rtg_execution_request_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_execution_requests_simple_list.o \
		$(BUILD_DIR_RELEASE)/rtg_execution_requests_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_expression.o \
		$(BUILD_DIR_RELEASE)/rtg_expression_sub_conditional.o \
		$(BUILD_DIR_RELEASE)/rtg_expression_sub_conditional_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_expression_sub_dice.o \
		$(BUILD_DIR_RELEASE)/rtg_expression_sub_dice_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_expression_sub_identifier.o \
		$(BUILD_DIR_RELEASE)/rtg_expression_sub_identifier_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_expression_sub_natural_literal.o \
		$(BUILD_DIR_RELEASE)/rtg_expression_sub_string_literal.o \
		$(BUILD_DIR_RELEASE)/rtg_expression_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_named_function.o \
		$(BUILD_DIR_RELEASE)/rtg_named_function_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_named_functions_simple_list.o \
		$(BUILD_DIR_RELEASE)/rtg_named_functions_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_operation.o \
		$(BUILD_DIR_RELEASE)/rtg_operation_arg.o \
		$(BUILD_DIR_RELEASE)/rtg_operation_arg_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_operation_args_simple_list.o \
		$(BUILD_DIR_RELEASE)/rtg_operation_args_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_operation_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_operations_simple_list.o \
		$(BUILD_DIR_RELEASE)/rtg_operations_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_where_value_binding.o \
		$(BUILD_DIR_RELEASE)/rtg_where_value_binding_tests.o \
		$(BUILD_DIR_RELEASE)/rtg_where_value_bindings_simple_list.o \
		$(BUILD_DIR_RELEASE)/rtg_where_value_bindings_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/tests_pseudo_random_numbers_generation.o \
		$(BUILD_DIR_RELEASE)/tests_pseudo_random_numbers_generation_tests.o \
		$(BUILD_DIR_RELEASE)/tests_runner.o \
		$(BUILD_DIR_RELEASE)/tests_simple_list.o \
		$(BUILD_DIR_RELEASE)/stt_application.o \
		$(BUILD_DIR_RELEASE)/stt_application_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_application_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_application_tests.o \
		$(BUILD_DIR_RELEASE)/stt_applications_simple_list.o \
		$(BUILD_DIR_RELEASE)/stt_applications_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/stt_condition.o \
		$(BUILD_DIR_RELEASE)/stt_condition_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_condition_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_condition_tests.o \
		$(BUILD_DIR_RELEASE)/stt_dice_expression.o \
		$(BUILD_DIR_RELEASE)/stt_dice_expression_tests.o \
		$(BUILD_DIR_RELEASE)/stt_doc_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_doc_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_execution_request.o \
		$(BUILD_DIR_RELEASE)/stt_execution_request_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_execution_request_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_execution_request_tests.o \
		$(BUILD_DIR_RELEASE)/stt_execution_requests_simple_list.o \
		$(BUILD_DIR_RELEASE)/stt_execution_requests_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/stt_expression.o \
		$(BUILD_DIR_RELEASE)/stt_expression_sub_conditional.o \
		$(BUILD_DIR_RELEASE)/stt_expression_sub_conditional_tests.o \
		$(BUILD_DIR_RELEASE)/stt_expression_sub_dice.o \
		$(BUILD_DIR_RELEASE)/stt_expression_sub_dice_tests.o \
		$(BUILD_DIR_RELEASE)/stt_expression_sub_identifier.o \
		$(BUILD_DIR_RELEASE)/stt_expression_sub_identifier_tests.o \
		$(BUILD_DIR_RELEASE)/stt_expression_sub_natural_literal.o \
		$(BUILD_DIR_RELEASE)/stt_expression_sub_string_literal.o \
		$(BUILD_DIR_RELEASE)/stt_expression_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_expression_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_expression_tests.o \
		$(BUILD_DIR_RELEASE)/stt_named_function.o \
		$(BUILD_DIR_RELEASE)/stt_named_function_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_named_function_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_named_function_tests.o \
		$(BUILD_DIR_RELEASE)/stt_named_functions_simple_list.o \
		$(BUILD_DIR_RELEASE)/stt_named_functions_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/stt_identifier_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_identifier_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_integer_literal_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_integer_literal_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_natural_literal_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_natural_literal_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_node.o \
		$(BUILD_DIR_RELEASE)/stt_node_tests.o \
		$(BUILD_DIR_RELEASE)/stt_operation.o \
		$(BUILD_DIR_RELEASE)/stt_operation_arg.o \
		$(BUILD_DIR_RELEASE)/stt_operation_arg_tests.o \
		$(BUILD_DIR_RELEASE)/stt_operation_args_simple_list.o \
		$(BUILD_DIR_RELEASE)/stt_operation_args_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/stt_operation_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_operation_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_operation_tests.o \
		$(BUILD_DIR_RELEASE)/stt_operations_list_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_operations_list_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_operations_simple_list.o \
		$(BUILD_DIR_RELEASE)/stt_operations_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/stt_rational_literal_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_rational_literal_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_string_literal_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_string_literal_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_tests.o \
		$(BUILD_DIR_RELEASE)/stt_where_value_binding.o \
		$(BUILD_DIR_RELEASE)/stt_where_value_binding_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_where_value_binding_subnode_tests.o \
		$(BUILD_DIR_RELEASE)/stt_where_value_binding_tests.o \
		$(BUILD_DIR_RELEASE)/stt_where_value_bindings_simple_list.o \
		$(BUILD_DIR_RELEASE)/stt_where_value_bindings_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/stt_where_value_bindings_subnode.o \
		$(BUILD_DIR_RELEASE)/stt_where_value_bindings_subnode_tests.o
DEBUG_RESOURCES = \
		$(RESOURCES_DIR)/minia.grammar

default: \
	checkdirs \
	$(BUILD_DIR_RELEASE)/amara

all: \
	checkdirs \
	$(BUILD_DIR_RELEASE)/amara \
	$(BUILD_DIR_RELEASE)/amara_not_stripped \
	$(BUILD_DIR_DEBUG)/amara_g \
	$(BUILD_DIR_DEBUG)/amara_g_not_stripped

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
	$(BUILD_DIR_SRC)/prs \
	$(BUILD_DIR_SRC)/rtg \
	$(BUILD_DIR_SRC)/stt \
	$(BUILD_DIR_SRC)/tst \
	$(BUILD_DIR_SRC)/wrp \
	$(BUILD_DIR_RELEASE) \
	$(BUILD_DIR_DEBUG)

$(BUILD_DIR):
	mkdir $@

$(BUILD_DIR_SRC):
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_SRC)/arn:
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_SRC)/asr:
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_SRC)/brt:
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_SRC)/bsn:
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_SRC)/cmn:
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_SRC)/ftr:
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_SRC)/log:
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_SRC)/prs:
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_SRC)/rtg:
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_SRC)/stt:
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_SRC)/tst:
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_SRC)/wrp:
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_DEBUG):
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

$(BUILD_DIR_RELEASE):
	@find $@ -type d -maxdepth 0 >/dev/null 2>/dev/null || mkdir -p $@

amara_g: \
	$(BUILD_DIR_DEBUG)/amara_g \
	$(DEBUG_RESOURCES)

amara: \
	$(BUILD_DIR_RELEASE)/amara

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

$(BUILD_DIR_DEBUG)/amara_g_not_stripped: \
		$(OBJ_DEBUG)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -o $@ $(OBJ_DEBUG)

$(BUILD_DIR_DEBUG)/amara_g : \
		$(BUILD_DIR_DEBUG)/amara_g_not_stripped
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

$(BUILD_DIR_DEBUG)/amara_string.o: \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/amara_string.o: \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/cmn/amara_string_tests.$(HEXT): \
		$(SRC_DIR)/cmn/amara_string_tests.h \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/amara_string_tests.$(CEXT): \
		$(SRC_DIR)/cmn/amara_string_tests.c \
		$(BUILD_DIR_SRC)/log/logging.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/amara_string_tests.o: \
		$(BUILD_DIR_SRC)/cmn/amara_string_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/amara_string_tests.o: \
		$(BUILD_DIR_SRC)/cmn/amara_string_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(HEXT): \
		$(SRC_DIR)/cmn/amara_strings_simple_list.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(CEXT): \
		$(SRC_DIR)/cmn/amara_strings_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/amara_strings_simple_list.o: \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/amara_strings_simple_list.o: \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/cmn/amara_strings_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/cmn/amara_strings_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/amara_strings_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/amara_strings_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arg.$(HEXT): \
		$(SRC_DIR)/arg.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arg.$(CEXT): \
		$(SRC_DIR)/arg.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arg.o: \
		$(BUILD_DIR_SRC)/arg.$(CEXT) \
		$(BUILD_DIR_SRC)/arg.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arg.o: \
		$(BUILD_DIR_SRC)/arg.$(CEXT) \
		$(BUILD_DIR_SRC)/arg.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

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

$(BUILD_DIR_DEBUG)/assertion.o: \
		$(BUILD_DIR_SRC)/asr/assertion.$(CEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/assertion.o: \
		$(BUILD_DIR_SRC)/asr/assertion.$(CEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/brt/basic_arithmetic_tests.$(HEXT): \
		$(SRC_DIR)/brt/basic_arithmetic_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/basic_arithmetic_tests.$(CEXT): \
		$(SRC_DIR)/brt/basic_arithmetic_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/basic_arithmetic_tests.o: \
		$(BUILD_DIR_SRC)/brt/basic_arithmetic_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/basic_arithmetic_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/integer_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/rational_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/basic_arithmetic_tests.o: \
		$(BUILD_DIR_SRC)/brt/basic_arithmetic_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/basic_arithmetic_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/integer_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/rational_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/bsn/bison_annex.$(HEXT): \
		$(SRC_DIR)/bsn/bison_annex.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/bsn/bison_annex.$(CEXT): \
		$(SRC_DIR)/bsn/bison_annex.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/bison_annex.o: \
		$(BUILD_DIR_SRC)/bsn/bison_annex.$(CEXT) \
		$(BUILD_DIR_SRC)/bsn/bison_annex.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/bison_annex.o: \
		$(BUILD_DIR_SRC)/bsn/bison_annex.$(CEXT) \
		$(BUILD_DIR_SRC)/bsn/bison_annex.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/bsn/bison_tests.$(HEXT): \
		$(SRC_DIR)/bsn/bison_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/bsn/bison_tests.$(CEXT): \
		$(SRC_DIR)/bsn/bison_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/bison_tests.o: \
		$(BUILD_DIR_SRC)/bsn/bison_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/bsn/bison_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/bsn/minia.tab.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/app_runner.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/bison_tests.o: \
		$(BUILD_DIR_SRC)/bsn/bison_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/bsn/bison_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/bsn/minia.tab.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/app_runner.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/cmn/char_array.$(HEXT): \
		$(SRC_DIR)/cmn/char_array.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/char_array.$(CEXT): \
		$(SRC_DIR)/cmn/char_array.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/char_array.o: \
		$(BUILD_DIR_SRC)/cmn/char_array.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/char_array.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/char_array.o: \
		$(BUILD_DIR_SRC)/cmn/char_array.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/char_array.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(HEXT): \
		$(SRC_DIR)/cmn/char_arrays_simple_list.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(CEXT): \
		$(SRC_DIR)/cmn/char_arrays_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/char_arrays_simple_list.o: \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/char_arrays_simple_list.o: \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/cmn/char_arrays_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/cmn/char_arrays_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/char_arrays_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/char_arrays_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/cmn/char_array_tests.$(HEXT): \
		$(SRC_DIR)/cmn/char_array_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/char_array_tests.$(CEXT): \
		$(SRC_DIR)/cmn/char_array_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/char_array_tests.o: \
		$(BUILD_DIR_SRC)/cmn/char_array_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/char_array_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/char_array.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/char_array_tests.o: \
		$(BUILD_DIR_SRC)/cmn/char_array_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/char_array_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/char_array.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/cmn/common_tests.$(HEXT): \
		$(SRC_DIR)/cmn/common_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/cmn/common_tests.$(CEXT): \
		$(SRC_DIR)/cmn/common_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/common_tests.o: \
		$(BUILD_DIR_SRC)/cmn/common_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/common_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/common_tests.o: \
		$(BUILD_DIR_SRC)/cmn/common_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/cmn/common_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/main.$(CEXT): \
		$(SRC_DIR)/main.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/main.o: \
		$(BUILD_DIR_SRC)/main.$(CEXT) \
		$(BUILD_DIR_SRC)/arg.$(HEXT) \
		$(BUILD_DIR_SRC)/prs/persistence.$(HEXT) \
		$(BUILD_DIR_SRC)/tst/tests_runner.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/app_runner.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/main.o: \
		$(BUILD_DIR_SRC)/main.$(CEXT) \
		$(BUILD_DIR_SRC)/arg.$(HEXT) \
		$(BUILD_DIR_SRC)/prs/persistence.$(HEXT) \
		$(BUILD_DIR_SRC)/tst/tests_runner.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/app_runner.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

# $(BUILD_DIR_SRC)/bsn/lex.minia.$(CEXT): \
		$(SRC_DIR)/bsn/lex.minia.c
# 	$(CP) $< $@

$(BUILD_DIR_DEBUG)/lex.minia.o: \
		$(BUILD_DIR_SRC)/bsn/lex.minia.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(C) $(CFLAGS_PARTICULAR_FLEX) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/lex.minia.o: \
		$(BUILD_DIR_SRC)/bsn/lex.minia.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(C) $(CFLAGS_PARTICULAR_FLEX) $(CFLAGS_RELEASE) -c -o $@ $<

# TODO    Have no `minia.tab.h` in `$(SRC_DIR)`, having it only in
# TODO  `$(BUILD_DIR_SRC)`, restricting it to `$(BUILD_DIR_SRC)`.
# $(BUILD_DIR_SRC)/bsn/minia.tab.$(HEXT): \
		$(SRC_DIR)/bsn/minia.tab.h
# 	$(CP) $< $@

# $(BUILD_DIR_SRC)/bsn/minia.tab.$(CEXT): \
		$(SRC_DIR)/bsn/minia.tab.c
# 	$(CP) $< $@

$(BUILD_DIR_DEBUG)/minia.tab.o: \
		$(BUILD_DIR_SRC)/bsn/minia.tab.$(CEXT) \
		$(BUILD_DIR_SRC)/bsn/minia.tab.$(HEXT) \
		$(BUILD_DIR_SRC)/bsn/minia.y \
		$(BUILD_DIR_SRC)/bsn/bison_annex.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/minia.tab.o: \
		$(BUILD_DIR_SRC)/bsn/minia.tab.$(CEXT) \
		$(BUILD_DIR_SRC)/bsn/minia.tab.$(HEXT) \
		$(BUILD_DIR_SRC)/bsn/minia.y \
		$(BUILD_DIR_SRC)/bsn/bison_annex.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/brt/brt_forward_declarations.$(HEXT): \
		$(SRC_DIR)/brt/brt_forward_declarations.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/natural.$(HEXT): \
		$(SRC_DIR)/brt/natural.h \
		$(BUILD_DIR_SRC)/brt/brt_forward_declarations.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/ftr/stdio_ninety_nine_modernizer.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/natural.$(CEXT): \
		$(SRC_DIR)/brt/natural.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/natural.o: \
		$(BUILD_DIR_SRC)/brt/natural.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/natural.o: \
		$(BUILD_DIR_SRC)/brt/natural.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/brt/natural_tests.$(HEXT): \
		$(SRC_DIR)/brt/natural_tests.h \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/natural_tests.$(CEXT): \
		$(SRC_DIR)/brt/natural_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/natural_tests.o: \
		$(BUILD_DIR_SRC)/brt/natural_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/natural_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/natural_tests.o: \
		$(BUILD_DIR_SRC)/brt/natural_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/natural_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/brt/integer.$(HEXT): \
		$(SRC_DIR)/brt/integer.h \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/integer.$(CEXT): \
		$(SRC_DIR)/brt/integer.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/integer.o: \
		$(BUILD_DIR_SRC)/brt/integer.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/integer.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/integer.o: \
		$(BUILD_DIR_SRC)/brt/integer.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/integer.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/brt/integer_tests.$(HEXT): \
		$(SRC_DIR)/brt/integer_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/integer_tests.$(CEXT): \
		$(SRC_DIR)/brt/integer_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/integer_tests.o: \
		$(BUILD_DIR_SRC)/brt/integer_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/integer_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/integer.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/integer_tests.o: \
		$(BUILD_DIR_SRC)/brt/integer_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/integer_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/integer.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/brt/rational.$(HEXT): \
		$(SRC_DIR)/brt/rational.h \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/rational.$(CEXT): \
		$(SRC_DIR)/brt/rational.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rational.o: \
		$(BUILD_DIR_SRC)/brt/rational.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/rational.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rational.o: \
		$(BUILD_DIR_SRC)/brt/rational.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/rational.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/brt/rational_tests.$(HEXT): \
		$(SRC_DIR)/brt/rational_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/brt/rational_tests.$(CEXT): \
		$(SRC_DIR)/brt/rational_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rational_tests.o: \
		$(BUILD_DIR_SRC)/brt/rational_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/rational_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/rational.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rational_tests.o: \
		$(BUILD_DIR_SRC)/brt/rational_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/brt/rational_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/rational.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/app_runner.$(HEXT): \
		$(SRC_DIR)/arn/app_runner.h \
		$(BUILD_DIR_SRC)/rtg/rtg_doc.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/app_runner.$(CEXT): \
		$(SRC_DIR)/arn/app_runner.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/app_runner.o: \
		$(BUILD_DIR_SRC)/arn/app_runner.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/app_runner.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/prs/persistence.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/app_runner.o: \
		$(BUILD_DIR_SRC)/arn/app_runner.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/app_runner.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/prs/persistence.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/app_runner_tests.$(HEXT): \
		$(SRC_DIR)/arn/app_runner_tests.h \
		$(BUILD_DIR_SRC)/arn/arn_value_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/app_runner_tests.$(CEXT): \
		$(SRC_DIR)/arn/app_runner_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/app_runner_tests.o: \
		$(BUILD_DIR_SRC)/arn/app_runner_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/app_runner_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/app_runner.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/app_runner_tests.o: \
		$(BUILD_DIR_SRC)/arn/app_runner_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/app_runner_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/app_runner.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/arn_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arn_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_type_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_type_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/arn_type.$(HEXT): \
		$(SRC_DIR)/arn/arn_type.h \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_type.$(CEXT): \
		$(SRC_DIR)/arn/arn_type.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arn_type.o: \
		$(BUILD_DIR_SRC)/arn/arn_type.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_type.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_type.o: \
		$(BUILD_DIR_SRC)/arn/arn_type.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_type.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/arn_type_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_type_tests.h \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_type_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_type_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arn_type_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_type_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_type_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/log/logging.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_type_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_type_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_type_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/log/logging.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT): \
		$(SRC_DIR)/arn/arn_value.h \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_value.$(CEXT): \
		$(SRC_DIR)/arn/arn_value.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arn_value.o: \
		$(BUILD_DIR_SRC)/arn/arn_value.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_value.o: \
		$(BUILD_DIR_SRC)/arn/arn_value.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/arn_value_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_value_tests.h \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_value_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_value_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arn_value_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_value_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_value_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_value_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$(HEXT): \
		$(SRC_DIR)/arn/arn_values_fixed_list.h \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$(CEXT): \
		$(SRC_DIR)/arn/arn_values_fixed_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arn_values_fixed_list.o: \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_values_fixed_list.o: \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_values_fixed_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_values_fixed_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arn_values_fixed_list_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_values_fixed_list_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_fixed_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$(HEXT): \
		$(SRC_DIR)/arn/arn_values_simple_list.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$(CEXT): \
		$(SRC_DIR)/arn/arn_values_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arn_values_simple_list.o: \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_values_simple_list.o: \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_values_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_values_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arn_values_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_values_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_values_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_value_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/arn_variable.$(HEXT): \
		$(SRC_DIR)/arn/arn_variable.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_variable.$(CEXT): \
		$(SRC_DIR)/arn/arn_variable.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arn_variable.o: \
		$(BUILD_DIR_SRC)/arn/arn_variable.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_variable.o: \
		$(BUILD_DIR_SRC)/arn/arn_variable.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/arn_variable_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_variable_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_variable_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_variable_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arn_variable_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_variable_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_variable_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_variable_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$(HEXT): \
		$(SRC_DIR)/arn/arn_variables_simple_list.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$(CEXT): \
		$(SRC_DIR)/arn/arn_variables_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arn_variables_simple_list.o: \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_variables_simple_list.o: \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/arn/arn_variables_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/arn/arn_variables_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/arn_variables_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_variables_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variables_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/arn_variable.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/bsn/flex_tests.$(HEXT): \
		$(SRC_DIR)/bsn/flex_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/bsn/flex_tests.$(CEXT): \
		$(SRC_DIR)/bsn/flex_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/flex_tests.o: \
		$(BUILD_DIR_SRC)/bsn/flex_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/bsn/flex_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/bsn/minia.l \
		$(BUILD_DIR_SRC)/bsn/minia.tab.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/flex_tests.o: \
		$(BUILD_DIR_SRC)/bsn/flex_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/bsn/flex_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/bsn/minia.l \
		$(BUILD_DIR_SRC)/bsn/minia.tab.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/log/logging.$(HEXT): \
		$(SRC_DIR)/log/logging.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/log/logging.$(CEXT): \
		$(SRC_DIR)/log/logging.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/logging.o: \
		$(BUILD_DIR_SRC)/log/logging.$(CEXT) \
		$(BUILD_DIR_SRC)/log/logging.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/logging.o: \
		$(BUILD_DIR_SRC)/log/logging.$(CEXT) \
		$(BUILD_DIR_SRC)/log/logging.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/prs/persistence.$(HEXT): \
		$(SRC_DIR)/prs/persistence.h \
		$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/prs/persistence.$(CEXT): \
		$(SRC_DIR)/prs/persistence.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/persistence.o: \
		$(BUILD_DIR_SRC)/prs/persistence.$(CEXT) \
		$(BUILD_DIR_SRC)/prs/persistence.$(HEXT) \
		$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/persistence.o: \
		$(BUILD_DIR_SRC)/prs/persistence.$(CEXT) \
		$(BUILD_DIR_SRC)/prs/persistence.$(HEXT) \
		$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/prs/persistence_tests.$(HEXT): \
		$(SRC_DIR)/prs/persistence_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/prs/persistence_tests.$(CEXT): \
		$(SRC_DIR)/prs/persistence_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/persistence_tests.o: \
		$(BUILD_DIR_SRC)/prs/persistence_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/prs/persistence_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/persistence_tests.o: \
		$(BUILD_DIR_SRC)/prs/persistence_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/prs/persistence_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$(HEXT): \
		$(SRC_DIR)/tst/tests_pseudo_random_numbers_generation.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$(CEXT): \
		$(SRC_DIR)/tst/tests_pseudo_random_numbers_generation.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/tests_pseudo_random_numbers_generation.o: \
		$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$(CEXT) \
		$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/tests_pseudo_random_numbers_generation.o: \
		$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$(CEXT) \
		$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation_tests.$(HEXT): \
		$(SRC_DIR)/tst/tests_pseudo_random_numbers_generation_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation_tests.$(CEXT): \
		$(SRC_DIR)/tst/tests_pseudo_random_numbers_generation_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/tests_pseudo_random_numbers_generation_tests.o: \
		$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/tests_pseudo_random_numbers_generation_tests.o: \
		$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/tst/tests_runner.$(HEXT): \
		$(SRC_DIR)/tst/tests_runner.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/tst/tests_runner.$(CEXT): \
		$(SRC_DIR)/tst/tests_runner.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/tests_runner.o: \
		$(BUILD_DIR_SRC)/tst/tests_runner.$(CEXT) \
		$(BUILD_DIR_SRC)/tst/tests_runner.$(HEXT) \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/app_runner_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/tests_runner.o: \
		$(BUILD_DIR_SRC)/tst/tests_runner.$(CEXT) \
		$(BUILD_DIR_SRC)/tst/tests_runner.$(HEXT) \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/arn/app_runner_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT): \
		$(SRC_DIR)/tst/tests_simple_list.h \
		$(BUILD_DIR_SRC)/definitions.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/tst/tests_simple_list.$(CEXT): \
		$(SRC_DIR)/tst/tests_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/tests_simple_list.o: \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/tests_simple_list.o: \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/tst/tests_pseudo_random_numbers_generation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$(HEXT): \
		$(SRC_DIR)/wrp/dirent_wrapper.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$(CEXT): \
		$(SRC_DIR)/wrp/dirent_wrapper.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/dirent_wrapper.o: \
		$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$(CEXT) \
		$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/dirent_wrapper.o: \
		$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$(CEXT) \
		$(BUILD_DIR_SRC)/wrp/dirent_wrapper.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_application.h \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_application.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_application.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_application.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_application.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_application_tests.h \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_application_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_application_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_application_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_applications_simple_list.h \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_applications_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_applications_simple_list.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_applications_simple_list.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_applications_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_applications_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_applications_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_applications_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_condition.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_condition.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_condition.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_condition.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_condition.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_condition.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_condition.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_condition.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_condition.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_condition.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_condition_tests.h \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_condition_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_condition_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_condition.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_condition_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_condition.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_doc.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_doc.h \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_doc.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_doc.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_doc.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_doc.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_doc.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_doc.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_doc.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_doc.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_doc_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_doc_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_doc_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_doc_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_doc_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_doc_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_doc_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_doc.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_doc_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_doc_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_doc_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_doc.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_execution_request.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_execution_request.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_execution_request.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_execution_request.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_execution_request_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_execution_request_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_execution_request_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_execution_request_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_execution_request_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_execution_request_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list.h \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list.c \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_execution_requests_simple_list.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_execution_requests_simple_list.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list_tests.h \
		$(BUILD_DIR_SRC)/rtg/rtg_application_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_execution_requests_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_execution_requests_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_requests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

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

$(BUILD_DIR_DEBUG)/rtg_expression.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional.h \
		$(BUILD_DIR_SRC)/rtg/rtg_condition.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_expression_sub_conditional.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_conditional.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional_tests.h \
		$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_expression_sub_conditional_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_conditional_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_conditional.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_expression_sub_dice.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_dice.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_expression_sub_dice_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_dice_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_dice.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_expression_sub_identifier.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_identifier.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_expression_sub_identifier_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_identifier_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_identifier.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_natural_literal.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_natural_literal.h \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_natural_literal.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_natural_literal.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_expression_sub_natural_literal.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_natural_literal.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_natural_literal.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_natural_literal.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_natural_literal.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_natural_literal.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_string_literal.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_string_literal.h \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_string_literal.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_sub_string_literal.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_expression_sub_string_literal.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_string_literal.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_string_literal.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_string_literal.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_string_literal.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_sub_string_literal.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_expression_tests.h \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_expression_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_expression_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_condition_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_named_function.h \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_named_function.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_named_function.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_named_function.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_named_function_tests.h \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_named_function_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_named_function_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_named_function_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_named_functions_simple_list.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_named_functions_simple_list.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_named_functions_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_named_functions_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_named_function_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operation.h \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operation.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operation.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_operation.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operation.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operation_arg.h \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operation_arg.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_operation_arg.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operation_arg.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_strings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_operation_arg_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operation_arg_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operation_arg_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operation_arg_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_operation_arg_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operation_arg_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operation_args_simple_list.h \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operation_args_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_operation_args_simple_list.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operation_args_simple_list.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operation_args_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operation_args_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_operation_args_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operation_args_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operation_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operation_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_operation_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operation_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operations_simple_list.h \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operations_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_operations_simple_list.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operations_simple_list.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_operations_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_operations_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_operations_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operations_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operations_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_operation_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_applications_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_binding.h \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_binding.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_where_value_binding.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_where_value_binding.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_binding_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_binding_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_where_value_binding_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_where_value_binding_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_expression_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list.h \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_where_value_bindings_simple_list.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_where_value_bindings_simple_list.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/rtg_where_value_bindings_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_where_value_bindings_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/rtg/rtg_where_value_bindings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/ftr/stdio_ninety_nine_modernizer.$(HEXT): \
		$(SRC_DIR)/ftr/stdio_ninety_nine_modernizer.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT): \
		$(SRC_DIR)/stt/stt_application.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_application.$(CEXT): \
		$(SRC_DIR)/stt/stt_application.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_application.o: \
		$(BUILD_DIR_SRC)/stt/stt_application.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_application.o: \
		$(BUILD_DIR_SRC)/stt/stt_application.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_application_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_application_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_application_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_application_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_application_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_application_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_application_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_application_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_application_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_application_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_application_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_application_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_application_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_application_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_application_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_application_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_application_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_application_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT): \
		$(SRC_DIR)/stt/stt_applications_simple_list.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(CEXT): \
		$(SRC_DIR)/stt/stt_applications_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_applications_simple_list.o: \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_applications_simple_list.o: \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_applications_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_applications_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_applications_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_applications_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT): \
		$(SRC_DIR)/stt/stt_condition.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_condition.$(CEXT): \
		$(SRC_DIR)/stt/stt_condition.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_condition.o: \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_forward_declarations.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_condition.o: \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_forward_declarations.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_condition_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_condition_subnode.c \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_condition_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_condition_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_condition_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_condition_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_condition_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_condition_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_condition_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_condition_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_condition_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_condition_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_condition_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_condition_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_condition_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_condition_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_condition_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_condition_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_condition_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_condition_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_dice_expression.$(HEXT): \
		$(SRC_DIR)/stt/stt_dice_expression.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_dice_expression.$(CEXT): \
		$(SRC_DIR)/stt/stt_dice_expression.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_dice_expression.o: \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_dice_expression.o: \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_dice_expression_tests.h \
		$(BUILD_DIR_SRC)/brt/natural_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_dice_expression_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_dice_expression_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_dice_expression_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_doc_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_doc_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_doc_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_doc_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_doc_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_doc_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_doc_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_doc_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_execution_request.$(HEXT): \
		$(SRC_DIR)/stt/stt_execution_request.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_execution_request.$(CEXT): \
		$(SRC_DIR)/stt/stt_execution_request.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_execution_request.o: \
		$(BUILD_DIR_SRC)/stt/stt_execution_request.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_execution_request.o: \
		$(BUILD_DIR_SRC)/stt/stt_execution_request.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_execution_request_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_execution_request_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_execution_request_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_execution_request_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_execution_request_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_execution_request_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_execution_request_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_execution_request_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_execution_request_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_execution_request_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_execution_request_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_execution_request_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT): \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list.h \
		$(BUILD_DIR_SRC)/stt/stt_execution_request.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(CEXT): \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_execution_requests_simple_list.o: \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_execution_requests_simple_list.o: \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_request.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_execution_requests_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_execution_requests_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_execution_requests_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

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

$(BUILD_DIR_DEBUG)/stt_expression.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_conditional.h \
		$(BUILD_DIR_SRC)/stt/stt_condition.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_conditional.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_expression_sub_conditional.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$(HEXT) \
		$(BUILD_DIR_SRC)/definitions.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_conditional.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$(HEXT) \
		$(BUILD_DIR_SRC)/definitions.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_conditional_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_condition_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_tests.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_conditional_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_expression_sub_conditional_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_conditional_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_conditional.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_dice.h \
		$(BUILD_DIR_SRC)/brt/brt_forward_declarations.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_dice.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_expression_sub_dice.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_dice.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_dice_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_dice_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_expression_sub_dice_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_dice_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_identifier.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_identifier.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_expression_sub_identifier.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_identifier.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_identifier_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_identifier_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_expression_sub_identifier_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_identifier_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_identifier.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_expression_sub_natural_literal.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_natural_literal.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_natural_literal.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_natural_literal.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_expression_sub_natural_literal.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_natural_literal.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_natural_literal.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_natural_literal.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_natural_literal.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_natural_literal.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_string_literal.h \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_sub_string_literal.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_expression_sub_string_literal.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_string_literal.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_string_literal.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_expression_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_expression_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_expression_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_subnode.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_expression_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_expression_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_expression_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_expression_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_expression_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_expression_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression_sub_dice_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_function.h \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_function.$(CEXT): \
		$(SRC_DIR)/stt/stt_named_function.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_named_function.o: \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_named_function.o: \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_function_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_named_function_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_named_function_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_named_function_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_function_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_named_function_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_named_function_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_named_function_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_function_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_named_function_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_named_function_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_named_function_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(CEXT): \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_named_functions_simple_list.o: \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_named_functions_simple_list.o: \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_named_functions_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_named_functions_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_named_functions_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_named_functions_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_functions_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_identifier_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_identifier_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_identifier_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_identifier_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_identifier_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_identifier_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_identifier_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_identifier_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_identifier_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_identifier_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_identifier_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_identifier_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_identifier_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_identifier_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_identifier_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_integer_literal_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_integer_literal_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_integer_literal_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/integer.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_integer_literal_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/integer.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_integer_literal_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_integer_literal_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_integer_literal_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/integer.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_integer_literal_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_integer_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/integer.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_natural_literal_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_natural_literal_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_natural_literal_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_natural_literal_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_natural_literal_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_natural_literal_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_natural_literal_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_natural_literal_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_natural_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

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

$(BUILD_DIR_DEBUG)/stt_node.o: \
		$(BUILD_DIR_SRC)/stt/stt_node.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/char_array.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_node.o: \
		$(BUILD_DIR_SRC)/stt/stt_node.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_applications_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/char_array.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_node_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_node_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_node_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_node_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_node_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_node_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/char_array.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_node_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_node_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/char_array.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/char_arrays_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_application_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_named_function_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_doc_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation.h \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_operation.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_arg.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_arg.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_operation_arg.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_arg.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_arg_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_arg_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_operation_arg_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_arg_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_args_simple_list.h \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_args_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_operation_args_simple_list.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_args_simple_list.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_arg.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_args_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_args_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_operation_args_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_args_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_args_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_operation_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_operation_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_operation_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_operation_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_operation_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_operation_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_operations_list_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_operations_list_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_operations_list_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operations_list_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_operations_list_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_operations_list_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_operations_list_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operations_list_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_list_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT): \
		$(SRC_DIR)/stt/stt_operations_simple_list.h \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/definitions.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(CEXT): \
		$(SRC_DIR)/stt/stt_operations_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_operations_simple_list.o: \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operations_simple_list.o: \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_operations_simple_list_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_operations_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_operations_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operations_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operations_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_operation_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_rational_literal_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_rational_literal_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_rational_literal_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/rational.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_rational_literal_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/natural.$(HEXT) \
		$(BUILD_DIR_SRC)/brt/rational.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_rational_literal_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_rational_literal_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_rational_literal_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_rational_literal_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_rational_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_string_literal_subnode.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_string_literal_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_string_literal_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_boolean.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_string_literal_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_boolean.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_string_literal_subnode_tests.h \
		$(BUILD_DIR_SRC)/tst/tests_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_string_literal_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_string_literal_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_boolean.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_string_literal_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_string_literal_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_boolean.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_node.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_dice_expression_tests.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding.h \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_where_value_binding.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_binding.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT) \
		$(BUILD_DIR_SRC)/cmn/amara_string.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_expression.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_where_value_binding_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_binding_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_where_value_binding_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_binding_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_binding_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_where_value_binding_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_binding_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list.h \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_where_value_bindings_simple_list.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_bindings_simple_list.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_binding.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list_tests.h \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_where_value_bindings_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_bindings_simple_list_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode.h \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT)
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_where_value_bindings_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_bindings_subnode.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_simple_list.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$(HEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode_tests.h
	$(CP) $< $@

$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$(CEXT): \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode_tests.c
	$(CP) $< $@

$(BUILD_DIR_DEBUG)/stt_where_value_bindings_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_bindings_subnode_tests.o: \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$(CEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode_tests.$(HEXT) \
		$(BUILD_DIR_SRC)/stt/stt_where_value_bindings_subnode.$(HEXT) \
		$(BUILD_DIR_SRC)/asr/assertion.$(HEXT)
	$(C) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

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
		amara_g

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
			$(BUILD_DIR_DEBUG)/amara_g_not_stripped \
			$(BUILD_DIR_DEBUG)/amara_g \
			$(BUILD_DIR_RELEASE)/amara_not_stripped \
			$(BUILD_DIR_RELEASE)/amara \
			$(BUILD_DIR_DEBUG)/*.o \
			$(BUILD_DIR_RELEASE)/*.o \
			$(BUILD_DIR_DEBUG)/*.gcno \
			$(BUILD_DIR_DEBUG)/*.gcda
	rm -rfv $(BUILD_DIR_DEBUG)
	rm -rfv $(BUILD_DIR_RELEASE)
	rm -rfv $(BUILD_DIR_SRC)
	rm -rfv $(BUILD_DIR)
