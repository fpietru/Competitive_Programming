i=0
while true
do
	./gen $i > in
	./brut < in > out1
	./ple < in > out2
	if diff out1 out2; then
		echo "Test $i OK"
	else
		echo "Cos sie zepsulo :("
		echo "Wejscie:"
		cat in
		echo "Brut:"
		cat out1
		echo "Rozw:"
		cat out2
		break
	fi
	((i++))
done
