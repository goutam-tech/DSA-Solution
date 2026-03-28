public class Solution {
    public int[] SortByBits(int[] arr) {
        return arr.OrderBy(x => CountBits(x)).ThenBy(x => x).ToArray();
    }

    private int CountBits(int x){
        int count = 0;
        while(x > 0){
            count += x & 1;
            x >>= 1;
        }

        return count;
    }
}