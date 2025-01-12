i=0
while true
do
	./gen $i > in1
	./brut < in1 > out1
	./a < in1 > out2
	if diff out1 out2; then
		echo "Test $i OK"
	else
		echo "Cos sie wywalilo ://"
		echo "Wejscie:"
		cat in1
		echo "Brut:"
		cat out1
		echo "Rozw:"
		cat out2
		break
	fi
	((i++))
done
