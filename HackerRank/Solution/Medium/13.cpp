/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int sherlockAndAnagrams(string s)
{
    int n = s.size();
    unordered_map<string, long long> anagramCount;

    for (int len = 1; len < n; len++)
    {
        for (int j = 0; j + len <= n; j++)
        {
            string sub = s.substr(j, len);
            sort(sub.begin(), sub.end());
            anagramCount[sub]++;
        }
    }

    long long count = 0;
    for (auto &p : anagramCount)
    {
        long long k = p.second;
        count += k * (k - 1) / 2;
    }

    return (int)count;
}