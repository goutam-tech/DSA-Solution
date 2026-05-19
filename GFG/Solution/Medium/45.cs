class Solution {
    public int longestSubarray(int[] arr, int k) {
        int n = arr.Length;

        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + (arr[i] > k ? 1 : -1);

        Stack<int> stack = new Stack<int>();
        for (int i = 0; i <= n; i++) {
            if (stack.Count == 0 || prefix[stack.Peek()] > prefix[i])
                stack.Push(i);
        }

        int maxLen = 0;
        for (int i = n; i >= 1; i--) {
            while (stack.Count > 0 && prefix[stack.Peek()] < prefix[i]) {
                maxLen = Math.Max(maxLen, i - stack.Peek());
                stack.Pop();
            }
        }

        return maxLen;
    }
}