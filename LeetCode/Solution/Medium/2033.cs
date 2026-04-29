public class Solution {
    public int MinOperations(int[][] grid, int x) {
        var nums = new List<int>();
        int remainder = grid[0][0] % x;
        
        for (int i = 0; i < grid.Length; i++) {
            for (int j = 0; j < grid[0].Length; j++) {
                if (grid[i][j] % x != remainder) return -1;
                nums.Add(grid[i][j]);
            }
        }
        
        nums.Sort();
        int median = nums[nums.Count / 2];
        int ops = 0;
        
        foreach (int num in nums) {
            ops += Math.Abs(num - median) / x;
        }
        
        return ops;
    }
}