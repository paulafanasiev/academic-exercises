import math


class ExpressionValidatingException(Exception):
    pass


class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)


def input_to_token(input_form):
    """Decompose expression string in list 

    Args:
        input_form: String with expression from user input (infix notation)
    Returns:
        list with decomposed expressions

    """
    tokenlist = []
    allowedfunc = ["cos", "sin", "tg", "ctg", "ln", "log", "sqrt", "abs", "pi"]
    num = ''
    exp = ''
    for token in input_form:
        if token in "0123456789.":
            num = num + token
        elif num != '':
            tokenlist.append(num)
            num = ''
        if token in "cossintgctglnlogsqrtabsp":
            exp += token
        elif exp != '':
            if exp in allowedfunc:
                tokenlist.append(exp)
            exp = ''
        if token in "+-*/()^e":
            tokenlist.append(token)
    if num != '':
        tokenlist.append(num)
    if exp != '':
        tokenlist.append(exp)
    return tokenlist


def check_input(token_list):
    """Checks correctness of the entered expression

    Args:
        token_list: List with expressions from user input (infix notation)

    Raises:
        ExpressionValidatingException: if input expression has errors 

    """
    count = 0
    for i in range(0, len(token_list)):
        if i > 0 and token_list[i][0] in "0123456789.pe" and token_list[i - 1][0] in "0123456789.pe)":
            raise ExpressionValidatingException(
                "There is no operation between numbers: " + token_list[i - 1] + " and " + token_list[
                    i] + " on expression positions " + str(i) + " and " + str(
                    i - 1) + " (one number or operation, or bracket = one position)")
        if token_list[i] in "+*/^" and token_list[i - 1][0] in "+*/^":
            raise ExpressionValidatingException(
                "There is no numbers between operations: " + token_list[i - 1] + " and " + token_list[
                    i] + " on expression positions " + str(i) + " and " + str(
                    i - 1) + " (one number or operation, or bracket = one position)")
        if token_list[i] in "cossintgctglnlogsqrtabs":
            if i == len(token_list) - 1 or token_list[i + 1] != "(":
                raise ExpressionValidatingException(
                    "There is no brackets for operation: " + token_list[i] + " on expression position " + str(
                        i) + " (one number or operation, or bracket = one position)")
            hasvalue = False
            for j in range(i + 1, len(token_list)):
                if token_list[j] == ')':
                    break
                elif token_list[j][0] in "0123456789.pe":
                    hasvalue = True
                    break
            if not hasvalue:
                raise ExpressionValidatingException(
                    "There is no value for operation: " + token_list[i] + " on expression position " + str(
                        i) + " (one number or operation, or bracket = one position)")
        if token_list[i] == '(':
            count += 1
        elif token_list[i] == ')':
            count -= 1
    if count != 0:
        raise ExpressionValidatingException("Number of ( and ) are not equal!")


def backwards(token_list):
    """Rewrites expression list in reverse order

    Args:
        token_list: List with expressions
    Returns:
        list with expressions written in reverse order

    """
    res = []
    for i in range(len(token_list) - 1, -1, -1):
        if token_list[i] == '(':
            res.append(')')
        elif token_list[i] == ')':
            res.append('(')
        else:
            res.append(token_list[i])
    return res


