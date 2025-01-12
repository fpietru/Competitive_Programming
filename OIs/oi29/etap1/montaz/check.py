import os
import sys

test_id = int(sys.argv[1])
test_dir = "testy_male"

ans1 = open(f"./{test_dir}/out/mon{test_id}.out", "r").read()

os.system(f"./mon < ./{test_dir}/in/mon{test_id}.in > tmp_out")

ans2 = open("./tmp_out", "r").read()

os.remove("./tmp_out")

print("Expected =", ans1, "Got =", ans2)