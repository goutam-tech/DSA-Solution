class Solution {
    public List<int> makeBeautiful(List<int> arr) {
        // code here
        var stack = new Stack<int>();
        
        foreach(int num in arr){
            if(stack.Count > 0 && ((stack.Peek() < 0) != (num < 0))){
                stack.Pop();
            }
            else{
                stack.Push(num);
            }
        }
        
        var result = new List<int>(stack);
        result.Reverse();
        return result;
    }
}