#include <bits/stdc++.h>
using namespace std;

long long merge_count(vector<int> &arr, int l, int mid, int r)
{
    vector<int> temp;
    temp.reserve(r - l + 1);
    int i = l, j = mid + 1;
    long long cnt = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            cnt += (mid - i + 1);
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= r)
        temp.push_back(arr[j++]);
    for (int k = l; k <= r; k++)
        arr[k] = temp[k - l];
    return cnt;
}

long long count_shifts(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    long long cnt = count_shifts(arr, l, mid) + count_shifts(arr, mid + 1, r);
    cnt += merge_count(arr, l, mid, r);
    return cnt;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << count_shifts(arr, 0, n - 1) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}