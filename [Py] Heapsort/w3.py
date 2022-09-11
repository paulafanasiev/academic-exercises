#для обхода двоичной кучи в глубину
class DFSIterator:
    """Class to traverse the binary heap depth-first .

    Attributes:
        stack: list with result of in-depth traversal
        lst: list of heap elements
    """
    #инициализатор
    def __init__(self, lst):
        self.stack = []
        self.lst = lst
        self.push_left(0)
      
    #получить следующий элемент
    def next(self):
        """Method to acquire next element

        Returns:
            Node key and value in tuple data type
        """
        i = self.stack.pop()
        self.push_left(i * 2 + 2)
        return (self.lst[i].key,self.lst[i].value)

    #есть возможность получить след. элемент?
    def hasNext(self):
        """Method to find out is there next element

        Returns:
            Boolean value True if there is next element available or False if there isn't
        """
        return len(self.stack) > 0
        
    #обход в глубину
    def push_left(self,start):
        """Method for realisation of in-depth traversal

        Args:
            start: number of element in heap list from which traverse will be started
        """
        i = start
        while i < len(self.lst):
            self.stack.append(i)
            i = i * 2 + 1
            
#в ширину (просто получаем по элементу исходного списка)
class BFSIterator:
    """Class to traverse the binary heap in broadwise.

    Attributes:
        i: number of element in list of heap elements from which traverse will be continued
        lst: list of heap elements
    """
    #инициализатор
    def __init__(self, lst):
        self.i = -1
        self.lst = lst
      
    #получить следующий элемент
    def next(self):
        """Method to acquire next element

        Returns:
            Node key and value in tuple data type
        """
        self.i += 1
        return (self.lst[self.i].key,self.lst[self.i].value)

    #есть возможность получить след. элемент?
    def hasNext(self):
        """Method to find out is there next element

        Returns:
            Boolean value True if there is next element available or False if there isn't
        """
        return self.i + 1 < len(self.lst)

#узел кучи
class Node:
    def __init__(self,key,value):
        self.key = key
        self.value = value

#двоичная max куча
class Heap:
    """Class that realises max-heap data storage.

    Attributes:
        lst: list of elements
    """
    def __init__(self):
        self.lst = []
        
    #поиск элемента в дереве по ключу O(N)
    def contains(self,key):
        """Method to find element by its data key

        Args:
            key: data key to be searched
        Returns:
            Boolean value True if there is such element available or False if there isn't
        """
        for node in self.lst:
            if(node.key == key):
                return True
        return False
    
    #добавление элемента O(log(N))
    def insert(self,node):
        """Method to add new element to heap

        Args:
            node: new node to be inserted to the heap
        """
        self.lst.append(node)
        i = len(self.lst) - 1
        self.heapifyUp(i)
        
    #упорядочивание кучи сверху-вниз O(log(N))
    def heapifyDown(self,i):
        """Method to heap ordering from top to bottom

        Args:
            i: position of the current root
        """
        n = len(self.lst)
        while True:
            left = 2 * i + 1
            right = 2 * i + 2
            large = i
            if(left < n):
                if(self.lst[left].key > self.lst[large].key):
                    large = left
            if(right < n):
                if(self.lst[right].key > self.lst[large].key):
                    large = right
            if(large == i):
                break
            else:
                self.lst[i],self.lst[large] = self.lst[large],self.lst[i]
                i = large
                
    #упорядочивание кучи снизу-вверх O(log(N))
    def heapifyUp(self,i):
        """Method to heap ordering from bottom to top

        Args:
            i: position of the current root
        """
        parent = (i - 1) // 2
        while(i > 0 and self.lst[parent].key < self.lst[i].key):
            self.lst[i],self.lst[parent] = self.lst[parent],self.lst[i]
            i = parent
            parent = (i - 1) // 2
        
    #извлечение корня (максимума) O(log(N))
    def getRoot(self):
        """Method to acquire current maximum (root) of the heap

        Returns:
            node of the current root

        Raises:
            Exception:if heap is empty
        """
        #попытка извлечь из пустой кучи
        if(len(self.lst) == 0):
            raise Exception("heap is empty")
        res = self.lst[0]
        self.lst[0] = self.lst[len(self.lst) - 1]
        self.lst = self.lst[:-1] #удаляем последний элемент
        self.heapifyDown(0) #упорядочиваем сверху-вниз
        return res
        
    #удаление из кучи O(N)
    def remove(self,key):
        """Method to remove element from the heap by its key value

        Args:
            key: Data key of the element to be removed from the heap
        """
        for i in range(len(self.lst)):
            #нашли ключ
            if(self.lst[i].key == key):
                #меняем с корнем местами
                self.lst[0],self.lst[i] = self.lst[i],self.lst[0]
                self.lst[0] = self.lst[len(self.lst) - 1]
                self.lst.pop() #удаляем последний элемент
                #если удалили последний элемент
                if(i >= len(self.lst)):
                    return
                #поднимаем старый корень наверх
                self.heapifyUp(i)
                #теперь элемент, который переместился на его место
                self.heapifyUp(i)
                return
    
    #итератор для обхода кучи в глубину O(N)
    def create_dft_iterator(self):
        """Method to create iterator to traverse the heap in depth class object

        Returns:
            Object of the DFSIterator class initialized by current heap data list
        """
        return DFSIterator(self.lst)
    
    #итератор для обхода кучи в ширину O(N)
    def create_bft_iterator(self):
        """Method to create iterator to traverse the heap in broadwise class object

        Returns:
            Object of the BFSIterator class initialized by current heap data list
        """
        return BFSIterator(self.lst)
    
if __name__ == '__main__':
    arr = [Node(2,'a'),Node(3,'b'),Node(1,'c'),Node(4,'q'),Node(5,'s'),Node(6,'e')]
    hp = Heap()
    for i in arr:
        hp.insert(i)
    print('Куча в порядке обхода в ширину:')
    iter = hp.create_bft_iterator()
    while(iter.hasNext()):
        print(iter.next())
    print('Проверяем есть ли в куче элемент по ключу 5:',hp.contains(5))
    print('Удаляем из кучи элемент по ключу 4 и обходим кучу в ширину:')
    hp.remove(4)
    iter = hp.create_bft_iterator()
    while(iter.hasNext()):
        print(iter.next())
    print('\nВ глубину:')
    iter = hp.create_dft_iterator()
    while(iter.hasNext()):
        print(iter.next())