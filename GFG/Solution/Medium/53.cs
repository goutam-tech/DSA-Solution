class Solution {
    public List<int> missingRange(int[] arr, int low, int high) {
        HashSet<int> present = new HashSet<int>(arr);
        List<int> missing = new List<int>();

        for (int i = low; i <= high; i++)
        {
            if (!present.Contains(i))
                missing.Add(i);
        }

        return missing;
    }
}