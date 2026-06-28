class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int cnt[26] = {0};
        for (char c : text)
        {
            cnt[c - 'a']++;
        }
        int b = cnt['b' - 'a'];
        int a = cnt['a' - 'a'];
        int l = cnt['l' - 'a'] / 2;
        int o = cnt['o' - 'a'] / 2;
        int n = cnt['n' - 'a'];
        return min({b, a, l, o, n});
    }
};