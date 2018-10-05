#!/usr/bin/env python3

#
# Copyright 2018 Mercedes Catherine Salazar
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
# utils/qa/run_examples.py: Python script using `pexpect` for doing
# several miscellaneous checks.
#


from os import devnull as os_devnull

from pexpect import spawnu as pexpect_spawnu

from pexpect.fdpexpect import fdspawn as pexpect_fdpexpect_fdspawn

import subprocess


def greet_no_banner():
    child_ = pexpect_spawnu('./build/release/amara greet --no-banner')
    child_.expect('Wish you have a wonderful day!')

def run_tests():
    command_and_args_ = [
            './build/release/amara', 'run', 'tests', '--no-banner']
    dev_null_ = open(os_devnull, 'w')
    command_ = subprocess.Popen(
            command_and_args_, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
            stderr=dev_null_)
    child_ = pexpect_fdpexpect_fdspawn(command_.stdout)
    child_.expect('Running tests...\n... done\n')
    dev_null_.close()

def hello_world():
    command_and_args_ = [
            './build/release/amara', 'run', 'app', 'examples/0_hello_world/',
            '--no-banner']
    dev_null_ = open(os_devnull, 'w')
    command_ = subprocess.Popen(
            command_and_args_, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
            stderr=dev_null_)
    child_ = pexpect_fdpexpect_fdspawn(command_.stdout)
    child_.expect('hello, world')
    dev_null_.close()

def functions_structure():
    command_and_args_ = [
            './build/release/amara', 'run', 'app', 'examples/1_functions_structure/',
            '--no-banner']
    dev_null_ = open(os_devnull, 'w')
    command_ = subprocess.Popen(
            command_and_args_, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
            stderr=dev_null_)
    child_ = pexpect_fdpexpect_fdspawn(command_.stdout)
    child_.expect('hello, world')
    dev_null_.close()

def naturals_substraction():
    command_and_args_ = [
            './build/release/amara', 'run', 'app', 'examples/2.0_naturals_substraction/',
            '--no-banner']
    dev_null_ = open(os_devnull, 'w')
    command_ = subprocess.Popen(
            command_and_args_, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
            stderr=dev_null_)
    child_ = pexpect_fdpexpect_fdspawn(command_.stdout)
    child_.expect('9 minus 2 equals to 7, which is of type natural')
    dev_null_.close()

def naturals_division():
    command_and_args_ = [
            './build/release/amara', 'run', 'app', 'examples/2.1_naturals_division/',
            '--no-banner']
    dev_null_ = open(os_devnull, 'w')
    command_ = subprocess.Popen(
            command_and_args_, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
            stderr=dev_null_)
    child_ = pexpect_fdpexpect_fdspawn(command_.stdout)
    child_.expect('18 divided by 3 equals to 6, with type natural')
    dev_null_.close()

def combine_math_operators_division_and_substraction():
    command_and_args_ = [
            './build/release/amara', 'run', 'app', 'examples/2.2_combine_math_operators_division_and_substraction/',
            '--no-banner']
    dev_null_ = open(os_devnull, 'w')
    command_ = subprocess.Popen(
            command_and_args_, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
            stderr=dev_null_)
    child_ = pexpect_fdpexpect_fdspawn(command_.stdout)
    child_.expect('18 divided by 3 minus 2 equals to 4, with type natural')
    dev_null_.close()

def combine_math_operators_substraction_and_division():
    command_and_args_ = [
            './build/release/amara', 'run', 'app', 'examples/2.3_combine_math_operators_substraction_and_division/',
            '--no-banner']
    dev_null_ = open(os_devnull, 'w')
    command_ = subprocess.Popen(
            command_and_args_, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
            stderr=dev_null_)
    child_ = pexpect_fdpexpect_fdspawn(command_.stdout)
    child_.expect('38 minus 20 divided by 4 equals to 33, with type natural')
    dev_null_.close()

def fahrenheit_to_celsius():
    command_and_args_ = [
            './build/release/amara', 'run', 'app', 'examples/2.4_fahrenheit_to_celsius/',
            '--no-banner']
    dev_null_ = open(os_devnull, 'w')
    command_ = subprocess.Popen(
            command_and_args_, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
            stderr=dev_null_)
    child_ = pexpect_fdpexpect_fdspawn(command_.stdout)
    child_.expect('99 degrees Fahrenheit equals to 37')
    child_.expect('(with type "natural")')
    child_.expect('degrees Celsius using the formula:')
    child_.expect('(99 minus 32)')
    child_.expect('times 5 divided by 9')
    child_.expect('=')
    child_.expect('37')
    dev_null_.close()

def do():
    greet_no_banner()
    run_tests()
    hello_world()
    functions_structure()
    naturals_substraction()
    naturals_division()
    combine_math_operators_division_and_substraction()
    combine_math_operators_substraction_and_division()
    fahrenheit_to_celsius()

def run():
    do()

if __name__ == '__main__':
    run()
