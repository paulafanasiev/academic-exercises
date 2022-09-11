import random as rd
import time as tm
rd.seed()

#двоичный поиск O(log(N))
def BinarySearch(arr,l,r,x):
    """Binary search function.

    Args:
        arr: list with elements
        l: Number of the first element
        r: Number of the last element
        x: value which will be searched
    Returns:
        number of the array element if its found, otherwise returns value = -1
    """
    if r >= l:
        mid = l + (r - l) // 2 #середина
        if arr[mid] == x:
            return mid
        #поиск слева
        elif arr[mid] > x:
            return BinarySearch(arr, l, mid-1, x)
        else:
            #справа
            return BinarySearch(arr, mid + 1, r, x)
    else:
        return -1
    
#быстрая сортировка
def partition(start, end, array):
    """Helper function for quick sort: gets the pivot element.

    Args:
        start: Number of the first element
        end: Number of the last element
        array: list with elements
    Returns:
        number of the pivot element
    """
    pivot_index = start 
    pivot = array[pivot_index]
    while start < end:
        while start < len(array) and array[start] <= pivot:
            start += 1
        while array[end] > pivot:
            end -= 1
        if(start < end):
            array[start], array[end] = array[end], array[start]
    array[end], array[pivot_index] = array[pivot_index], array[end]
    return end
      
#основная функция быстрой сортировки O(N*log(N))
def QuickSort(start, end, array):
    """Quick sort function: sorts list from arguments

    Args:
        start: Number of the first element
        end: Number of the last element
        array: list with elements
    """
    if (start < end):
        #получаем ведущий элемент
        p = partition(start, end, array)
        #сортируем слева
        QuickSort(start, p - 1, array)
        #и справа
        QuickSort(p + 1, end, array)
        
#сортировка пузырьком O(N^2)
def BubbleSort(arr):
    """Bubble sort function: sorts list from arguments

    Args:
        arr: list with elements
    """
    for i in range(len(arr)):
        for j in range(len(arr)-1,i,-1):
            if(arr[j] < arr[j-1]):
                arr[j],arr[j-1] = arr[j-1],arr[j]
                
#глупая сортировка O(N * N!)
def BogoSort(arr):
    """Permutation sort function: sorts list from arguments

    Args:
        arr: list with elements
    """
    #проверка порядка
    def correct(arr):
        s = len(arr)-1
        while(s > 0):
            if(arr[s-1] > arr[s]):
                return 0
            s -= 1
        return 1
    #перемешивание
    def shuffle(arr):
        for i in range(len(arr)):
            j = rd.randint(0,len(arr)-1)
            arr[i],arr[j] = arr[j],arr[i]
            
    #основной цикл сортировки
    while(correct(arr) == 0):
        shuffle(arr)

#сортировка подсчетом для символов O(N + K)
def CountingSort(arr):
    """Counting sort algorithm function: sorts list from arguments

    Args:
        arr: list with elements
    """
    size = 255 #кол-во букв
    b = [0] * len(arr) #результат
    c = [0] * (size + 1)
    for i in range(len(arr)):
        c[ord(arr[i])] += 1
    for i in range(1,size,1):
        c[i] += c[i-1]
    for i in range(len(arr)-1,-1,-1):
        b[c[ord(arr[i])]-1] = arr[i]
        c[ord(arr[i])] -= 1
    return b

#замер времени для 2 и 4 сортировки
def test():
    """Function to get timing for QuickSort and BubbleSort algorithms functions: generates test data and gets timings
    for sorting functions

    Returns:
        list with average times for QuickSort and BubbleSort algorithms functions
    """
    res = [] #результаты
    for n in [10,100,1000,10000,100000]:
        avgtime2 = 0 #среднее время
        avgtime4 = 0
        for t in range(10):
            #генерируем случайно
            data = [rd.randint(-50,50) for i in range(n)]
            #замер для 2-й сортировки
            start = tm.time()
            QuickSort(0,len(data)-1,data)
            avgtime2 += tm.time() - start
            
            #4-я
            data = [rd.randint(-50,50) for i in range(n)]
            start = tm.time()
            BubbleSort(data)
            avgtime4 += tm.time() - start
        res.append([avgtime2/10.0,avgtime4/10.0])
    return res

#для теста
if __name__ == '__main__':
    #тест сортировки по времени
    '''
    res = test()
    print('Время сортировок в секундах:\n')
    i = 0
    n = [10,100,1000,10000,100000]
    print('{0:15}{1:14}{2}'.format('Размерность','QuickSort','BubbleSort'))
    for a,b in res:
        print("{0:9}{1:14.3f}{2:14.3f}".format(n[i],a,b))
        i += 1'''
    #тест сортировки обычный с вводом-выводом
    arr = input('Введите элементы массива через пробел: ')
    mas = []
    for i in arr.split(' '):
        mas.append(int(i))
    print('Поиск элемента 5 в массиве:',BinarySearch(mas,0,len(mas)-1,5))
    mas1 = mas.copy()
    QuickSort(0,len(mas1)-1,mas1)
    print('Быстрая сортировка:',mas1)
    mas1 = mas.copy()
    BubbleSort(mas1)
    print('Сортировка пузырьком:',mas1)
    mas1 = mas.copy()
    BogoSort(mas1)
    print('Глупая сортировка:',mas1)
    mas1 = []
    for i in mas:
        s = str(i)
        for j in s:
            mas1.append(j)
    print('Исходный массив символов:',mas1)
    print('Сортировка подсчетом:',CountingSort(mas1))