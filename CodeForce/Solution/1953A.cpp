#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;
    }

    const int CHUNK = 2000;

    if (n <= CHUNK)
    {
        cout << "{d:";
        for (int i = 1; i <= n; i++)
        {
            if (i > 1)
                cout << ',';
            cout << i;
        }
        cout << "}\n";
    }
    else
    {
        vector<string> chunks;
        for (int start = 1; start <= n; start += CHUNK)
        {
            int end = min(start + CHUNK - 1, n);
            string s = "{d:";
            for (int i = start; i <= end; i++)
            {
                if (i > start)
                    s += ',';
                s += to_string(i);
            }
            s += "}";
            chunks.push_back(s);
        }

        if (chunks.size() == 1)
        {
            cout << chunks[0] << "\n";
            return 0;
        }

        cout << "{d:";
        for (int i = 0; i < (int)chunks.size(); i++)
        {
            if (i > 0)
                cout << ',';
            cout << chunks[i];
        }
        cout << "}\n";
    }

    return 0;
}