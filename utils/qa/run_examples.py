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

def structure():
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

def do():
    greet_no_banner()
    run_tests()
    hello_world()
    structure()
    naturals_substraction()

def run():
    do()

if __name__ == '__main__':
    run()
