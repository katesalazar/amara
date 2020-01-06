#!/bin/sh

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
# utils/ci/lcov_cycle_plus.sh: This should run debug cases demonstrating
# tests coverage.
#


FORCE=0

BASE='/var/www/html/lcov'

ORIGINAL_BRANCH=`git branch | grep '*' | cut -d ' ' -f 2`


if test $# -eq 1
then
	if test "$1" = '--force'
	then
		FORCE=1
	fi
fi

current_hash=`nice -n 19 git log --pretty=%H | head -1`

until false
do
for branch in master integration experimental
do
	previous_hash=${current_hash} &&
			nice -n 19 git fetch origin &&
			# nice -n 19 git pull &&
			nice -n 19 git checkout ${branch} &&
			nice -n 19 git reset --hard origin/${branch} &&
			current_hash=`nice -n 19 git log --pretty=%H | head -1`
	if test ${previous_hash} != ${current_hash} \
			-o ! -d ${BASE}/amara/${branch}/ \
			-o ${FORCE} -eq 1
	then
		rm -rfv build/
		if test "${branch}" = 'not-used-any-more'
		then
			PATH_TO_BSN_SOURCES="../../src/"
		else
			PATH_TO_BSN_SOURCES="../src/"
		fi
		true &&
				FORCE=0 &&
				nice -n 19 rm -fv `find ./ | grep gcno$` &&
				#   FIXME REMOVE THIS LATER. FIXME POSSIBLE DOT BAD ESCAPE.
				rm -rfv `find ./ | grep '\.o$' | grep -v '.git'` &&
# TODO the `clean` target is only guaranteed to exist if this script is called from the amara base directory.
				nice -n 19 make clean &&
				nice -n 19 make all
                                if test $? -ne 0
                                then
echo 'build failed'
break
fi
				cd build/debug/ &&
				rm -fv minia.l &&
				rm -fv lex.minia.c &&
				rm -fv minia.tab.c &&
				rm -fv minia.y &&
				ln -s ${PATH_TO_BSN_SOURCES}/bsn/minia.l &&
				ln -s ${PATH_TO_BSN_SOURCES}/bsn/lex.minia.c &&
				ln -s ${PATH_TO_BSN_SOURCES}/bsn/minia.tab.c &&
				ln -s ${PATH_TO_BSN_SOURCES}/bsn/minia.y &&
				cd ../../ &&
				nice -n 19 rm -fv `find ./ | grep gcda$` &&
				echo 'nice -n 19 ./build/debug/amara_g' &&
				nice -n 19 ./build/debug/amara_g
		true &&
				echo 'nice -n 19 ./build/release/amara' &&
				nice -n 19 ./build/release/amara
		if test "${branch}" = 'experimental'
		then
			echo 'nice -n 19 ./build/debug/amara_g run scrambled_tests'
			nice -n 19 ./build/debug/amara_g run scrambled_tests
			echo 'nice -n 19 ./build/release/amara run scrambled_tests'
			nice -n 19 ./build/release/amara run scrambled_tests
		else
			echo 'nice -n 19 ./build/debug/amara_g run tests'
			nice -n 19 ./build/debug/amara_g run tests
			echo 'nice -n 19 ./build/release/amara run tests'
			nice -n 19 ./build/release/amara run tests
		fi

		if test $? -ne 0
		then
			echo 'continuing (at line 68)'
			continue
		fi
		echo 'nice -n 19 ./build/debug/amara_g run app examples/0_hello_world'
		nice -n 19 ./build/debug/amara_g \
				run app examples/0_hello_world
		echo 'nice -n 19 ./build/debug/amara_g run app examples/0_hello_world --no-banner'
		nice -n 19 ./build/debug/amara_g \
				run app examples/0_hello_world --no-banner
		# echo 'nice -n 19 ./build/debug/amara_g run app examples/1_operations_sequencing/'
		# nice -n 19 ./build/debug/amara_g \
		# 		run app examples/1_operations_sequencing/
# 		if test "${branch}" = 'integration' -o "${branch}" = 'master'
# 		then
# 			echo "nice -n 19 ./build/debug/amara_g run app 'examples/'"
# 			nice -n 19 ./build/debug/amara_g \
# 					run app 'examples/'
# 			echo "nice -n 19 ./build/debug/amara_g run app 'examples/2_naturals_substraction'"
# 			nice -n 19 ./build/debug/amara_g \
# 					run app 'examples/2_naturals_substraction'
# 			echo "nice -n 19 ./build/debug/amara_g run app 'examples/3_naturals_division/'"
# 			nice -n 19 ./build/debug/amara_g \
# 					run app 'examples/3_naturals_division/'
# 		fi
# 		if test "${branch}" = 'integration' -o "${branch}" = 'master'
# 		then
			echo 'nice -n 19 ./build/debug/amara_g greet'
			nice -n 19 ./build/debug/amara_g \
					greet
