public class Solution {
    public List<int> kthLargest(int[] arr, int k) {
        List<int> result = new List<int>();
        PriorityQueue<int, int> minHeap = new PriorityQueue<int, int>();
        
        foreach (int num in arr) {
            minHeap.Enqueue(num, num);
            if (minHeap.Count > k) {
                minHeap.Dequeue();
            }
            result.Add(minHeap.Count < k ? -1 : minHeap.Peek());
        }
        
        return result;
    }
}