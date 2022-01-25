with open('input.txt') as fin:
    s = fin.readline()
    count_max = 0
    count = 0
    count_dot = 0
    for i in range(len(s)):
        if s[i] in 'AEIOUY':
            count = 0
            count_dot = 0
        else:
            count += 1
            if s[i] == '.':
                count_dot += 1
            if count > count_max and count_dot > 5:
                count_max = count
print(count_max)