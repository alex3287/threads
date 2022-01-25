with open('input.txt') as fin:
    s = fin.readline()
    print(s)
    count_max = 0
    count = 1
    for i in range(len(s)-1):
        if s[i] + s[i+1] != 'PP':
            count += 1
        else:
            count = 1
        if count_max < count:
            count_max = count
    print(count_max, count)