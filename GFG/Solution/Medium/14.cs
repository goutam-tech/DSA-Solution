public class Solution {
    public List<int> reducePairs(int[] arr) {
        Stack<int> stack = new Stack<int>();
        
        foreach (int num in arr) {
            bool pushed = true;
            int current = num;
            
            while (stack.Count > 0) {
                int top = stack.Peek();
                
                if ((top > 0 && current < 0) || (top < 0 && current > 0)) {
                    int absTop = Math.Abs(top);
                    int absCurrent = Math.Abs(current);
                    
                    if (absTop == absCurrent) {
                        stack.Pop();
                        pushed = false;
                        break;
                    } else if (absTop > absCurrent) {
                        pushed = false;
                        break;
                    } else {
                        stack.Pop();
                    }
                } else {
                    break;
                }
            }
            
            if (pushed) {
                stack.Push(current);
            }
        }
        
        List<int> result = new List<int>(stack);
        result.Reverse();
        return result;
    }
}