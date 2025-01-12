i=0
while true
do
	./gen $i > in1
	./a < in1 > out1
	./brut < in1 > out2
	if diff out1 out2 > res; then
		echo "OK test $i"
	else
		echo "WA test $i"
		cat in1
		echo "BRUT:"
		cat out2
		echo "a:"
		cat out1
		break
	fi
	((i++))
done
