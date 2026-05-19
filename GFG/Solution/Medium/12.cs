public class Solution {
    public int minSwaps(int[] arr) {
        int totalOnes = 0;
        foreach (int x in arr) if (x == 1) totalOnes++;
        
        if (totalOnes == 0) return -1;
        
        int onesInWindow = 0;
        for (int i = 0; i < totalOnes; i++)
            if (arr[i] == 1) onesInWindow++;
        
        int maxOnes = onesInWindow;
        int n = arr.Length;
        
        for (int i = totalOnes; i < n; i++) {
            if (arr[i] == 1) onesInWindow++;
            if (arr[i - totalOnes] == 1) onesInWindow--;
            if (onesInWindow > maxOnes) maxOnes = onesInWindow;
        }
        
        return totalOnes - maxOnes;
    }
}