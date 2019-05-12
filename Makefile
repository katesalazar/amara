#
# Copyright 2018-2019 Mercedes Catherine Salazar
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
BISON ?= /usr/local/Cellar/bison/3.1/bin/bison
FLEX ?= /usr/local/Cellar/flex/2.6.4/bin/flex
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
endif

CFLAGS_GENERAL += -pedantic -Wall -Wextra -std=c89
# $(info $(CFLAGS_GENERAL))
CFLAGS_PARTICULAR_FLEX += -pedantic -Wall -Wextra -std=c89
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

SRC_DIR = src
BUILD_DIR = build
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
	$(SRC_DIR)/brt/rationa_tests.c \
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
	$(SRC_DIR)/tst/tests_runner.c \
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
		$(BUILD_DIR_DEBUG)/bison_tests.o \
		$(BUILD_DIR_DEBUG)/char_array.o \
		$(BUILD_DIR_DEBUG)/char_array_tests.o \
		$(BUILD_DIR_DEBUG)/char_arrays_simple_list.o \
		$(BUILD_DIR_DEBUG)/char_arrays_simple_list_tests.o \
		$(BUILD_DIR_DEBUG)/common_tests.o \
		$(BUILD_DIR_DEBUG)/dirent_wrapper.o \
		$(BUILD_DIR_DEBUG)/flex_tests.o \
		$(BUILD_DIR_DEBUG)/integer.o \
		$(BUILD_DIR_DEBUG)/integer_tests.o \
		$(BUILD_DIR_DEBUG)/main.o \
		$(BUILD_DIR_DEBUG)/minia_lex.o \
		$(BUILD_DIR_DEBUG)/minia_tab.o \
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
		$(BUILD_DIR_DEBUG)/tests_runner.o \
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
		$(BUILD_DIR_RELEASE)/bison_tests.o \
		$(BUILD_DIR_RELEASE)/char_array.o \
		$(BUILD_DIR_RELEASE)/char_array_tests.o \
		$(BUILD_DIR_RELEASE)/char_arrays_simple_list.o \
		$(BUILD_DIR_RELEASE)/char_arrays_simple_list_tests.o \
		$(BUILD_DIR_RELEASE)/common_tests.o \
		$(BUILD_DIR_RELEASE)/dirent_wrapper.o \
		$(BUILD_DIR_RELEASE)/flex_tests.o \
		$(BUILD_DIR_RELEASE)/integer.o \
		$(BUILD_DIR_RELEASE)/integer_tests.o \
		$(BUILD_DIR_RELEASE)/main.o \
		$(BUILD_DIR_RELEASE)/minia_lex.o \
		$(BUILD_DIR_RELEASE)/minia_tab.o \
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
		$(BUILD_DIR_RELEASE)/tests_runner.o \
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

default: checkdirs $(BUILD_DIR_RELEASE)/amara

all: checkdirs $(BUILD_DIR_DEBUG)/amara_g $(BUILD_DIR_RELEASE)/amara

checkdirs: $(BUILD_DIR_DEBUG) $(BUILD_DIR_RELEASE)

$(BUILD_DIR_DEBUG):
	mkdir -p $@

$(BUILD_DIR_RELEASE):
	mkdir -p $@

amara_g: $(BUILD_DIR_DEBUG)/amara_g

amara: $(BUILD_DIR_RELEASE)/amara

#   It's most probably not required to go back to the source but... well
# maybe it's tidier like this.
$(SRC_DIR)/bsn/minia.tab.c $(SRC_DIR)/bsn/minia.tab.h: \
		$(SRC_DIR)/bsn/minia.y \
		$(SRC_DIR)/asr/assertion.h \
		$(SRC_DIR)/brt/natural.h \
		$(SRC_DIR)/stt/stt_node.h \
		$(SRC_DIR)/stt/stt_operation.h
	sh -c "pwd && \
			cd $(SRC_DIR)/bsn/ && \
			pwd && \
			$(BISON) \
					--name-prefix minia \
					--defines \
					--graph \
					--report=all \
					--verbose \
					$(BISON_FLAGS) \
					minia.y && \
			cd ../../ && \
			pwd"

#   It's most probably not required to go back to the source but... well
# maybe it's tidier like this.
$(SRC_DIR)/bsn/lex.minia.c: \
		$(SRC_DIR)/bsn/minia.l \
		$(SRC_DIR)/bsn/minia.tab.h \
		$(SRC_DIR)/asr/assertion.h \
		$(SRC_DIR)/stt/stt_node.h
	pwd && \
			cd $(SRC_DIR)/bsn/ && \
			pwd && \
			$(FLEX) \
				-P minia \
				$(FLEX_FLAGS) \
				minia.l && \
			cd ../../ && \
			pwd

$(BUILD_DIR_DEBUG)/amara_g: \
		$(OBJ_DEBUG) \
		$(DEBUG_RESOURCES)
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) -o $@ $(OBJ_DEBUG)

$(BUILD_DIR_RELEASE)/amara: \
		$(OBJ_RELEASE)
	$(CC) $(CFLAGS) $(CFLAGS_RELEASE) -o $@ $(OBJ_RELEASE)

$(BUILD_DIR_DEBUG)/amara_string.o: \
		$(SRC_DIR)/cmn/amara_string.c \
		$(SRC_DIR)/cmn/amara_string.h
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/amara_string.o: \
		$(SRC_DIR)/cmn/amara_string.c \
		$(SRC_DIR)/cmn/amara_string.h
	$(CC) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/amara_string_tests.o: \
		$(SRC_DIR)/cmn/amara_string_tests.c \
		$(SRC_DIR)/cmn/amara_string_tests.h \
		$(SRC_DIR)/cmn/amara_string.h
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/amara_string_tests.o: \
		$(SRC_DIR)/cmn/amara_string_tests.c \
		$(SRC_DIR)/cmn/amara_string_tests.h \
		$(SRC_DIR)/cmn/amara_string.h
	$(CC) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/amara_strings_simple_list.o: \
		$(SRC_DIR)/cmn/amara_strings_simple_list.c \
		$(SRC_DIR)/cmn/amara_strings_simple_list.h \
		$(SRC_DIR)/cmn/amara_string.h
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/amara_strings_simple_list.o: \
		$(SRC_DIR)/cmn/amara_strings_simple_list.c \
		$(SRC_DIR)/cmn/amara_strings_simple_list.h \
		$(SRC_DIR)/cmn/amara_string.h
	$(CC) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/amara_strings_simple_list_tests.o: \
		$(SRC_DIR)/cmn/amara_strings_simple_list_tests.c \
		$(SRC_DIR)/cmn/amara_strings_simple_list_tests.h \
		$(SRC_DIR)/cmn/amara_strings_simple_list.h \
		$(SRC_DIR)/cmn/amara_string_tests.h
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/amara_strings_simple_list_tests.o: \
		$(SRC_DIR)/cmn/amara_strings_simple_list_tests.c \
		$(SRC_DIR)/cmn/amara_strings_simple_list_tests.h \
		$(SRC_DIR)/cmn/amara_strings_simple_list.h \
		$(SRC_DIR)/cmn/amara_string_tests.h
	$(CC) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arg.o: $(SRC_DIR)/arg.c $(SRC_DIR)/arg.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $(BUILD_DIR_DEBUG)/arg.o $(SRC_DIR)/arg.c

$(BUILD_DIR_RELEASE)/arg.o: $(SRC_DIR)/arg.c $(SRC_DIR)/arg.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $(BUILD_DIR_RELEASE)/arg.o $(SRC_DIR)/arg.c

$(BUILD_DIR_DEBUG)/assertion.o: $(SRC_DIR)/asr/assertion.c $(SRC_DIR)/asr/assertion.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $(BUILD_DIR_DEBUG)/assertion.o $(SRC_DIR)/asr/assertion.c

$(BUILD_DIR_RELEASE)/assertion.o: $(SRC_DIR)/asr/assertion.c $(SRC_DIR)/asr/assertion.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $(BUILD_DIR_RELEASE)/assertion.o $(SRC_DIR)/asr/assertion.c

$(BUILD_DIR_DEBUG)/basic_arithmetic_tests.o: $(SRC_DIR)/brt/basic_arithmetic_tests.c $(SRC_DIR)/brt/basic_arithmetic_tests.h $(SRC_DIR)/brt/natural.h $(SRC_DIR)/stt/stt_node.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $(SRC_DIR)/brt/basic_arithmetic_tests.c

$(BUILD_DIR_RELEASE)/basic_arithmetic_tests.o: $(SRC_DIR)/brt/basic_arithmetic_tests.c $(SRC_DIR)/brt/basic_arithmetic_tests.h $(SRC_DIR)/brt/natural.h $(SRC_DIR)/stt/stt_node.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $(SRC_DIR)/brt/basic_arithmetic_tests.c

$(BUILD_DIR_DEBUG)/bison_tests.o: \
		$(SRC_DIR)/bsn/bison_tests.c \
		$(SRC_DIR)/bsn/bison_tests.h \
		$(SRC_DIR)/bsn/minia.tab.h \
		$(SRC_DIR)/stt/stt_node.h
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/bison_tests.o: \
		$(SRC_DIR)/bsn/bison_tests.c \
		$(SRC_DIR)/bsn/bison_tests.h \
		$(SRC_DIR)/bsn/minia.tab.h \
		$(SRC_DIR)/stt/stt_node.h
	$(CC) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/char_array.o: $(SRC_DIR)/cmn/char_array.c $(SRC_DIR)/cmn/char_array.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $(SRC_DIR)/cmn/char_array.c

$(BUILD_DIR_RELEASE)/char_array.o: $(SRC_DIR)/cmn/char_array.c $(SRC_DIR)/cmn/char_array.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $(SRC_DIR)/cmn/char_array.c

