class Solution {
    public void rearrangeQueue(Queue<int> q) {
        int n = q.Count;
        if(n%2 != 0){
            throw new ArgumentException("Queue size must be even");
        }
        
        Stack<int> stack = new Stack<int>();
        
        for(int i=0;i<n/2;i++){
            stack.Push(q.Dequeue());
        }
        
        while(stack.Count > 0){
            q.Enqueue(stack.Pop());
        }
        
        for(int i=0;i<n/2;i++){
            q.Enqueue(q.Dequeue());
        }
        
        for(int i=0;i<n/2;i++){
            stack.Push(q.Dequeue());
        }
        
        while(stack.Count>0){
            q.Enqueue(stack.Pop());
            q.Enqueue(q.Dequeue());
        }
    }
}