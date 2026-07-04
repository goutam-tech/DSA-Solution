#include <bits/stdc++.h>
using namespace std;

void magicBox()
{
    long long x, y, z, x1, y1, z1;
    cin >> x >> y >> z;
    cin >> x1 >> y1 >> z1;

    long long a[7];
    for (int i = 1; i <= 6; i++)
    {
        cin >> a[i];
    }

    long long ans = 0;

    if (y < 0)
        ans += a[1];
    if (y > y1)
        ans += a[2];
    if (z < 0)
        ans += a[3];
    if (z > z1)
        ans += a[4];
    if (x < 0)
        ans += a[5];
    if (x > x1)
        ans += a[6];

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    magicBox();

    return 0;
}