#!/bin/sh

#
# Copyright 2019 Mercedes Catherine Salazar
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
# utils/ci/valgrind-worker.sh: This should run debug cases
# demonstrating leak bugs as shown by `valgrind`, if applicable.
#


until false
do
	git fetch origin
	for branch in master integration experimental experimental0 \
			experimental1
	do
		git checkout ${branch} || break
		git reset --hard origin/${branch} || break
		make clean || break
		if test "${branch}" = 'master'
		then
			binary="./build/debug/amara_g_not_stripped"
		elif test "${branch}" = 'integration'
		then
			binary="./build/debug/amara_g_not_stripped"
		elif test "${branch}" = 'experimental'
		then
			binary="./build/debug/amara_g_not_stripped"
		elif test "${branch}" = 'experimental0'
		then
			binary="./build/debug/amara_g_not_stripped"
		elif test "${branch}" = 'experimental1'
		then
			binary="./build/debug/amara_g_not_stripped"
		else
			binary="ERROR_18"
		fi
#		rm "${binary}" || break
		make all || continue
		valgrind \
				--leak-check=full \
				--show-leak-kinds=all \
				--num-callers=24 \
				"${binary}"\
				run tests \
				2>&1 | \
				nl -b a >valgrind_report || ( \
				echo 'valgrind returned bad' && \
				continue)
		mv \
				./valgrind_report \
				/var/www/html/valgrind/amara/${branch}/valgrind_report || ( \
				echo 'mv returned bad' && continue)
		valgrind \
				--leak-check=full \
				--show-leak-kinds=all \
				--num-callers=24 \
				--verbose \
				"${binary}"\
				run tests \
				2>&1 | \
				nl -b a >valgrind_verbose_report || ( \
				echo 'valgrind returned bad' && \
				continue)
		mv \
				./valgrind_verbose_report \
				/var/www/html/valgrind/amara/${branch}/valgrind_verbose_report || ( \
				echo 'mv returned bad' && continue)
		valgrind \
				--leak-check=full \
				--show-leak-kinds=all \
				--num-callers=24 \
				--verbose --verbose \
				"${binary}"\
				run tests \
				2>&1 | \
				nl -b a >valgrind_doubly_verbose_report || ( \
				echo 'valgrind returned bad' && \
				continue)
		mv \
				./valgrind_doubly_verbose_report \
				/var/www/html/valgrind/amara/${branch}/valgrind_doubly_verbose_report || ( \
				echo 'mv returned bad' && continue)
		date
		echo 'sleeping 10'
		sleep 10
	done
	git checkout ci
	date
	echo 'sleeping 7200'
	sleep 7200
done
