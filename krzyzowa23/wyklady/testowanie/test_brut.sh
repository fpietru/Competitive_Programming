N=6

for i in {1..10000}
do
    echo -n "test $i "
    ./gen $i $N >myin

    # head -n X == wypisz X pierwszych linijek

    ./wzo <myin | head -n 1 >out1
    # mozna tez tak
    # ./wzo <myin >out1_cale
    # head -n 1 <out1_cale >out1

    ./brut <myin | head -n 1 >out2
    diff out1 out2 || break
    echo "OK"
done