# 		fi
		if test $? -ne 0
		then
			echo 'continuing (at line 85)'
			continue
		fi
		echo 'nice -n 19 ./build/debug/amara_g says'
		nice -n 19 ./build/debug/amara_g \
				says
# 		if test "${branch}" = 'integration' -o "${branch}" = 'master'
# 		then
# 			echo 'nice -n 19 ./build/debug/amara_g run app examples/0_hello_world/'
# 			nice -n 19 ./build/debug/amara_g run app examples/0_hello_world/
			# echo 'nice -n 19 ./build/debug/amara_g run app examples/1_operations_sequencing'
			# nice -n 19 ./build/debug/amara_g run app examples/1_operations_sequencing
# 		if test "${branch}" = 'integration' -o "${branch}" = 'master'
# 		then
# 			echo "nice -n 19 ./build/debug/amara_g run app 'examples/2_naturals_substraction/'"
# 			nice -n 19 ./build/debug/amara_g run app 'examples/2_naturals_substraction/'
# 		fi
			echo 'nice -n 19 ./build/debug/amara_g greet --no-banner'
			nice -n 19 ./build/debug/amara_g greet --no-banner
			echo 'nice -n 19 ./build/debug/amara_g greet foo'
			nice -n 19 ./build/debug/amara_g greet foo
			echo 'nice -n 19 ./build/debug/amara_g run foo'
			nice -n 19 ./build/debug/amara_g run foo
			if test "${branch}" = 'experimental'
			then
				echo 'nice -n 19 ./build/debug/amara_g run scrambled_tests --no-banner'
				nice -n 19 ./build/debug/amara_g run scrambled_tests --no-banner
				echo 'nice -n 19 ./build/debug/amara_g run scrambled_tests foo'
				nice -n 19 ./build/debug/amara_g run scrambled_tests foo
			else
				echo 'nice -n 19 ./build/debug/amara_g run tests --no-banner'
				nice -n 19 ./build/debug/amara_g run tests --no-banner
				echo 'nice -n 19 ./build/debug/amara_g run tests foo'
				nice -n 19 ./build/debug/amara_g run tests foo
			fi
			echo 'nice -n 19 ./build/debug/amara_g run foo --no-banner'
			nice -n 19 ./build/debug/amara_g run foo --no-banner
			echo 'nice -n 19 ./build/debug/amara_g assert 1 --no-banner'
			nice -n 19 ./build/debug/amara_g assert 1 --no-banner
			echo 'nice -n 19 ./build/debug/amara_g foo 1 --no-banner'
			nice -n 19 ./build/debug/amara_g foo 1 --no-banner
# 		fi
			echo 'nice -n 19 ./build/debug/amara_g assert 0'
			nice -n 19 ./build/debug/amara_g \
					assert 0
			echo 'nice -n 19 ./build/debug/amara_g assert 1'
			nice -n 19 ./build/debug/amara_g \
					assert 1
			echo 'nice -n 19 ./build/debug/amara_g assert 0 "failed to assert"'
			nice -n 19 ./build/debug/amara_g \
					assert 0 "failed to assert"
			echo 'nice -n 19 ./build/debug/amara_g assert 1 "failed to assert"'
			nice -n 19 ./build/debug/amara_g \
					assert 1 "failed to assert"
		echo 'nice -n 19 ./build/debug/amara_g says hello'
		nice -n 19 ./build/debug/amara_g \
				says hello
		echo 'nice -n 19 ./build/debug/amara_g run app examples/foo_is_not_any_existing_dir/'
		nice -n 19 ./build/debug/amara_g \
				run app examples/foo_is_not_any_existing_dir/
		mkdir examples/foo_is_an_existing_dir/
		echo 'nice -n 19 ./build/debug/amara_g run app examples/foo_is_an_existing_dir/'
		nice -n 19 ./build/debug/amara_g \
				run app examples/foo_is_an_existing_dir/
		rmdir examples/foo_is_an_existing_dir/
		echo 'nice -n 19 ./build/debug/amara_g says hello to the world'
		nice -n 19 ./build/debug/amara_g \
				says hello to the world
		true &&
# 				echo 'nice -n 19 valgrind --quiet ./build/debug/amara_g' &&
# 				nice -n 19 valgrind --quiet \
# 						./build/debug/amara_g &&
# 				echo 'nice -n 19 valgrind --quiet ./build/release/amara' &&
# 				nice -n 19 valgrind --quiet \
# 						./build/release/amara &&
# 				echo 'nice -n 19 valgrind --quiet ./build/debug/amara_g --tests' &&
# 				nice -n 19 valgrind --quiet \
# 						./build/debug/amara_g --tests &&
# 				echo 'nice -n 19 valgrind --quiet ./build/release/amara --tests' &&
# 				nice -n 19 valgrind --quiet \
# 						./build/release/amara --tests &&
				true
		if test $? -ne 0
		then
			echo 'continuing (at line 151)'
			continue
		fi
