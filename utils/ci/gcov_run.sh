#!/bin/sh

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
# utils/ci/gcov_run.sh: This should run debug cases demonstrating tests
# coverage.
#


true &&
		nice -n 19 make clean &&
		nice -n 19 rm -fv `find ./ | grep gcno$` &&
		nice -n 19 make all &&
		nice -n 19 rm -fv `find ./ | grep gcda$`

if test $? -ne 0
then
	echo 'THE BUILD HAS FAILED'
	exit 1
fi

success='false'

for i in `seq 0 1`
do
	true &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g greet`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g greet &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g greet --no-banner`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g greet --no-banner &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g assert 1`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g assert 1 &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g assert 1 --no-banner`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g assert 1 --no-banner &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g assert 1 message_word`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g assert 1 message_word &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g run app ./examples/hello_world/`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g run app ./examples/hello_world/ &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g run app ./examples/hello_world`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g run app ./examples/hello_world &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g
	true &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g greet foo`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g greet foo
	true &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g run app`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g run app
	true &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g run tests foo`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g run tests foo
	true &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g run foo bar`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g run foo bar
	true &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g foo bar baz`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g foo bar baz
	true &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g run tests`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g run tests &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g run tests --no-banner`' &&
			nice -n 19 valgrind --quiet \
					./build/debug/amara_g run tests --no-banner &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/release/amara greet`' &&
			nice -n 19 valgrind --quiet \
					./build/release/amara greet &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/release/amara greet --no-banner`' &&
			nice -n 19 valgrind --quiet \
					./build/release/amara greet --no-banner &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/release/amara`' &&
			nice -n 19 valgrind --quiet \
					./build/release/amara
	true &&
			echo 'will run now `nice -n 19 valgrind --quiet ./build/release/amara_g run tests`' &&
			nice -n 19 valgrind --quiet \
					./build/release/amara run tests
	if test $? -ne 0
	then
		# break
		exit 1
	fi
	echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g`'
	nice -n 19 valgrind --quiet \
			./build/debug/amara_g says
# 	if test $? -ne 0
# 	then
# 		echo 'will run now `nice -n 19 valgrind ./build/debug/amara_g`'
# 		nice -n 19 valgrind \
# 				./build/debug/amara_g says
# 		# break
# 		exit 1
# 	fi
	echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g says hello`'
	nice -n 19 valgrind --quiet \
			./build/debug/amara_g says hello
# 	if test $? -ne 0
# 	then
# 		echo 'will run now `nice -n 19 valgrind ./build/debug/amara_g says hello`'
# 		nice -n 19 valgrind \
# 				./build/debug/amara_g says hello
# 		# break
# 		exit 1
# 	fi
	echo 'will run now `nice -n 19 valgrind --quiet ./build/debug/amara_g says hello to the world`'
	nice -n 19 valgrind --quiet \
			./build/debug/amara_g says hello to the world
# 	if test $? -ne 0
# 	then
# 		echo 'will run now `nice -n 19 valgrind ./build/debug/amara_g says hello to the world`'
# 		nice -n 19 valgrind \
# 				./build/debug/amara_g says hello to the world
# 		# break
# 		exit 1
# 	fi
	echo 'will run now `nice -n 19 valgrind --quiet ./build/release/amara says`'
	nice -n 19 valgrind --quiet \
			./build/release/amara says
# 	if test $? -ne 0
# 	then
# 		echo 'will run now `nice -n 19 valgrind ./build/release/amara says`'
# 		nice -n 19 valgrind \
# 				./build/release/amara says
# 		# break
# 		exit 1
# 	fi
	echo 'will run now `nice -n 19 valgrind --quiet ./build/release/amara says hello`'
	nice -n 19 valgrind --quiet \
			./build/release/amara says hello
# 	if test $? -ne 0
# 	then
# 		echo 'will run now `nice -n 19 valgrind ./build/release/amara says hello`'
# 		nice -n 19 valgrind \
# 				./build/release/amara says hello
# 		# break
# 		exit 1
# 	fi
	echo 'will run now `nice -n 19 valgrind --quiet ./build/release/amara says hello to the world`'
	nice -n 19 valgrind --quiet \
			./build/release/amara says hello to the world
# 	if test $? -ne 0
# 	then
# 		echo 'will run now `nice -n 19 valgrind ./build/release/amara says hello to the world`'
# 		nice -n 19 valgrind \
# 				./build/release/amara says hello to the world
# 		# break
# 		exit 1
# 	fi
	true &&
			echo 'I am at 153' &&
			echo 'will run now `nice -n 19 ./build/debug/amara_g`' &&
			nice -n 19 ./build/debug/amara_g
	true &&
			echo 'I am at 157' &&
			echo 'will run now `nice -n 19 ./build/debug/amara_g greet`' &&
			nice -n 19 ./build/debug/amara_g greet &&
			echo 'will run now `nice -n 19 ./build/debug/amara_g assert 1`' &&
			nice -n 19 ./build/debug/amara_g assert 1 &&
			echo 'will run now `nice -n 19 ./build/debug/amara_g assert 1 foo`' &&
			nice -n 19 ./build/debug/amara_g assert 1 foo &&
			echo 'will run now `nice -n 19 ./build/debug/amara_g run tests`' &&
			nice -n 19 ./build/debug/amara_g \
					run tests &&
			echo 'will run now `nice -n 19 ./build/debug/amara_g run app examples/pong/`' &&
			nice -n 19 ./build/debug/amara_g \
					run app examples/pong/ &&
			echo 'will run now `nice -n 19 ./build/debug/amara_g run app examples/foo_is_supposed_not_to_be_any_existing_dir/`' &&
			nice -n 19 ./build/debug/amara_g \
					run app examples/foo_is_supposed_not_to_be_any_existing_dir/
	#   XXX Must review later.
	success='true'
	echo 'will run now `nice -n 19 ./build/debug/amara_g says`' &&
	nice -n 19 ./build/debug/amara_g \
			says
	echo 'will run now `nice -n 19 ./build/debug/amara_g says hello`' &&
	nice -n 19 ./build/debug/amara_g \
			says hello
	echo 'will run now `nice -n 19 ./build/debug/amara_g says hello to the world`' &&
	nice -n 19 ./build/debug/amara_g \
			says hello to the world
done

if test "${success}" = 'false'
then
	echo "THE BUILD DOESN'T PASS VALGRIND CHECKS WITHOUT HINTS"
	exit 1
fi

true &&
		clear &&
		nice -n 19 gcov \
				--branch-probabilities \
				`find ./ | grep gcda` \

if test $? -ne 0
then
	echo '`gcov` seems to be failing for some reason'
	exit 1
fi

exit 0
