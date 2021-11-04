VOWELS = 'aeiou'


def is_vow(inp):
    n = len(inp)
    for i in range(n):
        if chr(inp[i]) in VOWELS:
            inp[i] = chr(inp[i])
    return inp


A = [118,117,120,121,117,98,122,97,120,106,104,116,113,114,113,120,106]  # [118, "u",120,121,"u",98,122,"a",120,106,104,116,113,114,113,120,106 ]

print(is_vow(A))