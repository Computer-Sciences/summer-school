#!/bin/bash

if [ -f "../bin/replace.gcda" ]; then
	rm -rf ../bin/replace.gcda
fi

if [ -f "../bin/replace.c.cov" ]; then
	rm -rf ../bin/replace.c.cov
fi

for i in {1..5542}
do
	c="t${i}.sh"
	echo $c
	bash $c > /dev/null
done

gcov ../bin/replace.c
