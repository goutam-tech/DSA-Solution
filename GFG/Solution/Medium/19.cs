class Solution {
    public int[] find3Numbers(int[] arr) {
        int n = arr.Length;
        if (n < 3) return new int[0];
        
        int[] smaller = new int[n];
        int[] larger = new int[n];
        
        smaller[0] = -1;
        int minVal = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > minVal) smaller[i] = minVal;
            else { smaller[i] = -1; minVal = arr[i]; }
        }
        
        larger[n-1] = -1;
        int maxVal = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] < maxVal) larger[i] = maxVal;
            else { larger[i] = -1; maxVal = arr[i]; }
        }
        
        for (int j = 1; j < n-1; j++) {
            if (smaller[j] != -1 && larger[j] != -1)
                return new int[] { smaller[j], arr[j], larger[j] };
        }
        
        return new int[0];
    }
}