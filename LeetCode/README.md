# Cracking Coding Interview

## Time Complexity Analysis

- Common backtrack: Think of it as listing **the combinations of subsets**. So time complexity is $$O(2^n)$$. **The depth of recursion** is $$n$$. So space complexity is $$O(n)$$

## Similar Problems

### Tree

- Iterative DFS on a tree

  Binary Tree

  N-ary Tree

- Serialize and Deserialize Tree:

  - [449. Serialize and Deserialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst/): BST has more information than regular binary tree. So we don't need to encode any "NULL" in the serialized string. DFS (Postorder and preorder) and BFS would work. Inorder would not because you can't recover the root position. Also remember to include extra inherited max and min value during recursion/iteration.

    - [1008. Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/): This one asks preorder, but actually any type of traversal except inorder, could be used to rebuild BST.

    - [109. Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/): This one asks about inorder. It adds a height constraint to narrow down the number of answers. The tricky thing about this one is how to reduce the space complexity from $$O(n)$$ (turning the whole linked list into array in order to locate element quicker) to $$O(1)$$ (if not considering the $$O(\log n)$$ recursion stack). You need to use a "global" (or pass by ref) ListNode pointer that moves along with the call stack and simulate the inorder traversal.

  - [297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/): DFS or BFS with two "NULL"s encoded for a leaf node.

  - [428. Serialize and Deserialize N-ary Tree](https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/): Only adding extra "NULL"s wouldn't work. Need more data to express the number of children. There are many ways to do that. For example adding the number of children after each node, using parentheses to express sibling relationship, or, what I prefer, using a fence between children groups, which works almost like "NULL"s.

- Trees you don't see:

  - Word Ladders: [127. Word Ladder](https://leetcode.com/problems/word-ladder/), [126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/)

- Others:
  - $$O(1)$$ space BFS: [116. Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)
  - Reverse thinking DFS traversal (pass range to parent): [333. Largest BST Subtree](https://leetcode.com/problems/largest-bst-subtree/)

### Binary Search

- Basic practice:
  - [875. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)

- Bin search on multiple array or high dimensional data:

  - [4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/): :white_check_mark: [My answer](https://github.com/oceanlau/writings/blob/master/LeetCode/0004_Median_of_Two_Sorted_Arrays.cpp). Get rid of a lesser half at a time. Reset target nth point.

- Bin search you don't see:

  - [410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/). Use bin search to find the answers, use greedy accumulator to prove the answer.

### Sort

- MergeSort and $$O(1)$$ space MergeSort: [148. Sort List](https://leetcode.com/problems/sort-list/)

### Subsets

- [416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/). DP. `dp[i][j]` can `nums[0...i]` sum to `j`.
- [410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/). DP. `dp[i][j]` for minimum largest subarray sum when splitting `nums[0...i]` into `j` parts.
- [548. Split Array with Equal Sum](https://leetcode.com/problems/split-array-with-equal-sum/). Not DP. Straight forward for each middle point, check if left two quarters and right two quarters can get same sum.

### Monotonic Order Data Structure

- [239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/). Deque.

### $$O(n^2)$$ Dynamic Programming

- [435. Non-overlapping Intervals](). Look back. Actually greedy brings it down to $$O(n)$$.
- [403. Frog Jump](https://leetcode.com/problems/frog-jump/). Look forward.
- [410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/). DP. `dp[i][j]` for minimum largest subarray sum when splitting `nums[0...i]` into `j` parts. $$O(mn^2)$$