# 		echo 'nice -n 19 valgrind --quiet ./build/debug/amara_g says' &&
# 		nice -n 19 valgrind --quiet \
# 				./build/debug/amara_g says
# 		echo 'nice -n 19 valgrind --quiet ./build/release/amara says' &&
# 		nice -n 19 valgrind --quiet \
# 				./build/release/amara says
# 		echo 'nice -n 19 valgrind --quiet ./build/debug/amara_g says hello' &&
# 		nice -n 19 valgrind --quiet \
# 				./build/debug/amara_g says hello
# 		echo 'nice -n 19 valgrind --quiet ./build/release/amara says hello' &&
# 		nice -n 19 valgrind --quiet \
# 				./build/release/amara says hello

		echo 99 | ./build/debug/amara_g run app ./examples/7_fahrenheit_to_celsius_stdin/ --THIS_WILL_FAIL_USING_FOR_COVERAGE
		echo 99 | ./build/debug/amara_g run --THIS_WILL_FAIL_USING_FOR_COVERAGE ./examples/7_fahrenheit_to_celsius_stdin/ --no-banner
		echo 99 | ./build/debug/amara_g --THIS_WILL_FAIL_USING_FOR_COVERAGE app ./examples/7_fahrenheit_to_celsius_stdin/ --no-banner

		echo 'running examples...'
		./utils/qa/run_examples.py
		echo 'runned examples...'

# 		echo 99 | ./build/debug/amara_g run app ./examples/7_fahrenheit_to_celsius_stdin/ --no-banner

		true &&
				#   Removed the `gcov` call because it seemed
				# to break the `lcov` branch coverage report.
				# nice -n 19 gcov \
				# 		--branch-probabilities \
				# 		`find ./ | grep gcda` &&
				nice -n 19 rm -fv lcov.info &&
				#   FIXME REMOVE THIS LATER.
				rm -rfv `find ./ | grep lcov.info`
				nice -n 19 lcov \
						--capture \
						--no-external \
						--rc lcov_branch_coverage=1 \
						--directory ./ \
						--output lcov.info &&
				rm -rfv ./gcov_results/ &&
				#   I still don't understand what is the
				# difference in using `--show-details` in
				# `genhtml`, or not to use it, so I leave it
				# out for now.
				#   Can not use `--frames` in `genhtml` because
				# it seems to break branches coverage.
				nice -n 19 genhtml \
						--branch-coverage \
						--title 'amara' \
						--precision 2 \
						--output-directory \
								./gcov_results/ \
						lcov.info &&

				#   Dark orange in details changed to
				# light red.
				sed 's/FF6230/F99F99/g' ./gcov_results/gcov.css | \
						#   Blue in details
						# changed to light green.
						sed 's/CAD7FE/B4E8A7/g' | \
						#   Change the green
						# in summaries.
						sed 's/A7FC9D/66EE44/g' | \
						#   Changed the yellow
						# in summaries.
						sed 's/FFEA20/FFD942/g' | \
						#   Change the red in
						# summaries.
						sed 's/FF0000/FF4242/g' | \
						sponge ./gcov_results/gcov.css &&

				cp ./misc/emerald.png ./gcov_results/emerald.png &&
				cp ./misc/ruby.png ./gcov_results/ruby.png &&
				cp ./misc/amber.png ./gcov_results/amber.png &&

				true &&

				sudo rm -rfv ${BASE}/amara/${branch}/ &&
				sudo cp -rfv ./gcov_results/ \
						${BASE}/amara/${branch}/ &&
				(figlet -w `tput cols` succeeded ${branch} &&
						sleep 10) ||
					(true &&
							sudo rm -rfv ${BASE}/amara/${branch}/ &&
							sudo mkdir ${BASE}/amara/${branch}/ &&
							touch ./index.html &&
							echo 'the build failed' >>./index.html &&
							sudo mv ./index.html ${BASE}/amara/${branch}/index.html
							figlet -w `tput cols` failed ${branch} &&
							sleep 10)

		rm -fv build/debug/minia.l &&
				rm -fv build/debug/lex.minia.c &&
				rm -fv build/debug/minia.tab.c &&
				rm -fv build/debug/minia.y
	fi
done
nice -n 19 git checkout ${ORIGINAL_BRANCH}
date
echo 'sleep 3600...'
sleep 3600
done
