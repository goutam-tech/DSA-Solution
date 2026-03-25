class Solution {
    public int getMaxArea(int[] arr) {
        int n = arr.Length;
        var stack = new Stack<int>();
        int maxArea = 0;
        
        for(int i = 0; i <= n; i++){
            int currHeight = (i == n) ? 0 : arr[i];
            
            while(stack.Count > 0 && arr[stack.Peek()] > currHeight){
                int height = arr[stack.Pop()];
                int width = stack.Count == 0 ? i : i - stack.Peek() - 1;
                maxArea = Math.Max(maxArea, height * width);
            }
            
            stack.Push(i);
        }
        
        return maxArea;
    }
}