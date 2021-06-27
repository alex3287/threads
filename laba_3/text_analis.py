from threading import *
from time import time, sleep
from heapq import nlargest, nsmallest


class ThreadWithReturn(Thread):
    '''класс для для возрата данных из потока'''
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self._return = None

    def run(self):
        target = getattr(self, '_target')
        if not target is None:
            self._return = target(
                *getattr(self, '_args'),
                **getattr(self, '_kwargs') )

    def join(self, *args, **kwargs):
        super().join(*args, **kwargs)
        return self._return


def read_file(name):
    '''функция для чтения файлов'''
    R = dict()
    # TODO использую для тестов задержку по времени
    # sleep(2)
    for line in open(name):
        for letter in line:
            R.setdefault(letter, 0)
            R[letter] += 1
    return R


def merge_two_dict(A, B):
    '''слияние двух словарей'''
    R = A.copy()
    for key in B:
        if key in A:
            R[key] += B[key]
        else:
            R[key] = B[key]
    return R


def work_thread():
    '''функция для работы с потоками'''
    t1 = ThreadWithReturn(target=read_file, args=('first.txt',))
    t2 = ThreadWithReturn(target=read_file, args=('second.txt',))
    t1.start()
    t2.start()
    thread_t1 = t1.join()
    thread_t2 = t2.join()
    full_dict = merge_two_dict(thread_t1, thread_t2)
    maxi_5_letter = nlargest(5, full_dict, key=lambda x: full_dict[x])
    mini_3_letter = nsmallest(3, full_dict, key=lambda x: full_dict[x])
    print(thread_t1)
    print(thread_t2)
    print(full_dict)
    print(maxi_5_letter)
    print(mini_3_letter)



start = time()

work_thread()
finish = time()
print(finish-start)