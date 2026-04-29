# Problem Set of LeetCode - Medium

## Id - 2840 [Check if Strings Can be Made Equal With Operations II](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/)
### Problem : You are given two strings s1 and s2, both of length n, consisting of lowercase English letters. You can apply the following operation on any of the two strings any number of times: Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string. Return true if you can make the strings s1 and s2 equal, and false otherwise.

## Id - 3653 [XOR After Range Multiplication Queries I](https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/)
### Problem : You are given an integer array nums of length n and a 2D integer array queries of size q, where queries[i] = [li, ri, ki, vi]. For each query, you must apply the following operations in order: Set idx = li. While idx <= ri: Update: nums[idx] = (nums[idx] * vi) % (109 + 7) Set idx += ki. Return the bitwise XOR of all elements in nums after processing all queries.