alfabet="abcdefghijklmnopqrstuvwxyz"

def findChar(z: str):
    z=z.lower()
    for i,k in enumerate(alfabet):
        if z==k:
            return i
    return -1

def kodKlucz(wsad: str, klucz: str):
    indx: int
    indxklucz: int = 0
    out=""
    for i, x in enumerate(wsad):
        k = klucz[indxklucz]
        indxklucz+=1
        indx=(findChar(x) + findChar(k))%26
        out+=alfabet[indx]
        if indxklucz>=len(klucz):
            indxklucz=0
    return out

wsad="abcdefxyz"
wynikzklucza = kodKlucz(wsad, "ab")
print(f"wynik z klucza: {wynikzklucza}")