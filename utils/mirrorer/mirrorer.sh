#!/bin/sh


ACCOUNT="foo"
USER="bar"
PASSWORD="baz"


until false
do
    for repo in minia amara pangolin
    do
        rm -rfv "${repo}/"
        git clone "git://localhost/home/admin/repositories/${repo}"
        cd "${repo}/"
        # git checkout master
        git remote add github \
                "https://${USER}:${PASSWORD}@github.com/${ACCOUNT}/${repo}"
        branches=`git branch --list --all | \
                grep origin |                \
                sed 's/ -> .*//' |            \
                awk '{ print $1 }' |           \
                sed 's/remotes\/origin\///' |   \
                grep -v HEAD`
        for branch in ${branches}
        do
            git checkout "${branch}"
            git push --force github "${branch}"
            date
            echo 'sleeping 60'
            sleep 60
        done
        cd ../
        rm -rfv "${repo}/"
        date
        echo 'sleeping 300'
        sleep 300
    done
    date
    echo 'sleeping 3600'
    sleep 3600
done
