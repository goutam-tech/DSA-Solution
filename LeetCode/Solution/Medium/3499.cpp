class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int n = s.size();
        int totalOnes = 0;
        for (char c : s)
            if (c == '1')
                totalOnes++;

        string t = "1" + s + "1";
        int m = t.size();

        vector<pair<char, int>> blocks;
        int i = 0;
        while (i < m)
        {
            int j = i;
            while (j < m && t[j] == t[i])
                j++;
            blocks.push_back({t[i], j - i});
            i = j;
        }

        int sz = blocks.size();
        int maxZero = 0;
        int minSell = INT_MAX;
        int mergeGain = 0;
        bool hasInteriorOne = false;

        for (int k = 0; k < sz; k++)
        {
            if (blocks[k].first == '0')
            {
                maxZero = max(maxZero, blocks[k].second);
            }
            else if (k > 0 && k < sz - 1)
            {
                hasInteriorOne = true;
                minSell = min(minSell, blocks[k].second);
                mergeGain = max(mergeGain, blocks[k - 1].second + blocks[k + 1].second);
            }
        }

        if (!hasInteriorOne)
            return totalOnes;

        int nonMergeGain = maxZero - minSell;
        int best = max(0, max(mergeGain, nonMergeGain));

        return totalOnes + best;
    }
};