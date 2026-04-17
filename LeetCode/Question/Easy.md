# Problem Set of LeetCode - Easy

## Id - 1886 [Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)
### Problem : Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

## Id - 3643 [Flip Square Submatrix Vertically](https://leetcode.com/problems/flip-square-submatrix-vertically/description/)
### Problem : You are given an m x n integer matrix grid, and three integers x, y, and k. The integers x and y represent the row and column indices of the top-left corner of a square submatrix and the integer k represents the size (side length) of the square submatrix. Your task is to flip the submatrix by reversing the order of its rows vertically. Return the updated matrix.

## Id - 3852 [Smallest Pair With Different Frequencies](https://leetcode.com/problems/smallest-pair-with-different-frequencies/description/)
### Problem : You are given an integer array nums. Consider all pairs of distinct values x and y from nums such that: 
#### x < y
#### x and y have different frequencies in nums.
#### Among all such pairs:
### Choose the pair with the smallest possible value of x. If multiple pairs have the same x, choose the one with the smallest possible value of y. Return an integer array [x, y]. If no valid pair exists, return [-1, -1].

## Id - 3861 [Minimum Capacity Box](https://leetcode.com/problems/minimum-capacity-box/description/)
### Problem : You are given an integer array capacity, where capacity[i] represents the capacity of the ith box, and an integer itemSize representing the size of an item. The ith box can store the item if capacity[i] >= itemSize. Return an integer denoting the index of the box with the minimum capacity that can store the item. If multiple such boxes exist, return the smallest index. If no box can store the item, return -1.

## Id - 1009 [Complement of Base 10 Integer](https://leetcode.com/problems/complement-of-base-10-integer/description/)
### Problem : The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation. For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2. Given an integer n, return its complement.

## Id - 3827 [Count Monobit Integers](https://leetcode.com/problems/count-monobit-integers/description/)
### Problem : You are given an integer n. An integer is called Monobit if all bits in its binary representation are the same. Return the count of Monobit integers in the range [0, n] (inclusive). 

## Id - 1356 [Sort Integers by The Number of 1 Bits](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/)
### Problem : You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order. Return the array after sorting it.

## Id - 1022 [Sum of Root To Leaf Binary Numbers](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)
### Problem : You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit. For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13. For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers. The test cases are generated so that the answer fits in a 32-bits integer.

## Id - 868 [Binary Gap](https://leetcode.com/problems/binary-gap/description/)
### Problem : Given a positive integer n, find and return the longest distance between any two adjacent 1's in the binary representation of n. If there are no two adjacent 1's, return 0. Two 1's are adjacent if there are only 0's separating them (possibly no 0's). The distance between two 1's is the absolute difference between their bit positions. For example, the two 1's in "1001" have a distance of 3.

## Id - 762 [Prime Number of Set Bits in Binary Represtation](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/)
### Problem : Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation. Recall that the number of set bits an integer has is the number of 1's present when written in binary. For example, 21 written in binary is 10101, which has 3 set bits.

## Id - 696 [Count Binary Substrings](https://leetcode.com/problems/count-binary-substrings/)
### Problem : Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively. Substrings that occur multiple times are counted the number of times they occur.

## Id - 693 [Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/description/)
### Problem : Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

## Id - 401 [Binary Watch](https://leetcode.com/problems/binary-watch/description/)
### Problem : A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.
##### For example, the below binary watch reads "4:51".
##### Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order. The hour must not contain a leading zero. For example, "01:00" is not valid. It should be "1:00". The minute must consist of two digits and may contain a leading zero. For example, "10:2" is not valid. It should be "10:02".

## Id - 190 [Reverse Bits](https://leetcode.com/problems/reverse-bits/description/)
### Problem : Reverse bits of a given 32 bits signed integer.

## Id - 67 [Add Binary](https://leetcode.com/problems/add-binary/description/)
### Problem : Given two binary strings a and b, return their sum as a binary string.

## Id - 110 [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/description/)
### Problem : Given a binary tree, determine if it is height-balanced.

## Id - 3379 [Tranformed Array](https://leetcode.com/problems/transformed-array/description/)
### Problem : You are given an integer array nums that represents a circular array. Your task is to create a new array result of the same size, following these rules:
#### For each index i (where 0 <= i < nums.length), perform the following independent actions:
#### If nums[i] > 0: Start at index i and move nums[i] steps to the right in the circular array. Set result[i] to the value at the index where you land.
#### If nums[i] < 0: Start at index i and move abs(nums[i]) steps to the left in the circular array. Set result[i] to the value at the index where you land.
####  If nums[i] == 0: Set result[i] to nums[i]. Return the new array result. Note: Since nums is circular, moving past the last element wraps around to the beginning, and moving before the first element wraps back to the end.

