#include <bits/stdc++.h>
using namespace std;

void Bitchemist()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long a[3] = {1, 0, 0};
    int x = 0;
    long long ans = 0;
    char pre = '\0';
    int y = 0;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == '0')
            x -= 1;
        else
            x += 1;
        x = ((x % 3) + 3) % 3;

        if (c == pre)
            y = 1;
        else
            y += 1;
        pre = c;

        long long total = a[0] + a[1] + a[2];
        ans += total - a[x];
        a[x] += 1;
        ans -= (y - 1) / 2;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        Bitchemist();
    return 0;
}