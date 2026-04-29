public class Solution
{
    public int LongestBalanced(string InputString)
    {
        int MaxLength = FindSingleCharMax(InputString);

        MaxLength = Math.Max(MaxLength, FindTwoCharBalancedMax('a', 'b', 'c', InputString));
        MaxLength = Math.Max(MaxLength, FindTwoCharBalancedMax('a', 'c', 'b', InputString));
        MaxLength = Math.Max(MaxLength, FindTwoCharBalancedMax('b', 'c', 'a', InputString));

        MaxLength = Math.Max(MaxLength, FindThreeCharBalancedMax(InputString));

        return MaxLength;
    }

    private int FindSingleCharMax(string InputString)
    {
        int StringLength = InputString.Length;
        if (StringLength == 0)
            return 0;

        int MaxLength = 0;
        int CurrentCount = 1;

        for (int Index = 1; Index < StringLength; Index++)
        {
            if (InputString[Index] == InputString[Index - 1])
                CurrentCount++;
            else
                CurrentCount = 1;

            MaxLength = Math.Max(MaxLength, CurrentCount);
        }

        return Math.Max(MaxLength, CurrentCount);
    }

    private int FindTwoCharBalancedMax(char TargetA, char TargetB, char BarrierChar, string InputString)
    {
        int StringLength = InputString.Length;
        int MaxLength = 0;
        int BalanceCount = 0;
        var BalanceMap = new Dictionary<int, int>();

        BalanceMap[0] = -1;

        for (int Index = 0; Index < StringLength; Index++)
        {
            if (InputString[Index] == BarrierChar)
            {
                BalanceCount = 0;
                BalanceMap.Clear();
                BalanceMap[0] = Index;
                continue;
            }

            if (InputString[Index] == TargetA)
                BalanceCount++;
            else if (InputString[Index] == TargetB)
                BalanceCount--;

            if (BalanceMap.TryGetValue(BalanceCount, out int PreviousIndex))
                MaxLength = Math.Max(MaxLength, Index - PreviousIndex);
            else
                BalanceMap[BalanceCount] = Index;
        }

        return MaxLength;
    }

    private int FindThreeCharBalancedMax(string InputString)
    {
        int MaxLength = 0;
        int StringLength = InputString.Length;
        int[] CharCounts = new int[3];
        var DifferenceMap = new Dictionary<(int, int), int>();

        DifferenceMap[(0, 0)] = -1;

        for (int Index = 0; Index < StringLength; Index++)
        {
            CharCounts[InputString[Index] - 'a']++;
            var CurrentDiffKey = (CharCounts[0] - CharCounts[1], CharCounts[1] - CharCounts[2]);

            if (DifferenceMap.TryGetValue(CurrentDiffKey, out int PreviousIndex))
                MaxLength = Math.Max(MaxLength, Index - PreviousIndex);
            else
                DifferenceMap[CurrentDiffKey] = Index;
        }

        return MaxLength;
    }
}