alfabet="abcdefghijklmnopqrstuvwxyz"

def findChar(z):
    z = z.lower() # zamiana znaku na male litery 
    for i, k in enumerate(alfabet): # przejscie po kazdym znaku ze slowika
        if z == k: #jezeli szukany znak to ten ktory aktualnie jest w pentli
            return i # zwroc index
    return -1 # jezeli szykany znak nie istnieje w slowniku to zwroc -1

def cezar(wsad, k):
    indx = -1
    out = ""
    for i, c in enumerate(wsad):
        pozycja = findChar(c) # znajdz index szukanego znaku w alfabecie
        nowyIndex = pozycja+k # nowy index to pozycja powiekszona o przesuniecie jakiego uzywamy
        indx = (nowyIndex)%26 # alfabet ma 26 znakow
        out+=alfabet[indx]
    return out

wsad="abcDefxyz"
wynikZCezara = cezar(wsad, 27)
print(f"wynik z cezara: {wynikZCezara}")