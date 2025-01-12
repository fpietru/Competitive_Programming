N=6

for i in {1..10000}
do
    echo -n "test $i "
    ./gen $i $N 0 >myin0
    ./gen $i $N 1 >myin1

    ./wzo <myin0 | head -n 1 >out0
    ./wzo <myin1 | head -n 1 >out1

    diff out0 out1 || break
    echo "OK"
done
