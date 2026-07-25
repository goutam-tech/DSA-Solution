/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int nonDivisibleSubset(int k, vector<int> s)
{
    vector<int> mod_cnt(k, 0);
    for (int i = 0; i < (int)s.size(); i++)
    {
        mod_cnt[s[i] % k]++;
    }

    int result = 0;
    for (int i = 1; i < (k + 1) / 2; i++)
    {
        result += max(mod_cnt[i], mod_cnt[k - i]);
    }

    result += (mod_cnt[0] > 0 ? 1 : 0) + ((k % 2 == 0 && mod_cnt[k / 2] > 0) ? 1 : 0);

    return result;
}