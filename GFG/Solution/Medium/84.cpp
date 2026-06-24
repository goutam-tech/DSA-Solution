#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(int n)
    {
        // code here
        if (n == 2)
        {
            return 1;
        }
        if (n == 3)
        {
            return 2;
        }

        int product = 1;
        while (n > 4)
        {
            product *= 3;
            n -= 3;
        }

        return product * n;
    }
};

// Used for the testing in local system
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;

//     Solution obj;
//     int res = obj.maxProduct(n);

//     cout << res << "\n";
// }