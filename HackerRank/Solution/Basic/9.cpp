/*
 * Complete the 'beautifulPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY A
 *  2. INTEGER_ARRAY B
 */

int beautifulPairs(vector<int> A, vector<int> B)
{
    multiset<int> ms(B.begin(), B.end());

    int count = 0;
    for (auto a : A)
    {
        auto it = ms.find(a);
        if (it != ms.end())
        {
            count++;
            ms.erase(it);
        }
    }

    if (ms.empty())
    {
        return count - 1;
    }
    return count + 1;
}