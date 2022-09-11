from w2 import BinarySearch,QuickSort,BubbleSort,BogoSort,CountingSort

def test_BinarySearch():
    """Test for the Binary Search algorithm realisation"""
    arr = [1,2,3,4,5,6,7,8,9,10]
    index = BinarySearch(arr,0,len(arr)-1,2)
    assert index == 1
    index = BinarySearch(arr,0,len(arr)-1,11)
    assert index == -1
    index = BinarySearch(arr,0,len(arr)-1,8)
    assert index == 7
    
def test_QuickSort():
    """Test for the Quick sort algorithm realisation"""
    arr = [5,4,3,2,1]
    QuickSort(0,len(arr)-1,arr)
    expect = [1,2,3,4,5]
    for i in range(len(arr)):
        assert arr[i] == expect[i]
    arr = [2,2,2,1,1,1]
    QuickSort(0,len(arr)-1,arr)
    expect = [1,1,1,2,2,2]
    for i in range(len(arr)):
        assert arr[i] == expect[i]
    arr = [2,4,1,6,5,2,2,1]
    QuickSort(0,len(arr)-1,arr)
    expect = [1,1,2,2,2,4,5,6]
    for i in range(len(arr)):
        assert arr[i] == expect[i]    

def test_BubbleSort():
    """Test for the Bubble sort algorithm realisation"""
    arr = [5,4,3,2,1]
    BubbleSort(arr)
    expect = [1,2,3,4,5]
    for i in range(len(arr)):
        assert arr[i] == expect[i]
    arr = [2,2,2,1,1,1]
    BubbleSort(arr)
    expect = [1,1,1,2,2,2]
    for i in range(len(arr)):
        assert arr[i] == expect[i]
    arr = [2,4,1,6,5,2,2,1]
    BubbleSort(arr)
    expect = [1,1,2,2,2,4,5,6]
    for i in range(len(arr)):
        assert arr[i] == expect[i]

def test_BogoSort():
    """Test for the Permutation sort algorithm realisation"""
    arr = [5,4,3,2,1]
    BogoSort(arr)
    expect = [1,2,3,4,5]
    for i in range(len(arr)):
        assert arr[i] == expect[i]
    arr = [2,2,2,1,1,1]
    BogoSort(arr)
    expect = [1,1,1,2,2,2]
    for i in range(len(arr)):
        assert arr[i] == expect[i]
    arr = [2,4,1,6,5,2,2,1]
    BogoSort(arr)
    expect = [1,1,2,2,2,4,5,6]
    for i in range(len(arr)):
        assert arr[i] == expect[i]

def test_CountingSort():
    """Test for the Counting sort algorithm realisation"""
    arr = ['B','C','A','A','E']
    arr = CountingSort(arr)
    expect = ['A','A','B','C','E']
    for i in range(len(arr)):
        assert arr[i] == expect[i]
    arr = ['B','B','B','A','A','A']
    arr = CountingSort(arr)
    expect = ['A','A','A','B','B','B']
    for i in range(len(arr)):
        assert arr[i] == expect[i]
    arr = ['b','c','d','e','a','a','d']
    arr = CountingSort(arr)
    expect = ['a','a','b','c','d','d','e']
    for i in range(len(arr)):
        assert arr[i] == expect[i]    