## Id - 3637 [Trionic Array I](https://leetcode.com/problems/trionic-array-i/description/)
### Problem : You are given an integer array nums of length n.
#### An array is trionic if there exist indices 0 < p < q < n − 1 such that:
#### nums[0...p] is strictly increasing,
#### nums[p...q] is strictly decreasing,
#### nums[q...n − 1] is strictly increasing.
#### Return true if nums is trionic, otherwise return false.

## Id - 3010 [Divide an Array Into Subarray with Minimum Cost - I](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/)
### Problem : You are given an array of integers nums of length n.
#### The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3. You need to divide nums into 3 disjoint contiguous subarrays. Return the minimum possible sum of the cost of these subarrays.

## Id - 744 [Find Smllest Letter Greate Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/)
### Problem : You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters. Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

## Id - 1984 [Minimum Difference Between Highest](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/)
### Problem : You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k. Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized. Return the minimum possible difference.

## Id - 1200 [Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/description/)
### Problem : Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows a, b are from arr a < b b - a equals to the minimum absolute difference of any two elements in arr

## Id - 485 [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/description/)
### Problem : Given a binary array nums, return the maximum number of consecutive 1's in the array.

## Id - 1470 [Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/description/)
### Problem : Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn]. Return the array in the form [x1,y1,x2,y2,...,xn,yn].

## Id - 1929 [Concatenation of Array](https://leetcode.com/problems/concatenation-of-array/description/)
### Problem : Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed). Specifically, ans is the concatenation of two nums arrays. Return the array ans.

## Id - 26 [Remove Duplicates From Sorted Arry](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)
### Problem : Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Consider the number of unique elements in nums to be k​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k. The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

## Id - 27 [Remove Element](https://leetcode.com/problems/remove-element/description/)
### Problem : Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val. Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things: Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining  elements of nums are not important as well as the size of nums. Return k.

## Id - 14 [Longest Comman Prefix](https://leetcode.com/problems/longest-common-prefix/description/)
### Problem : Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".

## Id - 258 [Add Digits](https://leetcode.com/problems/add-digits/description/)
### Problem : Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

## Id - 231 [Power of Two](https://leetcode.com/problems/power-of-two/description/)
### Problem : Given an integer n, return true if it is a power of two. Otherwise, return false. An integer n is a power of two, if there exists an integer x such that n == 2x.
 
## Id - 69 [Sqrt(x)](https://leetcode.com/problems/sqrtx/description/)
### Problem : Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well. You must not use any built-in exponent function or operator. For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

## Id - 175 [Combine Two Tables](https://leetcode.com/problems/combine-two-tables/description/){SQL}
### Problem : Write a solution to report the first name, last name, city, and state of each person in the Person table. If the address of a personId is not present in the Address table, report null instead. Return the result table in any order. The result format is in the following example.

## Id - 9 [Palindrome Number](https://leetcode.com/problems/palindrome-number/description/)
### Problem : Given an integer x, return true if x is a palindrome, and false otherwise.

## Id - 2485 [Find the Pivot Integer](https://leetcode.com/problems/find-the-pivot-integer/description/)
### Problem : Given a positive integer n, find the pivot integer x such that: The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

## Id - 1502 [Can Make Arithmetic Progession From Sequence](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/)
### Problem : A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same. Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

## Id - 1 [Two Sum](https://leetcode.com/problems/two-sum/description/)
### Problem : Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

## Id - 2946 [Matrix Similarity After Cyclic Shifts](https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/)
### Problem : You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed. The following proccess happens k times: Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left. Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right. Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.

## Id - 1582 [Special Positions in a Binary Matrix](https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/)
### Problem : Given an m x n binary matrix mat, return the number of special positions in mat. A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

<<<<<<< Updated upstream
## Id - 1758 [Minimum Changes To Make Alternating Binary String](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/)
### Problem : You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa. The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not. Return the minimum number of operations needed to make s alternating.

## Id - 1784 [Check if Binary String Has at Most One Segment of Ones](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/)
### Problem : Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.
=======
## Id - 3010 [Divide an Array Into Subarrays With Minimum Cost I](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description)

## Id - 3379 [Transformed Array](https://leetcode.com/problems/transformed-array/description)

## Id - 3637 [Trionic Array I](https://leetcode.com/problems/trionic-array-i/description)

## Id - 3643 [Flip Square Submatrix Vertically](https://leetcode.com/problems/flip-square-submatrix-vertically/description)

## Id - 3740 [Minimum Distance Between Three Equal Elements I](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description)

## Id - 3827 [Count Monobit Integers](https://leetcode.com/problems/count-monobit-integers/description)

## Id - 3852 [Smallest Pair With Different Frequencies](https://leetcode.com/problems/smallest-pair-with-different-frequencies/description)

## Id - 3861 [Minimum Capacity Box](https://leetcode.com/problems/minimum-capacity-box/description)
>>>>>>> Stashed changes
