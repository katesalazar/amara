#!/bin/sh


SUCCESS='0'


rm -v `find ./ | grep \.gcda$` && exit ${SUCCESS} || exit ${SUCCESS}
