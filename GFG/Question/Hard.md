# Hard problems on GFG.

## PId - 1 [Alien Dictionary](https://www.geeksforgeeks.org/problems/alien-dictionary/0)
### Problem : A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules. Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them. However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string (""). A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller. Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

## PId - 2 [Trapping Rain Water](https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/0)
### Problem : Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.

## PId - 3 [Max Cirular Subarray Sum](https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/0)
### Problem : You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. In a circular array, the subarray can start at the end and wrap around to the beginning. Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.

## PId - 4 [Smallest window containing all characters](https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/0)
### Problem : Given two strings s and p. Find the smallest substring in s consisting of all the characters (including duplicates) of the string p. Return empty string in case no such substring is present. If there are multiple such substring of the same length found, return the one with the least starting index.

## PId - 5 [Histogram Max Rectangular Area](https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/0)
### Problem : You are given a histogram represented by an array arr[ ], where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit. Your task is to find the largest rectangular area possible in the given histogram, where the rectangle can be formed using a number of contiguous bars.

## PId - 6 [Buring Tree](https://www.geeksforgeeks.org/problems/burning-tree/0)
### Problem : Given the root of a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent. Note: The tree contains unique values.

## PId - 7 [The Painter's Partition Problem - II](https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/0)
### Problem : Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board. Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).

## PId - 8 [All numbers with specific difference](https://www.geeksforgeeks.org/problems/all-numbers-with-specific-difference3558/0)
### Problem : Given a positive number n and a number d. Find the count of positive numbers smaller or equal to n such that the difference between the number and sum of its digits is greater than or equal to given specific value d.

## PId - 9 [Distribute Candies](https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/0)
### Problem : You are given the root of a binary tree with n nodes, where each node contains a certain number of candies, and the total number of candies across all nodes is n. In one move, you can select any two adjacent nodes and transfer one candy from one node to the other. The transfer can occur between a parent and child in either direction. The task is to determine the minimum number of moves required to ensure that every node in the tree has exactly one candy. Note: The testcases are framed such that it is always possible to achieve a configuration in which every node has exactly one candy, after some moves.

## PId - 10 [Maximum number of overlapping intervals](https://www.geeksforgeeks.org/problems/intersecting-intervals/0)
### Problem : You are given an array of intervals arr[][], where each interval is represented by two integers [start, end] (inclusive). Return the maximum number of intervals that overlap at any point in time.

## PId - 11 [Max min Height](https://www.geeksforgeeks.org/problems/max-min-height--170647/0)
### Problem : Given a garden with n flowers planted in a row, that is represented by an array arr[], where arr[i] denotes the height of the ith flower.You will water them for k days. In one day you can water w continuous flowers. Whenever you water a flower its height increases by 1 unit. You have to maximize the minimum height of all flowers after  k days of watering.

## PId - 12 [Minimum K Consecutive Bit Flips](https://www.geeksforgeeks.org/problems/minimum-number-of-k-consecutive-bit-flips--171650/0)
### Problem : You are given a binary array arr[] (containing only 0's and 1's) and an integer k. In one operation, you can select a contiguous subarray of length k and flip all its bits (i.e., change every 0 to 1 and every 1 to 0). Your task is to find the minimum number of such operations required to make the entire array consist of only 1's. If it is not possible, return -1.

## PId - 13 [Number of submatrix have sum X](https://www.geeksforgeeks.org/problems/number-of-submatrix-have-sum-k/0)
### Problem : Given a matrix mat[][] of size n × m and an integer x, find the number of square submatrices whose sum of elements is equal to x.

## PId - 14 [Implment k Queues in a Single Array](https://www.geeksforgeeks.org/problems/implement-k-queues-in-a-single-array/0)
### Problem : You are given two integers n and k. Your task is to implement a class kQueues that uses a single array of size n to simulate k independent queues. The class should support the following operations:
### enqueue(x, i) → Adds the element x into the i-th queue.
### dequeue(i) → Removes the front element from the i-th queue and returns it. Returns -1 if the queue is empty.
### isEmpty(i) → Returns true if i-th queue is empty, else return false.
### isFull() → Returns true if the array is completely full and no more elements can be inserted, otherwise false.

## There will be a sequence of q queries represented as:

### 1 x i : Call enqueue(x, i)
### 2 i : Call dequeue(i)
### 3 i : Call isEmpty(i)
### 4 : Call isFull()

### The driver code will process the queries, call the corresponding functions, and print the results of dequeue, isEmpty, and isFull operations. You only need to implement the above four functions.

## PId - 15 [Number of BST From Array](https://www.geeksforgeeks.org/problems/number-of-bst-from-array/0)
### Problem : You are given an integer array arr[] containing distinct elements. Your task is to return an array where the ith element denotes the number of unique BSTs formed when arr[i] is chosen as the root.

## PId - 16 [Length of Longest Cycle in a Graph](https://www.geeksforgeeks.org/problems/length-of-longest-cycle-in-a-graph/0)
### Problem : Given an directed graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v. Each node has at most one outgoing edge. Your task is to find the length of the longest cycle present in the graph. If no cycle exists, return -1. Note: A cycle is a path that starts and ends at the same vertex.

## PId - 17 [Chocolates Pickup](https://www.geeksforgeeks.org/problems/chocolates-pickup/1)
### Problem : You are given a 2D matrix grid[][] of size n*m, where each cell grid[i][j] represents the number of chocolates available at position (i, j). Two robots are collecting chocolates from this grid: Robot 1 starts at the top-left corner (0, 0) Robot 2 starts at the top-right corner (0, m - 1) Your task is to determine the maximum total number of chocolates both robots can collect while following these rules:
##### From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
##### When a robot visits a cell, it collects all the chocolates there.
##### If both robots land on the same cell, the chocolates in that cell are collected only once.
##### Robots cannot move outside the boundaries of the grid.
##### Both robots must continue moving until they reach the bottom row of the grid.

## PId - 18 [Articulation Point - II](https://www.geeksforgeeks.org/problems/articulation-point2616/0)
### Problem : You are given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v. Your task is to return all the articulation points (or cut vertices) in the graph. An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph. Note: The graph may be disconnected, i.e., it may consist of more than one connected component. If no such point exists, return {-1}.