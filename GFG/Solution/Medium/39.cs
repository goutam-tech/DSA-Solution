class Solution {
    public int countSubarrays(int[] arr) {
        int count = 0;
        int n = arr.Length;
        
        
        Stack<int> stack = new Stack<int>();
        int[] nextSmaller = new int[n];
        
        for(int i = n - 1; i >= 0; i--){
            while(stack.Count > 0 && arr[stack.Peek()] >= arr[i]){
                stack.Pop();
            }
            nextSmaller[i] = stack.Count == 0 ? n : stack.Peek();
            stack.Push(i);
        }
        
        for(int i = 0; i < n; i++){
            count += nextSmaller[i] - i;
        }
        
        return count;
    }
}