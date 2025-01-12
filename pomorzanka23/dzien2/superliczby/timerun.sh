i=0
while true
do
	./gen $i > in1
	time ./a < in1 > res
	((i++))
done
