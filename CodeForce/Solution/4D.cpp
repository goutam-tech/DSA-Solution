#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long w, h;
    cin >> n >> w >> h;

    vector<pair<long long, long long>> env(n);
    vector<int> idx(n);

    for (int i = 0; i < n; i++)
    {
        cin >> env[i].first >> env[i].second;
        idx[i] = i;
    }

    sort(idx.begin(), idx.end(), [&](int a, int b)
         {
        if(env[a].first != env[b].first)
            return env[a].first < env[b].first;
        return env[a].second < env[b].second; });

    vector<int> valid;
    for (int i = 0; i < n; i++)
    {
        int id = idx[i];
        if (env[id].first > w && env[id].second > h)
            valid.push_back(id);
    }

    if (valid.empty())
    {
        cout << 0;
        return 0;
    }

    int m = valid.size();
    vector<int> dp(m, 1);
    vector<int> parent(m, -1);

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (env[valid[j]].first < env[valid[i]].first &&
                env[valid[j]].second < env[valid[i]].second)
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
    }

    int best = 0;
    for (int i = 1; i < m; i++)
    {
        if (dp[i] > dp[best])
            best = i;
    }

    vector<int> chain;
    int cur = best;
    while (cur != -1)
    {
        chain.push_back(valid[cur] + 1);
        cur = parent[cur];
    }
    reverse(chain.begin(), chain.end());

    cout << chain.size() << "\n";
    for (int i = 0; i < (int)chain.size(); i++)
    {
        cout << chain[i];
        if (i < (int)chain.size() - 1)
            cout << " ";
    }
    return 0;
}