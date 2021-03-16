# Fluent Python

My notes when reading Luciano Ramalho's Fluent Python.

## The Python Data Model

By implementing special methods (A.K.A. magic methods, like `__len__`, `__getitem__`, `__repr__` etc.. Often pronounced *dunder xx*), your objects can utilize built-in functions and syntax like `len()`, `[]`, `for ... in ...` and thus be considered Pythonic.

Understanding the Pythonic `len(xx)` over `xx.len()`: Think of these functions as unary operators.

## An Array of Sequences

- List Comprehension vs Generator Expression

  - List Comprehension: `list_a = [i + j for i in ... for j in ...]`

  This is a cartesian products example. `for i in ...` part is the outer loop.

  - Generator Expression: `xx(i + j for i in ... for j in ...)`

  The syntactic difference is `()` vs `[]`. But under the hood it saves space by yielding item one by one so a full list is never constructed. Also it can be used to build many other containers.

- Tuples

  - Tuples (Iterable) Unpacking

    - Use case: parallel assignment (can be nested), swap, `%` string formatting `print('%s %s' % tup)`, passing function parameter `f(*tup)`.

    - Works for any iterable as long as the iterable yields exactly one item per variable in the receiving end. The only exception is using `*` dicussed below.

    - `a, *b, c = range(5)` and `b` is `[1, 2, 3]`. Only one `*` prefix variable is allowed.

  - Named Tuples `collections.namedtuple`
    - Construction: Passing construct parameters by name or position. `NamedTup._make(iterable)`. `NamedTup(*iterable)`.
    - Accessing field by name or position.
    - `._asdict()` return a `collections.OrderedDict`

  - Methods and attributes as an "immutable list": No appending/poping/inserting nor any inplace ops.

- Slicing

  - `[:3]` exclude the last item.
  - Slice object.
    ```
    s = slice(begin, end, stride)
    line[s]
    ```
  - Under the hood:
    ```
    # v[a]
    v.__getitem__(a)
    # v[a, b]. Multidimensional. Used in Numpy.
    v.__getitem__((a, b))
    ```
  - Ellipsis object: function parameters `f(a, ..., z)` and slice `a[i:...]`. If `a` is four dimentional, this is a shortcut for `a[i, :, :, :]`. It is mostly used in Numpy.

  - Assignment using slices. Some interesting example from the book:
    ```
    >>> l = list(range(10))
    >>> l
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    >>> l[2:5] = [20, 30]
    >>> l
    [0, 1, 20, 30, 5, 6, 7, 8, 9]
    >>> del l[5:7]
    >>> l
    [0, 1, 20, 30, 5, 8, 9]
    >>> l[3::2] = [11, 22]
    >>> l
    [0, 1, 20, 11, 5, 22, 9]
    >>> l[2:5] = 100  
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
    TypeError: can only assign an iterable
    >>> l[2:5] = [100]
    >>> l
    [0, 1, 100, 22, 9]
    ```

- `+` and `*` and augmented assignment on sequences

  - `my_list = [[]] * 3` will result in a list with three references to the same inner list. List comprehension avoids this problem. `[[] for i in range(3)]`.
  - `+=` and `*=` will first try to use `__iadd__` and fall back to `__add__` and create a new object.

- `list.sort` and `sorted`
  - `list.sort` sorts inplace and returns `None`.
  - `sorted` library function accepts any iterable object.
  - Both accept two parameters: `reverse` bool and `key` for the name of a function that produces sorting keys.

## Misc

- [Online Python Tutor](http://www.pythontutor.com/)