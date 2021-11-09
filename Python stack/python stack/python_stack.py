class EmptyDek(IndexError): pass

class FullDek(IndexError): pass

class Dek:
    def __init__(self, list_max_size: int):
        self._list = [None] * list_max_size
        self._list_max_size = list_max_size
        self._start = 0
        self._end = 0
        self._size = 0

    def push_back(self, value: int):
        if self._size == self._list_max_size:
            raise FullDek
        self._end = (self._end + 1) % self._list_max_size
        self._list[self._end] = value
        self._size+=1
            

    def push_front(self, value: int):
        if self._size == self._list_max_size:
            raise FullDek
        self._list[self._start] = value
        self._start = (self._start - 1) % self._list_max_size  
        self._size+=1

            

    def pop_back(self):
        if self._size == 0:
            raise EmptyDek
        result = self._list[self._end]
        self._end = (self._end - 1) % self._list_max_size
        self._size-=1
        return result

    def pop_front(self):
        if self._size == 0:
            raise EmptyDek
        self._start = (self._start + 1) % self._list_max_size
        result = self._list[self._start]
        self._size-=1
        return result

def main():
    runtime_steps = int(input())
    size = int(input())
    data = Dek(size)
    list_of_commands ={
        'push_front': data.push_front,
        'push_back': data.push_back,
        'pop_front': data.pop_front,
        'pop_back': data.pop_back,
    }
    for i in range(runtime_steps):
        operation, *value = input().split()
        if value:
            try:
                list_of_commands[operation](int(*value))
            except FullDek:
                print('error')
        else:              
            try:
                print(list_of_commands[operation]())
            except EmptyDek:
                print('error')

if __name__ == '__main__':
    main()
