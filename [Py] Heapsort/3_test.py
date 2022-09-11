from w3 import Heap,Node

def test_contains():
    """Test for the find element by its data key method realisation in the w3.Heap class"""
    h = Heap()
    h.insert(Node(12,'a'))
    h.insert(Node(13,'b'))
    h.insert(Node(14,'c'))
    h.insert(Node(1,'k'))
    h.insert(Node(8,'j'))
    h.insert(Node(10,'l'))
    h.insert(Node(18,'m'))
    assert h.contains(1) == True
    assert h.contains(10) == True
    assert h.contains(3) == False
    
def test_insert():
    """Test for the add new element to heap method realisation in the w3.Heap class"""
    h = Heap()
    h.insert(Node(12,'a'))
    h.insert(Node(13,'b'))
    h.insert(Node(14,'c'))
    h.insert(Node(1,'k'))
    h.insert(Node(8,'j'))
    h.insert(Node(10,'l'))
    h.insert(Node(18,'m'))
    expect = [12,13,14,1,8,10,18]
    for i in expect:
        assert h.contains(i) == True

def test_remove():
    """Test for the remove element from the heap by its key value method realisation in the w3.Heap class"""
    h = Heap()
    h.insert(Node(12,'a'))
    h.insert(Node(13,'b'))
    h.insert(Node(14,'c'))
    h.insert(Node(1,'k'))
    assert h.contains(14) == True
    h.remove(14)
    assert h.contains(14) == False
    assert h.contains(13) == True
    h.remove(13)
    assert h.contains(13) == False

def test_create_dft_iterator():
    """Test for the create iterator to traverse the heap in depth class object method realisation in the w3.Heap
    class """
    h = Heap()
    h.insert(Node(12,'a'))
    h.insert(Node(13,'b'))
    h.insert(Node(14,'c'))
    h.insert(Node(1,'k'))
    h.insert(Node(8,'j'))
    h.insert(Node(10,'l'))
    h.insert(Node(18,'m'))
    h.insert(Node(2,'s'))
    h.insert(Node(-1,'g'))
    expect = [1,2,-1,12,8,18,10,14,13]
    iter = h.create_dft_iterator()
    i = 0
    while(iter.hasNext()):
        assert expect[i] == iter.next()[0]
        i += 1
    h.remove(-1)
    expect = [1,2,12,8,18,10,14,13]
    iter = h.create_dft_iterator()
    i = 0
    while(iter.hasNext()):
        assert expect[i] == iter.next()[0]
        i += 1
    
def test_create_bft_iterator():
    """Test for the create iterator to traverse the heap in broadwise class object method realisation in the w3.Heap
    class """
    h = Heap()
    h.insert(Node(12,'a'))
    h.insert(Node(13,'b'))
    h.insert(Node(14,'c'))
    h.insert(Node(1,'k'))
    h.insert(Node(8,'j'))
    h.insert(Node(10,'l'))
    h.insert(Node(18,'m'))
    h.insert(Node(2,'s'))
    h.insert(Node(-1,'g'))
    expect = [18,12,14,2,8,10,13,1,-1]
    iter = h.create_bft_iterator()
    i = 0
    while(iter.hasNext()):
        assert expect[i] == iter.next()[0]
        i += 1
    h.remove(10)
    expect = [18,12,14,2,8,-1,13,1]
    iter = h.create_bft_iterator()
    i = 0
    while(iter.hasNext()):
        assert expect[i] == iter.next()[0]
        i += 1