def permutacja(A):
    k: int = 0
    B = []
    n = len(A)
    for i in range(0, n):
        B.append(0)

    for i in range(0, n):
        if (A[i] <= n):
            B[A[i] - 1] = B[A[i] - 1] + 1
        else:
            k+= 1

    for i in range(0, n):
        if (B[i] > 1):
            k += B[i] - 1
    
    return k

C = [1, 4, 2, 5, 4]; # pomysł pati
print(f"{permutacja([1, 3, 1])}")
print(f"{permutacja([ 1, 4, 2, 5])}")
print(f"{permutacja([ 2, 2, 2, 2, 2 ])}")
print(f"{permutacja([ 4, 2, 3, 1 ])}")
print(f"{permutacja([ 5, 4, 1, 5, 6, 8 ])}")
print(f"{permutacja([ 8, 4, 9, 6, 5, 7 ])}")
        
    