$(BUILD_DIR_DEBUG)/char_arrays_simple_list.o: $(SRC_DIR)/cmn/char_arrays_simple_list.c $(SRC_DIR)/cmn/char_arrays_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $(SRC_DIR)/cmn/char_arrays_simple_list.c

$(BUILD_DIR_RELEASE)/char_arrays_simple_list.o: $(SRC_DIR)/cmn/char_arrays_simple_list.c $(SRC_DIR)/cmn/char_arrays_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $(SRC_DIR)/cmn/char_arrays_simple_list.c

$(BUILD_DIR_DEBUG)/char_arrays_simple_list_tests.o: \
		$(SRC_DIR)/cmn/char_arrays_simple_list_tests.c \
		$(SRC_DIR)/cmn/char_arrays_simple_list_tests.h \
		$(SRC_DIR)/cmn/char_arrays_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/char_arrays_simple_list_tests.o: \
		$(SRC_DIR)/cmn/char_arrays_simple_list_tests.c \
		$(SRC_DIR)/cmn/char_arrays_simple_list_tests.h \
		$(SRC_DIR)/cmn/char_arrays_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/char_array_tests.o: \
		$(SRC_DIR)/cmn/char_array_tests.c \
		$(SRC_DIR)/cmn/char_array_tests.h \
		$(SRC_DIR)/cmn/char_array.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/char_array_tests.o: \
		$(SRC_DIR)/cmn/char_array_tests.c \
		$(SRC_DIR)/cmn/char_array_tests.h \
		$(SRC_DIR)/cmn/char_array.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/common_tests.o: $(SRC_DIR)/cmn/common_tests.c $(SRC_DIR)/cmn/common_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $(SRC_DIR)/cmn/common_tests.c

$(BUILD_DIR_RELEASE)/common_tests.o: $(SRC_DIR)/cmn/common_tests.c $(SRC_DIR)/cmn/common_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $(SRC_DIR)/cmn/common_tests.c

$(BUILD_DIR_DEBUG)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/arg.h $(SRC_DIR)/prs/persistence.h $(SRC_DIR)/tst/tests_runner.h $(SRC_DIR)/arn/app_runner.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $(BUILD_DIR_DEBUG)/main.o $(SRC_DIR)/main.c

$(BUILD_DIR_RELEASE)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/arg.h $(SRC_DIR)/prs/persistence.h $(SRC_DIR)/tst/tests_runner.h $(SRC_DIR)/arn/app_runner.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $(BUILD_DIR_RELEASE)/main.o $(SRC_DIR)/main.c

$(BUILD_DIR_DEBUG)/minia_lex.o: \
		$(SRC_DIR)/bsn/lex.minia.c \
		$(SRC_DIR)/stt/stt_node.h
	gcc $(CFLAGS_PARTICULAR_FLEX) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/minia_lex.o: \
		$(SRC_DIR)/bsn/lex.minia.c \
		$(SRC_DIR)/stt/stt_node.h
	gcc $(CFLAGS_PARTICULAR_FLEX) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/minia_tab.o: $(SRC_DIR)/bsn/minia.tab.c $(SRC_DIR)/bsn/minia.tab.h $(SRC_DIR)/bsn/minia.y $(SRC_DIR)/asr/assertion.h $(SRC_DIR)/brt/natural.h $(SRC_DIR)/stt/stt_node.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $(BUILD_DIR_DEBUG)/minia_tab.o $(SRC_DIR)/bsn/minia.tab.c

$(BUILD_DIR_RELEASE)/minia_tab.o: $(SRC_DIR)/bsn/minia.tab.c $(SRC_DIR)/bsn/minia.tab.h $(SRC_DIR)/bsn/minia.y $(SRC_DIR)/asr/assertion.h $(SRC_DIR)/brt/natural.h $(SRC_DIR)/stt/stt_node.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $(BUILD_DIR_RELEASE)/minia_tab.o $(SRC_DIR)/bsn/minia.tab.c

$(BUILD_DIR_DEBUG)/natural.o: \
		$(SRC_DIR)/brt/natural.c \
		$(SRC_DIR)/brt/natural.h \
		$(SRC_DIR)/stt/stt_node.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/natural.o: \
		$(SRC_DIR)/brt/natural.c \
		$(SRC_DIR)/brt/natural.h \
		$(SRC_DIR)/stt/stt_node.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/natural_tests.o: $(SRC_DIR)/brt/natural_tests.c $(SRC_DIR)/brt/natural_tests.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/natural_tests.o: $(SRC_DIR)/brt/natural_tests.c $(SRC_DIR)/brt/natural_tests.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/integer.o: $(SRC_DIR)/brt/integer.c $(SRC_DIR)/brt/integer.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $(SRC_DIR)/brt/integer.c

$(BUILD_DIR_RELEASE)/integer.o: $(SRC_DIR)/brt/integer.c $(SRC_DIR)/brt/integer.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $(SRC_DIR)/brt/integer.c

$(BUILD_DIR_DEBUG)/integer_tests.o: \
		$(SRC_DIR)/brt/integer_tests.c \
		$(SRC_DIR)/brt/integer_tests.h \
		$(SRC_DIR)/brt/integer.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/integer_tests.o: \
		$(SRC_DIR)/brt/integer_tests.c \
		$(SRC_DIR)/brt/integer_tests.h \
		$(SRC_DIR)/brt/integer.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rational.o: $(SRC_DIR)/brt/rational.c $(SRC_DIR)/brt/rational.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $(SRC_DIR)/brt/rational.c

$(BUILD_DIR_RELEASE)/rational.o: $(SRC_DIR)/brt/rational.c $(SRC_DIR)/brt/rational.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $(SRC_DIR)/brt/rational.c

