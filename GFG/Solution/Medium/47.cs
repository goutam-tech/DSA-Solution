class Solution {
    public int kthSmallest(int[] arr, int k) {
        Array.Sort(arr);
        return arr[k-1];
    }
}