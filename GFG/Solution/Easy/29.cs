class Solution {
    public List<int> sortBySetBitCount(int[] arr) {
        return arr.Select((val, idx) => (val, idx))
                  .OrderByDescending(x => System.Numerics.BitOperations.PopCount((uint)x.val))
                  .ThenBy(x => x.idx)
                  .Select(x => x.val)
                  .ToList();
    }
}