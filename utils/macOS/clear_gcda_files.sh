#!/bin/sh


SUCCESS='0'

GCDA_DOCS=`find ./ | grep \.gcda$`

# echo "\${GCDA_DOCS}: ${GCDA_DOCS}"

if test $? -eq 64 -o $? -eq 1
then
    # echo $?
    true
else
    # echo $?
    rm -v ${GCDA_DOCS} && exit ${SUCCESS} || exit ${SUCCESS}
fi
