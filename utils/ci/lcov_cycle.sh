#!/bin/sh

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
# utils/ci/lcov_cycle.sh: This should run debug cases demonstrating
# tests coverage.
#


FORCE=0

BASE='/var/www/html/lcov/github/????'

ORIGINAL_BRANCH=$(git branch | grep '*' | cut -d ' ' -f 2)


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
	previous_hash=${current_hash}
	nice -n 19 git fetch origin
	nice -n 19 git checkout ${branch}
	nice -n 19 git reset --hard origin/${branch}
	current_hash=`nice -n 19 git log --pretty=%H | head -1`
	if test ${previous_hash} != ${current_hash} \
			-o ! -d ${BASE}/amara/${branch}/ \
			-o ${FORCE} -eq 1
	then
		true &&
				FORCE=0 &&
				nice -n 19 rm -fv `find ./ | grep gcno$` &&
				#   FIXME REMOVE THIS LATER. FIXME POSSIBLE DOT BAD ESCAPE.
				rm -rfv `find ./ | grep '\.o$' | grep -v '.git'`
				nice -n 19 make clean &&
				nice -n 19 make all &&
				nice -n 19 rm -fv `find ./ | grep gcda$` &&
				nice -n 19 ./build/debug/amara_g
				nice -n 19 ./build/debug/amara_g \
						--tests
				nice -n 19 ./build/debug/amara_g \
						--run examples/pong/
				nice -n 19 ./build/debug/amara_g \
						--run examples/foo_is_not_any_dir/
				nice -n 19 ./build/debug/amara_g \
						says
				nice -n 19 ./build/debug/amara_g \
						says hello
				nice -n 19 ./build/debug/amara_g \
						says hello to the world
				nice -n 19 ./build/debug/amara_g \
						--assert 0
#				nice -n 19 valgrind --quiet \
#						./build/debug/amara_g &&
#				nice -n 19 valgrind --quiet \
#						./build/debug/amara_g says &&
#				nice -n 19 valgrind --quiet \
#						./build/debug/amara_g --tests &&
#				nice -n 19 valgrind --quiet \
#						./build/debug/amara_g says hello &&
#				nice -n 19 valgrind --quiet \
#						./build/release/amara &&
#				nice -n 19 valgrind --quiet \
#						./build/release/amara says &&
#				nice -n 19 valgrind --quiet \
#						./build/release/amara --tests &&
#				nice -n 19 valgrind --quiet \
#						./build/release/amara says hello &&
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
						-o ./gcov_results/ \
						lcov.info &&
				sudo rm -rfv ${BASE}/amara/${branch}/ &&
				sudo cp -rfv ./gcov_results/ \
						${BASE}/amara/${branch}/ &&
				figlet built ${branch} &&
				sleep 1
	fi
done
nice -n 19 git checkout ${ORIGINAL_BRANCH}
date
echo 'sleep 3600...'
sleep 3600
done
