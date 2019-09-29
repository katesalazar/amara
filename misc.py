#!/usr/bin/env python3

#   Copyright 2019 Mercedes Catherine Salazar
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#
#   misc.py: Example tail recursion.


def fact(n):
    if n == 1:
        print("base case reached: returning 1")
        return 1
    n_minus_one_ = n - 1
    print("recursive case: call fact(" + str(n_minus_one_) + ')')
    recursive_ = fact(n - 1)
    print("multiply recursive return (" + str(recursive_) + ") by " + str(n))
    ret_ = recursive_ * n
    print("return " + str(ret_))
    return ret_


def tail_fact_inner(n, a):
    if n == 1:
        print("base case reached: returning " + str(a))
        return a
    print("recursive case: compute new n")
    n_minus_one_ = n - 1
    print("recursive case: compute new a")
    new_acc_ = a * n
    print("recursive case: call tail_fact_inner(" + str(n_minus_one_) + ', ' + str(new_acc_) + ')')
    recursive_ = tail_fact_inner(n_minus_one_, new_acc_)
    print("return " + str(recursive_))
    return recursive_


def tail_fact(n):
    return tail_fact_inner(n, 1)


print(fact(5))


print(tail_fact(5))
