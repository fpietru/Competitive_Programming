import os
import sys

test_id = int(sys.argv[1])
test_dir = "testy_duze2"
pattern = "dom"

ans1 = open(f"./{test_dir}/out/{pattern}{test_id}.out", "r").read()

os.system(f"./{pattern} < ./{test_dir}/in/{pattern}{test_id}.in > tmp_out")

ans2 = open("./tmp_out", "r").read()

os.remove("./tmp_out")

print("Expected =", ans1, "Got =", ans2.rstrip())