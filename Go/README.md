# Go

## Basics

A few things I feel interesting when doing [a tour of go](https://tour.golang.org/):

- for loop: `for` in Go is the for and while in other languages:

  ```Go
  for {}

  for i, v := range slice {}
  for i, _ := range slice {}
  for i := range slice {}
  ```

- Switch with no condition: a clean way to write long if-then-else chains. It stops at the first case that evaluates to `true`:

    ```Go
    t := time.Now()
    switch {
    case t.Hour() < 12:
        fmt.Println("Good morning!")
    case t.Hour() < 17:
        fmt.Println("Good afternoon.")
    default:
        fmt.Println("Good evening.")
    }
    ```

- Defer statement: 

  - For a function, its arguments are evaluated immediately, but the function call is not executed until the surrounding function returns.
  - Deferred statements are pushed onto a stack.

- No pointer arithmetic. To access a field from a struct pointer, instead of `(*p).x` we can write `p.x`

- Slices are like **references** to arrays. So the copies of a slice variable refer to the same array!

  - One interesting fact when using slice indexes is that you may drop the values in both sides of the slice, but you may only extend it in the right, till the end of the original array. Another way of seeing this is that when you drop the values in the left, you are shrinking the capacity of the slice.
  - Using `append` is another story. If the backing array of the slice is too small to fit all the given values, a bigger array will be allocated. The returned slice will point to the newly allocated array.
  - `make` can be used to create new slices

- A map variable declared is a `nil` map. Cannot be used. It will only be available after `make`

  - Interesting way to check if a key is present in a map: `elem, ok := m[key]`. `ok` is a bool

- Method: You can only declare a method with a receiver whose type is defined in the same package as the method.

  - Methods with pointer receivers can modify the value to which the receiver points. With value receiver the method operates on a copy of the original value.
  - Functions with a pointer argument must take a pointer. Methods with pointer receivers take either a value or a pointer as the receiver when they are called.