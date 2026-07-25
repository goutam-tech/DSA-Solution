/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr)
{
    long long total = 0;
    long long mn = arr[0], mx = arr[0];

    for (int v : arr)
    {
        total += v;
        mn = min(mn, (long long)v);
        mx = max(mx, (long long)v);
    }

    cout << total - mx << " " << total - mn << '\n';
}