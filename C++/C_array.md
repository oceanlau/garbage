## C array size

When I was doing a interview today, I found the a 2D array that passed into the function I needed to implement is not a `vector<vector<int>>` but an old-fashioned C array `int**`. Though the shape of the array was passed in by other parameters, I suddenly realized that I have never dealt with getting the size of C array from a pointer before. What if they did not do me the favor of passing the shape for me?

So after the interview, I googled about this and found it is actually an interesting topic. Here is what I found:

First to clarify, suppose we have the code below:


