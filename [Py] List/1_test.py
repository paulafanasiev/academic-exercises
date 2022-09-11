from w1 import List

def test_push_back():
    """Test for the push_back method of w1.List class"""
    lst = List()
    lst.push_back(1)
    assert lst.at(0) == 1
    lst.push_back(2)
    assert lst.at(1) == 2
    lst.push_back(5)
    assert lst.at(2) == 5
    assert lst.get_size() == 3

def test_push_front():
    """Test for the push_front method of w1.List class"""
    lst = List()
    lst.push_front(1)
    assert lst.at(0) == 1
    lst.push_front(2)
    assert lst.at(0) == 2
    lst.push_front(5)
    assert lst.at(0) == 5
    assert lst.get_size() == 3

def test_pop_back():
    """Test for the pop_back method of w1.List class"""
    lst = List()
    lst.push_back(1)
    lst.push_back(2)
    lst.push_back(5)
    lst.pop_back()
    assert lst.at(lst.get_size()-1) == 2
    lst.pop_back()
    assert lst.at(lst.get_size()-1) == 1
    lst.pop_back()
    assert lst.get_size() == 0
    try:
        lst.pop_back()
    except Exception as e:
        assert e.args[0] == 'list is empty'

def test_pop_front():
    """Test for the pop_front method of w1.List class"""
    lst = List()
    lst.push_back(1)
    lst.push_back(2)
    lst.push_back(5)
    lst.pop_front()
    assert lst.at(0) == 2
    lst.pop_front()
    assert lst.at(0) == 5
    lst.pop_front()
    assert lst.get_size() == 0
    try:
        lst.pop_front()
    except Exception as e:
        assert e.args[0] == 'list is empty'

def test_insert():
    """Test for the insert method of w1.List class"""
    lst = List()
    lst.insert(1,0)
    lst.insert(2,0)
    lst.insert(3,1)
    lst.insert(5,1)
    lst.insert(10,3)
    expect = [2,5,3,10,1]
    for i in range(lst.get_size()):
        assert lst.at(i) == expect[i]
    try:
        lst.insert(12,100)
    except Exception as e:
        assert e.args[0] == 'incorrect index'

def test_at():
    """Test for the get data from the list element by its number in the list method of w1.List class"""
    lst = List()
    lst.insert(1,0)
    lst.insert(2,0)
    assert lst.at(0) == 2
    assert lst.at(1) == 1
    try:
        lst.at(-1)
    except Exception as e:
        assert e.args[0] == 'incorrect index'

def test_remove():
    """Test for the delete list element by its number in the list method of w1.List class"""
    lst = List()
    lst.insert(1,0)
    lst.insert(2,0)
    lst.insert(3,1)
    lst.insert(5,1)
    lst.insert(10,3)
    lst.remove(2)
    expect = [2,5,10,1]
    for i in range(lst.get_size()):
        assert lst.at(i) == expect[i]
    lst.remove(3)
    lst.insert(60,2)
    expect = [2,5,60,10]
    for i in range(lst.get_size()):
        assert lst.at(i) == expect[i]
    try:
        lst.remove(100)
    except Exception as e:
        assert e.args[0] == 'incorrect index'

def test_get_size():
    """Test for the get_size method of w1.List class"""
    lst = List()
    assert lst.get_size() == 0
    lst.insert(1,0)
    assert lst.get_size() == 1
    lst.push_back(12)
    assert lst.get_size() == 2
    lst.push_front(100)
    assert lst.get_size() == 3
    lst.pop_back()
    assert lst.get_size() == 2
    lst.pop_front()
    assert lst.get_size() == 1
    lst.remove(0)
    assert lst.get_size() == 0
    lst.insert(13,0)
    assert lst.get_size() == 1
    assert lst.at(0) == 13

def test_clear():
    """Test for the clear list method of w1.List class"""
    lst = List()
    lst.insert(1,0)
    lst.insert(2,0)
    lst.insert(3,1)
    lst.insert(5,1)
    lst.insert(10,3)
    assert lst.get_size() == 5
    lst.clear()
    assert lst.get_size() == 0
    try:
        lst.at(0)
    except Exception as e:
        assert e.args[0] == 'incorrect index'

def test_set():
    """Test for the Change information in the node from desired place of the list method of w1.List class"""
    lst = List()
    lst.insert(1,0)
    lst.insert(2,0)
    lst.insert(3,1)
    lst.insert(5,1)
    lst.insert(10,3)
    lst.set(1,100)
    assert lst.at(1) == 100
    lst.set(0,200)
    assert lst.at(0) == 200
    try:
        lst.set(15,13)
    except Exception as e:
        assert e.args[0] == 'incorrect index'

def test_isEmpty():
    """Test for the isEmpty method of w1.List class"""
    lst = List()
    assert lst.isEmpty() == True
    lst.insert(1,0)
    lst.insert(2,0)
    lst.insert(3,1)
    lst.insert(5,1)
    lst.insert(10,3)
    assert lst.get_size() == 5
    assert lst.isEmpty() == False
    lst.clear()
    assert lst.isEmpty() == True

def test_out():
    """Test for the computation the string representation of current list of w1.List class"""
    lst = List()
    lst.insert(1,0)
    lst.insert(2,0)
    lst.insert(3,1)
    lst.insert(5,1)
    lst.insert(10,3)
    expect = [2,5,3,10,1]
    r = ""
    for i in expect[:-1]:
        r += str(i)
        r += " "
    r += str(expect[-1])
    assert r == str(lst)

def test_contains():
    """Test for the check if list contains other list method of w1.List class"""
    lst1 = List()
    lst1.insert(1,0)
    lst1.insert(2,0)
    lst1.insert(3,1)
    lst1.insert(5,1)
    lst1.insert(10,3)
    lst2 = List()
    lst2.push_back(3)
    lst2.push_back(2)
    assert lst1.contains(lst2) == True
    lst2.push_front(15)
    assert lst1.contains(lst2) == False
    lst1.insert(15,1)
    assert lst1.contains(lst2) == True