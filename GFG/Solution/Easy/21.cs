class Solution {
    public int countIncreasing(int[] arr) {
        int n = arr.Length;
        int count = 0;
        int len = 1;
        
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                len++;
            } else {
                if (len >= 2) count += (len - 1) * len / 2;
                len = 1;
            }
        }
        
        if (len >= 2) count += (len - 1) * len / 2;
        
        return count;
    }
}