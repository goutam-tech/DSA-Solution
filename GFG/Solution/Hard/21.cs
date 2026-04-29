using System;
using System.Collections.Generic;

public class Solution
{
    public class Node
    {
        public int freq;
        public int minIdx;
        public Node left, right;

        public Node(int freq, int idx)
        {
            this.freq = freq;
            this.minIdx = idx;
            this.left = null;
            this.right = null;
        }
    }

    public List<string> huffmanCodes(string s, int[] f)
    {
        var pq = new PriorityQueue<Node, (int, int)>();

        // Insert nodes into priority queue
        for (int i = 0; i < s.Length; i++)
        {
            var node = new Node(f[i], i);
            pq.Enqueue(node, (node.freq, node.minIdx));
        }

        // Edge case: only one character
        if (pq.Count == 1)
            return new List<string> { "0" };

        // Build Huffman Tree
        while (pq.Count > 1)
        {
            var left = pq.Dequeue();
            var right = pq.Dequeue();

            var parent = new Node(
                left.freq + right.freq,
                Math.Min(left.minIdx, right.minIdx)
            );

            parent.left = left;
            parent.right = right;

            pq.Enqueue(parent, (parent.freq, parent.minIdx));
        }

        var root = pq.Dequeue();

        var result = new List<string>();
        Traverse(root, "", result);

        return result;
    }

    private void Traverse(Node node, string code, List<string> result)
    {
        if (node == null) return;

        if (node.left == null && node.right == null)
        {
            result.Add(code);
            return;
        }

        Traverse(node.left, code + "0", result);
        Traverse(node.right, code + "1", result);
    }
}