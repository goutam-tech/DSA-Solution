class Solution
{
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<int> runStart, runEnd, runChar;
        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && s[j] == s[i])
                j++;
            runStart.push_back(i);
            runEnd.push_back(j - 1);
            runChar.push_back(s[i] - '0');
            i = j;
        }
        int m = runStart.size();
        vector<int> posToRun(n);
        for (int r = 0; r < m; r++)
            for (int p = runStart[r]; p <= runEnd[r]; p++)
                posToRun[p] = r;

        long long totalOnes = 0;
        for (char c : s)
            if (c == '1')
                totalOnes++;

        vector<long long> val(m, LLONG_MIN / 2);
        for (int r = 0; r < m; r++)
        {
            if (runChar[r] == 1)
            {
                long long left = (r > 0) ? (runEnd[r - 1] - runStart[r - 1] + 1) : 0;
                long long right = (r < m - 1) ? (runEnd[r + 1] - runStart[r + 1] + 1) : 0;
                val[r] = left + right;
            }
        }

        int LOG = 1;
        while ((1 << LOG) <= m)
            LOG++;
        vector<vector<long long>> st(LOG, vector<long long>(m));
        st[0] = val;
        for (int k = 1; k < LOG; k++)
            for (int idx = 0; idx + (1 << k) <= m; idx++)
                st[k][idx] = max(st[k - 1][idx], st[k - 1][idx + (1 << (k - 1))]);

        vector<int> logTable(m + 1, 0);
        for (int x = 2; x <= m; x++)
            logTable[x] = logTable[x / 2] + 1;

        auto rangeMax = [&](int l, int r) -> long long
        {
            if (l > r)
                return LLONG_MIN / 2;
            int k = logTable[r - l + 1];
            return max(st[k][l], st[k][r - (1 << k) + 1]);
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries)
        {
            int l = q[0], r = q[1];
            int Lr = posToRun[l], Rr = posToRun[r];
            long long gain = 0;
            if (Lr != Rr)
            {
                int lowIdx = Lr + 1, highIdx = Rr - 1;
                if (lowIdx <= highIdx)
                {
                    int firstCand = (runChar[lowIdx] == 1) ? lowIdx : lowIdx + 1;
                    int lastCand = (runChar[highIdx] == 1) ? highIdx : highIdx - 1;
                    if (firstCand <= highIdx && lastCand >= lowIdx && firstCand <= lastCand)
                    {
                        if (firstCand == lastCand)
                        {
                            long long leftLen = (firstCand - 1 == Lr) ? (runStart[firstCand] - l) : (runStart[firstCand] - runStart[firstCand - 1]);
                            long long rightLen = (firstCand + 1 == Rr) ? (r - runEnd[firstCand]) : (runEnd[firstCand + 1] - runEnd[firstCand]);
                            gain = leftLen + rightLen;
                        }
                        else
                        {
                            long long midMax = rangeMax(firstCand + 1, lastCand - 1);
                            long long leftLenFirst = (firstCand - 1 == Lr) ? (runStart[firstCand] - l) : (runStart[firstCand] - runStart[firstCand - 1]);
                            long long rightLenFirst = runEnd[firstCand + 1] - runEnd[firstCand];
                            long long adjFirst = leftLenFirst + rightLenFirst;
                            long long rightLenLast = (lastCand + 1 == Rr) ? (r - runEnd[lastCand]) : (runEnd[lastCand + 1] - runEnd[lastCand]);
                            long long leftLenLast = runStart[lastCand] - runStart[lastCand - 1];
                            long long adjLast = leftLenLast + rightLenLast;
                            gain = max({midMax, adjFirst, adjLast});
                        }
                    }
                }
            }
            ans.push_back((int)(totalOnes + gain));
        }
        return ans;
    }
};