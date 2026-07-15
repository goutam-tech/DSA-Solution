/*
 * Complete the 'icecreamParlor' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER m
 *  2. INTEGER_ARRAY arr
 */

vector<int> icecreamParlor(int m, vector<int> arr)
{
    unordered_map<int, int> priceIndex;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        int needed = m - arr[i];

        auto it = priceIndex.find(needed);
        if (it != priceIndex.end())
        {
            return {it->second + 1, i + 1};
        }

        priceIndex[arr[i]] = i;
    }

    return {};
}