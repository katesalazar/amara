#!/bin/sh


until false
do
	git fetch origin
	for branch in master integration experimental
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
			binary="./build/debug/amara_g"
		else
			binary="ERROR_18"
		fi
#		rm "${binary}" || break
		make all || continue
		valgrind --leak-check=full --show-leak-kinds=all --num-callers=24 "${binary}" run tests 2>&1 | nl >valgrind_report || (echo 'valgrind returned bad' && continue)
		mv ./valgrind_report /var/www/html/valgrind/amara/${branch}/valgrind_report || (echo 'mv returned bad' && continue)
		date
		echo 'sleeping 10'
		sleep 10
	done
	git checkout valgrind-worker
	date
	echo 'sleeping 3600'
	sleep 3600
done
