i=0
while true
do
	./gen $i > in1
	./a < in1 > out1
	if diff out1 ans > res; then
		break
	else
		echo "OK $i"
	fi
	((i++))
done
