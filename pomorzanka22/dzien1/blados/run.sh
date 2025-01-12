#!/bin/bash
i=0
while true
do
	./gen $i > in1
	./a < in1 > out1
	./brut < in1> out2
	if diff -w out1 out2 > info; then
		echo "Test $i OK"
	else
		echo "Test $i NIE ok"
		echo "Wejscie:"
		cat in1
		echo "Oczekiwano:"
		cat out2
		echo "Otrzymano:"
		cat out1
		break
	fi
	((i++))
done
