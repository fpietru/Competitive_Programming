i=0
while true
do
	./gen $i > in1
	./a < in1 > out1
	./brut < in1 > out2
	if diff out1 out2 > gowno; then
		echo "Test $i OK"
	else
		echo "Test $i NIE ok"
		echo "Wejscie:"
		cat in1
		echo "Powinno byc:"
		cat out2
		echo "Jest:"
		cat out1
		break
	fi
	((i++))
done
