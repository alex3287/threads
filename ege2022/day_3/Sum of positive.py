#  При работе с массивом задаем два вопроса
#  1) нужно ли смотреть каждый элемент, если да, то мы работаем с циклом
#  2) нужно ли изменять элементы внутри данного массива, если да, то мы в цикле for используем range(len(A))

def positive_sum(arr):
    summ = 0
    for i in arr:
        if i > 0:
            summ += i
    return summ


def positive_sum2(arr):
    return sum([i for i in arr if i > 0])


A = [-1, 2, 3, 4, -5, 3]   # 9
print(positive_sum2(A))