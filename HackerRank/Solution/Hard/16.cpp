#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'virusIndices' function below.
 *
 * The function accepts following parameters:
 *  1. STRING p
 *  2. STRING v
 */

vector<int> Z(string s)
{
    vector<int> z = {0};
    int l = 0, r = 0;
    for (int i = 1; i < (int)s.size(); i++)
    {
        if (i >= r)
        {
            r = l = i;
            while (r < (int)s.size() && s[r - i] == s[r])
                r++;
            z.push_back(r - i);
        }
        else
        {
            if (z[i - l] < r - i)
            {
                z.push_back(z[i - l]);
            }
            else
            {
                l = i;
                while (r < (int)s.size() && s[r - i] == s[r])
                    r++;
                z.push_back(r - i);
            }
        }
    }
    return z;
}

void virusIndices(string p, string v)
{
    // Print the answer for this test case in a single line
    if (v.size() > p.size())
    {
        cout << "No Match!" << '\n';
        return;
    }

    auto a = Z(v + "@" + p);
    string prev = p, vrev = v;

    reverse(prev.begin(), prev.end());
    reverse(vrev.begin(), vrev.end());

    auto b = Z(vrev + "@" + prev);
    vector<int> ans;

    for (int i = 0; i + (int)v.size() <= (int)p.size(); i++)
    {
        int suffIdx = (int)v.size() + 1 + (int)p.size() - (i + (int)v.size());

        if (a[v.size() + 1 + i] + b[suffIdx] + 1 >= (int)v.size())
        {
            ans.push_back(i);
        }
    }
    if (ans.empty())
    {
        cout << "No Match!" << '\n';
    }
    else
    {
        for (int i : ans)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        string p = first_multiple_input[0];

        string v = first_multiple_input[1];

        virusIndices(p, v);
    }

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