import calculator
import pytest


def test_calc_prefix_1():
    prefix_test = "- 2 ~ ~ 4".split()
    assert calculator.calc_prefix(prefix_test) == -2


def test_calc_prefix_2():
    prefix_test = "+ - 25 ~ sqrt 4 2".split()
    assert calculator.calc_prefix(prefix_test) == 29.0


def test_calc_prefix_3():
    prefix_test = "- - * / 15 - 7 + 1 1 3 * / * + 2 + 1 1 15 - 7 + 200 1 3 * + 2 + 1 1 - + - * / 15 - 7 + 1 1 3 + 2 + " \
                  "1 1 * / 15 - 7 + 1 1 3 + 2 + 1 1".split()
    assert calculator.calc_prefix(prefix_test) == -30.072164948453608


def test_infix_to_prefix_1():
    infix_form = "25--sqrt(4)+2"
    assert calculator.infix_to_prefix(infix_form) == "+ - 25 ~ sqrt 4 2"


def test_infix_to_prefix_2():
    infix_form = "(1 - 2/3*pi) * e / (1/4-5)"
    assert calculator.infix_to_prefix(infix_form) == "/ * - 1 * / 2 3 3.141592653589793 2.718281828459045 - / 1 4 5"


def test_infix_to_prefix_3():
    infix_form = "15/(7-(1+1))*3-(2+(1+1))*15/(7-cos(200*3+pi+1*e*2))*3-(2+(1+1))*-5*(15/(7-(1+1))*3-(2+(1+1))+15/(" \
                 "7-(1+1))*3-(2+(1+1))) "
    assert calculator.infix_to_prefix(
        infix_form) == "- - * / 15 - 7 + 1 1 3 * / * + 2 + 1 1 15 - 7 cos + + * 200 3 3.141592653589793 * * 1 " \
                       "2.718281828459045 2 3 * * + 2 + 1 1 ~ 5 - + - * / 15 - 7 + 1 1 3 + 2 + 1 1 * / 15 - 7 + 1 1 3" \
                       " + 2 + 1 1"


def test_infix_to_prefix_negative_1():
    infix_form = "(1 - 2/3*pi)e / (1/4-5)"
    with pytest.raises(calculator.ExpressionValidatingException):
        calculator.infix_to_prefix(infix_form)


def test_infix_to_prefix_negative_2():
    infix_form = "(1 - 2/3*pi)*e / (1pi * 4-5)"
    with pytest.raises(calculator.ExpressionValidatingException):
        calculator.infix_to_prefix(infix_form)


def test_infix_to_prefix_negative_3():
    infix_form = "(1 - 2/3*pi)*e / 1pi * 4-5)"
    with pytest.raises(calculator.ExpressionValidatingException):
        calculator.infix_to_prefix(infix_form)


def test_infix_to_prefix_negative_4():
    infix_form = "(1 - 2/3*pi)*e / (1 * cos() * 4-5)"
    with pytest.raises(calculator.ExpressionValidatingException):
        calculator.infix_to_prefix(infix_form)