$(BUILD_DIR_DEBUG)/rational_tests.o: \
		$(SRC_DIR)/brt/rational_tests.c \
		$(SRC_DIR)/brt/rational_tests.h \
		$(SRC_DIR)/brt/rational.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rational_tests.o: \
		$(SRC_DIR)/brt/rational_tests.c \
		$(SRC_DIR)/brt/rational_tests.h \
		$(SRC_DIR)/brt/rational.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/app_runner.o: \
		$(SRC_DIR)/arn/app_runner.c \
		$(SRC_DIR)/arn/app_runner.h \
		$(SRC_DIR)/stt/stt_node.h \
		$(SRC_DIR)/rtg/rtg_operation.h \
		$(SRC_DIR)/rtg/rtg_operation_args_simple_list.h \
		$(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/app_runner.o: \
		$(SRC_DIR)/arn/app_runner.c \
		$(SRC_DIR)/arn/app_runner.h \
		$(SRC_DIR)/stt/stt_node.h \
		$(SRC_DIR)/rtg/rtg_operation.h \
		$(SRC_DIR)/rtg/rtg_operation_args_simple_list.h \
		$(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/app_runner_tests.o: \
		$(SRC_DIR)/arn/app_runner_tests.c \
		$(SRC_DIR)/arn/app_runner_tests.h \
		$(SRC_DIR)/arn/app_runner.h
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/app_runner_tests.o: \
		$(SRC_DIR)/arn/app_runner_tests.c \
		$(SRC_DIR)/arn/app_runner_tests.h \
		$(SRC_DIR)/arn/app_runner.h
	$(CC) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arn_tests.o: \
		$(SRC_DIR)/arn/arn_tests.c \
		$(SRC_DIR)/arn/arn_tests.h \
		$(SRC_DIR)/arn/arn_variable.h \
		$(SRC_DIR)/arn/arn_variables_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_tests.o: \
		$(SRC_DIR)/arn/arn_tests.c \
		$(SRC_DIR)/arn/arn_tests.h \
		$(SRC_DIR)/arn/arn_variable.h \
		$(SRC_DIR)/arn/arn_variables_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arn_type.o: \
		$(SRC_DIR)/arn/arn_type.c \
		$(SRC_DIR)/arn/arn_type.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_type.o: \
		$(SRC_DIR)/arn/arn_type.c \
		$(SRC_DIR)/arn/arn_type.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arn_type_tests.o: \
		$(SRC_DIR)/arn/arn_type_tests.c \
		$(SRC_DIR)/arn/arn_type_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_type_tests.o: \
		$(SRC_DIR)/arn/arn_type_tests.c \
		$(SRC_DIR)/arn/arn_type_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arn_value.o: \
		$(SRC_DIR)/arn/arn_value.c \
		$(SRC_DIR)/arn/arn_value.h \
		$(SRC_DIR)/brt/natural.h \
		$(SRC_DIR)/rtg/rtg_expression.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_value.o: \
		$(SRC_DIR)/arn/arn_value.c \
		$(SRC_DIR)/arn/arn_value.h \
		$(SRC_DIR)/brt/natural.h \
		$(SRC_DIR)/rtg/rtg_expression.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arn_value_tests.o: \
		$(SRC_DIR)/arn/arn_value_tests.c \
		$(SRC_DIR)/arn/arn_value_tests.h \
		$(SRC_DIR)/arn/arn_value.h \
		$(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_value_tests.o: \
		$(SRC_DIR)/arn/arn_value_tests.c \
		$(SRC_DIR)/arn/arn_value_tests.h \
		$(SRC_DIR)/arn/arn_value.h \
		$(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arn_values_fixed_list.o: $(SRC_DIR)/arn/arn_values_fixed_list.c $(SRC_DIR)/arn/arn_values_fixed_list.h $(SRC_DIR)/arn/arn_value.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_values_fixed_list.o: $(SRC_DIR)/arn/arn_values_fixed_list.c $(SRC_DIR)/arn/arn_values_fixed_list.h $(SRC_DIR)/arn/arn_value.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arn_values_fixed_list_tests.o: \
		$(SRC_DIR)/arn/arn_values_fixed_list_tests.c \
		$(SRC_DIR)/arn/arn_values_fixed_list_tests.h \
		$(SRC_DIR)/arn/arn_values_fixed_list.h \
		$(SRC_DIR)/arn/arn_value_tests.h \
		$(SRC_DIR)/arn/arn_value.h \
		$(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_values_fixed_list_tests.o: \
		$(SRC_DIR)/arn/arn_values_fixed_list_tests.c \
		$(SRC_DIR)/arn/arn_values_fixed_list_tests.h \
		$(SRC_DIR)/arn/arn_values_fixed_list.h \
		$(SRC_DIR)/arn/arn_value_tests.h \
		$(SRC_DIR)/arn/arn_value.h \
		$(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arn_values_simple_list.o: $(SRC_DIR)/arn/arn_values_simple_list.c $(SRC_DIR)/arn/arn_values_simple_list.h $(SRC_DIR)/arn/arn_value.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_values_simple_list.o: $(SRC_DIR)/arn/arn_values_simple_list.c $(SRC_DIR)/arn/arn_values_simple_list.h $(SRC_DIR)/arn/arn_value.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arn_values_simple_list_tests.o: \
		$(SRC_DIR)/arn/arn_values_simple_list_tests.c \
		$(SRC_DIR)/arn/arn_values_simple_list_tests.h \
		$(SRC_DIR)/arn/arn_values_simple_list.h \
		$(SRC_DIR)/arn/arn_value.h \
		$(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_values_simple_list_tests.o: \
		$(SRC_DIR)/arn/arn_values_simple_list_tests.c \
		$(SRC_DIR)/arn/arn_values_simple_list_tests.h \
		$(SRC_DIR)/arn/arn_values_simple_list.h \
		$(SRC_DIR)/arn/arn_value.h \
		$(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arn_variable.o: $(SRC_DIR)/arn/arn_variable.c $(SRC_DIR)/arn/arn_variable.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_variable.o: $(SRC_DIR)/arn/arn_variable.c $(SRC_DIR)/arn/arn_variable.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arn_variable_tests.o: \
		$(SRC_DIR)/arn/arn_variable_tests.c \
		$(SRC_DIR)/arn/arn_variable_tests.h \
		$(SRC_DIR)/arn/arn_variable.h \
		$(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_variable_tests.o: \
		$(SRC_DIR)/arn/arn_variable_tests.c \
		$(SRC_DIR)/arn/arn_variable_tests.h \
		$(SRC_DIR)/arn/arn_variable.h \
		$(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arn_variables_simple_list.o: $(SRC_DIR)/arn/arn_variables_simple_list.c $(SRC_DIR)/arn/arn_variables_simple_list.h $(SRC_DIR)/arn/arn_variable.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_variables_simple_list.o: $(SRC_DIR)/arn/arn_variables_simple_list.c $(SRC_DIR)/arn/arn_variables_simple_list.h $(SRC_DIR)/arn/arn_variable.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/arn_variables_simple_list_tests.o: \
		$(SRC_DIR)/arn/arn_variables_simple_list_tests.c \
		$(SRC_DIR)/arn/arn_variables_simple_list_tests.h \
		$(SRC_DIR)/arn/arn_variables_simple_list.h \
		$(SRC_DIR)/arn/arn_variable.h \
		$(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/arn_variables_simple_list_tests.o: \
		$(SRC_DIR)/arn/arn_variables_simple_list_tests.c \
		$(SRC_DIR)/arn/arn_variables_simple_list_tests.h \
		$(SRC_DIR)/arn/arn_variables_simple_list.h \
		$(SRC_DIR)/arn/arn_variable.h \
		$(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/flex_tests.o: \
		$(SRC_DIR)/bsn/flex_tests.c \
		$(SRC_DIR)/bsn/flex_tests.h \
		$(SRC_DIR)/bsn/minia.l \
		$(SRC_DIR)/bsn/minia.tab.h \
		$(SRC_DIR)/stt/stt_node.h
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/flex_tests.o: \
		$(SRC_DIR)/bsn/flex_tests.c \
		$(SRC_DIR)/bsn/flex_tests.h \
		$(SRC_DIR)/bsn/minia.l \
		$(SRC_DIR)/bsn/minia.tab.h \
		$(SRC_DIR)/stt/stt_node.h
	$(CC) $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/persistence.o: $(SRC_DIR)/prs/persistence.c $(SRC_DIR)/prs/persistence.h $(SRC_DIR)/wrp/dirent_wrapper.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $(BUILD_DIR_DEBUG)/persistence.o $(SRC_DIR)/prs/persistence.c

$(BUILD_DIR_RELEASE)/persistence.o: $(SRC_DIR)/prs/persistence.c $(SRC_DIR)/prs/persistence.h $(SRC_DIR)/wrp/dirent_wrapper.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $(BUILD_DIR_RELEASE)/persistence.o $(SRC_DIR)/prs/persistence.c

$(BUILD_DIR_DEBUG)/persistence_tests.o: $(SRC_DIR)/prs/persistence_tests.c $(SRC_DIR)/prs/persistence_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $(BUILD_DIR_DEBUG)/persistence_tests.o $(SRC_DIR)/prs/persistence_tests.c

$(BUILD_DIR_RELEASE)/persistence_tests.o: $(SRC_DIR)/prs/persistence_tests.c $(SRC_DIR)/prs/persistence_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $(BUILD_DIR_RELEASE)/persistence_tests.o $(SRC_DIR)/prs/persistence_tests.c

$(BUILD_DIR_DEBUG)/tests_runner.o: $(SRC_DIR)/tst/tests_runner.c $(SRC_DIR)/tst/tests_runner.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $(BUILD_DIR_DEBUG)/tests_runner.o $(SRC_DIR)/tst/tests_runner.c

$(BUILD_DIR_RELEASE)/tests_runner.o: $(SRC_DIR)/tst/tests_runner.c $(SRC_DIR)/tst/tests_runner.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $(BUILD_DIR_RELEASE)/tests_runner.o $(SRC_DIR)/tst/tests_runner.c

$(BUILD_DIR_DEBUG)/dirent_wrapper.o: $(SRC_DIR)/wrp/dirent_wrapper.c $(SRC_DIR)/wrp/dirent_wrapper.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $(BUILD_DIR_DEBUG)/dirent_wrapper.o $(SRC_DIR)/wrp/dirent_wrapper.c

$(BUILD_DIR_RELEASE)/dirent_wrapper.o: $(SRC_DIR)/wrp/dirent_wrapper.c $(SRC_DIR)/wrp/dirent_wrapper.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $(BUILD_DIR_RELEASE)/dirent_wrapper.o $(SRC_DIR)/wrp/dirent_wrapper.c

$(BUILD_DIR_DEBUG)/rtg_application.o: \
		$(SRC_DIR)/rtg/rtg_application.c \
		$(SRC_DIR)/rtg/rtg_application.h \
		$(SRC_DIR)/cmn/amara_string.h \
		$(SRC_DIR)/stt/stt_application.h \
		$(SRC_DIR)/rtg/rtg_named_function.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_application.o: \
		$(SRC_DIR)/rtg/rtg_application.c \
		$(SRC_DIR)/rtg/rtg_application.h \
		$(SRC_DIR)/cmn/amara_string.h \
		$(SRC_DIR)/stt/stt_application.h \
		$(SRC_DIR)/rtg/rtg_named_function.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_application_tests.o: \
		$(SRC_DIR)/rtg/rtg_application_tests.c \
		$(SRC_DIR)/rtg/rtg_application_tests.h \
		$(SRC_DIR)/rtg/rtg_application.h \
		$(SRC_DIR)/cmn/amara_string.h \
		$(SRC_DIR)/stt/stt_application.h \
		$(SRC_DIR)/rtg/rtg_named_function.h \
		$(SRC_DIR)/rtg/rtg_named_function_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_application_tests.o: \
		$(SRC_DIR)/rtg/rtg_application_tests.c \
		$(SRC_DIR)/rtg/rtg_application_tests.h \
		$(SRC_DIR)/rtg/rtg_application.h \
		$(SRC_DIR)/cmn/amara_string.h \
		$(SRC_DIR)/stt/stt_application.h \
		$(SRC_DIR)/rtg/rtg_named_function.h \
		$(SRC_DIR)/rtg/rtg_named_function_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_applications_simple_list.o: \
		$(SRC_DIR)/rtg/rtg_applications_simple_list.c \
		$(SRC_DIR)/rtg/rtg_applications_simple_list.h \
		$(SRC_DIR)/rtg/rtg_application.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_applications_simple_list.o: \
		$(SRC_DIR)/rtg/rtg_applications_simple_list.c \
		$(SRC_DIR)/rtg/rtg_applications_simple_list.h \
		$(SRC_DIR)/rtg/rtg_application.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_applications_simple_list_tests.o: $(SRC_DIR)/rtg/rtg_applications_simple_list_tests.c $(SRC_DIR)/rtg/rtg_applications_simple_list_tests.h $(SRC_DIR)/rtg/rtg_applications_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_applications_simple_list_tests.o: $(SRC_DIR)/rtg/rtg_applications_simple_list_tests.c $(SRC_DIR)/rtg/rtg_applications_simple_list_tests.h $(SRC_DIR)/rtg/rtg_applications_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_condition.o: \
		$(SRC_DIR)/rtg/rtg_condition.c \
		$(SRC_DIR)/rtg/rtg_condition.h \
		$(SRC_DIR)/rtg/rtg_expression.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_condition.o: \
		$(SRC_DIR)/rtg/rtg_condition.c \
		$(SRC_DIR)/rtg/rtg_condition.h \
		$(SRC_DIR)/rtg/rtg_expression.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_condition_tests.o: \
		$(SRC_DIR)/rtg/rtg_condition_tests.c \
		$(SRC_DIR)/rtg/rtg_condition_tests.h \
		$(SRC_DIR)/rtg/rtg_condition.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_condition_tests.o: \
		$(SRC_DIR)/rtg/rtg_condition_tests.c \
		$(SRC_DIR)/rtg/rtg_condition_tests.h \
		$(SRC_DIR)/rtg/rtg_condition.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_doc.o: \
		$(SRC_DIR)/rtg/rtg_doc.c \
		$(SRC_DIR)/rtg/rtg_doc.h \
		$(SRC_DIR)/stt/stt_node.h \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list.h \
		$(SRC_DIR)/rtg/rtg_applications_simple_list.h \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_doc.o: \
		$(SRC_DIR)/rtg/rtg_doc.c \
		$(SRC_DIR)/rtg/rtg_doc.h \
		$(SRC_DIR)/stt/stt_node.h \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list.h \
		$(SRC_DIR)/rtg/rtg_applications_simple_list.h \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_doc_tests.o: $(SRC_DIR)/rtg/rtg_doc_tests.c $(SRC_DIR)/rtg/rtg_doc_tests.h $(SRC_DIR)/rtg/rtg_doc.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_doc_tests.o: $(SRC_DIR)/rtg/rtg_doc_tests.c $(SRC_DIR)/rtg/rtg_doc_tests.h $(SRC_DIR)/rtg/rtg_doc.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_execution_request.o: \
		$(SRC_DIR)/rtg/rtg_execution_request.c \
		$(SRC_DIR)/rtg/rtg_execution_request.h \
		$(SRC_DIR)/rtg/rtg_application.h \
		$(SRC_DIR)/rtg/rtg_applications_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_execution_request.o: \
		$(SRC_DIR)/rtg/rtg_execution_request.c \
		$(SRC_DIR)/rtg/rtg_execution_request.h \
		$(SRC_DIR)/rtg/rtg_application.h \
		$(SRC_DIR)/rtg/rtg_applications_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_execution_request_tests.o: \
		$(SRC_DIR)/rtg/rtg_execution_request_tests.c \
		$(SRC_DIR)/rtg/rtg_execution_request_tests.h \
		$(SRC_DIR)/rtg/rtg_execution_request.h \
		$(SRC_DIR)/rtg/rtg_application.h \
		$(SRC_DIR)/rtg/rtg_named_function_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_execution_request_tests.o: \
		$(SRC_DIR)/rtg/rtg_execution_request_tests.c \
		$(SRC_DIR)/rtg/rtg_execution_request_tests.h \
		$(SRC_DIR)/rtg/rtg_execution_request.h \
		$(SRC_DIR)/rtg/rtg_application.h \
		$(SRC_DIR)/rtg/rtg_named_function_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_execution_requests_simple_list.o: \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list.c \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list.h \
		$(SRC_DIR)/rtg/rtg_execution_request.h \
		$(SRC_DIR)/cmn/amara_strings_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_execution_requests_simple_list.o: \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list.c \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list.h \
		$(SRC_DIR)/rtg/rtg_execution_request.h \
		$(SRC_DIR)/cmn/amara_strings_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_execution_requests_simple_list_tests.o: \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list_tests.c \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list_tests.h \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list.h \
		$(SRC_DIR)/rtg/rtg_execution_request.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_execution_requests_simple_list_tests.o: \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list_tests.c \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list_tests.h \
		$(SRC_DIR)/rtg/rtg_execution_requests_simple_list.h \
		$(SRC_DIR)/rtg/rtg_execution_request.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_expression.o: \
		$(SRC_DIR)/rtg/rtg_expression.c \
		$(SRC_DIR)/rtg/rtg_expression.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression.o: \
		$(SRC_DIR)/rtg/rtg_expression.c \
		$(SRC_DIR)/rtg/rtg_expression.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_expression_sub_conditional.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional.h \
		$(SRC_DIR)/rtg/rtg_expression.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_conditional.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional.h \
		$(SRC_DIR)/rtg/rtg_expression.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_expression_sub_conditional_tests.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional_tests.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional_tests.h \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_conditional_tests.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional_tests.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional_tests.h \
		$(SRC_DIR)/rtg/rtg_expression_sub_conditional.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_expression_sub_dice.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_dice.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_expression_sub_dice_tests.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice_tests.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice_tests.h \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_dice_tests.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice_tests.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice_tests.h \
		$(SRC_DIR)/rtg/rtg_expression_sub_dice.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_expression_sub_identifier.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier.h \
		$(SRC_DIR)/stt/stt_expression_sub_identifier.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_identifier.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier.h \
		$(SRC_DIR)/stt/stt_expression_sub_identifier.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_expression_sub_identifier_tests.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier_tests.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier_tests.h \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_identifier_tests.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier_tests.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier_tests.h \
		$(SRC_DIR)/rtg/rtg_expression_sub_identifier.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_expression_sub_natural_literal.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_natural_literal.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_natural_literal.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_natural_literal.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_natural_literal.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_natural_literal.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_expression_sub_string_literal.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_string_literal.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_string_literal.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_sub_string_literal.o: \
		$(SRC_DIR)/rtg/rtg_expression_sub_string_literal.c \
		$(SRC_DIR)/rtg/rtg_expression_sub_string_literal.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_expression_tests.o: \
		$(SRC_DIR)/rtg/rtg_expression_tests.c \
		$(SRC_DIR)/rtg/rtg_expression_tests.h \
		$(SRC_DIR)/rtg/rtg_expression.h \
		$(SRC_DIR)/rtg/rtg_condition_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_expression_tests.o: \
		$(SRC_DIR)/rtg/rtg_expression_tests.c \
		$(SRC_DIR)/rtg/rtg_expression_tests.h \
		$(SRC_DIR)/rtg/rtg_expression.h \
		$(SRC_DIR)/rtg/rtg_condition_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_named_function.o: \
		$(SRC_DIR)/rtg/rtg_named_function.c \
		$(SRC_DIR)/rtg/rtg_named_function.h \
		$(SRC_DIR)/stt/stt_named_function.h \
		$(SRC_DIR)/rtg/rtg_operations_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_named_function.o: \
		$(SRC_DIR)/rtg/rtg_named_function.c \
		$(SRC_DIR)/rtg/rtg_named_function.h \
		$(SRC_DIR)/stt/stt_named_function.h \
		$(SRC_DIR)/rtg/rtg_operations_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_named_function_tests.o: \
		$(SRC_DIR)/rtg/rtg_named_function_tests.c \
		$(SRC_DIR)/rtg/rtg_named_function_tests.h \
		$(SRC_DIR)/rtg/rtg_named_function.h \
		$(SRC_DIR)/stt/stt_named_function.h \
		$(SRC_DIR)/rtg/rtg_operations_simple_list.h \
		$(SRC_DIR)/rtg/rtg_operation_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_named_function_tests.o: \
		$(SRC_DIR)/rtg/rtg_named_function_tests.c \
		$(SRC_DIR)/rtg/rtg_named_function_tests.h \
		$(SRC_DIR)/rtg/rtg_named_function.h \
		$(SRC_DIR)/stt/stt_named_function.h \
		$(SRC_DIR)/rtg/rtg_operations_simple_list.h \
		$(SRC_DIR)/rtg/rtg_operation_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_named_functions_simple_list.o: \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list.c \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/rtg/rtg_named_function.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_named_functions_simple_list.o: \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list.c \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/rtg/rtg_named_function.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_named_functions_simple_list_tests.o: \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list_tests.c \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list_tests.h \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/rtg/rtg_named_function.h \
		$(SRC_DIR)/rtg/rtg_named_function_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_named_functions_simple_list_tests.o: \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list_tests.c \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list_tests.h \
		$(SRC_DIR)/rtg/rtg_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/rtg/rtg_named_function.h \
		$(SRC_DIR)/rtg/rtg_named_function_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_operation.o: $(SRC_DIR)/rtg/rtg_operation.c $(SRC_DIR)/rtg/rtg_operation.h $(SRC_DIR)/rtg/rtg_operation_args_simple_list.h $(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operation.o: $(SRC_DIR)/rtg/rtg_operation.c $(SRC_DIR)/rtg/rtg_operation.h $(SRC_DIR)/rtg/rtg_operation_args_simple_list.h $(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_operation_arg.o: \
		$(SRC_DIR)/rtg/rtg_operation_arg.c \
		$(SRC_DIR)/rtg/rtg_operation_arg.h \
		$(SRC_DIR)/stt/stt_node.h \
		$(SRC_DIR)/cmn/amara_strings_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operation_arg.o: \
		$(SRC_DIR)/rtg/rtg_operation_arg.c \
		$(SRC_DIR)/rtg/rtg_operation_arg.h \
		$(SRC_DIR)/stt/stt_node.h \
		$(SRC_DIR)/cmn/amara_strings_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_operation_arg_tests.o: $(SRC_DIR)/rtg/rtg_operation_arg_tests.c $(SRC_DIR)/rtg/rtg_operation_arg_tests.h $(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operation_arg_tests.o: $(SRC_DIR)/rtg/rtg_operation_arg_tests.c $(SRC_DIR)/rtg/rtg_operation_arg_tests.h $(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_operation_args_simple_list.o: $(SRC_DIR)/rtg/rtg_operation_args_simple_list.c $(SRC_DIR)/rtg/rtg_operation_args_simple_list.h $(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operation_args_simple_list.o: $(SRC_DIR)/rtg/rtg_operation_args_simple_list.c $(SRC_DIR)/rtg/rtg_operation_args_simple_list.h $(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_operation_args_simple_list_tests.o: $(SRC_DIR)/rtg/rtg_operation_args_simple_list_tests.c $(SRC_DIR)/rtg/rtg_operation_args_simple_list_tests.h $(SRC_DIR)/rtg/rtg_operation_args_simple_list.h $(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operation_args_simple_list_tests.o: $(SRC_DIR)/rtg/rtg_operation_args_simple_list_tests.c $(SRC_DIR)/rtg/rtg_operation_args_simple_list_tests.h $(SRC_DIR)/rtg/rtg_operation_args_simple_list.h $(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_operation_tests.o: $(SRC_DIR)/rtg/rtg_operation_tests.c $(SRC_DIR)/rtg/rtg_operation_tests.h $(SRC_DIR)/rtg/rtg_operation.h $(SRC_DIR)/rtg/rtg_operation_args_simple_list.h $(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operation_tests.o: $(SRC_DIR)/rtg/rtg_operation_tests.c $(SRC_DIR)/rtg/rtg_operation_tests.h $(SRC_DIR)/rtg/rtg_operation.h $(SRC_DIR)/rtg/rtg_operation_args_simple_list.h $(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_operations_simple_list.o: $(SRC_DIR)/rtg/rtg_operations_simple_list.c $(SRC_DIR)/rtg/rtg_operations_simple_list.h $(SRC_DIR)/rtg/rtg_operation.h $(SRC_DIR)/rtg/rtg_operation_args_simple_list.h $(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operations_simple_list.o: $(SRC_DIR)/rtg/rtg_operations_simple_list.c $(SRC_DIR)/rtg/rtg_operations_simple_list.h $(SRC_DIR)/rtg/rtg_operation.h $(SRC_DIR)/rtg/rtg_operation_args_simple_list.h $(SRC_DIR)/rtg/rtg_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_operations_simple_list_tests.o: \
		$(SRC_DIR)/rtg/rtg_operations_simple_list_tests.c \
		$(SRC_DIR)/rtg/rtg_operations_simple_list_tests.h \
		$(SRC_DIR)/rtg/rtg_operations_simple_list.h \
		$(SRC_DIR)/rtg/rtg_operation.h \
		$(SRC_DIR)/rtg/rtg_operation_args_simple_list.h \
		$(SRC_DIR)/rtg/rtg_operation_arg.h \
		$(SRC_DIR)/rtg/rtg_operation_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_operations_simple_list_tests.o: \
		$(SRC_DIR)/rtg/rtg_operations_simple_list_tests.c \
		$(SRC_DIR)/rtg/rtg_operations_simple_list_tests.h \
		$(SRC_DIR)/rtg/rtg_operations_simple_list.h \
		$(SRC_DIR)/rtg/rtg_operation.h \
		$(SRC_DIR)/rtg/rtg_operation_args_simple_list.h \
		$(SRC_DIR)/rtg/rtg_operation_arg.h \
		$(SRC_DIR)/rtg/rtg_operation_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_tests.o: $(SRC_DIR)/rtg/rtg_tests.c $(SRC_DIR)/rtg/rtg_tests.h $(SRC_DIR)/rtg/rtg_applications_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_tests.o: $(SRC_DIR)/rtg/rtg_tests.c $(SRC_DIR)/rtg/rtg_tests.h $(SRC_DIR)/rtg/rtg_applications_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_where_value_binding.o: \
		$(SRC_DIR)/rtg/rtg_where_value_binding.c \
		$(SRC_DIR)/rtg/rtg_where_value_binding.h \
		$(SRC_DIR)/stt/stt_where_value_binding.h \
		$(SRC_DIR)/rtg/rtg_expression.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_where_value_binding.o: \
		$(SRC_DIR)/rtg/rtg_where_value_binding.c \
		$(SRC_DIR)/rtg/rtg_where_value_binding.h \
		$(SRC_DIR)/stt/stt_where_value_binding.h \
		$(SRC_DIR)/rtg/rtg_expression.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_where_value_binding_tests.o: \
		$(SRC_DIR)/rtg/rtg_where_value_binding_tests.c \
		$(SRC_DIR)/rtg/rtg_where_value_binding_tests.h \
		$(SRC_DIR)/stt/stt_where_value_binding.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_where_value_binding_tests.o: \
		$(SRC_DIR)/rtg/rtg_where_value_binding_tests.c \
		$(SRC_DIR)/rtg/rtg_where_value_binding_tests.h \
		$(SRC_DIR)/stt/stt_where_value_binding.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_where_value_bindings_simple_list.o: \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list.c \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list.h \
		$(SRC_DIR)/rtg/rtg_where_value_binding.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_where_value_bindings_simple_list.o: \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list.c \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list.h \
		$(SRC_DIR)/rtg/rtg_where_value_binding.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/rtg_where_value_bindings_simple_list_tests.o: \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list_tests.c \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list_tests.h \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/rtg_where_value_bindings_simple_list_tests.o: \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list_tests.c \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list_tests.h \
		$(SRC_DIR)/rtg/rtg_where_value_bindings_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_application.o: $(SRC_DIR)/stt/stt_application.c $(SRC_DIR)/stt/stt_application.h $(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_application.o: $(SRC_DIR)/stt/stt_application.c $(SRC_DIR)/stt/stt_application.h $(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_application_subnode.o: \
		$(SRC_DIR)/stt/stt_application_subnode.c \
		$(SRC_DIR)/stt/stt_application_subnode.h \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_applications_simple_list.h \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_application_subnode.o: \
		$(SRC_DIR)/stt/stt_application_subnode.c \
		$(SRC_DIR)/stt/stt_application_subnode.h \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_applications_simple_list.h \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_application_subnode_tests.o: $(SRC_DIR)/stt/stt_application_subnode_tests.c $(SRC_DIR)/stt/stt_application_subnode_tests.h $(SRC_DIR)/stt/stt_application_subnode.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_application_subnode_tests.o: $(SRC_DIR)/stt/stt_application_subnode_tests.c $(SRC_DIR)/stt/stt_application_subnode_tests.h $(SRC_DIR)/stt/stt_application_subnode.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_application_tests.o: $(SRC_DIR)/stt/stt_application_tests.c $(SRC_DIR)/stt/stt_application_tests.h $(SRC_DIR)/stt/stt_application.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_application_tests.o: $(SRC_DIR)/stt/stt_application_tests.c $(SRC_DIR)/stt/stt_application_tests.h $(SRC_DIR)/stt/stt_application.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_applications_simple_list.o: $(SRC_DIR)/stt/stt_applications_simple_list.c $(SRC_DIR)/stt/stt_applications_simple_list.h $(SRC_DIR)/stt/stt_application.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_applications_simple_list.o: $(SRC_DIR)/stt/stt_applications_simple_list.c $(SRC_DIR)/stt/stt_applications_simple_list.h $(SRC_DIR)/stt/stt_application.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_applications_simple_list_tests.o: \
		$(SRC_DIR)/stt/stt_applications_simple_list_tests.c \
		$(SRC_DIR)/stt/stt_applications_simple_list_tests.h \
		$(SRC_DIR)/stt/stt_applications_simple_list.h \
		$(SRC_DIR)/stt/stt_application_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_applications_simple_list_tests.o: \
		$(SRC_DIR)/stt/stt_applications_simple_list_tests.c \
		$(SRC_DIR)/stt/stt_applications_simple_list_tests.h \
		$(SRC_DIR)/stt/stt_applications_simple_list.h \
		$(SRC_DIR)/stt/stt_application_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_condition.o: \
		$(SRC_DIR)/stt/stt_condition.c \
		$(SRC_DIR)/stt/stt_condition.h \
		$(SRC_DIR)/stt/stt_expression.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_condition.o: \
		$(SRC_DIR)/stt/stt_condition.c \
		$(SRC_DIR)/stt/stt_condition.h \
		$(SRC_DIR)/stt/stt_expression.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_condition_subnode.o: \
		$(SRC_DIR)/stt/stt_condition_subnode.c \
		$(SRC_DIR)/stt/stt_condition_subnode.h \
		$(SRC_DIR)/stt/stt_condition.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_condition_subnode.o: \
		$(SRC_DIR)/stt/stt_condition_subnode.c \
		$(SRC_DIR)/stt/stt_condition_subnode.h \
		$(SRC_DIR)/stt/stt_condition.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_condition_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_condition_subnode_tests.c \
		$(SRC_DIR)/stt/stt_condition_subnode_tests.h \
		$(SRC_DIR)/stt/stt_condition_subnode.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_condition_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_condition_subnode_tests.c \
		$(SRC_DIR)/stt/stt_condition_subnode_tests.h \
		$(SRC_DIR)/stt/stt_condition_subnode.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_condition_tests.o: \
		$(SRC_DIR)/stt/stt_condition_tests.c \
		$(SRC_DIR)/stt/stt_condition_tests.h \
		$(SRC_DIR)/stt/stt_condition.h \
		$(SRC_DIR)/stt/stt_expression_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_condition_tests.o: \
		$(SRC_DIR)/stt/stt_condition_tests.c \
		$(SRC_DIR)/stt/stt_condition_tests.h \
		$(SRC_DIR)/stt/stt_condition.h \
		$(SRC_DIR)/stt/stt_expression_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_dice_expression.o: \
		$(SRC_DIR)/stt/stt_dice_expression.c \
		$(SRC_DIR)/stt/stt_dice_expression.h \
		$(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_dice_expression.o: \
		$(SRC_DIR)/stt/stt_dice_expression.c \
		$(SRC_DIR)/stt/stt_dice_expression.h \
		$(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_dice_expression_tests.o: \
		$(SRC_DIR)/stt/stt_dice_expression_tests.c \
		$(SRC_DIR)/stt/stt_dice_expression_tests.h \
		$(SRC_DIR)/stt/stt_dice_expression.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_dice_expression_tests.o: \
		$(SRC_DIR)/stt/stt_dice_expression_tests.c \
		$(SRC_DIR)/stt/stt_dice_expression_tests.h \
		$(SRC_DIR)/stt/stt_dice_expression.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_doc_subnode.o: \
		$(SRC_DIR)/stt/stt_doc_subnode.c \
		$(SRC_DIR)/stt/stt_doc_subnode.h \
		$(SRC_DIR)/stt/stt_applications_simple_list.h \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_doc_subnode.o: \
		$(SRC_DIR)/stt/stt_doc_subnode.c \
		$(SRC_DIR)/stt/stt_doc_subnode.h \
		$(SRC_DIR)/stt/stt_applications_simple_list.h \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_doc_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_doc_subnode_tests.c \
		$(SRC_DIR)/stt/stt_doc_subnode_tests.h \
		$(SRC_DIR)/stt/stt_doc_subnode.h \
		$(SRC_DIR)/stt/stt_applications_simple_list.h \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list.h \
		$(SRC_DIR)/stt/stt_named_function_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_doc_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_doc_subnode_tests.c \
		$(SRC_DIR)/stt/stt_doc_subnode_tests.h \
		$(SRC_DIR)/stt/stt_doc_subnode.h \
		$(SRC_DIR)/stt/stt_applications_simple_list.h \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_execution_requests_simple_list.h \
		$(SRC_DIR)/stt/stt_named_function_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_execution_request.o: $(SRC_DIR)/stt/stt_execution_request.c $(SRC_DIR)/stt/stt_execution_request.h $(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_execution_request.o: $(SRC_DIR)/stt/stt_execution_request.c $(SRC_DIR)/stt/stt_execution_request.h $(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_execution_request_subnode.o: $(SRC_DIR)/stt/stt_execution_request_subnode.c $(SRC_DIR)/stt/stt_execution_request_subnode.h $(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_execution_request_subnode.o: $(SRC_DIR)/stt/stt_execution_request_subnode.c $(SRC_DIR)/stt/stt_execution_request_subnode.h $(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_execution_request_subnode_tests.o: $(SRC_DIR)/stt/stt_execution_request_subnode_tests.c $(SRC_DIR)/stt/stt_execution_request_subnode_tests.h $(SRC_DIR)/stt/stt_execution_request_subnode.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_execution_request_subnode_tests.o: $(SRC_DIR)/stt/stt_execution_request_subnode_tests.c $(SRC_DIR)/stt/stt_execution_request_subnode_tests.h $(SRC_DIR)/stt/stt_execution_request_subnode.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_execution_request_tests.o: $(SRC_DIR)/stt/stt_execution_request_tests.c $(SRC_DIR)/stt/stt_execution_request_tests.h $(SRC_DIR)/stt/stt_execution_request.h $(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_execution_request_tests.o: $(SRC_DIR)/stt/stt_execution_request_tests.c $(SRC_DIR)/stt/stt_execution_request_tests.h $(SRC_DIR)/stt/stt_execution_request.h $(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_execution_requests_simple_list.o: $(SRC_DIR)/stt/stt_execution_requests_simple_list.c $(SRC_DIR)/stt/stt_execution_requests_simple_list.h $(SRC_DIR)/stt/stt_execution_request.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_execution_requests_simple_list.o: $(SRC_DIR)/stt/stt_execution_requests_simple_list.c $(SRC_DIR)/stt/stt_execution_requests_simple_list.h $(SRC_DIR)/stt/stt_execution_request.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_execution_requests_simple_list_tests.o: $(SRC_DIR)/stt/stt_execution_requests_simple_list_tests.c $(SRC_DIR)/stt/stt_execution_requests_simple_list_tests.h $(SRC_DIR)/stt/stt_execution_requests_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_execution_requests_simple_list_tests.o: $(SRC_DIR)/stt/stt_execution_requests_simple_list_tests.c $(SRC_DIR)/stt/stt_execution_requests_simple_list_tests.h $(SRC_DIR)/stt/stt_execution_requests_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_expression.o: \
		$(SRC_DIR)/stt/stt_expression.c \
		$(SRC_DIR)/stt/stt_expression.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression.o: \
		$(SRC_DIR)/stt/stt_expression.c \
		$(SRC_DIR)/stt/stt_expression.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_expression_sub_conditional.o: \
		$(SRC_DIR)/stt/stt_expression_sub_conditional.c \
		$(SRC_DIR)/stt/stt_expression_sub_conditional.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_conditional.o: \
		$(SRC_DIR)/stt/stt_expression_sub_conditional.c \
		$(SRC_DIR)/stt/stt_expression_sub_conditional.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_expression_sub_conditional_tests.o: \
		$(SRC_DIR)/stt/stt_expression_sub_conditional_tests.c \
		$(SRC_DIR)/stt/stt_expression_sub_conditional_tests.h \
		$(SRC_DIR)/stt/stt_expression_sub_conditional.h \
		$(SRC_DIR)/stt/stt_expression.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_conditional_tests.o: \
		$(SRC_DIR)/stt/stt_expression_sub_conditional_tests.c \
		$(SRC_DIR)/stt/stt_expression_sub_conditional_tests.h \
		$(SRC_DIR)/stt/stt_expression_sub_conditional.h \
		$(SRC_DIR)/stt/stt_expression.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_expression_sub_dice.o: \
		$(SRC_DIR)/stt/stt_expression_sub_dice.c \
		$(SRC_DIR)/stt/stt_expression_sub_dice.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_dice.o: \
		$(SRC_DIR)/stt/stt_expression_sub_dice.c \
		$(SRC_DIR)/stt/stt_expression_sub_dice.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_expression_sub_dice_tests.o: \
		$(SRC_DIR)/stt/stt_expression_sub_dice_tests.c \
		$(SRC_DIR)/stt/stt_expression_sub_dice_tests.h \
		$(SRC_DIR)/stt/stt_expression_sub_dice.h \
		$(SRC_DIR)/brt/natural_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_dice_tests.o: \
		$(SRC_DIR)/stt/stt_expression_sub_dice_tests.c \
		$(SRC_DIR)/stt/stt_expression_sub_dice_tests.h \
		$(SRC_DIR)/stt/stt_expression_sub_dice.h \
		$(SRC_DIR)/brt/natural_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_expression_sub_identifier.o: \
		$(SRC_DIR)/stt/stt_expression_sub_identifier.c \
		$(SRC_DIR)/stt/stt_expression_sub_identifier.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_identifier.o: \
		$(SRC_DIR)/stt/stt_expression_sub_identifier.c \
		$(SRC_DIR)/stt/stt_expression_sub_identifier.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_expression_sub_identifier_tests.o: \
		$(SRC_DIR)/stt/stt_expression_sub_identifier_tests.c \
		$(SRC_DIR)/stt/stt_expression_sub_identifier_tests.h \
		$(SRC_DIR)/stt/stt_expression_sub_identifier.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_identifier_tests.o: \
		$(SRC_DIR)/stt/stt_expression_sub_identifier_tests.c \
		$(SRC_DIR)/stt/stt_expression_sub_identifier_tests.h \
		$(SRC_DIR)/stt/stt_expression_sub_identifier.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_expression_sub_natural_literal.o: \
		$(SRC_DIR)/stt/stt_expression_sub_natural_literal.c \
		$(SRC_DIR)/stt/stt_expression_sub_natural_literal.h \
		$(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_natural_literal.o: \
		$(SRC_DIR)/stt/stt_expression_sub_natural_literal.c \
		$(SRC_DIR)/stt/stt_expression_sub_natural_literal.h \
		$(SRC_DIR)/brt/natural.h \
		$(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_expression_sub_string_literal.o: \
		$(SRC_DIR)/stt/stt_expression_sub_string_literal.c \
		$(SRC_DIR)/stt/stt_expression_sub_string_literal.h \
		$(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_sub_string_literal.o: \
		$(SRC_DIR)/stt/stt_expression_sub_string_literal.c \
		$(SRC_DIR)/stt/stt_expression_sub_string_literal.h \
		$(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_expression_subnode.o: \
		$(SRC_DIR)/stt/stt_expression_subnode.c \
		$(SRC_DIR)/stt/stt_expression_subnode.h \
		$(SRC_DIR)/stt/stt_expression.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_subnode.o: \
		$(SRC_DIR)/stt/stt_expression_subnode.c \
		$(SRC_DIR)/stt/stt_expression_subnode.h \
		$(SRC_DIR)/stt/stt_expression.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_expression_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_expression_subnode_tests.c \
		$(SRC_DIR)/stt/stt_expression_subnode_tests.h \
		$(SRC_DIR)/stt/stt_expression_subnode.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_expression_subnode_tests.c \
		$(SRC_DIR)/stt/stt_expression_subnode_tests.h \
		$(SRC_DIR)/stt/stt_expression_subnode.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_expression_tests.o: \
		$(SRC_DIR)/stt/stt_expression_tests.c \
		$(SRC_DIR)/stt/stt_expression_tests.h \
		$(SRC_DIR)/stt/stt_expression.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_expression_tests.o: \
		$(SRC_DIR)/stt/stt_expression_tests.c \
		$(SRC_DIR)/stt/stt_expression_tests.h \
		$(SRC_DIR)/stt/stt_expression.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_named_function.o: \
		$(SRC_DIR)/stt/stt_named_function.c \
		$(SRC_DIR)/stt/stt_named_function.h \
		$(SRC_DIR)/cmn/amara_string.h \
		$(SRC_DIR)/stt/stt_operations_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_named_function.o: \
		$(SRC_DIR)/stt/stt_named_function.c \
		$(SRC_DIR)/stt/stt_named_function.h \
		$(SRC_DIR)/cmn/amara_string.h \
		$(SRC_DIR)/stt/stt_operations_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_named_function_subnode.o: \
		$(SRC_DIR)/stt/stt_named_function_subnode.c \
		$(SRC_DIR)/stt/stt_named_function_subnode.h \
		$(SRC_DIR)/cmn/amara_string.h \
		$(SRC_DIR)/stt/stt_operations_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_named_function_subnode.o: \
		$(SRC_DIR)/stt/stt_named_function_subnode.c \
		$(SRC_DIR)/stt/stt_named_function_subnode.h \
		$(SRC_DIR)/cmn/amara_string.h \
		$(SRC_DIR)/stt/stt_operations_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_named_function_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_named_function_subnode_tests.c \
		$(SRC_DIR)/stt/stt_named_function_subnode_tests.h \
		$(SRC_DIR)/stt/stt_named_function_subnode.h \
		$(SRC_DIR)/stt/stt_operation_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_named_function_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_named_function_subnode_tests.c \
		$(SRC_DIR)/stt/stt_named_function_subnode_tests.h \
		$(SRC_DIR)/stt/stt_named_function_subnode.h \
		$(SRC_DIR)/stt/stt_operation_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_named_function_tests.o: \
		$(SRC_DIR)/stt/stt_named_function_tests.c \
		$(SRC_DIR)/stt/stt_named_function_tests.h \
		$(SRC_DIR)/stt/stt_named_function.h \
		$(SRC_DIR)/stt/stt_operation_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_named_function_tests.o: \
		$(SRC_DIR)/stt/stt_named_function_tests.c \
		$(SRC_DIR)/stt/stt_named_function_tests.h \
		$(SRC_DIR)/stt/stt_named_function.h \
		$(SRC_DIR)/stt/stt_operation_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_named_functions_simple_list.o: \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.c \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_named_function.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_named_functions_simple_list.o: \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.c \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_named_function.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_named_functions_simple_list_tests.o: \
		$(SRC_DIR)/stt/stt_named_functions_simple_list_tests.c \
		$(SRC_DIR)/stt/stt_named_functions_simple_list_tests.h \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_named_function_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_named_functions_simple_list_tests.o: \
		$(SRC_DIR)/stt/stt_named_functions_simple_list_tests.c \
		$(SRC_DIR)/stt/stt_named_functions_simple_list_tests.h \
		$(SRC_DIR)/stt/stt_named_functions_simple_list.h \
		$(SRC_DIR)/stt/stt_named_function_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_identifier_subnode.o: $(SRC_DIR)/stt/stt_identifier_subnode.c $(SRC_DIR)/stt/stt_identifier_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/asr/assertion.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_identifier_subnode.o: $(SRC_DIR)/stt/stt_identifier_subnode.c $(SRC_DIR)/stt/stt_identifier_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/asr/assertion.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_identifier_subnode_tests.o: $(SRC_DIR)/stt/stt_identifier_subnode_tests.c $(SRC_DIR)/stt/stt_identifier_subnode_tests.h $(SRC_DIR)/stt/stt_identifier_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/asr/assertion.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_identifier_subnode_tests.o: $(SRC_DIR)/stt/stt_identifier_subnode_tests.c $(SRC_DIR)/stt/stt_identifier_subnode_tests.h $(SRC_DIR)/stt/stt_identifier_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/asr/assertion.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_integer_literal_subnode.o: $(SRC_DIR)/stt/stt_integer_literal_subnode.c $(SRC_DIR)/stt/stt_integer_literal_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/asr/assertion.h $(SRC_DIR)/brt/integer.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_integer_literal_subnode.o: $(SRC_DIR)/stt/stt_integer_literal_subnode.c $(SRC_DIR)/stt/stt_integer_literal_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/asr/assertion.h $(SRC_DIR)/brt/integer.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_integer_literal_subnode_tests.o: $(SRC_DIR)/stt/stt_integer_literal_subnode_tests.c $(SRC_DIR)/stt/stt_integer_literal_subnode_tests.h $(SRC_DIR)/stt/stt_integer_literal_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/asr/assertion.h $(SRC_DIR)/brt/integer.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_integer_literal_subnode_tests.o: $(SRC_DIR)/stt/stt_integer_literal_subnode_tests.c $(SRC_DIR)/stt/stt_integer_literal_subnode_tests.h $(SRC_DIR)/stt/stt_integer_literal_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/asr/assertion.h $(SRC_DIR)/brt/integer.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_natural_literal_subnode.o: $(SRC_DIR)/stt/stt_natural_literal_subnode.c $(SRC_DIR)/stt/stt_natural_literal_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_natural_literal_subnode.o: $(SRC_DIR)/stt/stt_natural_literal_subnode.c $(SRC_DIR)/stt/stt_natural_literal_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_natural_literal_subnode_tests.o: $(SRC_DIR)/stt/stt_natural_literal_subnode_tests.c $(SRC_DIR)/stt/stt_natural_literal_subnode_tests.h $(SRC_DIR)/stt/stt_natural_literal_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_natural_literal_subnode_tests.o: $(SRC_DIR)/stt/stt_natural_literal_subnode_tests.c $(SRC_DIR)/stt/stt_natural_literal_subnode_tests.h $(SRC_DIR)/stt/stt_natural_literal_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/brt/natural.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_node.o: \
		$(SRC_DIR)/stt/stt_node.c \
		$(SRC_DIR)/stt/stt_node.h \
		$(SRC_DIR)/stt/stt_doc_subnode.h \
		$(SRC_DIR)/stt/stt_applications_simple_list.h \
		$(SRC_DIR)/cmn/char_array.h \
		$(SRC_DIR)/cmn/char_arrays_simple_list.h \
		$(SRC_DIR)/asr/assertion.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_node.o: \
		$(SRC_DIR)/stt/stt_node.c \
		$(SRC_DIR)/stt/stt_node.h \
		$(SRC_DIR)/stt/stt_doc_subnode.h \
		$(SRC_DIR)/stt/stt_applications_simple_list.h \
		$(SRC_DIR)/cmn/char_array.h \
		$(SRC_DIR)/cmn/char_arrays_simple_list.h \
		$(SRC_DIR)/asr/assertion.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_node_tests.o: \
		$(SRC_DIR)/stt/stt_node_tests.c \
		$(SRC_DIR)/stt/stt_node_tests.h \
		$(SRC_DIR)/stt/stt_node.h \
		$(SRC_DIR)/stt/stt_doc_subnode.h \
		$(SRC_DIR)/cmn/char_array.h \
		$(SRC_DIR)/cmn/char_arrays_simple_list.h \
		$(SRC_DIR)/stt/stt_named_function_tests.h \
		$(SRC_DIR)/stt/stt_named_function_subnode_tests.h \
		$(SRC_DIR)/stt/stt_doc_subnode_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_node_tests.o: \
		$(SRC_DIR)/stt/stt_node_tests.c \
		$(SRC_DIR)/stt/stt_node_tests.h \
		$(SRC_DIR)/stt/stt_node.h \
		$(SRC_DIR)/stt/stt_doc_subnode.h \
		$(SRC_DIR)/cmn/char_array.h \
		$(SRC_DIR)/cmn/char_arrays_simple_list.h \
		$(SRC_DIR)/stt/stt_named_function_tests.h \
		$(SRC_DIR)/stt/stt_named_function_subnode_tests.h \
		$(SRC_DIR)/stt/stt_doc_subnode_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_operation.o: $(SRC_DIR)/stt/stt_operation.c $(SRC_DIR)/stt/stt_operation.h $(SRC_DIR)/stt/stt_operation_args_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation.o: $(SRC_DIR)/stt/stt_operation.c $(SRC_DIR)/stt/stt_operation.h $(SRC_DIR)/stt/stt_operation_args_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_operation_arg.o: \
		$(SRC_DIR)/stt/stt_operation_arg.c \
		$(SRC_DIR)/stt/stt_operation_arg.h \
		$(SRC_DIR)/stt/stt_node.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_arg.o: \
		$(SRC_DIR)/stt/stt_operation_arg.c \
		$(SRC_DIR)/stt/stt_operation_arg.h \
		$(SRC_DIR)/stt/stt_node.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_operation_arg_tests.o: \
		$(SRC_DIR)/stt/stt_operation_arg_tests.c \
		$(SRC_DIR)/stt/stt_operation_arg_tests.h \
		$(SRC_DIR)/stt/stt_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_arg_tests.o: \
		$(SRC_DIR)/stt/stt_operation_arg_tests.c \
		$(SRC_DIR)/stt/stt_operation_arg_tests.h \
		$(SRC_DIR)/stt/stt_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_operation_args_simple_list.o: $(SRC_DIR)/stt/stt_operation_args_simple_list.c $(SRC_DIR)/stt/stt_operation_args_simple_list.h $(SRC_DIR)/stt/stt_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_args_simple_list.o: $(SRC_DIR)/stt/stt_operation_args_simple_list.c $(SRC_DIR)/stt/stt_operation_args_simple_list.h $(SRC_DIR)/stt/stt_operation_arg.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_operation_args_simple_list_tests.o: $(SRC_DIR)/stt/stt_operation_args_simple_list_tests.c $(SRC_DIR)/stt/stt_operation_args_simple_list_tests.h $(SRC_DIR)/stt/stt_operation_args_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_args_simple_list_tests.o: $(SRC_DIR)/stt/stt_operation_args_simple_list_tests.c $(SRC_DIR)/stt/stt_operation_args_simple_list_tests.h $(SRC_DIR)/stt/stt_operation_args_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_operation_subnode.o: $(SRC_DIR)/stt/stt_operation_subnode.c $(SRC_DIR)/stt/stt_operation_subnode.h $(SRC_DIR)/stt/stt_operation.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_subnode.o: $(SRC_DIR)/stt/stt_operation_subnode.c $(SRC_DIR)/stt/stt_operation_subnode.h $(SRC_DIR)/stt/stt_operation.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_operation_subnode_tests.o: $(SRC_DIR)/stt/stt_operation_subnode_tests.c $(SRC_DIR)/stt/stt_operation_subnode_tests.h $(SRC_DIR)/stt/stt_operation_subnode.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_subnode_tests.o: $(SRC_DIR)/stt/stt_operation_subnode_tests.c $(SRC_DIR)/stt/stt_operation_subnode_tests.h $(SRC_DIR)/stt/stt_operation_subnode.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_operation_tests.o: $(SRC_DIR)/stt/stt_operation_tests.c $(SRC_DIR)/stt/stt_operation_tests.h $(SRC_DIR)/stt/stt_operation.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operation_tests.o: $(SRC_DIR)/stt/stt_operation_tests.c $(SRC_DIR)/stt/stt_operation_tests.h $(SRC_DIR)/stt/stt_operation.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_operations_list_subnode.o: $(SRC_DIR)/stt/stt_operations_list_subnode.c $(SRC_DIR)/stt/stt_operations_list_subnode.h $(SRC_DIR)/stt/stt_operations_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operations_list_subnode.o: $(SRC_DIR)/stt/stt_operations_list_subnode.c $(SRC_DIR)/stt/stt_operations_list_subnode.h $(SRC_DIR)/stt/stt_operations_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_operations_list_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_operations_list_subnode_tests.c \
		$(SRC_DIR)/stt/stt_operations_list_subnode_tests.h \
		$(SRC_DIR)/stt/stt_operations_list_subnode.h \
		$(SRC_DIR)/stt/stt_operation_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operations_list_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_operations_list_subnode_tests.c \
		$(SRC_DIR)/stt/stt_operations_list_subnode_tests.h \
		$(SRC_DIR)/stt/stt_operations_list_subnode.h \
		$(SRC_DIR)/stt/stt_operation_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_operations_simple_list.o: $(SRC_DIR)/stt/stt_operations_simple_list.c $(SRC_DIR)/stt/stt_operations_simple_list.h $(SRC_DIR)/stt/stt_operation.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operations_simple_list.o: $(SRC_DIR)/stt/stt_operations_simple_list.c $(SRC_DIR)/stt/stt_operations_simple_list.h $(SRC_DIR)/stt/stt_operation.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_operations_simple_list_tests.o: \
		$(SRC_DIR)/stt/stt_operations_simple_list_tests.c \
		$(SRC_DIR)/stt/stt_operations_simple_list_tests.h \
		$(SRC_DIR)/stt/stt_operations_simple_list.h \
		$(SRC_DIR)/stt/stt_operation.h \
		$(SRC_DIR)/stt/stt_operation_tests.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_operations_simple_list_tests.o: \
		$(SRC_DIR)/stt/stt_operations_simple_list_tests.c \
		$(SRC_DIR)/stt/stt_operations_simple_list_tests.h \
		$(SRC_DIR)/stt/stt_operations_simple_list.h \
		$(SRC_DIR)/stt/stt_operation.h \
		$(SRC_DIR)/stt/stt_operation_tests.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_rational_literal_subnode.o: $(SRC_DIR)/stt/stt_rational_literal_subnode.c $(SRC_DIR)/stt/stt_rational_literal_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/asr/assertion.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_rational_literal_subnode.o: $(SRC_DIR)/stt/stt_rational_literal_subnode.c $(SRC_DIR)/stt/stt_rational_literal_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/asr/assertion.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_rational_literal_subnode_tests.o: $(SRC_DIR)/stt/stt_rational_literal_subnode_tests.c $(SRC_DIR)/stt/stt_rational_literal_subnode_tests.h $(SRC_DIR)/stt/stt_rational_literal_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/asr/assertion.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_rational_literal_subnode_tests.o: $(SRC_DIR)/stt/stt_rational_literal_subnode_tests.c $(SRC_DIR)/stt/stt_rational_literal_subnode_tests.h $(SRC_DIR)/stt/stt_rational_literal_subnode.h $(SRC_DIR)/cmn/amara_string.h $(SRC_DIR)/asr/assertion.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_string_literal_subnode.o: $(SRC_DIR)/stt/stt_string_literal_subnode.c $(SRC_DIR)/stt/stt_string_literal_subnode.h $(SRC_DIR)/cmn/amara_boolean.h $(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_string_literal_subnode.o: $(SRC_DIR)/stt/stt_string_literal_subnode.c $(SRC_DIR)/stt/stt_string_literal_subnode.h $(SRC_DIR)/cmn/amara_boolean.h $(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_string_literal_subnode_tests.o: $(SRC_DIR)/stt/stt_string_literal_subnode_tests.c $(SRC_DIR)/stt/stt_string_literal_subnode_tests.h $(SRC_DIR)/stt/stt_string_literal_subnode.h $(SRC_DIR)/cmn/amara_boolean.h $(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_string_literal_subnode_tests.o: $(SRC_DIR)/stt/stt_string_literal_subnode_tests.c $(SRC_DIR)/stt/stt_string_literal_subnode_tests.h $(SRC_DIR)/stt/stt_string_literal_subnode.h $(SRC_DIR)/cmn/amara_boolean.h $(SRC_DIR)/cmn/amara_string.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_tests.o: $(SRC_DIR)/stt/stt_tests.c $(SRC_DIR)/stt/stt_tests.h $(SRC_DIR)/stt/stt_node.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_tests.o: $(SRC_DIR)/stt/stt_tests.c $(SRC_DIR)/stt/stt_tests.h $(SRC_DIR)/stt/stt_node.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_where_value_binding.o: \
		$(SRC_DIR)/stt/stt_where_value_binding.c \
		$(SRC_DIR)/stt/stt_where_value_binding.h \
		$(SRC_DIR)/cmn/amara_string.h \
		$(SRC_DIR)/stt/stt_expression.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_binding.o: \
		$(SRC_DIR)/stt/stt_where_value_binding.c \
		$(SRC_DIR)/stt/stt_where_value_binding.h \
		$(SRC_DIR)/cmn/amara_string.h \
		$(SRC_DIR)/stt/stt_expression.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_where_value_binding_subnode.o: \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode.c \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode.h \
		$(SRC_DIR)/stt/stt_where_value_binding.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_binding_subnode.o: \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode.c \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode.h \
		$(SRC_DIR)/stt/stt_where_value_binding.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_where_value_binding_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode_tests.c \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode_tests.h \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_binding_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode_tests.c \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode_tests.h \
		$(SRC_DIR)/stt/stt_where_value_binding_subnode.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_where_value_binding_tests.o: \
		$(SRC_DIR)/stt/stt_where_value_binding_tests.c \
		$(SRC_DIR)/stt/stt_where_value_binding_tests.h \
		$(SRC_DIR)/stt/stt_where_value_binding.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_binding_tests.o: \
		$(SRC_DIR)/stt/stt_where_value_binding_tests.c \
		$(SRC_DIR)/stt/stt_where_value_binding_tests.h \
		$(SRC_DIR)/stt/stt_where_value_binding.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_where_value_bindings_simple_list.o: \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list.c \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list.h \
		$(SRC_DIR)/stt/stt_where_value_binding.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_bindings_simple_list.o: \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list.c \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list.h \
		$(SRC_DIR)/stt/stt_where_value_binding.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_where_value_bindings_simple_list_tests.o: \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list_tests.c \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list_tests.h \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_bindings_simple_list_tests.o: \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list_tests.c \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list_tests.h \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_where_value_bindings_subnode.o: \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode.c \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode.h \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_bindings_subnode.o: \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode.c \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode.h \
		$(SRC_DIR)/stt/stt_where_value_bindings_simple_list.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

$(BUILD_DIR_DEBUG)/stt_where_value_bindings_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode_tests.c \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode_tests.h \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode.h
	gcc $(CFLAGS) $(CFLAGS_DEBUG) -c -o $@ $<

$(BUILD_DIR_RELEASE)/stt_where_value_bindings_subnode_tests.o: \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode_tests.c \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode_tests.h \
		$(SRC_DIR)/stt/stt_where_value_bindings_subnode.h
	gcc $(CFLAGS) $(CFLAGS_RELEASE) -c -o $@ $<

# TODO   Fix `utils/grammar/bison_extractor.py` into accepting (requiring, actually) `-i` and `-o` parameters, then simplify this sh.
$(RESOURCES_DIR)/minia.grammar: $(SRC_DIR)/bsn/minia.y
	pwd && \
			cd $(UTILS_DIR)/grammar/ && \
			pwd && \
			./bison_extractor.py && \
			cd ../../ && \
			pwd

.PHONY: all checkdirs clean default amara_g amara

clean:
	rm -fv \
			$(BUILD_DIR_DEBUG)/amara_g \
			$(BUILD_DIR_RELEASE)/amara \
			$(BUILD_DIR_DEBUG)/*.o \
			$(BUILD_DIR_RELEASE)/*.o \
			$(BUILD_DIR_DEBUG)/*.gcno \
			$(SRC_DIR)/bsn/minia.tab.c \
			$(SRC_DIR)/bsn/lex.minia.c \
			$(SRC_DIR)/bsn/minia.tab.h
