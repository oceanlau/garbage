# C++ Fundamental

## Build

```
g++ -std=c++0x your_file.cpp -o your_program
```
## Initialization

- Default initialized: Built-in type defined outside function body are default initialized to 0. Inside are undefined (may be some weird value).

## Reference VS Pointer

- Use reference when you can, use pointer when you have to. [Ref](https://www.geeksforgeeks.org/pointers-vs-references-cpp/).
- References are in some sense all const. You have to bind to something and cannot change the binding. So there is ref to const but no const ref. (The real reason is reference is not an object, unlike pointer)
- Function return ref. [1](https://stackoverflow.com/questions/10371094/returning-a-null-reference-in-c), [2](https://stackoverflow.com/questions/752658/is-the-practice-of-returning-a-c-reference-variable-evil)

## const

- Pointer
  - Top-level const: pointer itself is a const
  - Low-level const: the object pointer points to is a const
- `constexpr`: Constant expression is an experssion evaluated at compile time. Literal types are naturally constant expressions. Function initializers can be asked to be evaluated at compiling time by explicitly using `constexpr` both on the function and const object declaration. If the function needs arguments, the arguments must also be constant expressions. Also these two are different:
- [Ref](https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const)
- Function and const: [1](https://stackoverflow.com/questions/751681/meaning-of-const-last-in-a-function-declaration-of-a-class), [2](https://stackoverflow.com/questions/8716330/purpose-of-returning-by-const-value), [3](https://stackoverflow.com/questions/6299967/what-are-the-use-cases-for-having-a-function-return-by-const-value-for-non-built)

```C++
const int *p = nullptr; // p is a pointer to const
constexpr int *q = nullptr // q is a const pointer (int * const q)
```

## unique_ptr

- Init vector of `unique_ptr`: [Ref](https://stackoverflow.com/questions/33953115/how-to-resize-a-vector-of-vector-of-unique-ptr), [Ref](https://stackoverflow.com/questions/9618268/initializing-container-of-unique-ptrs-from-initializer-list-fails-with-gcc-4-7)

## Cast

- [Ref](https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used)

## auto and decltype

- `auto` ignores top-level const. When deduced from a reference, will use the type the reference refer to.
- `decltype` keeps top-level const and reference. So be careful in the following cases:

```C++
int i = 1;
int &r = i;
int *p = &i;
decltype(r + 0) b; // ok: expression yields int
decltype(*p) c; // error: *p yields int&! It is a reference and must be initialized
decltype((i)) d; // error: (i) also yields a reference!
```

## Iterator

- [Type](https://www.geeksforgeeks.org/input-iterators-in-cpp/?ref=lbp): random access (vector, deque), bidirectional (list, map, multimap, set, multiset), forward, input, output.
- [ops](https://www.geeksforgeeks.org/iterators-c-stl/?ref=rp). [Distance](https://en.cppreference.com/w/cpp/iterator/distance).
- [constness](http://www.cplusplus.com/reference/list/list/begin/#:~:text=An%20iterator%20to%20the%20beginning,a%20const%20element%2C%20respectively).)

## Class

- [With or without parentheses](https://stackoverflow.com/questions/620137/do-the-parentheses-after-the-type-name-make-a-difference-with-new)

## Template

- `typename` and `class` keywords: [Almost](https://stackoverflow.com/questions/2023977/difference-of-keywords-typename-and-class-in-templates) no difference.

# Multi-threading

- Problems in multi-threading:
  - Race conditions: process ends with undesired output, resulting from unexpected sequence of execution in threads.
  - Deadlocks: Threads wait for each other.
  - Resource starvation: A thread is always waiting.
- Tools:
  - Lock
  - Semaphore
  - Condition variable

