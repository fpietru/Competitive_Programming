mith, zloto, srebro, miedz = input().split(":")

mith = int(mith)
zloto = int(zloto)
srebro = int(srebro)
miedz = int(miedz)

srebro += miedz // 12
miedz %= 12

zloto += srebro // 20
srebro %= 20

mith += zloto // 100
zloto %= 100

print(f"{mith}:{zloto}:{srebro}:{miedz}")