import pytest

from src.calculator import Calculator, CalcError


@pytest.mark.parametrize("a, b, res",
                         [(7, 2, 9),
                          (3, 2, 5),
                          (-1, 2, 1)])
def test_soma(a, b, res):
    calculator = Calculator()
    res_calc = calculator.soma(a, b)
    assert res == res_calc


@pytest.mark.parametrize("a, b, res",
                         [("7", 2, 9),
                          (3, "2", 5),
                          (-1, "2", 1)])
def test_soma_type(a, b, res):
    calculator = Calculator()
    with pytest.raises(CalcError):
        res_calc = calculator.soma(a, b)


@pytest.mark.parametrize("a, b, res",
                         [(7, 2, 5),
                          (3, 2, 1),
                          (-1, 2, -3)])
def test_sub(a, b, res):
    calculator = Calculator()
    res_calc = calculator.sub(a, b)
    assert res == res_calc


@pytest.mark.parametrize("a, b, res",
                         [("7", 2, 5),
                          (3, "2", 1),
                          (-1, "2", -3)])
def test_sub(a, b, res):
    calculator = Calculator()
    with pytest.raises(CalcError):
        res_calc = calculator.sub(a, b)
