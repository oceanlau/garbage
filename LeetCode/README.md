# Cracking Coding Interview

## Time Complexity Analysis

- Common backtrack: Think of it as listing **the combinations of subsets**. So time complexity is $$O(2^n)$$. $$The depth of recursion$$ is $$n$$. So space complexity is $$O(n)$$

## Similar Problems

### Tree

- Iterative DFS on a tree

  Binary Tree

  N-ary Tree

- Serialize and Deserialize Tree:

  - [449. Serialize and Deserialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst/): BST has more information than regular binary tree. So we don't need to encode any "NULL" in the serialized string. DFS and BFS both work. Just remember to include extra inherited max and min value during recursion/iteration.

    - [1008. Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/): This one asks preorder, but actually any type of traversal, even postorder, could be used to rebuild BST.

  - [297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/): DFS or BFS with two "NULL"s encoded for a leaf node.

  - [428. Serialize and Deserialize N-ary Tree](https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/): Only adding extra "NULL"s wouldn't work. Need more data to express the number of children. There are many ways to do that. For example adding the number of children after each node, using parentheses to express sibling relationship, or, what I prefer, using a fence between children groups, which works almost like "NULL"s.

### Binary Search

- Bin search on multiple array or high dimensional data:

  - [4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/): [My answer](https://github.com/oceanlau/writings/blob/master/LeetCode/0004_Median_of_Two_Sorted_Arrays.cpp). Get rid of a lesser half at a time. Reset target nth point.