class Solution {
    public int sumSubMins(int[] arr) {
        int n = arr.Length;
        long result = 0;
        Stack<int> stack = new Stack<int>();
        int[] left = new int[n];
        int[] right = new int[n];

        for (int i = 0; i < n; i++) {
            while (stack.Count > 0 && arr[stack.Peek()] > arr[i])
                stack.Pop();
            left[i] = stack.Count == 0 ? i + 1 : i - stack.Peek();
            stack.Push(i);
        }

        stack.Clear();

        for (int i = n - 1; i >= 0; i--) {
            while (stack.Count > 0 && arr[stack.Peek()] >= arr[i])
                stack.Pop();
            right[i] = stack.Count == 0 ? n - i : stack.Peek() - i;
            stack.Push(i);
        }

        for (int i = 0; i < n; i++)
            result += (long)arr[i] * left[i] * right[i];

        return (int)result;
    }
}