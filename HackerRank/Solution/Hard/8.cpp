#include <bits/stdc++.h>
using namespace std;

int maxValue(string t)
{
    int n = t.size();
    vector<int> sa(n), rnk(n), tmp(n);
    for (int i = 0; i < n; i++)
    {
        sa[i] = i;
        rnk[i] = t[i];
    }
    for (int k = 1; k < n; k <<= 1)
    {
        auto cmp = [&](int a, int b)
        {
            if (rnk[a] != rnk[b])
                return rnk[a] < rnk[b];
            int ra = a + k < n ? rnk[a + k] : -1;
            int rb = b + k < n ? rnk[b + k] : -1;
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        rnk = tmp;
        if (rnk[sa[n - 1]] == n - 1)
            break;
    }

    vector<int> irnk(n), lcp(n, 0);
    for (int i = 0; i < n; i++)
        irnk[sa[i]] = i;
    for (int i = 0, h = 0; i < n; i++)
    {
        if (irnk[i] > 0)
        {
            int j = sa[irnk[i] - 1];
            while (i + h < n && j + h < n && t[i + h] == t[j + h])
                h++;
            lcp[irnk[i]] = h;
            if (h > 0)
                h--;
        }
        else
            h = 0;
    }

    vector<int> left(n, 0), right(n, n), st;
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && lcp[st.back()] >= lcp[i])
            st.pop_back();
        if (!st.empty())
            left[i] = st.back();
        st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 1; i--)
    {
        while (!st.empty() && lcp[st.back()] >= lcp[i])
            st.pop_back();
        if (!st.empty())
            right[i] = st.back();
        st.push_back(i);
    }

    long long ans = n;
    for (int i = 1; i < n; i++)
        ans = max(ans, (long long)lcp[i] * (right[i] - left[i]));
    return (int)ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    cout << maxValue(s) << "\n";
}