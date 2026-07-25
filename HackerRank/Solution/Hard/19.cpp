#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005
static int n, t;
static int p[MAXN], r_[MAXN], h[MAXN];
static string s;

string ltrim(const string &);
string rtrim(const string &);

static void fix_index(int *b, int *e)
{
    int pkm1, pk, np, i, d, m;
    pkm1 = p[*b + t];
    m = e - b;
    d = 0;
    np = b - r_;
    for (i = 0; i < m; i++)
    {
        if (((pk = p[*b + t]) != pkm1) && !(np <= pkm1 && pk < np + m))
        {
            pkm1 = pk;
            d = i;
        }
        p[*(b++)] = np + d;
    }
}

static bool comp_fn(int i, int j)
{
    return p[i + t] < p[j + t];
}

static void suff_arr()
{
    int i, j, bc[256];
    t = 1;
    for (i = 0; i < 256; i++)
        bc[i] = 0;
    for (i = 0; i < n; i++)
        ++bc[(unsigned char)s[i]];
    for (i = 1; i < 256; i++)
        bc[i] += bc[i - 1];
    for (i = 0; i < n; i++)
        r_[--bc[(unsigned char)s[i]]] = i;
    for (i = n - 1; i >= 0; i--)
        p[i] = bc[(unsigned char)s[i]];
    for (t = 1; t < n; t *= 2)
    {
        for (i = 0, j = 1; i < n; i = j++)
        {
            while (j < n && p[r_[j]] == p[r_[i]])
                ++j;
            if (j - i > 1)
            {
                sort(r_ + i, r_ + j, comp_fn);
                fix_index(r_ + i, r_ + j);
            }
        }
    }
}

static void lcp()
{
    int tam = 0, i, j;
    for (i = 0; i < n; i++)
        if (p[i] > 0)
        {
            j = r_[p[i] - 1];
            while (s[i + tam] == s[j + tam])
                ++tam;
            h[p[i]] = tam;
            if (tam > 0)
                --tam;
        }
    h[0] = 0;
}

vector<string> findStrings(vector<string> w, vector<int> queries)
{
    s.clear();
    int numS = (int)w.size();
    for (int idx = 0; idx < numS; ++idx)
    {
        s += w[idx] + char(idx + 1);
    }
    n = (int)s.size();

    int clearUpTo = min((long long)MAXN, 2LL * n + 10);
    for (int i = 0; i < clearUpTo; i++)
    {
        p[i] = 0;
        r_[i] = 0;
        h[i] = 0;
    }

    suff_arr();
    lcp();

    vector<int> l(n);
    for (int i = n - 1, acum = 1; i >= 0; --i)
    {
        if ((unsigned char)s[i] < (unsigned char)'a')
            acum = 0;
        l[p[i]] = acum;
        acum++;
    }

    vector<string> results;
    results.reserve(queries.size());
    for (size_t qi = 0; qi < queries.size(); ++qi)
    {
        int k = queries[qi];
        int i = 1;
        bool found = false;
        for (; i < n; ++i)
        {
            int rem = l[i] - h[i];
            if (rem >= k)
            {
                results.push_back(s.substr(r_[i], h[i] + k));
                found = true;
                break;
            }
            else
            {
                k -= rem;
            }
        }
        if (!found)
            results.push_back("INVALID");
    }
    return results;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string w_count_temp;
    getline(cin, w_count_temp);

    int w_count = stoi(ltrim(rtrim(w_count_temp)));

    vector<string> w(w_count);

    for (int i = 0; i < w_count; i++)
    {
        string w_item;
        getline(cin, w_item);

        w[i] = w_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++)
    {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<string> result = findStrings(w, queries);

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