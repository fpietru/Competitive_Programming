
i=1
while true
do
	./gen $i > in
	./brut < in > out1
	./zdj < in > out2
	if diff out1 out2; then
		echo "Test $i OK"
	else
		echo "Test $i WA"
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
