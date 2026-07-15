#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int spf[N + 1];

void init()
{
    for (int i = 2; i <= N; i++)
    {
        if (!spf[i])
        {
            for (int j = i; j <= N; j += i)
            {
                if (!spf[j])
                {
                    spf[j] = i;
                }
            }
        }
    }
}

void stormingArasaka()
{
    int n;
    cin >> n;
    int big = 0, small = 0;
    while (n > 1)
    {
        int p = spf[n];
        small++;
        while (n % p == 0)
        {
            n /= p;
            big++;
        }
    }

    cout << big + small - 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    while (t--)
        stormingArasaka();
    return 0;
}