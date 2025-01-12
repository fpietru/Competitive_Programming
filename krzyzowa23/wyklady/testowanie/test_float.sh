N=6

for i in {1..10000}
do
    echo -n "test $i "
    ./gen $i $N >myin
    ./wzo <myin >out1
    ./brut <myin >out2
    ./diff_float out1 out2 || break
    echo "OK"
done
