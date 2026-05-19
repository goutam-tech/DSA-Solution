class Solution {
    public bool PythagoreanTriplet(int[] arr) {
        int n = arr.Length;
        if (n < 3) return false;

        HashSet<long> squareSet = new HashSet<long>(n);
        long[] sq = new long[n];

        for (int i = 0; i < n; i++)
        {
            sq[i] = (long)arr[i] * arr[i];
            squareSet.Add(sq[i]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long sumOfSquares = sq[i] + sq[j];
                if (squareSet.Contains(sumOfSquares))
                    return true;
            }
        }

        return false;
    }
}