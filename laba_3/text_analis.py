# Частотный анализатор текстов. 2 “читающих” потока считывают данные из текста(-ов).
# Поток-интерфейс отвечает за взаимодействие с пользователем через командную строку.
# Пользователю доступны следующие команды: вывести на экран 5 самых распространённых
# на данный момент букв; вывести на экран вероятность появление буквы, введённой
# пользователем; выдать три самые редкие буквы. Внутренний поток обрабатывает запросы
# пользователя в соответствии с актуальной на данный момент информацией,
# собранной “читающими” потоками.

from threading import *
from time import time, sleep


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


def maxi_5_letters(D):
    pass


def work_thread():
    '''функция для работы с потоками'''
    t1 = ThreadWithReturn(target=read_file, args=('first.txt',))
    t2 = ThreadWithReturn(target=read_file, args=('second.txt',))
    t1.start()
    t2.start()
    thread_t1 = t1.join()
    thread_t2 = t2.join()
    full_dict = merge_two_dict(thread_t1, thread_t2)
    maxi = maxi_5_letters(full_dict)
    print(thread_t1)
    print(thread_t2)
    print(full_dict)
    print(maxi)


# t1 = ThreadWithReturn(target=read_file, args=('24-s1.txt',))
# t2 = ThreadWithReturn(target=read_file, args=('24_2.txt',))

start = time()
# print(read_file('24-s1.txt'))
# print(read_file('24-s1.txt'))
# t1.start()
# t2.start()
# thread_t1 = t1.join()
# thread_t2 = t2.join()
# t1.join()
# t2.join()

# full_dict = merge_two_dict(thread_t1, thread_t2)
# print(thread_t1, '\n', t1.name)
# print(thread_t2, '\n', t2.name)
# print(full_dict)
work_thread()
finish = time()
print(finish-start)