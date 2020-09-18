# Cracking Coding Interview

## Time Complexity Analysis

- Common backtrack: Think of it as listing **the combinations of subsets**. So time complexity is $$O(2^n)$$. **The depth of recursion** is $$n$$. So space complexity is $$O(n)$$

## Algorithms

### Tree

- Iterative DFS on a tree

  Binary Tree

  N-ary Tree: [582. Kill Process](https://leetcode.com/problems/kill-process/)

- Serialize and Deserialize Tree:

  - [449. Serialize and Deserialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst/): BST has more information than regular binary tree. So we don't need to encode any "NULL" in the serialized string. DFS (Postorder and preorder) and BFS would work. Inorder would not because you can't recover the root position. Also remember to include extra inherited max and min value during recursion/iteration.

    - [1008. Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/): This one asks preorder, but actually any type of traversal except inorder, could be used to rebuild BST.

    - [109. Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/): This one asks about inorder. It adds a height constraint to narrow down the number of answers. The tricky thing about this one is how to reduce the space complexity from $$O(n)$$ (turning the whole linked list into array in order to locate element quicker) to $$O(1)$$ (if not considering the $$O(\log n)$$ recursion stack). You need to use a "global" (or pass by ref) ListNode pointer that moves along with the call stack and simulate the inorder traversal.

  - [297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/): DFS or BFS with two "NULL"s encoded for a leaf node.

    - [105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/): Two traversal vector narrow down the answer.

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
  - [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/). `tails[i]` means the smallest ending number of LIS length i. We update it going through nums and use binary search.

### Quick Select

- [347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)

### Sort

- MergeSort and $$O(1)$$ space MergeSort: [148. Sort List](https://leetcode.com/problems/sort-list/)

### Monotonic Order Data Structure

- [496. Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) Tricky.
- [503. Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/). Tricky. Loop twice.
- [239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/). Deque.

### $$O(n^2)$$ Dynamic Programming

- [435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/). `dp[i]` means the maximum number of non-overlapping intervals ending at interval `i` . But actually greedy brings it down to $$O(n)$$.
- [403. Frog Jump](https://leetcode.com/problems/frog-jump/). A dp that looks forward. For each stone, we record a set of jump distances k that lands on it
- [410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/). `dp[i][j]` for minimum largest subarray sum when splitting `nums[0...i]` into `j` parts. $$O(mn^2)$$
- [1027. Longest Arithmetic Sequence](https://leetcode.com/problems/longest-arithmetic-sequence/). `dp[i]{d, l}` Diff -> length for all LASs ending at i.
- [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/). $$O(n^2)$$ DP not optimal. Use bin search to update an array of smallest ending numbers of LISs.

## Similar Problems

### Subsets

#### Easy
- [413. Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/). $$O(1)$$ DP.
- [1027. Longest Arithmetic Sequence](https://leetcode.com/problems/longest-arithmetic-sequence/). DP. `dp[i]{d, l}` Diff -> length for all LASs ending at i.

#### Medium and Hard
- [446. Arithmetic Slices II - Subsequence](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/). DP. Good comparison with 1027. `dp[i]{d, n}` Diff -> count for all pair (tricky design here) of numbers ending at i.
- [416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/). DP. `dp[i][j]`: can `nums[0...i]` sum to `j`.
- [410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/). DP. `dp[i][j]` for minimum largest subarray sum when splitting `nums[0...i]` into `j` parts.
- [548. Split Array with Equal Sum](https://leetcode.com/problems/split-array-with-equal-sum/). Not DP. Straight forward for each middle point, check if left two quarters and right two quarters can get same sum.
- [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/). `tails[i]` means the smallest ending number of LIS length i. We update it going through nums and use binary search.