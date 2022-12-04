T=[33,21,23,27,27,28,2,13,24,32]
len=1
maxlen=1
idx=0
N=10

for i in range(1, N):
    if T[i]>=T[i-1]:
        len+=1
        if len>maxlen:
            maxlen=len
            idx=i
    else:
        len=1
print("Najdluzszy caig niemalejacy: ")
print(f"Ilosc el: {maxlen}")
print(f"Pierwszy element: {T[idx-maxlen+1]}[{idx-maxlen+1}]")  


# 7: i => idx; N => max = 10; range (1, N) => [1, 2, 3, 4, 5, 6, 7 ,8, 9]
