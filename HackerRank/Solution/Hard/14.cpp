#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY x as parameter.
 */

long solve(vector<int> x)
{
    const int mod = 1e9 + 7;
    const int inv2 = (mod + 1) >> 1;

    auto add = [&](int a, int b)
    {
        a += b;
        return a >= mod ? a - mod : a;
    };
    auto pop = [&](int a, int b)
    {
        a -= b;
        return a < 0 ? a + mod : a;
    };
    auto mul = [&](int a, int b)
    {
        return (int)(1LL * a * b % mod);
    };
    auto cal2 = [&](int n)
    {
        return mul(mul(n, pop(n, 1)), inv2);
    };

    int N = x.size();
    vector<int> a(N + 1), fac(N + 1), pre(N, 0), c(N + 2, 0);
    for (int i = 1; i <= N; i++)
    {
        a[i] = x[i - 1];
    }

    auto lowbit = [](int i)
    {
        return i & (-i);
    };
    auto upd = [&](int o, int v)
    {
        for (int i = o + 1; i <= N; i += lowbit(i))
        {
            c[i] += v;
        }
    };
    auto calc = [&](int o)
    {
        int s = 0;
        for (int i = o + 1; i >= 1; i -= lowbit(i))
        {
            s += c[i];
        }
        return s;
    };

    int cnt = 0, ans = 0, cur = 0, lex = 0;

    for (int i = 1; i <= N; i++)
    {
        a[i]--;
        cnt += (a[i] == -1);
        if (a[i] >= 0)
        {
            pre[a[i]] = 1;
        }
    }
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fac[i] = mul(i, fac[i - 1]);
    }
    for (int i = 1; i <= N - 1; i++)
    {
        pre[i] += pre[i - 1];
    }

    lex = mul(mul(N, pop(N, 1)), inv2);
    for (int i = 1; i <= N; i++)
    {
        if (a[i] != -1)
        {
            lex = pop(lex, a[i]);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (a[i] != -1)
        {
            int sum = mul(fac[cnt], a[i] - calc(a[i]));
            if (cnt >= 1)
            {
                sum = pop(sum, mul(fac[cnt - 1], mul(cur, a[i] + 1 - pre[a[i]])));
            }
            sum = mul(sum, fac[N - i]);
            ans = add(ans, sum);
            upd(a[i], 1);
            lex = pop(lex, pop(N - 1 - a[i], pop(pre[N - 1], pre[a[i]])));
        }
        else
        {
            int sum = mul(lex, fac[cnt - 1]);
            if (cnt >= 2)
            {
                sum = pop(sum, mul(fac[cnt - 2], mul(cur, cal2(cnt))));
            }
            sum = mul(sum, fac[N - i]);
            ans = add(ans, sum);
            cur++;
        }
    }
    return add(ans, fac[cnt]);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    long result = solve(a);

    fout << result << "\n";

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}