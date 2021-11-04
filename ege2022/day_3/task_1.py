with open('input.txt') as fin:
    n = int(fin.readline())
    A = []
    for i in range(n):
        A.append(int(fin.readline()))

with open('input.txt') as fin:
    B = [int(i) for i in fin.readlines()]
    B = B[1:]

C = [int(i) for i in open('input.txt')]

print(A)
print(B)
print(C[1:])

print(sum(A)/n)