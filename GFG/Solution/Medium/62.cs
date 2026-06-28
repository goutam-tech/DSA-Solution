using System;
using System.Collections.Generic;

public class Solution {
    public List<int> maxOfSubarrays(int[] arr, int k) {
        int n = arr.Length;
        List<int> result = new List<int>();
        LinkedList<int> deque = new LinkedList<int>();
        
        for(int i=0;i<n;i++){
            if(deque.Count > 0 && deque.First.Value <= i-k){
                deque.RemoveFirst();
            }
            
            while(deque.Count > 0 && arr[deque.Last.Value] <= arr[i]){
                deque.RemoveLast();
            }
            
            deque.AddLast(i);
            
            if(i>=k-1){
                result.Add(arr[deque.First.Value]);
            }
        }
        
        // return result.ToArray(); //If it the function is given in int[]  then write this.
        return result;
    }
}