#include <bits/stdc++.h>
using namespace std;

void add_not_add()
{
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    sort(a.begin(), a.end());

    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + a[i];
    }

    int bestCnt = 0;
    long long bestVal = a[0];
    int l = 0;

    for (int r = 0; r < n; r++)
    {
        while (a[r] * (long long)(r - l + 1) - (pre[r + 1] - pre[l]) > k)
        {
            l++;
        }
        int cnt = r - l + 1;
        if (cnt > bestCnt || (cnt == bestCnt && a[r] < bestVal))
        {
            bestCnt = cnt;
            bestVal = a[r];
        }
    }
    cout << bestCnt << " " << bestVal << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    add_not_add();

    return 0;
}