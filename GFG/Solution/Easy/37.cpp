class Solution
{
public:
    int minToggle(vector<int> &arr)
    {
        int n = arr.size();
        int ones = 0;
        for (int x : arr)
            ones += x;

        int onesLeft = 0;
        int minToggle = ones;

        minToggle = INT_MAX;
        onesLeft = 0;
        int zerosLeft = 0;
        int totalZeros = n - ones;

        for (int i = 0; i <= n; i++)
        {
            int zerosRight = totalZeros - zerosLeft;
            minToggle = min(minToggle, onesLeft + zerosRight);
            if (i < n)
            {
                if (arr[i] == 1)
                    onesLeft++;
                else
                    zerosLeft++;
            }
        }

        return minToggle;
    }
};