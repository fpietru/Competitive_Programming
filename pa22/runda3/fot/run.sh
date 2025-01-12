#!/bin/bash
for i in {1..120}
do
	./gen $i > in3
	./a < in3 > outa
	cat in3
	cat outa
	echo ""
done
