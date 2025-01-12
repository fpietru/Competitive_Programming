i=0
while true
do
	echo "Test nr. $i"
	./mxgen $i > in1
	time ./a < in1 > out1
	((i++))
done
