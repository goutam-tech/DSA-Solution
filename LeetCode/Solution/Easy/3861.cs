public class Solution {
    public int MinimumIndex(int[] capacity, int itemSize) {
        int minCapacity = int.MaxValue;
        int index = -1;

        for (int i = 0; i < capacity.Length; i++)
        {
            if (capacity[i] >= itemSize && capacity[i] < minCapacity)
            {
                minCapacity = capacity[i];
                index = i;
            }
        }

        return index;
    }
}