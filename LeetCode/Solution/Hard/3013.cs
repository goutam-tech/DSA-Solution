using System;
using System.Collections.Generic;

public class Solution
{
    public long MinimumCost(int[] nums, int k, int dist)
    {
        int n = nums.Length;
        long baseCost = nums[0];

        PriorityQueue<int, int> small = new();
        PriorityQueue<int, int> large = new();

        Dictionary<int, int> delayed = new();
        long sumSmall = 0;
        int smallSize = 0;

        void AddDelayed(int x)
        {
            if (!delayed.ContainsKey(x)) delayed[x] = 0;
            delayed[x]++;
        }

        void Clean(PriorityQueue<int, int> heap, bool isSmall)
        {
            while (heap.Count > 0)
            {
                int x = heap.Peek();
                if (delayed.ContainsKey(x))
                {
                    delayed[x]--;
                    if (delayed[x] == 0) delayed.Remove(x);
                    heap.Dequeue();
                }
                else break;
            }
        }

        void Balance()
        {
            Clean(small, true);
            Clean(large, false);

            while (smallSize > k - 1)
            {
                int x = small.Dequeue();
                sumSmall -= x;
                smallSize--;
                large.Enqueue(x, x);
                Clean(small, true);
            }

            while (smallSize < k - 1 && large.Count > 0)
            {
                int x = large.Dequeue();
                sumSmall += x;
                smallSize++;
                small.Enqueue(x, -x);
                Clean(large, false);
            }
        }

        long ans = long.MaxValue;
        int left = 1;

        for (int right = 1; right < n; right++)
        {
            int x = nums[right];

            if (smallSize < k - 1 || (small.Count > 0 && x <= small.Peek()))
            {
                small.Enqueue(x, -x);
                sumSmall += x;
                smallSize++;
            }
            else
            {
                large.Enqueue(x, x);
            }

            Balance();

            while (right - left > dist)
            {
                int y = nums[left++];
                AddDelayed(y);

                if (small.Count > 0 && y <= small.Peek())
                {
                    sumSmall -= y;
                    smallSize--;
                }

                Balance();
            }

            if (smallSize == k - 1)
                ans = Math.Min(ans, baseCost + sumSmall);
        }

        return ans;
    }
}