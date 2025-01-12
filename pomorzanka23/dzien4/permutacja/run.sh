i=0
while true
do
	./gen $i > in1
	./a < in1 > out1
	./brut < in1 > out2
	if diff out1 out2 > res; then
		echo "$(tput bold)$(tput setaf 2)OK$(tput sgr0) $i"
	else
		echo "Wejscie:"
		cat in1
		echo "Brut:"
		cat out2
		echo "Rozw:"
		cat out1
		break
	fi
	((i++))
done
