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