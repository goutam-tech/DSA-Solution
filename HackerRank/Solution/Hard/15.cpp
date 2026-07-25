#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'circularPalindromes' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING s as parameter.
 */

vector<int> circularPalindromes(string s)
{
    int n = s.size();
    vector<char> buf(2 * n);
    for (int i = 0; i < n; i++)
        buf[i] = buf[n + i] = s[i];

    int len = 2 * n;
    int L = 4 * n;
    vector<int> rad(L, 0);
    {
        int i, j, k;
        for (i = 0, j = 0; i < 2 * len; i += k, j = max(j - k, 0))
        {
            while (i - j >= 0 && i + j + 1 < 2 * len && buf[(i - j) / 2] == buf[(i + j + 1) / 2])
                ++j;
            rad[i] = j;
            for (k = 1; i - k >= 0 && rad[i] - k >= 0 && rad[i - k] != rad[i] - k; ++k)
                rad[i + k] = min(rad[i - k], rad[i] - k);
        }
    }

    vector<int> ss(L, 0), ee(L, 0), vv(L, 0);
    for (int i = 0; i < L; i++)
    {
        int k = min(n, rad[i]);
        if (i % 2 == 0 && k % 2 == 0)
            k--;
        if (i % 2 == 1 && k % 2 == 1)
            k--;
        if (rad[i] == 0)
            continue;
        int st = i / 2 - (k - 1) / 2;
        int ed = i / 2 + k / 2;
        int m = ed - st + 1;
        ss[i] = ((st - (n - m)) % n + n + n) % n;
        ee[i] = (st % n + n + n) % n;
        vv[i] = m;
    }

    vector<int> idx(L);
    for (int i = 0; i < L; i++)
        idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int a, int b)
         {
        if (vv[a] != vv[b]) return vv[a] < vv[b];
        if (ss[a] != ss[b]) return ss[a] < ss[b];
        return ee[a] < ee[b]; });

    vector<int> res(n, 0);
    vector<int> nx(n + 1, -1);
    vector<int> path;
    path.reserve(n + 1);

    auto getNext = [&](int start)
    {
        int cur = start;
        path.clear();
        while (nx[cur] != -1 && cur != n - 1)
        {
            path.push_back(cur);
            cur = nx[cur];
        }
        int result;
        if (nx[cur] == -1)
            result = cur;
        else
        {
            nx[cur] = n;
            result = n;
        }
        for (int p : path)
            nx[p] = result;
        return result;
    };

    for (int ii = L - 1; ii >= 0; ii--)
    {
        int i = idx[ii];
        if (ss[i] <= ee[i])
        {
            int k = ss[i];
            while (k <= ee[i])
            {
                res[k] = max(res[k], vv[i]);
                if (nx[k] == -1)
                    nx[k] = k + 1;
                k = getNext(k);
            }
        }
        else
        {
            int k = ss[i];
            while (k < n)
            {
                res[k] = max(res[k], vv[i]);
                if (nx[k] == -1)
                    nx[k] = k + 1;
                k = getNext(k);
            }
            k = 0;
            while (k <= ee[i])
            {
                res[k] = max(res[k], vv[i]);
                if (nx[k] == -1)
                    nx[k] = k + 1;
                k = getNext(k);
            }
        }
    }

    for (int i = 1; i < 2 * n; i++)
    {
        res[i % n] = max(res[i % n], res[(i - 1) % n] - 2);
    }
    for (int i = 2 * n - 2; i >= 0; i--)
    {
        res[i % n] = max(res[i % n], res[(i + 1) % n] - 2);
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    vector<int> result = circularPalindromes(s);

    for (size_t i = 0; i < result.size(); i++)
    {
        fout << result[i];

        if (i != result.size() - 1)
        {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}