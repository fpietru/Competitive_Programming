make b
for i in {0..50000}
do
	./b < ./testy/$i.in > out
	if diff -w ./testy/$i.out out; then
		echo "Test $i OK"
	else
		echo "Cos sie wywalilo ://"
		echo "Wejscie:"
		cat ./testy/$i.in
		echo "b:"
		cat out
		echo "Rozw:"
		cat ./testy/$i.out
		break
	fi
done
