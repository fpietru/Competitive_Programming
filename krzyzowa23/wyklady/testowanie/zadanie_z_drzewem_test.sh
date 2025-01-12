N=50

for i in {1..10000}
do
    echo -n "$i "
    ./gen-tree $i $N >myin
    ./judge $N <myin >out1
    ./wa <out1 >myout
    ./judge $N <myout >out2
    diff out1 out2 || break
    echo "OK"
done