def infix_to_prefix(input_form):
    """Converts infix notation to prefix, also validates input

    Args:
        input_form: String with expression from user input (infix notation)
    Returns:
        String with expression in prefix form

    """
    priority = {"abs": 5, "sqrt": 5, "log": 5, "ln": 5, "ctg": 5, "tg": 5, "sin": 5, "cos": 5, "~": 4, "^": 3, "*": 2,
                "/": 2, "+": 1, "-": 1, "(": 0}
    operation_stack = Stack()
    queue = []
    token_list = input_to_token(input_form)
    check_input(token_list)
    token_list = backwards(token_list)
    for i in range(len(token_list)):
        if token_list[i][0] in "0123456789.":
            queue.append(token_list[i])
        elif token_list[i] in ["pi", "e"]:
            if token_list[i] == "pi":
                queue.append(str(math.pi))
            else:
                queue.append(str(math.e))
        elif token_list[i] == '(':
            operation_stack.push(token_list[i])
        elif token_list[i] == ')':
            while not operation_stack.is_empty() and operation_stack.peek() != '(':
                queue.append(operation_stack.pop())
            operation_stack.pop()
        else:
            if token_list[i] == '-' and (
                    i == len(token_list)-1 or (i < len(token_list) and token_list[i + 1] in priority.keys())):
                token_list[i] = '~'
            while (not operation_stack.is_empty()) and operation_stack.peek() != '(' and (
                    priority[operation_stack.peek()] > priority[token_list[i]]):
                queue.append(operation_stack.pop())
            operation_stack.push(token_list[i])

    while not operation_stack.is_empty():
        queue.append(operation_stack.pop())
    queue = backwards(queue)
    return " ".join(queue)


def execute(op, first, second):
    """Execute operation for values.

    Args
        op: operation string
        first: first operand
        second: second operand
    Returns: 
        value of executing operation over first and second parameters

    """
    if op == "abs":
        return abs(second)
    elif op == "sqrt":
        if second < 0:
            raise ExpressionValidatingException("Sqrt of negative number sqrt(" + str(second) + ")")
        return second ** 0.5
    elif op == "log":
        if second < 0:
            raise ExpressionValidatingException("logarithm of negative number log(" + str(second) + ")")
        return math.log10(second)
    elif op == "ln":
        if second < 0:
            raise ExpressionValidatingException("logarithm of negative number ln(" + str(second) + ")")
        return math.log(second)
    elif op == "ctg":
        return math.cos(second) / math.sin(second)
    elif op == "tg":
        return math.tan(second)
    elif op == "sin":
        return math.sin(second)
    elif op == "cos":
        return math.cos(second)
    elif op == "~":
        return 0 - second
    elif op == "^":
        return first ** second
    elif op == "*":
        return first * second
    elif op == '/':
        if second == 0:
            raise ExpressionValidatingException("Division by zero in operation " + str(first) + " / " + str(second))
        return first / second
    elif op == "+":
        return first + second
    elif op == "-":
        return first - second


def calc_prefix(prefix_form_list):
    """Calculate value for expression in prefix form.

    Args
        prefix_form_list: Expression in prefix form decomposed into list
    Returns: 
        value for expression

    """
    operation_binar = ["^", "*", "/", "+", "-"]
    prefix_form_list = backwards(prefix_form_list)
    value_stack = Stack()
    counter = 0
    for i in range(len(prefix_form_list)):
        if prefix_form_list[i][0] in "0123456789.":
            value_stack.push(float(prefix_form_list[i]))
        else:
            counter += 1
            if not prefix_form_list[i] in operation_binar:
                last = value_stack.pop() if not value_stack.is_empty() else 0
                value_stack.push(execute(prefix_form_list[i], 0, last))
#                print(prefix_form_list[i] + "(" + str(last) + ")" + " = " + str(value_stack.peek()))
                continue
            first = value_stack.pop() if not value_stack.is_empty() else 0
            second = value_stack.pop() if not value_stack.is_empty() else 0
            value_stack.push(execute(prefix_form_list[i], first, second))
 #           print(str(first) + " " + prefix_form_list[i] + " " + str(second) + " = " + str(value_stack.peek()))
    return value_stack.pop()


#s=input()
#s= "- 10 - cos(2*pi) * -4"
#s="(1 - 2/3*pi) e / (1/4-5)"
#s = "abs(25--sqrt(4)+2)"
#s="15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))"
#s="15/(7-(1+1))*3-(2+(1+1))*15/(7-cos(200*3+pi+1*e*2))*3-(2+(1+1))*-5*(15/(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))"
# s="50/-50"
# InputToToken("10pi(3)")
# InputToToken("-cos(10pi)-sin(2e)*(4e)^2")
try:
    prefixform = infix_to_prefix(s)
    print(prefixform)
    print(str(calc_prefix(prefixform.split())))
except Exception as e:
    print("Error: " + str(e))