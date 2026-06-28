#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

bool check(int step)
{
    int nodes = n / step;
    for (int offset = 0; offset < step; offset++)
    {
        bool ok = true;
        for (int u = 0; u < nodes; u++)
        {
            if (!a[(step * u + offset) % n])
            {
                ok = false;
                break;
            }
        }
        if (ok)
            return true;
    }
    return false;
}

void knights()
{
    cin >> n;
    a.assign(n, 0);
    for (int &x : a)
        cin >> x;

    for (int step = 1; step <= n / 3; step++)
    {
        if (n % step != 0)
            continue;
        if (check(step))
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    knights();
    return 0;
}