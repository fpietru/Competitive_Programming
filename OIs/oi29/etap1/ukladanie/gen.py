import os
import sys

k = 1

for i in range(2, 11):
	for j in range(2, 300):
		print(k, i, j);
		in_file = open(f"./in/ukl{k}.in", "w")
		in_file.write(f"{i} {j}")
		in_file.close()
		os.system(f"./ok < ./in/ukl{k}.in > ./out/ukl{k}.out")
		k += 1