# Fluent Python

My notes when reading Luciano Ramalho's Fluent Python.

## The Python Data Model

By implementing special methods (A.K.A. magic methods, like `__len__`, `__getitem__`, `__repr__` etc.. Often pronounced *dunder xx*), your objects can utilize built-in functions and syntax like `len()`, `[]`, `for ... in ...` and thus be considered Pythonic.

Understanding the Pythonic `len(xx)` over `xx.len()`: Think of these functions as unary operators.