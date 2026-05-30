#include <iostream>
using namespace std;
int main()
{
    int d, sumTime;
    cin >> d >> sumTime;

    int minT[30], maxT[30], schedule[30];
    int totalMin = 0, totalMax = 0;

    for (int i = 0; i < d; i++)
    {
        cin >> minT[i] >> maxT[i];
        totalMin += minT[i];
        totalMax += maxT[i];
    }

    if (sumTime < totalMin || sumTime > totalMax)
    {
        cout << "NO";
        return 0;
    }

    int remaining = sumTime - totalMin;
    for (int i = 0; i < d; i++)
    {
        schedule[i] = minT[i];
    }

    for (int i = 0; i < d; i++)
    {
        int canAdd = maxT[i] - minT[i];
        int add = min(canAdd, remaining);
        schedule[i] += add;
        remaining -= add;
        if (remaining == 0)
            break;
    }

    cout << "YES\n";
    for (int i = 0; i < d; i++)
    {
        cout << schedule[i];
        if (i < d - 1)
            cout << " ";
    }
    return 0;
}